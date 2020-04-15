
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

      .def("CodeGen", CodeGenVisitor::CodeGen,  py::arg("e"), doc.CodeGenVisitor.CodeGen.doc)
    .def("VisitVariable", CodeGenVisitor::VisitVariable,  py::arg("e"), doc.CodeGenVisitor.VisitVariable.doc)
    .def("VisitConstant", CodeGenVisitor::VisitConstant,  py::arg("e"), doc.CodeGenVisitor.VisitConstant.doc)
    .def("VisitAddition", CodeGenVisitor::VisitAddition,  py::arg("e"), doc.CodeGenVisitor.VisitAddition.doc)
    .def("VisitMultiplication", CodeGenVisitor::VisitMultiplication,  py::arg("e"), doc.CodeGenVisitor.VisitMultiplication.doc)
    .def("VisitUnary", CodeGenVisitor::VisitUnary,  py::arg("f"), py::arg("e"), doc.CodeGenVisitor.VisitUnary.doc)
    .def("VisitBinary", CodeGenVisitor::VisitBinary,  py::arg("f"), py::arg("e"), doc.CodeGenVisitor.VisitBinary.doc)
    .def("VisitPow", CodeGenVisitor::VisitPow,  py::arg("e"), doc.CodeGenVisitor.VisitPow.doc)
    .def("VisitDivision", CodeGenVisitor::VisitDivision,  py::arg("e"), doc.CodeGenVisitor.VisitDivision.doc)
    .def("VisitAbs", CodeGenVisitor::VisitAbs,  py::arg("e"), doc.CodeGenVisitor.VisitAbs.doc)
    .def("VisitLog", CodeGenVisitor::VisitLog,  py::arg("e"), doc.CodeGenVisitor.VisitLog.doc)
    .def("VisitExp", CodeGenVisitor::VisitExp,  py::arg("e"), doc.CodeGenVisitor.VisitExp.doc)
    .def("VisitSqrt", CodeGenVisitor::VisitSqrt,  py::arg("e"), doc.CodeGenVisitor.VisitSqrt.doc)
    .def("VisitSin", CodeGenVisitor::VisitSin,  py::arg("e"), doc.CodeGenVisitor.VisitSin.doc)
    .def("VisitCos", CodeGenVisitor::VisitCos,  py::arg("e"), doc.CodeGenVisitor.VisitCos.doc)
    .def("VisitTan", CodeGenVisitor::VisitTan,  py::arg("e"), doc.CodeGenVisitor.VisitTan.doc)
    .def("VisitAsin", CodeGenVisitor::VisitAsin,  py::arg("e"), doc.CodeGenVisitor.VisitAsin.doc)
    .def("VisitAcos", CodeGenVisitor::VisitAcos,  py::arg("e"), doc.CodeGenVisitor.VisitAcos.doc)
    .def("VisitAtan", CodeGenVisitor::VisitAtan,  py::arg("e"), doc.CodeGenVisitor.VisitAtan.doc)
    .def("VisitAtan2", CodeGenVisitor::VisitAtan2,  py::arg("e"), doc.CodeGenVisitor.VisitAtan2.doc)
    .def("VisitSinh", CodeGenVisitor::VisitSinh,  py::arg("e"), doc.CodeGenVisitor.VisitSinh.doc)
    .def("VisitCosh", CodeGenVisitor::VisitCosh,  py::arg("e"), doc.CodeGenVisitor.VisitCosh.doc)
    .def("VisitTanh", CodeGenVisitor::VisitTanh,  py::arg("e"), doc.CodeGenVisitor.VisitTanh.doc)
    .def("VisitMin", CodeGenVisitor::VisitMin,  py::arg("e"), doc.CodeGenVisitor.VisitMin.doc)
    .def("VisitMax", CodeGenVisitor::VisitMax,  py::arg("e"), doc.CodeGenVisitor.VisitMax.doc)
    .def("VisitCeil", CodeGenVisitor::VisitCeil,  py::arg("e"), doc.CodeGenVisitor.VisitCeil.doc)
    .def("VisitFloor", CodeGenVisitor::VisitFloor,  py::arg("e"), doc.CodeGenVisitor.VisitFloor.doc)
    .def("VisitIfThenElse", CodeGenVisitor::VisitIfThenElse,  py::arg("e"), doc.CodeGenVisitor.VisitIfThenElse.doc)
    .def("VisitUninterpretedFunction", CodeGenVisitor::VisitUninterpretedFunction,  py::arg("e"), doc.CodeGenVisitor.VisitUninterpretedFunction.doc)

  
}

}  // namespace pydrake
}  // namespace drake
