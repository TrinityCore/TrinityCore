-- Repositions existing spawns
DELETE FROM `creature` WHERE `guid` IN (86719,1117,152259,86238);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(86719,21778,530,1,1,-2665.374,2058.359,116.3339,3.106686,300,0,0), -- Doctor Gutrick
(1117,21779,530,1,1,-2695.573,2633.819,74.68369,4.363323,300,0,0), -- Doctor Maleficus 
(152259,21789,530,1,1,-2725.632,2712.664,122.433,5.201081,300,0,0), -- Nakansi
(86238,21790,530,1,1,-2764.224,1980.787,167.5258,1.797689,300,0,0); -- Plexi

-- New Spawns
SET @CGUID := 213306;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+67;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0,21961,530,1,1,-2624.587,2645.83,75.00489,4.70832,300,0,0),-- Cataclysm Overseer
(@CGUID+1,21961,530,1,1,-2658.601,2642.981,74.9452,4.725823,300,0,0),-- Cataclysm Overseer
(@CGUID+2,21961,530,1,1,-2708.177,2097.77,117.1897,4.686018,300,0,0),-- Cataclysm Overseer
(@CGUID+3,21961,530,1,1,-2740.772,2448.112,93.38111,4.805989,300,0,0),-- Cataclysm Overseer
(@CGUID+4,21961,530,1,1,-2742.03,2059.698,116.7964,4.681119,300,0,0),-- Cataclysm Overseer
(@CGUID+5,21961,530,1,1,-2758.742,2243.91,93.21526,1.552272,300,0,0),-- Cataclysm Overseer
(@CGUID+6,21961,530,1,1,-2774.287,2263.532,92.94308,4.718167,300,0,0),-- Cataclysm Overseer
(@CGUID+7,21961,530,1,1,-2775.945,2361.191,93.28397,4.685721,300,0,0),-- Cataclysm Overseer
(@CGUID+8,21753,530,1,1,-2622.266,2628.122,74.8339,4.716521,300,0,0), -- Shadow Council Felsworn
(@CGUID+9,21753,530,1,1,-2623.208,2548.756,74.8182,1.556335,300,0,0), -- Shadow Council Felsworn
(@CGUID+10,21753,530,1,1,-2636.863,2574.913,74.9474,4.696648,300,0,0), -- Shadow Council Felsworn
(@CGUID+11,21753,530,1,1,-2636.998,2607.602,74.69077,1.563033,300,0,0), -- Shadow Council Felsworn
(@CGUID+12,21753,530,1,1,-2652.578,2534.493,74.78423,4.71961,300,0,0), -- Shadow Council Felsworn
(@CGUID+13,21753,530,1,1,-2653.093,2619.055,74.94731,4.703067,300,0,0), -- Shadow Council Felsworn
(@CGUID+14,21753,530,1,1,-2669.707,2604.662,74.95037,1.581261,300,0,0), -- Shadow Council Felsworn
(@CGUID+15,21753,530,1,1,-2669.842,2537.49,74.45392,1.606841,300,0,0), -- Shadow Council Felsworn
(@CGUID+16,21753,530,1,1,-2679.377,2058.013,116.8943,4.688863,300,0,0), -- Shadow Council Felsworn
(@CGUID+17,21753,530,1,1,-2683.737,2545.338,74.33199,4.702662,300,0,0), -- Shadow Council Felsworn
(@CGUID+18,21753,530,1,1,-2684.123,2618.183,74.8682,4.739147,300,0,0), -- Shadow Council Felsworn
(@CGUID+19,21753,530,1,1,-2695.207,2038.744,117.3595,4.693588,300,0,0), -- Shadow Council Felsworn
(@CGUID+20,21753,530,1,1,-2706.087,2455.823,92.19871,3.647834,300,0,0), -- Shadow Council Felsworn
(@CGUID+21,21753,530,1,1,-2712.173,2052.405,117.1693,4.725927,300,0,0), -- Shadow Council Felsworn
(@CGUID+22,21753,530,1,1,-2729.676,2036.5,117.2379,4.690808,300,0,0), -- Shadow Council Felsworn
(@CGUID+23,21753,530,1,1,-2729.925,2437.338,92.79486,4.70655,300,0,0), -- Shadow Council Felsworn
(@CGUID+24,21753,530,1,1,-2744.948,2056.218,117.2141,4.698718,300,0,0), -- Shadow Council Felsworn
(@CGUID+25,21753,530,1,1,-2745.869,2401.989,92.68388,1.562935,300,0,0), -- Shadow Council Felsworn
(@CGUID+26,21753,530,1,1,-2747.979,2331.009,93.2812,4.724142,300,0,0), -- Shadow Council Felsworn
(@CGUID+27,21753,530,1,1,-2761.9,2082.233,116.1504,4.676732,300,0,0), -- Shadow Council Felsworn
(@CGUID+28,21753,530,1,1,-2761.907,2255.418,93.29506,4.709726,300,0,0), -- Shadow Council Felsworn
(@CGUID+29,21753,530,1,1,-2761.913,2350.896,93.31357,4.714221,300,0,0), -- Shadow Council Felsworn
(@CGUID+30,21753,530,1,1,-2762.018,2436.756,93.38111,4.681306,300,0,0), -- Shadow Council Felsworn
(@CGUID+31,21753,530,1,1,-2776.212,2418.02,93.31845,1.551268,300,0,0), -- Shadow Council Felsworn
(@CGUID+32,21753,530,1,1,-2777.241,2356.42,93.10667,4.704577,300,0,0), -- Shadow Council Felsworn
(@CGUID+33,21753,530,1,1,-2779.028,2207.845,93.30978,1.520008,300,0,0), -- Shadow Council Felsworn
(@CGUID+34,21753,530,1,1,-2795.168,2237.445,93.36533,4.720132,300,0,0), -- Shadow Council Felsworn
(@CGUID+35,21754,530,1,1,-2628.103,2627.774,74.94058,1.536073,300,0,0), -- Shadow Council Zealot
(@CGUID+36,21754,530,1,1,-2644.939,2625.912,74.56854,1.564112,300,0,0), -- Shadow Council Zealot
(@CGUID+37,21754,530,1,1,-2661.52,2625.054,74.94732,4.703033,300,0,0), -- Shadow Council Zealot
(@CGUID+38,21754,530,1,1,-2677.226,2647.989,74.92176,1.605468,300,0,0), -- Shadow Council Zealot
(@CGUID+39,21754,530,1,1,-2690.104,2048.885,117.4553,4.713993,300,0,0), -- Shadow Council Zealot
(@CGUID+40,21754,530,1,1,-2705.832,2043.225,117.2379,4.707129,300,0,0), -- Shadow Council Zealot
(@CGUID+41,21754,530,1,1,-2720.884,2436.895,92.55349,1.570773,300,0,0), -- Shadow Council Zealot
(@CGUID+42,21754,530,1,1,-2722.164,2058.124,117.2379,4.708858,300,0,0), -- Shadow Council Zealot
(@CGUID+43,21754,530,1,1,-2737.436,2437.372,92.92113,4.710443,300,0,0), -- Shadow Council Zealot
(@CGUID+44,21754,530,1,1,-2738.531,2051.189,117.008,4.708483,300,0,0), -- Shadow Council Zealot
(@CGUID+45,21754,530,1,1,-2753.18,2060.903,116.6311,4.686984,300,0,0), -- Shadow Council Zealot
(@CGUID+46,21754,530,1,1,-2754.035,2446.205,93.35241,4.702646,300,0,0), -- Shadow Council Zealot
(@CGUID+47,21754,530,1,1,-2756.416,2325.13,92.8938,4.708452,300,0,0), -- Shadow Council Zealot
(@CGUID+48,21754,530,1,1,-2757.087,2292.479,92.72278,4.704577,300,0,0), -- Shadow Council Zealot
(@CGUID+49,21754,530,1,1,-2769.958,2445.585,93.39021,4.709271,300,0,0), -- Shadow Council Zealot
(@CGUID+50,21754,530,1,1,-2770.757,2286.646,93.37387,1.554465,300,0,0), -- Shadow Council Zealot
(@CGUID+51,21754,530,1,1,-2770.834,2304.946,93.35271,4.728845,300,0,0), -- Shadow Council Zealot
(@CGUID+52,21754,530,1,1,-2784.362,2422.751,92.59094,4.731622,300,0,0), -- Shadow Council Zealot
(@CGUID+53,21754,530,1,1,-2785.126,2319.199,92.42504,1.584508,300,0,0), -- Shadow Council Zealot
(@CGUID+54,21754,530,1,1,-2785.269,2251.403,93.20892,4.702585,300,0,0), -- Shadow Council Zealot
(@CGUID+55,21754,530,1,1,-2803.432,2250.95,92.96349,1.521959,300,0,0), -- Shadow Council Zealot
(@CGUID+56,21949,530,1,1,-2634.423,2668.06,74.95636,4.625123,300,0,0), -- Fel Reaver Sentinel
(@CGUID+57,21949,530,1,1,-2644.064,2666.833,75.00764,4.660029,300,0,0), -- Fel Reaver Sentinel
(@CGUID+58,21949,530,1,1,-2654.26,2667.904,74.91562,4.712389,300,0,0), -- Fel Reaver Sentinel
(@CGUID+59,21949,530,1,1,-2728.15,2020.016,116.1963,1.797689,300,0,0), -- Fel Reaver Sentinel
(@CGUID+60,21949,530,1,1,-2752.245,2024.444,116.1941,0.8203048,300,0,0), -- Fel Reaver Sentinel
(@CGUID+61,21949,530,1,1,-2759.59,2031.663,116.029,0.7330383,300,0,0), -- Fel Reaver Sentinel
(@CGUID+62,19353,530,1,1,-2758.158,1950.055,163.0797,0.171564,300,0,0), -- Wildhammer Guard
(@CGUID+63,19353,530,1,1,-2762.693,1979.738,167.5258,1.867502,300,0,0), -- Wildhammer Guard
(@CGUID+64,19353,530,1,1,-2765.28,1979.205,167.5258,1.972222,300,0,0), -- Wildhammer Guard
(@CGUID+65,19362,530,1,1,-2680.367,2702.561,102.4103,4.429259,300,0,0), -- Kor'kron Defender
(@CGUID+66,19362,530,1,1,-2723.378,2714.348,122.4363,4.921828,300,0,0), -- Kor'kron Defender
(@CGUID+67,19362,530,1,1,-2728.28,2712.981,122.429,5.305801,300,0,0), -- Kor'kron Defender
(@CGUID+68,21960,530,1,1,-2662.274,2637.847,74.94393,3.228831,300,0,0), -- Gan'arg Technician
(@CGUID+69,21960,530,1,1,-2662.334,2627.642,74.94731,3.217441,300,0,0), -- Gan'arg Technician
(@CGUID+70,21960,530,1,1,-2662.363,2576.12,74.80489,3.146482,300,0,0), -- Gan'arg Technician
(@CGUID+71,21960,530,1,1,-2662.44,2605.669,74.94731,3.090388,300,0,0), -- Gan'arg Technician
(@CGUID+72,21960,530,1,1,-2662.484,2605.247,74.94731,2.984356,300,0,0), -- Gan'arg Technician
(@CGUID+73,21960,530,1,1,-2662.589,2616.999,74.94731,3.269433,300,0,0), -- Gan'arg Technician
(@CGUID+74,21960,530,1,1,-2662.651,2617.355,74.94731,3.359917,300,0,0), -- Gan'arg Technician
(@CGUID+75,21960,530,1,1,-2662.696,2649.217,74.94393,2.939052,300,0,0), -- Gan'arg Technician
(@CGUID+76,21960,530,1,1,-2662.72,2551.947,74.94743,3.279413,300,0,0), -- Gan'arg Technician
(@CGUID+77,21960,530,1,1,-2662.768,2585.632,74.94741,2.939708,300,0,0), -- Gan'arg Technician
(@CGUID+78,21960,530,1,1,-2662.919,2616.957,74.94731,3.269846,300,0,0), -- Gan'arg Technician
(@CGUID+79,21960,530,1,1,-2663.48,2640.375,74.94393,3.944187,300,0,0), -- Gan'arg Technician
(@CGUID+80,21960,530,1,1,-2679.141,2589.499,74.94743,3.1772,300,0,0), -- Gan'arg Technician
(@CGUID+81,21960,530,1,1,-2680.452,2119.558,117.2397,3.628669,300,0,0), -- Gan'arg Technician
(@CGUID+82,21960,530,1,1,-2680.883,2536.066,74.91338,1.53924,300,0,0), -- Gan'arg Technician
(@CGUID+83,21960,530,1,1,-2681.474,2105.147,117.2397,2.234858,300,0,0), -- Gan'arg Technician
(@CGUID+84,21960,530,1,1,-2684.377,2104.689,117.2397,1.970172,300,0,0), -- Gan'arg Technician
(@CGUID+85,21960,530,1,1,-2685.436,2649.809,74.96772,6.005017,300,0,0), -- Gan'arg Technician
(@CGUID+86,21960,530,1,1,-2687.952,2058.775,117.2378,0.4311885,300,0,0), -- Gan'arg Technician
(@CGUID+87,21960,530,1,1,-2688.315,2060.593,117.2378,6.246561,300,0,0), -- Gan'arg Technician
(@CGUID+88,21960,530,1,1,-2696.139,2108.279,117.2397,3.165622,300,0,0), -- Gan'arg Technician
(@CGUID+89,21960,530,1,1,-2696.204,2131.748,117.2397,3.473983,300,0,0), -- Gan'arg Technician
(@CGUID+90,21960,530,1,1,-2696.365,2059.025,117.2379,2.720629,300,0,0), -- Gan'arg Technician
(@CGUID+91,21960,530,1,1,-2696.47,2081.015,117.2379,2.646988,300,0,0), -- Gan'arg Technician
(@CGUID+92,21960,530,1,1,-2697.003,2492.952,91.17992,3.31027,300,0,0), -- Gan'arg Technician
(@CGUID+93,21960,530,1,1,-2697.313,2079.943,117.2379,2.304487,300,0,0), -- Gan'arg Technician
(@CGUID+94,21960,530,1,1,-2697.706,2121.994,117.0979,4.042038,300,0,0), -- Gan'arg Technician
(@CGUID+95,21960,530,1,1,-2699.329,2034.668,117.3073,1.784621,300,0,0), -- Gan'arg Technician
(@CGUID+96,21960,530,1,1,-2699.708,2464.722,92.82695,1.771426,300,0,0), -- Gan'arg Technician
(@CGUID+97,21960,530,1,1,-2699.817,2483.558,93.37987,4.436833,300,0,0), -- Gan'arg Technician
(@CGUID+98,21960,530,1,1,-2703.914,2059.765,117.2379,0.2255644,300,0,0), -- Gan'arg Technician
(@CGUID+99,21960,530,1,1,-2703.966,2071.468,117.2379,6.269042,300,0,0), -- Gan'arg Technician
(@CGUID+100,21960,530,1,1,-2704.035,2117.757,117.2379,0.2795732,300,0,0), -- Gan'arg Technician
(@CGUID+101,21960,530,1,1,-2712.5,2504.166,93.08694,3.532249,300,0,0), -- Gan'arg Technician
(@CGUID+102,21960,530,1,1,-2712.5,2504.166,93.08694,3.532249,300,0,0), -- Gan'arg Technician
(@CGUID+103,21960,530,1,1,-2712.701,2481.473,93.32631,3.212119,300,0,0), -- Gan'arg Technician
(@CGUID+104,21960,530,1,1,-2712.728,2109.292,116.2379,3.765052,300,0,0), -- Gan'arg Technician
(@CGUID+105,21960,530,1,1,-2712.986,2130.237,117.2379,3.257504,300,0,0), -- Gan'arg Technician
(@CGUID+106,21960,530,1,1,-2713.081,2461.817,92.19871,3.716504,300,0,0), -- Gan'arg Technician
(@CGUID+107,21960,530,1,1,-2713.168,2461.937,92.35677,3.753464,300,0,0), -- Gan'arg Technician
(@CGUID+108,21960,530,1,1,-2714.23,2484.344,93.32631,4.049511,300,0,0), -- Gan'arg Technician
(@CGUID+109,21960,530,1,1,-2714.616,2072.605,117.2379,3.228679,300,0,0), -- Gan'arg Technician
(@CGUID+110,21960,530,1,1,-2714.7,2506.686,92.91842,4.274538,300,0,0), -- Gan'arg Technician
(@CGUID+111,21960,530,1,1,-2716.16,2474.859,93.32631,1.765639,300,0,0), -- Gan'arg Technician
(@CGUID+112,21960,530,1,1,-2716.42,2496.898,93.32631,4.638556,300,0,0), -- Gan'arg Technician
(@CGUID+113,21960,530,1,1,-2716.48,2507.077,93.11801,4.733479,300,0,0), -- Gan'arg Technician
(@CGUID+114,21960,530,1,1,-2716.613,2117.148,117.2379,1.361349,300,0,0), -- Gan'arg Technician
(@CGUID+115,21960,530,1,1,-2717.775,2108.599,116.8502,4.792531,300,0,0), -- Gan'arg Technician
(@CGUID+116,21960,530,1,1,-2718.241,2141.993,117.1699,4.687004,300,0,0), -- Gan'arg Technician
(@CGUID+117,21960,530,1,1,-2720.366,2482.769,93.32631,5.8778,300,0,0), -- Gan'arg Technician
(@CGUID+118,21960,530,1,1,-2729.103,2480.981,93.32631,3.142375,300,0,0), -- Gan'arg Technician
(@CGUID+119,21960,530,1,1,-2729.506,2430.046,92.51438,3.505173,300,0,0), -- Gan'arg Technician
(@CGUID+120,21960,530,1,1,-2729.6,2505.105,93.33694,3.867108,300,0,0), -- Gan'arg Technician
(@CGUID+121,21960,530,1,1,-2731.765,2079.603,117.2379,2.045345,300,0,0), -- Gan'arg Technician
(@CGUID+122,21960,530,1,1,-2731.941,2467.264,93.3752,1.960836,300,0,0), -- Gan'arg Technician
(@CGUID+123,21960,530,1,1,-2732.936,2093.803,117.2379,2.337537,300,0,0), -- Gan'arg Technician
(@CGUID+124,21960,530,1,1,-2736.649,2426.526,92.20086,0.5521232,300,0,0), -- Gan'arg Technician
(@CGUID+125,21960,530,1,1,-2737.314,2073.677,117.2918,5.922287,300,0,0), -- Gan'arg Technician
(@CGUID+126,21960,530,1,1,-2737.446,2471.294,93.40414,6.200187,300,0,0), -- Gan'arg Technician
(@CGUID+127,21960,530,1,1,-2746.396,2103.484,117.3472,2.84799,300,0,0), -- Gan'arg Technician
(@CGUID+128,21960,530,1,1,-2746.566,2047.411,117.3364,2.611017,300,0,0), -- Gan'arg Technician
(@CGUID+129,21960,530,1,1,-2746.63,2393.509,92.7717,2.889993,300,0,0), -- Gan'arg Technician
(@CGUID+130,21960,530,1,1,-2747.405,2444.994,93.38111,4.180933,300,0,0), -- Gan'arg Technician
(@CGUID+131,21960,530,1,1,-2747.589,2468.379,93.40414,1.028925,300,0,0), -- Gan'arg Technician
(@CGUID+132,21960,530,1,1,-2748.777,2378.743,92.22152,2.260248,300,0,0), -- Gan'arg Technician
(@CGUID+133,21960,530,1,1,-2749.725,2134.48,116.5986,1.674635,300,0,0), -- Gan'arg Technician
(@CGUID+134,21960,530,1,1,-2750.138,2449.126,93.38111,1.024091,300,0,0), -- Gan'arg Technician
(@CGUID+135,21960,530,1,1,-2750.753,2113.889,116.4206,1.490655,300,0,0), -- Gan'arg Technician
(@CGUID+136,21960,530,1,1,-2752.436,2455.338,93.38111,5.401339,300,0,0), -- Gan'arg Technician
(@CGUID+137,21960,530,1,1,-2752.763,2325.278,92.99591,1.409628,300,0,0), -- Gan'arg Technician
(@CGUID+138,21960,530,1,1,-2752.869,2351.622,92.32831,6.181377,300,0,0), -- Gan'arg Technician
(@CGUID+139,21960,530,1,1,-2753.66,2082.062,116.9274,0.2952486,300,0,0), -- Gan'arg Technician
(@CGUID+140,21960,530,1,1,-2754.198,2384.608,92.22152,5.515212,300,0,0), -- Gan'arg Technician
(@CGUID+141,21960,530,1,1,-2754.322,2384.474,92.22152,5.560681,300,0,0), -- Gan'arg Technician
(@CGUID+142,21960,530,1,1,-2755.084,2213.958,93.28703,6.154799,300,0,0), -- Gan'arg Technician
(@CGUID+143,21960,530,1,1,-2756.057,2328.534,92.98515,0.1728606,300,0,0), -- Gan'arg Technician
(@CGUID+144,21960,530,1,1,-2756.323,2293.546,92.57965,0.2574178,300,0,0), -- Gan'arg Technician
(@CGUID+145,21960,530,1,1,-2756.371,2306.511,93.37035,4.577257,300,0,0), -- Gan'arg Technician
(@CGUID+146,21960,530,1,1,-2762.603,2428.956,93.32586,3.081786,300,0,0), -- Gan'arg Technician
(@CGUID+147,21960,530,1,1,-2762.917,2364.197,93.36164,5.357472,300,0,0), -- Gan'arg Technician
(@CGUID+148,21960,530,1,1,-2763.213,2449.418,93.38111,2.519936,300,0,0), -- Gan'arg Technician
(@CGUID+149,21960,530,1,1,-2763.519,2326.09,93.37035,2.419822,300,0,0), -- Gan'arg Technician
(@CGUID+150,21960,530,1,1,-2763.615,2292.914,93.30166,2.498588,300,0,0), -- Gan'arg Technician
(@CGUID+151,21960,530,1,1,-2763.667,2248.236,93.34501,2.471995,300,0,0), -- Gan'arg Technician
(@CGUID+152,21960,530,1,1,-2764.015,2380.88,93.34652,2.31511,300,0,0), -- Gan'arg Technician
(@CGUID+153,21960,530,1,1,-2766.159,2085.463,116.1668,1.847406,300,0,0), -- Gan'arg Technician
(@CGUID+154,21960,530,1,1,-2766.311,2211.282,93.28703,1.592559,300,0,0), -- Gan'arg Technician
(@CGUID+155,21960,530,1,1,-2767.313,2358.693,93.32701,1.413016,300,0,0), -- Gan'arg Technician
(@CGUID+156,21960,530,1,1,-2768.272,2274.027,93.37387,5.12182,300,0,0), -- Gan'arg Technician
(@CGUID+157,21960,530,1,1,-2768.338,2105.61,117.2314,1.717898,300,0,0), -- Gan'arg Technician
(@CGUID+158,21960,530,1,1,-2769.912,2248.203,93.37387,0.6804543,300,0,0), -- Gan'arg Technician
(@CGUID+159,21960,530,1,1,-2770.266,2216.298,93.40082,6.026309,300,0,0), -- Gan'arg Technician
(@CGUID+160,21960,530,1,1,-2770.569,2271.29,93.37387,6.048157,300,0,0), -- Gan'arg Technician
(@CGUID+161,21960,530,1,1,-2775.968,2316.968,92.40705,3.238038,300,0,0), -- Gan'arg Technician
(@CGUID+162,21960,530,1,1,-2776.491,2417.638,93.19102,3.385516,300,0,0), -- Gan'arg Technician
(@CGUID+163,21960,530,1,1,-2776.986,2450.351,92.95542,3.140613,300,0,0), -- Gan'arg Technician
(@CGUID+164,21960,530,1,1,-2777.848,2380.973,92.79283,2.411169,300,0,0), -- Gan'arg Technician
(@CGUID+165,21960,530,1,1,-2778.497,2453.443,92.94651,4.04254,300,0,0), -- Gan'arg Technician
(@CGUID+166,21960,530,1,1,-2779.636,2251.41,93.37387,2.703256,300,0,0), -- Gan'arg Technician
(@CGUID+167,21960,530,1,1,-2780.335,2222.892,93.40082,2.084666,300,0,0), -- Gan'arg Technician
(@CGUID+168,21960,530,1,1,-2780.522,2471.875,93.02473,3.141593,300,0,0), -- Gan'arg Technician
(@CGUID+169,21960,530,1,1,-2780.526,2409.15,92.50851,1.881965,300,0,0), -- Gan'arg Technician
(@CGUID+170,21960,530,1,1,-2781.428,2387.01,93.28701,3.091882,300,0,0), -- Gan'arg Technician
(@CGUID+171,21960,530,1,1,-2782.46,2228.431,93.01517,4.651798,300,0,0), -- Gan'arg Technician
(@CGUID+172,21960,530,1,1,-2782.613,2211.195,93.4317,1.616505,300,0,0), -- Gan'arg Technician
(@CGUID+173,21960,530,1,1,-2784.19,2347.69,92.49637,0.9226072,300,0,0), -- Gan'arg Technician
(@CGUID+174,21960,530,1,1,-2784.32,2261.709,93.37387,5.655887,300,0,0), -- Gan'arg Technician
(@CGUID+175,21960,530,1,1,-2785.128,2267.869,93.16708,0.546796,300,0,0), -- Gan'arg Technician
(@CGUID+176,21960,530,1,1,-2786.685,2214.266,93.40082,0.2333348,300,0,0), -- Gan'arg Technician
(@CGUID+177,21960,530,1,1,-2796.945,2201.53,93.40082,2.410823,300,0,0), -- Gan'arg Technician
(@CGUID+178,21960,530,1,1,-2797.118,2241.497,93.37387,3.957823,300,0,0), -- Gan'arg Technician
(@CGUID+179,21960,530,1,1,-2797.156,2229.635,93.40082,3.957152,300,0,0), -- Gan'arg Technician
(@CGUID+180,21960,530,1,1,-2803.292,2218.528,93.04189,5.788416,300,0,0); -- Gan'arg Technician

