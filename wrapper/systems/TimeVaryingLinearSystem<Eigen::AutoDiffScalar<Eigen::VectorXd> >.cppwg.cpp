#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "TimeVaryingLinearSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >.cppwg.hpp"

namespace py = pybind11;
typedef TimeVaryingLinearSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> > TimeVaryingLinearSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
typedef ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, 1, 0, -1, 1> _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_1_0_neg1_1_gt_;
typedef ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, 1, 0, -1, 1> _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_1_0_neg1_1_gt_;

class TimeVaryingLinearSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >_Overloads : public TimeVaryingLinearSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >{
    public:
    using TimeVaryingLinearSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::TimeVaryingLinearSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >;

};
void register_TimeVaryingLinearSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >_class(py::module &m){
py::class_<TimeVaryingLinearSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> > , TimeVaryingLinearSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >_Overloads , std::shared_ptr<TimeVaryingLinearSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> > >  , TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >  >(m, "TimeVaryingLinearSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >")
    ;
}
