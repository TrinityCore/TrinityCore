-- Path for Coastal Albatross
SET @MOVERGUID := 1051127;
SET @ENTRY := 161133;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x02, NULL, 'Coastal Albatross - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -266.69943, -2456.9673, 30.767942, NULL, 0),
(@PATH, 1, -269.63284, -2449.898, 30.767942, NULL, 0),
(@PATH, 2, -266.70837, -2442.8252, 30.767942, NULL, 0),
(@PATH, 3, -259.63916, -2439.8916, 30.767942, NULL, 0),
(@PATH, 4, -252.56625, -2442.8162, 30.767942, NULL, 0),
(@PATH, 5, -249.63284, -2449.8853, 30.767942, NULL, 0),
(@PATH, 6, -252.5573, -2456.9583, 30.767942, NULL, 0),
(@PATH, 7, -259.6265, -2459.8916, 30.767942, NULL, 0);

UPDATE `creature` SET `position_x`=-266.69943, `position_y`=-2456.9673, `position_z`=30.767942, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Coastal Albatross
SET @MOVERGUID := 1051134;
SET @ENTRY := 161133;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x02, NULL, 'Coastal Albatross - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -184.51358, -2488.4644, 34.979782, NULL, 0),
(@PATH, 1, -184.92104, -2496.1072, 34.979782, NULL, 0),
(@PATH, 2, -190.61345, -2501.2234, 34.979782, NULL, 0),
(@PATH, 3, -198.25626, -2500.816, 34.979782, NULL, 0),
(@PATH, 4, -203.37242, -2495.1235, 34.979782, NULL, 0),
(@PATH, 5, -202.96497, -2487.4807, 34.979782, NULL, 0),
(@PATH, 6, -197.27257, -2482.3645, 34.979782, NULL, 0),
(@PATH, 7, -189.62975, -2482.772, 34.979782, NULL, 0);

UPDATE `creature` SET `position_x`=-184.51358, `position_y`=-2488.4644, `position_z`=34.979782, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Coastal Albatross
SET @MOVERGUID := 1051145;
SET @ENTRY := 161133;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x02, NULL, 'Coastal Albatross - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -197.94951, -2438.024, 24.703934, NULL, 0),
(@PATH, 1, -203.62326, -2432.887, 24.703934, NULL, 0),
(@PATH, 2, -204.0029, -2425.2427, 24.703934, NULL, 0),
(@PATH, 3, -198.86604, -2419.569, 24.703934, NULL, 0),
(@PATH, 4, -191.2218, -2419.1895, 24.703934, NULL, 0),
(@PATH, 5, -185.54805, -2424.3262, 24.703934, NULL, 0),
(@PATH, 6, -185.16841, -2431.9705, 24.703934, NULL, 0),
(@PATH, 7, -190.30527, -2437.6443, 24.703934, NULL, 0);

UPDATE `creature` SET `position_x`=-197.94951, `position_y`=-2438.024, `position_z`=24.703934, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Coastal Albatross
SET @MOVERGUID := 1051128;
SET @ENTRY := 161133;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x02, NULL, 'Coastal Albatross - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -215.52295, -2465.0913, 38.79076, NULL, 0),
(@PATH, 1, -219.65314, -2471.535, 38.79076, NULL, 0),
(@PATH, 2, -227.12993, -2473.171, 38.79076, NULL, 0),
(@PATH, 3, -233.57356, -2469.0408, 38.79076, NULL, 0),
(@PATH, 4, -235.20941, -2461.564, 38.79076, NULL, 0),
(@PATH, 5, -231.07924, -2455.12, 38.79076, NULL, 0),
(@PATH, 6, -223.60243, -2453.4844, 39.98038, NULL, 0),
(@PATH, 7, -217.15881, -2457.6145, 38.79076, NULL, 0);

