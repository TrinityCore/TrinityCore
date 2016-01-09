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

find_path(ZMQ_ROOT_DIR
  NAMES
    include/zmq.h
  HINTS
    ${ZMQ_REGISTRY_PATH}
  PATHS
    /usr
    /usr/local
)

find_path(ZMQ_INCLUDE_DIR zmq.h ${ZMQ_ROOT_DIR}/include)

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
  set(_VS_VERSIONS "140" "120")

  if (${ZMQ_NAME} MATCHES "registry") # if key was not found, the string "registry" is returned
    set(_ZMQ_VERSIONS "4_0_4" "4_0_3" "4_0_2" "4_0_1" "4_0_0" "3_2_5" "3_2_4" "3_2_3" "3_2_2"  "3_2_1" "3_2_0" "3_1_0")
    set(ZMQ_LIBRARY_NAME)
    foreach(ver ${_ZMQ_VERSIONS})
      foreach(vs ${_VS_VERSIONS})
        list(APPEND ZMQ_LIBRARY_NAME "libzmq-v${vs}-mt-${ver}")
      endforeach()
    endforeach()
  else()
    # Format ZMQ library file name
    foreach(vs ${_VS_VERSIONS})
      set(ZMQ_LIBRARY_NAME "libzmq-v${vs}-mt-${ZMQ_NAME}")
    endforeach()
  endif()
endif()

find_library(ZMQ_LIBRARY
  NAMES
    zmq
    ${ZMQ_LIBRARY_NAME}
  PATHS
    /lib
    /usr/lib
    /usr/local/lib
    "${ZMQ_ROOT_DIR}/lib"
)

if (ZMQ_INCLUDE_DIR AND ZMQ_LIBRARY AND NOT ZMQ_LIBRARY-NOTFOUND)
  set(ZMQ_FOUND 1)
  message(STATUS "Found ZMQ library: ${ZMQ_LIBRARY}")
  message(STATUS "Found ZMQ headers: ${ZMQ_INCLUDE_DIR}")
else()
  message(FATAL_ERROR "Could not find ZMQ libraries/headers! Please install ZMQ with libraries and headers")
endif()

# show the ZMQ_INCLUDE_DIR and ZMQ_LIBRARY variables only in the advanced view
mark_as_advanced(ZMQ_ROOT_DIR ZMQ_INCLUDE_DIR ZMQ_LIBRARY ZMQ_FOUND)
