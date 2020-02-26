#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >.cppwg.hpp"

namespace py = pybind11;
typedef TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> > TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
typedef ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, -1, 0, -1, -1> _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_neg1_0_neg1_neg1_gt_;
typedef ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, -1, 0, -1, -1> _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_neg1_0_neg1_neg1_gt_;
typedef ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, 1, 0, -1, 1> _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_1_0_neg1_1_gt_;
typedef ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, -1, 0, -1, -1> _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_neg1_0_neg1_neg1_gt_;
typedef ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, -1, 0, -1, -1> _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_neg1_0_neg1_neg1_gt_;
typedef ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, 1, 0, -1, 1> _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_1_0_neg1_1_gt_;

class TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >_Overloads : public TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >{
    public:
    using TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >;
    ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, -1, 0, -1, -1> A(::Eigen::AutoDiffScalar<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const & t) const  override {
        PYBIND11_OVERLOAD_PURE(
            _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_neg1_0_neg1_neg1_gt_,
            TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >,
            A,
            t);
    }
    ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, -1, 0, -1, -1> B(::Eigen::AutoDiffScalar<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const & t) const  override {
        PYBIND11_OVERLOAD_PURE(
            _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_neg1_0_neg1_neg1_gt_,
            TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >,
            B,
            t);
    }
    ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, 1, 0, -1, 1> f0(::Eigen::AutoDiffScalar<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const & t) const  override {
        PYBIND11_OVERLOAD_PURE(
            _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_1_0_neg1_1_gt_,
            TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >,
            f0,
            t);
    }
    ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, -1, 0, -1, -1> C(::Eigen::AutoDiffScalar<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const & t) const  override {
        PYBIND11_OVERLOAD_PURE(
            _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_neg1_0_neg1_neg1_gt_,
            TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >,
            C,
            t);
    }
    ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, -1, 0, -1, -1> D(::Eigen::AutoDiffScalar<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const & t) const  override {
        PYBIND11_OVERLOAD_PURE(
            _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_neg1_0_neg1_neg1_gt_,
            TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >,
            D,
            t);
    }
    ::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, 1, 0, -1, 1> y0(::Eigen::AutoDiffScalar<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const & t) const  override {
        PYBIND11_OVERLOAD_PURE(
            _Eigen_Matrix_lt_Eigen_AutoDiffScalar_lt_Eigen_VectorXd_gt__neg1_1_0_neg1_1_gt_,
            TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >,
            y0,
            t);
    }
    void CalcOutputY(::drake::systems::Context<Eigen::AutoDiffScalar<Eigen::VectorXd> > const & context, ::drake::systems::BasicVector<Eigen::AutoDiffScalar<Eigen::VectorXd> > * output_vector) const  override {
        PYBIND11_OVERLOAD(
            void,
            TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >,
            CalcOutputY,
            context, 
output_vector);
    }
    void DoCalcTimeDerivatives(::drake::systems::Context<Eigen::AutoDiffScalar<Eigen::VectorXd> > const & context, ::drake::systems::ContinuousState<Eigen::AutoDiffScalar<Eigen::VectorXd> > * derivatives) const  override {
        PYBIND11_OVERLOAD(
            void,
            TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >,
            DoCalcTimeDerivatives,
            context, 
derivatives);
    }
    void DoCalcDiscreteVariableUpdates(::drake::systems::Context<Eigen::AutoDiffScalar<Eigen::VectorXd> > const & context, ::std::vector<const drake::systems::DiscreteUpdateEvent< ::drake::AutoDiffXd> *, std::allocator<const drake::systems::DiscreteUpdateEvent< ::drake::AutoDiffXd> *> > const & events, ::drake::systems::DiscreteValues<Eigen::AutoDiffScalar<Eigen::VectorXd> > * updates) const  override {
        PYBIND11_OVERLOAD(
            void,
            TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >,
            DoCalcDiscreteVariableUpdates,
            context, 
events, 
updates);
    }
    void SetDefaultState(::drake::systems::Context<Eigen::AutoDiffScalar<Eigen::VectorXd> > const & context, ::drake::systems::State<Eigen::AutoDiffScalar<Eigen::VectorXd> > * state) const  override {
        PYBIND11_OVERLOAD(
            void,
            TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >,
            SetDefaultState,
            context, 
state);
    }
    void SetRandomState(::drake::systems::Context<Eigen::AutoDiffScalar<Eigen::VectorXd> > const & context, ::drake::systems::State<Eigen::AutoDiffScalar<Eigen::VectorXd> > * state, ::drake::RandomGenerator * generator) const  override {
        PYBIND11_OVERLOAD(
            void,
            TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >,
            SetRandomState,
            context, 
state, 
generator);
    }

};
void register_TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >_class(py::module &m){
py::class_<TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> > , TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >_Overloads , std::shared_ptr<TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> > >   >(m, "TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >")
        .def(
            "get_input_port", 
            (::drake::systems::InputPort<Eigen::AutoDiffScalar<Eigen::VectorXd> > const &(TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::get_input_port, 
            " "  )
        .def(
            "get_output_port", 
            (::drake::systems::OutputPort<Eigen::AutoDiffScalar<Eigen::VectorXd> > const &(TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::get_output_port, 
            " "  )
        .def(
            "A", 
            (::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, -1, 0, -1, -1>(TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)(::Eigen::AutoDiffScalar<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const &) const ) &TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::A, 
            " " , py::arg("t") )
        .def(
            "B", 
            (::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, -1, 0, -1, -1>(TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)(::Eigen::AutoDiffScalar<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const &) const ) &TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::B, 
            " " , py::arg("t") )
        .def(
            "f0", 
            (::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, 1, 0, -1, 1>(TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)(::Eigen::AutoDiffScalar<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const &) const ) &TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::f0, 
            " " , py::arg("t") )
        .def(
            "C", 
            (::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, -1, 0, -1, -1>(TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)(::Eigen::AutoDiffScalar<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const &) const ) &TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::C, 
            " " , py::arg("t") )
        .def(
            "D", 
            (::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, -1, 0, -1, -1>(TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)(::Eigen::AutoDiffScalar<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const &) const ) &TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::D, 
            " " , py::arg("t") )
        .def(
            "y0", 
            (::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, 1, 0, -1, 1>(TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)(::Eigen::AutoDiffScalar<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const &) const ) &TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::y0, 
            " " , py::arg("t") )
        .def(
            "configure_default_state", 
            (void(TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)(::Eigen::Ref<const Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &)) &TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::configure_default_state, 
            " " , py::arg("x0") )
        .def(
            "configure_random_state", 
            (void(TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)(::Eigen::Ref<const Eigen::Matrix<double, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1> > const &)) &TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::configure_random_state, 
            " " , py::arg("covariance") )
        .def(
            "get_default_state", 
            (::Eigen::Matrix<Eigen::AutoDiffScalar<Eigen::VectorXd>, -1, 1, 0, -1, 1> const &(TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::get_default_state, 
            " "  )
        .def(
            "get_random_state_covariance", 
            (::Eigen::MatrixXd const(TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::get_random_state_covariance, 
            " "  )
        .def(
            "time_period", 
            (double(TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::time_period, 
            " "  )
        .def(
            "num_states", 
            (int(TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::num_states, 
            " "  )
        .def(
            "num_inputs", 
            (int(TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::num_inputs, 
            " "  )
        .def(
            "num_outputs", 
            (int(TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::*)() const ) &TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >::num_outputs, 
            " "  )
    ;
}
