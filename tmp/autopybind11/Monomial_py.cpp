#include "drake/common/symbolic.h"
#include <pybind11/eigen.h>
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <sstream>

namespace py = pybind11;
void apb11_pydrake_Monomial_py_register(py::module &m) {
  static bool called = false;
  if (called) {
    return;
  }
  called = true;
  py::class_<::drake::symbolic::Monomial> Monomial(
      m, "Monomial",
      "/** Represents a monomial, a product of powers of variables with non-negative \
 * integer exponents. Note that it does not include the coefficient part of a \
 * monomial. \
 */");

  Monomial.def(py::init<::drake::symbolic::Monomial const &>(), py::arg("arg0"))
      .def(py::init<>())
      .def(py::init<::std::nullptr_t>(), py::arg("arg0"))
      .def(py::init<::std::map<
               drake::symbolic::Variable, int,
               std::less<drake::symbolic::Variable>,
               std::allocator<
                   std::pair<const drake::symbolic::Variable, int>>> const &>(),
           py::arg("powers"))
      .def(py::init<::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Variable,
                                                     -1, 1, 0, -1, 1>,
                                 0, Eigen::InnerStride<1>> const &,
                    ::Eigen::Ref<const Eigen::Matrix<int, -1, 1, 0, -1, 1>, 0,
                                 Eigen::InnerStride<1>> const &>(),
           py::arg("vars"), py::arg("exponents"))
      .def(py::init<::drake::symbolic::Expression const &>(), py::arg("e"))
      .def(py::init<::drake::symbolic::Variable const &>(), py::arg("var"))
      .def(py::init<::drake::symbolic::Variable const &, int>(), py::arg("var"),
           py::arg("exponent"))
      .def_static(
          "DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE",
          static_cast<void (*)()>(&::drake::symbolic::Monomial::
                                      DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE),
          "")
      .def("degree",
           static_cast<int (::drake::symbolic::Monomial::*)(
               ::drake::symbolic::Variable const &) const>(
               &::drake::symbolic::Monomial::degree),
           py::arg("v"),
           "/** Returns the degree of this Monomial in a variable @p v. */")
      .def("total_degree",
           static_cast<int (::drake::symbolic::Monomial::*)() const>(
               &::drake::symbolic::Monomial::total_degree),
           "/** Returns the total degree of this Monomial. */")
      .def("GetVariables",
           static_cast<::drake::symbolic::Variables (
               ::drake::symbolic::Monomial::*)() const>(
               &::drake::symbolic::Monomial::GetVariables),
           "/** Returns the set of variables in this monomial. */")
      .def(
          "get_powers",
          static_cast<
              ::std::map<drake::symbolic::Variable, int,
                         std::less<drake::symbolic::Variable>,
                         std::allocator<std::pair<
                             const drake::symbolic::Variable, int>>> const
                  &(::drake::symbolic::Monomial::*)() const>(
              &::drake::symbolic::Monomial::get_powers),
          "/** Returns the internal representation of Monomial, the map from a base \
 * (Variable) to its exponent (int).*/")
      .def("Evaluate",
           static_cast<double (::drake::symbolic::Monomial::*)(
               ::drake::symbolic::Environment const &) const>(
               &::drake::symbolic::Monomial::Evaluate),
           py::arg("env"), "/** Evaluates under a given environment @p env. \
 * \
 * @throws std::out_of_range exception if there is a variable in this monomial \
 * whose assignment is not provided by @p env. \
 */")
      .def(
          "EvaluatePartial",
          static_cast<::std::pair<double, drake::symbolic::Monomial> (
              ::drake::symbolic::Monomial::*)(
              ::drake::symbolic::Environment const &) const>(
              &::drake::symbolic::Monomial::EvaluatePartial),
          py::arg("env"),
          "/** Partially evaluates using a given environment @p env. The evaluation \
 * result is of type pair<double, Monomial>. The first component (: double) \
 * represents the coefficient part while the second component represents the \
 * remaining parts of the Monomial which was not evaluated. \
 * \
 * Example 1. Evaluate with a fully-specified environment \
 *     (x³*y²).EvaluatePartial({{x, 2}, {y, 3}}) \
 *   = (2³ * 3² = 8 * 9 = 72, Monomial{} = 1). \
 * \
 * Example 2. Evaluate with a partial environment \
 *     (x³*y²).EvaluatePartial({{x, 2}}) \
 *   = (2³ = 8, y²). \
 */")
      .def("ToExpression",
           static_cast<::drake::symbolic::Expression (
               ::drake::symbolic::Monomial::*)() const>(
               &::drake::symbolic::Monomial::ToExpression),
           "/** Returns a symbolic expression representing this monomial. */")
      .def("pow_in_place",
           static_cast<::drake::symbolic::Monomial &(
               ::drake::symbolic::Monomial::*)(int)>(
               &::drake::symbolic::Monomial::pow_in_place),
           py::arg("p"), "/** Returns this monomial raised to @p p. \
 * @throws std::runtime_error if @p p is negative. \
 */")

      .def(
          "__eq__",
          static_cast<bool (::drake::symbolic::Monomial::*)(
              ::drake::symbolic::Monomial const &) const>(
              &::drake::symbolic::Monomial::operator==),
          py::arg("m"),
          "/** Checks if this monomial and @p m represent the same monomial. Two \
 * monomials are equal iff they contain the same variable raised to the same \
 * exponent. */")
      .def("__imul__",
           static_cast<::drake::symbolic::Monomial &(
               ::drake::symbolic::Monomial::*)(::drake::symbolic::Monomial const
                                                   &)>(
               &::drake::symbolic::Monomial::operator*=),
           py::arg("m"), "/** Returns this monomial multiplied by @p m. */")
      .def("__neq__",
           static_cast<bool (::drake::symbolic::Monomial::*)(
               ::drake::symbolic::Monomial const &) const>(
               &::drake::symbolic::Monomial::operator!=),
           py::arg("m"),
           "/** Checks if this monomial and @p m do not represent the same "
           "monomial. */")
      .def(
          "__str__", +[](::drake::symbolic::Monomial const &m) {
            std::ostringstream oss;
            oss << m;
            std::string s(oss.str());

            return s;
          });
}
