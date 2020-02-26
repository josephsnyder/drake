#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "PortSwitch<drake::symbolic::Expression>.cppwg.hpp"

namespace py = pybind11;
typedef PortSwitch<drake::symbolic::Expression> PortSwitch<drake::symbolic::Expression>;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

void register_PortSwitch<drake::symbolic::Expression>_class(py::module &m){
py::class_<PortSwitch<drake::symbolic::Expression>  , std::shared_ptr<PortSwitch<drake::symbolic::Expression> >   >(m, "PortSwitch<drake::symbolic::Expression>")
        .def(py::init<int >(), py::arg("vector_size"))
        .def(
            "get_port_selector_input_port", 
            (::drake::systems::InputPort<drake::symbolic::Expression> const &(PortSwitch<drake::symbolic::Expression>::*)() const ) &PortSwitch<drake::symbolic::Expression>::get_port_selector_input_port, 
            " "  )
        .def(
            "get_output_port", 
            (::drake::systems::OutputPort<drake::symbolic::Expression> const &(PortSwitch<drake::symbolic::Expression>::*)() const ) &PortSwitch<drake::symbolic::Expression>::get_output_port, 
            " "  )
        .def(
            "DeclareInputPort", 
            (::drake::systems::InputPort<drake::symbolic::Expression> const &(PortSwitch<drake::symbolic::Expression>::*)(::std::string)) &PortSwitch<drake::symbolic::Expression>::DeclareInputPort, 
            " " , py::arg("name") )
    ;
}