UPDATE `creature` SET `position_x`=-215.52295, `position_y`=-2465.0913, `position_z`=38.79076, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Coastal Albatross
SET @MOVERGUID := 1051151;
SET @ENTRY := 161133;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x02, NULL, 'Coastal Albatross - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -141.67023, -2455.4355, 34.259457, NULL, 0),
(@PATH, 1, -135.54694, -2450.8438, 34.259457, NULL, 0),
(@PATH, 2, -127.970276, -2451.9268, 34.259457, NULL, 0),
(@PATH, 3, -123.37854, -2458.05, 34.259457, NULL, 0),
(@PATH, 4, -124.46151, -2465.6267, 34.259457, NULL, 0),
(@PATH, 5, -130.5848, -2470.2185, 34.259457, NULL, 0),
(@PATH, 6, -138.16145, -2469.1355, 34.259457, NULL, 0),
(@PATH, 7, -142.75319, -2463.0122, 34.259457, NULL, 0);

UPDATE `creature` SET `position_x`=-141.67023, `position_y`=-2455.4355, `position_z`=34.259457, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Coastal Albatross
SET @MOVERGUID := 1051153;
SET @ENTRY := 161133;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x02, NULL, 'Coastal Albatross - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -125.053505, -2412.7556, 15.660763, NULL, 0),
(@PATH, 1, -117.60623, -2414.521, 15.660763, NULL, 0),
(@PATH, 2, -113.58858, -2421.0354, 15.660763, NULL, 0),
(@PATH, 3, -115.35403, -2428.4827, 15.660763, NULL, 0),
(@PATH, 4, -121.8684, -2432.5002, 15.660763, NULL, 0),
(@PATH, 5, -129.31567, -2430.7349, 15.660763, NULL, 0),
(@PATH, 6, -133.33333, -2424.2205, 15.660763, NULL, 0),
(@PATH, 7, -131.56789, -2416.7732, 15.660763, NULL, 0);

UPDATE `creature` SET `position_x`=-125.053505, `position_y`=-2412.7556, `position_z`=15.660763, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Sharpbeak Hawk
SET @MOVERGUID := 1051163;
SET @ENTRY := 164827;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x02, NULL, 'Sharpbeak Hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -182.28308, -2593.7358, 50.873833, NULL, 0),
(@PATH, 1, -176.15979, -2589.144, 50.873833, NULL, 0),
(@PATH, 2, -168.58313, -2590.227, 50.873833, NULL, 0),
(@PATH, 3, -163.9914, -2596.3503, 50.873833, NULL, 0),
(@PATH, 4, -165.07437, -2603.927, 50.873833, NULL, 0),
(@PATH, 5, -171.19765, -2608.5188, 50.873833, NULL, 0),
(@PATH, 6, -178.7743, -2607.4358, 50.873833, NULL, 0),
(@PATH, 7, -183.36604, -2601.3125, 50.873833, NULL, 0);

UPDATE `creature` SET `position_x`=-182.28308, `position_y`=-2593.7358, `position_z`=50.873833, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Sharpbeak Hawk
SET @MOVERGUID := 1051161;
SET @ENTRY := 164827;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x02, NULL, 'Sharpbeak Hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -143.37067, -2626.1196, 60.741047, NULL, 0),
(@PATH, 1, -149.7132, -2621.8357, 60.741047, NULL, 0),
(@PATH, 2, -151.16895, -2614.3218, 60.741047, NULL, 0),
(@PATH, 3, -146.88515, -2607.9792, 60.741047, NULL, 0),
(@PATH, 4, -139.3712, -2606.5234, 60.741047, NULL, 0),
(@PATH, 5, -133.02867, -2610.8074, 60.741047, NULL, 0),
(@PATH, 6, -131.57292, -2618.3213, 60.741047, NULL, 0),
(@PATH, 7, -135.85672, -2624.6638, 60.741047, NULL, 0);

UPDATE `creature` SET `position_x`=-143.37067, `position_y`=-2626.1196, `position_z`=60.741047, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Sharpbeak Hawk
SET @MOVERGUID := 1051162;
SET @ENTRY := 164827;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x02, NULL, 'Sharpbeak Hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -145.33858, -2670.5547, 68.75432, NULL, 0),
(@PATH, 1, -148.41629, -2677.5623, 68.75432, NULL, 0),
(@PATH, 2, -155.54768, -2680.341, 68.75432, NULL, 0),
(@PATH, 3, -162.55527, -2677.2632, 68.75432, NULL, 0),
(@PATH, 4, -165.3341, -2670.1318, 68.75432, NULL, 0),
(@PATH, 5, -162.2564, -2663.1243, 68.75432, NULL, 0),
(@PATH, 6, -155.125, -2660.3455, 68.75432, NULL, 0),
(@PATH, 7, -148.11742, -2663.423, 68.75432, NULL, 0);

