#include "drake/common/constants.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

py::module apb11_pydrake_drake_py_register(py::module &m) {
  py::module drake = m.def_submodule("drake", "");
  py::enum_<::drake::ToleranceType>(drake, "ToleranceType", py::arithmetic(),
                                    "")
      .value("absolute", ::drake::ToleranceType::kAbsolute, "")
      .value("relative", ::drake::ToleranceType::kRelative, "")
      .export_values();
  return drake;
}
