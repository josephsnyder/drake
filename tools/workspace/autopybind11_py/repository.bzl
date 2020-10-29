# -*- python -*-

load("@drake//tools/workspace:github.bzl", "github_archive")

def autopybind11_py_repository(
        name,
        mirrors = None):
    github_archive(
        name = name,
        repository = "autopybind11/autopybind11",
        commit = "99c004f7f78bfd90eab719927520bb01d7a11c41",
        sha256 = "e465864a241ff89f18dda2bf2505520981c7c14626eb7c1562711ad3a651bea4",  # noqa
        build_file = "@drake//tools/workspace/autopybind11_py:package.BUILD.bazel",  # noqa
        mirrors = {
            "github": ["https://gitlab.kitware.com/{repository}/-/archive/{commit}/autopybind11-{commit}.tar.gz"],  # noqa
        },
    )
