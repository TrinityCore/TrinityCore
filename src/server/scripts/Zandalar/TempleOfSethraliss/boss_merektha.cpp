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
#include "GameObject.h"
#include "GameObjectAI.h"
#include "temple_of_sethraliss.h"

enum Spells
{
    SPELL_NOXIOUS_BREATH = 272657,
    SPELL_NOXIOUS_BREATH_AT_TRIGGER = 263925, //at 12750
    SPELL_BLINDING_SAND = 263914,
    SPELL_DUST_CLOUD_DUMMY = 256359,
    SPELL_DUST_CLOUD_MISSILE = 256336, // npc 134390, spawn spell 267047

    SPELL_BURROW_KNOCKBACK = 264206,
    SPELL_BURROW_CREAT_AT = 264194, // at 12779
    SPELL_A_KNOT_OF_SNAKES = 263958,

    SPELL_CYTOTOXIN = 267027,
};

enum Events
{
    EVENT_NOXIOUS_BREATH = 1,
    EVENT_BURROW,
    EVENT_EMERGE,
    EVENT_BLINDING_SAND,
    EVENT_A_KNOT_OF_SNAKES,

    EVENT_CYTOTOXIN,
};

enum Timers
{
    TIMER_EMERGE = 30 * IN_MILLISECONDS,
    TIMER_NOXIOUS_BREATH = 15 * IN_MILLISECONDS,
    TIMER_BLIDING_SAND = 28 * IN_MILLISECONDS,
    TIMER_A_KNOT_OF_SNAKES = 35 * IN_MILLISECONDS,
    TIMER_CYTOTOXIN = 10 * IN_MILLISECONDS,
};

enum Creatures
{
    BOSS_MEREKTHA = 133384,
    NPC_SAND_CRUSTED_STRIKER_BFA = 134390,
    NPC_VENOMOUS_OPHIDIAN = 135562,
    NPC_A_KNOT_OF_SNAKES = 135029,
};

const Position centerPos = { 3549.29f, 3423.07f, 51.68f }; //55y

//toxic pool and dust cloud AT visual

void AddSC_boss_merektha()
{
    
}
