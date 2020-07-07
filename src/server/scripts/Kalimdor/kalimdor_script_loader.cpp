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
// Blackfathom Depths
void AddSC_blackfathom_deeps();
void AddSC_boss_gelihast();
void AddSC_boss_kelris();
void AddSC_boss_aku_mai();
void AddSC_instance_blackfathom_deeps();
// CoT Battle for Mt. Hyjal
void AddSC_hyjal();
void AddSC_boss_archimonde();
void AddSC_instance_mount_hyjal();
void AddSC_hyjal_trash();
void AddSC_boss_rage_winterchill();
void AddSC_boss_anetheron();
void AddSC_boss_kazrogal();
void AddSC_boss_azgalor();
// CoT Old Hillsbrad
void AddSC_boss_captain_skarloc();
void AddSC_boss_epoch_hunter();
void AddSC_boss_lieutenant_drake();
void AddSC_instance_old_hillsbrad();
void AddSC_old_hillsbrad();
// CoT The Black Morass
void AddSC_boss_aeonus();
void AddSC_boss_chrono_lord_deja();
void AddSC_boss_temporus();
void AddSC_the_black_morass();
void AddSC_instance_the_black_morass();
// CoT Culling Of Stratholme
void AddSC_boss_epoch();
void AddSC_npc_arthas_stratholme();
void AddSC_boss_infinite_corruptor();
void AddSC_boss_salramm();
void AddSC_boss_mal_ganis();
void AddSC_boss_meathook();
void AddSC_culling_of_stratholme();
void AddSC_instance_culling_of_stratholme();
// Dire Maul
void AddSC_instance_dire_maul();
// Ragefire Chasm
void AddSC_instance_ragefire_chasm();
// Maraudon
void AddSC_boss_celebras_the_cursed();
void AddSC_boss_landslide();
void AddSC_boss_noxxion();
void AddSC_boss_ptheradras();
void AddSC_instance_maraudon();
// Onyxia's Lair
void AddSC_boss_onyxia();
void AddSC_instance_onyxias_lair();
// Razorfen Downs
void AddSC_boss_tuten_kash();
void AddSC_boss_mordresh_fire_eye();
void AddSC_boss_glutton();
void AddSC_boss_amnennar_the_coldbringer();
void AddSC_razorfen_downs();
void AddSC_instance_razorfen_downs();
// Razorfen Kraul
void AddSC_razorfen_kraul();
void AddSC_instance_razorfen_kraul();
// Ruins of ahn'qiraj
void AddSC_boss_kurinnaxx();
void AddSC_boss_rajaxx();
void AddSC_boss_moam();
void AddSC_boss_buru();
void AddSC_boss_ayamiss();
void AddSC_boss_ossirian();
void AddSC_instance_ruins_of_ahnqiraj();
// Temple of ahn'qiraj
void AddSC_boss_cthun();
void AddSC_boss_viscidus();
void AddSC_boss_fankriss();
void AddSC_boss_huhuran();
void AddSC_bug_trio();
void AddSC_boss_sartura();
void AddSC_boss_skeram();
void AddSC_boss_twinemperors();
void AddSC_boss_ouro();
void AddSC_npc_anubisath_sentinel();
void AddSC_instance_temple_of_ahnqiraj();
// Wailing caverns
void AddSC_wailing_caverns();
void AddSC_instance_wailing_caverns();
// Zul'Farrak
void AddSC_boss_zum_rah();
void AddSC_zulfarrak();
void AddSC_instance_zulfarrak();

void AddSC_ashenvale();
void AddSC_azshara();
void AddSC_azuremyst_isle();
void AddSC_bloodmyst_isle();
void AddSC_boss_azuregos();
void AddSC_darkshore();
void AddSC_desolace();
void AddSC_durotar();
void AddSC_dustwallow_marsh();
void AddSC_felwood();
void AddSC_feralas();
void AddSC_moonglade();
void AddSC_orgrimmar();
void AddSC_silithus();
// void AddSC_stonetalon_mountains();
void AddSC_tanaris();
void AddSC_the_barrens();
// void AddSC_thousand_needles();
void AddSC_thunder_bluff();
// void AddSC_ungoro_crater();
void AddSC_winterspring();

