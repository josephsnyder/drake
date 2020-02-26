#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "Sine<drake::symbolic::Expression>.cppwg.hpp"

namespace py = pybind11;
typedef Sine<drake::symbolic::Expression> Sine<drake::symbolic::Expression>;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

void register_Sine<drake::symbolic::Expression>_class(py::module &m){
py::class_<Sine<drake::symbolic::Expression>  , std::shared_ptr<Sine<drake::symbolic::Expression> >   >(m, "Sine<drake::symbolic::Expression>")
        .def(py::init<double, double, double, int, bool >(), py::arg("amplitude"), py::arg("frequency"), py::arg("phase"), py::arg("size"), py::arg("is_time_based") = true)
        .def(py::init<::Eigen::VectorXd const &, ::Eigen::VectorXd const &, ::Eigen::VectorXd const &, bool >(), py::arg("amplitudes"), py::arg("frequencies"), py::arg("phases"), py::arg("is_time_based") = true)
        .def(
            "amplitude", 
            (double(Sine<drake::symbolic::Expression>::*)() const ) &Sine<drake::symbolic::Expression>::amplitude, 
            " "  )
        .def(
            "frequency", 
            (double(Sine<drake::symbolic::Expression>::*)() const ) &Sine<drake::symbolic::Expression>::frequency, 
            " "  )
        .def(
            "phase", 
            (double(Sine<drake::symbolic::Expression>::*)() const ) &Sine<drake::symbolic::Expression>::phase, 
            " "  )
        .def(
            "is_time_based", 
            (bool(Sine<drake::symbolic::Expression>::*)() const ) &Sine<drake::symbolic::Expression>::is_time_based, 
            " "  )
        .def(
            "amplitude_vector", 
            (::Eigen::VectorXd const &(Sine<drake::symbolic::Expression>::*)() const ) &Sine<drake::symbolic::Expression>::amplitude_vector, 
            " "  )
        .def(
            "frequency_vector", 
            (::Eigen::VectorXd const &(Sine<drake::symbolic::Expression>::*)() const ) &Sine<drake::symbolic::Expression>::frequency_vector, 
            " "  )
        .def(
            "phase_vector", 
            (::Eigen::VectorXd const &(Sine<drake::symbolic::Expression>::*)() const ) &Sine<drake::symbolic::Expression>::phase_vector, 
            " "  )
    ;
}
