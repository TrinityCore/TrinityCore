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

#include "thenighthold.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

Position const anomalySumPos[12] =
{
    {236.42f, 3108.52f, -236.93f, 0.66f}, //108786
    {277.72f, 3087.88f, -236.93f, 1.58f}, //108786
    {315.29f, 3163.98f, -236.95f, 3.68f}, //108786
    {232.46f, 3156.74f, -236.95f, 5.98f}, //108786
    {228.15f, 3132.27f, -236.95f, 0.19f}, //108786
    {248.43f, 3175.77f, -236.95f, 5.46f}, //108786
    {254.49f, 3093.32f, -236.93f, 1.12f}, //108786
    {271.78f, 3184.27f, -236.95f, 4.89f}, //108786
    {296.25f, 3179.95f, -236.95f, 4.29f}, //108786
    {303.50f, 3097.13f, -236.95f, 2.05f}, //108786
    {319.47f, 3116.16f, -236.95f, 2.55f}, //108786
    {323.78f, 3140.63f, -236.93f, 3.09f}  //108786
};

enum Says
{
    SAY_AGGRO = 0,
    SAY_NORMAL_TIME = 1,
    SAY_ADDITIONAL = 2,
    SAY_SUM_ADD = 3,

    SAY_TEMP_ORB = 4,
    SAY_POWER = 5,
    SAY_DEATH = 6,
    SAY_TIME_SLOW = 7,
    SAY_TIME_FAST = 9,
};

enum Spells
{
    SPELL_PASSAGE_OF_TIME = 205653,

    SPELL_SPEED_SLOW = 207011,
    SPELL_SPEED_NORMAL = 207012,
    SPELL_SPEED_FAST = 207013,
    SPELL_BURST_OF_TIME = 219984,
    SPELL_BURST_OF_TIME_NORMAL = 206613,
    SPELL_BURST_OF_TIME_SLOW = 214049,
    SPELL_BURST_OF_TIME_FAST = 214050,
    SPELL_POWER_OVERWHELMING = 211927,
    SPELL_POWER_OVERWHELMING_MOD = 219823,
    SPELL_CHRONOMETRIC_PARTICLES = 206607,
    SPELL_CHRONOMETRIC_OVERLOAD = 207491,
    SPELL_TIME_RELEASE_FILTER = 206610,
    SPELL_TIME_RELEASE_ABSORB = 206609,
    SPELL_TIME_RELEASE_DMG = 206608,
    SPELL_TIME_RELEASE_GREEN = 219964,
    SPELL_TIME_RELEASE_YELLOW = 219965,
    SPELL_TIME_RELEASE_RED = 219966,
    SPELL_TIME_BOMB_FILTER = 206618,
    SPELL_TIME_BOMB_DMG = 206615,
    SPELL_SUM_SLOW_ADD_FILTER = 206700,
    SPELL_SUM_SLOW_ADD = 206698,
    SPELL_TEMPORAL_ORB = 219815,
    SPELL_TEMPORAL_ORB_AT = 212874,
    SPELL_TEMPORAL_ORB_AT_2 = 227217,
    SPELL_TEMPORAL_SMASH_MOD = 222283,

    SPELL_WARP_NIGHTWELL_BIG = 207228,
    SPELL_WARP_NIGHTWELL_SMALL = 228335,
    SPELL_CHRONOMATE = 219808,
    SPELL_TEMPORAL_RIFT = 212072,
    SPELL_SUM_TEMPORAL_RIFT = 212076,
    SPELL_TEMPORAL_RIFT_VIS = 212090,
};

enum eEvents
{
    EVENT_BURST_OF_TIME = 1,
    EVENT_CHRONOMETRIC_PARTICLES = 2,
    EVENT_TIME_RELEASE = 3,
    EVENT_TIME_BOMB = 4,
    EVENT_SUM_SLOW_ADD = 5,
    EVENT_TEMPORAL_ORB = 6,
    EVENT_POWER_OVERWHELMING = 7,
    //Mythic
    EVENT_CHANGE_SPEED = 8
};

enum Misc
{
    EVENT_1 = 1,
    EVENT_2,
    EVENT_3,
};

void AddSC_boss_chronomatic_anomaly()
{
    
}
