/*
* Copyright 2023 AzgathCore
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

#ifndef FALL_OF_THERAMORE_ALLIANCE_SCENARIO_H_
#define FALL_OF_THERAMORE_ALLIANCE_SCENARIO_H_

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"

#define CHAPTERS 5

const Position StandartsSpawnPos[3]
{
    { -3739.89f, -4381.48f, 11.14f, 1.97f },
    { -3787.95f, -4327.24f,  9.57f, 0.40f },
    { -3744.97f, -4291.65f,  8.68f, 3.51f },
};

const Position SiegeMachineSpawnPos = { -3783.61f, -4268.70f,   7.37f, 4.96f };
const Position BunnyPosition        = { -3703.17f, -4468.28f, -18.62f, 2.98f };
const Position WarlordSpawnPos      = { -3653.44f, -4449.49f,  -4.08f, 3.44f };

enum eData
{
    DATA_WELCOME_TO_THERAMORE,  // First chapter, done when u`ll kill orks forward of ship
    DATA_SWEEP_THE_HARBOR,      // Second chapter, done when u`ll kill 3td captains and burn their ships. + 20 npc slain
    DATA_INTO_THE_RUINS,        // Third chapter, done when u`ll kill 2td Wyverns and Gash`nul. + 8 npc slain
    DATA_LADY_PROUDMOORE,       // Four chapter, done when u`ll reach and talk with Jaina.
    DATA_DESTROY_THE_DESTROYER, // Five chapter, done when u`ll kill siege machine and take 3 standarts
    DATA_LAST_STAND,            // Last chapter, done when u`ll slain Warlord Rok`nah
};

enum eSpells
{
    SPELL_THERAMORE_EXPLOSION_CINEMATIC = 128446,
    SPELL_COSMETIC_ICE_BLOCK            = 82950,
    SPELL_ARCANE_BEAM                   = 40639,
    SPELL_SUMMON_WATER_ELEMENTALS       = 84374,
};

enum eCreatures
{
    NPC_LEAKED_OIL_DRUM    = 65571,
    NPC_AIRSHIP_MARINE     = 65611,
    NPC_AIRSHIP_CREWMAN    = 65610,
    NPC_ROKNAH_GRUNT       = 64732,
    NPC_ROKNAH_SKRIMISHER  = 65494,
    NPC_ROKNAH_FELCASTER   = 65507,
    NPC_ROKNAH_HEADHUNTER  = 64735,
    NPC_ROKNAH_LOA_SINGER  = 64733,
    NPC_ROKNAH_HAG         = 64734,
    NPC_ROKNAH_RIDER       = 64729,
    NPC_ROKNAH_WAVE_CALLER = 65510,
    NPC_SERGEANT_GRUD      = 65785,
    NPC_WAVE_CALLER_ZULGA  = 65786,
    NPC_VICIOUS_WYVERN     = 64957,
    NPC_GASHNUL            = 64900,
    NPC_SKY_CAPTAIN_DAZRIP = 65609,
    NPC_CAPTAIN_MOUSSON    = 65444,
    NPC_CAPTAIN_KORTHOK    = 65152,
    NPC_JAINA_PROUDMOORE   = 64727,
    NPC_GATECRUSHER        = 64479,
    NPC_GENERAL_BUNNY_JMF  = 45979,
    NPC_TANK_TARGET        = 59566,
    NPC_WARLORD_ROHNAH     = 65442,
};

enum eActions
{
    ACTION_ACTIVATE_BY_REGION,
    ACTION_JAINA_INTRO,
    ACTION_JAINA_LAST_STAND,
};

enum eGameObjects
{
    GO_STOLEN_STANDART = 214672,
};

enum Worldstates
{
    WORLDSTATE_KITE_FIGHT  = 12604,
    WORLDSTATE_NO_TANK_YOU = 12606,
};

enum Criteries
{
    CRITERIA_HORDE_CAPTAINS_SLAIN = 21030,
    CRITERIA_HORDE_SHIP_TORCHED   = 19980,
    CRITERIA_ROKNAH_SOLDERS_SLAIN = 21033,
    CRITERIA_GASHNUL_SLAIN        = 21109,
    CRITERIA_WYVERN_SLAIN         = 21110,
    CRITERIA_GATECRUSHER_SLAIN    = 21113,
    CRITERIA_BANNER_FOUND         = 21114,
    CRITERIA_DEFEAT_ROHNAH        = 21115,
    CRITERIA_JAINA_PROTECTED      = 22223,
};

const std::vector<uint32> wGuids =
{
    541848,
    541549,
    541683,
    541681,
    541741,
    541747,
    541730,
};

#endif // FALL_OF_THERAMORE_ALLIANCE_H_