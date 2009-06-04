/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: HyjalAI
SD%Complete: 90
SDComment:
SDCategory: Caverns of Time, Mount Hyjal
EndScriptData */

#include "precompiled.h"
#include "hyjalAI.h"
#include "hyjal_trash.h"
#include "MapManager.h"
#include "Language.h"
#include "Chat.h"
#include "Object.h"

#define SPAWN_GARG_GATE 0
#define SPAWN_WYRM_GATE 1
#define SPAWN_NEAR_TOWER 2
// Locations for summoning gargoyls and frost wyrms in special cases
float SpawnPointSpecial[3][3]=
{
    {5497.08,    -2493.23,    1535.72}, //spawn point for the gargoyles near the horde gate
    {5624.53,    -2548.12,    1551.54}, //spawn point for the frost wyrm near the horde gate
    {5604.41,   -2811.98,   1547.77}  //spawn point for the gargoyles and wyrms near the horde tower
};

// Locations for summoning waves in Alliance base
float AllianceBase[4][3]=
{
    {4928.48,    -1526.38,    1326.83},
    {4923.54,    -1514.29,    1327.98},
    {4928.41,    -1510.35,    1327.99},
    {4938.35,    -1521.00,    1326.69}
};

float JainaDummySpawn[2][4]=
{
    {5497.01, -2719.03, 1483.08, 2.90426},
    {5484.98, -2721.69, 1483.39, 6.00656}
};


// Locations for summoning waves in Horde base
float HordeBase[4][3]=
{
    {5458.01,    -2340.27,    1459.60},
    {5466.01,    -2334.69,    1460.06},
    {5468.45,    -2355.13,    1459.99},
    {5479.06,    -2344.16,    1461.74}
};

// Lady Jaina's waypoints when retreathing
float JainaWPs[2][3]=
{
    {5078.56,    -1789.79,    1320.73},//next to the small stairs
    {5037.38,    -1778.39,    1322.61},//center of alliance base
};

float InfernalPos[8][3]=//spawn points for the infernals in the horde base
{
    {5453.59,    -2764.52,    1493.50},
    {5478.4,    -2781.77,    1497.52},
    {5506.09,    -2780.53,    1496.32},
    {5532.1,    -2763.42,    1492.37},
    {5544.16,    -2733.99,    1487.14},
    {5536.19,    -2708.18,    1480.01},
    {5510.16,    -2691.75,    1479.66},
    {5482.39,    -2689.19,    1481.09}
};

float InfernalSPWP[26][4]=//spawn points for the infernals in the horde base used in the cleaning wave
{
    {5490.96, -2718.72, 1482.96, 0.49773},
    {5449.51, -2723.32, 1485.69, 2.69685},
    {5520.83, -2624.68, 1483.82, 1.20459},
    {5558.28, -2629.26, 1485.76, 0.37992},
    {5567.97, -2758.69, 1494.10, 5.04125},
    {5384.90, -2793.47, 1503.90, 5.55412},
    {5495.33, -2814.06, 1501.56, 1.12055},
    {5472.63, -2929.39, 1538.31, 1.95777},
    {5334.72, -2952.29, 1534.34, 0.50869},
    {5398.36, -2872.46, 1512.38, 0.76787},
    {5514.39, -2768.63, 1492.30, 1.55721},
    {5598.91, -2703.75, 1495.64, 2.56644},
    {5467.80, -2655.93, 1482.27, 0.85819},
    {5399.83, -2985.24, 1545.04, 5.92559},
    {5232.13, -2967.05, 1553.09, 5.41351},
    {5272.02, -3082.52, 1567.09, 3.40681},
    {5343.26, -3120.71, 1582.92, 3.16727},
    {5371.26, -3175.24, 1587.41, 6.10466},
    {5434.67, -3177.91, 1579.25, 2.77850},
    {5237.39, -3149.25, 1593.59, 0.83855},
    {5202.15, -3016.64, 1566.28, 3.31256},
    {5302.54, -2914.37, 1528.53, 3.37146},
    {5439.04, -2834.81, 1508.80, 2.14231},
    {5421.33, -2771.04, 1494.28, 6.06223},
    {5549.76, -2692.93, 1482.68, 2.19414},
    {5459.78, -2755.71, 1490.68, 1.05139}
};

float VeinPos[14][8]=//spawn points of the ancient gem veins
{
    {5184.84,    -1982.59,    1382.66,    2.58079,    0,    0,    0.960944,    0.276742},  //alliance
    {5107.66,    -2071.16,    1368.37,    2.65148,    0,    0,    0.970124,    0.242611},    //alliance
    {5040.53,    -2227.65,    1403.17,    3.35049,    0,    0,    0.99455,    -0.104257},    //alliance
    {5187.59,    -2453.12,    1455.51,    5.87943,    0,    0,    0.20051,    -0.979692},    //alliance
    {5429.43,    -2340.65,    1465.38,    4.7681,        0,    0,    0.687138,    -0.726527},    //alliance
    {5463.99,    -2315.95,    1470.29,    1.52045,    0,    0,    0.689084,    0.724682},    //alliance
    {5624.65,    -2495.09,    1510.11,    0.0124869,    0,    0,    0.00624342,    0.999981},    //alliance
    {5285.41,    -3348.32,    1663.01,    1.57152,    0,    0,    0.707362,    0.706852},    //horde
    {5417.69,    -3372.52,    1656.31,    0.361993,    0,    0,    0.18001,    0.983665},    //horde
    {5315.34,    -3238.32,    1622.88,    3.03627,    0,    0,    0.998614,    0.0526347},    //horde
    {5303.4,    -3096.44,    1596.41,    1.72073,    0,    0,    0.758081,    0.65216},    //horde
    {5265.13,    -3177.27,    1616.22,    0.813604,    0,    0,    0.395674,    0.918391},    //horde
    {5374.3,    -3420.59,    1653.43,    1.45762,    0,    0,    0.665981,    0.745969},    //horde
    {5441.54,    -3321.59,    1651.55,    0.258306,    0,    0,    0.128794,    0.991671}   //horde
};

float AllianceOverrunGargPos[5][4]=//gargoyle spawn points in the alliance overrun
{
    {5279.94, -2049.68, 1311.38, 0},//garg1
    {5289.15, -2219.06, 1291.12, 0},//garg2
    {5202.07, -2136.10, 1305.07, 2.8},//garg3
    {5071.52, -2425.63, 1454.48, 5.54},//garg4
    {5120.65, -2467.92, 1463.93, 2.54}//garg5
};

