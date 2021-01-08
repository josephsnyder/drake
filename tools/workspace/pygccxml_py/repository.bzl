# -*- python -*-

load("@drake//tools/workspace:github.bzl", "github_archive")

def pygccxml_py_repository(
        name,
        mirrors = None):
    github_archive(
        name = name,
        repository = "CastXML/pygccxml",
        # Need bleeding edge from `develop` for C++17
        # support and comment capturing.
        commit = "5f42a00933ac2cd45a62f2e034e1706e46e0bd36",
        sha256 = "52c8419bdeea52876d28191bfe8088886deeb386c5f813fdc5da18c492b5c009",  # noqa
        build_file = "@drake//tools/workspace/pygccxml_py:package.BUILD.bazel",
        mirrors = mirrors,
    )
