/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: HyjalAI
SD%Complete: 90
SDComment:
SDCategory: Caverns of Time, Mount Hyjal
EndScriptData */

#include "ScriptPCH.h"
#include "hyjalAI.h"
#include "hyjal_trash.h"
#include "MapManager.h"
#include "Language.h"
#include "Chat.h"
#include "Object.h"

#define SPAWN_GARG_GATE 0
#define SPAWN_WYRM_GATE 1
#define SPAWN_NEAR_TOWER 2

#define YELL_HURRY  "Hurry, we don't have much time"

// Locations for summoning gargoyls and frost wyrms in special cases
float SpawnPointSpecial[3][3]=
{
    {5497.08f,    -2493.23f,    1535.72f}, //spawn point for the gargoyles near the horde gate
    {5624.53f,    -2548.12f,    1551.54f}, //spawn point for the frost wyrm near the horde gate
    {5604.41f,   -2811.98f,   1547.77f}  //spawn point for the gargoyles and wyrms near the horde tower
};

// Locations for summoning waves in Alliance base
float AllianceBase[4][3]=
{
    {4928.48f,    -1526.38f,    1326.83f},
    {4923.54f,    -1514.29f,    1327.98f},
    {4928.41f,    -1510.35f,    1327.99f},
    {4938.35f,    -1521.00f,    1326.69f}
};

float JainaDummySpawn[2][4]=
{
    {5497.01f, -2719.03f, 1483.08f, 2.90426f},
    {5484.98f, -2721.69f, 1483.39f, 6.00656f}
};

// Locations for summoning waves in Horde base
float HordeBase[4][3]=
{
    {5458.01f,    -2340.27f,    1459.60f},
    {5466.01f,    -2334.69f,    1460.06f},
    {5468.45f,    -2355.13f,    1459.99f},
    {5479.06f,    -2344.16f,    1461.74f}
};

// Lady Jaina's waypoints when retreathing
float JainaWPs[2][3]=
{
    {5078.56f,    -1789.79f,    1320.73f}, //next to the small stairs
    {5037.38f,    -1778.39f,    1322.61f}, //center of alliance base
};

float InfernalPos[8][3]=//spawn points for the infernals in the horde base
{
    {5453.59f,    -2764.52f,    1493.50f},
    {5478.4f,    -2781.77f,    1497.52f},
    {5506.09f,    -2780.53f,    1496.32f},
    {5532.1f,    -2763.42f,    1492.37f},
    {5544.16f,    -2733.99f,    1487.14f},
    {5536.19f,    -2708.18f,    1480.01f},
    {5510.16f,    -2691.75f,    1479.66f},
    {5482.39f,    -2689.19f,    1481.09f}
};

float InfernalSPWP[26][4]=//spawn points for the infernals in the horde base used in the cleaning wave
{
    {5490.96f, -2718.72f, 1482.96f, 0.49773f},
    {5449.51f, -2723.32f, 1485.69f, 2.69685f},
    {5520.83f, -2624.68f, 1483.82f, 1.20459f},
    {5558.28f, -2629.26f, 1485.76f, 0.37992f},
    {5567.97f, -2758.69f, 1494.10f, 5.04125f},
    {5384.90f, -2793.47f, 1503.90f, 5.55412f},
    {5495.33f, -2814.06f, 1501.56f, 1.12055f},
    {5472.63f, -2929.39f, 1538.31f, 1.95777f},
    {5334.72f, -2952.29f, 1534.34f, 0.50869f},
    {5398.36f, -2872.46f, 1512.38f, 0.76787f},
    {5514.39f, -2768.63f, 1492.30f, 1.55721f},
    {5598.91f, -2703.75f, 1495.64f, 2.56644f},
    {5467.80f, -2655.93f, 1482.27f, 0.85819f},
    {5399.83f, -2985.24f, 1545.04f, 5.92559f},
    {5232.13f, -2967.05f, 1553.09f, 5.41351f},
    {5272.02f, -3082.52f, 1567.09f, 3.40681f},
    {5343.26f, -3120.71f, 1582.92f, 3.16727f},
    {5371.26f, -3175.24f, 1587.41f, 6.10466f},
    {5434.67f, -3177.91f, 1579.25f, 2.77850f},
    {5237.39f, -3149.25f, 1593.59f, 0.83855f},
    {5202.15f, -3016.64f, 1566.28f, 3.31256f},
    {5302.54f, -2914.37f, 1528.53f, 3.37146f},
    {5439.04f, -2834.81f, 1508.80f, 2.14231f},
    {5421.33f, -2771.04f, 1494.28f, 6.06223f},
    {5549.76f, -2692.93f, 1482.68f, 2.19414f},
    {5459.78f, -2755.71f, 1490.68f, 1.05139f}
};

float VeinPos[14][8]=//spawn points of the ancient gem veins
{
    {5184.84f,    -1982.59f,    1382.66f,    2.58079f,    0,    0,    0.960944f,    0.276742f},  //alliance
    {5107.66f,    -2071.16f,    1368.37f,    2.65148f,    0,    0,    0.970124f,    0.242611f},    //alliance
    {5040.53f,    -2227.65f,    1403.17f,    3.35049f,    0,    0,    0.99455f,    -0.104257f},    //alliance
    {5187.59f,    -2453.12f,    1455.51f,    5.87943f,    0,    0,    0.20051f,    -0.979692f},    //alliance
    {5429.43f,    -2340.65f,    1465.38f,    4.7681f,        0,    0,    0.687138f,    -0.726527f},    //alliance
    {5463.99f,    -2315.95f,    1470.29f,    1.52045f,    0,    0,    0.689084f,    0.724682f},    //alliance
    {5624.65f,    -2495.09f,    1510.11f,    0.0124869f,    0,    0,    0.00624342f,    0.999981f},    //alliance
    {5285.41f,    -3348.32f,    1663.01f,    1.57152f,    0,    0,    0.707362f,    0.706852f},    //horde
    {5417.69f,    -3372.52f,    1656.31f,    0.361993f,    0,    0,    0.18001f,    0.983665f},    //horde
    {5315.34f,    -3238.32f,    1622.88f,    3.03627f,    0,    0,    0.998614f,    0.0526347f},    //horde
    {5303.4f,    -3096.44f,    1596.41f,    1.72073f,    0,    0,    0.758081f,    0.65216f},    //horde
    {5265.13f,    -3177.27f,    1616.22f,    0.813604f,    0,    0,    0.395674f,    0.918391f},    //horde
    {5374.3f,    -3420.59f,    1653.43f,    1.45762f,    0,    0,    0.665981f,    0.745969f},    //horde
    {5441.54f,    -3321.59f,    1651.55f,    0.258306f,    0,    0,    0.128794f,    0.991671f}   //horde
};

float AllianceOverrunGargPos[5][4]=//gargoyle spawn points in the alliance overrun
{
    {5279.94f, -2049.68f, 1311.38f, 0}, //garg1
    {5289.15f, -2219.06f, 1291.12f, 0}, //garg2
    {5202.07f, -2136.10f, 1305.07f, 2.8f}, //garg3
    {5071.52f, -2425.63f, 1454.48f, 5.54f}, //garg4
    {5120.65f, -2467.92f, 1463.93f, 2.54f}//garg5
};

