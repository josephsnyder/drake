#include "drake/math/rotation_matrix.h"
#include <pybind11/eigen.h>
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;
void apb11_pydrake_RollPitchYaw_py_register(py::module &m) {
  static bool called = false;
  if (called) {
    return;
  }
  called = true;
  py::class_<::drake::math::RollPitchYaw<double>> RollPitchYaw_double(
      m, "RollPitchYaw_double", "");

  RollPitchYaw_double
      .def(py::init<::drake::math::RollPitchYaw<double> const &>(),
           py::arg("arg0"))
      .def(py::init<
               Eigen::Ref<::Eigen::Matrix<double, 3, 1, 0, 3, 1> const &, 0,
                          Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &>(),
           py::arg("rpy"))
      .def(py::init<double const &, double const &, double const &>(),
           py::arg("roll"), py::arg("pitch"), py::arg("yaw"))
      .def(py::init<::drake::math::RotationMatrix<double> const &>(),
           py::arg("R"))
      .def(py::init<::Eigen::Quaternion<double, 0> const &>(),
           py::arg("quaternion"))
      .def_static("DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE",
                  static_cast<void (*)()>(
                      &::drake::math::RollPitchYaw<
                          double>::DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE),
                  "")
      .def("set",
           [](::drake::math::RollPitchYaw<double> &self,
              Eigen::Ref<::Eigen::Matrix<double, 3, 1, 0, 3, 1> const &, 0,
                         Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &rpy) {
             return self.set(rpy);
           })
      .def(
          "set",
          static_cast<::drake::math::RollPitchYaw<double> &(
              ::drake::math::RollPitchYaw<double>::*)(double const &,
                                                      double const &,
                                                      double const &)>(
              &::drake::math::RollPitchYaw<double>::set),
          py::arg("roll"), py::arg("pitch"), py::arg("yaw"),
          "/// Sets `this` %RollPitchYaw from roll, pitch, yaw angles (units of radians). \
/// @param[in] roll x-directed angle in SpaceXYZ rotation sequence. \
/// @param[in] pitch y-directed angle in SpaceXYZ rotation sequence. \
/// @param[in] yaw z-directed angle in SpaceXYZ rotation sequence. \
/// @throws std::exception in debug builds if \
/// !IsValid(Vector3<T>(roll, pitch, yaw)).")
      .def("SetFromQuaternion",
           [](::drake::math::RollPitchYaw<double> &self,
              ::Eigen::Quaternion<double, 0> const &quaternion) {
             return self.SetFromQuaternion(quaternion);
           })
      .def(
          "SetFromRotationMatrix",
          static_cast<void (::drake::math::RollPitchYaw<double>::*)(
              ::drake::math::RotationMatrix<double> const &)>(
              &::drake::math::RollPitchYaw<double>::SetFromRotationMatrix),
          py::arg("R"),
          "/// Uses a high-accuracy efficient algorithm to set the roll-pitch-yaw \
/// angles `[r, p, y]` that underlie `this` @RollPitchYaw, even when the pitch \
/// angle p is very near a singularity (when p is within 1E-6 of π/2 or -π/2). \
/// After calling this method, the underlying roll-pitch-yaw `[r, p, y]` has \
/// range `-π <= r <= π`, `-π/2 <= p <= π/2`, `-π <= y <= π`. \
/// @param[in] R a %RotationMatrix. \
/// @note This high-accuracy algorithm was invented at TRI in October 2016 and \
/// avoids numerical round-off issues encountered by some algorithms when \
/// pitch is within 1E-6 of π/2 or -π/2.")
      .def("vector",
           static_cast<::Eigen::Matrix<double, 3, 1, 0, 3, 1> const &(
               ::drake::math::RollPitchYaw<double>::*)() const>(
               &::drake::math::RollPitchYaw<double>::vector),
           "/// Returns the Vector3 underlying `this` %RollPitchYaw.",
           py::return_value_policy::reference_internal)
      .def("roll_angle",
           static_cast<double const &(::drake::math::RollPitchYaw<double>::*)()
                           const>(
               &::drake::math::RollPitchYaw<double>::roll_angle),
           "/// Returns the roll-angle underlying `this` %RollPitchYaw.")
      .def("pitch_angle",
           static_cast<double const &(::drake::math::RollPitchYaw<double>::*)()
                           const>(
               &::drake::math::RollPitchYaw<double>::pitch_angle),
           "/// Returns the pitch-angle underlying `this` %RollPitchYaw.")
      .def("yaw_angle",
           static_cast<double const &(::drake::math::RollPitchYaw<double>::*)()
                           const>(
               &::drake::math::RollPitchYaw<double>::yaw_angle),
           "/// Returns the yaw-angle underlying `this` %RollPitchYaw.")
      .def("set_roll_angle",
           static_cast<void (::drake::math::RollPitchYaw<double>::*)(
               double const &)>(
               &::drake::math::RollPitchYaw<double>::set_roll_angle),
           py::arg("r"),
           "/// Set the roll-angle underlying `this` %RollPitchYaw. \
/// @param[in] r roll angle (in units of radians).")
      .def("set_pitch_angle",
           static_cast<void (::drake::math::RollPitchYaw<double>::*)(
               double const &)>(
               &::drake::math::RollPitchYaw<double>::set_pitch_angle),
           py::arg("p"),
           "/// Set the pitch-angle underlying `this` %RollPitchYaw. \
/// @param[in] p pitch angle (in units of radians).")
      .def("set_yaw_angle",
           static_cast<void (::drake::math::RollPitchYaw<double>::*)(
               double const &)>(
               &::drake::math::RollPitchYaw<double>::set_yaw_angle),
           py::arg("y"),
           "/// Set the yaw-angle underlying `this` %RollPitchYaw. \
/// @param[in] y yaw angle (in units of radians).")
      .def("ToQuaternion",
           static_cast<::Eigen::Quaternion<double, 0> (
               ::drake::math::RollPitchYaw<double>::*)() const>(
               &::drake::math::RollPitchYaw<double>::ToQuaternion),
           "/// Returns a quaternion representation of `this` %RollPitchYaw.")
      .def("ToRotationMatrix",
           static_cast<::drake::math::RotationMatrix<double> (
               ::drake::math::RollPitchYaw<double>::*)() const>(
               &::drake::math::RollPitchYaw<double>::ToRotationMatrix),
           "/// Returns the RotationMatrix representation of `this` "
           "%RollPitchYaw.")
      .def(
          "ToMatrix3ViaRotationMatrix",
          static_cast<::Eigen::Matrix<double, 3, 3, 0, 3, 3> (
              ::drake::math::RollPitchYaw<double>::*)() const>(
              &::drake::math::RollPitchYaw<double>::ToMatrix3ViaRotationMatrix),
          "/// Returns the 3x3 matrix representation of the %RotationMatrix that \
/// corresponds to `this` %RollPitchYaw.  This is a convenient " sugar
          " method \
/// that is exactly equivalent to RotationMatrix(rpy).ToMatrix3().")
      .def(
          "IsNearlyEqualTo",
          static_cast<::drake::scalar_predicate<double>::type (
              ::drake::math::RollPitchYaw<double>::*)(
              ::drake::math::RollPitchYaw<double> const &, double) const>(
              &::drake::math::RollPitchYaw<double>::IsNearlyEqualTo),
          py::arg("other"), py::arg("tolerance"),
          "/// Compares each element of `this` to the corresponding element of `other` \
/// to check if they are the same to within a specified `tolerance`. \
/// @param[in] other %RollPitchYaw to compare to `this`. \
/// @param[in] tolerance maximum allowable absolute difference between the \
/// matrix elements in `this` and `other`. \
/// @returns `true` if `‖this - other‖∞ <= tolerance`.")
      .def(
          "IsNearlySameOrientation",
          static_cast<::drake::scalar_predicate<double>::type (
              ::drake::math::RollPitchYaw<double>::*)(
              ::drake::math::RollPitchYaw<double> const &, double) const>(
              &::drake::math::RollPitchYaw<double>::IsNearlySameOrientation),
          py::arg("other"), py::arg("tolerance"),
          "/// Compares each element of the %RotationMatrix R1 produced by `this` to the \
/// corresponding element of the %RotationMatrix R2 produced by `other` to \
/// check if they are the same to within a specified `tolerance`. \
/// @param[in] other %RollPitchYaw to compare to `this`. \
/// @param[in] tolerance maximum allowable absolute difference between R1, R2. \
/// @returns `true` if `‖R1 - R2‖∞ <= tolerance`.")
      .def(
          "IsRollPitchYawInCanonicalRange",
          static_cast<::drake::scalar_predicate<double>::type (
              ::drake::math::RollPitchYaw<double>::*)() const>(
              &::drake::math::RollPitchYaw<
                  double>::IsRollPitchYawInCanonicalRange),
          "/// Returns true if roll-pitch-yaw angles `[r, p, y]` are in the range \
/// `-π <= r <= π`, `-π/2 <= p <= π/2`, `-π <= y <= π`.")
      .def_static(
          "DoesCosPitchAngleViolateGimbalLockTolerance",
          static_cast<::drake::scalar_predicate<double>::type (*)(
              double const &)>(
              &::drake::math::RollPitchYaw<
                  double>::DoesCosPitchAngleViolateGimbalLockTolerance),
          py::arg("cos_pitch_angle"),
          "/// Returns true if the pitch-angle `p` is close to gimbal-lock, which means \
/// `cos(p) ≈ 0` or `p ≈ (n*π + π/2)` where `n = 0, ±1, ±2, ...`. \
/// More specifically, returns true if `abs(cos_pitch_angle)` is less than an \
/// internally-defined tolerance of gimbal-lock. \
/// @param[in] cos_pitch_angle cosine of the pitch angle, i.e., `cos(p)`. \
/// @note Pitch-angles close to gimbal-lock can can cause problems with \
/// numerical precision and numerical integration.")
      .def(
          "DoesPitchAngleViolateGimbalLockTolerance",
          static_cast<::drake::scalar_predicate<double>::type (
              ::drake::math::RollPitchYaw<double>::*)() const>(
              &::drake::math::RollPitchYaw<
                  double>::DoesPitchAngleViolateGimbalLockTolerance),
          "/// Returns true if the pitch-angle `p` is within an internally-defined \
/// tolerance of gimbal-lock.  In other words, this method returns true if \
/// `p ≈ (n*π + π/2)` where `n = 0, ±1, ±2, ...`. \
/// @note To improve efficiency when cos(pitch_angle()) is already calculated, \
/// instead use the function DoesCosPitchAngleViolateGimbalLockTolerance(). \
/// @see DoesCosPitchAngleViolateGimbalLockTolerance()")
      .def_static(
          "GimbalLockPitchAngleTolerance",
          static_cast<double (*)()>(&::drake::math::RollPitchYaw<
                                    double>::GimbalLockPitchAngleTolerance),
          "/// Returns the internally-defined allowable closeness (in radians) of the \
/// pitch angle `p` to gimbal-lock, i.e., the allowable proximity of `p` to \
/// `(n*π + π/2)` where `n = 0, ±1, ±2, ...`.")
      .def("IsValid",
           [](::drake::math::RollPitchYaw<double> &self,
              Eigen::Ref<::Eigen::Matrix<double, 3, 1, 0, 3, 1> const &, 0,
                         Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &rpy) {
             return self.IsValid(rpy);
           })
      .def(
          "CalcRotationMatrixDt",
          [](::drake::math::RollPitchYaw<double> &self,
             Eigen::Ref<::Eigen::Matrix<double, 3, 1, 0, 3, 1> const &, 0,
                        Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &rpyDt) {
            return self.CalcRotationMatrixDt(rpyDt);
          })
      .def(
          "CalcAngularVelocityInParentFromRpyDt",
          [](::drake::math::RollPitchYaw<double> &self,
             Eigen::Ref<::Eigen::Matrix<double, 3, 1, 0, 3, 1> const &, 0,
                        Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &rpyDt) {
            return self.CalcAngularVelocityInParentFromRpyDt(rpyDt);
          })
      .def(
          "CalcAngularVelocityInChildFromRpyDt",
          [](::drake::math::RollPitchYaw<double> &self,
             Eigen::Ref<::Eigen::Matrix<double, 3, 1, 0, 3, 1> const &, 0,
                        Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &rpyDt) {
            return self.CalcAngularVelocityInChildFromRpyDt(rpyDt);
          })
      .def("CalcRpyDtFromAngularVelocityInParent",
           [](::drake::math::RollPitchYaw<double> &self,
              Eigen::Ref<::Eigen::Matrix<double, 3, 1, 0, 3, 1> const &, 0,
                         Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                  &w_AD_A) {
             return self.CalcRpyDtFromAngularVelocityInParent(w_AD_A);
           })
      .def(
          "CalcMatrixRelatingRpyDtToAngularVelocityInParent",
          static_cast<::Eigen::Matrix<double, 3, 3, 0, 3, 3> const (
              ::drake::math::RollPitchYaw<double>::*)() const>(
              &::drake::math::RollPitchYaw<
                  double>::CalcMatrixRelatingRpyDtToAngularVelocityInParent),
          "/// For `this` %RollPitchYaw with roll-pitch-yaw angles `[r; p; y]` which \
/// relate the orientation of two generic frames A and D, returns the 3x3 \
/// matrix M that contains the partial derivatives of [ṙ, ṗ, ẏ] with respect \
/// to `[wx; wy; wz]ₐ` (which is w_AD_A expressed in A). \
/// In other words, `rpyDt = M * w_AD_A`. \
/// @param[in] function_name name of the calling function/method. \
/// @throws std::exception if `cos(p) ≈ 0` (`p` is near gimbal-lock). \
/// @note This method has a divide-by-zero error (singularity) when the cosine \
/// of the pitch angle `p` is zero [i.e., `cos(p) = 0`].  This problem (called \
/// " gimbal lock ") occurs when `p = n π  + π / 2`, where n is any integer. \
/// There are associated precision problems (inaccuracies) in the neighborhood \
/// of these pitch angles, i.e., when `cos(p) ≈ 0`.")
      .def("CalcRpyDDtFromRpyDtAndAngularAccelInParent",
           [](::drake::math::RollPitchYaw<double> &self,
              Eigen::Ref<::Eigen::Matrix<double, 3, 1, 0, 3, 1> const &, 0,
                         Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &rpyDt,
              Eigen::Ref<::Eigen::Matrix<double, 3, 1, 0, 3, 1> const &, 0,
                         Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                  &alpha_AD_A) {
             return self.CalcRpyDDtFromRpyDtAndAngularAccelInParent(rpyDt,
                                                                    alpha_AD_A);
           })
      .def("CalcRpyDDtFromAngularAccelInChild",
           [](::drake::math::RollPitchYaw<double> &self,
              Eigen::Ref<::Eigen::Matrix<double, 3, 1, 0, 3, 1> const &, 0,
                         Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &rpyDt,
              Eigen::Ref<::Eigen::Matrix<double, 3, 1, 0, 3, 1> const &, 0,
                         Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                  &alpha_AD_D) {
             return self.CalcRpyDDtFromAngularAccelInChild(rpyDt, alpha_AD_D);
           })

      ;

  py::class_<
      ::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<Eigen::VectorXd>>>
      RollPitchYaw_Eigen_AutoDiffScalar_Eigen_VectorXd(
          m, "RollPitchYaw_Eigen_AutoDiffScalar_Eigen_VectorXd", "");

  RollPitchYaw_Eigen_AutoDiffScalar_Eigen_VectorXd
      .def(py::init<::drake::math::RollPitchYaw<
               Eigen::AutoDiffScalar<Eigen::VectorXd>> const &>(),
           py::arg("arg0"))
      .def(
          py::init<
              Eigen::Ref<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                         3, 1, 0, 3, 1> const &,
                         0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &>(),
          py::arg("rpy"))
      .def(
          py::init<
              Eigen::Ref<::Eigen::AutoDiffScalar<
                             Eigen::Matrix<double, -1, 1, 0, -1, 1>> const &,
                         0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &,
              Eigen::Ref<::Eigen::AutoDiffScalar<
                             Eigen::Matrix<double, -1, 1, 0, -1, 1>> const &,
                         0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &,
              Eigen::Ref<::Eigen::AutoDiffScalar<
                             Eigen::Matrix<double, -1, 1, 0, -1, 1>> const &,
                         0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &>(),
          py::arg("roll"), py::arg("pitch"), py::arg("yaw"))
      .def(
          py::init<
              Eigen::Ref<::drake::math::RotationMatrix<
                             Eigen::AutoDiffScalar<Eigen::VectorXd>> const &,
                         0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &>(),
          py::arg("R"))
      .def(py::init<::Eigen::Quaternion<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                        0> const &>(),
           py::arg("quaternion"))
      .def_static(
          "DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE",
          static_cast<void (*)()>(
              &::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<
                  Eigen::VectorXd>>::DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE),
          "")
      .def(
          "set",
          [](::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<Eigen::VectorXd>>
                 &self,
             Eigen::Ref<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                        3, 1, 0, 3, 1> const &,
                        0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                 &rpy) { return self.set(rpy); },
          py::return_value_policy::reference_internal)
      .def(
          "set",
          [](::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<Eigen::VectorXd>>
                 &self,
             Eigen::Ref<::Eigen::AutoDiffScalar<
                            Eigen::Matrix<double, -1, 1, 0, -1, 1>> const &,
                        0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &roll,
             Eigen::Ref<::Eigen::AutoDiffScalar<
                            Eigen::Matrix<double, -1, 1, 0, -1, 1>> const &,
                        0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                 &pitch,
             Eigen::Ref<::Eigen::AutoDiffScalar<
                            Eigen::Matrix<double, -1, 1, 0, -1, 1>> const &,
                        0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                 &yaw) { return self.set(roll, pitch, yaw); },
          py::return_value_policy::reference_internal)
      .def(
          "SetFromQuaternion",
          [](::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<Eigen::VectorXd>>
                 &self,
             ::Eigen::Quaternion<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                 0> const &quaternion) {
            return self.SetFromQuaternion(quaternion);
          })
      .def(
          "SetFromRotationMatrix",
          [](::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<Eigen::VectorXd>>
                 &self,
             Eigen::Ref<::drake::math::RotationMatrix<
                            Eigen::AutoDiffScalar<Eigen::VectorXd>> const &,
                        0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &R) {
            return self.SetFromRotationMatrix(R);
          })
      .def("vector",
           static_cast<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                       3, 1, 0, 3, 1> const
                           &(::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<
                                 Eigen::VectorXd>>::*)() const>(
               &::drake::math::RollPitchYaw<
                   Eigen::AutoDiffScalar<Eigen::VectorXd>>::vector),
           "/// Returns the Vector3 underlying `this` %RollPitchYaw.",
           py::return_value_policy::reference_internal)
      .def("roll_angle",
           static_cast<::Eigen::AutoDiffScalar<
               Eigen::Matrix<double, -1, 1, 0, -1, 1>> const
                           &(::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<
                                 Eigen::VectorXd>>::*)() const>(
               &::drake::math::RollPitchYaw<
                   Eigen::AutoDiffScalar<Eigen::VectorXd>>::roll_angle),
           "/// Returns the roll-angle underlying `this` %RollPitchYaw.",
           py::return_value_policy::reference_internal)
      .def("pitch_angle",
           static_cast<::Eigen::AutoDiffScalar<
               Eigen::Matrix<double, -1, 1, 0, -1, 1>> const
                           &(::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<
                                 Eigen::VectorXd>>::*)() const>(
               &::drake::math::RollPitchYaw<
                   Eigen::AutoDiffScalar<Eigen::VectorXd>>::pitch_angle),
           "/// Returns the pitch-angle underlying `this` %RollPitchYaw.",
           py::return_value_policy::reference_internal)
      .def("yaw_angle",
           static_cast<::Eigen::AutoDiffScalar<
               Eigen::Matrix<double, -1, 1, 0, -1, 1>> const
                           &(::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<
                                 Eigen::VectorXd>>::*)() const>(
               &::drake::math::RollPitchYaw<
                   Eigen::AutoDiffScalar<Eigen::VectorXd>>::yaw_angle),
           "/// Returns the yaw-angle underlying `this` %RollPitchYaw.",
           py::return_value_policy::reference_internal)
      .def(
          "set_roll_angle",
          [](::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<Eigen::VectorXd>>
                 &self,
             Eigen::Ref<::Eigen::AutoDiffScalar<
                            Eigen::Matrix<double, -1, 1, 0, -1, 1>> const &,
                        0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &r) {
            return self.set_roll_angle(r);
          })
      .def(
          "set_pitch_angle",
          [](::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<Eigen::VectorXd>>
                 &self,
             Eigen::Ref<::Eigen::AutoDiffScalar<
                            Eigen::Matrix<double, -1, 1, 0, -1, 1>> const &,
                        0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &p) {
            return self.set_pitch_angle(p);
          })
      .def(
          "set_yaw_angle",
          [](::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<Eigen::VectorXd>>
                 &self,
             Eigen::Ref<::Eigen::AutoDiffScalar<
                            Eigen::Matrix<double, -1, 1, 0, -1, 1>> const &,
                        0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &y) {
            return self.set_yaw_angle(y);
          })
      .def("ToQuaternion",
           static_cast<
               ::Eigen::Quaternion<Eigen::AutoDiffScalar<Eigen::VectorXd>, 0> (
                   ::drake::math::RollPitchYaw<
                       Eigen::AutoDiffScalar<Eigen::VectorXd>>::*)() const>(
               &::drake::math::RollPitchYaw<
                   Eigen::AutoDiffScalar<Eigen::VectorXd>>::ToQuaternion),
           "/// Returns a quaternion representation of `this` %RollPitchYaw.")
      .def("ToRotationMatrix",
           static_cast<::drake::math::RotationMatrix<
               Eigen::AutoDiffScalar<Eigen::VectorXd>> (
               ::drake::math::RollPitchYaw<
                   Eigen::AutoDiffScalar<Eigen::VectorXd>>::*)() const>(
               &::drake::math::RollPitchYaw<
                   Eigen::AutoDiffScalar<Eigen::VectorXd>>::ToRotationMatrix),
           "/// Returns the RotationMatrix representation of `this` "
           "%RollPitchYaw.")
      .def(
          "ToMatrix3ViaRotationMatrix",
          static_cast<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, 3,
                                      3, 0, 3, 3> (
              ::drake::math::RollPitchYaw<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>>::*)() const>(
              &::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<
                  Eigen::VectorXd>>::ToMatrix3ViaRotationMatrix),
          "/// Returns the 3x3 matrix representation of the %RotationMatrix that \
/// corresponds to `this` %RollPitchYaw.  This is a convenient " sugar
          " method \
/// that is exactly equivalent to RotationMatrix(rpy).ToMatrix3().")
      .def(
          "IsNearlyEqualTo",
          [](::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<Eigen::VectorXd>>
                 &self,
             ::drake::math::RollPitchYaw<
                 Eigen::AutoDiffScalar<Eigen::VectorXd>> const &other,
             double tolerance) {
            return self.IsNearlyEqualTo(other, tolerance);
          })
      .def(
          "IsNearlySameOrientation",
          [](::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<Eigen::VectorXd>>
                 &self,
             ::drake::math::RollPitchYaw<
                 Eigen::AutoDiffScalar<Eigen::VectorXd>> const &other,
             double tolerance) {
            return self.IsNearlySameOrientation(other, tolerance);
          })
      .def(
          "IsRollPitchYawInCanonicalRange",
          static_cast<::drake::scalar_predicate<
              Eigen::AutoDiffScalar<Eigen::VectorXd>>::
                          type (::drake::math::RollPitchYaw<
                                Eigen::AutoDiffScalar<Eigen::VectorXd>>::*)()
                              const>(
              &::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<
                  Eigen::VectorXd>>::IsRollPitchYawInCanonicalRange),
          "/// Returns true if roll-pitch-yaw angles `[r, p, y]` are in the range \
/// `-π <= r <= π`, `-π/2 <= p <= π/2`, `-π <= y <= π`.")
      .def(
          "DoesCosPitchAngleViolateGimbalLockTolerance",
          [](::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<Eigen::VectorXd>>
                 &self,
             Eigen::Ref<::Eigen::AutoDiffScalar<
                            Eigen::Matrix<double, -1, 1, 0, -1, 1>> const &,
                        0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                 &cos_pitch_angle) {
            return self.DoesCosPitchAngleViolateGimbalLockTolerance(
                cos_pitch_angle);
          })
      .def(
          "DoesPitchAngleViolateGimbalLockTolerance",
          static_cast<::drake::scalar_predicate<
              Eigen::AutoDiffScalar<Eigen::VectorXd>>::
                          type (::drake::math::RollPitchYaw<
                                Eigen::AutoDiffScalar<Eigen::VectorXd>>::*)()
                              const>(
              &::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<
                  Eigen::VectorXd>>::DoesPitchAngleViolateGimbalLockTolerance),
          "/// Returns true if the pitch-angle `p` is within an internally-defined \
/// tolerance of gimbal-lock.  In other words, this method returns true if \
/// `p ≈ (n*π + π/2)` where `n = 0, ±1, ±2, ...`. \
/// @note To improve efficiency when cos(pitch_angle()) is already calculated, \
/// instead use the function DoesCosPitchAngleViolateGimbalLockTolerance(). \
/// @see DoesCosPitchAngleViolateGimbalLockTolerance()")
      .def_static(
          "GimbalLockPitchAngleTolerance",
          static_cast<double (*)()>(
              &::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<
                  Eigen::VectorXd>>::GimbalLockPitchAngleTolerance),
          "/// Returns the internally-defined allowable closeness (in radians) of the \
/// pitch angle `p` to gimbal-lock, i.e., the allowable proximity of `p` to \
/// `(n*π + π/2)` where `n = 0, ±1, ±2, ...`.")
      .def(
          "IsValid",
          [](::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<Eigen::VectorXd>>
                 &self,
             Eigen::Ref<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                        3, 1, 0, 3, 1> const &,
                        0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                 &rpy) { return self.IsValid(rpy); })
      .def(
          "CalcRotationMatrixDt",
          [](::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<Eigen::VectorXd>>
                 &self,
             Eigen::Ref<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                        3, 1, 0, 3, 1> const &,
                        0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                 &rpyDt) { return self.CalcRotationMatrixDt(rpyDt); })
      .def(
          "CalcAngularVelocityInParentFromRpyDt",
          [](::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<Eigen::VectorXd>>
                 &self,
             Eigen::Ref<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                        3, 1, 0, 3, 1> const &,
                        0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                 &rpyDt) {
            return self.CalcAngularVelocityInParentFromRpyDt(rpyDt);
          })
      .def(
          "CalcAngularVelocityInChildFromRpyDt",
          [](::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<Eigen::VectorXd>>
                 &self,
             Eigen::Ref<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                        3, 1, 0, 3, 1> const &,
                        0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                 &rpyDt) {
            return self.CalcAngularVelocityInChildFromRpyDt(rpyDt);
          })
      .def(
          "CalcRpyDtFromAngularVelocityInParent",
          [](::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<Eigen::VectorXd>>
                 &self,
             Eigen::Ref<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                        3, 1, 0, 3, 1> const &,
                        0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                 &w_AD_A) {
            return self.CalcRpyDtFromAngularVelocityInParent(w_AD_A);
          })
      .def(
          "CalcMatrixRelatingRpyDtToAngularVelocityInParent",
          static_cast<::Eigen::Matrix<
              Eigen::AutoDiffScalar<Eigen::VectorXd>, 3, 3, 0, 3,
              3> const (::drake::math::
                            RollPitchYaw<Eigen::AutoDiffScalar<
                                Eigen::VectorXd>>::*)() const>(
              &::drake::math::RollPitchYaw<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>>::
                  CalcMatrixRelatingRpyDtToAngularVelocityInParent),
          "/// For `this` %RollPitchYaw with roll-pitch-yaw angles `[r; p; y]` which \
/// relate the orientation of two generic frames A and D, returns the 3x3 \
/// matrix M that contains the partial derivatives of [ṙ, ṗ, ẏ] with respect \
/// to `[wx; wy; wz]ₐ` (which is w_AD_A expressed in A). \
/// In other words, `rpyDt = M * w_AD_A`. \
/// @param[in] function_name name of the calling function/method. \
/// @throws std::exception if `cos(p) ≈ 0` (`p` is near gimbal-lock). \
/// @note This method has a divide-by-zero error (singularity) when the cosine \
/// of the pitch angle `p` is zero [i.e., `cos(p) = 0`].  This problem (called \
/// " gimbal lock ") occurs when `p = n π  + π / 2`, where n is any integer. \
/// There are associated precision problems (inaccuracies) in the neighborhood \
/// of these pitch angles, i.e., when `cos(p) ≈ 0`.")
      .def(
          "CalcRpyDDtFromRpyDtAndAngularAccelInParent",
          [](::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<Eigen::VectorXd>>
                 &self,
             Eigen::Ref<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                        3, 1, 0, 3, 1> const &,
                        0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                 &rpyDt,
             Eigen::Ref<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                        3, 1, 0, 3, 1> const &,
                        0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                 &alpha_AD_A) {
            return self.CalcRpyDDtFromRpyDtAndAngularAccelInParent(rpyDt,
                                                                   alpha_AD_A);
          })
      .def(
          "CalcRpyDDtFromAngularAccelInChild",
          [](::drake::math::RollPitchYaw<Eigen::AutoDiffScalar<Eigen::VectorXd>>
                 &self,
             Eigen::Ref<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                        3, 1, 0, 3, 1> const &,
                        0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                 &rpyDt,
             Eigen::Ref<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                        3, 1, 0, 3, 1> const &,
                        0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                 &alpha_AD_D) {
            return self.CalcRpyDDtFromAngularAccelInChild(rpyDt, alpha_AD_D);
          })

      ;
}
