# Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB_RECURSE sources_ha *.cpp *.h)

set(ha_SRCS
  ${sources_ha}
)

if (UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -pedantic -Wall -Wextra")
endif()

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/dep/zmqpp
  ${CMAKE_SOURCE_DIR}/src/server/shared/
  ${ZMQ_INCLUDE_DIR}
  ${ACE_INCLUDE_DIR}
)

add_library(ha STATIC ${ha_SRCS})

target_link_libraries(ha
  ${ZMQ_LIBRARY}
  ${ACE_LIBRARY}
)