float AllianceFirePos[92][8]=//spawn points for the fire visuals (GO) in the alliance base
{
    {5039.9f,    -1796.84f,    1323.88f,    2.59222f,    0,    0,    0.962511f,    0.271243f},
    {5087.2f,    -1795.2f,    1320.68f,    1.03946f,    0,    0,    0.496644f,    0.867954f},
    {5112.68f,    -1806.66f,    1359.93f,    1.37799f,    0,    0,    0.63576f,    0.771887f},
    {5095.61f,    -1793.27f,    1359.78f,    0.580806f,    0,    0,    0.286338f,    0.958129f},
    {5090.43f,    -1784.45f,    1360.44f,    0.796784f,    0,    0,    0.387937f,    0.921686f},
    {5139.25f,    -1783.11f,    1359.39f,    3.30849f,    0,    0,    0.99652f,    -0.0833509f},
    {5112.16f,    -1763.72f,    1361.35f,    5.10312f,    0,    0,    0.556388f,    -0.830922f},
    {4981.18f,    -1793.98f,    1335.7f,        3.23072f,    0,    0,    0.999007f,    -0.0445498f},
    {4996.57f,    -1766.75f,    1341.62f,    3.5331f,        0,    0,    0.980902f,    -0.194505f},
    {4983.74f,    -1769.25f,    1345.75f,    3.79228f,    0,    0,    0.947541f,    -0.319635f},
    {4996.01f,    -1774.43f,    1330.71f,    3.07364f,    0,    0,    0.999423f,    0.0339693f},
    {5094.2f,    -1726.13f,    1330.55f,    1.56175f,    0,    0,    0.703901f,    0.710298f},
    {5079.82f,    -1721.24f,    1336.26f,    1.18868f,    0,    0,    0.559964f,    0.828517f},
    {5077.68f,    -1717.15f,    1327.78f,    0.0145145f,    0,    0,    0.00725717f,    0.999974f},
    {5122.27f,    -1738.22f,    1341.67f,    0.835256f,    0,    0,    0.405593f,    0.914054f},
    {5131.88f,    -1741.15f,    1335.25f,    2.15472f,    0,    0,    0.880712f,    0.473653f},
    {5196.93f,    -1772.99f,    1345.2f,        0.128397f,    0,    0,    0.0641544f,    0.99794f},
    {5225.33f,    -1756.06f,    1344.17f,    3.04223f,    0,    0,    0.998766f,    0.0496599f},
    {5224.84f,    -1767.05f,    1360.06f,    3.19538f,    0,    0,    0.999638f,    -0.0268922f},
    {5202.05f,    -1763.47f,    1361.68f,    2.59455f,    0,    0,    0.962826f,    0.270122f},
    {5194.74f,    -1766.66f,    1356.94f,    0.0734191f,    0,    0,    0.0367013f,    0.999326f},
    {5159.67f,    -1832.97f,    1344.5f,        5.17457f,    0,    0,    0.526356f,    -0.850264f},
    {5096.17f,    -1858.73f,    1332.46f,    5.30021f,    0,    0,    0.471939f,    -0.881631f},
    {5110.7f,    -1856.59f,    1342.84f,    5.97564f,    0,    0,    0.153167f,    -0.9882f},
    {5109.76f,    -1855.3f,    1332.38f,    4.89572f,    0,    0,    0.639411f,    -0.768865f},
    {5068.95f,    -1837.37f,    1328.81f,    2.61569f,    0,    0,    0.965628f,    0.25993f},
    {5064.4f,    -1824.77f,    1329.02f,    2.16409f,    0,    0,    0.88292f,    0.469524f},
    {5059.89f,    -1848.79f,    1329.59f,    0.0709955f,    0,    0,    0.0354903f,    0.99937f},
    {5014.37f,    -1851.39f,    1322.56f,    4.66949f,    0,    0,    0.722111f,    -0.691777f},
    {5025.1f,    -1848.27f,    1323.39f,    4.44565f,    0,    0,    0.794854f,    -0.606801f},
    {4942.63f,    -1890.13f,    1326.59f,    3.28719f,    0,    0,    0.997351f,    -0.0727343f},
    {4937.95f,    -1888.71f,    1352.41f,    3.41678f,    0,    0,    0.990549f,    -0.13716f},
    {4922.48f,    -1881.92f,    1352.41f,    5.03077f,    0,    0,    0.586075f,    -0.810257f},
    {4915.35f,    -1894.32f,    1351.24f,    6.22457f,    0,    0,    0.0293048f,    -0.999571f},
    {4922.71f,    -1904.84f,    1352.56f,    1.37866f,    0,    0,    0.63602f,    0.771672f},
    {4932.89f,    -1905.49f,    1352.56f,    1.89702f,    0,    0,    0.812549f,    0.582893f},
    {5011.83f,    -1861.05f,    1345.86f,    4.43777f,    0,    0,    0.797239f,    -0.603664f},
    {5011.83f,    -1861.05f,    1363.26f,    4.748f,        0,    0,    0.694406f,    -0.719583f},
    {5021.46f,    -1858.35f,    1342.17f,    4.86188f,    0,    0,    0.652329f,    -0.757936f},
    {4995.02f,    -1698.3f,    1370.38f,    6.15779f,    0,    0,    0.0626579f,    -0.998035f},
    {5119.85f,    -1728.9f,    1336.04f,    5.87112f,    0,    0,    0.204579f,    -0.97885f},
    {5214.75f,    -1751.02f,    1342.5f,        5.08965f,    0,    0,    0.561972f,    -0.827156f},
    {5075.04f,    -1822.43f,    1328.87f,    3.99951f,    0,    0,    0.9094f,        -0.415924f},
    {5057.09f,    -1823.32f,    1350.35f,    3.88169f,    0,    0,    0.93231f,    -0.361659f},
    {4984.6f,    -1816.99f,    1329.21f,    3.05308f,    0,    0,    0.999021f,    0.0442417f},
    {4983.35f,    -1811.55f,    1356.82f,    3.33975f,    0,    0,    0.995096f,    -0.098917f},
    {4984.11f,    -1825.73f,    1350.76f,    2.26375f,    0,    0,    0.905211f,    0.424962f},
    {4968.47f,    -1786.46f,    1354.09f,    3.07663f,    0,    0,    0.999473f,    0.0324733f},
    {5061.82f,    -1751.16f,    1339.07f,    5.94727f,    0,    0,    0.167171f,    -0.985928f},
    {5063.75f,    -1763,        1351.91f,    0.759707f,    0,    0,    0.370784f,    0.928719f},
    {5078.65f,    -1708.26f,    1353.9f,        1.27022f,    0,    0,    0.593264f,    0.805008f},
    {4983.19f,    -1755.96f,    1331.13f,    4.28221f,    0,    0,    0.841733f,    -0.539894f},
    {4972.76f,    -1755.3f,    1332.5f,        4.21938f,    0,    0,    0.858276f,    -0.513188f},
    {4961.65f,    -1760.82f,    1351.69f,    3.56515f,    0,    0,    0.977659f,    -0.210198f},
    {5086.45f,    -1779.83f,    1321.62f,    6.23157f,    0,    0,    0.0258051f,    -0.999667f},
    {5063.15f,    -1756.74f,    1328.56f,    0.886926f,    0,    0,    0.42907f,    0.903271f},
    {5042.45f,    -1800.61f,    1323.88f,    2.50093f,    0,    0,    0.949131f,    0.31488f},
    {5084.74f,    -1725.35f,    1327.89f,    1.65034f,    0,    0,    0.734663f,    0.678432f},
    {4993.25f,    -1758.1f,    1331.07f,    3.49995f,    0,    0,    0.98399f,    -0.178223f},
    {5078.53f,    -1867.85f,    1348.91f,    5.85612f,    0,    0,    0.211913f,    -0.977288f},
    {5080.74f,    -1869.73f,    1333.18f,    6.18206f,    0,    0,    0.0505424f,    -0.998722f},
    {5089.55f,    -1894.13f,    1356.08f,    1.52072f,    0,    0,    0.689181f,    0.724589f},
    {5113.24f,    -1899.49f,    1363.77f,    1.50108f,    0,    0,    0.682034f,    0.731321f},
    {4984.18f,    -1907.69f,    1325.62f,    3.82193f,    0,    0,    0.942698f,    -0.333646f},
    {5094.14f,    -2432.08f,    1429.38f,    4.70083f,    0,    0,    0.711182f,    -0.703007f},
    {5329.89f,    -2113.30f,    1281.06f,    5.60560f,    0,    0,    0.332347f,    -0.943157f},
    {5170.87f,    -2148.13f,    1278.32f,    1.63540f,    0,    0,    0.729573f,    0.683903f },
    {5132.94f,    -1960.25f,    1367.8f,        3.69787f,    0,    0,    0.961568f,    -0.274566f},
    {5280.82f,    -2351.55f,    1431.57f,    4.46913f,    0,    0,    0.787677f,    -0.616088f},
    {5176.78f,    -2121.43f,    1295.27f,    3.24153f,    0,    0,    0.998752f,    -0.04995f},
    {5332.75f,    -2101.41f,    1296.37f,    5.50350f,    0,    0,    0.380043f,    -0.924969f},
    {5265.70f,    -2050.27f,    1287.57f,    0.50051f,    0,    0,    0.247655f,    0.968848f },
    {5194.21f,    -2129.89f,    1274.04f,    3.08053f,    0,    0,    0.999534f,    0.0305272f},
    {5225.81f,    -1985.50f,    1364.15f,    0.37247f,    0,    0,    0.185163f,    0.982708f },
    {5339.46f,    -2204.47f,    1280.45f,    0.99921f,    0,    0,    0.479081f,    0.877771f },
    {5269.63f,    -2020.57f,    1299.62f,    3.00201f,    0,    0,    0.997566f,    0.0697332f},
    {5111.54f,    -2445.70f,    1435.31f,    2.70983f,    0,    0,    0.976788f,    0.214207f },
    {5111.24f,    -1901.14f,    1355.33f,    1.61028f,    0,    0,    0.720929f,    0.693009f },
    {5310.42f,    -2207.82f,    1277.46f,    0.50441f,    0,    0,    0.249544f,    0.968363f },
    {5150.81f,    -2042.13f,    1394.3f,        2.21031f,    0,    0,    0.893534f,    0.448995f },
    {5224.84f,    -2376.61f,    1366.33f,    5.0621f,        0,    0,    0.573311f,    -0.819338f},
    {5105.41f,    -2454.86f,    1446.16f,    4.64584f,    0,    0,    0.730239f,    -0.683191f},
    {5309.65f,    -2188.28f,    1266.84f,    5.56631f,    0,    0,    0.350811f,    -0.936446f},
    {5281.46f,    -2047.82f,    1287.67f,    2.44909f,    0,    0,    0.940652f,    0.339373f },
    {5325.45f,    -2189.41f,    1309.6f,        6.23783f,    0,    0,    0.0226771f,    -0.999743f},
    {5190.96f,    -2142.54f,    1293.03f,    6.25668f,    0,    0,    0.0132544f,    -0.999912f},
    {5089.99f,    -2467.49f,    1441.8f,        0.77381f,    0,    0,    0.377326f,    0.92608f     },
    {5195.08f,    -2129.01f,    1285.36f,    3.55727f,    0,    0,    0.978480f,    -0.206344f},
    {5353.76f,    -2116.28f,    1299.27f,    6.17894f,    0,    0,    0.0521006f,    -0.998642f},
    {5271.14f,    -2037.38f,    1299.24f,    4.07879f,    0,    0,    0.892201f,    -0.451638f},
    {5332.5f    ,    -2181.28f,    1279.95f,    4.6906f,        0,    0,    0.714768f,    -0.699362f},
    {5108.2f    ,    -2429.84f,    1427.73f,    4.5194f,        0,    0,    0.771943f,    -0.635691f}
};

