# Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

file(GLOB_RECURSE sources_Configuration Configuration/*.cpp Configuration/*.h)
file(GLOB_RECURSE sources_Cryptography Cryptography/*.cpp Cryptography/*.h)
file(GLOB_RECURSE sources_Database Database/*.cpp Database/*.h)
file(GLOB_RECURSE sources_DataStores DataStores/*.cpp DataStores/*.h)
file(GLOB_RECURSE sources_Dynamic Dynamic/*.cpp Dynamic/*.h)
file(GLOB_RECURSE sources_Logging Logging/*.cpp Logging/*.h)
file(GLOB_RECURSE sources_Packets Packets/*.cpp Packets/*.h)
file(GLOB_RECURSE sources_Threading Threading/*.cpp Threading/*.h)
file(GLOB_RECURSE sources_Utilities Utilities/*.cpp Utilities/*.h)

file(GLOB sources_localdir *.cpp *.h)

#
# Build shared sourcelist
#

if( USE_COREPCH AND MSVC )
  set(shared_STAT_SRCS
    PrecompiledHeaders/sharedPCH.cpp
    PrecompiledHeaders/sharedPCH.h
  )
endif()

set(shared_STAT_SRCS
  ${shared_STAT_SRCS}
  ${sources_Configuration}
  ${sources_Cryptography}
  ${sources_Database}
  ${sources_DataStores}
  ${sources_Dynamic}
  ${sources_Logging}
  ${sources_Packets}
  ${sources_Threading}
  ${sources_Utilities}
  ${sources_localdir}
  Debugging/Errors.h
)

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/dep/SFMT
  ${CMAKE_SOURCE_DIR}/dep/mersennetwister
  ${CMAKE_SOURCE_DIR}/dep/sockets/include
  ${CMAKE_SOURCE_DIR}/dep/utf8cpp
  ${CMAKE_SOURCE_DIR}/src/server
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/Configuration
  ${CMAKE_CURRENT_SOURCE_DIR}/Cryptography
  ${CMAKE_CURRENT_SOURCE_DIR}/Database
  ${CMAKE_CURRENT_SOURCE_DIR}/DataStores
  ${CMAKE_CURRENT_SOURCE_DIR}/Debugging
  ${CMAKE_CURRENT_SOURCE_DIR}/Dynamic
  ${CMAKE_CURRENT_SOURCE_DIR}/Logging
  ${CMAKE_CURRENT_SOURCE_DIR}/Packets
  ${CMAKE_CURRENT_SOURCE_DIR}/Threading
  ${CMAKE_CURRENT_SOURCE_DIR}/Utilities
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Object
  ${ACE_INCLUDE_DIR}
  ${MYSQL_INCLUDE_DIR}
  ${OPENSSL_INCLUDE_DIR}
)

add_library(shared STATIC ${shared_STAT_SRCS})

target_link_libraries(shared
  ${ACE_LIBRARY}
)

# Generate precompiled header
if( USE_COREPCH )
  if(CMAKE_COMPILER_IS_GNUCXX)
    add_precompiled_header(shared ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders/sharedPCH.h)
  elseif(MSVC)
    add_native_precompiled_header(shared ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders/sharedPCH)
  endif()
endif()