float AllianceFirePos[92][8]=//spawn points for the fire visuals (GO) in the alliance base
{
    {5039.9,    -1796.84,    1323.88,    2.59222,    0,    0,    0.962511,    0.271243},
    {5087.2,    -1795.2,    1320.68,    1.03946,    0,    0,    0.496644,    0.867954},
    {5112.68,    -1806.66,    1359.93,    1.37799,    0,    0,    0.63576,    0.771887},
    {5095.61,    -1793.27,    1359.78,    0.580806,    0,    0,    0.286338,    0.958129},
    {5090.43,    -1784.45,    1360.44,    0.796784,    0,    0,    0.387937,    0.921686},
    {5139.25,    -1783.11,    1359.39,    3.30849,    0,    0,    0.99652,    -0.0833509},
    {5112.16,    -1763.72,    1361.35,    5.10312,    0,    0,    0.556388,    -0.830922},
    {4981.18,    -1793.98,    1335.7,        3.23072,    0,    0,    0.999007,    -0.0445498},
    {4996.57,    -1766.75,    1341.62,    3.5331,        0,    0,    0.980902,    -0.194505},
    {4983.74,    -1769.25,    1345.75,    3.79228,    0,    0,    0.947541,    -0.319635},
    {4996.01,    -1774.43,    1330.71,    3.07364,    0,    0,    0.999423,    0.0339693},
    {5094.2,    -1726.13,    1330.55,    1.56175,    0,    0,    0.703901,    0.710298},
    {5079.82,    -1721.24,    1336.26,    1.18868,    0,    0,    0.559964,    0.828517},
    {5077.68,    -1717.15,    1327.78,    0.0145145,    0,    0,    0.00725717,    0.999974},
    {5122.27,    -1738.22,    1341.67,    0.835256,    0,    0,    0.405593,    0.914054},
    {5131.88,    -1741.15,    1335.25,    2.15472,    0,    0,    0.880712,    0.473653},
    {5196.93,    -1772.99,    1345.2,        0.128397,    0,    0,    0.0641544,    0.99794},
    {5225.33,    -1756.06,    1344.17,    3.04223,    0,    0,    0.998766,    0.0496599},
    {5224.84,    -1767.05,    1360.06,    3.19538,    0,    0,    0.999638,    -0.0268922},
    {5202.05,    -1763.47,    1361.68,    2.59455,    0,    0,    0.962826,    0.270122},
    {5194.74,    -1766.66,    1356.94,    0.0734191,    0,    0,    0.0367013,    0.999326},
    {5159.67,    -1832.97,    1344.5,        5.17457,    0,    0,    0.526356,    -0.850264},
    {5096.17,    -1858.73,    1332.46,    5.30021,    0,    0,    0.471939,    -0.881631},
    {5110.7,    -1856.59,    1342.84,    5.97564,    0,    0,    0.153167,    -0.9882},
    {5109.76,    -1855.3,    1332.38,    4.89572,    0,    0,    0.639411,    -0.768865},
    {5068.95,    -1837.37,    1328.81,    2.61569,    0,    0,    0.965628,    0.25993},
    {5064.4,    -1824.77,    1329.02,    2.16409,    0,    0,    0.88292,    0.469524},
    {5059.89,    -1848.79,    1329.59,    0.0709955,    0,    0,    0.0354903,    0.99937},
    {5014.37,    -1851.39,    1322.56,    4.66949,    0,    0,    0.722111,    -0.691777},
    {5025.1,    -1848.27,    1323.39,    4.44565,    0,    0,    0.794854,    -0.606801},
    {4942.63,    -1890.13,    1326.59,    3.28719,    0,    0,    0.997351,    -0.0727343},
    {4937.95,    -1888.71,    1352.41,    3.41678,    0,    0,    0.990549,    -0.13716},
    {4922.48,    -1881.92,    1352.41,    5.03077,    0,    0,    0.586075,    -0.810257},
    {4915.35,    -1894.32,    1351.24,    6.22457,    0,    0,    0.0293048,    -0.999571},
    {4922.71,    -1904.84,    1352.56,    1.37866,    0,    0,    0.63602,    0.771672},
    {4932.89,    -1905.49,    1352.56,    1.89702,    0,    0,    0.812549,    0.582893},
    {5011.83,    -1861.05,    1345.86,    4.43777,    0,    0,    0.797239,    -0.603664},
    {5011.83,    -1861.05,    1363.26,    4.748,        0,    0,    0.694406,    -0.719583},
    {5021.46,    -1858.35,    1342.17,    4.86188,    0,    0,    0.652329,    -0.757936},
    {4995.02,    -1698.3,    1370.38,    6.15779,    0,    0,    0.0626579,    -0.998035},
    {5119.85,    -1728.9,    1336.04,    5.87112,    0,    0,    0.204579,    -0.97885},
    {5214.75,    -1751.02,    1342.5,        5.08965,    0,    0,    0.561972,    -0.827156},
    {5075.04,    -1822.43,    1328.87,    3.99951,    0,    0,    0.9094,        -0.415924},
    {5057.09,    -1823.32,    1350.35,    3.88169,    0,    0,    0.93231,    -0.361659},
    {4984.6,    -1816.99,    1329.21,    3.05308,    0,    0,    0.999021,    0.0442417},
    {4983.35,    -1811.55,    1356.82,    3.33975,    0,    0,    0.995096,    -0.098917},
    {4984.11,    -1825.73,    1350.76,    2.26375,    0,    0,    0.905211,    0.424962},
    {4968.47,    -1786.46,    1354.09,    3.07663,    0,    0,    0.999473,    0.0324733},
    {5061.82,    -1751.16,    1339.07,    5.94727,    0,    0,    0.167171,    -0.985928},
    {5063.75,    -1763,        1351.91,    0.759707,    0,    0,    0.370784,    0.928719},
    {5078.65,    -1708.26,    1353.9,        1.27022,    0,    0,    0.593264,    0.805008},
    {4983.19,    -1755.96,    1331.13,    4.28221,    0,    0,    0.841733,    -0.539894},
    {4972.76,    -1755.3,    1332.5,        4.21938,    0,    0,    0.858276,    -0.513188},
    {4961.65,    -1760.82,    1351.69,    3.56515,    0,    0,    0.977659,    -0.210198},
    {5086.45,    -1779.83,    1321.62,    6.23157,    0,    0,    0.0258051,    -0.999667},
    {5063.15,    -1756.74,    1328.56,    0.886926,    0,    0,    0.42907,    0.903271},
    {5042.45,    -1800.61,    1323.88,    2.50093,    0,    0,    0.949131,    0.31488},
    {5084.74,    -1725.35,    1327.89,    1.65034,    0,    0,    0.734663,    0.678432},
    {4993.25,    -1758.1,    1331.07,    3.49995,    0,    0,    0.98399,    -0.178223},
    {5078.53,    -1867.85,    1348.91,    5.85612,    0,    0,    0.211913,    -0.977288},
    {5080.74,    -1869.73,    1333.18,    6.18206,    0,    0,    0.0505424,    -0.998722},
    {5089.55,    -1894.13,    1356.08,    1.52072,    0,    0,    0.689181,    0.724589},
    {5113.24,    -1899.49,    1363.77,    1.50108,    0,    0,    0.682034,    0.731321},
    {4984.18,    -1907.69,    1325.62,    3.82193,    0,    0,    0.942698,    -0.333646},
    {5094.14,    -2432.08,    1429.38,    4.70083,    0,    0,    0.711182,    -0.703007},
    {5329.89,    -2113.30,    1281.06,    5.60560,    0,    0,    0.332347,    -0.943157},
    {5170.87,    -2148.13,    1278.32,    1.63540,    0,    0,    0.729573,    0.683903 },
    {5132.94,    -1960.25,    1367.8,        3.69787,    0,    0,    0.961568,    -0.274566},
    {5280.82,    -2351.55,    1431.57,    4.46913,    0,    0,    0.787677,    -0.616088},
    {5176.78,    -2121.43,    1295.27,    3.24153,    0,    0,    0.998752,    -0.04995},
    {5332.75,    -2101.41,    1296.37,    5.50350,    0,    0,    0.380043,    -0.924969},
    {5265.70,    -2050.27,    1287.57,    0.50051,    0,    0,    0.247655,    0.968848 },
    {5194.21,    -2129.89,    1274.04,    3.08053,    0,    0,    0.999534,    0.0305272},
    {5225.81,    -1985.50,    1364.15,    0.37247,    0,    0,    0.185163,    0.982708 },
    {5339.46,    -2204.47,    1280.45,    0.99921,    0,    0,    0.479081,    0.877771 },
    {5269.63,    -2020.57,    1299.62,    3.00201,    0,    0,    0.997566,    0.0697332},
    {5111.54,    -2445.70,    1435.31,    2.70983,    0,    0,    0.976788,    0.214207 },
    {5111.24,    -1901.14,    1355.33,    1.61028,    0,    0,    0.720929,    0.693009 },
    {5310.42,    -2207.82,    1277.46,    0.50441,    0,    0,    0.249544,    0.968363 },
    {5150.81,    -2042.13,    1394.3,        2.21031,    0,    0,    0.893534,    0.448995 },
    {5224.84,    -2376.61,    1366.33,    5.0621,        0,    0,    0.573311,    -0.819338},
    {5105.41,    -2454.86,    1446.16,    4.64584,    0,    0,    0.730239,    -0.683191},
    {5309.65,    -2188.28,    1266.84,    5.56631,    0,    0,    0.350811,    -0.936446},
    {5281.46,    -2047.82,    1287.67,    2.44909,    0,    0,    0.940652,    0.339373 },
    {5325.45,    -2189.41,    1309.6,        6.23783,    0,    0,    0.0226771,    -0.999743},
    {5190.96,    -2142.54,    1293.03,    6.25668,    0,    0,    0.0132544,    -0.999912},
    {5089.99,    -2467.49,    1441.8,        0.77381,    0,    0,    0.377326,    0.92608     },
    {5195.08,    -2129.01,    1285.36,    3.55727,    0,    0,    0.978480,    -0.206344},
    {5353.76,    -2116.28,    1299.27,    6.17894,    0,    0,    0.0521006,    -0.998642},
    {5271.14,    -2037.38,    1299.24,    4.07879,    0,    0,    0.892201,    -0.451638},
    {5332.5    ,    -2181.28,    1279.95,    4.6906,        0,    0,    0.714768,    -0.699362},
    {5108.2    ,    -2429.84,    1427.73,    4.5194,        0,    0,    0.771943,    -0.635691}
};

