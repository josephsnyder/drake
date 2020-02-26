#ifndef Gain<Eigen::AutoDiffScalar<Eigen::VectorXd> >_hpp__pyplusplus_wrapper
#define Gain<Eigen::AutoDiffScalar<Eigen::VectorXd> >_hpp__pyplusplus_wrapper

namespace py = pybind11;
void register_Gain<Eigen::AutoDiffScalar<Eigen::VectorXd> >_class(py::module &m);
#endif // Gain<Eigen::AutoDiffScalar<Eigen::VectorXd> >_hpp__pyplusplus_wrapper
