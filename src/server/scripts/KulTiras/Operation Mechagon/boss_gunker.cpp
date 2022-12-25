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
    SPELL_PERIODIC_ENERGY_GAIN = 295065,
    SPELL_GUNKER_VISUAL = 300859,
    SPELL_GOOPED_CREATE_AURA_AT = 297821,
    SPELL_GOOPED_INCAPCITATED = 298124,
    SPELL_GOOPED_MAIN = 298259,
    SPELL_TOXIC_FLAMES_TRIGGER = 298228,
    SPELL_SPLATTER_TRIGGER = 297985,
    SPELL_COALESCE = 297835,
    SPELL_SLUDGE_BOLT = 298212,
    SPELL_TOXIC_WAVE = 297834,
    SPELL_SANITIZING_SPRAY = 297901,
    SPELL_SANITIZING_AURA = 298145,
    SPELL_SANITIZING_SPRAY2 = 298216,
};

enum Events
{
    EVENT_COALESCE = 1,
    EVENT_GOOPED,
    EVENT_SLUDGE_BOLT,
    EVENT_SPLATTER,
    EVENT_TOXIC_WAVE,
    EVENT_TOXIC_FLAMES
};

const Position squirt_bot_pos = { 626.622f, -348.212f, 0.423f, 3.54f };
const Position squirt_bot_pos2 = { 595.423f, -325.170f, 1.017f, 4.79f };
const Position squirt_bot_pos3 = { 577.199f, -359.477f, 0.864f, 0.11f };

void AddSC_boss_gunker()
{   
   
}