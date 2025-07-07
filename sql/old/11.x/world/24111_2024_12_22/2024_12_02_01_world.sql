SET @CGUID := 10004615;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+36;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1633.6197509765625, -2367.53125, 11.22044658660888671, 3.833467006683349609, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+1, 224149, 2552, 14717, 14788, '0', 0, 0, 0, 1, 1690.90625, -2327.94970703125, 10.35885047912597656, 5.104869365692138671, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Webspinner (Area: The Opalcreg - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+2, 219397, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1599.3160400390625, -2343.760498046875, 15.36542224884033203, 3.8426666259765625, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Shalescale Striker (Area: The Opalcreg - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+3, 221681, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1663.892333984375, -2342.913330078125, 12.17217254638671875, 4.191411018371582031, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Slithering Shalescale (Area: The Opalcreg - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+4, 224149, 2552, 14717, 14788, '0', 0, 0, 0, 1, 1600.4722900390625, -2335.796875, 15.95692729949951171, 6.154852867126464843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Webspinner (Area: The Opalcreg - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+5, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1608.2725830078125, -2340.59716796875, 15.87487125396728515, 1.872506380081176757, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2 (Auras: ) (possible waypoints or random movement)
(@CGUID+6, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1687.34033203125, -2299.7275390625, 11.94620895385742187, 6.260561466217041015, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+7, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1704.30908203125, -2344.307373046875, 10.50328254699707031, 5.681008338928222656, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+8, 219397, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1651.7413330078125, -2373.3369140625, 8.641309738159179687, 0.516100823879241943, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Shalescale Striker (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+9, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1627.2083740234375, -2294.826416015625, 19.78551864624023437, 1.305797934532165527, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+10, 219397, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1625.4930419921875, -2344.385498046875, 16.53010940551757812, 3.589919567108154296, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Shalescale Striker (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+11, 219397, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1694.5555419921875, -2340.532958984375, 14.01274394989013671, 1.269250154495239257, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Shalescale Striker (Area: The Opalcreg - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+12, 221681, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1674.5086669921875, -2409.263916015625, 3.392244577407836914, 6.080512046813964843, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Slithering Shalescale (Area: The Opalcreg - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+13, 219397, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1697.6805419921875, -2404.873291015625, 0.407025307416915893, 3.072361946105957031, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Shalescale Striker (Area: The Opalcreg - Difficulty: 0) CreateObject2 (Auras: ) (possible waypoints or random movement)
(@CGUID+14, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1695.248291015625, -2424.654541015625, -0.1652492880821228, 5.322813034057617187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+15, 224149, 2552, 14717, 14788, '0', 0, 0, 0, 1, 1671.185791015625, -2463.154541015625, -8.01746368408203125, 5.688301563262939453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Webspinner (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+16, 219397, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1644.5242919921875, -2464.942626953125, -8.08136367797851562, 2.273038864135742187, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Shalescale Striker (Area: The Opalcreg - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+17, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1582.173583984375, -2443.717041015625, -21.2715187072753906, 5.365936279296875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+18, 219397, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1592.623291015625, -2482.864501953125, -13.1115322113037109, 2.068622589111328125, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Shalescale Striker (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+19, 221681, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1629.734375, -2511.845458984375, -5.38252735137939453, 1.470829129219055175, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Slithering Shalescale (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+20, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1613.157958984375, -2469.3994140625, -12.8920907974243164, 1.96464705467224121, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+21, 219397, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1570.59033203125, -2403.625, -26.3231849670410156, 1.018332719802856445, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Shalescale Striker (Area: The Opalcreg - Difficulty: 0) CreateObject2 (Auras: ) (possible waypoints or random movement)
(@CGUID+22, 224149, 2552, 14717, 14788, '0', 0, 0, 0, 1, 1556.8629150390625, -2427.748291015625, -23.2648487091064453, 5.135574817657470703, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Webspinner (Area: The Opalcreg - Difficulty: 0) CreateObject2 (Auras: ) (possible waypoints or random movement)
(@CGUID+23, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1589.295166015625, -2397.614501953125, -30.3449230194091796, 3.103336572647094726, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+24, 219397, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1668.2742919921875, -2437.157958984375, -43.8441047668457031, 2.273038864135742187, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Shalescale Striker (Area: The Opalcreg - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+25, 219397, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1722.4913330078125, -2422.642333984375, -46.412628173828125, 2.273038864135742187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Shalescale Striker (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+26, 219397, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1713.857666015625, -2441.26904296875, -45.9769630432128906, 2.273038864135742187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Shalescale Striker (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+27, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1613.2413330078125, -2358.553955078125, -41.7684402465820312, 1.042003870010375976, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+28, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1653.7725830078125, -2374.15966796875, -42.61199951171875, 0.607931971549987792, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+29, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1686.515625, -2430.407958984375, -46.137939453125, 1.315374374389648437, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+30, 221681, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1672.720458984375, -2429.767333984375, -43.477935791015625, 1.385368943214416503, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Slithering Shalescale (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+31, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1701.90625, -2392.145751953125, -47.1682014465332031, 5.934742927551269531, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+32, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1555.07470703125, -2415.942626953125, -25.36297607421875, 1.689284563064575195, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+33, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1607.98095703125, -2466.380126953125, -51.32073974609375, 5.951233386993408203, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+34, 221681, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1636.9739990234375, -2524.435791015625, -57.2230796813964843, 1.305542945861816406, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Slithering Shalescale (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+35, 224149, 2552, 14717, 14788, '0', 0, 0, 0, 1, 1571.845458984375, -2472.307373046875, -52.340087890625, 3.286326885223388671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Webspinner (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+36, 219397, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1574.390625, -2448.600830078125, -55.5827522277832031, 5.316397666931152343, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689); -- Shalescale Striker (Area: The Opalcreg - Difficulty: 0) CreateObject2
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+36;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Nerubian Webspinner
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 567, 0, 0, 0, 0, ''), -- Nerubian Skirmisher
(@CGUID+15, 0, 0, 0, 0, 0, 0, 0, 537, 0, 0, 0, 0, ''), -- Nerubian Webspinner
(@CGUID+27, 0, 0, 0, 0, 0, 1, 0, 537, 0, 0, 0, 0, ''), -- Nerubian Skirmisher
(@CGUID+32, 0, 0, 0, 0, 0, 1, 0, 537, 0, 0, 0, 0, ''), -- Nerubian Skirmisher
(@CGUID+35, 0, 0, 0, 0, 0, 0, 0, 537, 0, 0, 0, 0, ''); -- Nerubian Webspinner

-- Path for Nerubian Skirmisher
SET @MOVERGUID := @CGUID+17;
SET @ENTRY := 224150;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Nerubian Skirmisher - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1596.3013, -2460.9844, -15.605801, NULL, 0),
(@PATH, 1, 1598.8698, -2467.7588, -14.58057, NULL, 0),
(@PATH, 2, 1599.2812, -2479.158, -13.5259695, NULL, 0),
(@PATH, 3, 1598.6024, -2491.5938, -12.35553, NULL, 0),
(@PATH, 4, 1607.8524, -2507.4392, -11.187968, NULL, 0),
(@PATH, 5, 1617.2344, -2508.3213, -8.895281, NULL, 0),
(@PATH, 6, 1629.2084, -2509.7136, -5.6208534, NULL, 0),
(@PATH, 7, 1632.691, -2513.2466, -4.4681997, NULL, 0),
(@PATH, 8, 1641.401, -2515.4011, -4.4606285, NULL, 0),
(@PATH, 9, 1634.1788, -2511.1128, -4.3511605, NULL, 0),
(@PATH, 10, 1629.4305, -2509.6372, -5.5505295, NULL, 0),
(@PATH, 11, 1617.4341, -2508.007, -8.927226, NULL, 0),
(@PATH, 12, 1609.9305, -2506.5715, -10.849711, NULL, 0),
(@PATH, 13, 1599.0834, -2491.5295, -12.383754, NULL, 0),
(@PATH, 14, 1598.967, -2479.0781, -13.538734, NULL, 0),
(@PATH, 15, 1599.2656, -2467.6597, -14.602921, NULL, 0),
(@PATH, 16, 1596.566, -2461.434, -15.50868, NULL, 0),
(@PATH, 17, 1590.1823, -2454.236, -17.709822, NULL, 0),
(@PATH, 18, 1586.1216, -2448.8264, -19.618963, NULL, 0),
(@PATH, 19, 1591.0399, -2455.2952, -17.311071, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
