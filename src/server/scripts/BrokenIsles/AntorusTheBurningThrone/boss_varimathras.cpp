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

#include "antorus.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_NECROTIC_EMBRACE = 1,
    SAY_DARK_FISSURE = 2,
    SAY_MARKED_PREY = 3,
    SAY_DEATH = 4
};

enum Spells
{
    SPELL_CHRISTMAS_VARIMATHRAS = 254076, //Winter Veil Holidays
    SPELL_INTRO_CONV = 250026,
    SPELL_DAILY_ESSENCE_VARIMATHRAS = 305314,

    SPELL_BERSERK = 26662,
    SPELL_ENERGY_GAIN = 244697,
    SPELL_CONTROL_AURA_AT = 243975,
    SPELL_TORMENT_OF_FLAMES_AT = 243967,
    SPELL_TORMENT_OF_FROST_AT = 243976,
    SPELL_TORMENT_OF_FEL_AT = 243979,
    SPELL_TORMENT_OF_SHADOWS_AT = 243974,
    SPELL_SHADOW_STRIKE = 243960,
    SPELL_MISERY = 243961,
    SPELL_ALONE_IN_DARKNESS_DMG = 243963,
    SPELL_ALONE_IN_DARKNESS_VISUAL = 244326,
    SPELL_DARK_FISSURE = 243999,
    SPELL_DARK_FISSURE_AT = 244003,
    SPELL_DARK_ERUPTION = 244006,
    SPELL_MARKED_PREY_FILTER = 244042,
    SPELL_MARKED_PREY_BETWEEN = 244068,
    SPELL_MARKED_PREY_VISUAL = 244522,
    SPELL_SHADOW_HUNTER_DMG = 244070,
    SPELL_SHADOW_HUNTER_KNOCK = 252105,

    //Heroic+
    SPELL_NECROTIC_EMBRACE_FILTER = 244093,
    SPELL_NECROTIC_EMBRACE_DOT = 244094,
    SPELL_NECROTIC_EMBRACE_PLR_FILTER = 244097,

    //Mythic
    SPELL_ECHOES_OF_DOOM_CHANNEL = 248732,
    SPELL_ECHOES_OF_DOOM_AT = 248725,
};

enum Events
{
    EVENT_DARK_FISSURE = 1,
    EVENT_MARKED_PREY = 2,
    EVENT_NECROTIC_EMBRACE = 3,
};

void AddSC_boss_varimathras()
{
    
}
