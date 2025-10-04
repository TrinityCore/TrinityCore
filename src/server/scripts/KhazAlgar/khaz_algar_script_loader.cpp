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

// Dornogal
void AddSC_zone_dornogal();

// Zone Isle Of Dorn
void AddSC_zone_isle_of_dorn();

// The Stonevault
void AddSC_instance_the_stonevault();
void AddSC_boss_edna();
void AddSC_boss_skarmorak();

// Nerub'ar Palace
void AddSC_instance_nerubar_palace();
void AddSC_boss_ulgrax_the_devourer();

// City of Threads
void AddSC_instance_city_of_threads();
void AddSC_boss_orator_krix_vizk();

// The name of this function should match:
// void Add${NameOfDirectory}Scripts()
void AddKhazAlgarScripts()
{
    // Dornogal
    AddSC_zone_dornogal();

    // Zone Isle of Dorn
    AddSC_zone_isle_of_dorn();

    // The Stonevault
    AddSC_instance_the_stonevault();
    AddSC_boss_edna();
    AddSC_boss_skarmorak();

    // Nerub'ar Palace
    AddSC_instance_nerubar_palace();
    AddSC_boss_ulgrax_the_devourer();

    // City of Threads
    AddSC_instance_city_of_threads();
    AddSC_boss_orator_krix_vizk();
}
