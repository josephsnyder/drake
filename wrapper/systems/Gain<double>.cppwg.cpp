#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "Gain<double>.cppwg.hpp"

namespace py = pybind11;
typedef Gain<double> Gain<double>;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

class Gain<double>_Overloads : public Gain<double>{
    public:
    using Gain<double>::Gain<double>;

};
void register_Gain<double>_class(py::module &m){
py::class_<Gain<double> , Gain<double>_Overloads , std::shared_ptr<Gain<double> >  , VectorSystem<double>  >(m, "Gain<double>")
        .def(py::init<double, int >(), py::arg("k"), py::arg("size"))
        .def(py::init<::Eigen::VectorXd const & >(), py::arg("k"))
        .def(
            "get_gain", 
            (double(Gain<double>::*)() const ) &Gain<double>::get_gain, 
            " "  )
        .def(
            "get_gain_vector", 
            (::Eigen::VectorXd const &(Gain<double>::*)() const ) &Gain<double>::get_gain_vector, 
            " "  )
    ;
}
