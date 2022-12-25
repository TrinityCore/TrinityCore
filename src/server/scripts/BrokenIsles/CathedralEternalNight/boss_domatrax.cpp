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

#include "cathedral_of_eternal_night.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "AreaTriggerTemplate.h"

enum Says
{
    SAY_INTRO = 0,
    SAY_AGGRO = 1,
    SAY_WAVE = 2,
    SAY_WAVE_TWO = 3,
    SAY_CHAOTIC_ENERGY = 4,
    SAY_CHAOTIC_ENERGY_1 = 5,
    SAY_DEATH = 6,
};

enum Spells
{
    SPELL_WAVE_ONE = 235822,
    SPELL_WAVE_TWO = 235862,

    SPELL_FELSOUL_CLEAVE = 236543, // 18
    SPELL_CHAOTIC_ENERGY = 239339, // (visual only ?)
    SPELL_CHAOTIC_ENERGY_DMG = 234107, // 

    SPELL_ENRAGE = 243157, // 25%

    // egida
    SPELL_EGIDA_DISPLAY_BAR = 236421,
    SPELL_EGIDA_AT = 239350,
    SPELL_EGIDA_AT_BUFF = 238410,
    SPELL_EGIDA_OUTRO = 239352,

    // portals (118834)
    SPELL_PORTAL_PERIODIC_ONE = 235827,  // heroic - imps,
    SPELL_PORTAL_PERIODIC_TWO = 235881,  // heroic - guards, mythic - shivarras
    SPELL_PORTAL_MYTHIC_ADD = 241622,

    // other
    SPELL_VISUAL_SPAWN = 211762,
    SPELL_INTRO = 241001,
    SPELL_OUTRO = 241382,
};

enum eEvents
{
    EVENT_FELSOUL_CLEAVE = 1,
    EVENT_CHAOTIC_ENERGY,
    EVENT_WAVE_ONE,
    EVENT_WAVE_TWO,
    EVENT_ENRAGE
};

Position const portals_position[4]
{
    {-519.67f, 2548.22f, 533.94f, 3.94f},
    {-522.056f, 2504.01f, 533.94f, 2.24f},
    {-564.17f, 2503.62f, 533.94f, 0.77f},
    {-561.85f, 2549.77f, 533.94f, 5.45f}
};

void AddSC_boss_domatrax()
{
    
}
