SET @OGUID := 164371;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+74;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 208527, 568, 1, 1, 118.997, 1782.152, 40.66697, 1.569402, 0, 0, 0.9999998, 0.0006961703, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+1, 208528, 568, 1, 1, 118.0522, 1783.465, 40.77031, 4.710998, 0, 0, 0.9999998, 0.0006961703, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+2, 186728, 568, 1, 1, 120.2937, 1605.67, 63.18038, 3.13883, 0, 0, 0.9999998, 0.0006961703, 7200, 255, 1), -- Massive Gate (Area: 0)
(@OGUID+3, 186622, 568, 1, 1, 305.5138, 1467.337, 81.50594, 3.961899, 0, 0, 0, 1, 7200, 255, 1), -- Zul'Aman - Loot Box - Dwarf (Area: 0)
(@OGUID+4, 186858, 568, 1, 1, 337.066, 1396.095, 74.17232, 3.429581, 0, 0, 0.9896514, -0.1434927, 7200, 255, 0), -- Doodad_ZulAman_WindDoor01 (Area: 0)
(@OGUID+5, 187035, 568, 1, 1, 132.4638, 1334.191, -9.374673, 3.752462, 0, 0, 0, 1, 7200, 255, 1), -- Zul'Aman - Altar Torch - Eagle God (Area: 0)
(@OGUID+6, 186860, 568, 1, 1, 99.98275, 1333.95, -9.395689, 0.5934101, 0, 0, 0, 1, 7200, 255, 1), -- Zul'Aman - Altar Torch - Bear God (Area: 0)
(@OGUID+7, 187036, 568, 1, 1, 98.81522, 1245.411, -9.494817, 1.431168, 0, 0, 0, 1, 7200, 255, 1), -- Zul'Aman - Altar Torch - Dragonhawk God (Area: 0)
(@OGUID+8, 187037, 568, 1, 1, 132.3735, 1244.415, -9.647598, 0.2967052, 0, 0, 0, 1, 7200, 255, 1), -- Zul'Aman - Altar Torch - Lynx God (Area: 0)
(@OGUID+9, 186303, 568, 1, 1, 305.908, 1112.087, 9.956597, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Lynx Temple Exit (Area: 0)
(@OGUID+10, 186305, 568, 1, 1, 124.2036, 1022.951, 34.14412, 4.703663, 0, 0, 0.9999905, 0.004363511, 7200, 255, 1), -- Hexlord Entrance (Area: 0)
(@OGUID+11, 186304, 568, 1, 1, 375.4099, 1057.671, 9.861444, 4.71239, 0, 0, 1, -4.371139E-08, 7200, 255, 0), -- Lynx Temple Entrance (Area: 0)
(@OGUID+12, 186306, 568, 1, 1, 123.2564, 914.4214, 34.14412, 4.703663, 0, 0, 0.9999905, 0.004363511, 7200, 255, 1), -- Wooden Door (Area: 0)
(@OGUID+13, 186859, 568, 1, 1, 120.2938, 732.0077, 45.01099, 1.562067, 0, 0, 0.9999905, 0.004363511, 7200, 255, 0), -- Doodad_ZulAman_FireDoor01 (Area: 0)
(@OGUID+14, 208549, 568, 1, 1, 95.14584, 1649.174, 42.02156, 3.787367, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+15, 187359, 568, 1, 1, 134.0088, 1642.797, 42.08408, 3.141593, 0, 0, 0, 1, 7200, 255, 1), -- Strange Gong (Area: 0)
(@OGUID+16, 185455, 568, 1, 1, 298.2845, 1454.724, 81.50593, 0.2443456, 0, 0, 0, 1, 7200, 255, 1), -- Laying Skeleton 03 (Area: 0)
(@OGUID+17, 185454, 568, 1, 1, 297.778, 1461.44, 81.50594, 4.415683, 0, 0, 0, 1, 7200, 255, 1), -- Laying Skeleton 02 (Area: 0)
(@OGUID+18, 186482, 568, 1, 1, 294.2524, 1457.963, 81.50594, 4.939284, 0, 0, 0, 1, 7200, 255, 0), -- Zul'Aman Dummy Cage - Open (Area: 0)
(@OGUID+19, 185455, 568, 1, 1, 291.7971, 1464.713, 81.50596, 0.6806767, 0, 0, 0, 1, 7200, 255, 1), -- Laying Skeleton 03 (Area: 0)
(@OGUID+20, 185434, 568, 1, 1, 293.9154, 1458.404, 81.50594, 5.026549, 0, 0, 0, 1, 7200, 255, 1), -- Sitting Skeleton 01 (Area: 0)
(@OGUID+21, 185455, 568, 1, 1, 300.4619, 1470.833, 81.50595, 1.884953, 0, 0, 0, 1, 7200, 255, 1), -- Laying Skeleton 03 (Area: 0)
(@OGUID+22, 187378, 568, 1, 1, 296.3336, 1468.373, 81.50596, 3.769912, 0, 0, 0, 1, 7200, 255, 1), -- Harkor's Cage (Area: 0)
(@OGUID+23, 185454, 568, 1, 1, 305.4029, 1460.194, 81.50593, 5.096362, 0, 0, 0, 1, 7200, 255, 1), -- Laying Skeleton 02 (Area: 0)
(@OGUID+24, 185454, 568, 1, 1, 337.4445, 1323.924, 81.58758, 3.38594, 0, 0, 0, 1, 7200, 255, 1), -- Laying Skeleton 02 (Area: 0)
(@OGUID+25, 186482, 568, 1, 1, 341.0594, 1311.294, 81.5876, 0.01745246, 0, 0, 0, 1, 7200, 255, 0), -- Zul'Aman Dummy Cage - Open (Area: 0)
(@OGUID+26, 185455, 568, 1, 1, 341.9977, 1320.824, 81.58758, 5.375615, 0, 0, 0, 1, 7200, 255, 1), -- Laying Skeleton 03 (Area: 0)
(@OGUID+27, 185455, 568, 1, 1, 335.6972, 1314.936, 81.58759, 0.3141584, 0, 0, 0, 1, 7200, 255, 1), -- Laying Skeleton 03 (Area: 0)
(@OGUID+28, 185454, 568, 1, 1, 345.4576, 1324.546, 81.58758, 0.8377574, 0, 0, 0, 1, 7200, 255, 1), -- Laying Skeleton 02 (Area: 0)
(@OGUID+29, 185454, 568, 1, 1, 346.2016, 1314.281, 81.58759, 1.954769, 0, 0, 0, 1, 7200, 255, 1), -- Laying Skeleton 02 (Area: 0)
(@OGUID+30, 185434, 568, 1, 1, 343.3606, 1311.331, 81.5876, 0.01745246, 0, 0, 0, 1, 7200, 255, 1), -- Sitting Skeleton 01 (Area: 0)
(@OGUID+31, 186623, 568, 1, 1, 307.2083, 1464.144, 81.60316, 6.178466, 0, 0, 0, 1, 7200, 255, 1), -- Zul'Aman - Dwarf Hammer (Area: 0)
(@OGUID+32, 187021, 568, 1, 1, 305.7754, 1467.306, 81.5875, 1.53589, 0, 0, 0, 1, 7200, 255, 1), -- Harkor's Satchel (Area: 0)
(@OGUID+33, 186338, 568, 1, 1, 407.2562, 1502.667, 81.63722, 4.625124, 0, 0, 0, 1, 7200, 255, 1), -- Zul'Aman Dummy Cage (Area: 0)
(@OGUID+34, 186338, 568, 1, 1, 417.8336, 1499.603, 81.63318, 2.286379, 0, 0, 0, 1, 7200, 255, 1), -- Zul'Aman Dummy Cage (Area: 0)
(@OGUID+35, 186633, 568, 1, 1, 305.3553, 1467.356, 81.69344, 0.8377574, 0, 0, 0, 1, 7200, 255, 1), -- Gold Coins (Area: 0)
(@OGUID+36, 186633, 568, 1, 1, 305.9524, 1466.293, 81.64482, 4.084071, 0, 0, 0, 1, 7200, 255, 1), -- Gold Coins (Area: 0)
(@OGUID+37, 186634, 568, 1, 1, 304.0233, 1467.731, 81.58927, 0.7504908, 0, 0, 0, 1, 7200, 255, 1), -- Gold Coins (Area: 0)
(@OGUID+38, 186633, 568, 1, 1, 304.4055, 1465.527, 81.69344, 3.525572, 0, 0, 0, 1, 7200, 255, 1), -- Gold Coins (Area: 0)
(@OGUID+39, 185434, 568, 1, 1, -23.89442, 1332.414, 48.17391, 0.6457717, 0, 0, 0, 1, 7200, 255, 1), -- Sitting Skeleton 01 (Area: 0)
(@OGUID+40, 185455, 568, 1, 1, -24.04991, 1343.662, 48.17391, 6.213374, 0, 0, 0, 1, 7200, 255, 1), -- Laying Skeleton 03 (Area: 0)
(@OGUID+41, 185454, 568, 1, 1, -28.10677, 1338.444, 48.17391, 4.747296, 0, 0, 0, 1, 7200, 255, 1), -- Laying Skeleton 02 (Area: 0)
(@OGUID+42, 186482, 568, 1, 1, -22.09147, 1350.191, 48.17392, 2.268925, 0, 0, 0, 1, 7200, 255, 0), -- Zul'Aman Dummy Cage - Open (Area: 0)
(@OGUID+43, 186648, 568, 1, 1, -135.1944, 1333.054, 48.17387, 2.391098, 0, 0, 0, 1, 7200, 255, 1), -- Tanzar's Trunk (Area: 0)
(@OGUID+44, 185455, 568, 1, 1, -133.9123, 1335.868, 48.17386, 0.2268925, 0, 0, 0, 1, 7200, 255, 1), -- Laying Skeleton 03 (Area: 0)
(@OGUID+45, 185455, 568, 1, 1, -147.7177, 1342.067, 48.17388, 5.742135, 0, 0, 0, 1, 7200, 255, 1), -- Laying Skeleton 03 (Area: 0)
(@OGUID+46, 185438, 568, 1, 1, -150.0234, 1350.042, 48.17389, 5.707228, 0, 0, 0, 1, 7200, 255, 1), -- Sitting Skeleton 04 (Area: 0)
(@OGUID+47, 186482, 568, 1, 1, -149.0895, 1349.992, 48.17389, 4.084071, 0, 0, 0, 1, 7200, 255, 0), -- Zul'Aman Dummy Cage - Open (Area: 0)
(@OGUID+48, 185454, 568, 1, 1, -132.6105, 1341.922, 48.17387, 0.8901166, 0, 0, 0, 1, 7200, 255, 1), -- Laying Skeleton 02 (Area: 0)
(@OGUID+49, 186338, 568, 1, 1, -23.44021, 1333.181, 48.17391, 0.01745246, 0, 0, 0, 1, 7200, 255, 1), -- Zul'Aman Dummy Cage (Area: 0)
(@OGUID+50, 185434, 568, 1, 1, -146.864, 1332.22, 48.17388, 5.323256, 0, 0, 0, 1, 7200, 255, 1), -- Sitting Skeleton 01 (Area: 0)
(@OGUID+51, 186733, 568, 1, 1, -150.9121, 1343.151, 49.785, 5.253442, 0, 0, 0, 1, 7200, 255, 1), -- The Map of Zul'Aman (Area: 0)
(@OGUID+52, 187377, 568, 1, 1, -147.7314, 1333.472, 48.17388, 5.410522, 0, 0, 0, 1, 7200, 255, 1), -- Tanzar's Cage (Area: 0)
(@OGUID+53, 185454, 568, 1, 1, -150.2511, 1337.349, 48.17388, 0.8552105, 0, 0, 0, 1, 7200, 255, 1), -- Laying Skeleton 02 (Area: 0)
(@OGUID+54, 187379, 568, 1, 1, -73.78657, 1164.578, 5.203399, 3.141593, 0, 0, 0, 1, 7200, 255, 0), -- Kraz's Cage (Area: 0)
(@OGUID+55, 186667, 568, 1, 1, -80.09061, 1125.301, 5.594004, 4.991644, 0, 0, 0, 1, 7200, 255, 1), -- Kraz's Package (Area: 0)
(@OGUID+56, 185434, 568, 1, 1, -75.11784, 1137.772, 5.211044, 1.169369, 0, 0, 0, 1, 7200, 255, 1), -- Sitting Skeleton 01 (Area: 0)
(@OGUID+57, 185434, 568, 1, 1, -73.52843, 1139.153, 5.194067, 4.01426, 0, 0, 0, 1, 7200, 255, 1), -- Sitting Skeleton 01 (Area: 0)
(@OGUID+58, 186658, 568, 1, 1, -79.98514, 1125.343, 5.594004, 3.228859, 0, 0, 0, 1, 7200, 255, 1), -- Kraz's Chest (Area: 0)
(@OGUID+59, 186482, 568, 1, 1, -74.63194, 1138.703, 5.202056, 0, 0, 0, 0, 1, 7200, 255, 0), -- Zul'Aman Dummy Cage - Open (Area: 0)
(@OGUID+60, 191460, 568, 1, 1, 245.8242, 1018.735, 3.550614, 3.35977, 0, 0, 0.9940563, -0.1088669, 7200, 255, 1), -- Bonfire (Area: 0)
(@OGUID+61, 186430, 568, 1, 1, 251.4287, 996.8561, 10.91198, 2.111848, 0, 0, 0, 1, 7200, 255, 1), -- Zungam's Ball and Chain (Area: 0)
(@OGUID+62, 186671, 568, 1, 1, 332.369, 1084.419, 6.280053, 3.071766, 0, 0, 0, 1, 7200, 255, 1), -- Ashli's Vase (Area: 0)
(@OGUID+63, 186671, 568, 1, 1, 344.3331, 1084.677, 6.966906, 2.967041, 0, 0, 0, 1, 7200, 255, 1), -- Ashli's Vase (Area: 0)
(@OGUID+64, 186672, 568, 1, 1, 424.1022, 1083.671, 6.603121, 0.6806767, 0, 0, 0, 1, 7200, 255, 1), -- Ashli's Bag (Area: 0)
(@OGUID+65, 186671, 568, 1, 1, 424.2561, 1083.613, 6.606084, 1.099556, 0, 0, 0, 1, 7200, 255, 1), -- Ashli's Vase (Area: 0)
(@OGUID+66, 185438, 568, 1, 1, 398.7859, 1086.315, 5.357515, 2.844883, 0, 0, 0, 1, 7200, 255, 1), -- Sitting Skeleton 04 (Area: 0)
(@OGUID+67, 187380, 568, 1, 1, 383.6736, 1083.184, 5.753235, 0.01745246, 0, 0, 0, 1, 7200, 255, 0), -- Ashli's Cage (Area: 0)
(@OGUID+68, 186338, 568, 1, 1, 397.3085, 1083.455, 5.417239, 6.265733, 0, 0, 0, 1, 7200, 255, 1), -- Zul'Aman Dummy Cage (Area: 0)
(@OGUID+69, 185454, 568, 1, 1, 411.9372, 1123.931, 6.100508, 5.846854, 0, 0, 0, 1, 7200, 255, 1), -- Laying Skeleton 02 (Area: 0)
(@OGUID+70, 186671, 568, 1, 1, 343.3571, 1152.027, 6.343656, 3.351047, 0, 0, 0, 1, 7200, 255, 1), -- Ashli's Vase (Area: 0)
(@OGUID+71, 186482, 568, 1, 1, 383.4884, 1152.291, 6.343661, 3.124123, 0, 0, 0, 1, 7200, 255, 0), -- Zul'Aman Dummy Cage - Open (Area: 0)
(@OGUID+72, 185434, 568, 1, 1, 392.5631, 1155.374, 6.343639, 4.468043, 0, 0, 0, 1, 7200, 255, 1), -- Sitting Skeleton 01 (Area: 0)
(@OGUID+73, 185454, 568, 1, 1, 396.143, 1148.681, 6.343392, 2.565632, 0, 0, 0, 1, 7200, 255, 1), -- Laying Skeleton 02 (Area: 0)
(@OGUID+74, 186338, 568, 1, 1, 398.4367, 1152.451, 6.34364, 3.141593, 0, 0, 0, 1, 7200, 255, 1); -- Zul'Aman Dummy Cage (Area: 0)


UPDATE `creature_template` SET `npcflag`=1048577 WHERE `entry`=44004; -- Gilnean Envoy
UPDATE `creature_template` SET `gossip_menu_id`=12804, `minlevel`=85, `maxlevel`=85, `npcflag`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33024 WHERE `entry`=52941; -- Bakkalzu


UPDATE `gameobject_template` SET `flags`=4 WHERE `entry`=208549; -- -Unknown-
UPDATE `gameobject_template` SET `flags`=1 WHERE `entry`=186482; -- Zul'Aman Dummy Cage - Open
UPDATE `gameobject_template` SET `faction`=14, `flags`=2 WHERE `entry`=187378; -- Harkor's Cage
UPDATE `gameobject_template` SET `faction`=94, `flags`=16 WHERE `entry`=187021; -- Harkor's Satchel
UPDATE `gameobject_template` SET `flags`=32 WHERE `entry`=182521; -- Corki's Prison
UPDATE `gameobject_template` SET `flags`=32 WHERE `entry`=182490; -- Warmaul Prison
UPDATE `gameobject_template` SET `flags`=2 WHERE `entry`=187377; -- Tanzar's Cage
UPDATE `gameobject_template` SET `faction`=94, `flags`=16 WHERE `entry`=186672; -- Ashli's Bag
UPDATE `gameobject_template` SET `faction`=14, `flags`=3 WHERE `entry`=187380; -- Ashli's Cage


DELETE FROM `creature_template_addon` WHERE `entry` IN (23746, 52938, 52938, 23746, 14881, 52938, 52938, 52938, 52938, 14881, 23746, 52938, 52938, 14881, 52938, 52938, 23746, 23746, 52933, 52925, 23746, 53488, 14881, 23746, 52924, 52938, 52938, 23746, 23746, 23746, 23746, 23746, 23746, 23746, 23746, 23746, 23746, 23746, 23746, 23746, 23746, 53488, 53488, 14881, 53488, 53488, 52938, 52938, 52938, 52938, 25173, 23746, 53488, 14881, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23597, 23597, 25173, 23889, 24175, 23746, 23746, 23746, 23576, 23746, 23746, 23746, 23746, 23746, 52956, 52962, 24325, 24223, 24223, 24223, 24179, 24180, 1412, 24223, 52958, 52962, 24223, 53021, 24180, 53021, 53021, 53021, 53021, 53021, 24179, 53021, 53021, 53021, 53021, 53021, 53021, 24223, 24396, 53021, 53021, 53021, 53021, 53021, 24396, 53021, 53021, 24396, 53021, 53021, 24396, 24396, 53021, 53021, 53021, 24549, 24363, 24396, 24396, 53021, 24396, 53021, 53021, 52958, 53021, 24180, 24179, 24223, 24223, 24223, 23746, 23746, 23746, 24223, 24223, 24223, 23574, 52941, 24180, 24179, 23746, 23814, 24551, 24858, 24858, 24858, 24858, 24858, 24858, 24858, 24858, 24858, 24858, 24858, 24858, 24858, 24858, 24858, 24858, 24858, 24858, 24858, 24858, 24858, 6491, 52956, 52962, 52956, 52958, 1412, 1412, 1412, 23542, 23582, 23542, 23584, 23746, 23584, 23817, 23817, 23817, 23817, 23817, 23817, 23817, 23817, 23817, 23817, 23817, 23817, 23817, 23817, 23817, 23817, 23817, 23817, 23746, 23746, 23584, 23581, 23584, 23584, 23582, 23542, 23542, 23584, 23807, 23580, 23580, 23580, 23542, 23580, 23581, 52939, 23746, 22515, 23596, 1412, 22515, 23586, 23597, 23586, 23597, 23597, 23596, 52962, 1412, 22515, 23834, 23834, 22515, 24312, 24312, 24312, 24312, 24312, 24312, 24312, 24312, 24312, 24312, 24312, 24312, 23774, 23834, 23834, 23586, 24312, 24312, 24312, 24312, 24312, 24312, 23586, 24312, 24312, 24312, 24312, 24312, 24312, 24312, 24312, 24312, 24312, 24312, 24312, 22515, 23774, 23834, 23834, 1412, 22515, 23746, 23746, 23834, 23834, 23834, 23774, 23597, 23597, 23596, 23834, 23834, 23774, 23586, 23834, 23578, 22515, 23586, 52958, 23597, 23596, 23597, 23834, 23596, 23596, 23596, 22515, 52943, 22515, 23817, 23817, 23817, 23817, 23817, 23817, 23817, 23817, 23817, 23817, 23817, 23817, 23817, 23817, 23817, 23817, 23817, 23817, 23834, 23834, 21252, 52956, 22515, 23596, 23597, 23596, 23774, 23774, 23834, 23813, 23834, 23586, 23834, 23597, 23596, 23834, 52962, 21252, 21252, 1412, 21252, 21252, 52956, 53021, 53021, 53021, 53021, 53021, 53021, 24064, 24530, 52958, 53021, 53021, 53021, 53021, 24064, 24064, 24064, 24064, 24064, 24064, 24064, 24530, 53021, 53021, 24396, 53021, 53021, 53021, 24396, 23746, 24240, 24239, 24246, 24064, 24064, 1412, 52956, 52958, 24065, 24064, 24065, 23746, 23746, 24064, 24064, 24064, 24064, 24064, 24064, 23577, 22517, 23746, 23746, 23897, 24047, 24047, 24059, 24138, 24138, 23746, 24047, 23597, 52958, 24065, 23597, 23597, 24047, 24047, 24047, 24047, 24047, 24047, 24047, 24047, 24047, 24047, 24043, 24043, 24043, 24043, 24043, 24043, 24043, 24043, 24043, 23597, 23597, 24043, 24043, 24043, 24043, 24043, 52956, 23597, 24065, 52945, 23814, 52958, 23581, 23596, 23597, 24374, 24374, 23746, 23746, 23746, 23746, 23746, 23880, 23878, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23746, 23746, 23877, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23879, 23746, 23863, 23746, 23746, 52850, 52850, 52850, 52850, 52938, 52938, 52938, 52938, 52933, 52925, 52924);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(23746, 0, 0x0, 0x1, ''), -- Zul'Aman Exterior InvisMan
(52938, 0, 0x0, 0x1, ''), -- Siame-Quashi
(14881, 0, 0x0, 0x1, ''), -- Spider
-- (52938, 0, 0x8, 0x1, ''), -- Siame-Quashi
-- (52938, 0, 0x1, 0x1, ''), -- Siame-Quashi
-- (52933, 0, 0x0, 0x0, ''), -- Blood Guard Hakkuz
(52925, 0, 0x0, 0x1, ''), -- Witch Doctor T'wansi
-- (52924, 29261, 0x0, 0x1, '45225'), -- Vol'jin - Banging the Gong
(25173, 0, 0x0, 0x1, ''), -- Zul'Aman Door Trigger
(23889, 0, 0x0, 0x1, ''), -- Amani'shi Savage
(23597, 0, 0x0, 0x1, ''), -- Amani'shi Guardian
(24175, 0, 0x0, 0x1, ''), -- Amani'shi Lookout
(23576, 0, 0x0, 0x1, '97531'), -- Nalorakk - Nalorakk Abilities
(52956, 0, 0x0, 0x1, '97987'), -- Zandalari Juggernaut - Tectonic Plating
(52962, 0, 0x0, 0x1, ''), -- Zandalari Archon
(24325, 0, 0x0, 0x1, ''), -- Eagle Troll Spawn Target
(24223, 0, 0x0, 0x1, ''), -- Eagle Trash Aggro Trigger
(24179, 0, 0x0, 0x1, '18950'), -- Amani'shi Wind Walker - Invisibility and Stealth Detection
(24180, 0, 0x0, 0x1, ''), -- Amani'shi Protector
(1412, 0, 0x0, 0x1, ''), -- Squirrel
(52958, 0, 0x0, 0x1, ''), -- Zandalari Hierophant
(53021, 0, 0x0, 0x1, ''), -- Amani'shi Peon
(24396, 0, 0x0, 0x1, ''), -- Forest Frog
-- (53021, 0, 0x1, 0x1, ''), -- Amani'shi Peon
(24549, 0, 0x0, 0x1, ''), -- Amani'shi Tempest
(24363, 0, 0x0, 0x1, ''), -- Hex Lord Malacrass
(23574, 0, 0x0, 0x1, ''), -- Akil'zon
(52941, 0, 0x0, 0x1, ''), -- Bakkalzu
(23814, 0, 0x0, 0x1, ''), -- Zul'Aman - Eagle God Invisman
(24551, 0, 0x0, 0x1, ''), -- Eagle Event Deactivation Trigger
(24858, 0, 0x0, 0x1, ''), -- Soaring Eagle
(6491, 0, 0x10000, 0x1, '10848'), -- Spirit Healer - Shroud of Death
(23542, 0, 0x0, 0x1, '97848'), -- Amani'shi Axe Thrower - Wave 1 Aggro Proc
(23582, 0, 0x0, 0x1, '97848'), -- Amani'shi Tribesman - Wave 1 Aggro Proc
(23584, 0, 0x0, 0x1, ''), -- Amani Bear
(23817, 0, 0x0, 0x1, ''), -- Dragonhawk Egg
-- (23581, 0, 0x0, 0x1, '97849'), -- Amani'shi Medicine Man - Wave 2 Aggro Proc
-- (23582, 0, 0x0, 0x1, '97849'), -- Amani'shi Tribesman - Wave 2 Aggro Proc
-- (23542, 0, 0x0, 0x1, '97849'), -- Amani'shi Axe Thrower - Wave 2 Aggro Proc
(23807, 0, 0x0, 0x1, ''), -- Zul'Aman - Bear God Invisman
(23580, 22467, 0x0, 0x1, '97850'), -- Amani'shi Warbringer - Wave 3 Aggro Proc
-- (23580, 22467, 0x0, 0x1, '97851'), -- Amani'shi Warbringer - Wave 4 Aggro Proc
-- (23542, 0, 0x0, 0x1, '97851'), -- Amani'shi Axe Thrower - Wave 4 Aggro Proc
-- (23581, 0, 0x0, 0x1, '97851'), -- Amani'shi Medicine Man - Wave 4 Aggro Proc
(52939, 0, 0x0, 0x1, '42726'), -- Hazlek - Cosmetic - Immolation (Whole Body)
(22515, 0, 0x0, 0x1, ''), -- World Trigger
-- (23596, 0, 0x0, 0x0, ''), -- Amani'shi Flame Caster
-- (23586, 0, 0x1, 0x1, '18950'), -- Amani'shi Scout - Invisibility and Stealth Detection
-- (23597, 0, 0x0, 0x0, ''), -- Amani'shi Guardian
-- (23586, 0, 0x0, 0x0, '18950'), -- Amani'shi Scout - Invisibility and Stealth Detection
(23596, 0, 0x0, 0x1, ''), -- Amani'shi Flame Caster
(23834, 0, 0x0, 0x1, '18950'), -- Amani Dragonhawk - Invisibility and Stealth Detection
(24312, 0, 0x0, 0x1, ''), -- Dragonhawk Egg
(23774, 0, 0x0, 0x1, ''), -- Amani'shi Trainer
(23586, 0, 0x0, 0x1, '18950'), -- Amani'shi Scout - Invisibility and Stealth Detection
(23578, 0, 0x0, 0x1, ''), -- Jan'alai
(52943, 0, 0x7, 0x1, '42726'), -- Norkani - Cosmetic - Immolation (Whole Body)
-- (21252, 0, 0x0, 0x1, '43113'), -- World Trigger (Not Immune PC) - Fire Wall
(23813, 0, 0x0, 0x1, ''), -- Zul'Aman - Dragonhawk God Invisman
-- (23597, 0, 0x1, 0x1, ''), -- Amani'shi Guardian
-- (23596, 0, 0x3, 0x1, ''), -- Amani'shi Flame Caster
(21252, 0, 0x0, 0x1, '46750'), -- World Trigger (Not Immune PC) - Teleport Aura
(24064, 0, 0x0, 0x1, ''), -- Amani Lynx Cub
(24530, 0, 0x0, 0x1, ''), -- Amani Elder Lynx
(24240, 0, 0x0, 0x1, ''), -- Alyson Antille
(24239, 0, 0x0, 0x1, ''), -- Hex Lord Malacrass
(24246, 0, 0x0, 0x1, ''), -- Darkheart
-- (24065, 0, 0x1, 0x1, '18950'), -- Amani'shi Handler - Invisibility and Stealth Detection
(24065, 0, 0x0, 0x1, '18950'), -- Amani'shi Handler - Invisibility and Stealth Detection
(23577, 0, 0x0, 0x1, ''), -- Halazzi
(22517, 0, 0x0, 0x1, ''), -- World Trigger (Large AOI)
(23897, 0, 0x0, 0x1, ''), -- Zungam
(24047, 0, 0x0, 0x1, ''), -- Amani Crocolisk
(24059, 0, 0x0, 0x1, ''), -- Amani'shi Beast Tamer
(24138, 0, 0x0, 0x1, ''), -- Tamed Amani Crocolisk
(24043, 0, 0x0, 0x1, '18950'), -- Amani Lynx - Invisibility and Stealth Detection
(52945, 0, 0x7, 0x1, '42726'), -- Kasha - Cosmetic - Immolation (Whole Body)
(23581, 0, 0x0, 0x1, ''), -- Amani'shi Medicine Man
(24374, 0, 0x0, 0x1, ''), -- Amani'shi Berserker
(23880, 0, 0x0, 0x1, '42466'), -- Amani Eagle Spirit - Spirit Visual
(23878, 0, 0x0, 0x1, '42466'), -- Amani Bear Spirit - Spirit Visual
(23877, 0, 0x0, 0x1, '42466'), -- Amani Lynx Spirit - Spirit Visual
-- (23889, 0, 0x8, 0x1, ''), -- Amani'shi Savage
(23879, 0, 0x0, 0x1, '42466'), -- Amani Dragonhawk Spirit - Spirit Visual
(23863, 0, 0x0, 0x1, '97696'), -- Zul'jin - Ring Out Achievement
(52850, 0, 0x0, 0x1, ''), -- Quad Stalker
(52933, 0, 0x0, 0x1, ''), -- Blood Guard Hakkuz
(52924, 29261, 0x0, 0x1, ''); -- Vol'jin


UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=38087; -- 38087
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=38086; -- 38086
UPDATE `creature_model_info` SET `bounding_radius`=0.347222, `combat_reach`=1.5 WHERE `modelid`=22323; -- 22323
UPDATE `creature_model_info` SET `bounding_radius`=0.347222, `combat_reach`=1.5 WHERE `modelid`=22325; -- 22325
UPDATE `creature_model_info` SET `bounding_radius`=0.347222, `combat_reach`=1.5 WHERE `modelid`=22324; -- 22324
UPDATE `creature_model_info` SET `bounding_radius`=0.347222, `combat_reach`=1.5 WHERE `modelid`=22322; -- 22322
UPDATE `creature_model_info` SET `bounding_radius`=0.4513886, `combat_reach`=1.95 WHERE `modelid`=22309; -- 22309
UPDATE `creature_model_info` SET `bounding_radius`=0.4513886, `combat_reach`=1.95 WHERE `modelid`=22310; -- 22310
UPDATE `creature_model_info` SET `bounding_radius`=0.4340275, `combat_reach`=1.875 WHERE `modelid`=22161; -- 22161
UPDATE `creature_model_info` SET `bounding_radius`=0.9, `combat_reach`=3, `gender`=0 WHERE `modelid`=21631; -- 21631
UPDATE `creature_model_info` SET `bounding_radius`=0.4340275, `combat_reach`=1.875 WHERE `modelid`=22262; -- 22262
UPDATE `creature_model_info` SET `bounding_radius`=0.4513886, `combat_reach`=1.95 WHERE `modelid`=22264; -- 22264
UPDATE `creature_model_info` SET `bounding_radius`=0.2777776, `combat_reach`=1.2, `gender`=0 WHERE `modelid`=38121; -- 38121
UPDATE `creature_model_info` SET `bounding_radius`=0.2777776, `combat_reach`=1.2, `gender`=0 WHERE `modelid`=38119; -- 38119
UPDATE `creature_model_info` SET `bounding_radius`=0.2777776, `combat_reach`=1.2, `gender`=0 WHERE `modelid`=38120; -- 38120
UPDATE `creature_model_info` SET `bounding_radius`=0.2777776, `combat_reach`=1.2, `gender`=0 WHERE `modelid`=38122; -- 38122
UPDATE `creature_model_info` SET `bounding_radius`=0.4340275, `combat_reach`=1.875 WHERE `modelid`=22261; -- 22261
UPDATE `creature_model_info` SET `bounding_radius`=0.5902774, `combat_reach`=2.55 WHERE `modelid`=22538; -- 22538
UPDATE `creature_model_info` SET `bounding_radius`=0.4513886, `combat_reach`=1.95 WHERE `modelid`=22263; -- 22263
UPDATE `creature_model_info` SET `bounding_radius`=0.9, `combat_reach`=3, `gender`=0 WHERE `modelid`=21630; -- 21630
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=38097; -- 38097
UPDATE `creature_model_info` SET `bounding_radius`=0.4513886, `combat_reach`=1.95 WHERE `modelid`=22274; -- 22274
UPDATE `creature_model_info` SET `bounding_radius`=0.4513886, `combat_reach`=1.95 WHERE `modelid`=22272; -- 22272
UPDATE `creature_model_info` SET `bounding_radius`=0.4513886, `combat_reach`=1.95 WHERE `modelid`=22273; -- 22273
UPDATE `creature_model_info` SET `bounding_radius`=1.5, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=22467; -- 22467
UPDATE `creature_model_info` SET `bounding_radius`=0.4340275, `combat_reach`=1.875 WHERE `modelid`=22275; -- 22275
UPDATE `creature_model_info` SET `bounding_radius`=0.4513886, `combat_reach`=1.95 WHERE `modelid`=22271; -- 22271
UPDATE `creature_model_info` SET `bounding_radius`=0.4513886, `combat_reach`=1.95 WHERE `modelid`=22277; -- 22277
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=38096; -- 38096
UPDATE `creature_model_info` SET `bounding_radius`=0.4340275, `combat_reach`=1.875 WHERE `modelid`=22307; -- 22307
UPDATE `creature_model_info` SET `bounding_radius`=0.3825, `combat_reach`=1.875 WHERE `modelid`=22983; -- 22983
UPDATE `creature_model_info` SET `bounding_radius`=0.255, `combat_reach`=1.275 WHERE `modelid`=37573; -- 37573
UPDATE `creature_model_info` SET `bounding_radius`=0.4513886, `combat_reach`=1.95 WHERE `modelid`=22313; -- 22313
UPDATE `creature_model_info` SET `bounding_radius`=0.4513886, `combat_reach`=1.95 WHERE `modelid`=22314; -- 22314
UPDATE `creature_model_info` SET `bounding_radius`=0.9, `combat_reach`=3, `gender`=0 WHERE `modelid`=21633; -- 21633
UPDATE `creature_model_info` SET `bounding_radius`=0.4340275, `combat_reach`=1.875 WHERE `modelid`=22308; -- 22308
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=38098; -- 38098
UPDATE `creature_model_info` SET `bounding_radius`=0.341, `combat_reach`=1.5 WHERE `modelid`=30963; -- 30963
UPDATE `creature_model_info` SET `bounding_radius`=0.6894, `combat_reach`=2.7 WHERE `modelid`=22230; -- 22230
UPDATE `creature_model_info` SET `bounding_radius`=0.9722216, `combat_reach`=4.2 WHERE `modelid`=22332; -- 22332
UPDATE `creature_model_info` SET `bounding_radius`=1.75, `combat_reach`=2.625 WHERE `modelid`=22335; -- 22335
UPDATE `creature_model_info` SET `bounding_radius`=0.4340275, `combat_reach`=1.875 WHERE `modelid`=22304; -- 22304
UPDATE `creature_model_info` SET `bounding_radius`=0.4340275, `combat_reach`=1.875 WHERE `modelid`=22303; -- 22303
UPDATE `creature_model_info` SET `bounding_radius`=0.9, `combat_reach`=3, `gender`=0 WHERE `modelid`=21632; -- 21632
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5 WHERE `modelid`=21893; -- 21893
UPDATE `creature_model_info` SET `bounding_radius`=1.2501, `combat_reach`=2.25 WHERE `modelid`=834; -- 834
UPDATE `creature_model_info` SET `bounding_radius`=0.4340275, `combat_reach`=1.875 WHERE `modelid`=22301; -- 22301
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=38099; -- 38099
UPDATE `creature_model_info` SET `bounding_radius`=0.4340275, `combat_reach`=1.875 WHERE `modelid`=22276; -- 22276
UPDATE `creature_model_info` SET `bounding_radius`=0.775, `combat_reach`=5 WHERE `modelid`=22256; -- 22256
UPDATE `creature_model_info` SET `bounding_radius`=1.833, `combat_reach`=4.5 WHERE `modelid`=21830; -- 21830
UPDATE `creature_model_info` SET `bounding_radius`=0.93, `combat_reach`=1.5 WHERE `modelid`=21793; -- 21793
UPDATE `creature_model_info` SET `bounding_radius`=0.525, `combat_reach`=2.625 WHERE `modelid`=21831; -- 21831
UPDATE `creature_model_info` SET `bounding_radius`=0.694444, `combat_reach`=3, `gender`=0 WHERE `modelid`=38118; -- 38118

SET @CGUID := 220823;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+527;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 53021, 568, 1, 1, 126.8472, 1202.01, -16.29678, 1.867502, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+1, 24396, 568, 1, 1, 135.6927, 1206.047, -13.16617, 5.164894, 7200, 0, 0), -- Forest Frog (Area: 0)
(@CGUID+2, 23746, 568, 1, 1, 119.4268, 928.8355, 64.39378, 4.660029, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+3, 24240, 568, 1, 1, 125.5799, 923.1528, 33.97253, 1.58825, 7200, 0, 0), -- Alyson Antille (Area: 0) (possible waypoints or random movement)
(@CGUID+4, 24239, 568, 1, 1, 117.8646, 923.6945, 33.97255, 1.58825, 7200, 0, 0), -- Hex Lord Malacrass (Area: 0) (possible waypoints or random movement)
(@CGUID+5, 24246, 568, 1, 1, 109.309, 923.0504, 33.97256, 1.553343, 7200, 0, 0), -- Darkheart (Area: 0) (possible waypoints or random movement)
(@CGUID+6, 24064, 568, 1, 1, 193.8079, 1175.49, 2.647962, 1.516057, 7200, 0, 0), -- Amani Lynx Cub (Area: 0) (possible waypoints or random movement)
(@CGUID+7, 24064, 568, 1, 1, 194.3827, 1164.006, 1.368286, 5.484831, 7200, 0, 0), -- Amani Lynx Cub (Area: 0) (possible waypoints or random movement)
(@CGUID+8, 1412, 568, 1, 1, 187.3682, 1178.085, 2.69095, 5.741253, 7200, 0, 0), -- Squirrel (Area: 0)
(@CGUID+9, 52956, 568, 1, 1, 236.9167, 1059.5, 0.09429461, 3.595378, 7200, 0, 0), -- Zandalari Juggernaut (Area: 0)
(@CGUID+10, 52958, 568, 1, 1, 230.0781, 1055.707, 0.2012075, 0.6283185, 7200, 0, 0), -- Zandalari Hierophant (Area: 0)
(@CGUID+11, 24065, 568, 1, 1, 236.5967, 1115.737, 0.08333334, 1.675516, 7200, 0, 0), -- Amani'shi Handler (Area: 0)
(@CGUID+12, 24064, 568, 1, 1, 237.4108, 1135.669, 0.08333433, 5.864306, 7200, 0, 0), -- Amani Lynx Cub (Area: 0)
(@CGUID+13, 24065, 568, 1, 1, 243.0647, 1143.474, 0.125, 2.934749, 7200, 0, 0), -- Amani'shi Handler (Area: 0) (possible waypoints or random movement)
(@CGUID+14, 23746, 568, 1, 1, 333.1309, 1085.871, 7.728353, 1.448623, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+15, 23746, 568, 1, 1, 342.9178, 1150.477, 7.065882, 4.39823, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+16, 24064, 568, 1, 1, 221.9648, 1130.846, 0.08333433, 0.8028514, 7200, 0, 0), -- Amani Lynx Cub (Area: 0)
(@CGUID+17, 24064, 568, 1, 1, 227.7935, 1136.081, 0.08333234, 2.356194, 7200, 0, 0), -- Amani Lynx Cub (Area: 0)
(@CGUID+18, 24064, 568, 1, 1, 228.5124, 1126.026, 0.08333234, 4.014257, 7200, 0, 0), -- Amani Lynx Cub (Area: 0)
(@CGUID+19, 24064, 568, 1, 1, 240.458, 1125.036, 0.08333433, 0.8028514, 7200, 0, 0), -- Amani Lynx Cub (Area: 0)
(@CGUID+20, 24064, 568, 1, 1, 247.53, 1128.972, 0.3301703, 3.193953, 7200, 0, 0), -- Amani Lynx Cub (Area: 0)
(@CGUID+21, 24064, 568, 1, 1, 245.3819, 1138.242, 0.08333234, 5.166174, 7200, 0, 0), -- Amani Lynx Cub (Area: 0)
(@CGUID+22, 23577, 568, 1, 1, 370.257, 1135.743, 6.549134, 1.448623, 7200, 0, 0), -- Halazzi (Area: 0) (possible waypoints or random movement)
(@CGUID+23, 22517, 568, 1, 1, 370.7795, 1119.511, 5.784716, 3.874631, 7200, 0, 0), -- World Trigger (Large AOI) (Area: 0)
(@CGUID+24, 23746, 568, 1, 1, 383.2224, 1152.546, 6.426994, 4.555309, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+25, 23746, 568, 1, 1, 390.18, 1080.001, 6.426977, 3.385939, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+26, 23897, 568, 1, 1, 250.1413, 996.7825, 10.99151, 2.007129, 7200, 0, 0), -- Zungam (Area: 0)
(@CGUID+27, 24047, 568, 1, 1, 286.0339, 1033.078, -3.82142, 1.437651, 7200, 0, 0), -- Amani Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+28, 24047, 568, 1, 1, 296.9295, 1019.789, -1.771615, 0.3105986, 7200, 0, 0), -- Amani Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+29, 24059, 568, 1, 1, 309.9468, 1030.991, 0.1677107, 5.038402, 7200, 0, 0), -- Amani'shi Beast Tamer (Area: 0) (possible waypoints or random movement)
(@CGUID+30, 24138, 568, 1, 1, 306.1252, 1029.593, 0.09859085, 5.060909, 7200, 0, 0), -- Tamed Amani Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+31, 24138, 568, 1, 1, 313.6117, 1032.311, 0.1593672, 5.071356, 7200, 0, 0), -- Tamed Amani Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+32, 23746, 568, 1, 1, 423.0996, 1084.315, 7.316636, 2.548181, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+33, 24047, 568, 1, 1, 303.4022, 1004.776, -5.457073, 4.935946, 7200, 0, 0), -- Amani Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+34, 23597, 568, 1, 1, 346.1951, 1046.094, 9.595057, 3.141593, 7200, 0, 0), -- Amani'shi Guardian (Area: 0)
(@CGUID+35, 52958, 568, 1, 1, 338.1121, 1051.793, 9.60488, 5.253441, 7200, 0, 0), -- Zandalari Hierophant (Area: 0)
(@CGUID+36, 24065, 568, 1, 1, 337.652, 1043.239, 9.604876, 0.8726646, 7200, 0, 0), -- Amani'shi Handler (Area: 0)
(@CGUID+37, 23597, 568, 1, 1, 337.2353, 1022.442, 9.605337, 4.520403, 7200, 0, 0), -- Amani'shi Guardian (Area: 0)
(@CGUID+38, 23597, 568, 1, 1, 327.9329, 1030.541, 9.605011, 3.298672, 7200, 0, 0), -- Amani'shi Guardian (Area: 0)
(@CGUID+39, 24047, 568, 1, 1, 315.625, 988.542, -5.543424, 1.292127, 7200, 0, 0), -- Amani Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+40, 24047, 568, 1, 1, 335.0742, 977.9414, -2.257419, 0.235507, 7200, 0, 0), -- Amani Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+41, 24047, 568, 1, 1, 288.3621, 874.1204, -1.49208, 2.565634, 7200, 0, 0), -- Amani Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+42, 24047, 568, 1, 1, 272.5919, 875.3275, -1.336503, 5.270895, 7200, 0, 0), -- Amani Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+43, 24047, 568, 1, 1, 281.395, 902.0822, 0.4699233, 5.846853, 7200, 0, 0), -- Amani Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+44, 24047, 568, 1, 1, 280.8683, 889.9552, -0.3481417, 1.972222, 7200, 0, 0), -- Amani Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+45, 24047, 568, 1, 1, 361.1954, 899.1907, -2.561936, 1.850049, 7200, 0, 0), -- Amani Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+46, 24047, 568, 1, 1, 355.6435, 923.7117, -2.526138, 3.141593, 7200, 0, 0), -- Amani Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+47, 24047, 568, 1, 1, 338.2008, 957.9579, -2.702579, 1.968473, 7200, 0, 0), -- Amani Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+48, 24047, 568, 1, 1, 364.813, 874.9839, -3.226526, 5.577332, 7200, 0, 0), -- Amani Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+49, 24043, 568, 1, 1, 408.5535, 891.5619, 0.125, 4.685212, 7200, 0, 0), -- Amani Lynx (Area: 0)
(@CGUID+50, 24043, 568, 1, 1, 403.7654, 895.4753, 0.125, 5.206737, 7200, 0, 0), -- Amani Lynx (Area: 0)
(@CGUID+51, 24043, 568, 1, 1, 404.8013, 876.7266, 0.2469583, 1.226453, 7200, 0, 0), -- Amani Lynx (Area: 0)
(@CGUID+52, 24043, 568, 1, 1, 423.3551, 905.123, 0.3692112, 4.027855, 7200, 0, 0), -- Amani Lynx (Area: 0)
(@CGUID+53, 24043, 568, 1, 1, 440.2548, 930.2247, 0.2084785, 0.4783139, 7200, 0, 0), -- Amani Lynx (Area: 0)
(@CGUID+54, 24043, 568, 1, 1, 443.6231, 942.5699, 0.125, 4.920036, 7200, 0, 0), -- Amani Lynx (Area: 0)
(@CGUID+55, 24043, 568, 1, 1, 445.7425, 963.6548, 0.125, 4.708923, 7200, 0, 0), -- Amani Lynx (Area: 0)
(@CGUID+56, 24043, 568, 1, 1, 450.0388, 933.6926, 0.125, 3.294324, 7200, 0, 0), -- Amani Lynx (Area: 0)
(@CGUID+57, 24043, 568, 1, 1, 451.7911, 951.9664, 0.2226419, 4.398367, 7200, 0, 0), -- Amani Lynx (Area: 0)
(@CGUID+58, 23597, 568, 1, 1, 411.5532, 1022.259, 9.605077, 4.782202, 7200, 0, 0), -- Amani'shi Guardian (Area: 0)
(@CGUID+59, 23597, 568, 1, 1, 400.7974, 1022.438, 9.605576, 4.660029, 7200, 0, 0), -- Amani'shi Guardian (Area: 0)
(@CGUID+60, 24043, 568, 1, 1, 423.337, 980.8189, 0.08333033, 0.541052, 7200, 0, 0), -- Amani Lynx (Area: 0)
(@CGUID+61, 24043, 568, 1, 1, 394.9993, 988.6764, 0.125, 6.113269, 7200, 0, 0), -- Amani Lynx (Area: 0)
(@CGUID+62, 24043, 568, 1, 1, 423.787, 992.6092, 0.3991549, 4.831779, 7200, 0, 0), -- Amani Lynx (Area: 0)
(@CGUID+63, 24043, 568, 1, 1, 382.6401, 992.0042, 0.125, 6.085645, 7200, 0, 0), -- Amani Lynx (Area: 0)
(@CGUID+64, 24043, 568, 1, 1, 393.9897, 1008.093, 0.75, 5.497866, 7200, 0, 0), -- Amani Lynx (Area: 0)
(@CGUID+65, 52956, 568, 1, 1, 397.7076, 1048.77, 9.604503, 6.108652, 7200, 0, 0), -- Zandalari Juggernaut (Area: 0)
(@CGUID+66, 23597, 568, 1, 1, 406.0692, 1044.394, 9.60488, 2.356194, 7200, 0, 0), -- Amani'shi Guardian (Area: 0)
(@CGUID+67, 24065, 568, 1, 1, 406.4329, 1054.867, 9.604886, 4.520403, 7200, 0, 0), -- Amani'shi Handler (Area: 0)
(@CGUID+68, 52946, 568, 1, 1, 383.4793, 1088.059, 5.974284, 1.63491, 7200, 0, 0), -- Kasha (Area: 0)
(@CGUID+69, 23814, 568, 1, 1, 369.8111, 1088.396, 6.595592, 4.764749, 7200, 0, 0), -- Zul'Aman - Eagle God Invisman (Area: 0)
(@CGUID+70, 52958, 568, 1, 1, 114.8588, 992.1212, 30.54751, 0.6108652, 7200, 0, 0), -- Zandalari Hierophant (Area: 0) (possible waypoints or random movement)
(@CGUID+71, 23581, 568, 1, 1, 120.3534, 992.8157, 30.74231, 2.373648, 7200, 0, 0), -- Amani'shi Medicine Man (Area: 0) (possible waypoints or random movement)
(@CGUID+72, 23596, 568, 1, 1, 121.9231, 996.9573, 30.77481, 3.420845, 7200, 0, 0), -- Amani'shi Flame Caster (Area: 0) (possible waypoints or random movement)
(@CGUID+73, 23597, 568, 1, 1, 116.2163, 997.4488, 30.57613, 5.393067, 7200, 0, 0), -- Amani'shi Guardian (Area: 0) (possible waypoints or random movement)
(@CGUID+74, 24374, 568, 1, 1, 130.2552, 960.4305, 31.10892, 1.762783, 7200, 0, 0), -- Amani'shi Berserker (Area: 0) (possible waypoints or random movement)
(@CGUID+75, 24374, 568, 1, 1, 107.5868, 962.0174, 29.97174, 1.396263, 7200, 0, 0), -- Amani'shi Berserker (Area: 0) (possible waypoints or random movement)
(@CGUID+76, 23746, 568, 1, 1, 120.4323, 766.1129, 55.10535, 6.265732, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+77, 23746, 568, 1, 1, 130.3624, 733.8627, 49.7089, 4.34587, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+78, 23746, 568, 1, 1, 110.7865, 734.368, 49.49263, 3.281219, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+79, 23746, 568, 1, 1, 78.35069, 733.0399, 56.71772, 3.438299, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+80, 23746, 568, 1, 1, 135.5174, 720.7188, 58.29888, 4.171337, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+81, 23880, 568, 1, 1, 105.5265, 724.9262, 45.19471, 5.358161, 7200, 0, 0), -- Amani Eagle Spirit (Area: 0) (possible waypoints or random movement)
(@CGUID+82, 23878, 568, 1, 1, 134.5998, 724.3408, 45.19471, 4.066617, 7200, 0, 0), -- Amani Bear Spirit (Area: 0) (possible waypoints or random movement)
(@CGUID+83, 23889, 568, 1, 1, 121.2992, 869.9263, 33.45835, 1.291544, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+84, 23889, 568, 1, 1, 121.2045, 879.6914, 33.4736, 1.343904, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+85, 23889, 568, 1, 1, 119.163, 883.8483, 33.51263, 1.448623, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+86, 23889, 568, 1, 1, 119.5603, 874.8582, 33.48911, 1.413717, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+87, 23889, 568, 1, 1, 118.8996, 863.9178, 33.45926, 1.32645, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+88, 23889, 568, 1, 1, 121.4269, 889.0146, 33.48838, 1.361357, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+89, 23889, 568, 1, 1, 117.2093, 859.3001, 33.45927, 1.396263, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+90, 23889, 568, 1, 1, 123.2586, 859.0441, 33.45927, 1.37881, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+91, 23889, 568, 1, 1, 111.8493, 857.0572, 33.45926, 1.291544, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+92, 23889, 568, 1, 1, 128.9489, 856.4097, 33.45927, 1.308997, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+93, 23889, 568, 1, 1, 95.40745, 827.434, 33.45926, 1.658063, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+94, 23889, 568, 1, 1, 98.03613, 823.7934, 33.45927, 1.570796, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+95, 23889, 568, 1, 1, 143.8894, 825.9803, 33.45926, 1.53589, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+96, 23889, 568, 1, 1, 140.5423, 821.4152, 33.45926, 1.570796, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+97, 23889, 568, 1, 1, 98.59354, 819.1327, 33.45926, 1.605703, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+98, 23889, 568, 1, 1, 102.3006, 816.0118, 33.45926, 1.623156, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+99, 23889, 568, 1, 1, 139.8846, 816.5479, 33.45927, 1.64061, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+100, 23889, 568, 1, 1, 136.1947, 814.0804, 33.45926, 1.518436, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+101, 23889, 568, 1, 1, 103.6184, 811.7459, 33.45927, 1.553343, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+102, 23889, 568, 1, 1, 134.4181, 809.7753, 33.45927, 1.500983, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+103, 23889, 568, 1, 1, 120.719, 789.5555, 33.49589, 1.815142, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+104, 23889, 568, 1, 1, 118.15, 784.1548, 33.51597, 1.745329, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+105, 23889, 568, 1, 1, 120.6477, 779.3137, 33.53322, 1.727876, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+106, 23889, 568, 1, 1, 118.435, 773.8891, 33.5535, 1.692969, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+107, 23889, 568, 1, 1, 125.2321, 767.5013, 33.60368, 1.762783, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+108, 23889, 568, 1, 1, 115.9722, 766.7875, 33.63086, 1.428563, 7200, 0, 0), -- Amani'shi Savage (Area: 0)
(@CGUID+109, 23889, 568, 1, 1, 120.6259, 763.826, 33.71795, 1.44281, 7200, 0, 0), -- Amani'shi Savage (Area: 0)
(@CGUID+110, 23889, 568, 1, 1, 125.5915, 760.1313, 33.8483, 2.422666, 7200, 0, 0), -- Amani'shi Savage (Area: 0)
(@CGUID+111, 23889, 568, 1, 1, 115.5157, 759.6605, 33.84968, 1.570088, 7200, 0, 0), -- Amani'shi Savage (Area: 0)
(@CGUID+112, 23889, 568, 1, 1, 120.4031, 756.4976, 33.84968, 1.433999, 7200, 0, 0), -- Amani'shi Savage (Area: 0)
(@CGUID+113, 23889, 568, 1, 1, 116.778, 748.9891, 37.14451, 1.321692, 7200, 0, 0), -- Amani'shi Savage (Area: 0)
(@CGUID+114, 23889, 568, 1, 1, 124.8122, 749.1364, 36.96867, 1.833704, 7200, 0, 0), -- Amani'shi Savage (Area: 0)
(@CGUID+115, 23889, 568, 1, 1, 120.3957, 745.8044, 39.64478, 1.57868, 7200, 0, 0), -- Amani'shi Savage (Area: 0)
(@CGUID+116, 23889, 568, 1, 1, 115.2873, 744.0933, 40.91274, 1.568771, 7200, 0, 0), -- Amani'shi Savage (Area: 0)
(@CGUID+117, 23889, 568, 1, 1, 125.6053, 744.1508, 40.80178, 1.908645, 7200, 0, 0), -- Amani'shi Savage (Area: 0)
(@CGUID+118, 23889, 568, 1, 1, 120.2608, 741.7857, 42.7495, 1.598383, 7200, 0, 0), -- Amani'shi Savage (Area: 0)
(@CGUID+119, 23889, 568, 1, 1, 125.8623, 740.1678, 43.91919, 1.851394, 7200, 0, 0), -- Amani'shi Savage (Area: 0)
(@CGUID+120, 23889, 568, 1, 1, 114.7597, 739.7479, 44.32387, 1.565722, 7200, 0, 0), -- Amani'shi Savage (Area: 0)
(@CGUID+121, 23889, 568, 1, 1, 117.9806, 736.8023, 45.19473, 1.447222, 7200, 0, 0), -- Amani'shi Savage (Area: 0)
(@CGUID+122, 23889, 568, 1, 1, 122.2798, 736.7369, 45.19473, 1.60923, 7200, 0, 0), -- Amani'shi Savage (Area: 0)
(@CGUID+123, 23746, 568, 1, 1, 92.49653, 698.9167, 64.25027, 2.321288, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+124, 23746, 568, 1, 1, 148.6875, 698.3715, 67.61139, 1.012291, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+125, 23877, 568, 1, 1, 149.6574, 705.75, 45.19477, 3.106686, 7200, 0, 0), -- Amani Lynx Spirit (Area: 0)
(@CGUID+126, 23889, 568, 1, 1, 135.8311, 688.9501, 45.19472, 4.747295, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+127, 23889, 568, 1, 1, 132.5362, 689.2184, 45.19472, 4.694936, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+128, 23889, 568, 1, 1, 129.2538, 689.1514, 45.19472, 4.660029, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+129, 23889, 568, 1, 1, 125.9288, 689.121, 45.19471, 4.764749, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+130, 23889, 568, 1, 1, 112.498, 689.1459, 45.19471, 4.660029, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+131, 23889, 568, 1, 1, 109.5535, 689.0452, 45.19472, 4.642576, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+132, 23889, 568, 1, 1, 106.8334, 689.0573, 45.19471, 4.729842, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+133, 23889, 568, 1, 1, 103.7123, 689.0286, 45.19471, 4.572762, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+134, 23879, 568, 1, 1, 91.13303, 705.7529, 45.19471, 0.01745329, 7200, 0, 0), -- Amani Dragonhawk Spirit (Area: 0) (possible waypoints or random movement)
(@CGUID+135, 23746, 568, 1, 1, 69.91819, 683.5466, 57.15291, 4.415683, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+136, 23863, 568, 1, 1, 119.9806, 674.2449, 51.82448, 1.466077, 7200, 0, 0), -- Zul'jin (Area: 0) (possible waypoints or random movement)
(@CGUID+137, 23746, 568, 1, 1, 130.9566, 659.7177, 57.00269, 5.410521, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+138, 23746, 568, 1, 1, 108.1197, 659.9573, 55.39274, 4.014257, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+139, 52850, 568, 1, 1, 102.5069, 717.1111, 45.19468, 0, 7200, 0, 0), -- Quad Stalker (Area: 0)
(@CGUID+140, 52850, 568, 1, 1, 137.9774, 716.8143, 45.19469, 0, 7200, 0, 0), -- Quad Stalker (Area: 0)
(@CGUID+141, 52850, 568, 1, 1, 102.3733, 696.1424, 45.19468, 0, 7200, 0, 0), -- Quad Stalker (Area: 0)
(@CGUID+142, 52850, 568, 1, 1, 137.8142, 695.809, 45.19469, 0, 7200, 0, 0), -- Quad Stalker (Area: 0)
(@CGUID+143, 52938, 568, 1, 1, 140.3168, 675.4478, 50.47615, 2.609154, 7200, 0, 0), -- Siame-Quashi (Area: 0) (possible waypoints or random movement)
(@CGUID+144, 52938, 568, 1, 1, 96.60017, 671.1309, 55.38797, 6.079883, 7200, 0, 0), -- Siame-Quashi (Area: 0) (possible waypoints or random movement)
(@CGUID+145, 52938, 568, 1, 1, 71.08985, 681.7556, 58.61654, 0.9031725, 7200, 0, 0), -- Siame-Quashi (Area: 0) (possible waypoints or random movement)
(@CGUID+146, 52938, 568, 1, 1, 151.6018, 723.7537, 45.44305, 4.162918, 7200, 0, 0), -- Siame-Quashi (Area: 0) (possible waypoints or random movement)
(@CGUID+147, 52933, 568, 1, 1, 127.2369, 760.9934, 33.73362, 4.729511, 7200, 0, 0), -- Blood Guard Hakkuz (Area: 0) (possible waypoints or random movement)
(@CGUID+148, 52925, 568, 1, 1, 114.5734, 763.373, 33.71713, 4.773839, 7200, 0, 0), -- Witch Doctor T'wansi (Area: 0)
(@CGUID+149, 52924, 568, 1, 1, 120.6902, 761.9821, 33.67579, 4.757428, 7200, 0, 0), -- Vol'jin (Area: 0) (possible waypoints or random movement)
(@CGUID+150, 53488, 568, 1, 1, 120.7899, 1729.146, 42.10487, 0, 7200, 0, 0), -- Summon Enabler Stalker (Area: 0)
(@CGUID+151, 53488, 568, 1, 1, 84.74132, 1726.252, 42.1048, 0, 7200, 0, 0), -- Summon Enabler Stalker (Area: 0)
(@CGUID+152, 53488, 568, 1, 1, 119.4306, 1762.863, 43.03535, 0, 7200, 0, 0), -- Summon Enabler Stalker (Area: 0)
(@CGUID+153, 53488, 568, 1, 1, 158.6962, 1727.042, 42.10493, 0, 7200, 0, 0), -- Summon Enabler Stalker (Area: 0)
(@CGUID+154, 23746, 568, 1, 1, 133.8215, 1759.531, 47.91025, 1.727876, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+155, 52938, 568, 1, 1, 111.6285, 1712.754, 42.10487, 1.43117, 7200, 0, 0), -- Siame-Quashi (Area: 0)
(@CGUID+156, 52938, 568, 1, 1, 130.0938, 1712.254, 42.1049, 1.762783, 7200, 0, 0), -- Siame-Quashi (Area: 0)
(@CGUID+157, 23746, 568, 1, 1, 119.2955, 1711.27, 47.27927, 2.042035, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+158, 14881, 568, 1, 1, 84.76714, 1725.754, 42.10481, 4.171337, 7200, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+159, 52938, 568, 1, 1, 163.1094, 1733.146, 42.10496, 6.003932, 7200, 0, 0), -- Siame-Quashi (Area: 0) (possible waypoints or random movement)
(@CGUID+160, 52938, 568, 1, 1, 168.375, 1737.747, 42.10496, 4.677482, 7200, 0, 0), -- Siame-Quashi (Area: 0) (possible waypoints or random movement)
(@CGUID+161, 52938, 568, 1, 1, 168.2379, 1728.352, 42.10496, 1.762783, 7200, 0, 0), -- Siame-Quashi (Area: 0) (possible waypoints or random movement)
(@CGUID+162, 52938, 568, 1, 1, 172.7396, 1733.273, 42.10497, 3.001966, 7200, 0, 0), -- Siame-Quashi (Area: 0) (possible waypoints or random movement)
(@CGUID+163, 14881, 568, 1, 1, 170.9538, 1727.968, 42.10496, 0.08726646, 7200, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+164, 23746, 568, 1, 1, 87.41319, 1703.156, 45.55624, 4.747295, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+165, 52938, 568, 1, 1, 71.8941, 1711.351, 42.10484, 3.141593, 7200, 0, 0), -- Siame-Quashi (Area: 0)
(@CGUID+166, 52938, 568, 1, 1, 66.80903, 1714.986, 42.10484, 4.817109, 7200, 0, 0), -- Siame-Quashi (Area: 0)
(@CGUID+167, 14881, 568, 1, 1, 162.7597, 1697.514, 42.10495, 3.281219, 7200, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+168, 52938, 568, 1, 1, 68.32291, 1705.712, 42.10485, 1.902409, 7200, 0, 0), -- Siame-Quashi (Area: 0)
(@CGUID+169, 52938, 568, 1, 1, 62.43576, 1709.542, 42.10485, 6.143559, 7200, 0, 0), -- Siame-Quashi (Area: 0)
(@CGUID+170, 23746, 568, 1, 1, 63.90148, 1735.931, 47.68813, 5.8294, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+171, 23746, 568, 1, 1, 119.4023, 1680.13, 47.6264, 5.689773, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+172, 52933, 568, 1, 1, 111.4809, 1678.047, 42.10491, 4.834562, 7200, 0, 0), -- Blood Guard Hakkuz (Area: 0)
(@CGUID+173, 52925, 568, 1, 1, 130.2743, 1677.837, 42.10493, 4.642576, 7200, 0, 0), -- Witch Doctor T'wansi (Area: 0)
(@CGUID+174, 23746, 568, 1, 1, 104.3134, 1678.456, 45.7201, 0.3839724, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+175, 53488, 568, 1, 1, 155.1736, 1666.012, 42.10493, 0.9599311, 7200, 0, 0), -- Summon Enabler Stalker (Area: 0)
(@CGUID+176, 14881, 568, 1, 1, 73.04655, 1687.665, 42.10487, 0.5759587, 7200, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+177, 23746, 568, 1, 1, 89.92264, 1678.821, 42.10489, 5.864306, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+178, 52924, 568, 1, 1, 121.0399, 1672.196, 42.10492, 4.782202, 7200, 0, 0), -- Vol'jin (Area: 0) (possible waypoints or random movement)
(@CGUID+179, 52938, 568, 1, 1, 102.6476, 1672.663, 42.1049, 4.712389, 7200, 0, 0), -- Siame-Quashi (Area: 0)
(@CGUID+180, 52938, 568, 1, 1, 137.1493, 1672.302, 42.10493, 4.764749, 7200, 0, 0), -- Siame-Quashi (Area: 0)
(@CGUID+181, 23746, 568, 1, 1, 58.45258, 1695.63, 47.05721, 3.001966, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+182, 23746, 568, 1, 1, 182.8277, 1695.275, 45.74854, 1.623156, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+183, 23746, 568, 1, 1, 91.43359, 1668.38, 42.10489, 4.799655, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+184, 23746, 568, 1, 1, 116.7426, 1659.94, 42.10491, 1.343904, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+185, 23746, 568, 1, 1, 94.99078, 1656.762, 42.10489, 5.88176, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+186, 23746, 568, 1, 1, 77.94531, 1651.015, 46.73899, 4.310963, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+187, 23746, 568, 1, 1, 65.66504, 1656.891, 51.85952, 5.951573, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+188, 23746, 568, 1, 1, 81.9872, 1648.868, 47.94931, 1.466077, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+189, 23746, 568, 1, 1, 81.8456, 1648.206, 45.82775, 0.9599311, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+190, 23746, 568, 1, 1, 179.9117, 1657.18, 47.80621, 3.508112, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+191, 23746, 568, 1, 1, 120.172, 1638.108, 42.35682, 6.230825, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+192, 23746, 568, 1, 1, 108.3809, 1632.485, 47.63385, 0.9773844, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+193, 23746, 568, 1, 1, 120.8572, 1605.621, 43.58566, 4.13643, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+194, 23746, 568, 1, 1, 133.7189, 1631.768, 47.75201, 4.08407, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+195, 53488, 568, 1, 1, 166.5851, 1693.63, 42.10494, 0, 7200, 0, 0), -- Summon Enabler Stalker (Area: 0)
(@CGUID+196, 53488, 568, 1, 1, 74.54166, 1694.575, 42.10487, 0, 7200, 0, 0), -- Summon Enabler Stalker (Area: 0)
(@CGUID+197, 14881, 568, 1, 1, 98.98239, 1666.083, 42.02155, 0.2323489, 7200, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+198, 53488, 568, 1, 1, 85.71702, 1665.207, 42.10487, 3.595378, 7200, 0, 0), -- Summon Enabler Stalker (Area: 0)
(@CGUID+199, 53488, 568, 1, 1, 121.4497, 1658.597, 42.1049, 3.612832, 7200, 0, 0), -- Summon Enabler Stalker (Area: 0)
(@CGUID+200, 52938, 568, 1, 1, 77.65972, 1660.606, 42.10489, 3.787364, 7200, 0, 0), -- Siame-Quashi (Area: 0) (possible waypoints or random movement)
(@CGUID+201, 52938, 568, 1, 1, 70.91319, 1653.733, 42.10488, 0.5061455, 7200, 0, 0), -- Siame-Quashi (Area: 0) (possible waypoints or random movement)
(@CGUID+202, 52938, 568, 1, 1, 77.93229, 1653.941, 42.10489, 2.548181, 7200, 0, 0), -- Siame-Quashi (Area: 0) (possible waypoints or random movement)
(@CGUID+203, 52938, 568, 1, 1, 71.40625, 1660.703, 42.10488, 5.462881, 7200, 0, 0), -- Siame-Quashi (Area: 0) (possible waypoints or random movement)
(@CGUID+204, 25173, 568, 1, 1, 134.0296, 1642.781, 42.27852, 4.537856, 7200, 0, 0), -- Zul'Aman Door Trigger (Area: 0)
(@CGUID+205, 23746, 568, 1, 1, 171.5354, 1561.777, 53.79171, 2.059489, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+206, 53488, 568, 1, 1, 121.1441, 1625.484, 43.28013, 0.9599311, 7200, 0, 0), -- Summon Enabler Stalker (Area: 0)
(@CGUID+207, 14881, 568, 1, 1, 167.1277, 1657.375, 42.02161, 1.649963, 7200, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+208, 23889, 568, 1, 1, 80.12598, 1516.039, 21.23372, 2.585904, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+209, 23889, 568, 1, 1, 122.7868, 1526.045, 21.23383, 5.348517, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+210, 23889, 568, 1, 1, 83.46954, 1523.155, 21.2337, 4.25388, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+211, 23889, 568, 1, 1, 167.6694, 1526.254, 21.31714, 1.850049, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+212, 23889, 568, 1, 1, 104.0745, 1523.379, 21.23373, 5.207433, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+213, 23889, 568, 1, 1, 160.0105, 1531.554, 21.2338, 4.41571, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+214, 23889, 568, 1, 1, 128.1491, 1524.885, 21.23382, 3.568551, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+215, 23597, 568, 1, 1, 101.3333, 1589.189, 43.73046, 5.131268, 7200, 0, 0), -- Amani'shi Guardian (Area: 0) (possible waypoints or random movement)
(@CGUID+216, 23597, 568, 1, 1, 138.8162, 1587.092, 43.64893, 4.747295, 7200, 0, 0), -- Amani'shi Guardian (Area: 0) (possible waypoints or random movement)
(@CGUID+217, 25173, 568, 1, 1, 121.1786, 1605.34, 55.65352, 3.577925, 7200, 0, 0), -- Zul'Aman Door Trigger (Area: 0)
(@CGUID+218, 23889, 568, 1, 1, 159.3942, 1514.544, 21.23377, 6.187668, 7200, 0, 0), -- Amani'shi Savage (Area: 0) (possible waypoints or random movement)
(@CGUID+219, 24175, 568, 1, 1, 206.9213, 1473.42, 26.00007, 3.961897, 7200, 0, 0), -- Amani'shi Lookout (Area: 0) (possible waypoints or random movement)
(@CGUID+220, 23746, 568, 1, 1, 106.7552, 1369.818, -22.054, 1.32645, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+221, 23746, 568, 1, 1, 129.7907, 1357.971, -24.07626, 6.091199, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+222, 23746, 568, 1, 1, 103.8917, 1357.135, -24.14213, 3.490659, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+223, 23576, 568, 1, 1, 16.96159, 1414.601, 11.92652, 6.230825, 7200, 0, 0), -- Nalorakk (Area: 0) (possible waypoints or random movement)
(@CGUID+224, 23746, 568, 1, 1, 117.7122, 1402.443, -8.414627, 0.8552113, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+225, 23746, 568, 1, 1, 124.361, 1373.145, -20.883, 0.5061455, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+226, 23746, 568, 1, 1, 290.5162, 1467.126, 81.58929, 5.410521, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+227, 23746, 568, 1, 1, 305.3816, 1467.21, 81.58927, 4.18879, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+228, 23746, 568, 1, 1, 294.0146, 1457.979, 81.58928, 3.263766, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+229, 52956, 568, 1, 1, 149.1351, 1421.933, 2.884622, 2.291274, 7200, 0, 0), -- Zandalari Juggernaut (Area: 0) (possible waypoints or random movement)
(@CGUID+230, 52962, 568, 1, 1, 150.3925, 1415.847, 3.324402, 1.849629, 7200, 0, 0), -- Zandalari Archon (Area: 0) (possible waypoints or random movement)
(@CGUID+231, 24325, 568, 1, 1, 192.9383, 1422.353, 15.72448, 5.916666, 7200, 0, 0), -- Eagle Troll Spawn Target (Area: 0)
(@CGUID+232, 24223, 568, 1, 1, 227.8884, 1452.763, 26.00041, 3.001966, 7200, 0, 0), -- Eagle Trash Aggro Trigger (Area: 0)
(@CGUID+233, 24223, 568, 1, 1, 231.7856, 1477.332, 26.00007, 0.541052, 7200, 0, 0), -- Eagle Trash Aggro Trigger (Area: 0)
(@CGUID+234, 24223, 568, 1, 1, 228.4806, 1433.126, 27.38743, 2.583087, 7200, 0, 0), -- Eagle Trash Aggro Trigger (Area: 0)
(@CGUID+235, 24179, 568, 1, 1, 223.8005, 1424.94, 29.46985, 1.169371, 7200, 0, 0), -- Amani'shi Wind Walker (Area: 0) (possible waypoints or random movement)
(@CGUID+236, 24180, 568, 1, 1, 232.7488, 1428.699, 28.82419, 1.832596, 7200, 0, 0), -- Amani'shi Protector (Area: 0) (possible waypoints or random movement)
(@CGUID+237, 1412, 568, 1, 1, 162.7539, 1396.369, 6.184458, 0.4886922, 7200, 0, 0), -- Squirrel (Area: 0)
(@CGUID+238, 24223, 568, 1, 1, 227.03, 1417.474, 32.81706, 2.75762, 7200, 0, 0), -- Eagle Trash Aggro Trigger (Area: 0)
(@CGUID+239, 52958, 568, 1, 1, 198.1875, 1386.479, 15.14776, 3.508112, 7200, 0, 0), -- Zandalari Hierophant (Area: 0)
(@CGUID+240, 52962, 568, 1, 1, 192.974, 1382.929, 15.14776, 0.4537856, 7200, 0, 0), -- Zandalari Archon (Area: 0)
(@CGUID+241, 24223, 568, 1, 1, 227.6509, 1404.276, 37.13389, 2.321288, 7200, 0, 0), -- Eagle Trash Aggro Trigger (Area: 0)
(@CGUID+242, 53021, 568, 1, 1, 121.7309, 1389.927, -14.07657, 4.537856, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+243, 24180, 568, 1, 1, 224.0694, 1394.261, 40.19848, 1.308997, 7200, 0, 0), -- Amani'shi Protector (Area: 0) (possible waypoints or random movement)
(@CGUID+244, 53021, 568, 1, 1, 119.3958, 1390.057, -14.00993, 4.590216, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+245, 53021, 568, 1, 1, 130.6094, 1385.394, -16.16843, 4.45059, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+246, 53021, 568, 1, 1, 112.3646, 1389.899, -14.07176, 4.712389, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+247, 53021, 568, 1, 1, 124.6094, 1383.271, -16.97602, 4.555309, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+248, 53021, 568, 1, 1, 119.783, 1384.304, -16.50148, 4.625123, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+249, 24179, 568, 1, 1, 231.7972, 1393.424, 40.58874, 1.692969, 7200, 0, 0), -- Amani'shi Wind Walker (Area: 0) (possible waypoints or random movement)
(@CGUID+250, 53021, 568, 1, 1, 113.8576, 1385.097, -16.1817, 4.712389, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+251, 53021, 568, 1, 1, 130.3073, 1378.448, -19.00636, 4.433136, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+252, 53021, 568, 1, 1, 117.1267, 1381.913, -17.49407, 4.642576, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+253, 53021, 568, 1, 1, 108.5347, 1384.698, -16.38485, 4.869469, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+254, 53021, 568, 1, 1, 122.7587, 1378.608, -18.8402, 4.485496, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+255, 53021, 568, 1, 1, 102.1563, 1386.526, -15.63947, 4.939282, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+256, 24223, 568, 1, 1, 227.5511, 1382.419, 44.78124, 0.1745329, 7200, 0, 0), -- Eagle Trash Aggro Trigger (Area: 0)
(@CGUID+257, 24396, 568, 1, 1, 137.7369, 1372.667, -21.87626, 3.804818, 7200, 0, 0), -- Forest Frog (Area: 0)
(@CGUID+258, 53021, 568, 1, 1, 127.6337, 1372.899, -21.03611, 4.485496, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+259, 53021, 568, 1, 1, 110.1927, 1378.385, -18.98549, 4.852015, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+260, 53021, 568, 1, 1, 117.934, 1374.566, -20.3765, 4.694936, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+261, 53021, 568, 1, 1, 121.5503, 1372.67, -21.00919, 4.607669, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+262, 53021, 568, 1, 1, 115.7188, 1374.116, -20.54578, 4.712389, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+263, 24396, 568, 1, 1, 143.5353, 1368.166, -23.63038, 1.204277, 7200, 0, 0), -- Forest Frog (Area: 0)
(@CGUID+264, 53021, 568, 1, 1, 110.1649, 1371.72, -21.42487, 4.799655, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+265, 53021, 568, 1, 1, 116.9375, 1367.563, -22.48419, 4.694936, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+266, 24396, 568, 1, 1, 97.40679, 1374.911, -20.46243, 3.281219, 7200, 0, 0), -- Forest Frog (Area: 0)
(@CGUID+267, 53021, 568, 1, 1, 120.7604, 1364.63, -23.0134, 4.468043, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+268, 53021, 568, 1, 1, 123.8646, 1362.691, -23.37251, 4.625123, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+269, 24396, 568, 1, 1, 130.4537, 1360.008, -23.91731, 5.270895, 7200, 0, 0), -- Forest Frog (Area: 0)
(@CGUID+270, 24396, 568, 1, 1, 141.7188, 1357.349, -24.76056, 5.078908, 7200, 0, 0), -- Forest Frog (Area: 0)
(@CGUID+271, 53021, 568, 1, 1, 112.7656, 1363.587, -23.27941, 4.764749, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+272, 53021, 568, 1, 1, 117.724, 1361.738, -23.48207, 4.712389, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+273, 53021, 568, 1, 1, 121.7986, 1357.802, -23.91373, 4.39823, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+274, 24549, 568, 1, 1, 301.1223, 1385.6, 57.75306, 3.263766, 7200, 0, 0), -- Amani'shi Tempest (Area: 0) (possible waypoints or random movement)
(@CGUID+275, 24363, 568, 1, 1, 116.2857, 1277.441, -15.26866, 4.590216, 7200, 0, 0), -- Hex Lord Malacrass (Area: 0)
(@CGUID+276, 24396, 568, 1, 1, 90.40267, 1365.505, -23.82376, 5.67232, 7200, 0, 0), -- Forest Frog (Area: 0)
(@CGUID+277, 24396, 568, 1, 1, 83.4719, 1352.883, -24.77254, 5.410521, 7200, 0, 0), -- Forest Frog (Area: 0)
(@CGUID+278, 53021, 568, 1, 1, 108.191, 1362.139, -23.59942, 4.974188, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+279, 24396, 568, 1, 1, 87.15357, 1377.103, -19.03518, 2.063282, 7200, 0, 0), -- Forest Frog (Area: 0)
(@CGUID+280, 53021, 568, 1, 1, 125.0729, 1355.613, -24.11232, 4.363323, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+281, 53021, 568, 1, 1, 111.2153, 1356.734, -24.06442, 4.764749, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+282, 52958, 568, 1, 1, 116.6944, 1337.705, -21.73458, 1.500983, 7200, 0, 0), -- Zandalari Hierophant (Area: 0)
(@CGUID+283, 53021, 568, 1, 1, 115.6233, 1358.217, -23.90183, 4.729842, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+284, 24180, 568, 1, 1, 244.807, 1367.658, 48.94979, 2.617994, 7200, 0, 0), -- Amani'shi Protector (Area: 0) (possible waypoints or random movement)
(@CGUID+285, 24179, 568, 1, 1, 246.9084, 1375.147, 49.40504, 2.897247, 7200, 0, 0), -- Amani'shi Wind Walker (Area: 0) (possible waypoints or random movement)
(@CGUID+286, 24223, 568, 1, 1, 245.9202, 1374.849, 49.40488, 3.403392, 7200, 0, 0), -- Eagle Trash Aggro Trigger (Area: 0)
(@CGUID+287, 24223, 568, 1, 1, 229.5756, 1361.475, 49.16213, 5.218534, 7200, 0, 0), -- Eagle Trash Aggro Trigger (Area: 0)
(@CGUID+288, 24223, 568, 1, 1, 246.9738, 1356.473, 49.40504, 1.204277, 7200, 0, 0), -- Eagle Trash Aggro Trigger (Area: 0)
(@CGUID+289, 23746, 568, 1, 1, 124.8804, 1225.514, -23.98874, 5.986479, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+290, 23746, 568, 1, 1, 115.0994, 1245.865, -20.10626, 2.583087, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+291, 23746, 568, 1, 1, 107.3443, 1226.045, -23.93908, 0.8377581, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+292, 24223, 568, 1, 1, 253.9278, 1429.991, 49.40504, 2.181662, 7200, 0, 0), -- Eagle Trash Aggro Trigger (Area: 0)
(@CGUID+293, 24223, 568, 1, 1, 261.4551, 1402.299, 49.40504, 2.024582, 7200, 0, 0), -- Eagle Trash Aggro Trigger (Area: 0)
(@CGUID+294, 24223, 568, 1, 1, 281.3025, 1430.996, 61.60976, 0.08726646, 7200, 0, 0), -- Eagle Trash Aggro Trigger (Area: 0)
(@CGUID+295, 23574, 568, 1, 1, 376.3534, 1407.341, 75.53125, 3.455752, 7200, 0, 0), -- Akil'zon (Area: 0) (possible waypoints or random movement)
(@CGUID+296, 52941, 568, 1, 1, 296.2255, 1468.354, 81.58929, 5.375614, 7200, 0, 0), -- Bakkalzu (Area: 0) (possible waypoints or random movement)
(@CGUID+297, 24180, 568, 1, 1, 274.3584, 1385.163, 49.40504, 3.752458, 7200, 0, 0), -- Amani'shi Protector (Area: 0) (possible waypoints or random movement)
(@CGUID+298, 24179, 568, 1, 1, 284.0443, 1372.319, 49.40504, 2.775074, 7200, 0, 0), -- Amani'shi Wind Walker (Area: 0) (possible waypoints or random movement)
(@CGUID+299, 23746, 568, 1, 1, 341.0219, 1310.98, 81.67094, 3.333579, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+300, 23814, 568, 1, 1, 347.3426, 1398.941, 74.42841, 4.066617, 7200, 0, 0), -- Zul'Aman - Eagle God Invisman (Area: 0)
(@CGUID+301, 24551, 568, 1, 1, 409.0086, 1417.029, 74.39153, 0.6457718, 7200, 0, 0), -- Eagle Event Deactivation Trigger (Area: 0)
(@CGUID+302, 24858, 568, 1, 1, 354.5434, 1411.222, 91.67165, 5.856516, 7200, 0, 0), -- Soaring Eagle (Area: 0)
(@CGUID+303, 24858, 568, 1, 1, 356.8288, 1422.785, 91.71573, 1.518436, 7200, 0, 0), -- Soaring Eagle (Area: 0)
(@CGUID+304, 24858, 568, 1, 1, 368.2694, 1377.702, 91.77523, 0.4312179, 7200, 0, 0), -- Soaring Eagle (Area: 0)
(@CGUID+305, 24858, 568, 1, 1, 361.3212, 1380.682, 91.76196, 3.036873, 7200, 0, 0), -- Soaring Eagle (Area: 0)
(@CGUID+306, 24858, 568, 1, 1, 396.4331, 1399.515, 91.59589, 4.308315, 7200, 0, 0), -- Soaring Eagle (Area: 0)
(@CGUID+307, 24858, 568, 1, 1, 395.2363, 1391.221, 91.78426, 3.787364, 7200, 0, 0), -- Soaring Eagle (Area: 0)
(@CGUID+308, 24858, 568, 1, 1, 387.0167, 1430.316, 92.32381, 3.171995, 7200, 0, 0), -- Soaring Eagle (Area: 0)
(@CGUID+309, 24858, 568, 1, 1, 379.344, 1434.552, 91.64027, 0.9599311, 7200, 0, 0), -- Soaring Eagle (Area: 0)
(@CGUID+310, 24858, 568, 1, 1, 356.8288, 1422.785, 91.71573, 1.518436, 7200, 0, 0), -- Soaring Eagle (Area: 0)
(@CGUID+311, 24858, 568, 1, 1, 351.3624, 1420.166, 81.42112, 5.794183, 7200, 0, 0), -- Soaring Eagle (Area: 0)
(@CGUID+312, 24858, 568, 1, 1, 396.5072, 1399.688, 91.61591, 4.307571, 7200, 0, 0), -- Soaring Eagle (Area: 0)
(@CGUID+313, 24858, 568, 1, 1, 379.344, 1434.552, 91.64027, 0.9599311, 7200, 0, 0), -- Soaring Eagle (Area: 0)
(@CGUID+314, 24858, 568, 1, 1, 413.1595, 1397.339, 90.87935, 2.384298, 7200, 0, 0), -- Soaring Eagle (Area: 0)
(@CGUID+315, 24858, 568, 1, 1, 368.805, 1377.947, 91.78362, 0.4257987, 7200, 0, 0), -- Soaring Eagle (Area: 0)
(@CGUID+316, 24858, 568, 1, 1, 361.3212, 1380.682, 91.76196, 3.036873, 7200, 0, 0), -- Soaring Eagle (Area: 0)
(@CGUID+317, 24858, 568, 1, 1, 396.1866, 1398.937, 91.52866, 4.309618, 7200, 0, 0), -- Soaring Eagle (Area: 0)
(@CGUID+318, 24858, 568, 1, 1, 395.2363, 1391.221, 91.78426, 3.787364, 7200, 0, 0), -- Soaring Eagle (Area: 0)
(@CGUID+319, 24858, 568, 1, 1, 386.3184, 1430.294, 92.52235, 3.174006, 7200, 0, 0), -- Soaring Eagle (Area: 0)
(@CGUID+320, 24858, 568, 1, 1, 396.3574, 1399.337, 91.57533, 4.308892, 7200, 0, 0), -- Soaring Eagle (Area: 0)
(@CGUID+321, 24858, 568, 1, 1, 386.7904, 1430.308, 92.38822, 3.172718, 7200, 0, 0), -- Soaring Eagle (Area: 0)
(@CGUID+322, 24858, 568, 1, 1, 379.344, 1434.552, 91.64027, 0.9599311, 7200, 0, 0), -- Soaring Eagle (Area: 0)
(@CGUID+323, 6491, 530, 1, 1, 6747.523, -7940.57, 170.1822, 2.844887, 120, 0, 0), -- Spirit Healer (Area: Amani Mountains)
(@CGUID+324, 52956, 568, 1, 1, 119.0139, 1303.347, -15.26871, 1.919862, 7200, 0, 0), -- Zandalari Juggernaut (Area: 0)
(@CGUID+325, 52962, 568, 1, 1, 99.89584, 1293.186, -15.26878, 5.235988, 7200, 0, 0), -- Zandalari Archon (Area: 0)
(@CGUID+326, 52956, 568, 1, 1, 111.9844, 1303.448, -15.26871, 0.9948376, 7200, 0, 0), -- Zandalari Juggernaut (Area: 0)
(@CGUID+327, 52958, 568, 1, 1, 101.7517, 1287.255, -15.26876, 1.745329, 7200, 0, 0), -- Zandalari Hierophant (Area: 0)
(@CGUID+328, 1412, 568, 1, 1, 47.52465, 1377.327, 4.515452, 5.152116, 7200, 0, 0), -- Squirrel (Area: 0)
(@CGUID+329, 1412, 568, 1, 1, 69.79102, 1373.17, -4.793645, 1.570796, 7200, 0, 0), -- Squirrel (Area: 0)
(@CGUID+330, 1412, 568, 1, 1, 52.53556, 1420.891, 0.9727492, 2.251963, 7200, 0, 0), -- Squirrel (Area: 0)
(@CGUID+331, 23542, 568, 1, 1, 19.09484, 1420.573, 11.97303, 5.8294, 7200, 0, 0), -- Amani'shi Axe Thrower (Area: 0) (possible waypoints or random movement)
(@CGUID+332, 23582, 568, 1, 1, 17.34549, 1418.596, 11.94753, 6.021386, 7200, 0, 0), -- Amani'shi Tribesman (Area: 0) (possible waypoints or random movement)
(@CGUID+333, 23542, 568, 1, 1, 14.54134, 1411.64, 11.98198, 0.01745329, 7200, 0, 0), -- Amani'shi Axe Thrower (Area: 0) (possible waypoints or random movement)
(@CGUID+334, 23584, 568, 1, 1, 24.99756, 1462.921, 2.040478, 6.21782, 7200, 0, 0), -- Amani Bear (Area: 0) (possible waypoints or random movement)
(@CGUID+335, 23746, 568, 1, 1, -22.20638, 1350.515, 48.25725, 3.961897, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+336, 23584, 568, 1, 1, 26.18797, 1472.281, 1.699823, 5.709407, 7200, 0, 0), -- Amani Bear (Area: 0) (possible waypoints or random movement)
(@CGUID+337, 23817, 568, 1, 1, -28.08507, 1214.224, 18.79466, 3.385939, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+338, 23817, 568, 1, 1, -27.00434, 1211.986, 18.79467, 3.944444, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+339, 23817, 568, 1, 1, -29.86513, 1211.384, 18.79466, 2.949606, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+340, 23817, 568, 1, 1, -36.43978, 1209.925, 18.79471, 0.3316126, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+341, 23817, 568, 1, 1, -39.36361, 1209.733, 18.79471, 0.5934119, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+342, 23817, 568, 1, 1, -39.72721, 1216.091, 18.79474, 5.585053, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+343, 23817, 568, 1, 1, -29.72439, 1208.432, 18.79467, 4.939282, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+344, 23817, 568, 1, 1, -38.95768, 1207.246, 18.79471, 4.066617, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+345, 23817, 568, 1, 1, -34.05859, 1207.233, 18.79469, 4.607669, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+346, 23817, 568, 1, 1, -28.07053, 1216.81, 18.79466, 1.396263, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+347, 23817, 568, 1, 1, -30.43045, 1216.394, 18.79466, 4.904375, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+348, 23817, 568, 1, 1, -32.07845, 1218.554, 18.79466, 5.654867, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+349, 23817, 568, 1, 1, -33.1212, 1209.771, 18.79468, 2.775074, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+350, 23817, 568, 1, 1, -34.41829, 1213.355, 18.79469, 2.268928, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+351, 23817, 568, 1, 1, -32.76194, 1215.327, 18.79466, 2.80998, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+352, 23817, 568, 1, 1, -36.28722, 1218.105, 18.7947, 0.03490658, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+353, 23817, 568, 1, 1, -38.57639, 1218.683, 18.79472, 4.974188, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+354, 23817, 568, 1, 1, -37.33681, 1212.526, 18.79472, 0.3141593, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+355, 23746, 568, 1, 1, -151.6817, 1339.344, 48.25722, 2.80998, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+356, 23746, 568, 1, 1, -149.1916, 1350.128, 48.25722, 0.05235988, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+357, 23584, 568, 1, 1, -8.414398, 1482.303, 9.448007, 5.664353, 7200, 0, 0), -- Amani Bear (Area: 0) (possible waypoints or random movement)
(@CGUID+358, 23581, 568, 1, 1, -50.70964, 1423.468, 27.48988, 6.178465, 7200, 0, 0), -- Amani'shi Medicine Man (Area: 0) (possible waypoints or random movement)
(@CGUID+359, 23584, 568, 1, 1, -19.96085, 1489.779, 15.13612, 0.3679289, 7200, 0, 0), -- Amani Bear (Area: 0) (possible waypoints or random movement)
(@CGUID+360, 23584, 568, 1, 1, -53.87508, 1478.836, 16.32967, 4.963339, 7200, 0, 0), -- Amani Bear (Area: 0) (possible waypoints or random movement)
(@CGUID+361, 23582, 568, 1, 1, -53.38997, 1422.759, 27.36697, 6.178465, 7200, 0, 0), -- Amani'shi Tribesman (Area: 0) (possible waypoints or random movement)
(@CGUID+362, 23542, 568, 1, 1, -50.77637, 1415.719, 27.45376, 0, 7200, 0, 0), -- Amani'shi Axe Thrower (Area: 0) (possible waypoints or random movement)
(@CGUID+363, 23542, 568, 1, 1, -53.32834, 1416.592, 27.36663, 0.01745329, 7200, 0, 0), -- Amani'shi Axe Thrower (Area: 0) (possible waypoints or random movement)
(@CGUID+364, 23584, 568, 1, 1, -64.73045, 1485.462, 18.17659, 2.066986, 7200, 0, 0), -- Amani Bear (Area: 0) (possible waypoints or random movement)
(@CGUID+365, 23807, 568, 1, 1, -80.10004, 1366.404, 40.84917, 4.642576, 7200, 0, 0), -- Zul'Aman - Bear God Invisman (Area: 0)
(@CGUID+366, 23580, 568, 1, 1, -76.19791, 1375.835, 40.84711, 1.413717, 7200, 0, 0), -- Amani'shi Warbringer (Area: 0) (possible waypoints or random movement)
(@CGUID+367, 23580, 568, 1, 1, -84.61111, 1375.879, 40.88389, 1.675516, 7200, 0, 0), -- Amani'shi Warbringer (Area: 0) (possible waypoints or random movement)
(@CGUID+368, 23580, 568, 1, 1, -77.10069, 1314.844, 41.30155, 4.660029, 7200, 0, 0), -- Amani'shi Warbringer (Area: 0) (possible waypoints or random movement)
(@CGUID+369, 23542, 568, 1, 1, -88.5434, 1314.734, 41.10989, 4.607669, 7200, 0, 0), -- Amani'shi Axe Thrower (Area: 0) (possible waypoints or random movement)
(@CGUID+370, 23580, 568, 1, 1, -83.03472, 1314.793, 41.23617, 4.747295, 7200, 0, 0), -- Amani'shi Warbringer (Area: 0) (possible waypoints or random movement)
(@CGUID+371, 23581, 568, 1, 1, -71.77084, 1314.774, 41.30156, 4.764749, 7200, 0, 0), -- Amani'shi Medicine Man (Area: 0) (possible waypoints or random movement)
(@CGUID+372, 52939, 568, 1, 1, -147.6961, 1333.272, 48.25721, 0.8203048, 7200, 0, 0), -- Hazlek (Area: 0) (possible waypoints or random movement)
(@CGUID+373, 23746, 568, 1, 1, -78.6888, 1164.774, 5.526937, 2.932153, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+374, 22515, 568, 1, 1, -179.9688, 1350.314, -0.02309655, 5.462881, 7200, 0, 0), -- World Trigger (Area: 0)
(@CGUID+375, 23596, 568, 1, 1, -190.8197, 1325.562, -0.03345666, 3.630285, 7200, 0, 0), -- Amani'shi Flame Caster (Area: 0) (possible waypoints or random movement)
(@CGUID+376, 1412, 568, 1, 1, -229.3526, 1425.052, 0.9414903, 0.4886922, 7200, 0, 0), -- Squirrel (Area: 0)
(@CGUID+377, 22515, 568, 1, 1, -195.5333, 1357.581, 0.4278964, 2.583087, 7200, 0, 0), -- World Trigger (Area: 0)
(@CGUID+378, 23586, 568, 1, 1, -219.3753, 1380.724, 0.03532434, 1.047198, 7200, 0, 0), -- Amani'shi Scout (Area: 0) (possible waypoints or random movement)
(@CGUID+379, 23597, 568, 1, 1, -193.4693, 1324.258, 0.1598215, 0.4537856, 7200, 0, 0), -- Amani'shi Guardian (Area: 0) (possible waypoints or random movement)
(@CGUID+380, 23586, 568, 1, 1, -186.4549, 1323.147, -0.03345666, 4.118977, 7200, 0, 0), -- Amani'shi Scout (Area: 0) (possible waypoints or random movement)
(@CGUID+381, 23597, 568, 1, 1, -225.5004, 1314.841, 1.910452, 5.637414, 7200, 0, 0), -- Amani'shi Guardian (Area: 0)
(@CGUID+382, 23597, 568, 1, 1, -221.8445, 1316.849, 1.175429, 3.892084, 7200, 0, 0), -- Amani'shi Guardian (Area: 0)
(@CGUID+383, 23596, 568, 1, 1, -222.093, 1312.359, 2.442197, 1.64061, 7200, 0, 0), -- Amani'shi Flame Caster (Area: 0)
(@CGUID+384, 52962, 568, 1, 1, -186.4201, 1316.76, -0.03345609, 2.076942, 7200, 0, 0), -- Zandalari Archon (Area: 0) (possible waypoints or random movement)
(@CGUID+385, 1412, 568, 1, 1, -201.9785, 1305.521, 0.8807219, 2.769791, 7200, 0, 0), -- Squirrel (Area: 0)
(@CGUID+386, 22515, 568, 1, 1, -185.4694, 1292.651, 1.963682, 2.059489, 7200, 0, 0), -- World Trigger (Area: 0)
(@CGUID+387, 23834, 568, 1, 1, -191.6632, 1250.87, 1.321181, 0.02175559, 7200, 0, 0), -- Amani Dragonhawk (Area: 0) (possible waypoints or random movement)
(@CGUID+388, 23834, 568, 1, 1, -201.6111, 1251.759, 1.251736, 2.804073, 7200, 0, 0), -- Amani Dragonhawk (Area: 0) (possible waypoints or random movement)
(@CGUID+389, 22515, 568, 1, 1, -177.9287, 1274.981, 1.561496, 0.4363323, 7200, 0, 0), -- World Trigger (Area: 0)
(@CGUID+390, 24312, 568, 1, 1, -224.4423, 1154.634, -0.6069207, 6.248279, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+391, 24312, 568, 1, 1, -224.8909, 1153.067, -0.6160877, 3.752458, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+392, 24312, 568, 1, 1, -209.1848, 1152.063, -0.1189517, 4.276057, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+393, 24312, 568, 1, 1, -223.9404, 1153.755, -0.4680277, 1.797689, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+394, 24312, 568, 1, 1, -209.2184, 1151.032, 0.03399334, 1.745329, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+395, 24312, 568, 1, 1, -208.3613, 1151.373, -0.2864816, 1.518436, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+396, 24312, 568, 1, 1, -225.1778, 1155.077, -0.6210707, 3.298672, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+397, 24312, 568, 1, 1, -208.3371, 1150.513, -0.04097466, 0.1047198, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+398, 24312, 568, 1, 1, -225.3862, 1153.915, -0.6926637, 3.752458, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+399, 24312, 568, 1, 1, -207.6011, 1150.806, -0.1514207, 1.815142, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+400, 24312, 568, 1, 1, -208.2971, 1152.333, -0.2086087, 2.251475, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+401, 24312, 568, 1, 1, -225.5621, 1154.839, -0.6369417, 3.979351, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+402, 23774, 568, 1, 1, -200.4844, 1242.847, 1.069049, 0.2094395, 7200, 0, 0), -- Amani'shi Trainer (Area: 0) (possible waypoints or random movement)
(@CGUID+403, 23834, 568, 1, 1, -184.4326, 1250.77, 2.437592, 1.460359, 7200, 0, 0), -- Amani Dragonhawk (Area: 0) (possible waypoints or random movement)
(@CGUID+404, 23834, 568, 1, 1, -191.8145, 1245.236, 0.6961226, 0.3383643, 7200, 0, 0), -- Amani Dragonhawk (Area: 0) (possible waypoints or random movement)
(@CGUID+405, 23586, 568, 1, 1, -184.1492, 1241.52, 1.482865, 6.268538, 7200, 0, 0), -- Amani'shi Scout (Area: 0) (possible waypoints or random movement)
(@CGUID+406, 24312, 568, 1, 1, -205.2695, 1134.63, 0.2038823, 0.3665192, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+407, 24312, 568, 1, 1, -206.3469, 1136.505, 0.1523283, 6.178465, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+408, 24312, 568, 1, 1, -206.665, 1135.724, 0.2118283, 3.351032, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+409, 24312, 568, 1, 1, -205.9197, 1135.657, -0.03911766, 5.497787, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+410, 24312, 568, 1, 1, -204.9283, 1136.49, 0.3888933, 6.003932, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+411, 24312, 568, 1, 1, -206.5408, 1134.726, 0.3449683, 0.4014257, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+412, 23586, 568, 1, 1, -198.8053, 1227.374, 1.090973, 1.32645, 7200, 0, 0), -- Amani'shi Scout (Area: 0) (possible waypoints or random movement)
(@CGUID+413, 24312, 568, 1, 1, -222.0245, 1126.659, -0.3158427, 3.281219, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+414, 24312, 568, 1, 1, -209.4416, 1117.165, 0.4169703, 0.7853982, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+415, 24312, 568, 1, 1, -208.8649, 1116.264, 0.3775593, 1.204277, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+416, 24312, 568, 1, 1, -221.969, 1125.637, -0.4019136, 6.073746, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+417, 24312, 568, 1, 1, -210.5338, 1115.474, 0.4689663, 1.186824, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+418, 24312, 568, 1, 1, -221.1223, 1126.028, -0.3680896, 0.715585, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+419, 24312, 568, 1, 1, -221.3659, 1124.914, -0.3190027, 3.769911, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+420, 24312, 568, 1, 1, -210.5506, 1116.895, 0.2905473, 2.059489, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+421, 24312, 568, 1, 1, -222.8466, 1125.743, -0.1326867, 1.902409, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+422, 24312, 568, 1, 1, -222.5744, 1124.88, -0.05733667, 1.32645, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+423, 24312, 568, 1, 1, -209.4372, 1115.291, 0.2649643, 1.37881, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+424, 24312, 568, 1, 1, -209.8233, 1116.503, 0.03415434, 4.921828, 7200, 0, 0), -- Dragonhawk Egg (Area: 0)
(@CGUID+425, 22515, 568, 1, 1, -166.0242, 1191.632, 0.9256693, 2.80998, 7200, 0, 0), -- World Trigger (Area: 0)
(@CGUID+426, 23774, 568, 1, 1, -205.2766, 1170.912, -0.5678995, 4.943881, 7200, 0, 0), -- Amani'shi Trainer (Area: 0) (possible waypoints or random movement)
(@CGUID+427, 23834, 568, 1, 1, -204.6293, 1172.851, -0.5678992, 5.90413, 7200, 0, 0), -- Amani Dragonhawk (Area: 0) (possible waypoints or random movement)
(@CGUID+428, 23834, 568, 1, 1, -207.589, 1172.104, -0.5678993, 4.736306, 7200, 0, 0), -- Amani Dragonhawk (Area: 0) (possible waypoints or random movement)
(@CGUID+429, 1412, 568, 1, 1, -194.8559, 1211.023, 0.7057803, 2.51216, 7200, 0, 0), -- Squirrel (Area: 0)
(@CGUID+430, 22515, 568, 1, 1, -173.4629, 1212.12, 0.1742263, 0.3839724, 7200, 0, 0), -- World Trigger (Area: 0)
(@CGUID+431, 23746, 568, 1, 1, -80.10667, 1125.272, 5.420393, 3.054326, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+432, 23746, 568, 1, 1, -74.42014, 1138.559, 5.282763, 0.7679449, 7200, 0, 0), -- Zul'Aman Exterior InvisMan (Area: 0)
(@CGUID+433, 23834, 568, 1, 1, -197.4964, 1159.448, -0.1378156, 5.78548, 7200, 0, 0), -- Amani Dragonhawk (Area: 0) (possible waypoints or random movement)
(@CGUID+434, 23834, 568, 1, 1, -218.2534, 1155.931, -1.911696, 3.232224, 7200, 0, 0), -- Amani Dragonhawk (Area: 0) (possible waypoints or random movement)
(@CGUID+435, 23834, 568, 1, 1, -211.3261, 1161.02, -1.4737, 2.475588, 7200, 0, 0), -- Amani Dragonhawk (Area: 0) (possible waypoints or random movement)
(@CGUID+436, 23774, 568, 1, 1, -207.9202, 1162.875, -0.9978887, 4.660029, 7200, 0, 0), -- Amani'shi Trainer (Area: 0)
(@CGUID+437, 23597, 568, 1, 1, -181.8656, 1158.574, 12.03916, 0.9773844, 7200, 0, 0), -- Amani'shi Guardian (Area: 0)
(@CGUID+438, 23597, 568, 1, 1, -181.74, 1164.196, 12.03915, 5.131268, 7200, 0, 0), -- Amani'shi Guardian (Area: 0)
(@CGUID+439, 23596, 568, 1, 1, -177.4641, 1159.707, 12.03915, 2.740167, 7200, 0, 0), -- Amani'shi Flame Caster (Area: 0)
(@CGUID+440, 23834, 568, 1, 1, -196.2479, 1152.249, -0.08489916, 0.4825343, 7200, 0, 0), -- Amani Dragonhawk (Area: 0) (possible waypoints or random movement)
(@CGUID+441, 23834, 568, 1, 1, -215.4075, 1147.116, -1.911696, 3.632347, 7200, 0, 0), -- Amani Dragonhawk (Area: 0) (possible waypoints or random movement)
(@CGUID+442, 23774, 568, 1, 1, -222.9597, 1147.851, -1.885152, 3.025423, 7200, 0, 0), -- Amani'shi Trainer (Area: 0) (possible waypoints or random movement)
(@CGUID+443, 23586, 568, 1, 1, -139.3332, 1165.003, 3.266365, 1.884956, 7200, 0, 0), -- Amani'shi Scout (Area: 0) (possible waypoints or random movement)
(@CGUID+444, 23834, 568, 1, 1, -205.7946, 1143.364, -1.560622, 0.4394569, 7200, 0, 0), -- Amani Dragonhawk (Area: 0) (possible waypoints or random movement)
(@CGUID+445, 23578, 568, 1, 1, -18.64215, 1150.456, 18.79474, 3.193953, 7200, 0, 0), -- Jan'alai (Area: 0) (possible waypoints or random movement)
(@CGUID+446, 22515, 568, 1, 1, -127.5242, 1167.951, 0.7607253, 2.565634, 7200, 0, 0), -- World Trigger (Area: 0)
(@CGUID+447, 23586, 568, 1, 1, -143.7847, 1145.705, 0.1684799, 6.021386, 7200, 0, 0), -- Amani'shi Scout (Area: 0) (possible waypoints or random movement)
(@CGUID+448, 52958, 568, 1, 1, -85.99827, 1196.401, 5.783861, 5.497787, 7200, 0, 0), -- Zandalari Hierophant (Area: 0)
(@CGUID+449, 23597, 568, 1, 1, -131.8663, 1147.823, 0.376895, 4.24115, 7200, 0, 0), -- Amani'shi Guardian (Area: 0) (possible waypoints or random movement)
(@CGUID+450, 23596, 568, 1, 1, -84.78125, 1192.72, 5.758795, 1.815142, 7200, 0, 0), -- Amani'shi Flame Caster (Area: 0)
(@CGUID+451, 23597, 568, 1, 1, -81.94618, 1196.438, 5.682, 2.844887, 7200, 0, 0), -- Amani'shi Guardian (Area: 0)
(@CGUID+452, 23834, 568, 1, 1, -131.7007, 1144.828, 0.5664063, 1.626033, 7200, 0, 0), -- Amani Dragonhawk (Area: 0) (possible waypoints or random movement)
(@CGUID+453, 23596, 568, 1, 1, -78.67285, 1199.083, 5.635486, 1.169371, 7200, 0, 0), -- Amani'shi Flame Caster (Area: 0)
(@CGUID+454, 23596, 568, 1, 1, -143.9688, 1134.191, 0.1160578, 1.22173, 7200, 0, 0), -- Amani'shi Flame Caster (Area: 0) (possible waypoints or random movement)
(@CGUID+455, 23596, 568, 1, 1, -128.2309, 1136.356, 0.4522538, 2.530727, 7200, 0, 0), -- Amani'shi Flame Caster (Area: 0) (possible waypoints or random movement)
(@CGUID+456, 22515, 568, 1, 1, -112.1164, 1159.569, 0.08333334, 3.560472, 7200, 0, 0), -- World Trigger (Area: 0)
(@CGUID+457, 52944, 568, 1, 1, -74.96983, 1158.323, 5.439155, 4.512255, 7200, 0, 0), -- Norkani (Area: 0)
(@CGUID+458, 22515, 568, 1, 1, -80.6288, 1150.352, 5.67736, 5.61996, 7200, 0, 0), -- World Trigger (Area: 0)
(@CGUID+459, 23817, 568, 1, 1, -40.00054, 1090.552, 18.79483, 1.117011, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+460, 23817, 568, 1, 1, -40.70692, 1088.505, 18.79484, 0.01745329, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+461, 23817, 568, 1, 1, -42.81348, 1085.943, 18.79484, 2.042035, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+462, 23817, 568, 1, 1, -38.28017, 1088.144, 18.7948, 1.27409, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+463, 23817, 568, 1, 1, -41.17698, 1084.593, 18.79484, 1.064651, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+464, 23817, 568, 1, 1, -36.24338, 1088.147, 18.7948, 1.727876, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+465, 23817, 568, 1, 1, -33.59256, 1090.162, 18.79482, 5.131268, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+466, 23817, 568, 1, 1, -38.88129, 1084.203, 18.79481, 0.5759587, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+467, 23817, 568, 1, 1, -33.66385, 1087.023, 18.79478, 0.9599311, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+468, 23817, 568, 1, 1, -39.79557, 1081.467, 18.79483, 2.740167, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+469, 23817, 568, 1, 1, -35.03472, 1084.924, 18.79476, 5.218534, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+470, 23817, 568, 1, 1, -29.17567, 1090.269, 18.79483, 0.6806784, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+471, 23817, 568, 1, 1, -31.03906, 1088.327, 18.7948, 2.70526, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+472, 23817, 568, 1, 1, -34.05675, 1082.022, 18.79473, 2.670354, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+473, 23817, 568, 1, 1, -30.51465, 1084.717, 18.79481, 1.797689, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+474, 23817, 568, 1, 1, -31.66471, 1081.882, 18.79478, 6.178465, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+475, 23817, 568, 1, 1, -26.57454, 1084.442, 18.79485, 2.792527, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+476, 23817, 568, 1, 1, -28.42014, 1082.094, 18.79485, 4.014257, 7200, 0, 0), -- Dragonhawk Egg (Area: 0) (possible waypoints or random movement)
(@CGUID+477, 23834, 568, 1, 1, -191.1465, 1127.604, 0.4991473, 6.199122, 7200, 0, 0), -- Amani Dragonhawk (Area: 0) (possible waypoints or random movement)
(@CGUID+478, 23834, 568, 1, 1, -204.9207, 1127.155, -1.021139, 4.652216, 7200, 0, 0), -- Amani Dragonhawk (Area: 0) (possible waypoints or random movement)
(@CGUID+479, 21252, 568, 1, 1, -53.62381, 1150.026, 18.78856, 0, 7200, 0, 0), -- World Trigger (Not Immune PC) (Area: 0)
(@CGUID+480, 52956, 568, 1, 1, -88.0191, 1123.571, 5.677376, 4.660029, 7200, 0, 0), -- Zandalari Juggernaut (Area: 0) (possible waypoints or random movement)
(@CGUID+481, 22515, 568, 1, 1, -114.4545, 1125.793, 0.08333334, 3.333579, 7200, 0, 0), -- World Trigger (Area: 0)
(@CGUID+482, 23596, 568, 1, 1, -88.02952, 1114.767, 5.677354, 1.553343, 7200, 0, 0), -- Amani'shi Flame Caster (Area: 0) (possible waypoints or random movement)
(@CGUID+483, 23597, 568, 1, 1, -91.49479, 1119.052, 5.677344, 6.248279, 7200, 0, 0), -- Amani'shi Guardian (Area: 0) (possible waypoints or random movement)
(@CGUID+484, 23596, 568, 1, 1, -83.81077, 1118.656, 5.67736, 3.071779, 7200, 0, 0), -- Amani'shi Flame Caster (Area: 0) (possible waypoints or random movement)
(@CGUID+485, 23774, 568, 1, 1, -190.5923, 1114.023, 0.102406, 0.2235023, 7200, 0, 0), -- Amani'shi Trainer (Area: 0) (possible waypoints or random movement)
(@CGUID+486, 23774, 568, 1, 1, -215.5026, 1125.64, -1.786683, 2.587866, 7200, 0, 0), -- Amani'shi Trainer (Area: 0) (possible waypoints or random movement)
(@CGUID+487, 23834, 568, 1, 1, -201.6128, 1111.197, 0.1490275, 6.074902, 7200, 0, 0), -- Amani Dragonhawk (Area: 0) (possible waypoints or random movement)
(@CGUID+488, 23813, 568, 1, 1, -51.09766, 1150.071, 18.78963, 3.281219, 7200, 0, 0), -- Zul'Aman - Dragonhawk God Invisman (Area: 0)
(@CGUID+489, 23834, 568, 1, 1, -216.0968, 1119.232, -1.782497, 1.521305, 7200, 0, 0), -- Amani Dragonhawk (Area: 0) (possible waypoints or random movement)
(@CGUID+490, 23586, 568, 1, 1, -180.2018, 1088.595, 2.176042, 2.459644, 7200, 0, 0), -- Amani'shi Scout (Area: 0) (possible waypoints or random movement)
(@CGUID+491, 23834, 568, 1, 1, -213.5355, 1106.019, -0.01076257, 5.278391, 7200, 0, 0), -- Amani Dragonhawk (Area: 0) (possible waypoints or random movement)
(@CGUID+492, 23597, 568, 1, 1, -82.19878, 1084.488, 0.9727573, 3.700098, 7200, 0, 0), -- Amani'shi Guardian (Area: 0)
(@CGUID+493, 23596, 568, 1, 1, -86.09853, 1083.582, 1.199107, 6.056293, 7200, 0, 0), -- Amani'shi Flame Caster (Area: 0)
(@CGUID+494, 23834, 568, 1, 1, -220.1237, 1112.356, -0.3165487, 3.922773, 7200, 0, 0), -- Amani Dragonhawk (Area: 0) (possible waypoints or random movement)
(@CGUID+495, 52962, 568, 1, 1, -83.87749, 1081.236, 1.016078, 1.658063, 7200, 0, 0), -- Zandalari Archon (Area: 0)
(@CGUID+496, 21252, 568, 1, 1, -33.89692, 1122.812, 18.79475, 1.58825, 7200, 0, 0), -- World Trigger (Not Immune PC) (Area: 0)
(@CGUID+497, 21252, 568, 1, 1, -34.71929, 1149.694, 19.2254, 6.038839, 7200, 0, 0), -- World Trigger (Not Immune PC) (Area: 0)
(@CGUID+498, 1412, 568, 1, 1, 41.97039, 1365.528, 8.766522, 1.623533, 7200, 0, 0), -- Squirrel (Area: 0)
(@CGUID+499, 21252, 568, 1, 1, -10.28961, 1149.977, 18.79469, 3.141593, 7200, 0, 0), -- World Trigger (Not Immune PC) (Area: 0)
(@CGUID+500, 21252, 568, 1, 1, -33.43728, 1177.729, 18.79469, 4.660029, 7200, 0, 0), -- World Trigger (Not Immune PC) (Area: 0)
(@CGUID+501, 52956, 568, 1, 1, 81.14171, 1147.258, 0.1385887, 3.057819, 7200, 0, 0), -- Zandalari Juggernaut (Area: 0) (possible waypoints or random movement)
(@CGUID+502, 53021, 568, 1, 1, 101.6146, 1199.967, -15.3494, 1.22173, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+503, 53021, 568, 1, 1, 105.3715, 1192.526, -15.35548, 1.361357, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+504, 53021, 568, 1, 1, 98.04514, 1192.222, -13.96633, 1.291544, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+505, 53021, 568, 1, 1, 110.8767, 1197.182, -15.67311, 1.37881, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+506, 53021, 568, 1, 1, 121.2743, 1188.498, -14.48825, 5.532694, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+507, 53021, 568, 1, 1, 124.6146, 1184.627, -13.29845, 1.570796, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+508, 24064, 568, 1, 1, 148.1857, 1125.203, 2.134738, 3.193953, 7200, 0, 0), -- Amani Lynx Cub (Area: 0) (possible waypoints or random movement)
(@CGUID+509, 24530, 568, 1, 1, 148.9321, 1113.783, 1.307261, 0.122173, 7200, 0, 0), -- Amani Elder Lynx (Area: 0) (possible waypoints or random movement)
(@CGUID+510, 52958, 568, 1, 1, 139.7197, 1139.511, -0.3296066, 2.480121, 7200, 0, 0), -- Zandalari Hierophant (Area: 0) (possible waypoints or random movement)
(@CGUID+511, 53021, 568, 1, 1, 97.23264, 1205.276, -15.62686, 1.099557, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+512, 53021, 568, 1, 1, 121.7205, 1198.531, -16.18747, 1.727876, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+513, 53021, 568, 1, 1, 113.8073, 1197.229, -15.81901, 1.745329, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+514, 53021, 568, 1, 1, 127.5573, 1189.552, -13.96838, 4.13643, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+515, 24064, 568, 1, 1, 186.4376, 1163.986, 0.1567021, 1.939879, 7200, 0, 0), -- Amani Lynx Cub (Area: 0) (possible waypoints or random movement)
(@CGUID+516, 24064, 568, 1, 1, 177.4398, 1167.915, 0.8686959, 1.294571, 7200, 0, 0), -- Amani Lynx Cub (Area: 0) (possible waypoints or random movement)
(@CGUID+517, 24064, 568, 1, 1, 178.7173, 1180.375, 0.4899006, 1.518077, 7200, 0, 0), -- Amani Lynx Cub (Area: 0) (possible waypoints or random movement)
(@CGUID+518, 24064, 568, 1, 1, 169.4625, 1130.477, 1.097785, 5.51524, 7200, 0, 0), -- Amani Lynx Cub (Area: 0) (possible waypoints or random movement)
(@CGUID+519, 24064, 568, 1, 1, 172.895, 1120.761, 0.4784693, 6.230825, 7200, 0, 0), -- Amani Lynx Cub (Area: 0) (possible waypoints or random movement)
(@CGUID+520, 24064, 568, 1, 1, 162.5309, 1135.593, 0.5825203, 1.134464, 7200, 0, 0), -- Amani Lynx Cub (Area: 0) (possible waypoints or random movement)
(@CGUID+521, 24064, 568, 1, 1, 155.3346, 1130.246, 1.174717, 0.9075712, 7200, 0, 0), -- Amani Lynx Cub (Area: 0) (possible waypoints or random movement)
(@CGUID+522, 24530, 568, 1, 1, 187.0768, 1172.536, 0.8493893, 4.380776, 7200, 0, 0), -- Amani Elder Lynx (Area: 0)
(@CGUID+523, 53021, 568, 1, 1, 134.3108, 1188.688, -11.05451, 2.129302, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+524, 53021, 568, 1, 1, 118.0938, 1200.889, -16.85375, 1.64061, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+525, 24396, 568, 1, 1, 114.42, 1206.34, -20.98254, 0.3213686, 7200, 0, 0), -- Forest Frog (Area: 0)
(@CGUID+526, 53021, 568, 1, 1, 103.4167, 1204.747, -17.33355, 1.239184, 7200, 0, 0), -- Amani'shi Peon (Area: 0)
(@CGUID+527, 53021, 568, 1, 1, 123.4149, 1205.767, -17.8389, 1.727876, 7200, 0, 0); -- Amani'shi Peon (Area: 0)
