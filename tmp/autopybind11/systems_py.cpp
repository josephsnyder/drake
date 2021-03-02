#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

py::module apb11_pydrake_systems_py_register(py::module &m) {
  py::module systems = m.def_submodule("systems", "");

  return systems;
}
