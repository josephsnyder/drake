#include "drake/systems/framework/system_base.h"
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

class SystemBase_publicist : public ::drake::systems::SystemBase {
public:
  using ::drake::systems::SystemBase::AddAbstractParameter;
  using ::drake::systems::SystemBase::AddAbstractState;
  using ::drake::systems::SystemBase::AddDiscreteStateGroup;
  using ::drake::systems::SystemBase::AddInputPort;
  using ::drake::systems::SystemBase::AddNumericParameter;
  using ::drake::systems::SystemBase::AddOutputPort;
  using ::drake::systems::SystemBase::assign_next_dependency_ticket;
  using ::drake::systems::SystemBase::ContextSizes;
  using ::drake::systems::SystemBase::DeclareCacheEntryWithKnownTicket;
  using ::drake::systems::SystemBase::DoAllocateContext;
  using ::drake::systems::SystemBase::EvalAbstractInputImpl;
  using ::drake::systems::SystemBase::get_parent_service;
  using ::drake::systems::SystemBase::get_system_id;
  using ::drake::systems::SystemBase::GetInputPortBaseOrThrow;
  using ::drake::systems::SystemBase::GetOutputPortBaseOrThrow;
  using ::drake::systems::SystemBase::InitializeContextBase;
  using ::drake::systems::SystemBase::MakeFixInputPortTypeChecker;
  using ::drake::systems::SystemBase::NextInputPortName;
  using ::drake::systems::SystemBase::NextOutputPortName;
  using ::drake::systems::SystemBase::
      set_implicit_time_derivatives_residual_size;
  using ::drake::systems::SystemBase::set_parent_service;
  using ::drake::systems::SystemBase::ThrowCantEvaluateInputPort;
  using ::drake::systems::SystemBase::ThrowInputPortHasWrongType;
  using ::drake::systems::SystemBase::ThrowInputPortIndexOutOfRange;
  using ::drake::systems::SystemBase::ThrowNegativePortIndex;
  using ::drake::systems::SystemBase::ThrowNotAVectorInputPort;
  using ::drake::systems::SystemBase::ThrowOutputPortIndexOutOfRange;
};

