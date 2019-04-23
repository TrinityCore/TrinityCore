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

void AddSC_garrison_level_1();
void AddSC_garrison_level_2();
void AddSC_garrison_level_3();
void AddSC_spells_garrison();

// Bloodmaul Slag Mines
void AddSC_areatrigger_Bloodmaul();
void AddSC_boss_forgemaster_gogduh();
void AddSC_boss_gugrokk();
void AddSC_boss_roltall();
void AddSC_boss_SlaveWatcherCrushto();
void AddSC_mob_Bloodmaul();
void AddSC_spell_Bloodmaul();
void AddSC_instance_Bloodmaul();

// Everbloom
void AddSC_boss_ancient_protectors();
void AddSC_boss_sol();
void AddSC_boss_witherbark();
void AddSC_boss_xeritac();
void AddSC_boss_yalnu();
void AddSC_the_everbloom();
void AddSC_instance_everbloom();

// Shadowmoon Burial Grounds
void AddSC_bonemaw();
void AddSC_nerzul();
void AddSC_nhalish();
void AddSC_sadana();
void AddSC_shadowmoon_burial_grounds();
void AddSC_instance_shadowmoon_burial_grounds();

// Highmaul
void AddSC_boss_twin_ogron();
void AddSC_boss_the_butcher();
void AddSC_boss_koragh();
void AddSC_boss_kargath_bladefist();
void AddSC_boss_imperator_margok();
void AddSC_boss_brackenspore();
void AddSC_boss_tectus();
void AddSC_highmaul();
void AddSC_instance_highmaul();

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

    AddSC_garrison_level_1();
    AddSC_garrison_level_2();
    AddSC_garrison_level_3();
    AddSC_spells_garrison();

    // Bloodmaul Slag Mines
    AddSC_areatrigger_Bloodmaul();
    AddSC_boss_forgemaster_gogduh();
    AddSC_boss_gugrokk();
    AddSC_boss_roltall();
    AddSC_boss_SlaveWatcherCrushto();
    AddSC_mob_Bloodmaul();
    AddSC_spell_Bloodmaul();
    AddSC_instance_Bloodmaul();

    // Everbloom
    AddSC_boss_ancient_protectors();
    AddSC_boss_sol();
    AddSC_boss_witherbark();
    AddSC_boss_xeritac();
    AddSC_boss_yalnu();
    AddSC_the_everbloom();
    AddSC_instance_everbloom();

    // Shadowmoon Burial Grounds
    AddSC_bonemaw();
    AddSC_nerzul();
    AddSC_nhalish();
    AddSC_sadana();
    AddSC_shadowmoon_burial_grounds();
    AddSC_instance_shadowmoon_burial_grounds();

    // Highmaul
    AddSC_boss_twin_ogron();
    AddSC_boss_the_butcher();
    AddSC_boss_koragh();
    AddSC_boss_kargath_bladefist();
    AddSC_boss_imperator_margok();
    AddSC_boss_brackenspore();
    AddSC_boss_tectus();
    AddSC_highmaul();
    AddSC_instance_highmaul();
}
