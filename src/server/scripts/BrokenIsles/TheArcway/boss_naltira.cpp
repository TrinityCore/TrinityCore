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

#include "the_arcway.h"

enum Spells
{
    //Intro
    SPELL_WEB_BEAM_BOSS = 209833,
    SPELL_WEB_BEAM_TRASH = 209834,

    SPELL_BLINK_STRIKES_VISUAL = 199864,
    SPELL_BLINK_STRIKES_SEARCH = 199809,
    SPELL_BLINK_STRIKES_TP = 199810,
    SPELL_BLINK_STRIKES_DMG = 199811,
    SPELL_NETHER_VENOM = 199956,
    SPELL_TANGLED_WEB = 200227,
    SPELL_TANGLED_WEB_JUMP = 200230,
    SPELL_TANGLED_WEB_DMG = 200284,
    SPELL_TANGLED_BEAM = 200237,

    //Trash
    SPELL_DEVOUR = 211543,
};

enum eEvents
{
    EVENT_BLINK_STRIKES_1 = 1,
    EVENT_BLINK_STRIKES_2 = 2,
    EVENT_NETHER_VENOM = 3,
    EVENT_TANGLED_WEB = 4,
    EVENT_SUM_MANAFANG = 5,
    EVENT_1,
};

Position const spiderPos[21] =
{
    {3163.41f, 4665.23f, 574.34f, 0.56f},
    {3178.14f, 4667.58f, 574.34f, 0.18f},
    {3182.06f, 4650.01f, 574.34f, 5.93f},
    {3169.97f, 4640.99f, 574.34f, 5.17f},
    {3150.47f, 4692.17f, 574.34f, 2.30f},
    {3141.19f, 4699.91f, 574.34f, 2.03f},
    {3156.49f, 4687.44f, 574.34f, 1.01f},
    {3128.86f, 4684.70f, 574.34f, 3.09f},
    {3163.68f, 4633.81f, 574.34f, 3.96f},
    {3156.48f, 4641.36f, 574.34f, 3.21f},
    {3132.53f, 4679.60f, 574.34f, 1.01f},
    {3154.51f, 4632.66f, 574.34f, 0.92f},
    {3125.42f, 4657.03f, 574.34f, 1.26f},
    {3145.54f, 4680.42f, 574.34f, 4.54f},
    {3120.70f, 4661.97f, 574.34f, 5.98f},
    {3120.99f, 4666.23f, 574.34f, 1.57f},
    {3125.56f, 4689.92f, 574.34f, 4.71f},
    {3132.43f, 4637.73f, 574.34f, 0.56f},
    {3124.91f, 4628.75f, 574.34f, 4.66f},
    {3105.72f, 4651.09f, 574.34f, 3.28f},
    {3120.08f, 4643.58f, 574.34f, 3.07f}
};

void AddSC_boss_naltira()
{
   
}
