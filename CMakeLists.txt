# Copyright (C) 2005-2010 Trinity <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

project(Trinity)

# CMake policies
cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0005 OLD)

# Force out-of-source build
string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_BINARY_DIR}" BUILDING_IN_SOURCE)

if( BUILDING_IN_SOURCE )
  message(FATAL_ERROR "
    This project requires an out of source build. Remove the file 'CMakeCache.txt'
    found in this directory before continuing, create a separate build directory
    and run 'cmake path_to_project [options]' from there.
  ")
endif()

#
# Basic packagesearching and setup (further support will be needed, this is a preliminary release!)
#

include(CheckIncludeFiles)
include(cmake/FindPCHSupport.cmake)
include(cmake/FindACE.cmake)
include(cmake/FindMySQL.cmake)
include(cmake/FindOpenSSL.cmake)

#
# *nix-specific packages ( zlib and bzip2 libraries will be built from sourcetree on WIN32-platforms)
#

if( UNIX )
  include(cmake/FindReadline.cmake)
  include(cmake/FindTermcap.cmake)
  include(FindZLIB)
  include(FindBZip2)
endif()

# Select the Release build configuration by default.
if( NOT CMAKE_BUILD_TYPE )
  set(CMAKE_BUILD_TYPE "Release")
endif()

configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
  IMMEDIATE @ONLY
)

add_custom_target(uninstall
  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
)

option(DO_AUTHSERVER "Build authserver" 1)
option(DO_WORLDSERVER "Build worldserver" 1)
option(DO_CLI "With CLI" 1)
option(DO_DEBUG "Debug mode" 0)
option(DO_PCH "Use precompiled headers" 1)
option(DO_RA "With RA" 0)
option(DO_SCRIPTS "With trinityscripts" 1)
option(DO_SQL "Copy SQL files" 0)
option(DO_TOOLS "Build tools" 0)
option(CENTOS "CENTOS" 0)
option(DO_WARN "Enable all compile warnings" 0)

if( UNIX )
  if( CENTOS )
    add_definitions(-DCENTOS)
    find_termcap()
  else()
    find_readline()
  endif()
endif()

# Set up the installation-prefix
if( PREFIX )
  set(CMAKE_INSTALL_PREFIX ${PREFIX})
endif()

set(GENREV_SRC
  src/genrevision/genrevision.cpp
)

# Handle debugmode compiles (this will require further work for proper WIN32-setups)
if( DO_DEBUG )
  set(CMAKE_BUILD_TYPE Debug)
  add_executable(genrev
    ${GENREV_SRC}
  )

  add_custom_target("revision.h" ALL
    COMMAND "${CMAKE_BINARY_DIR}/genrev"
    ${CMAKE_SOURCE_DIR}
    WORKING_DIRECTORY "${CMAKE_BUILD_DIR}"
    DEPENDS genrev
  )
else()
  add_executable(genrev
    ${GENREV_SRC}
  )

  add_custom_target("revision.h" ALL
    COMMAND "${CMAKE_BINARY_DIR}/genrev"
    ${CMAKE_SOURCE_DIR}
    WORKING_DIRECTORY "${CMAKE_BUILD_DIR}"
    DEPENDS genrev
  )
endif()

execute_process(
  COMMAND hg tip --template {rev}
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
  OUTPUT_VARIABLE HG_REVISION
)

message("")
message("* TrinityCore revision  : ${HG_REVISION}")
message("* Build binaries in     : ${CMAKE_BUILD_TYPE} mode")
message("")

if( NOT CONF_DIR )
  set(CONF_DIR ${CMAKE_INSTALL_PREFIX}/etc)
endif()

set(LIBSDIR ${CMAKE_INSTALL_PREFIX}/lib)

message("* Install core to       : ${CMAKE_INSTALL_PREFIX}")
message("* Install libraries to  : ${LIBSDIR}")
message("* Install configs to    : ${CONF_DIR}")
message("")

if( DO_AUTHSERVER )
  message("* Build authserver      : Yes (default)")
else()
  message("* Build authserver      : No")
endif()

if( DO_WORLDSERVER )
  message("* Build worldserver     : Yes (default)")
else()
  message("* Build worldserver     : No")
endif()

if( DO_SCRIPTS )
  message("* Build Trinityscripts  : Yes (default)")
  add_definitions(-DDO_SCRIPTS)
else()
  message("* Build Trinityscripts  : No")
endif()

if( DO_TOOLS )
  message("* Build map/vmap tools  : Yes")
else()
  message("* Build map/vmap tools  : No  (default)")
endif()

if( DO_CLI )
  message("* Build with CLI        : Yes (default)")
  add_definitions(-DENABLE_CLI)
else()
  message("* Build with CLI        : No")
endif()

if( DO_RA )
  message("* Build with RA         : Yes")
  add_definitions(-DENABLE_RA)
else()
  message("* Build with RA         : No  (default)")
endif()

if( DO_DEBUG )
  message("* Build in debug-mode   : Yes")
  add_definitions(-g -DTRINITY_DEBUG)
else()
  message("* Build in debug-mode   : No  (default)")
endif()

if( DO_PCH )
  message("* Use PCH               : Yes (default)")
else()
  message("* Use PCH               : No")
endif()

if( DO_WARN )
  message("* Show all warnings     : Yes")
  if( UNIX )
    add_definitions(-Wall -Wfatal-errors -Wextra)
  endif()
else()
  message("* Show compile-warnings : No  (default)")
  if( UNIX )
    add_definitions(--no-warnings) # makes build look nice, no warnings shown at all, only errors
  elseif( WIN32 )
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
  endif()
endif()

if( DO_SQL )
  message("* Install SQL-files     : Yes")
else()
  message("* Install SQL-files     : No  (default)")
endif()

message("")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config.h)

# Little tweak for OS X
if( CMAKE_SYSTEM_NAME MATCHES "Darwin" )
  set(MACOSX 1)
  set(OSX_LIBS /opt/local/lib/libcrypto.dylib)
  add_definitions(-D__ASSERTMACROS__)
endif()

set(CMAKE_SKIP_BUILD_RPATH 0)
set(CMAKE_BUILD_WITH_INSTALL_RPATH 0)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH 1)

add_subdirectory(externals)
add_subdirectory(src)
if( DO_SQL )
  add_subdirectory(sql)
endif()
