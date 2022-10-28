# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
# Copyright 2019 Josua Mayer <josua.mayer97@gmail.com>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

add_library(pcg INTERFACE
 ${PCG_SRCS})

target_include_directories(pcg
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR})
