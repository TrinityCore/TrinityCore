# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

cmake_minimum_required(VERSION 3.18)

# add this options before PROJECT keyword
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

# Set projectname (must be done AFTER setting configurationtypes)
project(TrinityCore)

#tswow-begin add tswow sources
cmake_policy(SET CMP0135 NEW) # use local timestamps for FetchContent
include(FetchContent)

FetchContent_Declare(lua
  URL https://www.lua.org/ftp/lua-5.4.4.tar.gz
  URL_HASH MD5=bd8ce7069ff99a400efd14cf339a727b
)
FetchContent_MakeAvailable(lua)
SET(LUA_ROOT ${lua_SOURCE_DIR}/src)
file(GLOB SRC_LUA ${LUA_ROOT}/*.h ${LUA_ROOT}/*.c)
LIST(REMOVE_ITEM SRC_LUA ${CMAKE_SOURCE_DIR}/../../misc/client-extensions/lua-5.1/src/lua.c)
add_library ( liblua STATIC ${SRC_LUA} )
if(NOT WIN32)
    target_compile_options(liblua PUBLIC -fPIC)
endif()

#
# sol2
#
FetchContent_Declare (sol2
  GIT_REPOSITORY https://github.com/ThePhD/sol2
  GIT_TAG 4de99c5b41b64b7e654bf8e48b177e8414a756b7
)
FetchContent_MakeAvailable (sol2)
target_compile_definitions(sol2 INTERFACE SOL_NO_CHECK_NUMBER_PRECISION)

#
# sourcemap
#
if(FALSE)
  FetchContent_Declare (sourcemap
    GIT_REPOSITORY https://github.com/tswow/sourcemap.cpp.git
    GIT_TAG 79a901a367fdc1482306661eadfbb7d0ec50f2c2
  )
  FetchContent_MakeAvailable (sourcemap)
  file(GLOB SOURCEMAP_SRC
      ${sourcemap_SOURCE_DIR}/src/*
      ${sourcemap_SOURCE_DIR}/src/format/*
      ${sourcemap_SOURCE_DIR}/deps/json/*
      ${sourcemap_SOURCE_DIR}/deps/cencode/*
  )
  add_library(sourcemaps STATIC ${SOURCEMAP_SRC})
  target_include_directories(sourcemaps PUBLIC
      ${sourcemap_SOURCE_DIR}/src
      ${sourcemap_SOURCE_DIR}/deps/json
      ${sourcemap_SOURCE_DIR}/deps/cencode
  )
  if(NOT WIN32)
      target_compile_options(sourcemaps PUBLIC -fPIC)
  endif()
endif()

#
# tracy
#

if(WIN32)
  SET(TRACY_NO_CALLSTACK ON CACHE BOOL "" FORCE)
  SET(TRACY_NO_SAMPLING ON CACHE BOOL "" FORCE)
  SET(TRACY_NO_CALLSTACK_INLINES ON CACHE BOOL "" FORCE)
  SET(TRACY_NO_SYSTEM_TRACING ON CACHE BOOL "" FORCE)
  SET(TRACY_CALLSTACK OFF CACHE BOOL "" FORCE)
  SET(TRACY_NO_CONTEXT_SWITCH ON CACHE BOOL "" FORCE)
  SET(TRACY_NO_VSYNC_CAPTURE ON CACHE BOOL "" FORCE)
  SET(TRACY_NO_FRAME_IMAGE ON CACHE BOOL "" FORCE)
  SET(TRACY_NO_CRASH_HANDLER ON CACHE BOOL "" FORCE)
endif()
SET(TRACY_ON_DEMAND ON CACHE BOOL "" FORCE)
SET(TRACY_ONLY_LOCALHOST OFF CACHE BOOL "" FORCE)
FetchContent_Declare (
  tracy
  GIT_REPOSITORY https://github.com/wolfpld/tracy.git
  GIT_TAG a8511d357650282c6915f7aa9775e9c4945e42b5
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable (tracy)
target_compile_definitions(TracyClient
  PRIVATE
  TRACY_DATA_PORT=8084
  TRACY_ON_DEMAND=1
)

# note: temporary workaround until the latest server that tracy publishes
# does this automatically via CMake.
if(TRACY_TIMER_FALLBACK)
  target_compile_definitions(TracyClient PRIVATE TRACY_TIMER_FALLBACK=1)
endif()

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
cmake_policy(SET CMP0043 NEW) # Ignore COMPILE_DEFINITIONS_<Config> properties
cmake_policy(SET CMP0054 NEW) # Only interpret if() arguments as variables or keywords when unquoted - prevents intepreting if(SOME_STRING_VARIABLE MATCHES "MSVC") as if(SOME_STRING_VARIABLE MATCHES "1")
cmake_policy(SET CMP0074 NEW) # find_package() uses <PackageName>_ROOT variables

if(POLICY CMP0144)
  cmake_policy(SET CMP0144 NEW) # find_package() uses upper-case <PACKAGENAME>_ROOT variables
endif()

# Set RPATH-handing (CMake parameters)
set(CMAKE_SKIP_BUILD_RPATH 0)
set(CMAKE_BUILD_WITH_INSTALL_RPATH 0)
list(APPEND CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH 1)

# set macro-directory
list(APPEND CMAKE_MODULE_PATH
  "${CMAKE_SOURCE_DIR}/cmake/macros")

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

if(NOT WITHOUT_GIT)
  find_package(Git 1.7)
endif()

# find mysql client binary (needed by genrev)
find_package(MySQL OPTIONAL_COMPONENTS binary)

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
