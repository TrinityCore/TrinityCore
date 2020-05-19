SET @CGUID := 396305;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+72;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- Worgen
(@CGUID+1, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1387.13720703125, 1385.486083984375, 64.5087432861328125, 4.656879425048828125, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+2, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1371.454833984375, 1346.75, 36.23651885986328125, 1.593780279159545898, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+3, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1476.78125, 1347.857666015625, 35.6392669677734375, 3.357446193695068359, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+4, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1396.4600830078125, 1351.99658203125, 71.082427978515625, 3.366068601608276367, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+5, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1421.829833984375, 1399.1319580078125, 71.7026519775390625, 4.734184741973876953, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+6, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1572.329833984375, 1441.4600830078125, 71.89566802978515625, 4.858071327209472656, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+7, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1476.2222900390625, 1330.2864990234375, 71.11440277099609375, 0.351950049400329589, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+8, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1470.9322509765625, 1383.0850830078125, 36.0872039794921875, 4.118977069854736328, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+9, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1374.15283203125, 1389.0382080078125, 36.2371826171875, 5.10256052017211914, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+10, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1371.454833984375, 1346.75, 36.23651885986328125, 1.593780279159545898, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+11, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1571.53125, 1409.3021240234375, 71.54961395263671875, 0.061006966978311538, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+12, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1470.77783203125, 1441.05908203125, 36.343597412109375, 2.600540637969970703, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (Auras: 8599 - Enrage)
(@CGUID+13, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1386.6944580078125, 1436.626708984375, 71.87969970703125, 4.654486656188964843, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+14, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1572.329833984375, 1441.4600830078125, 71.89566802978515625, 4.858071327209472656, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (Auras: 8599 - Enrage)
(@CGUID+15, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1542.060791015625, 1428.609375, 35.63924789428710937, 3.993407487869262695, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+16, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1539.3941650390625, 1370.75, 63.33633041381835937, 3.16800689697265625, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+17, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1555.1024169921875, 1413.939208984375, 35.63924789428710937, 4.710654258728027343, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+18, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1492.046875, 1434.3489990234375, 35.78022384643554687, 4.753104686737060546, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+19, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1490.0052490234375, 1370.4166259765625, 71.98633575439453125, 3.162922382354736328, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+20, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1503.142333984375, 1371.7742919921875, 35.63924026489257812, 3.885082244873046875, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+21, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1576.0191650390625, 1377.8541259765625, 71.78739166259765625, 6.259011745452880859, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+22, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1568.1875, 1364.1041259765625, 35.781524658203125, 2.691069364547729492, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+23, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1554.5416259765625, 1351.41845703125, 35.63924789428710937, 3.70555424690246582, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+24, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1497.3055419921875, 1439.810791015625, 36.05542373657226562, 0.820304751396179199, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+25, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1583.0572509765625, 1333.0572509765625, 63.34681320190429687, 1.494119644165039062, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+26, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1564.68408203125, 1341.40283203125, 35.81101226806640625, 3.884108781814575195, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+27, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1441.8992919921875, 1450.796875, 71.41571044921875, 3.141127824783325195, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+28, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1522.74658203125, 1458.59375, 63.98261260986328125, 4.867583751678466796, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+29, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1477.298583984375, 1322.5035400390625, 65.577789306640625, 2.02928018569946289, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+30, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1558.84033203125, 1306.861083984375, 73.1620025634765625, 0.344788163900375366, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+31, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1529.203125, 1355.076416015625, 36.07855987548828125, 0.17860431969165802, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+32, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1582.484375, 1344.2916259765625, 71.54705047607421875, 4.691989898681640625, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+33, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1594.66845703125, 1336.296875, 60.98972320556640625, 6.237114429473876953, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+34, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1554.2100830078125, 1323.376708984375, 35.6392669677734375, 0.578911244869232177, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+35, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1490.0052490234375, 1370.4166259765625, 71.98633575439453125, 3.162922382354736328, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (Auras: 8599 - Enrage)
(@CGUID+36, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1572.329833984375, 1441.4600830078125, 71.89566802978515625, 4.858071327209472656, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+37, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1375.9132080078125, 1426.9427490234375, 65.6416778564453125, 3.176557302474975585, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (Auras: 8599 - Enrage)
(@CGUID+38, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1420.2847900390625, 1438.8541259765625, 71.3798828125, 4.710591316223144531, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+39, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1490.0052490234375, 1370.4166259765625, 71.98633575439453125, 3.162922382354736328, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+40, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1572.329833984375, 1441.4600830078125, 71.89566802978515625, 4.858071327209472656, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+41, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1520.8836669921875, 1382.7291259765625, 36.08524322509765625, 4.468042850494384765, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+42, 34884, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1558.907958984375, 1395.24658203125, 35.775390625, 5.014535427093505859, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
-- Guards
(@CGUID+43, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1441.632, 1420.7205, 35.68091, 3.368485450744628906, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+44, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1488.7135, 1345.2413, 35.68091, 2.321287870407104492, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+45, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1502.5156, 1359.8923, 35.68091, 2.321287870407104492, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+46, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1437.901, 1395.618, 35.68091, 3.874630928039550781, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+47, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1449.1666, 1361.0209, 35.65739, 2.321287870407104492, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+48, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1455.4271, 1390.8334, 35.68091, 3.368485450744628906, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+49, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1417.8091, 1367.6598, 35.680923, 2.321287870407104492, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+50, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1404.3091, 1379.8108, 35.680923, 2.321287870407104492, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+51, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1462.1823, 1429.7101, 35.68091, 3.368485450744628906, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+52, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1484.9132, 1428.3594, 35.680904, 2.321287870407104492, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+53, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1535.4966, 1435.8507, 35.73284, 5.811946392059326171, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+54, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1513.8195, 1423.8629, 35.67107, 3.368485450744628906, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+55, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1555.4567, 1386.3942, 35.680916, 1.134464025497436523, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+56, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1555.1163, 1406.4028, 35.67107, 0.436332315206527709, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+57, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1548.1163, 1421.691, 35.67107, 4.660028934478759765, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+58, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1486.8264, 1404.2257, 35.680904, 3.944444179534912109, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+59, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1527.6476, 1390.5435, 35.68091, 0.837758064270019531, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+60, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1542.7291, 1405.092, 35.67107, 2.321287870407104492, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+61, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1506.9548, 1401.5955, 35.67107, 2.321287870407104492, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+62, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1511.5817, 1399.1024, 35.68091, 0.244346097111701965, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+63, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1499.5642, 1380.9896, 35.680904, 1.466076612472534179, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+64, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1556.2101, 1354.5173, 35.68091, 5.218534469604492187, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+65, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1516.4774, 1334.5435, 35.68091, 3.525565147399902343, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+66, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1522.7396, 1349.0139, 35.68091, 2.321287870407104492, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+67, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1530.4341, 1336.2778, 35.68091, 2.321287870407104492, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+68, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1559.4514, 1324.3438, 35.61812, 2.321287870407104492, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+69, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1572.6528, 1339.9567, 35.786976, 5.969026088714599609, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+70, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1565.3177, 1347.2535, 35.68091, 5.044001579284667968, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+71, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1572.7118, 1366.2916, 35.933598, 6.021385669708251953, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+72, 34916, 654, 4755, 4756, 1, 170, 0, 638, 0, 0, -1539.5486, 1349.1598, 36.01758, 5.79449319839477539, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0); -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+72;
INSERT INTO `creature_addon` (`guid`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID+12, 0, 1, 173, ''),
(@CGUID+24, 0, 1, 173, ''),
(@CGUID+41, 0, 1, 173, ''),
(@CGUID+8, 0, 1, 173, '');

-- Correct Liam Greymane home position
UPDATE `creature` SET `position_x`= -1437.9548, `position_y`= 1401.1476, `position_z`= 35.639267, `orientation`= 4.743285655975341796 WHERE `guid`= 376406;

-- Set random movement
UPDATE `creature` SET `MovementType`= 1, `spawndist`= 8 WHERE `guid` IN (@CGUID+18, @CGUID+15, @CGUID+17, @CGUID+42, @CGUID+20, @CGUID+31, @CGUID+34, @CGUID+26, @CGUID+23, @CGUID+22, @CGUID+3);

-- Delete old worgen
DELETE FROM `creature` WHERE `guid` IN (376647, 376613, 376612, 376611, 376610, 376608, 376600, 376599, 376596, 376597, 376598, 376464, 376465, 376463, 376462, 376461, 376460, 376459, 376458, 376457, 376456, 376441, 376423, 376421, 376422, 376418, 376419, 376413, 376414, 376412, 376410, 376409, 376407, 376408, 376403, 376401, 376399, 376400, 376397, 376398, 376396, 376395, 376394, 376393, 376392, 376391, 376390, 376388, 376386, 376385, 376384, 376382, 376381, 376380, 376379, 376378);
DELETE FROM `creature_addon` WHERE `guid` IN (376647, 376613, 376612, 376611, 376610, 376608, 376600, 376599, 376596, 376597, 376598, 376464, 376465, 376463, 376462, 376461, 376460, 376459, 376458, 376457, 376456, 376441, 376423, 376421, 376422, 376418, 376419, 376413, 376414, 376412, 376410, 376409, 376407, 376408, 376403, 376401, 376399, 376400, 376397, 376398, 376396, 376395, 376394, 376393, 376392, 376391, 376390, 376388, 376386, 376385, 376384, 376382, 376381, 376380, 376379, 376378);
-- Delete old guards
DELETE FROM `creature` WHERE `guid` IN (376377, 376383, 376387, 376389, 376402, 376411, 376416, 376417, 376424, 376426, 376427, 376431, 376434, 376435, 376436, 376438, 376440, 376442, 376443, 376445, 376446, 376447, 376448, 376450);
DELETE FROM `creature_addon` WHERE `guid` IN (376377, 376383, 376387, 376389, 376402, 376411, 376416, 376417, 376424, 376426, 376427, 376431, 376434, 376435, 376436, 376438, 376440, 376442, 376443, 376445, 376446, 376447, 376448, 376450);

-- Creature Rampaging Worgen 34884 SAI
SET @ENTRY := 34884;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell Enrage (8599) on Self // Rampaging Worgen - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Rampaging Worgen - Between 0-30% Health - Say Line 0 (No Repeat)");
