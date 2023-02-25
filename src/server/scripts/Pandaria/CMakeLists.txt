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
  Pandaria/WorldBosses/boss_chi_ji.cpp
  Pandaria/WorldBosses/boss_galion.cpp
  Pandaria/WorldBosses/boss_nalak.cpp
  Pandaria/WorldBosses/boss_niuzao.cpp
  Pandaria/WorldBosses/boss_oondasta.cpp
  Pandaria/WorldBosses/boss_ordos.cpp
  Pandaria/WorldBosses/boss_sha_of_anger.cpp
  Pandaria/WorldBosses/boss_xuen.cpp
  Pandaria/WorldBosses/boss_yu_lon.cpp

  Pandaria/MogushanPalace/instance_mogu_shan_palace.cpp
  Pandaria/MogushanPalace/boss_trial_of_the_king.cpp
  Pandaria/MogushanPalace/boss_gekkan.cpp
  Pandaria/MogushanPalace/boss_xin_the_weaponmaster.cpp
  Pandaria/MogushanPalace/mogu_shan_palace.h

  Pandaria/TempleJadeSerpent/instance_temple_of_jade_serpent.cpp
  temple_of_jade_serpent.h
  Pandaria/TempleJadeSerpent/boss_wise_mari.cpp
  Pandaria/TempleJadeSerpent/boss_lorewalker_stonestep.cpp
  Pandaria/TempleJadeSerpent/boss_liu_flameheart.cpp
  Pandaria/TempleJadeSerpent/boss_sha_of_doubt.cpp

 // Pandaria/StormstoutBrewery/boss_hoptallus.cpp
  Pandaria/StormstoutBrewery/boss_ook_ook.cpp
 // Pandaria/StormstoutBrewery/boss_yanzhu_the_uncasked.cpp
  Pandaria/StormstoutBrewery/instance_stormstout_brewery.cpp
  Pandaria/StormstoutBrewery/stormstout_brewery.cpp
  Pandaria/StormstoutBrewery/stormstout_brewery.h

  Pandaria/GateSettingSun/instance_gate_setting_sun.cpp
  Pandaria/GateSettingSun/gate_setting_sun.cpp
  Pandaria/GateSettingSun/gate_setting_sun.h
  Pandaria/GateSettingSun/boss_saboteur_kiptilak.cpp
  Pandaria/GateSettingSun/boss_striker_gadok.cpp
  Pandaria/GateSettingSun/boss_commander_rimok.cpp
  Pandaria/GateSettingSun/boss_raigonn.cpp

  Pandaria/ShadopanMonastery/instance_shadopan_monastery.cpp
  Pandaria/ShadopanMonastery/shadopan_monastery.cpp
  Pandaria/ShadopanMonastery/shadopan_monastery.h
  Pandaria/ShadopanMonastery/boss_gu_cloudstrike.cpp
  Pandaria/ShadopanMonastery/boss_master_snowdrift.cpp
  Pandaria/ShadopanMonastery/boss_sha_of_violence.cpp
  Pandaria/ShadopanMonastery/boss_taran_zhu.cpp
 

  Pandaria/MogushanVault/instance_mogu_shan_vault.cpp
  Pandaria/MogushanVault/mogu_shan_vault.cpp
  Pandaria/MogushanVault/mogu_shan_vault.h
  Pandaria/MogushanVault/boss_stone_guard.cpp
  Pandaria/MogushanVault/boss_feng.cpp
  Pandaria/MogushanVault/boss_garajal.cpp
  Pandaria/MogushanVault/boss_spirit_kings.cpp
  Pandaria/MogushanVault/boss_elegon.cpp
  Pandaria/MogushanVault/boss_will_of_emperor.cpp

