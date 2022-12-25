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

#include "Scenario.h"
#include "OutdoorPvP.h"
#include "AccountMgr.h"
#include "ScriptMgr.h"
#include "Player.h"
#include "SpellMgr.h"
#include "ScriptedGossip.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "Log.h"
#include "Conversation.h"
#include "CreatureTextMgr.h"
#include "PhasingHandler.h"
#include "AreaTriggerAI.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "GameEventMgr.h"

enum events
{
    EVENT_1,
    EVENT_2,
    EVENT_3,
    EVENT_4
};
Position const DemonHunterBonich[5] =
{
    { -3730.54f, -8004.46f, 2.84272f, 3.7699f },
    { -3716.07f, -7999.76f, 2.85281f, 0.0f },
    { -3721.6f, -8007.37f, 2.49409f, 5.02602f },
    { -3721.6f, -7992.15f, 2.92483f, 1.25663f },
    { -3730.54f, -7995.06f, 3.14554f, 2.51329f }
};

Position const DemonHunterAurinor[5] =
{
    { -4073.0f, -4654.52f, 80.5863f, 2.51329f },
    { -4073.0f, -4663.92f, 80.5863f, 3.7699f },
    { -4064.05f, -4666.83f, 80.5863f, 5.02655f },
    { -4064.05f, -4651.61f, 80.5863f, 1.25663f },
    { -4058.52f, -4659.22f, 80.5863f, 0.0f }
};

Position const DemonHunterNaigtal[5] =
{
    { -1835.82f, -1596.12f, 1.11104f, 1.85724f },
    { -1836.24f, -1611.33f, 0.672226f, 4.37052f },
    { -1827.22f, -1608.67f, 0.583281f, 5.62716f },
    { -1826.96f, -1599.27f, 1.00169f, 0.600602f },
    { -1841.56f, -1603.57f, 0.681503f, 3.11388f }
};

Position const DemonHunterCengar[5] =
{
    { 655.852f, 604.255f, 40.9144f, 1.34802f },
    { 662.049f, 597.18f, 40.4902f, 0.0910225f },
    { 648.064f, 591.182f, 40.2618f, 3.86093f },
    { 657.235f, 589.101f, 40.2661f, 5.11757f },
    { 647.209f, 600.548f, 40.4144f, 2.60429f }
};

Position const DemonHunterVal[5] =
{
    { 4025.6f, 570.56f, 0.33214f, 0.202399f },
    { -4038.83f, 563.044f, 0.0224609f, 3.97231f },
    { -4032.55f, 576.901f, 0.58214f, 1.45902f },
    { -4040.72f, 572.257f, 0.962267f, 2.71566f },
    { -4029.49f, 561.995f, -0.219604f, 5.22931f }
};

Position const DemonHunterSangua[5] =
{
    { -1387.595f, 753.6718f, 61.38449f, 5.115621f },
    { -1388.96f, 768.8273f, 62.62868f, 1.346462f },
    { -1382.772f, 761.7454f, 62.27438f, 0.08982736f },
    { -1396.764f, 755.7639f, 62.23556f, 3.859742f },
    { -1397.607f, 765.1305f, 62.38156f, 2.603098f }
};

Position const GameObjectsFlagsSangua[2] =
{
    { -1401.347f, 756.7188f, 62.50092f, 2.286167f },
    { -1385.615f, 770.9549f, 62.50092f, 2.286167f }
};

Position const GameObjectsFlagsBonich[2] =
{
    { -3713.248f, -8003.493f, 3.149687f, 4.70962f },
    { -3734.464f, -8003.865f, 3.163017f, 4.70962f }
};

Position const GameObjectsFlagsCengar[2] =
{
    { 665.1163f, 594.6597f, 40.31978f, 1.030727f },
    { 646.6945f, 605.1945f, 40.31978f, 1.030727f }
};

Position const GameObjectsFlagsNaigtal[2] =
{
    { -1844.26f, -1599.764f, 0.8188952f, 1.540312f },
    { -1823.043f, -1599.976f, 0.8188952f, 1.540312f }
};

Position const GameObjectsFlagsAurinor[2] =
{
    { -4076.918f, -4663.325f, 80.46125f, 4.70962f },
    { -4055.703f, -4662.953f, 80.46125f, 4.70962f }
};

Position const GameObjectsFlagsVal[2] =
{
    { -4043.491f, 563.4879f, 0.4485643f, 2.398739f },
    { -4029.46f, 579.4011f, 0.4485643f, 2.398739f }
};

void AddSC_invasion_point_argus()
{
    
}
