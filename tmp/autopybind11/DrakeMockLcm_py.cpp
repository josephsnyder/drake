#include "drake/lcm/drake_mock_lcm.h"
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

class DrakeMockLcm_trampoline : public ::drake::lcm::DrakeMockLcm {
public:
  typedef ::drake::lcm::DrakeMockLcm DrakeMockLcm_alias;
  using DrakeMockLcm_alias::DrakeMockLcm;

  void Publish(std::string const &arg0, void const *arg1, int arg2,
               std::optional<double> arg3) override {
    using localType = void;
    PYBIND11_OVERLOAD(localType, DrakeMockLcm_alias, Publish, arg0, arg1, arg2,
                      arg3);
  }

  std::shared_ptr<drake::lcm::DrakeSubscriptionInterface>
  Subscribe(std::string const &arg0,
            drake::lcm::DrakeLcmInterface::HandlerFunction arg1) override {
    using localType = std::shared_ptr<drake::lcm::DrakeSubscriptionInterface>;
    PYBIND11_OVERLOAD(localType, DrakeMockLcm_alias, Subscribe, arg0, arg1);
  }

  int HandleSubscriptions(int arg0) override {
    using localType = int;
    PYBIND11_OVERLOAD(localType, DrakeMockLcm_alias, HandleSubscriptions, arg0);
  }

  void OnHandleSubscriptionsError(std::string const &error_message) override {
    using localType = void;
    PYBIND11_OVERLOAD_PURE(localType, DrakeMockLcm_alias,
                           OnHandleSubscriptionsError, error_message);
  }
};

namespace py = pybind11;
void apb11_pydrake_DrakeMockLcm_py_register(py::module &m) {
  static bool called = false;
  if (called) {
    return;
  }
  called = true;
  py::class_<::drake::lcm::DrakeMockLcm, ::drake::lcm::DrakeLcm, DrakeMockLcm_trampoline> DrakeMockLcm(m, "DrakeMockLcm", "/** An implementation of DrakeLcmInterface that manipulates LCM messages in \
memory, not on the wire. Other than the class name, it is identical to a \
`DrakeLcm("memq://")`, i.e., an object constructed with the <a \
href="https://lcm-proj.github.io/group__LcmC__lcm__t.html#gaf29963ef43edadf45296d5ad82c18d4b">memq \
provider</a>. \
*/");
        
    
    DrakeMockLcm.def(py::init<>())
    
    
    
    ;
}
