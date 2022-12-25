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

#include "black_rook_hold.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_SCYTHE = 1,
    SAY_SOUL = 2,
    SAY_REAP = 3
};

enum Spells
{
    SPELL_SWIRLING_SCYTHE = 195254,
    SPELL_SOUL_ECHOES = 194966,
    SPELL_REAP_SOUL = 194956,

    //Heroic
    SPELL_CALL_SOULS = 196078,
    SPELL_CALL_SOULS_AT = 196925,
    SPELL_SOUL_BURST = 196587,
    SPELL_SOULGORGE = 196930,

    //Trash
    SPELL_SOUL_ECHOES_CLONE_PLR = 194981,
    SPELL_SOUL_ECHOES_DMG = 194960,

    SPELL_SUMMON_MINIBOSS_A = 196619,
    SPELL_SUMMON_MINIBOSS_B = 196620,
    SPELL_SUMMON_MINIBOSS_C = 196646,
    SPELL_SUMMON_CONVERSATION = 197075,
};

enum eEvents
{
    EVENT_SWIRLING_SCYTHE = 1,
    EVENT_SOUL_ECHOES = 2,
    EVENT_REAP_SOUL = 3,
    EVENT_MOVE_CENTR_POS = 4,
    EVENT_CALL_SOULS = 5,
    EVENT_CHECK_SOULS = 6,
    EVENT_REMOVE_SOULS = 7,

    ACHIEVEMENT,
};

enum eAnim //SMSG_PLAY_ONE_SHOT_ANIM_KIT
{
    STALKER_ANIM_1 = 9038,
    STALKER_ANIM_2 = 9039,
    STALKER_ANIM_3 = 9176
};

uint32 AnimRand[3] =
{
    STALKER_ANIM_1,
    STALKER_ANIM_2,
    STALKER_ANIM_3
};

enum Misc
{
    ACTION_1 = 1,
    EVENT_1,
    EVENT_2,
    EVENT_3,
};

Position const centrPos = { 3251.35f, 7582.79f, 12.75f };

Position const soulsPos[7] =
{
    {3288.37f, 7593.30f, 14.10f, 3.45f},
    {3259.17f, 7620.32f, 14.10f, 4.53f},
    {3239.09f, 7618.44f, 14.10f, 5.05f},
    {3213.97f, 7587.99f, 14.10f, 6.12f},
    {3215.85f, 7567.98f, 14.10f, 0.36f},
    {3245.75f, 7541.42f, 14.10f, 1.41f},
    {3265.50f, 7543.86f, 14.10f, 1.90f}
};

void AddSC_boss_amalgam_of_souls()
{
    
}
