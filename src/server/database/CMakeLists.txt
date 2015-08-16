# Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

if( USE_COREPCH )
  include_directories(${CMAKE_CURRENT_BINARY_DIR})
endif()

file(GLOB_RECURSE sources_Database Database/*.cpp Database/*.h)
file(GLOB_RECURSE sources_Logging Logging/*.cpp Logging/*.h)
file(GLOB_RECURSE sources_Updater Updater/*.cpp Updater/*.h)

file(GLOB sources_localdir *.cpp *.h)

#
# Build shared sourcelist
#

if (USE_COREPCH)
  set(database_STAT_PCH_HDR PrecompiledHeaders/databasePCH.h)
  set(database_STAT_PCH_SRC PrecompiledHeaders/databasePCH.cpp)
endif()

set(database_STAT_SRCS
  ${database_STAT_SRCS}
  ${sources_Database}
  ${sources_Logging}
  ${sources_Updater}
)

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/dep/recastnavigation/Detour
  ${CMAKE_SOURCE_DIR}/dep/SFMT
  ${CMAKE_SOURCE_DIR}/dep/cppformat
  ${CMAKE_SOURCE_DIR}/dep/utf8cpp
  ${CMAKE_SOURCE_DIR}/dep/process
  ${CMAKE_SOURCE_DIR}/src/server
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/Database
  ${CMAKE_CURRENT_SOURCE_DIR}/Logging
  ${CMAKE_CURRENT_SOURCE_DIR}/Updater
  ${CMAKE_SOURCE_DIR}/src/common/
  ${CMAKE_SOURCE_DIR}/src/common/Collision
  ${CMAKE_SOURCE_DIR}/src/common/Collision/Management
  ${CMAKE_SOURCE_DIR}/src/common/Collision/Models
  ${CMAKE_SOURCE_DIR}/src/common/Debugging
  ${CMAKE_SOURCE_DIR}/src/common/Threading
  ${CMAKE_SOURCE_DIR}/src/common/Utilities
  ${CMAKE_SOURCE_DIR}/src/common/Configuration
  ${CMAKE_SOURCE_DIR}/src/common/Logging
  ${CMAKE_SOURCE_DIR}/src/server/shared
  ${MYSQL_INCLUDE_DIR}
  ${OPENSSL_INCLUDE_DIR} # seems needed for Windows build
  ${VALGRIND_INCLUDE_DIR}
)

GroupSources(${CMAKE_CURRENT_SOURCE_DIR})

add_library(database STATIC
  ${database_STAT_SRCS}
  ${database_STAT_PCH_SRC}
)

# Generate precompiled header
if (USE_COREPCH)
  add_cxx_pch(database ${database_STAT_PCH_HDR} ${database_STAT_PCH_SRC})
endif ()
