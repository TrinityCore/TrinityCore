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

#include "emerald_nightmare.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_CALL = 1,
    SAY_DEATH = 3,
};

enum Spells
{
    SPELL_EMPTY_ENERGY = 205283,
    SPELL_ENERGIZE_UP = 205284,
    SPELL_REMOVE_MARK_TAERAR = 224627,
    SPELL_REMOVE_MARK_LETHON = 224626,
    SPELL_REMOVE_MARK_EMERISS = 224625,
    SPELL_NIGHTMARE_BOND = 203966,
    SPELL_CORRUPTED_BREATH = 203028,
    SPELL_TAIL_LASH = 204119,
    SPELL_ENERGIZE_DRAGONS = 205281,
    SPELL_SLUMBERING_NIGHTMARE = 203110,

    //Ysondre - 102679
    SPELL_MARK_OF_YSONDRE = 203083,
    SPELL_ENERGIZE_YSONDRE = 205282,
    SPELL_NIGHTMARE_BLAST = 203147,
    SPELL_CALL_DEFILED_SPIRIT = 207573,

    //Taerar - 102681
    SPELL_MARK_OF_TAERAR = 203085,
    SPELL_SHADES_OF_TAERAR = 204100,
    SPELL_SEEPING_FOG = 205331,
    SPELL_BELLOWING_ROAR_AURA = 205172,
    SPELL_BELLOWING_ROAR = 204078,

    //Lethon - 102682
    SPELL_MARK_OF_LETHON = 203086,
    SPELL_SIPHON_SPIRIT = 203888,
    SPELL_SIPHON_SPIRIT_SUM = 203837,
    SPELL_DARK_OFFERING_LETHON = 203896,
    SPELL_DARK_OFFERING_YSONDRE = 203897,
    SPELL_GLOOM_AURA = 206758,
    SPELL_SHADOW_BURST = 204030,

    //Emeriss - 102683
    SPELL_MARK_OF_EMERISS = 203084,
    SPELL_NIGHTMARE_ENERGY = 224200,
    SPELL_GROUNDED = 204719,
    SPELL_VOLATILE_INFECTION = 203787,
    SPELL_ESSENCE_OF_CORRUPTION = 205298,

    //Nightmare Bloom - 102804
    SPELL_NIGHTMARE_BLOOM_VISUAL = 203672,
    SPELL_NIGHTMARE_BLOOM_DUMMY = 205945,
    SPELL_NIGHTMARE_BLOOM_DUMMY_2 = 207681,
    SPELL_NIGHTMARE_BLOOM_DUMMY_3 = 220938,
    SPELL_NIGHTMARE_BLOOM_DUMMY_4 = 211497,
    SPELL_NIGHTMARE_BLOOM_AT = 203687,
    SPELL_NIGHTMARE_BLOOM_PERIODIC = 205278,

    //Defiled Druid Spirit - 103080
    SPELL_DEFILED_SPIRIT_ROOT = 203768,
    SPELL_DEFILED_ERUPTION = 203771,

    //Essence of Corruption - 103691
    SPELL_CORRUPTION = 205300,

    //Shade of Taerar - 103145
    SPELL_NIGHTMARE_VISAGE = 204084,
    SPELL_CORRUPTED_BREATH_2 = 204767,
    SPELL_TAIL_LASH_2 = 204768,

    //Dread Horror - 103044
    SPELL_WASTING_DREAD_AT = 204729,
    SPELL_UNRELENTING = 221419,

    //Corrupted Mushroom
    SPELL_CORRUPTED_BURST_4 = 203817,
    SPELL_CORRUPTED_BURST_7 = 203827,
    SPELL_CORRUPTED_BURST_10 = 203828,
};

enum eEvents
{
    EVENT_CORRUPTED_BREATH = 1,

    //Ysondre
    EVENT_SWITCH_DRAGONS = 2,
    EVENT_NIGHTMARE_BLAST = 3,
    EVENT_CALL_DEFILED_SPIRIT = 4,

    //Taerar
    EVENT_SHADES_OF_TAERAR = 5,
    EVENT_SEEPING_FOG = 6,

    //Emeriss
    EVENT_VOLATILE_INFECTION = 7,
    EVENT_ESSENCE_OF_CORRUPTION = 8,

    //Lethon
    EVENT_SIPHON_SPIRIT = 9,
    EVENT_SHADOW_BURST = 10,

    //Mythic
    EVENT_TAIL_LASH = 11,
};

Position const dragonPos[5] =
{
    {617.51f, -12807.0f,  4.84f, 3.39f},
    {674.78f, -12875.5f, 42.21f, 2.91f},
    {623.48f, -12845.71f, 4.13f, 2.47f},
    //Mythic
    {681.84f, -12869.25f, 43.62f, 2.74f},
    {662.45f, -12893.78f, 43.62f, 2.31f}
};

enum Actions
{
    ACTION_1 = 1,
    ACTION_2,
    ACTION_3,
    ACTION_4,
    ACTION_5,

    EVENT_1,
    EVENT_2,
    EVENT_4,
    EVENT_3,
};

void AddSC_boss_dragons_of_nightmare()
{

}
