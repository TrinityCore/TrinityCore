SET @CGUID := 396570;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+66;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+66;

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- Armory
(@CGUID+0, 44690, 189, 796, 0, 1, 169, 0, 0, 0, 1624.6800537109375, -315.660003662109375, 18.09073448181152343, 4.660028934478759765, 7200, 0, 0, 7662, 0, 0, 0, 0, 0, 15211), -- Dark Ranger Velonara (Area: 0 - Difficulty: 0)
(@CGUID+1, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1620.72998046875, -326.75, 18.09083366394042968, 5.689773082733154296, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+2, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1620.1500244140625, -317.25, 18.09073448181152343, 4.712388992309570312, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+3, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1620.1800537109375, -345.427001953125, 18.09073448181152343, 1.553343057632446289, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+4, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1621.68994140625, -312.756988525390625, 18.09073448181152343, 4.712388992309570312, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+5, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1621.5899658203125, -315.6929931640625, 18.09073448181152343, 4.712388992309570312, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+6, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1621.6800537109375, -346.9169921875, 18.09073448181152343, 1.570796370506286621, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+7, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1622.219970703125, -337.555999755859375, 18.09073448181152343, 0.244346097111701965, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+8, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1623.1099853515625, -314.0780029296875, 18.09073448181152343, 4.712388992309570312, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+9, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1624.6500244140625, -312.644012451171875, 18.09073448181152343, 4.712388992309570312, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+10, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1626.06005859375, -314.15301513671875, 18.09073448181152343, 4.712388992309570312, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+11, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1627.7099609375, -315.64801025390625, 18.09073448181152343, 4.712388992309570312, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+12, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1627.510009765625, -339.47900390625, 18.09073448181152343, 0.733038306236267089, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+13, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1627.5999755859375, -346.92498779296875, 18.09073448181152343, 1.570796370506286621, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+14, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1627.6099853515625, -312.75299072265625, 18.09073448181152343, 4.712388992309570312, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+15, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1628.1099853515625, -329.962005615234375, 18.09073448181152343, 4.258603572845458984, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+16, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1629.199951171875, -317.209991455078125, 18.09073448181152343, 4.712388992309570312, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+17, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1629.0699462890625, -321.946014404296875, 18.09073448181152343, 4.660028934478759765, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+18, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1629.0999755859375, -345.5159912109375, 18.09073448181152343, 1.570796370506286621, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+19, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1641.1300048828125, -335.509002685546875, 18.76113319396972656, 4.258603572845458984, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+20, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1643.4000244140625, -360.885009765625, 18.76113319396972656, 4.258603572845458984, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+21, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1654.22998046875, -355.5780029296875, 18.10663414001464843, 4.258603572845458984, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+22, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1654.4300537109375, -363.427001953125, 18.10663414001464843, 4.258603572845458984, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+23, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1656.4599609375, -380.1510009765625, 18.76113319396972656, 4.258603572845458984, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+24, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1656.969970703125, -339.605987548828125, 18.76113319396972656, 4.258603572845458984, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+25, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1656.3699951171875, -360.22900390625, 18.10663414001464843, 4.258603572845458984, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+26, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1674.8299560546875, -359.316009521484375, 18.10663414001464843, 4.258603572845458984, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+27, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1675.1300048828125, -334.509002685546875, 18.76113319396972656, 4.258603572845458984, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+28, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1683.300048828125, -367.45098876953125, 18.10663414001464843, 4.258603572845458984, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+29, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1688.4300537109375, -359.985992431640625, 18.10663414001464843, 4.258603572845458984, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+30, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1689.469970703125, -381.6199951171875, 18.76113319396972656, 4.258603572845458984, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+31, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1694.489990234375, -351.259002685546875, 18.10663414001464843, 4.258603572845458984, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+32, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1700.9100341796875, -363.9320068359375, 18.10663414001464843, 4.258603572845458984, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+33, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1708.219970703125, -367.785003662109375, 18.76113319396972656, 4.258603572845458984, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+34, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1711.2099609375, -365.886993408203125, 18.76113319396972656, 4.258603572845458984, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+35, 44691, 189, 796, 0, 1, 169, 0, 0, 0, 1713.68994140625, -334.697998046875, 18.76113319396972656, 4.258603572845458984, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15211), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+36, 44693, 189, 796, 0, 1, 169, 0, 0, 0, 1624.6417236328125, -325.408477783203125, 18.00749778747558593, 4.714207649230957031, 7200, 0, 0, 6660, 0, 0, 0, 0, 0, 15211), -- Forsaken Flesh Ripper (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
-- Graveyard
(@CGUID+37, 44637, 189, 796, 0, 1, 169, 0, 0, 0, 1694.93994140625, 1098.030029296875, 6.903333663940429687, 0, 7200, 0, 0, 5730, 0, 0, 0, 0, 0, 15050), -- Dark Ranger Velonara (Area: 0 - Difficulty: 0)
(@CGUID+38, 44655, 189, 796, 0, 1, 169, 0, 0, 0, 1694.97998046875, 1101.030029296875, 6.903333663940429687, 6.2657318115234375, 7200, 0, 0, 3200, 0, 0, 0, 0, 0, 15050), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+39, 44655, 189, 796, 0, 1, 169, 0, 0, 0, 1695.0799560546875, 1095.0699462890625, 6.903333663940429687, 6.2657318115234375, 7200, 0, 0, 3200, 0, 0, 0, 0, 0, 15050), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
-- Library
(@CGUID+40, 44660, 189, 796, 0, 1, 169, 0, 0, 0, 278.09, -228.179, 18.614035, 3.141592741012573242, 7200, 0, 0, 6660, 0, 0, 0, 0, 0, 15050), -- Dark Ranger Velonara (Area: 0 - Difficulty: 0)
(@CGUID+41, 44661, 189, 796, 0, 1, 169, 0, 0, 0, 275.182, -231.174, 18.614035, 3.298672199249267578, 7200, 0, 0, 3820, 0, 0, 0, 0, 0, 15050), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+42, 44661, 189, 796, 0, 1, 169, 0, 0, 0, 278.142, -231.160, 18.614035, 3.298672199249267578, 7200, 0, 0, 3820, 0, 0, 0, 0, 0, 15050), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+43, 44661, 189, 796, 0, 1, 169, 0, 0, 0, 280.958, -228.167, 18.614035, 3.298672199249267578, 7200, 0, 0, 3820, 0, 0, 0, 0, 0, 15050), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+44, 44661, 189, 796, 0, 1, 169, 0, 0, 0, 278.106, -225.111, 18.614035, 3.298672199249267578, 7200, 0, 0, 3820, 0, 0, 0, 0, 0, 15050), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+45, 44661, 189, 796, 0, 1, 169, 0, 0, 0, 275.102, -225.182, 18.614035, 3.298672199249267578, 7200, 0, 0, 3820, 0, 0, 0, 0, 0, 15050), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
-- Cathedral
(@CGUID+46, 44706, 189, 796, 0, 1, 169, 0, 0, 0, 870.83, 1400.43, 18.089334, 4.694935798645019531, 7200, 0, 0, 8754, 0, 0, 0, 0, 0, 15050), -- Dark Ranger Velonara (Area: 0 - Difficulty: 0)
(@CGUID+47, 44707, 189, 796, 0, 1, 169, 0, 0, 0, 874.771, 1317.14, 18.089334, 3.159045934677124023, 7200, 0, 0, 5108, 0, 0, 0, 0, 0, 15050), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+48, 44707, 189, 796, 0, 1, 169, 0, 0, 0, 875.054, 1333.19, 18.089334, 3.159045934677124023, 7200, 0, 0, 5108, 0, 0, 0, 0, 0, 15050), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+49, 44707, 189, 796, 0, 1, 169, 0, 0, 0, 867.200, 1333.30, 18.089334, 6.213372230529785156, 7200, 0, 0, 5108, 0, 0, 0, 0, 0, 15050), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+50, 44707, 189, 796, 0, 1, 169, 0, 0, 0, 866.823, 1317.21, 18.089334, 6.213372230529785156, 7200, 0, 0, 5108, 0, 0, 0, 0, 0, 15050), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+51, 44707, 189, 796, 0, 1, 169, 0, 0, 0, 874.842, 1396.13, 18.089334, 3.159045934677124023, 7200, 0, 0, 5108, 0, 0, 0, 0, 0, 15050), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+52, 44707, 189, 796, 0, 1, 169, 0, 0, 0, 875.054, 1343.87, 18.089334, 3.159045934677124023, 7200, 0, 0, 5108, 0, 0, 0, 0, 0, 15050), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+53, 44707, 189, 796, 0, 1, 169, 0, 0, 0, 867.111, 1354.32, 18.089334, 6.213372230529785156, 7200, 0, 0, 5108, 0, 0, 0, 0, 0, 15050), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+54, 44707, 189, 796, 0, 1, 169, 0, 0, 0, 875.068, 1354.32, 18.089334, 3.159045934677124023, 7200, 0, 0, 5108, 0, 0, 0, 0, 0, 15050), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+55, 44707, 189, 796, 0, 1, 169, 0, 0, 0, 867.075, 1343.84, 18.089334, 6.213372230529785156, 7200, 0, 0, 5108, 0, 0, 0, 0, 0, 15050), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+56, 44707, 189, 796, 0, 1, 169, 0, 0, 0, 866.675, 1375.02, 18.089334, 6.213372230529785156, 7200, 0, 0, 5108, 0, 0, 0, 0, 0, 15050), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+57, 44707, 189, 796, 0, 1, 169, 0, 0, 0, 874.592, 1364.45, 18.089334, 3.159045934677124023, 7200, 0, 0, 5108, 0, 0, 0, 0, 0, 15050), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+58, 44707, 189, 796, 0, 1, 169, 0, 0, 0, 866.594, 1364.55, 18.089334, 6.213372230529785156, 7200, 0, 0, 5108, 0, 0, 0, 0, 0, 15050), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+59, 44707, 189, 796, 0, 1, 169, 0, 0, 0, 874.642, 1385.70, 18.089334, 3.159045934677124023, 7200, 0, 0, 5108, 0, 0, 0, 0, 0, 15050), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+60, 44707, 189, 796, 0, 1, 169, 0, 0, 0, 866.547, 1385.66, 18.089334, 6.213372230529785156, 7200, 0, 0, 5108, 0, 0, 0, 0, 0, 15050), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+61, 44707, 189, 796, 0, 1, 169, 0, 0, 0, 866.840, 1396.44, 18.089334, 6.213372230529785156, 7200, 0, 0, 5108, 0, 0, 0, 0, 0, 15050), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+62, 44707, 189, 796, 0, 1, 169, 0, 0, 0, 874.613, 1375.00, 18.089334, 3.159045934677124023, 7200, 0, 0, 5108, 0, 0, 0, 0, 0, 15050), -- Forsaken Royal Dreadguard (Area: 0 - Difficulty: 0)
(@CGUID+63, 44708, 189, 796, 0, 1, 169, 0, 0, 0, 907.334, 1381.6497, 18.025724, -0.54192733764648437, 7200, 0, 0, 7662, 0, 0, 0, 0, 0, 15050), -- Forsaken Flesh Ripper (Area: 0 - Difficulty: 0)
(@CGUID+64, 44708, 189, 796, 0, 1, 169, 0, 0, 0, 943.086, 1374.8909, 18.024418, 0.179109618067741394, 7200, 0, 0, 7662, 0, 0, 0, 0, 0, 15050), -- Forsaken Flesh Ripper (Area: 0 - Difficulty: 0)
(@CGUID+65, 44708, 189, 796, 0, 1, 169, 0, 0, 0, 906.418, 1420.1716, 17.996574, -0.08486439287662506, 7200, 0, 0, 7662, 0, 0, 0, 0, 0, 15050), -- Forsaken Flesh Ripper (Area: 0 - Difficulty: 0)
(@CGUID+66, 44708, 189, 796, 0, 1, 169, 0, 0, 0, 944.679, 1425.1497, 18.023273, -0.35963124036788940, 7200, 0, 0, 7662, 0, 0, 0, 0, 0, 15050); -- Forsaken Flesh Ripper (Area: 0 - Difficulty: 0)

INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
--
(@CGUID+0, 0, 0, 0, 1, 0, ''), -- Dark Ranger Velonara
(@CGUID+1, 0, 0, 0, 1, 0, '70628'), -- Forsaken Royal Dreadguard
(@CGUID+2, 0, 0, 0, 1, 333, ''), -- Forsaken Royal Dreadguard
(@CGUID+3, 0, 0, 0, 1, 333, ''), -- Forsaken Royal Dreadguard
(@CGUID+4, 0, 0, 0, 1, 333, ''), -- Forsaken Royal Dreadguard
(@CGUID+5, 0, 0, 0, 1, 333, ''), -- Forsaken Royal Dreadguard
(@CGUID+6, 0, 0, 0, 1, 333, ''), -- Forsaken Royal Dreadguard
(@CGUID+7, 0, 0, 0, 1, 0, '70628'), -- Forsaken Royal Dreadguard
(@CGUID+8, 0, 0, 0, 1, 333, ''), -- Forsaken Royal Dreadguard
(@CGUID+9, 0, 0, 0, 1, 333, ''), -- Forsaken Royal Dreadguard
(@CGUID+10, 0, 0, 0, 1, 333, ''), -- Forsaken Royal Dreadguard
(@CGUID+11, 0, 0, 0, 1, 333, ''), -- Forsaken Royal Dreadguard
(@CGUID+12, 0, 0, 0, 1, 0, '70628'), -- Forsaken Royal Dreadguard
(@CGUID+13, 0, 0, 0, 1, 333, ''), -- Forsaken Royal Dreadguard
(@CGUID+14, 0, 0, 0, 1, 333, ''), -- Forsaken Royal Dreadguard
(@CGUID+15, 0, 0, 0, 1, 0, '70628'), -- Forsaken Royal Dreadguard
(@CGUID+16, 0, 0, 0, 1, 333, ''), -- Forsaken Royal Dreadguard
(@CGUID+17, 0, 0, 0, 1, 0, '70628'), -- Forsaken Royal Dreadguard
(@CGUID+18, 0, 0, 0, 1, 333, ''), -- Forsaken Royal Dreadguard
(@CGUID+19, 0, 0, 0, 1, 0, '70628'), -- Forsaken Royal Dreadguard
(@CGUID+20, 0, 0, 0, 1, 0, '70628'), -- Forsaken Royal Dreadguard
(@CGUID+21, 0, 0, 0, 1, 0, '70628'), -- Forsaken Royal Dreadguard
(@CGUID+22, 0, 0, 0, 1, 0, '70628'), -- Forsaken Royal Dreadguard
(@CGUID+23, 0, 0, 0, 1, 0, '70628'), -- Forsaken Royal Dreadguard
(@CGUID+24, 0, 0, 0, 1, 0, '70628'), -- Forsaken Royal Dreadguard
(@CGUID+25, 0, 0, 0, 1, 0, '70628'), -- Forsaken Royal Dreadguard
(@CGUID+26, 0, 0, 0, 1, 0, '70628'), -- Forsaken Royal Dreadguard
(@CGUID+27, 0, 0, 0, 1, 0, '70628'), -- Forsaken Royal Dreadguard
(@CGUID+28, 0, 0, 0, 1, 0, '70628'), -- Forsaken Royal Dreadguard
(@CGUID+29, 0, 0, 0, 1, 0, '70628'), -- Forsaken Royal Dreadguard
(@CGUID+30, 0, 0, 0, 1, 0, '70628'), -- Forsaken Royal Dreadguard
(@CGUID+31, 0, 0, 0, 1, 0, '70628'), -- Forsaken Royal Dreadguard
(@CGUID+32, 0, 0, 0, 1, 0, '70628'), -- Forsaken Royal Dreadguard
(@CGUID+33, 0, 0, 0, 1, 0, '70628'), -- Forsaken Royal Dreadguard
(@CGUID+34, 0, 0, 0, 1, 0, '70628'), -- Forsaken Royal Dreadguard
(@CGUID+35, 0, 0, 0, 1, 0, '70628'), -- Forsaken Royal Dreadguard
--
(@CGUID+37, 0, 0, 0, 1, 0, ''), -- Dark Ranger Velonara
(@CGUID+38, 0, 0, 0, 1, 0, ''), -- Forsaken Royal Dreadguard
(@CGUID+39, 0, 0, 0, 1, 0, ''), -- Forsaken Royal Dreadguard
--
(@CGUID+40, 0, 0, 0, 1, 0, '58506'), -- Dark Ranger Velonara
(@CGUID+41, 0, 0, 0, 1, 333, '58506'), -- Forsaken Royal Dreadguard
(@CGUID+42, 0, 0, 0, 1, 333, '58506'), -- Forsaken Royal Dreadguard
(@CGUID+43, 0, 0, 0, 1, 333, '58506'), -- Forsaken Royal Dreadguard
(@CGUID+44, 0, 0, 0, 1, 333, '58506'), -- Forsaken Royal Dreadguard
(@CGUID+45, 0, 0, 0, 1, 333, '58506'), -- Forsaken Royal Dreadguard
-- 
(@CGUID+46, 0, 0, 0, 1, 468, ''), -- Dark Ranger Velonara
(@CGUID+47, 0, 0, 8, 1, 0, ''), -- Forsaken Royal Dreadguard
(@CGUID+48, 0, 0, 8, 1, 0, ''), -- Forsaken Royal Dreadguard
(@CGUID+49, 0, 0, 8, 1, 0, ''), -- Forsaken Royal Dreadguard
(@CGUID+50, 0, 0, 8, 1, 0, ''), -- Forsaken Royal Dreadguard
(@CGUID+51, 0, 0, 8, 1, 0, ''), -- Forsaken Royal Dreadguard
(@CGUID+52, 0, 0, 8, 1, 0, ''), -- Forsaken Royal Dreadguard
(@CGUID+53, 0, 0, 8, 1, 0, ''), -- Forsaken Royal Dreadguard
(@CGUID+54, 0, 0, 8, 1, 0, ''), -- Forsaken Royal Dreadguard
(@CGUID+55, 0, 0, 8, 1, 0, ''), -- Forsaken Royal Dreadguard
(@CGUID+56, 0, 0, 8, 1, 0, ''), -- Forsaken Royal Dreadguard
(@CGUID+57, 0, 0, 8, 1, 0, ''), -- Forsaken Royal Dreadguard
(@CGUID+58, 0, 0, 8, 1, 0, ''), -- Forsaken Royal Dreadguard
(@CGUID+59, 0, 0, 8, 1, 0, ''), -- Forsaken Royal Dreadguard
(@CGUID+60, 0, 0, 8, 1, 0, ''), -- Forsaken Royal Dreadguard
(@CGUID+61, 0, 0, 8, 1, 0, ''), -- Forsaken Royal Dreadguard
(@CGUID+62, 0, 0, 8, 1, 0, ''); -- Forsaken Royal Dreadguard

