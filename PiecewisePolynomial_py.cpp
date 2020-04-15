
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
    .def(py::init<::std::vector<Eigen::Matrix<drake::Polynomial<double>, -1, -1, 0, -1, -1>, std::allocator<Eigen::Matrix<drake::Polynomial<double>, -1, -1, 0, -1, -1> > > const &,::std::vector<double, std::allocator<double> > const &>(), )
    .def(py::init<::std::vector<drake::Polynomial<double>, std::allocator<drake::Polynomial<double> > > const &,::std::vector<double, std::allocator<double> > const &>(), )

      .def_static("DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE", PiecewisePolynomial<double>::DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE, , doc.PiecewisePolynomial.DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE.doc)
    .def("Clone", PiecewisePolynomial<double>::Clone, , doc.PiecewisePolynomial.Clone.doc)
    .def_static("ZeroOrderHold", py::overload_cast<::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &,::Eigen::Ref<const Eigen::Matrix<double, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1> > const &,>(ZeroOrderHold),,  py::arg("breaks") , py::arg("samples") , doc.PiecewisePolynomial.ZeroOrderHold.doc)
    .def_static("ZeroOrderHold", py::overload_cast<::std::vector<double, std::allocator<double> > const &,::std::vector<Eigen::Matrix<double, -1, -1, 0, -1, -1>, std::allocator<Eigen::Matrix<double, -1, -1, 0, -1, -1> > > const &,>(ZeroOrderHold),,  py::arg("breaks") , py::arg("samples") , doc.PiecewisePolynomial.ZeroOrderHold.doc)
    .def_static("FirstOrderHold", py::overload_cast<::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &,::Eigen::Ref<const Eigen::Matrix<double, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1> > const &,>(FirstOrderHold),,  py::arg("breaks") , py::arg("samples") , doc.PiecewisePolynomial.FirstOrderHold.doc)
    .def_static("FirstOrderHold", py::overload_cast<::std::vector<double, std::allocator<double> > const &,::std::vector<Eigen::Matrix<double, -1, -1, 0, -1, -1>, std::allocator<Eigen::Matrix<double, -1, -1, 0, -1, -1> > > const &,>(FirstOrderHold),,  py::arg("breaks") , py::arg("samples") , doc.PiecewisePolynomial.FirstOrderHold.doc)
    .def_static("CubicShapePreserving", py::overload_cast<::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &,::Eigen::Ref<const Eigen::Matrix<double, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1> > const &,bool,>(CubicShapePreserving),,  py::arg("breaks") , py::arg("samples") , py::arg("zero_end_point_derivatives") = false, doc.PiecewisePolynomial.CubicShapePreserving.doc)
    .def_static("CubicShapePreserving", py::overload_cast<::std::vector<double, std::allocator<double> > const &,::std::vector<Eigen::Matrix<double, -1, -1, 0, -1, -1>, std::allocator<Eigen::Matrix<double, -1, -1, 0, -1, -1> > > const &,bool,>(CubicShapePreserving),,  py::arg("breaks") , py::arg("samples") , py::arg("zero_end_point_derivatives") = false, doc.PiecewisePolynomial.CubicShapePreserving.doc)
    .def_static("Pchip", py::overload_cast<::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &,::Eigen::Ref<const Eigen::Matrix<double, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1> > const &,bool,>(Pchip),,  py::arg("breaks") , py::arg("samples") , py::arg("zero_end_point_derivatives") = false, doc.PiecewisePolynomial.Pchip.doc)
    .def_static("Pchip", py::overload_cast<::std::vector<double, std::allocator<double> > const &,::std::vector<Eigen::Matrix<double, -1, -1, 0, -1, -1>, std::allocator<Eigen::Matrix<double, -1, -1, 0, -1, -1> > > const &,bool,>(Pchip),,  py::arg("breaks") , py::arg("samples") , py::arg("zero_end_point_derivatives") = false, doc.PiecewisePolynomial.Pchip.doc)
    .def_static("CubicWithContinuousSecondDerivatives", py::overload_cast<::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &,::Eigen::Ref<const Eigen::Matrix<double, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1> > const &,::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &,::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &,>(CubicWithContinuousSecondDerivatives),,  py::arg("breaks") , py::arg("samples") , py::arg("sample_dot_at_start") , py::arg("sample_dot_at_end") , doc.PiecewisePolynomial.CubicWithContinuousSecondDerivatives.doc)
    .def_static("CubicWithContinuousSecondDerivatives", py::overload_cast<::std::vector<double, std::allocator<double> > const &,::std::vector<Eigen::Matrix<double, -1, -1, 0, -1, -1>, std::allocator<Eigen::Matrix<double, -1, -1, 0, -1, -1> > > const &,bool,>(CubicWithContinuousSecondDerivatives),,  py::arg("breaks") , py::arg("samples") , py::arg("periodic_end_condition") = false, doc.PiecewisePolynomial.CubicWithContinuousSecondDerivatives.doc)
    .def_static("CubicWithContinuousSecondDerivatives", py::overload_cast<::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &,::Eigen::Ref<const Eigen::Matrix<double, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1> > const &,bool,>(CubicWithContinuousSecondDerivatives),,  py::arg("breaks") , py::arg("samples") , py::arg("periodic_end_condition") = false, doc.PiecewisePolynomial.CubicWithContinuousSecondDerivatives.doc)
    .def_static("CubicWithContinuousSecondDerivatives", py::overload_cast<::std::vector<double, std::allocator<double> > const &,::std::vector<Eigen::Matrix<double, -1, -1, 0, -1, -1>, std::allocator<Eigen::Matrix<double, -1, -1, 0, -1, -1> > > const &,::Eigen::Matrix<double, -1, -1, 0, -1, -1> const &,::Eigen::Matrix<double, -1, -1, 0, -1, -1> const &,>(CubicWithContinuousSecondDerivatives),,  py::arg("breaks") , py::arg("samples") , py::arg("sample_dot_at_start") , py::arg("sample_dot_at_end") , doc.PiecewisePolynomial.CubicWithContinuousSecondDerivatives.doc)
    .def_static("Cubic", py::overload_cast<::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &,::Eigen::Ref<const Eigen::Matrix<double, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1> > const &,::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &,::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &,>(Cubic),,  py::arg("breaks") , py::arg("samples") , py::arg("sample_dot_at_start") , py::arg("sample_dot_at_end") , doc.PiecewisePolynomial.Cubic.doc)
    .def_static("Cubic", py::overload_cast<::std::vector<double, std::allocator<double> > const &,::std::vector<Eigen::Matrix<double, -1, -1, 0, -1, -1>, std::allocator<Eigen::Matrix<double, -1, -1, 0, -1, -1> > > const &,::std::vector<Eigen::Matrix<double, -1, -1, 0, -1, -1>, std::allocator<Eigen::Matrix<double, -1, -1, 0, -1, -1> > > const &,>(Cubic),,  py::arg("breaks") , py::arg("samples") , py::arg("samples_dot") , doc.PiecewisePolynomial.Cubic.doc)
    .def_static("Cubic", py::overload_cast<::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &,::Eigen::Ref<const Eigen::Matrix<double, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1> > const &,::Eigen::Ref<const Eigen::Matrix<double, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1> > const &,>(Cubic),,  py::arg("breaks") , py::arg("samples") , py::arg("samples_dot") , doc.PiecewisePolynomial.Cubic.doc)
    .def_static("Cubic", py::overload_cast<::std::vector<double, std::allocator<double> > const &,::std::vector<Eigen::Matrix<double, -1, -1, 0, -1, -1>, std::allocator<Eigen::Matrix<double, -1, -1, 0, -1, -1> > > const &,bool,>(Cubic),,  py::arg("breaks") , py::arg("samples") , py::arg("periodic_end_condition") = false, doc.PiecewisePolynomial.Cubic.doc)
    .def_static("Cubic", py::overload_cast<::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &,::Eigen::Ref<const Eigen::Matrix<double, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1> > const &,bool,>(Cubic),,  py::arg("breaks") , py::arg("samples") , py::arg("periodic_end_condition") = false, doc.PiecewisePolynomial.Cubic.doc)
    .def_static("Cubic", py::overload_cast<::std::vector<double, std::allocator<double> > const &,::std::vector<Eigen::Matrix<double, -1, -1, 0, -1, -1>, std::allocator<Eigen::Matrix<double, -1, -1, 0, -1, -1> > > const &,::Eigen::Matrix<double, -1, -1, 0, -1, -1> const &,::Eigen::Matrix<double, -1, -1, 0, -1, -1> const &,>(Cubic),,  py::arg("breaks") , py::arg("samples") , py::arg("sample_dot_at_start") , py::arg("sample_dot_at_end") , doc.PiecewisePolynomial.Cubic.doc)
    .def_static("CubicHermite", py::overload_cast<::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &,::Eigen::Ref<const Eigen::Matrix<double, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1> > const &,::Eigen::Ref<const Eigen::Matrix<double, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1> > const &,>(CubicHermite),,  py::arg("breaks") , py::arg("samples") , py::arg("samples_dot") , doc.PiecewisePolynomial.CubicHermite.doc)
    .def_static("CubicHermite", py::overload_cast<::std::vector<double, std::allocator<double> > const &,::std::vector<Eigen::Matrix<double, -1, -1, 0, -1, -1>, std::allocator<Eigen::Matrix<double, -1, -1, 0, -1, -1> > > const &,::std::vector<Eigen::Matrix<double, -1, -1, 0, -1, -1>, std::allocator<Eigen::Matrix<double, -1, -1, 0, -1, -1> > > const &,>(CubicHermite),,  py::arg("breaks") , py::arg("samples") , py::arg("samples_dot") , doc.PiecewisePolynomial.CubicHermite.doc)
    .def("derivative", PiecewisePolynomial<double>::derivative,  py::arg("derivative_order") = 1, doc.PiecewisePolynomial.derivative.doc)
    .def("MakeDerivative", PiecewisePolynomial<double>::MakeDerivative,  py::arg("derivative_order") = 1, doc.PiecewisePolynomial.MakeDerivative.doc)
    .def("integral", py::overload_cast<::Eigen::Ref<Eigen::Matrix<double, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1> > const &,>(integral),,  py::arg("value_at_start_time") , doc.PiecewisePolynomial.integral.doc)
    .def("integral", py::overload_cast<double const &,>(integral),,  py::arg("value_at_start_time") = 0., doc.PiecewisePolynomial.integral.doc)
    .def("empty", PiecewisePolynomial<double>::empty, , doc.PiecewisePolynomial.empty.doc)
    .def("scalarValue", PiecewisePolynomial<double>::scalarValue,  py::arg("t") , py::arg("row") = 0, py::arg("col") = 0, doc.PiecewisePolynomial.scalarValue.doc)
    .def("value", PiecewisePolynomial<double>::value,  py::arg("t") , doc.PiecewisePolynomial.value.doc)
    .def("EvalDerivative", PiecewisePolynomial<double>::EvalDerivative,  py::arg("t") , py::arg("derivative_order") = 1, doc.PiecewisePolynomial.EvalDerivative.doc)
    .def("getPolynomialMatrix", PiecewisePolynomial<double>::getPolynomialMatrix,  py::arg("segment_index") , doc.PiecewisePolynomial.getPolynomialMatrix.doc)
    .def("getPolynomial", PiecewisePolynomial<double>::getPolynomial,  py::arg("segment_index") , py::arg("row") = 0, py::arg("col") = 0, doc.PiecewisePolynomial.getPolynomial.doc)
    .def("getSegmentPolynomialDegree", PiecewisePolynomial<double>::getSegmentPolynomialDegree,  py::arg("segment_index") , py::arg("row") = 0, py::arg("col") = 0, doc.PiecewisePolynomial.getSegmentPolynomialDegree.doc)
    .def("rows", PiecewisePolynomial<double>::rows, , doc.PiecewisePolynomial.rows.doc)
    .def("cols", PiecewisePolynomial<double>::cols, , doc.PiecewisePolynomial.cols.doc)
    .def("isApprox", PiecewisePolynomial<double>::isApprox,  py::arg("other") , py::arg("tol") , doc.PiecewisePolynomial.isApprox.doc)
    .def("ConcatenateInTime", PiecewisePolynomial<double>::ConcatenateInTime,  py::arg("other") , doc.PiecewisePolynomial.ConcatenateInTime.doc)
    .def("AppendCubicHermiteSegment", PiecewisePolynomial<double>::AppendCubicHermiteSegment,  py::arg("time") , py::arg("sample") , py::arg("sample_dot") , doc.PiecewisePolynomial.AppendCubicHermiteSegment.doc)
    .def("RemoveFinalSegment", PiecewisePolynomial<double>::RemoveFinalSegment, , doc.PiecewisePolynomial.RemoveFinalSegment.doc)
    .def("ReverseTime", PiecewisePolynomial<double>::ReverseTime, , doc.PiecewisePolynomial.ReverseTime.doc)
    .def("ScaleTime", PiecewisePolynomial<double>::ScaleTime,  py::arg("scale") , doc.PiecewisePolynomial.ScaleTime.doc)
    .def("shiftRight", PiecewisePolynomial<double>::shiftRight,  py::arg("offset") , doc.PiecewisePolynomial.shiftRight.doc)
    .def("setPolynomialMatrixBlock", PiecewisePolynomial<double>::setPolynomialMatrixBlock,  py::arg("replacement") , py::arg("segment_index") , py::arg("row_start") = 0, py::arg("col_start") = 0, doc.PiecewisePolynomial.setPolynomialMatrixBlock.doc)
    .def("slice", PiecewisePolynomial<double>::slice,  py::arg("start_segment_index") , py::arg("num_segments") , doc.PiecewisePolynomial.slice.doc)
    .def("EvaluateSegmentAbsoluteTime", PiecewisePolynomial<double>::EvaluateSegmentAbsoluteTime,  py::arg("segment_index") , py::arg("t") , py::arg("row") , py::arg("col") , py::arg("derivative_order") = 0, doc.PiecewisePolynomial.EvaluateSegmentAbsoluteTime.doc)
    .def_static("ComputeCubicSplineCoeffs", PiecewisePolynomial<double>::ComputeCubicSplineCoeffs,  py::arg("dt") , py::arg("y0") , py::arg("y1") , py::arg("yd0") , py::arg("yd1") , doc.PiecewisePolynomial.ComputeCubicSplineCoeffs.doc)
    .def_static("SetupCubicSplineInteriorCoeffsLinearSystem", PiecewisePolynomial<double>::SetupCubicSplineInteriorCoeffsLinearSystem,  py::arg("breaks") , py::arg("samples") , py::arg("row") , py::arg("col") , py::arg("A") , py::arg("b") , doc.PiecewisePolynomial.SetupCubicSplineInteriorCoeffsLinearSystem.doc)
    .def_static("CheckSplineGenerationInputValidityOrThrow", PiecewisePolynomial<double>::CheckSplineGenerationInputValidityOrThrow,  py::arg("breaks") , py::arg("samples") , py::arg("min_length") , doc.PiecewisePolynomial.CheckSplineGenerationInputValidityOrThrow.doc)

  
}

}  // namespace pydrake
}  // namespace drake
