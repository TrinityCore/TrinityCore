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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "Vehicle.h"
#include "InstanceScript.h"
#include "operation_mechagon.h"

enum Texts
{
    SAY_HK_AGGRO = 0,
    SAY_CANNON_BLAST,
    SAY_REINFORCEMENTS,
    SAY_STAGE_TWO,
    SAY_DEATH
};

enum Spells
{
    //HK8
    SPELL_CANNON_BLAST_TRIGGER = 295536,
    SPELL_CANNON_BLAST_MISSILE = 302098,
    SPELL_REINFORCEMENT_RELAY_TRIGGER_SUMMON = 301351,
    SPELL_ANNIHILATION_RAY_CHANNEL = 295939,
    SPELL_ANNIHILATION_BLAST = 303206,
    SPELL_HAYWIRE = 296080,
    SPELL_LIFT_OFF = 301177,
    SPELL_FORCE_SHIELD = 300011,

    //Overcharge Station
    SPELL_HACK = 296260,

    //Walkie Shockie X1
    SPELL_AREA_DENIAL_BOT = 296517,
    SPELL_STATIC_DISCHARGE = 302384,
    SPELL_STATIC_DISCHARGE_CREATE_AT = 296518,
    SPELL_CLINGING_STATIC_DAMAGE = 296560,
    SPELL_SELF_DESTRUCT = 296522,
};

const Position boss_hk_default_encounter_pos = { 632.534f, -43.874f, 92.058f, 5.39f };
const Position mk1_spawn_pos = { 607.170f, -20.907f, 71.112f, 5.478f };
const Position annhilation_pos = { 615.586f, -22.346f, 87.0f, 5.43f };

void AddSC_boss_hk8()
{
   
};
