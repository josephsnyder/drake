#include "drake/geometry/render/render_engine.h"
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;
void apb11_pydrake_DepthRenderCamera_py_register(py::module &m) {
  static bool called = false;
  if (called) {
    return;
  }
  called = true;
  py::class_<::drake::geometry::render::DepthRenderCamera> DepthRenderCamera(
      m, "DepthRenderCamera",
      "/** Collection of camera properties for cameras to be used with depth images. \
 */");

  DepthRenderCamera
      .def(py::init<::drake::geometry::render::DepthRenderCamera const &>(),
           py::arg("arg0"))
      .def(py::init<::drake::geometry::render::DepthCameraProperties const &,
                    ::drake::math::RigidTransformd>(),
           py::arg("camera"),
           py::arg("X_BD") = ::drake::math::RigidTransformd({}))
      .def(py::init<::drake::geometry::render::RenderCameraCore,
                    ::drake::geometry::render::DepthRange>(),
           py::arg("core"), py::arg("depth_range"))
      .def_static("DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE",
                  static_cast<void (*)()>(
                      &::drake::geometry::render::DepthRenderCamera::
                          DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE),
                  "")
      .def("core",
           static_cast<::drake::geometry::render::RenderCameraCore const &(
               ::drake::geometry::render::DepthRenderCamera::*)() const>(
               &::drake::geometry::render::DepthRenderCamera::core),
           "/** This camera's core render properties.  */")
      .def("depth_range",
           static_cast<::drake::geometry::render::DepthRange const &(
               ::drake::geometry::render::DepthRenderCamera::*)() const>(
               &::drake::geometry::render::DepthRenderCamera::depth_range),
           "/** The range of valid values for the depth camera.  */")

      ;
}
