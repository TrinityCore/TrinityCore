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
#include "shadopan_monastery.h"

enum eSpells
{
    // Gu
    SPELL_KILL_GUARDIANS = 114927,

    SPELL_INVOKE_LIGHTNING = 106984,
    SPELL_CHARGING_SOUL = 110945,

    SPELL_OVERCHARGED_SOUL = 110852,
    SPELL_OVERCHARGED_SOUL_DAMAGE = 111129,

    // Azure Serpent
    SPELL_LIGHTNING_SHIELD = 123496,
    SPELL_STATIC_FIELD = 106923,

    SPELL_LIGHTNING_BREATH = 102573,
    SPELL_MAGNETIC_SHROUD = 107140, // TODO
};

enum eEvents
{
    // Gu
    EVENT_INVOKE_LIGHTNING = 1,
    EVENT_OVERCHARGED_SOUL = 2,

    // Azure Serpent
    EVENT_STATIC_FIELD = 3,
    EVENT_LIGHTNING_BREATH = 4,
    EVENT_MAGNETIC_SHROUD = 5
};

enum eActions
{
    // Gu
    ACTION_INTRO = 1,
    ACTION_GU_P_3 = 2,

    // Azure Serpent
    ACTION_AZURE_SERPENT_P_1 = 3,
    ACTION_AZURE_SERPENT_P_2 = 4,
    ACTION_AZURE_SERPENT_RESET = 5
};

enum ePhases
{
    PHASE_ONE = 1,
    PHASE_TWO = 2,
    PHASE_THREE = 3
};

void AddSC_boss_gu_cloudstrike()
{
    
}
