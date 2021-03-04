#include "drake/common/symbolic.h"
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <sstream>

namespace py = pybind11;
void apb11_pydrake_Variable_py_register(py::module &m) {
  static bool called = false;
  if (called) {
    return;
  }
  called = true;
  py::class_<::drake::symbolic::Variable> Variable(
      m, "Variable",
      R"""(/** Represents a symbolic variable. 
 * 
 * @note Expression::Evaluate and Formula::Evaluate methods take a symbolic 
 * environment (Variable → double) and a random number generator. When an 
 * expression or a formula includes random variables, `Evaluate` methods use the 
 * random number generator to draw a number for a random variable from the given 
 * distribution. Then this numeric value is used to substitute all the 
 * occurrences of the corresponding random variable in an expression or a 
 * formula. 
 */)""");

  py::enum_<::drake::symbolic::Variable::Type>(
      Variable, "Type", py::arithmetic(),
      R"""(/** Supported types of symbolic variables. */)""")
      .value("BINARY", ::drake::symbolic::Variable::Type::BINARY, "")
      .value("BOOLEAN", ::drake::symbolic::Variable::Type::BOOLEAN, "")
      .value("CONTINUOUS", ::drake::symbolic::Variable::Type::CONTINUOUS, "")
      .value("INTEGER", ::drake::symbolic::Variable::Type::INTEGER, "")
      .value("RANDOM_EXPONENTIAL",
             ::drake::symbolic::Variable::Type::RANDOM_EXPONENTIAL, "")
      .value("RANDOM_GAUSSIAN",
             ::drake::symbolic::Variable::Type::RANDOM_GAUSSIAN, "")
      .value("RANDOM_UNIFORM",
             ::drake::symbolic::Variable::Type::RANDOM_UNIFORM, "");
  Variable.def(py::init<::drake::symbolic::Variable const &>(), py::arg("arg0"))
      .def(py::init<>())
      .def(py::init<::std::nullptr_t>(), py::arg("arg0"))
      .def(py::init<::std::string, ::drake::symbolic::Variable::Type>(),
           py::arg("name"),
           py::arg("type") = ::drake::symbolic::Variable::Type(
               ::drake::symbolic::Variable::Type::CONTINUOUS))
      .def_static(
          "DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE",
          static_cast<void (*)()>(&::drake::symbolic::Variable::
                                      DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE))
      .def(
          "equal_to",
          static_cast<bool (::drake::symbolic::Variable::*)(
              ::drake::symbolic::Variable const &) const>(
              &::drake::symbolic::Variable::equal_to),
          py::arg("v"),
          R"""(/// Checks the equality of two variables based on their ID values.)""")
      .def("get_id", static_cast<::drake::symbolic::Variable::Id (
                         ::drake::symbolic::Variable::*)() const>(
                         &::drake::symbolic::Variable::get_id))
      .def("get_name",
           static_cast<::std::string (::drake::symbolic::Variable::*)() const>(
               &::drake::symbolic::Variable::get_name))
      .def(
          "is_dummy",
          static_cast<bool (::drake::symbolic::Variable::*)() const>(
              &::drake::symbolic::Variable::is_dummy),
          R"""(/** Checks if this is a dummy variable (ID = 0) which is created by 
 *  the default constructor. */)""")
      .def("less",
           static_cast<bool (::drake::symbolic::Variable::*)(
               ::drake::symbolic::Variable const &) const>(
               &::drake::symbolic::Variable::less),
           py::arg("v"),
           R"""(/// Compares two variables based on their ID values.)""")
      .def("to_string",
           static_cast<::std::string (::drake::symbolic::Variable::*)() const>(
               &::drake::symbolic::Variable::to_string))

      .def(
          "__str__", +[](::drake::symbolic::Variable const &var) {
            std::ostringstream oss;
            oss << var;
            std::string s(oss.str());

            return s;
          });
}
