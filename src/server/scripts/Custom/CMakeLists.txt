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
Custom/TrialOfTheCrusader/TW_boss_faction_champions.cpp
Custom/HallsOfReflection/TW_boss_falric_marwyn.cpp
Custom/HallsOfReflection/TW_boss_hor_lichking.cpp
Custom/HallsOfReflection/TW_halls_of_reflection_trash.cpp
Custom/HallsOfReflection/TW_instance_halls_of_reflection.cpp
Custom/HallsOfReflection/TW_npc_jaina_or_sylvanas_hor.cpp
Custom/HallsOfReflection/TW_npc_frostsworn_general.cpp
  ${scripts_STAT_SRCS}
)

message("  -> Prepared: Custom")
