# Copyright (C) 2005-2010 Trinity <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# Set projectname (must be done AFTER setting configurationtypes)
project(TrinityCore)

# CMake policies (can not be handled elsewhere)
cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0005 NEW)

# Set RPATH-handing (CMake parameters)
set(CMAKE_SKIP_BUILD_RPATH 0)
set(CMAKE_BUILD_WITH_INSTALL_RPATH 0)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH 1)

# set macro-directory
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/macros")

# build in Release-mode by default if not explicitly set
if( NOT CMAKE_BUILD_TYPE )
  set(CMAKE_BUILD_TYPE "Release")
endif()

include(CheckCXXSourceRuns)
include(CheckIncludeFiles)

# set default buildoptions and print them
include(cmake/options.cmake)

# turn off PCH totally if enabled (hidden setting, mainly for devs)
if( NOPCH )
  set(USE_COREPCH 0)
  set(USE_SCRIPTPCH 0)
endif()

include(CheckPlatform)

# basic packagesearching and setup (further support will be needed, this is a preliminary release!)
find_package(PCHSupport)
find_package(ACE REQUIRED)
find_package(OpenSSL REQUIRED)
if( NOT USE_MYSQL_SOURCES )
  find_package(MySQL REQUIRED)
endif()

if( UNIX )
  find_package(Readline)
  find_package(ZLIB)
  find_package(BZip2)
endif()

# Find revision ID and hash of the sourcetree
execute_process(
  COMMAND hg id -n
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
  OUTPUT_VARIABLE hg_rev_id_str
  OUTPUT_STRIP_TRAILING_WHITESPACE
  ERROR_QUIET
)
execute_process(
  COMMAND hg id -i
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
  OUTPUT_VARIABLE hg_rev_hash_str
  OUTPUT_STRIP_TRAILING_WHITESPACE
  ERROR_QUIET
)

if(EXISTS ${CMAKE_SOURCE_DIR}/.hg_archival.txt)
  file(READ
    ${CMAKE_SOURCE_DIR}/.hg_archival.txt hg_rev_hash_str
    LIMIT 10
    OFFSET 7
    NEWLINE_CONSUME
  )
  string(STRIP ${hg_rev_hash_str} hg_rev_hash_str)
  set(hg_rev_id_str "Archive")
  set(hg_rev_id "0")
  set(hg_rev_hash ${hg_rev_hash_str})
endif()

# Last minute check - ensure that we have a proper revision
# If everything above fails (means the user has erased the mercurial revisional control directory, or runs archive and erased their .hg_archival.txt)
if(NOT hg_rev_id_str)
  message("")
  message(STATUS "WARNING - No revision-information found - have you been tampering with the sources?")

  # Ok, since we have no valid ways of finding/setting the revision, let's force some defaults
  set(hg_rev_hash_str "Archive")
  set(hg_rev_hash "0")
  set(hg_rev_id_str "0")
  set(hg_rev_id "0")
endif()

# Strip off excess strings (shows when the source is actually modified)
if(NOT hg_rev_id_str MATCHES "Archive")
  string(REPLACE "+" "" hg_rev_id ${hg_rev_id_str})
endif()
string(REPLACE "+" "" hg_rev_hash ${hg_rev_hash_str})

# Create the actual revision.h file from the above params
configure_file(
  "${CMAKE_SOURCE_DIR}/revision.h.in.cmake"
  "${CMAKE_BINARY_DIR}/revision.h"
  @ONLY
)
message(STATUS "Created revision.h")

# print out the results before continuing
include(cmake/showoptions.cmake)

# add dependencies
add_subdirectory(dep)

# add core sources
add_subdirectory(src)

# add sql-files
add_subdirectory(sql)
