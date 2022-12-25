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

#include "vault_of_the_wardens.h"
#include "GameObject.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_TELEPORT = 1,
    SAY_DEATH = 2,
    SAY_EMOTE = 3,
};

enum Spells
{
    SPELL_SAP_SOUL = 200905,
    SPELL_TELEPORT = 200898,
    SPELL_OPEN_PRISONS_AURA = 196821,
    SPELL_OPEN_PRISONS_CENTR = 196993,
    SPELL_OPEN_PRISONS_LEFT = 197009,
    SPELL_OPEN_PRISONS_RIGHT = 197010,

    //Other
    SPELL_TORMENT = 206470,
};

enum eEvents
{
    EVENT_SAP_SOUL = 1,
    EVENT_TELEPORT = 2,
    EVENT_OPEN_PRISON = 3,
    EVENT_SUM_PRISON_ADDS = 4,
};

Position const tpPos[4] =
{
    {4423.45f, -423.79f, 119.87f, 2.33f}, //Orks
    {4478.04f, -423.82f, 119.87f, 0.75f}, //Mogu
    {4478.52f, -478.88f, 119.87f, 5.44f}, //Void
    {4423.03f, -478.81f, 119.87f, 3.90f}, //Corruption
};

Position const sumPos[12] =
{
    {4417.47f, -417.87f, 120.39f, 5.50f}, //Orks centr - 99704
    {4405.09f, -418.98f, 120.15f, 4.65f}, //Orks left  - 99644
    {4418.89f, -405.60f, 120.23f, 0.08f}, //Orks right - 99645
    {4483.31f, -418.44f, 119.96f, 3.97f}, //Mogu centr - 99675
    {4481.22f, -405.33f, 119.96f, 3.13f}, //Mogu left  - 99676
    {4496.58f, -419.27f, 120.39f, 4.91f}, //Mogu right - 99676
    {4484.36f, -484.62f, 120.31f, 2.36f}, //Void centr - 99655
    {4496.40f, -482.99f, 120.15f, 1.47f}, //Void left  - 99657
    {4483.17f, -496.78f, 120.15f, 3.25f}, //Void right - 99651
    {4417.06f, -484.70f, 120.31f, 0.79f}, //Corruption centr - 99678
    {4418.96f, -496.95f, 120.25f, 0.02f}, //Corruption left  - 99678
    {4405.20f, -483.58f, 120.25f, 1.68f}, //Corruption right - 99678
};

void AddSC_boss_inquisitor_tormentorum()
{
    
}
