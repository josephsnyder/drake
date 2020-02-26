#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "PassThrough<drake::symbolic::Expression>.cppwg.hpp"

namespace py = pybind11;
typedef PassThrough<drake::symbolic::Expression> PassThrough<drake::symbolic::Expression>;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

void register_PassThrough<drake::symbolic::Expression>_class(py::module &m){
py::class_<PassThrough<drake::symbolic::Expression>  , std::shared_ptr<PassThrough<drake::symbolic::Expression> >   >(m, "PassThrough<drake::symbolic::Expression>")
        .def(py::init<int >(), py::arg("vector_size"))
        .def(py::init<::drake::AbstractValue const & >(), py::arg("abstract_model_value"))
        .def(
            "get_input_port", 
            (::drake::systems::InputPort<drake::symbolic::Expression> const &(PassThrough<drake::symbolic::Expression>::*)() const ) &PassThrough<drake::symbolic::Expression>::get_input_port, 
            " "  )
        .def(
            "get_output_port", 
            (::drake::systems::OutputPort<drake::symbolic::Expression> const &(PassThrough<drake::symbolic::Expression>::*)() const ) &PassThrough<drake::symbolic::Expression>::get_output_port, 
            " "  )
    ;
}
