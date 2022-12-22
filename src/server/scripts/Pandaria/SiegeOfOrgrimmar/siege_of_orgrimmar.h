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

#ifndef SIEGE_OF_ORGRIMMAR_H_
#define SIEGE_OF_ORGRIMMAR_H_

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"

#define MAX_FALLEN_PROTECTORS 3
#define MAX_KORKRON_DARK_SHAMANS 2
#define MAX_PARAGONS_OF_THE_KLAXXI 9
#define MATH_PI 3.14
#define GarroshGuardsOri 6.16f
#define CraneShaCount 2
#define JadeSerpentShaCount 15
#define TerraceShaCount 32

#define DataHeader "SOO"
#define scarlet_halls_scriptname "instance_siege_of_orgrimmar"
#define MAX_TYPES 14

const Position MalkorokPoint             = { 1914.39f, -4950.73f, -198.97f, 0.0f  };
const Position ConveyorAtriggerPos       = { 2099.51f, -5656.82f, -266.2f,  0.0f  }; // from sniffs
const Position ShredderSpawnPos          = { 1870.85f, -5642.97f, -248.54f, 0.48f };
const Position PlatformCenterPos         = { 1956.19f, -5608.70f, -309.24f, 5.30f };
const Position lorewalkerUpWaters        = { 1440.91f,   356.39f,  289.19f, 1.57f };
const Position ImmerseusCenterPos        = { 1440.79f,   751.55f,  245.93f, 1.37f };
const Position fallenProtectorsCenterPos = { 1213.10f,  1028.70f,  418.08f, 1.49f };
const Position quarMeasSpawnPos          = { 777.509f,  974.266f, 356.340f,  0.0f };
const Position nazgrimCenterPos          = { 1602.81f, -4629.72f,  -66.69f, 0.73f };
const Position aysaJiPath                = { 1538.95f, -4406.34f,   18.33f, 0.07f };
const Position ironJugernaunRelocate     = { 1328.14f, -4383.77f,   26.11f, 3.73f }; // after first wipe
const Position immerseusPuddleEvent      = { 1440.93f,   719.30f,  245.93f, 4.71f };
const Position galakrasFlyPoint          = { 1409.35f, -4822.68f,   97.50f, 5.00f };
const Position norushenShaRoom           = { 759.13f,   1060.50f,  356.07f, 1.76f };
const Position cagePrisonerLeavePos      = { 1573.47f, -4354.36f,   20.96f, 4.03f };
const Position jailerEntrancePos         = { 1290.97f, -5053.41f, -291.00f, 3.80f };
const Position demolisherMovePos         = { 1407.65f, -4818.29f, 20.57f, 5.00f };
const Position dagrynCenterPos           = { 1462.90f, -4804.51f, 68.45f, 1.18f };
const Position flamestrikePos            = { 1422.34f, -4867.66f, 11.78f, 4.94f };
const Position demolisherSpawnPos        = { 1370.024f, -4713.426f, 28.48843f, 5.04649f };
const Position sawformPos                = { 1910.70f, -5639.94f, -309.32f, 5.258132f }; // heroic blackfuse
const Position conveyorPull              = { 1992.15f, -5582.18f, -309.32f, 0.57f };
const Position myworldGarrosh            = { -8499.52f, 1080.75f, 17.95f, 1.35f };
const Position myWorldPlayers            = { -8486.28f, 1143.59f, 17.94f, 4.50f };
const Position starvedYetiTrash          = { 1218.61f, -5127.42f, -289.94f, 1.66f };
const Position garroshJumpPos            = { 1072.89f, -5639.42f, -317.38f, 0.0f };

const Position PipelineEntrace[2] =
{
    { 1971.691f, -5548.554f, -308.3217f, 4.34f }, // dest exit
    { 1995.047f, -5503.350f, -244.5230f, 5.14f }, // dest entrance
};

const Position ConveyorWeaponsPoints[2] = 
{
    { 1962.337f, -5452.712f, -303.0483f, 5.305801f }, // deactivated weap
    { 1935.752f, -5739.543f, -302.9146f, 2.146755f }, // activated weap
};

const Position ConveyorActivatedPoints[4] =
{
    { 1871.357f, -5644.402f, -302.885f, 0.593235f }, // high
    { 1886.838f, -5667.875f, -302.885f, 0.577523f }, // middle
    { 1902.893f, -5690.880f, -302.885f, 0.534326f }, // low
    { 1801.648f, -5539.229f, -302.998f, 2.153203f }, // despawn
};

const Position WarbringersSpawnPos[6] =
{
    { 997.77f, -5567.39f, -310.48f, 0.54f },
    { 997.23f, -5561.72f, -309.81f, 6.11f },
    { 997.14f, -5554.83f, -309.33f, 5.47f },
    { 980.55f, -5706.04f, -308.92f, 5.76f },
    { 982.08f, -5699.49f, -309.42f, 6.23f },
    { 983.45f, -5692.31f, -309.77f, 6.03f },
};

const Position WolfridersSpawnPos[2] =
{
    { 981.11f, -5699.22f, -308.89f, 6.23f },
    { 997.41f, -5561.68f, -309.98f, 6.15f },
};

const Position SiegeEngineersSpawnPos[2] =
{
    { 1060.98f, -5761.37f, -304.48f, 1.47f },
    { 1085.09f, -5520.41f, -304.35f, 4.67f },
};

const Position IronStarSpawnPos[2] =
{
    { 1059.924f, -5520.203f, -317.5687f, 4.647993f },
    { 1086.865f, -5755.289f, -317.5687f, 1.428905f },
};

const Position RealmWorldEntrancePos[3] =
{
    { 1055.27f, -5844.77f, -318.86f, 4.58f }, // Red Crane
    { 1090.02f, -5478.10f, -355.15f, 1.44f }, // jade Serpent
    { 1084.44f, -5631.01f, -423.45f, 4.58f }, // Terrace of the Endless Spring
};

const Position RealmWorldEGarroshPos[3] =
{
    { 1056.72f, -5829.73f, -368.66f, 4.56f }, // Red Crane
    { 1105.85f, -5339.25f, -349.70f, 1.44f }, // jade Serpent
    { 818.97f,  -5603.12f, -397.70f, 6.12f }, // Terrace of the Endless Spring
};

const Position KazowAmberSpawn[8] =
{
    { 1520.51f, -5666.36f, -295.14f, 5.79f },
    { 1495.81f, -5694.37f, -299.28f, 0.58f },
    { 1541.58f, -5762.19f, -299.28f, 0.55f },
    { 1576.78f, -5749.70f, -295.14f, 1.64f },
    { 1645.19f, -5703.36f, -295.14f, 2.66f },
    { 1669.87f, -5675.59f, -299.27f, 3.71f },
    { 1624.29f, -5607.76f, -299.27f, 3.67f },
    { 1589.00f, -5619.98f, -295.15f, 4.72f },
};

const Position choScarredValePath[5] =
{
    { 1431.33f,  987.31f, 340.25f, 1.69f },
    { 1426.51f, 1035.17f, 340.25f, 1.91f },
    { 1392.97f, 1037.91f, 340.29f, 3.08f },
    { 1288.99f, 1038.16f, 434.87f, 3.11f },
    { 1275.08f, 1034.98f, 434.86f, 3.29f },
};

const Position choPastImmerseusEvent[2] =
{
    { 1412.14f, 660.02f, 246.85f, 1.31f },
    { 1427.31f, 711.35f, 246.85f, 1.30f },
};

const Position choPreNorushenEvent[2] =
{
    { 806.04f, 839.95f, 371.18f, 1.77f },
    { 796.05f, 887.06f, 371.12f, 1.77f },
};

const Position pridePrisonsPos[4] =
{
    { 722.94f, 1129.06f, 356.07f, 0.0f },
    { 764.13f, 1137.86f, 356.07f, 0.0f },
    { 773.06f, 1096.81f, 356.07f, 0.0f },
    { 731.49f, 1087.53f, 356.07f, 0.0f },
};

const Position manifestationSpawnPos[3] =
{
    { 735.08f, 1173.70f, 356.07f, 4.87f }, // only 10N
    { 687.02f, 1099.83f, 356.07f, 0.15f },
    { 809.14f, 1125.79f, 356.07f, 3.30f },
};

const Position nazgrimKorkronSpawnPos[5] =
{
    { 1592.02f, -4584.47f, -66.81f, 5.26f },
    { 1584.05f, -4591.73f, -66.81f, 5.71f },
    { 1558.71f, -4621.78f, -66.92f, 5.82f },
    { 1558.88f, -4633.83f, -67.06f, 0.54f },
    { 1567.88f, -4646.63f, -66.86f, 0.57f },
};

const Position aysaPath[3]=
{
    { 1436.42f, -4425.73f, 25.45f, 1.62f },
    { 1486.87f, -4413.73f, 25.34f, 0.28f },
    { 1494.12f, -4410.41f, 23.91f, 0.10f },
};

const Position darkShamansRelocatePos[2] =
{
    { 1602.75f, -4383.12f, 20.49f, 3.51f },
    { 1598.78f, -4375.54f, 20.95f, 3.51f },
};

const Position norushenHomePath[3] =
{
    { 794.58f, 894.23f,  371.12f, 1.73f },
    { 789.73f, 915.71f,  357.21f, 1.73f },
    { 767.67f, 1015.55f, 356.09f, 4.92f },
};

