#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "TimeVaryingLinearSystem<double>.cppwg.hpp"

namespace py = pybind11;
typedef TimeVaryingLinearSystem<double> TimeVaryingLinearSystem<double>;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
typedef ::Eigen::Matrix<double, -1, 1, 0, -1, 1> _Eigen_Matrix_lt_double_neg1_1_0_neg1_1_gt_;
typedef ::Eigen::Matrix<double, -1, 1, 0, -1, 1> _Eigen_Matrix_lt_double_neg1_1_0_neg1_1_gt_;

class TimeVaryingLinearSystem<double>_Overloads : public TimeVaryingLinearSystem<double>{
    public:
    using TimeVaryingLinearSystem<double>::TimeVaryingLinearSystem<double>;

};
void register_TimeVaryingLinearSystem<double>_class(py::module &m){
py::class_<TimeVaryingLinearSystem<double> , TimeVaryingLinearSystem<double>_Overloads , std::shared_ptr<TimeVaryingLinearSystem<double> >  , TimeVaryingAffineSystem<double>  >(m, "TimeVaryingLinearSystem<double>")
    ;
}
