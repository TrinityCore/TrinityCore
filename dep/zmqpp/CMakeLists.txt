# Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB_RECURSE sources_zmqpp *.cpp *.h)

set(zmqpp_STAT_SRCS
  ${sources_zmqpp}
  )

add_library(zmqpp STATIC
  ${zmqpp_STAT_SRCS}
  )

add_definitions(-DBUILD_VERSION='"3.1.0"')
add_definitions(-DBUILD_VERSION_MAJOR=3)
add_definitions(-DBUILD_VERSION_MINOR=1)
add_definitions(-DBUILD_VERSION_REVISION=0)

if(UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

target_link_libraries(zmqpp
  zmq
)