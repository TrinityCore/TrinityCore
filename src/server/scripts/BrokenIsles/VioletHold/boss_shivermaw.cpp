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

enum Says
{
    SAY_WARNING = 0,
};

enum Spells
{
    SPELL_FROST_BREATH = 201379,
    SPELL_RELENTLESS_STORM = 201672,
    SPELL_RELENTLESS_STORM_TRIG = 201848, //26 cast count
    SPELL_RELENTLESS_STORM_SEARCH = 201865, //Target search
    SPELL_RELENTLESS_STORM_DMG = 201852,
    SPELL_RELENTLESS_STORM_AT_1 = 201643,
    SPELL_RELENTLESS_STORM_AT_2 = 201652,
    SPELL_TAIL_SWEEP = 201354,
    SPELL_WING_BUFFET = 201355,
    SPELL_ICE_BOMB = 201960,
    SPELL_ICE_BOMB_DMG_AOE = 201961,
    SPELL_FROZEN = 202037,

    //Heroic+
    SPELL_FRIGID_WINDS = 202062,
};

enum eEvents
{
    EVENT_FROST_BREATH = 1,
    EVENT_RELENTLESS_STORM = 2,
    EVENT_TAIL_SWEEP = 3,
    EVENT_WING_BUFFET = 4,
    EVENT_FLY = 5,
    EVENT_ICE_BOMB = 6,
    EVENT_GROUND = 7,
    EVENT_FRIGID_WINDS = 8
};

void AddSC_boss_shivermaw()
{
  
}
