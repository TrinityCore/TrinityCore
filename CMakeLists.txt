# Copyright (C) 2005-2010 Trinity <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

#####
##### Base setup for project
#####

#
# Set projectname (must be done AFTER setting configurationtypes btw...)
#

project(TrinityCore)

# CMake policies
cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0005 OLD)

#
# Force out-of-source build
#

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
include(cmake/FindPlatform.cmake)
include(cmake/FindPCHSupport.cmake)
if(WIN32)
  set(ACE_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/externals)
endif()
include(cmake/FindACE.cmake)
include(cmake/FindMySQL.cmake)
include(cmake/FindOpenSSL.cmake)
if( UNIX )
  include(cmake/FindReadline.cmake)
  include(FindZLIB)
  include(FindBZip2)
endif()

#
# Select the Release build configuration by default.
#

if( NOT CMAKE_BUILD_TYPE )
  set(CMAKE_BUILD_TYPE "Release")
endif()

#####
##### Options and settings
#####

#
# Set up default option-parameters for building
#

option(SERVERS "Build worldserver and authserver" 1)
option(SCRIPTS "Build worldserver with scripts included" 1)
option(TOOLS "Build map/vmap extraction/assembler tools" 0)
option(COREDEBUG "Build worldserver with additional debug-code included" 0)
option(SCRIPTPCH "Use precompiled headers when compiling scripts project" 1)
option(GAMEPCH "Use precompiled headers when compiling game project" 1)
option(SQL "Copy SQL files during installation" 0)
option(WARNINGS "Enable all compile-warnings during compile" 0)

#
# Search for readline on *nixbased systems (CLI-handler)
#

if( UNIX )
  find_readline()
endif()

#
# Set up the installation-prefix
#

if( PREFIX )
  set(CMAKE_INSTALL_PREFIX "${PREFIX}")
endif()

#
# Example: Check the CMake preload parameters (Commented out by default)
#
# Overload CMAKE_INSTALL_PREFIX if not being set properly
#if( WIN32 )
#  if( NOT CYGWIN )
#    if( NOT CMAKE_INSTALL_PREFIX )
#      set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/bin")
#    endif()
#  endif()
#endif()

#
# Handle core debugmode compilation (this will require further work for proper WIN32-setups)
#

if( COREDEBUG )
  set(CMAKE_BUILD_TYPE Debug)
endif()

#
# WINDOWS/MSVC: Set up paths for where we want binaries to end up after compilation
#

if( MSVC )
  # Set up MSVC to dump files in the <builddir>/bin/<buildtype>/ folder for testing builds before install

  # executable binaries (.exe-files, and .dll-files on DLL-capable platforms)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

  # other parts like static libraries etc - commented out as it's not needed - shown here as an example only
  #set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
  #set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()

#
# Set default configuration-directory (used on NIX-based platforms only)
#

if( NOT CONF_DIR )
  set(CONF_DIR ${CMAKE_INSTALL_PREFIX}/etc)
endif()

set(LIBSDIR ${CMAKE_INSTALL_PREFIX}/lib)

#####
##### Build-preparation
#####

#
# Create genrev object and create revision.h
# (Moved to subfolder to avoid cluttering up the base build-dir)
#

add_subdirectory(src/genrevision)

#
# Find current revision of downloaded sourcetree
#

execute_process(
  COMMAND hg tip --template {rev}
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
  OUTPUT_VARIABLE HG_REVISION
)

if(DEFINED NOPCH)
  set(SCRIPTPCH 0)
  set(GAMEPCH 0)
endif()

#
# Output some generic information about the core and buildtype chosen
#

message("")
message("* TrinityCore revision  : ${HG_REVISION}")
if( UNIX )
  message("* Build binaries in     : ${CMAKE_BUILD_TYPE} mode")
endif()
message("")

#
# Output information about installation-directories and locations
#

message("* Install core to       : ${CMAKE_INSTALL_PREFIX}")
if( UNIX )
  message("* Install libraries to  : ${LIBSDIR}")
  message("* Install configs to    : ${CONF_DIR}")
endif()
message("")

#
# Show infomation about the options selected during configuration
#

if( SERVERS )
  message("* Build servers         : Yes (default)")
else()
  message("* Build servers         : No")
endif()

if( GAMEPCH )
  message("* Build game w/PCH      : Yes (default)")
else()
  message("* Build game w/PCH      : No")
endif()

if( SCRIPTS )
  message("* Build with scripts    : Yes (default)")
  add_definitions(-DSCRIPTS)
else()
  message("* Build with scripts    : No")
  set(SCRIPTPCH 0)
endif()

if( SCRIPTPCH )
  message("* Build scripts w/PCH   : Yes (default)")
else()
  message("* Build scripts w/PCH   : No")
endif()

if( TOOLS )
  message("* Build map/vmap tools  : Yes")
else()
  message("* Build map/vmap tools  : No  (default)")
endif()

if( COREDEBUG )
  message("* Use coreside debug    : Yes")
  add_definitions(-DTRINITY_DEBUG)
  if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-g)
  endif()
else()
  message("* Use coreside debug    : No  (default)")
endif()

if( WARNINGS )
  message("* Show all warnings     : Yes")
  if( UNIX )
    add_definitions(-Wall -Wfatal-errors -Wextra)
  endif()
else()
  message("* Show compile-warnings : No  (default)")
  if( UNIX )
    add_definitions(--no-warnings) # makes build look nice, no warnings shown at all, only errors
  elseif( WIN32 )
    # Disable warnings in Visual Studio 8 and above
    if(MSVC AND NOT CMAKE_GENERATOR MATCHES "Visual Studio 7")
      set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /wd4996 /wd4355 /wd4244 /wd4985 /wd4267 /wd4619")
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4996 /wd4355 /wd4244 /wd4985 /wd4267 /wd4619")
    endif()
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
  endif()
endif()

#
# Inform if we will install SQL-files or not
#

if( SQL )
  message("* Install SQL-files     : Yes")
else()
  message("* Install SQL-files     : No  (default)")
endif()
message("")

#####
##### Tweaks to make things operate well
#####

#
# Little tweak for OS X
#

if( CMAKE_SYSTEM_NAME MATCHES "Darwin" )
  set(MACOSX 1)
  set(OSX_LIBS /usr/lib/libcrypto.dylib)
  add_definitions(-D__ASSERTMACROS__)
endif()

#
# Some small tweaks for Visual Studio 7 and above.  
#

if( MSVC )
  # Mark 32 bit executables large address aware so they can use > 2GB address space
  if(CMAKE_SIZEOF_VOID_P MATCHES 4)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /LARGEADDRESSAWARE")
  endif()
endif()

#
# Set RPATH-handing (CMake parameters)
#

set(CMAKE_SKIP_BUILD_RPATH 0)
set(CMAKE_BUILD_WITH_INSTALL_RPATH 0)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH 1)

#####
##### Start filling in the blanks, and build the project
#####

#
# Create uninstall-object for UNIX platforms
#

if( UNIX )
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY
  )
  add_custom_target(uninstall
    "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
  )
endif()

#
# Enter the different builddirectories and start working 
#

add_subdirectory(externals)
add_subdirectory(src)
if( SQL )
  add_subdirectory(sql)
endif()
