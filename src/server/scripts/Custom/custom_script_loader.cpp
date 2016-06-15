/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
void AddSC_announce_login();
void AddSC_LearnSpellsOnLevelUp();
void AddSC_XpWeekend();
void AddSC_PvP_System();
void AddSC_VAS_AutoBalance();
void AddSC_item_enchant_visuals();
void AddSC_Transmogrification();
void AddSC_REFORGER_NPC();
void AddSC_guildmaster();

// The name of this function should match:
// void Add${NameOfDirectory}Scripts()
void AddCustomScripts()
{
	AddSC_announce_login();
	AddSC_LearnSpellsOnLevelUp();
	AddSC_XpWeekend();
	AddSC_PvP_System();
	AddSC_VAS_AutoBalance();
	AddSC_item_enchant_visuals();
    AddSC_Transmogrification();
    AddSC_REFORGER_NPC();
	AddSC_guildmaster();
}
