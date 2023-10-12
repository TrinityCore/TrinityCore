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
// 类似这样 void AddSC_announce_login();

void AddSC_announce_login();
void AddSC_Boss_Announcer();
void AddSC_Death_Announcer();
void AddSC_gon_playerscripts();
void AddSC_item_add_huanhua();


// The name of this function should match:
// void Add${NameOfDirectory}Scripts()
//类似这样 AddSC_announce_login();


void AddCustomScripts()
{

    AddSC_announce_login();
    AddSC_Boss_Announcer();
    AddSC_Death_Announcer();
    AddSC_gon_playerscripts();
    AddSC_item_add_huanhua();


}