UPDATE `creature` SET `position_x`=-145.33858, `position_y`=-2670.5547, `position_z`=68.75432, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Sharpbeak Hawk
SET @MOVERGUID := 1051221;
SET @ENTRY := 164827;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x02, NULL, 'Sharpbeak Hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -103.705635, -2670.7598, 75.72378, NULL, 0),
(@PATH, 1, -96.05725, -2670.4753, 75.72378, NULL, 0),
(@PATH, 2, -90.44797, -2675.6826, 75.72378, NULL, 0),
(@PATH, 3, -90.163635, -2683.3308, 75.72378, NULL, 0),
(@PATH, 4, -95.370804, -2688.9402, 75.72378, NULL, 0),
(@PATH, 5, -103.019196, -2689.2246, 75.72378, NULL, 0),
(@PATH, 6, -108.62847, -2684.0173, 75.72378, NULL, 0),
(@PATH, 7, -108.9128, -2676.369, 75.72378, NULL, 0);

UPDATE `creature` SET `position_x`=-103.705635, `position_y`=-2670.7598, `position_z`=75.72378, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Sharpbeak Hawk
SET @MOVERGUID := 1051482;
SET @ENTRY := 164827;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x02, NULL, 'Sharpbeak Hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 247.80037, -2103.118, 123.64119, NULL, 0),
(@PATH, 1, 246.54276, -2091.7065, 123.64119, NULL, 0),
(@PATH, 2, 253.72258, -2082.748, 123.64119, NULL, 0),
(@PATH, 3, 265.134, -2081.4905, 123.64119, NULL, 0),
(@PATH, 4, 274.09235, -2088.6702, 123.64119, NULL, 0),
(@PATH, 5, 275.34995, -2100.0818, 123.64119, NULL, 0),
(@PATH, 6, 268.17014, -2109.04, 123.64119, NULL, 0),
(@PATH, 7, 256.75873, -2110.2976, 123.64119, NULL, 0);

UPDATE `creature` SET `position_x`=247.80037, `position_y`=-2103.118, `position_z`=123.64119, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Sharpbeak Hawk
SET @MOVERGUID := 1051495;
SET @ENTRY := 164827;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x02, NULL, 'Sharpbeak Hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 303.52255, -2086.049, 125.59218, NULL, 0),
(@PATH, 1, 292.42038, -2083.126, 125.59218, NULL, 0),
(@PATH, 2, 286.63684, -2073.2087, 125.59218, NULL, 0),
(@PATH, 3, 289.55988, -2062.1064, 125.59218, NULL, 0),
(@PATH, 4, 299.47717, -2056.323, 125.59218, NULL, 0),
(@PATH, 5, 310.5793, -2059.246, 125.59218, NULL, 0),
(@PATH, 6, 316.36285, -2069.1633, 125.59218, NULL, 0),
(@PATH, 7, 313.43982, -2080.2654, 125.59218, NULL, 0);

UPDATE `creature` SET `position_x`=303.52255, `position_y`=-2086.049, `position_z`=125.59218, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Sharpbeak Hawk
SET @MOVERGUID := 1051476;
SET @ENTRY := 164827;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x02, NULL, 'Sharpbeak Hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 333.76797, -2131.895, 126.231636, NULL, 0),
(@PATH, 1, 336.6066, -2143.019, 126.231636, NULL, 0),
(@PATH, 2, 330.74792, -2152.892, 126.231636, NULL, 0),
(@PATH, 3, 319.6239, -2155.7307, 126.231636, NULL, 0),
(@PATH, 4, 309.75082, -2149.872, 126.231636, NULL, 0),
(@PATH, 5, 306.91217, -2138.748, 126.231636, NULL, 0),
(@PATH, 6, 312.77084, -2128.875, 126.231636, NULL, 0),
(@PATH, 7, 323.89487, -2126.0364, 126.231636, NULL, 0);

