/*
 * Copyright 2021 ShadowCore
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
#include "ScriptMgr.h"
#include "Player.h"
#include "InstanceScript.h"
//#include "GameObjects"
#include "Instance_mists_of_tirna_scithe.cpp"
//#include "zone_ardenweald"
//#include "InstanceMap"

enum Data
{
	DATA_Ingra_Maloch,
	DATA_Mistcaller,
	DATA_Tredova,
    Data_Ancient_Swoop,
    Data_Cocoon_of_Lakali,
    Data_Doomguard,
    Data_Droman_Oulfarran,
    Data_Drust_Boughbreaker,
    Data_Drust_Harvester,
    Data_Drust_Soulcleaver,
    Data_Drust_Spiteclaw,
    Data_Ethereal_Transmorpher,
    Data_Felhound,
    Data_Fleeting_Memory,
    Data_Generic_Hunter_Pet,
    Data_Gormling_Larva,
    Data_Greater_Earth_Elemental,
    Data_Hydra_Seed,
    Data_Illusionary_Clone,
    Data_Illusionary_Vulpin,
    Data_Infernal,
    Data_Manifestation_of_Pride,
    Data_Merchant_Maku,
    Data_Mistveil_Defender,
    Data_Mistveil_Gorgegullet,
    Data_Mistveil_Guardian,
    //Data_Mistveil Matriarch,
    Data_Mistveil_Nightblossom,
    Data_Mistveil_Shaper,
    Data_Mistveil_Stalker,
    Data_Mistveil_Stinger,
    Data_Mistveil_Tender,
    Data_Nathrian_Inquisitor,
    Data_Overgrown_Hydra,
    Data_Overgrown,
    Data_Parasitic_Infestor,
   // Data_Savory Statshroom,
    Data_Shadowlands_Wormhole,
    Data_Shivarra,
    Data_Spinemaw_Acidgullet,
    Data_Spinemaw_Gorger,
    Data_Spinemaw_Larva,
    Data_Spinemaw_Reaver,
    Data_Spinemaw_Staghorn,
    Data_Spiteful_Shade,
    Data_Tasty_Toughshroom,
    Data_Tirnenn_Sapling,
    Data_tirnenn_villager,
    Data_Turnip_Punching_Bag,
    Data_Urzul, //"Ur'zul"
    Data_Wrathguard,
    Data_Xolartios,
};

enum Creatures
{
	NPC_Ingra_Maloch = 164567,
	NPC_Mistcaller = 170217,//164501,166885,
	NPC_Tredova = 164517,
	NPC_Ancient_Swoop = 151846,
	NPC_Cocoon_of_Lakali = 165512,
	NPC_Doomguard = 168932,
	NPC_Droman_Oulfarran = 164804,//170218,170229,
	NPC_Drust_Boughbreaker = 164926,
	NPC_Drust_Harvester = 164921,
	NPC_Drust_Soulcleaver = 164920,//172991,
    NPC_Drust_Spiteclaw = 165111,
    NPC_Ethereal_Transmorpher = 149596,
    NPC_Felhound = 169421,//169425,
    NPC_Fleeting_Memory = 175581,
    NPC_Generic_Hunter_Pet = 165189,
    NPC_Gormling_Larva = 165560,
    NPC_Greater_Earth_Elemental = 95072,
    NPC_Hydra_Seed = 172995,
    NPC_Illusionary_Clone = 165108,
    NPC_Illusionary_Vulpin = 165251,
    NPC_Infernal = 169426,
    NPC_Manifestation_of_Pridee = 173729,
    NPC_Merchant_Maku = 142668,
    NPC_Mistveil_Defender = 163058,//171772,
    NPC_Mistveil_Gorgegullet = 173720,
    NPC_Mistveil_Guardian = 166276,
    NPC_Mistveil_Matriarch = 173655,
    NPC_Mistveil_Nightblossom = 173714,
    NPC_Mistveil_Shaper = 166275,
    NPC_Mistveil_Stalker = 166301,
    NPC_Mistveil_Stinger = 166304,
    NPC_Mistveil_Tender = 166299,
    NPC_Nathrian_Inquisitor = 175513,
    NPC_Overgrown_Hydra = 172992,
    NPC_Overgrown = 168988,
    NPC_Parasitic_Infestor = 172647,
    NPC_Savory_Statshroom = 173680,
    NPC_Shadowlands_Wormhole = 169501,
    NPC_Shivarra = 169429,
    NPC_Spinemaw_Acidgullet = 167113,
    NPC_Spinemaw_Gorger = 172312,
    NPC_Spinemaw_Larva = 167117,
    Npc_Spinemaw_Reaver = 167116,
    NPC_Spinemaw_Staghorn = 167111,
    NPC_Spiteful_Shade = 174773,
    NPC_Tasty_Toughshroom = 173679,
    NPC_Tirnenn_Sapling = 167707,
    NPC_tirnenn_villager = 164929,//165120,
    NPC_Turnip_Punching_Bag = 65310,
    NPC_Urzul = 169430,
    NPC_Wrathguard = 169428,
    NPC_Xolartios = 158635,
};

enum objects
{
	Anvil = 192628,
	Challengers_Cache = 354972,
	Overgrown_Roots = 326498,
	Snow_Patch = 358375,
};

enum quest
{
	Shrieker_Soul = 62436,
	The_Eternal_Traveler = 57686,
};

enum achivements
{
    Heroic_Mists_of_Tirna_Scithe = 14412,
    Hooked_On_Hydroponics = 14503,
    Hunger_for_Knowledge = 14375,
    Mists_of_Tirna_Scithe = 14371,
    Mythic_Mists_of_Tirna_Scithe = 14413,
    Mythic_Mists_of_Tirna_Scithe_Guild_Run = 14382,
    Someone_Could_Trip_on_These = 14291,
};

    

