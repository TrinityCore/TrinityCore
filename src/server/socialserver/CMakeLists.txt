# Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB_RECURSE sources_socialsrv *.cpp *.h)

set(social_STAT_SRCS
  ${sources_socialsrv}
)

if(UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()


include_directories(
  ${CMAKE_SOURCE_DIR}/dep/
  ${ACE_INCLUDE_DIR}
)

add_executable(socialserver 
  ${social_STAT_SRCS}
)

target_link_libraries(socialserver
  zmqpp
  ${ACE_LIBRARY}
)