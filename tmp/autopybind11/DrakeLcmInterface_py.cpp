#include "drake/lcm/drake_lcm_interface.h"
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;
void apb11_pydrake_DrakeLcmInterface_py_register(py::module &m) {
  static bool called = false;
  if (called) {
    return;
  }
  called = true;
  py::class_<::drake::lcm::DrakeLcmInterface> DrakeLcmInterface(
      m, "DrakeLcmInterface",
      R"""(/** 
 * A pure virtual interface that enables LCM to be mocked. 
 * 
 * Because it must be pure, in general it will receive breaking API changes 
 * without notice.  Users should not subclass this interface directly, but 
 * rather use one of the existing subclasses instead. 
 * 
 * Similarly, method arguments will receive breaking API changes without 
 * notice.  Users should not call this interface directly, but rather use 
 * drake::lcm::Publish() or drake::lcm::Subscribe() instead. 
 */)""");

  DrakeLcmInterface
      .def("HandleSubscriptions",
           static_cast<int (::drake::lcm::DrakeLcmInterface::*)(int)>(
               &::drake::lcm::DrakeLcmInterface::HandleSubscriptions),
           py::arg("timeout_millis"),
           R"""(/** 
 * Invokes the HandlerFunction callbacks for all subscriptions' pending 
 * messages.  If @p timeout_millis is >0, blocks for up to that long until at 
 * least one message is handled. 
 * @return the number of messages handled, or 0 on timeout. 
 * @throw std::exception when a subscribed handler throws. 
 */)""")
      .def("Publish",
           static_cast<void (::drake::lcm::DrakeLcmInterface::*)(
               ::std::string const &, void const *, int,
               ::std::optional<double>)>(
               &::drake::lcm::DrakeLcmInterface::Publish),
           py::arg("channel"), py::arg("data"), py::arg("data_size"),
           py::arg("time_sec"),
           R"""(/** 
 * Most users should use the drake::lcm::Publish() free function, instead of 
 * this interface method. 
 * 
 * Publishes an LCM message on channel @p channel. 
 * 
 * @param channel The channel on which to publish the message. 
 * Must not be the empty string. 
 * 
 * @param data A buffer containing the serialized bytes of the message to 
 * publish. 
 * 
 * @param data_size The length of @data in bytes. 
 * 
 * @param time_sec Time in seconds when the publish event occurred. 
 * If unknown, use nullopt or a default-constructed optional. 
 */)""")
      .def("Subscribe",
           static_cast<
               ::std::shared_ptr<drake::lcm::DrakeSubscriptionInterface> (
                   ::drake::lcm::DrakeLcmInterface::*)(
                   ::std::string const &,
                   ::drake::lcm::DrakeLcmInterface::HandlerFunction)>(
               &::drake::lcm::DrakeLcmInterface::Subscribe),
           py::arg("channel"), py::arg("arg1"),
           R"""(/** 
 * Most users should use the drake::lcm::Subscribe() free function or the 
 * drake::lcm::Subscriber wrapper class, instead of this interface method. 
 * 
 * Subscribes to an LCM channel without automatic message decoding. The 
 * handler will be invoked when a message arrives on channel @p channel. 
 * 
 * The handler should never throw an exception, because it is indirectly 
 * called from C functions. 
 * 
 * NOTE: Unlike upstream LCM, DrakeLcm does not support regexes for the 
 * `channel` argument. 
 * 
 * @param channel The channel to subscribe to. 
 * Must not be the empty string. 
 * 
 * @return the object used to manage the subscription if that is supported, 
 * or else nullptr if not supported.  The unsubscribe-on-delete default is 
 * `false`.  Refer to the DrakeSubscriptionInterface class overview for 
 * details. 
 */)""")

      ;
}