-- Pathing for Cataclysm Overseer Entry: 21961
SET @NPC := @CGUID+0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2624.166,`position_y`=2571.218,`position_z`=75.01111 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2624.166,2571.218,75.01111,0,0,0,0,100,0),
(@PATH,2,-2624.62,2542.242,74.24536,0,0,0,0,100,0),
(@PATH,3,-2624.166,2571.218,75.01111,0,0,0,0,100,0),
(@PATH,4,-2624.751,2607.99,74.93158,0,0,0,0,100,0),
(@PATH,5,-2624.563,2651.694,74.28185,0,0,0,0,100,0),
(@PATH,6,-2624.751,2607.99,74.93158,0,0,0,0,100,0);

-- Pathing for Cataclysm Overseer Entry: 21961
SET @NPC := @CGUID+1;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2743.211,`position_y`=2099.005,`position_z`=117.2918 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2743.211,2099.005,117.2918,0,0,0,0,100,0),
(@PATH,2,-2743.264,2132.767,117.0985,0,0,0,0,100,0),
(@PATH,3,-2742.951,2145.269,116.2745,0,0,0,0,100,0),
(@PATH,4,-2743.264,2132.767,117.0985,0,0,0,0,100,0),
(@PATH,5,-2743.211,2099.005,117.2918,0,0,0,0,100,0),
(@PATH,6,-2741.874,2064.646,117.3364,0,0,0,0,100,0),
(@PATH,7,-2742.875,2033.14,117.0252,0,0,0,0,100,0),
(@PATH,8,-2741.874,2064.646,117.3364,0,0,0,0,100,0);

