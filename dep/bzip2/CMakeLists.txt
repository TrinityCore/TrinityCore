# Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB sources *.c)

set(bzip2_STAT_SRCS
  ${sources}
)

include_directories(
  ${CMAKE_SOURCE_DIR}/dep/zlib
  ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(bzip2 STATIC ${bzip2_STAT_SRCS})
