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

include(CheckIncludeFiles)
include(cmake/FindAce.cmake)
include(cmake/FindMySql.cmake)
include(cmake/FindReadline.cmake)
include(cmake/FindTermcap.cmake)
include(cmake/PCH.cmake)

# Force out-of-source build
string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_BINARY_DIR}" BUILDING_IN_SOURCE)
if(BUILDING_IN_SOURCE)
  message(FATAL_ERROR "This project requires an out of source build. Remove the file 'CMakeCache.txt' found in this directory before continuing, and create a separate build directory and run 'cmake path_to_project [options]' from there.")    
endif(BUILDING_IN_SOURCE)

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

option(CENTOS "CENTOS" 0)
option(DO_AUTHSERVER "Build authserver" 1)
option(DO_WORLDSERVER "Build worldserver" 1)
option(DO_CLI "With CLI" 1)
option(DO_DEBUG "Debug mode" 0)
option(DO_MYSQL "With MySQL support" 1)
option(DO_PCH "Use precompiled headers" 1)
option(DO_RA "With RA" 0)
option(DO_SCRIPTS "With trinityscripts" 1)
option(DO_SQL "Copy SQL files" 0)
option(DO_TOOLS "Build tools" 0)
option(DO_WARN "Enable all compile warnings" 0)

if(PREFIX)
  set(CMAKE_INSTALL_PREFIX ${PREFIX})
endif(PREFIX)

set(GENREV_SRC
  src/genrevision/genrevision.cpp
)

if(DO_DEBUG)
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
else (DO_DEBUG)
  add_executable(genrev
    ${GENREV_SRC}
  )
  add_custom_target("revision.h" ALL
    COMMAND "${CMAKE_BINARY_DIR}/genrev"
    ${CMAKE_SOURCE_DIR}
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/src/server/shared"
    DEPENDS genrev
  )
endif(DO_DEBUG)

execute_process(
  COMMAND hg tip --template {rev}
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
  OUTPUT_VARIABLE HG_REVISION
)

message("")
message("* TrinityCore revision  : ${HG_REVISION}")
message("* Build binaries in     : ${CMAKE_BUILD_TYPE} mode")
message("")

if(CONF_DIR)
else(CONF_DIR)
  set(CONF_DIR ${PREFIX}/etc)
endif(CONF_DIR)

set(LIBSDIR ${CMAKE_INSTALL_PREFIX}/lib)

message("* Install core to       : ${CMAKE_INSTALL_PREFIX}")
message("* Install libraries to  : ${LIBSDIR}")
message("* Install configs to    : ${CONF_DIR}")
message("")

if(DO_AUTHSERVER)
  message("* Build authserver      : Yes (default)")
else(DO_ATUHSERVER)
  message("* Build authserver      : No")
endif(DO_AUTHSERVER)

if(DO_WORLDSERVER)
  message("* Build worldserver     : Yes (default)")
else(DO_WORLDSERVER)
  message("* Build worldserver     : No")
endif(DO_WORLDSERVER)

if(DO_SCRIPTS)
  message("* Build Trinityscripts  : Yes (default)")
  ADD_DEFINITIONS(-DDO_SCRIPTS)
  add_definitions(-D_TRINITY_SCRIPT_CONFIG='"${CONF_DIR}/worldserver.conf"')
else (DO_SCRIPTS)
  message("* Build Trinityscripts  : No")
endif(DO_SCRIPTS)

if(DO_TOOLS)
  message("* Build map/vmap tools  : Yes")
else(DO_TOOLS)
  message("* Build map/vmap tools  : No  (default)")
endif(DO_TOOLS)

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

if(DO_DEBUG)
  message("* Build in debug-mode   : Yes")
  add_definitions(-g -DTRINITY_DEBUG)
else(DO_DEBUG)
  message("* Build in debug-mode   : No  (default)")
  add_definitions(--no-warnings) # makes build look nice, no warnings shown at all, only errors
endif(DO_DEBUG)

if(DO_PCH)
  message("* Use PCH               : Yes (default)")
else (DO_PCH)
  message("* Use PCH               : No")
endif(DO_PCH)

if(DO_WARN)
  message("* Show all warnings     : Yes")
  add_definitions(-Wall -Wfatal-errors -Wextra)
else(DO_WARN)
  message("* Show compile-warnings : No  (default)")
endif(DO_WARN)

if(DO_SQL)
  message("* Install SQL-files     : Yes")
else (DO_SQL)
  message("* Install SQL-files     : No  (default)")
endif(DO_SQL)

message("")

find_library(SSLLIB NAMES ssl DOC "SSL library")
find_library(ZLIB z "Zlib library")

if(DO_MYSQL)
  FIND_MYSQL()
  ADD_DEFINITIONS(-DDO_MYSQL)
endif(DO_MYSQL)

if(UNIX)
  if(CENTOS)
    add_definitions(-DCENTOS)
    FIND_TERMCAP()
  else(CENTOS)
    FIND_READLINE()
  endif(CENTOS)
endif(UNIX)

FIND_ACE(ACE)
if(ACE_FOUND)
  message(STATUS "Found ACE: ${ACE_LIBRARY}")
  message(STATUS "Include dir is: ${ACE_INCLUDE_DIR}")
else(ACE_FOUND)
  message(SEND_ERROR "** ACE library not found! Trinity Core cannot be compiled!")
  message(SEND_ERROR "** Please build ACE from http://www.cs.wustl.edu/~schmidt/ACE.html")
  #For now remove msg about install from repo, as ubuntu/debian don't have needed ver in repos.
  #message(SEND_ERROR "** your distro may provide a binary for ACE e.g. for ubuntu try apt-get install libace-dev")
  return()
  #set(BUILD_ACE 1)
  #set(ACE_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/dep/ACE_wrappers ${CMAKE_BINARY_DIR}/dep/ACE_wrappers")
  #set(ACE_LIBRARY ACE)
  #message(STATUS "I will try to build ACE from: ${ACE_INCLUDE_DIR}")
  #message(STATUS "And link using: ${ACE_LIBRARY}")
endif(ACE_FOUND)

#somehow line below don't work. so for now change it to if exist
#check_include_files(${ACE_INCLUDE_DIR}/ace/Stack_Trace.h HAVE_ACE_STACK_TRACE_H)
if(EXISTS ${ACE_INCLUDE_DIR}/ace/Stack_Trace.h)
  set(HAVE_ACE_STACK_TRACE_H 1)
else(EXISTS ${ACE_INCLUDE_DIR}/ace/Stack_Trace.h)
  message(STATUS "** Your libace is out of date. Please update your libace!")
endif(EXISTS ${ACE_INCLUDE_DIR}/ace/Stack_Trace.h)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config.h)

if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
  set(MACOSX 1)
  set(OSX_LIBS /opt/local/lib/libcrypto.dylib)
  add_definitions(-D__ASSERTMACROS__)
endif(CMAKE_SYSTEM_NAME MATCHES "Darwin")

if(DO_WARN)
else(DO_WARN)
  add_definitions(--no-warnings) # makes build look nice, no warnings shown at all, only errors
endif(DO_WARN)

set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

add_subdirectory(externals)
add_subdirectory(src)

if(DO_SQL)
  add_subdirectory(sql)
endif(DO_SQL)
