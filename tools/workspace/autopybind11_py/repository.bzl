# -*- python -*-

load("@drake//tools/workspace:github.bzl", "github_archive")

def autopybind11_py_repository(
        name,
        mirrors = None):
    github_archive(
        name = name,
        # Temporary branch
        repository = "autopybind11/autopybind11",
        commit = "43d3e3b9a6ab0966dbe5b8ff45695318576eda44",
        sha256 = "10d5a84bf788ffffa1ae4c945b47fdee448ef2511ae9564cd9ff986d700bc88b",  # noqa
        build_file = "@drake//tools/workspace/autopybind11_py:package.BUILD.bazel",  # noqa
        mirrors = {
            "github": ["https://gitlab.kitware.com/{repository}/-/archive/{commit}/autopybind11-{commit}.tar.gz"],  # noqa
        },
    )
