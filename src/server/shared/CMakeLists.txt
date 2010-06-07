########### shared ###############

SET(shared_STAT_SRCS
   Debugging/Errors.h
   Logging/Log.cpp
   Logging/Log.h
   Packets/ByteBuffer.h
   Packets/WorldPacket.h
   Policies/ObjectLifeTime.cpp
   Threading/DelayExecutor.cpp
   Threading/DelayExecutor.h
   Threading/Threading.cpp
   Utilities/ProgressBar.cpp
   Utilities/ProgressBar.h
   Utilities/SignalHandler.h
   Utilities/Timer.h
   Utilities/Util.cpp
   Utilities/Util.h
   Common.cpp
   Common.h
   SystemConfig.h
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
  ${CMAKE_SOURCE_DIR}/src/server/shared/Policies
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

SET(trinityconfig_STAT_SRCS
   Configuration/dotconfpp/dotconfpp.cpp
   Configuration/dotconfpp/dotconfpp.h
   Configuration/dotconfpp/mempool.cpp
   Configuration/dotconfpp/mempool.h
   Configuration/Config.cpp
   Configuration/Config.h
   Configuration/ConfigEnv.h
)

include_directories(
  ${ACE_INCLUDE_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/src/server/shared
)

add_library(trinityconfig STATIC ${trinityconfig_STAT_SRCS})

########### trinityauth ###############

SET(trinityauth_STAT_SRCS
   Cryptography/Authentication/AuthCrypt.cpp
   Cryptography/Authentication/AuthCrypt.h
   Cryptography/BigNumber.cpp
   Cryptography/BigNumber.h
   Cryptography/HMACSHA1.cpp
   Cryptography/HMACSHA1.h
   Cryptography/SHA1.cpp
   Cryptography/SHA1.h
   Cryptography/MD5.c
   Cryptography/MD5.h
   Cryptography/ARC4.cpp
   Cryptography/ARC4.h
)

include_directories(
  ${ACE_INCLUDE_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/src/server/shared
  ${MYSQL_INCLUDE_DIR}
)

add_library(trinityauth STATIC ${trinityauth_STAT_SRCS})

########### trinitydatabase ###############

SET(trinitydatabase_STAT_SRCS
    DataStores/DBCFileLoader.cpp
    DataStores/DBCFileLoader.h
    DataStores/DBCStore.h
    Database/Database.cpp
    Database/Database.h
    Database/DatabaseEnv.h
    Database/DatabaseImpl.h
    Database/Field.cpp
    Database/Field.h
    Database/QueryResult.cpp
    Database/QueryResult.h
    Database/SQLStorage.cpp
    Database/SQLStorage.h
    Database/SqlDelayThread.cpp
    Database/SqlDelayThread.h
    Database/SqlOperations.cpp
    Database/SqlOperations.h
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