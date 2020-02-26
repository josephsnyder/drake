#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "TrajectoryAffineSystem<double>.cppwg.hpp"

namespace py = pybind11;
typedef TrajectoryAffineSystem<double> TrajectoryAffineSystem<double>;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
typedef ::Eigen::Matrix<double, -1, -1, 0, -1, -1> _Eigen_Matrix_lt_double_neg1_neg1_0_neg1_neg1_gt_;
typedef ::Eigen::Matrix<double, -1, -1, 0, -1, -1> _Eigen_Matrix_lt_double_neg1_neg1_0_neg1_neg1_gt_;
typedef ::Eigen::Matrix<double, -1, 1, 0, -1, 1> _Eigen_Matrix_lt_double_neg1_1_0_neg1_1_gt_;
typedef ::Eigen::Matrix<double, -1, -1, 0, -1, -1> _Eigen_Matrix_lt_double_neg1_neg1_0_neg1_neg1_gt_;
typedef ::Eigen::Matrix<double, -1, -1, 0, -1, -1> _Eigen_Matrix_lt_double_neg1_neg1_0_neg1_neg1_gt_;
typedef ::Eigen::Matrix<double, -1, 1, 0, -1, 1> _Eigen_Matrix_lt_double_neg1_1_0_neg1_1_gt_;

class TrajectoryAffineSystem<double>_Overloads : public TrajectoryAffineSystem<double>{
    public:
    using TrajectoryAffineSystem<double>::TrajectoryAffineSystem<double>;
    ::Eigen::Matrix<double, -1, -1, 0, -1, -1> A(double const & t) const  override {
        PYBIND11_OVERLOAD(
            _Eigen_Matrix_lt_double_neg1_neg1_0_neg1_neg1_gt_,
            TrajectoryAffineSystem<double>,
            A,
            t);
    }
    ::Eigen::Matrix<double, -1, -1, 0, -1, -1> B(double const & t) const  override {
        PYBIND11_OVERLOAD(
            _Eigen_Matrix_lt_double_neg1_neg1_0_neg1_neg1_gt_,
            TrajectoryAffineSystem<double>,
            B,
            t);
    }
    ::Eigen::Matrix<double, -1, 1, 0, -1, 1> f0(double const & t) const  override {
        PYBIND11_OVERLOAD(
            _Eigen_Matrix_lt_double_neg1_1_0_neg1_1_gt_,
            TrajectoryAffineSystem<double>,
            f0,
            t);
    }
    ::Eigen::Matrix<double, -1, -1, 0, -1, -1> C(double const & t) const  override {
        PYBIND11_OVERLOAD(
            _Eigen_Matrix_lt_double_neg1_neg1_0_neg1_neg1_gt_,
            TrajectoryAffineSystem<double>,
            C,
            t);
    }
    ::Eigen::Matrix<double, -1, -1, 0, -1, -1> D(double const & t) const  override {
        PYBIND11_OVERLOAD(
            _Eigen_Matrix_lt_double_neg1_neg1_0_neg1_neg1_gt_,
            TrajectoryAffineSystem<double>,
            D,
            t);
    }
    ::Eigen::Matrix<double, -1, 1, 0, -1, 1> y0(double const & t) const  override {
        PYBIND11_OVERLOAD(
            _Eigen_Matrix_lt_double_neg1_1_0_neg1_1_gt_,
            TrajectoryAffineSystem<double>,
            y0,
            t);
    }

};
void register_TrajectoryAffineSystem<double>_class(py::module &m){
py::class_<TrajectoryAffineSystem<double> , TrajectoryAffineSystem<double>_Overloads , std::shared_ptr<TrajectoryAffineSystem<double> >  , TimeVaryingAffineSystem<double>  >(m, "TrajectoryAffineSystem<double>")
        .def(py::init<::drake::trajectories::Trajectory<double> const &, ::drake::trajectories::Trajectory<double> const &, ::drake::trajectories::Trajectory<double> const &, ::drake::trajectories::Trajectory<double> const &, ::drake::trajectories::Trajectory<double> const &, ::drake::trajectories::Trajectory<double> const &, double >(), py::arg("A"), py::arg("B"), py::arg("f0"), py::arg("C"), py::arg("D"), py::arg("y0"), py::arg("time_period") = 0.)
        .def(
            "A", 
            (::Eigen::Matrix<double, -1, -1, 0, -1, -1>(TrajectoryAffineSystem<double>::*)(double const &) const ) &TrajectoryAffineSystem<double>::A, 
            " " , py::arg("t") )
        .def(
            "B", 
            (::Eigen::Matrix<double, -1, -1, 0, -1, -1>(TrajectoryAffineSystem<double>::*)(double const &) const ) &TrajectoryAffineSystem<double>::B, 
            " " , py::arg("t") )
        .def(
            "f0", 
            (::Eigen::Matrix<double, -1, 1, 0, -1, 1>(TrajectoryAffineSystem<double>::*)(double const &) const ) &TrajectoryAffineSystem<double>::f0, 
            " " , py::arg("t") )
        .def(
            "C", 
            (::Eigen::Matrix<double, -1, -1, 0, -1, -1>(TrajectoryAffineSystem<double>::*)(double const &) const ) &TrajectoryAffineSystem<double>::C, 
            " " , py::arg("t") )
        .def(
            "D", 
            (::Eigen::Matrix<double, -1, -1, 0, -1, -1>(TrajectoryAffineSystem<double>::*)(double const &) const ) &TrajectoryAffineSystem<double>::D, 
            " " , py::arg("t") )
        .def(
            "y0", 
            (::Eigen::Matrix<double, -1, 1, 0, -1, 1>(TrajectoryAffineSystem<double>::*)(double const &) const ) &TrajectoryAffineSystem<double>::y0, 
            " " , py::arg("t") )
    ;
}
