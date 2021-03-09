#include "drake/systems/framework/leaf_system.h"
#include <pybind11/eigen.h>
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

class LeafSystem_double_publicist
    : public ::drake::systems::LeafSystem<double> {
public:
  using ::drake::systems::LeafSystem<
      double>::AddTriggeredWitnessFunctionToCompositeEventCollection;
  using ::drake::systems::LeafSystem<double>::AllocateAbstractState;
  using ::drake::systems::LeafSystem<double>::AllocateContinuousState;
  using ::drake::systems::LeafSystem<double>::AllocateDiscreteState;
  using ::drake::systems::LeafSystem<double>::AllocateParameters;
  using ::drake::systems::LeafSystem<double>::DeclareAbstractInputPort;
  using ::drake::systems::LeafSystem<double>::DeclareAbstractInputPort;
  using ::drake::systems::LeafSystem<double>::DeclareAbstractOutputPort;
  using ::drake::systems::LeafSystem<double>::DeclareAbstractOutputPort;
  using ::drake::systems::LeafSystem<double>::DeclareAbstractParameter;
  using ::drake::systems::LeafSystem<double>::DeclareAbstractState;
  using ::drake::systems::LeafSystem<double>::DeclareAbstractState;
  using ::drake::systems::LeafSystem<double>::DeclareContinuousState;
  using ::drake::systems::LeafSystem<double>::DeclareContinuousState;
  using ::drake::systems::LeafSystem<double>::DeclareContinuousState;
  using ::drake::systems::LeafSystem<double>::DeclareContinuousState;
  using ::drake::systems::LeafSystem<double>::DeclareDiscreteState;
  using ::drake::systems::LeafSystem<double>::DeclareDiscreteState;
  using ::drake::systems::LeafSystem<double>::DeclareDiscreteState;
  using ::drake::systems::LeafSystem<double>::DeclareEqualityConstraint;
  using ::drake::systems::LeafSystem<
      double>::DeclareImplicitTimeDerivativesResidualSize;
  using ::drake::systems::LeafSystem<double>::DeclareInequalityConstraint;
  using ::drake::systems::LeafSystem<double>::DeclareNumericParameter;
  using ::drake::systems::LeafSystem<double>::DeclarePeriodicDiscreteUpdate;
  using ::drake::systems::LeafSystem<double>::DeclarePeriodicPublish;
  using ::drake::systems::LeafSystem<double>::DeclarePeriodicUnrestrictedUpdate;
  using ::drake::systems::LeafSystem<double>::DeclareVectorInputPort;
  using ::drake::systems::LeafSystem<double>::DeclareVectorInputPort;
  using ::drake::systems::LeafSystem<double>::DeclareVectorOutputPort;
  using ::drake::systems::LeafSystem<double>::DeclareVectorOutputPort;
  using ::drake::systems::LeafSystem<double>::DoCalcDiscreteVariableUpdates;
  using ::drake::systems::LeafSystem<double>::DoCalcNextUpdateTime;
  using ::drake::systems::LeafSystem<double>::DoCalcUnrestrictedUpdate;
  using ::drake::systems::LeafSystem<double>::DoCalcWitnessValue;
  using ::drake::systems::LeafSystem<double>::DoMakeLeafContext;
  using ::drake::systems::LeafSystem<double>::DoPublish;
  using ::drake::systems::LeafSystem<double>::DoValidateAllocatedLeafContext;
  using ::drake::systems::LeafSystem<double>::GetGraphvizFragment;
  using ::drake::systems::LeafSystem<double>::GetGraphvizInputPortToken;
  using ::drake::systems::LeafSystem<double>::GetGraphvizOutputPortToken;
  using ::drake::systems::LeafSystem<double>::MakeWitnessFunction;
  using ::drake::systems::LeafSystem<double>::MakeWitnessFunction;
};

class LeafSystem_float_publicist : public ::drake::systems::LeafSystem<float> {
public:
  using ::drake::systems::LeafSystem<
      float>::AddTriggeredWitnessFunctionToCompositeEventCollection;
  using ::drake::systems::LeafSystem<float>::AllocateAbstractState;
  using ::drake::systems::LeafSystem<float>::AllocateContinuousState;
  using ::drake::systems::LeafSystem<float>::AllocateDiscreteState;
  using ::drake::systems::LeafSystem<float>::AllocateParameters;
  using ::drake::systems::LeafSystem<float>::DeclareAbstractOutputPort;
  using ::drake::systems::LeafSystem<float>::DeclareAbstractOutputPort;
  using ::drake::systems::LeafSystem<float>::DeclareAbstractParameter;
  using ::drake::systems::LeafSystem<float>::DeclareAbstractState;
  using ::drake::systems::LeafSystem<float>::DeclareAbstractState;
  using ::drake::systems::LeafSystem<float>::DeclareContinuousState;
  using ::drake::systems::LeafSystem<float>::DeclareContinuousState;
  using ::drake::systems::LeafSystem<float>::DeclareContinuousState;
  using ::drake::systems::LeafSystem<float>::DeclareContinuousState;
  using ::drake::systems::LeafSystem<float>::DeclareDiscreteState;
  using ::drake::systems::LeafSystem<float>::DeclareDiscreteState;
  using ::drake::systems::LeafSystem<float>::DeclareDiscreteState;
  using ::drake::systems::LeafSystem<float>::DeclareEqualityConstraint;
  using ::drake::systems::LeafSystem<
      float>::DeclareImplicitTimeDerivativesResidualSize;
  using ::drake::systems::LeafSystem<float>::DeclareInequalityConstraint;
  using ::drake::systems::LeafSystem<float>::DeclareNumericParameter;
  using ::drake::systems::LeafSystem<float>::DeclarePeriodicDiscreteUpdate;
  using ::drake::systems::LeafSystem<float>::DeclarePeriodicPublish;
  using ::drake::systems::LeafSystem<float>::DeclarePeriodicUnrestrictedUpdate;
  using ::drake::systems::LeafSystem<float>::DeclareVectorOutputPort;
  using ::drake::systems::LeafSystem<float>::DeclareVectorOutputPort;
  using ::drake::systems::LeafSystem<float>::DoCalcDiscreteVariableUpdates;
  using ::drake::systems::LeafSystem<float>::DoCalcNextUpdateTime;
  using ::drake::systems::LeafSystem<float>::DoCalcUnrestrictedUpdate;
  using ::drake::systems::LeafSystem<float>::DoMakeLeafContext;
  using ::drake::systems::LeafSystem<float>::DoPublish;
  using ::drake::systems::LeafSystem<float>::DoValidateAllocatedLeafContext;
  using ::drake::systems::LeafSystem<float>::GetGraphvizFragment;
  using ::drake::systems::LeafSystem<float>::GetGraphvizOutputPortToken;
  using ::drake::systems::LeafSystem<float>::MakeWitnessFunction;
  using ::drake::systems::LeafSystem<float>::MakeWitnessFunction;
};