UPDATE `creature` SET `position_x`=333.76797, `position_y`=-2131.895, `position_z`=126.231636, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Sharpbeak Hawk
SET @MOVERGUID := 1051458;
SET @ENTRY := 164827;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x02, NULL, 'Sharpbeak Hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 317.39938, -2271.3486, 116.081924, NULL, 0),
(@PATH, 1, 322.50333, -2261.0652, 116.081924, NULL, 0),
(@PATH, 2, 333.38394, -2257.4026, 116.081924, NULL, 0),
(@PATH, 3, 343.6675, -2262.5066, 116.081924, NULL, 0),
(@PATH, 4, 347.33005, -2273.3872, 116.081924, NULL, 0),
(@PATH, 5, 342.2261, -2283.6707, 116.081924, NULL, 0),
(@PATH, 6, 331.3455, -2287.3333, 116.081924, NULL, 0),
(@PATH, 7, 321.06192, -2282.2292, 116.081924, NULL, 0);

UPDATE `creature` SET `position_x`=317.39938, `position_y`=-2271.3486, `position_z`=116.081924, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Sharpbeak Hawk
SET @MOVERGUID := 1051442;
SET @ENTRY := 164827;
SET @PATHOFFSET := 8;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x02, NULL, 'Sharpbeak Hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 328.30615, -2329.7527, 103.62933, NULL, 0),
(@PATH, 1, 331.14478, -2340.8767, 103.62933, NULL, 0),
(@PATH, 2, 325.28613, -2350.7498, 103.62933, NULL, 0),
(@PATH, 3, 314.16208, -2353.5884, 103.62933, NULL, 0),
(@PATH, 4, 304.289, -2347.7297, 103.62933, NULL, 0),
(@PATH, 5, 301.45035, -2336.6057, 103.62933, NULL, 0),
(@PATH, 6, 307.30902, -2326.7327, 103.62933, NULL, 0),
(@PATH, 7, 318.43304, -2323.894, 103.62933, NULL, 0);

UPDATE `creature` SET `position_x`=328.30615, `position_y`=-2329.7527, `position_z`=103.62933, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Sharpbeak Hawk
SET @MOVERGUID := 1051481;
SET @ENTRY := 164827;
SET @PATHOFFSET := 9;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x02, NULL, 'Sharpbeak Hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 328.72983, -2073.2927, 131.38937, NULL, 0),
(@PATH, 1, 326.05466, -2084.4573, 131.38937, NULL, 0),
(@PATH, 2, 316.26855, -2090.4602, 131.38937, NULL, 0),
(@PATH, 3, 305.1041, -2087.785, 131.38937, NULL, 0),
(@PATH, 4, 299.10123, -2077.9988, 131.38937, NULL, 0),
(@PATH, 5, 301.7764, -2066.8345, 131.38937, NULL, 0),
(@PATH, 6, 311.5625, -2060.8315, 131.38937, NULL, 0),
(@PATH, 7, 322.72696, -2063.5066, 131.38937, NULL, 0);

UPDATE `creature` SET `position_x`=328.72983, `position_y`=-2073.2927, `position_z`=131.38937, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Hungry Vulture
SET @MOVERGUID := 1051465;
SET @ENTRY := 154268;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x02, NULL, 'Hungry Vulture - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 238.50812, -2333.4978, 110.37333, NULL, 0),
(@PATH, 1, 232.9311, -2338.7395, 110.37333, NULL, 0),
(@PATH, 2, 225.28111, -2338.5024, 110.37333, NULL, 0),
(@PATH, 3, 220.0394, -2332.9253, 110.37333, NULL, 0),
(@PATH, 4, 220.27647, -2325.2754, 110.37333, NULL, 0),
(@PATH, 5, 225.85349, -2320.0337, 110.37333, NULL, 0),
(@PATH, 6, 233.50348, -2320.2708, 110.37333, NULL, 0),
(@PATH, 7, 238.7452, -2325.8477, 110.37333, NULL, 0);

