#include <pybind11/pybind11.h>
#include "wrapper_header_collection.hpp"
#include "TestSystemMatrixTrajectories.cppwg.hpp"
#include "AffineLinearSystemTest.cppwg.hpp"
#include "ConstantValueSource<double>.cppwg.hpp"
#include "ConstantValueSource<Eigen::AutoDiffScalar<Eigen::VectorXd> >.cppwg.hpp"
#include "ConstantValueSource<drake::symbolic::Expression>.cppwg.hpp"
#include "TrajectoryAffineSystem<double>.cppwg.hpp"
#include "TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >.cppwg.hpp"
#include "Traits<TrajectoryLinearSystem>.cppwg.hpp"
#include "Traits<TrajectoryAffineSystem>.cppwg.hpp"
#include "PassThrough<double>.cppwg.hpp"
#include "PassThrough<Eigen::AutoDiffScalar<Eigen::VectorXd> >.cppwg.hpp"
#include "PassThrough<drake::symbolic::Expression>.cppwg.hpp"
#include "TrajectoryLinearSystem<double>.cppwg.hpp"
#include "TrajectoryLinearSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >.cppwg.hpp"
#include "PortSwitch<double>.cppwg.hpp"
#include "PortSwitch<Eigen::AutoDiffScalar<Eigen::VectorXd> >.cppwg.hpp"
#include "PortSwitch<drake::symbolic::Expression>.cppwg.hpp"
#include "RandomSource.cppwg.hpp"
#include "ZeroOrderHold<double>.cppwg.hpp"
#include "ZeroOrderHold<Eigen::AutoDiffScalar<Eigen::VectorXd> >.cppwg.hpp"
#include "ZeroOrderHold<drake::symbolic::Expression>.cppwg.hpp"
#include "SymbolicVectorSystem<double>.cppwg.hpp"
#include "SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >.cppwg.hpp"
#include "SymbolicVectorSystem<drake::symbolic::Expression>.cppwg.hpp"
#include "SymbolicVectorSystemBuilder.cppwg.hpp"
#include "Gain<double>.cppwg.hpp"
#include "Gain<Eigen::AutoDiffScalar<Eigen::VectorXd> >.cppwg.hpp"
#include "Gain<drake::symbolic::Expression>.cppwg.hpp"
#include "TimeVaryingAffineSystem<double>.cppwg.hpp"
#include "TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >.cppwg.hpp"
#include "Sine<double>.cppwg.hpp"
#include "Sine<Eigen::AutoDiffScalar<Eigen::VectorXd> >.cppwg.hpp"
#include "Sine<drake::symbolic::Expression>.cppwg.hpp"

namespace py = pybind11;

PYBIND11_MODULE(_drake_systems, m)
{
    register_TestSystemMatrixTrajectories_class(m);
    register_AffineLinearSystemTest_class(m);
    register_ConstantValueSource<double>_class(m);
    register_ConstantValueSource<Eigen::AutoDiffScalar<Eigen::VectorXd> >_class(m);
    register_ConstantValueSource<drake::symbolic::Expression>_class(m);
    register_TrajectoryAffineSystem<double>_class(m);
    register_TrajectoryAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >_class(m);
    register_Traits<TrajectoryLinearSystem>_class(m);
    register_Traits<TrajectoryAffineSystem>_class(m);
    register_PassThrough<double>_class(m);
    register_PassThrough<Eigen::AutoDiffScalar<Eigen::VectorXd> >_class(m);
    register_PassThrough<drake::symbolic::Expression>_class(m);
    register_TrajectoryLinearSystem<double>_class(m);
    register_TrajectoryLinearSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >_class(m);
    register_PortSwitch<double>_class(m);
    register_PortSwitch<Eigen::AutoDiffScalar<Eigen::VectorXd> >_class(m);
    register_PortSwitch<drake::symbolic::Expression>_class(m);
    register_RandomSource_class(m);
    register_ZeroOrderHold<double>_class(m);
    register_ZeroOrderHold<Eigen::AutoDiffScalar<Eigen::VectorXd> >_class(m);
    register_ZeroOrderHold<drake::symbolic::Expression>_class(m);
    register_SymbolicVectorSystem<double>_class(m);
    register_SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >_class(m);
    register_SymbolicVectorSystem<drake::symbolic::Expression>_class(m);
    register_SymbolicVectorSystemBuilder_class(m);
    register_Gain<double>_class(m);
    register_Gain<Eigen::AutoDiffScalar<Eigen::VectorXd> >_class(m);
    register_Gain<drake::symbolic::Expression>_class(m);
    register_TimeVaryingAffineSystem<double>_class(m);
    register_TimeVaryingAffineSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >_class(m);
    register_Sine<double>_class(m);
    register_Sine<Eigen::AutoDiffScalar<Eigen::VectorXd> >_class(m);
    register_Sine<drake::symbolic::Expression>_class(m);
}
