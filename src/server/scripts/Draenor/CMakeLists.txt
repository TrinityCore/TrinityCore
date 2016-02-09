# Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  include(Draenor/Auchindoun/CMakeLists.txt)
  include(Draenor/BloodmaulSlagMines/CMakeLists.txt)
  include(Draenor/GrimrailDepot/CMakeLists.txt)
  include(Draenor/Highmaul/CMakeLists.txt)
  include(Draenor/IronDocks/CMakeLists.txt)
  include(Draenor/ShadowmoonBurialGrounds/CMakeLists.txt)
  include(Draenor/Skyreach/CMakeLists.txt)
  include(Draenor/TheEverbloom/CMakeLists.txt)
  include(Draenor/UpperBlackrockSpire/CMakeLists.txt)

  
file(GLOB scripts_Draenor Draenor/*.cpp Draenor/*.h)

source_group(Draenor FILES ${scripts_Draenor})

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  ${scripts_Draenor}
)

message("  -> Prepared: Draenor")
