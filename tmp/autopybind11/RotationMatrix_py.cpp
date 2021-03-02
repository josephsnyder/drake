#include "drake/math/rotation_matrix.h"
#include <pybind11/eigen.h>
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;
void apb11_pydrake_RotationMatrix_py_register(py::module &m) {
  static bool called = false;
  if (called) {
    return;
  }
  called = true;
  py::class_<::drake::math::RotationMatrix<double>> RotationMatrix_double(
      m, "RotationMatrix_double", "");

  RotationMatrix_double
      .def(py::init<::drake::math::RotationMatrix<double> const &>(),
           py::arg("arg0"))
      .def(py::init<>())
      .def(py::init<
               Eigen::Ref<::Eigen::Matrix<double, 3, 3, 0, 3, 3> const &, 0,
                          Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &>(),
           py::arg("R"))
      .def(py::init<::Eigen::Quaternion<double, 0> const &>(),
           py::arg("quaternion"))
      .def(py::init<::Eigen::AngleAxis<double> const &>(),
           py::arg("theta_lambda"))
      .def(py::init<::drake::math::RollPitchYaw<double> const &>(),
           py::arg("rpy"))
      .def_static("DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE",
                  static_cast<void (*)()>(
                      &::drake::math::RotationMatrix<
                          double>::DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE),
                  "")
      .def("MakeFromOrthonormalColumns",
           [](::drake::math::RotationMatrix<double> &self,
              Eigen::Ref<::Eigen::Matrix<double, 3, 1, 0, 3, 1> const &, 0,
                         Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &Bx,
              Eigen::Ref<::Eigen::Matrix<double, 3, 1, 0, 3, 1> const &, 0,
                         Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &By,
              Eigen::Ref<::Eigen::Matrix<double, 3, 1, 0, 3, 1> const &, 0,
                         Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &Bz) {
             return self.MakeFromOrthonormalColumns(Bx, By, Bz);
           })
      .def("MakeFromOrthonormalRows",
           [](::drake::math::RotationMatrix<double> &self,
              Eigen::Ref<::Eigen::Matrix<double, 3, 1, 0, 3, 1> const &, 0,
                         Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &Ax,
              Eigen::Ref<::Eigen::Matrix<double, 3, 1, 0, 3, 1> const &, 0,
                         Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &Ay,
              Eigen::Ref<::Eigen::Matrix<double, 3, 1, 0, 3, 1> const &, 0,
                         Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &Az) {
             return self.MakeFromOrthonormalRows(Ax, Ay, Az);
           })
      .def_static(
          "MakeXRotation",
          static_cast<::drake::math::RotationMatrix<double> (*)(
              double const &)>(
              &::drake::math::RotationMatrix<double>::MakeXRotation),
          py::arg("theta"),
          "/// Makes the %RotationMatrix `R_AB` associated with rotating a frame B \
/// relative to a frame A by an angle `theta` about unit vector `Ax = Bx`. \
/// @param[in] theta radian measure of rotation angle about Ax. \
/// @note Orientation is same as Eigen::AngleAxis<T>(theta, Vector3d::UnitX(). \
/// @note `R_AB` relates two frames A and B having unit vectors Ax, Ay, Az and \
/// Bx, By, Bz.  Initially, `Bx = Ax`, `By = Ay`, `Bz = Az`, then B undergoes \
/// a right-handed rotation relative to A by an angle `theta` about `Ax = Bx`. \
/// ``` \
///        ⎡ 1       0                 0  ⎤ \
/// R_AB = ⎢ 0   cos(theta)   -sin(theta) ⎥ \
///        ⎣ 0   sin(theta)    cos(theta) ⎦ \
/// ```")
      .def_static(
          "MakeYRotation",
          static_cast<::drake::math::RotationMatrix<double> (*)(
              double const &)>(
              &::drake::math::RotationMatrix<double>::MakeYRotation),
          py::arg("theta"),
          "/// Makes the %RotationMatrix `R_AB` associated with rotating a frame B \
/// relative to a frame A by an angle `theta` about unit vector `Ay = By`. \
/// @param[in] theta radian measure of rotation angle about Ay. \
/// @note Orientation is same as Eigen::AngleAxis<T>(theta, Vector3d::UnitY(). \
/// @note `R_AB` relates two frames A and B having unit vectors Ax, Ay, Az and \
/// Bx, By, Bz.  Initially, `Bx = Ax`, `By = Ay`, `Bz = Az`, then B undergoes \
/// a right-handed rotation relative to A by an angle `theta` about `Ay = By`. \
/// ``` \
///        ⎡  cos(theta)   0   sin(theta) ⎤ \
/// R_AB = ⎢          0    1           0  ⎥ \
///        ⎣ -sin(theta)   0   cos(theta) ⎦ \
/// ```")
      .def_static(
          "MakeZRotation",
          static_cast<::drake::math::RotationMatrix<double> (*)(
              double const &)>(
              &::drake::math::RotationMatrix<double>::MakeZRotation),
          py::arg("theta"),
          "/// Makes the %RotationMatrix `R_AB` associated with rotating a frame B \
/// relative to a frame A by an angle `theta` about unit vector `Az = Bz`. \
/// @param[in] theta radian measure of rotation angle about Az. \
/// @note Orientation is same as Eigen::AngleAxis<T>(theta, Vector3d::UnitZ(). \
/// @note `R_AB` relates two frames A and B having unit vectors Ax, Ay, Az and \
/// Bx, By, Bz.  Initially, `Bx = Ax`, `By = Ay`, `Bz = Az`, then B undergoes \
/// a right-handed rotation relative to A by an angle `theta` about `Az = Bz`. \
/// ``` \
///        ⎡ cos(theta)  -sin(theta)   0 ⎤ \
/// R_AB = ⎢ sin(theta)   cos(theta)   0 ⎥ \
///        ⎣         0            0    1 ⎦ \
/// ```")
      .def("set",
           [](::drake::math::RotationMatrix<double> &self,
              Eigen::Ref<::Eigen::Matrix<double, 3, 3, 0, 3, 3> const &, 0,
                         Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &R) {
             return self.set(R);
           })
      .def_static(
          "Identity",
          static_cast<::drake::math::RotationMatrix<double> const &(*)()>(
              &::drake::math::RotationMatrix<double>::Identity),
          "")
      .def("inverse",
           static_cast<::drake::math::RotationMatrix<double> (
               ::drake::math::RotationMatrix<double>::*)() const>(
               &::drake::math::RotationMatrix<double>::inverse),
           "")
      .def("transpose",
           static_cast<::drake::math::RotationMatrix<double> (
               ::drake::math::RotationMatrix<double>::*)() const>(
               &::drake::math::RotationMatrix<double>::transpose),
           "")
      .def("matrix",
           static_cast<::Eigen::Matrix<double, 3, 3, 0, 3, 3> const &(
               ::drake::math::RotationMatrix<double>::*)() const>(
               &::drake::math::RotationMatrix<double>::matrix),
           "/// Returns the Matrix3 underlying a %RotationMatrix. \
/// @see col(), row()",
           py::return_value_policy::reference_internal)
      .def("row",
           static_cast<::Eigen::Block<
               const Eigen::Matrix<double, 3, 3, 0, 3, 3>, 1, 3,
               false> const (::drake::math::RotationMatrix<double>::*)(int)
                           const>(&::drake::math::RotationMatrix<double>::row),
           py::arg("index"),
           "/// Returns `this` rotation matrix's iᵗʰ row (i = 0, 1, 2). \
/// For `this` rotation matrix R_AB (which relates right-handed \
/// sets of orthogonal unit vectors Ax, Ay, Az to Bx, By, Bz), \
/// - row(0) returns Ax_B (Ax expressed in terms of Bx, By, Bz). \
/// - row(1) returns Ay_B (Ay expressed in terms of Bx, By, Bz). \
/// - row(2) returns Az_B (Az expressed in terms of Bx, By, Bz). \
/// @param[in] index requested row index (0 <= index <= 2). \
/// @see col(), matrix() \
/// @throws In debug builds, asserts (0 <= index <= 2). \
/// @note For efficiency and consistency with Eigen, this method returns \
/// the same quantity returned by Eigen's row() operator. \
/// The returned quantity can be assigned in various ways, e.g., as \
/// `const auto& Az_B = row(2);` or `RowVector3<T> Az_B = row(2);`")
      .def("col",
           static_cast<::Eigen::Block<
               const Eigen::Matrix<double, 3, 3, 0, 3, 3>, 3, 1,
               true> const (::drake::math::RotationMatrix<double>::*)(int)
                           const>(&::drake::math::RotationMatrix<double>::col),
           py::arg("index"),
           "/// Returns `this` rotation matrix's iᵗʰ column (i = 0, 1, 2). \
/// For `this` rotation matrix R_AB (which relates right-handed \
/// sets of orthogonal unit vectors Ax, Ay, Az to Bx, By, Bz), \
/// - col(0) returns Bx_A (Bx expressed in terms of Ax, Ay, Az). \
/// - col(1) returns By_A (By expressed in terms of Ax, Ay, Az). \
/// - col(2) returns Bz_A (Bz expressed in terms of Ax, Ay, Az). \
/// @param[in] index requested column index (0 <= index <= 2). \
/// @see row(), matrix() \
/// @throws In debug builds, asserts (0 <= index <= 2). \
/// @note For efficiency and consistency with Eigen, this method returns \
/// the same quantity returned by Eigen's col() operator. \
/// The returned quantity can be assigned in various ways, e.g., as \
/// `const auto& Bz_A = col(2);` or `Vector3<T> Bz_A = col(2);`")
      .def("GetMeasureOfOrthonormality",
           [](::drake::math::RotationMatrix<double> &self,
              Eigen::Ref<::Eigen::Matrix<double, 3, 3, 0, 3, 3> const &, 0,
                         Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &R) {
             return self.GetMeasureOfOrthonormality(R);
           })
      .def("IsOrthonormal",
           [](::drake::math::RotationMatrix<double> &self,
              Eigen::Ref<::Eigen::Matrix<double, 3, 3, 0, 3, 3> const &, 0,
                         Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &R,
              double tolerance) { return self.IsOrthonormal(R, tolerance); })
      .def("IsValid",
           [](::drake::math::RotationMatrix<double> &self,
              Eigen::Ref<::Eigen::Matrix<double, 3, 3, 0, 3, 3> const &, 0,
                         Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &R,
              double tolerance) { return self.IsValid(R, tolerance); })
      .def("IsValid",
           [](::drake::math::RotationMatrix<double> &self,
              Eigen::Ref<::Eigen::Matrix<double, 3, 3, 0, 3, 3> const &, 0,
                         Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &R) {
             return self.IsValid(R);
           })
      .def(
          "IsValid",
          static_cast<::drake::scalar_predicate<double>::type (
              ::drake::math::RotationMatrix<double>::*)() const>(
              &::drake::math::RotationMatrix<double>::IsValid),
          "/// Tests if `this` rotation matrix R is a proper orthonormal rotation matrix \
/// to within the threshold of get_internal_tolerance_for_orthonormality(). \
/// @returns `true` if `this` is a valid rotation matrix.")
      .def("IsExactlyIdentity",
           static_cast<::drake::scalar_predicate<double>::type (
               ::drake::math::RotationMatrix<double>::*)() const>(
               &::drake::math::RotationMatrix<double>::IsExactlyIdentity),
           "/// Returns `true` if `this` is exactly equal to the identity "
           "matrix.")
      .def(
          "IsIdentityToInternalTolerance",
          static_cast<::drake::scalar_predicate<double>::type (
              ::drake::math::RotationMatrix<double>::*)() const>(
              &::drake::math::RotationMatrix<
                  double>::IsIdentityToInternalTolerance),
          "/// Returns true if `this` is equal to the identity matrix to within the \
/// threshold of get_internal_tolerance_for_orthonormality().")
      .def(
          "IsNearlyEqualTo",
          static_cast<::drake::scalar_predicate<double>::type (
              ::drake::math::RotationMatrix<double>::*)(
              ::drake::math::RotationMatrix<double> const &, double) const>(
              &::drake::math::RotationMatrix<double>::IsNearlyEqualTo),
          py::arg("other"), py::arg("tolerance"),
          "/// Compares each element of `this` to the corresponding element of `other` \
/// to check if they are the same to within a specified `tolerance`. \
/// @param[in] other %RotationMatrix to compare to `this`. \
/// @param[in] tolerance maximum allowable absolute difference between the \
/// matrix elements in `this` and `other`. \
/// @returns `true` if `‖this - other‖∞ <= tolerance`.")
      .def(
          "IsExactlyEqualTo",
          static_cast<::drake::scalar_predicate<double>::type (
              ::drake::math::RotationMatrix<double>::*)(
              ::drake::math::RotationMatrix<double> const &) const>(
              &::drake::math::RotationMatrix<double>::IsExactlyEqualTo),
          py::arg("other"),
          "/// Compares each element of `this` to the corresponding element of `other` \
/// to check if they are exactly the same. \
/// @param[in] other %RotationMatrix to compare to `this`. \
/// @returns true if each element of `this` is exactly equal to the \
/// corresponding element in `other`.")
      .def(
          "GetMaximumAbsoluteDifference",
          static_cast<double (::drake::math::RotationMatrix<double>::*)(
              ::drake::math::RotationMatrix<double> const &) const>(
              &::drake::math::RotationMatrix<
                  double>::GetMaximumAbsoluteDifference),
          py::arg("other"),
          "/// Computes the infinity norm of `this` - `other` (i.e., the maximum absolute \
/// value of the difference between the elements of `this` and `other`). \
/// @param[in] other %RotationMatrix to subtract from `this`. \
/// @returns `‖this - other‖∞`")
      .def("ProjectToRotationMatrix",
           [](::drake::math::RotationMatrix<double> &self,
              Eigen::Ref<::Eigen::Matrix<double, 3, 3, 0, 3, 3> const &, 0,
                         Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &M,
              double *quality_factor) {
             return self.ProjectToRotationMatrix(M, quality_factor);
           })
      .def_static(
          "get_internal_tolerance_for_orthonormality",
          static_cast<double (*)()>(
              &::drake::math::RotationMatrix<
                  double>::get_internal_tolerance_for_orthonormality),
          "/// Returns an internal tolerance that checks rotation matrix orthonormality. \
/// @returns internal tolerance (small multiplier of double-precision epsilon) \
/// used to check whether or not a rotation matrix is orthonormal. \
/// @note The tolerance is chosen by developers to ensure a reasonably \
/// valid (orthonormal) rotation matrix. \
/// @note To orthonormalize a 3x3 matrix, use ProjectToRotationMatrix().")
      .def(
          "ToQuaternion",
          static_cast<::Eigen::Quaternion<double, 0> (
              ::drake::math::RotationMatrix<double>::*)() const>(
              &::drake::math::RotationMatrix<double>::ToQuaternion),
          "/// Returns a quaternion q that represents `this` %RotationMatrix.  Since the \
/// quaternion `q` and `-q` represent the same %RotationMatrix, this method \
/// chooses to return a canonical quaternion, i.e., with q(0) >= 0. \
/// @note There is a constructor in the RollPitchYaw class that converts \
/// a rotation matrix to roll-pitch-yaw angles.")
      .def("ToQuaternion",
           [](::drake::math::RotationMatrix<double> &self,
              ::Eigen::Ref<const Eigen::Matrix<double, 3, 3, 0, 3, 3>, 0,
                           Eigen::OuterStride<-1>> const &M) {
             return self.ToQuaternion(M);
           })
      .def(
          "ToQuaternionAsVector4",
          static_cast<::Eigen::Matrix<double, 4, 1, 0, 4, 1> (
              ::drake::math::RotationMatrix<double>::*)() const>(
              &::drake::math::RotationMatrix<double>::ToQuaternionAsVector4),
          "/// Utility method to return the Vector4 associated with ToQuaternion(). \
/// @see ToQuaternion().")
      .def("ToQuaternionAsVector4",
           [](::drake::math::RotationMatrix<double> &self,
              Eigen::Ref<::Eigen::Matrix<double, 3, 3, 0, 3, 3> const &, 0,
                         Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &M) {
             return self.ToQuaternionAsVector4(M);
           })
      .def(
          "ToAngleAxis",
          static_cast<::Eigen::AngleAxis<double> (
              ::drake::math::RotationMatrix<double>::*)() const>(
              &::drake::math::RotationMatrix<double>::ToAngleAxis),
          "/// Returns an AngleAxis `theta_lambda` containing an angle `theta` and unit \
/// vector (axis direction) `lambda` that represents `this` %RotationMatrix. \
/// @note The orientation and %RotationMatrix associated with `theta * lambda` \
/// is identical to that of `(-theta) * (-lambda)`.  The AngleAxis returned by \
/// this method chooses to have `0 <= theta <= pi`. \
/// @returns an AngleAxis with `0 <= theta <= pi` and a unit vector `lambda`.")

      .def(
          "__mul__",
          static_cast<::drake::math::RotationMatrix<double> (
              ::drake::math::RotationMatrix<double>::*)(
              ::drake::math::RotationMatrix<double> const &) const>(
              &::drake::math::RotationMatrix<double>::operator*),
          py::arg("other"),
          "/// Calculates `this` rotation matrix `R_AB` multiplied by `other` rotation \
/// matrix `R_BC`, returning the composition `R_AB * R_BC`. \
/// @param[in] other %RotationMatrix that post-multiplies `this`. \
/// @returns rotation matrix that results from `this` multiplied by `other`. \
/// @note It is possible (albeit improbable) to create an invalid rotation \
/// matrix by accumulating round-off error with a large number of multiplies.")
      .def(
          "__mul__",
          static_cast<::Eigen::Matrix<double, 3, 1, 0, 3, 1> (
              ::drake::math::RotationMatrix<double>::*)(
              ::Eigen::Matrix<double, 3, 1, 0, 3, 1> const &) const>(
              &::drake::math::RotationMatrix<double>::operator*),
          py::arg("v_B"),
          "/// Calculates `this` rotation matrix `R_AB` multiplied by an arbitrary \
/// Vector3 expressed in the B frame. \
/// @param[in] v_B 3x1 vector that post-multiplies `this`. \
/// @returns 3x1 vector `v_A = R_AB * v_B`.")
      .def(
          "__imul__",
          static_cast<::drake::math::RotationMatrix<double> &(
              ::drake::math::RotationMatrix<
                  double>::*)(::drake::math::RotationMatrix<double> const &)>(
              &::drake::math::RotationMatrix<double>::operator*=),
          py::arg("other"),
          "/// In-place multiply of `this` rotation matrix `R_AB` by `other` rotation \
/// matrix `R_BC`.  On return, `this` is set to equal `R_AB * R_BC`. \
/// @param[in] other %RotationMatrix that post-multiplies `this`. \
/// @returns `this` rotation matrix which has been multiplied by `other`. \
/// @note It is possible (albeit improbable) to create an invalid rotation \
/// matrix by accumulating round-off error with a large number of multiplies.");

  py::class_<
      ::drake::math::RotationMatrix<Eigen::AutoDiffScalar<Eigen::VectorXd>>>
      RotationMatrix_Eigen_AutoDiffScalar_Eigen_VectorXd(
          m, "RotationMatrix_Eigen_AutoDiffScalar_Eigen_VectorXd", "");

  RotationMatrix_Eigen_AutoDiffScalar_Eigen_VectorXd
      .def(
          py::init<
              Eigen::Ref<::drake::math::RotationMatrix<
                             Eigen::AutoDiffScalar<Eigen::VectorXd>> const &,
                         0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &>(),
          py::arg("arg0"))
      .def(py::init<>())
      .def(
          py::init<
              Eigen::Ref<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                         3, 3, 0, 3, 3> const &,
                         0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &>(),
          py::arg("R"))
      .def(py::init<::Eigen::Quaternion<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                        0> const &>(),
           py::arg("quaternion"))
      .def(py::init<::Eigen::AngleAxis<
               Eigen::AutoDiffScalar<Eigen::VectorXd>> const &>(),
           py::arg("theta_lambda"))
      .def(py::init<::drake::math::RollPitchYaw<
               Eigen::AutoDiffScalar<Eigen::VectorXd>> const &>(),
           py::arg("rpy"))
      .def_static(
          "DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE",
          static_cast<void (*)()>(
              &::drake::math::RotationMatrix<Eigen::AutoDiffScalar<
                  Eigen::VectorXd>>::DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE),
          "")
      .def(
          "MakeFromOrthonormalColumns",
          [](::drake::math::RotationMatrix<
                 Eigen::AutoDiffScalar<Eigen::VectorXd>> &self,
             Eigen::Ref<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                        3, 1, 0, 3, 1> const &,
                        0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &Bx,
             Eigen::Ref<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                        3, 1, 0, 3, 1> const &,
                        0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &By,
             Eigen::Ref<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                        3, 1, 0, 3, 1> const &,
                        0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &Bz) {
            return self.MakeFromOrthonormalColumns(Bx, By, Bz);
          })
      .def(
          "MakeFromOrthonormalRows",
          [](::drake::math::RotationMatrix<
                 Eigen::AutoDiffScalar<Eigen::VectorXd>> &self,
             Eigen::Ref<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                        3, 1, 0, 3, 1> const &,
                        0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &Ax,
             Eigen::Ref<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                        3, 1, 0, 3, 1> const &,
                        0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &Ay,
             Eigen::Ref<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                        3, 1, 0, 3, 1> const &,
                        0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &Az) {
            return self.MakeFromOrthonormalRows(Ax, Ay, Az);
          })
      .def("MakeXRotation",
           [](::drake::math::RotationMatrix<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>> &self,
              Eigen::Ref<::Eigen::AutoDiffScalar<
                             Eigen::Matrix<double, -1, 1, 0, -1, 1>> const &,
                         0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                  &theta) { return self.MakeXRotation(theta); })
      .def("MakeYRotation",
           [](::drake::math::RotationMatrix<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>> &self,
              Eigen::Ref<::Eigen::AutoDiffScalar<
                             Eigen::Matrix<double, -1, 1, 0, -1, 1>> const &,
                         0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                  &theta) { return self.MakeYRotation(theta); })
      .def("MakeZRotation",
           [](::drake::math::RotationMatrix<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>> &self,
              Eigen::Ref<::Eigen::AutoDiffScalar<
                             Eigen::Matrix<double, -1, 1, 0, -1, 1>> const &,
                         0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                  &theta) { return self.MakeZRotation(theta); })
      .def("set",
           [](::drake::math::RotationMatrix<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>> &self,
              Eigen::Ref<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                         3, 3, 0, 3, 3> const &,
                         0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &R) {
             return self.set(R);
           })
      .def_static("Identity",
                  static_cast<::drake::math::RotationMatrix<
                      Eigen::AutoDiffScalar<Eigen::VectorXd>> const &(*)()>(
                      &::drake::math::RotationMatrix<
                          Eigen::AutoDiffScalar<Eigen::VectorXd>>::Identity),
                  "", py::return_value_policy::reference_internal)
      .def("inverse",
           static_cast<::drake::math::RotationMatrix<
               Eigen::AutoDiffScalar<Eigen::VectorXd>> (
               ::drake::math::RotationMatrix<
                   Eigen::AutoDiffScalar<Eigen::VectorXd>>::*)() const>(
               &::drake::math::RotationMatrix<
                   Eigen::AutoDiffScalar<Eigen::VectorXd>>::inverse),
           "")
      .def("transpose",
           static_cast<::drake::math::RotationMatrix<
               Eigen::AutoDiffScalar<Eigen::VectorXd>> (
               ::drake::math::RotationMatrix<
                   Eigen::AutoDiffScalar<Eigen::VectorXd>>::*)() const>(
               &::drake::math::RotationMatrix<
                   Eigen::AutoDiffScalar<Eigen::VectorXd>>::transpose),
           "")
      .def("matrix",
           static_cast<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                       3, 3, 0, 3, 3> const
                           &(::drake::math::RotationMatrix<
                               Eigen::AutoDiffScalar<Eigen::VectorXd>>::*)()
                               const>(
               &::drake::math::RotationMatrix<
                   Eigen::AutoDiffScalar<Eigen::VectorXd>>::matrix),
           "/// Returns the Matrix3 underlying a %RotationMatrix. \
/// @see col(), row()",
           py::return_value_policy::reference_internal)
      .def("row",
           static_cast<::Eigen::Block<
               const Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, 3, 3,
                                   0, 3, 3>,
               1, 3, false> const (::drake::math::
                                       RotationMatrix<Eigen::AutoDiffScalar<
                                           Eigen::VectorXd>>::*)(int) const>(
               &::drake::math::RotationMatrix<
                   Eigen::AutoDiffScalar<Eigen::VectorXd>>::row),
           py::arg("index"),
           "/// Returns `this` rotation matrix's iᵗʰ row (i = 0, 1, 2). \
/// For `this` rotation matrix R_AB (which relates right-handed \
/// sets of orthogonal unit vectors Ax, Ay, Az to Bx, By, Bz), \
/// - row(0) returns Ax_B (Ax expressed in terms of Bx, By, Bz). \
/// - row(1) returns Ay_B (Ay expressed in terms of Bx, By, Bz). \
/// - row(2) returns Az_B (Az expressed in terms of Bx, By, Bz). \
/// @param[in] index requested row index (0 <= index <= 2). \
/// @see col(), matrix() \
/// @throws In debug builds, asserts (0 <= index <= 2). \
/// @note For efficiency and consistency with Eigen, this method returns \
/// the same quantity returned by Eigen's row() operator. \
/// The returned quantity can be assigned in various ways, e.g., as \
/// `const auto& Az_B = row(2);` or `RowVector3<T> Az_B = row(2);`")
      .def("col",
           static_cast<::Eigen::Block<
               const Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, 3, 3,
                                   0, 3, 3>,
               3, 1, true> const (::drake::math::
                                      RotationMatrix<Eigen::AutoDiffScalar<
                                          Eigen::VectorXd>>::*)(int) const>(
               &::drake::math::RotationMatrix<
                   Eigen::AutoDiffScalar<Eigen::VectorXd>>::col),
           py::arg("index"),
           "/// Returns `this` rotation matrix's iᵗʰ column (i = 0, 1, 2). \
/// For `this` rotation matrix R_AB (which relates right-handed \
/// sets of orthogonal unit vectors Ax, Ay, Az to Bx, By, Bz), \
/// - col(0) returns Bx_A (Bx expressed in terms of Ax, Ay, Az). \
/// - col(1) returns By_A (By expressed in terms of Ax, Ay, Az). \
/// - col(2) returns Bz_A (Bz expressed in terms of Ax, Ay, Az). \
/// @param[in] index requested column index (0 <= index <= 2). \
/// @see row(), matrix() \
/// @throws In debug builds, asserts (0 <= index <= 2). \
/// @note For efficiency and consistency with Eigen, this method returns \
/// the same quantity returned by Eigen's col() operator. \
/// The returned quantity can be assigned in various ways, e.g., as \
/// `const auto& Bz_A = col(2);` or `Vector3<T> Bz_A = col(2);`")
      .def("GetMeasureOfOrthonormality",
           [](::drake::math::RotationMatrix<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>> &self,
              Eigen::Ref<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                         3, 3, 0, 3, 3> const &,
                         0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &R) {
             return self.GetMeasureOfOrthonormality(R);
           })
      .def("IsOrthonormal",
           [](::drake::math::RotationMatrix<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>> &self,
              Eigen::Ref<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                         3, 3, 0, 3, 3> const &,
                         0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &R,
              double tolerance) { return self.IsOrthonormal(R, tolerance); })
      .def("IsValid",
           [](::drake::math::RotationMatrix<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>> &self,
              Eigen::Ref<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                         3, 3, 0, 3, 3> const &,
                         0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &R,
              double tolerance) { return self.IsValid(R, tolerance); })
      .def("IsValid",
           [](::drake::math::RotationMatrix<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>> &self,
              Eigen::Ref<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                         3, 3, 0, 3, 3> const &,
                         0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &R) {
             return self.IsValid(R);
           })
      .def(
          "IsValid",
          static_cast<::drake::scalar_predicate<
              Eigen::AutoDiffScalar<Eigen::VectorXd>>::
                          type (::drake::math::RotationMatrix<
                                Eigen::AutoDiffScalar<Eigen::VectorXd>>::*)()
                              const>(
              &::drake::math::RotationMatrix<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>>::IsValid),
          "/// Tests if `this` rotation matrix R is a proper orthonormal rotation matrix \
/// to within the threshold of get_internal_tolerance_for_orthonormality(). \
/// @returns `true` if `this` is a valid rotation matrix.")
      .def("IsExactlyIdentity",
           static_cast<::drake::scalar_predicate<
               Eigen::AutoDiffScalar<Eigen::VectorXd>>::
                           type (::drake::math::RotationMatrix<
                                 Eigen::AutoDiffScalar<Eigen::VectorXd>>::*)()
                               const>(
               &::drake::math::RotationMatrix<
                   Eigen::AutoDiffScalar<Eigen::VectorXd>>::IsExactlyIdentity),
           "/// Returns `true` if `this` is exactly equal to the identity "
           "matrix.")
      .def(
          "IsIdentityToInternalTolerance",
          static_cast<::drake::scalar_predicate<
              Eigen::AutoDiffScalar<Eigen::VectorXd>>::
                          type (::drake::math::RotationMatrix<
                                Eigen::AutoDiffScalar<Eigen::VectorXd>>::*)()
                              const>(
              &::drake::math::RotationMatrix<Eigen::AutoDiffScalar<
                  Eigen::VectorXd>>::IsIdentityToInternalTolerance),
          "/// Returns true if `this` is equal to the identity matrix to within the \
/// threshold of get_internal_tolerance_for_orthonormality().")
      .def("IsNearlyEqualTo",
           [](::drake::math::RotationMatrix<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>> &self,
              Eigen::Ref<::drake::math::RotationMatrix<
                             Eigen::AutoDiffScalar<Eigen::VectorXd>> const &,
                         0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                  &other,
              double tolerance) {
             return self.IsNearlyEqualTo(other, tolerance);
           })
      .def("IsExactlyEqualTo",
           [](::drake::math::RotationMatrix<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>> &self,
              Eigen::Ref<::drake::math::RotationMatrix<
                             Eigen::AutoDiffScalar<Eigen::VectorXd>> const &,
                         0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                  &other) { return self.IsExactlyEqualTo(other); })
      .def("GetMaximumAbsoluteDifference",
           [](::drake::math::RotationMatrix<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>> &self,
              Eigen::Ref<::drake::math::RotationMatrix<
                             Eigen::AutoDiffScalar<Eigen::VectorXd>> const &,
                         0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                  &other) { return self.GetMaximumAbsoluteDifference(other); })
      .def("ProjectToRotationMatrix",
           [](::drake::math::RotationMatrix<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>> &self,
              Eigen::Ref<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                         3, 3, 0, 3, 3> const &,
                         0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &M,
              Eigen::Ref<::Eigen::AutoDiffScalar<
                             Eigen::Matrix<double, -1, 1, 0, -1, 1>> *,
                         0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                  quality_factor) {
             return self.ProjectToRotationMatrix(M, quality_factor);
           })
      .def_static(
          "get_internal_tolerance_for_orthonormality",
          static_cast<double (*)()>(
              &::drake::math::RotationMatrix<Eigen::AutoDiffScalar<
                  Eigen::VectorXd>>::get_internal_tolerance_for_orthonormality),
          "/// Returns an internal tolerance that checks rotation matrix orthonormality. \
/// @returns internal tolerance (small multiplier of double-precision epsilon) \
/// used to check whether or not a rotation matrix is orthonormal. \
/// @note The tolerance is chosen by developers to ensure a reasonably \
/// valid (orthonormal) rotation matrix. \
/// @note To orthonormalize a 3x3 matrix, use ProjectToRotationMatrix().")
      .def(
          "ToQuaternion",
          static_cast<
              ::Eigen::Quaternion<Eigen::AutoDiffScalar<Eigen::VectorXd>, 0> (
                  ::drake::math::RotationMatrix<
                      Eigen::AutoDiffScalar<Eigen::VectorXd>>::*)() const>(
              &::drake::math::RotationMatrix<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>>::ToQuaternion),
          "/// Returns a quaternion q that represents `this` %RotationMatrix.  Since the \
/// quaternion `q` and `-q` represent the same %RotationMatrix, this method \
/// chooses to return a canonical quaternion, i.e., with q(0) >= 0. \
/// @note There is a constructor in the RollPitchYaw class that converts \
/// a rotation matrix to roll-pitch-yaw angles.")
      .def("ToQuaternion",
           [](::drake::math::RotationMatrix<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>> &self,
              ::Eigen::Ref<
                  const Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, 3,
                                      3, 0, 3, 3>,
                  0, Eigen::OuterStride<-1>> const &M) {
             return self.ToQuaternion(M);
           })
      .def(
          "ToQuaternionAsVector4",
          static_cast<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, 4,
                                      1, 0, 4, 1> (
              ::drake::math::RotationMatrix<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>>::*)() const>(
              &::drake::math::RotationMatrix<Eigen::AutoDiffScalar<
                  Eigen::VectorXd>>::ToQuaternionAsVector4),
          "/// Utility method to return the Vector4 associated with ToQuaternion(). \
/// @see ToQuaternion().")
      .def("ToQuaternionAsVector4",
           [](::drake::math::RotationMatrix<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>> &self,
              Eigen::Ref<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>,
                                         3, 3, 0, 3, 3> const &,
                         0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> &M) {
             return self.ToQuaternionAsVector4(M);
           })
      .def(
          "ToAngleAxis",
          static_cast<
              ::Eigen::AngleAxis<Eigen::AutoDiffScalar<Eigen::VectorXd>> (
                  ::drake::math::RotationMatrix<
                      Eigen::AutoDiffScalar<Eigen::VectorXd>>::*)() const>(
              &::drake::math::RotationMatrix<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>>::ToAngleAxis),
          "/// Returns an AngleAxis `theta_lambda` containing an angle `theta` and unit \
/// vector (axis direction) `lambda` that represents `this` %RotationMatrix. \
/// @note The orientation and %RotationMatrix associated with `theta * lambda` \
/// is identical to that of `(-theta) * (-lambda)`.  The AngleAxis returned by \
/// this method chooses to have `0 <= theta <= pi`. \
/// @returns an AngleAxis with `0 <= theta <= pi` and a unit vector `lambda`.")

      .def(
          "__imul__",
          static_cast<::drake::math::RotationMatrix<
              Eigen::AutoDiffScalar<Eigen::VectorXd>> &(
              ::drake::math::RotationMatrix<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>>::
                  *)(::drake::math::RotationMatrix<
                     Eigen::AutoDiffScalar<Eigen::VectorXd>> const &)>(
              &::drake::math::RotationMatrix<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>>::operator*=),
          py::arg("other"),
          "/// In-place multiply of `this` rotation matrix `R_AB` by `other` rotation \
/// matrix `R_BC`.  On return, `this` is set to equal `R_AB * R_BC`. \
/// @param[in] other %RotationMatrix that post-multiplies `this`. \
/// @returns `this` rotation matrix which has been multiplied by `other`. \
/// @note It is possible (albeit improbable) to create an invalid rotation \
/// matrix by accumulating round-off error with a large number of multiplies.")
      .def(
          "__mul__",
          static_cast<::drake::math::RotationMatrix<
              Eigen::AutoDiffScalar<Eigen::VectorXd>> (
              ::drake::math::RotationMatrix<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>>::*)(
              ::drake::math::RotationMatrix<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>> const &) const>(
              &::drake::math::RotationMatrix<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>>::operator*),
          py::arg("other"),
          "/// Calculates `this` rotation matrix `R_AB` multiplied by `other` rotation \
/// matrix `R_BC`, returning the composition `R_AB * R_BC`. \
/// @param[in] other %RotationMatrix that post-multiplies `this`. \
/// @returns rotation matrix that results from `this` multiplied by `other`. \
/// @note It is possible (albeit improbable) to create an invalid rotation \
/// matrix by accumulating round-off error with a large number of multiplies.")
      .def(
          "__mul__",
          static_cast<::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, 3,
                                      1, 0, 3, 1> (
              ::drake::math::RotationMatrix<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>>::*)(
              ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, 3, 1, 0,
                              3, 1> const &) const>(
              &::drake::math::RotationMatrix<
                  Eigen::AutoDiffScalar<Eigen::VectorXd>>::operator*),
          py::arg("v_B"),
          "/// Calculates `this` rotation matrix `R_AB` multiplied by an arbitrary \
/// Vector3 expressed in the B frame. \
/// @param[in] v_B 3x1 vector that post-multiplies `this`. \
/// @returns 3x1 vector `v_A = R_AB * v_B`.");
}
