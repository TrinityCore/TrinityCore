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
    SAY_AIR_DROP,
    SAY_VENTING_FLAMES,
    SAY_EXPLOSIVE_LEAP,
    SAY_DEATH
};

enum Spells
{
    SPELL_AIR_DROP_DAMAGE_KNOCK = 291930,
    SPELL_JUNK_BOMB_DAMAGE = 291953,
    SPELL_EXPLOSIVE_LEAP_TRIGGER = 291973,
    SPELL_EXPLOSIVE_LEAP_DAMAGE = 292035,
    SPELL_VENTING_FLAMES = 291946,
    SPELL_VENTING_FLAMES_DAMAGE = 291949, // triggered by previous spell already
    SPELL_BLAZING_CHOMP = 294929,
};

enum Events
{
    EVENT_AIR_DROP = 1,
    EVENT_EXPLOSIVE_LEAP,
    EVENT_VENTING_FLAMES,
    EVENT_BLAZING_CHOMP
};

const Position middle_of_the_room = { 583.771f, 245.203f, -333.555f, 1.05f };

void AddSC_boss_kujo()
{
    
};
