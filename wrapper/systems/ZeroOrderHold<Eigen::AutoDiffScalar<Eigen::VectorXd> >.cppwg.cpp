#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "ZeroOrderHold<Eigen::AutoDiffScalar<Eigen::VectorXd> >.cppwg.hpp"

namespace py = pybind11;
typedef ZeroOrderHold<Eigen::AutoDiffScalar<Eigen::VectorXd> > ZeroOrderHold<Eigen::AutoDiffScalar<Eigen::VectorXd> >;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

void register_ZeroOrderHold<Eigen::AutoDiffScalar<Eigen::VectorXd> >_class(py::module &m){
py::class_<ZeroOrderHold<Eigen::AutoDiffScalar<Eigen::VectorXd> >  , std::shared_ptr<ZeroOrderHold<Eigen::AutoDiffScalar<Eigen::VectorXd> > >   >(m, "ZeroOrderHold<Eigen::AutoDiffScalar<Eigen::VectorXd> >")
        .def(py::init<double, int >(), py::arg("period_sec"), py::arg("vector_size"))
        .def(py::init<double, ::drake::AbstractValue const & >(), py::arg("period_sec"), py::arg("abstract_model_value"))
        .def(
            "get_input_port", 
            (::drake::systems::InputPort<Eigen::AutoDiffScalar<Eigen::VectorXd> > const &(ZeroOrderHold<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &ZeroOrderHold<Eigen::AutoDiffScalar<Eigen::VectorXd> >::get_input_port, 
            " "  )
        .def(
            "get_output_port", 
            (::drake::systems::OutputPort<Eigen::AutoDiffScalar<Eigen::VectorXd> > const &(ZeroOrderHold<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &ZeroOrderHold<Eigen::AutoDiffScalar<Eigen::VectorXd> >::get_output_port, 
            " "  )
        .def(
            "period", 
            (double(ZeroOrderHold<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &ZeroOrderHold<Eigen::AutoDiffScalar<Eigen::VectorXd> >::period, 
            " "  )
        .def(
            "LatchInputPortToState", 
            (void(ZeroOrderHold<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)(::drake::systems::Context<Eigen::AutoDiffScalar<Eigen::VectorXd> > *) const ) &ZeroOrderHold<Eigen::AutoDiffScalar<Eigen::VectorXd> >::LatchInputPortToState, 
            " " , py::arg("context") )
    ;
}