-- Pathing for Cataclysm Overseer Entry: 21961
SET @NPC := @CGUID+2;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2657.852,`position_y`=2594.252,`position_z`=74.94736 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2657.852,2594.252,74.94736,0,0,0,0,100,0),
(@PATH,2,-2658.395,2560.189,74.94743,0,0,0,0,100,0),
(@PATH,3,-2658.091,2527.67,74.94743,0,0,0,0,100,0),
(@PATH,4,-2658.395,2560.189,74.94743,0,0,0,0,100,0),
(@PATH,5,-2657.852,2594.252,74.94736,0,0,0,0,100,0),
(@PATH,6,-2658.377,2626.292,74.94731,0,0,0,0,100,0),
(@PATH,7,-2658.736,2653.005,74.94393,0,0,0,0,100,0),
(@PATH,8,-2658.377,2626.292,74.94731,0,0,0,0,100,0);

-- Pathing for Cataclysm Overseer Entry: 21961
SET @NPC := @CGUID+3;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2774.228,`position_y`=2205.861,`position_z`=93.40082 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2774.228,2205.861,93.40082,0,0,0,0,100,0),
(@PATH,2,-2774.099,2231.308,93.40082,0,0,0,0,100,0),
(@PATH,3,-2774.292,2264.527,92.85751,0,0,0,0,100,0),
(@PATH,4,-2774.898,2299.137,93.37387,0,0,0,0,100,0),
(@PATH,5,-2774.974,2330.74,92.13889,0,0,0,0,100,0),
(@PATH,6,-2775.949,2350.123,93.32701,0,0,0,0,100,0),
(@PATH,7,-2774.974,2330.74,92.13889,0,0,0,0,100,0),
(@PATH,8,-2774.898,2299.137,93.37387,0,0,0,0,100,0),
(@PATH,9,-2774.292,2264.527,92.85751,0,0,0,0,100,0),
(@PATH,10,-2774.099,2231.308,93.40082,0,0,0,0,100,0);

