#include "drake/lcm/drake_lcm.h"
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

class DrakeLcm_trampoline : public ::drake::lcm::DrakeLcm {
public:
  typedef ::drake::lcm::DrakeLcm DrakeLcm_alias;
  using DrakeLcm_alias::DrakeLcm;

  void Publish(std::string const &arg0, void const *arg1, int arg2,
               std::optional<double> arg3) override {
    using localType = void;
    PYBIND11_OVERLOAD(localType, DrakeLcm_alias, Publish, arg0, arg1, arg2,
                      arg3);
  }

  std::shared_ptr<drake::lcm::DrakeSubscriptionInterface>
  Subscribe(std::string const &arg0,
            drake::lcm::DrakeLcmInterface::HandlerFunction arg1) override {
    using localType = std::shared_ptr<drake::lcm::DrakeSubscriptionInterface>;
    PYBIND11_OVERLOAD(localType, DrakeLcm_alias, Subscribe, arg0, arg1);
  }

  int HandleSubscriptions(int arg0) override {
    using localType = int;
    PYBIND11_OVERLOAD(localType, DrakeLcm_alias, HandleSubscriptions, arg0);
  }
};

namespace py = pybind11;
void apb11_pydrake_DrakeLcm_py_register(py::module &m) {
  static bool called = false;
  if (called) {
    return;
  }
  called = true;
  py::class_<::drake::lcm::DrakeLcm, ::drake::lcm::DrakeLcmInterface,
             DrakeLcm_trampoline>
      DrakeLcm(m, "DrakeLcm", "/** \
 * A wrapper around a *real* LCM instance. \
 */");

  DrakeLcm.def(py::init<>())
      .def(py::init<::std::string>(), py::arg("lcm_url"))
      .def("get_lcm_instance",
           static_cast<::lcm::LCM *(::drake::lcm::DrakeLcm::*)()>(
               &::drake::lcm::DrakeLcm::get_lcm_instance),
           "/** \
 * (Advanced.) An accessor to the underlying LCM instance. The returned \
 * pointer is guaranteed to be valid for the duration of this object's \
 * lifetime. \
 */")
      .def("get_lcm_url",
           static_cast<::std::string (::drake::lcm::DrakeLcm::*)() const>(
               &::drake::lcm::DrakeLcm::get_lcm_url),
           "/** \
 * Returns the LCM URL. \
 */")
      .def("Publish",
           static_cast<void (::drake::lcm::DrakeLcm::*)(
               ::std::string const &, void const *, int,
               ::std::optional<double>)>(&::drake::lcm::DrakeLcm::Publish),
           py::arg("channel"), py::arg("data"), py::arg("data_size"),
           py::arg("time_sec"), "")
      .def("Subscribe",
           static_cast<
               ::std::shared_ptr<drake::lcm::DrakeSubscriptionInterface> (
                   ::drake::lcm::DrakeLcm::*)(
                   ::std::string const &,
                   ::drake::lcm::DrakeLcmInterface::HandlerFunction)>(
               &::drake::lcm::DrakeLcm::Subscribe),
           py::arg("channel"), py::arg("arg1"), "")
      .def("HandleSubscriptions",
           static_cast<int (::drake::lcm::DrakeLcm::*)(int)>(
               &::drake::lcm::DrakeLcm::HandleSubscriptions),
           py::arg("timeout_millis"), "")

      ;
}
