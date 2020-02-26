#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >.cppwg.hpp"

namespace py = pybind11;
typedef TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> > TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
typedef ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, -1, 0, -1, -1> _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_neg1_0_neg1_neg1_gt_;
typedef ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, -1, 0, -1, -1> _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_neg1_0_neg1_neg1_gt_;
typedef ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, 1, 0, -1, 1> _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_1_0_neg1_1_gt_;
typedef ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, -1, 0, -1, -1> _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_neg1_0_neg1_neg1_gt_;
typedef ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, -1, 0, -1, -1> _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_neg1_0_neg1_neg1_gt_;
typedef ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, 1, 0, -1, 1> _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_1_0_neg1_1_gt_;

class TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >_Overloads : public TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >{
    public:
    using TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >;
    ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, -1, 0, -1, -1> A(::Eigen::AutoDiffScalar<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const & t) const  override {
        PYBIND11_OVERLOAD(
            _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_neg1_0_neg1_neg1_gt_,
            TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >,
            A,
            t);
    }
    ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, -1, 0, -1, -1> B(::Eigen::AutoDiffScalar<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const & t) const  override {
        PYBIND11_OVERLOAD(
            _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_neg1_0_neg1_neg1_gt_,
            TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >,
            B,
            t);
    }
    ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, 1, 0, -1, 1> f0(::Eigen::AutoDiffScalar<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const & t) const  override {
        PYBIND11_OVERLOAD(
            _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_1_0_neg1_1_gt_,
            TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >,
            f0,
            t);
    }
    ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, -1, 0, -1, -1> C(::Eigen::AutoDiffScalar<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const & t) const  override {
        PYBIND11_OVERLOAD(
            _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_neg1_0_neg1_neg1_gt_,
            TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >,
            C,
            t);
    }
    ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, -1, 0, -1, -1> D(::Eigen::AutoDiffScalar<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const & t) const  override {
        PYBIND11_OVERLOAD(
            _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_neg1_0_neg1_neg1_gt_,
            TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >,
            D,
            t);
    }
    ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, 1, 0, -1, 1> y0(::Eigen::AutoDiffScalar<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const & t) const  override {
        PYBIND11_OVERLOAD(
            _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_1_0_neg1_1_gt_,
            TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >,
            y0,
            t);
    }

};
void register_TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >_class(py::module &m){
py::class_<TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> > , TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >_Overloads , std::shared_ptr<TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> > >  , TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >  >(m, "TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >")
        .def(py::init<::drake::trajectories::Trajectory<double> const &, ::drake::trajectories::Trajectory<double> const &, ::drake::trajectories::Trajectory<double> const &, ::drake::trajectories::Trajectory<double> const &, ::drake::trajectories::Trajectory<double> const &, ::drake::trajectories::Trajectory<double> const &, double >(), py::arg("A"), py::arg("B"), py::arg("f0"), py::arg("C"), py::arg("D"), py::arg("y0"), py::arg("time_period") = 0.)
        .def(
            "A", 
            (::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, -1, 0, -1, -1>(TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)(::Eigen::AutoDiffScalar<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const &) const ) &TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::A, 
            " " , py::arg("t") )
        .def(
            "B", 
            (::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, -1, 0, -1, -1>(TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)(::Eigen::AutoDiffScalar<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const &) const ) &TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::B, 
            " " , py::arg("t") )
        .def(
            "f0", 
            (::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, 1, 0, -1, 1>(TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)(::Eigen::AutoDiffScalar<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const &) const ) &TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::f0, 
            " " , py::arg("t") )
        .def(
            "C", 
            (::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, -1, 0, -1, -1>(TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)(::Eigen::AutoDiffScalar<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const &) const ) &TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::C, 
            " " , py::arg("t") )
        .def(
            "D", 
            (::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, -1, 0, -1, -1>(TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)(::Eigen::AutoDiffScalar<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const &) const ) &TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::D, 
            " " , py::arg("t") )
        .def(
            "y0", 
            (::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, 1, 0, -1, 1>(TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)(::Eigen::AutoDiffScalar<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const &) const ) &TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::y0, 
            " " , py::arg("t") )
    ;
}
