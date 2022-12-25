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

enum Spells
{
    SPELL_MANA_DEVOURER_ENERGIZE = 227451,
    SPELL_ENERGIZE = 232066,
    SPELL_ARCANE_BOMB = 227618,
    SPELL_ENERGY_VOID = 227523,
    SPELL_ENERGY_VOID_MANA_DRAIN = 227528,
    SPELL_UNSTABLE_MANA = 227502,
    SPELL_ENGULFING_POWER = 228577,
    SPELL_ENERGY_DISCHARGE = 227457,
    SPELL_COALESCE_POWER = 227297,
    SPELL_LOOSE_MANA = 228066,
    SPELL_DECIMATING_ESSENCE = 227507,

    SPELL_PLR_TELEPORT = 231500,
};

enum eEvents
{
    EVENT_ARCANE_BOMB = 1,
    EVENT_ENERGY_VOID = 2,
    EVENT_ENERGY_DISCHARGE = 3,
    EVENT_COALESCE_POWER = 4,
};

void AddSC_boss_mana_devourer()
{
    
}