float HordeFirePos[65][8]=//spawn points for the fire visuals (GO) in the horde base
{
    {5524.11,    -2612.73,    1483.38,    1.96198,    0,    0,    0.831047,    0.556202},
    {5514.42,    -2617.19,    1505.77,    1.82453,    0,    0,    0.790892,    0.611956},
    {5510.21,    -2624.77,    1485.34,    1.71065,    0,    0,    0.754783,    0.655974},
    {5570.72,    -2619.04,    1487.62,    0.728898,    0,    0,    0.356435,    0.93432},
    {5570.29,    -2639.37,    1487.31,    1.49308,    0,    0,    0.679104,    0.734042},
    {5583.56,    -2637.2,    1503.78,    1.46559,    0,    0,    0.668951,    0.743307},
    {5571.53,    -2626.81,    1510.99,    0.362107,    0,    0,    0.180066,    0.983654},
    {5545.97,    -2659.62,    1489.64,    5.07055,    0,    0,    0.569845,    -0.821752},
    {5557.44,    -2675.91,    1482.58,    1.70118,    0,    0,    0.751671,    0.659539},
    {5594.98,    -2742.31,    1495.51,    4.5993,        0,    0,    0.74594,    -0.666013},
    {5599.65,    -2755.6,    1505.05,    1.66896,    0,    0,    0.740947,    0.671564},
    {5565.95,    -2774.75,    1499.48,    6.22425,    0,    0,    0.0294611,    -0.999566},
    {5567.1,    -2769.7,    1511.17,    5.99257,    0,    0,    0.144799,    -0.989461},
    {5572.84,    -2774.16,    1527.06,    0.836428,    0,    0,    0.406129,    0.913816},
    {5538.32,    -2805.94,    1498.87,    4.30082,    0,    0,    0.836674,    -0.547701},
    {5515.66,    -2801.74,    1503.53,    5.57316,    0,    0,    0.347602,    -0.937642},
    {5516.76,    -2827.14,    1501.15,    0.35026,    0,    0,    0.174236,    0.984704},
    {5536.13,    -2813.51,    1537.21,    4.51681,    0,    0,    0.772765,    -0.634692},
    {5525.05,    -2825.16,    1538.53,    0.489275,    0,    0,    0.242205,    0.970225},
    {5534.42,    -2815.45,    1562.84,    4.62834,    0,    0,    0.736191,    -0.676774},
    {5519.64,    -2831.12,    1526.46,    0.611008,    0,    0,    0.300774,    0.953696},
    {5551.04,    -2827.55,    1523.5,        3.35206,    0,    0,    0.994468,    -0.10504},
    {5469.22,    -2802.87,    1503.5,        4.99509,    0,    0,    0.600436,    -0.799673},
    {5427.8,    -2737.26,    1487.12,    1.78673,    0,    0,    0.779186,    0.626793},
    {5454.1,    -2709.1,    1485.92,    3.03552,    0,    0,    0.998594,    0.0530137},
    {5436.3,    -2718.2,    1506.02,    2.7567,        0,    0,    0.981539,    0.191261},
    {5412.6,    -2740.55,    1510.79,    2.98446,    0,    0,    0.996915,    0.0784832},
    {5406.12,    -2752.48,    1521.01,    2.05769,    0,    0,    0.856705,    0.515807},
    {5445.24,    -2676.35,    1521.89,    2.91378,    0,    0,    0.99352,    0.113661},
    {5481.4,    -2665.08,    1482.23,    4.30001,    0,    0,    0.836895,    -0.547363},
    {5443.51,    -2675.44,    1487.12,    2.90986,    0,    0,    0.993295,    0.115606},
    {5391.72,    -2647.3,    1528.9,        3.76987,    0,    0,    0.951063,    -0.308997},
    {5421.09,    -2734.12,    1521.01,    2.70567,    0,    0,    0.97634,    0.216242},
    {5405.39,    -2710.33,    1533.77,    2.51324,    0,    0,    0.951052,    0.309032},
    {5423.96,    -2703.76,    1516.34,    2.79206,    0,    0,    0.984767,    0.173879},
    {5444.75,    -2735.23,    1486.37,    2.22657,    0,    0,    0.897155,    0.441715},
    {5570.98,    -2747.91,    1495.7,        5.14433,    0,    0,    0.53915,    -0.84221},
    {5567.79,    -2673.9,    1484.66,    2.72529,    0,    0,    0.978415,    0.20665},
    {5600.71,    -2696.8,    1500.42,    0.443704,    0,    0,    0.220036,    0.975492},
    {5600.7,    -2693.04,    1515.2,        5.16003,    0,    0,    0.532522,    -0.846416},
    {5627.56,    -2839.66,    1510.53,    5.41527,    0,    0,    0.420463,    -0.907309},
    {5622.02,    -2868.71,    1516.22,    2.25482,    0,    0,    0.903303,    0.429002},
    {5586.61,    -2878.97,    1510.34,    4.55604,    0,    0,    0.76017,    -0.649724},
    {5583.78,    -2843.71,    1509.54,    5.35715,    0,    0,    0.44665,    -0.894709},
    {5580.95,    -2811.3,    1513.3,        3.57587,    0,    0,    0.976518,    -0.215434},
    {5542.52,    -2869.31,    1523.13,    5.23304,    0,    0,    0.501275,    -0.865288},
    {5557.35,    -2866.36,    1518.76,    4.48299,    0,    0,    0.783388,    -0.621533},
    {5380.91,    -2849.36,    1512.81,    3.90962,    0,    0,    0.927168,    -0.374646},
    {5395.76,    -2881.41,    1521.11,    4.28426,    0,    0,    0.84118,    -0.540755},
    {5374.87,    -2859.63,    1528.98,    3.30252,    0,    0,    0.996765,    -0.0803745},
    {5356.07,    -2854.66,    1520.34,    5.83933,    0,    0,    0.220108,    -0.975475},
    {5363.01,    -2975.72,    1539.02,    4.13738,    0,    0,    0.87859,    -0.477576},
    {5336.85,    -2980.74,    1561.24,    5.11126,    0,    0,    0.553001,    -0.83318},
    {5335.23,    -2974.62,    1540.05,    5.04451,    0,    0,    0.580496,    -0.814263},
    {5422.37,    -2998.87,    1549.98,    4.51831,    0,    0,    0.772288,    -0.635272},
    {5405.54,    -3014.6,    1562.16,    5.86761,    0,    0,    0.206298,    -0.978489},
    {5427.96,    -3019.4,    1561.58,    3.53498,    0,    0,    0.980718,    -0.19543},
    {5348.12,    -2977.84,    1582.47,    3.94025,    0,    0,    0.921323,    -0.388799},
    {5331.12,    -2993.71,    1576.14,    0.0642734,    0,    0,    0.0321311,    0.999484},
    {5321.63,    -2986.55,    1552.2,        5.29503,    0,    0,    0.474219,    -0.880407},
    {5292.1,    -2914.36,    1529.52,    2.9742,        0,    0,    0.996499,    0.083601},
    {5281.77,    -2926.5,    1530.62,    1.67829,    0,    0,    0.744071,    0.6681},
    {5287.19,    -2909.94,    1543.49,    3.31192,    0,    0,    0.996376,    -0.0850591},
    {5534.15,    -2679.35,    1483.61,    0.428685,    0,    0,    0.212705,    0.977116},
    {5545.43,    -2647.82,    1483.05,    5.38848,    0,    0,    0.432578,    -0.901596}
};

