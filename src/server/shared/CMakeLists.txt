add_subdirectory(vmap)
add_subdirectory(Auth)
add_subdirectory(Config)
add_subdirectory(Database)

########### next target ###############

SET(shared_STAT_SRCS
   ByteBuffer.h
   Common.cpp
   Common.h
   DelayExecutor.cpp
   DelayExecutor.h
   Errors.h
   Log.cpp
   Log.h
   ProgressBar.cpp
   ProgressBar.h
   SignalHandler.h
   Threading.cpp
   Timer.h
   Util.cpp
   Util.h
   WorldPacket.h
   SystemConfig.h
)

include_directories(
  ${ACE_INCLUDE_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/dep/include
  ${CMAKE_SOURCE_DIR}/dep/include/sockets
  ${CMAKE_SOURCE_DIR}/src/server/framework
  ${CMAKE_SOURCE_DIR}/src/shared
  ${MYSQL_INCLUDE_DIR}
)

add_library(shared STATIC ${shared_STAT_SRCS})
target_link_libraries(
shared
${ACE_LIBRARY}
)