namespace py = pybind11;
void apb11_pydrake_LeafSystem_py_register(py::module &m) {
  static bool called = false;
  if (called) {
    return;
  }
  called = true;
  py::class_<::drake::systems::LeafSystem<double>,
             ::drake::systems::System<double>>
      LeafSystem_double(m, "LeafSystem_double");

  LeafSystem_double
      .def("AddTriggeredWitnessFunctionToCompositeEventCollection",
           static_cast<void (::drake::systems::LeafSystem<double>::*)(
               ::drake::systems::Event<double> *,
               ::drake::systems::CompositeEventCollection<double> *) const>(
               &LeafSystem_double_publicist::
                   AddTriggeredWitnessFunctionToCompositeEventCollection),
           py::arg("event"), py::arg("events"))
      .def(
          "AllocateAbstractState",
          static_cast<::std::unique_ptr<
              drake::systems::AbstractValues,
              std::default_delete<drake::systems::AbstractValues>> (
              ::drake::systems::LeafSystem<double>::*)() const>(
              &LeafSystem_double_publicist::AllocateAbstractState),
          R"""(/** Returns a copy of the states declared in DeclareAbstractState() calls. */)""")
      .def(
          "AllocateCompositeEventCollection",
          static_cast<::std::unique_ptr<
              drake::systems::CompositeEventCollection<double>,
              std::default_delete<drake::systems::CompositeEventCollection<
                  double>>> (::drake::systems::LeafSystem<double>::*)() const>(
              &::drake::systems::LeafSystem<
                  double>::AllocateCompositeEventCollection),
          R"""(/** Allocates a CompositeEventCollection object for this system. 
@sa System::AllocateCompositeEventCollection(). */)""")
      .def(
          "AllocateContext",
          static_cast<::std::unique_ptr<
              drake::systems::LeafContext<double>,
              std::default_delete<drake::systems::LeafContext<double>>> (
              ::drake::systems::LeafSystem<double>::*)() const>(
              &::drake::systems::LeafSystem<double>::AllocateContext),
          R"""(/** Shadows System<T>::AllocateContext to provide a more concrete return 
type LeafContext<T>. */)""")
      .def("AllocateContinuousState",
           static_cast<::std::unique_ptr<
               drake::systems::ContinuousState<double>,
               std::default_delete<drake::systems::ContinuousState<double>>> (
               ::drake::systems::LeafSystem<double>::*)() const>(
               &LeafSystem_double_publicist::AllocateContinuousState),
           R"""(/** Returns a copy of the state declared in the most recent 
DeclareContinuousState() call, or else a zero-sized state if that method 
has never been called. */)""")
      .def(
          "AllocateDiscreteState",
          static_cast<::std::unique_ptr<
              drake::systems::DiscreteValues<double>,
              std::default_delete<drake::systems::DiscreteValues<double>>> (
              ::drake::systems::LeafSystem<double>::*)() const>(
              &LeafSystem_double_publicist::AllocateDiscreteState),
          R"""(/** Returns a copy of the states declared in DeclareDiscreteState() calls. */)""")
      .def(
          "AllocateDiscreteVariables",
          static_cast<::std::unique_ptr<
              drake::systems::DiscreteValues<double>,
              std::default_delete<drake::systems::DiscreteValues<double>>> (
              ::drake::systems::LeafSystem<double>::*)() const>(
              &::drake::systems::LeafSystem<double>::AllocateDiscreteVariables))
      .def("AllocateForcedDiscreteUpdateEventCollection",
           static_cast<::std::unique_ptr<
               drake::systems::EventCollection<
                   drake::systems::DiscreteUpdateEvent<double>>,
               std::default_delete<drake::systems::EventCollection<
                   drake::systems::DiscreteUpdateEvent<double>>>> (
               ::drake::systems::LeafSystem<double>::*)() const>(
               &::drake::systems::LeafSystem<
                   double>::AllocateForcedDiscreteUpdateEventCollection))
      .def("AllocateForcedPublishEventCollection",
           static_cast<::std::unique_ptr<
               drake::systems::EventCollection<
                   drake::systems::PublishEvent<double>>,
               std::default_delete<drake::systems::EventCollection<
                   drake::systems::PublishEvent<double>>>> (
               ::drake::systems::LeafSystem<double>::*)() const>(
               &::drake::systems::LeafSystem<
                   double>::AllocateForcedPublishEventCollection))
      .def("AllocateForcedUnrestrictedUpdateEventCollection",
           static_cast<::std::unique_ptr<
               drake::systems::EventCollection<
                   drake::systems::UnrestrictedUpdateEvent<double>>,
               std::default_delete<drake::systems::EventCollection<
                   drake::systems::UnrestrictedUpdateEvent<double>>>> (
               ::drake::systems::LeafSystem<double>::*)() const>(
               &::drake::systems::LeafSystem<
                   double>::AllocateForcedUnrestrictedUpdateEventCollection))
      .def(
          "AllocateParameters",
          static_cast<::std::unique_ptr<
              drake::systems::Parameters<double>,
              std::default_delete<drake::systems::Parameters<double>>> (
              ::drake::systems::LeafSystem<double>::*)() const>(
              &LeafSystem_double_publicist::AllocateParameters),
          R"""(/** Returns a copy of the parameters declared in DeclareNumericParameter() 
and DeclareAbstractParameter() calls. */)""")
      .def("AllocateTimeDerivatives",
           static_cast<::std::unique_ptr<
               drake::systems::ContinuousState<double>,
               std::default_delete<drake::systems::ContinuousState<double>>> (
               ::drake::systems::LeafSystem<double>::*)() const>(
               &::drake::systems::LeafSystem<double>::AllocateTimeDerivatives))
      .def(
          "DeclareAbstractInputPort",
          static_cast<::drake::systems::InputPort<double> &(
              ::drake::systems::LeafSystem<double>::
                  *)(::std::variant<
                         std::basic_string<char, std::char_traits<char>,
                                           std::allocator<char>>,
                         drake::systems::UseDefaultName>,
                     ::drake::AbstractValue const &)>(
              &LeafSystem_double_publicist::DeclareAbstractInputPort),
          py::arg("name"), py::arg("model_value"),
          R"""(/** Declares an abstract-valued input port using the given @p model_value. 
This is the best way to declare LeafSystem abstract input ports. 
 
Any port connected to this input, and any call to FixValue for this 
input, must provide for values whose type matches this @p model_value. 
 
@see System::DeclareInputPort() for more information. */)""")
      .def(
          "DeclareAbstractInputPort",
          static_cast<::drake::systems::InputPort<double> &(
              ::drake::systems::LeafSystem<
                  double>::*)(::drake::AbstractValue const &)>(
              &LeafSystem_double_publicist::DeclareAbstractInputPort),
          py::arg("model_value"),
          R"""(/** See the nearly identical signature with an additional (first) argument 
specifying the port name.  This version will be deprecated as discussed 
in #9447. */)""")
      .def(
          "DeclareAbstractOutputPort",
          [](::drake::systems::LeafSystem<double> &self,
             ::std::variant<std::basic_string<char, std::char_traits<char>,
                                              std::allocator<char>>,
                            drake::systems::UseDefaultName>
                 name,
             ::drake::systems::LeafOutputPort<double>::AllocCallback
                 alloc_function,
             ::drake::systems::LeafOutputPort<double>::CalcCallback
                 calc_function,
             ::std::set<
                 drake::TypeSafeIndex<drake::systems::DependencyTag>,
                 std::less<drake::TypeSafeIndex<drake::systems::DependencyTag>>,
                 std::allocator<
                     drake::TypeSafeIndex<drake::systems::DependencyTag>>>
                 prerequisites_of_calc) {
            return self.DeclareAbstractOutputPort(
                name, alloc_function, calc_function, prerequisites_of_calc);
          },
          R"""(/** (Advanced) Declares an abstract-valued output port using the given 
allocator and calculator functions provided in their most generic forms. 
If you have a member function available use one of the other signatures. 
@see LeafOutputPort::AllocCallback, LeafOutputPort::CalcCallback */)""")
      .def(
          "DeclareAbstractOutputPort",
          [](::drake::systems::LeafSystem<double> &self,
             ::drake::systems::LeafOutputPort<double>::AllocCallback
                 alloc_function,
             ::drake::systems::LeafOutputPort<double>::CalcCallback
                 calc_function,
             ::std::set<
                 drake::TypeSafeIndex<drake::systems::DependencyTag>,
                 std::less<drake::TypeSafeIndex<drake::systems::DependencyTag>>,
                 std::allocator<
                     drake::TypeSafeIndex<drake::systems::DependencyTag>>>
                 prerequisites_of_calc) {
            return self.DeclareAbstractOutputPort(alloc_function, calc_function,
                                                  prerequisites_of_calc);
          },
          R"""(/** See the nearly identical signature with an additional (first) argument 
specifying the port name.  This version will be deprecated as discussed 
in #9447. */)""")
      .def(
          "DeclareAbstractParameter",
          static_cast<int (::drake::systems::LeafSystem<double>::*)(
              ::drake::AbstractValue const &)>(
              &LeafSystem_double_publicist::DeclareAbstractParameter),
          py::arg("model_value"),
          R"""(/** Declares an abstract parameter using the given @p model_value. 
LeafSystem's default implementation of SetDefaultParameters() will reset 
parameters to their model values.  Returns the index of the new 
parameter. */)""")
      .def("DeclareAbstractState",
           static_cast<::drake::systems::AbstractStateIndex (
               ::drake::systems::LeafSystem<double>::*)(
               ::drake::AbstractValue const &)>(
               &LeafSystem_double_publicist::DeclareAbstractState),
           py::arg("abstract_state"),
           R"""(/** Declares an abstract state. 
@param abstract_state The abstract state model value. 
@return index of the declared abstract state. */)""")
      .def(
          "DeclareAbstractState",
          [](::drake::systems::LeafSystem<double> &self,
             drake::AbstractValue abstract_state) {
            return self.DeclareAbstractState(
                std::make_unique<drake::AbstractValue>(abstract_state));
          },
          R"""(/** Declares an abstract state. 
@param abstract_state The abstract state model value.  The internal model 
value will contain a copy of `value` (not retain a pointer to `value`). 
@return index of the declared abstract state. */)""")
      .def(
          "DeclareContinuousState",
          static_cast<void (::drake::systems::LeafSystem<double>::*)(int)>(
              &LeafSystem_double_publicist::DeclareContinuousState),
          py::arg("num_state_variables"),
          R"""(/** Declares that this System should reserve continuous state with 
@p num_state_variables state variables, which have no second-order 
structure. */)""")
      .def(
          "DeclareContinuousState",
          static_cast<void (::drake::systems::LeafSystem<double>::*)(int, int,
                                                                     int)>(
              &LeafSystem_double_publicist::DeclareContinuousState),
          py::arg("num_q"), py::arg("num_v"), py::arg("num_z"),
          R"""(/** Declares that this System should reserve continuous state with @p num_q 
generalized positions, @p num_v generalized velocities, and @p num_z 
miscellaneous state variables. */)""")
      .def(
          "DeclareContinuousState",
          static_cast<void (::drake::systems::LeafSystem<double>::*)(
              ::drake::systems::BasicVector<double> const &)>(
              &LeafSystem_double_publicist::DeclareContinuousState),
          py::arg("model_vector"),
          R"""(/** Declares that this System should reserve continuous state with 
@p model_vector.size() miscellaneous state variables, stored in a 
vector cloned from @p model_vector. */)""")
      .def(
          "DeclareContinuousState",
          static_cast<void (::drake::systems::LeafSystem<double>::*)(
              ::drake::systems::BasicVector<double> const &, int, int, int)>(
              &LeafSystem_double_publicist::DeclareContinuousState),
          py::arg("model_vector"), py::arg("num_q"), py::arg("num_v"),
          py::arg("num_z"),
          R"""(/** Declares that this System should reserve continuous state with @p num_q 
generalized positions, @p num_v generalized velocities, and @p num_z 
miscellaneous state variables, stored in a vector cloned from 
@p model_vector. Aborts if @p model_vector has the wrong size. If the 
@p model_vector declares any VectorBase::GetElementBounds() 
constraints, they will be re-declared as inequality constraints on this 
system (see DeclareInequalityConstraint()). */)""")
      .def(
          "DeclareDiscreteState",
          static_cast<::drake::systems::DiscreteStateIndex (
              ::drake::systems::LeafSystem<double>::*)(
              ::drake::systems::BasicVector<double> const &)>(
              &LeafSystem_double_publicist::DeclareDiscreteState),
          py::arg("model_vector"),
          R"""(/** Declares a discrete state group with @p model_vector.size() state 
variables, stored in a vector cloned from @p model_vector (preserving the 
concrete type and value). */)""")
      .def("DeclareDiscreteState",
           [](::drake::systems::LeafSystem<double> &self,
              ::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0,
                           Eigen::InnerStride<1>> const &vector) {
             return self.DeclareDiscreteState(vector);
           })
      .def(
          "DeclareDiscreteState",
          static_cast<::drake::systems::DiscreteStateIndex (
              ::drake::systems::LeafSystem<double>::*)(int)>(
              &LeafSystem_double_publicist::DeclareDiscreteState),
          py::arg("num_state_variables"),
          R"""(/** Declares a discrete state group with @p num_state_variables state 
variables, stored in a BasicVector initialized to be all-zero. If you want 
non-zero initial values, use an alternate DeclareDiscreteState() signature 
that accepts a `model_vector` parameter. 
@pre `num_state_variables` must be non-negative. */)""")
      .def("DeclareEqualityConstraint",
           [](::drake::systems::LeafSystem<double> &self,
              Eigen::Ref<::std::function<void(
                             const drake::systems::Context<double> &,
                             Eigen::Matrix<double, -1, 1, 0, -1, 1> *)>,
                         0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                  calc,
              int count, ::std::string description) {
             return self.DeclareEqualityConstraint(calc, count, description);
           })
      .def("DeclareImplicitTimeDerivativesResidualSize",
           static_cast<void (::drake::systems::LeafSystem<double>::*)(int)>(
               &LeafSystem_double_publicist::
                   DeclareImplicitTimeDerivativesResidualSize),
           py::arg("n"),
           R"""(/** (Advanced) Overrides the default size for the implicit time 
derivatives residual. If no value is set, the default size is 
n=num_continuous_states(). 
 
@param[in] n The size of the residual vector output argument of 
             System::CalcImplicitTimeDerivativesResidual(). If n <= 0 
             restore to the default, num_continuous_states(). 
 
@see implicit_time_derivatives_residual_size() 
@see System::CalcImplicitTimeDerivativesResidual() */)""")
      .def("DeclareInequalityConstraint",
           [](::drake::systems::LeafSystem<double> &self,
              Eigen::Ref<::std::function<void(
                             const drake::systems::Context<double> &,
                             Eigen::Matrix<double, -1, 1, 0, -1, 1> *)>,
                         0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                  calc,
              ::drake::systems::SystemConstraintBounds bounds,
              ::std::string description) {
             return self.DeclareInequalityConstraint(calc, bounds, description);
           })
      .def(
          "DeclareNumericParameter",
          static_cast<int (::drake::systems::LeafSystem<double>::*)(
              ::drake::systems::BasicVector<double> const &)>(
              &LeafSystem_double_publicist::DeclareNumericParameter),
          py::arg("model_vector"),
          R"""(/** Declares a numeric parameter using the given @p model_vector. 
LeafSystem's default implementation of SetDefaultParameters() will reset 
parameters to their model vectors.  If the @p model_vector declares any 
VectorBase::GetElementBounds() constraints, they will be re-declared as 
inequality constraints on this system (see 
DeclareInequalityConstraint()).  Returns the index of the new parameter. */)""")
      .def(
          "DeclarePeriodicDiscreteUpdate",
          static_cast<void (::drake::systems::LeafSystem<double>::*)(double,
                                                                     double)>(
              &LeafSystem_double_publicist::DeclarePeriodicDiscreteUpdate),
          py::arg("period_sec"), py::arg("offset_sec") = double(0),
          R"""(/** (To be deprecated) Declares a periodic discrete update event that invokes 
the DiscreteUpdate() dispatcher but does not provide a handler 
function. This does guarantee that a Simulator step will end exactly at 
the update time, but otherwise has no effect unless the 
DoDiscreteUpdate() dispatcher has been overloaded (not recommended). */)""")
      .def(
          "DeclarePeriodicPublish",
          static_cast<void (::drake::systems::LeafSystem<double>::*)(double,
                                                                     double)>(
              &LeafSystem_double_publicist::DeclarePeriodicPublish),
          py::arg("period_sec"), py::arg("offset_sec") = double(0),
          R"""(/** (To be deprecated) Declares a periodic publish event that invokes the 
Publish() dispatcher but does not provide a handler function. This does 
guarantee that a Simulator step will end exactly at the publish time, 
but otherwise has no effect unless the DoPublish() dispatcher has been 
overloaded (not recommended). */)""")
      .def(
          "DeclarePeriodicUnrestrictedUpdate",
          static_cast<void (::drake::systems::LeafSystem<double>::*)(double,
                                                                     double)>(
              &LeafSystem_double_publicist::DeclarePeriodicUnrestrictedUpdate),
          py::arg("period_sec"), py::arg("offset_sec") = double(0),
          R"""(/** (To be deprecated) Declares a periodic unrestricted update event that 
invokes the UnrestrictedUpdate() dispatcher but does not provide a handler 
function. This does guarantee that a Simulator step will end exactly at 
the update time, but otherwise has no effect unless the 
DoUnrestrictedUpdate() dispatcher has been overloaded (not recommended). */)""")
      .def(
          "DeclareVectorInputPort",
          static_cast<::drake::systems::InputPort<double> &(
              ::drake::systems::LeafSystem<double>::
                  *)(::std::variant<
                         std::basic_string<char, std::char_traits<char>,
                                           std::allocator<char>>,
                         drake::systems::UseDefaultName>,
                     ::drake::systems::BasicVector<double> const &,
                     ::std::optional<drake::RandomDistribution>)>(
              &LeafSystem_double_publicist::DeclareVectorInputPort),
          py::arg("name"), py::arg("model_vector"),
          py::arg("random_type") =
              ::std::optional<drake::RandomDistribution>(std::nullopt),
          R"""(/** Declares a vector-valued input port using the given @p model_vector. 
This is the best way to declare LeafSystem input ports that require 
subclasses of BasicVector.  The port's size and type will be the same as 
model_vector. If the port is intended to model a random noise or 
disturbance input, @p random_type can (optionally) be used to label it 
as such.  If the @p model_vector declares any 
VectorBase::GetElementBounds() constraints, they will be 
re-declared as inequality constraints on this system (see 
DeclareInequalityConstraint()). 
 
@see System::DeclareInputPort() for more information. */)""")
      .def(
          "DeclareVectorInputPort",
          static_cast<::drake::systems::InputPort<double> &(
              ::drake::systems::LeafSystem<
                  double>::*)(::drake::systems::BasicVector<double> const &,
                              ::std::optional<drake::RandomDistribution>)>(
              &LeafSystem_double_publicist::DeclareVectorInputPort),
          py::arg("model_vector"),
          py::arg("random_type") =
              ::std::optional<drake::RandomDistribution>(std::nullopt),
          R"""(/** See the nearly identical signature with an additional (first) argument 
specifying the port name.  This version will be deprecated as discussed 
in #9447. */)""")
      .def(
          "DeclareVectorOutputPort",
          static_cast<::drake::systems::LeafOutputPort<double> &(
              ::drake::systems::LeafSystem<double>::
                  *)(::std::variant<
                         std::basic_string<char, std::char_traits<char>,
                                           std::allocator<char>>,
                         drake::systems::UseDefaultName>,
                     ::drake::systems::BasicVector<double> const &,
                     ::drake::systems::LeafOutputPort<
                         double>::CalcVectorCallback,
                     ::std::set<
                         drake::TypeSafeIndex<drake::systems::DependencyTag>,
                         std::less<drake::TypeSafeIndex<
                             drake::systems::DependencyTag>>,
                         std::allocator<drake::TypeSafeIndex<
                             drake::systems::DependencyTag>>>)>(
              &LeafSystem_double_publicist::DeclareVectorOutputPort),
          py::arg("name"), py::arg("model_vector"),
          py::arg("vector_calc_function"),
          py::arg("prerequisites_of_calc") = ::std::set<
              drake::TypeSafeIndex<drake::systems::DependencyTag>,
              std::less<drake::TypeSafeIndex<drake::systems::DependencyTag>>,
              std::allocator<
                  drake::TypeSafeIndex<drake::systems::DependencyTag>>>(
              {drake::systems::SystemBase::all_sources_ticket()}),
          R"""(/** (Advanced) Declares a vector-valued output port using the given 
`model_vector` and a function for calculating the port's value at runtime. 
The port's size will be model_vector.size(), and the default allocator for 
the port will be model_vector.Clone(). Note that this takes the calculator 
function in its most generic form; if you have a member function available 
use one of the other signatures. 
@see LeafOutputPort::CalcVectorCallback */)""")
      .def(
          "DeclareVectorOutputPort",
          static_cast<::drake::systems::LeafOutputPort<double> &(
              ::drake::systems::LeafSystem<double>::
                  *)(::drake::systems::BasicVector<double> const &,
                     ::drake::systems::LeafOutputPort<
                         double>::CalcVectorCallback,
                     ::std::set<
                         drake::TypeSafeIndex<drake::systems::DependencyTag>,
                         std::less<drake::TypeSafeIndex<
                             drake::systems::DependencyTag>>,
                         std::allocator<drake::TypeSafeIndex<
                             drake::systems::DependencyTag>>>)>(
              &LeafSystem_double_publicist::DeclareVectorOutputPort),
          py::arg("model_vector"), py::arg("vector_calc_function"),
          py::arg("prerequisites_of_calc") = ::std::set<
              drake::TypeSafeIndex<drake::systems::DependencyTag>,
              std::less<drake::TypeSafeIndex<drake::systems::DependencyTag>>,
              std::allocator<
                  drake::TypeSafeIndex<drake::systems::DependencyTag>>>(
              {drake::systems::SystemBase::all_sources_ticket()}),
          R"""(/** See the nearly identical signature with an additional (first) argument 
specifying the port name.  This version will be deprecated as discussed 
in #9447. */)""")
      .def("DoAllocateContext",
           static_cast<::std::unique_ptr<
               drake::systems::ContextBase,
               std::default_delete<drake::systems::ContextBase>> (
               ::drake::systems::LeafSystem<double>::*)() const>(
               &::drake::systems::LeafSystem<double>::DoAllocateContext))
      .def(
          "DoCalcDiscreteVariableUpdates",
          static_cast<void (::drake::systems::LeafSystem<double>::*)(
              ::drake::systems::Context<double> const &,
              ::std::vector<
                  const drake::systems::DiscreteUpdateEvent<double> *,
                  std::allocator<const drake::systems::DiscreteUpdateEvent<
                      double> *>> const &,
              ::drake::systems::DiscreteValues<double> *) const>(
              &LeafSystem_double_publicist::DoCalcDiscreteVariableUpdates),
          py::arg("context"), py::arg("events"), py::arg("discrete_state"),
          R"""(/** Derived-class event dispatcher for all simultaneous discrete update 
events. Override this in your derived LeafSystem only if you require 
behavior other than the default dispatch behavior (not common). 
The default behavior is to traverse events in the arbitrary order they 
appear in @p events, and for each event that has a callback function, 
to invoke the callback with @p context, that event, and @p discrete_state. 
Note that the same (possibly modified) @p discrete_state is passed to 
subsequent callbacks. 
 
Do not override this just to handle an event -- instead declare the event 
and a handler callback for it using one of the 
`Declare...DiscreteUpdateEvent()` methods. 
 
This method is called only from the virtual 
DispatchDiscreteVariableUpdateHandler(), which is only called from 
the public non-virtual CalcDiscreteVariableUpdates(), which will already 
have error-checked the parameters so you don't have to. In particular, 
implementations may assume that @p context is valid; that 
@p discrete_state is non-null, and that the referenced object has the 
same constituent structure as was produced by AllocateDiscreteVariables(). 
 
@param[in] context The "before" state. 
@param[in] events All the discrete update events that need handling. 
@param[in,out] discrete_state The current state of the system on input; 
the desired state of the system on return. */)""")
      .def(
          "DoCalcNextUpdateTime",
          static_cast<void (::drake::systems::LeafSystem<double>::*)(
              ::drake::systems::Context<double> const &,
              ::drake::systems::CompositeEventCollection<double> *, double *)
                          const>(
              &LeafSystem_double_publicist::DoCalcNextUpdateTime),
          py::arg("context"), py::arg("events"), py::arg("time"),
          R"""(/** Computes the next update time based on the configured periodic events, for 
scalar types that are arithmetic, or aborts for scalar types that are not 
arithmetic. Subclasses that require aperiodic events should override, but 
be sure to invoke the parent class implementation at the start of the 
override if you want periodic events to continue to be handled. 
 
@post `time` is set to a value greater than or equal to 
      `context.get_time()` on return. 
@warning If you override this method, think carefully before setting 
         `time` to `context.get_time()` on return, which can inadvertently 
         cause simulations of systems derived from %LeafSystem to loop 
         interminably. Such a loop will occur if, for example, the 
         event(s) does not modify the state. */)""")
      .def(
          "DoCalcUnrestrictedUpdate",
          static_cast<void (::drake::systems::LeafSystem<double>::*)(
              ::drake::systems::Context<double> const &,
              ::std::vector<
                  const drake::systems::UnrestrictedUpdateEvent<double> *,
                  std::allocator<const drake::systems::UnrestrictedUpdateEvent<
                      double> *>> const &,
              ::drake::systems::State<double> *) const>(
              &LeafSystem_double_publicist::DoCalcUnrestrictedUpdate),
          py::arg("context"), py::arg("events"), py::arg("state"),
          R"""(/** Derived-class event dispatcher for all simultaneous unrestricted update 
events. Override this in your derived LeafSystem only if you require 
behavior other than the default dispatch behavior (not common). 
The default behavior is to traverse events in the arbitrary order they 
appear in @p events, and for each event that has a callback function, 
to invoke the callback with @p context, that event, and @p state. 
Note that the same (possibly modified) @p state is passed to subsequent 
callbacks. 
 
Do not override this just to handle an event -- instead declare the event 
and a handler callback for it using one of the 
`Declare...UnrestrictedUpdateEvent()` methods. 
 
This method is called only from the virtual 
DispatchUnrestrictedUpdateHandler(), which is only called from the 
non-virtual public CalcUnrestrictedUpdate(), which will already have 
error-checked the parameters so you don't have to. In particular, 
implementations may assume that the @p context is valid; that @p state 
is non-null, and that the referenced object has the same constituent 
structure as the state in @p context. 
 
@param[in]     context The "before" state that is to be used to calculate 
                       the returned state update. 
@param[in]     events All the unrestricted update events that need 
                      handling. 
@param[in,out] state   The current state of the system on input; the 
                       desired state of the system on return. */)""")
      .def("DoCalcWitnessValue",
           static_cast<double (::drake::systems::LeafSystem<double>::*)(
               ::drake::systems::Context<double> const &,
               ::drake::systems::WitnessFunction<double> const &) const>(
               &LeafSystem_double_publicist::DoCalcWitnessValue),
           py::arg("context"), py::arg("witness_func"))
      .def(
          "DoMakeLeafContext",
          static_cast<::std::unique_ptr<
              drake::systems::LeafContext<double>,
              std::default_delete<drake::systems::LeafContext<double>>> (
              ::drake::systems::LeafSystem<double>::*)() const>(
              &LeafSystem_double_publicist::DoMakeLeafContext),
          R"""(/** Provides a new instance of the leaf context for this system. Derived 
leaf systems with custom derived leaf system contexts should override this 
to provide a context of the appropriate type. The returned context should 
be "empty"; invoked by AllocateContext(), the caller will take the 
responsibility to initialize the core LeafContext data. The default 
implementation provides a default-constructed `LeafContext<T>`. */)""")
      .def(
          "DoPublish",
          static_cast<void (::drake::systems::LeafSystem<double>::*)(
              ::drake::systems::Context<double> const &,
              ::std::vector<const drake::systems::PublishEvent<double> *,
                            std::allocator<const drake::systems::PublishEvent<
                                double> *>> const &) const>(
              &LeafSystem_double_publicist::DoPublish),
          py::arg("context"), py::arg("events"),
          R"""(/** Derived-class event dispatcher for all simultaneous publish events 
in @p events. Override this in your derived LeafSystem only if you require 
behavior other than the default dispatch behavior (not common). 
The default behavior is to traverse events in the arbitrary order they 
appear in @p events, and for each event that has a callback function, 
to invoke the callback with @p context and that event. 
 
Do not override this just to handle an event -- instead declare the event 
and a handler callback for it using one of the `Declare...PublishEvent()` 
methods. 
 
This method is called only from the virtual DispatchPublishHandler, which 
is only called from the public non-virtual Publish(), which will have 
already error-checked @p context so you may assume that it is valid. 
 
@param[in] context Const current context. 
@param[in] events All the publish events that need handling. */)""")
      .def(
          "DoValidateAllocatedLeafContext",
          static_cast<void (::drake::systems::LeafSystem<double>::*)(
              ::drake::systems::LeafContext<double> const &) const>(
              &LeafSystem_double_publicist::DoValidateAllocatedLeafContext),
          py::arg("context"),
          R"""(/** Derived classes that impose restrictions on what resources are permitted 
should check those restrictions by implementing this. For example, a 
derived class might require a single input and single output. Note that 
the supplied Context will be complete except that input and output 
dependencies on peer and parent subcontexts will not yet have been set up, 
so you may not consider them for validation. 
The default implementation does nothing. */)""")
      .def("GetDirectFeedthroughs",
           static_cast<
               ::std::multimap<int, int, std::less<int>,
                               std::allocator<std::pair<const int, int>>> (
                   ::drake::systems::LeafSystem<double>::*)() const>(
               &::drake::systems::LeafSystem<double>::GetDirectFeedthroughs))
      .def(
          "GetGraphvizFragment",
          static_cast<void (::drake::systems::LeafSystem<double>::*)(
              int, ::std::stringstream *) const>(
              &LeafSystem_double_publicist::GetGraphvizFragment),
          py::arg("max_depth"), py::arg("dot"),
          R"""(/** Emits a graphviz fragment for this System. Leaf systems are visualized as 
records. For instance, a leaf system with 2 inputs and 1 output is: 
 
@verbatim 
123456 [shape= record, label="name | {<u0> 0 |<y0> 0} | {<u1> 1 | }"]; 
@endverbatim 
 
which looks like: 
 
@verbatim 
+------------+----+ 
| name  | u0 | u1 | 
|       | y0 |    | 
+-------+----+----+ 
@endverbatim */)""")
      .def("GetGraphvizInputPortToken",
           static_cast<void (::drake::systems::LeafSystem<double>::*)(
               ::drake::systems::InputPort<double> const &, int,
               ::std::stringstream *) const>(
               &LeafSystem_double_publicist::GetGraphvizInputPortToken),
           py::arg("port"), py::arg("max_depth"), py::arg("dot"))
      .def("GetGraphvizOutputPortToken",
           static_cast<void (::drake::systems::LeafSystem<double>::*)(
               ::drake::systems::OutputPort<double> const &, int,
               ::std::stringstream *) const>(
               &LeafSystem_double_publicist::GetGraphvizOutputPortToken),
           py::arg("port"), py::arg("max_depth"), py::arg("dot"))
      .def(
          "MakeWitnessFunction",
          static_cast<::std::unique_ptr<
              drake::systems::WitnessFunction<double>,
              std::default_delete<drake::systems::WitnessFunction<double>>> (
              ::drake::systems::LeafSystem<double>::*)(
              ::std::string const &,
              ::drake::systems::WitnessFunctionDirection const &,
              ::std::function<double(const drake::systems::Context<double> &)>)
                          const>(
              &LeafSystem_double_publicist::MakeWitnessFunction),
          py::arg("description"), py::arg("direction_type"), py::arg("calc"),
          R"""(/** Constructs the witness function with the given description (used primarily 
for debugging and logging), direction type, and calculator function; and 
with no event object. 
 
@note In order for the witness function to be used, you MUST 
overload System::DoGetWitnessFunctions(). */)""")
      .def(
          "MakeWitnessFunction",
          static_cast<::std::unique_ptr<
              drake::systems::WitnessFunction<double>,
              std::default_delete<drake::systems::WitnessFunction<double>>> (
              ::drake::systems::LeafSystem<double>::*)(
              ::std::string const &,
              ::drake::systems::WitnessFunctionDirection const &,
              ::std::function<double(const drake::systems::Context<double> &)>,
              ::drake::systems::Event<double> const &) const>(
              &LeafSystem_double_publicist::MakeWitnessFunction),
          py::arg("description"), py::arg("direction_type"), py::arg("calc"),
          py::arg("e"),
          R"""(/** Constructs the witness function with the given description (used primarily 
for debugging and logging), direction type, and calculator 
function, and with an object corresponding to the event that is to be 
dispatched when this witness function triggers. Example types of event 
objects are publish, discrete variable update, unrestricted update events. 
A clone of the event will be owned by the newly constructed 
WitnessFunction. 
 
@note In order for the witness function to be used, you MUST 
overload System::DoGetWitnessFunctions(). */)""")
      .def(
          "SetDefaultParameters",
          static_cast<void (::drake::systems::LeafSystem<double>::*)(
              ::drake::systems::Context<double> const &,
              ::drake::systems::Parameters<double> *) const>(
              &::drake::systems::LeafSystem<double>::SetDefaultParameters),
          py::arg("context"), py::arg("parameters"),
          R"""(/** Default implementation: sets all numeric parameters to the model vector 
given to DeclareNumericParameter, or else if no model was provided sets 
the numeric parameter to one.  It sets all abstract parameters to the 
model value given to DeclareAbstractParameter.  Overrides must not change 
the number of parameters. */)""")
      .def(
          "SetDefaultState",
          static_cast<void (::drake::systems::LeafSystem<double>::*)(
              ::drake::systems::Context<double> const &,
              ::drake::systems::State<double> *) const>(
              &::drake::systems::LeafSystem<double>::SetDefaultState),
          py::arg("context"), py::arg("state"),
          R"""(/** Default implementation: sets all continuous state to the model vector 
given in DeclareContinuousState (or zero if no model vector was given) and 
discrete states to zero. Overrides must not change the number of state 
variables. */)""")

      ;

  py::class_<::drake::systems::LeafSystem<float>> LeafSystem_float(
      m, "LeafSystem_float");

  LeafSystem_float
      .def("AddTriggeredWitnessFunctionToCompositeEventCollection",
           static_cast<void (::drake::systems::LeafSystem<float>::*)(
               ::drake::systems::Event<float> *,
               ::drake::systems::CompositeEventCollection<float> *) const>(
               &LeafSystem_float_publicist::
                   AddTriggeredWitnessFunctionToCompositeEventCollection),
           py::arg("event"), py::arg("events"))
      .def("AllocateAbstractState",
           static_cast<::std::unique_ptr<
               drake::systems::AbstractValues,
               std::default_delete<drake::systems::AbstractValues>> (
               ::drake::systems::LeafSystem<float>::*)() const>(
               &LeafSystem_float_publicist::AllocateAbstractState))
      .def("AllocateCompositeEventCollection",
           static_cast<::std::unique_ptr<
               drake::systems::CompositeEventCollection<float>,
               std::default_delete<drake::systems::CompositeEventCollection<
                   float>>> (::drake::systems::LeafSystem<float>::*)() const>(
               &::drake::systems::LeafSystem<
                   float>::AllocateCompositeEventCollection))
      .def("AllocateContext",
           static_cast<::std::unique_ptr<
               drake::systems::LeafContext<float>,
               std::default_delete<drake::systems::LeafContext<float>>> (
               ::drake::systems::LeafSystem<float>::*)() const>(
               &::drake::systems::LeafSystem<float>::AllocateContext))
      .def("AllocateContinuousState",
           static_cast<::std::unique_ptr<
               drake::systems::ContinuousState<float>,
               std::default_delete<drake::systems::ContinuousState<float>>> (
               ::drake::systems::LeafSystem<float>::*)() const>(
               &LeafSystem_float_publicist::AllocateContinuousState))
      .def("AllocateDiscreteState",
           static_cast<::std::unique_ptr<
               drake::systems::DiscreteValues<float>,
               std::default_delete<drake::systems::DiscreteValues<float>>> (
               ::drake::systems::LeafSystem<float>::*)() const>(
               &LeafSystem_float_publicist::AllocateDiscreteState))
      .def("AllocateDiscreteVariables",
           static_cast<::std::unique_ptr<
               drake::systems::DiscreteValues<float>,
               std::default_delete<drake::systems::DiscreteValues<float>>> (
               ::drake::systems::LeafSystem<float>::*)() const>(
               &::drake::systems::LeafSystem<float>::AllocateDiscreteVariables))
      .def("AllocateForcedDiscreteUpdateEventCollection",
           static_cast<::std::unique_ptr<
               drake::systems::EventCollection<
                   drake::systems::DiscreteUpdateEvent<float>>,
               std::default_delete<drake::systems::EventCollection<
                   drake::systems::DiscreteUpdateEvent<float>>>> (
               ::drake::systems::LeafSystem<float>::*)() const>(
               &::drake::systems::LeafSystem<
                   float>::AllocateForcedDiscreteUpdateEventCollection))
      .def("AllocateForcedPublishEventCollection",
           static_cast<::std::unique_ptr<
               drake::systems::EventCollection<
                   drake::systems::PublishEvent<float>>,
               std::default_delete<drake::systems::EventCollection<
                   drake::systems::PublishEvent<float>>>> (
               ::drake::systems::LeafSystem<float>::*)() const>(
               &::drake::systems::LeafSystem<
                   float>::AllocateForcedPublishEventCollection))
      .def("AllocateForcedUnrestrictedUpdateEventCollection",
           static_cast<::std::unique_ptr<
               drake::systems::EventCollection<
                   drake::systems::UnrestrictedUpdateEvent<float>>,
               std::default_delete<drake::systems::EventCollection<
                   drake::systems::UnrestrictedUpdateEvent<float>>>> (
               ::drake::systems::LeafSystem<float>::*)() const>(
               &::drake::systems::LeafSystem<
                   float>::AllocateForcedUnrestrictedUpdateEventCollection))
      .def("AllocateParameters",
           static_cast<::std::unique_ptr<
               drake::systems::Parameters<float>,
               std::default_delete<drake::systems::Parameters<float>>> (
               ::drake::systems::LeafSystem<float>::*)() const>(
               &LeafSystem_float_publicist::AllocateParameters))
      .def("AllocateTimeDerivatives",
           static_cast<::std::unique_ptr<
               drake::systems::ContinuousState<float>,
               std::default_delete<drake::systems::ContinuousState<float>>> (
               ::drake::systems::LeafSystem<float>::*)() const>(
               &::drake::systems::LeafSystem<float>::AllocateTimeDerivatives))
      .def(
          "DeclareAbstractOutputPort",
          [](::drake::systems::LeafSystem<float> &self,
             ::std::variant<std::basic_string<char, std::char_traits<char>,
                                              std::allocator<char>>,
                            drake::systems::UseDefaultName>
                 name,
             ::drake::systems::LeafOutputPort<float>::AllocCallback
                 alloc_function,
             ::drake::systems::LeafOutputPort<float>::CalcCallback
                 calc_function,
             ::std::set<
                 drake::TypeSafeIndex<drake::systems::DependencyTag>,
                 std::less<drake::TypeSafeIndex<drake::systems::DependencyTag>>,
                 std::allocator<
                     drake::TypeSafeIndex<drake::systems::DependencyTag>>>
                 prerequisites_of_calc) {
            return self.DeclareAbstractOutputPort(
                name, alloc_function, calc_function, prerequisites_of_calc);
          })
      .def(
          "DeclareAbstractOutputPort",
          [](::drake::systems::LeafSystem<float> &self,
             ::drake::systems::LeafOutputPort<float>::AllocCallback
                 alloc_function,
             ::drake::systems::LeafOutputPort<float>::CalcCallback
                 calc_function,
             ::std::set<
                 drake::TypeSafeIndex<drake::systems::DependencyTag>,
                 std::less<drake::TypeSafeIndex<drake::systems::DependencyTag>>,
                 std::allocator<
                     drake::TypeSafeIndex<drake::systems::DependencyTag>>>
                 prerequisites_of_calc) {
            return self.DeclareAbstractOutputPort(alloc_function, calc_function,
                                                  prerequisites_of_calc);
          })
      .def("DeclareAbstractParameter",
           static_cast<int (::drake::systems::LeafSystem<float>::*)(
               ::drake::AbstractValue const &)>(
               &LeafSystem_float_publicist::DeclareAbstractParameter),
           py::arg("model_value"))
      .def("DeclareAbstractState",
           static_cast<::drake::systems::AbstractStateIndex (
               ::drake::systems::LeafSystem<float>::*)(
               ::drake::AbstractValue const &)>(
               &LeafSystem_float_publicist::DeclareAbstractState),
           py::arg("abstract_state"))
      .def("DeclareAbstractState",
           [](::drake::systems::LeafSystem<float> &self,
              drake::AbstractValue abstract_state) {
             return self.DeclareAbstractState(
                 std::make_unique<drake::AbstractValue>(abstract_state));
           })
      .def("DeclareContinuousState",
           static_cast<void (::drake::systems::LeafSystem<float>::*)(int)>(
               &LeafSystem_float_publicist::DeclareContinuousState),
           py::arg("num_state_variables"))
      .def("DeclareContinuousState",
           static_cast<void (::drake::systems::LeafSystem<float>::*)(int, int,
                                                                     int)>(
               &LeafSystem_float_publicist::DeclareContinuousState),
           py::arg("num_q"), py::arg("num_v"), py::arg("num_z"))
      .def("DeclareContinuousState",
           static_cast<void (::drake::systems::LeafSystem<float>::*)(
               ::drake::systems::BasicVector<float> const &)>(
               &LeafSystem_float_publicist::DeclareContinuousState),
           py::arg("model_vector"))
      .def("DeclareContinuousState",
           static_cast<void (::drake::systems::LeafSystem<float>::*)(
               ::drake::systems::BasicVector<float> const &, int, int, int)>(
               &LeafSystem_float_publicist::DeclareContinuousState),
           py::arg("model_vector"), py::arg("num_q"), py::arg("num_v"),
           py::arg("num_z"))
      .def("DeclareDiscreteState",
           static_cast<::drake::systems::DiscreteStateIndex (
               ::drake::systems::LeafSystem<float>::*)(
               ::drake::systems::BasicVector<float> const &)>(
               &LeafSystem_float_publicist::DeclareDiscreteState),
           py::arg("model_vector"))
      .def("DeclareDiscreteState",
           [](::drake::systems::LeafSystem<float> &self,
              ::Eigen::Ref<const Eigen::Matrix<float, -1, 1, 0, -1, 1>, 0,
                           Eigen::InnerStride<1>> const &vector) {
             return self.DeclareDiscreteState(vector);
           })
      .def("DeclareDiscreteState",
           static_cast<::drake::systems::DiscreteStateIndex (
               ::drake::systems::LeafSystem<float>::*)(int)>(
               &LeafSystem_float_publicist::DeclareDiscreteState),
           py::arg("num_state_variables"))
      .def(
          "DeclareEqualityConstraint",
          [](::drake::systems::LeafSystem<float> &self,
             Eigen::Ref<
                 ::std::function<void(const drake::systems::Context<float> &,
                                      Eigen::Matrix<float, -1, 1, 0, -1, 1> *)>,
                 0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                 calc,
             int count, ::std::string description) {
            return self.DeclareEqualityConstraint(calc, count, description);
          })
      .def("DeclareImplicitTimeDerivativesResidualSize",
           static_cast<void (::drake::systems::LeafSystem<float>::*)(int)>(
               &LeafSystem_float_publicist::
                   DeclareImplicitTimeDerivativesResidualSize),
           py::arg("n"),
           R"""(/** (Advanced) Overrides the default size for the implicit time 
derivatives residual. If no value is set, the default size is 
n=num_continuous_states(). 
 
@param[in] n The size of the residual vector output argument of 
             System::CalcImplicitTimeDerivativesResidual(). If n <= 0 
             restore to the default, num_continuous_states(). 
 
@see implicit_time_derivatives_residual_size() 
@see System::CalcImplicitTimeDerivativesResidual() */)""")
      .def(
          "DeclareInequalityConstraint",
          [](::drake::systems::LeafSystem<float> &self,
             Eigen::Ref<
                 ::std::function<void(const drake::systems::Context<float> &,
                                      Eigen::Matrix<float, -1, 1, 0, -1, 1> *)>,
                 0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                 calc,
             ::drake::systems::SystemConstraintBounds bounds,
             ::std::string description) {
            return self.DeclareInequalityConstraint(calc, bounds, description);
          })
      .def("DeclareNumericParameter",
           static_cast<int (::drake::systems::LeafSystem<float>::*)(
               ::drake::systems::BasicVector<float> const &)>(
               &LeafSystem_float_publicist::DeclareNumericParameter),
           py::arg("model_vector"))
      .def("DeclarePeriodicDiscreteUpdate",
           static_cast<void (::drake::systems::LeafSystem<float>::*)(double,
                                                                     double)>(
               &LeafSystem_float_publicist::DeclarePeriodicDiscreteUpdate),
           py::arg("period_sec"), py::arg("offset_sec") = double(0))
      .def("DeclarePeriodicPublish",
           static_cast<void (::drake::systems::LeafSystem<float>::*)(double,
                                                                     double)>(
               &LeafSystem_float_publicist::DeclarePeriodicPublish),
           py::arg("period_sec"), py::arg("offset_sec") = double(0))
      .def("DeclarePeriodicUnrestrictedUpdate",
           static_cast<void (::drake::systems::LeafSystem<float>::*)(double,
                                                                     double)>(
               &LeafSystem_float_publicist::DeclarePeriodicUnrestrictedUpdate),
           py::arg("period_sec"), py::arg("offset_sec") = double(0))
      .def("DeclareVectorOutputPort",
           static_cast<::drake::systems::LeafOutputPort<float> &(
               ::drake::systems::LeafSystem<float>::
                   *)(::std::variant<
                          std::basic_string<char, std::char_traits<char>,
                                            std::allocator<char>>,
                          drake::systems::UseDefaultName>,
                      ::drake::systems::BasicVector<float> const &,
                      ::drake::systems::LeafOutputPort<
                          float>::CalcVectorCallback,
                      ::std::set<
                          drake::TypeSafeIndex<drake::systems::DependencyTag>,
                          std::less<drake::TypeSafeIndex<
                              drake::systems::DependencyTag>>,
                          std::allocator<drake::TypeSafeIndex<
                              drake::systems::DependencyTag>>>)>(
               &LeafSystem_float_publicist::DeclareVectorOutputPort),
           py::arg("name"), py::arg("model_vector"),
           py::arg("vector_calc_function"),
           py::arg("prerequisites_of_calc") = ::std::set<
               drake::TypeSafeIndex<drake::systems::DependencyTag>,
               std::less<drake::TypeSafeIndex<drake::systems::DependencyTag>>,
               std::allocator<
                   drake::TypeSafeIndex<drake::systems::DependencyTag>>>(
               {drake::systems::SystemBase::all_sources_ticket()}))
      .def("DeclareVectorOutputPort",
           static_cast<::drake::systems::LeafOutputPort<float> &(
               ::drake::systems::LeafSystem<float>::
                   *)(::drake::systems::BasicVector<float> const &,
                      ::drake::systems::LeafOutputPort<
                          float>::CalcVectorCallback,
                      ::std::set<
                          drake::TypeSafeIndex<drake::systems::DependencyTag>,
                          std::less<drake::TypeSafeIndex<
                              drake::systems::DependencyTag>>,
                          std::allocator<drake::TypeSafeIndex<
                              drake::systems::DependencyTag>>>)>(
               &LeafSystem_float_publicist::DeclareVectorOutputPort),
           py::arg("model_vector"), py::arg("vector_calc_function"),
           py::arg("prerequisites_of_calc") = ::std::set<
               drake::TypeSafeIndex<drake::systems::DependencyTag>,
               std::less<drake::TypeSafeIndex<drake::systems::DependencyTag>>,
               std::allocator<
                   drake::TypeSafeIndex<drake::systems::DependencyTag>>>(
               {drake::systems::SystemBase::all_sources_ticket()}))
      .def("DoAllocateContext",
           static_cast<::std::unique_ptr<
               drake::systems::ContextBase,
               std::default_delete<drake::systems::ContextBase>> (
               ::drake::systems::LeafSystem<float>::*)() const>(
               &::drake::systems::LeafSystem<float>::DoAllocateContext))
      .def("DoCalcDiscreteVariableUpdates",
           static_cast<void (::drake::systems::LeafSystem<float>::*)(
               ::drake::systems::Context<float> const &,
               ::std::vector<
                   const drake::systems::DiscreteUpdateEvent<float> *,
                   std::allocator<const drake::systems::DiscreteUpdateEvent<
                       float> *>> const &,
               ::drake::systems::DiscreteValues<float> *) const>(
               &LeafSystem_float_publicist::DoCalcDiscreteVariableUpdates),
           py::arg("context"), py::arg("events"), py::arg("discrete_state"))
      .def("DoCalcNextUpdateTime",
           static_cast<void (::drake::systems::LeafSystem<float>::*)(
               ::drake::systems::Context<float> const &,
               ::drake::systems::CompositeEventCollection<float> *, float *)
                           const>(
               &LeafSystem_float_publicist::DoCalcNextUpdateTime),
           py::arg("context"), py::arg("events"), py::arg("time"))
      .def("DoCalcUnrestrictedUpdate",
           static_cast<void (::drake::systems::LeafSystem<float>::*)(
               ::drake::systems::Context<float> const &,
               ::std::vector<
                   const drake::systems::UnrestrictedUpdateEvent<float> *,
                   std::allocator<const drake::systems::UnrestrictedUpdateEvent<
                       float> *>> const &,
               ::drake::systems::State<float> *) const>(
               &LeafSystem_float_publicist::DoCalcUnrestrictedUpdate),
           py::arg("context"), py::arg("events"), py::arg("state"))
      .def("DoMakeLeafContext",
           static_cast<::std::unique_ptr<
               drake::systems::LeafContext<float>,
               std::default_delete<drake::systems::LeafContext<float>>> (
               ::drake::systems::LeafSystem<float>::*)() const>(
               &LeafSystem_float_publicist::DoMakeLeafContext))
      .def("DoPublish",
           static_cast<void (::drake::systems::LeafSystem<float>::*)(
               ::drake::systems::Context<float> const &,
               ::std::vector<const drake::systems::PublishEvent<float> *,
                             std::allocator<const drake::systems::PublishEvent<
                                 float> *>> const &) const>(
               &LeafSystem_float_publicist::DoPublish),
           py::arg("context"), py::arg("events"))
      .def(
          "DoValidateAllocatedLeafContext",
          static_cast<void (::drake::systems::LeafSystem<float>::*)(
              ::drake::systems::LeafContext<float> const &) const>(
              &LeafSystem_float_publicist::DoValidateAllocatedLeafContext),
          py::arg("context"),
          R"""(/** Derived classes that impose restrictions on what resources are permitted 
should check those restrictions by implementing this. For example, a 
derived class might require a single input and single output. Note that 
the supplied Context will be complete except that input and output 
dependencies on peer and parent subcontexts will not yet have been set up, 
so you may not consider them for validation. 
The default implementation does nothing. */)""")
      .def("GetDirectFeedthroughs",
           static_cast<
               ::std::multimap<int, int, std::less<int>,
                               std::allocator<std::pair<const int, int>>> (
                   ::drake::systems::LeafSystem<float>::*)() const>(
               &::drake::systems::LeafSystem<float>::GetDirectFeedthroughs))
      .def("GetGraphvizFragment",
           static_cast<void (::drake::systems::LeafSystem<float>::*)(
               int, ::std::stringstream *) const>(
               &LeafSystem_float_publicist::GetGraphvizFragment),
           py::arg("max_depth"), py::arg("dot"))
      .def("GetGraphvizOutputPortToken",
           static_cast<void (::drake::systems::LeafSystem<float>::*)(
               ::drake::systems::OutputPort<float> const &, int,
               ::std::stringstream *) const>(
               &LeafSystem_float_publicist::GetGraphvizOutputPortToken),
           py::arg("port"), py::arg("max_depth"), py::arg("dot"))
      .def("MakeWitnessFunction",
           static_cast<::std::unique_ptr<
               drake::systems::WitnessFunction<float>,
               std::default_delete<drake::systems::WitnessFunction<float>>> (
               ::drake::systems::LeafSystem<float>::*)(
               ::std::string const &,
               ::drake::systems::WitnessFunctionDirection const &,
               ::std::function<float(const drake::systems::Context<float> &)>)
                           const>(
               &LeafSystem_float_publicist::MakeWitnessFunction),
           py::arg("description"), py::arg("direction_type"), py::arg("calc"))
      .def("MakeWitnessFunction",
           static_cast<::std::unique_ptr<
               drake::systems::WitnessFunction<float>,
               std::default_delete<drake::systems::WitnessFunction<float>>> (
               ::drake::systems::LeafSystem<float>::*)(
               ::std::string const &,
               ::drake::systems::WitnessFunctionDirection const &,
               ::std::function<float(const drake::systems::Context<float> &)>,
               ::drake::systems::Event<float> const &) const>(
               &LeafSystem_float_publicist::MakeWitnessFunction),
           py::arg("description"), py::arg("direction_type"), py::arg("calc"),
           py::arg("e"))
      .def("SetDefaultParameters",
           static_cast<void (::drake::systems::LeafSystem<float>::*)(
               ::drake::systems::Context<float> const &,
               ::drake::systems::Parameters<float> *) const>(
               &::drake::systems::LeafSystem<float>::SetDefaultParameters),
           py::arg("context"), py::arg("parameters"))
      .def("SetDefaultState",
           static_cast<void (::drake::systems::LeafSystem<float>::*)(
               ::drake::systems::Context<float> const &,
               ::drake::systems::State<float> *) const>(
               &::drake::systems::LeafSystem<float>::SetDefaultState),
           py::arg("context"), py::arg("state"))

      ;
}