hyjalAI::hyjalAI(Creature *c) : npc_escortAI(c), Summons(m_creature)
{
    pInstance = (c->GetInstanceData());
    VeinsSpawned[0] = false;
    VeinsSpawned[1] = false;
    for(uint8 i=0;i<14;i++)
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

void hyjalAI::JustSummoned(Creature *summoned)
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
    m_creature->setActive(true);
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

    // Set faction properly based on creature entry
    switch(m_creature->GetEntry())
    {
        case JAINA:
            Faction = 0;
            DoCast(m_creature, SPELL_BRILLIANCE_AURA, true);
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
    m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

    //Initialize spells
    memset(Spell, 0, sizeof(Spell));



    //Reset Instance Data for trash count
    if(pInstance)
    {
        if((!pInstance->GetData(DATA_ALLIANCE_RETREAT) && m_creature->GetEntry() == JAINA) || (pInstance->GetData(DATA_ALLIANCE_RETREAT) && m_creature->GetEntry() == THRALL))
        {
            //Reset World States
            UpdateWorldState(WORLD_STATE_WAVES, 0);
            UpdateWorldState(WORLD_STATE_ENEMY, 0);
            UpdateWorldState(WORLD_STATE_ENEMYCOUNT, 0);
            pInstance->SetData(DATA_RESET_TRASH_COUNT, 0);
        }
    }else error_log(ERROR_INST_DATA);

    //Visibility
    DoHide = true;
}

void hyjalAI::EnterEvadeMode()
{
    m_creature->InterruptNonMeleeSpells(true);
    if(m_creature->GetEntry() != JAINA)
        m_creature->RemoveAllAuras();
    m_creature->DeleteThreatList();
    m_creature->CombatStop();
    m_creature->LoadCreaturesAddon();

    if(m_creature->isAlive())
        m_creature->GetMotionMaster()->MoveTargetedHome();

    m_creature->SetLootRecipient(NULL);
}

void hyjalAI::EnterCombat(Unit *who)
{
    if(IsDummy)return;
    for(uint8 i = 0; i < 3; ++i)
        if(Spell[i].Cooldown)
            SpellTimer[i] = Spell[i].Cooldown;

    Talk(ATTACKED);
}

void hyjalAI::MoveInLineOfSight(Unit *who)
{
    if(IsDummy)return;
    if (IsBeingEscorted && !GetAttack())
        return;

    if(m_creature->getVictim() || !m_creature->canStartAttack(who))
        return;

    AttackStart(who);
}

void hyjalAI::SummonCreature(uint32 entry, float Base[4][3])
{
    uint32 random = rand()%4;
    float SpawnLoc[3];

    for(uint8 i = 0; i < 3; ++i)
    {
        SpawnLoc[i] = Base[random][i];
    }
    Creature* pCreature = NULL;
    switch(entry)
    {
            case 17906:    //GARGOYLE

                if(!FirstBossDead && (WaveCount == 1 || WaveCount == 3))
                {//summon at tower
                    pCreature = m_creature->SummonCreature(entry, SpawnPointSpecial[SPAWN_NEAR_TOWER][0]+irand(-20,20), SpawnPointSpecial[SPAWN_NEAR_TOWER][1]+irand(-20,20), SpawnPointSpecial[SPAWN_NEAR_TOWER][2]+irand(-10,10), 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 120000);
                    if(pCreature)
                        CAST_AI(hyjal_trashAI, pCreature->AI())->useFlyPath = true;
                }else{//summon at gate
                    pCreature = m_creature->SummonCreature(entry, SpawnPointSpecial[SPAWN_GARG_GATE][0]+irand(-10,10), SpawnPointSpecial[SPAWN_GARG_GATE][1]+irand(-10,10), SpawnPointSpecial[SPAWN_GARG_GATE][2]+irand(-10,10), 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 120000);
                }
                break;
            case 17907:    //FROST_WYRM ,
                if(FirstBossDead && WaveCount == 1)
                {//summon at gate
                    pCreature = m_creature->SummonCreature(entry, SpawnPointSpecial[SPAWN_WYRM_GATE][0],SpawnPointSpecial[SPAWN_WYRM_GATE][1],SpawnPointSpecial[SPAWN_WYRM_GATE][2], 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 120000);
                }else{
                    pCreature = m_creature->SummonCreature(entry, SpawnPointSpecial[SPAWN_NEAR_TOWER][0], SpawnPointSpecial[SPAWN_NEAR_TOWER][1],SpawnPointSpecial[SPAWN_NEAR_TOWER][2], 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 120000);
                    if(pCreature)
                        CAST_AI(hyjal_trashAI, pCreature->AI())->useFlyPath = true;
                }
                break;
            case 17908:    //GIANT_INFERNAL
                InfernalCount++;
                if(InfernalCount > 7)InfernalCount = 0;
                pCreature = m_creature->SummonCreature(entry, InfernalPos[InfernalCount][0], InfernalPos[InfernalCount][1], InfernalPos[InfernalCount][2], 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 120000);
                break;
            default:
                pCreature = m_creature->SummonCreature(entry, SpawnLoc[0], SpawnLoc[1], SpawnLoc[2], 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 120000);
                break;

    }

    if(pCreature)
    {
        // Increment Enemy Count to be used in World States and instance script
        ++EnemyCount;

        pCreature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
        pCreature->setActive(true);
        switch(entry)
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
                CAST_AI(hyjal_trashAI, pCreature->AI())->IsEvent = true;
                break;
        }
        if(pInstance)
        {
            if(pInstance->GetData(DATA_RAIDDAMAGE) < MINRAIDDAMAGE)
                pCreature->SetDisableReputationGain(true);//no repu for solo farming
        }
        // Check if creature is a boss.
        if (pCreature->isWorldBoss())
        {
            if(!FirstBossDead)  BossGUID[0] = pCreature->GetGUID();
            else                BossGUID[1] = pCreature->GetGUID();
            CheckTimer = 5000;
        }
    }
}