Pandaria/HeartOfFear/heart_of_fear.cpp
  Pandaria/HeartOfFear/Imperial_Zorlok.cpp
  Pandaria/HeartOfFear/Blade_Lord_Tayak.cpp  
  Pandaria/HeartOfFear/Wind_Lord_Meljarak.cpp
  Pandaria/HeartOfFear/Garalon.cpp
  Pandaria/HeartOfFear/Grand_Empress_Shekzeer.cpp

  Pandaria/SiegeNiuzaoTemple/siege_of_the_niuzoa_temple.cpp
  Pandaria/SiegeNiuzaoTemple/siege_of_the_niuzoa_temple.h
  Pandaria/SiegeNiuzaoTemple/boss_jinbak.cpp
  Pandaria/SiegeNiuzaoTemple/boss_vojak.cpp
  Pandaria/SiegeNiuzaoTemple/boss_pavalak.cpp
  Pandaria/SiegeNiuzaoTemple/boss_wing_leader.cpp
  
  Pandaria/TerraceOfEndlessSpring/instance_terrace_of_endless_spring.cpp
  Pandaria/TerraceOfEndlessSpring/terrace_of_endless_spring.cpp
  Pandaria/TerraceOfEndlessSpring/terrace_of_endless_spring.h
  Pandaria/TerraceOfEndlessSpring/boss_protectors_of_the_endless.cpp
  Pandaria/TerraceOfEndlessSpring/boss_lei_shi.cpp
  Pandaria/TerraceOfEndlessSpring/boss_tsulong.cpp

  Pandaria/TerraceOfEndlessSpring/boss_sha_of_fear.cpp


  Pandaria/WanderingIsland/WanderingIsland_North.cpp
  Pandaria/WanderingIsland/WanderingIsland_East.cpp
  Pandaria/WanderingIsland/WanderingIsland_West.cpp
  Pandaria/WanderingIsland/WanderingIsland_South.cpp

  Pandaria/townlong_steppes.cpp
  Pandaria/dread_wastes.cpp
  Pandaria/valley_of_the_four_winds.cpp
  Pandaria/krasarang_wilds.cpp
  Pandaria/kun_lai_summit.cpp
  Pandaria/jade_forest.cpp
  Pandaria/vale_of_eternal_blossoms.cpp

  Pandaria/ThroneOfThunder/instance_throne_of_thunder.cpp
  Pandaria/ThroneOfThunder/boss_horridon.cpp
  Pandaria/ThroneOfThunder/boss_council.cpp
  Pandaria/ThroneOfThunder/boss_tortos.cpp
  Pandaria/ThroneOfThunder/boss_jinrokh.cpp
  Pandaria/ThroneOfThunder/boss_megaera.cpp
  Pandaria/ThroneOfThunder/boss_ji_kun.cpp
  Pandaria/ThroneOfThunder/boss_durumu.cpp
  Pandaria/ThroneOfThunder/throne_of_thunder.cpp 
  
  Pandaria/SiegeOfOrgrimmar/siege_of_orgrimmar.h
  Pandaria/SiegeOfOrgrimmar/siege_of_orgrimmar.cpp
  Pandaria/SiegeOfOrgrimmar/instance_siege_of_orgrimmar.cpp
  Pandaria/SiegeOfOrgrimmar/boss_immersius.cpp
  Pandaria/SiegeOfOrgrimmar/boss_fallen_protectors.cpp	
  Pandaria/SiegeOfOrgrimmar/boss_norushen.cpp
  Pandaria/SiegeOfOrgrimmar/boss_sha_of_pride.cpp
  Pandaria/SiegeOfOrgrimmar/boss_galakras.cpp
  Pandaria/SiegeOfOrgrimmar/boss_iron_juggernaut.cpp
  Pandaria/SiegeOfOrgrimmar/boss_dark_shaman.cpp
  Pandaria/SiegeOfOrgrimmar/boss_general_nazgrim.cpp
  Pandaria/SiegeOfOrgrimmar/boss_malkorok.cpp
  Pandaria/SiegeOfOrgrimmar/boss_spoils_of_pandaria.cpp
  Pandaria/SiegeOfOrgrimmar/boss_thok_the_bloodthirsty.cpp
  Pandaria/SiegeOfOrgrimmar/boss_siegecrafter_blackfuse.cpp
  Pandaria/SiegeOfOrgrimmar/boss_paragons_of_the_klaxxi.cpp
  Pandaria/SiegeOfOrgrimmar/boss_garrosh_hellscream.cpp
  Pandaria/SiegeOfOrgrimmar/boss_garrosh_hellscream.h	
  
  Pandaria/TimelessIsle/timeless_isle.cpp
  Pandaria/TimelessIsle/timeless_isle.h
  Pandaria/TimelessIsle/zone_timeless_isle.cpp


)

message("  -> Prepared: Pandaria")
