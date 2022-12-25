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

#include "GameObject.h"
#include "PhasingHandler.h"
#include "Log.h"

enum StepID
{
    STEP_0 = 2175,
    STEP_1 = 2176,
    STEP_2 = 2177,
    STEP_3 = 2178,
    STEP_4 = 2181,
    STEP_5 = 2179,
};

enum
{
    NPC_KATHRA_NATIR_102785 = 102785,
    NPC_MERYL_FELSTORM_102850 = 102850,
    NPC_SIPHONING_RIFT_102787 = 102787,
    NPC_FORGE_OF_THE_GUARDIAN_447175 = 447175,
    NPC_ALODI = 102846,
    PLAYER_GUID = 0,
    TALK_INTRO = 0,
    EVENT_INTRO = 1,
    EVENT_ATTACK_1 = 2,
    EVENT_ATTACK_2 = 3,
    EVENT_PART2 = 4,
    EVENT_PART3 = 5,
    EVENT_PART4 = 6,
    EVENT_MOVE_TO = 7,
    EVENT_MOVE_TO_POSITION = 8,

    EVENT_FORGE_OF_THE_GUARDIAN_1 = 1,
    EVENT_FORGE_OF_THE_GUARDIAN_2 = 2,

    SPELL_CONVERSATION_KATHRA_FIGHT1 = 205450,
    SPELL_CONVERSATION_KATHRA_FIGHT2 = 205451,
    SPELL_CONVERSATION_KATHRA_FIGHT3 = 205452,
    SPELL_CONVERSATION_KATHRA_FIGHT4 = 205453,
    
    SPELL_CONVERSATION_KATHRA_FIGHT5 = 205454,
    SPELL_CONVERSATION_KATHRA_FIGHT6 = 203444,
    SPELL_CONVERSATION_KATHRA_FIGHT7 = 205455,

    SPELL_CONVERSATION_MERYL_1 = 203265,
    SPELL_CONVERSATION_PART_3 = 203422,

    SPELL_MARK_OF_THE_GUARDIAN = 203363,

    SPELL_ATTACK_KATHRA_DRAIN_LIFE = 207639,
    SPELL_ATTACK_MERYL_1 = 227382,
    SPELL_ATTACK_MERYL_2 = 211581,

    SPELL_ATTACK_MERYL_3 = 211589,
    GO_PRISON_SEAL = 105772,
};

void AddSC_scenario_the_violet_hold()
{
    
}
