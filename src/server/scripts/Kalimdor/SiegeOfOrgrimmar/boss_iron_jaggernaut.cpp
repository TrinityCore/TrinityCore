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

#include "siege_of_orgrimmar.hpp"
#include "MoveSplineInit.h"
#include "SpellMgr.h"
#include <algorithm>

enum ScriptedTexts
{
    SAY_SIEGE_MODE = 0,
    SAY_ASSAULT_MODE = 1,
};

enum Spells
{
    SPELL_BERSERK = 26662,

    // TODO: We should use this spells to handle energy regeneration/degeneration
    // but there is 1000 msec periodic in spells
    // Don't know how to use it correctly
    SPELL_REGENERATION = 146359,
    SPELL_DEPLETION = 146360,

    SPELL_BORER_DRILL = 144209,
    SPELL_BORER_DRILL_AURA = 144221, // npc 'borer drill' has it
    SPELL_BORER_DRILL_AREATRIGGER = 144220,
    SPELL_BORER_DRLL_DMG = 144218,
    SPELL_BORER_DRILL_VISUAL_1 = 144296,
    SPELL_BORER_DRILL_VISUAL_2 = 148823,

    SPELL_SCATTER_LASER_FORCE = 144460, // main spell
    SPELL_LASER_STRIKE = 144456,
    SPELL_SCATTER_LASER_FORCE_2 = 144458, // on players
    SPELL_LASER_BURN = 144459,

    SPELL_MORTAR_BLAST_FORCE = 145407, // main spell
    SPELL_MORTAR_BLAST_AOE = 144315, // select targets
    SPELL_MORTAR_BLAST_MISSILE = 146027,
    SPELL_MORTAR_BLAST_DMG = 144316,

    SPELL_MORTAR_BLAST_FORCE_2 = 144555, // heroic
    SPELL_MORTAR_BLAST_PERIODIC = 144554, // heroic
    SPELL_MORTAR_BLAST_MISSILE_2 = 144553, // heroic
    SPELL_MORTAR_BLAST_DMG_2 = 144556, // heroic

    SPELL_RICOCHET_AREAGRIGGER = 144356,
    SPELL_RICOCHET_AURA = 144375,
    SPELL_RICOCHET_DMG = 144327,
    SPELL_DISAPPEAR = 149501,
    SPELL_DISAPPEAR_REMOVE = 149502,

    SPELL_FLAME_VENTS = 144464,
    SPELL_IGNITE_ARMOR = 144467,

    SPELL_CRAWLER_MINE_AOE = 144673, // select targets
    SPELL_CRAWLER_MINE_SUMMON = 144705,
    SPELL_CRAWLER_MINE_IMMUNITY = 149836,
    SPELL_CRAWLER_MINE_JUMP_3 = 149837, // remove immunities
    SPELL_SUPERHEATED_CRAWLER_MINE = 146342, // created when laser touchs crawler mine
    SPELL_DETONATION_SEQUENCE = 144718,
    SPELL_CRAWLER_MINE_BLAST = 144766, // dmg to all players

    SPELL_GROUND_POUND = 144776, // player jumps on crawler mines
    SPELL_ENGULFED_EXPLOSION_DMG = 144791,

    SPELL_SEISMIC_ACTIVITY = 144483,
    SPELL_SEISMIC_ACTIVITY_DMG = 144484,
    SPELL_SEISMIC_ACTITITY_DEST = 144557,

    SPELL_SHOCK_PULSE = 144485,

    SPELL_DEMOLISHER_CANNONS_PERIODIC = 144199,
    SPELL_DEMOLISHER_CANNONS_AOE = 144198, // select targets
    SPELL_DEMOLISHER_CANNONS_MISSILE = 144153,
    SPELL_DEMOLISHER_CANNONS_DMG = 144154,

    SPELL_CUTTER_LASER_AOE = 144573, // casted by 'cutter laser' dummy
    SPELL_CUTTER_LASER_RAY = 144576,
    SPELL_CUTTER_LASER_FORCE = 145190, // triggers script ??
    SPELL_CUTTER_LASER_SCRIPT = 144575, // ??
    SPELL_CUTTER_LASER_TARGET = 146325,
    SPELL_CUTTER_LASER_DMG = 144918,

    SPELL_EXPLOSIVE_TAR_PERIODIC = 144492,
    SPELL_EXPLOSIVE_TAR_MISSILE = 144496,
    SPELL_EXPLOSIVE_TAR_SUMMON = 144497,
    SPELL_EXPLOSIVE_TAR_VISUAL = 146191,
    SPELL_EXPLOSIVE_TAR_DMG = 144498,
    // 144525 explosive tar unknown (aura without visuals)
    SPELL_TAR_EXPLOSION = 144919,
};

enum Adds
{
    NPC_BORER_DRILL = 71906,

    NPC_CANNON_LEFT = 71468,
    NPC_CANNON_RIGHT = 71913,
    NPC_TOP_CANNON = 71484,
    NPC_TAIL_GUN = 71914,

    NPC_SAWBLADE_1 = 71469, // basic
    NPC_SAWBLADE_2 = 71945, // invisible

