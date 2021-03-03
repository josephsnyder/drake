#include "drake/math/barycentric.h"
#include <pybind11/eigen.h>
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;
void apb11_pydrake_BarycentricMesh_py_register(py::module &m) {
  static bool called = false;
  if (called) {
    return;
  }
  called = true;
  py::class_<::drake::math::BarycentricMesh<double>> BarycentricMesh_double(
      m, "BarycentricMesh_double", "");

  BarycentricMesh_double
      .def(py::init<::drake::math::BarycentricMesh<double> const &>(),
           py::arg("arg0"))
      .def(py::init<::std::vector<
               std::set<double, std::less<double>, std::allocator<double>>,
               std::allocator<std::set<double, std::less<double>,
                                       std::allocator<double>>>>>(),
           py::arg("input_grid"))
      .def_static("DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE",
                  static_cast<void (*)()>(
                      &::drake::math::BarycentricMesh<
                          double>::DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE),
                  "")
      .def(
          "get_input_grid",
          static_cast<::std::vector<
              std::set<double, std::less<double>, std::allocator<double>>,
              std::allocator<std::set<double, std::less<double>,
                                      std::allocator<double>>>> const
                          &(::drake::math::BarycentricMesh<double>::*)() const>(
              &::drake::math::BarycentricMesh<double>::get_input_grid),
          "")
      .def("get_input_size",
           static_cast<int (::drake::math::BarycentricMesh<double>::*)() const>(
               &::drake::math::BarycentricMesh<double>::get_input_size),
           "")
      .def("get_num_mesh_points",
           static_cast<int (::drake::math::BarycentricMesh<double>::*)() const>(
               &::drake::math::BarycentricMesh<double>::get_num_mesh_points),
           "")
      .def("get_num_interpolants",
           static_cast<int (::drake::math::BarycentricMesh<double>::*)() const>(
               &::drake::math::BarycentricMesh<double>::get_num_interpolants),
           "")
      .def("get_mesh_point",
           [](::drake::math::BarycentricMesh<double> &self, int index,
              Eigen::Ref<
                  ::drake::EigenPtr<Eigen::Matrix<double, -1, 1, 0, -1, 1>>, 0,
                  Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                  point) { return self.get_mesh_point(index, point); })
      .def(
          "get_mesh_point",
          static_cast<::Eigen::Matrix<double, -1, 1, 0, -1, 1> (
              ::drake::math::BarycentricMesh<double>::*)(int) const>(
              &::drake::math::BarycentricMesh<double>::get_mesh_point),
          py::arg("index"),
          "/// Returns the position of a mesh point in the input space referenced by its \
/// scalar index to @p point. \
/// @param index must be in [0, get_num_mesh_points).")
      .def("get_all_mesh_points",
           static_cast<::Eigen::Matrix<double, -1, -1, 0, -1, -1> (
               ::drake::math::BarycentricMesh<double>::*)() const>(
               &::drake::math::BarycentricMesh<double>::get_all_mesh_points),
           "/// Returns a matrix with all of the mesh points, one per column.")
      .def("EvalBarycentricWeights",
           [](::drake::math::BarycentricMesh<double> &self,
              ::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0,
                           Eigen::InnerStride<1>> const &input,
              Eigen::Ref<::drake::EigenPtr<Eigen::Matrix<int, -1, 1, 0, -1, 1>>,
                         0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                  mesh_indices,
              Eigen::Ref<
                  ::drake::EigenPtr<Eigen::Matrix<double, -1, 1, 0, -1, 1>>, 0,
                  Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                  weights) {
             return self.EvalBarycentricWeights(input, mesh_indices, weights);
           })
      .def("Eval",
           [](::drake::math::BarycentricMesh<double> &self,
              ::Eigen::Ref<const Eigen::Matrix<double, -1, -1, 0, -1, -1>, 0,
                           Eigen::OuterStride<-1>> const &mesh_values,
              ::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0,
                           Eigen::InnerStride<1>> const &input,
              Eigen::Ref<
                  ::drake::EigenPtr<Eigen::Matrix<double, -1, 1, 0, -1, 1>>, 0,
                  Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                  output) { return self.Eval(mesh_values, input, output); })
      .def("Eval",
           [](::drake::math::BarycentricMesh<double> &self,
              ::Eigen::Ref<const Eigen::Matrix<double, -1, -1, 0, -1, -1>, 0,
                           Eigen::OuterStride<-1>> const &mesh_values,
              ::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0,
                           Eigen::InnerStride<1>> const &input) {
             return self.Eval(mesh_values, input);
           })
      .def("EvalBarycentricWeights",
           [](::drake::math::BarycentricMesh<double> &self,
              ::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0,
                           Eigen::InnerStride<1>> const &input,
              Eigen::Ref<::drake::EigenPtr<Eigen::Matrix<int, -1, 1, 0, -1, 1>>,
                         0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                  mesh_indices,
              Eigen::Ref<
                  ::drake::EigenPtr<Eigen::Matrix<double, -1, 1, 0, -1, 1>>, 0,
                  Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                  weights) {
             return self.EvalBarycentricWeights(input, mesh_indices, weights);
           })
      .def("MeshValuesFrom",
           [](::drake::math::BarycentricMesh<double> &self,
              ::std::function<Eigen::Matrix<double, -1, 1, 0, -1, 1>(
                  const Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>,
                                   0, Eigen::InnerStride<1>> &)> const
                  &vector_func) { return self.MeshValuesFrom(vector_func); })
      .def(
          "get_all_mesh_points",
          static_cast<::Eigen::Matrix<double, -1, -1, 0, -1, -1> (
              ::drake::math::BarycentricMesh<double>::*)() const>(
              &::drake::math::BarycentricMesh<double>::get_all_mesh_points),
          R"""(/// Returns a matrix with all of the mesh points, one per column.)""")
      .def(
          "get_input_grid",
          static_cast<::std::vector<
              std::set<double, std::less<double>, std::allocator<double>>,
              std::allocator<std::set<double, std::less<double>,
                                      std::allocator<double>>>> const
                          &(::drake::math::BarycentricMesh<double>::*)() const>(
              &::drake::math::BarycentricMesh<double>::get_input_grid))
      .def("get_input_size",
           static_cast<int (::drake::math::BarycentricMesh<double>::*)() const>(
               &::drake::math::BarycentricMesh<double>::get_input_size))
      .def("get_mesh_point",
           [](::drake::math::BarycentricMesh<double> &self, int index,
              Eigen::Ref<
                  ::drake::EigenPtr<Eigen::Matrix<double, -1, 1, 0, -1, 1>>, 0,
                  Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>
                  point) { return self.get_mesh_point(index, point); })
      .def(
          "get_mesh_point",
          static_cast<::Eigen::Matrix<double, -1, 1, 0, -1, 1> (
              ::drake::math::BarycentricMesh<double>::*)(int) const>(
              &::drake::math::BarycentricMesh<double>::get_mesh_point),
          py::arg("index"),
          R"""(/// Returns the position of a mesh point in the input space referenced by its 
/// scalar index to @p point. 
/// @param index must be in [0, get_num_mesh_points).)""")
      .def("get_num_interpolants",
           static_cast<int (::drake::math::BarycentricMesh<double>::*)() const>(
               &::drake::math::BarycentricMesh<double>::get_num_interpolants))
      .def("get_num_mesh_points",
           static_cast<int (::drake::math::BarycentricMesh<double>::*)() const>(
               &::drake::math::BarycentricMesh<double>::get_num_mesh_points))

      ;
}
