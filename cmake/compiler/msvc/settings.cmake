# set up output paths for executable binaries (.exe-files, and .dll-files on DLL-capable platforms)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# set up output paths ofr static libraries etc (commented out - shown here as an example only)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# mark 32 bit executables large address aware so they can use > 2GB address space
if(CMAKE_SIZEOF_VOID_P MATCHES 4)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /LARGEADDRESSAWARE")
  message(STATUS "- MSVC: Enabled large address awareness")
endif()

# multithreaded compiling on VS
if((NOT USE_COREPCH) AND (NOT USE_SCRIPTPCH))
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
  message(STATUS "- MSVC: PCH not used - enabled multithreaded compiling")
endif()

if(${PLATFORM} STREQUAL "X64")
  # This definition is necessary to work around a bug with Intellisense described
  # here: http://tinyurl.com/2cb428.  Syntax highlighting is important for proper
  # debugger functionality.
  add_definitions("-D_WIN64")
  message(STATUS "- MSVC: 64-bit platform, enforced -D_WIN64 parameter")

  #Enable extended object support for debug compiles on X64 (not required on X86)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /bigobj")
  message(STATUS "- MSVC: Enabled extended object-support for debug-compiles")
endif()

# Define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES - eliminates the warning by changing the strcpy call to strcpy_s, which prevents buffer overruns
add_definitions(-D_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES)
message(STATUS "- MSVC: Overloaded standard names")

# Ignore warnings about older, less secure functions
add_definitions(-D_CRT_SECURE_NO_WARNINGS)
message(STATUS "- MSVC: Disabled NON-SECURE warnings")

#Ignore warnings about POSIX deprecation
add_definitions(-D_CRT_NONSTDC_NO_WARNINGS)
message(STATUS "- MSVC: Disabled POSIX warnings")

# disable warnings in Visual Studio 8 and above if not wanted
if(NOT WITH_WARNINGS)
  if(MSVC AND NOT CMAKE_GENERATOR MATCHES "Visual Studio 7")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /wd4996 /wd4355 /wd4244 /wd4985 /wd4267 /wd4619")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4996 /wd4355 /wd4244 /wd4985 /wd4267 /wd4619")
    message(STATUS "- MSVC: Disabled generic compiletime warnings")
  endif()
endif()
