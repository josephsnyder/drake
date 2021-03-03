# -*- python -*-

load("@drake//tools/workspace:github.bzl", "github_archive")

def autopybind11_py_repository(
        name,
        mirrors = None):
    github_archive(
        name = name,
        # Temporary branch
        repository = "autopybind11/autopybind11",
        commit = "89fecfb3a3c763f6ca63106796ff5c9e6de63872",
        sha256 = "e4293b658d9b5af837ed86a0cd5915eda35c6a0833093ca5bfe9fad1364b839c",  # noqa
        build_file = "@drake//tools/workspace/autopybind11_py:package.BUILD.bazel",  # noqa
        mirrors = {
            "github": ["https://gitlab.kitware.com/{repository}/-/archive/{commit}/autopybind11-{commit}.tar.gz"],  # noqa
        },
    )
