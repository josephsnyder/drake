#include "drake/common/symbolic.h"
#include <pybind11/eigen.h>
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <sstream>

namespace py = pybind11;
void apb11_pydrake_Environment_py_register(py::module &m) {
  static bool called = false;
  if (called) {
    return;
  }
  called = true;
  py::class_<::drake::symbolic::Environment> Environment(
      m, "Environment",
      "/** Represents a symbolic environment (mapping from a variable to a value). \
 * \
 * This class is used when we evaluate symbolic expressions or formulas which \
 * include unquantified (free) variables. Here are examples: \
 * \
 * \code{.cpp} \
 *   const Variable var_x{" x "}; \
 *   const Variable var_y{"y
      "}; \
 *   const Expression x{var_x}; \
 *   const Expression y{var_x}; \
 *   const Expression e1{x + y}; \
 *   const Expression e2{x - y}; \
 *   const Formula f{e1 > e2}; \
 * \
 *   // env maps var_x to 2.0 and var_y to 3.0 \
 *   const Environment env{{var_x, 2.0}, {var_y, 3.0}}; \
 * \
 *   const double res1 = e1.Evaluate(env);  // x + y => 2.0 + 3.0 =>  5.0 \
 *   const double res2 = e2.Evaluate(env);  // x - y => 2.0 - 3.0 => -1.0 \
 *   const bool res = f.Evaluate(env);  // x + y > x - y => 5.0 >= -1.0 => True \
 * \endcode \
 * \
 * Note that it is not allowed to have a dummy variable in an environment. It \
 * throws std::runtime_error for the attempts to create an environment with a \
 * dummy variable, to insert a dummy variable to an existing environment, or to \
 * take a reference to a value mapped to a dummy variable. See the following \
 * examples. \
 * \
 * \code{.cpp} \
 *   Variable    var_dummy{};           // OK to have a dummy variable \
 *   Environment e1{var_dummy};         // throws std::runtime_error exception \
 *   Environment e2{{var_dummy, 1.0}};  // throws std::runtime_error exception \
 *   Environment e{}; \
 *   e.insert(var_dummy, 1.0);          // throws std::runtime_error exception \
 *   e[var_dummy] = 3.0;                // throws std::runtime_error exception \
 * \endcode \
 * \
 */");

  Environment.def(py::init<::drake::symbolic::Environment const &>(),py::arg("arg0"))
    .def(py::init<>())
    .def(py::init<::std::initializer_list<std::pair<const drake::symbolic::Variable, double>>>(),py::arg("init"))
    .def(py::init<::std::initializer_list<drake::symbolic::Variable>>(),py::arg("vars"))
    .def(py::init<::drake::symbolic::Environment::map>(),py::arg("m"))
    .def_static("DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE", static_cast<void (*)(  )>(&::drake::symbolic::Environment::DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE), "")
    .def("begin", static_cast<::drake::symbolic::Environment::iterator ( ::drake::symbolic::Environment::* )(  )>(&::drake::symbolic::Environment::begin), "/** Returns an iterator to the beginning. */")
    .def("end", static_cast<::drake::symbolic::Environment::iterator ( ::drake::symbolic::Environment::* )(  )>(&::drake::symbolic::Environment::end), "/** Returns an iterator to the end. */")
    .def("begin", static_cast<::drake::symbolic::Environment::const_iterator ( ::drake::symbolic::Environment::* )(  )const>(&::drake::symbolic::Environment::begin), "/** Returns a const iterator to the beginning. */")
    .def("end", static_cast<::drake::symbolic::Environment::const_iterator ( ::drake::symbolic::Environment::* )(  )const>(&::drake::symbolic::Environment::end), "/** Returns a const iterator to the end. */")
    .def("cbegin", static_cast<::drake::symbolic::Environment::const_iterator ( ::drake::symbolic::Environment::* )(  )const>(&::drake::symbolic::Environment::cbegin), "/** Returns a const iterator to the beginning. */")
    .def("cend", static_cast<::drake::symbolic::Environment::const_iterator ( ::drake::symbolic::Environment::* )(  )const>(&::drake::symbolic::Environment::cend), "/** Returns a const iterator to the end. */")
    .def("insert", static_cast<void ( ::drake::symbolic::Environment::* )( ::drake::symbolic::Environment::key_type const &,::drake::symbolic::Environment::mapped_type const & )>(&::drake::symbolic::Environment::insert), py::arg("key"), py::arg("elem"), "/** Inserts a pair (@p key, @p elem). */")
    .def("insert", [](::drake::symbolic::Environment &self, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Variable, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1>> const & keys, ::Eigen::Ref<const Eigen::Matrix<double, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1>> const & elements)
{
  return self.insert(keys, elements);
})
    .def("empty", static_cast<bool ( ::drake::symbolic::Environment::* )(  )const>(&::drake::symbolic::Environment::empty), "/** Checks whether the container is empty.  */")
    .def("size", static_cast<::size_t ( ::drake::symbolic::Environment::* )(  )const>(&::drake::symbolic::Environment::size), "/** Returns the number of elements. */")
    .def("find", static_cast<::drake::symbolic::Environment::iterator ( ::drake::symbolic::Environment::* )( ::drake::symbolic::Environment::key_type const & )>(&::drake::symbolic::Environment::find), py::arg("key"), "/** Finds element with specific key. */")
    .def("find", static_cast<::drake::symbolic::Environment::const_iterator ( ::drake::symbolic::Environment::* )( ::drake::symbolic::Environment::key_type const & )const>(&::drake::symbolic::Environment::find), py::arg("key"), "/** Finds element with specific key. */")
    .def("domain", static_cast<::drake::symbolic::Variables ( ::drake::symbolic::Environment::* )(  )const>(&::drake::symbolic::Environment::domain), "/** Returns the domain of this environment. */")
    .def("to_string", static_cast<::std::string ( ::drake::symbolic::Environment::* )(  )const>(&::drake::symbolic::Environment::to_string), "/** Returns string representation. */")
    
    .def("__getitem__", static_cast<::drake::symbolic::Environment::mapped_type & ( ::drake::symbolic::Environment::* )( ::drake::symbolic::Environment::key_type const & )>(&::drake::symbolic::Environment::operator[]), py::arg("key"), "/** Returns a reference to the value that is mapped to a key equivalent to \
 *  @p key, performing an insertion if such key does not already exist. \
 */")
    .def("__str__", +[](::drake::symbolic::Environment const & env) {
        std::ostringstream oss;
        oss << env;
        std::string s(oss.str());

        return s;})    .def("__getitem__", static_cast<::drake::symbolic::Environment::mapped_type const & ( ::drake::symbolic::Environment::* )( ::drake::symbolic::Environment::key_type const & )const>(&::drake::symbolic::Environment::operator[]), py::arg("key"), "/** As above, but returns a constref and does not perform an insertion \
 * (throwing a runtime error instead) if the key does not exist. */")
    ;
}
