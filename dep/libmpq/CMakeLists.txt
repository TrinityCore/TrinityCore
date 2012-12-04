# Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB sources_mpq libmpq/*.c libmpq/*.h)

set(mpq_STAT_SRCS
  ${sources_mpq}
)

if( UNIX )
  include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/dep/zlib
    ${CMAKE_SOURCE_DIR}/dep/bzip2
  )
elseif( WIN32 )
  include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/win
    ${CMAKE_SOURCE_DIR}/dep/zlib
    ${CMAKE_SOURCE_DIR}/dep/bzip2
  )
endif()

add_library(mpq STATIC ${mpq_STAT_SRCS})

set_target_properties(mpq PROPERTIES LINKER_LANGUAGE CXX)
