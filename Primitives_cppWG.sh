#!/bin/bash

# Assumes that one is running this is the drake top-level directory
# and that the cppwg repository has been added to the PYTHONPATH environment variable.
#
# export PYTHONPATH=/<path>/<to>/cppwg:$PATH

/usr/bin/python3 wrapper/generate.py \
  --source_root /home/softhat/Work/TRI/drake/systems/primitives/ \
  --wrapper_root /home/softhat/Work/TRI/drake/wrapper/ \
  --castxml_binary /home/softhat/Work/TRI/castxml/bin/castxml \
  --package_info /home/softhat/Work/TRI/drake/wrapper/package_info.yaml \
  "-i/home/softhat/Work/TRI/drake/bazel-bin/install.runfiles/" \
  "-i/home/softhat/Work/TRI/drake/bazel-bin/install.runfiles/optitrack_driver/lcmtypes/" \
  "-i/home/softhat/Work/TRI/drake/bazel-bin/install.runfiles/lcmtypes_robotlocomotion/lcmtypes/" \
  "-i.." \
  "-icommon/test_utilities" \
  "-i/home/softhat/.cache/bazel/_bazel_softhat/f609cd39646d462a4a64447c03bad13a/external/lcm/" \
  "-i/home/softhat/.cache/bazel/_bazel_softhat/f609cd39646d462a4a64447c03bad13a/external/eigen/" \
  "-i/home/softhat/.cache/bazel/_bazel_softhat/f609cd39646d462a4a64447c03bad13a/external/fmt/include" \
  "-i/home/softhat/.cache/bazel/_bazel_softhat/f609cd39646d462a4a64447c03bad13a/external/spdlog/include" \
  "-i/home/softhat/.cache/bazel/_bazel_softhat/f609cd39646d462a4a64447c03bad13a/external/gtest/googletest/include" \
  "-i/home/softhat/.cache/bazel/_bazel_softhat/f609cd39646d462a4a64447c03bad13a/external/vtk/include/vtk-8.2/" \
  "-isystems" \
  "-isystems/primitives/test" \
  "-isystems/primitives" \
  "-isystems/lcm" \
  "-isystems/plants/spring_mass_system" \
  "-isystems/plants" \
  "-isystems/rendering" \
  "-isystems/sensors" \
  "-isystems/trajectory_optimization" \
  "-isystems/controllers" \
  "-isystems/controllers/test" \
  "-isystems/controllers/test_utilities" \
  "-isystems/analysis/test_utilities" \
  "-isystems/analysis" \
  "-isystems/estimators" \
  "-isystems/framework" \
  "-ilcmtypes" \
  -hf /home/softhat/Work/TRI/drake/systems/primitives/zero_order_hold.h \
  -hf /home/softhat/Work/TRI/drake/systems/primitives/trajectory_affine_system.h \
  -hf /home/softhat/Work/TRI/drake/systems/primitives/trajectory_linear_system.h
