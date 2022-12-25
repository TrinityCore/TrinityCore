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
    SAY_AGGRO = 0,
    SAY_GIGA_ZAP,
    SAY_TAKE_OFF,
    SAY_STAGE_TWO,
    SAY_MAGNETO_ARM,
    SAY_KILL,
    SAY_DEATH
};

enum Spells
{    
    SPELL_PULSE_BLAST = 291878,
    SPELL_PLASMA_ORB_DAMAGE_KNOCK = 291915,
    SPELL_PLASMA_ORB_APPLY_AT_VISUAL = 291835,
    SPELL_RECALIBRATE_DAMAGE_KNOCK = 291856,
    SPELL_RECALIBRATE_TAR_DEST_VISUAL = 291845,
    SPELL_GIGA_ZAP_MAIN = 291928,
    SPELL_GIGA_ZAP_DAMAGE = 291939,
    SPELL_TAKE_OFF = 291613,
    SPELL_CUTTING_BEAM_CREATE_AT = 291626,
    SPELL_OBNOXIOUS_MONOLOQUE = 291974,
    SPELL_MAGNETO_ARM_CREATE_AT = 283143,
};

enum Events
{
    EVENT_PULSE_BLAST = 1,
    EVENT_PLASMA_ORBS,
    EVENT_RECALIBRATE,
    EVENT_GIGA_ZAP,
    EVENT_TAKE_OFF,
    EVENT_STAGE_TWO,
    EVENT_CUTTING_BEAM,
    EVENT_MAGNETO_ARM
};

Vehicle* vehicle;

const Position king_mechagon_jump_pos = { 699.518f, 623.309f, -238.285f, 5.25f };
const Position king_mechagon_vehicle_escort_pos = { 633.195f, 551.366f, -266.912f, 5.25f };

void AddSC_boss_king_mechagon()
{
    
};
