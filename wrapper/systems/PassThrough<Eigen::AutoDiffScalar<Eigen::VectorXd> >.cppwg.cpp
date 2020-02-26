#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "PassThrough<Eigen::AutoDiffScalar<Eigen::VectorXd> >.cppwg.hpp"

namespace py = pybind11;
typedef PassThrough<Eigen::AutoDiffScalar<Eigen::VectorXd> > PassThrough<Eigen::AutoDiffScalar<Eigen::VectorXd> >;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

void register_PassThrough<Eigen::AutoDiffScalar<Eigen::VectorXd> >_class(py::module &m){
py::class_<PassThrough<Eigen::AutoDiffScalar<Eigen::VectorXd> >  , std::shared_ptr<PassThrough<Eigen::AutoDiffScalar<Eigen::VectorXd> > >   >(m, "PassThrough<Eigen::AutoDiffScalar<Eigen::VectorXd> >")
        .def(py::init<int >(), py::arg("vector_size"))
        .def(py::init<::drake::AbstractValue const & >(), py::arg("abstract_model_value"))
        .def(
            "get_input_port", 
            (::drake::systems::InputPort<Eigen::AutoDiffScalar<Eigen::VectorXd> > const &(PassThrough<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &PassThrough<Eigen::AutoDiffScalar<Eigen::VectorXd> >::get_input_port, 
            " "  )
        .def(
            "get_output_port", 
            (::drake::systems::OutputPort<Eigen::AutoDiffScalar<Eigen::VectorXd> > const &(PassThrough<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &PassThrough<Eigen::AutoDiffScalar<Eigen::VectorXd> >::get_output_port, 
            " "  )
    ;
}
