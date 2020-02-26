#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "Sine<Eigen::AutoDiffScalar<Eigen::VectorXd> >.cppwg.hpp"

namespace py = pybind11;
typedef Sine<Eigen::AutoDiffScalar<Eigen::VectorXd> > Sine<Eigen::AutoDiffScalar<Eigen::VectorXd> >;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

void register_Sine<Eigen::AutoDiffScalar<Eigen::VectorXd> >_class(py::module &m){
py::class_<Sine<Eigen::AutoDiffScalar<Eigen::VectorXd> >  , std::shared_ptr<Sine<Eigen::AutoDiffScalar<Eigen::VectorXd> > >   >(m, "Sine<Eigen::AutoDiffScalar<Eigen::VectorXd> >")
        .def(py::init<double, double, double, int, bool >(), py::arg("amplitude"), py::arg("frequency"), py::arg("phase"), py::arg("size"), py::arg("is_time_based") = true)
        .def(py::init<::Eigen::VectorXd const &, ::Eigen::VectorXd const &, ::Eigen::VectorXd const &, bool >(), py::arg("amplitudes"), py::arg("frequencies"), py::arg("phases"), py::arg("is_time_based") = true)
        .def(
            "amplitude", 
            (double(Sine<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &Sine<Eigen::AutoDiffScalar<Eigen::VectorXd> >::amplitude, 
            " "  )
        .def(
            "frequency", 
            (double(Sine<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &Sine<Eigen::AutoDiffScalar<Eigen::VectorXd> >::frequency, 
            " "  )
        .def(
            "phase", 
            (double(Sine<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &Sine<Eigen::AutoDiffScalar<Eigen::VectorXd> >::phase, 
            " "  )
        .def(
            "is_time_based", 
            (bool(Sine<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &Sine<Eigen::AutoDiffScalar<Eigen::VectorXd> >::is_time_based, 
            " "  )
        .def(
            "amplitude_vector", 
            (::Eigen::VectorXd const &(Sine<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &Sine<Eigen::AutoDiffScalar<Eigen::VectorXd> >::amplitude_vector, 
            " "  )
        .def(
            "frequency_vector", 
            (::Eigen::VectorXd const &(Sine<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &Sine<Eigen::AutoDiffScalar<Eigen::VectorXd> >::frequency_vector, 
            " "  )
        .def(
            "phase_vector", 
            (::Eigen::VectorXd const &(Sine<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &Sine<Eigen::AutoDiffScalar<Eigen::VectorXd> >::phase_vector, 
            " "  )
    ;
}
