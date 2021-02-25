#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

py::module apb11_pydrake_geometry_py_register(py::module &m) {
  py::module geometry = m.def_submodule("geometry", "");

  return geometry;
}
