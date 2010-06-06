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
add_custom_target(uninstall "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake")

option(DO_MYSQL "With MySQL support" 1)
option(DO_SCRIPTS "With trinityscripts" 1)
option(DO_CLI "With CLI" 1)
option(DO_RA "With RA" 0)
option(DO_DEBUG "Debug mode" 0)
option(DO_WARN "Enable all compile warnings" 0)
option(DO_WARN "Enable all compile warnings" 0)
option(CENTOS "CENTOS" 0)
option(DO_SQL "Copy SQL files" 0)
option(DO_PCH "Use precompiled headers" 1)

set(GENREV_SRC
src/genrevision/genrevision.cpp
)

if(DO_DEBUG)
    add_executable(genrev
    ${GENREV_SRC}
    )
    add_custom_target("revision.h" ALL
        COMMAND "${CMAKE_BINARY_DIR}/genrev"
        ${CMAKE_SOURCE_DIR}
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/src/shared"
        DEPENDS genrev
    )
else (DO_DEBUG)
    add_executable(genrev
    ${GENREV_SRC}
    )
    add_custom_target("revision.h" ALL
        COMMAND "${CMAKE_BINARY_DIR}/genrev"
        ${CMAKE_SOURCE_DIR}
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/src/shared"
        DEPENDS genrev
    )
endif(DO_DEBUG)


execute_process(
        COMMAND hg tip --template {rev}
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
        OUTPUT_VARIABLE HG_REVISION
)

message("* TrinityCore revision: ${HG_REVISION}")

if(PREFIX)
    set(CMAKE_INSTALL_PREFIX ${PREFIX})
endif(PREFIX)

if(CONF_DIR)

else(CONF_DIR)
    set(CONF_DIR ${PREFIX}/etc)
endif(CONF_DIR)
set(LIBSDIR ${CMAKE_INSTALL_PREFIX}/lib)

message("* Will install to: ${CMAKE_INSTALL_PREFIX}")
message("* With config dir at: ${CONF_DIR}")
message("* Libs install dir at: ${LIBSDIR}")

find_library(SSLLIB NAMES ssl DOC "SSL library")
find_library(ZLIB z "Zlib library")

if(DO_MYSQL)
    message("* With MySQL")
    FIND_MYSQL()
    ADD_DEFINITIONS(-DDO_MYSQL)
endif(DO_MYSQL)

if(DO_SCRIPTS)
    message("* With Trinity Scripts")
    ADD_DEFINITIONS(-DDO_SCRIPTS)
    add_definitions(-D_TRINITY_SCRIPT_CONFIG='"${CONF_DIR}/trinitycore.conf"')
else (DO_SCRIPTS)
    message("* Without Trinity Scripts")
endif(DO_SCRIPTS)

message("-- Miscellaneus options:")

if(DO_CLI)
    message("* With CLI")
    add_definitions(-DENABLE_CLI)
else (DO_CLI)
    message(* Without CLI)
endif(DO_CLI)

if(DO_RA)
    message("* With RA")
    add_definitions(-DENABLE_RA)
else(DO_RA)
    message("* Without RA")
endif(DO_RA)

if(DO_DEBUG)
    message("* Debug mode ON")
    add_definitions(-g -DTRINITY_DEBUG)
endif(DO_DEBUG)

if(DO_WARN)
    message("* All warnings mode")
    add_definitions(-Wall -Wfatal-errors -Wextra)
endif(DO_WARN)

if(UNIX)
    if(CENTOS)
        add_definitions(-DCENTOS)
        message("* Building with termcap")
        FIND_TERMCAP()
    else(CENTOS)
        message("* Building with readline")
        FIND_READLINE()
    endif(CENTOS)
endif(UNIX)

FIND_ACE(ACE)
if(ACE_FOUND)
    message(STATUS "Found ACE library: ${ACE_LIBRARY}")
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


add_definitions(--no-warnings) #to make build look nice, no gcc nazi warnings.

set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

#add_subdirectory(doc)
add_subdirectory(dep)
add_subdirectory(src)
if(DO_SQL)
    message("* Copy SQL files ON")
    add_subdirectory(sql)
endif(DO_SQL)

