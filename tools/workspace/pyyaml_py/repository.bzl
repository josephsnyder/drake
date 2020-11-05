# -*- python -*-

load("@drake//tools/workspace:pypi.bzl", "pypi_archive")

def pyyaml_repository(
        name,
        mirrors = None):
    pypi_archive(
        name = name,
        package = "PyYAML",
        version = "5.3.1",
        sha256 = "b8eac752c5e14d3eca0e6dd9199cd627518cb5ec06add0de9d32baeee6fe645d",  # noqa
        build_file = "@drake//tools/workspace/pyyaml_py:package.BUILD.bazel",  # noqa
        mirrors = mirrors,
    )
