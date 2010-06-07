add_subdirectory(Configuration)
add_subdirectory(Cryptography)
add_subdirectory(Database)
add_subdirectory(DataStores)
add_subdirectory(Debugging)
add_subdirectory(Dynamic)
add_subdirectory(Logging)
add_subdirectory(Packets)
add_subdirectory(Policies)
add_subdirectory(Threading)
add_subdirectory(Utilities)

########### next target ###############

SET(shared_STAT_SRCS
   Debugging/Errors.h
   Logging/Log.cpp
   Logging/Log.h
   Packets/ByteBuffer.h
   Packets/WorldPacket.h
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
  ${CMAKE_BINARY_DIR}/externals/SFMT
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