-- Pathing for Cataclysm Overseer Entry: 21961
SET @NPC := @CGUID+4;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2759.871,`position_y`=2277.614,`position_z`=93.29873 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2759.871,2277.614,93.29873,0,0,0,0,100,0),
(@PATH,2,-2760.06,2308.136,93.37035,0,0,0,0,100,0),
(@PATH,3,-2759.403,2333.865,92.56857,0,0,0,0,100,0),
(@PATH,4,-2760.633,2357.157,93.31051,0,0,0,0,100,0),
(@PATH,5,-2759.403,2333.865,92.56857,0,0,0,0,100,0),
(@PATH,6,-2760.06,2308.136,93.37035,0,0,0,0,100,0),
(@PATH,7,-2759.871,2277.614,93.29873,0,0,0,0,100,0),
(@PATH,8,-2758.652,2248.756,93.28703,0,0,0,0,100,0),
(@PATH,9,-2759.07,2225.875,92.48966,0,0,0,0,100,0),
(@PATH,10,-2759.81,2209.213,93.28703,0,0,0,0,100,0),
(@PATH,11,-2759.07,2225.875,92.48966,0,0,0,0,100,0),
(@PATH,12,-2758.652,2248.756,93.28703,0,0,0,0,100,0);

-- Pathing for Cataclysm Overseer Entry: 21961
SET @NPC := @CGUID+5;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2775.073,`position_y`=2395.292,`position_z`=93.28701 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2775.073,2395.292,93.28701,0,0,0,0,100,0),
(@PATH,2,-2776.016,2358.512,93.32701,0,0,0,0,100,0),
(@PATH,3,-2775.073,2395.292,93.28701,0,0,0,0,100,0),
(@PATH,4,-2772.866,2425.821,92.54453,0,0,0,0,100,0),
(@PATH,5,-2774.25,2452.304,93.39854,0,0,0,0,100,0),
(@PATH,6,-2772.562,2466.367,93.39854,0,0,0,0,100,0),
(@PATH,7,-2758.671,2467.425,93.40414,0,0,0,0,100,0),
(@PATH,8,-2742.215,2468.052,93.40414,0,0,0,0,100,0),
(@PATH,9,-2741.37,2499.675,93.40414,0,0,0,0,100,0),
(@PATH,10,-2742.215,2468.052,93.40414,0,0,0,0,100,0),
(@PATH,11,-2758.671,2467.425,93.40414,0,0,0,0,100,0),
(@PATH,12,-2772.562,2466.367,93.39854,0,0,0,0,100,0),
(@PATH,13,-2774.25,2452.304,93.39854,0,0,0,0,100,0),
(@PATH,14,-2772.866,2425.821,92.54453,0,0,0,0,100,0),
(@PATH,15,-2775.073,2395.292,93.28701,0,0,0,0,100,0);

