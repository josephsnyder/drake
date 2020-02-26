#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "PassThrough<double>.cppwg.hpp"

namespace py = pybind11;
typedef PassThrough<double> PassThrough<double>;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

void register_PassThrough<double>_class(py::module &m){
py::class_<PassThrough<double>  , std::shared_ptr<PassThrough<double> >   >(m, "PassThrough<double>")
        .def(py::init<int >(), py::arg("vector_size"))
        .def(py::init<::drake::AbstractValue const & >(), py::arg("abstract_model_value"))
        .def(
            "get_input_port", 
            (::drake::systems::InputPort<double> const &(PassThrough<double>::*)() const ) &PassThrough<double>::get_input_port, 
            " "  )
        .def(
            "get_output_port", 
            (::drake::systems::OutputPort<double> const &(PassThrough<double>::*)() const ) &PassThrough<double>::get_output_port, 
            " "  )
    ;
}
