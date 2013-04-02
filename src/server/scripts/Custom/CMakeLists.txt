# Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
  Custom/hunterpet_vendor.cpp
  Custom/Transmogrification.cpp
  Custom/Transmogrification.h
  Custom/chat_censure.cpp
  Custom/argent_tournament.cpp
  Custom/npc_arena_team_top.cpp
  Custom/mod_MultiKill.cpp
  Custom/npc_maniek.cpp
  Custom/npc_mmr_reset.cpp
  Custom/npc_shop.cpp
)

message("  -> Prepared: Custom")