UPDATE `creature_template` SET `minlevel`= 36, `maxlevel`= 36, `unit_flags2`= 34816 WHERE `entry`= 44690;
UPDATE `creature_template` SET `minlevel`= 30, `maxlevel`= 30 WHERE `entry`= 44637;
UPDATE `creature_template` SET `minlevel`= 33, `maxlevel`= 33, `unit_flags`= 0x200 WHERE `entry`= 44691;
UPDATE `creature_template` SET `minlevel`= 33, `maxlevel`= 33, `unit_flags`= 768 WHERE `entry`= 44693;
UPDATE `creature_template` SET `minlevel`= 27, `maxlevel`= 27, `unit_flags`= 768 WHERE `entry`= 44655;
UPDATE `creature_template` SET `minlevel`=33, `maxlevel`=33, `unit_flags2`=34816 WHERE `entry`=44660;
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `unit_flags`=768 WHERE `entry`=44661;
UPDATE `creature_template` SET `minlevel`=39, `maxlevel`=39, `unit_flags2`=34816 WHERE `entry`=44706;
UPDATE `creature_template` SET `minlevel`=36, `maxlevel`=36, `faction`=2110, `unit_flags`=256 WHERE `entry`=44708;
UPDATE `creature_template` SET `minlevel`=36, `maxlevel`=36, `unit_flags`=768 WHERE `entry`=44707;

