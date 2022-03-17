# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

cmake_minimum_required(VERSION 3.11)

# add this options before PROJECT keyword
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

# Set projectname (must be done AFTER setting configurationtypes)
project(TrinityCore)

#tswow-begin add tswow sources

include(FetchContent)

#
# Lua 5.1
#
FetchContent_Declare(
  lua51
  URL https://www.lua.org/ftp/lua-5.1.5.tar.gz
)
FetchContent_MakeAvailable(lua51)
file(GLOB SRC_LUA ${lua51_SOURCE_DIR}/src/*.c)
add_library ( liblua ${SRC_LUA} )

#
# sol2
#
FetchContent_Declare (sol2
  GIT_REPOSITORY https://github.com/tswow/sol2
  GIT_TAG b9c83d5ecf6bc9503dc66779f2395dc32dffb1e5
)
FetchContent_MakeAvailable (sol2)
add_library (sane-sol2 INTERFACE)
add_library (sol2::sane ALIAS sane-sol2)
target_link_libraries (sane-sol2 INTERFACE liblua)
target_include_directories (sane-sol2 SYSTEM INTERFACE "${sol2_SOURCE_DIR}/include")

#
# sourcemap
#
FetchContent_Declare (sourcemap
  GIT_REPOSITORY https://github.com/mgreter/sourcemap.cpp.git
  GIT_TAG bd09bd903ff6bf77950b5bb8d0138e26ade95d4a
)
FetchContent_MakeAvailable (sourcemap)
file(GLOB SOURCEMAP_SRC
    ${sourcemap_SOURCE_DIR}/src/*
    ${sourcemap_SOURCE_DIR}/src/format/*
    ${sourcemap_SOURCE_DIR}/deps/json/*
    ${sourcemap_SOURCE_DIR}/deps/cencode/*
)
add_library(sourcemaps ${SOURCEMAP_SRC})
target_include_directories(sourcemaps PUBLIC
    ${sourcemap_SOURCE_DIR}/src
    ${sourcemap_SOURCE_DIR}/deps/json
    ${sourcemap_SOURCE_DIR}/deps/cencode
)

#
# tswow
#
get_filename_component(
  TSWOW_CORE_PRIVATE ${CMAKE_SOURCE_DIR}/../../tswow-core/Private ABSOLUTE
)

get_filename_component(
  TSWOW_CORE_PUBLIC ${CMAKE_SOURCE_DIR}/../../tswow-core/Public ABSOLUTE
)

get_filename_component(
  TSWOW_MESSAGES_INCLUDES ${CMAKE_SOURCE_DIR}/../../misc/client-extensions/CustomPackets ABSOLUTE
)

SET(TSWOW_INCLUDES
  ${TSWOW_CORE_PRIVATE}
  ${TSWOW_CORE_PUBLIC}
  ${TSWOW_MESSAGES_INCLUDES}
)

ADD_COMPILE_DEFINITIONS(USE_STD_SHARED_PTR=1)

FILE(GLOB_RECURSE TSWOW_SOURCES
    ${TSWOW_CORE_PRIVATE}/*
    ${TSWOW_CORE_PUBLIC}/*
    ${TSWOW_MESSAGES_INCLUDES}/*.h
    ${TSWOW_MESSAGES_INCLUDES}/*.cpp
)
#tswow-end

# CMake policies (can not be handled elsewhere)
cmake_policy(SET CMP0005 NEW)
if(CMAKE_VERSION VERSION_LESS "3.16.0")
  cmake_policy(SET CMP0043 OLD) # Disable 'Ignore COMPILE_DEFINITIONS_<Config> properties'
else()
  cmake_policy(SET CMP0043 NEW) # Cotire isn't used so set to NEW
endif()
cmake_policy(SET CMP0054 NEW) # Only interpret if() arguments as variables or keywords when unquoted - prevents intepreting if(SOME_STRING_VARIABLE MATCHES "MSVC") as if(SOME_STRING_VARIABLE MATCHES "1")

if(POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW) # find_package() uses <PackageName>_ROOT variables
endif()

# Set RPATH-handing (CMake parameters)
set(CMAKE_SKIP_BUILD_RPATH 0)
set(CMAKE_BUILD_WITH_INSTALL_RPATH 0)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH 1)

# set macro-directory
list(APPEND CMAKE_MODULE_PATH
  "${CMAKE_SOURCE_DIR}/cmake/macros")

if(CMAKE_VERSION VERSION_LESS "3.16.0")
  list(APPEND CMAKE_MODULE_PATH
    "${CMAKE_SOURCE_DIR}/dep/cotire/CMake")
endif()

# build in Release-mode by default if not explicitly set
if(CMAKE_GENERATOR STREQUAL "Ninja Multi-Config")
  set(CMAKE_DEFAULT_BUILD_TYPE "RelWithDebInfo" CACHE INTERNAL "")
endif()
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

include(CheckCXXSourceRuns)
include(CheckIncludeFiles)
include(ConfigureScripts)

# set default buildoptions and print them
include(cmake/options.cmake)

# turn off PCH totally if enabled (hidden setting, mainly for devs)
if(NOPCH)
  set(USE_COREPCH 0)
  set(USE_SCRIPTPCH 0)
endif()

include(ConfigureBaseTargets)
include(CheckPlatform)

include(GroupSources)
include(AutoCollect)

find_package(PCHSupport)
find_package(MySQL)

if(NOT WITHOUT_GIT)
  find_package(Git 1.7)
endif()

# Find revision ID and hash of the sourcetree
include(cmake/genrev.cmake)

# print out the results before continuing
include(cmake/showoptions.cmake)

# add dependencies
add_subdirectory(dep)

# add core sources
add_subdirectory(src)

include(CTest)
if(BUILD_TESTING)
  list(APPEND CMAKE_MODULE_PATH
    "${Catch2_SOURCE_DIR}/contrib")
  include(Catch)

  add_subdirectory(tests)

  # Catch cmakefile messes with our settings we explicitly leave up to the user
  # restore user preference
  if (NOT WITH_SOURCE_TREE STREQUAL "hierarchical-folders")
    set_property(GLOBAL PROPERTY USE_FOLDERS OFF)
  endif()
endif()
