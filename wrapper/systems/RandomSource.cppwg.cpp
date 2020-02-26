#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "RandomSource.cppwg.hpp"

namespace py = pybind11;
typedef RandomSource RandomSource;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

class RandomSource_Overloads : public RandomSource{
    public:
    using RandomSource::RandomSource;

};
void register_RandomSource_class(py::module &m){
py::class_<RandomSource , RandomSource_Overloads , std::shared_ptr<RandomSource >   >(m, "RandomSource")
        .def(py::init<::drake::RandomDistribution, int, double >(), py::arg("distribution"), py::arg("num_outputs"), py::arg("sampling_interval_sec"))
        .def(
            "get_distribution", 
            (::drake::RandomDistribution(RandomSource::*)() const ) &RandomSource::get_distribution, 
            " "  )
        .def(
            "get_seed", 
            (::drake::systems::RandomSource::Seed(RandomSource::*)(::drake::systems::Context<double> const &) const ) &RandomSource::get_seed, 
            " " , py::arg("context") )
        .def(
            "get_fixed_seed", 
            (::std::optional<unsigned long>(RandomSource::*)() const ) &RandomSource::get_fixed_seed, 
            " "  )
        .def(
            "set_fixed_seed", 
            (void(RandomSource::*)(::std::optional<unsigned long> const &)) &RandomSource::set_fixed_seed, 
            " " , py::arg("seed") )
    ;
}
