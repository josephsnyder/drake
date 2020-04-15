from argparse import ArgumentParser
import glob
import json
import logging
import os
import pygccxml

cppbody = """
#include "pybind11/eigen.h"
#include "pybind11/operators.h"
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "drake/bindings/pydrake/documentation_pybind.h"
#include "drake/bindings/pydrake/pydrake_pybind.h"

namespace drake {{
namespace pydrake {{
PYBIND11_MODULE({name},m) {{
  py:class<{name}>(m, "{name}", doc.{name}.doc)
  {constructor}
  {funcs}
  {arith}
}}

}}  // namespace pydrake
}}  // namespace drake
"""

arithmetic = """
  // Arithmetic
  .def(-py::self)
  .def(py::self + py::self)
  .def(py::self + {type}())
  .def({type}() + py::self)
  .def(py::self - py::self)
  .def(py::self - {type}())
  .def({type}() - py::self)
  .def(py::self * py::self)
  .def(py::self * {type}())
  .def({type}() * py::self)
  .def(py::self / {type}())
  // Logical comparison
  .def(py::self == py::self);

"""

constructor = """    .def(py::init<{}>(), {})\n"""
member_func = """    .def{static}(\"{fun_name}\", {classname}, {args}, doc.{classname_doc}.{fun_name}.doc)\n"""
member_func_arg = """ py::arg(\"{}\")"""
overload_template = """py::overload_cast<{arg_types}>({classname}),"""
wrap_header = """#ifndef TMP_WRAPPING_HEADER
#define TMP_WRAPPING_HEADER
#include <experimental/optional>
%s
%s
namespace _wrapping_
{
  const char* const group = "%s";

  namespace wrappers
  {
    %s
  }

  void force_instantiate()
  {
    using namespace _wrapping_::wrappers;

  }
}
#endif
"""


def find_all_function_decls(function_data):
  all_functions = []
  for overload in function_data.overloads.declarations:
    all_functions.append(overload)
  all_functions.append(function_data)

  return all_functions

def write_class_data(class_data):
  constructor_str = ""
  written_functions = []
  file_part = "%s_py" % class_data.name.split("<")[0]
  for constructorObj in class_data.constructors():
    arg_string = ""
    print(constructorObj.name)
    for arg in constructorObj.argument_types:
      arg_string += arg.decl_string + ","
    arg_string = arg_string.strip(",")
    constructor_str += constructor.format(arg_string, "")

  member_string = ""
  for member_function in class_data.member_functions():
    # Check to see if we've written out this function and its overloads
    # already
    if member_function.name in written_functions:
      continue

    # Capture all overloaded versions at once.
    all_version = find_all_function_decls(member_function)
    overload_flag = False
    # Len > 1 means there are overloads
    if len(all_version) > 1:
      overload_flag = True
    for version in all_version:
      written_functions.append(member_function.name)
      arg_string = ""
      signature  = ""
      for arg in version.arguments:
        arg_string += member_func_arg.format(arg.name) + ','
      if overload_flag:
        arg_types = ""
        for arg_type in version.argument_types:
          arg_types += arg_type.decl_string + ','
        signature = overload_template.format(classname=version.name, arg_types=arg_types)
      if signature == "":
        signature = "%s::%s" % (version.parent.name, version.name)
      arg_string = arg_string.strip(",")
      member_string += member_func.format(
        static="_static" if member_function.has_static else "",
        fun_name=member_function.name,
        classname=signature,
        args=arg_string,
        classname_doc=member_function.parent.name,
        doc_string="")
  for operator in class_data.operators():
    continue
    #print(operator)
    #print(operator.name)
    #print(len(operator.argument_types))

  # with open("%s.hpp"  % file_part, "w") as hpp_file:
  with open("%s.cpp" % file_part, "w") as cpp_file:
    cpp_file.write(cppbody.format(name=file_part,
                                  constructor=constructor_str,
                                  funcs=member_string,
                                  arith=""))



