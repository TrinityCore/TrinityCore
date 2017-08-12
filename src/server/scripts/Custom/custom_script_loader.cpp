/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
void AddSC_hearthstone_without_cooldown();
void AddSC_System_Censure();
void AddSC_Transmogrification();
void AddSC_my_script();
void AddSC_premium_commandscript();
//void AddSC_collesium_script();
void AddSC_Boss_Anouncer();
void AddSC_boss_chaoscontrol();
void AddSC_PLAYER_TRANSFER_NPC_SCRIPT();
// The name of this function should match:
// void Add${NameOfDirectory}Scripts()
void AddCustomScripts()
{
    AddSC_PLAYER_TRANSFER_NPC_SCRIPT();
    AddSC_System_Censure();
    AddSC_hearthstone_without_cooldown();
    AddSC_Transmogrification();
    AddSC_my_script();
    AddSC_Boss_Anouncer();
  //  AddSC_collesium_script();
    // VIP
    AddSC_boss_chaoscontrol();
    AddSC_premium_commandscript();
}

