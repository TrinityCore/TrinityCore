# Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  
  Custom/argent_tournament.cpp
  Custom/custom_goldperlevel.cpp
  Custom/custom_pvpevent.cpp
  Custom/custom_quest.cpp
  Custom/custom_spell.cpp
  Custom/custom_totalizator.cpp
  Custom/dalaran_squirrel.cpp
  Custom/guildmaster.cpp
  Custom/hunterpet_vendor.cpp
  Custom/npc_arena_honor.cpp
  Custom/npc_arena_teamtop.cpp
  Custom/npc_customize.cpp
  Custom/npc_gurubashi_theme.cpp
  Custom/npc_lottery.cpp
  Custom/npc_mount.cpp
  Custom/npc_teleport.cpp
  Custom/pvpkillstreak.cpp

  Custom/npc_summon_gossip.cpp
)

message("  -> Prepared: Custom")