UPDATE `creature` SET `position_x`=238.50812, `position_y`=-2333.4978, `position_z`=110.37333, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Hungry Vulture
SET @MOVERGUID := 1051470;
SET @ENTRY := 154268;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x02, NULL, 'Hungry Vulture - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 198.40569, -2287.1506, 126.89249, NULL, 0),
(@PATH, 1, 192.82867, -2292.3923, 126.89249, NULL, 0),
(@PATH, 2, 185.17868, -2292.1553, 126.89249, NULL, 0),
(@PATH, 3, 179.93695, -2286.5781, 126.89249, NULL, 0),
(@PATH, 4, 180.17404, -2278.9282, 126.89249, NULL, 0),
(@PATH, 5, 185.75105, -2273.6865, 126.89249, NULL, 0),
(@PATH, 6, 193.40105, -2273.9236, 126.89249, NULL, 0),
(@PATH, 7, 198.64276, -2279.5005, 126.89249, NULL, 0);

UPDATE `creature` SET `position_x`=198.40569, `position_y`=-2287.1506, `position_z`=126.89249, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Hungry Vulture
SET @MOVERGUID := 1051207;
SET @ENTRY := 154268;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x02, NULL, 'Hungry Vulture - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 134.69476, -2248.1013, 114.29144, NULL, 0),
(@PATH, 1, 142.05219, -2250.2102, 114.29144, NULL, 0),
(@PATH, 2, 145.76353, -2256.9038, 114.29144, NULL, 0),
(@PATH, 3, 143.65475, -2264.2612, 114.29144, NULL, 0),
(@PATH, 4, 136.96112, -2267.9727, 114.29144, NULL, 0),
(@PATH, 5, 129.6037, -2265.8638, 114.29144, NULL, 0),
(@PATH, 6, 125.89236, -2259.1702, 114.29144, NULL, 0),
(@PATH, 7, 128.00114, -2251.8127, 114.29144, NULL, 0);

UPDATE `creature` SET `position_x`=134.69476, `position_y`=-2248.1013, `position_z`=114.29144, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Hungry Vulture
SET @MOVERGUID := 1051205;
SET @ENTRY := 154268;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x02, NULL, 'Hungry Vulture - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 74.37294, -2243.2366, 123.023994, NULL, 0),
(@PATH, 1, 68.13437, -2247.6704, 123.023994, NULL, 0),
(@PATH, 2, 60.587837, -2246.3943, 123.023994, NULL, 0),
(@PATH, 3, 56.154015, -2240.1555, 123.023994, NULL, 0),
(@PATH, 4, 57.43017, -2232.6091, 123.023994, NULL, 0),
(@PATH, 5, 63.668747, -2228.1753, 123.023994, NULL, 0),
(@PATH, 6, 71.21527, -2229.4514, 123.023994, NULL, 0),
(@PATH, 7, 75.64909, -2235.69, 123.023994, NULL, 0);

UPDATE `creature` SET `position_x`=74.37294, `position_y`=-2243.2366, `position_z`=123.023994, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Hungry Vulture
SET @MOVERGUID := 1051448;
SET @ENTRY := 154268;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x02, NULL, 'Hungry Vulture - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 215.90024, -2288.5962, 108.52238, NULL, 0),
(@PATH, 1, 213.56062, -2281.3088, 108.52238, NULL, 0),
(@PATH, 2, 217.05919, -2274.5017, 108.52238, NULL, 0),
(@PATH, 3, 224.3465, -2272.162, 108.52238, NULL, 0),
(@PATH, 4, 231.15375, -2275.6606, 108.52238, NULL, 0),
(@PATH, 5, 233.49335, -2282.9478, 108.52238, NULL, 0),
(@PATH, 6, 229.9948, -2289.7551, 108.52238, NULL, 0),
(@PATH, 7, 222.70749, -2292.0947, 108.52238, NULL, 0);

UPDATE `creature` SET `position_x`=215.90024, `position_y`=-2288.5962, `position_z`=108.52238, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Hungry Vulture
SET @MOVERGUID := 1051193;
SET @ENTRY := 154268;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x02, NULL, 'Hungry Vulture - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 80.01768, -2218.3826, 115.87697, NULL, 0),
(@PATH, 1, 87.37511, -2220.4915, 115.87697, NULL, 0),
(@PATH, 2, 91.08646, -2227.185, 115.87697, NULL, 0),
(@PATH, 3, 88.97767, -2234.5425, 115.87697, NULL, 0),
(@PATH, 4, 82.28405, -2238.254, 115.87697, NULL, 0),
(@PATH, 5, 74.92663, -2236.145, 115.87697, NULL, 0),
(@PATH, 6, 71.21528, -2229.4514, 115.87697, NULL, 0),
(@PATH, 7, 73.32406, -2222.094, 115.87697, NULL, 0);

