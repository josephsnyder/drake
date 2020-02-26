#ifndef SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >_hpp__pyplusplus_wrapper
#define SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >_hpp__pyplusplus_wrapper

namespace py = pybind11;
void register_SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >_class(py::module &m);
#endif // SymbolicVectorSystem<Eigen::AutoDiffScalar<Eigen::VectorXd> >_hpp__pyplusplus_wrapper
