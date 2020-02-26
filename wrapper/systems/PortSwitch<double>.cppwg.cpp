#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "PortSwitch<double>.cppwg.hpp"

namespace py = pybind11;
typedef PortSwitch<double> PortSwitch<double>;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

void register_PortSwitch<double>_class(py::module &m){
py::class_<PortSwitch<double>  , std::shared_ptr<PortSwitch<double> >   >(m, "PortSwitch<double>")
        .def(py::init<int >(), py::arg("vector_size"))
        .def(
            "get_port_selector_input_port", 
            (::drake::systems::InputPort<double> const &(PortSwitch<double>::*)() const ) &PortSwitch<double>::get_port_selector_input_port, 
            " "  )
        .def(
            "get_output_port", 
            (::drake::systems::OutputPort<double> const &(PortSwitch<double>::*)() const ) &PortSwitch<double>::get_output_port, 
            " "  )
        .def(
            "DeclareInputPort", 
            (::drake::systems::InputPort<double> const &(PortSwitch<double>::*)(::std::string)) &PortSwitch<double>::DeclareInputPort, 
            " " , py::arg("name") )
    ;
}
