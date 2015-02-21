 #/*
 #* Copyright (C) 2013-2015 DeathCore <http://www.noffearrdeathproject.net/>
 #*
 #* This program is free software; you can redistribute it and/or modify it
 #* under the terms of the GNU General Public License as published by the
 #* Free Software Foundation; either version 2 of the License, or (at your
 #* option) any later version.
 #*
 #* This program is distributed in the hope that it will be useful, but WITHOUT
 #* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 #* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 #* more details.
 #*
 #* You should have received a copy of the GNU General Public License along
 #* with this program. If not, see <http://www.gnu.org/licenses/>.
 #*/



set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  Pandaria/boss_ordos.cpp
  Pandaria/boss_sha_of_anger.cpp
  Pandaria/MoguShanPalace/instance_mogushan_palace.cpp
  Pandaria/MoguShanPalace/mogushan_palace.h
  Pandaria/MoguShanPalace/boss_gekkan.cpp
  Pandaria/MoguShanPalace/boss_trial_of_king.cpp
  Pandaria/MoguShanPalace/boss_xin_the_weaponmaster.cpp
  Pandaria/MoguShanVaults/instance_mogushan_vaults.cpp
  Pandaria/MoguShanVaults/mogushan_vaults.h
  Pandaria/MoguShanVaults/boss_elegon.cpp
  Pandaria/MoguShanVaults/boss_feng_the_accursed.cpp
  Pandaria/MoguShanVaults/boss_garajal_the_spiritbinder.cpp
  Pandaria/MoguShanVaults/boss_the_spirit_kings.cpp
  Pandaria/MoguShanVaults/boss_the_stone_guard.cpp
  Pandaria/MoguShanVaults/boss_will_of_the_emperor.cpp
  Pandaria/ShadoPanMonastery/shadopan_monastery.h
  Pandaria/ShadoPanMonastery/instance_shadopan_monastery.cpp
  Pandaria/ShadoPanMonastery/boss_gu_cloudstrike.cpp
  Pandaria/ShadoPanMonastery/boss_master_snowdrift.cpp
  Pandaria/ShadoPanMonastery/boss_sha_of_violence.cpp
  Pandaria/ShadoPanMonastery/boss_taran_zhu.cpp
  Pandaria/TempleoftheJadeSerpent/temple_of_the_jade_serpent.h
  Pandaria/TempleoftheJadeSerpent/instance_temple_of_the_jade_serpent.cpp
  Pandaria/TempleoftheJadeSerpent/boss_liu_flameheart.cpp
  Pandaria/TempleoftheJadeSerpent/boss_lorewalker_stonestep.cpp
  Pandaria/TempleoftheJadeSerpent/boss_sha_of_doubt.cpp
  Pandaria/TempleoftheJadeSerpent/boss_wise_mari.cpp
  Pandaria/TerraceofEndlessSpring/terrace_of_the_endless_spring.h
  Pandaria/TerraceofEndlessSpring/instance_terrace_of_the_endless_spring.cpp
  Pandaria/TerraceofEndlessSpring/boss_lei_shi.cpp
  Pandaria/TerraceofEndlessSpring/boss_protectors_of_the_endless.cpp
  Pandaria/TerraceofEndlessSpring/boss_sha_of_fear.cpp
  Pandaria/TerraceofEndlessSpring/boss_tsulong.cpp
  Pandaria/StormstoutBrewery/stormstout_brewery.h
  Pandaria/StormstoutBrewery/instance_stormstout_brewery.cpp
  Pandaria/StormstoutBrewery/boss_hoptallus.cpp
  Pandaria/StormstoutBrewery/boss_ook_ook.cpp
  Pandaria/StormstoutBrewery/boss_yan_zhu.cpp
  Pandaria/GateoftheSettingSun/gate_of_the_setting_sun.h
  Pandaria/GateoftheSettingSun/instance_gate_of_the_setting_sun.cpp
  Pandaria/GateoftheSettingSun/boss_commander_rimok.cpp
  Pandaria/GateoftheSettingSun/boss_raigonn.cpp
  Pandaria/GateoftheSettingSun/boss_saboteur_kiptilak.cpp
  Pandaria/GateoftheSettingSun/boss_striker_gadok.cpp
  Pandaria/HeartofFear/heart_of_fear.h
  Pandaria/HeartofFear/instance_heart_of_fear.cpp
  Pandaria/HeartofFear/boss_ambershaper_unsok.cpp
  Pandaria/HeartofFear/boss_blade_lord_tayak.cpp
  Pandaria/HeartofFear/boss_garalon.cpp
  Pandaria/HeartofFear/boss_grand_empress_shekzeer.cpp
  Pandaria/HeartofFear/boss_imperial_vizier_zorlok.cpp
  Pandaria/HeartofFear/boss_wind_lord_meljarak.cpp
  Pandaria/SiegeofNiuzaoTemple/siege_of_niuzao_temple.h
  Pandaria/SiegeofNiuzaoTemple/instance_siege_of_niuzao_temple.cpp
  Pandaria/SiegeofNiuzaoTemple/boss_commander_vojak.cpp
  Pandaria/SiegeofNiuzaoTemple/boss_general_pavalak.cpp
  Pandaria/SiegeofNiuzaoTemple/boss_vizier_jinbak.cpp
  Pandaria/SiegeofNiuzaoTemple/boss_wing_leader_neronok.cpp
  Pandaria/SiegeOfOrgrimmar/SiegeOfOrgrimmar.h
  Pandaria/SiegeOfOrgrimmar/instance_SiegeOfOrgrimmar.cpp
  Pandaria/SiegeOfOrgrimmar/boss_Immerseus.cpp
  Pandaria/SiegeOfOrgrimmar/boss_TheFallenProtectors.cpp
  Pandaria/SiegeOfOrgrimmar/boss_Norushen.cpp
  Pandaria/SiegeOfOrgrimmar/boss_ShaOfPride.cpp
  Pandaria/SiegeOfOrgrimmar/boss_Galakras.cpp
  Pandaria/SiegeOfOrgrimmar/boss_IronJuggernaut.cpp
  Pandaria/SiegeOfOrgrimmar/boss_KorKron.cpp
  Pandaria/SiegeOfOrgrimmar/boss_GeneralNazgrim.cpp
  Pandaria/SiegeOfOrgrimmar/boss_Malkorok.cpp
  Pandaria/SiegeOfOrgrimmar/boss_SpoilsOfPandaria.cpp
  Pandaria/SiegeOfOrgrimmar/boss_Thok.cpp
  Pandaria/SiegeOfOrgrimmar/boss_SiegecrafterBlackfuse.cpp
  Pandaria/SiegeOfOrgrimmar/boss_ParagonsOfTheKlaxxi.cpp
  Pandaria/SiegeOfOrgrimmar/boss_GarroshHellscream.cpp
  Pandaria/ThroneOfThunder/ThroneOfThunder.h
  Pandaria/ThroneOfThunder/instance_ThroneOfThunder.cpp
  Pandaria/ThroneOfThunder/boss_Jinrokh.cpp
  Pandaria/ThroneOfThunder/boss_Horridon.cpp
  Pandaria/ThroneOfThunder/boss_Council.cpp
  Pandaria/ThroneOfThunder/boss_Tortos.cpp
  Pandaria/ThroneOfThunder/boss_Megaera.cpp
  Pandaria/ThroneOfThunder/boss_JiKun.cpp
  Pandaria/ThroneOfThunder/boss_Durumu.cpp
  Pandaria/ThroneOfThunder/boss_Primordius.cpp
  Pandaria/ThroneOfThunder/boss_DarkAnimus.cpp
  Pandaria/ThroneOfThunder/boss_IronQon.cpp
  Pandaria/ThroneOfThunder/boss_TwinConsorts.cpp
  Pandaria/ThroneOfThunder/boss_LeiShen.cpp
  Pandaria/ThroneOfThunder/boss_Raden.cpp
  Pandaria/ScarletHalls/scarlet_halls.h
  Pandaria/ScarletHalls/instance_scarlet_halls.cpp
  Pandaria/ScarletHalls/boss_armsmaster_harlan.cpp
  Pandaria/ScarletHalls/boss_flameweaver_koegler.cpp
  Pandaria/ScarletHalls/boss_houndmaster_braun.cpp
  //Pandaria/ScarletMonastery/scarlet_monastery.h
  //Pandaria/ScarletMonastery/instance_scarlet_monastery.cpp
  Pandaria/ScarletMonastery/boss_brother_korloff.cpp
  Pandaria/ScarletMonastery/boss_high_inquisitor_whitemane.cpp
  Pandaria/ScarletMonastery/boss_thalnos_the_souldrender.cpp
  //Pandaria/Scholomance/scholomance.h
  //Pandaria/Scholomance/instance_scholomance.cpp
  //Pandaria/Scholomance/boss_darkmaster_gandling.cpp
  Pandaria/Scholomance/boss_instructor_chillheart.cpp
  Pandaria/Scholomance/boss_jandice_barov.cpp
  Pandaria/Scholomance/boss_lilian_voss.cpp
  Pandaria/Scholomance/boss_rattlegore.cpp
)

message("  -> Prepared: Pandaria")
