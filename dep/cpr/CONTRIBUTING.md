# Contributing to C++ Requests

Please fork this repository and contribute back using [pull requests](https://github.com/whoshuu/cpr/pulls). Features can be requested using [issues](https://github.com/whoshuu/cpr/issues). All code, comments, and critiques are greatly appreciated.

## Formatting

To avoid unproductive debates on formatting, this project uses `clang-format` to ensure a consistent style across all source files. Currently, `clang-format` 3.8 is the version of `clang-format` we use. The format file can be found [here](https://github.com/whoshuu/cpr/blob/master/.clang-format). To install `clang-format` on Ubuntu, run this:

```
apt-get install clang-format-3.8
```

To install `clang-format` on OS X, run this:

```
brew install clang-format
```

Note that `brew` might install a later version of `clang-format`, but it should be mostly compatible with what's run on the Travis servers.

To run `clang-format` on every source file, run this in the root directory:

```
./format-check.sh
```

This should indicate which files need formatting and also show a diff of the requested changes. More specific usage instructions can be found on the official [LLVM website](http://releases.llvm.org/3.8.0/tools/clang/docs/ClangFormat.html).