const Position demolotionsSiegeSouthPath[5] =
{
    { 1429.03f, -4910.97f, 11.57f, 1.67f },
    { 1423.13f, -4905.76f, 11.34f, 2.56f },
    { 1377.68f, -4907.71f, 12.70f, 3.10f },
    { 1373.30f, -4862.76f, 31.13f, 1.66f },
    { 1370.92f, -4850.82f, 32.70f, 1.79f },
};

const Position demolotionsSiegeNorthPath[4] =
{
    { 1439.23f, -4887.82f, 10.71f, 0.95f },
    { 1462.43f, -4868.72f, 23.21f, 0.68f },
    { 1463.19f, -4859.78f, 26.07f, 1.48f },
    { 1459.48f, -4817.73f, 29.19f, 1.65f },
};

const Position inTowerCenter[2] =
{
    { 1363.08f, -4839.60f, 71.84f, 2.21f }, // south
    { 1462.71f, -4804.88f, 68.46f, 1.20f },
};

const Position jainaLorthemarShaRoomPortals[2] =
{
    { 782.00f, 1165.09f, 356.07f, 4.09f },
    { 695.62f, 1146.64f, 356.07f, 5.61f },
};

const Position galakrasWavePoint[6] =
{
    { 1407.28f, -4815.41f, 21.13f, 4.99f },
    { 1410.74f, -4809.28f, 21.66f, 4.99f },
    { 1401.52f, -4811.92f, 22.10f, 4.99f },
    { 1411.80f, -4804.24f, 22.08f, 4.99f },
    { 1405.63f, -4806.01f, 22.31f, 4.99f },
    { 1399.91f, -4807.64f, 22.57f, 4.99f },
};

const Position blackSpearLeadersPos[2] =
{
    { 1253.06f, -4398.66f, 26.15f, 0.08f },
    { 1253.27f, -4406.47f, 26.11f, 0.03f },
};

const Position blackSpearLeadersPosDefeat[2] =
{
    { 1291.52f, -4390.15f, 26.03f, 0.25f },
    { 1293.76f, -4397.80f, 26.03f, 0.25f },
};

const Position blackSpearWarriorsSuicide[2] =
{
    { 1258.78f, -4402.65f, 26.03f, 0.20f },
    { 1276.46f, -4397.25f, 26.03f, 0.20f },
};

const Position EncountersEntrance[MAX_TYPES - 1]
{
    { 1440.83f,   306.52f,  289.19f, 1.537f }, // Original Entrance
    { 1441.06f,   827.16f,  246.83f, 1.527f }, // after immerseus defeat
    { 1213.22f,  1040.77f,  417.88f, 4.646f }, // after fallen protectors defeat
    {  802.67f,   855.06f,  371.08f, 1.732f }, // after norushen defeat
    {  741.06f,  1145.15f,  356.07f, 1.763f }, // after sha of pride defeat
    { 1422.57f, -4867.28f,   11.79f,  1.90f }, // after galakras defeat
    { 1249.05f, -4404.78f,   26.03f, 0.200f }, // after iron juggernaut defeat
    { 1569.53f, -4402.74f,   16.07f, 5.883f }, // after dark korkron shamans defeat
    { 1726.47f, -4767.94f, -242.28f, 0.102f }, // after nazgrim defeat
    { 1901.00f, -4959.76f, -198.97f, 0.570f }, // after malkorok defeat
    { 1964.21f, -5190.32f, -272.25f, 3.721f }, // after spoils, thok defeat
    { 1710.14f, -5361.67f, -276.80f, 3.677f }, // after siegecrafter defeat
    { 1673.49f, -5623.99f, -306.69f, 3.709f }, // after paragon of klaxxi defeat
};

const Position korkronJailersPos[5] =
{
    { 1156.92f, -5143.96f, -289.94f, 3.76f },
    { 1178.54f, -5152.20f, -289.94f, 3.71f },
    { 1157.58f, -5122.87f, -289.94f, 3.71f },
    { 1168.65f, -5122.97f, -289.94f, 3.71f },
    { 1182.60f, -5142.66f, -289.94f, 3.71f },
};

const Position animalsJumpPos[2] =
{
    { 1210.31f, -5104.93f, -289.93f, 0.50f },
    { 1215.04f, -5166.48f, -289.94f, 1.74f },
};

const Position thokBloodthristyRelocate[2] =
{
    { 1147.80f, -5152.43f, -290.46f, 0.63f },
    { 1205.48f, -5110.47f, -289.94f, 0.58f },
};

const Position assaultTowers[2] =
{
    { 1372.33f, -4835.18f, 32.70f, 3.58f }, // South
    { 1450.51f, -4807.24f, 29.19f, 0.16f },
};

const Position ropeJumpPos[2] =
{
    { 1381.75f, -4839.26f, 71.52f, 2.88f }, // south
    { 1444.03f, -4811.81f, 68.09f, 0.40f },
};

const Position pipelineTransfertPos[4] =
{
    { 1894.37f, -5516.10f, -294.89f, 2.15f }, // from platform to underhold
    { 1921.70f, -5590.21f, -309.32f, 5.79f }, // from underhold to platform
    { 1995.68f, -5503.18f, -243.83f, 2.24f }, // from platform to conveyor
    { 1960.49f, -5560.35f, -309.32f, 4.57f }, // from conveyor to platform
};

const Position underholdToPlatform[6] =
{
    { 1914.36f, -5549.65f, -316.78f, 5.07f },
    { 1901.94f, -5563.30f, -315.87f, 5.26f },
    { 1893.39f, -5573.01f, -314.07f, 5.53f },
    { 1885.47f, -5587.63f, -319.40f, 5.06f },
    { 1877.80f, -5594.92f, -315.13f, 6.19f },
    { 1884.65f, -5607.80f, -316.26f, 6.08f },
};

const Position platformToUnderhold[3] =
{
    { 1922.22f, -5527.95f, -309.14f, 1.60f },
    { 1907.48f, -5537.35f, -309.14f, 2.01f },
    { 1893.54f, -5546.53f, -307.83f, 1.87f },
};

const Position conveyorToPlatform[5] =
{
    { 1936.26f, -5540.44f, -315.06f, 5.10f },
    { 1945.89f, -5536.30f, -315.41f, 4.70f },
    { 1958.49f, -5537.33f, -316.38f, 4.47f },
    { 1973.97f, -5538.24f, -314.64f, 4.42f },
    { 1988.87f, -5543.93f, -317.10f, 4.07f },
};

const Position bloodlettingMisslePos[4] =
{
    { 1634.86f, -5697.51f, -313.696f, 0.0f },
    { 1575.19f, -5738.07f, -313.713f, 0.0f },
    { 1531.14f, -5672.6f,  -313.695f, 0.0f },
    { 1603.76f, -5631.88f, -313.76f, 5.11f },
};

const Position garroshPathReach[2] =
{
    { 1026.44f, -5634.30f, -317.68f, 6.17f },
    { 1033.76f, -5635.01f, -317.68f, 3.04f }, // for thrall
};

const Position embodiedFearSpawnPos[8] =
{
    { 1050.52f, -5640.76f, -423.70f, 3.11f },
    { 1053.43f, -5614.22f, -423.70f, 4.41f },
    { 1032.36f, -5625.66f, -423.97f, 3.01f },
    { 1011.95f, -5623.40f, -423.96f, 3.04f },
    {  977.96f, -5619.63f, -416.90f, 3.03f },
    {  932.32f, -5615.01f, -416.65f, 3.04f },
    {  847.36f, -5582.81f, -398.02f, 1.66f },
    {  842.55f, -5628.58f, -398.02f, 4.26f },
};

const Position embodiedDoubtSpawnPos[5] =
{
    { 1071.90f, -5431.65f, -355.15f, 1.42f },
    { 1114.69f, -5436.27f, -355.15f, 6.17f },
    { 1098.63f, -5397.41f, -349.76f, 1.42f },
    { 1131.39f, -5363.80f, -350.56f, 6.14f },
    { 1073.66f, -5357.72f, -350.56f, 3.00f },
};

const Position embodiedDespairSpawnPos[2] =
{
    { 1067.10f, -5877.11f, -360.35f, 1.73f },
    { 1036.59f, -5873.62f, -360.35f, 1.13f },
};

const Position towerGruntsPosition[4] =
{
    { 1364.26f, -4858.18f, 71.45f, 5.90f },
    { 1375.27f, -4863.27f, 30.68f, 6.15f }, // jump there
    { 1446.02f, -4815.35f, 68.20f, 5.14f },
    { 1452.04f, -4830.92f, 29.01f, 5.43f }, // jump there
};

const Position overchargedLaserBunnyStartPos[3] =
{
    { 1906.63f, -5632.30f, -309.32f, 1.96f }, // Large
    { 1933.78f, -5581.89f, -309.32f, 0.66f },
    { 1946.72f, -5621.20f, -309.32f, 0.66f }, // Inner
};

const Position warbringerLastPosition[2] =
{
    { 1075.11f, -5616.70f, -317.68f, 5.31f }, // right
    { 1070.14f, -5662.05f, -317.68f, 0.48f },
};

