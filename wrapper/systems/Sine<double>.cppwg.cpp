#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "Sine<double>.cppwg.hpp"

namespace py = pybind11;
typedef Sine<double> Sine<double>;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

void register_Sine<double>_class(py::module &m){
py::class_<Sine<double>  , std::shared_ptr<Sine<double> >   >(m, "Sine<double>")
        .def(py::init<double, double, double, int, bool >(), py::arg("amplitude"), py::arg("frequency"), py::arg("phase"), py::arg("size"), py::arg("is_time_based") = true)
        .def(py::init<::Eigen::VectorXd const &, ::Eigen::VectorXd const &, ::Eigen::VectorXd const &, bool >(), py::arg("amplitudes"), py::arg("frequencies"), py::arg("phases"), py::arg("is_time_based") = true)
        .def(
            "amplitude", 
            (double(Sine<double>::*)() const ) &Sine<double>::amplitude, 
            " "  )
        .def(
            "frequency", 
            (double(Sine<double>::*)() const ) &Sine<double>::frequency, 
            " "  )
        .def(
            "phase", 
            (double(Sine<double>::*)() const ) &Sine<double>::phase, 
            " "  )
        .def(
            "is_time_based", 
            (bool(Sine<double>::*)() const ) &Sine<double>::is_time_based, 
            " "  )
        .def(
            "amplitude_vector", 
            (::Eigen::VectorXd const &(Sine<double>::*)() const ) &Sine<double>::amplitude_vector, 
            " "  )
        .def(
            "frequency_vector", 
            (::Eigen::VectorXd const &(Sine<double>::*)() const ) &Sine<double>::frequency_vector, 
            " "  )
        .def(
            "phase_vector", 
            (::Eigen::VectorXd const &(Sine<double>::*)() const ) &Sine<double>::phase_vector, 
            " "  )
    ;
}
