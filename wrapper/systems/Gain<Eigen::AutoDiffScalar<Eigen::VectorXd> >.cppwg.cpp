#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "Gain<Eigen::AutoDiffScalar<Eigen::VectorXd> >.cppwg.hpp"

namespace py = pybind11;
typedef Gain<Eigen::AutoDiffScalar<Eigen::VectorXd> > Gain<Eigen::AutoDiffScalar<Eigen::VectorXd> >;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

class Gain<Eigen::AutoDiffScalar<Eigen::VectorXd> >_Overloads : public Gain<Eigen::AutoDiffScalar<Eigen::VectorXd> >{
    public:
    using Gain<Eigen::AutoDiffScalar<Eigen::VectorXd> >::Gain<Eigen::AutoDiffScalar<Eigen::VectorXd> >;

};
void register_Gain<Eigen::AutoDiffScalar<Eigen::VectorXd> >_class(py::module &m){
py::class_<Gain<Eigen::AutoDiffScalar<Eigen::VectorXd> > , Gain<Eigen::AutoDiffScalar<Eigen::VectorXd> >_Overloads , std::shared_ptr<Gain<Eigen::AutoDiffScalar<Eigen::VectorXd> > >  , VectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >  >(m, "Gain<Eigen::AutoDiffScalar<Eigen::VectorXd> >")
        .def(py::init<double, int >(), py::arg("k"), py::arg("size"))
        .def(py::init<::Eigen::VectorXd const & >(), py::arg("k"))
        .def(
            "get_gain", 
            (double(Gain<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &Gain<Eigen::AutoDiffScalar<Eigen::VectorXd> >::get_gain, 
            " "  )
        .def(
            "get_gain_vector", 
            (::Eigen::VectorXd const &(Gain<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &Gain<Eigen::AutoDiffScalar<Eigen::VectorXd> >::get_gain_vector, 
            " "  )
    ;
}
