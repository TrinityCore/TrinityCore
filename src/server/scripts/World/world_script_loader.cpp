/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "World.h"

// This is where scripts' loading functions should be declared:
// world
void AddSC_areatrigger_scripts();
void AddSC_emerald_dragons();
void AddSC_generic_creature();
void AddSC_go_scripts();
void AddSC_npc_guard();
void AddSC_item_scripts();
void AddSC_npc_professions();
void AddSC_npc_innkeeper();
void AddSC_npcs_special();
void AddSC_achievement_scripts();
void AddSC_action_ip_logger();
void AddSC_duel_reset();
void AddSC_xp_boost();
// player
void AddSC_chat_log();
void AddSC_action_ip_logger();

// The name of this function should match:
// void Add${NameOfDirectory}Scripts()
void AddWorldScripts()
{
    AddSC_areatrigger_scripts();
    AddSC_emerald_dragons();
    AddSC_generic_creature();
    AddSC_go_scripts();
    AddSC_npc_guard();
    AddSC_item_scripts();
    AddSC_npc_professions();
    AddSC_npc_innkeeper();
    AddSC_npcs_special();
    AddSC_achievement_scripts();
    AddSC_chat_log(); // location: scripts\World\chat_log.cpp

    // FIXME: This should be moved in a script validation hook.
    // To avoid duplicate code, we check once /*ONLY*/ if logging is permitted or not.
    if (sWorld->getBoolConfig(CONFIG_IP_BASED_ACTION_LOGGING))
        AddSC_action_ip_logger(); // location: scripts\World\action_ip_logger.cpp
    AddSC_duel_reset();
    if (sWorld->getIntConfig(CONFIG_XP_BOOST_DAYMASK) != 0)
        AddSC_xp_boost();
}
