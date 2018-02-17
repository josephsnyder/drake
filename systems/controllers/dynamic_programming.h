#pragma once

#include <memory>
#include <set>
#include <utility>

#include "drake/math/barycentric.h"
#include "drake/systems/analysis/simulator.h"
#include "drake/systems/framework/vector_system.h"
#include "drake/systems/primitives/barycentric_system.h"

namespace drake {
namespace systems {
namespace controllers {

/// Consolidates the many possible options to be passed to the dynamic
/// programming algorithms.
struct DynamicProgrammingOptions {
  /// A value between (0,1] that discounts future rewards.
  /// @see FittedValueIteration.
  double discount_factor{1.};

  /// For algorithms that rely on approximations of the state-dynamics
  /// (as in FittedValueIteration), this is a list of state dimensions for
  /// which the state space maximum value should be "wrapped around" to the
  /// state space minimum value.  The classic example is for angles that are
  /// wrapped around at 2π.
  std::set<int> state_indices_with_periodic_boundary_conditions;

  /// Value iteration methods converge when the value function stops
  /// changing (typically evaluated with the l∞ norm).  This value sets that
  /// threshold.
  double convergence_tol = 1e-4;

  /// If callable, this method is invoked during each major iteration of the
  /// dynamic programming algorithm, in order to facilitate e.g. graphical
  /// inspection/debugging of the results.  Note: the first call happens at
  /// iteration 1 (after the value iteration has run once), not zero.
  std::function<void(int iteration,
                     const math::BarycentricMesh<double>& state_mesh,
                     const Eigen::RowVectorXd& cost_to_go,
                     const Eigen::MatrixXd& policy)>
      visualization_callback{nullptr};
};

/// Implements Fitted Value Iteration on a (triangulated) Barycentric Mesh,
/// which designs a state-feedback policy to minimize the infinite-horizon cost
///  ∑ γⁿ g(x[n],u[n]), where γ is the discount factor in @p options.
///
/// For background, and a description of this algorithm, see
/// http://underactuated.csail.mit.edu/underactuated.html?chapter=dp .
/// It currently requires that the system to be optimized has only continuous
/// state and it is assumed to be time invariant.  This code makes a
/// discrete-time approximation (using @p timestep) for the value iteration
/// update.
///
/// @param simulator contains the reference to the System being optimized and to
/// a Context for that system, which may contain non-default Parameters, etc.
/// The @p simulator is run for @p timestep seconds from every point on the mesh
/// in order to approximate the dynamics... all of the simulation parameters
/// (integrator, etc) are relevant during that evaluation.
///
/// @param cost_function is the continuous-time instantaneous cost.  This
/// implementation of the discrete-time formulation above uses the approximation
///   g(x,u) = timestep*cost_function(x,u).
/// @param state_grid defines the mesh on the state space used to represent
/// the cost-to-go function and the resulting policy.
/// @param input_grid defines the discrete action space used in the value
/// iteration update.
/// @param timestep a time in seconds used for the discrete-time approximation.
/// @param options optional DynamicProgrammingOptions structure.
///
/// @return a std::pair containing the resulting policy, implemented as a
/// BarycentricMeshSystem, and the RowVectorXd J that defines the expected
/// cost-to-go on a BarycentricMesh using @p state_grid.  The policy has a
/// single vector input (which is the continuous state of the system passed
/// in through @p simulator) and a single vector output (which is the input
/// of the system passed in through @p simulator).
///
std::pair<std::unique_ptr<BarycentricMeshSystem<double>>, Eigen::RowVectorXd>
FittedValueIteration(
    Simulator<double>* simulator,  // has system and context, as well
    // as integrator params, etc.
    const std::function<double(const Context<double>& context)>& cost_function,
    const math::BarycentricMesh<double>::MeshGrid& state_grid,
    const math::BarycentricMesh<double>::MeshGrid& input_grid, double timestep,
    const DynamicProgrammingOptions& options = DynamicProgrammingOptions());

// TODO(russt): Handle the specific case where system is control affine and the
// cost function is quadratic positive-definite.  (Adds requirements on the
// system and cost function (e.g. autodiff/symbolic), and doesn't need the
// input_grid argument).

// TODO(russt): Implement more general FittedValueIteration methods as the
// function approximation tools become available.

Eigen::RowVectorXd
LinearProgrammingApproximateDynamicProgramming(
    Simulator<double>* simulator,  // has system and context, as well
    // as integrator params, etc.
    const std::function<double(const Context<double>& context)>& cost_function,
    const math::BarycentricMesh<double>::MeshGrid& state_grid,
    const math::BarycentricMesh<double>::MeshGrid& input_grid, double timestep,
    const DynamicProgrammingOptions& options = DynamicProgrammingOptions());


}  // namespace controllers
}  // namespace systems
}  // namespace drake
