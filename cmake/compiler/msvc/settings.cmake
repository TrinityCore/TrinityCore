# set up output paths for executable binaries (.exe-files, and .dll-files on DLL-capable platforms)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(MSVC_EXPECTED_VERSION 19.0.24210) # MSVC 2015 Update 3

if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS MSVC_EXPECTED_VERSION)
  message(FATAL_ERROR "MSVC: TrinityCore requires version ${MSVC_EXPECTED_VERSION} (MSVC 2015 Update 3) to build but found ${CMAKE_CXX_COMPILER_VERSION}")
endif()

# set up output paths ofr static libraries etc (commented out - shown here as an example only)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(PLATFORM EQUAL 64)
  # This definition is necessary to work around a bug with Intellisense described
  # here: http://tinyurl.com/2cb428.  Syntax highlighting is important for proper
  # debugger functionality.
  add_definitions("-D_WIN64")
  message(STATUS "MSVC: 64-bit platform, enforced -D_WIN64 parameter")

else()
  # mark 32 bit executables large address aware so they can use > 2GB address space
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /LARGEADDRESSAWARE")
  message(STATUS "MSVC: Enabled large address awareness")

  add_definitions(/arch:SSE2)
  message(STATUS "MSVC: Enabled SSE2 support")

  set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} /SAFESEH:NO")
  message(STATUS "MSVC: Disabled Safe Exception Handlers for debug builds")
endif()

# Set build-directive (used in core to tell which buildtype we used)
# msbuild/devenv don't set CMAKE_MAKE_PROGRAM, you can choose build type from a dropdown after generating projects
if("${CMAKE_MAKE_PROGRAM}" MATCHES "MSBuild")
  add_definitions(-D_BUILD_DIRECTIVE=\\"$(ConfigurationName)\\")
else()
  # while all make-like generators do (nmake, ninja)
  add_definitions(-D_BUILD_DIRECTIVE=\\"${CMAKE_BUILD_TYPE}\\")
endif()

# multithreaded compiling on VS
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")

if((PLATFORM EQUAL 64) OR (NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 19.0.23026.0) OR BUILD_SHARED_LIBS)
  # Enable extended object support
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
  message(STATUS "MSVC: Enabled increased number of sections in object files")
endif()

# /Zc:throwingNew.
# When you specify Zc:throwingNew on the command line, it instructs the compiler to assume
# that the program will eventually be linked with a conforming operator new implementation,
# and can omit all of these extra null checks from your program.
# http://blogs.msdn.com/b/vcblog/archive/2015/08/06/new-in-vs-2015-zc-throwingnew.aspx
if(NOT (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 19.0.23026.0))
  # makes this flag a requirement to build TC at all
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:throwingNew")
endif()

# Define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES - eliminates the warning by changing the strcpy call to strcpy_s, which prevents buffer overruns
add_definitions(-D_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES)
message(STATUS "MSVC: Overloaded standard names")

# Ignore warnings about older, less secure functions
add_definitions(-D_CRT_SECURE_NO_WARNINGS)
message(STATUS "MSVC: Disabled NON-SECURE warnings")

# Ignore warnings about POSIX deprecation
add_definitions(-D_CRT_NONSTDC_NO_WARNINGS)
message(STATUS "MSVC: Disabled POSIX warnings")

# Ignore specific warnings
# C4351: new behavior: elements of array 'x' will be default initialized
# C4091: 'typedef ': ignored on left of '' when no variable is declared
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4351 /wd4091")

if(NOT WITH_WARNINGS)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /wd4996 /wd4355 /wd4244 /wd4985 /wd4267 /wd4619 /wd4512")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4996 /wd4355 /wd4244 /wd4985 /wd4267 /wd4619 /wd4512")
  message(STATUS "MSVC: Disabled generic compiletime warnings")
endif()

if (BUILD_SHARED_LIBS)
  # C4251: needs to have dll-interface to be used by clients of class '...'
  # C4275: non dll-interface class ...' used as base for dll-interface class '...'
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4251 /wd4275")
  message(STATUS "MSVC: Enabled shared linking")
endif()

# Specify the maximum PreCompiled Header memory allocation limit
# Fixes a compiler-problem when using PCH - the /Ym flag is adjusted by the compiler in MSVC2012, hence we need to set an upper limit with /Zm to avoid discrepancies)
# (And yes, this is a verified , unresolved bug with MSVC... *sigh*)
string(REGEX REPLACE "/Zm[0-9]+ *" "" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zm500")

# Enable and treat as errors the following warnings to easily detect virtual function signature failures:
# 'function' : member function does not override any base class virtual member function
# 'virtual_function' : no override available for virtual member function from base 'class'; function is hidden
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /we4263 /we4264")

# Disable incremental linking in debug builds.
# To prevent linking getting stuck (which might be fixed in a later VS version).
macro(DisableIncrementalLinking variable)
  string(REGEX REPLACE "/INCREMENTAL *" "" ${variable} "${${variable}}")
  set(${variable} "${${variable}} /INCREMENTAL:NO")
endmacro()

DisableIncrementalLinking(CMAKE_EXE_LINKER_FLAGS_DEBUG)
DisableIncrementalLinking(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO)
DisableIncrementalLinking(CMAKE_SHARED_LINKER_FLAGS_DEBUG)
DisableIncrementalLinking(CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO)
