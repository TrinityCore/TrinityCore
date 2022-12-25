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
#include "seat_of_triumvirate.h"

enum Spells
{
    SPELL_VOID_CONTAINMENT = 246922,
    SPELL_VOID_PHASED = 246913,

    SPELL_NULL_PALM = 246134,
    SPELL_NULL_PALM_MISSILE = 246135,
    SPELL_NULL_PALM_DAMAGE = 246136,

    SPELL_DECIMATE = 244579,

    SPELL_COALESCED_VOID = 244602,
    SPELL_DARK_EXPULSION = 244599,
    SPELL_UMBRAL_EJECTION = 244731,
    SPELL_VOID_SLUDGE = 244588,
    SPELL_VOID_INFUSION = 244300,

    SPELL_UMBRA_SHIFT = 244433,
    SPELL_FIXATE = 244657,
    SPELL_MADDENED_FRENZY = 247038,

    SPELL_RELEASE_VOID_ENERGY = 244618,
    SPELL_VOID_TEAR = 244621,

    SPELL_PHYSICAL_REALM_COSMETIC = 244087,
};

enum Npcs
{
    NPC_COALESCED_VOID = 122716,
    NPC_DARK_ABERRATION = 122482
};

void AddSC_boss_zuraal_the_ascended()
{
    
}
