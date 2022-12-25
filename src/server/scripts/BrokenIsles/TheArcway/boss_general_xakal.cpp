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
#include "the_arcway.h"

enum Says
{
    SAY_AGGRO = 1,
    SAY_FEL = 2,
    SAY_SUM = 3,
    SAY_WICKED = 4,
    SAY_WICKED_TEXT = 5,
    SAY_DEATH = 6,
};

enum Spells
{
    SPELL_FEL_FISSURE = 197776,
    SPELL_FEL_FISSURE_SUM = 197765,
    SPELL_FEL_FISSURE_AT = 197542,
    SPELL_FEL_FISSURE_GO = 197573,
    SPELL_SHADOW_SLASH = 212028,
    SPELL_SHADOW_SLASH_AT = 212030,
    SPELL_WICKED_SLAM = 197810,
    SPELL_WAKE_OF_SHADOW = 220441,

    SPELL_BOMBARDMENT_AURA = 197786,
    SPELL_BOMBARDMENT_DMG = 197787,
    SPELL_THIRST_FOR_BLOOD = 220533,
};

enum eEvents
{
    EVENT_FEL_FISSURE = 1,
    EVENT_SHADOW_SLASH = 2,
    EVENT_WICKED_SLAM = 3,
    EVENT_SUM_FELBAT = 4,
    EVENT_1,
    EVENT_2,
};

void AddSC_boss_general_xakal()
{
    
}
