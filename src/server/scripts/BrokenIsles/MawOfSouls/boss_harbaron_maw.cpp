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

#include "maw_of_souls.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_INTRO = 0,
    SAY_AGGRO = 1,
    SAY_SUMMON = 2,
    SAY_FRAGMENT = 3,
    SAY_EMOTE_FRAGMENT = 4,
    SAY_DEATH = 5,
};

enum Spells
{
    SPELL_COSMIC_SCYTHE = 205330,
    SPELL_COSMIC_SCYTHE_VIS = 198580,
    SPELL_COSMIC_SCYTHE_VIS_2 = 194667,
    SPELL_COSMIC_SCYTHE_DMG = 194218,
    SPELL_SUM_SHACKLED_SERVITOR = 194231,
    SPELL_FRAGMENT = 194325,

    //Heroic
    SPELL_NETHER_RIP_AURA = 194668,

    //Summons
    SPELL_SHACKLED_SERVITOR = 194259,
    SPELL_VOID_SNAP = 194266,
};

enum eEvents
{
    EVENT_COSMIC_SCYTHE = 1,
    EVENT_SUM_SHACKLED_SERVITOR = 2,
    EVENT_FRAGMENT = 3,
    EVENT_NETHER_RIP = 4,
    EVENT_1,
    EVENT_2,
};

enum eMisc
{
    DATA_ACHIEVEMENT = 0
};

enum Actions
{
    ACTION_1 = 1,
    ACTION_2,
};

void AddSC_boss_harbaron_maw()
{
    
}