UPDATE `creature` SET `position_x`=80.01768, `position_y`=-2218.3826, `position_z`=115.87697, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Hungry Vulture
SET @MOVERGUID := 1051367;
SET @ENTRY := 154268;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x02, NULL, 'Hungry Vulture - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 179.39145, -2070.7358, 111.89391, NULL, 0),
(@PATH, 1, 186.65712, -2068.3298, 111.89391, NULL, 0),
(@PATH, 2, 193.496, -2071.766, 111.89391, NULL, 0),
(@PATH, 3, 195.90198, -2079.0317, 111.89391, NULL, 0),
(@PATH, 4, 192.46567, -2085.8706, 111.89391, NULL, 0),
(@PATH, 5, 185.2, -2088.2766, 111.89391, NULL, 0),
(@PATH, 6, 178.36111, -2084.8403, 111.89391, NULL, 0),
(@PATH, 7, 175.95514, -2077.5747, 111.89391, NULL, 0);

UPDATE `creature` SET `position_x`=179.39145, `position_y`=-2070.7358, `position_z`=111.89391, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Hungry Vulture
SET @MOVERGUID := 1051364;
SET @ENTRY := 154268;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x02, NULL, 'Hungry Vulture - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 192.62746, -2076.4026, 104.377655, NULL, 0),
(@PATH, 1, 189.47807, -2083.3784, 104.377655, NULL, 0),
(@PATH, 2, 182.31857, -2086.084, 104.377655, NULL, 0),
(@PATH, 3, 175.3429, -2082.9346, 104.377655, NULL, 0),
(@PATH, 4, 172.6373, -2075.775, 104.377655, NULL, 0),
(@PATH, 5, 175.78668, -2068.7993, 104.377655, NULL, 0),
(@PATH, 6, 182.94618, -2066.0938, 104.377655, NULL, 0),
(@PATH, 7, 189.92186, -2069.2432, 104.377655, NULL, 0);

UPDATE `creature` SET `position_x`=192.62746, `position_y`=-2076.4026, `position_z`=104.377655, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Hungry Vulture
SET @MOVERGUID := 1051363;
SET @ENTRY := 154268;
SET @PATHOFFSET := 8;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x02, NULL, 'Hungry Vulture - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 195.14304, -2034.4199, 96.83711, NULL, 0),
(@PATH, 1, 201.94855, -2030.918, 96.83711, NULL, 0),
(@PATH, 2, 209.23703, -2033.2539, 96.83711, NULL, 0),
(@PATH, 3, 212.73898, -2040.0594, 96.83711, NULL, 0),
(@PATH, 4, 210.40302, -2047.3479, 96.83711, NULL, 0),
(@PATH, 5, 203.59752, -2050.8499, 96.83711, NULL, 0),
(@PATH, 6, 196.30904, -2048.514, 96.83711, NULL, 0),
(@PATH, 7, 192.80708, -2041.7084, 96.83711, NULL, 0);

UPDATE `creature` SET `position_x`=195.14304, `position_y`=-2034.4199, `position_z`=96.83711, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Harpy Snatcher
SET @MOVERGUID := 1051520;
SET @ENTRY := 152571;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, NULL, 'Harpy Snatcher - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 432.696, -2412.7878, 147.20538, NULL, 0),
(@PATH, 1, 430.24692, -2415.7285, 147.90018, NULL, 0),
(@PATH, 2, 426.4359, -2416.076, 148.46404, NULL, 0),
(@PATH, 3, 423.4954, -2413.627, 148.45517, NULL, 0),
(@PATH, 4, 423.1479, -2409.816, 147.62311, NULL, 0),
(@PATH, 5, 425.59695, -2406.8752, 147.62181, NULL, 0),
(@PATH, 6, 429.408, -2406.5278, 147.54799, NULL, 0),
(@PATH, 7, 432.3485, -2408.9768, 146.9591, NULL, 0);

UPDATE `creature` SET `position_x`=432.696, `position_y`=-2412.7878, `position_z`=147.20538, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
