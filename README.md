# static-site-generator
Another static site generator.

This program currently only stitches together files.

## Usage
`static-site-generator /path/to/file` will write result to stdout.

To include files in one another, use the typical C/C++ include directive `#include some/file.txt` in a file.

## Building
Run `make`. Currently compiling with `clang++` and C++11 standards. The binary will be in `bin`.

Compiled successfully on Mac OS and Debian Linux.
