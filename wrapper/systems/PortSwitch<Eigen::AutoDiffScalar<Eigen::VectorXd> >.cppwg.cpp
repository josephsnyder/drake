#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "PortSwitch<Eigen::AutoDiffScalar<Eigen::VectorXd> >.cppwg.hpp"

namespace py = pybind11;
typedef PortSwitch<Eigen::AutoDiffScalar<Eigen::VectorXd> > PortSwitch<Eigen::AutoDiffScalar<Eigen::VectorXd> >;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

void register_PortSwitch<Eigen::AutoDiffScalar<Eigen::VectorXd> >_class(py::module &m){
py::class_<PortSwitch<Eigen::AutoDiffScalar<Eigen::VectorXd> >  , std::shared_ptr<PortSwitch<Eigen::AutoDiffScalar<Eigen::VectorXd> > >   >(m, "PortSwitch<Eigen::AutoDiffScalar<Eigen::VectorXd> >")
        .def(py::init<int >(), py::arg("vector_size"))
        .def(
            "get_port_selector_input_port", 
            (::drake::systems::InputPort<Eigen::AutoDiffScalar<Eigen::VectorXd> > const &(PortSwitch<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &PortSwitch<Eigen::AutoDiffScalar<Eigen::VectorXd> >::get_port_selector_input_port, 
            " "  )
        .def(
            "get_output_port", 
            (::drake::systems::OutputPort<Eigen::AutoDiffScalar<Eigen::VectorXd> > const &(PortSwitch<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &PortSwitch<Eigen::AutoDiffScalar<Eigen::VectorXd> >::get_output_port, 
            " "  )
        .def(
            "DeclareInputPort", 
            (::drake::systems::InputPort<Eigen::AutoDiffScalar<Eigen::VectorXd> > const &(PortSwitch<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)(::std::string)) &PortSwitch<Eigen::AutoDiffScalar<Eigen::VectorXd> >::DeclareInputPort, 
            " " , py::arg("name") )
    ;
}