-- Pathing for Cataclysm Overseer Entry: 21961
SET @NPC := @CGUID+6;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2742.463,`position_y`=2466.129,`position_z`=93.38111 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2742.463,2466.129,93.38111,0,0,0,0,100,0),
(@PATH,2,-2740.73,2447.661,93.38111,0,0,0,0,100,0),
(@PATH,3,-2759.502,2447.807,93.38111,0,0,0,0,100,0),
(@PATH,4,-2759.231,2419.446,93.32586,0,0,0,0,100,0),
(@PATH,5,-2759.33,2387.436,92.4454,0,0,0,0,100,0),
(@PATH,6,-2761.243,2364.419,93.31051,0,0,0,0,100,0),
(@PATH,7,-2759.33,2387.436,92.4454,0,0,0,0,100,0),
(@PATH,8,-2759.231,2419.446,93.32586,0,0,0,0,100,0),
(@PATH,9,-2759.502,2447.807,93.38111,0,0,0,0,100,0),
(@PATH,10,-2740.73,2447.661,93.38111,0,0,0,0,100,0),
(@PATH,11,-2742.463,2466.129,93.38111,0,0,0,0,100,0),
(@PATH,12,-2709.779,2464.938,93.25584,0,0,0,0,100,0),
(@PATH,13,-2709.288,2476.609,93.32631,0,0,0,0,100,0),
(@PATH,14,-2709.779,2464.938,93.25584,0,0,0,0,100,0);

