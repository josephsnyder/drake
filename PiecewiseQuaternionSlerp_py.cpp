
#include "pybind11/eigen.h"
#include "pybind11/operators.h"
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "drake/bindings/pydrake/documentation_pybind.h"
#include "drake/bindings/pydrake/pydrake_pybind.h"

namespace drake {
namespace pydrake {
PYBIND11_MODULE(PiecewiseQuaternionSlerp_py,m) {
  py:class<PiecewiseQuaternionSlerp_py>(m, "PiecewiseQuaternionSlerp_py", doc.PiecewiseQuaternionSlerp_py.doc)
      .def(py::init<::drake::trajectories::PiecewiseQuaternionSlerp<double> const &>(), )
    .def(py::init<>(), )
    .def(py::init<::std::vector<double, std::allocator<double> > const &,::std::vector<Eigen::Quaternion<double, 0>, std::allocator<Eigen::Quaternion<double, 0> > > const &>(), )
    .def(py::init<::std::vector<double, std::allocator<double> > const &,::std::vector<Eigen::Matrix<double, 3, 3, 0, 3, 3>, std::allocator<Eigen::Matrix<double, 3, 3, 0, 3, 3> > > const &>(), )
    .def(py::init<::std::vector<double, std::allocator<double> > const &,::std::vector<Eigen::AngleAxis<double>, std::allocator<Eigen::AngleAxis<double> > > const &>(), )

      .def_static("DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE", PiecewiseQuaternionSlerp<double>::DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE, , doc.DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE.doc)
    .def("Clone", PiecewiseQuaternionSlerp<double>::Clone, , doc.Clone.doc)
    .def("rows", PiecewiseQuaternionSlerp<double>::rows, , doc.rows.doc)
    .def("cols", PiecewiseQuaternionSlerp<double>::cols, , doc.cols.doc)
    .def("orientation", PiecewiseQuaternionSlerp<double>::orientation,  py::arg("t"), doc.orientation.doc)
    .def("value", PiecewiseQuaternionSlerp<double>::value,  py::arg("t"), doc.value.doc)
    .def("angular_velocity", PiecewiseQuaternionSlerp<double>::angular_velocity,  py::arg("t"), doc.angular_velocity.doc)
    .def("MakeDerivative", PiecewiseQuaternionSlerp<double>::MakeDerivative,  py::arg("derivative_order"), doc.MakeDerivative.doc)
    .def("angular_acceleration", PiecewiseQuaternionSlerp<double>::angular_acceleration,  py::arg("t"), doc.angular_acceleration.doc)
    .def("get_quaternion_knots", PiecewiseQuaternionSlerp<double>::get_quaternion_knots, , doc.get_quaternion_knots.doc)
    .def("is_approx", PiecewiseQuaternionSlerp<double>::is_approx,  py::arg("other"), py::arg("tol"), doc.is_approx.doc)
    .def("Initialize", PiecewiseQuaternionSlerp<double>::Initialize,  py::arg("breaks"), py::arg("quaternions"), doc.Initialize.doc)
    .def("ComputeAngularVelocities", PiecewiseQuaternionSlerp<double>::ComputeAngularVelocities, , doc.ComputeAngularVelocities.doc)
    .def("ComputeInterpTime", PiecewiseQuaternionSlerp<double>::ComputeInterpTime,  py::arg("segment_index"), py::arg("time"), doc.ComputeInterpTime.doc)

  
}

}  // namespace pydrake
}  // namespace drake
