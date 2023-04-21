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

#ifndef FALL_OF_THERAMORE_HORDE_SCENARIO_H_
#define FALL_OF_THERAMORE_HORDE_SCENARIO_H_

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"

#define CHAPTERS 3

enum eCreature
{
    NPC_RIG_THIS_POWDER_BARREL = 58665,
    NPC_BLASTMASTER_SPARKFUSE  = 58765,
    NPC_THERAMORE_FOOTMAN      = 58612,
    NPC_THERAMORE_ARCANIST     = 59596,
    NPC_THERAMORE_FAITHFUL     = 59595,
    NPC_THERAMORE_MARKSMAN     = 59317,
    NPC_THERAMORE_OFFICER      = 58913,
    NPC_THERAMORE_GRYPHON      = 58782,
    NPC_KNIGHT_OF_THERAMORE    = 59654,
    NPC_BALDRUC                = 58777,
    NPC_BIG_BESSA              = 58787,
    NPC_UNMANNED_TANK          = 58788,
    NPC_THALEN_SONGWEAVER      = 58816,
    NPC_HEDRIC_EVENCANE        = 58840,
    NPC_SABOTAGED_TANK         = 58792,
    NPC_TANK_TARGET            = 59566,
    NPC_CAPTAIN_DROK           = 58870,
    NPC_LEAKED_OIL_DRUM        = 65571, // Alliance
    NPC_CAPTAIN_TELLERN        = 59088,
    NPC_SPELLSHARPER_LANARA    = 58948,
    NPC_CAPTAIN_DASHING        = 59089,
};

enum eSpellMiscId
{
    SPELL_TANK_EXPLOSION            = 39531,
    SPELL_THERAMORE_EXPLOSION_SCENE = 128446,
};

enum eData
{
    DATA_TO_THE_WATERLINE, // First chapter, done when u`ll explosive 6 barrels on ships
    DATA_THE_BLASTMASTER, // Second chapter, done when u`ll reach to Blastmaster and talk with him
    DATA_GRYPHON_DOWN, // Third chapter, done when u`ll kill 2 gryphons and leader of gryphons
    DATA_TANKS_FOR_NOTHING, // Four chapter, done when u`ll deactivate 2 tanks and kill activated
    DATA_FLY_SPY, // Last chapter, done when u`ll kill commander and break the shackles with spy.
    DATA_MAX_CHAPTER,

    // Misc Data
    DATA_SWEEP_THE_HARBOR = 1,
};

enum eActions
{
    ACTION_ACTIVATE_BY_REGION,
    ACTION_INTRO_SHIP,
    ACTION_INTRO_SONGWEAVER,
    ACTION_SONGWEAVER_CHAIN_BREAK,
};

enum eGamesObject
{
    GO_ORGRIMMAR_PORTAL = 215852,
};

enum worldstates
{
    WORLDSTATE_KITE_FIGHT  = 12604,
    WORLDSTATE_NO_KITE_YOU = 12606,
};

enum Criteries
{
    CRITERIA_BARRELS_EXPLOSIVE        = 22180,
    CRITERIA_ALLIANCE_CAPTAIN_SLAINED = 22381,
    CRITERIA_BALDRUK_SLAIN            = 19981,
    CRITERIA_GRYPHONE_SLAIN           = 19982,
    CRITERIA_BIG_BESSA_SLAIN          = 19983,
    CRITERIA_TANKS_EXPLOSIVE          = 19980,
    CRITERIA_HEDRIK_SLAIN             = 19987,
};

#endif // FALL_OF_THERAMORE_HORDE_H_