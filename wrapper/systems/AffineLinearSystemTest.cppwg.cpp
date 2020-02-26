#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "AffineLinearSystemTest.cppwg.hpp"

namespace py = pybind11;
typedef AffineLinearSystemTest AffineLinearSystemTest;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

class AffineLinearSystemTest_Overloads : public AffineLinearSystemTest{
    public:
    using AffineLinearSystemTest::AffineLinearSystemTest;
    void SetUp() override {
        PYBIND11_OVERLOAD(
            void,
            AffineLinearSystemTest,
            SetUp,
            );
    }
    void Initialize() override {
        PYBIND11_OVERLOAD_PURE(
            void,
            AffineLinearSystemTest,
            Initialize,
            );
    }

};
void register_AffineLinearSystemTest_class(py::module &m){
py::class_<AffineLinearSystemTest , AffineLinearSystemTest_Overloads , std::shared_ptr<AffineLinearSystemTest >  , Test  >(m, "AffineLinearSystemTest")
        .def(
            "SetUp", 
            (void(AffineLinearSystemTest::*)()) &AffineLinearSystemTest::SetUp, 
            " "  )
        .def(
            "Initialize", 
            (void(AffineLinearSystemTest::*)()) &AffineLinearSystemTest::Initialize, 
            " "  )
        .def(
            "SetInput", 
            (void(AffineLinearSystemTest::*)(::Eigen::Ref<const Eigen::Matrix<double, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1> > const &)) &AffineLinearSystemTest::SetInput, 
            " " , py::arg("u") )
        .def_static(
            "make_2x2_matrix", 
            (::Eigen::MatrixXd(*)(double, double, double, double)) &AffineLinearSystemTest::make_2x2_matrix, 
            " " , py::arg("a"), py::arg("b"), py::arg("c"), py::arg("d") )
        .def_static(
            "make_2x1_vector", 
            (::Eigen::VectorXd(*)(double, double)) &AffineLinearSystemTest::make_2x1_vector, 
            " " , py::arg("a"), py::arg("b") )
    ;
}
