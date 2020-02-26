#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "ConstantValueSource<drake::symbolic::Expression>.cppwg.hpp"

namespace py = pybind11;
typedef ConstantValueSource<drake::symbolic::Expression> ConstantValueSource<drake::symbolic::Expression>;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

void register_ConstantValueSource<drake::symbolic::Expression>_class(py::module &m){
py::class_<ConstantValueSource<drake::symbolic::Expression>  , std::shared_ptr<ConstantValueSource<drake::symbolic::Expression> >   >(m, "ConstantValueSource<drake::symbolic::Expression>")
        .def(py::init<::drake::AbstractValue const & >(), py::arg("value"))
    ;
}
