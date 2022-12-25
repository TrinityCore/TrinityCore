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

#include "new_karazhan.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_EVOCATION = 1,
    SAY_DEATH = 2,
};

enum Spells
{
    SPELL_COSMETIC_MANA_DRAIN = 228840,
    SPELL_VOLATILE_ENERGY_FILTER = 234416,
    SPELL_VOLATILE_ENERGY = 227267,
    SPELL_POWER_DISCHARGE_FILTER = 227278,
    SPELL_EVOCATION = 227254,
    SPELL_OVERLOAD = 227257,

    //Volatile Energy
    SPELL_VOLATILE_ENERGY_PASSIVE = 227268,
    SPELL_ARC_LIGHTNING = 227270,
    SPELL_STATIC_CHARGE = 228735,
};

enum eEvents
{
    EVENT_SUM_VOLATILE_ENERGY = 1,
    EVENT_POWER_DISCHARGE = 2,
    EVENT_MANA_CHECK = 3,
    EVENT_1,
};

void AddSC_boss_curator_new()
{
   
}
