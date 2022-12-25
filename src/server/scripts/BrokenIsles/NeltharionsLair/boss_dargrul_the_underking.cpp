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
#include "GameObject.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_EMOTE = 1,
    SAY_DEATH = 2,
};

enum Spells
{
    SPELL_GAIN_ENERGY = 201444,
    SPELL_CONVERSATION_01 = 201665, //SPELL_MAGMA_SCULPTOR
    SPELL_CONVERSATION_02 = 201666, //SPELL_MAGMA_SCULPTOR
    SPELL_MAGMA_SCULPTOR = 200637,
    SPELL_LANDSLIDE = 200700,
    SPELL_LANDSLIDE_MISSILE = 200722,
    SPELL_CRYSTAL_WALL = 200551,
    SPELL_MAGMA_WAVE = 200404,
    SPELL_MAGMA_WAVE_AT = 200418,
    SPELL_MAGMA_WAVE_DMG_AOE = 217090,
    SPELL_MOLTEN_CRASH = 200732,

    //Heroic
    SPELL_MAGMA_BREAKER_DARGRUL = 216368,
    SPELL_LAVA_GEYSER_SUM = 216373,
    SPELL_LAVA_GEYSER_AT = 216385,
    SPELL_FLAME_GOUT = 216374,

    SPELL_CONVERSATION_03 = 201663,
    SPELL_CONVERSATION_04 = 201659,
    SPELL_CONVERSATION_05 = 201661, //SPELL_MAGMA_WAVE

    SPELL_SUM_PILLAR_CREATION = 213589,

    //Trash
    SPELL_FIXATE_PLR = 200154,
    SPELL_COLLISION_AT = 188197,
    SPELL_MAGMA_BREAKER = 209926,
    SPELL_MAGMA_BREAKER_AURA = 209920,
    SPELL_RISING_INFERNO = 216369,

    SPELL_CRYSTAL_BLOCKER_AT = 200367,
    SPELL_CRYSTAL_WALL_SUM_GO = 209964, //GO DOOR
};

enum eEvents
{
    EVENT_MAGMA_SCULPTOR = 1,
    EVENT_LANDSLIDE = 2,
    EVENT_CRYSTAL_WALL = 3,
    EVENT_MOLTEN_CRASH = 4,

    //Heroic
    EVENT_LAVA_GEYSER = 5,

    EVENT_3,
    EVENT_2,
    EVENT_1,
};

void AddSC_boss_dargrul_the_underking()
{
   
}
