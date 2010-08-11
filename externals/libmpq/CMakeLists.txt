# Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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

include_directories(
  ${CMAKE_SOURCE_DIR}/externals/zlib
  ${CMAKE_SOURCE_DIR}/externals/bzip2
  ${CMAKE_SOURCE_DIR}/externals/libmpq
)

add_library(mpq STATIC ${mpq_STAT_SRCS})

set_target_properties(mpq PROPERTIES LINKER_LANGUAGE CXX)
