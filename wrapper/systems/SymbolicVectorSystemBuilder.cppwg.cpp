#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "SymbolicVectorSystemBuilder.cppwg.hpp"

namespace py = pybind11;
typedef SymbolicVectorSystemBuilder SymbolicVectorSystemBuilder;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

void register_SymbolicVectorSystemBuilder_class(py::module &m){
py::class_<SymbolicVectorSystemBuilder  , std::shared_ptr<SymbolicVectorSystemBuilder >   >(m, "SymbolicVectorSystemBuilder")
        .def(py::init<::drake::systems::SymbolicVectorSystemBuilder const & >(), py::arg("arg0"))
        .def(py::init< >())
        .def_static(
            "DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE", 
            (void(*)()) &SymbolicVectorSystemBuilder::DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE, 
            " "  )
        .def(
            "time", 
            (::drake::systems::SymbolicVectorSystemBuilder(SymbolicVectorSystemBuilder::*)(::drake::symbolic::Variable const &)) &SymbolicVectorSystemBuilder::time, 
            " " , py::arg("t") )
        .def(
            "state", 
            (::drake::systems::SymbolicVectorSystemBuilder(SymbolicVectorSystemBuilder::*)(::drake::symbolic::Variable const &)) &SymbolicVectorSystemBuilder::state, 
            " " , py::arg("v") )
        .def(
            "state", 
            (::drake::systems::SymbolicVectorSystemBuilder(SymbolicVectorSystemBuilder::*)(::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &)) &SymbolicVectorSystemBuilder::state, 
            " " , py::arg("vars") )
        .def(
            "state", 
            (::drake::systems::SymbolicVectorSystemBuilder(SymbolicVectorSystemBuilder::*)(::std::vector<drake::symbolic::Variable, std::allocator<drake::symbolic::Variable> > const &)) &SymbolicVectorSystemBuilder::state, 
            " " , py::arg("vars") )
        .def(
            "input", 
            (::drake::systems::SymbolicVectorSystemBuilder(SymbolicVectorSystemBuilder::*)(::drake::symbolic::Variable const &)) &SymbolicVectorSystemBuilder::input, 
            " " , py::arg("v") )
        .def(
            "input", 
            (::drake::systems::SymbolicVectorSystemBuilder(SymbolicVectorSystemBuilder::*)(::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &)) &SymbolicVectorSystemBuilder::input, 
            " " , py::arg("vars") )
        .def(
            "input", 
            (::drake::systems::SymbolicVectorSystemBuilder(SymbolicVectorSystemBuilder::*)(::std::vector<drake::symbolic::Variable, std::allocator<drake::symbolic::Variable> > const &)) &SymbolicVectorSystemBuilder::input, 
            " " , py::arg("vars") )
        .def(
            "parameter", 
            (::drake::systems::SymbolicVectorSystemBuilder(SymbolicVectorSystemBuilder::*)(::drake::symbolic::Variable const &)) &SymbolicVectorSystemBuilder::parameter, 
            " " , py::arg("v") )
        .def(
            "parameter", 
            (::drake::systems::SymbolicVectorSystemBuilder(SymbolicVectorSystemBuilder::*)(::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &)) &SymbolicVectorSystemBuilder::parameter, 
            " " , py::arg("vars") )
        .def(
            "parameter", 
            (::drake::systems::SymbolicVectorSystemBuilder(SymbolicVectorSystemBuilder::*)(::std::vector<drake::symbolic::Variable, std::allocator<drake::symbolic::Variable> > const &)) &SymbolicVectorSystemBuilder::parameter, 
            " " , py::arg("vars") )
        .def(
            "dynamics", 
            (::drake::systems::SymbolicVectorSystemBuilder(SymbolicVectorSystemBuilder::*)(::drake::symbolic::Expression const &)) &SymbolicVectorSystemBuilder::dynamics, 
            " " , py::arg("e") )
        .def(
            "dynamics", 
            (::drake::systems::SymbolicVectorSystemBuilder(SymbolicVectorSystemBuilder::*)(::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Expression, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &)) &SymbolicVectorSystemBuilder::dynamics, 
            " " , py::arg("e") )
        .def(
            "dynamics", 
            (::drake::systems::SymbolicVectorSystemBuilder(SymbolicVectorSystemBuilder::*)(::std::vector<drake::symbolic::Expression, std::allocator<drake::symbolic::Expression> > const &)) &SymbolicVectorSystemBuilder::dynamics, 
            " " , py::arg("e") )
        .def(
            "output", 
            (::drake::systems::SymbolicVectorSystemBuilder(SymbolicVectorSystemBuilder::*)(::drake::symbolic::Expression const &)) &SymbolicVectorSystemBuilder::output, 
            " " , py::arg("e") )
        .def(
            "output", 
            (::drake::systems::SymbolicVectorSystemBuilder(SymbolicVectorSystemBuilder::*)(::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Expression, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &)) &SymbolicVectorSystemBuilder::output, 
            " " , py::arg("e") )
        .def(
            "output", 
            (::drake::systems::SymbolicVectorSystemBuilder(SymbolicVectorSystemBuilder::*)(::std::vector<drake::symbolic::Expression, std::allocator<drake::symbolic::Expression> > const &)) &SymbolicVectorSystemBuilder::output, 
            " " , py::arg("e") )
        .def(
            "LinearizeDynamics", 
            (::drake::systems::SymbolicVectorSystemBuilder(SymbolicVectorSystemBuilder::*)(::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Expression, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &, ::Eigen::Ref<const Eigen::Matrix<drake::symbolic::Expression, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &)) &SymbolicVectorSystemBuilder::LinearizeDynamics, 
            " " , py::arg("x0"), py::arg("u0") )
        .def(
            "time_period", 
            (::drake::systems::SymbolicVectorSystemBuilder(SymbolicVectorSystemBuilder::*)(double)) &SymbolicVectorSystemBuilder::time_period, 
            " " , py::arg("p") )
        .def(
            "time", 
            (::std::optional<drake::symbolic::Variable> const &(SymbolicVectorSystemBuilder::*)() const ) &SymbolicVectorSystemBuilder::time, 
            " "  )
        .def(
            "state", 
            (::Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1> const &(SymbolicVectorSystemBuilder::*)() const ) &SymbolicVectorSystemBuilder::state, 
            " "  )
        .def(
            "input", 
            (::Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1> const &(SymbolicVectorSystemBuilder::*)() const ) &SymbolicVectorSystemBuilder::input, 
            " "  )
        .def(
            "parameter", 
            (::Eigen::Matrix<drake::symbolic::Variable, -1, 1, 0, -1, 1> const &(SymbolicVectorSystemBuilder::*)() const ) &SymbolicVectorSystemBuilder::parameter, 
            " "  )
        .def(
            "dynamics", 
            (::Eigen::Matrix<drake::symbolic::Expression, -1, 1, 0, -1, 1> const &(SymbolicVectorSystemBuilder::*)() const ) &SymbolicVectorSystemBuilder::dynamics, 
            " "  )
        .def(
            "dynamics_for_variable", 
            (::drake::symbolic::Expression const &(SymbolicVectorSystemBuilder::*)(::drake::symbolic::Variable const &) const ) &SymbolicVectorSystemBuilder::dynamics_for_variable, 
            " " , py::arg("var") )
        .def(
            "output", 
            (::Eigen::Matrix<drake::symbolic::Expression, -1, 1, 0, -1, 1> const &(SymbolicVectorSystemBuilder::*)() const ) &SymbolicVectorSystemBuilder::output, 
            " "  )
        .def(
            "time_period", 
            (double(SymbolicVectorSystemBuilder::*)() const ) &SymbolicVectorSystemBuilder::time_period, 
            " "  )
    ;
}
