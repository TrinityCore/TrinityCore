set(MSVC_EXPECTED_VERSION 19.32)
set(MSVC_EXPECTED_VERSION_STRING "Microsoft Visual Studio 2022 17.2")

# This file is also used by compilers that pretend to be MSVC but report their own version number - don't version check them
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS MSVC_EXPECTED_VERSION)
    message(FATAL_ERROR "MSVC: TrinityCore requires version ${MSVC_EXPECTED_VERSION} (${MSVC_EXPECTED_VERSION_STRING}) to build but found ${CMAKE_CXX_COMPILER_VERSION}")
  else()
    message(STATUS "MSVC: Minimum version required is ${MSVC_EXPECTED_VERSION}, found ${CMAKE_CXX_COMPILER_VERSION} - ok!")
  endif()
endif()

# CMake sets warning flags by default, however we manage it manually
# for different core and dependency targets
string(REGEX REPLACE "/W[0-4] " "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
# Search twice, once for space after /W argument,
# once for end of line as CMake regex has no \b
string(REGEX REPLACE "/W[0-4]$" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
string(REGEX REPLACE "/W[0-4] " "" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
string(REGEX REPLACE "/W[0-4]$" "" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

target_compile_options(trinity-warning-interface
  INTERFACE
    /W3)

# disable permissive mode to make msvc more eager to reject code that other compilers don't already accept
target_compile_options(trinity-compile-option-interface
  INTERFACE
    /permissive-)

if(PLATFORM EQUAL 32)
  # mark 32 bit executables large address aware so they can use > 2GB address space
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /LARGEADDRESSAWARE")
  message(STATUS "MSVC: Enabled large address awareness")

  target_compile_options(trinity-compile-option-interface
    INTERFACE
      /arch:SSE2)
  message(STATUS "MSVC: Enabled SSE2 support")

  set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} /SAFESEH:NO")
  message(STATUS "MSVC: Disabled Safe Exception Handlers for debug builds")
endif()

if("${CMAKE_MAKE_PROGRAM}" MATCHES "MSBuild")
  # multithreaded compiling on VS
  target_compile_options(trinity-compile-option-interface
    INTERFACE
      /MP)
else()
  # Forces writes to the PDB file to be serialized through mspdbsrv.exe (/FS)
  # Enable faster PDB generation in parallel builds by minimizing RPC calls to mspdbsrv.exe (/Zf)
  target_compile_options(trinity-compile-option-interface
    INTERFACE
      $<$<CONFIG:Debug,RelWithDebInfo>:/FS /Zf>)
endif()

if((PLATFORM EQUAL 64) OR (NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 19.0.23026.0) OR BUILD_SHARED_LIBS)
  # Enable extended object support
  target_compile_options(trinity-compile-option-interface
    INTERFACE
      /bigobj)

  message(STATUS "MSVC: Enabled increased number of sections in object files")
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  # /Zc:throwingNew.
  # When you specify Zc:throwingNew on the command line, it instructs the compiler to assume
  # that the program will eventually be linked with a conforming operator new implementation,
  # and can omit all of these extra null checks from your program.
  # http://blogs.msdn.com/b/vcblog/archive/2015/08/06/new-in-vs-2015-zc-throwingnew.aspx
  target_compile_options(trinity-compile-option-interface
    INTERFACE
      /Zc:throwingNew)
endif()

# Define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES - eliminates the warning by changing the strcpy call to strcpy_s, which prevents buffer overruns
target_compile_definitions(trinity-compile-option-interface
  INTERFACE
    _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES)
message(STATUS "MSVC: Overloaded standard names")

# Ignore warnings about older, less secure functions
target_compile_definitions(trinity-compile-option-interface
  INTERFACE
    _CRT_SECURE_NO_WARNINGS)
message(STATUS "MSVC: Disabled NON-SECURE warnings")

# Ignore warnings about POSIX deprecation
target_compile_definitions(trinity-compile-option-interface
  INTERFACE
    _CRT_NONSTDC_NO_WARNINGS)

# Force math constants like M_PI to be available
target_compile_definitions(trinity-compile-option-interface
  INTERFACE
    _USE_MATH_DEFINES)

message(STATUS "MSVC: Disabled POSIX warnings")

# Ignore specific warnings
target_compile_options(trinity-compile-option-interface
  INTERFACE
    /wd4351  # C4351: new behavior: elements of array 'x' will be default initialized
    /wd4091) # C4091: 'typedef ': ignored on left of '' when no variable is declared

if(NOT WITH_WARNINGS)
  target_compile_options(trinity-compile-option-interface
    INTERFACE
      /wd4996  # C4996 deprecation
      /wd4985  # C4985 'symbol-name': attributes not present on previous declaration.
      /wd4244  # C4244 'argument' : conversion from 'type1' to 'type2', possible loss of data
      /wd4267  # C4267 'var' : conversion from 'size_t' to 'type', possible loss of data
      /wd4619  # C4619 #pragma warning : there is no warning number 'number'
      /wd4512) # C4512 'class' : assignment operator could not be generated

  message(STATUS "MSVC: Disabled generic compiletime warnings")
endif()

if(BUILD_SHARED_LIBS)
  target_compile_options(trinity-compile-option-interface
    INTERFACE
      /wd4251  # C4251: needs to have dll-interface to be used by clients of class '...'
      /wd4275) # C4275: non dll-interface class ...' used as base for dll-interface class '...'

  message(STATUS "MSVC: Enabled shared linking")
endif()

# Move some warnings that are enabled for other compilers from level 4 to level 3
target_compile_options(trinity-compile-option-interface
  INTERFACE
    /w34100  # C4100 'identifier' : unreferenced formal parameter
    /w34101  # C4101: 'identifier' : unreferenced local variable
    /w34189  # C4189: 'identifier' : local variable is initialized but not referenced
    /w34389  # C4389: 'equality-operator' : signed/unsigned mismatch
	/w35054) # C5054: 'operator 'operator-name': deprecated between enumerations of different types'

# Enable and treat as errors the following warnings to easily detect virtual function signature failures:
# 'function' : member function does not override any base class virtual member function
# 'virtual_function' : no override available for virtual member function from base 'class'; function is hidden
target_compile_options(trinity-compile-option-interface
  INTERFACE
    /we4263
    /we4264)

if(ASAN)
  target_compile_definitions(trinity-compile-option-interface
    INTERFACE
      _DISABLE_STRING_ANNOTATION
      _DISABLE_VECTOR_ANNOTATION)

  target_compile_options(trinity-compile-option-interface
    INTERFACE
      /fsanitize=address)

  message(STATUS "MSVC: Enabled Address Sanitizer ASan")
endif()

# Disable incremental linking in debug builds.
# To prevent linking getting stuck (which might be fixed in a later VS version).
macro(DisableIncrementalLinking variable)
  string(REGEX REPLACE "/INCREMENTAL *" "" ${variable} "${${variable}}")
  set(${variable} "${${variable}} /INCREMENTAL:NO")
endmacro()

# Disable Visual Studio 2022 build process management
# This will make compiler behave like in 2019 - compiling num_cpus * num_projects at the same time
# it is neccessary because of a bug in current implementation that makes scripts build only a single
# file at the same time after game project finishes building
if (NOT MSVC_TOOLSET_VERSION LESS 143)
  file(COPY "${CMAKE_CURRENT_LIST_DIR}/Directory.Build.props" DESTINATION "${CMAKE_BINARY_DIR}")
endif()

DisableIncrementalLinking(CMAKE_EXE_LINKER_FLAGS_DEBUG)
DisableIncrementalLinking(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO)
DisableIncrementalLinking(CMAKE_SHARED_LINKER_FLAGS_DEBUG)
DisableIncrementalLinking(CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO)
