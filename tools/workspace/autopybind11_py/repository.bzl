# -*- python -*-

load("@drake//tools/workspace:github.bzl", "github_archive")

def autopybind11_py_repository(
        name,
        mirrors = None):
    github_archive(
        name = name,
        # Temporary branch
        repository = "autopybind11/autopybind11",
        commit = "1f01929a18014fd8c7868f30ae50526b07295cd3",
        sha256 = "50f28de610031e2a2024d3365d48c419a9c6554d72b6ccd123c8680ec289b7ff",  # noqa
        build_file = "@drake//tools/workspace/autopybind11_py:package.BUILD.bazel",  # noqa
        mirrors = {
            "github": ["https://gitlab.kitware.com/{repository}/-/archive/{commit}/autopybind11-{commit}.tar.gz"],  # noqa
        },
    )
