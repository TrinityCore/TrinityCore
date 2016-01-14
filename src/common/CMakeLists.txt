# Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

file(GLOB_RECURSE sources_Common Common.cpp Common.h)
file(GLOB_RECURSE sources_Collision Collision/*.cpp Collision/*.h)
file(GLOB_RECURSE sources_Threading Threading/*.cpp Threading/*.h)
file(GLOB_RECURSE sources_Utilities Utilities/*.cpp Utilities/*.h)
file(GLOB_RECURSE sources_Configuration Configuration/*.cpp Configuration/*.h)
file(GLOB_RECURSE sources_Logging Logging/*.cpp Logging/*.h)
if (SERVERS)
  file(GLOB_RECURSE sources_Cryptography Cryptography/*.cpp Cryptography/*.h)
endif (SERVERS)

# Manually set sources for Debugging directory as we don't want to include WheatyExceptionReport in common project
# It needs to be included both in authserver and worldserver for the static global variable to be properly initialized
# and to handle crash logs on windows
set(sources_Debugging Debugging/Errors.cpp Debugging/Errors.h)
file(GLOB sources_localdir *.cpp *.h)

if (USE_COREPCH)
  set(common_STAT_PCH_HDR PrecompiledHeaders/commonPCH.h)
  set(common_STAT_PCH_SRC PrecompiledHeaders/commonPCH.cpp)
endif (USE_COREPCH)

set(common_STAT_SRCS
  ${common_STAT_SRCS}
  ${sources_Common}
  ${sources_Collision}
  ${sources_Threading}
  ${sources_Utilities}
  ${sources_Debugging}
  ${sources_Configuration}
  ${sources_Logging}
  ${sources_Cryptography}
  ${sources_localdir}
)

# Do NOT add any extra include directory here, as we don't want the common
# library to depend on anything else than TC deps, and itself.
# This way we ensure that if either a PR does that without modifying this file,
# a compile error will be generated, either this file will be modified so it
# is detected more easily.
# While it is OK to include files from other libs as long as they don't require
# linkage (enums, defines...) it is discouraged to do so unless necessary, as it will pullute
# include_directories leading to further unnoticed dependency aditions
# Linker Depencency requirements: none
include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/Collision
  ${CMAKE_CURRENT_SOURCE_DIR}/Collision/Management
  ${CMAKE_CURRENT_SOURCE_DIR}/Collision/Maps
  ${CMAKE_CURRENT_SOURCE_DIR}/Collision/Models
  ${CMAKE_CURRENT_SOURCE_DIR}/Configuration
  ${CMAKE_CURRENT_SOURCE_DIR}/Cryptography
  ${CMAKE_CURRENT_SOURCE_DIR}/Debugging
  ${CMAKE_CURRENT_SOURCE_DIR}/Logging
  ${CMAKE_CURRENT_SOURCE_DIR}/Utilities
  ${CMAKE_SOURCE_DIR}/dep/cppformat
  ${CMAKE_SOURCE_DIR}/dep/g3dlite/include
  ${CMAKE_SOURCE_DIR}/dep/recastnavigation/Detour/Include
  ${CMAKE_SOURCE_DIR}/dep/SFMT
  ${CMAKE_SOURCE_DIR}/dep/utf8cpp
  ${OPENSSL_INCLUDE_DIR}
  ${VALGRIND_INCLUDE_DIR}
)

GroupSources(${CMAKE_CURRENT_SOURCE_DIR})

add_library(common STATIC
  ${common_STAT_SRCS}
  ${common_STAT_PCH_SRC}
)

add_dependencies(common revision_data.h)

# Generate precompiled header
if (USE_COREPCH)
  add_cxx_pch(common ${common_STAT_PCH_HDR} ${common_STAT_PCH_SRC})
endif ()
