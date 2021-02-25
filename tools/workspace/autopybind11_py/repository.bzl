# -*- python -*-

load("@drake//tools/workspace:github.bzl", "github_archive")

def autopybind11_py_repository(
        name,
        mirrors = None):
    github_archive(
        name = name,
        # Temporary branch
        repository = "autopybind11/autopybind11",
        commit = "master",
        sha256 = "7ec7001c215d800e27b0ac4b9c744f934fd177ce0c2111813995cbdc11c2e4e6",  # noqa
        build_file = "@drake//tools/workspace/autopybind11_py:package.BUILD.bazel",  # noqa
        mirrors = {
            "github": ["https://gitlab.kitware.com/{repository}/-/archive/{commit}/autopybind11-{commit}.tar.gz"],  # noqa
        },
    )
