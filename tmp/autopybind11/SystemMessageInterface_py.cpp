#include "drake/systems/framework/framework_common.h"
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

class SystemMessageInterface_publicist
    : public ::drake::systems::internal::SystemMessageInterface {
public:
  using ::drake::systems::internal::SystemMessageInterface::
      DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE;
};

namespace py = pybind11;
void apb11_pydrake_SystemMessageInterface_py_register(py::module &m) {
  static bool called = false;
  if (called) {
    return;
  }
  called = true;
  py::class_<::drake::systems::internal::SystemMessageInterface>
      SystemMessageInterface(m, "SystemMessageInterface");

  SystemMessageInterface
      .def_static(
          "DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE",
          static_cast<void (*)()>(&SystemMessageInterface_publicist::
                                      DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE))
      .def("GetSystemName",
           static_cast<::std::string const &(
               ::drake::systems::internal::SystemMessageInterface::*)() const>(
               &::drake::systems::internal::SystemMessageInterface::
                   GetSystemName))
      .def("GetSystemPathname",
           static_cast<::std::string (
               ::drake::systems::internal::SystemMessageInterface::*)() const>(
               &::drake::systems::internal::SystemMessageInterface::
                   GetSystemPathname))
      .def("GetSystemType",
           static_cast<::std::string (
               ::drake::systems::internal::SystemMessageInterface::*)() const>(
               &::drake::systems::internal::SystemMessageInterface::
                   GetSystemType))
      .def("ValidateContext",
           static_cast<void (
               ::drake::systems::internal::SystemMessageInterface::*)(
               ::drake::systems::ContextBase const &) const>(
               &::drake::systems::internal::SystemMessageInterface::
                   ValidateContext),
           py::arg("context"))
      .def_static(
          "no_name",
          static_cast<::std::string const &(*)()>(
              &::drake::systems::internal::SystemMessageInterface::no_name))
      .def_static("path_separator",
                  static_cast<::std::string const &(*)()>(
                      &::drake::systems::internal::SystemMessageInterface::
                          path_separator))

      ;
}
