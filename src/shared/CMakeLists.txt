add_subdirectory(vmap)
add_subdirectory(Auth)
add_subdirectory(Config)
add_subdirectory(Database)

########### next target ###############

SET(shared_STAT_SRCS
   ByteBuffer.h
   Common.cpp
   Common.h
   Errors.h
   Log.cpp
   Log.h
   ProgressBar.cpp
   ProgressBar.h
   Threading.cpp
   Timer.h
   Util.cpp
   Util.h
   WorldPacket.h
   SystemConfig.h
)
add_definitions(-fopenmp)
add_library(shared STATIC ${shared_STAT_SRCS})
target_link_libraries(
shared
${ACE_LIBRARY}
)
