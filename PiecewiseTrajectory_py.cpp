
#include "pybind11/eigen.h"
#include "pybind11/operators.h"
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "drake/bindings/pydrake/documentation_pybind.h"
#include "drake/bindings/pydrake/pydrake_pybind.h"

namespace drake {
namespace pydrake {
PYBIND11_MODULE(PiecewiseTrajectory_py,m) {
  py:class<PiecewiseTrajectory_py>(m, "PiecewiseTrajectory_py", doc.PiecewiseTrajectory_py.doc)
      .def(py::init<::drake::trajectories::PiecewiseTrajectory<double> const &>(), )
    .def(py::init<>(), )
    .def(py::init<::std::vector<double, std::allocator<double> > const &>(), )

      .def("get_number_of_segments", PiecewiseTrajectory<double>::get_number_of_segments, , doc.get_number_of_segments.doc)
    .def("start_time", py::overload_cast<>(start_time),, , doc.start_time.doc)
    .def("start_time", py::overload_cast<int,>(start_time),,  py::arg("segment_number"), doc.start_time.doc)
    .def("end_time", py::overload_cast<>(end_time),, , doc.end_time.doc)
    .def("end_time", py::overload_cast<int,>(end_time),,  py::arg("segment_number"), doc.end_time.doc)
    .def("duration", PiecewiseTrajectory<double>::duration,  py::arg("segment_number"), doc.duration.doc)
    .def("is_time_in_range", PiecewiseTrajectory<double>::is_time_in_range,  py::arg("t"), doc.is_time_in_range.doc)
    .def("get_segment_index", PiecewiseTrajectory<double>::get_segment_index,  py::arg("t"), doc.get_segment_index.doc)
    .def("get_segment_times", PiecewiseTrajectory<double>::get_segment_times, , doc.get_segment_times.doc)
    .def("segment_number_range_check", PiecewiseTrajectory<double>::segment_number_range_check,  py::arg("segment_number"), doc.segment_number_range_check.doc)
    .def_static("RandomSegmentTimes", PiecewiseTrajectory<double>::RandomSegmentTimes,  py::arg("num_segments"), py::arg("generator"), doc.RandomSegmentTimes.doc)
    .def_static("DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE", PiecewiseTrajectory<double>::DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE, , doc.DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE.doc)
    .def("SegmentTimesEqual", PiecewiseTrajectory<double>::SegmentTimesEqual,  py::arg("b"), py::arg("tol"), doc.SegmentTimesEqual.doc)
    .def("breaks", PiecewiseTrajectory<double>::breaks, , doc.breaks.doc)
    .def("get_mutable_breaks", PiecewiseTrajectory<double>::get_mutable_breaks, , doc.get_mutable_breaks.doc)
    .def("GetSegmentIndexRecursive", PiecewiseTrajectory<double>::GetSegmentIndexRecursive,  py::arg("time"), py::arg("start"), py::arg("end"), doc.GetSegmentIndexRecursive.doc)

  
}

}  // namespace pydrake
}  // namespace drake
