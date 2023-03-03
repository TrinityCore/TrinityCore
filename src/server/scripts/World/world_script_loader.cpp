///*
// * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
// *
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
//#include "World.h"
//
//// This is where scripts' loading functions should be declared:
//// world
//void AddSC_areatrigger_scripts();
//void AddSC_conversation_scripts();
//void AddSC_emerald_dragons();
//void AddSC_go_scripts();
//void AddSC_npc_guard();
//void AddSC_item_scripts();
//void AddSC_npc_professions();
//void AddSC_npc_innkeeper();
//void AddSC_npcs_special();
//void AddSC_achievement_scripts();
//void AddSC_action_ip_logger();
//void AddSC_scene_scripts();
//void AddSC_xp_boost();
//// player
//void AddSC_chat_log();
//void AddSC_duel_reset();
//// WorldBoss
//void AddSC_boss_galion();
//void AddSC_boss_nalak();
//void AddSC_boss_oondasta();
//void AddSC_boss_sha_of_anger();
//void AddSC_boss_dunegorger_kraulok();
//void AddSC_boss_jiarak();
//void AddSC_boss_tzane();
//
//// BrokenIsles
//void AddSC_boss_apocron();
//void AddSC_boss_nithogg();
//void AddSC_boss_ana_mouz();
//void AddSC_boss_brutallus_legion();
//void AddSC_boss_calamir();
//void AddSC_boss_drugon_the_frostblood();
//void AddSC_boss_flotsam();
//void AddSC_boss_humongris();
//void AddSC_boss_levantus();
//void AddSC_boss_nazak_the_fiend();
//void AddSC_boss_sharthos();
//void AddSC_boss_the_soultakers();
//void AddSC_boss_withered_jim();
//void AddSC_boss_malificus();
//
//// The name of this function should match:
//// void Add${NameOfDirectory}Scripts()
//void AddWorldScripts()
//{
//    AddSC_areatrigger_scripts();
//    AddSC_conversation_scripts();
//    AddSC_emerald_dragons();
//    AddSC_go_scripts();
//    AddSC_npc_guard();
//    AddSC_item_scripts();
//    AddSC_npc_professions();
//    AddSC_npc_innkeeper();
//    AddSC_npcs_special();
//    AddSC_achievement_scripts();
//    AddSC_chat_log(); // location: scripts\World\chat_log.cpp
//    AddSC_scene_scripts();
//	// WorldBoss
//	AddSC_boss_galion();
//	AddSC_boss_nalak();
//	AddSC_boss_oondasta();
//	AddSC_boss_sha_of_anger();
//	AddSC_boss_dunegorger_kraulok();
//    AddSC_boss_jiarak();
//    AddSC_boss_tzane();
//	
//	// BrokenIsles
//	AddSC_boss_apocron();
//    AddSC_boss_ana_mouz();
//    AddSC_boss_brutallus_legion();
//    AddSC_boss_calamir();
//    AddSC_boss_drugon_the_frostblood();
//    AddSC_boss_flotsam();
//    AddSC_boss_humongris();
//    AddSC_boss_levantus();
//    AddSC_boss_nazak_the_fiend();
//    AddSC_boss_nithogg();
//    AddSC_boss_sharthos();
//    AddSC_boss_the_soultakers();
//    AddSC_boss_withered_jim();
//    AddSC_boss_malificus();
//	
//
//    // FIXME: This should be moved in a script validation hook.
//    // To avoid duplicate code, we check once /*ONLY*/ if logging is permitted or not.
//    if (sWorld->getBoolConfig(CONFIG_IP_BASED_ACTION_LOGGING))
//        AddSC_action_ip_logger(); // location: scripts\World\action_ip_logger.cpp
//    AddSC_duel_reset();
//    if (sWorld->getIntConfig(CONFIG_XP_BOOST_DAYMASK) != 0)
//        AddSC_xp_boost();
//}
//XCore 2023
void AddWorldScripts()
{
    
}
