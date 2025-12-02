#!/usr/bin/env python3
import os
import sys
import shutil
import subprocess
from pathlib import Path


def find_repo_root() -> Path:
    return Path(__file__).resolve().parent.parent


def find_clang_format() -> str:
    exe = shutil.which("clang-format")
    if exe:
        return exe
    # Fallbacks (rarely needed, but harmless)
    for candidate in ("clang-format.exe", "clang-format-15", "clang-format-16", "clang-format-17", "clang-format-18", "clang-format-19", "clang-format-20", "clang-format-21"):
        exe = shutil.which(candidate)
        if exe:
            return exe
    return ""


def collect_files(root: Path) -> list[Path]:
    targets: list[Path] = []
    extensions = (".c", ".cc", ".cpp", ".h", ".hpp")
    for rel_dir in ("source", "tests"):
        base = root / rel_dir
        if not base.exists():
            continue
        for ext in extensions:
            targets.extend(base.rglob(f"*{ext}"))
    # Ensure stable ordering for deterministic runs
    return sorted({p.resolve() for p in targets})


def main() -> int:
    root = find_repo_root()
    clang_format = find_clang_format()
    if not clang_format:
        print("ERROR: clang-format not found on PATH. Ensure it's installed in the pixi env.", file=sys.stderr)
        return 127

    style_args: list[str] = []
    if (root / ".clang-format").exists():
        style_args = ["--style=file"]

    files = collect_files(root)
    if not files:
        print("No C/C++ source files found under 'source/' or 'tests/'. Nothing to do.")
        return 0

    failures: list[tuple[Path, str]] = []
    for path in files:
        cmd = [clang_format, "-i", *style_args, str(path)]
        try:
            result = subprocess.run(cmd, capture_output=True, text=True)
        except Exception as exc:
            failures.append((path, f"Exception: {exc}"))
            continue
        if result.returncode != 0:
            stderr = (result.stderr or result.stdout or "unknown error").strip()
            failures.append((path, stderr))

    if failures:
        print("clang-format failed for the following files:", file=sys.stderr)
        for p, err in failures:
            print(f" - {p}: {err}", file=sys.stderr)
        return 1

    print(f"Formatted {len(files)} files with clang-format.")
    return 0


if __name__ == "__main__":
    sys.exit(main())