const Position sparkSpawnRoomPos[4] =
{
    { 1574.28f, -5117.17f, -289.92f, 2.21f }, // mantid 1st
    { 1690.96f, -5133.86f, -289.92f, 5.30f }, // mogu 1st
    { 1653.25f, -5068.18f, -289.92f, 2.20f }, // mantid 2dt
    { 1611.09f, -5185.84f, -289.92f, 5.33f }, // mogu 2dt
};

const Position korkronPrisonersLeavePath[2]=
{
    { 1545.54f, -4402.91f, 18.23f, 0.0f },
    { 1491.09f, -4417.91f, 24.01f, 0.0f },
};

const Position theramorePrisonersLeavePath[3] =
{
    { 1567.16f, -4411.70f, 16.01f, 0.0f },
    { 1545.54f, -4402.91f, 18.23f, 0.0f },
    { 1491.09f, -4417.91f, 24.01f, 0.0f },
};

const Position gastropodPath[2] =
{
    { 1338.70f, -5053.90f, -289.18f, 2.58f },
    { 1308.27f, -5044.07f, -291.03f, 2.82f },
};

const Position gamonPath[24]=
{
    { 1862.99f, -4516.67f,  24.05f, 0.0f },
    { 1894.81f, -4484.95f,  23.67f, 0.0f },
    { 1892.33f, -4466.21f,  21.92f, 0.0f },
    { 1897.02f, -4430.05f,  15.10f, 0.0f },
    { 1882.23f, -4419.87f,  10.90f, 0.0f },
    { 1852.95f, -4418.31f,  5.58f,  0.0f },
    { 1836.98f, -4398.86f,  3.97f,  0.0f },
    { 1806.79f, -4348.62f, -10.62f, 0.0f },
    { 1799.88f, -4354.10f, -10.97f, 0.0f },
    { 1788.70f, -4365.92f, -15.82f, 0.0f },
    { 1796.45f, -4391.32f, -17.46f, 0.0f },
    { 1812.07f, -4410.18f, -18.19f, 0.0f },
    { 1818.53f, -4425.23f, -20.01f, 0.0f },
    { 1828.05f, -4448.19f, -27.50f, 0.0f },
    { 1831.20f, -4471.44f, -27.99f, 0.0f },
    { 1796.26f, -4484.48f, -27.83f, 0.0f },
    { 1779.53f, -4492.05f, -23.97f, 0.0f },
    { 1762.82f, -4502.22f, -28.45f, 0.0f },
    { 1752.63f, -4508.88f, -35.49f, 0.0f },
    { 1715.72f, -4534.44f, -39.75f, 0.0f },
    { 1692.02f, -4542.29f, -47.48f, 0.0f },
    { 1657.00f, -4577.33f, -59.57f, 0.0f },
    { 1630.82f, -4586.34f, -62.64f, 0.0f },
    { 1592.10f, -4616.08f, -66.71f, 0.0f },
};

uint32 const ArcingSmash = 5;

enum eData
{
    // First part
    DATA_IMMERSEUS,
    DATA_FALLEN_PROTECTORS,
    DATA_NORUSHEN,
    DATA_SHA_OF_PRIDE,

    // Second part
    DATA_GALAKRAS,
    DATA_IRON_JUGGERNAUT,
    DATA_KORKRON_DARK_SHAMANS,
    DATA_GENERAL_NAZGRIM,

    // Third part
    DATA_MALKOROK,
    DATA_SPOILS_OF_PANDARIA,
    DATA_THOK_THE_BLOODTHIRSTY,

    // Last part
    DATA_SIEGECRAFTER_BLACKFUSE,
    DATA_PARAGONS_OF_THE_KLAXXI,
    DATA_GARROSH_HELLSCREAM,

    DATA_MAX_BOSS_DATA,

    // Garrosh Sha Vortex State
    DATA_SHA_VORTEX,

    // Misc
    DATA_FALLEN_PROTECTORS_PRE_EVENT,
    DATA_NORUSHEN_PRE_EVENT_1,
    DATA_NORUSHEN_PRE_EVENT_2,
    DATA_SHA_OF_PRIDE_PRE_EVENT,
    DATA_SHA_OF_PRIDE_PAST_EVENT,
    DATA_GALAKRAS_PRE_EVENT,
    DATA_IRON_JUGGERNAUT_PAST_EVENT,
    DATA_THOK_BLOODTHIRSTY_PRE_EVENT,
    DATA_GROUP_FACTION,
    DATA_LFR,
    DATA_SHAMANS_PRISON,
    DATA_SIEGECRAFTER_PRE_EVENT,
    DATA_GARROSH_HELLSCREAM_PREVE_EVENT,
    DATA_FLEX,
    DATA_SHANNA_SPARKFIZZ,
    DATA_BEACH_CANNONS_COUNT,
    DATA_AQUEOUS_DEFENDERS_FALLEN_COUNT,
    DATA_AQUEOUS_DEFENDERS_FALLEN,
    DATA_KORKRON_BARRACKS_EVENT,
    DATA_MOJKA_PRISONERS_COMBAT,
    DATA_MOJKA_PRISONERS_LEAVE,
    DATA_THATUNG_PRISONERS_LEAVE,
    DATA_PRISONERS_COUNT,
    DATA_PARAGON_PRE_EVENT,
};

enum eCreatures
{
    // Immerseus
    NPC_IMMERSEUS                       = 71543,
    NPC_SHA_PUDDLE                      = 71603,
    NPC_CONTAMINATED_PUDDLE             = 71604,
    NPC_SHA_BOLT                        = 71544, // Sha Bolt NPC - goes with Sha Splash.
    NPC_SWIRL                           = 71548, // Swirl NPC (many, in room).
    NPC_SWIRL_TARGET                    = 71550, // For the boss channel spell.
    NPC_CONGEALED_SHA                   = 71642, // From Swelling Corruption aura, Heroic only!.
    NPC_SHA_POOL                        = 71611,

    // Fallen Protectors
    NPC_ROOK_STONETOE                   = 71475,
    NPC_HE_SOFTFOOT                     = 71479,
    NPC_SUN_TENDERHEART                 = 71480,
    NPC_EMBODIED_MISERY                 = 71476,
    NPC_EMBODIED_SORROW                 = 71481,
    NPC_EMBODIED_GLOOM                  = 71477,
    NPC_EMBODIED_ANGUISH                = 71478,
    NPC_EMBODIED_DESPAIR                = 71474,
    NPC_EMBODIED_DESPERATION            = 71482,
    NPC_DESPAIR_SPAWN                   = 71712,
    NPC_DESPERATION_SPAWN               = 71993,
    NPC_GOLDEN_LOTUS_TRIGGER_1          = 71711,
    NPC_GOLDEN_LOTUS_TRIGGER_2          = 71684,
    NPC_GOLDEN_LOTUS_TRIGGER_3          = 71686,

    // Norushen
    NPC_NORUSHEN                        = 71965,
    NPC_NORUSHEN_2                      = 71967,
    NPC_AMALGAM_OF_CORRUPTION           = 72276,
    NPC_ESSENCE_OF_CORRUPTION           = 71977,
    NPC_MANIFESTATION_OF_CORRUPTION     = 71976,
    NPC_QUARANTINE_MEASURES             = 72669,

    // Amalgam of Corruption.
    NPC_BLIND_HATRED                    = 72565,
    NPC_PURIFYING_LIGHT                 = 72065, // Orbs used to enter the Look Within realm. 2 in 10 players, 4 in 25.
    NPC_GREATER_CORRUPTION              = 72001, // Healer trial.
    NPC_TITANIC_CORRUPTION              = 72051, // Tank trial.
    NPC_MANIFEST_OF_CORRUPTION_L        = 71977,
    NPC_MANIFEST_OF_CORRUPTION_N        = 72264,
    NPC_ESSENCE_OF_CORRUPTION_L         = 71976,
    NPC_ESSENCE_OF_CORRUPTION_N         = 72263,
    NPC_RESIDUAL_CORRUPTION             = 72550, // Spawned by NPC_MANIFEST_OF_CORRUPTION_N when it dies.

    // Greater Corruption fight NPC's.
    NPC_LEVEN_DAWNBLADE_GC              = 71995,
    NPC_ROOK_STONETOE_GC                = 71996,
    NPC_SUN_TENDERHEART_GC              = 72000,

    // Sha of Pride
    NPC_SHA_OF_PRIDE                    = 71734,
    NPC_REFLECTION                      = 72172,
    NPC_MANIFESTATION_OF_PRIDE          = 71946, // From Banishment.
    NPC_RIFT_OF_CORRUPTION              = 72846, // From Unstable Corruption.
    NPC_SHADOW_PRISON                   = 72017,

