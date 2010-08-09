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

project(TrinityCore)

# CMake policies
cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0005 OLD)

#
# Override configuration-types - we don't use anything else than debug and release
#

if(CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_CONFIGURATION_TYPES Release Debug)
  set(CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING
    "Reset the configurations to what we need"
    FORCE)
endif()

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

#
# *nix-specific packages ( zlib and bzip2 libraries will be built from sourcetree on WIN32-platforms)
#

if( UNIX )
  include(cmake/FindReadline.cmake)
  include(cmake/FindTermcap.cmake)
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
option(CLI "Build worldserver with commandline-interface included" 1)
option(DEBUG "Build worldserver with additional debug-code included" 0)
option(PCH "Use precompiled headers when compiling" 1)
option(SQL "Copy SQL files during installation" 0)
option(WARNINGS "Enable all compile-warnings during compile" 0)

if( UNIX )
  option(CENTOS "CENTOS" 0)
  if( CENTOS )
    add_definitions(-DCENTOS)
    find_termcap()
  else()
    find_readline()
  endif()
endif()

#
# Set up the installation-prefix
#

if( PREFIX )
  set(CMAKE_INSTALL_PREFIX ${PREFIX})
endif()

#
# Handle debugmode compiles (this will require further work for proper WIN32-setups)
#

if( DEBUG )
  set(CMAKE_BUILD_TYPE Debug)
endif()

#
# WINDOWS/MSVC: Set up paths for where we want binaries to end up after compilation
#

if( MSVC )
  # Set up MSVC to dump binaries in the <builddir>/bin/<buildtype>/ folder
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
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

#
# Output some generic information about the core and buildtype chosen
#

message("* TrinityCore revision  : ${HG_REVISION}")
message("* Build binaries in     : ${CMAKE_BUILD_TYPE} mode")
message("")

#
# Output information about installation-directories and locations
#

if( UNIX )
  message("* Install core to       : ${CMAKE_INSTALL_PREFIX}")
  message("* Install libraries to  : ${LIBSDIR}")
  message("* Install configs to    : ${CONF_DIR}")
  message("")
endif()

#
# Show infomation about the options selected during configuration
#

if( SERVERS )
  message("* Build servers         : Yes (default)")
else()
  message("* Build servers         : No")
endif()

if( SCRIPTS )
  message("* Build with scripts    : Yes (default)")
  add_definitions(-DSCRIPTS)
else()
  message("* Build with scripts    : No")
endif()

if( TOOLS )
  message("* Build map/vmap tools  : Yes")
else()
  message("* Build map/vmap tools  : No  (default)")
endif()

if( CLI )
  message("* Build with CLI        : Yes (default)")
  add_definitions(-DENABLE_CLI)
else()
  message("* Build with CLI        : No")
endif()

if( DEBUG )
  message("* Build in debug-mode   : Yes")
  add_definitions(-DTRINITY_DEBUG)
  if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-g)
  elseif(MSVC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /Zi")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /DEBUG")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /DEBUG")
  endif()
else()
  message("* Build in debug-mode   : No  (default)")
endif()

if( PCH )
  message("* Use PCH               : Yes (default)")
else()
  message("* Use PCH               : No")
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
      set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /wd4996 /wd4355 /wd4244 /wd4985 /wd4267")
      set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /wd4996 /wd4355 /wd4244 /wd4267")
      set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /wd4996 /wd4355 /wd4244 /wd4985 /wd4267")
      set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /wd4996 /wd4355 /wd4244 /wd4985 /wd4267")
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

#####
##### Tweaks to make things operate well
#####

#
# Little tweak for OS X
#

if( CMAKE_SYSTEM_NAME MATCHES "Darwin" )
  set(MACOSX 1)
  set(OSX_LIBS /opt/local/lib/libcrypto.dylib)
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
