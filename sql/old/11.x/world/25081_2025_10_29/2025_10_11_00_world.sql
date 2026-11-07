SET @CGUID := 3000013;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+54;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1441.632, 1420.7205, 35.68091, 3.368485450744628906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1
(@CGUID+1, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1488.7135, 1345.2413, 35.68091, 2.321287870407104492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1
(@CGUID+2, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1502.5156, 1359.8923, 35.68091, 2.321287870407104492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1
(@CGUID+3, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1437.901, 1395.618, 35.68091, 3.874630928039550781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1
(@CGUID+4, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1449.1666, 1361.0209, 35.65739, 2.321287870407104492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1
(@CGUID+5, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1455.4271, 1390.8334, 35.68091, 3.368485450744628906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1
(@CGUID+6, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1417.8091, 1367.6598, 35.680923, 2.321287870407104492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1
(@CGUID+7, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1404.3091, 1379.8108, 35.680923, 2.321287870407104492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1
(@CGUID+8, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1462.1823, 1429.7101, 35.68091, 3.368485450744628906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1
(@CGUID+9, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1484.9132, 1428.3594, 35.680904, 2.321287870407104492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1
(@CGUID+10, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1535.4966, 1435.8507, 35.73284, 5.811946392059326171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1
(@CGUID+11, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1513.8195, 1423.8629, 35.67107, 3.368485450744628906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1
(@CGUID+12, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1555.4567, 1386.3942, 35.680916, 1.134464025497436523, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1
(@CGUID+13, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1555.1163, 1406.4028, 35.67107, 0.436332315206527709, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1
(@CGUID+14, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1548.1163, 1421.691, 35.67107, 4.660028934478759765, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1
(@CGUID+15, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1486.8264, 1404.2257, 35.680904, 3.944444179534912109, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1
(@CGUID+16, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1527.6476, 1390.5435, 35.68091, 0.837758064270019531, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1
(@CGUID+17, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1542.7291, 1405.092, 35.67107, 2.321287870407104492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1
(@CGUID+18, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1506.9548, 1401.5955, 35.67107, 2.321287870407104492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1
(@CGUID+19, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1511.5817, 1399.1024, 35.68091, 0.244346097111701965, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+20, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1499.5642, 1380.9896, 35.680904, 1.466076612472534179, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1
(@CGUID+21, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1516.4774, 1334.5435, 35.68091, 3.525565147399902343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+22, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1522.7396, 1349.0139, 35.68091, 2.321287870407104492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1
(@CGUID+23, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1530.4341, 1336.2778, 35.68091, 2.321287870407104492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1
(@CGUID+24, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1559.4514, 1324.3438, 35.61812, 2.321287870407104492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+25, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1572.6528, 1339.9567, 35.786976, 5.969026088714599609, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1
(@CGUID+26, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1565.3177, 1347.2535, 35.68091, 5.044001579284667968, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+27, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1572.7118, 1366.2916, 35.933598, 6.021385669708251953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1
(@CGUID+28, 34916, 654, 4755, 4756, '0', 170, 0, 0, 1, -1539.5486, 1349.1598, 36.01758, 5.79449319839477539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) CreateObject1
(@CGUID+29, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1441.8992919921875, 1450.796875, 71.41571044921875, 3.141127824783325195, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+30, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1542.060791015625, 1428.609375, 35.63924789428710937, 0.584159016609191894, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+31, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1571.53125, 1409.3021240234375, 71.54961395263671875, 0.061006966978311538, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+32, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1555.1024169921875, 1413.939208984375, 35.63924789428710937, 0.837758064270019531, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2
(@CGUID+33, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1576.0191650390625, 1377.8541259765625, 71.78739166259765625, 6.259011745452880859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+34, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1490.0052490234375, 1370.4166259765625, 71.98633575439453125, 3.162922382354736328, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+35, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1520.8836669921875, 1382.7291259765625, 36.08524322509765625, 4.468042850494384765, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2
(@CGUID+36, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1421.829833984375, 1399.1319580078125, 71.7026519775390625, 4.734184741973876953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2
(@CGUID+37, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1476.78125, 1347.857666015625, 35.6392669677734375, 2.133827686309814453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+38, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1554.5416259765625, 1351.41845703125, 35.63924789428710937, 1.865449070930480957, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+39, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1594.66845703125, 1336.296875, 60.98972320556640625, 6.237114429473876953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2
(@CGUID+40, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1568.1875, 1364.1041259765625, 35.781524658203125, 3.150498390197753906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+41, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1529.203125, 1355.076416015625, 36.07855987548828125, 2.008714675903320312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2
(@CGUID+42, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1554.2100830078125, 1323.376708984375, 35.6392669677734375, 3.099469184875488281, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2
(@CGUID+43, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1582.484375, 1344.2916259765625, 71.54705047607421875, 4.691989898681640625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2
(@CGUID+44, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1396.4600830078125, 1351.99658203125, 71.082427978515625, 3.366068601608276367, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2
(@CGUID+45, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1374.15283203125, 1389.0382080078125, 36.2371826171875, 5.10256052017211914, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2
(@CGUID+46, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1387.13720703125, 1385.486083984375, 64.5087432861328125, 4.656879425048828125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+47, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1470.9322509765625, 1383.0850830078125, 36.0872039794921875, 4.118977069854736328, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+48, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1476.2222900390625, 1330.2864990234375, 71.11440277099609375, 0.351950049400329589, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+49, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1470.77783203125, 1441.05908203125, 36.343597412109375, 2.600540637969970703, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2
(@CGUID+50, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1492.046875, 1434.3489990234375, 35.78022384643554687, 2.753101587295532226, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2
(@CGUID+51, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1503.142333984375, 1371.7742919921875, 35.63924026489257812, 1.330657958984375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2
(@CGUID+52, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1420.2847900390625, 1438.8541259765625, 71.3798828125, 4.710591316223144531, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+53, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1564.68408203125, 1341.40283203125, 35.81101226806640625, 2.426650762557983398, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2
(@CGUID+54, 34884, 654, 4755, 4756, '0', 170, 0, 0, 0, -1375.9132080078125, 1426.9427490234375, 65.6416778564453125, 3.176557302474975585, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305); -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) CreateObject2
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+54;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+11, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+12, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+13, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+14, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+15, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+16, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+17, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+18, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+19, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+20, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+21, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+22, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+23, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+24, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+25, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+26, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+27, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+28, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard
(@CGUID+35, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 3, ''), -- Rampaging Worgen
(@CGUID+50, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 3, ''); -- Rampaging Worgen

-- Template Addon
UPDATE `creature_template_addon` SET `visibilityDistanceType`=3 WHERE `entry`=35457; -- 35457 (Bloodfang Bloodletter)
UPDATE `creature_template_addon` SET `visibilityDistanceType`=3 WHERE `entry`=35456; -- 35456 (Worgen Runt)
UPDATE `creature_template_addon` SET `visibilityDistanceType`=3 WHERE `entry`=34884; -- 34884 (Rampaging Worgen)

-- Update Addon
UPDATE `creature_addon` SET `emote` = 375 WHERE `guid` = 376404;

-- Delete old Worgen
DELETE FROM `creature` WHERE `guid` IN (376647, 376613, 376612, 376611, 376610, 376608, 376600, 376599, 376596, 376597, 376598, 376464, 376465, 376463, 376462, 376461, 376460, 376459, 376458, 376457, 376456, 376441, 376423, 376421, 376422, 376418, 376419, 376413, 376414, 376412, 376410, 376409, 376407, 376408, 376403, 376401, 376399, 376400, 376397, 376398, 376396, 376395, 376394, 376393, 376392, 376391, 376390, 376388, 376386, 376385, 376384, 376382, 376381, 376380, 376379, 376378, 376609);
DELETE FROM `creature_addon` WHERE `guid` IN (376647, 376613, 376612, 376611, 376610, 376608, 376600, 376599, 376596, 376597, 376598, 376464, 376465, 376463, 376462, 376461, 376460, 376459, 376458, 376457, 376456, 376441, 376423, 376421, 376422, 376418, 376419, 376413, 376414, 376412, 376410, 376409, 376407, 376408, 376403, 376401, 376399, 376400, 376397, 376398, 376396, 376395, 376394, 376393, 376392, 376391, 376390, 376388, 376386, 376385, 376384, 376382, 376381, 376380, 376379, 376378, 376609);

-- Delete old Guards
DELETE FROM `creature` WHERE `guid` IN (376377, 376383, 376387, 376389, 376402, 376411, 376416, 376417, 376424, 376426, 376427, 376431, 376434, 376435, 376436, 376438, 376440, 376442, 376443, 376445, 376446, 376447, 376448, 376450);
DELETE FROM `creature_addon` WHERE `guid` IN (376377, 376383, 376387, 376389, 376402, 376411, 376416, 376417, 376424, 376426, 376427, 376431, 376434, 376435, 376436, 376438, 376440, 376442, 376443, 376445, 376446, 376447, 376448, 376450);

-- Correct Liam Greymane home position
UPDATE `creature` SET `position_x`= -1437.9548, `position_y`= 1401.1476, `position_z`= 35.639267, `orientation`= 4.743285655975341796 WHERE `guid`= 376406;

-- Update Frightened Chicken (Phase 170) spawn pos with CreateObject2
UPDATE `creature` SET `position_x`= -1512.8800048828125, `position_y`= 1380.1199951171875, `position_z`= 36.06293106079101562, `orientation`= 0.964403986930847167 WHERE `guid`= 376425;
UPDATE `creature` SET `position_x`= -1524.3900146484375, `position_y`= 1382.1300048828125, `position_z`= 36.08663177490234375, `orientation`= 0.83209317922592163 WHERE `guid`= 376429;
UPDATE `creature` SET `position_x`= -1525.77001953125, `position_y`= 1385.300048828125, `position_z`= 36.08723068237304687, `orientation`= 2.920115470886230468 WHERE `guid`= 376430;
UPDATE `creature` SET `position_x`= -1520.52001953125, `position_y`= 1382.4100341796875, `position_z`= 36.08503341674804687, `orientation`= 3.569797992706298828 WHERE `guid`= 376432;
UPDATE `creature` SET `position_x`= -1513.8399658203125, `position_y`= 1384.719970703125, `position_z`= 36.08203125, `orientation`= 6.104184627532958984 WHERE `guid`= 376433;
UPDATE `creature` SET `position_x`= -1520.1199951171875, `position_y`= 1386.550048828125, `position_z`= 36.084930419921875, `orientation`= 1.700930953025817871 WHERE `guid`= 376437;
UPDATE `creature` SET `position_x`= -1516.530029296875, `position_y`= 1382.760009765625, `position_z`= 36.08323287963867187, `orientation`= 5.5466461181640625 WHERE `guid`= 376439;

UPDATE `creature` SET `wander_distance` = 4, `MovementType` = 1 WHERE `guid` IN (376425,376429,376430,376432,376437,376439,376433);
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x0 WHERE (`Entry`=44426 AND `DifficultyID`=0);

-- Update Rat (Phase 170) spawn pos with CreateObject2
UPDATE `creature` SET `position_x`= -1410.0035400390625, `position_y`= 1432.0850830078125, `position_z`= 35.916656494140625, `orientation`= 4.641208648681640625 WHERE `guid`= 376420;
UPDATE `creature` SET `position_x`= -1553.8802490234375, `position_y`= 1435.888916015625, `position_z`= 35.91785430908203125, `orientation`= 6.234373092651367187 WHERE `guid`= 376405;
UPDATE `creature` SET `position_x`= -1566.982666015625, `position_y`= 1309.670166015625, `position_z`= 35.96320343017578125, `orientation`= 1.682290196418762207 WHERE `guid`= 376428;

-- Creature Sparring
DELETE FROM `creature_template_sparring` WHERE `Entry` IN (34916,34884,34913);
INSERT INTO `creature_template_sparring` (`Entry`, `NoNPCDamageBelowHealthPct`) VALUES
(34916, 85),
(34884, 85),
(34913, 85);

-- Rampaging Worgen smart ai
SET @ENTRY := 34884;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-30%% (once) - Self: Cast spell  8599 on Self // Rampaging Worgen - Between 0-30% Health - Cast \'Enrage\' (No Repeat)', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-30%% (once) - Self: Talk 0 to invoker // Rampaging Worgen - Between 0-30% Health - Say Line 0 (No Repeat)', ''),
(@ENTRY, 0, 2, 0, 25, 0, 100, 1, 0, 0, 0, 0, 0, 80, 3488400, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Start timed action list id #Rampaging Worgen #0 (3488400) (update Always)', ''),
(@ENTRY, 0, 3, 0, 25, 0, 100, 1, 0, 0, 0, 0, 0, 80, 3488401, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Start timed action list id #Rampaging Worgen #1 (3488401) (update Always)', ''),
(@ENTRY, 0, 4, 0, 25, 0, 100, 1, 0, 0, 0, 0, 0, 80, 3488402, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Start timed action list id #Rampaging Worgen #2 (3488402) (update Always)', ''),
(@ENTRY, 0, 5, 0, 25, 0, 100, 1, 0, 0, 0, 0, 0, 80, 3488403, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Start timed action list id #Rampaging Worgen #3 (3488403) (update Always)', ''),
(@ENTRY, 0, 6, 0, 25, 0, 100, 1, 0, 0, 0, 0, 0, 80, 3488404, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Start timed action list id #Rampaging Worgen #4 (3488404) (update Always)', ''),
(@ENTRY, 0, 7, 0, 25, 0, 100, 1, 0, 0, 0, 0, 0, 80, 3488405, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Start timed action list id #Rampaging Worgen #5 (3488405) (update Always)', ''),
(@ENTRY, 0, 8, 0, 25, 0, 100, 1, 0, 0, 0, 0, 0, 80, 3488406, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Start timed action list id #Rampaging Worgen #6 (3488406) (update Always)', ''),
(@ENTRY, 0, 9, 0, 25, 0, 100, 1, 0, 0, 0, 0, 0, 80, 3488407, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Start timed action list id #Rampaging Worgen #7 (3488407) (update Always)', ''),
(@ENTRY, 0, 10, 0, 25, 0, 100, 1, 0, 0, 0, 0, 0, 80, 3488408, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Start timed action list id #Rampaging Worgen #8 (3488408) (update Always)', ''),
(@ENTRY, 0, 11, 0, 25, 0, 100, 1, 0, 0, 0, 0, 0, 80, 3488409, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Start timed action list id #Rampaging Worgen #9 (3488409) (update Always)', ''),
(@ENTRY, 0, 12, 0, 25, 0, 100, 1, 0, 0, 0, 0, 0, 80, 3488410, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Start timed action list id #Rampaging Worgen #10 (3488410) (update Always)', ''),
(@ENTRY, 0, 13, 0, 25, 0, 100, 1, 0, 0, 0, 0, 0, 80, 3488411, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Start timed action list id #Rampaging Worgen #11 (3488411) (update Always)', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 34884 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 3, 34884, 0, 0, 58, 1, 0, 0, 0, 'Jump1', 0, 'Object has StringID Jump1'),
(22, 4, 34884, 0, 0, 58, 1, 0, 0, 0, 'Jump2', 0, 'Object has StringID Jump2'),
(22, 5, 34884, 0, 0, 58, 1, 0, 0, 0, 'Jump3', 0, 'Object has StringID Jump3'),
(22, 6, 34884, 0, 0, 58, 1, 0, 0, 0, 'Jump4', 0, 'Object has StringID Jump4'),
(22, 7, 34884, 0, 0, 58, 1, 0, 0, 0, 'Jump5', 0, 'Object has StringID Jump5'),
(22, 8, 34884, 0, 0, 58, 1, 0, 0, 0, 'Jump6', 0, 'Object has StringID Jump6'),
(22, 9, 34884, 0, 0, 58, 1, 0, 0, 0, 'Jump7', 0, 'Object has StringID Jump7'),
(22, 10, 34884, 0, 0, 58, 1, 0, 0, 0, 'Jump8', 0, 'Object has StringID Jump8'),
(22, 11, 34884, 0, 0, 58, 1, 0, 0, 0, 'Jump9', 0, 'Object has StringID Jump9'),
(22, 12, 34884, 0, 0, 58, 1, 0, 0, 0, 'Jump10', 0, 'Object has StringID Jump10'),
(22, 13, 34884, 0, 0, 58, 1, 0, 0, 0, 'Jump11', 0, 'Object has StringID Jump11'),
(22, 14, 34884, 0, 0, 58, 1, 0, 0, 0, 'Jump12', 0, 'Object has StringID Jump12');

UPDATE `creature` SET `StringID` = 'Jump1' WHERE `guid` = @CGUID+34;
UPDATE `creature` SET `StringID` = 'Jump2' WHERE `guid` = @CGUID+36;
UPDATE `creature` SET `StringID` = 'Jump3' WHERE `guid` = @CGUID+44;
UPDATE `creature` SET `StringID` = 'Jump4' WHERE `guid` = @CGUID+29;
UPDATE `creature` SET `StringID` = 'Jump5' WHERE `guid` = @CGUID+48;
UPDATE `creature` SET `StringID` = 'Jump6' WHERE `guid` = @CGUID+43;
UPDATE `creature` SET `StringID` = 'Jump7' WHERE `guid` = @CGUID+39;
UPDATE `creature` SET `StringID` = 'Jump8' WHERE `guid` = @CGUID+46;
UPDATE `creature` SET `StringID` = 'Jump9' WHERE `guid` = @CGUID+31;
UPDATE `creature` SET `StringID` = 'Jump10' WHERE `guid` = @CGUID+33;
UPDATE `creature` SET `StringID` = 'Jump11' WHERE `guid` = @CGUID+52;
UPDATE `creature` SET `StringID` = 'Jump12' WHERE `guid` = @CGUID+54;

-- Timed list 3488400 smart ai
SET @ENTRY := 3488400;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set react state to Passive', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0x20, 1000, 1000, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1461, 1370.68, 64.398, 0, 'After 1 seconds - Self: Jump to pos with speed XY 0, speed Z 14 and gravity 0', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0x20, 2000, 2000, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1459.82, 1386.06, 36.0044, 0, 'After 2 seconds - Self: Jump to pos with speed XY 14, speed Z 0 and gravity 0', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set react state to Aggressive', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set home position to current position', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Attack Creature Gilneas City Guard (34916) in 40 yd', '');

-- Timed list 3488401 smart ai
SET @ENTRY := 3488401;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set react state to Passive', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0x20, 1000, 1000, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1421.379, 1378.561, 73.31348, 0, 'After 1 seconds - Self: Jump to pos with speed XY 0, speed Z 14 and gravity 0', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0x20, 2000, 2000, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1437.56, 1364.63, 35.5559, 0, 'After 2 seconds - Self: Jump to pos with speed XY 14, speed Z 0 and gravity 0', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set react state to Aggressive', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set home position to current position', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Attack Creature Gilneas City Guard (34916) in 40 yd', '');

-- Timed list 3488402 smart ai
SET @ENTRY := 3488402;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set react state to Passive', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0x20, 1000, 1000, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1425.561, 1358.085, 65.88074, 0, 'After 1 seconds - Self: Jump to pos with speed XY 0, speed Z 14 and gravity 0', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0x20, 2000, 2000, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1447.21, 1394.15, 35.5559, 0, 'After 2 seconds - Self: Jump to pos with speed XY 14, speed Z 0 and gravity 0', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set react state to Aggressive', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set home position to current position', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Attack Creature Gilneas City Guard (34916) in 40 yd', '');

-- Timed list 3488403 smart ai
SET @ENTRY := 3488403;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set react state to Passive', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0x20, 1000, 1000, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1476.776, 1440.854, 60.71806, 0, 'After 1 seconds - Self: Jump to pos with speed XY 0, speed Z 14 and gravity 0', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0x20, 2000, 2000, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1491.3, 1412.48, 35.5559, 0, 'After 2 seconds - Self: Jump to pos with speed XY 14, speed Z 0 and gravity 0', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set react state to Aggressive', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set home position to current position', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Attack Creature Gilneas City Guard (34916) in 40 yd', '');

-- Timed list 3488404 smart ai
SET @ENTRY := 3488404;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set react state to Passive', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0x20, 1000, 1000, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1476.056, 1342.712, 64.17184, 0, 'After ´1 seconds - Self: Jump to pos with speed XY 0, speed Z 14 and gravity 0', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0x20, 2000, 2000, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1501.05, 1347.99, 35.5559, 0, 'After 2 seconds - Self: Jump to pos with speed XY 14, speed Z 0 and gravity 0', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set react state to Aggressive', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set home position to current position', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Attack Creature Gilneas City Guard (34916) in 40 yd', '');

-- Timed list 3488405 smart ai
SET @ENTRY := 3488405;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set react state to Passive', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0x20, 1000, 1000, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1571.002, 1351.12, 61.17989, 0, 'After 1 seconds - Self: Jump to pos with speed XY 0, speed Z 14 and gravity 0', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0x20, 2000, 2000, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1564.1, 1361.27, 35.5669, 0, 'After 2 seconds - Self: Jump to pos with speed XY 14, speed Z 0 and gravity 0', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set react state to Aggressive', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set home position to current position', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Attack Creature Gilneas City Guard (34916) in 40 yd', '');

-- Timed list 3488406 smart ai
SET @ENTRY := 3488406;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set react state to Passive', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0x20, 1000, 1000, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1573.484, 1333.042, 58.79423, 0, 'After 1 seconds - Self: Jump to pos with speed XY 0, speed Z 14 and gravity 0', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0x20, 2000, 2000, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1535.17, 1332.43, 35.5669, 0, 'After 2 seconds - Self: Jump to pos with speed XY 14, speed Z 0 and gravity 0', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set react state to Aggressive', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set home position to current position', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Attack Creature Gilneas City Guard (34916) in 40 yd', '');

-- Timed list 3488407 smart ai
SET @ENTRY := 3488407;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set react state to Passive', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0x20, 1000, 1000, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1388.774, 1370.519, 35.80763, 0, 'After 1 seconds - Self: Jump to pos with speed XY 0, speed Z 14 and gravity 0', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0x20, 2000, 2000, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1442.83, 1381.44, 35.5669, 0, 'After 2 seconds - Self: Jump to pos with speed XY 14, speed Z 0 and gravity 0', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set react state to Aggressive', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set home position to current position', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Attack Creature Gilneas City Guard (34916) in 40 yd', '');

-- Timed list 3488408 smart ai
SET @ENTRY := 3488408;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set react state to Passive', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0x20, 1000, 1000, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1523.646, 1411.806, 39.71187, 0, 'After 1 seconds - Self: Jump to pos with speed XY 0, speed Z 14 and gravity 0', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0x20, 2000, 2000, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1517.4, 1425.16, 35.5559, 0, 'After 2 seconds - Self: Jump to pos with speed XY 14, speed Z 0 and gravity 0', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set react state to Aggressive', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set home position to current position', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Attack Creature Gilneas City Guard (34916) in 40 yd', '');

-- Timed list 3488409 smart ai
SET @ENTRY := 3488409;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set react state to Passive', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0x20, 1000, 1000, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1528.896, 1381.031, 58.56568, 0, 'After 1 seconds - Self: Jump to pos with speed XY 0, speed Z 14 and gravity 0', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0x20, 2000, 2000, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1508.87, 1395.77, 35.5559, 0, 'After 2 seconds - Self: Jump to pos with speed XY 14, speed Z 0 and gravity 0', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set react state to Aggressive', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set home position to current position', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Attack Creature Gilneas City Guard (34916) in 40 yd', '');

-- Timed list 3488410 smart ai
SET @ENTRY := 3488410;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set react state to Passive', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0x20, 1000, 1000, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1421.38, 1413.828, 64.13194, 0, 'After 1 seconds - Self: Jump to pos with speed XY 0, speed Z 14 and gravity 0', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0x20, 2000, 2000, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1437.75, 1394.52, 35.5559, 0, 'After 2 seconds - Self: Jump to pos with speed XY 14, speed Z 0 and gravity 0', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set react state to Aggressive', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set home position to current position', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Attack Creature Gilneas City Guard (34916) in 40 yd', '');

-- Timed list 3488411 smart ai
SET @ENTRY := 3488411;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set react state to Passive', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0x20, 1000, 1000, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1387.14, 1426.55, 71.6557, 0, 'After 1 seconds - Self: Jump to pos with speed XY 0, speed Z 14 and gravity 0', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0x20, 2000, 2000, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1417.49, 1417.12, 42.5891, 0, 'After 2 seconds - Self: Jump to pos with speed XY 14, speed Z 0 and gravity 0', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0x20, 2000, 2000, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1446.68, 1420.5, 35.5559, 0, 'After 2 seconds - Self: Jump to pos with speed XY 14, speed Z 0 and gravity 0', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set react state to Aggressive', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set home position to current position', ''),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Attack Creature Gilneas City Guard (34916) in 40 yd', '');

-- Path for Rat
SET @MOVERGUID := 376420;
SET @ENTRY := 4075;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Rat - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1427.9948, 1419.7935, 35.555935, NULL, 0),
(@PATH, 1, -1438.8125, 1420.6823, 35.555923, NULL, 0),
(@PATH, 2, -1444.4497, 1404.1562, 35.55591, NULL, 0),
(@PATH, 3, -1451.7014, 1393.8264, 35.55591, NULL, 0),
(@PATH, 4, -1466.6267, 1393.2865, 35.55591, NULL, 0),
(@PATH, 5, -1494, 1393.2935, 35.555916, NULL, 0),
(@PATH, 6, -1525.5903, 1391.9445, 35.555916, NULL, 0),
(@PATH, 7, -1563.5764, 1394.6354, 35.90297, NULL, 0),
(@PATH, 8, -1575.6007, 1393.6685, 36.63449, NULL, 0),
(@PATH, 9, -1563.5764, 1394.6354, 35.90297, NULL, 0),
(@PATH, 10, -1525.5903, 1391.9445, 35.555916, NULL, 0),
(@PATH, 11, -1494, 1393.2935, 35.555916, NULL, 0),
(@PATH, 12, -1466.6267, 1393.2865, 35.55591, NULL, 0),
(@PATH, 13, -1451.7014, 1393.8264, 35.55591, NULL, 0),
(@PATH, 14, -1444.4497, 1404.1562, 35.55591, NULL, 0),
(@PATH, 15, -1438.8125, 1420.6823, 35.555923, NULL, 0),
(@PATH, 16, -1427.9948, 1419.7935, 35.555935, NULL, 0),
(@PATH, 17, -1418.1024, 1419.9548, 35.555935, NULL, 0),
(@PATH, 18, -1410.5017, 1425.099, 35.55593, NULL, 0),
(@PATH, 19, -1409.6962, 1431.6979, 35.81013, NULL, 0),
(@PATH, 20, -1418.1024, 1419.9548, 35.555935, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Rat
SET @MOVERGUID := 376405;
SET @ENTRY := 4075;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Rat - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1516.375, 1435.5764, 35.73242, NULL, 0),
(@PATH, 1, -1488.2639, 1435.0817, 35.73568, NULL, 0),
(@PATH, 2, -1460.5469, 1434.6267, 35.74746, NULL, 0),
(@PATH, 3, -1434.856, 1435.6094, 35.76918, NULL, 161),
(@PATH, 4, -1460.5469, 1434.6267, 35.74746, NULL, 0),
(@PATH, 5, -1488.2639, 1435.0817, 35.73568, NULL, 0),
(@PATH, 6, -1516.375, 1435.5764, 35.73242, NULL, 0),
(@PATH, 7, -1535.1962, 1434.9757, 35.675293, NULL, 0),
(@PATH, 8, -1553.007, 1435.7726, 35.8042, NULL, 66),
(@PATH, 9, -1535.1962, 1434.9757, 35.675293, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Rat
SET @MOVERGUID := 376428;
SET @ENTRY := 4075;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Rat - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1510.8021, 1340.2656, 35.55593, NULL, 0),
(@PATH, 1, -1473.8298, 1350.2448, 35.555935, NULL, 0),
(@PATH, 2, -1452.7291, 1357.2483, 35.555935, NULL, 0),
(@PATH, 3, -1435.4584, 1357.1719, 35.555935, NULL, 0),
(@PATH, 4, -1431.6041, 1348.0973, 35.555466, NULL, 0),
(@PATH, 5, -1452.7291, 1357.2483, 35.555935, NULL, 0),
(@PATH, 6, -1473.8298, 1350.2448, 35.555935, NULL, 0),
(@PATH, 7, -1510.8021, 1340.2656, 35.55593, NULL, 0),
(@PATH, 8, -1545.1754, 1330.6875, 35.555935, NULL, 0),
(@PATH, 9, -1567.9341, 1318.1666, 35.555923, NULL, 0),
(@PATH, 10, -1568.0608, 1311.1198, 35.87018, NULL, 56),
(@PATH, 11, -1545.1754, 1330.6875, 35.555935, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