    // Galakras
    NPC_GALAKRAS                        = 72249,
    NPC_ZAELA                           = 72248,
    NPC_MASTER_CANNONEER_DAGRYN         = 72356,
    NPC_HIGH_ENFORCER_THRANOK           = 72355,
    NPC_LIEUTENANT_KRUGRUK              = 72357,
    NPC_KORGRA_THE_SNAKE                = 72456,
    NPC_DEMOLITIONS_EXPERT              = 73550,
    NPC_DEMOLITIONS_ASSISTANT           = 73551,
    NPC_DRAGONMAW_FLAMESLINGER          = 72353,
    NPC_GALAKRAS_DRAGONMAW_BONECRUSHER  = 72945,
    NPC_GALAKRAS_DRAGONMAW_TIDAL_SHAMAN = 72958,
    NPC_GALAKRAS_DRAGONMAW_GRUNT        = 72941,
    NPC_GALAKRAS_DRAGONMAW_GRUNT_2      = 73530, // only in HC
    NPC_GALAKRAS_DRAGONMAW_FLAGBEARER   = 72942,
    NPC_GALAKRAS_DRAGONMAW_EBON_STALKER = 72352,
    NPC_GALAKRAS_DRAGONMAW_PROTO_DRAKE  = 72943,
    NPC_GALAKRAS_KORKRON_DEMOLISHER     = 72947,
    NPC_ARCHMAGE_AETHAS_SUNREAVER       = 73909,
    NPC_LORTHEMAR_THERON                = 72560,
    NPC_LADY_SYLVANAS_WINDRUNNER        = 72561,
    NPC_SUNREAVER_MAGUS                 = 72581,
    NPC_SUNREAVER_SENTINEL              = 72579,
    NPC_SUNREAVER_CONSTRUCT             = 72580,
    NPC_ALLIANCE_VANGUARD               = 72549,
    NPC_ALLIANCE_VANGUARD_1             = 72548,
    NPC_ALLIANCE_VANGUARD_2             = 72534,
    NPC_KING_VARIAN_WRYNN               = 72311,
    NPC_LADY_JAINA_PROUDMOORE           = 72302,
    NPC_VEREESA_WINDRUNNER              = 73910,
    NPC_ROPE                            = 73920,
    NPC_ANTI_AIR_CANNON                 = 72408,
    
    // Iron Juggernaut
    NPC_IRON_JUGGERNAUT                 = 71466,
    NPC_CRAWLER_MINE                    = 72050,
    NPC_BORER_DRILL                     = 71906,
    NPC_IJ_SAWBLADE                     = 71469,
    NPC_IJ_CANNON_1                     = 71468,
    NPC_IJ_CANNON_2                     = 71913,
    NPC_IJ_TOP_CANNON                   = 71484,
    NPC_IJ_TAIL_GUN                     = 71914,
    NPC_CUTTER_BEAM_STALKER_TARGET      = 73891,
    NPC_CUTTER_LASER                    = 72026,
    NPC_EXPLOSIVE_TAR                   = 71950,

    // Kor'Kron Dark Shamans
    NPC_EARTHBREAKER_HAROMM             = 71859,
    NPC_WAVEBINDER_KARDIS               = 71858,
    NPC_DARKFANG                        = 71921,
    NPC_BLOODCLAW                       = 71923,
    NPC_FOULSTREAM_TOTEM                = 71916,
    NPC_POISONMIST_TOTEM                = 71917,
    NPC_ASHFLARE_TOTEM                  = 71917,
    NPC_FOUL_SLIM                       = 71825,
    NPC_ASHEN_ELEMENTAL                 = 71827,
    NPC_TOXIC_STORM                     = 71801,
    NPC_TOXIC_TORNADO                   = 71817,
    NPC_FALLING_ASH                     = 71789,
    NPC_RUSTED_IRON_TOTEM               = 71918,
    NPC_IRON_TOMB                       = 71941,

    // General Nazgrim
    NPC_GENERAL_NAZGRIM                 = 71515,
    NPC_ORGRIMMAR_FAITHFUL              = 71715,
    NPC_KORKRON_IRONBLADE               = 71770,
    NPC_KORKRON_ARCWEAVER               = 71771,
    NPC_KORKRON_ASSASSIN                = 71772,
    NPC_KORKRON_WARSHAMAN               = 71773,
    NPC_KORKRON_BANNER                  = 71626,
    NPC_RAVAGER                         = 71762,
    NPC_HEROIC_SHOCKWAVE                = 71697,
    NPC_KORKRON_SNIPER                  = 71656,

    // Malkorok
    NPC_MALKOROK                        = 71454,
    NPC_IMPLOSION                       = 71470,
    NPC_ANCIENT_MIASMA                  = 71513,
    NPC_ARCING_SMASH                    = 71455,
    NPC_MALKOROK_CONTROLLER             = 71459,
    NPC_LIVING_CORRUPTION               = 71644,

    // Spoils ofPandaria
    NPC_SPOILS_OF_PANDARIA              = 71889,
    NPC_MODIFIED_ANIMA_GOLEM            = 71395,
    NPC_MOGU_SHADOW_RITUALIST           = 71393,
    NPC_SHADOW_RITUALIST_PHYLACTERY     = 71392,
    NPC_ZARTHIK_AMBER_PRIEST            = 71397,
    NPC_SETTHIK_WIELDER                 = 71405,
    NPC_ANIMATED_STONE_MOGU             = 71380,
    NPC_BURIAL_URN                      = 71382,
    NPC_SPARK_OF_LIFE                   = 71433,
    NPC_STONE_STATUE                    = 72535,
    NPC_QUILEN_GUARDIANS                = 72223,
    NPC_QUILEN_GUARDIANS_MAIN           = 71378,
    NPC_SRITHIK_BOMBARDIER              = 71385,
    NPC_KORTHIK_WARCALLER               = 71383,
    NPC_AMBER_ENCASED_KUNCHONG          = 71388,
    NPC_ANCIENT_BREWMASTER_SPIRIT       = 71427, // Unknown coordinates
    NPC_WISE_MISTEWEAVER_SPIRIT         = 71428, // Unknown coordinates
    NPC_NAMELESSE_WINDWALLKER_SPIRIT    = 71430, // Unknown coordinates
    NPC_JUN_WEI                         = 73723,
    NPC_KUN_DA                          = 71408,
    NPC_XIANG_LIN                       = 73725,
    NPC_ZU_YIN                          = 73724,
    NPC_COMMANDER_TIK                   = 73951,
    NPC_COMMANDER_IKTAL                 = 73948,
    NPC_COMMANDER_NAKAZ                 = 73949,
    NPC_SPOILS_OF_PANDARIA_LEVER        = 72281,
    NPC_MANTID_SPOILS_1                 = 73721,
    NPC_MOGU_SPOILS_1                   = 73720,
    NPC_MOGU_SPOILS_2                   = 73722,
    NPC_MANTID_SPOILS_2                 = 71512,
    NPC_STAFF_OF_RESONANTING_WATER      = 72810,
    NPC_BLADE_OF_HUNDRED_STEPS          = 72787,
    NPC_CLAW_OF_BURNING_ANGER           = 72828,
    NPC_UNSTABLE_SPARK                  = 73104,

    // Thok the Bloothirsty
    NPC_THOK_THE_BLOODTHIRSTY           = 71529,
    NPC_KORKRON_JAILER                  = 71658,
    NPC_AKOLIK                          = 71742,
    NPC_WATERSPEAKER_GORAI              = 71749,
    NPC_MONTAK                          = 71763,
    NPC_TESLA_COIL                      = 73198,
    NPC_THOK_INVISIBLE_MAN              = 69595,
    NPC_SHOCK_COLLAR                    = 71645,
    NPC_FOOTS_COLLAR                    = 73200,
    NPC_BODY_STALKER                    = 71787,
    NPC_INKGILL_CAPTIVE                 = 71753,
    NPC_SKUMBLADE_CAPTIVE               = 71744,
    NPC_GAI_CHO_REFUGE                  = 71764,
    NPC_ICE_TOMB                        = 69398,
    NPC_CAPTIVE_CAVE_BAT                = 73522,
    NPC_STARVED_YETI                    = 73526,
    NPC_MONSTROUS_GASTROPOD             = 73164,

    // Siegecrafter Blackfuse
    NPC_SIEGECRAFTER_BLACKFUSE          = 71504, // vehicle
    NPC_SIEGECRAFTER_BLACKFUSE_1        = 72694,
    NPC_AUTOMATED_SHREDDER              = 71591,
    NPC_SHOCKWAVE_MISSLE_CASTER_STALKER = 72710, // target for shockwave missle
    NPC_SHOCKWAVE_MISSLE                = 72052,
    NPC_SIEGECRAFTER_HELPER             = 71520,
    NPC_LASER_ARRAY_TARGET_VEHICLE      = 71912,
    NPC_LASSER_ARRAY                    = 71910,
    NPC_LASER_TARGET_BUNNY              = 71740,
    NPC_DISASSEMBLED_CRAWLER_MINES      = 71790,
    NPC_DIACTIVATED_MISSLE_TURRET       = 71606,
    NPC_DIACTIVATED_LASER_TURRET        = 71751,
    NPC_DIACTIVATED_ELECTROMAGNET       = 71694,
    NPC_ACTIVATED_LASER_TURRET_BASE     = 72015,
    NPC_ACTIVATED_LASER_TURRET          = 71752,
    NPC_ACTIVATED_ELECTROMAGNET         = 71696,
    NPC_ACTIVATED_MISSLE_TURRET         = 71638,
    NPC_ACTIVATED_MISSLE_TURRET_BASE    = 72027,
    NPC_SIEGECRAFTER_CRAWLER_MINE       = 71788,
    NPC_ACTIVATED_CRAWLER_MINE_VEHICLE  = 71795,
    NPC_SAWBLADE                        = 71532,
    NPC_DEACTIVATED_DEATHDEALER_TURRET  = 72904,
    NPC_ACTIVATED_DEATHDEALER_TURRET    = 72905,
    NPC_OVERCHARGED_CRAWLER_MINE        = 72668,
    NPC_OVERCHARGED_LASER_TURRET        = 72773,
    NPC_OVERCHARGED_MISSLE_TURRET       = 72831,
    NPC_OVERCHARGED_ELECTROMAGNET       = 73387,
    NPC_SHOCKWAVE_MISSLE_HC             = 72832,

