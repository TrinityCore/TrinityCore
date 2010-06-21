# Copyright (C) 2005-2009 MaNGOS project <http://getmangos.com/>
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
file(GLOB loadlib_sources loadlib/*.cpp)

include_directories (
  ${CMAKE_SOURCE_DIR}/src/server/shared
  ${CMAKE_SOURCE_DIR}/externals/libmpq
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/loadlib
)

link_directories(
  ${CMAKE_SOURCE_DIR}/externals/libmpq/libmpq
  ${CMAKE_CURRENT_SOURCE_DIR}}/loadlib
)

add_library(loadlib
  ${loadlib_sources}
)

if(NOT UNIX)
  target_link_libraries(loadlib
    zlib
  )
else()
  target_link_libraries(loadlib
    ${ZLIB_LIBRARIES}
  )
endif()

add_library(libmpq
  ${CMAKE_SOURCE_DIR}/externals/libmpq/libmpq/common.c
  ${CMAKE_SOURCE_DIR}/externals/libmpq/libmpq/explode.c
  ${CMAKE_SOURCE_DIR}/externals/libmpq/libmpq/extract.c
  ${CMAKE_SOURCE_DIR}/externals/libmpq/libmpq/huffman.c
  ${CMAKE_SOURCE_DIR}/externals/libmpq/libmpq/mpq.c
  ${CMAKE_SOURCE_DIR}/externals/libmpq/libmpq/wave.c
)

add_executable(mapextractor
  ${sources}
)

if(WIN32)
  target_link_libraries(mapextractor
    libmpq
    loadlib
    bzip2
  )
else()
  target_link_libraries(mapextractor
    libmpq
    loadlib
    ${BZIP2_LIBRARIES}
  )
endif()

install(TARGETS mapextractor DESTINATION bin)
