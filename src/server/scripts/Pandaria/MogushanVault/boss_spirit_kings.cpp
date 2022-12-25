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
#include "ScriptedCreature.h"
#include "mogu_shan_vault.h"

enum eSpells
{
    // Quiang
    SPELL_FLANKING_ORDERS = 117910, // Also when vanquished
    SPELL_MASSIVE_ATTACKS = 117921,
    SPELL_ANNIHILATE = 117948,
    SPELL_IMPERVIOUS_SHIELD = 117961, // Heroic

    // Subetai
    SPELL_PILLAGE_CHARGE = 118047, // Also when vanquished
    SPELL_PILLAGE = 118049,
    SPELL_VOLLEY_VISUAL = 118100,
    SPELL_VOLLEY_1 = 118094,
    SPELL_VOLLEY_2 = 118105,
    SPELL_VOLLEY_3 = 118106,
    SPELL_RAIN_OF_ARROWS = 118122,
    SPELL_PINNED_DOWN = 118145,
    SPELL_PINNED_DOWN_DOT = 118135,
    SPELL_PINNING_ARROW_VISUAL = 118141,
    SPELL_SLEIGHT_OF_HAND = 118162, // Heroic
    SPELL_ROBBED_BLIND = 118163, // Heroic

    // Zian
    SPELL_UNDYING_SHADOWS = 117506, // Also when vanquished
    SPELL_FIXATE = 118303,
    SPELL_UNDYING_SHADOW_DOT = 117514,
    SPELL_COALESCING_SHADOW_DOT = 117539,

    SPELL_SHADOW_BLAST = 117628,
    SPELL_CHARGED_SHADOWS = 117685,
    SPELL_SHIELD_OF_DARKNESS = 117697, // Heroic
    SPELL_DARKNESS = 117701, // Heroic

    // Meng
    SPELL_MADDENING_SHOUT = 117708, // Also when vanquished
    SPELL_CRAZED = 117737,
    SPELL_COWARDICE = 117756,
    SPELL_COWARDICE_DOT = 117829,
    SPELL_CRAZY_THOUGHT = 117833,
    SPELL_DELIRIOUS = 117837, // Heroic

    // Shared
    SPELL_INACTIVE = 118205,
    SPELL_INACTIVE_STUN = 118319,
    SPELL_KING_BERSERK = 120207,
    SPELL_ACTIVATION_VISUAL = 118212,
    SPELL_SPIRIT_KINGS_BONUS = 132191,

    // Flanking Mogu
    SPELL_GHOST_VISUAL = 117904,
    SPELL_TRIGGER_ATTACK = 117917
};

enum eEvents
{
    // Quiang
    EVENT_FLANKING_MOGU = 2,
    EVENT_MASSIVE_ATTACK = 3,
    EVENT_ANNIHILATE = 4,

    // Subetai
    EVENT_PILLAGE = 5,
    EVENT_VOLLEY_1 = 6,
    EVENT_VOLLEY_2 = 7,
    EVENT_VOLLEY_3 = 8,
    EVENT_RAIN_OF_ARROWS = 9,

    // Zian
    EVENT_UNDYING_SHADOWS = 10,
    EVENT_SHADOW_BLAST = 11,
    EVENT_CHARGED_SHADOWS = 12,

    // Meng
    EVENT_MADDENING_SHOUT = 13,
    EVENT_CRAZED = 14,
    EVENT_CRAZY_THOUGHT = 15,

    // Heroic
    EVENT_IMPERVIOUS_SHIELD = 16,
    EVENT_DELIRIOUS = 17,
    EVENT_SLEIGHT_OF_HAND = 18,
    EVENT_SHIELD_OF_DARKNESS = 19,

    EVENT_CHECK_SPIRITKINGS = 20
};

enum equipId
{
    EQUIP_QIANG_POLEARM = 86777,
    EQUIP_SUBETAI_SWORD = 80283,
    EQUIP_SUBETAI_BOW = 60790,
    EQUIP_ZIAN_STAFF = 76369,
    EQUIP_FLANKING_MOGU_SWORD = 68838,
    EQUIP_FLANKING_MOGU_SHIELD = 32375
};

enum qiangTalk
{
    QIANG_AGGRO = 0,
    QIANG_DEATH = 1,
    QIANG_INTRO = 2,
    QIANG_SLAY = 3,
    QIANG_SPELL = 4
};

enum subetaiTalk
{
    SUBETAI_AGGRO = 0,
    SUBETAI_DEATH = 1,
    SUBETAI_INTRO = 2,
    SUBETAI_SLAY = 3,
    SUBETAI_SPELL = 4
};

enum zianTalk
{
    ZIAN_AGGRO = 0,
    ZIAN_DEATH = 1,
    ZIAN_INTRO = 2,
    ZIAN_SLAY = 3,
    ZIAN_SPELL = 4
};

