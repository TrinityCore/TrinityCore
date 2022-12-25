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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "MapManager.h"
#include "Spell.h"
#include "Vehicle.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CreatureTextMgr.h"
#include "Weather.h"

#include "heart_of_fear.h"

enum eGaralonYells
{
    // He's a bug! Has no yells, just announces.
    ANN_CRUSH = 0, // Garalon begins to [Crush] his opponents!
    ANN_MEND = 1, // Garalon [Mends] one of his legs!
    ANN_FURY = 2, // Garalon fails to hit at least two players and gains [Fury]!
    ANN_DAMAGED = 3, // Garalon's massive armor plating begins to crack and split!
    ANN_BERSERK = 4  // Garalon becomes [Enraged] and prepares to execute a [Massive Crush]!
};

enum eGaralonSpells
{
    /*** Garalon ***/
    SPELL_FURIOUS_SWIPE = 122735, // Primary attack ability.
    SPELL_FURY = 122754, // If he doesn't hit at least two targets with Swipe.

    SPELL_CRUSH_BODY_VIS = 122082, // Visual for boss body, blue circle underneath. Triggers SPELL_CRUSH_TRIGGER each sec.
    SPELL_CRUSH_TRIGGER = 117709, // Dummy effect for SPELL_CRUSH_DUMMY casted on players in 14 yards.
    SPELL_CRUSH_DUMMY = 124068, // Dummy placed on players underneath. They take the extra damage.

    SPELL_CRUSH = 122774, // Extra damage for players underneath (in 14 yards), on Effect 1.
    SPELL_MASSIVE_CRUSH = 128555, // Hard enrage spell, used to wipe the raid: 10 million damage.

    SPELL_PHER_INIT_CAST = 123808, // When boss is pulled, after 2 secs this casts SPELL_PHEROMONES_AURA on nearest player.
    SPELL_PHEROMONES_AURA = 122835, // Trig SPELL_PHEROMONES_TAUNT, SPELL_PUNGENCY, SPELL_PHEROMONES_DMG, SPELL_PHEROMONES_FC / 2s + SPELL_PHER_CANT_BE_HIT, SPELL_PHEROMONES_DUMMY.

    SPELL_PHEROMONES_TAUNT = 123109, // Garalon Taunt / Attack Me spell.
    SPELL_PUNGENCY = 123081, // Stacking 10% damage increase aura.
    SPELL_PHEROMONES_DMG = 123092, // Damage spell, triggers SPELL_SUMM_PHER_TRAIL.
    SPELL_SUMM_PHER_TRAIL = 128573, // Summon spell for NPC_PHEROMONE_TRAIL.
    SPELL_PHEROMONES_FC = 123100, // Force Cast of SPELL_PHEROMONES_JUMP in 5 yards.
    SPELL_PHER_CANT_BE_HIT = 124056, // Some kind of dummy check.
    SPELL_PHEROMONES_DUMMY = 130662, // Special prereq dummy for SPELL_PHER_INIT_CAST.

    SPELL_DAMAGED = 123818, // Heroic, 33%. Uses melee, increased speed, ignores Pheromones taunt.

    // SPELL_BERSERK          = 120207, // Enrage, 420 seconds, or 7 minutes.

    /*** Pheromone Trail ****/
    SPELL_PHER_TRAIL_DMG_A = 123106, // Triggers SPELL_PHER_TRAIL_DMG each sec.
    SPELL_PHER_TRAIL_DMG = 123120, // 25000 damage in 4 yards.

