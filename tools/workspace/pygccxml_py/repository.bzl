# -*- python -*-

load("@drake//tools/workspace:github.bzl", "github_archive")

def pygccxml_py_repository(
        name,
        mirrors = None):
    github_archive(
        name = name,
        repository = "CastXML/pygccxml",
        # Need bleeding edge from `develop` for C++17 support and comment capturing.
        commit = "ad6345c88932ce76fb1514abdafa49f856be42f6",
        sha256 = "a31f8be5b31c0b21828580c6009a65ad91b376c492902528061d99998ea71028",  # noqa
        build_file = "@drake//tools/workspace/pygccxml_py:package.BUILD.bazel",
        mirrors = mirrors,
    )