-- Pathing for Cataclysm Overseer Entry: 21961
SET @NPC := @CGUID+7;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2708.779,`position_y`=2068.911,`position_z`=117.2379 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2708.779,2068.911,117.2379,0,0,0,0,100,0),
(@PATH,2,-2708.359,2090.884,117.2379,0,0,0,0,100,0),
(@PATH,3,-2707.642,2117.71,117.2379,0,0,0,0,100,0),
(@PATH,4,-2707.291,2149.051,116.3592,0,0,0,0,100,0),
(@PATH,5,-2707.642,2117.71,117.2379,0,0,0,0,100,0),
(@PATH,6,-2708.359,2090.884,117.2379,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+8;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2795.16,`position_y`=2236.348,`position_z`=93.37387 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2795.16,2236.348,93.37387,0,0,0,0,100,0),
(@PATH,2,-2795.431,2271.447,92.24887,0,0,0,0,100,0),
(@PATH,3,-2795.16,2236.348,93.37387,0,0,0,0,100,0),
(@PATH,4,-2794.978,2201.984,93.40082,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+9;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2747.554,`position_y`=2294.194,`position_z`=92.17666 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2747.554,2294.194,92.17666,0,0,0,0,100,0),
(@PATH,2,-2747.99,2332.008,93.37035,0,0,0,0,100,0),
(@PATH,3,-2747.863,2364.971,92.44698,0,0,0,0,100,0),
(@PATH,4,-2746.703,2395.644,92.38509,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+10;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2761.939,`position_y`=2308.565,`position_z`=93.37035 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2761.939,2308.565,93.37035,0,0,0,0,100,0),
(@PATH,2,-2761.886,2336.399,93.28854,0,0,0,0,100,0),
(@PATH,3,-2761.948,2369.98,93.34652,0,0,0,0,100,0),
(@PATH,4,-2762.17,2403.536,93.32586,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+11;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2761.123,`position_y`=2103.653,`position_z`=117.3472 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2761.123,2103.653,117.3472,0,0,0,0,100,0),
(@PATH,2,-2761.215,2144.157,116.0134,0,0,0,0,100,0),
(@PATH,3,-2761.123,2103.653,117.3472,0,0,0,0,100,0),
(@PATH,4,-2762.027,2078.674,116.1458,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+12;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2777.587,`position_y`=2282.628,`position_z`=92.58359 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2777.587,2282.628,92.58359,0,0,0,0,100,0),
(@PATH,2,-2777.419,2331.222,92.42014,0,0,0,0,100,0),
(@PATH,3,-2777.186,2363.471,93.32701,0,0,0,0,100,0),
(@PATH,4,-2777.419,2331.222,92.42014,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+13;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2762.517,`position_y`=2211.211,`position_z`=93.28703 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2762.517,2211.211,93.28703,0,0,0,0,100,0),
(@PATH,2,-2761.956,2237.105,93.28703,0,0,0,0,100,0),
(@PATH,3,-2761.867,2270.47,93.30166,0,0,0,0,100,0),
(@PATH,4,-2762.346,2303.099,93.37035,0,0,0,0,100,0),
(@PATH,5,-2761.867,2270.47,93.30166,0,0,0,0,100,0),
(@PATH,6,-2761.956,2237.105,93.28703,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+14;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2777.572,`position_y`=2279.407,`position_z`=92.54025 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2777.572,2279.407,92.54025,0,0,0,0,100,0),
(@PATH,2,-2777.548,2237.198,92.2955,0,0,0,0,100,0),
(@PATH,3,-2779.242,2203.625,93.40082,0,0,0,0,100,0),
(@PATH,4,-2777.548,2237.198,92.2955,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+15;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2694.64,`position_y`=2068.898,`position_z`=117.2379 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2694.64,2068.898,117.2379,0,0,0,0,100,0),
(@PATH,2,-2695.301,2033.725,117.3797,0,0,0,0,100,0),
(@PATH,3,-2694.64,2068.898,117.2379,0,0,0,0,100,0),
(@PATH,4,-2694.855,2102.532,117.2397,0,0,0,0,100,0),
(@PATH,5,-2693.58,2129.576,116.6858,0,0,0,0,100,0),
(@PATH,6,-2694.855,2102.532,117.2397,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+16;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2679.245,`position_y`=2063.623,`position_z`=116.3816 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2679.245,2063.623,116.3816,0,0,0,0,100,0),
(@PATH,2,-2678.192,2096.006,116.2379,0,0,0,0,100,0),
(@PATH,3,-2678.287,2122.549,116.7668,0,0,0,0,100,0),
(@PATH,4,-2678.192,2096.006,116.2379,0,0,0,0,100,0),
(@PATH,5,-2679.245,2063.623,116.3816,0,0,0,0,100,0),
(@PATH,6,-2679.909,2035.793,118.7458,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+17;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2713.678,`position_y`=2469.491,`position_z`=93.22096 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2713.678,2469.491,93.22096,0,0,0,0,100,0),
(@PATH,2,-2712.112,2501.797,93.04128,0,0,0,0,100,0),
(@PATH,3,-2700.205,2500.273,89.71194,0,0,0,0,100,0),
(@PATH,4,-2696.189,2493.531,90.74828,0,0,0,0,100,0),
(@PATH,5,-2698.287,2465.581,93.03493,0,0,0,0,100,0),
(@PATH,6,-2704.336,2456.793,92.19871,0,0,0,0,100,0),
(@PATH,7,-2714.398,2451.214,92.19871,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+18;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2637.056,`position_y`=2518.985,`position_z`=74.54729 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2637.056,2518.985,74.54729,0,0,0,0,100,0),
(@PATH,2,-2637.002,2566.124,74.94743,0,0,0,0,100,0),
(@PATH,3,-2636.515,2597.017,74.94736,0,0,0,0,100,0),
(@PATH,4,-2637.002,2566.124,74.94743,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+19;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2622.359,`position_y`=2651.183,`position_z`=74.192 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2622.359,2651.183,74.192,0,0,0,0,100,0),
(@PATH,2,-2622.162,2602.941,74.93158,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+20;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2637.046,`position_y`=2601.445,`position_z`=74.94731 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2637.046,2601.445,74.94731,0,0,0,0,100,0),
(@PATH,2,-2636.693,2650.933,74.31893,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+21;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2652.786,`position_y`=2651.182,`position_z`=74.58089 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2652.786,2651.182,74.58089,0,0,0,0,100,0),
(@PATH,2,-2653.248,2602.359,74.94731,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+22;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2670.338,`position_y`=2594.025,`position_z`=74.94743 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2670.338,2594.025,74.94743,0,0,0,0,100,0),
(@PATH,2,-2670.897,2566.762,74.32243,0,0,0,0,100,0),
(@PATH,3,-2669.479,2527.44,74.49906,0,0,0,0,100,0),
(@PATH,4,-2670.897,2566.762,74.32243,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+23;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2745.622,`position_y`=2429.984,`position_z`=92.47161 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2745.622,2429.984,92.47161,0,0,0,0,100,0),
(@PATH,2,-2745.583,2469.102,93.40414,0,0,0,0,100,0),
(@PATH,3,-2745.991,2494.831,93.28452,0,0,0,0,100,0),
(@PATH,4,-2745.583,2469.102,93.40414,0,0,0,0,100,0),
(@PATH,5,-2745.658,2430.102,92.20086,0,0,0,0,100,0),
(@PATH,6,-2745.909,2396.996,92.29305,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+24;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2652.775,`position_y`=2561.478,`position_z`=74.32243 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2652.775,2561.478,74.32243,0,0,0,0,100,0),
(@PATH,2,-2652.384,2595.102,74.94736,0,0,0,0,100,0),
(@PATH,3,-2652.775,2561.478,74.32243,0,0,0,0,100,0),
(@PATH,4,-2652.475,2520.3,74.67888,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+25;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2623.394,`position_y`=2536.816,`position_z`=74.73218 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2623.394,2536.816,74.73218,0,0,0,0,100,0),
(@PATH,2,-2622.707,2583.397,74.72375,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+26;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2762.018,`position_y`=2436.756,`position_z`=93.38111 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2762.018,2436.756,93.38111,0,0,0,0,100,0),
(@PATH,2,-2761.198,2485.882,92.27914,0,0,0,0,100,0),
(@PATH,3,-2762.018,2436.756,93.38111,0,0,0,0,100,0),
(@PATH,4,-2763.022,2404.462,93.32586,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+27;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2776.525,`position_y`=2401.978,`position_z`=93.37827 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2776.525,2401.978,93.37827,0,0,0,0,100,0),
(@PATH,2,-2775.851,2435.901,92.59995,0,0,0,0,100,0),
(@PATH,3,-2776.1,2474.675,93.34993,0,0,0,0,100,0),
(@PATH,4,-2775.851,2435.901,92.59995,0,0,0,0,100,0),
(@PATH,5,-2776.525,2401.978,93.37827,0,0,0,0,100,0),
(@PATH,6,-2776.522,2368.578,92.58315,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+28;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2729.753,`position_y`=2466.869,`position_z`=93.32631 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2729.753,2466.869,93.32631,0,0,0,0,100,0),
(@PATH,2,-2729.548,2504.533,93.33694,0,0,0,0,100,0),
(@PATH,3,-2729.753,2466.869,93.32631,0,0,0,0,100,0),
(@PATH,4,-2730.019,2426.732,92.59812,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+29;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2670.016,`position_y`=2634.249,`position_z`=74.96772 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2670.016,2634.249,74.96772,0,0,0,0,100,0),
(@PATH,2,-2670.114,2652.084,74.96772,0,0,0,0,100,0),
(@PATH,3,-2670.016,2634.249,74.96772,0,0,0,0,100,0),
(@PATH,4,-2669.654,2599.65,74.94743,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+30;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2683.622,`position_y`=2557.177,`position_z`=74.94743 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2683.622,2557.177,74.94743,0,0,0,0,100,0),
(@PATH,2,-2683.448,2597.54,74.94743,0,0,0,0,100,0),
(@PATH,3,-2683.622,2557.177,74.94743,0,0,0,0,100,0),
(@PATH,4,-2683.835,2535.185,74.44743,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+31;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2685.01,`position_y`=2651.311,`position_z`=74.65302 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2685.01,2651.311,74.65302,0,0,0,0,100,0),
(@PATH,2,-2683.696,2602.2,74.97202,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+32;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2745.845,`position_y`=2098.965,`position_z`=117.2918 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2745.845,2098.965,117.2918,0,0,0,0,100,0),
(@PATH,2,-2745.236,2141.679,116.4493,0,0,0,0,100,0),
(@PATH,3,-2745.845,2098.965,117.2918,0,0,0,0,100,0),
(@PATH,4,-2744.838,2064.231,116.8859,0,0,0,0,100,0),
(@PATH,5,-2745.277,2032.015,116.2408,0,0,0,0,100,0),
(@PATH,6,-2744.838,2064.231,116.8859,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+33;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2728.972,`position_y`=2067.545,`position_z`=117.2379 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2728.972,2067.545,117.2379,0,0,0,0,100,0),
(@PATH,2,-2728.488,2101.93,117.2379,0,0,0,0,100,0),
(@PATH,3,-2728.951,2136.013,117.3078,0,0,0,0,100,0),
(@PATH,4,-2728.488,2101.93,117.2379,0,0,0,0,100,0),
(@PATH,5,-2728.972,2067.545,117.2379,0,0,0,0,100,0),
(@PATH,6,-2729.725,2034.252,117.2379,0,0,0,0,100,0);

-- Pathing for Shadow Council Felsworn Entry: 21753
SET @NPC := @CGUID+34;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2711.632,`position_y`=2102.142,`position_z`=117.2379 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2711.632,2102.142,117.2379,0,0,0,0,100,0),
(@PATH,2,-2711.521,2139.267,117.3078,0,0,0,0,100,0),
(@PATH,3,-2711.632,2102.142,117.2379,0,0,0,0,100,0),
(@PATH,4,-2712.39,2068.484,117.2379,0,0,0,0,100,0),
(@PATH,5,-2711.994,2039.217,117.1129,0,0,0,0,100,0),
(@PATH,6,-2712.39,2068.484,117.2379,0,0,0,0,100,0);

-- Pathing for Shadow Council Zealot Entry: 21754
SET @NPC := @CGUID+35;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2785.22,`position_y`=2256.417,`position_z`=93.37387 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2785.22,2256.417,93.37387,0,0,0,0,100,0),
(@PATH,2,-2784.655,2291.455,92.24887,0,0,0,0,100,0),
(@PATH,3,-2785.22,2256.417,93.37387,0,0,0,0,100,0),
(@PATH,4,-2785.702,2208.109,93.27582,0,0,0,0,100,0);

-- Pathing for Shadow Council Zealot Entry: 21754
SET @NPC := @CGUID+36;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2804.135,`position_y`=2236.564,`position_z`=92.51945 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2804.135,2236.564,92.51945,0,0,0,0,100,0),
(@PATH,2,-2805.031,2198.412,93.28703,0,0,0,0,100,0),
(@PATH,3,-2804.135,2236.564,92.51945,0,0,0,0,100,0),
(@PATH,4,-2802.395,2272.887,93.38139,0,0,0,0,100,0);

