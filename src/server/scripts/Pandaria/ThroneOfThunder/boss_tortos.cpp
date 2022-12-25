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
#include "Unit.h"
#include "Player.h"
#include "Creature.h"
#include "InstanceScript.h"
#include "Map.h"
#include "VehicleDefines.h"
#include "SpellInfo.h"

#include "throne_of_thunder.h"

enum Yells
{
    // Boss
    ANN_TURTLES = 0,      // Tortos lets out a booming call, attracting nearby turtles.
    ANN_FURIOUS_BREATH                    // Tortos prepares to unleash a [Furious Stone Breath]!
};

enum Spells
{
    // Boss
    SPELL_ZERO_POWER = 72242,  // No Regen

    SPELL_KICK_SHELL_A = 134030, // Boss aura for adding mechanic abilities to players in 130y radius.

    SPELL_CALL_OF_TORTOS = 136294, // Dummy on eff 0 for summoning 3 turtles.
    SPELL_FURIOUS_STONE_BREATH = 133939, // Triggers damage each 500 ms + prevents Fury regen for duration.
    SPELL_GROWING_FURY = 136010, // When no players are in melee range. Adds 10 Fury.
    SPELL_SNAPPING_BITE = 135251, // On tank, main ability.

    SPELL_QUAKE_STOMP = 134920, // Massive AOE damage. Interruptible. Triggers SPELL_ROCKFALL_STOMP.
    SPELL_ROCKFALL_STOMP = 134915, // 8 second aura triggering SPELL_ROCKFALL_STOMP_S_TRIG each 500 ms.
    SPELL_ROCKFALL_STOMP_S_TRIG = 140431, // Dummy on eff 0 for SPELL_ROCKFALL_SUMMON on random player.

    SPELL_ROCKFALL_AURA = 134849, // Triggers SPELL_ROCKFALL_AURA_S_TRIG each 10 seconds. Permanent boss aura in fight.
    SPELL_ROCKFALL_AURA_S_TRIG = 134364, // Dummy on eff 0 for SPELL_ROCKFALL_SUMMON on random player.
    SPELL_ROCKFALL_SUMMON = 134365, // Summons NPC_ROCKFALL_TORTOS.

    SPELL_SUMMON_BATS = 136686, // Summons 8 Vampiric Cave Bats.

    // Adds

    // Whirl Turtle
    SPELL_SPINNING_SHELL_VISUAL = 133974, // Spin + aura visual.
    SPELL_SPINNING_SHELL_DUMMY = 140443, // Speed decrease + periodic dummy on effect 1 for SPELL_SPINNING_SHELL_DMG.
    SPELL_SPINNING_SHELL_DMG = 134011, // Damage and knockback.

    SPELL_SHELL_BLOCK = 133971, // Damage immune and kickable state aura.

    SPELL_KICK_SHELL_TRIGGER = 134031, // Spell from mechanic abilities button. Sends turtles forward fast. Needs turtle aura SPELL_SHELL_BLOCK to become usable.
    SPELL_KICK_SHELL_STUN = 134073, // Unused.

    SPELL_SHELL_CONCUSSION = 134092, // When kicked, aura triggering SPELL_SHELL_CONCUSSION_INT and SPELL_SHELL_CONCUSSION_D_IN each 300 ms.
    SPELL_SHELL_CONCUSSION_INT = 134091, // Spell casting interruption for 3 seconds in 8y.
    SPELL_SHELL_CONCUSSION_D_IN = 136431, // Damage taken increase by 50% in 8y.

    // Vampiric Cave Bat
    SPELL_DRAIN_THE_WEAK_A = 135103, // Triggers SPELL_DRAIN_THE_WEAK_DMG if target is below 35% health and drains 50x damage dealt.
    SPELL_DRAIN_THE_WEAK_DMG = 135101, // 25% weapon damage.

    // Rockfall
    SPELL_ROCKFALL = 134475, // Visual on ground and triggers 134539 missile drop + damage after 5 seconds.

    // Humming Crystal - HEROIC only.
    SPELL_CRYSTAL_SHELL_AURA = 137552, // Adds SPELL_CRYSTAL_SHELL_ABS, SPELL_CRYSTAL_SHELL_MOD_ABS to player attackers.
    SPELL_CRYSTAL_SHELL_ABS = 137633, // Eff 0 absorb, eff 1 dummy for absorbing max 15% of player's hp.
    SPELL_CRYSTAL_SHELL_MOD_ABS = 137648, // Eff 0 mod absorb %, eff 1 dummy for adding player aura SPELL_CRYSTAL_SHELL_CAPPED on cap when absorbing max 75% player hp.
    SPELL_CRYSTAL_SHELL_CAPPED = 140701  // "Maximum capacity" dummy aura from Crystal Shield (at 5 stacks).
};

enum Npcs
{
    // Boss
    NPC_WHIRL_TURTLE = 67966,
    NPC_VAMPIRIC_CAVE_BAT = 69352,
    NPC_ROCKFALL_TORTOS = 68219,

    // Misc
    NPC_HUMMING_CRYSTAL = 69639  // HEROIC only. When attacked adds Crystal Shell debuff to player atacker.
};

enum Events
{
    // Boss
    EVENT_CALL_OF_TORTOS = 1,
    EVENT_FURIOUS_STONE_BREATH,
    EVENT_RESET_CAST,
    EVENT_SNAPPING_BITE,
    EVENT_QUAKE_STOMP,
    EVENT_SUMMON_BATS,
    EVENT_DAMAGE_PLAYERS_SPIN,
    EVENT_GROWING_FURY,
    EVENT_REGEN_FURY_POWER,

    EVENT_BERSERK,

    // Whirl Turtle
    EVENT_SHELL_BLOCK,
    EVENT_CAST_SHELL_CONCUSSION,
    EVENT_KICKED,
    EVENT_MOVE_STOP,

    // Rockfall trigger
    EVENT_DESPAWN_ME,
    EVENT_MAKE_PLAYERS_IMMUNE_TO_AOE,
};

enum Timers
{
    // Boss
    TIMER_CALL_OF_TORTOS_F = 21000,
    TIMER_CALL_OF_TORTOS_S = 60500,

    TIMER_QUAKE_STOMP_F = 27000,
    TIMER_QUAKE_STOMP_S = 47000,

    TIMER_FURIOUS_STONE_BREATH = 500,
    TIMER_RESET_CAST = 6000,

    TIMER_SNAPPING_BITE_N = 12000,
    TIMER_SNAPPING_BITE_H = 8000,

    TIMER_CALL_BATS_F = 57000,
    TIMER_CALL_BATS_S = 50000,

    TIMER_GROWING_FURY = 6000,
    TIMER_REGEN_FURY_POWER = 450,

    TIMER_BERSERK_H = 600000, // 10 minutes (Heroic).
    TIMER_BERSERK = 780000  // 13 minutes.
};

enum iActions : uint32
{
    ACTION_ACTIVATE_INTRO = 1
};

static const Position aTurtlePos[3] =
{
    { 6046.86f, 4906.66f, -61.18f },
    { 6032.83f, 4906.31f, -61.18f },
    { 6040.08f, 4907.01f, -61.18f },
};

static const Position aBatPos[4] =
{
    { 6043.39f, 5039.37f, -16.43f, 4.66f },
    { 6040.19f, 4922.61f, -15.34f, 1.53f },
    { 6092.45f, 4958.73f, -14.09f, 2.82f },
    { 5996.11f, 4978.12f, -11.01f, 6.21f }
};

static const Position TurtleWp = { 6041.33f, 4940.45f, -61.f };

void AddSC_boss_tortos()
{
    
}
