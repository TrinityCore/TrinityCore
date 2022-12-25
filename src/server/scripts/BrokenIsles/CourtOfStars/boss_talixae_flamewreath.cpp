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

#include "court_of_stars.h"

enum Says
{
    SAY_AGGRO_BAD = 3,
    SAY_KILL = 4,
    SAY_AGGRO = 5,
    SAY_DEATH = 6,
    SAY_BURNING = 7
};

enum Spells
{
    SPELL_BURNING_INTENSITY = 207906,
    SPELL_WITHERING_SOUL = 208165,
    SPELL_INFERNAL_ERUPTION = 207881,

    SPELL_BOND_OF_FLAME_AT = 209723, //Boss
    SPELL_BOND_OF_STRENGTH_AT = 207819, //NPC_JAZSHARIU
    SPELL_BOND_OF_CRUELTY_AT = 209717, //NPC_BAALGAR_THE_WATCHFUL
    SPELL_BOND_OF_CUNNING_AT = 209712, //NPC_IMACUTYA

    //Christmas
    SPELL_CHRISTMAS_CAP = 220861
};

enum eEvents
{
    EVENT_BURNING_INTENSITY = 1,
    EVENT_WITHERING_SOUL = 2,
    EVENT_INFERNAL_ERUPTION = 3,

    EVENT_1,
    EVENT_2,
    EVENT_3,
};

Position const mBossPos[3] =
{
    {1081.21f, 3313.43f, 25.05f, 0.23f}, //NPC_JAZSHARIU
    {1083.43f, 3307.68f, 24.98f, 0.81f}, //NPC_BAALGAR_THE_WATCHFUL
    {1088.88f, 3306.01f, 25.05f, 1.43f}  //NPC_IMACUTYA
};

Position const patrolPos[3] =
{
    {1161.85f, 3279.33f, 20.00f, 3.82f}, //NPC_FELBOUND_ENFORCER
    {1041.14f, 3388.77f, 19.96f, 3.27f},
    {1182.30f, 3350.27f, 20.00f, 1.57f}
};

Position const gCheckPos[3] =
{
    {1133.87f, 3278.71f, 20.1f},
    {1156.15f, 3327.12f, 20.9f},
    {1053.71f, 3357.99f, 19.84f}
};

void AddSC_boss_talixae_flamewreath()
{
    
}
