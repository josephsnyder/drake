#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "TrajectoryLinearSystem<double>.cppwg.hpp"

namespace py = pybind11;
typedef TrajectoryLinearSystem<double> TrajectoryLinearSystem<double>;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
typedef ::Eigen::Matrix<double, -1, -1, 0, -1, -1> _Eigen_Matrix_lt_double_neg1_neg1_0_neg1_neg1_gt_;
typedef ::Eigen::Matrix<double, -1, -1, 0, -1, -1> _Eigen_Matrix_lt_double_neg1_neg1_0_neg1_neg1_gt_;
typedef ::Eigen::Matrix<double, -1, -1, 0, -1, -1> _Eigen_Matrix_lt_double_neg1_neg1_0_neg1_neg1_gt_;
typedef ::Eigen::Matrix<double, -1, -1, 0, -1, -1> _Eigen_Matrix_lt_double_neg1_neg1_0_neg1_neg1_gt_;

class TrajectoryLinearSystem<double>_Overloads : public TrajectoryLinearSystem<double>{
    public:
    using TrajectoryLinearSystem<double>::TrajectoryLinearSystem<double>;
    ::Eigen::Matrix<double, -1, -1, 0, -1, -1> A(double const & t) const  override {
        PYBIND11_OVERLOAD(
            _Eigen_Matrix_lt_double_neg1_neg1_0_neg1_neg1_gt_,
            TrajectoryLinearSystem<double>,
            A,
            t);
    }
    ::Eigen::Matrix<double, -1, -1, 0, -1, -1> B(double const & t) const  override {
        PYBIND11_OVERLOAD(
            _Eigen_Matrix_lt_double_neg1_neg1_0_neg1_neg1_gt_,
            TrajectoryLinearSystem<double>,
            B,
            t);
    }
    ::Eigen::Matrix<double, -1, -1, 0, -1, -1> C(double const & t) const  override {
        PYBIND11_OVERLOAD(
            _Eigen_Matrix_lt_double_neg1_neg1_0_neg1_neg1_gt_,
            TrajectoryLinearSystem<double>,
            C,
            t);
    }
    ::Eigen::Matrix<double, -1, -1, 0, -1, -1> D(double const & t) const  override {
        PYBIND11_OVERLOAD(
            _Eigen_Matrix_lt_double_neg1_neg1_0_neg1_neg1_gt_,
            TrajectoryLinearSystem<double>,
            D,
            t);
    }

};
void register_TrajectoryLinearSystem<double>_class(py::module &m){
py::class_<TrajectoryLinearSystem<double> , TrajectoryLinearSystem<double>_Overloads , std::shared_ptr<TrajectoryLinearSystem<double> >   >(m, "TrajectoryLinearSystem<double>")
        .def(py::init<::drake::trajectories::Trajectory<double> const &, ::drake::trajectories::Trajectory<double> const &, ::drake::trajectories::Trajectory<double> const &, ::drake::trajectories::Trajectory<double> const &, double >(), py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"), py::arg("time_period") = 0.)
        .def(
            "A", 
            (::Eigen::Matrix<double, -1, -1, 0, -1, -1>(TrajectoryLinearSystem<double>::*)(double const &) const ) &TrajectoryLinearSystem<double>::A, 
            " " , py::arg("t") )
        .def(
            "B", 
            (::Eigen::Matrix<double, -1, -1, 0, -1, -1>(TrajectoryLinearSystem<double>::*)(double const &) const ) &TrajectoryLinearSystem<double>::B, 
            " " , py::arg("t") )
        .def(
            "C", 
            (::Eigen::Matrix<double, -1, -1, 0, -1, -1>(TrajectoryLinearSystem<double>::*)(double const &) const ) &TrajectoryLinearSystem<double>::C, 
            " " , py::arg("t") )
        .def(
            "D", 
            (::Eigen::Matrix<double, -1, -1, 0, -1, -1>(TrajectoryLinearSystem<double>::*)(double const &) const ) &TrajectoryLinearSystem<double>::D, 
            " " , py::arg("t") )
    ;
}
