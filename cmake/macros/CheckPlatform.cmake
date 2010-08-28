# default to x86 platform.  We'll check for X64 in a bit
set(PLATFORM X86)

if(CMAKE_SIZEOF_VOID_P MATCHES 8)
    set(PLATFORM X64)
    MESSAGE(STATUS "Detected 64-bit platform")
else()
    MESSAGE(STATUS "Detected 32-bit platform")
endif()

include("${CMAKE_SOURCE_DIR}/cmake/platform/settings.cmake")

if(WIN32)
  include("${CMAKE_SOURCE_DIR}/cmake/platform/settings.win32.cmake")
elseif(APPLE)
  include("${CMAKE_SOURCE_DIR}/cmake/platform/settings.osx.cmake")
elseif(UNIX)
  include("${CMAKE_SOURCE_DIR}/cmake/platform/settings.unix.cmake")
endif()
