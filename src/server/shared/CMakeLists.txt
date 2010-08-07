# Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB_RECURSE sources_Configuration Configuration/*.cpp Configuration*/.h)
file(GLOB_RECURSE sources_Cryptography Cryptography/*.cpp Cryptography*/.h)
file(GLOB_RECURSE sources_Database Database/*.cpp Database*/.h)
file(GLOB_RECURSE sources_DataStores DataStores/*.cpp DataStores*/.h)
file(GLOB_RECURSE sources_Dynamic Dynamic/*.cpp Dynamic*/.h)
file(GLOB_RECURSE sources_Logging Logging/*.cpp Logging*/.h)
file(GLOB_RECURSE sources_Packets Packets/*.cpp Packets*/.h)
file(GLOB_RECURSE sources_Threading Threading/*.cpp Threading*/.h)

file(GLOB sources_localdir *.cpp *.h)

#
# Debugging/ contains platform specific files - create baselist
#

set(sources_Debugging
  Debugging/Errors.h
  Debugging/MemoryLeaks.cpp
  Debugging/MemoryLeaks.h
)

#
# Utilities/ contains platform specific files - create baselist
#

set(sources_Utilities
  Utilities/ByteConverter.h
  Utilities/EventProcessor.cpp
  Utilities/EventProcessor.h
  Utilities/ProgressBar.cpp
  Utilities/ProgressBar.h
  Utilities/SignalHandler.h
  Utilities/Timer.h
  Utilities/Util.cpp
  Utilities/Util.h
)

#
# Build shared sourcelist
#

set(shared_STAT_SRCS
  ${sources_Configuration}
  ${sources_Cryptography}
  ${sources_Database}
  ${sources_DataStores}
  ${sources_Debugging}
  ${sources_Dynamic}
  ${sources_Logging}
  ${sources_Packets}
  ${sources_Threading}
  ${sources_Utilities}
  ${sources_localdir}
)

# Windows specific files
if(WIN32)
  set(shared_STAT_SRCS
    ${shared_STAT_SRCS}
    Debugging/WheatyExceptionReport.cpp
    Utilities/ServiceWin32.cpp
  )
endif()

include_directories(
  ${ACE_INCLUDE_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/externals/mersennetwister
  ${CMAKE_SOURCE_DIR}/externals/SFMT
  ${CMAKE_SOURCE_DIR}/externals/sockets/include
  ${CMAKE_SOURCE_DIR}/externals/utf8cpp
  ${CMAKE_SOURCE_DIR}/src/server
  ${CMAKE_SOURCE_DIR}/src/server/shared
  ${CMAKE_SOURCE_DIR}/src/server/shared/Configuration
  ${CMAKE_SOURCE_DIR}/src/server/shared/Cryptography
  ${CMAKE_SOURCE_DIR}/src/server/shared/Database
  ${CMAKE_SOURCE_DIR}/src/server/shared/DataStores
  ${CMAKE_SOURCE_DIR}/src/server/shared/Debugging
  ${CMAKE_SOURCE_DIR}/src/server/shared/Dynamic
  ${CMAKE_SOURCE_DIR}/src/server/shared/Logging
  ${CMAKE_SOURCE_DIR}/src/server/shared/Packets
  ${CMAKE_SOURCE_DIR}/src/server/shared/Threading
  ${CMAKE_SOURCE_DIR}/src/server/shared/Utilities
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Object
  ${OPENSSL_INCLUDE_DIR}
  ${MYSQL_INCLUDE_DIR}
)

add_library(shared STATIC ${shared_STAT_SRCS})

if(WIN32)
  target_link_libraries(shared
    ace
  )
else()
  target_link_libraries(shared
    ${ACE_LIBRARY}
  )
endif()