    // Paragons of the Klaxxi
    NPC_KILRUK_THE_WIND_REAVER          = 71161,
    NPC_XARIL_THE_POISONED_MIND         = 71157,
    NPC_KAZTIK_THE_MANIPULATOR          = 71156,
    NPC_KORVEN_THE_PRIME                = 71155,
    NPC_IYYOKUK_THE_LUCID               = 71160,
    NPC_KAROZ_THE_LOCUST                = 71154,
    NPC_SKEER_THE_BLOODSEEKER           = 71152,
    NPC_RIKKAL_THE_DISSECTOR            = 71158,
    NPC_HISEK_THE_SWARMKEEPER           = 71153,
    NPC_PARAGON_OF_THE_KLAXXI           = 71592, // Helper
    NPC_MANTID_AMBER                    = 71628,
    NPC_IMPACT_JUMP_TARGET              = 71309,
    NPC_AMBER                           = 71407,
    NPC_BLOOD                           = 71542,
    NPC_AMBER_BOMB                      = 71691,
    NPC_HUNGRY_KUNCHONG                 = 71420,
    NPC_AMBER_PARASITE                  = 71578,

    // Garrosh Hellscream
    NPC_GARROSH_HELLSCREAM              = 71865,
    NPC_SIEGE_ENGINEER                  = 71984,
    NPC_WARBRINGER_KORKRON              = 71979,
    NPC_WOLF_RIDER_FARSEER              = 71983,
    NPC_DESECRATED_WEAPON               = 72154,
    NPC_DESECRATED_WEAPON_EMPOWERED     = 72198,
    NPC_IRON_STAR                       = 71985,
    NPC_HEART_OF_YSHAARJ                = 72215,
    NPC_SHA_VORTEX                      = 72239,
    NPC_EMBODIED_DESPAIR_G              = 72238,
    NPC_EMBODIED_FEAR                   = 72237,
    NPC_EMBODIED_DOUBT                  = 72236,
    NPC_MINION_OF_YSHAARJ               = 72272,
    NPC_HEART_OF_YSHAARJ_REALM          = 72228,
    NPC_UNSTABLE_IRON_STAR              = 73059,
    NPC_GUNSHIP_MAIN_CANNON             = 73258,
    NPC_GUNSHIP_SMALL_CANNON            = 73262,
    NPC_MANIFESTATION_OF_RAGE           = 73253,

    // Misc
    NPC_TORMENTED_INITIATE              = 73349,
    NPC_INVISIBLE_STALKER               = 73192,
    NPC_FALLEN_POOL_TENDER              = 73342,
    NPC_AQUEOUS_DEFENDER                = 73191,
    NPC_LESSER_SHA_PUDDLE               = 73197,
    NPC_LESSER_CONTAMINATED_PUDDLE      = 73260,
    NPC_VORTEX                          = 73409,
    NPC_LOREWALKER_CHO                  = 73330,
    NPC_LOREWALKER_CHO_NORUSHEN         = 72872,
    NPC_FRAGMENT_OF_PRIDE               = 72655,
    NPC_AMALGAMATED_HUBRIS              = 72658,
    NPC_LINGERING_CORRUPTION            = 72791,
    NPC_OOZE_CONTROLLER                 = 73222,
    NPC_PRESSURE_PLATE                  = 73124,
    NPC_KLAXXI_SKIRMISHER               = 73012,
    NPC_KORTHIK_HONOR_GUARD             = 72954,
    NPC_SRATHIK_AMBER_MASTER            = 72929,
    NPC_KOVOK                           = 72927,
    NPC_RESONATING_AMBER                = 72966,
    NPC_LORTHEMAR_PRIDE_ROOM            = 73605,
    NPC_JAINA_PRIDE_ROOM                = 73598,
    NPC_THARAN_ZHU_PRIDE                = 72779,
    NPC_AYSA_CLOUDSINGER                = 72438,
    NPC_JI_FIREPAW                      = 72454,
    NPC_EITRIGG                         = 72432,
    NPC_OVERSEER_KOMAK                  = 72455,
    NPC_DRAGONMAW_TIDAL_SHAMAN          = 72367,
    NPC_DRAGONMAW_CANNONEER             = 72365,
    NPC_DRAGONMAW_BONECRUSHER           = 72354,
    NPC_DRAGONMAW_ELITE_GRUNT           = 72350,
    NPC_DRAGONMAW_FLAGBEATER            = 72351,
    NPC_ZEAL                            = 72661,
    NPC_VANITY                          = 72662,
    NPC_PORTAL_TO_ORGRIMMAR             = 73536,
    NPC_KORKRON_ELITE_SNIPER            = 72261,
    NPC_BAINE_BLOODHOOF                 = 73941,
    NPC_VOLJIN                          = 73942,
    NPC_NAZGRIM_PRE_EVENT               = 73939,
    NPC_TYRANDE_WHISPERWIND             = 73962,
    NPC_OVERLORD_RUNTHAK                = 72191,
    NPC_GROLDAR                         = 72145,
    NPC_DRAGONMAW_GRUNT                 = 72941,
    NPC_BLOOD_POOL                      = 72781,
    NPC_DARKSPEAR_WARRIOR               = 73859,
    NPC_NIGHT_ELF_SENTINEL              = 73963,
    NPC_TYRANDE                         = 73962,
    NPC_GLAIWE_THROWER                  = 73961,
    NPC_GENERAL_FLY_BUNNY               = 67237,
    NPC_KORKRON_GRUNT                   = 73964,
    NPC_BLIND_BLADEMASTER               = 72131,
    NPC_KORKRON_DARK_SHAMAN             = 72451,
    NPC_KORKRON_SHADOWMAGE              = 72150,
    NPC_KORKRON_OVERSEER                = 72421,
    NPC_OVERSEER_MOJKA                  = 72490,
    NPC_OVERSEER_THATUNG                = 72496,
    NPC_TREASURE_GUARD                  = 72434,
    NPC_KORKRON_DIRE_WOLF               = 72452,
    NPC_MOKVAR_THE_THREASURER           = 72433,
    NPC_POISON_BOLT_TOTEM               = 72562,
    NPC_DOYODA                          = 72486,
    NPC_WILDHUMMER_SHAMAN               = 72640,
    NPC_HELLSCREAM_DEMOLISHER           = 72194,
    NPC_GAMON                           = 72192,
    NPC_DOOMLORD                        = 72564,
    NPC_KORKRON_BLOOD_AXE               = 72728,
    NPC_KORKRON_GUNNER                  = 72784,
    NPC_KORKRON_DARK_FARSEER            = 72770,
    NPC_KORKRON_WAR_WOLF                = 72768,
    NPC_KORKRON_SIEGEMASTER             = 72903,
    NPC_HELLSCREAM_ANNIHILATOR          = 72847,
    NPC_KORKRON_SKULL_SPLITTER          = 72744,
    NPC_ORGRIMMAR_PEON_2                = 72893,
    NPC_CORRUPTED_SKULLSPLITTER         = 72983,
    NPC_KORKRON_IRON_SCORPION           = 73194,
    NPC_KORKRON_WILD_GUN                = 73250,
    NPC_SLG_GENERIC_MOP                 = 68553,
    NPC_KORKRON_JAILER_THRASH           = 73195,
    NPC_RESISTANCE_TOTEM                = 72643,
    NPC_ARCWEAVER_REINFORCEMENTS        = 73153,
    NPC_BRUTE_REINFORCEMENTS            = 73155,
    NPC_STOREROOM_GUARD                 = 73152,
    NPC_BLACKFUSE_SELLSWORD             = 73091,
    NPC_BLACKFUSE_ENGINEER              = 73095,
    NPC_AGGRON                          = 72981,
    NPC_BLACKFUSE_KORKRON_OVERSEER      = 73098,
    NPC_SHANNA_SPARKFIZZ                = 72986,
    NPC_GORODAN                         = 72964,
    NPC_BEACH_CANNON                    = 72358,
    NPC_LEVER_KORKRON_BARRAKS           = 73461,
    NPC_INVISIBLE_MAN_UNK               = 62142,
    NPC_KORKRON_IRON_SENTINEL           = 73904,
    NPC_WAR_MASTER_KRAGG                = 73775,
    NPC_THRESHER_TURRET                 = 73742,
    NPC_BOMB_SPAWNER                    = 74028,
    NPC_THRALL_GARROSH_EVENT            = 73483,
    NPC_BLOOD_OF_YSHAARJ_TRIGGER        = 73411,
    NPC_HARBINGER_OF_YSHAARJ            = 73452,
    NPC_KORKRON_REAPER                  = 73414,
    NPC_ICHOR_OF_YSHAARJ                = 73415,
    NPC_KORKRON_GUNNER_RP               = 74158,
    NPC_GAMMON_CHAINS_BUNNY             = 54020,
    NPC_OVERLORD_SAURFANG               = 73716,
    NPC_KORKRON_TRAINING_DUMMY          = 32666,
    NPC_DANCING_FLAME                   = 61795,
    NPC_ENRAGED_MUSHAN_BEAST            = 73185,
    NPC_STARVED_YETI_TRASH              = 73184,
    NPC_SHA_CLOUD                       = 72588,
    NPC_SPIKE_MINE                      = 72656,
    NPC_SHIMRA                          = 72492,
    NPC_TRAK_GEN                        = 72493,
    NPC_ZAZO                            = 72484,
    NPC_GOMA                            = 72485,
    NPC_SAROK                           = 72483,
    NPC_THERAMORE_CITIZEN               = 72498,
    NPC_TEARS_OF_THE_VALE               = 73638,
    NPC_LOREWALKER_CHO_SHA_ROOM         = 61348,

