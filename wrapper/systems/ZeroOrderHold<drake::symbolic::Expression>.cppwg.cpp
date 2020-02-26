#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "ZeroOrderHold<drake::symbolic::Expression>.cppwg.hpp"

namespace py = pybind11;
typedef ZeroOrderHold<drake::symbolic::Expression> ZeroOrderHold<drake::symbolic::Expression>;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

void register_ZeroOrderHold<drake::symbolic::Expression>_class(py::module &m){
py::class_<ZeroOrderHold<drake::symbolic::Expression>  , std::shared_ptr<ZeroOrderHold<drake::symbolic::Expression> >   >(m, "ZeroOrderHold<drake::symbolic::Expression>")
        .def(py::init<double, int >(), py::arg("period_sec"), py::arg("vector_size"))
        .def(py::init<double, ::drake::AbstractValue const & >(), py::arg("period_sec"), py::arg("abstract_model_value"))
        .def(
            "get_input_port", 
            (::drake::systems::InputPort<drake::symbolic::Expression> const &(ZeroOrderHold<drake::symbolic::Expression>::*)() const ) &ZeroOrderHold<drake::symbolic::Expression>::get_input_port, 
            " "  )
        .def(
            "get_output_port", 
            (::drake::systems::OutputPort<drake::symbolic::Expression> const &(ZeroOrderHold<drake::symbolic::Expression>::*)() const ) &ZeroOrderHold<drake::symbolic::Expression>::get_output_port, 
            " "  )
        .def(
            "period", 
            (double(ZeroOrderHold<drake::symbolic::Expression>::*)() const ) &ZeroOrderHold<drake::symbolic::Expression>::period, 
            " "  )
        .def(
            "LatchInputPortToState", 
            (void(ZeroOrderHold<drake::symbolic::Expression>::*)(::drake::systems::Context<drake::symbolic::Expression> *) const ) &ZeroOrderHold<drake::symbolic::Expression>::LatchInputPortToState, 
            " " , py::arg("context") )
    ;
}
