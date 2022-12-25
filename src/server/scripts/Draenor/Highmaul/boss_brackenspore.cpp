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

# include "highmaul.h"
#include "Group.h"

Position g_CreepingMossPos[eHighmaulDatas::MaxCreepingMoss] =
{
    { 4096.283f, 7719.135f, 0.2535536f },
    { 4107.993f, 7719.417f, 0.2534866f },
    { 4100.202f, 7735.637f, 0.2534722f },
    { 4095.731f, 7745.500f, 0.2534722f },
    { 4105.304f, 7757.403f, 0.2534722f },
    { 4124.274f, 7726.856f, 0.2535520f },
    { 4114.686f, 7764.564f, 0.2534722f },
    { 4128.087f, 7739.741f, 0.2534592f },
    { 4138.525f, 7750.965f, 0.2534567f },
    { 4148.499f, 7756.370f, 0.2527755f },
    { 4111.810f, 7739.060f, 0.2535081f },
    { 4133.647f, 7758.851f, 0.2534722f },
    { 4126.690f, 7767.401f, 0.2534722f },
    { 4139.254f, 7735.781f, 0.2535115f },
    { 4118.909f, 7753.566f, 0.2534722f },
    { 4151.049f, 7743.521f, 0.6013964f }
};

Position const g_FleshEaterSpawns[eHighmaulDatas::MaxFleshEaterPos] =
{
    { 4178.046f, 7791.621f, -0.3537667f, 3.052145f },
    { 4141.948f, 7720.839f, -1.1697650f, 2.001688f }
};

Position const g_flameThrowerDefaultSpawns[eHighmaulDatas::MaxFleshEaterPos] =
{
    { 4089.879883f, 7758.709961f, 0.336928f, 0.0f },
    { 4085.929932f, 7737.870117f, 0.338542f, 0.0f }
};

G3D::Vector3 g_BeachCenter = { 4104.36f, 7769.18f, 0.254f };

void AddSC_boss_brackenspore()
{
    
}
