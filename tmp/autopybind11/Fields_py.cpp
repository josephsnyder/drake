#include "drake/perception/point_cloud_flags.h"
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <sstream>

namespace py = pybind11;
void apb11_pydrake_Fields_py_register(py::module &m) {
  static bool called = false;
  if (called) {
    return;
  }
  called = true;
  py::class_<::drake::perception::pc_flags::Fields> Fields(m, "Fields", "/** \
 * Allows combination of `BaseField` and `DescriptorType` for a `PointCloud`. \
 * You may combine multiple `BaseField`s, but you may have only zero or one \
 * `DescriptorType`. \
 * \
 * This provides the mechanism to use basic bit-mask operators (| &) to \
 * combine / intersect fields for convenience. \
 */");

  Fields.def(py::init<::drake::perception::pc_flags::Fields const &>(),py::arg("arg0"))
    .def(py::init<::drake::perception::pc_flags::BaseFieldT,::drake::perception::pc_flags::DescriptorType>(),py::arg("base_fields"),py::arg("descriptor_type"))
    .def(py::init<::drake::perception::pc_flags::BaseFieldT>(),py::arg("base_fields"))
    .def(py::init<::drake::perception::pc_flags::DescriptorType const &>(),py::arg("descriptor_type"))
    .def_static("DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE", static_cast<void (*)(  )>(&::drake::perception::pc_flags::Fields::DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE), "")
    .def("base_fields", static_cast<::drake::perception::pc_flags::BaseFieldT ( ::drake::perception::pc_flags::Fields::* )(  )const>(&::drake::perception::pc_flags::Fields::base_fields), "/// Returns the contained base fields.")
    .def("has_base_fields", static_cast<bool ( ::drake::perception::pc_flags::Fields::* )(  )const>(&::drake::perception::pc_flags::Fields::has_base_fields), "/// Returns whether there are any base fields contained by this set of fields.")
    .def("descriptor_type", static_cast<::drake::perception::pc_flags::DescriptorType const & ( ::drake::perception::pc_flags::Fields::* )(  )const>(&::drake::perception::pc_flags::Fields::descriptor_type), "/// Returns the contained descriptor type.")
    .def("has_descriptor", static_cast<bool ( ::drake::perception::pc_flags::Fields::* )(  )const>(&::drake::perception::pc_flags::Fields::has_descriptor), "/// Returns whether there is a descriptor contained by this set of fields.")
    .def("empty", static_cast<bool ( ::drake::perception::pc_flags::Fields::* )(  )const>(&::drake::perception::pc_flags::Fields::empty), "/// Returns whether both value types (BaseField + DescriptorType) are none.")
    .def("contains", static_cast<bool ( ::drake::perception::pc_flags::Fields::* )( ::drake::perception::pc_flags::Fields const & )const>(&::drake::perception::pc_flags::Fields::contains), py::arg("rhs"), "/// Returns whether this set of fields contains (is a superset of) `rhs`.")
    
    .def("__neq__", static_cast<bool ( ::drake::perception::pc_flags::Fields::* )( ::drake::perception::pc_flags::Fields const & )const>(&::drake::perception::pc_flags::Fields::operator!=), py::arg("rhs"), "")
    .def("__or__", static_cast<::drake::perception::pc_flags::Fields ( ::drake::perception::pc_flags::Fields::* )( ::drake::perception::pc_flags::Fields const & )const>(&::drake::perception::pc_flags::Fields::operator|), py::arg("rhs"), "/// Provides union. \
/// @see operator|= for preconditions.")
    .def("__str__", +[](::drake::perception::pc_flags::Fields const & rhs) {
        std::ostringstream oss;
        oss << rhs;
        std::string s(oss.str());

        return s;})    .def("__eq__", static_cast<bool ( ::drake::perception::pc_flags::Fields::* )( ::drake::perception::pc_flags::Fields const & )const>(&::drake::perception::pc_flags::Fields::operator==), py::arg("rhs"), "")
    .def("__iand__", static_cast<::drake::perception::pc_flags::Fields & ( ::drake::perception::pc_flags::Fields::* )( ::drake::perception::pc_flags::Fields const & )>(&::drake::perception::pc_flags::Fields::operator&=), py::arg("rhs"), "/// Provides in-place intersection.")
        .def("__and__", static_cast<::drake::perception::pc_flags::Fields ( ::drake::perception::pc_flags::Fields::* )( ::drake::perception::pc_flags::Fields const & )const>(&::drake::perception::pc_flags::Fields::operator&), py::arg("rhs"), "/// Provides intersection.")
    .def("__ior__", static_cast<::drake::perception::pc_flags::Fields & ( ::drake::perception::pc_flags::Fields::* )( ::drake::perception::pc_flags::Fields const & )>(&::drake::perception::pc_flags::Fields::operator|=), py::arg("rhs"), "/// Provides in-place union. \
/// @throws std::runtime_error if multiple non-None `DescriptorType`s are \
/// specified.")
    ;
}
