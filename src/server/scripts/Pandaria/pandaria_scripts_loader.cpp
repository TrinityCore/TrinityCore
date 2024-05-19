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

// This is where scripts loading function should be declared:

// Terrace of Endless Spring
void AddSC_boss_protectors_of_the_endless();
void AddSC_instance_terrace_of_endless_spring();

void AddSC_zone_the_wandering_isle();

// The name of this function should match:
// void Add${NameOfDirectory}Scripts()
void AddPandariaScripts()
{
    // Terrace of Endless Spring
    AddSC_boss_protectors_of_the_endless();
    AddSC_instance_terrace_of_endless_spring();

    AddSC_zone_the_wandering_isle();
}
