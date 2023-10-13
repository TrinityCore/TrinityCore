# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

if(WIN32)
  if(DEFINED ENV{BOOST_ROOT})
    set(BOOST_ROOT $ENV{BOOST_ROOT})
  endif()

  set(Boost_USE_STATIC_LIBS        ON)
  set(Boost_USE_MULTITHREADED      ON)
  set(Boost_USE_STATIC_RUNTIME     OFF)
endif()

set(Boost_NO_WARN_NEW_VERSIONS ON)

include (CheckCXXSourceCompiles)

if (WIN32)
  # On windows the requirements are higher according to the wiki.
  set(BOOST_REQUIRED_VERSION 1.78)
else()
  set(BOOST_REQUIRED_VERSION 1.71)
endif()

find_package(Boost ${BOOST_REQUIRED_VERSION} REQUIRED system filesystem program_options iostreams regex locale)

if(NOT Boost_FOUND)
  if(NOT DEFINED ENV{BOOST_ROOT} AND NOT DEFINED Boost_DIR AND NOT DEFINED BOOST_ROOT AND NOT DEFINED BOOSTROOT)
    message(FATAL_ERROR "No BOOST_ROOT environment variable could be found! Please make sure it is set and the points to your Boost installation.")
  endif()
endif()

add_library(boost INTERFACE)

target_link_libraries(boost
  INTERFACE
    ${Boost_LIBRARIES})

target_include_directories(boost
  INTERFACE
    ${Boost_INCLUDE_DIRS})

target_compile_definitions(boost
  INTERFACE
    -DBOOST_DATE_TIME_NO_LIB
    -DBOOST_REGEX_NO_LIB
    -DBOOST_CHRONO_NO_LIB
    -DBOOST_SERIALIZATION_NO_LIB
    -DBOOST_CONFIG_SUPPRESS_OUTDATED_MESSAGE
    -DBOOST_ASIO_NO_DEPRECATED
    -DBOOST_SYSTEM_USE_UTF8
    -DBOOST_BIND_NO_PLACEHOLDERS)

if (WITH_BOOST_STACKTRACE AND NOT WIN32)
  message("*** libbacktrace will be linked")

  if (BOOST_STACKTRACE_BACKTRACE_INCLUDE_FILE)
    CHECK_INCLUDE_FILE(${BOOST_STACKTRACE_BACKTRACE_INCLUDE_FILE} HAS_BACKTRACE)
  else()
    CHECK_INCLUDE_FILE("backtrace.h" HAS_BACKTRACE)
  endif()

  if (NOT HAS_BACKTRACE)
    message(FATAL_ERROR "Required header 'backtrace.h' not found. If building with a compiler other than GCC, please specify the full path in the CMake option BOOST_STACKTRACE_BACKTRACE_INCLUDE_FILE.")
  endif()

  target_compile_definitions(boost
    INTERFACE
      -DBOOST_STACKTRACE_USE_BACKTRACE)

  target_link_libraries(boost
    INTERFACE
      backtrace)
endif()
