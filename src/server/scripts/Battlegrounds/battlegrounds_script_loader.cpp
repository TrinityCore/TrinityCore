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
// Alterac Valley
void AddSC_alterac_valley();
void AddSC_boss_balinda();
void AddSC_boss_drekthar();
void AddSC_boss_galvangar();
void AddSC_boss_vanndar();
void AddSC_battleground_alterac_valley();

// Arathi Basin
void AddSC_arathi_basin();
void AddSC_battleground_arathi_basin();

// Eye of the storm
void AddSC_battleground_eye_of_the_storm();

// Warsong Gulch
void AddSC_battleground_warsong_gulch();

// Isle of Conquest
void AddSC_battleground_isle_of_conquest();
void AddSC_isle_of_conquest();
void AddSC_boss_ioc_horde_alliance();

// Strand of the Ancients
void AddSC_battleground_strand_of_the_ancients();
void AddSC_strand_of_the_ancients();

// Blade's Edge Arena
void AddSC_arena_blades_edge();
void AddSC_arena_dalaran_sewers();
void AddSC_arena_nagrand();
void AddSC_arena_ruins_of_lordaeron();
void AddSC_arena_ring_of_valor();

void AddSC_battleground_twin_peaks();
void AddSC_battleground_battle_for_gilneas();

void AddSC_battleground_seething_shore();

// The name of this function should match:
// void Add${NameOfDirectory}Scripts()
void AddBattlegroundsScripts()
{
    // Alterac Valley
    AddSC_alterac_valley();
    AddSC_boss_balinda();
    AddSC_boss_drekthar();
    AddSC_boss_galvangar();
    AddSC_boss_vanndar();
    AddSC_battleground_alterac_valley();

    // Arathi Basin
    AddSC_arathi_basin();
    AddSC_battleground_arathi_basin();

    // Eye of the Storm
    AddSC_battleground_eye_of_the_storm();

    // Warsong Gulch
    AddSC_battleground_warsong_gulch();

    // Isle of Conquest
    AddSC_battleground_isle_of_conquest();
    AddSC_isle_of_conquest();
    AddSC_boss_ioc_horde_alliance();

    // Strand of the Ancients
    AddSC_battleground_strand_of_the_ancients();
    AddSC_strand_of_the_ancients();

    AddSC_arena_blades_edge();
    AddSC_arena_dalaran_sewers();
    AddSC_arena_nagrand();
    AddSC_arena_ruins_of_lordaeron();
    AddSC_arena_ring_of_valor();

    AddSC_battleground_twin_peaks();
    AddSC_battleground_battle_for_gilneas();

    AddSC_battleground_seething_shore();
}