float HordeFirePos[65][8]=//spawn points for the fire visuals (GO) in the horde base
{
    {5524.11f,    -2612.73f,    1483.38f,    1.96198f,    0,    0,    0.831047f,    0.556202f},
    {5514.42f,    -2617.19f,    1505.77f,    1.82453f,    0,    0,    0.790892f,    0.611956f},
    {5510.21f,    -2624.77f,    1485.34f,    1.71065f,    0,    0,    0.754783f,    0.655974f},
    {5570.72f,    -2619.04f,    1487.62f,    0.728898f,    0,    0,    0.356435f,    0.93432f},
    {5570.29f,    -2639.37f,    1487.31f,    1.49308f,    0,    0,    0.679104f,    0.734042f},
    {5583.56f,    -2637.2f,    1503.78f,    1.46559f,    0,    0,    0.668951f,    0.743307f},
    {5571.53f,    -2626.81f,    1510.99f,    0.362107f,    0,    0,    0.180066f,    0.983654f},
    {5545.97f,    -2659.62f,    1489.64f,    5.07055f,    0,    0,    0.569845f,    -0.821752f},
    {5557.44f,    -2675.91f,    1482.58f,    1.70118f,    0,    0,    0.751671f,    0.659539f},
    {5594.98f,    -2742.31f,    1495.51f,    4.5993f,        0,    0,    0.74594f,    -0.666013f},
    {5599.65f,    -2755.6f,    1505.05f,    1.66896f,    0,    0,    0.740947f,    0.671564f},
    {5565.95f,    -2774.75f,    1499.48f,    6.22425f,    0,    0,    0.0294611f,    -0.999566f},
    {5567.1f,    -2769.7f,    1511.17f,    5.99257f,    0,    0,    0.144799f,    -0.989461f},
    {5572.84f,    -2774.16f,    1527.06f,    0.836428f,    0,    0,    0.406129f,    0.913816f},
    {5538.32f,    -2805.94f,    1498.87f,    4.30082f,    0,    0,    0.836674f,    -0.547701f},
    {5515.66f,    -2801.74f,    1503.53f,    5.57316f,    0,    0,    0.347602f,    -0.937642f},
    {5516.76f,    -2827.14f,    1501.15f,    0.35026f,    0,    0,    0.174236f,    0.984704f},
    {5536.13f,    -2813.51f,    1537.21f,    4.51681f,    0,    0,    0.772765f,    -0.634692f},
    {5525.05f,    -2825.16f,    1538.53f,    0.489275f,    0,    0,    0.242205f,    0.970225f},
    {5534.42f,    -2815.45f,    1562.84f,    4.62834f,    0,    0,    0.736191f,    -0.676774f},
    {5519.64f,    -2831.12f,    1526.46f,    0.611008f,    0,    0,    0.300774f,    0.953696f},
    {5551.04f,    -2827.55f,    1523.5f,        3.35206f,    0,    0,    0.994468f,    -0.10504f},
    {5469.22f,    -2802.87f,    1503.5f,        4.99509f,    0,    0,    0.600436f,    -0.799673f},
    {5427.8f,    -2737.26f,    1487.12f,    1.78673f,    0,    0,    0.779186f,    0.626793f},
    {5454.1f,    -2709.1f,    1485.92f,    3.03552f,    0,    0,    0.998594f,    0.0530137f},
    {5436.3f,    -2718.2f,    1506.02f,    2.7567f,        0,    0,    0.981539f,    0.191261f},
    {5412.6f,    -2740.55f,    1510.79f,    2.98446f,    0,    0,    0.996915f,    0.0784832f},
    {5406.12f,    -2752.48f,    1521.01f,    2.05769f,    0,    0,    0.856705f,    0.515807f},
    {5445.24f,    -2676.35f,    1521.89f,    2.91378f,    0,    0,    0.99352f,    0.113661f},
    {5481.4f,    -2665.08f,    1482.23f,    4.30001f,    0,    0,    0.836895f,    -0.547363f},
    {5443.51f,    -2675.44f,    1487.12f,    2.90986f,    0,    0,    0.993295f,    0.115606f},
    {5391.72f,    -2647.3f,    1528.9f,        3.76987f,    0,    0,    0.951063f,    -0.308997f},
    {5421.09f,    -2734.12f,    1521.01f,    2.70567f,    0,    0,    0.97634f,    0.216242f},
    {5405.39f,    -2710.33f,    1533.77f,    2.51324f,    0,    0,    0.951052f,    0.309032f},
    {5423.96f,    -2703.76f,    1516.34f,    2.79206f,    0,    0,    0.984767f,    0.173879f},
    {5444.75f,    -2735.23f,    1486.37f,    2.22657f,    0,    0,    0.897155f,    0.441715f},
    {5570.98f,    -2747.91f,    1495.7f,        5.14433f,    0,    0,    0.53915f,    -0.84221f},
    {5567.79f,    -2673.9f,    1484.66f,    2.72529f,    0,    0,    0.978415f,    0.20665f},
    {5600.71f,    -2696.8f,    1500.42f,    0.443704f,    0,    0,    0.220036f,    0.975492f},
    {5600.7f,    -2693.04f,    1515.2f,        5.16003f,    0,    0,    0.532522f,    -0.846416f},
    {5627.56f,    -2839.66f,    1510.53f,    5.41527f,    0,    0,    0.420463f,    -0.907309f},
    {5622.02f,    -2868.71f,    1516.22f,    2.25482f,    0,    0,    0.903303f,    0.429002f},
    {5586.61f,    -2878.97f,    1510.34f,    4.55604f,    0,    0,    0.76017f,    -0.649724f},
    {5583.78f,    -2843.71f,    1509.54f,    5.35715f,    0,    0,    0.44665f,    -0.894709f},
    {5580.95f,    -2811.3f,    1513.3f,        3.57587f,    0,    0,    0.976518f,    -0.215434f},
    {5542.52f,    -2869.31f,    1523.13f,    5.23304f,    0,    0,    0.501275f,    -0.865288f},
    {5557.35f,    -2866.36f,    1518.76f,    4.48299f,    0,    0,    0.783388f,    -0.621533f},
    {5380.91f,    -2849.36f,    1512.81f,    3.90962f,    0,    0,    0.927168f,    -0.374646f},
    {5395.76f,    -2881.41f,    1521.11f,    4.28426f,    0,    0,    0.84118f,    -0.540755f},
    {5374.87f,    -2859.63f,    1528.98f,    3.30252f,    0,    0,    0.996765f,    -0.0803745f},
    {5356.07f,    -2854.66f,    1520.34f,    5.83933f,    0,    0,    0.220108f,    -0.975475f},
    {5363.01f,    -2975.72f,    1539.02f,    4.13738f,    0,    0,    0.87859f,    -0.477576f},
    {5336.85f,    -2980.74f,    1561.24f,    5.11126f,    0,    0,    0.553001f,    -0.83318f},
    {5335.23f,    -2974.62f,    1540.05f,    5.04451f,    0,    0,    0.580496f,    -0.814263f},
    {5422.37f,    -2998.87f,    1549.98f,    4.51831f,    0,    0,    0.772288f,    -0.635272f},
    {5405.54f,    -3014.6f,    1562.16f,    5.86761f,    0,    0,    0.206298f,    -0.978489f},
    {5427.96f,    -3019.4f,    1561.58f,    3.53498f,    0,    0,    0.980718f,    -0.19543f},
    {5348.12f,    -2977.84f,    1582.47f,    3.94025f,    0,    0,    0.921323f,    -0.388799f},
    {5331.12f,    -2993.71f,    1576.14f,    0.0642734f,    0,    0,    0.0321311f,    0.999484f},
    {5321.63f,    -2986.55f,    1552.2f,        5.29503f,    0,    0,    0.474219f,    -0.880407f},
    {5292.1f,    -2914.36f,    1529.52f,    2.9742f,        0,    0,    0.996499f,    0.083601f},
    {5281.77f,    -2926.5f,    1530.62f,    1.67829f,    0,    0,    0.744071f,    0.6681f},
    {5287.19f,    -2909.94f,    1543.49f,    3.31192f,    0,    0,    0.996376f,    -0.0850591f},
    {5534.15f,    -2679.35f,    1483.61f,    0.428685f,    0,    0,    0.212705f,    0.977116f},
    {5545.43f,    -2647.82f,    1483.05f,    5.38848f,    0,    0,    0.432578f,    -0.901596f}
};

