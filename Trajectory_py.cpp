
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

      .def("Clone", Trajectory<double>::Clone, , doc.Trajectory<double>.Clone.doc)
    .def("value", Trajectory<double>::value,  py::arg("t"), doc.Trajectory<double>.value.doc)
    .def("vector_values", Trajectory<double>::vector_values,  py::arg("t"), doc.Trajectory<double>.vector_values.doc)
    .def("MakeDerivative", Trajectory<double>::MakeDerivative,  py::arg("derivative_order"), doc.Trajectory<double>.MakeDerivative.doc)
    .def("rows", Trajectory<double>::rows, , doc.Trajectory<double>.rows.doc)
    .def("cols", Trajectory<double>::cols, , doc.Trajectory<double>.cols.doc)
    .def("start_time", Trajectory<double>::start_time, , doc.Trajectory<double>.start_time.doc)
    .def("end_time", Trajectory<double>::end_time, , doc.Trajectory<double>.end_time.doc)
    .def_static("DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE", Trajectory<double>::DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE, , doc.Trajectory<double>.DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE.doc)

  
}

}  // namespace pydrake
}  // namespace drake
