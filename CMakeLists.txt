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
cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0005 OLD)

# Force out-of-source build
string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_BINARY_DIR}" BUILDING_IN_SOURCE)
if(BUILDING_IN_SOURCE)
  message(FATAL_ERROR "This project requires an out of source build. Remove the file 'CMakeCache.txt' found in this directory before continuing, and create a separate build directory and run 'cmake path_to_project [options]' from there.")
endif(BUILDING_IN_SOURCE)

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

if(UNIX)
include(cmake/FindReadline.cmake)
include(cmake/FindTermcap.cmake)
include(FindZLIB)
include(FindBZip2)
endif(UNIX)

# Select the Release build configuration by default.
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif(NOT CMAKE_BUILD_TYPE)

CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
  IMMEDIATE @ONLY)

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
if( UNIX )
option(CENTOS "CENTOS" 0)
option(DO_WARN "Enable all compile warnings" 0)
endif( UNIX )

if( UNIX )
  if( CENTOS )
    add_definitions(-DCENTOS)
    find_termcap()
  else( CENTOS )
    find_readline()
  endif( CENTOS )
endif( UNIX )

# Set up the installation-prefix

if( PREFIX )
  set(CMAKE_INSTALL_PREFIX ${PREFIX})
endif( PREFIX )

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
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/src/server/shared"
    DEPENDS genrev
  )
else ( DO_DEBUG )

  add_executable(genrev
    ${GENREV_SRC}
  )

  add_custom_target("revision.h" ALL
    COMMAND "${CMAKE_BINARY_DIR}/genrev"
    ${CMAKE_SOURCE_DIR}
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/src/server/shared"
    DEPENDS genrev
  )

endif( DO_DEBUG )

execute_process(
  COMMAND hg tip --template {rev}
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
  OUTPUT_VARIABLE HG_REVISION
)

message("")
message("* TrinityCore revision  : ${HG_REVISION}")
message("* Build binaries in     : ${CMAKE_BUILD_TYPE} mode")
message("")

if( CONF_DIR )
else( CONF_DIR )
  set(CONF_DIR ${CMAKE_INSTALL_PREFIX}/etc)
endif( CONF_DIR )

set(LIBSDIR ${CMAKE_INSTALL_PREFIX}/lib)

message("* Install core to       : ${CMAKE_INSTALL_PREFIX}")
message("* Install libraries to  : ${LIBSDIR}")
message("* Install configs to    : ${CONF_DIR}")
message("")

if( DO_AUTHSERVER )
  message("* Build authserver      : Yes (default)")
else( DO_AUTHSERVER )
  message("* Build authserver      : No")
endif( DO_AUTHSERVER )

if( DO_WORLDSERVER )
  message("* Build worldserver     : Yes (default)")
else( DO_WORLDSERVER )
  message("* Build worldserver     : No")
endif( DO_WORLDSERVER )

if( DO_SCRIPTS )
  message("* Build Trinityscripts  : Yes (default)")
  add_definitions(-DDO_SCRIPTS)
else( DO_SCRIPTS )
  message("* Build Trinityscripts  : No")
endif( DO_SCRIPTS )

if( DO_TOOLS )
  message("* Build map/vmap tools  : Yes")
else( DO_TOOLS )
  message("* Build map/vmap tools  : No  (default)")
endif( DO_TOOLS )

if(DO_CLI)
  message("* Build with CLI        : Yes (default)")
  add_definitions(-DENABLE_CLI)
else(DO_CLI)
  message("* Build with CLI        : No")
endif(DO_CLI)

if(DO_RA)
  message("* Build with RA         : Yes")
  add_definitions(-DENABLE_RA)
else(DO_RA)
  message("* Build with RA         : No  (default)")
endif(DO_RA)

if( DO_DEBUG )
  message("* Build in debug-mode   : Yes")
  add_definitions(-g -DTRINITY_DEBUG)
else( DO_DEBUG )
  message("* Build in debug-mode   : No  (default)")
  add_definitions(--no-warnings) # makes build look nice, no warnings shown at all, only errors
endif( DO_DEBUG )

if( DO_PCH )
  message("* Use PCH               : Yes (default)")
else( DO_PCH )
  message("* Use PCH               : No")
endif( DO_PCH )

if( UNIX )
  if( DO_WARN )
    message("* Show all warnings     : Yes")
    add_definitions(-Wall -Wfatal-errors -Wextra)
  else( DO_WARN )
    message("* Show compile-warnings : No  (default)")
    add_definitions(--no-warnings) # makes build look nice, no warnings shown at all, only errors
  endif( DO_WARN )
endif( UNIX )

if(DO_SQL)
  message("* Install SQL-files     : Yes")
else (DO_SQL)
  message("* Install SQL-files     : No  (default)")
endif(DO_SQL)

message("")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config.h)

# Little tweak for OS X
if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
  set(MACOSX 1)
  set(OSX_LIBS /opt/local/lib/libcrypto.dylib)
  add_definitions(-D__ASSERTMACROS__)
endif(CMAKE_SYSTEM_NAME MATCHES "Darwin")

set(CMAKE_SKIP_BUILD_RPATH 0)
set(CMAKE_BUILD_WITH_INSTALL_RPATH 0)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH 1)

add_subdirectory(externals)
add_subdirectory(src)
if(DO_SQL)
add_subdirectory(sql)
endif(DO_SQL)
