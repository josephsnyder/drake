#include "drake/systems/estimators/luenberger_observer.h"

#include <cmath>
#include <vector>

#include <gtest/gtest.h>

#include "drake/common/eigen_types.h"
#include "drake/common/test_utilities/eigen_matrix_compare.h"
#include "drake/common/test_utilities/is_dynamic_castable.h"
#include "drake/examples/pendulum/pendulum_plant.h"
#include "drake/systems/primitives/linear_system.h"

namespace drake {
namespace {

// Test the estimator dynamics observing a linear system.
GTEST_TEST(LuenbergerObserverTest, ErrorDynamics) {
  Eigen::Matrix3d A;
  Eigen::Matrix<double, 3, 1> B;
  Eigen::Matrix<double, 2, 3> C;
  Eigen::Vector2d D;
  // clang-format off
  A << 1., 2., 3.,
       4., 5., 6.,
       7., 8., 9.;
  B << 10.,
       11.,
       12.;
  C << 16., 17., 18.,
       19., 20., 21.;
  D << 22.,
       23.;
  // clang-format on

  Eigen::Matrix<double, 3, 2> L;
  // clang-format off
  L << 24., 25., 26.,
       27., 28., 29.;
  // clang-format on

  auto plant = std::make_unique<systems::LinearSystem<double>>(A, B, C, D);
  auto plant_context = plant->CreateDefaultContext();
  auto observer =
      std::make_unique<systems::estimators::LuenbergerObserver<double>>(
          std::move(plant), std::move(plant_context), L);

  auto context = observer->CreateDefaultContext();
  auto derivatives = observer->AllocateTimeDerivatives();
  auto output = observer->AllocateOutput();

  EXPECT_FALSE(observer->HasAnyDirectFeedthrough());

  // The expected dynamics are:
  //  xhatdot = Axhat + Bu + L(y-yhat)
  //  y = xhat

  Eigen::Vector3d xhat(1.0, 2.0, 3.0);
  Vector1d u(4.0);

  Eigen::Vector2d y(5.0, 6.0);

  Eigen::Vector3d xhatdot = A * xhat + B * u + L * (y - C * xhat - D * u);

  observer->get_input_port(0).FixValue(context.get(), y);
  observer->get_input_port(1).FixValue(context.get(), u);
  context->get_mutable_continuous_state_vector().SetFromVector(xhat);

  observer->CalcTimeDerivatives(*context, derivatives.get());
  observer->CalcOutput(*context, output.get());

  double tol = 1e-10;

  EXPECT_TRUE(CompareMatrices(xhatdot, derivatives->CopyToVector(), tol));
  EXPECT_TRUE(CompareMatrices(
      xhat, output->GetMutableVectorData(0)->CopyToVector(), tol));
}

// Check that the observer inherits the dynamic types of the pendulum.
GTEST_TEST(LuenbergerObserverTest, DerivedTypes) {
  auto plant = std::make_unique<examples::pendulum::PendulumPlant<double>>();
  auto plant_context = plant->CreateDefaultContext();
  const Eigen::Matrix2d L = Eigen::Matrix2d::Identity();
  auto observer =
      std::make_unique<systems::estimators::LuenbergerObserver<double>>(
          std::move(plant), std::move(plant_context), L);
  auto context = observer->CreateDefaultContext();

  // The first input is the output of the plant (here the pendulum state).
  auto input0 = observer->AllocateInputVector(observer->get_input_port(0));
  EXPECT_TRUE(is_dynamic_castable<examples::pendulum::PendulumState<double>>(
      input0.get()));

  // The second input is the input of the plant.
  auto input1 = observer->AllocateInputVector(observer->get_input_port(1));
  EXPECT_TRUE(is_dynamic_castable<examples::pendulum::PendulumInput<double>>(
      input1.get()));

  // Would love to make the state and output have type PendulumState, but it
  // is not that way yet (see #6998).
}

}  // namespace
}  // namespace drake
