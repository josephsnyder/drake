#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "TimeVaryingAffineSystem<double>.cppwg.hpp"

namespace py = pybind11;
typedef TimeVaryingAffineSystem<double> TimeVaryingAffineSystem<double>;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
typedef ::Eigen::Matrix<double, -1, -1, 0, -1, -1> _Eigen_Matrix_lt_double_neg1_neg1_0_neg1_neg1_gt_;
typedef ::Eigen::Matrix<double, -1, -1, 0, -1, -1> _Eigen_Matrix_lt_double_neg1_neg1_0_neg1_neg1_gt_;
typedef ::Eigen::Matrix<double, -1, 1, 0, -1, 1> _Eigen_Matrix_lt_double_neg1_1_0_neg1_1_gt_;
typedef ::Eigen::Matrix<double, -1, -1, 0, -1, -1> _Eigen_Matrix_lt_double_neg1_neg1_0_neg1_neg1_gt_;
typedef ::Eigen::Matrix<double, -1, -1, 0, -1, -1> _Eigen_Matrix_lt_double_neg1_neg1_0_neg1_neg1_gt_;
typedef ::Eigen::Matrix<double, -1, 1, 0, -1, 1> _Eigen_Matrix_lt_double_neg1_1_0_neg1_1_gt_;

class TimeVaryingAffineSystem<double>_Overloads : public TimeVaryingAffineSystem<double>{
    public:
    using TimeVaryingAffineSystem<double>::TimeVaryingAffineSystem<double>;
    ::Eigen::Matrix<double, -1, -1, 0, -1, -1> A(double const & t) const  override {
        PYBIND11_OVERLOAD_PURE(
            _Eigen_Matrix_lt_double_neg1_neg1_0_neg1_neg1_gt_,
            TimeVaryingAffineSystem<double>,
            A,
            t);
    }
    ::Eigen::Matrix<double, -1, -1, 0, -1, -1> B(double const & t) const  override {
        PYBIND11_OVERLOAD_PURE(
            _Eigen_Matrix_lt_double_neg1_neg1_0_neg1_neg1_gt_,
            TimeVaryingAffineSystem<double>,
            B,
            t);
    }
    ::Eigen::Matrix<double, -1, 1, 0, -1, 1> f0(double const & t) const  override {
        PYBIND11_OVERLOAD_PURE(
            _Eigen_Matrix_lt_double_neg1_1_0_neg1_1_gt_,
            TimeVaryingAffineSystem<double>,
            f0,
            t);
    }
    ::Eigen::Matrix<double, -1, -1, 0, -1, -1> C(double const & t) const  override {
        PYBIND11_OVERLOAD_PURE(
            _Eigen_Matrix_lt_double_neg1_neg1_0_neg1_neg1_gt_,
            TimeVaryingAffineSystem<double>,
            C,
            t);
    }
    ::Eigen::Matrix<double, -1, -1, 0, -1, -1> D(double const & t) const  override {
        PYBIND11_OVERLOAD_PURE(
            _Eigen_Matrix_lt_double_neg1_neg1_0_neg1_neg1_gt_,
            TimeVaryingAffineSystem<double>,
            D,
            t);
    }
    ::Eigen::Matrix<double, -1, 1, 0, -1, 1> y0(double const & t) const  override {
        PYBIND11_OVERLOAD_PURE(
            _Eigen_Matrix_lt_double_neg1_1_0_neg1_1_gt_,
            TimeVaryingAffineSystem<double>,
            y0,
            t);
    }
    void CalcOutputY(::drake::systems::Context<double> const & context, ::drake::systems::BasicVector<double> * output_vector) const  override {
        PYBIND11_OVERLOAD(
            void,
            TimeVaryingAffineSystem<double>,
            CalcOutputY,
            context, 
output_vector);
    }
    void DoCalcTimeDerivatives(::drake::systems::Context<double> const & context, ::drake::systems::ContinuousState<double> * derivatives) const  override {
        PYBIND11_OVERLOAD(
            void,
            TimeVaryingAffineSystem<double>,
            DoCalcTimeDerivatives,
            context, 
derivatives);
    }
    void DoCalcDiscreteVariableUpdates(::drake::systems::Context<double> const & context, ::std::vector<const drake::systems::DiscreteUpdateEvent<double> *, std::allocator<const drake::systems::DiscreteUpdateEvent<double> *> > const & events, ::drake::systems::DiscreteValues<double> * updates) const  override {
        PYBIND11_OVERLOAD(
            void,
            TimeVaryingAffineSystem<double>,
            DoCalcDiscreteVariableUpdates,
            context, 
events, 
updates);
    }
    void SetDefaultState(::drake::systems::Context<double> const & context, ::drake::systems::State<double> * state) const  override {
        PYBIND11_OVERLOAD(
            void,
            TimeVaryingAffineSystem<double>,
            SetDefaultState,
            context, 
state);
    }
    void SetRandomState(::drake::systems::Context<double> const & context, ::drake::systems::State<double> * state, ::drake::RandomGenerator * generator) const  override {
        PYBIND11_OVERLOAD(
            void,
            TimeVaryingAffineSystem<double>,
            SetRandomState,
            context, 
state, 
generator);
    }

};
void register_TimeVaryingAffineSystem<double>_class(py::module &m){
py::class_<TimeVaryingAffineSystem<double> , TimeVaryingAffineSystem<double>_Overloads , std::shared_ptr<TimeVaryingAffineSystem<double> >   >(m, "TimeVaryingAffineSystem<double>")
        .def(
            "get_input_port", 
            (::drake::systems::InputPort<double> const &(TimeVaryingAffineSystem<double>::*)() const ) &TimeVaryingAffineSystem<double>::get_input_port, 
            " "  )
        .def(
            "get_output_port", 
            (::drake::systems::OutputPort<double> const &(TimeVaryingAffineSystem<double>::*)() const ) &TimeVaryingAffineSystem<double>::get_output_port, 
            " "  )
        .def(
            "A", 
            (::Eigen::Matrix<double, -1, -1, 0, -1, -1>(TimeVaryingAffineSystem<double>::*)(double const &) const ) &TimeVaryingAffineSystem<double>::A, 
            " " , py::arg("t") )
        .def(
            "B", 
            (::Eigen::Matrix<double, -1, -1, 0, -1, -1>(TimeVaryingAffineSystem<double>::*)(double const &) const ) &TimeVaryingAffineSystem<double>::B, 
            " " , py::arg("t") )
        .def(
            "f0", 
            (::Eigen::Matrix<double, -1, 1, 0, -1, 1>(TimeVaryingAffineSystem<double>::*)(double const &) const ) &TimeVaryingAffineSystem<double>::f0, 
            " " , py::arg("t") )
        .def(
            "C", 
            (::Eigen::Matrix<double, -1, -1, 0, -1, -1>(TimeVaryingAffineSystem<double>::*)(double const &) const ) &TimeVaryingAffineSystem<double>::C, 
            " " , py::arg("t") )
        .def(
            "D", 
            (::Eigen::Matrix<double, -1, -1, 0, -1, -1>(TimeVaryingAffineSystem<double>::*)(double const &) const ) &TimeVaryingAffineSystem<double>::D, 
            " " , py::arg("t") )
        .def(
            "y0", 
            (::Eigen::Matrix<double, -1, 1, 0, -1, 1>(TimeVaryingAffineSystem<double>::*)(double const &) const ) &TimeVaryingAffineSystem<double>::y0, 
            " " , py::arg("t") )
        .def(
            "configure_default_state", 
            (void(TimeVaryingAffineSystem<double>::*)(::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &)) &TimeVaryingAffineSystem<double>::configure_default_state, 
            " " , py::arg("x0") )
        .def(
            "configure_random_state", 
            (void(TimeVaryingAffineSystem<double>::*)(::Eigen::Ref<const Eigen::Matrix<double, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1> > const &)) &TimeVaryingAffineSystem<double>::configure_random_state, 
            " " , py::arg("covariance") )
        .def(
            "get_default_state", 
            (::Eigen::Matrix<double, -1, 1, 0, -1, 1> const &(TimeVaryingAffineSystem<double>::*)() const ) &TimeVaryingAffineSystem<double>::get_default_state, 
            " "  )
        .def(
            "get_random_state_covariance", 
            (::Eigen::MatrixXd const(TimeVaryingAffineSystem<double>::*)() const ) &TimeVaryingAffineSystem<double>::get_random_state_covariance, 
            " "  )
        .def(
            "time_period", 
            (double(TimeVaryingAffineSystem<double>::*)() const ) &TimeVaryingAffineSystem<double>::time_period, 
            " "  )
        .def(
            "num_states", 
            (int(TimeVaryingAffineSystem<double>::*)() const ) &TimeVaryingAffineSystem<double>::num_states, 
            " "  )
        .def(
            "num_inputs", 
            (int(TimeVaryingAffineSystem<double>::*)() const ) &TimeVaryingAffineSystem<double>::num_inputs, 
            " "  )
        .def(
            "num_outputs", 
            (int(TimeVaryingAffineSystem<double>::*)() const ) &TimeVaryingAffineSystem<double>::num_outputs, 
            " "  )
    ;
}
