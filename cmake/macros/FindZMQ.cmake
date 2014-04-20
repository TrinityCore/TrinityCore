#
# Find the ZMQ includes and library
# 

# This module defines
# ZMQ_INCLUDE_DIR, where to find zmq.h
# ZMQ_LIBRARY, the library needed to use ZMQ
# ZMQ_FOUND, if false, you cannot build anything that requires ZMQ.

set(ZMQ_FOUND 0)

if (PLATFORM EQUAL 64)
  set(ZMQ_REGISTRY_PATH
    "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\ZeroMQ (x64);DisplayIcon]"
    )
else()
  set(ZMQ_REGISTRY_PATH
    "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\ZeroMQ;DisplayIcon]"
    "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\ZeroMQ;DisplayIcon]"
    )
endif()

find_path(ZMQ_INCLUDE_DIR
  NAMES
    zmq.h
  HINTS
    "${ZMQ_REGISTRY_PATH}/include"
  PATHS
    /usr/include
    /usr/local/include
)

if (MSVC)
  # Read registry key holding version
  if (PLATFORM EQUAL 64)
    get_filename_component(ZMQ_NAME "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\ZeroMQ (x64);DisplayVersion]" NAME)
  else()
    get_filename_component(ZMQ_NAME "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\ZeroMQ;DisplayVersion]" NAME)
    if (${ZMQ_NAME} MATCHES "registry") # if key was not found, the string "registry" is returned
      get_filename_component(ZMQ_NAME "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\ZeroMQ;DisplayVersion]" NAME)
    endif()
  endif()

  # Replace dots with underscores
  string(REGEX REPLACE "\\." "_" ZMQ_NAME ${ZMQ_NAME})

  # Get Visual studio version number
  string(REGEX REPLACE "Visual Studio ([0-9]+).*" "\\1" ZMQ_VS_VERSION ${CMAKE_GENERATOR})

  # Format ZMQ library file name
  set(ZMQ_LIBRARY_NAME "libzmq-v${ZMQ_VS_VERSION}0-mt-${ZMQ_NAME}")
endif()

find_library(ZMQ_LIBRARY
  NAMES
    zmq
    ${ZMQ_LIBRARY_NAME}
  HINTS
    "${ZMQ_REGISTRY_PATH}/lib"
  PATHS
    /lib
    /usr/lib
    /usr/local/lib
)

if (ZMQ_INCLUDE_DIR AND ZMQ_LIBRARY)
  set(ZMQ_FOUND 1)
  message(STATUS "Found ZMQ library: ${ZMQ_LIBRARY}")
  message(STATUS "Found ZMQ headers: ${ZMQ_INCLUDE_DIR}")
else()
  message(FATAL_ERROR "Could not find ZMQ libraries/headers! Please install ZMQ with libraries and headers")
endif()

# show the ZMQ_INCLUDE_DIR and ZMQ_LIBRARY variables only in the advanced view
mark_as_advanced(ZMQ_INCLUDE_DIR ZMQ_LIBRARY ZMQ_FOUND)
