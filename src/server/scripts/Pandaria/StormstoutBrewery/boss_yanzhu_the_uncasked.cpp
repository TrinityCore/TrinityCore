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

#include "stormstout_brewery.h"

struct ValuePair
{
    uint32 entry_1;
    uint32 entry_2;
};

static const Position gaoWaypoints[] =
{
    { 0.f, 0.f, 0.f                    },
    { -703.3f, 1187.5f, 166.7f         },
    { -707.4f, 1189.8f, 166.7f         },
    { -709.6f, 1185.0f, 166.7f, 4.905f }
};

static const Position chenWaypoints[] =
{
    { -673.7f, 1155.7f, 166.7f          },
    { 0.f,     0.f,     0.f             }, // empty
    { -708.1f, 1180.2f, 166.7f, 1.832f  }
};

static const Position largeBrewPos[] =
{
    { -702.09f, 1158.76f, 166.22f, 0.24f },
    { -704.20f, 1166.94f, 166.22f, 0.24f }
};

static const Position smallBrewPos[] =
{
    { -709.23f, 1152.57f, 166.22f, 0.17f },
    { -711.52f, 1160.55f, 166.22f, 0.17f },
    { -713.58f, 1168.67f, 166.22f, 0.17f },
    { -701.03f, 1154.85f, 166.22f, 0.17f },
    { -703.38f, 1162.76f, 166.22f, 0.17f },
    { -705.75f, 1170.97f, 166.22f, 0.17f },
    { -693.20f, 1157.04f, 166.22f, 0.17f },
    { -695.33f, 1165.07f, 166.22f, 0.17f },
    { -697.44f, 1173.05f, 166.22f, 0.17f },
};

static const Position middleBrewPos[] =
{
    { -700.52f, 1167.84f, 166.22f, 0.25f },
    { -698.25f, 1159.97f, 166.22f, 0.25f },
    { -708.61f, 1165.69f, 166.22f, 0.25f },
    { -706.43f, 1157.70f, 166.22f, 0.25f },
};

static const Position yanzhuPos[] = { -703.44f, 1162.43f, 166.22f, 0.24f };
static const Position gaoPotPos[] = { -676.96f, 1193.96f, 166.79f, 1.82f };

static const Position sudsPos[2] =
{
    { -696.25f, 1138.78f, 166.75f, 1.82f },
    { -663.20f, 1172.84f, 166.74f, 3.38f }
};

const uint32 brewSpells[3] =
{
    128253,
    128255,
    128257,
};

void AddSC_boss_yanzhu()
{
    
}