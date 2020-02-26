#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "Gain<drake::symbolic::Expression>.cppwg.hpp"

namespace py = pybind11;
typedef Gain<drake::symbolic::Expression> Gain<drake::symbolic::Expression>;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

class Gain<drake::symbolic::Expression>_Overloads : public Gain<drake::symbolic::Expression>{
    public:
    using Gain<drake::symbolic::Expression>::Gain<drake::symbolic::Expression>;

};
void register_Gain<drake::symbolic::Expression>_class(py::module &m){
py::class_<Gain<drake::symbolic::Expression> , Gain<drake::symbolic::Expression>_Overloads , std::shared_ptr<Gain<drake::symbolic::Expression> >  , VectorSystem<drake::symbolic::Expression>  >(m, "Gain<drake::symbolic::Expression>")
        .def(py::init<double, int >(), py::arg("k"), py::arg("size"))
        .def(py::init<::Eigen::VectorXd const & >(), py::arg("k"))
        .def(
            "get_gain", 
            (double(Gain<drake::symbolic::Expression>::*)() const ) &Gain<drake::symbolic::Expression>::get_gain, 
            " "  )
        .def(
            "get_gain_vector", 
            (::Eigen::VectorXd const &(Gain<drake::symbolic::Expression>::*)() const ) &Gain<drake::symbolic::Expression>::get_gain_vector, 
            " "  )
    ;
}