def find_classes(src, src_dict, res_dict):
  for key, data in src_dict.items():
      if key in ["classes"]:
        for className in data:
          if len(data[className]["inst"]):
            for instantiation in data[className]["inst"]:
                res_dict['instantiate'].append(("   typedef {}<{}> {};\n").format(className, instantiation, className.split("::")[-1]+instantiation.split("::")[-1]))
                res_dict['typedefs'].append(("  template class {}<{}>;\n").format(className, instantiation))
                res_dict['decls'].append("%s<%s>" % (className.split("::")[-1],
                                                     instantiation.split("::")[-1]))
          else:
            res_dict['instantiate'].append(("   typedef {} {};\n").format(
              className, className.split("::")[-1]))
            res_dict['decls'].append(className.split("::")[-1])
          res_dict["#include"].append("#include \"%s\"\n" % data[className]["file"])
          res_dict['out_names'].append("%s_py.cpp" % className.split("::")[-1])
      else:
          res_dict["namespaces"].append(key)
          res_dict = find_classes(os.path.join(src, key), data, res_dict)
  return res_dict

def parse(options):
  # init the pygccxml stuff
  # Adapted from CPPWG: https://github.com/jmsgrogan/cppwg/blob/265117455ed57eb250643a28ea6029c2bccf3ab3/cppwg/parsers/source_parser.py#L24
  results = {"includes": [],
             "namespaces": [],
             "typedefs": [],
             "#include": [],
             'instantiate': [],
             "decls": [],
             "out_names": []}
  files_to_parse = []
  if options.json_path:
    files_to_parse.append(options.json_path)
  else:
    files_to_parse = glob.glob("**/wrapper_input.json", recursive=True)
  for found_input_file in files_to_parse:
    results = find_classes(options.source_dir, json.load(open(found_input_file, "r")), results)
    results["includes"].append(os.path.dirname(found_input_file))
  if options.no_generation:
    print(results["out_names"])
    return
  castxml_config = pygccxml.parser.xml_generator_configuration_t(xml_generator_path=options.castxml_path,
                                                xml_generator="castxml",
                                                cflags="-std=c++1z",
                                                include_paths=results["includes"])
  with open("wrapper.hpp", "w") as file:
    file.write(wrap_header % (" ".join(results["#include"]), " ".join(results['typedefs']), "drake_wrap", " ".join(results['instantiate']) ))
  total = pygccxml.parser.parse(["wrapper.hpp"], castxml_config, compilation_mode=pygccxml.parser.COMPILATION_MODE.ALL_AT_ONCE)

  # Reads in JSON of namespaces with exclusions and inclusions.

  pygccxml.utils.loggers.cxx_parser.setLevel(logging.CRITICAL)
  pygccxml.declarations.scopedef_t.RECURSIVE_DEFAULT = False
  pygccxml.declarations.scopedef_t.ALLOW_EMPTY_MDECL_WRAPPER = True
  name_data = total[0].namespace("drake")
  for declared_class in results['decls']:
    print(declared_class)
    if declared_class in [x.name for x in total[0].classes()]:
      write_class_data(total[0].class_(declared_class))
    else:
      known_namespaces = [x.name for x in name_data.namespaces()]
      for namespace in results['namespaces']:
          if namespace in known_namespaces:
            if declared_class in  [x.name for x in name_data.namespace(namespace).classes()]:
              write_class_data(name_data.namespace(namespace).class_(declared_class))



arg = ArgumentParser()
arg.add_argument("-s", "--source", action="store", dest="source_dir")
arg.add_argument(
  "-j",
  "--input_json",
  action="store",
  dest="json_path",
  help="Path to input JSON file of namespaces",
  required=False,
  default="",)
arg.add_argument(
  "-g",
  "--castxml-path",
  action="store",
  dest="castxml_path",
  help="Path to castxml",
  required=True)
arg.add_argument('--includes', '-i', type=str,
                    help='Path to the includes directory.',
                    action="append",
                    default=[])
arg.add_argument('--no-generation', '-n',
                    help='Only print name of files to be generated',
                    dest="no_generation",
                    action='store_true', required=False)
options = arg.parse_args()
parse(options)
