# Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# file(GLOB_RECURSE sources_Custom Custom/*.cpp Custom/*.h)

set(scripts_STAT_SRCS
  Custom/custom.cpp
  Custom/TrialOfTheCrusader/TW_boss_faction_champions.cpp
  Custom/custom_scripts.cpp
  Custom/WorldEvents/brewfest.cpp
  Custom/cs_custom.cpp
  Custom/WorldEvents/TW_hallows_end.cpp
  Custom/WorldEvents/TW_pilgrim.cpp
  Custom/WorldEvents/TW_boss_apothecary_trio.cpp
  Custom/AzjolNerub/TW_boss_hadronox.cpp
  Custom/TrialOfTheChampion/TW_instance_trial_of_the_champion.cpp
  Custom/TrialOfTheChampion/TW_trial_of_the_champion.h
  Custom/TrialOfTheChampion/TW_boss_argent_challenge.cpp
  Custom/TrialOfTheChampion/TW_boss_grand_champions.cpp
  Custom/TrialOfTheChampion/TW_boss_black_knight.cpp
  Custom/TrialOfTheChampion/TW_trial_of_the_champion.cpp
  Custom/Ulduar/TW_boss_thorim.cpp
  Custom/Ulduar/TW_boss_mimiron.cpp
  ${scripts_STAT_SRCS}
#  ${sources_Custom}
)

message("  -> Prepared: Custom")
