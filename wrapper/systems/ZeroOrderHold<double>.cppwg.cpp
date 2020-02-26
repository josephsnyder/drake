#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "ZeroOrderHold<double>.cppwg.hpp"

namespace py = pybind11;
typedef ZeroOrderHold<double> ZeroOrderHold<double>;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

void register_ZeroOrderHold<double>_class(py::module &m){
py::class_<ZeroOrderHold<double>  , std::shared_ptr<ZeroOrderHold<double> >   >(m, "ZeroOrderHold<double>")
        .def(py::init<double, int >(), py::arg("period_sec"), py::arg("vector_size"))
        .def(py::init<double, ::drake::AbstractValue const & >(), py::arg("period_sec"), py::arg("abstract_model_value"))
        .def(
            "get_input_port", 
            (::drake::systems::InputPort<double> const &(ZeroOrderHold<double>::*)() const ) &ZeroOrderHold<double>::get_input_port, 
            " "  )
        .def(
            "get_output_port", 
            (::drake::systems::OutputPort<double> const &(ZeroOrderHold<double>::*)() const ) &ZeroOrderHold<double>::get_output_port, 
            " "  )
        .def(
            "period", 
            (double(ZeroOrderHold<double>::*)() const ) &ZeroOrderHold<double>::period, 
            " "  )
        .def(
            "LatchInputPortToState", 
            (void(ZeroOrderHold<double>::*)(::drake::systems::Context<double> *) const ) &ZeroOrderHold<double>::LatchInputPortToState, 
            " " , py::arg("context") )
    ;
}
