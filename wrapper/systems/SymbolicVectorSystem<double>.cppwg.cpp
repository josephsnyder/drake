#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "SymbolicVectorSystem<double>.cppwg.hpp"

namespace py = pybind11;
typedef SymbolicVectorSystem<double> SymbolicVectorSystem<double>;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

class SymbolicVectorSystem<double>_Overloads : public SymbolicVectorSystem<double>{
    public:
    using SymbolicVectorSystem<double>::SymbolicVectorSystem<double>;

};
void register_SymbolicVectorSystem<double>_class(py::module &m){
py::class_<SymbolicVectorSystem<double> , SymbolicVectorSystem<double>_Overloads , std::shared_ptr<SymbolicVectorSystem<double> >   >(m, "SymbolicVectorSystem<double>")
        .def(py::init<::std::optional<drake::symbolic::Variable> const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Expression, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Expression, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, double >(), py::arg("time"), py::arg("state"), py::arg("input"), py::arg("parameter"), py::arg("dynamics"), py::arg("output") = Vector0<symbolic::Expression>{}, py::arg("time_period") = 0.)
        .def(py::init<::std::optional<drake::symbolic::Variable> const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Expression, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Expression, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, double >(), py::arg("time"), py::arg("state"), py::arg("input"), py::arg("dynamics"), py::arg("output") = Vector0<symbolic::Expression>{}, py::arg("time_period") = 0.)
        .def(
            "get_input_port", 
            (::drake::systems::InputPort<double> const &(SymbolicVectorSystem<double>::*)() const ) &SymbolicVectorSystem<double>::get_input_port, 
            " "  )
        .def(
            "get_output_port", 
            (::drake::systems::OutputPort<double> const &(SymbolicVectorSystem<double>::*)() const ) &SymbolicVectorSystem<double>::get_output_port, 
            " "  )
        .def(
            "time_var", 
            (::std::optional<drake::symbolic::Variable> const &(SymbolicVectorSystem<double>::*)() const ) &SymbolicVectorSystem<double>::time_var, 
            " "  )
        .def(
            "state_vars", 
            (::Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1> const &(SymbolicVectorSystem<double>::*)() const ) &SymbolicVectorSystem<double>::state_vars, 
            " "  )
        .def(
            "input_vars", 
            (::Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1> const &(SymbolicVectorSystem<double>::*)() const ) &SymbolicVectorSystem<double>::input_vars, 
            " "  )
        .def(
            "parameter_vars", 
            (::Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1> const &(SymbolicVectorSystem<double>::*)() const ) &SymbolicVectorSystem<double>::parameter_vars, 
            " "  )
        .def(
            "dynamics", 
            (::Eigen::Matrix<drake::symbolic::Expression, -1, 1, 0, -1, 1> const &(SymbolicVectorSystem<double>::*)() const ) &SymbolicVectorSystem<double>::dynamics, 
            " "  )
        .def(
            "dynamics_for_variable", 
            (::drake::symbolic::Expression const &(SymbolicVectorSystem<double>::*)(::drake::symbolic::Variable const &) const ) &SymbolicVectorSystem<double>::dynamics_for_variable, 
            " " , py::arg("var") )
        .def(
            "output", 
            (::Eigen::Matrix<drake::symbolic::Expression, -1, 1, 0, -1, 1> const &(SymbolicVectorSystem<double>::*)() const ) &SymbolicVectorSystem<double>::output, 
            " "  )
    ;
}
