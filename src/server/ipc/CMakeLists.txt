# Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB_RECURSE sources_ipc *.cpp *.h)

set(ipc_SRCS
  ${sources_ipc}
)

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/dep/zmqpp
  ${CMAKE_SOURCE_DIR}/src/server/shared/
  ${ZMQ_INCLUDE_DIR}
)

add_library(ipc STATIC ${ipc_SRCS})