void hyjalAI::SummonNextWave(Wave wave[18], uint32 Count, float Base[4][3])
{
    // 1 in 4 chance we give a rally yell. Not sure if the chance is offilike.
    if (rand()%4 == 0)
        Talk(RALLY);

    if(!pInstance)
    {
        error_log(ERROR_INST_DATA);
        return;
    }
    InfernalCount = 0;//reset infernal count every new wave

    EnemyCount = pInstance->GetData(DATA_TRASH);
    for(uint8 i = 0; i < 18; ++i)
    {
        if(wave[Count].Mob[i])
            SummonCreature(wave[Count].Mob[i], Base);
    }

    if(!wave[Count].IsBoss)
    {
        uint32 stateValue = Count+1;
        if(FirstBossDead)
            stateValue -= 9;                                // Subtract 9 from it to give the proper wave number if we are greater than 8
        UpdateWorldState(WORLD_STATE_WAVES, stateValue);    // Set world state to our current wave number
        UpdateWorldState(WORLD_STATE_ENEMY, 1);             // Enable world state

        pInstance->SetData(DATA_TRASH, EnemyCount);         // Send data for instance script to update count

        if(!Debug)
            NextWaveTimer = wave[Count].WaveTimer;
        else
        {
            NextWaveTimer = 15000;
            debug_log("TSCR: HyjalAI: debug mode is enabled. Next Wave in 15 seconds");
        }
    }
    else
    {
        UpdateWorldState(WORLD_STATE_WAVES, 0);             // Set world state for waves to 0 to disable it.
        UpdateWorldState(WORLD_STATE_ENEMY, 1);
        UpdateWorldState(WORLD_STATE_ENEMYCOUNT, 1);        // Set World State for enemies invading to 1.
        Summon = false;
    }
    CheckTimer = 5000;
}

void hyjalAI::StartEvent(Player* player)
{
    if(!player || IsDummy)
        return;

    Talk(BEGIN);

    EventBegun = true;
    Summon = true;

    NextWaveTimer = 15000;
    CheckTimer = 5000;
    PlayerGUID = player->GetGUID();

    m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

    UpdateWorldState(WORLD_STATE_WAVES, 0);
    UpdateWorldState(WORLD_STATE_ENEMY, 0);
    UpdateWorldState(WORLD_STATE_ENEMYCOUNT, 0);

    DeSpawnVeins();
}

uint32 hyjalAI::GetInstanceData(uint32 Event)
{
    if(pInstance)
        return pInstance->GetData(Event);
    else error_log(ERROR_INST_DATA);

    return 0;
}

void hyjalAI::Talk(uint32 id)
{
    std::list<uint8> index;
    for(uint8 i = 0; i < 10; i++)
    {
        if(Faction == 0)                                    // Alliance
        {
            if(JainaQuotes[i].id == id)
                index.push_back(i);
        }
        else if(Faction == 1)                               // Horde
        {
            if(ThrallQuotes[i].id == id)
                index.push_back(i);
        }
    }

    if(index.empty())
        return;                                             // No quotes found, no use to continue

    uint8 ind = *(index.begin()) + rand()%index.size();

    int32 YellId = 0;
    if(Faction == 0)                                        // Alliance
    {
        YellId = JainaQuotes[ind].textid;
    }
    else if(Faction == 1)                                   // Horde
    {
        YellId = ThrallQuotes[ind].textid;
    }

    if (YellId)
        DoScriptText(YellId, m_creature);
}

void hyjalAI::UpdateWorldState(uint32 id, uint32 state)
{
    Map * map = m_creature->GetMap();

    if(!map->IsDungeon())
        return;

    Map::PlayerList const& players = map->GetPlayers();

    if (!players.isEmpty())
    {
            for(Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
            {
                if (Player* player = itr->getSource())
                    player->SendUpdateWorldState(id,state);
            }
    }else debug_log("TSCR: HyjalAI: UpdateWorldState, but PlayerList is empty");
}

void hyjalAI::Retreat()
{
    if(pInstance)
    {
        if(Faction == 0)
        {
            pInstance->SetData(DATA_ALLIANCE_RETREAT, 1);
            AddWaypoint(0,JainaWPs[0][0],JainaWPs[0][1],JainaWPs[0][2]);
            AddWaypoint(1,JainaWPs[1][0],JainaWPs[1][1],JainaWPs[1][2]);
            Start(false, false, false);
            SetDespawnAtEnd(false);//move to center of alliance base
        }
        if(Faction == 1)
        {
            pInstance->SetData(DATA_HORDE_RETREAT, 1);
            Creature* JainaDummy = m_creature->SummonCreature(JAINA,JainaDummySpawn[0][0],JainaDummySpawn[0][1],JainaDummySpawn[0][2],JainaDummySpawn[0][3],TEMPSUMMON_TIMED_DESPAWN,60000);
            if(JainaDummy)
            {
                JainaDummy->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                CAST_AI(hyjalAI, JainaDummy->AI())->IsDummy = true;
                DummyGuid = JainaDummy->GetGUID();
            }
            AddWaypoint(0,JainaDummySpawn[1][0],JainaDummySpawn[1][1],JainaDummySpawn[1][2]);
            Start(false, false, false);
            SetDespawnAtEnd(false);//move to center of alliance base
        }
    }
    SpawnVeins();
    Overrun = true;
    m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);//cant talk after overrun event started
}

