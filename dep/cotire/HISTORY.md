## 1.7.10 (2017-06-16)

* CMake 3.8 compatibility.
* CMake 3.8.0 Qt automoc support (thanks bilke).
* fix Xcode recompiling every time builds happen (thanks gcamp).
* disable PCH messages when `-Wno-pch-messages` flag exists (thanks kbinani).
* work around ccache incompatibility with newer versions of GCC and Clang.
* fix MinGW incompatibility with `BUILD_INTERFACE` generator expression.
* fix handling of `CMAKE_INCLUDE_FLAG_SEP_<LANG>` variables.

## 1.7.9 (2016-12-08)

* CMake 3.6 and 3.7 compatibility.
* fix ccache 3.2 compatibility issues.
* fix bugs with handling language standard related properties (e.g., `CXX_STANDARD`, `CXX_EXTENSIONS`).
* make prefix header generation and precompiled header compilation depend on the compiler executable.
* fix Qt automoc handling for Windows (thanks jcelerier).
* convert Windows paths in include directories to CMake paths (thanks wdx04).
* replace object library with corresponding unity object library when using `COPY_UNITY` linking strategy.
* better error reporting from prefix header generation.
 
## 1.7.8 (2016-03-27)

* fix `COPY_UNITY` linking strategy for private link dependencies.
* honor `CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE` upon handling of target usage requirements.
* reworked setting up of `LINK_LIBRARIES` and `INTERFACE_LINK_LIBRARIES` properties for unity targets.

## 1.7.7 (2016-03-20)

* CMake 3.5 compatibility.
* fix bugs related to handling of interface libraries.
* output shorter log messages when using Visual Studio IDE.
* don't disable PCH if CMAKE_<LANG>_COMPILER_ID is not set (thanks jcelerier).
* add support for compiler launchers introduced in CMake 3.4 (thanks misery).

## 1.7.6 (2015-12-06)

* fix CMake 3.4 compatibility issues.
* prevent redundant re-generation of prefix header when a target has generated source files.

## 1.7.5 (2015-10-27)

* handle visibility target properties (`CXX_VISIBILITY_PRESET` and `VISIBILITY_INLINES_HIDDEN`).
* better handling of include directories and system include directories.
* parse additional system include directories from target compile flags.
* activate select CMake policies.

## 1.7.4 (2015-10-10)

* set up single unity source file for prefix header generation.
* increase MSVC default PCH memory to 128M.
* remove obsolete code.

## 1.7.3 (2015-07-25)

* handle language standard target properties (e.g., `CXX_STANDARD`).
* apply user provided prefix header to unity build target.
* remove effect of `COTIRE_MINIMUM_NUMBER_OF_TARGET_SOURCES` on generated unity target.
* manual updates.

## 1.7.2 (2015-04-22)

* reduce configure time overhead.
* fix bug with dependency checking when using Xcode.
* remove obsolete code required for CMake versions older than 2.8.12.
* streamline debugging output.

## 1.7.1 (2015-04-06)

* fix problem with CMake's automatic Qt processing for generated unity targets.
* added a section on common pitfalls when using cotire to the manual.
* remove obsolete code required for CMake versions older than 2.8.12.
* streamline debugging output.
* activate select CMake policies.

## 1.7.0 (2015-03-29)

* fix CMake 3.2 compatibility issues.
* cotire now requires CMake 2.8.12 or newer.
* copy `IMPORT_PREFIX` and `IMPORT_SUFFIX` target properties for unity targets (thanks peterhuene).
* new property `COTIRE_PREFIX_HEADER_INCLUDE_PRIORITY_PATH` allows for organizing includes
  added to the prefix header by priority (thanks ArnaudD-FR).
* for Visual Studio C++, increase static precompiled header memory allocation.
* the default strategy for setting up a unity target's linked libraries is now `COPY_UNITY`.
* for Qt projects, fix problem with handling of `AUTOMOC` in generated unity target.
* fix problem with generating the cotire intermediate directory.
* documentation updates.

## 1.6.9 (2015-01-18)

* fix bug with parsing of localized MSVC `/showIncludes` output.

## 1.6.8 (2014-12-28)

* fix bug with generation of unity source file segments for parallel builds.

## 1.6.7 (2014-12-21)