hyjalAI::hyjalAI(Creature* c) : npc_escortAI(c), Summons(me)
{
    pInstance = c->GetInstanceScript();
    VeinsSpawned[0] = false;
    VeinsSpawned[1] = false;
    for (uint8 i=0; i<14; ++i)
        VeinGUID[i] = 0;
    InfernalCount = 0;
    TeleportTimer = 1000;
    Overrun = false;
    Teleported = false;
    WaitForTeleport = false;
    OverrunCounter = 0;
    OverrunCounter2 = 0;
    InfernalPoint = 0;
    RespawnTimer = 10000;
    DoRespawn = false;
    DoHide = false;
    MassTeleportTimer = 0;
    DoMassTeleport = false;
}

void hyjalAI::JustSummoned(Creature* summoned)
{
    Summons.Summon(summoned);
}

void hyjalAI::SummonedCreatureDespawn(Creature* summoned)
{
    Summons.Despawn(summoned);
}

void hyjalAI::Reset()
{
    IsDummy = false;
    me->setActive(true);
    // GUIDs
    PlayerGUID = 0;
    BossGUID[0] = 0;
    BossGUID[1] = 0;

    // Timers
    NextWaveTimer = 10000;
    CheckTimer = 0;
    RetreatTimer = 1000;

    // Misc
    WaveCount = 0;
    EnemyCount = 0;

    // Set faction properly based on Creature entry
    switch (me->GetEntry())
    {
        case JAINA:
            Faction = 0;
            DoCast(me, SPELL_BRILLIANCE_AURA, true);
            break;

        case THRALL:
            Faction = 1;
            break;

        case TYRANDE:
            Faction = 2;
            break;
    }

    //Bools
    EventBegun = false;
    FirstBossDead = false;
    SecondBossDead = false;
    Summon = false;
    bRetreat = false;
    Debug = false;

    //Flags
    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

    //Initialize spells
    memset(Spells, 0, sizeof(Spell) * HYJAL_AI_MAX_SPELLS);

    //Reset Instance Data for trash count
    if (pInstance)
    {
        if ((!pInstance->GetData(DATA_ALLIANCE_RETREAT) && me->GetEntry() == JAINA) || (pInstance->GetData(DATA_ALLIANCE_RETREAT) && me->GetEntry() == THRALL))
        {
            //Reset World States
            pInstance->DoUpdateWorldState(WORLD_STATE_WAVES, 0);
            pInstance->DoUpdateWorldState(WORLD_STATE_ENEMY, 0);
            pInstance->DoUpdateWorldState(WORLD_STATE_ENEMYCOUNT, 0);
            pInstance->SetData(DATA_RESET_TRASH_COUNT, 0);
        }
    } else sLog->outError(ERROR_INST_DATA);

    //Visibility
    DoHide = true;
}

