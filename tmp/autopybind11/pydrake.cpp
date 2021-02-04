
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

PYBIND11_EXPORT void apb11_pydrake_register_types(py::module &model) {
  // make sure this module is only initialized once
  static bool called = false;
  if (called) {
    return;
  }
  called = true;

  // initialize class for module pydrake
};

PYBIND11_MODULE(pydrake, model) {
  // First initialize dependent modules
  // then this module.
  apb11_pydrake_register_types(model);
}
