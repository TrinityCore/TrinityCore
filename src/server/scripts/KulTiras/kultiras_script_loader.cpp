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

void AddSC_zone_boralus();

// Waycrest Manor
void AddSC_boss_heartsbane_triad();
void AddSC_boss_lord_and_lady_waycrest();
void AddSC_instance_waycrest_manor();

// The name of this function should match:
// void Add${NameOfDirectory}Scripts()
void AddKulTirasScripts()
{
    AddSC_zone_boralus();

    // Waycrest Manor
    AddSC_boss_heartsbane_triad();
    AddSC_boss_lord_and_lady_waycrest();
    AddSC_instance_waycrest_manor();
}
