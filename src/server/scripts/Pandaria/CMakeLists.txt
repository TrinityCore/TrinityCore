# Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# Gate of the Setting Sun
file(GLOB_RECURSE sources_GateOfTheSettingSun Pandaria/GateOfTheSettingSun/*.h Pandaria/GateOfTheSettingSun/*.cpp)
# Heart of Fear
file(GLOB_RECURSE sources_HeartOfFear Pandaria/HeartOfFear/*.h Pandaria/HeartOfFear/*.cpp)
# Mogushan Palace
file(GLOB_RECURSE sources_MogushanPalace Pandaria/MogushanPalace/*.h Pandaria/MogushanPalace/*.cpp)
# Mogushan Vaults
file(GLOB_RECURSE sources_MogushanVaults Pandaria/MogushanVaults/*.h Pandaria/MogushanVaults/*.cpp)
# Shadopan Monastery
file(GLOB_RECURSE sources_ShadopanMonastery Pandaria/ShadopanMonastery/*.h Pandaria/ShadopanMonastery/*.cpp)
# Siege of Niuzao Temple
file(GLOB_RECURSE sources_SiegeOfNiuzaoTemple Pandaria/SiegeOfNiuzaoTemple/*.h Pandaria/SiegeOfNiuzaoTemple/*.cpp)
# Stormstout Brewery
file(GLOB_RECURSE sources_StormstoutBrewery Pandaria/StormstoutBrewery/*.h Pandaria/StormstoutBrewery/*.cpp)
# Temple of the Jade Serpent
file(GLOB_RECURSE sources_TempleOfTheJadeSerpent Pandaria/TempleOfTheJadeSerpent/*.h Pandaria/TempleOfTheJadeSerpent/*.cpp)
# Terrace of Endless Spring
file(GLOB_RECURSE sources_TerraceOfEndlessSpring Pandaria/TerraceOfEndlessSpring/*.h Pandaria/TerraceOfEndlessSpring/*.cpp)
# Throne of Thunder
file(GLOB_RECURSE sources_ThroneOfThunder Pandaria/ThroneOfThunder/*.h Pandaria/ThroneOfThunder/*.cpp)
# Siege of Orgrimmar
file(GLOB_RECURSE sources_SiegeOfOrgrimmar Pandaria/SiegeOfOrgrimmar/*.h Pandaria/SiegeOfOrgrimmar/*.cpp)
# Wandering Island
file(GLOB_RECURSE sources_WanderingIsland Pandaria/WanderingIsland/*.h Pandaria/WanderingIsland/*.cpp)
# World Bosses
file(GLOB_RECURSE sources_WorldBosses Pandaria/WorldBosses/*.h Pandaria/WorldBosses/*.cpp)
# August Celestials
file(GLOB_RECURSE sources_AugustCelestials Pandaria/WorldBosses/AugustCelestials/*.h Pandaria/WorldBosses/AugustCelestials/*.cpp)
# Zones
file(GLOB_RECURSE sources_Zones Pandaria/Zones/*.h Pandaria/Zones/*.cpp)

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  ${sources_GateOfTheSettingSun}
  ${sources_HeartOfFear}
  ${sources_MogushanPalace}
  ${sources_MogushanVaults}
  ${sources_ShadopanMonastery}
  ${sources_SiegeOfNiuzaoTemple}
  ${sources_StormstoutBrewery}
  ${sources_TempleOfTheJadeSerpent}
  ${sources_TerraceOfEndlessSpring}
  ${sources_ThroneOfThunder}
  ${sources_SiegeOfOrgrimmar}
  ${sources_WanderingIsland}
  ${sources_WorldBosses}
  ${sources_AugustCelestials}
  ${sources_Zones}
)

message("  -> Prepared: Pandaria")