enum mengTalk
{
    MENG_AGGRO = 0,
    MENG_DEATH_CRAZED = 1,
    MENG_DEATH_COWARDICE = 2,
    MENG_INTRO = 3,
    MENG_SLAY = 4,
    MENG_SPELL = 5
};

#define MAX_FLANKING_MOGU   48

Position flankingPos[MAX_FLANKING_MOGU] =
{
    {4195.25f, 1590.85f, 438.841f, 0.12350f},
    {4194.99f, 1586.06f, 438.841f, 0.26639f},
    {4193.99f, 1581.04f, 438.840f, 0.39482f},
    {4195.19f, 1576.21f, 438.840f, 0.52845f},
    {4196.93f, 1571.99f, 438.839f, 0.64866f},
    {4200.06f, 1568.31f, 438.839f, 0.77664f},
    {4203.17f, 1564.49f, 438.837f, 0.90416f},
    {4206.52f, 1561.59f, 438.837f, 1.01808f},
    {4209.94f, 1558.79f, 438.836f, 1.12821f},
    {4213.91f, 1556.73f, 438.837f, 1.23942f},
    {4217.99f, 1556.02f, 438.839f, 1.34239f},
    {4222.20f, 1555.52f, 438.839f, 1.44913f},
    {4226.90f, 1555.01f, 438.839f, 1.56812f},
    {4231.69f, 1555.00f, 438.839f, 1.68814f},
    {4236.49f, 1556.31f, 438.838f, 1.81247f},
    {4241.28f, 1558.22f, 438.837f, 1.94289f},
    {4245.75f, 1561.11f, 438.837f, 2.07869f},
    {4250.17f, 1563.56f, 438.837f, 2.20908f},
    {4253.08f, 1568.12f, 438.839f, 2.34491f},
    {4255.07f, 1573.32f, 438.840f, 2.48865f},
    {4257.26f, 1579.05f, 438.840f, 2.66189f},
    {4257.36f, 1584.80f, 438.841f, 2.82356f},
    {4258.93f, 1591.29f, 438.841f, 3.03247f},
    {4259.81f, 1597.36f, 438.841f, 3.21968f},
    {4265.56f, 1603.04f, 438.842f, 3.35247f},
    {4264.61f, 1608.74f, 438.843f, 3.49683f},
    {4263.33f, 1613.64f, 438.841f, 3.62029f},
    {4260.61f, 1618.46f, 438.842f, 3.75534f},
    {4257.08f, 1622.41f, 438.845f, 3.88442f},
    {4253.70f, 1625.77f, 438.845f, 4.00111f},
    {4250.06f, 1629.08f, 438.844f, 4.12039f},
    {4245.74f, 1631.66f, 438.843f, 4.24225f},
    {4241.14f, 1634.23f, 438.846f, 4.36825f},
    {4236.42f, 1635.51f, 438.847f, 4.48507f},
    {4231.43f, 1635.73f, 438.849f, 4.60476f},
    {4226.52f, 1635.65f, 438.851f, 4.72422f},
    {4221.75f, 1635.25f, 438.851f, 4.84165f},
    {4217.01f, 1633.81f, 438.853f, 4.96304f},
    {4211.88f, 1632.07f, 438.853f, 5.09767f},
    {4207.12f, 1629.80f, 438.851f, 5.22899f},
    {4202.68f, 1626.57f, 438.851f, 5.36565f},
    {4198.73f, 1623.16f, 438.850f, 5.49605f},
    {4195.37f, 1619.05f, 438.849f, 5.62901f},
    {4192.82f, 1614.57f, 438.849f, 5.75861f},
    {4190.84f, 1609.64f, 438.847f, 5.89364f},
    {4190.58f, 1604.28f, 438.850f, 6.02825f},
    {4192.61f, 1600.68f, 438.844f, 6.11362f},
    {4195.38f, 1595.63f, 438.841f, 6.25653f}
};

/*
Position QiangTheMerciless      = {4226.33f, 1626.28f, 438.856f, 4.72348f};
Position SubetaiTheSwift        = {4257.35f, 1591.36f, 438.841f, 3.13526f};
Position ZianOfTheEndlessShadow = {4226.97f, 1558.32f, 438.804f, 1.58495f};
Position MengTheDemented        = {4198.78f, 1590.29f, 438.841f, 6.26345f};
*/

uint32 volleySpells[3] =
{
    SPELL_VOLLEY_1,
    SPELL_VOLLEY_2,
    SPELL_VOLLEY_3
};

uint32 spiritsOrder[4] =
{
    NPC_QIANG,
    NPC_SUBETAI,
    NPC_ZIAN,
    NPC_MENG
};

void AddSC_boss_spirit_kings()
{
    
}