-- Pathing for Shadow Council Zealot Entry: 21754
SET @NPC := @CGUID+37;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2785.103,`position_y`=2378.464,`position_z`=92.28701 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2785.103,2378.464,92.28701,0,0,0,0,100,0),
(@PATH,2,-2785.072,2315.19,92.25803,0,0,0,0,100,0),
(@PATH,3,-2785.525,2346.845,92.21165,0,0,0,0,100,0);

-- Pathing for Shadow Council Zealot Entry: 21754
SET @NPC := @CGUID+38;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2785.131,`position_y`=2471.353,`position_z`=92.22493 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2785.131,2471.353,92.22493,0,0,0,0,100,0),
(@PATH,2,-2784.354,2422.32,92.56406,0,0,0,0,100,0);

-- Pathing for Shadow Council Zealot Entry: 21754
SET @NPC := @CGUID+39;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2756.622,`position_y`=2229.722,`position_z`=92.28703 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2756.622,2229.722,92.28703,0,0,0,0,100,0),
(@PATH,2,-2755.861,2208.263,93.28703,0,0,0,0,100,0),
(@PATH,3,-2756.622,2229.722,92.28703,0,0,0,0,100,0),
(@PATH,4,-2757.308,2264.421,93.28703,0,0,0,0,100,0),
(@PATH,5,-2757.039,2298.67,93.30166,0,0,0,0,100,0),
(@PATH,6,-2757.308,2264.421,93.28703,0,0,0,0,100,0);

-- Pathing for Shadow Council Zealot Entry: 21754
SET @NPC := @CGUID+40;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2771.052,`position_y`=2268.596,`position_z`=93.37387 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2771.052,2268.596,93.37387,0,0,0,0,100,0),
(@PATH,2,-2771.679,2235.563,93.37387,0,0,0,0,100,0),
(@PATH,3,-2771.962,2202.936,93.40082,0,0,0,0,100,0),
(@PATH,4,-2771.679,2235.563,93.37387,0,0,0,0,100,0),
(@PATH,5,-2771.052,2268.596,93.37387,0,0,0,0,100,0),
(@PATH,6,-2770.619,2295.07,93.37387,0,0,0,0,100,0);

-- Pathing for Shadow Council Zealot Entry: 21754
SET @NPC := @CGUID+41;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2753.945,`position_y`=2102.062,`position_z`=117.3472 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2753.945,2102.062,117.3472,0,0,0,0,100,0),
(@PATH,2,-2753.002,2067.915,116.1668,0,0,0,0,100,0),
(@PATH,3,-2753.865,2033.915,116.2114,0,0,0,0,100,0),
(@PATH,4,-2753.002,2067.915,116.1668,0,0,0,0,100,0),
(@PATH,5,-2753.945,2102.062,117.3472,0,0,0,0,100,0),
(@PATH,6,-2753.775,2145.034,116.2692,0,0,0,0,100,0);

-- Pathing for Shadow Council Zealot Entry: 21754
SET @NPC := @CGUID+42;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2704.264,`position_y`=2136.729,`position_z`=117.3078 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2704.264,2136.729,117.3078,0,0,0,0,100,0),
(@PATH,2,-2704.649,2103.023,117.2379,0,0,0,0,100,0),
(@PATH,3,-2705.716,2065.331,117.2379,0,0,0,0,100,0),
(@PATH,4,-2705.87,2035.906,117.2379,0,0,0,0,100,0),
(@PATH,5,-2705.716,2065.331,117.2379,0,0,0,0,100,0),
(@PATH,6,-2704.649,2103.023,117.2379,0,0,0,0,100,0);

-- Pathing for Shadow Council Zealot Entry: 21754
SET @NPC := @CGUID+43;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2722.125,`position_y`=2069.174,`position_z`=117.2379 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2722.125,2069.174,117.2379,0,0,0,0,100,0),
(@PATH,2,-2722.249,2034.047,117.2379,0,0,0,0,100,0),
(@PATH,3,-2722.125,2069.174,117.2379,0,0,0,0,100,0),
(@PATH,4,-2720.923,2115.775,117.2379,0,0,0,0,100,0),
(@PATH,5,-2720.486,2142.357,116.9133,0,0,0,0,100,0),
(@PATH,6,-2720.923,2115.775,117.2379,0,0,0,0,100,0);

-- Pathing for Shadow Council Zealot Entry: 21754
SET @NPC := @CGUID+44;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2690.13,`position_y`=2064.948,`position_z`=117.2378 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2690.13,2064.948,117.2378,0,0,0,0,100,0),
(@PATH,2,-2689.416,2099.356,116.8526,0,0,0,0,100,0),
(@PATH,3,-2688.399,2132.129,116.1147,0,0,0,0,100,0),
(@PATH,4,-2689.416,2099.356,116.8526,0,0,0,0,100,0),
(@PATH,5,-2690.13,2064.948,117.2378,0,0,0,0,100,0),
(@PATH,6,-2690.084,2035.869,117.6316,0,0,0,0,100,0);

-- Pathing for Shadow Council Zealot Entry: 21754
SET @NPC := @CGUID+45;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2737.035,`position_y`=2498.918,`position_z`=93.40414 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2737.035,2498.918,93.40414,0,0,0,0,100,0),
(@PATH,2,-2737.381,2465.538,93.38111,0,0,0,0,100,0),
(@PATH,3,-2737.459,2428.079,92.20086,0,0,0,0,100,0),
(@PATH,4,-2737.381,2465.538,93.38111,0,0,0,0,100,0),
(@PATH,5,-2737.035,2498.918,93.40414,0,0,0,0,100,0),
(@PATH,6,-2736.389,2511.215,93.38651,0,0,0,0,100,0);

-- Pathing for Shadow Council Zealot Entry: 21754
SET @NPC := @CGUID+46;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2628.166,`position_y`=2652.95,`position_z`=74.27159 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2628.166,2652.95,74.27159,0,0,0,0,100,0),
(@PATH,2,-2627.974,2631.489,74.93158,0,0,0,0,100,0),
(@PATH,3,-2629.114,2598.675,75.01111,0,0,0,0,100,0),
(@PATH,4,-2628.789,2564.261,74.94849,0,0,0,0,100,0),
(@PATH,5,-2629.153,2518.347,74.27462,0,0,0,0,100,0),
(@PATH,6,-2628.789,2564.261,74.94849,0,0,0,0,100,0),
(@PATH,7,-2629.114,2598.675,75.01111,0,0,0,0,100,0),
(@PATH,8,-2627.974,2631.489,74.93158,0,0,0,0,100,0);

-- Pathing for Shadow Council Zealot Entry: 21754
SET @NPC := @CGUID+47;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2770.884,`position_y`=2403.361,`position_z`=93.37827 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2770.884,2403.361,93.37827,0,0,0,0,100,0),
(@PATH,2,-2769.982,2437.895,93.39854,0,0,0,0,100,0),
(@PATH,3,-2769.842,2482.756,93.34993,0,0,0,0,100,0),
(@PATH,4,-2769.982,2437.895,93.39854,0,0,0,0,100,0);

-- Pathing for Shadow Council Zealot Entry: 21754
SET @NPC := @CGUID+48;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2754.18,`position_y`=2431.333,`position_z`=93.32586 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2754.18,2431.333,93.32586,0,0,0,0,100,0),
(@PATH,2,-2755.019,2403.688,93.32586,0,0,0,0,100,0),
(@PATH,3,-2754.18,2431.333,93.32586,0,0,0,0,100,0),
(@PATH,4,-2753.878,2462.278,93.38111,0,0,0,0,100,0),
(@PATH,5,-2754.642,2486.674,92.27914,0,0,0,0,100,0),
(@PATH,6,-2753.878,2462.278,93.38111,0,0,0,0,100,0);

-- Pathing for Shadow Council Zealot Entry: 21754
SET @NPC := @CGUID+49;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2720.884,`position_y`=2469.591,`position_z`=93.32631 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2720.884,2469.591,93.32631,0,0,0,0,100,0),
(@PATH,2,-2720.662,2513.249,92.96389,0,0,0,0,100,0),
(@PATH,3,-2720.884,2469.591,93.32631,0,0,0,0,100,0),
(@PATH,4,-2720.884,2434.87,92.5084,0,0,0,0,100,0);

