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

void AddSC_frostfire_ridge();
void AddSC_shadowmoon_draenor();
void AddSC_tanaan_jungle();

void AddSC_tanaan_intro_global();
void AddSC_tanaan_intro_portal();
void AddSC_tanaan_intro_bleeding_hollow();
void AddSC_tanaan_intro_shattered_hand();
void AddSC_tanaan_intro_shadowmoon();
void AddSC_tanaan_intro_blackrock();
void AddSC_tanaan_intro_finale();

void AddSC_spells_garrison();

// The name of this function should match:
// void Add${NameOfDirectory}Scripts()
void AddDraenorScripts()
{
    AddSC_frostfire_ridge();
    AddSC_shadowmoon_draenor();
    AddSC_tanaan_jungle();

    AddSC_tanaan_intro_global();
    AddSC_tanaan_intro_portal();
    AddSC_tanaan_intro_bleeding_hollow();
    AddSC_tanaan_intro_shattered_hand();
    AddSC_tanaan_intro_shadowmoon();
    AddSC_tanaan_intro_blackrock();
    AddSC_tanaan_intro_finale();

    AddSC_spells_garrison();
}
