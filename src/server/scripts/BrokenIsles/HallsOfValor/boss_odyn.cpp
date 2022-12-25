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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "halls_of_valor.h"

enum Says
{
    SAY_FIRST = 0,
    SAY_INTRO_1 = 2,
    SAY_INTRO_2 = 3,
    SAY_INTRO_3 = 4,
    SAY_RADIANT = 5,
    SAY_SPEARS = 6,
    SAY_RUNIC = 7,
    SAY_RUNIC_1 = 8,
    SAY_DEATH = 9,
};

enum Spells
{
    SPELL_HONOR_BOUND = 198187, //? 01:44
    SPELL_SPEAR_OF_LIGHT = 198072,
    SPELL_RADIANT_TEMPEST = 201006,
    SPELL_SHATTER_SPEARS = 198077,
    SPELL_GLOWING_FRAGMENT = 198078,
    SPELL_UNWORTHY = 198190,
    SPELL_RUNIC_BRAND = 197961,

    SPELL_RUNIC_BRAND_PURE = 197963,
    SPELL_RUNIC_BRAND_RED = 197964,
    SPELL_RUNIC_BRAND_YELLOW = 197965,
    SPELL_RUNIC_BRAND_BLUE = 197966,
    SPELL_RUNIC_BRAND_GREEN = 197967,

    SPELL_RUNIC_BRAND_PURE_AT = 197968,
    SPELL_RUNIC_BRAND_RED_AT = 197971,
    SPELL_RUNIC_BRAND_YELLOW_AT = 197972,
    SPELL_RUNIC_BRAND_BLUE_AT = 197975,
    SPELL_RUNIC_BRAND_GREEN_AT = 197977,

    //Heroic
    SPELL_SUMMON_STORMFORGED = 201209,
    SPELL_SURGE = 198750,
    SPELL_CONDUIT = 199787,
};

enum eEvents
{
    EVENT_SKOVALD_DONE_1 = 1,
    EVENT_SKOVALD_DONE_2 = 2,
    EVENT_SPEAR_OF_LIGHT = 3,
    EVENT_RADIANT_TEMPEST = 4,
    EVENT_SHATTER_SPEARS = 5,
    EVENT_RUNIC_BRAND = 6,
    EVENT_SUMMON_STORMFORGED = 7,

    EVENT_1,
    EVENT_2,
};

enum Misc
{
    DATA_ACHIEVEMENT,
};

uint32 SpellsRunicColour[5] =
{
    SPELL_RUNIC_BRAND_PURE,
    SPELL_RUNIC_BRAND_RED,
    SPELL_RUNIC_BRAND_YELLOW,
    SPELL_RUNIC_BRAND_BLUE,
    SPELL_RUNIC_BRAND_GREEN
};

uint32 SpellsRunicAt[5] =
{
    SPELL_RUNIC_BRAND_PURE_AT,
    SPELL_RUNIC_BRAND_RED_AT,
    SPELL_RUNIC_BRAND_YELLOW_AT,
    SPELL_RUNIC_BRAND_BLUE_AT,
    SPELL_RUNIC_BRAND_GREEN_AT
};

Position const centrPos = { 2429.13f, 528.55f, 748.99f };

void AddSC_boss_odyn_hov()
{
    
}