-- Pathing for  Entry: 44693 'TDB FORMAT' 
SET @NPC := @CGUID+36;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= 1624.61, `position_y`= -349.786, `position_z`= 18.00743 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 1624.61, -349.786, 18.00743, 0, 705, 0, 0, 100, 0),
(@PATH, 2, 1624.61, -340.92, 18.007425, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 1624.55, -334.894, 18.007444, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 1624.65, -330.012, 18.00749, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 1624.64, -324.502, 18.007498, 0, 721, 0, 0, 100, 0),
(@PATH, 6, 1624.65, -330.012, 18.00749, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 1624.55, -334.894, 18.007444, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 1624.61, -340.92, 18.007425, 0, 0, 0, 0, 100, 0);
-- 0xF130AE9500021F7A .go xyz 1624.61 -349.786 18.00743

-- Creature Dark Ranger Velonara 44660 SAI
SET @ENTRY := 44660;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 11, 32783, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Cast spell 32783 on Self // "),
(@ENTRY, 0, 1, 0, 19, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "When player accepts any quest - Action invoker: Talk 0 // ");

-- Creature Dark Ranger Velonara 44706 SAI
SET @ENTRY := 44706;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 11, 83413, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Cast spell 83413 on Self // ");

DELETE FROM `creature_text` WHERE `CreatureID` IN (44637, 44660);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(44637, 0, 0, 'I\'ll even get you started.', 12, 0, 100, 0, 0, 0, 44665, 'Dark Ranger Velonara to Player'),
(44660, 0, 0, 'Move quickly, $N. Your work will be for nothing if Mograine notices us before your work is done. ', 15, 0, 100, 0, 0, 0, 44728, 'Dark Ranger Velonara to Player');

