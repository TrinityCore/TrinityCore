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
    SAY_HATEFUL_GAZE = 1,
    SAY_WARN_HATEFUL_GAZE = 2,
    SAY_HATEFUL_GAZE_CHARGE = 3,
    SAY_EARTHSHAKING_STOMP = 4,
    SAY_BRUTAL_HAYMAKER = 5,
    SAY_DEATH = 6,
};

enum Spells
{
    SPELL_ZERO_REGEN = 72242,
    SPELL_BRUTALITY_PROC = 198114,
    SPELL_EARTHSHAKING_STOMP = 198073,
    SPELL_BRUTAL_HAYMAKER = 198245,

    //Heroic
    SPELL_HATEFUL_GAZE = 198079,
    SPELL_HATEFUL_CHARGE = 198250,
    SPELL_HATEFUL_CHARGE_DMG = 198080,
    SPELL_HATEFUL_CHARGE_DEBUF = 224188,

    SPELL_FEL_VOMIT = 198446,
    SPELL_FEL_VOMIT_DMG = 198499,

    //Other
    SPELL_SIC_BATS = 203163,
};

enum eEvents
{
    EVENT_EARTHSHAKING_STOMP = 1,
    EVENT_FEL_ATTACK = 2,
    EVENT_HATEFUL_GAZE = 3,
};

Position const felPos[10] =
{
    {3377.12f, 7379.05f, 260.46f}, //100759
    {3405.04f, 7360.28f, 250.10f},
    {3410.22f, 7311.27f, 250.10f},
    {3392.56f, 7317.72f, 260.46f},
    {3379.99f, 7295.96f, 268.62f},
    {3388.76f, 7284.25f, 237.00f},
    {3257.77f, 7188.85f, 255.80f},
    {3352.13f, 7259.52f, 251.29f},
    {3206.34f, 7261.78f, 255.80f},
    {3267.14f, 7182.61f, 244.89f}
};

Position const centrPos = { 3269.27f, 7289.28f, 231.47f };

void AddSC_boss_smashspite_the_hateful()
{
   
}
