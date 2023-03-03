///*
//<<<<<<< HEAD:src/server/scripts/Draenor/draenor_script_loader.cpp
// * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
// * Copyright 2023 AzgathCore
//=======
// * Copyright (C) 2022 BfaCore Reforged
// *
//>>>>>>> 00c8b4918beff3f29ba8b4eb8d50c9fd67076687:src/server/scripts/Kalimdor/RagefireChasm/ragefire_chasm.cpp
// * This program is free software; you can redistribute it and/or modify it
// * under the terms of the GNU General Public License as published by the
// * Free Software Foundation; either version 2 of the License, or (at your
// * option) any later version.
// *
// * This program is distributed in the hope that it will be useful, but WITHOUT
// * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// * more details.
// *
// * You should have received a copy of the GNU General Public License along
// * with this program. If not, see <http://www.gnu.org/licenses/>.
// */
// 
//#include "ScriptMgr.h"
//#include "ScriptedCreature.h"
//#include "PassiveAI.h"
//#include "ragefire_chasm.h"
//
//<<<<<<< HEAD:src/server/scripts/Draenor/draenor_script_loader.cpp
//// This is where scripts' loading functions should be declared:
//
////void AddSC_draenor_shadowmoon_valley();
////void AddSC_frostfire_ridge();
////void AddSC_shadowmoon_draenor();
////void AddSC_tanaan_jungle();
////
////void AddSC_tanaan_intro_global();
////void AddSC_tanaan_intro_portal();
////void AddSC_tanaan_intro_bleeding_hollow();
////void AddSC_tanaan_intro_shattered_hand();
////void AddSC_tanaan_intro_shadowmoon();
////void AddSC_tanaan_intro_blackrock();
////void AddSC_tanaan_intro_finale();
////
////void AddSC_garrison_level_1();
////void AddSC_garrison_level_2();
////void AddSC_garrison_level_3();
////void AddSC_spells_garrison();
////
////// Bloodmaul Slag Mines
////void AddSC_areatrigger_Bloodmaul();
////void AddSC_boss_forgemaster_gogduh();
////void AddSC_boss_gugrokk();
////void AddSC_boss_roltall();
////void AddSC_boss_SlaveWatcherCrushto();
////void AddSC_mob_Bloodmaul();
////void AddSC_spell_Bloodmaul();
////void AddSC_instance_Bloodmaul();
////
////// Everbloom
////void AddSC_boss_ancient_protectors();
////void AddSC_boss_sol();
////void AddSC_boss_witherbark();
////void AddSC_boss_xeritac();
////void AddSC_boss_yalnu();
////void AddSC_the_everbloom();
////void AddSC_instance_everbloom();
////
////// FateOfKaraborScenario
////void AddSC_instance_scenario_fate_of_karabor();
////
////// Shadowmoon Burial Grounds
////void AddSC_bonemaw();
////void AddSC_nerzul();
////void AddSC_nhalish();
////void AddSC_sadana();
////void AddSC_shadowmoon_burial_grounds();
////void AddSC_instance_shadowmoon_burial_grounds();
////
////// Highmaul
////void AddSC_boss_twin_ogron();
////void AddSC_boss_the_butcher();
////void AddSC_boss_koragh();
////void AddSC_boss_kargath_bladefist();
////void AddSC_boss_imperator_margok();
////void AddSC_boss_brackenspore();
////void AddSC_boss_tectus();
////void AddSC_highmaul();
////void AddSC_instance_highmaul();
////
////// UpperBlackrockSpire
////void AddSC_boss_commander_tharbek();
////void AddSC_boss_kyrak();
////void AddSC_boss_orebender_gorashan();
////void AddSC_boss_ragewing_untamed();
////void AddSC_boss_warlord_zaela();
////void AddSC_instance_upper_blackrock_spire();
//=======
//>>>>>>> 00c8b4918beff3f29ba8b4eb8d50c9fd67076687:src/server/scripts/Kalimdor/RagefireChasm/ragefire_chasm.cpp
//
//
//void AddSC_ragefire_chasm()
//{
//<<<<<<< HEAD:src/server/scripts/Draenor/draenor_script_loader.cpp
//	//AddSC_draenor_shadowmoon_valley();
// //   AddSC_frostfire_ridge();
// //   AddSC_shadowmoon_draenor();
// //   AddSC_tanaan_jungle();
//
// //   AddSC_tanaan_intro_global();
// //   AddSC_tanaan_intro_portal();
// //   AddSC_tanaan_intro_bleeding_hollow();
// //   AddSC_tanaan_intro_shattered_hand();
// //   AddSC_tanaan_intro_shadowmoon();
// //   AddSC_tanaan_intro_blackrock();
// //   AddSC_tanaan_intro_finale();
//
// //   AddSC_garrison_level_1();
// //   AddSC_garrison_level_2();
// //   AddSC_garrison_level_3();
// //   AddSC_spells_garrison();
//
// //   // Bloodmaul Slag Mines
// //   AddSC_areatrigger_Bloodmaul();
// //   AddSC_boss_forgemaster_gogduh();
// //   AddSC_boss_gugrokk();
// //   AddSC_boss_roltall();
// //   AddSC_boss_SlaveWatcherCrushto();
// //   AddSC_mob_Bloodmaul();
// //   AddSC_spell_Bloodmaul();
// //   AddSC_instance_Bloodmaul();
//
// //   // UpperBlackrockSpire
// //   AddSC_boss_commander_tharbek();
// //   AddSC_boss_kyrak();
// //   AddSC_boss_orebender_gorashan();
// //   AddSC_boss_ragewing_untamed();
// //   AddSC_boss_warlord_zaela();
// //   AddSC_instance_upper_blackrock_spire();
// //   
// //   // Everbloom
// //   AddSC_boss_ancient_protectors();
// //   AddSC_boss_sol();
// //   AddSC_boss_witherbark();
// //   AddSC_boss_xeritac();
// //   AddSC_boss_yalnu();
// //   AddSC_the_everbloom();
// //   AddSC_instance_everbloom();
//	//
//	//// FateOfKaraborScenario
//	//AddSC_instance_scenario_fate_of_karabor();
//
// //   // Shadowmoon Burial Grounds
// //   AddSC_bonemaw();
// //   AddSC_nerzul();
// //   AddSC_nhalish();
// //   AddSC_sadana();
// //   AddSC_shadowmoon_burial_grounds();
// //   AddSC_instance_shadowmoon_burial_grounds();
//
// //   // Highmaul
// //   AddSC_boss_twin_ogron();
// //   AddSC_boss_the_butcher();
// //   AddSC_boss_koragh();
// //   AddSC_boss_kargath_bladefist();
// //   AddSC_boss_imperator_margok();
// //   AddSC_boss_brackenspore();
// //   AddSC_boss_tectus();
// //   AddSC_highmaul();
// //   AddSC_instance_highmaul();
//=======
//  
//>>>>>>> 00c8b4918beff3f29ba8b4eb8d50c9fd67076687:src/server/scripts/Kalimdor/RagefireChasm/ragefire_chasm.cpp
//}
//
