
#include "pybind11/eigen.h"
#include "pybind11/operators.h"
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "drake/bindings/pydrake/documentation_pybind.h"
#include "drake/bindings/pydrake/pydrake_pybind.h"

namespace drake {
namespace pydrake {
PYBIND11_MODULE(Trajectory_py,m) {
  py:class<Trajectory_py>(m, "Trajectory_py", doc.Trajectory_py.doc)
      .def(py::init<::drake::trajectories::Trajectory<double> const &>(), )
    .def(py::init<>(), )

      .def("Clone", Trajectory<double>::Clone, , doc.Clone.doc)
    .def("value", Trajectory<double>::value,  py::arg("t"), doc.value.doc)
    .def("MakeDerivative", Trajectory<double>::MakeDerivative,  py::arg("derivative_order"), doc.MakeDerivative.doc)
    .def("rows", Trajectory<double>::rows, , doc.rows.doc)
    .def("cols", Trajectory<double>::cols, , doc.cols.doc)
    .def("start_time", Trajectory<double>::start_time, , doc.start_time.doc)
    .def("end_time", Trajectory<double>::end_time, , doc.end_time.doc)
    .def_static("DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE", Trajectory<double>::DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE, , doc.DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE.doc)

  
}

}  // namespace pydrake
}  // namespace drake
