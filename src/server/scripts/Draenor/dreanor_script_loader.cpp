/*
* Copyright (C) 2021 BfaCore Reforged
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

// Tanaan Intro
void AddSC_tanaan_intro_global();
void AddSC_tanaan_intro_portal();
void AddSC_tanaan_intro_bleeding_hollow();
void AddSC_tanaan_intro_shattered_hand();
void AddSC_tanaan_intro_shadowmoon();
void AddSC_tanaan_intro_blackrock();
void AddSC_tanaan_intro_finale();

// Garrison
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

// Auchindoun
void AddSC_boss_azaakel();
void AddSC_boss_kaathar();
void AddSC_boss_nyami();
void AddSC_boss_teronogor();
void AddSC_auchindoun();
void AddSC_instance_auchindoun();

// Blackrock Foundry
void AddSC_boss_beastlord_darmac();
void AddSC_boss_blackhand();
void AddSC_boss_blast_furnace();
void AddSC_boss_flamebender_kagraz();
void AddSC_boss_gruul_foundry();
void AddSC_boss_hansgar_and_franzok();
void AddSC_boss_iron_maidens();
void AddSC_boss_kromog();
void AddSC_boss_operator_thogar();
void AddSC_boss_oregorger();
void AddSC_blackrock_foundry();
void AddSC_instance_blackrock_foundry();

// Grimrail Depot
void AddSC_boss_nitrogg_thundertower();
void AddSC_boss_rocketspark_and_borka();
void AddSC_boss_skylord_tovra();
void AddSC_grimrail_depot();
void AddSC_instance_grimrail_depot();

// Hellfire Citadel
void AddSC_boss_fel_lord_zakuun();
void AddSC_boss_gorefiend();
void AddSC_boss_hellfire_archimonde();
void AddSC_boss_hellfire_gurtogg_bloodboil();
void AddSC_boss_hellfire_kormrok();
void AddSC_boss_hellfire_mannoroth();
void AddSC_boss_iron_reaver();
void AddSC_boss_kilrogg_deadeye();
void AddSC_boss_shadow_lord_iskar();
void AddSC_boss_siegemaster_martak();
void AddSC_boss_soulbound_construct();
void AddSC_boss_tyrant_velhari();
void AddSC_boss_xhulhorac();
void AddSC_hellfire_citadel();
void AddSC_instance_hellfire_citadel();

// Iron Docks
void AddSC_boss_grimrail();
void AddSC_boss_nokgar();
void AddSC_boss_oshir();
void AddSC_boss_skulloc();
void AddSC_iron_docks();
void AddSC_instance_iron_docks();

// Skyreach
void AddSC_boss_araknath();
void AddSC_boss_high_save_viryx();
void AddSC_boss_ranjit();
void AddSC_boss_rukhran();
void AddSC_mob_instance_skyreach();
void AddSC_instance_skyreach();

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

    // Auchindoun
    AddSC_boss_azaakel();
    AddSC_boss_kaathar();
    AddSC_boss_nyami();
    AddSC_boss_teronogor();
    AddSC_auchindoun();
    AddSC_instance_auchindoun();
    
    // Blackrock Foundry
    AddSC_boss_beastlord_darmac();
    AddSC_boss_blackhand();
    AddSC_boss_blast_furnace();
    AddSC_boss_flamebender_kagraz();
    AddSC_boss_gruul_foundry();
    AddSC_boss_hansgar_and_franzok();
    AddSC_boss_iron_maidens();
    AddSC_boss_kromog();
    AddSC_boss_operator_thogar();
    AddSC_boss_oregorger();
    AddSC_blackrock_foundry();
    AddSC_instance_blackrock_foundry();

    // Grimrail Depot
    AddSC_boss_nitrogg_thundertower();
    AddSC_boss_rocketspark_and_borka();
    AddSC_boss_skylord_tovra();
    AddSC_grimrail_depot();
    AddSC_instance_grimrail_depot();
    
    // Hellfire Citadel
    AddSC_boss_fel_lord_zakuun();
    AddSC_boss_gorefiend();
    AddSC_boss_hellfire_archimonde();
    AddSC_boss_hellfire_gurtogg_bloodboil();
    AddSC_boss_hellfire_kormrok();
    AddSC_boss_hellfire_mannoroth();
    AddSC_boss_iron_reaver();
    AddSC_boss_kilrogg_deadeye();
    AddSC_boss_shadow_lord_iskar();
    AddSC_boss_siegemaster_martak();
    AddSC_boss_soulbound_construct();
    AddSC_boss_tyrant_velhari();
    AddSC_boss_xhulhorac();
    AddSC_hellfire_citadel();
    AddSC_instance_hellfire_citadel();
    
    // Iron Docks
    AddSC_boss_grimrail();
    AddSC_boss_nokgar();
    AddSC_boss_oshir();
    AddSC_boss_skulloc();
    AddSC_iron_docks();
    AddSC_instance_iron_docks();
    
    // Skyreach
    AddSC_boss_araknath();
    AddSC_boss_high_save_viryx();
    AddSC_boss_ranjit();
    AddSC_boss_rukhran();
    AddSC_mob_instance_skyreach();
    AddSC_instance_skyreach();
}
