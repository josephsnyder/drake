#include "drake/common/symbolic.h"
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <sstream>

namespace py = pybind11;
void apb11_pydrake_Formula_py_register(py::module &m) {
  static bool called = false;
  if (called) {
    return;
  }
  called = true;
  py::class_<::drake::symbolic::Formula> Formula(
      m, "Formula",
      "/** Represents a symbolic form of a first-order logic formula. \
 \
It has the following grammar: \
 \
\verbatim \
    F := ⊥ | ⊤ | Var | E = E | E ≠ E | E > E | E ≥ E | E < E | E ≤ E \
       | E ∧ ... ∧ E | E ∨ ... ∨ E | ¬F | ∀ x₁, ..., xn. F \
\endverbatim \
 \
In the implementation, Formula is a simple wrapper including a shared \
pointer to FormulaCell class which is a super-class of different kinds \
of symbolic formulas (i.e. FormulaAnd, FormulaOr, FormulaEq). Note \
that it includes a shared pointer, not a unique pointer, to allow \
sharing sub-expressions. \
 \
\note The sharing of sub-expressions is not yet implemented. \
 \
The following simple simplifications are implemented: \
\verbatim \
    E1 = E2        ->  True    (if E1 and E2 are structurally equal) \
    E1 ≠ E2        ->  False   (if E1 and E2 are structurally equal) \
    E1 > E2        ->  False   (if E1 and E2 are structurally equal) \
    E1 ≥ E2        ->  True    (if E1 and E2 are structurally equal) \
    E1 < E2        ->  False   (if E1 and E2 are structurally equal) \
    E1 ≤ E2        ->  True    (if E1 and E2 are structurally equal) \
    F1 ∧ F2        ->  False   (if either F1 or F2 is False) \
    F1 ∨ F2        ->  True    (if either F1 or F2 is True) \
    ¬(¬(F))        ->  F \
\endverbatim \
 \
We flatten nested conjunctions (or disjunctions) at the construction. A \
conjunction (resp. disjunction) takes a set of conjuncts (resp. disjuncts). Note \
that any duplicated conjunct/disjunct is removed. For example, both of `f1 && \
(f2 && f1)` and `(f1 && f2) && f1` are flattened to `f1 && f2 && f1` and \
simplified into `f1 && f2`. As a result, the two are identified as the same \
formula. \
 \
\note Formula class has an explicit conversion operator to bool. It evaluates a \
symbolic formula under an empty environment. If a symbolic formula includes \
variables, the conversion operator throws an exception. This operator is only \
intended for third-party code doing things like `(imag(SymbolicExpression(0)) \
== SymbolicExpression(0)) { ... };` that we found in Eigen3 codebase. In \
general, a user of this class should explicitly call `Evaluate` from within \
Drake for readability. \
 \
*/");

  Formula.def(py::init<::drake::symbolic::Formula const &>(), py::arg("arg0"))
      .def(py::init<>())
      .def(py::init<bool>(), py::arg("value"))
      .def(py::init<::std::shared_ptr<const drake::symbolic::FormulaCell>>(),
           py::arg("ptr"))
      .def(py::init<::drake::symbolic::Variable const &>(), py::arg("var"))
      .def_static(
          "DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE",
          static_cast<void (*)()>(&::drake::symbolic::Formula::
                                      DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE),
          "")
      .def("get_kind",
           static_cast<::drake::symbolic::FormulaKind (
               ::drake::symbolic::Formula::*)() const>(
               &::drake::symbolic::Formula::get_kind),
           "")
      .def("GetFreeVariables",
           static_cast<::drake::symbolic::Variables (
               ::drake::symbolic::Formula::*)() const>(
               &::drake::symbolic::Formula::GetFreeVariables),
           "/** Gets free variables (unquantified variables). */")
      .def("EqualTo",
           static_cast<bool (::drake::symbolic::Formula::*)(
               ::drake::symbolic::Formula const &) const>(
               &::drake::symbolic::Formula::EqualTo),
           py::arg("f"), "/** Checks structural equality. */")
      .def("Less",
           static_cast<bool (::drake::symbolic::Formula::*)(
               ::drake::symbolic::Formula const &) const>(
               &::drake::symbolic::Formula::Less),
           py::arg("f"),
           "/** Checks lexicographical ordering between this and @p e. \
 * \
 * If the two formulas f1 and f2 have different kinds k1 and k2 respectively, \
 * f1.Less(f2) is equal to k1 < k2. If f1 and f2 are expressions of the same \
 * kind, we check the ordering between f1 and f2 by comparing their elements \
 * lexicographically. \
 * \
 * For example, in case of And, let f1 and f2 be \
 * \
 *     f1 = f_1,1 ∧ ... ∧ f_1,n \
 *     f2 = f_2,1 ∧ ... ∧ f_2,m \
 * \
 * f1.Less(f2) is true if there exists an index i (<= n, m) such that \
 * for all j < i, we have \
 * \
 *     ¬(f_1_j.Less(f_2_j)) ∧ ¬(f_2_j.Less(f_1_j)) \
 * \
 * and f_1_i.Less(f_2_i) holds. \
 * \
 * This function is used as a compare function in \
 * std::map<symbolic::Formula> and std::set<symbolic::Formula> via \
 * std::less<symbolic::Formula>. */")
      .def(
          "Evaluate",
          static_cast<bool (::drake::symbolic::Formula::*)(
              ::drake::symbolic::Environment const &,
              ::drake::RandomGenerator *) const>(
              &::drake::symbolic::Formula::Evaluate),
          py::arg("env") =
              (::drake::symbolic::Environment)drake::symbolic::Environment{},
          py::arg("random_generator") = (::drake::RandomGenerator *)nullptr,
          "/** Evaluates using a given environment (by default, an empty environment) and \
 * a random number generator. If there is a random variable in this formula \
 * which is unassigned in @p env, it uses @p random_generator to sample a \
 * value and use it to substitute all occurrences of the random variable in \
 * this formula. \
 * \
 * @throws std::runtime_error if a variable `v` is needed for an evaluation \
 *                            but not provided by @p env. \
 * @throws std::runtime_error if an unassigned random variable is detected \
 *                            while @p random_generator is `nullptr`. \
 */")
      .def(
          "Evaluate",
          static_cast<bool (::drake::symbolic::Formula::*)(
              ::drake::RandomGenerator *) const>(
              &::drake::symbolic::Formula::Evaluate),
          py::arg("random_generator"),
          "/** Evaluates using an empty environment and a random number generator. \
 * \
 * See the above overload for the exceptions that it might throw. \
 */")
      .def(
          "Substitute",
          static_cast<::drake::symbolic::Formula (
              ::drake::symbolic::Formula::*)(
              ::drake::symbolic::Variable const &,
              ::drake::symbolic::Expression const &) const>(
              &::drake::symbolic::Formula::Substitute),
          py::arg("var"), py::arg("e"),
          "/** Returns a copy of this formula replacing all occurrences of @p var \
 * with @p e. \
 * @throws std::runtime_error if NaN is detected during substitution. \
 */")
      .def(
          "Substitute",
          static_cast<::drake::symbolic::Formula (
              ::drake::symbolic::Formula::*)(
              ::drake::symbolic::Substitution const &) const>(
              &::drake::symbolic::Formula::Substitute),
          py::arg("s"),
          "/** Returns a copy of this formula replacing all occurrences of the \
 * variables in @p s with corresponding expressions in @p s. Note that the \
 * substitutions occur simultaneously. For example, (x / y > \
 * 0).Substitute({{x, y}, {y, x}}) gets (y / x > 0). \
 * @throws std::runtime_error if NaN is detected during substitution. \
 */")
      .def("to_string",
           static_cast<::std::string (::drake::symbolic::Formula::*)() const>(
               &::drake::symbolic::Formula::to_string),
           "/** Returns string representation of Formula. */")
      .def_static("True",
                  static_cast<::drake::symbolic::Formula (*)()>(
                      &::drake::symbolic::Formula::True),
                  "")
      .def_static("False",
                  static_cast<::drake::symbolic::Formula (*)()>(
                      &::drake::symbolic::Formula::False),
                  "")

      .def("__bool__",
           static_cast<bool (::drake::symbolic::Formula::*)() const>(
               &::drake::symbolic::Formula::operator bool),
           "/** Conversion to bool. */")
      .def(
          "__str__", +[](::drake::symbolic::Formula const &f) {
            std::ostringstream oss;
            oss << f;
            std::string s(oss.str());

            return s;
          });
}