void hyjalAI::SpawnVeins()
{
    if(Faction == 0)
    {
        if (VeinsSpawned[0])//prevent any buggers
            return;
        for (uint8 i = 0; i<7; i++)
        {
            GameObject* gem = m_creature->SummonGameObject(ANCIENT_VEIN,VeinPos[i][0],VeinPos[i][1],VeinPos[i][2],VeinPos[i][3],VeinPos[i][4],VeinPos[i][5],VeinPos[i][6],VeinPos[i][7],0);
            if(gem)
                VeinGUID[i]=gem->GetGUID();
        }
        VeinsSpawned[0] = true;
    }else{
        if (VeinsSpawned[1])
            return;
        for (uint8 i = 7; i<14; i++)
        {
            GameObject* gem = m_creature->SummonGameObject(ANCIENT_VEIN,VeinPos[i][0],VeinPos[i][1],VeinPos[i][2],VeinPos[i][3],VeinPos[i][4],VeinPos[i][5],VeinPos[i][6],VeinPos[i][7],0);
            if(gem)
                VeinGUID[i]=gem->GetGUID();
        }
        VeinsSpawned[1] = true;
    }
}

void hyjalAI::DeSpawnVeins()
{
    if(!pInstance)return;
    if(Faction == 1)
    {
        Creature* pUnit=Unit::GetCreature((*m_creature),pInstance->GetData64(DATA_JAINAPROUDMOORE));
        if (!pUnit)return;
        hyjalAI* ai = ((hyjalAI*)pUnit->AI());
        if(!ai)return;
        for (uint8 i = 0; i<7; i++)
        {
            GameObject* gem = GameObject::GetGameObject((*m_creature), ai->VeinGUID[i]);
            if(gem)
                gem->RemoveFromWorld();
        }
    }else if (Faction)
    {
        Creature* pUnit=Unit::GetCreature((*m_creature),pInstance->GetData64(DATA_THRALL));
        if (!pUnit)return;
        hyjalAI* ai = ((hyjalAI*)pUnit->AI());
        if(!ai)return;
        for (uint8 i = 7; i<14; i++)
        {
            GameObject* gem = GameObject::GetGameObject((*m_creature), ai->VeinGUID[i]);
            if(gem)
                gem->RemoveFromWorld();
        }
    }
}

