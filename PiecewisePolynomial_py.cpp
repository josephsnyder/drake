
#include "pybind11/eigen.h"
#include "pybind11/operators.h"
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "drake/bindings/pydrake/documentation_pybind.h"
#include "drake/bindings/pydrake/pydrake_pybind.h"

namespace drake {
namespace pydrake {
PYBIND11_MODULE(PiecewisePolynomial_py,m) {
  py:class<PiecewisePolynomial_py>(m, "PiecewisePolynomial_py", doc.PiecewisePolynomial_py.doc)
      .def(py::init<>(), )
    .def(py::init<::drake::trajectories::PiecewisePolynomial<double> const &>(), )
    .def(py::init<::std::vector<Eigen::Matrix<Polynomial<double>, -1, -1, 0, -1, -1>, std::allocator<Eigen::Matrix<Polynomial<double>, -1, -1, 0, -1, -1> > > const &,::std::vector<double, std::allocator<double> > const &>(), )
    .def(py::init<::std::vector<Polynomial<double>, std::allocator<Polynomial<double> > > const &,::std::vector<double, std::allocator<double> > const &>(), )

      .def_static("DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE", PiecewisePolynomial<double>::DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE, , doc.DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE.doc)
    .def("Clone", PiecewisePolynomial<double>::Clone, , doc.Clone.doc)
    .def_static("ZeroOrderHold", py::overload_cast<::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &,::Eigen::Ref<const Eigen::Matrix<double, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1> > const &,>(ZeroOrderHold),,  py::arg("breaks"), py::arg("knots"), doc.ZeroOrderHold.doc)
    .def_static("ZeroOrderHold", py::overload_cast<::std::vector<double, std::allocator<double> > const &,::std::vector<Eigen::Matrix<double, -1, -1, 0, -1, -1>, std::allocator<Eigen::Matrix<double, -1, -1, 0, -1, -1> > > const &,>(ZeroOrderHold),,  py::arg("breaks"), py::arg("knots"), doc.ZeroOrderHold.doc)
    .def_static("FirstOrderHold", py::overload_cast<::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &,::Eigen::Ref<const Eigen::Matrix<double, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1> > const &,>(FirstOrderHold),,  py::arg("breaks"), py::arg("knots"), doc.FirstOrderHold.doc)
    .def_static("FirstOrderHold", py::overload_cast<::std::vector<double, std::allocator<double> > const &,::std::vector<Eigen::Matrix<double, -1, -1, 0, -1, -1>, std::allocator<Eigen::Matrix<double, -1, -1, 0, -1, -1> > > const &,>(FirstOrderHold),,  py::arg("breaks"), py::arg("knots"), doc.FirstOrderHold.doc)
    .def_static("Pchip", py::overload_cast<::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &,::Eigen::Ref<const Eigen::Matrix<double, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1> > const &,bool,>(Pchip),,  py::arg("breaks"), py::arg("knots"), py::arg("zero_end_point_derivatives"), doc.Pchip.doc)
    .def_static("Pchip", py::overload_cast<::std::vector<double, std::allocator<double> > const &,::std::vector<Eigen::Matrix<double, -1, -1, 0, -1, -1>, std::allocator<Eigen::Matrix<double, -1, -1, 0, -1, -1> > > const &,bool,>(Pchip),,  py::arg("breaks"), py::arg("knots"), py::arg("zero_end_point_derivatives"), doc.Pchip.doc)
    .def_static("Cubic", py::overload_cast<::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &,::Eigen::Ref<const Eigen::Matrix<double, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1> > const &,::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &,::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &,>(Cubic),,  py::arg("breaks"), py::arg("knots"), py::arg("knots_dot_start"), py::arg("knots_dot_end"), doc.Cubic.doc)
    .def_static("Cubic", py::overload_cast<::std::vector<double, std::allocator<double> > const &,::std::vector<Eigen::Matrix<double, -1, -1, 0, -1, -1>, std::allocator<Eigen::Matrix<double, -1, -1, 0, -1, -1> > > const &,::std::vector<Eigen::Matrix<double, -1, -1, 0, -1, -1>, std::allocator<Eigen::Matrix<double, -1, -1, 0, -1, -1> > > const &,>(Cubic),,  py::arg("breaks"), py::arg("knots"), py::arg("knots_dot"), doc.Cubic.doc)
    .def_static("Cubic", py::overload_cast<::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &,::Eigen::Ref<const Eigen::Matrix<double, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1> > const &,::Eigen::Ref<const Eigen::Matrix<double, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1> > const &,>(Cubic),,  py::arg("breaks"), py::arg("knots"), py::arg("knots_dot"), doc.Cubic.doc)
    .def_static("Cubic", py::overload_cast<::std::vector<double, std::allocator<double> > const &,::std::vector<Eigen::Matrix<double, -1, -1, 0, -1, -1>, std::allocator<Eigen::Matrix<double, -1, -1, 0, -1, -1> > > const &,bool,>(Cubic),,  py::arg("breaks"), py::arg("knots"), py::arg("periodic_end_condition"), doc.Cubic.doc)
    .def_static("Cubic", py::overload_cast<::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &,::Eigen::Ref<const Eigen::Matrix<double, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1> > const &,bool,>(Cubic),,  py::arg("breaks"), py::arg("knots"), py::arg("periodic_end_condition"), doc.Cubic.doc)
    .def_static("Cubic", py::overload_cast<::std::vector<double, std::allocator<double> > const &,::std::vector<Eigen::Matrix<double, -1, -1, 0, -1, -1>, std::allocator<Eigen::Matrix<double, -1, -1, 0, -1, -1> > > const &,::drake::trajectories::PiecewisePolynomial<double>::CoefficientMatrix const &,::drake::trajectories::PiecewisePolynomial<double>::CoefficientMatrix const &,>(Cubic),,  py::arg("breaks"), py::arg("knots"), py::arg("knot_dot_start"), py::arg("knot_dot_end"), doc.Cubic.doc)
    .def("derivative", PiecewisePolynomial<double>::derivative,  py::arg("derivative_order"), doc.derivative.doc)
    .def("MakeDerivative", PiecewisePolynomial<double>::MakeDerivative,  py::arg("derivative_order"), doc.MakeDerivative.doc)
    .def("integral", py::overload_cast<::drake::trajectories::PiecewisePolynomial<double>::CoefficientMatrixRef const &,>(integral),,  py::arg("value_at_start_time"), doc.integral.doc)
    .def("integral", py::overload_cast<double,>(integral),,  py::arg("value_at_start_time"), doc.integral.doc)
    .def("empty", PiecewisePolynomial<double>::empty, , doc.empty.doc)
    .def("scalarValue", PiecewisePolynomial<double>::scalarValue,  py::arg("t"), py::arg("row"), py::arg("col"), doc.scalarValue.doc)
    .def("value", PiecewisePolynomial<double>::value,  py::arg("t"), doc.value.doc)
    .def("getPolynomialMatrix", PiecewisePolynomial<double>::getPolynomialMatrix,  py::arg("segment_index"), doc.getPolynomialMatrix.doc)
    .def("getPolynomial", PiecewisePolynomial<double>::getPolynomial,  py::arg("segment_index"), py::arg("row"), py::arg("col"), doc.getPolynomial.doc)
    .def("getSegmentPolynomialDegree", PiecewisePolynomial<double>::getSegmentPolynomialDegree,  py::arg("segment_index"), py::arg("row"), py::arg("col"), doc.getSegmentPolynomialDegree.doc)
    .def("rows", PiecewisePolynomial<double>::rows, , doc.rows.doc)
    .def("cols", PiecewisePolynomial<double>::cols, , doc.cols.doc)
    .def("isApprox", PiecewisePolynomial<double>::isApprox,  py::arg("other"), py::arg("tol"), doc.isApprox.doc)
    .def("ConcatenateInTime", PiecewisePolynomial<double>::ConcatenateInTime,  py::arg("other"), doc.ConcatenateInTime.doc)
    .def("shiftRight", PiecewisePolynomial<double>::shiftRight,  py::arg("offset"), doc.shiftRight.doc)
    .def("setPolynomialMatrixBlock", PiecewisePolynomial<double>::setPolynomialMatrixBlock,  py::arg("replacement"), py::arg("segment_index"), py::arg("row_start"), py::arg("col_start"), doc.setPolynomialMatrixBlock.doc)
    .def("slice", PiecewisePolynomial<double>::slice,  py::arg("start_segment_index"), py::arg("num_segments"), doc.slice.doc)
    .def("segmentValueAtGlobalAbscissa", PiecewisePolynomial<double>::segmentValueAtGlobalAbscissa,  py::arg("segment_index"), py::arg("t"), py::arg("row"), py::arg("col"), doc.segmentValueAtGlobalAbscissa.doc)
    .def_static("ComputeCubicSplineCoeffs", PiecewisePolynomial<double>::ComputeCubicSplineCoeffs,  py::arg("dt"), py::arg("y0"), py::arg("y1"), py::arg("yd0"), py::arg("yd1"), doc.ComputeCubicSplineCoeffs.doc)
    .def_static("SetupCubicSplineInteriorCoeffsLinearSystem", PiecewisePolynomial<double>::SetupCubicSplineInteriorCoeffsLinearSystem,  py::arg("breaks"), py::arg("knots"), py::arg("row"), py::arg("col"), py::arg("A"), py::arg("b"), doc.SetupCubicSplineInteriorCoeffsLinearSystem.doc)
    .def_static("ComputePchipEndSlope", PiecewisePolynomial<double>::ComputePchipEndSlope,  py::arg("dt0"), py::arg("dt1"), py::arg("slope0"), py::arg("slope1"), doc.ComputePchipEndSlope.doc)
    .def_static("CheckSplineGenerationInputValidityOrThrow", PiecewisePolynomial<double>::CheckSplineGenerationInputValidityOrThrow,  py::arg("breaks"), py::arg("knots"), py::arg("min_length"), doc.CheckSplineGenerationInputValidityOrThrow.doc)

  
}

}  // namespace pydrake
}  // namespace drake
