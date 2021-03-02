#include "drake/geometry/render/render_engine.h"
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;
void apb11_pydrake_ClippingRange_py_register(py::module &m) {
  static bool called = false;
  if (called) {
    return;
  }
  called = true;
  py::class_<::drake::geometry::render::ClippingRange> ClippingRange(
      m, "ClippingRange",
      "/** Defines the near and far clipping planes for frustum-based (e.g. OpenGL) \
 RenderEngine cameras.  */");

  ClippingRange
      .def(py::init<::drake::geometry::render::ClippingRange const &>(),
           py::arg("arg0"))
      .def(py::init<double, double>(), py::arg("near"), py::arg("far"))
      .def_static(
          "DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE",
          static_cast<void (*)()>(&::drake::geometry::render::ClippingRange::
                                      DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE),
          "")
      .def("near",
           static_cast<double (::drake::geometry::render::ClippingRange::*)()
                           const>(
               &::drake::geometry::render::ClippingRange::near),
           "")
      .def("far",
           static_cast<double (::drake::geometry::render::ClippingRange::*)()
                           const>(
               &::drake::geometry::render::ClippingRange::far),
           "")

      ;
}
