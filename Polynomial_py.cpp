
#include "pybind11/eigen.h"
#include "pybind11/operators.h"
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "drake/bindings/pydrake/documentation_pybind.h"
#include "drake/bindings/pydrake/pydrake_pybind.h"

namespace drake {
namespace pydrake {
PYBIND11_MODULE(Polynomial_py,m) {
  py:class<Polynomial_py>(m, "Polynomial_py", doc.Polynomial_py.doc)
      .def(py::init<>(), )
    .def(py::init<::Polynomial<double>::CoefficientType const &>(), )
    .def(py::init<::Polynomial<double>::CoefficientType const,::std::vector<Polynomial<double>::Term, std::allocator<Polynomial<double>::Term> > const &>(), )
    .def(py::init<::std::vector<Polynomial<double>::Monomial, std::allocator<Polynomial<double>::Monomial> >::const_iterator,::std::vector<Polynomial<double>::Monomial, std::allocator<Polynomial<double>::Monomial> >::const_iterator>(), )
    .def(py::init<::std::string const,unsigned int const>(), )
    .def(py::init<::Polynomial<double>::CoefficientType const &,unsigned int const &>(), )
    .def(py::init<::Polynomial<double> const &>(), )

      .def("GetNumberOfCoefficients", Polynomial<double>::GetNumberOfCoefficients, , doc.GetNumberOfCoefficients.doc)
    .def("GetDegree", Polynomial<double>::GetDegree, , doc.GetDegree.doc)
    .def("IsAffine", Polynomial<double>::IsAffine, , doc.IsAffine.doc)
    .def("GetSimpleVariable", Polynomial<double>::GetSimpleVariable, , doc.GetSimpleVariable.doc)
    .def("GetMonomials", Polynomial<double>::GetMonomials, , doc.GetMonomials.doc)
    .def("GetCoefficients", Polynomial<double>::GetCoefficients, , doc.GetCoefficients.doc)
    .def("GetVariables", Polynomial<double>::GetVariables, , doc.GetVariables.doc)
    .def("EvaluateMultivariate", Polynomial<double>::EvaluateMultivariate,  py::arg("var_values"), doc.EvaluateMultivariate.doc)
    .def("EvaluatePartial", Polynomial<double>::EvaluatePartial,  py::arg("var_values"), doc.EvaluatePartial.doc)
    .def("Subs", Polynomial<double>::Subs,  py::arg("orig"), py::arg("replacement"), doc.Subs.doc)
    .def("Derivative", Polynomial<double>::Derivative,  py::arg("derivative_order"), doc.Derivative.doc)
    .def("Integral", Polynomial<double>::Integral,  py::arg("integration_constant"), doc.Integral.doc)
    .def("Roots", Polynomial<double>::Roots, , doc.Roots.doc)
    .def("IsApprox", Polynomial<double>::IsApprox,  py::arg("other"), py::arg("tol"), doc.IsApprox.doc)
    .def_static("IsValidVariableName", Polynomial<double>::IsValidVariableName,  py::arg("name"), doc.IsValidVariableName.doc)
    .def_static("VariableNameToId", Polynomial<double>::VariableNameToId,  py::arg("name"), py::arg("m"), doc.VariableNameToId.doc)
    .def_static("IdToVariableName", Polynomial<double>::IdToVariableName,  py::arg("id"), doc.IdToVariableName.doc)
    .def("MakeMonomialsUnique", Polynomial<double>::MakeMonomialsUnique, , doc.MakeMonomialsUnique.doc)

  
}

}  // namespace pydrake
}  // namespace drake
