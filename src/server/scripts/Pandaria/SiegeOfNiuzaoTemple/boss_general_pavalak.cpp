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

enum Spells
{
    SPELL_BLADE_RUSH = 124283,
    SPELL_BLADE_RUSH_CHARGE = 124312,
    SPELL_BLADE_RUSH_SUMMON = 124277,
    SPELL_BLADE_RUSH_DISARM = 124327,
    SPELL_BLADE_RUSH_VISUAL = 124288,
    SPELL_BLADE_RUSH_VISUAL_TWO = 124307,
    SPELL_BLADE_RUSH_DUMMY = 124291,
    SPELL_BLADE_RUSH_DAMAGE_EFFECT = 124290,
    SPELL_BLADE_RUSH_FINAL_DAMAGE = 124317,
    SPELL_BULWARK = 119476,
    SPELL_AURA_PERIODIC_SUMMON_MANTID_SOLDIERS = 119781,
    SPELL_CARRYING_SIEGE_EXPLOSIVE = 119388,
    SPELL_ARMING_VISUAL = 88315,
    SPELL_DETONATE_AFTER_ARM = 119703,
    SPELL_SUMMON_SIEGE_EXPLOSIVE = 119377,
    SPELL_TEMPEST = 119875,
};

enum Events
{
    EVENT_CAST_BLADE_RUSH = 1,
    EVENT_CHARGE_AT_BLADE_RUSH_POS,
    EVENT_DO_CHARGE_DAMAGE_EFFECT,
    EVENT_START_ATTACKING_AGAIN,
    EVENT_CALL_REINFORCEMENTS,
    EVENT_STOP_BULWARK,
    EVENT_ARM_BOMB,
    EVENT_SIEGE_EXPLOSIVE_DETONATE,
    EVENT_SUMMON_SIEGE_EXPLOSIVE,
    EVENT_REPOSITION_EXPLOSIVE,
    EVENT_CAST_TEMPEST,
};

enum Actions
{
    ACTION_DELAYED_CAST_BLADE_RUSH_AT_TRIGGER = 1,
    ACTION_GENERAL_PAVALAK_BULWARK_REMOVED,
};

enum Points
{
    POINT_GENERAL_PAVALAK_CALL_IN_REINFORCEMENTS = 1,
    POINT_SIKTHIK_MOVE_TO_FIGHTZONE,
};

enum Misc
{
    NPC_BLADE_RUSH = 63720,
};

void AddSC_boss_general_pavalak()
{
   
}
