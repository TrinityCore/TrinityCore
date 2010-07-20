# Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB sources *.cpp)

set(g3dlib_STAT_SRCS
  ${sources}
)
if(WIN32)
  include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/externals/zlib
  )
else()
  include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
  )
endif()

add_library(g3dlib STATIC ${g3dlib_STAT_SRCS})

if(WIN32)
  target_link_libraries(g3dlib
    zlib
  )
else()
  target_link_libraries(g3dlib
    ${ZLIB_LIBRARIES}
  )
endif()
