add_subdirectory(vmap)
add_subdirectory(Auth)
add_subdirectory(Config)
add_subdirectory(Database)

########### next target ###############

SET(shared_STAT_SRCS
   Base.cpp
   Base.h
   ByteBuffer.h
   Common.cpp
   Common.h
   Errors.h
   Log.cpp
   Log.h
   Mthread.cpp
   Mthread.h
   ProgressBar.cpp
   ProgressBar.h
   Timer.h
   Util.cpp
   Util.h
   WorldPacket.h
   SystemConfig.h
)

add_library(shared STATIC ${shared_STAT_SRCS})
