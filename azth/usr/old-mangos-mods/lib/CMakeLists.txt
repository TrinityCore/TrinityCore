# Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB_RECURSE sources_hw2     hw2/*.cpp hw2/*.h)

# Create game-libary
set(hw2lib_STAT_SRCS
  ${hw2lib_STAT_SRCS}
  ${sources_hw2}
)

include(../cmake/CMakeIncludeFull.txt)

add_library(hw2lib STATIC
  ${hw2lib_STAT_SRCS}
  ${hw2lib_STAT_PCH_SRC}
)

add_dependencies(hw2game revision_data.h)
