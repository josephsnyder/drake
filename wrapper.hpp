#ifndef TMP_WRAPPING_HEADER
#define TMP_WRAPPING_HEADER
#include <experimental/optional>
#include "polynomial.h"
 #include "symbolic_codegen.h"
 #include "piecewise_polynomial.h"
 #include "piecewise_trajectory.h"
 #include "piecewise_quaternion.h"
 #include "trajectory.h"
 #include "rigid_transform.h"

  template class drake::Polynomial<double>;
   template class drake::trajectories::PiecewisePolynomial<double>;
   template class drake::trajectories::PiecewiseTrajectory<double>;
   template class drake::trajectories::PiecewiseQuaternionSlerp<double>;
   template class drake::trajectories::Trajectory<double>;
   template class drake::math::RigidTransform<double>;
   template class drake::math::RigidTransform<drake::AutoDiffXd>;

namespace _wrapping_
{
  const char* const group = "drake_wrap";

  namespace wrappers
  {
       typedef drake::Polynomial<double> Polynomialdouble;
    typedef drake::symbolic::CodeGenVisitor CodeGenVisitor;
    typedef drake::trajectories::PiecewisePolynomial<double> PiecewisePolynomialdouble;
    typedef drake::trajectories::PiecewiseTrajectory<double> PiecewiseTrajectorydouble;
    typedef drake::trajectories::PiecewiseQuaternionSlerp<double> PiecewiseQuaternionSlerpdouble;
    typedef drake::trajectories::Trajectory<double> Trajectorydouble;
    typedef drake::math::RigidTransform<double> RigidTransformdouble;
    typedef drake::math::RigidTransform<drake::AutoDiffXd> RigidTransformAutoDiffXd;

  }

  void force_instantiate()
  {
    using namespace _wrapping_::wrappers;

  }
}
#endif
