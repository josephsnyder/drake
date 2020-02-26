#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "ConstantValueSource<Eigen::AutoDiffScalar<Eigen::VectorXd> >.cppwg.hpp"

namespace py = pybind11;
typedef ConstantValueSource<Eigen::AutoDiffScalar<Eigen::VectorXd> > ConstantValueSource<Eigen::AutoDiffScalar<Eigen::VectorXd> >;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

void register_ConstantValueSource<Eigen::AutoDiffScalar<Eigen::VectorXd> >_class(py::module &m){
py::class_<ConstantValueSource<Eigen::AutoDiffScalar<Eigen::VectorXd> >  , std::shared_ptr<ConstantValueSource<Eigen::AutoDiffScalar<Eigen::VectorXd> > >   >(m, "ConstantValueSource<Eigen::AutoDiffScalar<Eigen::VectorXd> >")
        .def(py::init<::drake::AbstractValue const & >(), py::arg("value"))
    ;
}
