#include "drake/perception/point_cloud_flags.h"
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

py::module apb11_pydrake_pc_flags_py_register(py::module &m) {
  py::module pc_flags = m.def_submodule("pc_flags", "");
  py::enum_<::drake::perception::pc_flags::BaseField>(
      pc_flags, "BaseField", py::arithmetic(),
      R"""(/// Indicates the data the point cloud stores.)""")
      .value("kInherit", ::drake::perception::pc_flags::BaseField::kInherit, "")
      .value("kNone", ::drake::perception::pc_flags::BaseField::kNone, "")
      .value("kNormals", ::drake::perception::pc_flags::BaseField::kNormals, "")
      .value("kRGBs", ::drake::perception::pc_flags::BaseField::kRGBs, "")
      .value("kXYZs", ::drake::perception::pc_flags::BaseField::kXYZs, "");
  return pc_flags;
}
