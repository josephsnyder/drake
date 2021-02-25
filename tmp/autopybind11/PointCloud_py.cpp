#include "drake/perception/point_cloud.h"
#include <pybind11/eigen.h>
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;
void apb11_pydrake_PointCloud_py_register(py::module &m) {
  static bool called = false;
  if (called) {
    return;
  }
  called = true;
  py::class_<::drake::perception::PointCloud> PointCloud(m, "PointCloud", "/// Implements a point cloud (with contiguous storage), whose main goal is to \
/// offer a convenient, synchronized interface to commonly used fields and \
/// data types applicable for basic 3D perception. \
/// \
/// This is a mix between the philosophy of PCL (templated interface to \
/// provide a compile-time open set, run-time closed set) and VTK (non-templated \
/// interface to provide a very free form run-time open set). \
/// You may construct one PointCloud which will contain different sets of \
/// data, but you cannot change the contained data types after construction. \
/// However, you can mutate the data contained within the structure and resize \
/// the cloud. \
/// \
/// Definitions: \
/// \
/// - point - An entry in a point cloud (not exclusively an XYZ point). \
/// - feature - Abstract representation of local properties (geometric and \
///   non-geometric) \
/// - descriptor - Concrete representation of a feature. \
/// - field - A feature or descriptor described by the point cloud. \
/// \
/// This point cloud class provides the following fields: \
/// \
/// - xyz - Cartesian XYZ coordinates (float[3]). \
/// - descriptor - A descriptor that is run-time defined (float[X]). \
/// \
/// @note "contiguous" here means contiguous in memory. This was chosen to \
/// avoid ambiguity between PCL and Eigen, where in PCL "dense" implies that \
/// the point cloud corresponds to a cloud with invalid values, and in Eigen \
/// "dense" implies contiguous storage. \
/// \
/// @note The accessors / mutators for the point fields of this class returns \
/// references to the original Eigen matrices. This implies that they are \
/// invalidated whenever memory is reallocated for the values. Given this, \
/// minimize the lifetime of these references to be as short as possible. \
/// Additionally, algorithms wanting fast access to values should avoid the \
/// single point accessors / mutatotrs (e.g. `xyz(i)`, `mutable_descriptor(i)`) \
/// to avoid overhead when accessing a single element (either copying or \
/// creating a reference). \
/// \
/// @note The definitions presented here for "feature" and "descriptor" are \
/// loosely based on their definitions within PCL and Radu Rusu's dissertation: \
///   Rusu, Radu Bogdan. "Semantic 3d object maps for everyday manipulation in \
///   human living environments." KI-Künstliche Intelligenz 24.4 (2010): \
///   345-348. \
/// This differs from other definitions, such as having "feature" \
/// describe geometric quantities and "descriptor" describe non-geometric \
/// quantities which is presented in the following survey paper: \
///   Pomerleau, François, Francis Colas, and Roland Siegwart. "A review of \
///   point cloud registration algorithms for mobile robotics." Foundations and \
///   Trends® in Robotics 4.1 (2015): 1-104.");
        
    
    PointCloud.def(py::init<int,::drake::perception::pc_flags::Fields,bool>(),py::arg("new_size") = int(0),py::arg("fields") = ::drake::perception::pc_flags::Fields(drake::perception::pc_flags::kXYZs),py::arg("skip_initialize") = bool(false))
    .def(py::init<::drake::perception::PointCloud const &>(),py::arg("other"))
    .def(py::init<::drake::perception::PointCloud const &,::drake::perception::pc_flags::Fields>(),py::arg("other"),py::arg("copy_fields"))
    .def_static("IsDefaultValue", static_cast<bool (*)( ::drake::perception::PointCloud::T )>(&::drake::perception::PointCloud::IsDefaultValue), py::arg("value"), "")
    .def_static("IsInvalidValue", static_cast<bool (*)( ::drake::perception::PointCloud::T )>(&::drake::perception::PointCloud::IsInvalidValue), py::arg("value"), "")
    .def("fields", static_cast<::drake::perception::pc_flags::Fields ( ::drake::perception::PointCloud::* )(  )const>(&::drake::perception::PointCloud::fields), "/// Returns the fields provided by this point cloud.")
    .def("size", static_cast<int ( ::drake::perception::PointCloud::* )(  )const>(&::drake::perception::PointCloud::size), "/// Returns the number of points in this point cloud.")
    .def("resize", static_cast<void ( ::drake::perception::PointCloud::* )( int,bool )>(&::drake::perception::PointCloud::resize), py::arg("new_size"), py::arg("skip_initialize") = bool(false), "/// Conservative resize; will maintain existing data, and initialize new \
/// data to their invalid values. \
/// @param new_size \
///    The new size of the value. If less than the present `size()`, then \
///    the values will be truncated. If greater than the present `size()`, \
///    then the new values will be uninitialized if `skip_initialize` is not \
///    true. \
/// @param skip_initialize \
///    Do not default-initialize new values.")
    .def("has_xyzs", static_cast<bool ( ::drake::perception::PointCloud::* )(  )const>(&::drake::perception::PointCloud::has_xyzs), "/// Returns if this cloud provides XYZ values.")
    .def("xyzs", static_cast<::Eigen::Ref<const Eigen::Matrix<float, 3, -1, 0, 3, -1>, 0, Eigen::OuterStride<-1>> ( ::drake::perception::PointCloud::* )(  )const>(&::drake::perception::PointCloud::xyzs), "/// Returns access to XYZ values. \
/// @pre `has_xyzs()` must be true.", py::return_value_policy::reference_internal)
    .def("mutable_xyzs", static_cast<::Eigen::Ref<Eigen::Matrix<float, 3, -1, 0, 3, -1>, 0, Eigen::OuterStride<-1>> ( ::drake::perception::PointCloud::* )(  )>(&::drake::perception::PointCloud::mutable_xyzs), "/// Returns mutable access to XYZ values. \
/// @pre `has_xyzs()` must be true.", py::return_value_policy::reference_internal)
    .def("xyz", static_cast<::Eigen::Matrix<float, 3, 1, 0, 3, 1> ( ::drake::perception::PointCloud::* )( int )const>(&::drake::perception::PointCloud::xyz), py::arg("i"), "/// Returns access to an XYZ value. \
/// @pre `has_xyzs()` must be true.")
    .def("mutable_xyz", static_cast<::Eigen::Ref<Eigen::Matrix<float, 3, 1, 0, 3, 1>, 0, Eigen::InnerStride<1>> ( ::drake::perception::PointCloud::* )( int )>(&::drake::perception::PointCloud::mutable_xyz), py::arg("i"), "/// Returns mutable access to an XYZ value. \
/// @pre `has_xyzs()` must be true.", py::return_value_policy::reference_internal)
    .def("has_normals", static_cast<bool ( ::drake::perception::PointCloud::* )(  )const>(&::drake::perception::PointCloud::has_normals), "/// Returns if this cloud provides normals.")
    .def("normals", static_cast<::Eigen::Ref<const Eigen::Matrix<float, 3, -1, 0, 3, -1>, 0, Eigen::OuterStride<-1>> ( ::drake::perception::PointCloud::* )(  )const>(&::drake::perception::PointCloud::normals), "/// Returns access to normals. \
/// @pre `has_normals()` must be true.", py::return_value_policy::reference_internal)
    .def("mutable_normals", static_cast<::Eigen::Ref<Eigen::Matrix<float, 3, -1, 0, 3, -1>, 0, Eigen::OuterStride<-1>> ( ::drake::perception::PointCloud::* )(  )>(&::drake::perception::PointCloud::mutable_normals), "/// Returns mutable access to normals. \
/// @pre `has_normals()` must be true.", py::return_value_policy::reference_internal)
    .def("normal", static_cast<::Eigen::Matrix<float, 3, 1, 0, 3, 1> ( ::drake::perception::PointCloud::* )( int )const>(&::drake::perception::PointCloud::normal), py::arg("i"), "/// Returns access to a normal. \
/// @pre `has_normals()` must be true.")
    .def("mutable_normal", static_cast<::Eigen::Ref<Eigen::Matrix<float, 3, 1, 0, 3, 1>, 0, Eigen::InnerStride<1>> ( ::drake::perception::PointCloud::* )( int )>(&::drake::perception::PointCloud::mutable_normal), py::arg("i"), "/// Returns mutable access to a normal. \
/// @pre `has_normals()` must be true.", py::return_value_policy::reference_internal)
    .def("has_rgbs", static_cast<bool ( ::drake::perception::PointCloud::* )(  )const>(&::drake::perception::PointCloud::has_rgbs), "/// Returns if this cloud provides RGB colors.")
    .def("rgbs", static_cast<::Eigen::Ref<const Eigen::Matrix<unsigned char, 3, -1, 0, 3, -1>, 0, Eigen::OuterStride<-1>> ( ::drake::perception::PointCloud::* )(  )const>(&::drake::perception::PointCloud::rgbs), "/// Returns access to RGB colors. \
/// @pre `has_rgbs()` must be true.", py::return_value_policy::reference_internal)
    .def("mutable_rgbs", static_cast<::Eigen::Ref<Eigen::Matrix<unsigned char, 3, -1, 0, 3, -1>, 0, Eigen::OuterStride<-1>> ( ::drake::perception::PointCloud::* )(  )>(&::drake::perception::PointCloud::mutable_rgbs), "/// Returns mutable access to RGB colors. \
/// @pre `has_rgbs()` must be true.", py::return_value_policy::reference_internal)
    .def("rgb", static_cast<::Eigen::Matrix<unsigned char, 3, 1, 0, 3, 1> ( ::drake::perception::PointCloud::* )( int )const>(&::drake::perception::PointCloud::rgb), py::arg("i"), "/// Returns access to an RGB color. \
/// @pre `has_rgbs()` must be true.")
    .def("mutable_rgb", static_cast<::Eigen::Ref<Eigen::Matrix<unsigned char, 3, 1, 0, 3, 1>, 0, Eigen::InnerStride<1>> ( ::drake::perception::PointCloud::* )( int )>(&::drake::perception::PointCloud::mutable_rgb), py::arg("i"), "/// Returns mutable access to an RGB color. \
/// @pre `has_rgbs()` must be true.", py::return_value_policy::reference_internal)
    .def("has_descriptors", static_cast<bool ( ::drake::perception::PointCloud::* )(  )const>(&::drake::perception::PointCloud::has_descriptors), "/// Returns if this point cloud provides descriptor values.")
    .def("has_descriptors", static_cast<bool ( ::drake::perception::PointCloud::* )( ::drake::perception::pc_flags::DescriptorType const & )const>(&::drake::perception::PointCloud::has_descriptors), py::arg("descriptor_type"), "/// Returns if the point cloud provides a specific descriptor.")
    .def("descriptor_type", static_cast<::drake::perception::pc_flags::DescriptorType const & ( ::drake::perception::PointCloud::* )(  )const>(&::drake::perception::PointCloud::descriptor_type), "/// Returns the descriptor type.")
    .def("descriptors", static_cast<::Eigen::Ref<const Eigen::Matrix<float, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1>> ( ::drake::perception::PointCloud::* )(  )const>(&::drake::perception::PointCloud::descriptors), "/// Returns access to descriptor values. \
/// @pre `has_descriptors()` must be true.", py::return_value_policy::reference_internal)
    .def("mutable_descriptors", static_cast<::Eigen::Ref<Eigen::Matrix<float, -1, -1, 0, -1, -1>, 0, Eigen::OuterStride<-1>> ( ::drake::perception::PointCloud::* )(  )>(&::drake::perception::PointCloud::mutable_descriptors), "/// Returns mutable access to descriptor values. \
/// @pre `has_descriptors()` must be true.", py::return_value_policy::reference_internal)
    .def("descriptor", static_cast<::Eigen::Matrix<float, -1, 1, 0, -1, 1> ( ::drake::perception::PointCloud::* )( int )const>(&::drake::perception::PointCloud::descriptor), py::arg("i"), "/// Returns access to a descriptor value. \
/// @pre `has_descriptors()` must be true.")
    .def("mutable_descriptor", static_cast<::Eigen::Ref<Eigen::Matrix<float, -1, 1, 0, -1, 1>, 0, Eigen::InnerStride<1>> ( ::drake::perception::PointCloud::* )( int )>(&::drake::perception::PointCloud::mutable_descriptor), py::arg("i"), "/// Returns mutable access to a descriptor value. \
/// @pre `has_descriptors()` must be true.", py::return_value_policy::reference_internal)
    .def("SetFrom", static_cast<void ( ::drake::perception::PointCloud::* )( ::drake::perception::PointCloud const &,::drake::perception::pc_flags::Fields,bool )>(&::drake::perception::PointCloud::SetFrom), py::arg("other"), py::arg("fields_in") = ::drake::perception::pc_flags::Fields(drake::perception::pc_flags::kInherit), py::arg("allow_resize") = bool(true), "/// Copies all points from another point cloud. \
/// @param other \
///    Other point cloud. \
/// @param fields_in \
///    Fields to copy. If this is `kInherit`, then both clouds must have the \
///    exact same fields. Otherwise, both clouds must support the fields \
///    indicated this parameter. \
/// @param allow_resize \
///    Permit resizing to the other cloud's size.")
    .def("Expand", static_cast<void ( ::drake::perception::PointCloud::* )( int,bool )>(&::drake::perception::PointCloud::Expand), py::arg("add_size"), py::arg("skip_initialization") = bool(false), "/// Adds `add_size` default-initialized points. \
/// @param add_size \
///    Number of points to add. \
/// @param skip_initialization \
///    Do not require that the new values be initialized.")
    .def("HasFields", static_cast<bool ( ::drake::perception::PointCloud::* )( ::drake::perception::pc_flags::Fields )const>(&::drake::perception::PointCloud::HasFields), py::arg("fields_in"), "/// Returns if a point cloud has a given set of fields.")
    .def("RequireFields", static_cast<void ( ::drake::perception::PointCloud::* )( ::drake::perception::pc_flags::Fields )const>(&::drake::perception::PointCloud::RequireFields), py::arg("fields_in"), "/// Requires a given set of fields. \
/// @see HasFields for preconditions. \
/// @throws std::runtime_error if this point cloud does not have these \
/// fields.")
    .def("HasExactFields", static_cast<bool ( ::drake::perception::PointCloud::* )( ::drake::perception::pc_flags::Fields )const>(&::drake::perception::PointCloud::HasExactFields), py::arg("fields_in"), "/// Returns if a point cloud has exactly a given set of fields. \
/// @see HasFields for preconditions.")
    .def("RequireExactFields", static_cast<void ( ::drake::perception::PointCloud::* )( ::drake::perception::pc_flags::Fields )const>(&::drake::perception::PointCloud::RequireExactFields), py::arg("field_set"), "/// Requires the exact given set of fields. \
/// @see HasFields for preconditions. \
/// @throws std::runtime_error if this point cloud does not have exactly \
/// these fields.")
    .def_readonly_static("kDefaultColor", &::drake::perception::PointCloud::kDefaultColor)
    .def_readonly_static("kDefaultValue", &::drake::perception::PointCloud::kDefaultValue)
    
    ;
}
