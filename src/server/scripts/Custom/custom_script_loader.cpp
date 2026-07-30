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

// ==================== Player Scripts ======================== //
void AddSC_custom_player_inventory();
void AddSC_custom_player_mails();

// ==================== Class Scripts ========================= //
void AddSC_custom_demonhunter_spell_fixes();
void AddSC_custom_evoker_spell_fixes();
void AddSC_custom_hunter_spell_fixes();
void AddSC_custom_mage_spell_fixes();
void AddSC_custom_monk_spell_npcs();
void AddSC_custom_monk_spell_fixes();
void AddSC_custom_shaman_totem_npcs();
void AddSC_custom_warlock_spell_fixes();
void AddSC_custom_warlock_demon_npcs();
void AddSC_custom_warrior_spell_fixes();

// ==================== Per Zone Scripts ====================== //
void AddSC_custom_elwynn_forest_npcs();

void AddSC_custom_stormwind_at();
void AddSC_custom_stormwind_npcs();
void AddSC_custom_stormwind_player();
void AddSC_custom_stormwind_quests();

void AddSC_custom_the_wandering_isle_at();
void AddSC_custom_the_wandering_isle_npcs();
void AddSC_custom_the_wandering_isle_objects();
void AddSC_custom_the_wandering_isle_player();
void AddSC_custom_the_wandering_isle_quests();
void AddSC_custom_the_wandering_isle_spells();

void AddSC_custom_tirisfal_glades_npcs();
void AddSC_custom_tirisfal_glades_player();

void AddSC_custom_westfall_at();
void AddSC_custom_westfall_npcs();
void AddSC_custom_westfall_player();
void AddSC_custom_westfall_quests();

// ==================== Followship Scripts ==================== //
void AddSC_followship_bots();                // FSB main Script
void AddSC_followship_bots_player();                // FSB Player Scripts
void AddSC_followship_bots_commandscript();
void AddSC_followship_bots_command_stats();
void AddSC_followship_bots_command_template();
void AddSC_followship_bots_world();                // FSB World Script
void AddSC_followship_npcs_player();               // FSB NPC Chat Player Script
void AddSC_followship_bots_battleground_player(); // FSB Battleground Player Script

// ==================== Delves Scripts ======================= //
void AddSC_delve_system();
void AddSC_instance_atal_aman_delve();
void AddSC_instance_shadow_enclave_delve();
void AddSC_delve_commands();

// ==================== Instance Scripts ===================== //
// Deadmines
void AddSC_custom_instance_deadmines();
void AddSC_custom_deadmines_areatrigger();
void AddSC_custom_deadmines_npcs();
void AddSC_custom_deadmines_objects();
void AddSC_custom_deadmines_spells();
void AddSC_custom_deadmines_old_npcs();
void AddSC_custom_deadmines_admiral_ripsnarl();
void AddSC_custom_deadmines_foe_reaper_5000();
void AddSC_custom_deadmines_glubtok();
void AddSC_custom_deadmines_helix_gearbreaker();
void AddSC_custom_deadmines_captain_cookie();
void AddSC_custom_deadmines_vanessa_vancleef();

// Magister's Terrace 12.0.1 (Map 2811)
void AddSC_instance_magisters_terrace_12();
void AddSC_boss_arcanotron_custos();
void AddSC_boss_seranel_sunlash();
void AddSC_boss_gemellus();
void AddSC_boss_degentrius();
void AddSC_npc_magister_umbric_mt();
void AddSC_magisters_terrace_12_trash();

// ==================== Creature Codex Scripts =============== //
//void AddSC_creature_codex_sniffer();
//void AddSC_creature_codex_commands();

// ==================== Trading Post Scripts ================= //
void AddSC_npc_perks_program_vendor();

// ==================== Spells Scripts ======================= //
void AddSC_advanced_flying_spell_scripts();

// ==================== Misc Scripts ========================= //
void AddSC_gm_fixer();

// The name of this function should match:
// void Add${NameOfDirectory}Scripts()
void AddCustomScripts()
{
    AddSC_custom_player_inventory();
    AddSC_custom_player_mails();

    AddSC_custom_demonhunter_spell_fixes();
    AddSC_custom_evoker_spell_fixes();
    AddSC_custom_hunter_spell_fixes();
    AddSC_custom_mage_spell_fixes();
    AddSC_custom_monk_spell_npcs();
    AddSC_custom_monk_spell_fixes();
    AddSC_custom_shaman_totem_npcs();
    AddSC_custom_warlock_spell_fixes();
    AddSC_custom_warlock_demon_npcs();
    AddSC_custom_warrior_spell_fixes();

    AddSC_custom_elwynn_forest_npcs();

    AddSC_custom_stormwind_at();
    AddSC_custom_stormwind_npcs();
    AddSC_custom_stormwind_player();
    AddSC_custom_stormwind_quests();

    AddSC_custom_the_wandering_isle_at();
    AddSC_custom_the_wandering_isle_npcs();
    AddSC_custom_the_wandering_isle_objects();
    AddSC_custom_the_wandering_isle_player();
    AddSC_custom_the_wandering_isle_quests();
    AddSC_custom_the_wandering_isle_spells();

    AddSC_custom_tirisfal_glades_npcs();
    AddSC_custom_tirisfal_glades_player();

    AddSC_custom_westfall_at();
    AddSC_custom_westfall_npcs();
    AddSC_custom_westfall_player();
    AddSC_custom_westfall_quests();

    AddSC_followship_bots();
    AddSC_followship_bots_player();
    AddSC_followship_bots_commandscript();
    AddSC_followship_bots_command_stats();
    AddSC_followship_bots_command_template();
    AddSC_followship_bots_world();
    AddSC_followship_npcs_player();
    AddSC_followship_bots_battleground_player();

    // Creature Codex
    //AddSC_creature_codex_sniffer();
    //AddSC_creature_codex_commands();

    // Perks Program (Trading Post)
    AddSC_npc_perks_program_vendor();

    // Deadmines
    AddSC_custom_instance_deadmines();
    AddSC_custom_deadmines_areatrigger();
    AddSC_custom_deadmines_npcs();
    AddSC_custom_deadmines_objects();
    AddSC_custom_deadmines_spells();
    AddSC_custom_deadmines_old_npcs();
    AddSC_custom_deadmines_admiral_ripsnarl();
    AddSC_custom_deadmines_foe_reaper_5000();
    AddSC_custom_deadmines_glubtok();
    AddSC_custom_deadmines_helix_gearbreaker();
    AddSC_custom_deadmines_captain_cookie();
    AddSC_custom_deadmines_vanessa_vancleef();

    // Magister's Terrace 12.0.1 (Map 2811)
    AddSC_instance_magisters_terrace_12();
    AddSC_boss_arcanotron_custos();
    AddSC_boss_seranel_sunlash();
    AddSC_boss_gemellus();
    AddSC_boss_degentrius();
    AddSC_npc_magister_umbric_mt();
    AddSC_magisters_terrace_12_trash();

    // Delves
    AddSC_delve_system();
    AddSC_instance_atal_aman_delve();
    AddSC_instance_shadow_enclave_delve();
    AddSC_delve_commands();

    // Spells
    AddSC_advanced_flying_spell_scripts();

    // Misc
    AddSC_gm_fixer();
}