-- Pathing for Shadow Council Zealot Entry: 21754
SET @NPC := @CGUID+50;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2756.388,`position_y`=2332.109,`position_z`=92.19946 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2756.388,2332.109,92.19946,0,0,0,0,100,0),
(@PATH,2,-2756.482,2301.443,93.37035,0,0,0,0,100,0),
(@PATH,3,-2756.388,2332.109,92.19946,0,0,0,0,100,0),
(@PATH,4,-2756.648,2365.67,93.31051,0,0,0,0,100,0),
(@PATH,5,-2755.329,2399.249,93.34652,0,0,0,0,100,0),
(@PATH,6,-2756.648,2365.67,93.31051,0,0,0,0,100,0);

-- Pathing for Shadow Council Zealot Entry: 21754
SET @NPC := @CGUID+51;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2771.347,`position_y`=2336.068,`position_z`=93.06529 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2771.347,2336.068,93.06529,0,0,0,0,100,0),
(@PATH,2,-2769.864,2369.139,93.17776,0,0,0,0,100,0),
(@PATH,3,-2770.086,2395.213,93.28701,0,0,0,0,100,0),
(@PATH,4,-2769.864,2369.139,93.17776,0,0,0,0,100,0),
(@PATH,5,-2771.347,2336.068,93.06529,0,0,0,0,100,0),
(@PATH,6,-2770.781,2301.665,93.38303,0,0,0,0,100,0);

-- Pathing for Shadow Council Zealot Entry: 21754
SET @NPC := @CGUID+52;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2661.922,`position_y`=2565.167,`position_z`=74.94743 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2661.922,2565.167,74.94743,0,0,0,0,100,0),
(@PATH,2,-2662.236,2526.605,74.94743,0,0,0,0,100,0),
(@PATH,3,-2661.922,2565.167,74.94743,0,0,0,0,100,0),
(@PATH,4,-2661.766,2598.691,74.94736,0,0,0,0,100,0),
(@PATH,5,-2661.454,2632.066,74.94731,0,0,0,0,100,0),
(@PATH,6,-2661.921,2652.52,74.94393,0,0,0,0,100,0),
(@PATH,7,-2661.454,2632.066,74.94731,0,0,0,0,100,0),
(@PATH,8,-2661.766,2598.691,74.94736,0,0,0,0,100,0);

-- Pathing for Shadow Council Zealot Entry: 21754
SET @NPC := @CGUID+53;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2676.634,`position_y`=2630.928,`position_z`=74.71323 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2676.634,2630.928,74.71323,0,0,0,0,100,0),
(@PATH,2,-2676.133,2597.521,74.94743,0,0,0,0,100,0),
(@PATH,3,-2675.693,2564.413,74.84319,0,0,0,0,100,0),
(@PATH,4,-2676.745,2531.281,74.96903,0,0,0,0,100,0),
(@PATH,5,-2675.693,2564.413,74.84319,0,0,0,0,100,0),
(@PATH,6,-2676.133,2597.521,74.94743,0,0,0,0,100,0),
(@PATH,7,-2676.634,2630.928,74.71323,0,0,0,0,100,0),
(@PATH,8,-2677.356,2651.749,74.96772,0,0,0,0,100,0);

-- Pathing for Shadow Council Zealot Entry: 21754
SET @NPC := @CGUID+54;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2645.054,`position_y`=2653.658,`position_z`=74.94393 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2645.054,2653.658,74.94393,0,0,0,0,100,0),
(@PATH,2,-2644.895,2632.497,74.94731,0,0,0,0,100,0),
(@PATH,3,-2645.055,2597.804,74.94736,0,0,0,0,100,0),
(@PATH,4,-2644.371,2564.333,74.36674,0,0,0,0,100,0),
(@PATH,5,-2644.736,2531.433,74.94743,0,0,0,0,100,0),
(@PATH,6,-2645.176,2513.085,74.32243,0,0,0,0,100,0),
(@PATH,7,-2644.736,2531.433,74.94743,0,0,0,0,100,0),
(@PATH,8,-2644.371,2564.333,74.36674,0,0,0,0,100,0),
(@PATH,9,-2645.055,2597.804,74.94736,0,0,0,0,100,0),
(@PATH,10,-2644.895,2632.497,74.94731,0,0,0,0,100,0);

-- Pathing for Shadow Council Zealot Entry: 21754
SET @NPC := @CGUID+55;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2738.647,`position_y`=2029.915,`position_z`=117.2366 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2738.647,2029.915,117.2366,0,0,0,0,100,0),
(@PATH,2,-2738.477,2065.157,117.3364,0,0,0,0,100,0),
(@PATH,3,-2737.82,2098.544,117.2918,0,0,0,0,100,0),
(@PATH,4,-2737.512,2131.9,117.3472,0,0,0,0,100,0),
(@PATH,5,-2737.184,2145.899,115.8942,0,0,0,0,100,0),
(@PATH,6,-2737.512,2131.9,117.3472,0,0,0,0,100,0),
(@PATH,7,-2737.82,2098.544,117.2918,0,0,0,0,100,0),
(@PATH,8,-2738.477,2065.157,117.3364,0,0,0,0,100,0);

-- Pathing for Wildhammer Guard Entry: 19353
SET @NPC := @CGUID+62;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2738.818,`position_y`=1952.552,`position_z`=153.4082 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2738.818,1952.552,153.4082,0,0,0,0,100,0),
(@PATH,2,-2724.426,1951.31,147.3684,0,0,0,0,100,0),
(@PATH,3,-2711.517,1951.894,144.3868,0,0,0,0,100,0),
(@PATH,4,-2701.61,1953.292,143.8939,0,0,0,0,100,0),
(@PATH,5,-2711.517,1951.894,144.3868,0,0,0,0,100,0),
(@PATH,6,-2724.426,1951.31,147.3684,0,0,0,0,100,0),
(@PATH,7,-2738.818,1952.552,153.4082,0,0,0,0,100,0),
(@PATH,8,-2752.306,1951.067,160.1505,0,0,0,0,100,0),
(@PATH,9,-2763.156,1949.187,166.0191,0,0,0,0,100,0),
(@PATH,10,-2771.908,1945.806,172.0308,0,0,0,0,100,0),
(@PATH,11,-2778.184,1942.703,177.1924,0,0,0,0,100,0),
(@PATH,12,-2771.908,1945.806,172.0308,0,0,0,0,100,0),
(@PATH,13,-2763.26,1949.171,166.2084,0,0,0,0,100,0),
(@PATH,14,-2752.41,1951.051,160.2691,0,0,0,0,100,0);

-- Pathing for Kor'kron Defender Entry: 19362
SET @NPC := @CGUID+65;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2679.007,`position_y`=2707.241,`position_z`=103.5283 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2679.007,2707.241,103.5283,0,0,0,0,100,0),
(@PATH,2,-2689.075,2716.259,106.572,0,0,0,0,100,0),
(@PATH,3,-2699.496,2721.168,111.1267,0,0,0,0,100,0),
(@PATH,4,-2706.34,2725.309,114.5727,0,0,0,0,100,0),
(@PATH,5,-2713.205,2729.05,117.3128,0,0,0,0,100,0),
(@PATH,6,-2706.492,2725.396,114.4426,0,0,0,0,100,0),
(@PATH,7,-2699.496,2721.168,111.1267,0,0,0,0,100,0),
(@PATH,8,-2689.075,2716.259,106.572,0,0,0,0,100,0),
(@PATH,9,-2679.007,2707.241,103.5283,0,0,0,0,100,0),
(@PATH,10,-2681.186,2699.77,101.498,0,0,0,0,100,0),
(@PATH,11,-2687.217,2694.512,98.07244,0,0,0,0,100,0),
(@PATH,12,-2681.186,2699.77,101.498,0,0,0,0,100,0);