    // Garrosh Outro
    NPC_STORMWIND_ROYAL_GUARD           = 73600,
    NPC_ORGRIMMAR_GRUNT                 = 73602,
    NPC_IRONFORGE_GUARD                 = 74218,
    NPC_DARNASSUS_SENTINEL              = 74219,
    NPC_TYRANDE_WHISPERWIND_GARROSH     = 74216,
    NPC_ANDUIN_WRYNN_GARROSH            = 73607,
    NPC_TINKER_MEKKATORQUE_GARROSH      = 74217,
    NPC_LOREWALKER_CHO_GARROSH          = 73318,
    NPC_TARAN_ZHU_GARROSH               = 73593,
    NPC_GALLYWIX_GARROSH                = 73604,
    NPC_SYLVANAS_GARROSH                = 73606,
    NPC_THRALL_GARROSH                  = 73591,
    NPC_VOLJIN_GARROSH                  = 73597,
    NPC_BAINE_GARROSH                   = 73603,
    NPC_MOIRA_GARROSH                   = 70279,
    NPC_VARIAN_GARROSH                  = 73592,
    NPC_FADING_BREATH                   = 73335,

    // Misc
    NPC_DANCING_RUNIC_WEAPON            = 27893,
    NPC_MONK_XUEN                       = 63508,
    NPC_GUARDIAN_OF_ANCIENT_KINGS       = 46490,
};

enum iActions
{
    ACTION_CONVEYOR_RESET,
    ACTION_CONVEYOR_RUN,
    ACTION_ANY_DEACTIVATED_HAS_DISSAPEAR,
    ACTION_LAUNCH_ACTIVATED_WEAPON,
    ACTION_REMOVE_ACTIVATED_WEAPON,
    ACTION_SAWBLADE_LAUNCHED,
    ACTION_LAUNCH_AMBER_BOMB,
    ACTION_ENCASE_AMBER_DONE,
    ACTION_DEVOUR,
    ACTION_GARROSH_EVADE,
    ACTION_POWER_IRON_STAR,
    ACTION_GARROSH_PHASE_SECOND,
    ACTION_GARROSH_ALT_PHASE,
    ACTION_REMOVE_YSHAARJ_PROTECTION,
    ACTION_GARROSH_PHASE_THIRD,
    ACTION_GARROSH_EMBODIED,
    ACTION_START_INTRO,
    ACTION_UNDER_TORMENTED,
    ACTION_IMMERSIUS_DEFEAT,
    ACTION_SCARRED_VALE,
    ACTION_HEALED_BY_BOND_OF_LOTUS,
    ACTION_CHO_PAST_PROTECTORS,
    ACTION_COOLING_OFF,
    ACTION_TAR_EXPLOSION,
    ACTION_IRON_JUGGERNAUT_DEFEAT,
    ACTION_IRON_JUGGERNAUT_COMBAT_INIT,
    ACTION_HANDLE_CAST_STATE,
    ACTION_REMOVE_GEYSER,
    ACTION_SIEGECRAFTER_MINE_LAUNCH,
    ACTION_CRAWLER_MINE_REFIXATE,
    ACTION_CRAWLER_MINE_DISSAPEAR,
    ACTION_THRALL_UNLEASHED,
    ACTION_THRALL_KNELL,
    ACTION_RESET_YSHAARJ_TIMER,
    ACTION_OVERCHARGE_WEAPON,
    ACTION_REMOVE_REAVE,
    ACTION_LAUNCH_IRON_STAR,
    ACTION_AQUEOUS_DEFENDERS,
    ACTION_CORRUPTED_SKULLSPLITTER,
    ACTION_CAGE_PRISONERS_INTRO,
    ACTION_GAMON_OUTRO,
};

enum iType
{
    TYPE_CONVEYOR_LENGTH = 1,
    TYPE_CONVEYOR_WEAPON_DESTROYED,
    TYPE_LASER_TARGET_GUID,
    TYPE_KLAXXI_DEATH,
    TYPE_KLAXXI_EVADE,
    TYPE_KLAXXI_AIM_TARGET,
    TYPE_KLAXXI_AIM_COUNT,
    TYPE_CALCULATE,
    TYPE_DEVOUR,
    TYPE_GARROSH_REALM,
    TYPE_SWIRL,
    TYPE_BOND_OF_LOTUS,
    TYPE_ORB_POS,
    TYPE_PRISON_CONE_ACTIVATED,
    TYPE_PRISON_ID,
    TYPE_CUTTER_LASER,
    TYPE_LIGHT_ORB,
    TYPE_LIGHT_ORB_SLOT,
    TYPE_ARCING_SMASH,
    TYPE_LEVER_DATA,
    TYPE_LEVER_POWER,
    TYPE_BLOOD_FRENZY,
    TYPE_LAUNCH_SAWBLADE,
    TYPE_BLIND_HATRED,
    TYPE_MANTID_SWARM_COUNT,
    TYPE_RETURN_TO_STONE_VALUE,
    TYPE_CURRENT_VOICE_CHOISE,
    TYPE_DEFENSE_SYSTEM_ACTIVE,
    TYPE_CRAWLER_MINE_DETONATE,
    TYPE_LASSER_TURRET_USING,
    TYPE_ICHOR_OF_YSHAARJ_COUNT,
    TYPE_FLASH_DATA,
    TYPE_GARROSH_FIRST_TRANSITION,
    TYPE_GARROSH_STRIKE_COUNT,
    TYPE_EXPLOSIVE_DESPAIR,
    TYPE_CALAMITY_OVERPOWER,
    TYPE_ALLOW_SAWBLADE_EFF,
    TYPE_NONE_SHALL_PASS,
    TYPE_OVERCHARGE_WEAPON,
    TYPE_NOT_IN_CONVEYOR_LINE,
    TYPE_SAW_TRAJ,
    TYPE_EERIE_FOG_DELAY,
    TYPE_SLINGER_IN_TOWER,
    TYPE_CLUMP_CHECK_DONE,
    TYPE_IRON_STAR_EXPLOSIVE,
    TYPE_VAMPIRIC_FRENZY,
    TYPE_ALLOW_IRON_STAR_EXPLOSIVE,
    TYPE_GEYSER_CAST_SUCCESS,
    TYPE_ALLOW_DETONATE_CRAWLER_MINE,
    TYPE_SUPERHEATED_MINE_STOMP,
    TYPE_EMBODIED_TRIGGER,
    TYPE_NO_MORE_TEARS,
    TYPE_GO_LONG,
    TYPE_GO_LONG_CLEAR,
    TYPE_CRISS_CROSS,
    TYPE_GIANT_SNAIL_LOCKED_COUNT,
    TYPE_REACH_NAZGRIM,
};

enum iGameObjects
{
    GO_SHA_FIELD                       = 221611,
    GO_IMMERSEUS_DOOR                  = 221245,
    GO_MASSIVE_ANCIENT_DOOR            = 221663,
    GO_SHA_ENERGY_WALL                 = 221602,
    GO_GARROSH_SOUTH_WEST_DOOR         = 221440,
    GO_GARROSH_SOUTH_EAST_DOOR         = 221439,
    GO_GARROSH_SHA_VORTEX              = 221132,
    GO_MYSTERIOUS_ORNATE_DOOR          = 221620,
    GO_TEARS_OF_THE_VALE_HC            = 233028, // Loot chest.
    GO_TEARS_OF_THE_VALE               = 232092,

    // Norushen - Quarantine Zone
    GO_NORUSHEN_LIGHT_CONTAIN_WALL1    = 223142,
    GO_NORUSHEN_LIGHT_CONTAIN_WALL2    = 223143,
    GO_NORUSHEN_LIGHT_CONTAIN_WALL3    = 223144,
    GO_NORUSHEN_LIGHT_CONTAIN_WALL4    = 223145,
    GO_NORUSHEN_LIGHT_CONTAIN_CEIL     = 223146,
    GO_NORUSHEN_LIGHT_CONTAIN_FLOOR    = 223147,
    GO_NORUSHEN_EXIT                   = 221447,
    GO_PRIDE_ENTRANCE                  = 221446,

    // Sha of Pride - Prisons
    GO_N_PRISON_FLOOR                  = 221677,
    GO_S_PRISON_FLOOR                  = 221679,
    GO_E_PRISON_FLOOR                  = 221678,
    GO_W_PRISON_FLOOR                  = 221676,
    GO_PRISON_FLOOR                    = 222679,

