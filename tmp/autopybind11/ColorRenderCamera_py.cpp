#include "drake/geometry/render/render_engine.h"
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;
void apb11_pydrake_ColorRenderCamera_py_register(py::module &m) {
  static bool called = false;
  if (called) {
    return;
  }
  called = true;
  py::class_<::drake::geometry::render::ColorRenderCamera> ColorRenderCamera(
      m, "ColorRenderCamera",
      "/** Collection of camera properties for cameras to be used with color/label \
 images.  */");

  ColorRenderCamera
      .def(py::init<::drake::geometry::render::ColorRenderCamera const &>(),
           py::arg("arg0"))
      .def(py::init<::drake::geometry::render::CameraProperties const &, bool,
                    ::drake::math::RigidTransformd>(),
           py::arg("camera"), py::arg("show_window") = bool(false),
           py::arg("X_BC") = ::drake::math::RigidTransformd({}))
      .def(py::init<::drake::geometry::render::RenderCameraCore, bool>(),
           py::arg("core"), py::arg("show_window") = bool(false))
      .def_static("DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE",
                  static_cast<void (*)()>(
                      &::drake::geometry::render::ColorRenderCamera::
                          DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE),
                  "")
      .def("core",
           static_cast<::drake::geometry::render::RenderCameraCore const &(
               ::drake::geometry::render::ColorRenderCamera::*)() const>(
               &::drake::geometry::render::ColorRenderCamera::core),
           "/** This camera's core render properties.  */")
      .def("show_window",
           static_cast<bool (::drake::geometry::render::ColorRenderCamera::*)()
                           const>(
               &::drake::geometry::render::ColorRenderCamera::show_window),
           "/** If true, requests that the RenderEngine display the rendered "
           "image.  */")

      ;
}
