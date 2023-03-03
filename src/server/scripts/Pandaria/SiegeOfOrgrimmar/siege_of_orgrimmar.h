/*
* Copyright (C) 2008-20XX JadeCore <http://www.pandashan.com>
* Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
* Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#ifndef SIEGE_OF_ORG
#define SIEGE_OF_ORG

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"

enum eData
{
	// Immerseus
    DATA_IMMERSUS							= 1,
    DATA_IMMERSUS_DOORS						= 2,
    DATA_BACK_DOOR_IMMERSUS					= 3,
    DATA_FRONT_DOOR_IMMERSUS				= 4,

	// Fallen Protectors
    DATA_FALLEN_PROTECTORS					= 5,
    DATA_STONE								= 6,
    DATA_HU									= 7,
    DATA_SUN								= 8,
    DATA_FALLEN_PROTECTOR_DOOR				= 9,
    
    // Norushen
    DATA_NORUSHEN							= 10,
    DATA_NORUSHEN_BOSS						= 11,
    DATA_NORUSHEN_CHO						= 12,
    DATA_NORUSHEN_TRIGGER					= 13,
    DATA_NORUSHEN_ALMAGLEM_OF_CORRUPTION	= 14,
    DATA_NORUSHEN_ENTRANCE					= 15,
    DATA_PRIDE_ENTRANCE						= 16,

	// Sha of Pride
    DATA_SHA_OF_PRIDE						= 17,
    DATA_NORTH01							= 18,
    DATA_NORTH02							= 19,
    DATA_NORTH03							= 20,
    DATA_SOUTH01							= 21,
    DATA_SOUTH02							= 22,
    DATA_SOUTH03							= 23,
    DATA_WEST01								= 24,
    DATA_WEST02								= 25,
    DATA_WEST03								= 26,
    DATA_EAST01								= 27,
    DATA_EAST02								= 28,
    DATA_EAST03								= 29,

	// Galakras
	DATA_GALAKRAS							= 30,

	// Iron Juggernaut
	DATA_IRON_JUGGERNAUT					= 31,

	// Kor'kron Dark Shamans
	DATA_DARK_SHAMANS						= 32,
	DATA_EARTHBREAKER_HAROMM				= 33,
	DATA_WAVEBINDER_KARDRIS					= 34,

	// General Nazgrim
	DATA_GENERAL_NAZGRIM					= 35,

	// Malkorok
	DATA_MALKOROK							= 36,

	// Spoils of Pandaria
	DATA_SPOILS_OF_PANDARIA					= 37,

	// Thok the Bloodthirsty
	DATA_THOK_THE_BLOODTHIRSTY				= 38,

	// Siegecrafter Blackfuse
	DATA_SIEGECRAFTER_BLACKFUSE				= 39,

	// Paragons of the Klaxxi
	DATA_PARAGONS_OF_THE_KLAXXI_EVENT		= 40,
	DATA_SKEER_THE_BLOODSEEKER				= 41,
	DATA_RIKKAL_THE_DISSECTOR				= 42,
	DATA_HISEK_THE_SWARMKEEPER				= 43,
	DATA_KAROZ_THE_LOCUST					= 44,
	DATA_KORVET_THE_PRIME					= 45,
	DATA_IYYOKUK_THE_LUCID					= 46,
	DATA_XARIL_THE_POISONED_MIND			= 47,
	DATA_KAZTIK_THE_MANIPULATOR				= 48,
	DATA_KILRUK_THE_WIND_REAVER				= 49,

	// Garrosh Hellscream
    DATA_GARROSH_HELLSCREAM					= 50,
    DATA_THRALL								= 51,
    DATA_GARROSH_HEART_OF_YSHAARAJ			= 52,
    DATA_RIGHT_DOOR_GARROSH					= 53,
    DATA_LEFT_DOOR_GARROSH					= 54,

	// Lorewalker Cho
    DATA_LORE_WALKER_CHO_01					= 55,
};

enum eActionsLocal
{ 
    ACTION_LAST_TALK_BEFORE_BOSS	= 3214
};

enum eCreaturesLocal
{
	// Immerseus
    BOSS_IMMERSUS						= 72436,
    CREATURE_TORMENTED_INITATE			= 73349,
    CREATURE_FALLEN_POOL_TENDER			= 73342,
    CREATURE_AQUEOUS_DEFENDER			= 73191,
    CREATURE_BUBBLE_TRIGGER				= 342652,
    CREATURE_LESSER_SHA_PUDDLE			= 71604,
    CREATURE_CONTAMINATED_PUDDLE		= 73226,

	// Fallen Protectors
    BOSS_STONE							= 71475,
    BOSS_HU								= 71479,
    BOSS_SUN							= 71480,

    /// Norushen
    BOSS_NORUSHEN						= 719600,
    CREATURE_ALMAGLEM_OF_CORRUPTION		= 72276,
    CREATURE_CHO_NORUSHEN				= 72872,
    CREATURE_TRIGGER					= 425013, // CUSTOM

    /// Sha of Pride
    BOSS_SHA_OF_PRIDE					= 71734,
    CREATURE_NORUSHEN					= 71967,
    CREATURE_PRISON_TRIGGER_SWITCHERS	= 3242457, // CUSTOM

	// Galakras

	// Iron Juggernaut
	BOSS_IRON_JUGGERNAUT				= 71466,

	// Kor'kron Dark Shamans
	BOSS_EARTHBREAKER_HAROMM			= 71859,
	BOSS_WAVEBINDER_KARDRIS				= 71858,

	// General Nazgrim
	BOSS_GENERAL_NAZGRIM				= 71515,

	// Garrosh Hellscream
    BOSS_GARROSH_HELLSCREAM				= 71865,
    CREATURE_THRALL						= 73483,
    CREATURE_HEART_OF_YSHAARAJ_MAIN		= 72215,

	// Lorewalker Cho
    CREATURE_CHO01						= 73330, 
};

enum eGameObjectsLocal
{
    GAMEOBJECT_IMMERSUS_FRONTDOOR	= 231412,
    GAMEOBJECT_IMMERSUS_BACKDOOR	= 532425,
    GobjectMediumShaWall			= 221611,

    GAMEOBJECT_SKYROOM_HOLA			= 222681,

    /*
    Prisoners
    */

    // Norushen
    GAMEOBJECT_NORUSHEN_ENTRANCE	= 221447,
    GAMEOBJECT_PRIDE_ENTRNANCE		= 221446,

    // North 
    GAMEOBJECT_PRISON_NORTH_01		= 221755,
    GAMEOBJECT_PRISON_NORTH_02		= 221750,
    GAMEOBJECT_PRISON_NORTH_03		= 221754,
    GAMEOBJECT_ACTIVATOR_NORTH		= 221676,

    // East
    GAMEOBJECT_PRISON_EAST_01		= 221753,
    GAMEOBJECT_PRISON_EAST_02		= 221751,
    GAMEOBJECT_PRISON_EAST_03		= 221752,
    GAMEOBJECT_ACTIVATOR_EAST		= 221677,

    // South
    GAMEOBJECT_PRISON_SOUTH_01		= 221761,
    GAMEOBJECT_PRISON_SOUTH_02		= 221760,
    GAMEOBJECT_PRISON_SOUTH_03		= 221756,
    GAMEOBJECT_ACTIVATOR_SOUTH		= 221678,

    // West
    GAMEOBJECT_PRISON_WEST_01		= 221758,
    GAMEOBJECT_PRISON_WEST_02		= 221759,
    GAMEOBJECT_PRISON_WEST_03		= 221757,
    GAMEOBJECT_ACTIVATOR_WEST		= 221679,

    GAMEOBJECT_RIGHT_DOOR			= 221440,
    GAMEOBJECT_LEFT_DOOR			= 221439,
};

enum eSpellsLocal
{
    SPELL_BUBBLY_SHIELD	= 147333,
};


#endif SIEGE_OF_ORG
