
#include "pybind11/eigen.h"
#include "pybind11/operators.h"
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "drake/bindings/pydrake/documentation_pybind.h"
#include "drake/bindings/pydrake/pydrake_pybind.h"

namespace drake {
namespace pydrake {
PYBIND11_MODULE(CodeGenVisitor_py,m) {
  py:class<CodeGenVisitor_py>(m, "CodeGenVisitor_py", doc.CodeGenVisitor_py.doc)
      .def(py::init<::std::vector<drake::symbolic::Variable, std::allocator<drake::symbolic::Variable> > const &>(), )

      .def("CodeGen", CodeGenVisitor::CodeGen,  py::arg("e"), doc.CodeGen.doc)
    .def("VisitVariable", CodeGenVisitor::VisitVariable,  py::arg("e"), doc.VisitVariable.doc)
    .def("VisitConstant", CodeGenVisitor::VisitConstant,  py::arg("e"), doc.VisitConstant.doc)
    .def("VisitAddition", CodeGenVisitor::VisitAddition,  py::arg("e"), doc.VisitAddition.doc)
    .def("VisitMultiplication", CodeGenVisitor::VisitMultiplication,  py::arg("e"), doc.VisitMultiplication.doc)
    .def("VisitUnary", CodeGenVisitor::VisitUnary,  py::arg("f"), py::arg("e"), doc.VisitUnary.doc)
    .def("VisitBinary", CodeGenVisitor::VisitBinary,  py::arg("f"), py::arg("e"), doc.VisitBinary.doc)
    .def("VisitPow", CodeGenVisitor::VisitPow,  py::arg("e"), doc.VisitPow.doc)
    .def("VisitDivision", CodeGenVisitor::VisitDivision,  py::arg("e"), doc.VisitDivision.doc)
    .def("VisitAbs", CodeGenVisitor::VisitAbs,  py::arg("e"), doc.VisitAbs.doc)
    .def("VisitLog", CodeGenVisitor::VisitLog,  py::arg("e"), doc.VisitLog.doc)
    .def("VisitExp", CodeGenVisitor::VisitExp,  py::arg("e"), doc.VisitExp.doc)
    .def("VisitSqrt", CodeGenVisitor::VisitSqrt,  py::arg("e"), doc.VisitSqrt.doc)
    .def("VisitSin", CodeGenVisitor::VisitSin,  py::arg("e"), doc.VisitSin.doc)
    .def("VisitCos", CodeGenVisitor::VisitCos,  py::arg("e"), doc.VisitCos.doc)
    .def("VisitTan", CodeGenVisitor::VisitTan,  py::arg("e"), doc.VisitTan.doc)
    .def("VisitAsin", CodeGenVisitor::VisitAsin,  py::arg("e"), doc.VisitAsin.doc)
    .def("VisitAcos", CodeGenVisitor::VisitAcos,  py::arg("e"), doc.VisitAcos.doc)
    .def("VisitAtan", CodeGenVisitor::VisitAtan,  py::arg("e"), doc.VisitAtan.doc)
    .def("VisitAtan2", CodeGenVisitor::VisitAtan2,  py::arg("e"), doc.VisitAtan2.doc)
    .def("VisitSinh", CodeGenVisitor::VisitSinh,  py::arg("e"), doc.VisitSinh.doc)
    .def("VisitCosh", CodeGenVisitor::VisitCosh,  py::arg("e"), doc.VisitCosh.doc)
    .def("VisitTanh", CodeGenVisitor::VisitTanh,  py::arg("e"), doc.VisitTanh.doc)
    .def("VisitMin", CodeGenVisitor::VisitMin,  py::arg("e"), doc.VisitMin.doc)
    .def("VisitMax", CodeGenVisitor::VisitMax,  py::arg("e"), doc.VisitMax.doc)
    .def("VisitCeil", CodeGenVisitor::VisitCeil,  py::arg("e"), doc.VisitCeil.doc)
    .def("VisitFloor", CodeGenVisitor::VisitFloor,  py::arg("e"), doc.VisitFloor.doc)
    .def("VisitIfThenElse", CodeGenVisitor::VisitIfThenElse,  py::arg("e"), doc.VisitIfThenElse.doc)
    .def("VisitUninterpretedFunction", CodeGenVisitor::VisitUninterpretedFunction,  py::arg("e"), doc.VisitUninterpretedFunction.doc)

  
}

}  // namespace pydrake
}  // namespace drake