* fix CMake 3.1 compatibility issues.
* fix ccache 3.2 compatibility issues.
* handle `COTIRE_MINIMUM_NUMBER_OF_TARGET_SOURCES` correctly for mixed-language targets.
* correctly compute absolute paths of generated source files added to the unity source file.
* fix bug with checking unity source and prefix header dependencies under Xcode.
* fix bug with handling of unity source file dependencies.
* move code to determine build configurations to function of its own.
* documentation updates.

## 1.6.6 (2014-09-21)

* fix GCC issue with prefix header generation when source files are missing.
* fix bug where some target properties were not properly propagated to the generated unity target.
* use `target_link_libraries` to set up the unity target link libraries.
* add Qt4 and Qt5 examples to the `Patches` directory.
* documentation updates.

## 1.6.5 (2014-08-26)

* correctly handle generator expressions used in compile definitions, compile flags and include
  directories (requires CMake 2.8.12 or newer).
* fix `-isystem` includes being incorrectly passed to `execute_process` (thanks nickhutchinson).
* make some error messages more verbose.

## 1.6.4 (2014-07-14)

* fix CMake 3.0 compatibility issues.
* preserve system flag for includes when generating PCH (thanks gjasny).
* fix bug with setting up `EXPORTS` symbol for shared libraries.

## 1.6.3 (2014-06-11)

* correctly handle usage requirements for transitive link targets.
* use indirect inclusion for prefix header when using generator Xcode.

## 1.6.2 (2014-06-09)

* don't use `-w` flag for pre-compiling the prefix header, because it has unwanted side effects.
* correctly handle linked targets' `INTERFACE_COMPILE_OPTIONS`, `INTERFACE_INCLUDE_DIRECTORIES`
  and `INTERFACE_COMPILE_DEFINITIONS` properties upon pre-compiling and prefix header generation.
* For Clang and GCC, pre-compile prefix header through indirect inclusion via a prefix source file,
  to make both compilers honor the `system_header` pragma in the prefix header correctly.
* fix ccache incompatibility.

## 1.6.1 (2014-04-20)

* fixed bug where precompiled headers did not work with Clang (thanks to nh2 for reporting).
* when using ccache, require that environment variable `CCACHE_SLOPPINESS` is set to `time_macros`.

## 1.6.0 (2014-03-16)

* suppress compiler warnings from precompiled headers.
* fix Clang compatibility issue with prefix header generation.
* use file extension `.pch` for precompiled headers generated with Clang.
* manual updates.

## 1.5.2 (2014-01-17)

* honor framework includes under OS X correctly.
* fix handling of OS X specific variables `CMAKE_OSX_SYSROOT` and `CMAKE_OSX_DEPLOYMENT_TARGET`.
* add new examples to the `Patches` directory.

## 1.5.1 (2013-11-12)

* fixed string quoting bugs.

## 1.5.0 (2013-10-13)

* CMake 2.8.12 compatibility fixes.
* Upon generation of a unity target, cotire can now be configured to automatically copy all the
  linked libraries and targets from the original target. See the section on the new target property
  `COTIRE_UNITY_LINK_LIBRARIES_INIT` in the cotire manual.
* fixed bug with copying target properties to generated unity target.
* cotire manual updates.
* add new examples to the `Patches` directory.
* fix typos.

## 1.4.3 (2013-09-28)

* fixed bug with generation of unity source file when `COTIRE_MINIMUM_NUMBER_OF_TARGET_SOURCES` is
  set to 0.

## 1.4.2 (2013-08-24)

* CMake 2.8.11 compatibility fixes.
* always force the inclusion of a user provided prefix header, even if the target
  contains too few sources to enable the use of a precompiled header.

## 1.4.1 (2013-06-08)

* fixed bug with determination of compiler version.
* fixed bug with generation of unity source when target source files are used for multiple targets.
* fixed bug with multi-core optimized prefix header generation.

## 1.4.0 (2013-03-11)

* one year anniversary release.
* add support for multi-core optimized unity builds for some CMake generators.
* add support for multi-core optimized prefix header generation.
* add more examples to cotire manual.

## 1.3.6 (2013-03-06)

* fix bug with prefix header initialization for generator Xcode.
* print cotire version upon inclusion.

## 1.3.5 (2013-03-01)

* fix typos in function names and property descriptions.

## 1.3.4 (2013-02-07)

* fixed bug with computing to output directory of the generated unity target (thanks shaunew).
* fixed wrong variable reference in debugging output (thanks shaunew).

## 1.3.3 (2013-02-03)

* fixed bug with handling of policy CMP0018 relating to target property `POSITION_INDEPENDENT_CODE`.
* fixed warnings relating to uninitialized variables.
* Intel XE 2013 Update 2 compatibility fixes.

