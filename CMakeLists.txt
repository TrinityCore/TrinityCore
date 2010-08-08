# Copyright (C) 2005-2010 Trinity <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

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

# Select the Release build configuration by default.
if( NOT CMAKE_BUILD_TYPE )
  set(CMAKE_BUILD_TYPE "Release")
endif()

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

option(SERVERS "Build servers" 1)
option(CLI "With CLI" 1)
option(DEBUG "Debug mode" 0)
option(PCH "Use precompiled headers" 1)
option(SCRIPTS "With trinityscripts" 1)
option(SQL "Copy SQL files" 0)
option(TOOLS "Build tools" 0)
option(WARNINGS "Enable all compile warnings" 0)

if( UNIX )
  option(CENTOS "CENTOS" 0)
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

# Handle debugmode compiles (this will require further work for proper WIN32-setups)
if( DEBUG )
  set(CMAKE_BUILD_TYPE Debug)
endif()

if( MSVC )
  # Set up MSVC to dump binaries in the <builddir>/bin/<buildtype>/ folder
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()

#
# Generate revision-extractor
#

set(GENREV_SRC
  src/genrevision/genrevision.cpp
)
add_executable(genrev
  ${GENREV_SRC}
)

if( CMAKE_GENERATOR MATCHES "Visual Studio" )
  add_custom_target("revision.h" ALL
    COMMAND "${CMAKE_BINARY_DIR}/bin/$(Configuration)/genrev"
    ${CMAKE_SOURCE_DIR}
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
    DEPENDS genrev
  )
else()
  add_custom_target("revision.h" ALL
    COMMAND "${CMAKE_BINARY_DIR}/genrev"
    ${CMAKE_SOURCE_DIR}
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
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

if( SERVERS )
  message("* Build server          : Yes (default)")
else()
  message("* Build server          : No")
endif()

if( SCRIPTS )
  message("* Build Trinityscripts  : Yes (default)")
  add_definitions(-DSCRIPTS)
else()
  message("* Build Trinityscripts  : No")
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

if( SQL )
  message("* Install SQL-files     : Yes")
else()
  message("* Install SQL-files     : No  (default)")
endif()

message("")

# Little tweak for OS X
if( CMAKE_SYSTEM_NAME MATCHES "Darwin" )
  set(MACOSX 1)
  set(OSX_LIBS /opt/local/lib/libcrypto.dylib)
  add_definitions(-D__ASSERTMACROS__)
endif()

# Some small tweaks for Visual Studio 7 and above.  
if( MSVC )
  # Mark 32 bit executables large address aware so they can use > 2GB address space
  if(CMAKE_SIZEOF_VOID_P MATCHES 4)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /LARGEADDRESSAWARE")
  endif()
endif()

set(CMAKE_SKIP_BUILD_RPATH 0)
set(CMAKE_BUILD_WITH_INSTALL_RPATH 0)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH 1)

add_subdirectory(externals)
add_subdirectory(src)
if( SQL )
  add_subdirectory(sql)
endif()