// The name of this function should match:
// void Add${NameOfDirectory}Scripts()
void AddKalimdorScripts()
{
    // Blackfathom Depths
    AddSC_blackfathom_deeps();
    AddSC_boss_gelihast();
    AddSC_boss_kelris();
    AddSC_boss_aku_mai();
    AddSC_instance_blackfathom_deeps();
    // CoT Battle for Mt. Hyjal
    AddSC_hyjal();
    AddSC_boss_archimonde();
    AddSC_instance_mount_hyjal();
    AddSC_hyjal_trash();
    AddSC_boss_rage_winterchill();
    AddSC_boss_anetheron();
    AddSC_boss_kazrogal();
    AddSC_boss_azgalor();
    // CoT Old Hillsbrad
    AddSC_boss_captain_skarloc();
    AddSC_boss_epoch_hunter();
    AddSC_boss_lieutenant_drake();
    AddSC_instance_old_hillsbrad();
    AddSC_old_hillsbrad();
    // CoT The Black Morass
    AddSC_boss_aeonus();
    AddSC_boss_chrono_lord_deja();
    AddSC_boss_temporus();
    AddSC_the_black_morass();
    AddSC_instance_the_black_morass();
    // CoT Culling Of Stratholme
    AddSC_boss_epoch();
    AddSC_npc_arthas_stratholme();
    AddSC_boss_infinite_corruptor();
    AddSC_boss_salramm();
    AddSC_boss_mal_ganis();
    AddSC_boss_meathook();
    AddSC_culling_of_stratholme();
    AddSC_instance_culling_of_stratholme();
    // Dire Maul
    AddSC_instance_dire_maul();
    // Ragefire Chasm
    AddSC_instance_ragefire_chasm();
    //Maraudon
    AddSC_boss_celebras_the_cursed();
    AddSC_boss_landslide();
    AddSC_boss_noxxion();
    AddSC_boss_ptheradras();
    AddSC_instance_maraudon();
    // Onyxia's Lair
    AddSC_boss_onyxia();
    AddSC_instance_onyxias_lair();
    // Razorfen Downs
    AddSC_boss_tuten_kash();
    AddSC_boss_mordresh_fire_eye();
    AddSC_boss_glutton();
    AddSC_boss_amnennar_the_coldbringer();
    AddSC_razorfen_downs();
    AddSC_instance_razorfen_downs();
    // Razorfen Kraul
    AddSC_razorfen_kraul();
    AddSC_instance_razorfen_kraul();
    // Ruins of ahn'qiraj
    AddSC_boss_kurinnaxx();
    AddSC_boss_rajaxx();
    AddSC_boss_moam();
    AddSC_boss_buru();
    AddSC_boss_ayamiss();
    AddSC_boss_ossirian();
    AddSC_instance_ruins_of_ahnqiraj();
    // Temple of ahn'qiraj
    AddSC_boss_cthun();
    AddSC_boss_viscidus();
    AddSC_boss_fankriss();
    AddSC_boss_huhuran();
    AddSC_bug_trio();
    AddSC_boss_sartura();
    AddSC_boss_skeram();
    AddSC_boss_twinemperors();
    AddSC_boss_ouro();
    AddSC_npc_anubisath_sentinel();
    AddSC_instance_temple_of_ahnqiraj();
    // Wailing caverns
    AddSC_wailing_caverns();
    AddSC_instance_wailing_caverns();
    // Zul'Farrak
    AddSC_boss_zum_rah();
    AddSC_zulfarrak();
    AddSC_instance_zulfarrak();

    AddSC_ashenvale();
    AddSC_azshara();
    AddSC_azuremyst_isle();
    AddSC_bloodmyst_isle();
    AddSC_boss_azuregos();
    AddSC_darkshore();
    AddSC_desolace();
    AddSC_durotar();
    AddSC_dustwallow_marsh();
    AddSC_felwood();
    AddSC_feralas();
    AddSC_moonglade();
    AddSC_orgrimmar();
    AddSC_silithus();
    // AddSC_stonetalon_mountains();
    AddSC_tanaris();
    AddSC_the_barrens();
    // AddSC_thousand_needles();
    AddSC_thunder_bluff();
    // AddSC_ungoro_crater();
    AddSC_winterspring();
}
