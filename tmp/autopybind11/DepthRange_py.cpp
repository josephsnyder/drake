#include "drake/geometry/render/render_engine.h"
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;
void apb11_pydrake_DepthRange_py_register(py::module &m) {
  static bool called = false;
  if (called) {
    return;
  }
  called = true;
  py::class_<::drake::geometry::render::DepthRange> DepthRange(
      m, "DepthRange",
      "/** Defines a depth sensor's functional range. Only points that lie within the \
 range `[min_depth, max_depth]` will register meaningful values. \
 \
 @note It's important to carefully coordinate depth range and clipping planes. \
 It might seem reasonable to use the depth range as clipping planes, but that \
 would be a mistake. Objects closer than the depth range's minimum value have \
 an occluding effect in reality. If the near clipping plane is set to the \
 minimum depth range value, those objects will be clipped away and won't \
 occlude as they should. In essence, the camera will see through them and return \
 incorrect values from beyond the missing geometry. The near clipping plane \
 should _always_ be closer than the minimum depth range. How much closer depends \
 on the scenario. Given the scenario, evaluate the closest possible distance \
 to the camera that geometry in the scene could possibly achieve; the clipping \
 plane should be slightly closer than that. When in doubt, some very small \
 value (e.g., 1 mm) is typically safe.  */");

  DepthRange
      .def(py::init<::drake::geometry::render::DepthRange const &>(),
           py::arg("arg0"))
      .def(py::init<double, double>(), py::arg("min_in"), py::arg("max_in"))
      .def_static(
          "DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE",
          static_cast<void (*)()>(&::drake::geometry::render::DepthRange::
                                      DRAKE_COPYABLE_DEMAND_COPY_CAN_COMPILE),
          "")
      .def("min_depth",
           static_cast<double (::drake::geometry::render::DepthRange::*)()
                           const>(
               &::drake::geometry::render::DepthRange::min_depth),
           "")
      .def("max_depth",
           static_cast<double (::drake::geometry::render::DepthRange::*)()
                           const>(
               &::drake::geometry::render::DepthRange::max_depth),
           "")

      ;
}