    /*** Garalon's Legs ****/
    // Ride Vehicle auras for each Leg.
    SPELL_RIDE_FRONT_RIGHT = 123430, // Ride Vehicle (Front Right Leg) - Triggers 122757 Weak Points aura which triggers SPELL_WEAK_POINT_VIS1 and SPELL_WEAK_POINTS_FR.
    SPELL_RIDE_FRONT_LEFT = 123431, // Ride Vehicle (Front Left Leg)  - Triggers 123424 Weak Points aura which triggers SPELL_WEAK_POINT_VIS2 and SPELL_WEAK_POINTS_FL.
    SPELL_RIDE_BACK_LEFT = 123432, // Ride Vehicle (Back Left Leg)   - Triggers 123425 Weak Points aura which triggers SPELL_WEAK_POINT_VIS3 and SPELL_WEAK_POINTS_BL.
    SPELL_RIDE_BACK_RIGHT = 123433, // Ride Vehicle (Back Right Leg)  - Triggers 123427 Weak Points aura which triggers SPELL_WEAK_POINT_VIS4 and SPELL_WEAK_POINTS_BR.

    // Weak Points: 12 yard 100% proximity leg damage increase.
    SPELL_WEAK_POINTS_FR = 123235, // Right, front.
    SPELL_WEAK_POINTS_FL = 123423, // Left,  front.
    SPELL_WEAK_POINTS_BL = 123426, // Left,  back.
    SPELL_WEAK_POINTS_BR = 123428, // Right, back.

    // Weak Points: Visual triggers for Broken Leg animations. --! No scripting usage.
    SPELL_WEAK_POINT_VIS1 = 128599, // All these 4 spells trigger SPELL_BROKEN_LEG_VIS (one for each Leg).
    SPELL_WEAK_POINT_VIS2 = 128596,
    SPELL_WEAK_POINT_VIS3 = 128600,
    SPELL_WEAK_POINT_VIS4 = 128601,

    // Broken Leg: Boss 15% speed decrease stacking aura / 3 % HP damage spell. Stacks to 4 x 15% = 60% speed decrease.
    SPELL_BROKEN_LEG = 122786, // Boss self-cast spell.

    // Broken Leg: Visual (triggered by spells from SPELL_WEAK_POINT_VIS) - "Blood" dripping out.
    SPELL_BROKEN_LEG_VIS = 123500,

    // Mend Leg: Boss Leg heal spell. Used every 30 seconds after a leg dies.
    SPELL_MEND_LEG = 123495, // Dummy, handled to "revive" the leg. Triggers 123796 script effect to remove SPELL_BROKEN_LEG from boss, we don't use it.

    SPELL_GARALON_BONUS = 132196
};

enum eGaralonEvents
{
    // Garalon
    EVENT_FURIOUS_SWIPE = 1,      // About 8 - 11 seconds after pull. Every 8 seconds.
    EVENT_PHEROMONES,               // About 2 -  3 seconds after pull.
    EVENT_CRUSH,                    // About 30     seconds after pull. Every 37.5 seconds.
    EVENT_MEND_LEG,

    EVENT_GARALON_BERSERK           // Goes with SPELL_MASSIVE_CRASH.
};

enum eGaralonActions
{
    // Garalon
    ACTION_FUR_SWIPE_FAILED = 1,
    ACTION_PHEROMONES_JUMP_OR_PLAYERS_UNDERNEATH, // Normal Difficulty - Galaron casts Crush when Pheromones jump to another player / when he detects players underneath him.
    ACTION_LEG_IS_DEAD,
    ACTION_MENDED_LEG,

    // Garalon's Legs
    ACTION_LEG_DIED,
    ACTION_MEND_LEG,          // Heal leg.
    ACTION_LEG_WIPE
};

enum eGaralonEntries
{
    NPC_GARALON_LEG = 63053,
    NPC_PHEROMONE_TRAIL = 63021
};

enum eGaralonDisplayId
{
    DISPLAY_LEG_ACTIVE = 42852
};

enum eGaralonGuids
{
    GUID_MENDED_LEG = 1
};

uint32 legSpells[4] = { SPELL_RIDE_FRONT_RIGHT, SPELL_RIDE_FRONT_LEFT, SPELL_RIDE_BACK_RIGHT, SPELL_RIDE_BACK_LEFT };

void AddSC_boss_garalon()
{
   
}
