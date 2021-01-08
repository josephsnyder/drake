"""
This provides a very concrete usage of `autopybind11` to be used for Drake
symbols during development under Bazel.

Please see the neighboring README.md for more information.
"""

from contextlib import contextmanager
import argparse
import tarfile
from tempfile import TemporaryDirectory
import os
import sys
from subprocess import run, PIPE, STDOUT

# TODO(eric.cousineau): Use Bazel's runfiles / Rlocation for proper resource
# finding.
from drake.tools.lint.find_data import find_data


@contextmanager
def extract_archive_tempdir(archive, *, dir=None, prefix=None):
    """
    Extracts an archive to a temporary directory.

    If `dir` is None, then it will try to resolve to $TEST_TMPDIR.
    """
    if dir is None:
        dir = os.environ.get("TEST_TMPDIR")
    with TemporaryDirectory(dir=dir, prefix=prefix) as tmp_dir:
        with tarfile.open(archive, "r") as tar:
            tar.extractall(path=tmp_dir)
            yield str(tmp_dir)


def run_autopybind11(output_dir):
    castxml_bin = find_data("external/castxml/castxml_bin")
    config_file = find_data("bindings/pydrake/autopybind11_example.yaml")
    response_file = find_data("bindings/pydrake/autopybind11_example.rsp")
    headers_tar = find_data("bindings/pydrake/autopybind11_example_headers.tar")

    if not os.path.isdir(output_dir):
        os.makedirs(output_dir)

    argv = [
        sys.executable,
        "-m",
        "autopybind11",
        "--stage=2",
        "--module_name=pydrake",
        "--castxml",
        castxml_bin,
        "-o",
        output_dir,
        "-y",
        config_file,
        "-rs",
        response_file,
    ]

    # Since we're connecting a genrule with a proper binary, we must "simulate"
    # the genfiles directory.
    with extract_archive_tempdir(headers_tar) as headers_dir:
        result = run(
            argv, cwd=headers_dir, stdout=PIPE, stderr=STDOUT,
            encoding="utf8",
            env=os.environ.copy(),
        )

    if result.returncode != 0:
        print(f"Failure for: {argv}", file=sys.stderr)
        print(result.stdout, file=sys.stderr)
        sys.exit(1)
    print(f"Wrote files to: {output_dir}")


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--output_dir", type=str, required=True,
        help="Outputs all generated artifcats this directory. Creates the "
             "directory if it does not exist.")
    args = parser.parse_args()
    run_autopybind11(args.output_dir)


if __name__ == "__main__":
    main()