    NPC_CRAWLER_MINE = 72050,
    NPC_CRAWLER_MINE_2 = 72060, // invisible, summoned by 144705 (I think it's target for real mine jumping)

    NPC_CUTTER_LASER = 72026,

    NPC_EXPLOSIVE_TAR = 71950,
};

enum Events
{
    EVENT_BERSERK = 1,
    EVENT_SIEGE_MODE_PREPARE,
    EVENT_ASSAULT_MODE_PREPARE,
    EVENT_FLAME_VENTS,
    EVENT_BORER_DRILL,
    EVENT_SCATTER_LASER,
    EVENT_MORTAR_BLAST,
    EVENT_CRAWLER_MINE,
    EVENT_MORTAR_BLAST_SIEGE_MODE,
    EVENT_RICOCHET,

    EVENT_SHOCK_PULSE,
    EVENT_DEMOLISHER_CANNONS,
    EVENT_CUTTER_LASER,
    EVENT_EXPLOSIVE_TAR,

};

enum Actions
{
    ACTION_DEMOLISHER_CANNONS = 1,
    ACTION_CUTTER_LASER,
    ACTION_SAWBLADE_RICOCHET
};

enum eData
{
    DATA_CRAWLER_MINE_DUMMY = 1,
    DATA_CUTTER_LASER_GUID,
    DATA_BORER_DRILL_TARGET,
};

enum VehicleSeatPositions
{
    TOP_CANNON_SEAT = 0,
    SAWBLADE_SEAT = 1,
    RIGHT_CANNON_SEAT = 2,
    LEFT_CANNON_SEAT = 3,
    TAIL_GUN_SEAT = 4,
};

enum Phases
{
    PHASE_NONE = 0,
    PHASE_ASSAULT = 1,
    PHASE_SIEGE = 2,
};

enum Timers
{
    TIMER_BERSERK_NORMAL = 10 * MINUTE * IN_MILLISECONDS,
    TIMER_BERSERK_HEROIC = 8 * MINUTE * IN_MILLISECONDS,
    TIMER_FLAME_VENTS_FIRST = 9 * IN_MILLISECONDS,
    TIMER_FLAME_VENTS = 10 * IN_MILLISECONDS,
    TIMER_BORER_DRILL = 17 * IN_MILLISECONDS,
    TIMER_MORTAR_BLAST = 7 * IN_MILLISECONDS,
    TIMER_SCATTER_LASER = 11500,
    TIMER_CRAWLER_MINE = 30 * IN_MILLISECONDS,
    TIMER_DEMOLISHER_CANNONS = 9500,
    TIMER_RICOCHET_FIRST = 15 * IN_MILLISECONDS,
    TIMER_RICOCHET = 20 * IN_MILLISECONDS,

    TIMER_SHOCK_PULSE = 16500,
    TIMER_CRAWLER_MINE_SIEGE_MODE = 7 * IN_MILLISECONDS, // after Shock Pulse
    TIMER_CUTTER_LASER = 25 * IN_MILLISECONDS,
    TIMER_EXPLOSIVE_TAR_FIRST = 7000,
    TIMER_EXPLOSIVE_TAR = 30000,
    TIMER_MORTAR_BLAST_SIEGE_FIRST = 20 * IN_MILLISECONDS,
    TIMER_MORTAR_BLAST_SIEGE = 30 * IN_MILLISECONDS,

    TIMER_SIEGE_MODE_PREPARE = 1 * IN_MILLISECONDS,
    TIMER_ASSAULT_MODE_PREPARE = 1 * IN_MILLISECONDS,
    TIMER_ASSAULT_MODE_REGENERATE = 1200,
    TIMER_SIEGE_MODE_REGENERATE = 600,
};

#define MAX_POWER_ENERGY 100
#define POWER_TYPE POWER_ENERGY
#define MAX_CRAWLER_MINES 3
#define SCATTER_LASER_COUNT_10 1
#define SCATTER_LASER_COUNT_25 3
#define CUTTER_LASER_RADIUS 2.0f
#define EXPLOSIVE_TAR_RADIUS 4.0f
#define BOSS_COMBAT_REACH_SIZE 15.0f
#define DEFAULT_RANGE_TARGETS_DIST 15.0f
#define BOSS_RANGE_TARGETS_DIST (BOSS_COMBAT_REACH_SIZE - DEFAULT_RANGE_TARGETS_DIST)
#define BORER_DRILL_COUNT 3
#define RICOCHET_COUNT 2

void GetPositionUnderJuggernautClaw(Creature* pJuggernaut, Position& pos, bool isLeft)
{
    if (isLeft)
    {
        pos = pJuggernaut->GetNearPosition(13.0f, 0.3f);
        //pJuggernaut->GetNearPosition(pos, 13.0f, 0.3f);
    }
    else
    {
        pos = pJuggernaut->GetNearPosition(13.0f, -0.3f);
        //pJuggernaut->GetNearPosition(pos, 13.0f, -0.3f);
    }
}

Creature* GetIronJuggernaut(WorldObject* searcher)
{
    if (InstanceScript* pInstance = searcher->GetInstanceScript())
    {
        return pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_IRON_JUGGERNAUT));
    }

    return NULL;
}

void AddSC_boss_iron_juggernaut()
{
   
}
