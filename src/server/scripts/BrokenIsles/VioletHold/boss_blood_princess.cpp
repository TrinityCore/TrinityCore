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

#include "violet_hold_assault.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_DEATH = 0,
};

enum Spells
{
    SPELL_SHROUD_OF_SORROW = 203033,
    SPELL_SHROUD_OF_SORROW_DMG = 203057,
    SPELL_VAMPYR_KISS = 202652, //Find target
    SPELL_VAMPYR_KISS_JUMP = 202676,
    SPELL_VAMPYR_KISS_DMG = 202766,
    SPELL_VAMPYR_ESSENCE_1 = 202779, //Select target
    SPELL_VAMPYR_ESSENCE_2 = 202810, //Self target
    SPELL_VAMPYR_ESSENCE_MOD = 202781, //Mod dmg, threat...
    SPELL_FRENZIED_BLOODTHIRST = 202792,
    SPELL_UNCONTROLLABLE_FRENZY = 202804,
    SPELL_BLOOD_SWARM = 202659,
    SPELL_BLOOD_SWARM_TRIG = 202785,
    SPELL_BLOOD_SWARM_AT = 202944,

    //Heroic+
    SPELL_BLOOD_CALL = 203381,
    SPELL_BLOOD_CALL_VISUAL = 203405,
    SPELL_BLOOD_CALL_SUM = 203452,
    SPELL_BLOOD_DESTRUCT_AT = 203469,
    SPELL_ETERNAL_HUNGER = 203462,
};

enum eEvents
{
    EVENT_VAMPYR_KISS = 1,
    EVENT_BLOOD_SWARM = 2,
    EVENT_BLOOD_CALL = 3,

    EVENT_1,
    EVENT_2,
};

uint32 vampireAuras[4] =
{
    SPELL_VAMPYR_ESSENCE_1,
    SPELL_VAMPYR_ESSENCE_2,
    SPELL_FRENZIED_BLOODTHIRST,
    SPELL_UNCONTROLLABLE_FRENZY
};

bool IsVampire(Unit* unit)
{
    for (uint8 i = 0; i < 4; ++i)
        if (unit->HasAura(vampireAuras[i]))
            return true;

    return false;
}

void AddSC_boss_blood_princess_thalena()
{
 
}
