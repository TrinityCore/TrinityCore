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
    DATA_IMMERSUS,
    DATA_IMMERSUS_DOORS,

    DATA_BACK_DOOR_IMMERSUS,
    DATA_FRONT_DOOR_IMMERSUS,

    DATA_LORE_WALKER_CHO_01,

    DATA_FALLEN_PROTECTORS,
    DATA_STONE,
    DATA_HU,
    DATA_SUN,

    DATA_FALLEN_PROTECTOR_DOOR,

    DATA_SHA_OF_PRIDE,
    DATA_NORUSHEN,

    // Norushen
    DATA_NORUSHEN_BOSS,
    DATA_NORUSHEN_CHO,
    DATA_NORUSHEN_TRIGGER,
    DATA_NORUSHEN_ALMAGLEM_OF_CORRUPTION,
    DATA_NORUSHEN_ENTRANCE,
    DATA_PRIDE_ENTRANCE,


    DATA_GARROSH_HELLSCREAM,
    DATA_THRALL,

    DATA_GARROSH_HEART_OF_YSHAARAJ,

    DATA_NORTH01,
    DATA_NORTH02,
    DATA_NORTH03,
    DATA_SOUTH01,
    DATA_SOUTH02,
    DATA_SOUTH03,
    DATA_WEST01,
    DATA_WEST02,
    DATA_WEST03,
    DATA_EAST01,
    DATA_EAST02,
    DATA_EAST03,

    DATA_RIGHT_DOOR_GARROSH,
    DATA_LEFT_DOOR_GARROSH
};

enum eActionsLocal
{
    ACTION_LAST_TALK_BEFORE_BOSS = 3214
};

enum eCreaturesLocal
{
    BOSS_IMMERSUS = 72436,
    CREATURE_TORMENTED_INITATE = 73349,
    CREATURE_FALLEN_POOL_TENDER = 73342,
    CREATURE_AQUEOUS_DEFENDER = 73191,
    CREATURE_BUBBLE_TRIGGER = 342652,
    CREATURE_LESSER_SHA_PUDDLE = 71604,
    CREATURE_CONTAMINATED_PUDDLE = 73226,

    CREATURE_PRISON_TRIGGER_SWITCHERS = 3242457, // CUSTOM

    CREATURE_CHO01 = 73330,

    BOSS_STONE = 71475,
    BOSS_HU = 71479,
    BOSS_SUN = 71480,

    /// Norushen
    BOSS_NORUSHEN = 719600,
    CREATURE_ALMAGLEM_OF_CORRUPTION = 72276,
    CREATURE_CHO_NORUSHEN = 72872,
    CREATURE_TRIGGER = 425013, // CUSTOM

    /// Sha of Pride
    BOSS_SHA_OF_PRIDE = 71734,
    CREATURE_NORUSHEN = 71967,

    BOSS_GARROSH_HELLSCREAM = 71865,
    CREATURE_THRALL = 73483,
    CREATURE_HEART_OF_YSHAARAJ_MAIN = 72215
};

enum eGameObjectsLocal
{
    GAMEOBJECT_IMMERSUS_FRONTDOOR = 231412,
    GAMEOBJECT_IMMERSUS_BACKDOOR = 532425,
    GobjectMediumShaWall = 221611,

    GAMEOBJECT_SKYROOM_HOLA = 222681,

    /*
    Prisoners
    */

    // Norushen
    GAMEOBJECT_NORUSHEN_ENTRANCE = 221447,
    GAMEOBJECT_PRIDE_ENTRNANCE   = 221446,

    // North
    GAMEOBJECT_PRISON_NORTH_01 = 221755,
    GAMEOBJECT_PRISON_NORTH_02 = 221750,
    GAMEOBJECT_PRISON_NORTH_03 = 221754,
    GAMEOBJECT_ACTIVATOR_NORTH = 221676,

    // East
    GAMEOBJECT_PRISON_EAST_01 = 221753,
    GAMEOBJECT_PRISON_EAST_02 = 221751,
    GAMEOBJECT_PRISON_EAST_03 = 221752,
    GAMEOBJECT_ACTIVATOR_EAST = 221677,

    // South
    GAMEOBJECT_PRISON_SOUTH_01 = 221761,
    GAMEOBJECT_PRISON_SOUTH_02 = 221760,
    GAMEOBJECT_PRISON_SOUTH_03 = 221756,
    GAMEOBJECT_ACTIVATOR_SOUTH = 221678,

    // West
    GAMEOBJECT_PRISON_WEST_01 = 221758,
    GAMEOBJECT_PRISON_WEST_02 = 221759,
    GAMEOBJECT_PRISON_WEST_03 = 221757,
    GAMEOBJECT_ACTIVATOR_WEST = 221679,

    GAMEOBJECT_RIGHT_DOOR = 221440,
    GAMEOBJECT_LEFT_DOOR = 221439,
};

enum eSpellsLocal
{
    SPELL_BUBBLY_SHIELD = 147333,
};


#endif SIEGE_OF_ORG
