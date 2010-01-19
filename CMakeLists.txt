PROJECT(Trinity)
cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0005 OLD)

include(CheckIncludeFiles)
include(cmake/FindAce.cmake)
include(cmake/FindMySql.cmake)
include(cmake/FindPostgreSql.cmake)
include(cmake/FindReadline.cmake)
include(cmake/FindTermcap.cmake)
CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
  IMMEDIATE @ONLY)
ADD_CUSTOM_TARGET(uninstall "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake")

OPTION(DO_MYSQL "With MySQL support" 1)
OPTION(DO_POSTGRESQL "With PostgreSQL support" 0) # not complete yet, may not link properly.
OPTION(DO_SCRIPTS "With trinityscripts" 1)
OPTION(DO_CLI "With CLI" 1)
OPTION(DO_RA "With RA" 0)
OPTION(DO_DEBUG "Debug mode" 0)
OPTION(DO_WARN "Enable all compile warnings" 0)
OPTION(CENTOS "CENTOS" 0)

SET(GENREV_SRC
src/tools/genrevision/genrevision.cpp
)

if (DO_DEBUG)
    ADD_EXECUTABLE(genrev
    ${GENREV_SRC}
    )
    ADD_CUSTOM_TARGET("revision.h" ALL
        COMMAND "${Trinity_BINARY_DIR}/genrev"
        ${Trinity_SOURCE_DIR}
        WORKING_DIRECTORY "${Trinity_SOURCE_DIR}/src/shared"
        DEPENDS genrev
    )
else (DO_DEBUG)
    ADD_EXECUTABLE(genrev
    ${GENREV_SRC}
    )
    ADD_CUSTOM_TARGET("revision.h" ALL
        COMMAND "${Trinity_BINARY_DIR}/genrev"
        ${Trinity_SOURCE_DIR}
        WORKING_DIRECTORY "${Trinity_SOURCE_DIR}/src/shared"
        DEPENDS genrev
    )
endif (DO_DEBUG)


EXECUTE_PROCESS(
        COMMAND hg tip --template {rev}
        OUTPUT_VARIABLE HG_REVISION
)

message("* TrinityCore2 revision: ${HG_REVISION}")

IF (PREFIX)
    SET(CMAKE_INSTALL_PREFIX ${PREFIX})
ENDIF (PREFIX)

if(CONF_DIR)

else(CONF_DIR)
SET(CONF_DIR ${PREFIX}/etc)
endif(CONF_DIR)
SET(LIBSDIR ${CMAKE_INSTALL_PREFIX}/lib)

message("* Will install to: ${CMAKE_INSTALL_PREFIX}")
message("* With config dir at: ${CONF_DIR}")
message("* Libs install dir at: ${LIBSDIR}")

FIND_LIBRARY(SSLLIB NAMES ssl DOC "SSL library")
FIND_LIBRARY(ZLIB z "Zlib library")

IF(DO_POSTGRESQL)
    SET(DO_MYSQL 0)
    MESSAGE("* With PostgreSQL")
    FIND_PostgreSQL()
    ADD_DEFINITIONS(-DDO_POSTGRESQL)
ENDIF(DO_POSTGRESQL)

IF(DO_MYSQL)
    MESSAGE("* With MySQL")
    FIND_MYSQL()
    ADD_DEFINITIONS(-DDO_MYSQL)
ENDIF(DO_MYSQL)

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

IF(UNIX)
    IF(CENTOS)
        add_definitions(-DCENTOS)
        MESSAGE("* Building with termcap")
        FIND_TERMCAP()
    ELSE(CENTOS)
        MESSAGE("* Building with readline")
        FIND_READLINE()
    ENDIF(CENTOS)
ENDIF(UNIX)

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
#SET(BUILD_ACE 1)
#SET(ACE_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/dep/ACE_wrappers ${CMAKE_BINARY_DIR}/dep/ACE_wrappers")
#SET(ACE_LIBRARY ACE)
#message(STATUS "I will try to build ACE from: ${ACE_INCLUDE_DIR}")
#message(STATUS "And link using: ${ACE_LIBRARY}")
endif(ACE_FOUND)

#somehow line below don't work. so for now change it to if exist
#check_include_files(${ACE_INCLUDE_DIR}/ace/Stack_Trace.h HAVE_ACE_STACK_TRACE_H)
IF(EXISTS ${ACE_INCLUDE_DIR}/ace/Stack_Trace.h)
    SET(HAVE_ACE_STACK_TRACE_H 1)
ELSE(EXISTS ${ACE_INCLUDE_DIR}/ace/Stack_Trace.h)
    message(STATUS "** Your libace is out of date. Please update your libace!")
ENDIF(EXISTS ${ACE_INCLUDE_DIR}/ace/Stack_Trace.h)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config.h)

IF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
  SET(OSX_LIBS /opt/local/lib/libcrypto.dylib)
  add_definitions(-D__ASSERTMACROS__)
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")


add_definitions(--no-warnings) #to make build look nice, no gcc nazi warnings.

INCLUDE_DIRECTORIES(
dep/include 
dep/include/g3dlite 
dep/include/sockets
src/shared 
src/framework 
src/shared/Database 
src/shared/vmap
src/game 
${CMAKE_BINARY_DIR}
${MYSQL_INCLUDE_DIR} 
${POSTGRESQL_INCLUDE_DIR}
${POSTGRESQL_INCLUDE_DIR}/libpq-4/
${POSTGRESQL_INCLUDE_DIR}/libpq-4/server/ 
${CMAKE_CURRENT_BINARY_DIR}/src/shared 
${CMAKE_CURRENT_SOURCE_DIR}/..
${ACE_INCLUDE_DIR}
)

SET(CMAKE_SKIP_BUILD_RPATH FALSE)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

add_subdirectory(dep)
#add_subdirectory(doc)
add_subdirectory(src)
add_subdirectory(sql)
