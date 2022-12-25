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
#include "Group.h"

enum eSpells
{
    SPELL_CINDER_BREATH = 228785,
    SPELL_TAIL_SWIPE = 228786,
    SPELL_CHARRED_GROUND_AT = 228806,
    SPELL_CHARRED_GROUND_TICK = 228863,
    SPELL_BURNING_BONES = 228829,
    SPELL_IGNITE_SOUL = 228796,
    SPELL_REVERBERATING_SHADOWS = 229307,

    SPELL_INFERNAL_POWER = 228792,
    SPELL_CONCENTRATED_POWER = 228790,

    SPELL_RAIN_OF_BONES = 228839,

    SPELL_BELLOWING_ROAR = 228837,
};

enum eEvents
{
    EVENT_CINDER_BREATH = 1,
    EVENT_IGNITE_SOUL = 2,
    EVENT_REVERBERATING_SHADOWS = 3,
    EVENT_CHARRED_GROUND = 4,
    EVENT_BURNING = 5,
    EVENT_TAIL = 6,
    EVENT_POWER_1 = 7,
    EVENT_POWER = 8,
    EVENT_ROAR = 9,

};

enum eText
{
    SAY_AGGRO = 2,
    SAY_SOUL = 3,
    SAY_SOUL_1 = 4,
    SAY_FLY = 5,
    SAY_GROUND = 6,
    SAY_ROAR = 7,
    SAY_BURNING = 8,
    SAY_DEATH = 9
};

void AddSC_boss_nightbane_new()
{
    
};