    // North
    GO_NORTH_PRISON_A                  = 221755,
    GO_NORTH_PRISON_B                  = 221750,
    GO_NORTH_PRISON_C                  = 221754,

    // South
    GO_SOUTH_PRISON_A                  = 221761,
    GO_SOUTH_PRISON_B                  = 221760,
    GO_SOUTH_PRISON_C                  = 221756,

    // East
    GO_EAST_PRISON_A                   = 221753,
    GO_EAST_PRISON_B                   = 221751,
    GO_EAST_PRISON_C                   = 221752,

    // West
    GO_WEST_PRISON_A                   = 221758,
    GO_WEST_PRISON_B                   = 221759,
    GO_WEST_PRISON_C                   = 221757,

    GO_VAULT_OF_FORBIDDEN_TREASURES    = 232164,
    GO_VAULT_OF_FORBIDDEN_TREASURES_HC = 233029,

    // Galakras
    GO_PORTCULLIS                      = 223044,

    // Iron Juggernaut
    GO_THE_GATES_OF_ORGRIMMAR          = 223739,

    GO_JUGGERNAUT_WIND_DOOR            = 223219,
    GO_NAZGRIM_ENTRY_DOOR              = 223276,
    GO_NAZGRIM_EXIT_DOOR               = 221793,
    GO_RUSTED_IRON_PORTCULLIS          = 223231,
    GO_DARK_SHAMANS_FRONTGATE          = 223814,
    GO_KORKRON_CAGE                    = 221563,
    GO_KORKRON_CAGE_2                  = 221564,
    GO_IRON_TOMB                       = 220864,

    // Malkorok
    GO_JAGGED_IRON_GATE_ENTRANCE       = 221784,
    GO_JAGGED_IRON_GATE_EXIT           = 221785,

    // Spoils of Pandaria
    GO_SECURED_STOCKPILE_OF_SPOILS     = 220823,
    GO_SPOILS_CHEST                    = 232166,
    GO_SPOILS_CHEST_HC                 = 233030,
    GO_SPOILS_IRON_GATE_1              = 221800,
    GO_SPOILS_IRON_GATE_2              = 221801,
    GO_SPOILS_IRON_GATE_3              = 221798,
    GO_SPOILS_IRON_GATE_4              = 221799,
    GO_MASSIVE_IRONBOUND_DOOR          = 223058,
    GO_SPOILS_ACCESS_LOW_LEFT          = 221796,
    GO_SPOILS_ACCESS_LOW_RIGHT         = 221797,
    GO_SPOILS_ACCESS_HIGH_RIGHT        = 221794,
    GO_SPOILS_ACCESS_HIGH_LEFT         = 221795,
    GO_SPOILS_CROSS_RIGHT              = 223032,
    GO_SPOILS_CROSS_LEFT               = 223033,
    GO_MANTID_LOW_BOX_1                = 221806,
    GO_MANTID_LOW_BOX_2                = 221808,
    GO_MANTID_LOW_BOX_3                = 221809,
    GO_MANTID_LOW_BOX_4                = 221810,
    GO_MANTID_LOW_BOX_5                = 221812,
    GO_MANTID_LOW_BOX_6                = 221813,
    GO_MANTID_LOW_BOX_7                = 221814,
    GO_MANTID_LOW_BOX_8                = 221815,
    GO_MANTID_LOW_BOX_9                = 221818,
    GO_MANTID_LOW_BOX_10               = 221819,
    GO_MANTID_LOW_BOX_11               = 221822,
    GO_MANTID_LOW_BOX_12               = 221823,
    GO_MANTID_LOW_BOX_13               = 221824,
    GO_MANTID_LOW_BOX_14               = 221826,
    GO_MANTID_LOW_BOX_15               = 221827,
    GO_MANTID_LOW_BOX_16               = 221828,
    GO_MANTID_LOW_BOX_17               = 221829,
    GO_MANTID_LOW_BOX_18               = 221854,
    GO_MANTID_LOW_BOX_19               = 221856,
    GO_MANTID_LOW_BOX_20               = 221858,
    GO_MANTID_LOW_BOX_21               = 221861,
    GO_MANTID_LOW_BOX_22               = 221862,
    GO_MANTID_LOW_BOX_23               = 221863,
    GO_MANTID_LOW_BOX_24               = 221864,
    GO_MANTID_LOW_BOX_25               = 221865,
    GO_MANTID_LOW_BOX_26               = 221866,
    GO_MANTID_LOW_BOX_27               = 221868,
    GO_MANTID_LOW_BOX_28               = 221869,
    GO_MANTID_LOW_BOX_29               = 221870,
    GO_MANTID_LOW_BOX_30               = 221871,
    GO_MANTID_LOW_BOX_31               = 221872,
    GO_MANTID_LOW_BOX_32               = 221873,
    GO_MANTID_LOW_BOX_33               = 221876,
    GO_MANTID_LOW_BOX_34               = 221877,
    GO_MANTID_LOW_BOX_35               = 223224,
    GO_MANTID_LOW_BOX_36               = 223245,
    GO_MANTID_MIDDLE_BOX_1             = 221802,
    GO_MANTID_MIDDLE_BOX_2             = 221811,
    GO_MANTID_MIDDLE_BOX_3             = 221816,
    GO_MANTID_MIDDLE_BOX_4             = 221817,
    GO_MANTID_MIDDLE_BOX_5             = 221820,
    GO_MANTID_MIDDLE_BOX_6             = 221821,
    GO_MANTID_MIDDLE_BOX_7             = 221853,
    GO_MANTID_MIDDLE_BOX_8             = 221857,
    GO_MANTID_MIDDLE_BOX_9             = 221860,
    GO_MANTID_MIDDLE_BOX_10            = 221867,
    GO_MANTID_MIDDLE_BOX_11            = 221874,
    GO_MANTID_MIDDLE_BOX_12            = 221875,
    GO_MANTID_HIGH_BOX_1               = 221804,
    GO_MANTID_HIGH_BOX_2               = 221825,
    GO_MANTID_HIGH_BOX_3               = 221855,
    GO_MANTID_HIGH_BOX_4               = 221859,

    GO_MOGU_LOW_BOX_1                  = 221807,
    GO_MOGU_LOW_BOX_2                  = 221832,
    GO_MOGU_LOW_BOX_3                  = 221833,
    GO_MOGU_LOW_BOX_4                  = 221835,
    GO_MOGU_LOW_BOX_5                  = 221836,
    GO_MOGU_LOW_BOX_6                  = 221837,
    GO_MOGU_LOW_BOX_7                  = 221839,
    GO_MOGU_LOW_BOX_8                  = 221840,
    GO_MOGU_LOW_BOX_9                  = 221841,
    GO_MOGU_LOW_BOX_10                 = 221842,
    GO_MOGU_LOW_BOX_11                 = 221843,
    GO_MOGU_LOW_BOX_12                 = 221844,
    GO_MOGU_LOW_BOX_13                 = 221845,
    GO_MOGU_LOW_BOX_14                 = 221846,
    GO_MOGU_LOW_BOX_15                 = 221847,
    GO_MOGU_LOW_BOX_16                 = 221848,
    GO_MOGU_LOW_BOX_17                 = 221851,
    GO_MOGU_LOW_BOX_18                 = 221852,
    GO_MOGU_LOW_BOX_19                 = 221882,
    GO_MOGU_LOW_BOX_20                 = 221883,
    GO_MOGU_LOW_BOX_21                 = 221884,
    GO_MOGU_LOW_BOX_22                 = 221886,
    GO_MOGU_LOW_BOX_23                 = 221894,
    GO_MOGU_LOW_BOX_24                 = 221896,
    GO_MOGU_LOW_BOX_25                 = 221898,
    GO_MOGU_LOW_BOX_26                 = 221900,
    GO_MOGU_LOW_BOX_27                 = 221901,
    GO_MOGU_LOW_BOX_28                 = 221902,
    GO_MOGU_LOW_BOX_29                 = 221903,
    GO_MOGU_LOW_BOX_30                 = 221904,
    GO_MOGU_LOW_BOX_31                 = 221905,
    GO_MOGU_LOW_BOX_32                 = 221906,
    GO_MOGU_LOW_BOX_33                 = 221907,
    GO_MOGU_LOW_BOX_34                 = 221908,
    GO_MOGU_LOW_BOX_35                 = 221909,
    GO_MOGU_LOW_BOX_36                 = 221910,
    GO_MOGU_MIDDLE_BOX_1               = 221805,
    GO_MOGU_MIDDLE_BOX_2               = 221830,
    GO_MOGU_MIDDLE_BOX_3               = 221834,
    GO_MOGU_MIDDLE_BOX_4               = 221838,
    GO_MOGU_MIDDLE_BOX_5               = 221849,
    GO_MOGU_MIDDLE_BOX_6               = 221850,
    GO_MOGU_MIDDLE_BOX_7               = 221887,
    GO_MOGU_MIDDLE_BOX_8               = 221888,
    GO_MOGU_MIDDLE_BOX_9               = 221889,
    GO_MOGU_MIDDLE_BOX_10              = 221890,
    GO_MOGU_MIDDLE_BOX_11              = 221892,
    GO_MOGU_MIDDLE_BOX_12              = 221893,
    GO_MOGU_HIGH_BOX_1                 = 221803,
    GO_MOGU_HIGH_BOX_2                 = 221831,
    GO_MOGU_HIGH_BOX_3                 = 221885,
    GO_MOGU_HIGH_BOX_4                 = 221891,
    GO_DEFENSE_SYSTEM_LEVER_LOW_RIGHT  = 221771,
    GO_DEFENSE_SYSTEM_LEVER_UP_RIGHT   = 221772,
    GO_DEFENSE_SYSTEM_LEVER_UP_LEFT    = 221773,
    GO_DEFENSE_SYSTEM_LEVER_LOW_LEFT   = 221774,
    NPC_CRATE_OF_PANDAREN_RELIC_1      = 222694, // tank role
    NPC_CRATE_OF_PANDAREN_RELIC_2      = 221881, // dps role
    NPC_CRATE_OF_PANDAREN_RELIC_3      = 222691, // healer role
    NPC_CRATE_OF_PANDAREN_RELIC_4      = 221880, // healer role
    NPC_CRATE_OF_PANDAREN_RELIC_5      = 221879, // dps role
    NPC_CRATE_OF_PANDAREN_RELIC_6      = 222693, // healer role
    NPC_CRATE_OF_PANDAREN_RELIC_7      = 222692, // tank role
    NPC_CRATE_OF_PANDAREN_RELIC_8      = 221878, // healer role


