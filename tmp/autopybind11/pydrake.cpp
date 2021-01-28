
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
namespace py = pybind11;

py::module apb11_pydrake_drake_py_register(py::module &model);
void apb11_pydrake_RandomGenerator_py_register(py::module &model);

PYBIND11_EXPORT void apb11_pydrake_register_types(py::module &model) {
  // make sure this module is only initialized once
  static bool called = false;
  if (called) {
    return;
  }
  called = true;

  // initialize class for module pydrake
  auto drake = apb11_pydrake_drake_py_register(model);
  apb11_pydrake_RandomGenerator_py_register(drake);
};

PYBIND11_MODULE(pydrake, model) {
  // First initialize dependent modules
  // then this module.
  apb11_pydrake_register_types(model);
}
