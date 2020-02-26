#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "SymbolicVectorSystem<drake::symbolic::Expression>.cppwg.hpp"

namespace py = pybind11;
typedef SymbolicVectorSystem<drake::symbolic::Expression> SymbolicVectorSystem<drake::symbolic::Expression>;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

class SymbolicVectorSystem<drake::symbolic::Expression>_Overloads : public SymbolicVectorSystem<drake::symbolic::Expression>{
    public:
    using SymbolicVectorSystem<drake::symbolic::Expression>::SymbolicVectorSystem<drake::symbolic::Expression>;

};
void register_SymbolicVectorSystem<drake::symbolic::Expression>_class(py::module &m){
py::class_<SymbolicVectorSystem<drake::symbolic::Expression> , SymbolicVectorSystem<drake::symbolic::Expression>_Overloads , std::shared_ptr<SymbolicVectorSystem<drake::symbolic::Expression> >   >(m, "SymbolicVectorSystem<drake::symbolic::Expression>")
        .def(py::init<::std::optional<drake::symbolic::Variable> const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Expression, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Expression, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, double >(), py::arg("time"), py::arg("state"), py::arg("input"), py::arg("parameter"), py::arg("dynamics"), py::arg("output") = Vector0<symbolic::Expression>{}, py::arg("time_period") = 0.)
        .def(py::init<::std::optional<drake::symbolic::Variable> const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Expression, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Expression, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, double >(), py::arg("time"), py::arg("state"), py::arg("input"), py::arg("dynamics"), py::arg("output") = Vector0<symbolic::Expression>{}, py::arg("time_period") = 0.)
        .def(
            "get_input_port", 
            (::drake::systems::InputPort<drake::symbolic::Expression> const &(SymbolicVectorSystem<drake::symbolic::Expression>::*)() const ) &SymbolicVectorSystem<drake::symbolic::Expression>::get_input_port, 
            " "  )
        .def(
            "get_output_port", 
            (::drake::systems::OutputPort<drake::symbolic::Expression> const &(SymbolicVectorSystem<drake::symbolic::Expression>::*)() const ) &SymbolicVectorSystem<drake::symbolic::Expression>::get_output_port, 
            " "  )
        .def(
            "time_var", 
            (::std::optional<drake::symbolic::Variable> const &(SymbolicVectorSystem<drake::symbolic::Expression>::*)() const ) &SymbolicVectorSystem<drake::symbolic::Expression>::time_var, 
            " "  )
        .def(
            "state_vars", 
            (::Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1> const &(SymbolicVectorSystem<drake::symbolic::Expression>::*)() const ) &SymbolicVectorSystem<drake::symbolic::Expression>::state_vars, 
            " "  )
        .def(
            "input_vars", 
            (::Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1> const &(SymbolicVectorSystem<drake::symbolic::Expression>::*)() const ) &SymbolicVectorSystem<drake::symbolic::Expression>::input_vars, 
            " "  )
        .def(
            "parameter_vars", 
            (::Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1> const &(SymbolicVectorSystem<drake::symbolic::Expression>::*)() const ) &SymbolicVectorSystem<drake::symbolic::Expression>::parameter_vars, 
            " "  )
        .def(
            "dynamics", 
            (::Eigen::Matrix<drake::symbolic::Expression, -1, 1, 0, -1, 1> const &(SymbolicVectorSystem<drake::symbolic::Expression>::*)() const ) &SymbolicVectorSystem<drake::symbolic::Expression>::dynamics, 
            " "  )
        .def(
            "dynamics_for_variable", 
            (::drake::symbolic::Expression const &(SymbolicVectorSystem<drake::symbolic::Expression>::*)(::drake::symbolic::Variable const &) const ) &SymbolicVectorSystem<drake::symbolic::Expression>::dynamics_for_variable, 
            " " , py::arg("var") )
        .def(
            "output", 
            (::Eigen::Matrix<drake::symbolic::Expression, -1, 1, 0, -1, 1> const &(SymbolicVectorSystem<drake::symbolic::Expression>::*)() const ) &SymbolicVectorSystem<drake::symbolic::Expression>::output, 
            " "  )
    ;
}
