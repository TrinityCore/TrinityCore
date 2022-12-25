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
    SAY_AGGRO = 0,
    SAY_DEATH = 18,
};

enum Spells
{
    SPELL_SHADOW_CRASH = 201920,
    SPELL_SHADOW_CRASH_AT = 201120,
    SPELL_DOOM = 201148,
    SPELL_HYSTERIA = 201146,
    SPELL_ETERNAL_DARKNESS_SUM = 201153,

    //Summons
    SPELL_ETERNAL_DARKNESS_DMG = 201172,

    //Heroic
    SPELL_COLLAPSING_SHADOWS_AT = 201256, //201255 dmg
    SPELL_COLLAPSING_SHADOWS_MOD = 201287, //Mod force speed ?
};

enum eEvents
{
    EVENT_SHADOW_CRASH = 1,
    EVENT_DOOM = 2,
    EVENT_HYSTERIA = 3,
    EVENT_ETERNAL_DARKNESS = 4,
};

void AddSC_boss_mind_flayer_kaarhj()
{
    
}
