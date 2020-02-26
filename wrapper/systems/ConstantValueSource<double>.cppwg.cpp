#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "ConstantValueSource<double>.cppwg.hpp"

namespace py = pybind11;
typedef ConstantValueSource<double> ConstantValueSource<double>;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

void register_ConstantValueSource<double>_class(py::module &m){
py::class_<ConstantValueSource<double>  , std::shared_ptr<ConstantValueSource<double> >   >(m, "ConstantValueSource<double>")
        .def(py::init<::drake::AbstractValue const & >(), py::arg("value"))
    ;
}
