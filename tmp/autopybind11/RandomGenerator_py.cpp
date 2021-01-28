#include "drake/common/random.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;
void apb11_pydrake_RandomGenerator_py_register(py::module &m) {
  static bool called = false;
  if (called) {
    return;
  }
  called = true;
  py::class_<::drake::RandomGenerator> RandomGenerator(m, "RandomGenerator");

  RandomGenerator
      .def(py::init<::drake::RandomGenerator const &>(), py::arg("arg0"))
      .def(py::init<>())
      .def(py::init<::drake::RandomGenerator::result_type>(), py::arg("value"))
      .def_static(
          "DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE",
          static_cast<void (*)()>(&::drake::RandomGenerator::
                                      DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE))
      .def_static("min",
                  static_cast<::drake::RandomGenerator::result_type (*)()>(
                      &::drake::RandomGenerator::min))
      .def_static("max",
                  static_cast<::drake::RandomGenerator::result_type (*)()>(
                      &::drake::RandomGenerator::max))
      .def_readonly_static("default_seed",
                           &::drake::RandomGenerator::default_seed)
      .def("__call__", static_cast<::drake::RandomGenerator::result_type (
                           ::drake::RandomGenerator::*)()>(
                           &::drake::RandomGenerator::operator()));
}
