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

#include "neltharions_lair.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_STANCE_EMOTE = 1,
    SAY_DEATH = 2,
};

enum Spells
{
    SPELL_SUNDER = 198496,
    SPELL_SUNDER_CALL = 198823, //Conversation
    SPELL_STRIKE_MOUNTAIN = 198428,
    SPELL_STRIKE_MOUNTAIN_2 = 216290,
    SPELL_STRIKE_MOUNTAIN_AT = 216292,
    SPELL_MOUNTAIN_CALL = 198825, //Conversation
    SPELL_BELLOW_DEEPS_1 = 193375,
    SPELL_BELLOW_DEEPS_2 = 193376,
    SPELL_BELLOW_DEEPS_CALL = 198824,
    //SPELL_CALL                    = 198826, //Conversation
    SPELL_STANCE_MOUNTAIN_JUMP = 198509,
    SPELL_STANCE_MOUNTAIN_SUM_1 = 198564,
    SPELL_STANCE_MOUNTAIN_SUM_2 = 198565,
    SPELL_STANCE_MOUNTAIN_SUM_3 = 216249, //Heroic+
    SPELL_STANCE_MOUNTAIN_SUM_4 = 216250, //Heroic+
    SPELL_STANCE_MOUNTAIN_MORPH = 198510,
    SPELL_STANCE_MOUNTAIN_TICK = 198617,
    SPELL_STANCE_MOUNTAIN_FILTER = 198619,
    SPELL_STANCE_MOUNTAIN_TELEPORT = 198630,
    SPELL_FALLING_DEBRIS_ULAROGG = 198719, //boss
    SPELL_STANCE_MOUNTAIN_END = 198631,

    SPELL_FALLING_DEBRIS = 193267, //npc 98081
    SPELL_FALLING_DEBRIS_2 = 198717, //npc 100818
    SPELL_STANCE_MOUNTAIN_MOVE = 198616,
};

enum eEvents
{
    EVENT_SUNDER = 1,
    EVENT_STRIKE_MOUNTAIN = 2,
    EVENT_BELLOW_DEEPS_1 = 3,
    EVENT_BELLOW_DEEPS_2 = 4,
    EVENT_STANCE_MOUNTAIN_1 = 5,
    EVENT_STANCE_MOUNTAIN_2 = 6,
    EVENT_STANCE_MOUNTAIN_3 = 7,
    EVENT_STANCE_MOUNTAIN_4 = 8,

    EVENT_1,
    EVENT_2,
    EVENT_3,

    ACTION_1,
};

void AddSC_boss_ularogg_cragshaper()
{
    
}
