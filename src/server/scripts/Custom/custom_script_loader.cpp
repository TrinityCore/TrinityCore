/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

// This is where scripts' loading functions should be declared:
void AddSC_npc_levels();
void AddSC_Player_Even_Action();
void AddSC_npc_innkeeper_new();
void AddSC_npc_changer();
void AddSC_npc_gossip_menu_option_new();

// The name of this function should match:
// void Add${NameOfDirectory}Scripts()
void AddCustomScripts()
{
    AddSC_npc_levels();
    AddSC_Player_Even_Action();
    AddSC_npc_innkeeper_new();
    AddSC_npc_changer();
    AddSC_npc_gossip_menu_option_new();
}