namespace py = pybind11;
void apb11_pydrake_SystemBase_py_register(py::module &m) {
  static bool called = false;
  if (called) {
    return;
  }
  called = true;
  py::class_<::drake::systems::SystemBase,
             ::drake::systems::internal::SystemMessageInterface>
      SystemBase(
          m, "SystemBase",
          "/** Provides non-templatized functionality shared by the templatized System \
classes. \
 \
Terminology: in general a Drake System is a tree structure composed of \
" subsystems
          ", which are themselves System objects. The corresponding Context is \
a parallel tree structure composed of " subcontexts ", which are themselves \
Context objects. There is a one-to-one correspondence between subsystems and \
subcontexts. Within a given System (Context), its child subsystems (subcontexts) \
are indexed using a SubsystemIndex; there is no separate SubcontextIndex since \
the numbering must be identical. */");

  SystemBase
      .def(
          "set_name",
          static_cast<void (::drake::systems::SystemBase::*)(
              ::std::string const &)>(&::drake::systems::SystemBase::set_name),
          py::arg("name"),
          "/** Sets the name of the system. Do not use the path delimiter character ':' \
in the name. When creating a Diagram, names of sibling subsystems should be \
unique. DiagramBuilder uses this method to assign a unique default name if \
none is provided. */")
      .def(
          "get_name",
          static_cast<::std::string const &(::drake::systems::SystemBase::*)()
                          const>(&::drake::systems::SystemBase::get_name),
          "/** Returns the name last supplied to set_name(), if any. Diagrams built with \
DiagramBuilder will always have a default name for every contained subsystem \
for which no user-provided name is available. Systems created by copying with \
a scalar type change have the same name as the source system. An empty string \
is returned if no name has been set. */")
      .def(
          "GetSystemName",
          static_cast<::std::string const &(::drake::systems::SystemBase::*)()
                          const>(&::drake::systems::SystemBase::GetSystemName),
          "/** Returns a human-readable name for this system, for use in messages and \
logging. This will be the same as returned by get_name(), unless that would \
be an empty string. In that case we return a non-unique placeholder name, \
currently just "_
          " (a lone underscore). */")
      .def(
          "GetSystemPathname",
          static_cast<::std::string (::drake::systems::SystemBase::*)() const>(
              &::drake::systems::SystemBase::GetSystemPathname),
          "/** Generates and returns a human-readable full path name of this subsystem, \
for use in messages and logging. The name starts from the root System, with \
" ::" delimiters between parent and child subsystems, with the individual \
subsystems represented by their names as returned by GetSystemName(). */")
      .def(
          "GetSystemType",
          static_cast<::std::string (::drake::systems::SystemBase::*)() const>(
              &::drake::systems::SystemBase::GetSystemType),
          "/** Returns the most-derived type of this concrete System object as a \
human-readable string suitable for use in error messages. The format is as \
generated by NiceTypeName and will include namespace qualification if \
present. \
@see NiceTypeName for more specifics. */")
      .def(
          "AllocateContext",
          static_cast<::std::unique_ptr<
              drake::systems::ContextBase,
              std::default_delete<drake::systems::ContextBase>> (
              ::drake::systems::SystemBase::*)() const>(
              &::drake::systems::SystemBase::AllocateContext),
          "/** Returns a Context suitable for use with this System. Context resources \
are allocated based on resource requests that were made during System \
construction. */")
      .def(
          "EvalAbstractInput",
          static_cast<::drake::AbstractValue const *(
              ::drake::systems::SystemBase::
                  *)(::drake::systems::ContextBase const &, int)const>(
              &::drake::systems::SystemBase::EvalAbstractInput),
          py::arg("context"), py::arg("port_index"),
          "/** Returns the value of the input port with the given `port_index` as an \
AbstractValue, which is permitted for ports of any type. Causes the value to \
become up to date first if necessary, delegating to our parent Diagram. \
Returns a pointer to the port's value, or nullptr if the port is not \
connected. If you know the actual type, use one of the more-specific \
signatures. \
 \
@pre `port_index` selects an existing input port of this System. \
 \
@see EvalInputValue(), System::EvalVectorInput(), \
     System::EvalEigenVectorInput() */")
      .def(
          "num_input_ports",
          static_cast<int (::drake::systems::SystemBase::*)() const>(
              &::drake::systems::SystemBase::num_input_ports),
          "/** Returns the number of input ports currently allocated in this System. \
These are indexed from 0 to %num_input_ports()-1. */")
      .def(
          "num_output_ports",
          static_cast<int (::drake::systems::SystemBase::*)() const>(
              &::drake::systems::SystemBase::num_output_ports),
          "/** Returns the number of output ports currently allocated in this System. \
These are indexed from 0 to %num_output_ports()-1. */")
      .def(
          "get_input_port_base",
          static_cast<::drake::systems::InputPortBase const &(
              ::drake::systems::SystemBase::*)(::drake::systems::InputPortIndex)
                          const>(
              &::drake::systems::SystemBase::get_input_port_base),
          py::arg("port_index"),
          "/** Returns a reference to an InputPort given its `port_index`. \
@pre `port_index` selects an existing input port of this System. */")
      .def("get_output_port_base",
           static_cast<::drake::systems::OutputPortBase const &(
               ::drake::systems::SystemBase::
                   *)(::drake::systems::OutputPortIndex) const>(
               &::drake::systems::SystemBase::get_output_port_base),
           py::arg("port_index"),
           "/** Returns a reference to an OutputPort given its `port_index`. \
@pre `port_index` selects an existing output port of this System. */")
      .def(
          "num_total_inputs",
          static_cast<int (::drake::systems::SystemBase::*)() const>(
              &::drake::systems::SystemBase::num_total_inputs),
          "/** Returns the total dimension of all of the vector-valued input ports (as if \
they were muxed). */")
      .def(
          "num_total_outputs",
          static_cast<int (::drake::systems::SystemBase::*)() const>(
              &::drake::systems::SystemBase::num_total_outputs),
          "/** Returns the total dimension of all of the vector-valued output ports (as \
if they were muxed). */")
      .def(
          "GetDirectFeedthroughs",
          static_cast<
              ::std::multimap<int, int, std::less<int>,
                              std::allocator<std::pair<const int, int>>> (
                  ::drake::systems::SystemBase::*)() const>(
              &::drake::systems::SystemBase::GetDirectFeedthroughs),
          "/** Reports all direct feedthroughs from input ports to output ports. For \
a system with m input ports: `I = i₀, i₁, ..., iₘ₋₁`, and n output ports, \
`O = o₀, o₁, ..., oₙ₋₁`, the return map will contain pairs (u, v) such that \
 \
- 0 ≤ u < m, \
- 0 ≤ v < n, \
- and there _might_ be a direct feedthrough from input iᵤ to each output oᵥ. \
 \
See @ref DeclareLeafOutputPort_feedthrough " DeclareLeafOutputPort " \
documentation for how leaf systems can report their feedthrough. \
*/")
      .def(
          "num_cache_entries",
          static_cast<int (::drake::systems::SystemBase::*)() const>(
              &::drake::systems::SystemBase::num_cache_entries),
          "/** Returns the number nc of cache entries currently allocated in this System. \
These are indexed from 0 to nc-1. */")
      .def("get_cache_entry",
           static_cast<::drake::systems::CacheEntry const &(
               ::drake::systems::SystemBase::*)(::drake::systems::CacheIndex)
                           const>(
               &::drake::systems::SystemBase::get_cache_entry),
           py::arg("index"),
           "/** Returns a reference to a CacheEntry given its `index`. */")
      .def(
          "get_mutable_cache_entry",
          static_cast<::drake::systems::CacheEntry &(
              ::drake::systems::SystemBase::*)(::drake::systems::CacheIndex)>(
              &::drake::systems::SystemBase::get_mutable_cache_entry),
          py::arg("index"),
          "/** (Advanced) Returns a mutable reference to a CacheEntry given its `index`. \
Note that you do not need mutable access to a CacheEntry to modify its value \
in a Context, so most users should not use this method. */")
      .def(
          "DeclareCacheEntry",
          [](::drake::systems::SystemBase &self, ::std::string description,
             ::drake::systems::CacheEntry::AllocCallback alloc_function,
             ::drake::systems::CacheEntry::CalcCallback calc_function,
             ::std::set<
                 drake::TypeSafeIndex<drake::systems::DependencyTag>,
                 std::less<drake::TypeSafeIndex<drake::systems::DependencyTag>>,
                 std::allocator<
                     drake::TypeSafeIndex<drake::systems::DependencyTag>>>
                 prerequisites_of_calc) {
            return self.DeclareCacheEntry(description, alloc_function,
                                          calc_function, prerequisites_of_calc);
          })
      .def_static(
          "nothing_ticket",
          static_cast<::drake::systems::DependencyTicket (*)()>(
              &::drake::systems::SystemBase::nothing_ticket),
          "/** Returns a ticket indicating that a computation does not depend on *any* \
source value; that is, it is a constant. If this appears in a prerequisite \
list, it must be the only entry. */")
      .def_static(
          "time_ticket",
          static_cast<::drake::systems::DependencyTicket (*)()>(
              &::drake::systems::SystemBase::time_ticket),
          "/** Returns a ticket indicating dependence on time. This is the same ticket \
for all systems and refers to the same time value. */")
      .def_static(
          "accuracy_ticket",
          static_cast<::drake::systems::DependencyTicket (*)()>(
              &::drake::systems::SystemBase::accuracy_ticket),
          "/** Returns a ticket indicating dependence on the accuracy setting in the \
Context. This is the same ticket for all systems and refers to the same \
accuracy value. */")
      .def_static(
          "q_ticket",
          static_cast<::drake::systems::DependencyTicket (*)()>(
              &::drake::systems::SystemBase::q_ticket),
          "/** Returns a ticket indicating that a computation depends on configuration \
state variables q. There is no ticket representing just one of the state \
variables qᵢ. */")
      .def_static(
          "v_ticket",
          static_cast<::drake::systems::DependencyTicket (*)()>(
              &::drake::systems::SystemBase::v_ticket),
          "/** Returns a ticket indicating dependence on velocity state variables v. This \
does _not_ also indicate a dependence on configuration variables q -- you must \
list that explicitly or use kinematics_ticket() instead. There is no ticket \
representing just one of the state variables vᵢ. */")
      .def_static(
          "z_ticket",
          static_cast<::drake::systems::DependencyTicket (*)()>(
              &::drake::systems::SystemBase::z_ticket),
          "/** Returns a ticket indicating dependence on any or all of the miscellaneous \
continuous state variables z. There is no ticket representing just one of \
the state variables zᵢ. */")
      .def_static(
          "xc_ticket",
          static_cast<::drake::systems::DependencyTicket (*)()>(
              &::drake::systems::SystemBase::xc_ticket),
          "/** Returns a ticket indicating dependence on _all_ of the continuous \
state variables q, v, or z. */")
      .def(
          "discrete_state_ticket",
          static_cast<::drake::systems::DependencyTicket (
              ::drake::systems::SystemBase::*)(
              ::drake::systems::DiscreteStateIndex) const>(
              &::drake::systems::SystemBase::discrete_state_ticket),
          py::arg("index"),
          "/** Returns a ticket indicating dependence on a particular discrete state \
variable xdᵢ (may be a vector). (We sometimes refer to this as a " discrete
              variable group ".) \
@see xd_ticket() to obtain a ticket for _all_ discrete variables. */")
      .def_static(
          "xd_ticket",
          static_cast<::drake::systems::DependencyTicket (*)()>(
              &::drake::systems::SystemBase::xd_ticket),
          "/** Returns a ticket indicating dependence on all of the numerical \
discrete state variables, in any discrete variable group. \
@see discrete_state_ticket() to obtain a ticket for just one discrete \
     state variable. */")
      .def(
          "abstract_state_ticket",
          static_cast<::drake::systems::DependencyTicket (
              ::drake::systems::SystemBase::*)(
              ::drake::systems::AbstractStateIndex) const>(
              &::drake::systems::SystemBase::abstract_state_ticket),
          py::arg("index"),
          "/** Returns a ticket indicating dependence on a particular abstract state \
variable xaᵢ. \
@see xa_ticket() to obtain a ticket for _all_ abstract variables. */")
      .def_static(
          "xa_ticket",
          static_cast<::drake::systems::DependencyTicket (*)()>(
              &::drake::systems::SystemBase::xa_ticket),
          "/** Returns a ticket indicating dependence on all of the abstract \
state variables in the current Context. \
@see abstract_state_ticket() to obtain a ticket for just one abstract \
     state variable. */")
      .def_static(
          "all_state_ticket",
          static_cast<::drake::systems::DependencyTicket (*)()>(
              &::drake::systems::SystemBase::all_state_ticket),
          "/** Returns a ticket indicating dependence on _all_ state variables x in this \
system, including continuous variables xc, discrete (numeric) variables xd, \
and abstract state variables xa. This does not imply dependence on time, \
accuracy, parameters, or inputs; those must be specified separately. If you \
mean to express dependence on all possible value sources, use \
all_sources_ticket() instead. */")
      .def(
          "numeric_parameter_ticket",
          static_cast<::drake::systems::DependencyTicket (
              ::drake::systems::SystemBase::*)(
              ::drake::systems::NumericParameterIndex) const>(
              &::drake::systems::SystemBase::numeric_parameter_ticket),
          py::arg("index"),
          "/** Returns a ticket indicating dependence on a particular numeric parameter \
pnᵢ (may be a vector). \
@see pn_ticket() to obtain a ticket for _all_ numeric parameters. */")
      .def_static(
          "pn_ticket",
          static_cast<::drake::systems::DependencyTicket (*)()>(
              &::drake::systems::SystemBase::pn_ticket),
          "/** Returns a ticket indicating dependence on all of the numerical \
parameters in the current Context. \
@see numeric_parameter_ticket() to obtain a ticket for just one numeric \
     parameter. */")
      .def(
          "abstract_parameter_ticket",
          static_cast<::drake::systems::DependencyTicket (
              ::drake::systems::SystemBase::*)(
              ::drake::systems::AbstractParameterIndex) const>(
              &::drake::systems::SystemBase::abstract_parameter_ticket),
          py::arg("index"),
          "/** Returns a ticket indicating dependence on a particular abstract \
parameter paᵢ. \
@see pa_ticket() to obtain a ticket for _all_ abstract parameters. */")
      .def_static(
          "pa_ticket",
          static_cast<::drake::systems::DependencyTicket (*)()>(
              &::drake::systems::SystemBase::pa_ticket),
          "/** Returns a ticket indicating dependence on all of the abstract \
parameters pa in the current Context. \
@see abstract_parameter_ticket() to obtain a ticket for just one abstract \
     parameter. */")
      .def_static(
          "all_parameters_ticket",
          static_cast<::drake::systems::DependencyTicket (*)()>(
              &::drake::systems::SystemBase::all_parameters_ticket),
          "/** Returns a ticket indicating dependence on _all_ parameters p in this \
system, including numeric parameters pn, and abstract parameters pa. */")
      .def(
          "input_port_ticket",
          static_cast<::drake::systems::DependencyTicket (
              ::drake::systems::SystemBase::*)(::drake::systems::InputPortIndex)
                          const>(
              &::drake::systems::SystemBase::input_port_ticket),
          py::arg("index"),
          "/** Returns a ticket indicating dependence on input port uᵢ indicated \
by `index`. \
@pre `index` selects an existing input port of this System. */")
      .def_static(
          "all_input_ports_ticket",
          static_cast<::drake::systems::DependencyTicket (*)()>(
              &::drake::systems::SystemBase::all_input_ports_ticket),
          "/** Returns a ticket indicating dependence on _all_ input ports u of this \
system. \
@see input_port_ticket() to obtain a ticket for just one input port. */")
      .def_static(
          "all_sources_except_input_ports_ticket",
          static_cast<::drake::systems::DependencyTicket (*)()>(
              &::drake::systems::SystemBase::
                  all_sources_except_input_ports_ticket),
          "/** Returns a ticket indicating dependence on every possible independent \
source value _except_ input ports. This can be helpful in avoiding the \
incorrect appearance of algebraic loops in a Diagram (those always involve \
apparent input port dependencies). For an output port, use this ticket plus \
tickets for just the input ports on which the output computation _actually_ \
depends. The sources included in this ticket are: time, accuracy, state, \
and parameters. Note that dependencies on cache entries are _not_ included \
here. Usually that won't matter since cache entries typically depend on at \
least one of time, accuracy, state, or parameters so will be invalidated for \
the same reason the current computation is. However, for a computation that \
depends on a cache entry that depends only on input ports, be sure that \
you have included those input ports in the dependency list, or include a \
direct dependency on the cache entry. \
 \
@see input_port_ticket() to obtain a ticket for an input port. \
@see cache_entry_ticket() to obtain a ticket for a cache entry. \
@see all_sources_ticket() to also include all input ports as dependencies. */")
      .def_static(
          "all_sources_ticket",
          static_cast<::drake::systems::DependencyTicket (*)()>(
              &::drake::systems::SystemBase::all_sources_ticket),
          "/** Returns a ticket indicating dependence on every possible independent \
source value, including time, accuracy, state, input ports, and parameters \
(but not cache entries). This is the default dependency for computations that \
have not specified anything more refined. It is equivalent to the set \
`{all_sources_except_input_ports_ticket(), all_input_ports_ticket()}`. \
@see cache_entry_ticket() to obtain a ticket for a cache entry. */")
      .def(
          "cache_entry_ticket",
          static_cast<::drake::systems::DependencyTicket (
              ::drake::systems::SystemBase::*)(::drake::systems::CacheIndex)
                          const>(
              &::drake::systems::SystemBase::cache_entry_ticket),
          py::arg("index"),
          "/** Returns a ticket indicating dependence on the cache entry indicated \
by `index`. Note that cache entries are _not_ included in the `all_sources` \
ticket so must be listed separately. \
@pre `index` selects an existing cache entry in this System. */")
      .def_static("configuration_ticket",
                  static_cast<::drake::systems::DependencyTicket (*)()>(
                      &::drake::systems::SystemBase::configuration_ticket),
                  "")
      .def_static("kinematics_ticket",
                  static_cast<::drake::systems::DependencyTicket (*)()>(
                      &::drake::systems::SystemBase::kinematics_ticket),
                  "")
      .def_static(
          "xcdot_ticket",
          static_cast<::drake::systems::DependencyTicket (*)()>(
              &::drake::systems::SystemBase::xcdot_ticket),
          "/** Returns a ticket for the cache entry that holds time derivatives of \
the continuous variables. \
@see EvalTimeDerivatives() */")
      .def_static(
          "pe_ticket",
          static_cast<::drake::systems::DependencyTicket (*)()>(
              &::drake::systems::SystemBase::pe_ticket),
          "/** Returns a ticket for the cache entry that holds the potential energy \
calculation. \
@see System::EvalPotentialEnergy() */")
      .def_static(
          "ke_ticket",
          static_cast<::drake::systems::DependencyTicket (*)()>(
              &::drake::systems::SystemBase::ke_ticket),
          "/** Returns a ticket for the cache entry that holds the kinetic energy \
calculation. \
@see System::EvalKineticEnergy() */")
      .def_static(
          "pc_ticket",
          static_cast<::drake::systems::DependencyTicket (*)()>(
              &::drake::systems::SystemBase::pc_ticket),
          "/** Returns a ticket for the cache entry that holds the conservative power \
calculation. \
@see System::EvalConservativePower() */")
      .def_static(
          "pnc_ticket",
          static_cast<::drake::systems::DependencyTicket (*)()>(
              &::drake::systems::SystemBase::pnc_ticket),
          "/** Returns a ticket for the cache entry that holds the non-conservative \
power calculation. \
@see System::EvalNonConservativePower() */")
      .def(
          "output_port_ticket",
          static_cast<::drake::systems::DependencyTicket (
              ::drake::systems::SystemBase::*)(
              ::drake::systems::OutputPortIndex) const>(
              &::drake::systems::SystemBase::output_port_ticket),
          py::arg("index"),
          "/** (Internal use only) Returns a ticket indicating dependence on the output \
port indicated by `index`. No user-definable quantities in a system can \
meaningfully depend on that system's own output ports. \
@pre `index` selects an existing output port of this System. */")
      .def("num_continuous_states",
           static_cast<int (::drake::systems::SystemBase::*)() const>(
               &::drake::systems::SystemBase::num_continuous_states),
           "/** Returns the number of declared continuous state variables. */")
      .def(
          "num_discrete_state_groups",
          static_cast<int (::drake::systems::SystemBase::*)() const>(
              &::drake::systems::SystemBase::num_discrete_state_groups),
          "/** Returns the number of declared discrete state groups (each group is \
a vector-valued discrete state variable). */")
      .def("num_abstract_states",
           static_cast<int (::drake::systems::SystemBase::*)() const>(
               &::drake::systems::SystemBase::num_abstract_states),
           "/** Returns the number of declared abstract state variables. */")
      .def(
          "num_numeric_parameter_groups",
          static_cast<int (::drake::systems::SystemBase::*)() const>(
              &::drake::systems::SystemBase::num_numeric_parameter_groups),
          "/** Returns the number of declared numeric parameters (each of these is \
a vector-valued parameter). */")
      .def("num_abstract_parameters",
           static_cast<int (::drake::systems::SystemBase::*)() const>(
               &::drake::systems::SystemBase::num_abstract_parameters),
           "/** Returns the number of declared abstract parameters. */")
      .def(
          "implicit_time_derivatives_residual_size",
          static_cast<int (::drake::systems::SystemBase::*)() const>(
              &::drake::systems::SystemBase::
                  implicit_time_derivatives_residual_size),
          "/** Returns the size of the implicit time derivatives residual vector. \
By default this is the same as num_continuous_states() but a LeafSystem \
can change it during construction via \
LeafSystem::DeclareImplicitTimeDerivativesResidualSize(). */")
      .def("ValidateContext",
           static_cast<void (::drake::systems::SystemBase::*)(
               ::drake::systems::ContextBase const &) const>(
               &::drake::systems::SystemBase::ValidateContext),
           py::arg("context"),
           "/** Checks whether the given context was created for this system. \
@note This method is sufficiently fast for performance sensitive code. */")
      .def("ValidateContext",
           static_cast<void (::drake::systems::SystemBase::*)(
               ::drake::systems::ContextBase *) const>(
               &::drake::systems::SystemBase::ValidateContext),
           py::arg("context"),
           "/** Checks whether the given context was created for this system. \
@note This method is sufficiently fast for performance sensitive code. */")
      .def("AddInputPort",
           [](::drake::systems::SystemBase &self,
              drake::systems::InputPortBase port) {
             self.AddInputPort(
                 std::make_unique<drake::systems::InputPortBase>(port));
           })
      .def("AddOutputPort",
           [](::drake::systems::SystemBase &self,
              drake::systems::OutputPortBase port) {
             self.AddOutputPort(
                 std::make_unique<drake::systems::OutputPortBase>(port));
           })
      .def(
          "NextInputPortName",
          static_cast<::std::string (::drake::systems::SystemBase::*)(
              ::std::variant<std::basic_string<char, std::char_traits<char>,
                                               std::allocator<char>>,
                             drake::systems::UseDefaultName>) const>(
              &SystemBase_publicist::NextInputPortName),
          py::arg("given_name"),
          "/** (Internal use only) Returns a name for the next input port, using the \
given name if it isn't kUseDefaultName, otherwise making up a name like " u3 " \
from the next available input port index. \
@pre `given_name` must not be empty. */")
      .def(
          "NextOutputPortName",
          static_cast<::std::string (::drake::systems::SystemBase::*)(
              ::std::variant<std::basic_string<char, std::char_traits<char>,
                                               std::allocator<char>>,
                             drake::systems::UseDefaultName>) const>(
              &SystemBase_publicist::NextOutputPortName),
          py::arg("given_name"),
          "/** (Internal use only) Returns a name for the next output port, using the \
given name if it isn't kUseDefaultName, otherwise making up a name like " y3 " \
from the next available output port index. \
@pre `given_name` must not be empty. */")
      .def(
          "AddDiscreteStateGroup",
          static_cast<void (::drake::systems::SystemBase::*)(
              ::drake::systems::DiscreteStateIndex)>(
              &SystemBase_publicist::AddDiscreteStateGroup),
          py::arg("index"),
          "/** (Internal use only) Assigns a ticket to a new discrete variable group \
with the given `index`. \
@pre The supplied index must be the next available one; that is, indexes \
     must be assigned sequentially. */")
      .def(
          "AddAbstractState",
          static_cast<void (::drake::systems::SystemBase::*)(
              ::drake::systems::AbstractStateIndex)>(
              &SystemBase_publicist::AddAbstractState),
          py::arg("index"),
          "/** (Internal use only) Assigns a ticket to a new abstract state variable with \
the given `index`. \
@pre The supplied index must be the next available one; that is, indexes \
     must be assigned sequentially. */")
      .def(
          "AddNumericParameter",
          static_cast<void (::drake::systems::SystemBase::*)(
              ::drake::systems::NumericParameterIndex)>(
              &SystemBase_publicist::AddNumericParameter),
          py::arg("index"),
          "/** (Internal use only) Assigns a ticket to a new numeric parameter with \
the given `index`. \
@pre The supplied index must be the next available one; that is, indexes \
     must be assigned sequentially. */")
      .def(
          "AddAbstractParameter",
          static_cast<void (::drake::systems::SystemBase::*)(
              ::drake::systems::AbstractParameterIndex)>(
              &SystemBase_publicist::AddAbstractParameter),
          py::arg("index"),
          "/** (Internal use only) Assigns a ticket to a new abstract parameter with \
the given `index`. \
@pre The supplied index must be the next available one; that is, indexes \
     must be assigned sequentially. */")
      .def(
          "DeclareCacheEntryWithKnownTicket",
          [](::drake::systems::SystemBase &self,
             ::drake::systems::DependencyTicket known_ticket,
             ::std::string description,
             ::drake::systems::CacheEntry::AllocCallback alloc_function,
             ::drake::systems::CacheEntry::CalcCallback calc_function,
             ::std::set<
                 drake::TypeSafeIndex<drake::systems::DependencyTag>,
                 std::less<drake::TypeSafeIndex<drake::systems::DependencyTag>>,
                 std::allocator<
                     drake::TypeSafeIndex<drake::systems::DependencyTag>>>
                 prerequisites_of_calc) {
            return self.DeclareCacheEntryWithKnownTicket(
                known_ticket, description, alloc_function, calc_function,
                prerequisites_of_calc);
          })
      .def(
          "get_parent_service",
          static_cast<
              ::drake::systems::internal::SystemParentServiceInterface const *(
                  ::drake::systems::SystemBase::*)() const>(
              &SystemBase_publicist::get_parent_service),
          "/** Returns a pointer to the service interface of the immediately enclosing \
Diagram if one has been set, otherwise nullptr. */")
      .def(
          "assign_next_dependency_ticket",
          static_cast<::drake::systems::DependencyTicket (
              ::drake::systems::SystemBase::*)()>(
              &SystemBase_publicist::assign_next_dependency_ticket),
          "/** (Internal use only) Assigns the next unused dependency ticket number, \
unique only within a particular system. Each call to this method increments \
the ticket number. */")
      .def_static(
          "set_parent_service",
          static_cast<void (*)(
              ::drake::systems::SystemBase *,
              ::drake::systems::internal::SystemParentServiceInterface const
                  *)>(&SystemBase_publicist::set_parent_service),
          py::arg("child"), py::arg("parent_service"),
          "/** (Internal use only) Declares that `parent_service` is the service \
interface of the Diagram that owns this subsystem. Aborts if the parent \
service has already been set to something else. */")
      .def(
          "MakeFixInputPortTypeChecker",
          static_cast<::std::function<void(const drake::AbstractValue &)> (
              ::drake::systems::SystemBase::*)(::drake::systems::InputPortIndex)
                          const>(
              &SystemBase_publicist::MakeFixInputPortTypeChecker),
          py::arg("port_index"),
          "/** (Internal use only) Given a `port_index`, returns a function to be called \
when validating Context::FixInputPort requests. The function should attempt \
to throw an exception if the input AbstractValue is invalid, so that errors \
can be reported at Fix-time instead of EvalInput-time.*/")
      .def(
          "EvalAbstractInputImpl",
          static_cast<::drake::AbstractValue const *(
              ::drake::systems::SystemBase::
                  *)(char const *, ::drake::systems::ContextBase const &,
                     ::drake::systems::InputPortIndex) const>(
              &SystemBase_publicist::EvalAbstractInputImpl),
          py::arg("func"), py::arg("context"), py::arg("port_index"),
          "/** (Internal use only) Shared code for updating an input port and returning a \
pointer to its abstract value, or nullptr if the port is not connected. `func` \
should be the user-visible API function name obtained with __func__. */")
      .def(
          "ThrowNegativePortIndex",
          static_cast<void (::drake::systems::SystemBase::*)(char const *, int)
                          const>(&SystemBase_publicist::ThrowNegativePortIndex),
          py::arg("func"), py::arg("port_index"), "")
      .def(
          "ThrowInputPortIndexOutOfRange",
          static_cast<void (::drake::systems::SystemBase::*)(
              char const *, ::drake::systems::InputPortIndex) const>(
              &SystemBase_publicist::ThrowInputPortIndexOutOfRange),
          py::arg("func"), py::arg("port_index"),
          "/** Throws std::out_of_range to report bad input `port_index` that was passed \
to API method `func`. */")
      .def(
          "ThrowOutputPortIndexOutOfRange",
          static_cast<void (::drake::systems::SystemBase::*)(
              char const *, ::drake::systems::OutputPortIndex) const>(
              &SystemBase_publicist::ThrowOutputPortIndexOutOfRange),
          py::arg("func"), py::arg("port_index"),
          "/** Throws std::out_of_range to report bad output `port_index` that was passed \
to API method `func`. */")
      .def(
          "ThrowNotAVectorInputPort",
          static_cast<void (::drake::systems::SystemBase::*)(
              char const *, ::drake::systems::InputPortIndex) const>(
              &SystemBase_publicist::ThrowNotAVectorInputPort),
          py::arg("func"), py::arg("port_index"),
          "/** Throws std::logic_error because someone misused API method `func`, that is \
only allowed for declared-vector input ports, on an abstract port whose \
index is given here. */")
      .def(
          "ThrowInputPortHasWrongType",
          static_cast<void (::drake::systems::SystemBase::*)(
              char const *, ::drake::systems::InputPortIndex,
              ::std::string const &, ::std::string const &) const>(
              &SystemBase_publicist::ThrowInputPortHasWrongType),
          py::arg("func"), py::arg("port_index"), py::arg("expected_type"),
          py::arg("actual_type"),
          "/** Throws std::logic_error because someone called API method `func` claiming \
the input port had some value type that was wrong. */")
      .def_static(
          "ThrowInputPortHasWrongType",
          static_cast<void (*)(char const *, ::std::string const &,
                               ::drake::systems::InputPortIndex,
                               ::std::string const &, ::std::string const &,
                               ::std::string const &)>(
              &SystemBase_publicist::ThrowInputPortHasWrongType),
          py::arg("func"), py::arg("system_pathname"), py::arg("arg2"),
          py::arg("port_name"), py::arg("expected_type"),
          py::arg("actual_type"),
          "/** Throws std::logic_error because someone called API method `func` claiming \
the input port had some value type that was wrong. */")
      .def(
          "ThrowCantEvaluateInputPort",
          static_cast<void (::drake::systems::SystemBase::*)(
              char const *, ::drake::systems::InputPortIndex) const>(
              &SystemBase_publicist::ThrowCantEvaluateInputPort),
          py::arg("func"), py::arg("port_index"),
          "/** Throws std::logic_error because someone called API method `func`, that \
requires this input port to be evaluatable, but the port was neither \
fixed nor connected. */")
      .def(
          "GetInputPortBaseOrThrow",
          static_cast<::drake::systems::InputPortBase const &(
              ::drake::systems::SystemBase::*)(char const *, int)const>(
              &SystemBase_publicist::GetInputPortBaseOrThrow),
          py::arg("func"), py::arg("port_index"),
          "/** (Internal use only) Returns the InputPortBase at index `port_index`, \
throwing std::out_of_range we don't like the port index. The name of the \
public API method that received the bad index is provided in `func` and is \
included in the error message. */")
      .def(
          "GetOutputPortBaseOrThrow",
          static_cast<::drake::systems::OutputPortBase const &(
              ::drake::systems::SystemBase::*)(char const *, int)const>(
              &SystemBase_publicist::GetOutputPortBaseOrThrow),
          py::arg("func"), py::arg("port_index"),
          "/** (Internal use only) Returns the OutputPortBase at index `port_index`, \
throwing std::out_of_range if we don't like the port index. The name of the \
public API method that received the bad index is provided in `func` and is \
included in the error message. */")
      .def(
          "InitializeContextBase",
          static_cast<void (::drake::systems::SystemBase::*)(
              ::drake::systems::ContextBase *) const>(
              &SystemBase_publicist::InitializeContextBase),
          py::arg("context"),
          "/** This method must be invoked from within derived class DoAllocateContext() \
implementations right after the concrete Context object has been allocated. \
It allocates cache entries, sets up all intra-Context dependencies, and marks \
the ContextBase as initialized so that we can verify proper derived-class \
behavior. \
@pre The supplied context must not be null and must not already have been \
     initialized. */")
      .def(
          "DoAllocateContext",
          static_cast<::std::unique_ptr<
              drake::systems::ContextBase,
              std::default_delete<drake::systems::ContextBase>> (
              ::drake::systems::SystemBase::*)() const>(
              &SystemBase_publicist::DoAllocateContext),
          "/** Derived class implementations should allocate a suitable concrete Context \
type, then invoke the above InitializeContextBase() method. A Diagram must \
then invoke AllocateContext() to obtain each of the subcontexts for its \
DiagramContext, and must set up inter-subcontext dependencies among its \
children and between itself and its children. Then context resources such as \
parameters and state should be allocated. */")
      .def(
          "set_implicit_time_derivatives_residual_size",
          static_cast<void (::drake::systems::SystemBase::*)(int)>(
              &SystemBase_publicist::
                  set_implicit_time_derivatives_residual_size),
          py::arg("n"),
          "/** Allows a LeafSystem to override the default size for the implicit time \
derivatives residual and a Diagram to sum up the total size. If no value \
is set, the default size is n=num_continuous_states(). \
 \
@param[in] n The size of the residual vector output argument of \
             System::CalcImplicitTimeDerivativesResidual(). If n <= 0 \
             restore to the default, num_continuous_states(). \
 \
@see implicit_time_derivatives_residual_size() \
@see LeafSystem::DeclareImplicitTimeDerivativesResidualSize() \
@see System::CalcImplicitTimeDerivativesResidual() */")
      .def(
          "get_system_id",
          static_cast<::drake::systems::internal::SystemId (
              ::drake::systems::SystemBase::*)() const>(
              &SystemBase_publicist::get_system_id),
          "/** (Internal) Gets the id used to tag context data as being created by this \
system. */")

      ;
}
