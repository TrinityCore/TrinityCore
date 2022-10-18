/*
 * Copyright 2021 FuzionCore Project
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

/* Script Data Start
SDName: 
SDAuthor: Frozen
SD%Complete: %
SDComment: still working on structure.
Script Data End */

enum Objects
{
    Anvil = 192628,
    High_Value_Cache = 375893,
    Protoform_Schematic = 375905,
    Protoform Schematic_1 = 375907,
    Snow_Patch = 358375,
    Treasures_of_the_First_Ones = 375886,
    Treasures_of_the_First_Ones_1 = 375901,
    Xyraths_Booby-Trapped_Cache = 375536,
};

enum Quests
{
    Blingtron_7000 = 56042,
    Cervid_Soul = 65640,
    Heart_of_the_Sepulcher = 65259,
    Leading_Motives = 65717,
    Schematic_Reassimilation: Curious_Crystalsniffer = 65399,
    Schematic_Reassimilation: Serenade = 65384,
    Schematic_Reassimilation: Stabilized_Geomental = 65336,
    Sepulcher_of_the_First_Ones - Heavy_is_the_Crown = 65762,
    Sepulcher_of_the_First_Ones - Heavy_is_the_Crown_1 = 65763,
    Sepulcher_of_the_First_Ones - Heavy_is_the_Crown_2 = 65764,
    Silithid_Soul = 65512,
    Snail_Soul = 65519,
};

enum Loot
{
    Malleable_Flesh = 178061,
};

enum Achievements 
{
    // Guild achievements
    Hall_of_Fame: The_Jailer_A = 15476,
    Hall_of_Fame: The_Jailer_H = 15475,
    Heroic: Sepulcher_of_the_First_Ones_Guild_Run = 15473,
    Mythic: The_Jailer_Guild_Run = 15474,
    Sepulcher_of_the_First_Ones_Guild_Run = 15472,
    // Character Achievements
    Ahead_of_the_Curve: The_Jailer = 15470,
    Amidst_Ourselves = 15315,
    Cutting_Edge: The_Jailer = 15471,
    
};

enum Creatures
{
    Anduin_Wrynn                = 181954,
    

    zone_Sepulcher_of_the_First_Ones         = 13742,
};

struct zone_Sepulcher_of_the_First_Ones : public InstanceScript
{
    Sepulcher_of_the_First_Ones(InstanceMap* map) : InstanceScript(map, Sepulcher_of_the_First_Ones) { } 
};

void AddSC_Sepulcher_of_the_First_Ones()
{
    void AddSC_Sepulcher_of_the_First_Ones();
};