void hyjalAI::UpdateAI(const uint32 diff)
{
    if(IsDummy)
    {
        if(MassTeleportTimer < diff && DoMassTeleport)
        {
            m_creature->CastSpell(m_creature,SPELL_MASS_TELEPORT,false);
            DoMassTeleport = false;
        }else MassTeleportTimer -= diff;
        return;
    }
    if(DoHide)
    {
        DoHide = false;
        switch(m_creature->GetEntry())
        {
            case JAINA:
                if(pInstance->GetData(DATA_ALLIANCE_RETREAT))
                {
                    m_creature->SetVisibility(VISIBILITY_OFF);
                    HideNearPos(m_creature->GetPositionX(), m_creature->GetPositionY());
                    HideNearPos(5037.76, -1889.71);
                    for(uint8 i = 0; i < 92; i++)//summon fires
                        m_creature->SummonGameObject(FLAMEOBJECT,AllianceFirePos[i][0],AllianceFirePos[i][1],AllianceFirePos[i][2],AllianceFirePos[i][3],AllianceFirePos[i][4],AllianceFirePos[i][5],AllianceFirePos[i][6],AllianceFirePos[i][7],0);

                }
                else m_creature->SetVisibility(VISIBILITY_ON);
                break;
            case THRALL: //thrall
                if(pInstance->GetData(DATA_HORDE_RETREAT))
                {
                    m_creature->SetVisibility(VISIBILITY_OFF);
                    HideNearPos(m_creature->GetPositionX(), m_creature->GetPositionY());
                    HideNearPos(5563, -2763.19);
                    HideNearPos(5542.2, -2629.36);
                    for(uint8 i = 0; i < 65; i++)//summon fires
                        m_creature->SummonGameObject(FLAMEOBJECT,HordeFirePos[i][0],HordeFirePos[i][1],HordeFirePos[i][2],HordeFirePos[i][3],HordeFirePos[i][4],HordeFirePos[i][5],HordeFirePos[i][6],HordeFirePos[i][7],0);

                }
                else m_creature->SetVisibility(VISIBILITY_ON);
                break;
        }
    }
    if(DoRespawn)
    {
        if(RespawnTimer < diff)
        {
            DoRespawn = false;
            RespawnNearPos(m_creature->GetPositionX(), m_creature->GetPositionY());
            if(Faction == 0)
            {
                RespawnNearPos(5037.76, -1889.71);
            }else if (Faction == 1)
            {
                RespawnNearPos(5563, -2763.19);
                RespawnNearPos(5542.2, -2629.36);
            }
            m_creature->SetVisibility(VISIBILITY_ON);
        }else{
            RespawnTimer -= diff;
            m_creature->SetVisibility(VISIBILITY_OFF);
        }
        return;
    }
    if(Overrun)
        DoOverrun(Faction, diff);
    if(bRetreat)
    {
        if(RetreatTimer < diff)
        {
            IsDummy = true;
            bRetreat = false;
            HideNearPos(m_creature->GetPositionX(), m_creature->GetPositionY());
            switch(m_creature->GetEntry())
            {
                case JAINA://jaina
                    HideNearPos(5037.76, -1889.71);
                    break;
                case THRALL://thrall
                    HideNearPos(5563, -2763.19);
                    HideNearPos(5542.2, -2629.36);
                    HideNearPos(5603.75, -2853.12);
                    break;
            }
            m_creature->SetVisibility(VISIBILITY_OFF);
        }else RetreatTimer -= diff;
    }

    if(!EventBegun)
        return;

    if(Summon)
    {
        if(pInstance && EnemyCount)
        {
            EnemyCount = pInstance->GetData(DATA_TRASH);
            if(!EnemyCount)
                NextWaveTimer = 5000;
        }

        if(NextWaveTimer < diff)
        {
            if(Faction == 0)
                SummonNextWave(AllianceWaves, WaveCount, AllianceBase);
            else if(Faction == 1)
                SummonNextWave(HordeWaves, WaveCount, HordeBase);
            ++WaveCount;
        }else NextWaveTimer -= diff;
    }

    if(CheckTimer < diff)
    {
        for(uint8 i = 0; i < 2; ++i)
        {
            if(BossGUID[i])
            {
                Unit* pUnit = Unit::GetUnit((*m_creature), BossGUID[i]);
                if(pUnit && (!pUnit->isAlive()))
                {
                    if(BossGUID[i] == BossGUID[0])
                    {
                        Talk(INCOMING);
                        FirstBossDead = true;
                    }
                    else if(BossGUID[i] == BossGUID[1])
                    {
                        Talk(SUCCESS);
                        SecondBossDead = true;
                    }
                    EventBegun = false;
                    CheckTimer = 0;
                    m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    BossGUID[i] = 0;
                    UpdateWorldState(WORLD_STATE_ENEMY, 0); // Reset world state for enemies to disable it
                }
            }
        }
        CheckTimer = 5000;
    }else CheckTimer -= diff;

    if(!UpdateVictim())
        return;

    for(uint8 i = 0; i < 3; ++i)
    {
        if(Spell[i].SpellId)
        {
            if(SpellTimer[i] < diff)
            {
                if(m_creature->IsNonMeleeSpellCasted(false))
                    m_creature->InterruptNonMeleeSpells(false);

                Unit* target = NULL;

                switch(Spell[i].TargetType)
                {
                    case TARGETTYPE_SELF: target = m_creature; break;
                    case TARGETTYPE_RANDOM: target = SelectUnit(SELECT_TARGET_RANDOM, 0); break;
                    case TARGETTYPE_VICTIM: target = m_creature->getVictim(); break;
                }

                if(target && target->isAlive())
                {
                    DoCast(target, Spell[i].SpellId);
                    SpellTimer[i] = Spell[i].Cooldown;
                }
            }else SpellTimer[i] -= diff;
        }
    }

    DoMeleeAttackIfReady();
}
void hyjalAI::JustDied(Unit* killer)
{
    if(IsDummy)return;
    m_creature->Respawn();
    m_creature->SetVisibility(VISIBILITY_OFF);
    DoRespawn = true;
    RespawnTimer = 120000;
    Talk(DEATH);
    Summons.DespawnAll();//despawn all wave's summons
    if(pInstance)
    {//reset encounter if boss is despawned (ex: thrall is killed, boss despawns, event stucks at inprogress)
        if(pInstance->GetData(DATA_RAGEWINTERCHILLEVENT) == IN_PROGRESS)
            pInstance->SetData(DATA_RAGEWINTERCHILLEVENT, NOT_STARTED);
        if(pInstance->GetData(DATA_ANETHERONEVENT) == IN_PROGRESS)
            pInstance->SetData(DATA_ANETHERONEVENT, NOT_STARTED);
        if(pInstance->GetData(DATA_KAZROGALEVENT) == IN_PROGRESS)
            pInstance->SetData(DATA_KAZROGALEVENT, NOT_STARTED);
        if(pInstance->GetData(DATA_AZGALOREVENT) == IN_PROGRESS)
            pInstance->SetData(DATA_AZGALOREVENT, NOT_STARTED);
        pInstance->SetData(DATA_RESET_RAIDDAMAGE, NULL);//reset damage on die
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
    Trinity::AllFriendlyCreaturesInGrid creature_check(m_creature);
    Trinity::CreatureListSearcher<Trinity::AllFriendlyCreaturesInGrid> creature_searcher(m_creature, creatures, creature_check);
    TypeContainerVisitor
        <Trinity::CreatureListSearcher<Trinity::AllFriendlyCreaturesInGrid>,
        GridTypeMapContainer> creature_visitor(creature_searcher);

    CellLock<GridReadGuard> cell_lock(cell, pair);
                                                            // Get Creatures
    cell_lock->Visit(cell_lock, creature_visitor, *(m_creature->GetMap()));

    if(!creatures.empty())
    {
        for(std::list<Creature*>::iterator itr = creatures.begin(); itr != creatures.end(); ++itr)
        {
            (*itr)->SetVisibility(VISIBILITY_OFF);
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
    Trinity::WorldObjectWorker<Trinity::RespawnDo> worker(m_creature, u_do);
    TypeContainerVisitor<Trinity::WorldObjectWorker<Trinity::RespawnDo>, GridTypeMapContainer > obj_worker(worker);
    CellLock<GridReadGuard> cell_lock(cell, p);
    cell_lock->Visit(cell_lock, obj_worker, *m_creature->GetMap());
}
void hyjalAI::WaypointReached(uint32 i)
{
    if(i == 1 || (i == 0 && m_creature->GetEntry() == THRALL))
    {
        m_creature->MonsterYell("Hurry, we don't have much time",0,0);
        WaitForTeleport = true;
        TeleportTimer = 20000;
        if(m_creature->GetEntry() == JAINA)
            m_creature->CastSpell(m_creature,SPELL_MASS_TELEPORT,false);
        if(m_creature->GetEntry() == THRALL && DummyGuid)
        {
            Unit* Dummy = Unit::GetUnit((*m_creature),DummyGuid);
            if(Dummy)
            {
                CAST_AI(hyjalAI, CAST_CRE(Dummy)->AI())->DoMassTeleport = true;
                CAST_AI(hyjalAI, CAST_CRE(Dummy)->AI())->MassTeleportTimer = 20000;
                Dummy->CastSpell(m_creature,SPELL_MASS_TELEPORT,false);
            }
        }
        //do some talking
        //all alive guards walk near here
        CellPair pair(Trinity::ComputeCellPair(m_creature->GetPositionX(), m_creature->GetPositionY()));
        Cell cell(pair);
        cell.data.Part.reserved = ALL_DISTRICT;
        cell.SetNoCreate();

        // First get all creatures.
        std::list<Creature*> creatures;
        Trinity::AllFriendlyCreaturesInGrid creature_check(m_creature);
        Trinity::CreatureListSearcher<Trinity::AllFriendlyCreaturesInGrid> creature_searcher(m_creature, creatures, creature_check);
        TypeContainerVisitor
            <Trinity::CreatureListSearcher<Trinity::AllFriendlyCreaturesInGrid>,
            GridTypeMapContainer> creature_visitor(creature_searcher);

        CellLock<GridReadGuard> cell_lock(cell, pair);
        cell_lock->Visit(cell_lock, creature_visitor, *(m_creature->GetMap()));

        if(!creatures.empty())
        {
            for(std::list<Creature*>::iterator itr = creatures.begin(); itr != creatures.end(); ++itr)
            {
                if((*itr) && (*itr)->isAlive() && (*itr) != m_creature && (*itr)->GetEntry() != JAINA)
                {
                    if((*itr)->GetDistance(m_creature) >= 60)
                        (*itr)->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                    float x, y, z;
                    (*itr)->SetDefaultMovementType(IDLE_MOTION_TYPE);
                    (*itr)->GetMotionMaster()->Initialize();
                    float range = 10;
                    if(m_creature->GetEntry() == THRALL)range = 20;
                    m_creature->GetNearPoint(m_creature, x, y, z, range, 0, m_creature->GetAngle((*itr)));
                    (*itr)->GetMotionMaster()->MovePoint(0, x+irand(-5,5), y+irand(-5,5), m_creature->GetPositionZ());
                }
            }
        }
    }
}
void hyjalAI::DoOverrun(uint32 faction, const uint32 diff)
{
    npc_escortAI::UpdateAI(diff);
    if(WaitForTeleport)
    {
        if(TeleportTimer < diff)
        {
            CellPair pair(Trinity::ComputeCellPair(m_creature->GetPositionX(), m_creature->GetPositionY()));
            Cell cell(pair);
            cell.data.Part.reserved = ALL_DISTRICT;
            cell.SetNoCreate();

            std::list<Creature*> creatures;
            Trinity::AllFriendlyCreaturesInGrid creature_check(m_creature);
            Trinity::CreatureListSearcher<Trinity::AllFriendlyCreaturesInGrid> creature_searcher(m_creature, creatures, creature_check);
            TypeContainerVisitor
                <Trinity::CreatureListSearcher<Trinity::AllFriendlyCreaturesInGrid>,
                GridTypeMapContainer> creature_visitor(creature_searcher);

            CellLock<GridReadGuard> cell_lock(cell, pair);
            cell_lock->Visit(cell_lock, creature_visitor, *(m_creature->GetMap()));

            if(!creatures.empty())
            {
                for(std::list<Creature*>::iterator itr = creatures.begin(); itr != creatures.end(); ++itr)
                {
                    if((*itr) && (*itr)->isAlive())
                    {
                        (*itr)->CastSpell(*itr, SPELL_TELEPORT_VISUAL, true);
                        (*itr)->setFaction(35);//make them friendly so mobs won't attack them
                        (*itr)->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    }
                }
                DoCast(m_creature, SPELL_TELEPORT_VISUAL);
                bRetreat = true;
                RetreatTimer = 1000;
            }

            WaitForTeleport = false;
            Teleported = true;
        }TeleportTimer -= diff;
    }
    if(!Teleported)
        return;
    Overrun = false;//execute once
    switch(faction)
    {
        case 0://alliance
            for(uint8 i = 0; i < 92; i++)//summon fires
                m_creature->SummonGameObject(FLAMEOBJECT,AllianceFirePos[i][0],AllianceFirePos[i][1],AllianceFirePos[i][2],AllianceFirePos[i][3],AllianceFirePos[i][4],AllianceFirePos[i][5],AllianceFirePos[i][6],AllianceFirePos[i][7],0);

            for(uint8 i = 0; i < 25; i++)//summon 25 ghouls
            {
                uint8 r = rand()%4;
                Creature* pUnit = m_creature->SummonCreature(GHOUL, AllianceBase[r][0]+irand(-15,15), AllianceBase[r][1]+irand(-15,15), AllianceBase[r][2], 0, TEMPSUMMON_MANUAL_DESPAWN, 2*60*1000);
                if(pUnit)
                {
                    CAST_AI(hyjal_trashAI, pUnit->AI())->faction = Faction;
                    CAST_AI(hyjal_trashAI, pUnit->AI())->IsOverrun = true;
                    CAST_AI(hyjal_trashAI, pUnit->AI())->OverrunType = i;
                    pUnit->setActive(true);
                }
            }
            for(uint8 i = 0; i < 3; i++)//summon 3 abominations
            {
                uint8 r = rand()%4;
                Creature* pUnit = m_creature->SummonCreature(ABOMINATION, AllianceBase[r][0]+irand(-15,15), AllianceBase[r][1]+irand(-15,15), AllianceBase[r][2], 0, TEMPSUMMON_MANUAL_DESPAWN, 2*60*1000);
                if(pUnit)
                {
                    CAST_AI(hyjal_trashAI, pUnit->AI())->faction = Faction;
                    CAST_AI(hyjal_trashAI, pUnit->AI())->IsOverrun = true;
                    CAST_AI(hyjal_trashAI, pUnit->AI())->OverrunType = i;
                    pUnit->setActive(true);
                }
            }
            for(uint8 i = 0; i < 5; i++)//summon 5 gargoyles
            {
                Creature* pUnit = m_creature->SummonCreature(GARGOYLE, AllianceOverrunGargPos[i][0], AllianceOverrunGargPos[i][1], AllianceOverrunGargPos[i][2], AllianceOverrunGargPos[i][3], TEMPSUMMON_MANUAL_DESPAWN, 2*60*1000);
                if(pUnit)
                {
                    pUnit->SetHomePosition(AllianceOverrunGargPos[i][0], AllianceOverrunGargPos[i][1], AllianceOverrunGargPos[i][2], AllianceOverrunGargPos[i][3]);
                    CAST_AI(hyjal_trashAI, pUnit->AI())->faction = Faction;
                    CAST_AI(hyjal_trashAI, pUnit->AI())->IsOverrun = true;
                    CAST_AI(hyjal_trashAI, pUnit->AI())->OverrunType = i;
                    pUnit->setActive(true);
                }
            }
            break;
        case 1://horde
            for(uint8 i = 0; i < 65; i++)//summon fires
                m_creature->SummonGameObject(FLAMEOBJECT,HordeFirePos[i][0],HordeFirePos[i][1],HordeFirePos[i][2],HordeFirePos[i][3],HordeFirePos[i][4],HordeFirePos[i][5],HordeFirePos[i][6],HordeFirePos[i][7],0);

            for(uint8 i = 0; i < 26; i++)//summon infernals
            {
                Creature* pUnit = m_creature->SummonCreature(GIANT_INFERNAL, InfernalSPWP[i][0], InfernalSPWP[i][1], InfernalSPWP[i][2], InfernalSPWP[i][3], TEMPSUMMON_MANUAL_DESPAWN, 2*60*1000);
                if(pUnit)
                {
                    pUnit->SetHomePosition(InfernalSPWP[i][0], InfernalSPWP[i][1], InfernalSPWP[i][2], InfernalSPWP[i][3]);
                    CAST_AI(hyjal_trashAI, pUnit->AI())->faction = Faction;
                    CAST_AI(hyjal_trashAI, pUnit->AI())->IsOverrun = true;
                    CAST_AI(hyjal_trashAI, pUnit->AI())->OverrunType = i;
                    pUnit->setActive(true);
                }
            }
            for(uint8 i = 0; i < 25; i++)//summon 25 ghouls
            {
                uint8 r = rand()%4;
                Creature* pUnit = m_creature->SummonCreature(GHOUL, HordeBase[r][0]+irand(-15,15), HordeBase[r][1]+irand(-15,15), HordeBase[r][2], 0, TEMPSUMMON_MANUAL_DESPAWN, 2*60*1000);
                if(pUnit)
                {
                    CAST_AI(hyjal_trashAI, pUnit->AI())->faction = Faction;
                    CAST_AI(hyjal_trashAI, pUnit->AI())->IsOverrun = true;
                    CAST_AI(hyjal_trashAI, pUnit->AI())->OverrunType = i;
                    pUnit->setActive(true);
                }
            }
            for(uint8 i = 0; i < 5; i++)//summon 5 abominations
            {
                uint8 r = rand()%4;
                Creature* pUnit = m_creature->SummonCreature(ABOMINATION, HordeBase[r][0]+irand(-15,15), HordeBase[r][1]+irand(-15,15), HordeBase[r][2], 0, TEMPSUMMON_MANUAL_DESPAWN, 2*60*1000);
                if(pUnit)
                {
                    CAST_AI(hyjal_trashAI, pUnit->AI())->faction = Faction;
                    CAST_AI(hyjal_trashAI, pUnit->AI())->IsOverrun = true;
                    CAST_AI(hyjal_trashAI, pUnit->AI())->OverrunType = i;
                    pUnit->setActive(true);
                }
            }
            break;
    }
}