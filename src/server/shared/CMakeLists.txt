# Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

########### shared ###############

set(shared_STAT_SRCS
  Logging/Log.cpp
  Threading/DelayExecutor.cpp
  Threading/Threading.cpp
  Utilities/ProgressBar.cpp
  Utilities/Util.cpp
  Utilities/EventProcessor.cpp
  Common.cpp
)

include_directories(
  ${ACE_INCLUDE_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/externals/mersennetwister
  ${CMAKE_SOURCE_DIR}/externals/SFMT
  ${CMAKE_SOURCE_DIR}/externals/sockets/include
  ${CMAKE_SOURCE_DIR}/externals/utf8cpp
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
  ${MYSQL_INCLUDE_DIR}
)

add_library(shared STATIC ${shared_STAT_SRCS})

target_link_libraries(
  shared
  ${ACE_LIBRARY}
)

########### trinityconfig ###############

set(trinityconfig_STAT_SRCS
  Configuration/dotconfpp/dotconfpp.cpp
  Configuration/dotconfpp/mempool.cpp
  Configuration/Config.cpp
)

include_directories(
  ${ACE_INCLUDE_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/src/server/shared
)

add_library(trinityconfig STATIC ${trinityconfig_STAT_SRCS})

########### trinityauth ###############

set(trinityauth_STAT_SRCS
  Cryptography/Authentication/AuthCrypt.cpp
  Cryptography/BigNumber.cpp
  Cryptography/HMACSHA1.cpp
  Cryptography/SHA1.cpp
  Cryptography/MD5.c
  Cryptography/ARC4.cpp
)

include_directories(
  ${ACE_INCLUDE_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/src/server/shared
  ${MYSQL_INCLUDE_DIR}
)

add_library(trinityauth STATIC ${trinityauth_STAT_SRCS})

########### trinitydatabase ###############

set(trinitydatabase_STAT_SRCS
  DataStores/DBCFileLoader.cpp
  Database/Database.cpp
  Database/Field.cpp
  Database/QueryResult.cpp
  Database/SQLStorage.cpp
  Database/SqlDelayThread.cpp
  Database/SqlOperations.cpp
  Database/PreparedStatements.cpp
)

include_directories(
  ${ACE_INCLUDE_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/src/server/shared
  ${CMAKE_SOURCE_DIR}/src/server/shared/Database
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Object
  ${MYSQL_INCLUDE_DIR}
)

add_library(trinitydatabase STATIC ${trinitydatabase_STAT_SRCS})