void hyjalAI::EnterEvadeMode()
{
    if (me->GetEntry() != JAINA)
        me->RemoveAllAuras();
    me->DeleteThreatList();
    me->CombatStop(true);
    me->LoadCreaturesAddon();

    if (me->isAlive())
        me->GetMotionMaster()->MoveTargetedHome();

    me->SetLootRecipient(NULL);
}

void hyjalAI::EnterCombat(Unit* /*who*/)
{
    if (IsDummy)return;
    for (uint8 i = 0; i < HYJAL_AI_MAX_SPELLS; ++i)
        if (Spells[i].Cooldown)
            SpellTimer[i] = Spells[i].Cooldown;

    Talk(ATTACKED);
}

void hyjalAI::MoveInLineOfSight(Unit* who)
{
    if (IsDummy)
        return;

    npc_escortAI::MoveInLineOfSight(who);
}

void hyjalAI::SummonCreature(uint32 entry, float Base[4][3])
{
    uint32 random = rand()%4;
    float SpawnLoc[3];

    for (uint8 i = 0; i < 3; ++i)
    {
        SpawnLoc[i] = Base[random][i];
    }
    Creature* creature = NULL;
    switch (entry)
    {
            case 17906:    //GARGOYLE

                if (!FirstBossDead && (WaveCount == 1 || WaveCount == 3))
                {//summon at tower
                    creature = me->SummonCreature(entry, SpawnPointSpecial[SPAWN_NEAR_TOWER][0]+irand(-20, 20), SpawnPointSpecial[SPAWN_NEAR_TOWER][1]+irand(-20, 20), SpawnPointSpecial[SPAWN_NEAR_TOWER][2]+irand(-10, 10), 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 120000);
                    if (creature)
                        CAST_AI(hyjal_trashAI, creature->AI())->useFlyPath = true;
                }else{//summon at gate
                    creature = me->SummonCreature(entry, SpawnPointSpecial[SPAWN_GARG_GATE][0]+irand(-10, 10), SpawnPointSpecial[SPAWN_GARG_GATE][1]+irand(-10, 10), SpawnPointSpecial[SPAWN_GARG_GATE][2]+irand(-10, 10), 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 120000);
                }
                break;
            case 17907:    //FROST_WYRM,
                if (FirstBossDead && WaveCount == 1) //summon at gate
                    creature = me->SummonCreature(entry, SpawnPointSpecial[SPAWN_WYRM_GATE][0], SpawnPointSpecial[SPAWN_WYRM_GATE][1], SpawnPointSpecial[SPAWN_WYRM_GATE][2], 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 120000);
                else
                {
                    creature = me->SummonCreature(entry, SpawnPointSpecial[SPAWN_NEAR_TOWER][0], SpawnPointSpecial[SPAWN_NEAR_TOWER][1], SpawnPointSpecial[SPAWN_NEAR_TOWER][2], 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 120000);
                    if (creature)
                        CAST_AI(hyjal_trashAI, creature->AI())->useFlyPath = true;
                }
                break;
            case 17908:    //GIANT_INFERNAL
                ++InfernalCount;
                if (InfernalCount > 7)
                    InfernalCount = 0;
                creature = me->SummonCreature(entry, InfernalPos[InfernalCount][0], InfernalPos[InfernalCount][1], InfernalPos[InfernalCount][2], 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 120000);
                break;
            default:
                creature = me->SummonCreature(entry, SpawnLoc[0], SpawnLoc[1], SpawnLoc[2], 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 120000);
                break;

    }

    if (creature)
    {
        // Increment Enemy Count to be used in World States and instance script
        ++EnemyCount;

        creature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
        creature->setActive(true);
        switch (entry)
        {
            case NECROMANCER:
            case ABOMINATION:
            case GHOUL:
            case BANSHEE:
            case CRYPT_FIEND:
            case GARGOYLE:
            case FROST_WYRM:
            case GIANT_INFERNAL:
            case FEL_STALKER:
            case RAGE_WINTERCHILL:
            case ANETHERON:
            case KAZROGAL:
            case AZGALOR:
                CAST_AI(hyjal_trashAI, creature->AI())->IsEvent = true;
                break;
        }
        if (pInstance)
        {
            if (pInstance->GetData(DATA_RAIDDAMAGE) < MINRAIDDAMAGE)
                creature->SetDisableReputationGain(true);//no repu for solo farming
        }
        // Check if Creature is a boss.
        if (creature->isWorldBoss())
        {
            if (!FirstBossDead)  BossGUID[0] = creature->GetGUID();
            else                BossGUID[1] = creature->GetGUID();
            CheckTimer = 5000;
        }
    }
}

void hyjalAI::SummonNextWave(const Wave wave[18], uint32 Count, float Base[4][3])
{
    // 1 in 4 chance we give a rally yell. Not sure if the chance is offilike.
    if (rand()%4 == 0)
        Talk(RALLY);

    if (!pInstance)
    {
        sLog->outError(ERROR_INST_DATA);
        return;
    }
    InfernalCount = 0;//reset infernal count every new wave

    EnemyCount = pInstance->GetData(DATA_TRASH);
    for (uint8 i = 0; i < 18; ++i)
    {
        if (wave[Count].Mob[i])
            SummonCreature(wave[Count].Mob[i], Base);
    }

    if (!wave[Count].IsBoss)
    {
        uint32 stateValue = Count+1;
        if (FirstBossDead)
            stateValue -= 9;                                // Subtract 9 from it to give the proper wave number if we are greater than 8

        // Set world state to our current wave number
        pInstance->DoUpdateWorldState(WORLD_STATE_WAVES, stateValue);    // Set world state to our current wave number
        // Enable world state
        pInstance->DoUpdateWorldState(WORLD_STATE_ENEMY, 1);             // Enable world state

        pInstance->SetData(DATA_TRASH, EnemyCount);         // Send data for instance script to update count

        if (!Debug)
            NextWaveTimer = wave[Count].WaveTimer;
        else
        {
            NextWaveTimer = 15000;
            sLog->outDebug(LOG_FILTER_TSCR, "TSCR: HyjalAI: debug mode is enabled. Next Wave in 15 seconds");
        }
    }
    else
    {
        // Set world state for waves to 0 to disable it.
        pInstance->DoUpdateWorldState(WORLD_STATE_WAVES, 0);
        pInstance->DoUpdateWorldState(WORLD_STATE_ENEMY, 1);

        // Set World State for enemies invading to 1.
        pInstance->DoUpdateWorldState(WORLD_STATE_ENEMYCOUNT, 1);

        Summon = false;
    }
    CheckTimer = 5000;
}

void hyjalAI::StartEvent(Player* player)
{
    if (!player || IsDummy || !pInstance)
        return;

    Talk(BEGIN);

    EventBegun = true;
    Summon = true;

    NextWaveTimer = 15000;
    CheckTimer = 5000;
    PlayerGUID = player->GetGUID();

    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

    pInstance->DoUpdateWorldState(WORLD_STATE_WAVES, 0);
    pInstance->DoUpdateWorldState(WORLD_STATE_ENEMY, 0);
    pInstance->DoUpdateWorldState(WORLD_STATE_ENEMYCOUNT, 0);

    DeSpawnVeins();
}

uint32 hyjalAI::GetInstanceData(uint32 Event)
{
    if (pInstance)
        return pInstance->GetData(Event);
    else sLog->outError(ERROR_INST_DATA);

    return 0;
}

