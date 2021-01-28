# -*- python -*-

load("@drake//tools/workspace:github.bzl", "github_archive")

def autopybind11_py_repository(
        name,
        mirrors = None):
    github_archive(
        name = name,
        repository = "autopybind11/autopybind11",
        # DNM Unmerged PR: https://gitlab.kitware.com/autopybind11/autopybind11/-/merge_requests/121
        commit = "bf45caec52c65d2bf6d8d493393e2fbd408c1544",
        sha256 = "2a66e2f2bcd9f137f37ce1e1d48838e6c542cfb34d90d78b572fb44d2d6ccb7b",  # noqa
        build_file = "@drake//tools/workspace/autopybind11_py:package.BUILD.bazel",  # noqa
        mirrors = {
            "github": ["https://gitlab.kitware.com/{repository}/-/archive/{commit}/autopybind11-{commit}.tar.gz"],  # noqa
        },
    )
