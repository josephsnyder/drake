#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >.cppwg.hpp"

namespace py = pybind11;
typedef SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> > SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

class SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >_Overloads : public SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >{
    public:
    using SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >;

};
void register_SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >_class(py::module &m){
py::class_<SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> > , SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >_Overloads , std::shared_ptr<SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> > >   >(m, "SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >")
        .def(py::init<::std::optional<drake::symbolic::Variable> const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Expression, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Expression, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, double >(), py::arg("time"), py::arg("state"), py::arg("input"), py::arg("parameter"), py::arg("dynamics"), py::arg("output") = Vector0<symbolic::Expression>{}, py::arg("time_period") = 0.)
        .def(py::init<::std::optional<drake::symbolic::Variable> const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Expression, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Expression, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, double >(), py::arg("time"), py::arg("state"), py::arg("input"), py::arg("dynamics"), py::arg("output") = Vector0<symbolic::Expression>{}, py::arg("time_period") = 0.)
        .def(
            "get_input_port", 
            (::drake::systems::InputPort<Eigen::AutoDiffScalar<Eigen::VectorXd> > const &(SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::get_input_port, 
            " "  )
        .def(
            "get_output_port", 
            (::drake::systems::OutputPort<Eigen::AutoDiffScalar<Eigen::VectorXd> > const &(SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::get_output_port, 
            " "  )
        .def(
            "time_var", 
            (::std::optional<drake::symbolic::Variable> const &(SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::time_var, 
            " "  )
        .def(
            "state_vars", 
            (::Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1> const &(SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::state_vars, 
            " "  )
        .def(
            "input_vars", 
            (::Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1> const &(SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::input_vars, 
            " "  )
        .def(
            "parameter_vars", 
            (::Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1> const &(SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::parameter_vars, 
            " "  )
        .def(
            "dynamics", 
            (::Eigen::Matrix<drake::symbolic::Expression, -1, 1, 0, -1, 1> const &(SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::dynamics, 
            " "  )
        .def(
            "dynamics_for_variable", 
            (::drake::symbolic::Expression const &(SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)(::drake::symbolic::Variable const &) const ) &SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::dynamics_for_variable, 
            " " , py::arg("var") )
        .def(
            "output", 
            (::Eigen::Matrix<drake::symbolic::Expression, -1, 1, 0, -1, 1> const &(SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::output, 
            " "  )
    ;
}
