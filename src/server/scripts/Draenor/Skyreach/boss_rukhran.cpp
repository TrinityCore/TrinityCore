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

#include "instance_skyreach.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "GameObject.h"

static const Position k_Waypoints[12] =
{
    { 929.272f, 1937.448f, 224.75f, 0.0f},
    { 910.023f, 1921.640f, 219.96f, 0.0f},
    { 896.675f, 1901.697f, 219.96f, 0.0f},
    { 898.726f, 1872.698f, 224.75f, 0.0f},
    { 876.896f, 1888.450f, 224.75f, 0.0f},
    { 895.448f, 1928.450f, 224.75f, 0.0f},


    { 895.448f, 1928.450f, 224.75f, 0.0f},
    { 876.896f, 1888.450f, 224.75f, 0.0f},
    { 898.726f, 1872.698f, 224.75f, 0.0f},
    { 896.675f, 1901.697f, 219.96f, 0.0f},
    { 910.023f, 1921.640f, 219.96f, 0.0f},
    { 929.272f, 1937.448f, 224.75f, 0.0f},
};

static const Position k_RandomSummonSolarFlare[] =
{
    { 939.31f, 1907.440f, 213.86f, 0.0f },
    { 938.64f, 1899.550f, 213.86f, 0.0f },
    { 942.61f, 1915.518f, 214.40f, 0.0f },
    { 933.88f, 1908.990f, 213.86f, 0.0f },
    { 926.94f, 1898.300f, 213.86f, 0.0f },
    { 918.43f, 1892.141f, 213.86f, 0.0f },
    { 913.15f, 1887.884f, 213.86f, 0.0f },
    { 920.61f, 1882.406f, 213.86f, 0.0f },
    { 917.99f, 1876.340f, 213.86f, 0.0f },
    { 918.28f, 1884.108f, 213.86f, 0.0f },
    { 909.16f, 1883.930f, 214.40f, 0.0f },
};

void AddSC_boss_rukhran()
{
    
}
