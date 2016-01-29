# Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB_RECURSE sources_zmqpp zmqpp/*.cpp zmqpp/*.hpp zmqpp/*.h)

set(zmqpp_STAT_SRCS
  ${sources_zmqpp}
)

include_directories(${ZMQ_INCLUDE_DIR})

add_library(zmqpp STATIC
  ${zmqpp_STAT_SRCS}
)

if (WIN32)
  add_definitions(-DBUILD_VERSION=\\"3.2.0\\")
else()
  add_definitions(-DBUILD_VERSION='"3.2.0"')
endif()

add_definitions(-DBUILD_VERSION_MAJOR=3)
add_definitions(-DBUILD_VERSION_MINOR=2)
add_definitions(-DBUILD_VERSION_REVISION=0)