DELETE FROM `spawn_group_template` WHERE `groupId`= 454;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(454, 'Scarlet Monastery - Horde Spawns', 4);

DELETE FROM `spawn_group` WHERE `groupId`= 454;
INSERT INTO `spawn_group` (`groupId`, `spawnType`,`spawnId`)
SELECT 454, 0, `guid` FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+66;

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId`= 454;
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
(189, 0, 1 | 2 | 4 | 8 | 16, 454, 0x1 | 0x8);

UPDATE `instance_spawn_groups` SET `bossStates`= 31 WHERE `spawnGroupId`= 453;

DELETE FROM `creature_sparring_template` WHERE `CreatureID`= 44708;
INSERT INTO `creature_sparring_template` (`CreatureID`, `HealthLimitPct`) VALUES
(44708, 100);

DELETE FROM `spawn_group` WHERE `spawnId` IN (40131, 40126, 39945, 39955, 39952, 39950, 39948);
INSERT INTO `spawn_group` (`groupId`, `spawnType`,`spawnId`) VALUES
(453, 0, 40131),
(453, 0, 40126),
(453, 0, 39945),
(453, 0, 39955),
(453, 0, 39952),
(453, 0, 39950),
(453, 0, 39948);

-- Fix some startup errors
DELETE FROM `creature_addon` WHERE `guid`= 40071;
DELETE FROM `npc_text` WHERE `ID` IN (12558, 14602, 15006, 15232, 15262, 18561);
INSERT INTO `npc_text` (`ID`, `text0_0`) VALUES
(12558, 'Missing npc_text'),
(14602, 'Missing npc_text'),
(15006, 'Missing npc_text'),
(15232, 'Missing npc_text'),
(15262, 'Missing npc_text'),
(18561, 'Missing npc_text');