## 1.3.2 (2013-02-02)

* fixed missing curly brace (thanks shaunew).

## 1.3.1 (2013-01-29)

* fix bug with filtering of compile options.

## 1.3.0 (2013-01-09)

* add support for Intel C and C++ compilers.
* CMake 2.8.10 compatibility fixes.
* properly clean up generated cotire log files upon invoking `clean` target.
* documentation updates.

## 1.2.0 (2012-11-01)

* add support for manually maintained prefix header and unity source files.
* the target property `COTIRE_<LANG>_PREFIX_HEADER_INIT` can be set to a user provided prefix
  header file to be used instead of the automatically generated one (e.g., `stdafx.h`).
* the new target property `COTIRE_<LANG>_UNITY_SOURCE_INIT` can be set to a user provided unity
  source file to be used instead of the automatically generated one.
* the target property `COTIRE_UNITY_TARGET_NAME` is no longer read-only. It can be set to the
  desired name of the unity target that will be added by cotire.
* add parameters `SOURCE_DIR` and `BINARY_DIR` to function `cotire` to allow for explicitly
  specifying a target's source and binary directory, if target to be cotired has been added in a
  different directory.

## 1.1.8 (2012-10-27)

* when using MSVC, apply option `/bigobj` to compilation of generated unity files.

## 1.1.7 (2012-10-26)

* cope with double slash characters in scanned include paths.

## 1.1.6 (2012-09-22)

* check result code upon scanning includes.
* always add a `clean_cotire` target to easily clean up cotire generated files.
* add section on `extern "C"` linkage issues to manual.

## 1.1.5 (2012-08-17)

* new cache variable `COTIRE_UNITY_SOURCE_EXCLUDE_EXTENSIONS` can be set to globally exclude
  sources with the listed file extensions from the generated unity source.
* fix check for multi-architecture builds under OS X.

## 1.1.4 (2012-08-15)

* prevent redundant re-generation of the unity source, prefix header and precompiled header files
  (this makes cotire more applicable to C++ projects that use Qt).

## 1.1.3 (2012-08-12)

* fix out of range index operation upon building list of target include directories.
* honor target properties `POSITION_INDEPENDENT_CODE` and `NO_SONAME` introduced with CMake 2.8.9.
* make selection of target source files for requested target language more careful.
* prevent modification of the CMake policy stack upon CMake version check.

## 1.1.2 (2012-05-06)

* make handling of include directories more robust against invalid paths.

## 1.1.1 (2012-04-20)

* fixed bug with generation of unity targets for `WIN32_EXECUTABLE` targets.
* fixed bug with parsing of localized MSVC `/showIncludes` output.

## 1.1.0 (2012-04-19)

* tested with CMake 2.8.8.
* added example to manual that shows how to apply cotire to CMake object library targets.
* fixed multiple bugs with handling of CMake single build type and multiple configuration builds.
* added more robust parsing of localized MSVC `/showIncludes` output.

## 1.0.9 (2012-04-09)

* add support for compiler wrappers like ccache.
* under OS X, apply `CMAKE_OSX_SYSROOT` to prefix header include and ignore paths.

## 1.0.8 (2012-04-05)

* require CMake 2.8.6 since we are using `set_property` option `APPEND_STRING`.

## 1.0.7 (2012-04-02)

* add support for Ninja generator introduced in CMake 2.8.8.
* fix bug with initialization of variable `COTIRE_VERBOSE`.

## 1.0.6 (2012-04-01)

* correctly handle builds where both `CMAKE_BUILD_TYPE` and `CMAKE_CONFIGURATION_TYPES` are set.

## 1.0.5 (2012-03-26)

* fix Visual Studio C++ 2010 compilation of example project.
* enhance heuristic for #include_next directive detection.
* fix llvm-3.0.src.patch for GCC 4.6 compilation.

## 1.0.4 (2012-03-24)

* honor target property INCLUDE_DIRECTORIES introduced in CMake 2.8.8.

## 1.0.3 (2012-03-23)

* handle OBJECT_LIBRARY targets introduced in CMake 2.8.8.
* use predefined compiler version variable, if available.

## 1.0.2 (2012-03-16)

* fix Xcode 4.3 compatibility.
* Cotire manual corrections.

## 1.0.1 (2012-03-15)

* Cotire manual corrections.
* Add prefix header to the generated unity build target.

## 1.0.0 (2012-03-11)

* First release.
