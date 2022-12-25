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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Vehicle.h"

enum Spells
{
    SPELL_SAP_PUDDLE_SUMMON = 123112,
    SPELL_CARRYING_CAUSTIC_TAR = 123032,
    SPELL_MANTID_BARREL_ACTIVE = 123215,
    SPELL_MANTID_BARREL_INACTIVE = 123218,
    SPELL_GRAB_BARREL = 120405,
    SPELL_LOOT_SPARKLES = 92406,
    SPELL_SAP_PUDDLE_SLOW = 120270,
    SPELL_CARRYING_EXPLOSIVES = 121986,
    SPELL_BOMBARD_PERIODIC = 120559,
    SPELL_THOUSAND_BLADES = 120759,
    SPELL_DASHING_STRIKE = 120789,
    SPELL_AURA_CAUSTIC_TAR = 120778,
    SPELL_FRANTIC_FITHER = 120757,
    SPELL_RISING_SPEED = 120758,
    SPELL_BLUE_ARROW = 87864,

    BFA_SPELL_SLEEP = 9454,
};

enum Events
{
    EVENT_YANG_DO_IRONCLAW_INTRO_EVENT = 1,
    EVENT_YANG_DO_IRONCLAW_BOSS_ORDER_CHECK,
    EVENT_PICK_UP_BARREL,
    EVENT_MOVE_TO_BARREL_DROP_SPOT,
    EVENT_MOVE_BACK_TO_BARREL_PICKUP_SPOT,
    EVENT_VOJAK_SAY_INTRO_LINE_ONE,
    EVENT_VOJAK_SAY_INTRO_LINE_TWO,
    EVENT_VOJAK_SUMMON_SIKTHIK_SWARMER,
    EVENT_VOJAK_SUMMON_SIKTHIK_DEMOLISHER,
    EVENT_VOJAK_SUMMON_SIKTHIK_SWARMER_AND_WARRIOR,
    EVENT_VOJAK_SUMMON_SIKTHIK_DEMOLISHER_AND_WARRIOR,
    EVENT_VOJAK_SUMMON_AIR_SUPPORT,
    EVENT_CHECK_FOR_SAP_PUDDLE,
    EVENT_CHECK_FOR_ALIVE_PLAYERS,
    EVENT_AMBERWING_RETREAT,
    EVENT_AMBERWING_START_MOVING,
    EVENT_VOJAK_MOVE_TO_PLATFORM,
    EVENT_CAST_DASHING_STRIKE,
    EVENT_CAST_THOUSAND_BLADES,

};

enum Points
{
    POINT_YANG_IRONCLAW_INTRO = 1,
    POINT_LO_LI_CHU_BARREL_PICKUP_SPOT,
    POINT_LO_LI_CHU_PLANT_BOMB_POS,
    POINT_SIKTHIK_MOVE_TO_HALFWAY,
    POINT_MOVE_TO_PLATFORM_TOP,
    POINT_AMBERWING_WAYPOINT,
    POINT_AMBERWING_RETREAT,
};

enum Actions
{
    ACTION_CHU_START_PLANTING_BARRELS = 1,
    ACTION_CHU_MOVE_TO_BARREL_DROP_SPOT_INITIAL,
    ACTION_CHU_MOVE_TO_BARREL_DROP_SPOT,
    ACTION_VOJAK_START_ENCOUNTER,
    ACTION_ENCOUNTER_RESET,
};

enum Misc
{
    NPC_LI_CHU = 61812,
    NPC_LO_CHU = 62794,
    NPC_SIKTHIK_SWARMER = 63106,
    NPC_SIKTHIK_DEMOLISHER = 61670,
    NPC_SIKTHIK_AMBERWING = 61699,
    NPC_YANG_IRONCLAW = 61620,
    NPC_SAP_PUDDLE = 61579,
    NPC_SIKTHIK_WARRIOR = 61701,
    NPC_MANTID_TAR_KEG = 61817,
};

Position LiChuBarrelPlacePosition[3] =
{
    { 1547.93f, 5289.14f, 184.73f, 0.0f },
    { 1533.28f, 5311.80f, 184.64f, 0.0f },
    { 1551.89f, 5313.00f, 184.64f, 0.0f },
};

Position LoChuBarrelPlacePosition[3] =
{
    { 1488.72f, 5299.47f, 184.64f, 0.0f },
    { 1515.69f, 5309.72f, 184.64f, 0.0f },
    { 1490.19f, 5308.79f, 184.64f, 0.0f },
};

Position SikthikAmberwingWaypoint[6]
{
    { 1648.000f, 5398.483f, 158.9442f },
    { 1630.078f, 5402.018f, 163.3863f },
    { 1574.807f, 5394.819f, 173.6126f },
    { 1548.351f, 5376.471f, 192.1736f },
    { 1529.559f, 5346.958f, 196.6980f },
    { 1527.813f, 5316.797f, 196.6980f },
};

void AddSC_boss_commander_vojak()
{
    
}