void hyjalAI::Talk(uint32 id)
{
    std::list<uint8> index;
    for (uint8 i = 0; i < 9; ++i)
    {
        if (Faction == 0)                                    // Alliance
        {
            if (JainaQuotes[i].id == id)
                index.push_back(i);
        }
        else if (Faction == 1)                               // Horde
        {
            if (ThrallQuotes[i].id == id)
                index.push_back(i);
        }
    }

    if (index.empty())
        return;                                             // No quotes found, no use to continue

    uint8 ind = *(index.begin()) + rand()%index.size();

    int32 YellId = 0;
    if (Faction == 0)                                        // Alliance
    {
        YellId = JainaQuotes[ind].textid;
    }
    else if (Faction == 1)                                   // Horde
    {
        YellId = ThrallQuotes[ind].textid;
    }

    if (YellId)
        DoScriptText(YellId, me);
}

void hyjalAI::Retreat()
{
    if (pInstance)
    {
        pInstance->SetData(TYPE_RETREAT, SPECIAL);

        if (Faction == 0)
        {
            pInstance->SetData(DATA_ALLIANCE_RETREAT, 1);
            AddWaypoint(0, JainaWPs[0][0], JainaWPs[0][1], JainaWPs[0][2]);
            AddWaypoint(1, JainaWPs[1][0], JainaWPs[1][1], JainaWPs[1][2]);
            Start(false, false);
            SetDespawnAtEnd(false);//move to center of alliance base
        }
        if (Faction == 1)
        {
            pInstance->SetData(DATA_HORDE_RETREAT, 1);
            Creature* JainaDummy = me->SummonCreature(JAINA, JainaDummySpawn[0][0], JainaDummySpawn[0][1], JainaDummySpawn[0][2], JainaDummySpawn[0][3], TEMPSUMMON_TIMED_DESPAWN, 60000);
            if (JainaDummy)
            {
                JainaDummy->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                CAST_AI(hyjalAI, JainaDummy->AI())->IsDummy = true;
                DummyGuid = JainaDummy->GetGUID();
            }
            AddWaypoint(0, JainaDummySpawn[1][0], JainaDummySpawn[1][1], JainaDummySpawn[1][2]);
            Start(false, false);
            SetDespawnAtEnd(false);//move to center of alliance base
        }
    }
    SpawnVeins();
    Overrun = true;
    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);//cant talk after overrun event started
}

void hyjalAI::SpawnVeins()
{
    if (Faction == 0)
    {
        if (VeinsSpawned[0])//prevent any buggers
            return;
        for (uint8 i = 0; i<7; ++i)
        {
            GameObject* gem = me->SummonGameObject(ANCIENT_VEIN, VeinPos[i][0], VeinPos[i][1], VeinPos[i][2], VeinPos[i][3], VeinPos[i][4], VeinPos[i][5], VeinPos[i][6], VeinPos[i][7], 0);
            if (gem)
                VeinGUID[i]=gem->GetGUID();
        }
        VeinsSpawned[0] = true;
    }else{
        if (VeinsSpawned[1])
            return;
        for (uint8 i = 7; i<14; ++i)
        {
            GameObject* gem = me->SummonGameObject(ANCIENT_VEIN, VeinPos[i][0], VeinPos[i][1], VeinPos[i][2], VeinPos[i][3], VeinPos[i][4], VeinPos[i][5], VeinPos[i][6], VeinPos[i][7], 0);
            if (gem)
                VeinGUID[i]=gem->GetGUID();
        }
        VeinsSpawned[1] = true;
    }
}

void hyjalAI::DeSpawnVeins()
{
    if (!pInstance)
        return;
    if (Faction == 1)
    {
        Creature* unit=Unit::GetCreature((*me), pInstance->GetData64(DATA_JAINAPROUDMOORE));
        if (!unit)return;
        hyjalAI* ai = CAST_AI(hyjalAI, unit->AI());
        if (!ai)return;
        for (uint8 i = 0; i<7; ++i)
        {
            if (GameObject* gem = pInstance->instance->GetGameObject(ai->VeinGUID[i]))
                gem->Delete();
        }
    } else if (Faction)
    {
        Creature* unit=Unit::GetCreature((*me), pInstance->GetData64(DATA_THRALL));
        if (!unit)return;
        hyjalAI* ai = CAST_AI(hyjalAI, unit->AI());
        if (!ai)return;
        for (uint8 i = 7; i<14; ++i)
        {
            if (GameObject* gem = pInstance->instance->GetGameObject(ai->VeinGUID[i]))
                gem->Delete();
        }
    }
}

