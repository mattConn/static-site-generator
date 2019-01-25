# static-site-generator
Another static site generator.

## Usage
`static-site-generator filepath` will write result to stdout.

To include files, use the typical C/C++ include directive `#include filepath`.

## Building
Run `make`. Currently compiling with `clang++` and C++11 standards. The binary will be in `bin`.

Compiled successfully on Mac OS and Debian Linux. I haven't tried it on Windows yet.

## This program is partially complete
This program will successfully include files in the your current working directory or in one directory above.

If a file a directory above tries to include something with a relative path, the program will fail to include it and write this error to stdout.
