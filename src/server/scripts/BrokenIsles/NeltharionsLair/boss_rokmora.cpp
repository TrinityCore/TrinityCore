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
#include "Unit.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_RAZOR = 1,
    SAY_DEATH = 2,
};

enum Spells
{
    SPELL_GAIN_ENERGY = 193245,
    SPELL_BRITTLE = 187714,
    SPELL_INTRO_ULAROGG = 209390, //Boss 01 Intro Ularogg Cast
    SPELL_INTRO_EMERGE = 209394, //Boss 01 Intro Emerge

    SPELL_SHATTER_START_CALL_1 = 198122, //Conversation Shatter
    SPELL_SHATTER_END_CALL_1 = 198135, //Conversation Shatter
    SPELL_SHATTER_END_CALL_2 = 198136, //Conversation Shatter
    SPELL_SHATTER = 188114,
    SPELL_SHATTER_KILL = 200247,
    SPELL_RAZOR_SHARDS_CALL = 198125, //Conversation Razor Shards
    SPELL_RAZOR_SHARDS = 188169,
    SPELL_RAZOR_SHARDS_VISUAL_1 = 188207,
    SPELL_RAZOR_SHARDS_VISUAL_2 = 197920,
    SPELL_RAZOR_SHARDS_FILTER = 209718,

    //Heroic
    SPELL_CRYSTALLINE_GROUND = 198024,
    SPELL_CRYSTALLINE_GROUND_DMG = 198028,
    SPELL_RUPTURING_SKITTER = 215929,

    SPELL_CHOKING_DUST_AT = 192799,
};

enum eEvents
{
    EVENT_RAZOR_SHARDS = 1,
    EVENT_CRYSTALLINE_GROUND = 2,
    EVENT_DEAD_CONVERSATION = 3,
    EVENT_2,
    EVENT_1,
    EVENT_3,
};

void AddSC_boss_rokmora()
{
    
}
