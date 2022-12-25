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

#include "GameEventMgr.h"
#include "GameObject.h"

enum eSay
{
    SAY_PANDA,
 
    SAY_TROLL,
    SAY_TAUREN,
    SAY_ORC,
    SAY_GOBLIN,
    SAY_UNDEAD,
    SAY_BLOOD_ELF,
    SAY_HIGHMOUNTAIN_TAUREN,
    SAY_NIGHTBORNE,
 
    SAY_HUMAN = 1,
    SAY_DRAENEI,
    SAY_GNOME,
    SAY_DWARF,
    SAY_NIGHTELF,
    SAY_WORGEN,
    SAY_LIGHTFORGED_DRAENEI,
    SAY_VOID_ELF
};

enum eEvent
{
    EVENT_1 = 1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
    EVENT_5,
    EVENT_6,
    EVENT_7,
    EVENT_8,
    EVENT_9
};

enum eAction
{
    ACTION_1 = 1,
    ACTION_2,
    ACTION_3,
    ACTION_4,
    ACTION_5,
    ACTION_6,
    ACTION_7,
    ACTION_8,
    ACTION_9,
};
Position GameObjects_PandaHorde1[2] =
{
    { 1646.538f, -4446.736f, 18.34174f, 0.0f },
    { 1645.198f, -4448.274f, 18.37885f, 5.277842f }
};
 
Position GameObjects_PandaHorde2[2] =
{
    { 1639.217f, -4454.135f, 18.52924f, 1.444366f },
    { 1640.997f, -4453.488f, 18.52862f, 1.444366f }
};
 
Position GameObjects_Undead[2] =
{
    { 1634.129f, -4450.229f, 18.58235f, 1.692287f },
    { 1642.49f, -4441.861f, 18.56001f, 2.807821f }
};
 
Position Creatures_Undead[2] =
{
    { 1646.344f, -4447.566f, 18.61218f, 2.624754f },
    { 1639.727f, -4453.734f, 18.61253f, 1.908382f }
};
 
Position GameObjects_Troll[2] =
{
    { 1634.082f, -4450.311f, 18.61004f, 1.962201f },
    { 1642.389f, -4442.094f, 18.61934f, 2.762229f }
};
 
Position Creatures_Troll[2] =
{
    { 1639.168f, -4453.635f, 18.6129f, 1.44558f },
    { 1646.5f, -4448.054f, 18.61526f, 2.603914f }
};
 
Position GameObjects_Tauren[2] =
{
    { 1634.092f, -4450.299f, 18.62661f, 2.360492f },
    { 1642.392f, -4442.052f, 18.60526f, 2.393105f }
};
 
Position GameObjects_Goblin1[2] =
{
    { 1642.576f, -4441.997f, 18.53502f, 2.567097f },
    { 1634.156f, -4450.365f, 18.40569f, 2.272538f }
};
 
Position GameObjects_Goblin2[1] =
{
    { 1639.512f, -4454.743f, 18.5289f, 1.639161f }
};
 
Position GameObjects_BloodElf[2] =
{
    { 1634.028f, -4450.311f, 18.44618f, 2.341336f },
    { 1642.415f, -4441.995f, 18.54674f, 2.341336f }
};
 
Position Creatures_BloodElf[2] =
{
    { 1646.379f, -4447.776f, 18.61213f, 2.284842f },
    { 1639.392f, -4454.759f, 18.61214f, 2.284842f }
};
 
Position GameObjects_Orc[4] =
{
    { 1642.403f, -4442.122f, 18.52885f, 2.339575f },
    { 1634.132f, -4450.304f, 18.53629f, 2.339575f },
    { 1648.064f, -4448.8f, 18.52731f, 2.339575f },
    { 1640.708f, -4456.162f, 18.5273f, 2.339575f }
};
 
Position Creatures_Human[4] =
{
    { -8809.627f, 667.875f, 99.68798f, 3.573264f },
    { -8811.129f, 671.9097f, 99.62115f, 3.601025f },
    { -8803.71f, 655.5677f, 99.61188f, 3.601025f },
    { -8805.778f, 658.6632f, 99.72522f, 3.601025f }
};
 
Position GameObjects_Human[2] =
{
    { -8816.955f, 671.0573f, 99.50975f, 3.868148f },
    { -8808.649f, 652.0295f, 99.58704f, 3.295569f }
};
 
Position GameObjects_PandaAlliance1[2] =
{
    { -8803.479f, 653.4132f, 99.61394f, 5.176046f },
    { -8804.701f, 656.5955f, 99.60896f, 0.0f }
};
 
Position GameObjects_PandaAlliance2[2] =
{
    { -8811.194f, 670.1927f, 99.61343f, 0.3403957f },
    { -8812.531f, 672.3646f, 99.60198f, 1.278826f }
};
 
Position GameObjects_PandaAlliance3[2] =
{
    { -8816.583f, 670.9063f, 99.51109f, 3.827629f },
    { -8808.478f, 652.0417f, 99.50964f, 2.903347f }
};
 
Position Creatures_PandaAlliance[2] =
{
    { -8805.607f, 658.6823f, 99.77298f, 3.323271f },
    { -8809.594f, 667.4236f, 99.72505f, 3.538034f }
};
 
Position Creatures_PandaHorde[2] =
{
    { 1637.998f, -4453.658f, 19.51874f, 1.905331f },
    { 1646.026f, -4445.582f, 19.78983f, 2.588455f }
};
 
Position GameObjects_Draenei1[2] =
{
    { -8817.076f, 671.0625f, 99.50977f, 3.992838f },
    { -8808.42f, 652.1059f, 99.5117f, 3.229078f }
};
 
Position GameObjects_Draenei2[2] =
{
    { -8803.939f, 655.5174f, 99.90648f, 5.15875f },
    { -8806.221f, 660.6702f, 99.90648f, 5.15875f }
};
 
Position GameObjects_Worgen[2] =
{
    { -8816.759f, 670.9688f, 99.50755f, 4.076256f },
    { -8808.451f, 651.9861f, 99.50967f, 2.962185f }
};

void AddSC_AuctionHouseDanceParty()
{
    
}
