
#include "pybind11/eigen.h"
#include "pybind11/operators.h"
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "drake/bindings/pydrake/documentation_pybind.h"
#include "drake/bindings/pydrake/pydrake_pybind.h"

namespace drake {
namespace pydrake {
PYBIND11_MODULE(RigidTransform_py,m) {
  py:class<RigidTransform_py>(m, "RigidTransform_py", doc.RigidTransform_py.doc)
      .def(py::init<::drake::math::RigidTransform<double> const &>(), )
    .def(py::init<>(), )
    .def(py::init<::drake::math::RotationMatrix<double> const &,::Eigen::Matrix<double, 3, 1, 0, 3, 1> const &>(), )
    .def(py::init<::drake::math::RollPitchYaw<double> const &,::Eigen::Matrix<double, 3, 1, 0, 3, 1> const &>(), )
    .def(py::init<::Eigen::Quaternion<double, 0> const &,::Eigen::Matrix<double, 3, 1, 0, 3, 1> const &>(), )
    .def(py::init<::Eigen::AngleAxis<double> const &,::Eigen::Matrix<double, 3, 1, 0, 3, 1> const &>(), )
    .def(py::init<::drake::math::RotationMatrix<double> const &>(), )
    .def(py::init<::Eigen::Matrix<double, 3, 1, 0, 3, 1> const &>(), )
    .def(py::init<::Eigen::Translation<double, 3> const &>(), )
    .def(py::init<::Eigen::Transform<double, 3, 1, 0> const &>(), )
    .def(py::init<::Eigen::Matrix<double, 3, 4, 0, 3, 4> const>(), )
    .def(py::init<::Eigen::Matrix<double, 4, 4, 0, 4, 4> const &>(), )

      .def_static("DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE", RigidTransform<double>::DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE, , doc.DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE.doc)
    .def("set", RigidTransform<double>::set,  py::arg("R"), py::arg("p"), doc.set.doc)
    .def("SetFromIsometry3", RigidTransform<double>::SetFromIsometry3,  py::arg("pose"), doc.SetFromIsometry3.doc)
    .def_static("Identity", RigidTransform<double>::Identity, , doc.Identity.doc)
    .def("rotation", RigidTransform<double>::rotation, , doc.rotation.doc)
    .def("set_rotation", py::overload_cast<::drake::math::RollPitchYaw<double> const &,>(set_rotation),,  py::arg("rpy"), doc.set_rotation.doc)
    .def("set_rotation", py::overload_cast<::Eigen::Quaternion<double, 0> const &,>(set_rotation),,  py::arg("quaternion"), doc.set_rotation.doc)
    .def("set_rotation", py::overload_cast<::Eigen::AngleAxis<double> const &,>(set_rotation),,  py::arg("theta_lambda"), doc.set_rotation.doc)
    .def("set_rotation", py::overload_cast<::drake::math::RotationMatrix<double> const &,>(set_rotation),,  py::arg("R"), doc.set_rotation.doc)
    .def("translation", RigidTransform<double>::translation, , doc.translation.doc)
    .def("set_translation", RigidTransform<double>::set_translation,  py::arg("p"), doc.set_translation.doc)
    .def("GetAsMatrix4", RigidTransform<double>::GetAsMatrix4, , doc.GetAsMatrix4.doc)
    .def("GetAsMatrix34", RigidTransform<double>::GetAsMatrix34, , doc.GetAsMatrix34.doc)
    .def("GetAsIsometry3", RigidTransform<double>::GetAsIsometry3, , doc.GetAsIsometry3.doc)
    .def("SetIdentity", RigidTransform<double>::SetIdentity, , doc.SetIdentity.doc)
    .def("IsExactlyIdentity", RigidTransform<double>::IsExactlyIdentity, , doc.IsExactlyIdentity.doc)
    .def("IsIdentityToEpsilon", RigidTransform<double>::IsIdentityToEpsilon,  py::arg("translation_tolerance"), doc.IsIdentityToEpsilon.doc)
    .def("inverse", RigidTransform<double>::inverse, , doc.inverse.doc)
    .def("linear", RigidTransform<double>::linear, , doc.linear.doc)
    .def("matrix", RigidTransform<double>::matrix, , doc.matrix.doc)
    .def("IsNearlyEqualTo", RigidTransform<double>::IsNearlyEqualTo,  py::arg("other"), py::arg("tolerance"), doc.IsNearlyEqualTo.doc)
    .def("IsExactlyEqualTo", RigidTransform<double>::IsExactlyEqualTo,  py::arg("other"), doc.IsExactlyEqualTo.doc)
    .def("GetMaximumAbsoluteDifference", RigidTransform<double>::GetMaximumAbsoluteDifference,  py::arg("other"), doc.GetMaximumAbsoluteDifference.doc)
    .def("GetMaximumAbsoluteTranslationDifference", RigidTransform<double>::GetMaximumAbsoluteTranslationDifference,  py::arg("other"), doc.GetMaximumAbsoluteTranslationDifference.doc)
    .def_static("ThrowIfInvalidBottomRow", RigidTransform<double>::ThrowIfInvalidBottomRow,  py::arg("pose"), doc.ThrowIfInvalidBottomRow.doc)

  
}

}  // namespace pydrake
}  // namespace drake