void hyjalAI::UpdateAI(const uint32 diff)
{
    if (IsDummy)
    {
        if (MassTeleportTimer < diff && DoMassTeleport)
        {
            DoCast(me, SPELL_MASS_TELEPORT, false);
            DoMassTeleport = false;
        } else MassTeleportTimer -= diff;
        return;
    }
    if (DoHide)
    {
        DoHide = false;
        switch (me->GetEntry())
        {
            case JAINA:
                if (pInstance && pInstance->GetData(DATA_ALLIANCE_RETREAT))
                {
                    me->SetVisible(false);
                    HideNearPos(me->GetPositionX(), me->GetPositionY());
                    HideNearPos(5037.76f, -1889.71f);
                    for (uint8 i = 0; i < 92; ++i)//summon fires
                        me->SummonGameObject(FLAMEOBJECT, AllianceFirePos[i][0], AllianceFirePos[i][1], AllianceFirePos[i][2], AllianceFirePos[i][3], AllianceFirePos[i][4], AllianceFirePos[i][5], AllianceFirePos[i][6], AllianceFirePos[i][7], 0);

                }
                else me->SetVisible(true);
                break;
            case THRALL: //thrall
                if (pInstance && pInstance->GetData(DATA_HORDE_RETREAT))
                {
                    me->SetVisible(false);
                    HideNearPos(me->GetPositionX(), me->GetPositionY());
                    HideNearPos(5563, -2763.19f);
                    HideNearPos(5542.2f, -2629.36f);
                    for (uint8 i = 0; i < 65; ++i)//summon fires
                        me->SummonGameObject(FLAMEOBJECT, HordeFirePos[i][0], HordeFirePos[i][1], HordeFirePos[i][2], HordeFirePos[i][3], HordeFirePos[i][4], HordeFirePos[i][5], HordeFirePos[i][6], HordeFirePos[i][7], 0);

                }
                else me->SetVisible(true);
                break;
        }
    }
    if (DoRespawn)
    {
        if (RespawnTimer <= diff)
        {
            DoRespawn = false;
            RespawnNearPos(me->GetPositionX(), me->GetPositionY());
            if (Faction == 0)
            {
                RespawnNearPos(5037.76f, -1889.71f);
            } else if (Faction == 1)
            {
                RespawnNearPos(5563, -2763.19f);
                RespawnNearPos(5542.2f, -2629.36f);
            }
            me->SetVisible(true);
        }else{
            RespawnTimer -= diff;
            me->SetVisible(false);
        }
        return;
    }
    if (Overrun)
        DoOverrun(Faction, diff);
    if (bRetreat)
    {
        if (RetreatTimer <= diff)
        {
            IsDummy = true;
            bRetreat = false;
            HideNearPos(me->GetPositionX(), me->GetPositionY());
            switch (me->GetEntry())
            {
                case JAINA://jaina
                    HideNearPos(5037.76f, -1889.71f);
                    break;
                case THRALL://thrall
                    HideNearPos(5563, -2763.19f);
                    HideNearPos(5542.2f, -2629.36f);
                    HideNearPos(5603.75f, -2853.12f);
                    break;
            }
            me->SetVisible(false);
        } else RetreatTimer -= diff;
    }

    if (!EventBegun)
        return;

    if (Summon)
    {
        if (pInstance && EnemyCount)
        {
            EnemyCount = pInstance->GetData(DATA_TRASH);
            if (!EnemyCount)
                NextWaveTimer = 5000;
        }

        if (NextWaveTimer <= diff)
        {
            if (Faction == 0)
                SummonNextWave(AllianceWaves, WaveCount, AllianceBase);
            else if (Faction == 1)
                SummonNextWave(HordeWaves, WaveCount, HordeBase);
            ++WaveCount;
        } else NextWaveTimer -= diff;
    }

    if (CheckTimer <= diff)
    {
        for (uint8 i = 0; i < 2; ++i)
        {
            if (BossGUID[i])
            {
                Unit* unit = Unit::GetUnit((*me), BossGUID[i]);
                if (unit && (!unit->isAlive()))
                {
                    if (BossGUID[i] == BossGUID[0])
                    {
                        Talk(INCOMING);
                        FirstBossDead = true;
                    }
                    else if (BossGUID[i] == BossGUID[1])
                    {
                        Talk(SUCCESS);
                        SecondBossDead = true;
                    }
                    EventBegun = false;
                    CheckTimer = 0;
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    BossGUID[i] = 0;
                    if (pInstance)
                        pInstance->DoUpdateWorldState(WORLD_STATE_ENEMY, 0); // Reset world state for enemies to disable it
                }
            }
        }
        CheckTimer = 5000;
    } else CheckTimer -= diff;

    if (!UpdateVictim())
        return;

    for (uint8 i = 0; i < HYJAL_AI_MAX_SPELLS; ++i)
    {
        if (Spells[i].SpellId)
        {
            if (SpellTimer[i] <= diff)
            {
                if (me->IsNonMeleeSpellCasted(false))
                    me->InterruptNonMeleeSpells(false);

                Unit* target = NULL;

                switch (Spells[i].TargetType)
                {
                    case TARGETTYPE_SELF: target = me; break;
                    case TARGETTYPE_RANDOM: target = SelectTarget(SELECT_TARGET_RANDOM, 0); break;
                    case TARGETTYPE_VICTIM: target = me->getVictim(); break;
                }

                if (target && target->isAlive())
                {
                    DoCast(target, Spells[i].SpellId);
                    SpellTimer[i] = Spells[i].Cooldown;
                }
            } else SpellTimer[i] -= diff;
        }
    }

    DoMeleeAttackIfReady();
}
void hyjalAI::JustDied(Unit* /*killer*/)
{
    if (IsDummy)return;
    me->Respawn();
    me->SetVisible(false);
    DoRespawn = true;
    RespawnTimer = 120000;
    Talk(DEATH);
    Summons.DespawnAll();//despawn all wave's summons
    if (pInstance)
    {//reset encounter if boss is despawned (ex: thrall is killed, boss despawns, event stucks at inprogress)
        if (pInstance->GetData(DATA_RAGEWINTERCHILLEVENT) == IN_PROGRESS)
            pInstance->SetData(DATA_RAGEWINTERCHILLEVENT, NOT_STARTED);
        if (pInstance->GetData(DATA_ANETHERONEVENT) == IN_PROGRESS)
            pInstance->SetData(DATA_ANETHERONEVENT, NOT_STARTED);
        if (pInstance->GetData(DATA_KAZROGALEVENT) == IN_PROGRESS)
            pInstance->SetData(DATA_KAZROGALEVENT, NOT_STARTED);
        if (pInstance->GetData(DATA_AZGALOREVENT) == IN_PROGRESS)
            pInstance->SetData(DATA_AZGALOREVENT, NOT_STARTED);
        pInstance->SetData(DATA_RESET_RAIDDAMAGE, 0);//reset damage on die
    }
}
void hyjalAI::HideNearPos(float x, float y)
{
    CellPair pair(Trinity::ComputeCellPair(x, y));
    Cell cell(pair);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();

    // First get all creatures.
    std::list<Creature*> creatures;
    Trinity::AllFriendlyCreaturesInGrid creature_check(me);
    Trinity::CreatureListSearcher<Trinity::AllFriendlyCreaturesInGrid> creature_searcher(me, creatures, creature_check);
    TypeContainerVisitor
        <Trinity::CreatureListSearcher<Trinity::AllFriendlyCreaturesInGrid>,
        GridTypeMapContainer> creature_visitor(creature_searcher);

                                                            // Get Creatures
    cell.Visit(pair, creature_visitor, *(me->GetMap()));

    if (!creatures.empty())
    {
        for (std::list<Creature*>::const_iterator itr = creatures.begin(); itr != creatures.end(); ++itr)
        {
            (*itr)->SetVisible(false);
            (*itr)->setFaction(35);//make them friendly so mobs won't attack them
        }
    }
}
void hyjalAI::RespawnNearPos(float x, float y)
{
    CellPair p(Trinity::ComputeCellPair(x, y));
    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();

    Trinity::RespawnDo u_do;
    Trinity::WorldObjectWorker<Trinity::RespawnDo> worker(me, u_do);
    TypeContainerVisitor<Trinity::WorldObjectWorker<Trinity::RespawnDo>, GridTypeMapContainer > obj_worker(worker);
    cell.Visit(p, obj_worker, *me->GetMap());
}
void hyjalAI::WaypointReached(uint32 i)
{
    if (i == 1 || (i == 0 && me->GetEntry() == THRALL))
    {
        me->MonsterYell(YELL_HURRY, 0, 0);
        WaitForTeleport = true;
        TeleportTimer = 20000;
        if (me->GetEntry() == JAINA)
            DoCast(me, SPELL_MASS_TELEPORT, false);
        if (me->GetEntry() == THRALL && DummyGuid)
        {
            Unit* Dummy = Unit::GetUnit((*me), DummyGuid);
            if (Dummy)
            {
                CAST_AI(hyjalAI, CAST_CRE(Dummy)->AI())->DoMassTeleport = true;
                CAST_AI(hyjalAI, CAST_CRE(Dummy)->AI())->MassTeleportTimer = 20000;
                Dummy->CastSpell(me, SPELL_MASS_TELEPORT, false);
            }
        }
        //do some talking
        //all alive guards walk near here
        CellPair pair(Trinity::ComputeCellPair(me->GetPositionX(), me->GetPositionY()));
        Cell cell(pair);
        cell.data.Part.reserved = ALL_DISTRICT;
        cell.SetNoCreate();

        // First get all creatures.
        std::list<Creature*> creatures;
        Trinity::AllFriendlyCreaturesInGrid creature_check(me);
        Trinity::CreatureListSearcher<Trinity::AllFriendlyCreaturesInGrid> creature_searcher(me, creatures, creature_check);
        TypeContainerVisitor
            <Trinity::CreatureListSearcher<Trinity::AllFriendlyCreaturesInGrid>,
            GridTypeMapContainer> creature_visitor(creature_searcher);

        cell.Visit(pair, creature_visitor, *(me->GetMap()));

        if (!creatures.empty())
        {
            for (std::list<Creature*>::const_iterator itr = creatures.begin(); itr != creatures.end(); ++itr)
            {
                if ((*itr) && (*itr)->isAlive() && (*itr) != me && (*itr)->GetEntry() != JAINA)
                {
                    if (!(*itr)->IsWithinDist(me, 60))
                        (*itr)->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                    float x, y, z;
                    (*itr)->SetDefaultMovementType(IDLE_MOTION_TYPE);
                    (*itr)->GetMotionMaster()->Initialize();
                    float range = 10;
                    if (me->GetEntry() == THRALL)range = 20;
                    me->GetNearPoint(me, x, y, z, range, 0, me->GetAngle((*itr)));
                    (*itr)->GetMotionMaster()->MovePoint(0, x+irand(-5, 5), y+irand(-5, 5), me->GetPositionZ());
                }
            }
        }
    }
}
void hyjalAI::DoOverrun(uint32 faction, const uint32 diff)
{
    npc_escortAI::UpdateAI(diff);
    if (WaitForTeleport)
    {
        if (TeleportTimer <= diff)
        {
            CellPair pair(Trinity::ComputeCellPair(me->GetPositionX(), me->GetPositionY()));
            Cell cell(pair);
            cell.data.Part.reserved = ALL_DISTRICT;
            cell.SetNoCreate();

            std::list<Creature*> creatures;
            Trinity::AllFriendlyCreaturesInGrid creature_check(me);
            Trinity::CreatureListSearcher<Trinity::AllFriendlyCreaturesInGrid> creature_searcher(me, creatures, creature_check);
            TypeContainerVisitor
                <Trinity::CreatureListSearcher<Trinity::AllFriendlyCreaturesInGrid>,
                GridTypeMapContainer> creature_visitor(creature_searcher);

            cell.Visit(pair, creature_visitor, *(me->GetMap()));

            if (!creatures.empty())
            {
                for (std::list<Creature*>::const_iterator itr = creatures.begin(); itr != creatures.end(); ++itr)
                {
                    if ((*itr) && (*itr)->isAlive())
                    {
                        (*itr)->CastSpell(*itr, SPELL_TELEPORT_VISUAL, true);
                        (*itr)->setFaction(35);//make them friendly so mobs won't attack them
                        (*itr)->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    }
                }
                DoCast(me, SPELL_TELEPORT_VISUAL);
                bRetreat = true;
                RetreatTimer = 1000;
            }

            WaitForTeleport = false;
            Teleported = true;
        }TeleportTimer -= diff;
    }
    if (!Teleported)
        return;
    Overrun = false;//execute once
    switch (faction)
    {
        case 0://alliance
            for (uint8 i = 0; i < 92; ++i)//summon fires
                me->SummonGameObject(FLAMEOBJECT, AllianceFirePos[i][0], AllianceFirePos[i][1], AllianceFirePos[i][2], AllianceFirePos[i][3], AllianceFirePos[i][4], AllianceFirePos[i][5], AllianceFirePos[i][6], AllianceFirePos[i][7], 0);

            for (uint8 i = 0; i < 25; ++i)//summon 25 ghouls
            {
                uint8 r = rand()%4;
                Creature* unit = me->SummonCreature(GHOUL, AllianceBase[r][0]+irand(-15, 15), AllianceBase[r][1]+irand(-15, 15), AllianceBase[r][2], 0, TEMPSUMMON_MANUAL_DESPAWN, 2*60*1000);
                if (unit)
                {
                    CAST_AI(hyjal_trashAI, unit->AI())->faction = Faction;
                    CAST_AI(hyjal_trashAI, unit->AI())->IsOverrun = true;
                    CAST_AI(hyjal_trashAI, unit->AI())->OverrunType = i;
                    unit->setActive(true);
                }
            }
            for (uint8 i = 0; i < 3; ++i)//summon 3 abominations
            {
                uint8 r = rand()%4;
                Creature* unit = me->SummonCreature(ABOMINATION, AllianceBase[r][0]+irand(-15, 15), AllianceBase[r][1]+irand(-15, 15), AllianceBase[r][2], 0, TEMPSUMMON_MANUAL_DESPAWN, 2*60*1000);
                if (unit)
                {
                    CAST_AI(hyjal_trashAI, unit->AI())->faction = Faction;
                    CAST_AI(hyjal_trashAI, unit->AI())->IsOverrun = true;
                    CAST_AI(hyjal_trashAI, unit->AI())->OverrunType = i;
                    unit->setActive(true);
                }
            }
            for (uint8 i = 0; i < 5; ++i)//summon 5 gargoyles
            {
                Creature* unit = me->SummonCreature(GARGOYLE, AllianceOverrunGargPos[i][0], AllianceOverrunGargPos[i][1], AllianceOverrunGargPos[i][2], AllianceOverrunGargPos[i][3], TEMPSUMMON_MANUAL_DESPAWN, 2*60*1000);
                if (unit)
                {
                    unit->SetHomePosition(AllianceOverrunGargPos[i][0], AllianceOverrunGargPos[i][1], AllianceOverrunGargPos[i][2], AllianceOverrunGargPos[i][3]);
                    CAST_AI(hyjal_trashAI, unit->AI())->faction = Faction;
                    CAST_AI(hyjal_trashAI, unit->AI())->IsOverrun = true;
                    CAST_AI(hyjal_trashAI, unit->AI())->OverrunType = i;
                    unit->setActive(true);
                }
            }
            break;
        case 1://horde
            for (uint8 i = 0; i < 65; ++i)//summon fires
                me->SummonGameObject(FLAMEOBJECT, HordeFirePos[i][0], HordeFirePos[i][1], HordeFirePos[i][2], HordeFirePos[i][3], HordeFirePos[i][4], HordeFirePos[i][5], HordeFirePos[i][6], HordeFirePos[i][7], 0);

            for (uint8 i = 0; i < 26; ++i)//summon infernals
            {
                Creature* unit = me->SummonCreature(GIANT_INFERNAL, InfernalSPWP[i][0], InfernalSPWP[i][1], InfernalSPWP[i][2], InfernalSPWP[i][3], TEMPSUMMON_MANUAL_DESPAWN, 2*60*1000);
                if (unit)
                {
                    unit->SetHomePosition(InfernalSPWP[i][0], InfernalSPWP[i][1], InfernalSPWP[i][2], InfernalSPWP[i][3]);
                    CAST_AI(hyjal_trashAI, unit->AI())->faction = Faction;
                    CAST_AI(hyjal_trashAI, unit->AI())->IsOverrun = true;
                    CAST_AI(hyjal_trashAI, unit->AI())->OverrunType = i;
                    unit->setActive(true);
                }
            }
            for (uint8 i = 0; i < 25; ++i)//summon 25 ghouls
            {
                uint8 r = rand()%4;
                Creature* unit = me->SummonCreature(GHOUL, HordeBase[r][0]+irand(-15, 15), HordeBase[r][1]+irand(-15, 15), HordeBase[r][2], 0, TEMPSUMMON_MANUAL_DESPAWN, 2*60*1000);
                if (unit)
                {
                    CAST_AI(hyjal_trashAI, unit->AI())->faction = Faction;
                    CAST_AI(hyjal_trashAI, unit->AI())->IsOverrun = true;
                    CAST_AI(hyjal_trashAI, unit->AI())->OverrunType = i;
                    unit->setActive(true);
                }
            }
            for (uint8 i = 0; i < 5; ++i)//summon 5 abominations
            {
                uint8 r = rand()%4;
                Creature* unit = me->SummonCreature(ABOMINATION, HordeBase[r][0]+irand(-15, 15), HordeBase[r][1]+irand(-15, 15), HordeBase[r][2], 0, TEMPSUMMON_MANUAL_DESPAWN, 2*60*1000);
                if (unit)
                {
                    CAST_AI(hyjal_trashAI, unit->AI())->faction = Faction;
                    CAST_AI(hyjal_trashAI, unit->AI())->IsOverrun = true;
                    CAST_AI(hyjal_trashAI, unit->AI())->OverrunType = i;
                    unit->setActive(true);
                }
            }
            break;
    }
}
