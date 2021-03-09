# -*- python -*-

load("@drake//tools/workspace:github.bzl", "github_archive")

def autopybind11_py_repository(
        name,
        mirrors = None):
    github_archive(
        name = name,
        # Temporary branch
        repository = "autopybind11/autopybind11",
        commit = "71bb87a912514abff6309f56e20e81981927e34a",
        sha256 = "fcf6f653f4892fd8a261455dcd2c5def4b0b9a6db868e7c59efb5799b4eb4439",  # noqa
        build_file = "@drake//tools/workspace/autopybind11_py:package.BUILD.bazel",  # noqa
        mirrors = {
            "github": ["https://gitlab.kitware.com/{repository}/-/archive/{commit}/autopybind11-{commit}.tar.gz"],  # noqa
        },
    )
