cotire
======

Cotire (compile time reducer) is a CMake module that speeds up the build process of CMake based
build systems by fully automating techniques as [precompiled header][pch] usage and
[single compilation unit][scu] builds for C and C++.

features
--------

* Non-intrusive. Requires no source code modification and only minimal changes to CMake list files.
* Automatically generates a [single compilation unit][scu] (aka unity source file) for a CMake target.
* Automatically generates a [prefix header][pfh] by tracking includes used by a CMake target.
* Automatically precompiles prefix header and applies resulting [precompiled header][pch] to a CMake target.
* Alternatively, allows for using manually maintained unity source and prefix header files.
* Supports C/C++ compilers Clang, GCC, Intel and Visual Studio C++.
* Supports mixed language CMake targets.
* Supports console (Makefile generator) and IDE (Visual Studio and Xcode) based builds.
* Compatible with CMake single build type and CMake multi-configuration builds.
* Compatible with most CMake generators (including [Ninja][ninja]).
* Supports multi-core unity builds for some generators (make -j, [jom][jom], Visual Studio, Ninja).
* Leverages native precompiled header generation features of IDEs (Visual Studio and Xcode).
* Compatible with CMake's [cross-compiling][ccrc] support.
* Compatible with compiler wrappers like [ccache][ccch].
* Applicable to CMake based Qt projects.
* Tested with Windows, Linux and OS X.
* MIT licensed.

requirements
------------

* [CMake 2.8.12][cmk] or newer. The executable `cmake` should be on the system path.
* [Visual Studio C++][vslstd], [MinGW][mingw] or [Cygwin][cgwn] under Windows.
* [GCC][gcc] or [Clang][clang] under Linux or OS X.
* [Intel C++ compiler][intel] under Windows, Linux or OS X.
* [Xcode][xcdt] application or Xcode Command Line Tools under OS X.

installation
------------

Copy the file `CMake/cotire.cmake` to the module directory of your CMake project. In the
top-level `CMakeList.txt` file, add the module directory to the CMake module search path:

    set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")

usage
-----

To use cotire in your CMake project, add the following include directive to the beginning of the
top-level `CMakeList.txt`:

    include(cotire)

To speed the build process of a CMake library or executable target, just apply the `cotire`
function to the target:

    add_executable(MyExecutable ${MyExecutableSources})
    target_link_libraries(MyExecutable ${MyExecutableLibraries})
    cotire(MyExecutable)

Cotire looks at the properties of the target provided by CMake (e.g., target type, source files,
compile flags, preprocessor defines, include directories, ...) and sets up custom commands that
will generate a unity source file, a prefix header and a precompiled header at build time
specially tailored to the target.

For the generation of the prefix header, cotire will automatically choose headers used by the
target that are outside of the project directory and thus are likely to change infrequently.
The precompiled prefix header is then applied to the target to speed up the compilation process.

To use an existing manually maintained prefix header instead of the automatically generated one,
set the `COTIRE_CXX_PREFIX_HEADER_INIT` property before invoking cotire:

    set_target_properties(MyExecutable PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "stdafx.h")
    cotire(MyExecutable)

As a side effect, cotire generates a new target named `MyExecutable_unity`, which lets you perform
a unity build for the original target. The unity target inherits all build settings from the
original target, including linked library dependencies.

For Makefile based generators you can then invoke a unity build that produces the same output as
the original target, but does so much faster by entering:

    $ make MyExecutable_unity

See the advanced usage section of the [cotire manual][manual] for information on how to
configure the cotire process (e.g., how to make the unity build use all available processor
cores).

The directory `Patches` contains patch files to enable cotire for some popular open sources
packages that use CMake as a build system.

speedup
-------

Depending on factors like hardware, compiler, the number of files in the target and the complexity
of the C/C++ code, the build process of targets that use a cotire generated precompiled header
will be sped up from 10 to 40 percent. Using precompiled headers however is not without
[issues][PCHH] and may not work for some programs.

A unity build may be up to 90 percent faster than the one file at a time build of the original
target. Single compilation unit builds however are very unlikely to work without source code
modifications, because they [break][EoUB] the use of some C and C++ language features.

Generally, modern C++ code which makes heavy use of header-only libraries will profit the most from
cotiring.

This [blog post][shrp] discusses speedup results obtained for real-world projects.

known issues
------------

* CMake configure time will increase for cotired targets.
* The size of the CMake build folder will increase, because precompiled headers are large binaries.
* It is not possible to share precompiled headers generated by cotire between CMake targets.
  Multiple targets can share a generated prefix header, though (see the [cotire manual][manual]).
* Cotire is not compatible with [Xoreax IncrediBuild][XGE].

[ccch]:https://ccache.samba.org/
[ccrc]:https://cmake.org/Wiki/CMake_Cross_Compiling
[cgwn]:http://www.cygwin.com/
[clang]:http://clang.llvm.org/
[cmk]:https://cmake.org/download/
[gcc]:https://gcc.gnu.org/
[manual]:https://github.com/sakra/cotire/blob/master/MANUAL.md
[mingw]:http://www.mingw.org/
[ninja]:https://ninja-build.org/
[pch]:https://en.wikipedia.org/wiki/Precompiled_header
[pfh]:https://en.wikipedia.org/wiki/Prefix_header
[scu]:https://en.wikipedia.org/wiki/Single_Compilation_Unit
[vslstd]:https://www.visualstudio.com/
[xcdt]:https://developer.apple.com/xcode/
[PCHH]:https://gcc.gnu.org/wiki/PCHHaters
[EoUB]:https://engineering-game-dev.com/2009/12/15/the-evils-of-unity-builds/
[jom]:http://wiki.qt.io/Jom
[intel]:https://software.intel.com/en-us/c-compilers
[XGE]:https://www.incredibuild.com/
[shrp]:http://unriskinsight.blogspot.co.at/2014/09/sharpen-your-tools.html
