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

};

enum Spells
{
    SPELL_BUZZ_SAW_CREATE_AT_VISUAL = 282898,
    SPELL_BUZZ_SAW_DAMAGE_KNOCK = 282945,

    SPELL_PLATINUM_PLATING = 282801,
    SPELL_WHIRLING_EDGE = 285020,
    SPELL_LAY_MINE_MISSILE = 285344,
    SPELL_LAY_MINE_CREATE_AREATRIGGER = 285351,
    SPELL_MAXIMUM_THRUST_DAMAGE = 283422,
    SPELL_AURA_VENT_JETS = 285388,
};

enum Events
{
    EVENT_BUZZ_SAW = 1,
    EVENT_WHIRLING_EDGE,
    EVENT_LAY_MINE,
    EVENT_MAXIMUM_THRUST,
    EVENT_VENT_JETS
};

const Position buzz_saws_charge_pos = { 454.811f, 224.149f, 72.0f, 1.5f };
const Position buzz_saws_spawn_pos = { 461.845f, 260.902f, 72.406f, 4.5f };

void AddSC_boss_tussie_tonks()
{
   
};
