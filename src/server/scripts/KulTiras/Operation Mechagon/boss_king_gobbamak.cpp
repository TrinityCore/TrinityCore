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
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "operation_mechagon.h"

enum Spells
{
    SPELL_CHARGED_SMASH = 297254,
    SPELL_ELECTRICAL_CHARGE = 297257,
    SPELL_RUMBLE = 297261,
    SPELL_PERIODIC_ENERGY_GAIN = 295065,
};

enum Texts
{
    SAY_AGGRO = 0,
    SAY_SMASH,
    SAY_RUMBLE,
    SAY_GETEM,
    SAY_KILL,
    SAY_DEATH
};

enum Events
{
    EVENT_CHARGED_SMASH = 1,
    EVENT_ELECTRICAL_CHARGE,
    EVENT_RUMBLE,
    EVENT_GETEM
};

const Position cave_pos = { 1188.0f, -75.0f, 21.84f, 3.59f };

void AddSC_boss_king_gobbamak()
{
   
}