    // Thok Bloodthirsty
    GO_REX_DOOR                        = 223222,
    GO_THOK_ENTRANCE                   = 223805,
    GO_JINYU_PRISON                    = 222011,
    GO_JINYU_PRISON_2                  = 222010,
    GO_SAUROK_PRISON                   = 222047,
    GO_SAUROK_PRISON_2                 = 222046,
    GO_YAUNGOL_PRISON                  = 223005,
    GO_YAUNGOL_PRISON_2                = 223006,
    GO_THOK_ICE_TOMB                   = 218627,
    GO_YETI_CAGE                       = 222041,
    GO_BAT_CAGE_1                      = 222042,
    GO_BAT_CAGE_2                      = 222045,
    GO_BAT_CAGE_3                      = 222044,
    GO_BAT_CAGE_4                      = 222043,
    GO_THRICE_LOCKED_CAGE              = 222030,

    // Siegecrafter Blackfuse
    GO_MASSIVE_IRON_DOOR_BLACKFUSE     = 223057,

    // Paragon of the Klaxxi
    GO_PARAGON_ENTRANCE                = 221912,
    GO_PARAGON_ARENA_WALL              = 221264,
    GO_PARAGON_EXIT                    = 223235,
    GO_ENCASE_IN_AMBER                 = 220348,

    // Garrosh Hellscream
    GO_ENTRANCE_RIGHT                  = 221441,
    GO_ENTRANCE_LEFT                   = 221438,
    GO_HEART_OF_YSHAARJ                = 221995,
};

enum eFallenProtectors
{
    ROOK_STONETOE,
    HE_SOFTFOOT,
    SUN_THUNDERHEART
};

enum eKorkronDarkShamans
{
    EARTHBREAKER_HAROMM,
    WAVEBINDER_KARDIS
};

enum pSpells
{
    SHIELD_OF_RIGHTEOUS   = 132403,
    SHIELD_BLOCK          = 132404,
    SPELL_BLOOD_SHIELD    = 77535,
    SPELL_SHUFFLE         = 115307,
    SPELL_SAVAGE_DEFENCE  = 132402,
    SPELL_SHIELD_BARRIER  = 112048,

    // Misc
    SPELL_PRESSURE_PLATE  = 147626,
    SPELL_SIMPLE_TELEPORT = 105315,
};

enum Scenes
{
    SCENE_SCARED_VALE = 274, // PackageID 564
    SCENE_BLACKFUSE   = 272, // PackageID 562
};

enum InstanceEvents
{
    INSTANCE_EVENT_SCARRED_VALE = 37642,
    INSTANCE_EVENT_GAMON        = 37287,
};

enum InstanceWorldStates
{
    WORLDSTATE_CANNONS_REMAINING             = 8414,
    WORLDSTATE_CANNONS_REMAINING_COUNT       = 8373,
    WORLDSTATE_SOUTH_TOWER_PROGRESS          = 8545,
    WORLDSTATE_SOUTH_TOWER_PROGRESS_COUNT    = 8461,
    WORLDSTATE_NORTH_TOWER_PROGRESS          = 8547,
    WORLDSTATE_NORTH_TOWER_PROGRESS_COUNT    = 8462,
    WORLDSTATE_SOUTH_TOWER_INFLUENCE         = 8546,
    WORLDSTATE_SOUTH_TOWER_INFLUENCE_COUNT   = 8468,
    WORLDSTATE_NORTH_TOWER_INFLUENCE         = 8548,
    WORLDSTATE_NORTH_TOWER_INFLUENCE_COUNT   = 8469,
    WORLDSTATE_DEFENSE_SYSTEM                = 8431,
    WORLDSTATE_DEFENSE_SYSTEM_COUNT          = 8381,

    // Achievements
    WORLDSTATE_NO_MORE_TEARS                 = 14463,
    WORLDSTATE_IMMORTAL_VANGUARD             = 14372,
    WORLDSTATE_LASERS_MAGNITES_NOT_LASER     = 14397,
    WORLDSTATE_LASERS_MAGNITES_NOT_MAGNET    = 14398,
    WORLDSTATE_LASERS_MAGNITES_NOT_SHOCKWAVE = 14399,
    WORLDSTATE_LASERS_MAGNITES_NOT_MINES     = 14400,
    WORLDSTATE_SHALLOW_YOUR_PRIDE            = 13918,
    WORLDSTATE_SHALLOW_YOUR_PRIDE_ADDITIONAL = 14401,
    WORLDSTATE_FIRE_IN_THE_HALL              = 14307,
    WORLDSTATE_RESCUE_RAIDERS                = 14208,
    WORLDSTATE_GAMON_WILL_SAVE_US            = 14284,
    WORLDSTATE_GAMON_WILL_SAVE_US_2          = 14185,
    WORLDSTATE_UNLIMITED_POTENTIAL           = 14396,
    WORLDSTATE_UNLIMITED_POTENTIAL_2         = 13918,
    WORLDSTATE_CRISS_CROSS                   = 14497,
    WORLDSTATE_STRIKE                        = 14469,
    WORLDSTATE_STRIKE_2                      = 14616,
};

const std::vector<uint32> eParagonsOfTheKlaaxi
{
    NPC_KILRUK_THE_WIND_REAVER,
    NPC_XARIL_THE_POISONED_MIND,
    NPC_KAZTIK_THE_MANIPULATOR,
    NPC_KORVEN_THE_PRIME,
    NPC_IYYOKUK_THE_LUCID,
    NPC_KAROZ_THE_LOCUST,
    NPC_SKEER_THE_BLOODSEEKER,
    NPC_RIKKAL_THE_DISSECTOR,
    NPC_HISEK_THE_SWARMKEEPER,
};

// Tank Abilities for dodge some mechanic
const std::vector<uint32> eProtectiveSpells
{
    SHIELD_OF_RIGHTEOUS, // prot paladin
    SHIELD_BLOCK, // prot warrior
    SPELL_SHIELD_BARRIER, // prot warrior
    SPELL_BLOOD_SHIELD, // Death Knight
    SPELL_SHUFFLE, // Monk
    SPELL_SAVAGE_DEFENCE, // Guard
};

// Cho events by any part of Instance
const std::map<uint32, uint32> invChoEventsType =
{
    { NPC_IMMERSEUS,      ACTION_IMMERSIUS_DEFEAT },
    { NPC_PRESSURE_PLATE, ACTION_SCARRED_VALE     },
};

enum RaidFinder
{
    QUARTER_NONE                        = 0,
    QUARTER_VALE_OF_ETERNAL_SORROWS     = 716,
    QUARTER_GATES_OF_RETRIBUTION        = 717,
    QUARTER_THE_UNDERHOLD               = 724,
    QUARTER_DOWNFALL                    = 725,
    QUARTER_VALE_OF_ETERNAL_SORROWS_F   = 726,
    QUARTER_GATES_OF_RETRIBUTION_F      = 728,
    QUARTER_THE_UNDERHOLD_F             = 729,
    QUARTER_DOWNFALL_F                  = 730,
};

// just for enum
const std::vector<uint64> firstLaserWaveGUIDs
{
    561193,
    561190,
    561192,
    561194,
    561191,
};

const std::vector<uint64> secondLaserWaveGUIDs
{
    561196,
    561198,
    561197,
    561199,
    561195,
};

const std::vector<uint64> thirdLaserWaveGUIDs
{
    561200,
    561202,
    561204,
    561201,
    561203,
};

const std::map<uint32, uint32> goldenLotusCorrupedType =
{
    { NPC_GOLDEN_LOTUS_TRIGGER_1, NPC_EMBODIED_SORROW },
    { NPC_GOLDEN_LOTUS_TRIGGER_2, NPC_EMBODIED_GLOOM  },
    { NPC_GOLDEN_LOTUS_TRIGGER_3, NPC_EMBODIED_MISERY },
};

#endif // SIEGE_OF_ORGRIMMAR_H_
