DELETE FROM `creature` WHERE `map`= 654;
DELETE FROM `gameobject` WHERE `map`= 654;
DELETE FROM `gameobject_addon` WHERE `guid` NOT IN (SELECT `guid` FROM `gameobject`);

SET @CGUID := 376242;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1226;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 35374, 654, 4755, 4756, 1, 169, 0, 0, 0, -1734.951, 1663.092, 20.56362, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Generic Trigger LAB - Multiphase (Area: Merchant Square - Difficulty: 0)
(@CGUID+1, 35374, 654, 4755, 4756, 1, 169, 0, 0, 0, -1617.578, 1531.641, 26.23375, 0.8203048, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Generic Trigger LAB - Multiphase (Area: Merchant Square - Difficulty: 0)
(@CGUID+2, 35317, 654, 4755, 4756, 1, 169, 0, 0, 0, -1549.41, 1595.73, 26.53588, 1.710423, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rebel Cannon (Area: Merchant Square - Difficulty: 0)
(@CGUID+3, 35374, 654, 4755, 4756, 1, 169, 0, 0, 0, -1425.078, 1409.701, 36.87229, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Generic Trigger LAB - Multiphase (Area: Merchant Square - Difficulty: 0)
(@CGUID+4, 34864, 654, 4755, 4756, 1, 169, 0, 0, 0, -1444.934, 1405.981, 35.63924, 3.159046, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+5, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1458.681, 1418.543, 35.63924, 1.029744, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+6, 35830, 654, 4755, 4756, 1, 169, 0, 0, 0, -1420.962, 1418.455, 35.63927, 3.246312, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas Evacuation Facing Marker (First) (Area: Merchant Square - Difficulty: 0)
(@CGUID+7, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1453.01, 1437.085, 35.94489, 5.096361, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+8, 35374, 654, 4755, 4756, 1, 169, 0, 0, 0, -1539.028, 1617.955, 20.56887, 5.67232, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Generic Trigger LAB - Multiphase (Area: Merchant Square - Difficulty: 0)
(@CGUID+9, 34864, 654, 4755, 4756, 1, 169, 0, 0, 0, -1441.104, 1413.96, 35.63924, 3.228859, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+10, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1470.285, 1384.361, 36.08721, 1.099557, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+11, 35374, 654, 4755, 4756, 1, 169, 0, 0, 0, -1566.795, 1555.3, 29.28475, 0.8203048, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Generic Trigger LAB - Multiphase (Area: Merchant Square - Difficulty: 0)
(@CGUID+12, 4075, 654, 4755, 4756, 1, 169, 0, 0, 0, -1490.295, 1424.214, 35.6809, 4.247014, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Merchant Square - Difficulty: 0)
(@CGUID+13, 34864, 654, 4755, 4756, 1, 169, 0, 0, 0, -1441.144, 1418.014, 35.63924, 3.263766, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+14, 35374, 654, 4755, 4756, 1, 169, 0, 0, 0, -1565.299, 1556.535, 29.28475, 5.5676, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Generic Trigger LAB - Multiphase (Area: Merchant Square - Difficulty: 0)
(@CGUID+15, 35010, 654, 4755, 4756, 1, 169, 0, 0, 0, -1475.002, 1426.059, 35.63924, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas Evacuation Facing Marker (Near) (Area: Merchant Square - Difficulty: 0)
(@CGUID+16, 34864, 654, 4755, 4756, 1, 169, 0, 0, 0, -1444.939, 1398.372, 35.63924, 3.124139, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+17, 35317, 654, 4755, 4756, 1, 169, 0, 0, 0, -1540.175, 1613.618, 20.56887, 0.6806784, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rebel Cannon (Area: Merchant Square - Difficulty: 0)
(@CGUID+18, 34864, 654, 4755, 4756, 1, 169, 0, 0, 0, -1441.21, 1405.986, 35.63924, 3.159046, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+19, 35010, 654, 4755, 4756, 1, 169, 0, 0, 0, -1437.25, 1420.738, 35.63927, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas Evacuation Facing Marker (Near) (Area: Merchant Square - Difficulty: 0)
(@CGUID+20, 34864, 654, 4755, 4756, 1, 169, 0, 0, 0, -1444.941, 1418, 35.63924, 3.263766, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+21, 35374, 654, 4755, 4756, 1, 169, 0, 0, 0, -1423.906, 1432.493, 36.50103, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Generic Trigger LAB - Multiphase (Area: Merchant Square - Difficulty: 0)
(@CGUID+22, 35317, 654, 4755, 4756, 1, 169, 0, 0, 0, -1528.205, 1588.418, 26.53708, 0.7990122, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rebel Cannon (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+23, 34864, 654, 4755, 4756, 1, 169, 0, 0, 0, -1444.915, 1410.274, 35.63924, 3.193953, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+24, 34850, 654, 4755, 4756, 1, 169, 0, 0, 0, -1447.979, 1407.352, 35.63924, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Prince Liam Greymane (Area: Merchant Square - Difficulty: 0)
(@CGUID+25, 6368, 654, 4755, 4756, 1, 169, 0, 0, 0, -1461.45, 1402.828, 37.74655, 0.2268928, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Cat (Area: Merchant Square - Difficulty: 0)
(@CGUID+26, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1545.081, 1640.24, 20.48777, 3.93261, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+27, 34864, 654, 4755, 4756, 1, 169, 0, 0, 0, -1444.622, 1402.186, 35.63924, 3.141593, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+28, 35317, 654, 4755, 4756, 1, 169, 0, 0, 0, -1517.84, 1603.986, 20.56887, 0.8028514, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rebel Cannon (Area: Merchant Square - Difficulty: 0)
(@CGUID+29, 35830, 654, 4755, 4756, 1, 169, 0, 0, 0, -1464.09, 1440.082, 36.0566, 4.625123, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas Evacuation Facing Marker (First) (Area: Merchant Square - Difficulty: 0)
(@CGUID+30, 35317, 654, 4755, 4756, 1, 169, 0, 0, 0, -1528.698, 1610.229, 20.56887, 1.064651, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rebel Cannon (Area: Merchant Square - Difficulty: 0)
(@CGUID+31, 34864, 654, 4755, 4756, 1, 169, 0, 0, 0, -1441.313, 1402.193, 35.63924, 3.141593, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+32, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1517.669, 1612.602, 20.4855, 4.776461, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+33, 35830, 654, 4755, 4756, 1, 169, 0, 0, 0, -1433.323, 1437.436, 35.95538, 3.089233, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas Evacuation Facing Marker (First) (Area: Merchant Square - Difficulty: 0)
(@CGUID+34, 34864, 654, 4755, 4756, 1, 169, 0, 0, 0, -1441.116, 1410.38, 35.63924, 3.193953, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+35, 35317, 654, 4755, 4756, 1, 169, 0, 0, 0, -1540.95, 1596.29, 26.53644, 1.562069, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rebel Cannon (Area: Merchant Square - Difficulty: 0)
(@CGUID+36, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1521.584, 1621.586, 20.6104, 0.8224227, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+37, 34864, 654, 4755, 4756, 1, 169, 0, 0, 0, -1441.002, 1397.965, 35.63926, 3.124139, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+38, 34864, 654, 4755, 4756, 1, 169, 0, 0, 0, -1444.95, 1414.047, 35.63924, 3.228859, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+39, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1522.868, 1680.894, 20.59014, 2.776726, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+40, 35317, 654, 4755, 4756, 1, 169, 0, 0, 0, -1533.46, 1591.96, 26.53648, 0.9442232, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rebel Cannon (Area: Merchant Square - Difficulty: 0)
(@CGUID+41, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1519.996, 1616.039, 20.61054, 0.9206055, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+42, 34867, 654, 4755, 4756, 1, 169, 0, 0, 0, -1421.56, 1386.36, 71.88338, 1.595842, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Shadowy Figure (Area: Merchant Square - Difficulty: 0) (Auras: 39662 - Vertex Color Black)
(@CGUID+43, 44086, 654, 4755, 4756, 1, 169, 0, 0, 0, -1430.37, 1353.85, 35.63923, 4.764749, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0)
(@CGUID+44, 44426, 654, 4755, 4756, 1, 169, 0, 0, 0, -1518.53, 1381.32, 36.52353, 1.570796, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frightened Chicken (Area: Merchant Square - Difficulty: 0)
(@CGUID+45, 35374, 654, 4755, 4756, 1, 169, 0, 0, 0, -1489.311, 1330.344, 36.56679, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Generic Trigger LAB - Multiphase (Area: Merchant Square - Difficulty: 0)
(@CGUID+46, 44086, 654, 4755, 4756, 1, 169, 0, 0, 0, -1432.97, 1352.17, 35.63923, 5.061455, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0)
(@CGUID+47, 44426, 654, 4755, 4756, 1, 169, 0, 0, 0, -1520.22, 1382.78, 36.08493, 1.570796, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frightened Chicken (Area: Merchant Square - Difficulty: 0)
(@CGUID+48, 35830, 654, 4755, 4756, 1, 169, 0, 0, 0, -1487.21, 1338.227, 35.63927, 3.246312, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas Evacuation Facing Marker (First) (Area: Merchant Square - Difficulty: 0)
(@CGUID+49, 35010, 654, 4755, 4756, 1, 169, 0, 0, 0, -1402.882, 1391.72, 35.63926, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas Evacuation Facing Marker (Near) (Area: Merchant Square - Difficulty: 0)
(@CGUID+50, 50260, 654, 4755, 4756, 1, 169, 0, 0, 0, -1403.392, 1444.313, 35.63926, 2.600541, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+51, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1506.026, 1416.773, 35.55592, 5.258136, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+52, 50260, 654, 4755, 4756, 1, 169, 0, 0, 0, -1403.54, 1446.675, 35.63926, 2.617994, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+53, 35374, 654, 4755, 4756, 1, 169, 0, 0, 0, -1533.911, 1447.528, 36.72313, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Generic Trigger LAB - Multiphase (Area: Merchant Square - Difficulty: 0)
(@CGUID+54, 44086, 654, 4755, 4756, 1, 169, 0, 0, 0, -1427.55, 1354.11, 35.63923, 4.520403, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0)
(@CGUID+55, 35374, 654, 4755, 4756, 1, 169, 0, 0, 0, -1490.538, 1367.53, 36.61352, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Generic Trigger LAB - Multiphase (Area: Merchant Square - Difficulty: 0)
(@CGUID+56, 50260, 654, 4755, 4756, 1, 169, 0, 0, 0, -1407.161, 1445.04, 35.63926, 4.118977, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+57, 44086, 654, 4755, 4756, 1, 169, 0, 0, 0, -1435.73, 1355.46, 35.63923, 5.148721, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0)
(@CGUID+58, 44086, 654, 4755, 4756, 1, 169, 0, 0, 0, -1435.15, 1352.44, 35.63923, 5.218534, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0)
(@CGUID+59, 34867, 654, 4755, 4756, 1, 169, 0, 0, 0, -1566.021, 1410.03, 71.13116, 0.1396263, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Shadowy Figure (Area: Merchant Square - Difficulty: 0) (Auras: 39662 - Vertex Color Black)
(@CGUID+60, 50260, 654, 4755, 4756, 1, 169, 0, 0, 0, -1407.205, 1441.679, 35.63926, 2.199115, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+61, 35374, 654, 4755, 4756, 1, 169, 0, 0, 0, -1459.776, 1447.688, 36.72193, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Generic Trigger LAB - Multiphase (Area: Merchant Square - Difficulty: 0)
(@CGUID+62, 35830, 654, 4755, 4756, 1, 169, 0, 0, 0, -1537.741, 1439.448, 36.03258, 4.625123, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas Evacuation Facing Marker (First) (Area: Merchant Square - Difficulty: 0)
(@CGUID+63, 44086, 654, 4755, 4756, 1, 169, 0, 0, 0, -1438.47, 1353.14, 35.63923, 5.427974, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0)
(@CGUID+64, 34867, 654, 4755, 4756, 1, 169, 0, 0, 0, -1506.928, 1321.813, 76.19249, 3.456795, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Shadowy Figure (Area: Merchant Square - Difficulty: 0) (Auras: 39662 - Vertex Color Black)
(@CGUID+65, 34863, 654, 4755, 4756, 1, 169, 0, 0, 0, -1405.486, 1447.415, 35.63926, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Lieutenant Walden (Area: Merchant Square - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+66, 35830, 654, 4755, 4756, 1, 169, 0, 0, 0, -1492.767, 1371.201, 36.62104, 3.246312, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas Evacuation Facing Marker (First) (Area: Merchant Square - Difficulty: 0)
(@CGUID+67, 50260, 654, 4755, 4756, 1, 169, 0, 0, 0, -1401.519, 1448.191, 35.63926, 4.782202, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+68, 34864, 654, 4755, 4756, 1, 169, 0, 0, 0, -1430.47, 1345.55, 35.57663, 1.780236, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+69, 34867, 654, 4755, 4756, 1, 169, 0, 0, 0, -1536.078, 1371.512, 60.56247, 1.553343, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Shadowy Figure (Area: Merchant Square - Difficulty: 0) (Auras: 39662 - Vertex Color Black)
(@CGUID+70, 39095, 654, 4755, 4756, 1, 169, 0, 0, 0, -1404.509, 1435.073, 35.63926, 3.804818, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Slain Guard (Area: Merchant Square - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+71, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1521.514, 1403.049, 35.63925, 4.520403, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+72, 50260, 654, 4755, 4756, 1, 169, 0, 0, 0, -1406.899, 1446.514, 35.63926, 0.6981317, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+73, 35830, 654, 4755, 4756, 1, 169, 0, 0, 0, -1398.88, 1403.543, 35.63926, 3.246312, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas Evacuation Facing Marker (First) (Area: Merchant Square - Difficulty: 0)
(@CGUID+74, 44426, 654, 4755, 4756, 1, 169, 0, 0, 0, -1529.61, 1380.22, 36.57993, 0.6632251, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frightened Chicken (Area: Merchant Square - Difficulty: 0)
(@CGUID+75, 35374, 654, 4755, 4756, 1, 169, 0, 0, 0, -1391.248, 1399.266, 36.50103, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Generic Trigger LAB - Multiphase (Area: Merchant Square - Difficulty: 0)
(@CGUID+76, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1517.184, 1358.682, 35.67543, 5.585053, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+77, 34867, 654, 4755, 4756, 1, 169, 0, 0, 0, -1420.476, 1425.659, 73.86883, 1.524312, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Shadowy Figure (Area: Merchant Square - Difficulty: 0) (Auras: 39662 - Vertex Color Black)
(@CGUID+78, 34867, 654, 4755, 4756, 1, 169, 0, 0, 0, -1421.443, 1380.905, 72.87177, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Shadowy Figure (Area: Merchant Square - Difficulty: 0) (Auras: 39662 - Vertex Color Black)
(@CGUID+79, 35010, 654, 4755, 4756, 1, 169, 0, 0, 0, -1546.288, 1408.818, 35.63925, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas Evacuation Facing Marker (Near) (Area: Merchant Square - Difficulty: 0)
(@CGUID+80, 50260, 654, 4755, 4756, 1, 169, 0, 0, 0, -1405.477, 1444.845, 35.63926, 4.834562, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+81, 34867, 654, 4755, 4756, 1, 169, 0, 0, 0, -1531.319, 1370.038, 71.83533, 2.199115, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Shadowy Figure (Area: Merchant Square - Difficulty: 0) (Auras: 39662 - Vertex Color Black)
(@CGUID+82, 44086, 654, 4755, 4756, 1, 169, 0, 0, 0, -1432.83, 1354.98, 35.63923, 4.956735, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0)
(@CGUID+83, 4075, 654, 4755, 4756, 1, 169, 0, 0, 0, -1541.412, 1411.171, 35.67107, 1.285822, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Merchant Square - Difficulty: 0)
(@CGUID+84, 35374, 654, 4755, 4756, 1, 169, 0, 0, 0, -1516.33, 1375.245, 36.6125, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Generic Trigger LAB - Multiphase (Area: Merchant Square - Difficulty: 0)
(@CGUID+85, 34867, 654, 4755, 4756, 1, 169, 0, 0, 0, -1387.781, 1394.849, 72.97905, 1.500983, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Shadowy Figure (Area: Merchant Square - Difficulty: 0) (Auras: 39662 - Vertex Color Black)
(@CGUID+86, 44086, 654, 4755, 4756, 1, 169, 0, 0, 0, -1431.38, 1356.77, 35.63923, 4.834562, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0)
(@CGUID+87, 44426, 654, 4755, 4756, 1, 169, 0, 0, 0, -1522.18, 1381.2, 37.18743, 1.570796, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frightened Chicken (Area: Merchant Square - Difficulty: 0)
(@CGUID+88, 6368, 654, 4755, 4756, 1, 169, 0, 0, 0, -1530.689, 1383.311, 40.11686, 0.4712389, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Cat (Area: Merchant Square - Difficulty: 0)
(@CGUID+89, 35010, 654, 4755, 4756, 1, 169, 0, 0, 0, -1495.502, 1340.696, 35.63927, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas Evacuation Facing Marker (Near) (Area: Merchant Square - Difficulty: 0)
(@CGUID+90, 50260, 654, 4755, 4756, 1, 169, 0, 0, 0, -1408.594, 1443.686, 36.09393, 0.7504916, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+91, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1511.776, 1382.741, 35.95466, 1.099557, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+92, 34867, 654, 4755, 4756, 1, 169, 0, 0, 0, -1464.899, 1450.804, 71.7703, 6.257058, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Shadowy Figure (Area: Merchant Square - Difficulty: 0) (Auras: 39662 - Vertex Color Black)
(@CGUID+93, 44086, 654, 4755, 4756, 1, 169, 0, 0, 0, -1437.52, 1350.65, 35.63923, 5.410521, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0)
(@CGUID+94, 39095, 654, 4755, 4756, 1, 169, 0, 0, 0, -1396.684, 1445.738, 36.04398, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Slain Guard (Area: Merchant Square - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+95, 34867, 654, 4755, 4756, 1, 169, 0, 0, 0, -1446.231, 1340.991, 71.15733, 1.857003, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Shadowy Figure (Area: Merchant Square - Difficulty: 0) (Auras: 39662 - Vertex Color Black)
(@CGUID+96, 44086, 654, 4755, 4756, 1, 169, 0, 0, 0, -1428.64, 1356.64, 35.63923, 4.625123, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0)
(@CGUID+97, 35006, 654, 4755, 4756, 1, 169, 0, 0, 0, -1401.517, 1368.231, 35.63927, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas Market Evacuation Credit (Area: Merchant Square - Difficulty: 0)
(@CGUID+98, 44426, 654, 4755, 4756, 1, 169, 0, 0, 0, -1516.56, 1381.3, 36.48103, 1.570796, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frightened Chicken (Area: Merchant Square - Difficulty: 0)
(@CGUID+99, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1510.833, 1437.731, 35.94954, 5.532694, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+100, 35830, 654, 4755, 4756, 1, 169, 0, 0, 0, -1507.766, 1370.988, 35.63925, 6.230825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas Evacuation Facing Marker (First) (Area: Merchant Square - Difficulty: 0)
(@CGUID+101, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1538.72, 1390.661, 35.55592, 0.005486719, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+102, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1476.811, 1439.623, 35.63926, 3.714623, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+103, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1398.113, 1431.059, 35.63926, 3.478062, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+104, 4075, 654, 4755, 4756, 1, 169, 0, 0, 0, -1527.604, 1439.422, 35.95203, 5.445497, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Merchant Square - Difficulty: 0)
(@CGUID+105, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1530.157, 1389.502, 35.55592, 0.1329265, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+106, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1464.753, 1505.498, 20.74778, 0.5018748, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower) (possible waypoints or random movement)
(@CGUID+107, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1432.875, 1431.646, 35.63927, 3.390748, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+108, 35374, 654, 4755, 4756, 1, 169, 0, 0, 0, -1566.311, 1413.51, 36.72263, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Generic Trigger LAB - Multiphase (Area: Merchant Square - Difficulty: 0)
(@CGUID+109, 35830, 654, 4755, 4756, 1, 169, 0, 0, 0, -1558.247, 1409.644, 36.00442, 0.122173, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas Evacuation Facing Marker (First) (Area: Merchant Square - Difficulty: 0)
(@CGUID+110, 35010, 654, 4755, 4756, 1, 169, 0, 0, 0, -1552.142, 1394.392, 35.63925, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas Evacuation Facing Marker (Near) (Area: Merchant Square - Difficulty: 0)
(@CGUID+111, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1475.917, 1355.622, 35.63927, 5.878766, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+112, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1559.502, 1384.313, 36.2494, 0.5759587, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+113, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1559, 1419.451, 35.79858, 5.532694, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+114, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1517.184, 1358.682, 35.67543, 4.704118, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+115, 35374, 654, 4755, 4756, 1, 169, 0, 0, 0, -1573.932, 1381.87, 37.07738, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Generic Trigger LAB - Multiphase (Area: Merchant Square - Difficulty: 0)
(@CGUID+116, 35011, 654, 4755, 4756, 1, 169, 0, 0, 0, -1570.665, 1322.703, 35.63926, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas Evacuation Facing Marker (Far) (Area: Merchant Square - Difficulty: 0)
(@CGUID+117, 35374, 654, 4755, 4756, 1, 169, 0, 0, 0, -1579.764, 1339.984, 36.61267, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Generic Trigger LAB - Multiphase (Area: Merchant Square - Difficulty: 0)
(@CGUID+118, 35830, 654, 4755, 4756, 1, 169, 0, 0, 0, -1530.535, 1326.66, 35.63927, 3.246312, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas Evacuation Facing Marker (First) (Area: Merchant Square - Difficulty: 0)
(@CGUID+119, 35830, 654, 4755, 4756, 1, 169, 0, 0, 0, -1569.372, 1388.644, 36.50435, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas Evacuation Facing Marker (First) (Area: Merchant Square - Difficulty: 0)
(@CGUID+120, 35830, 654, 4755, 4756, 1, 169, 0, 0, 0, -1571.861, 1335.837, 35.70319, 3.246312, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas Evacuation Facing Marker (First) (Area: Merchant Square - Difficulty: 0)
(@CGUID+121, 35374, 654, 4755, 4756, 1, 169, 0, 0, 0, -1531.887, 1318.653, 36.66387, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Generic Trigger LAB - Multiphase (Area: Merchant Square - Difficulty: 0)
(@CGUID+122, 4075, 654, 4755, 4756, 1, 169, 0, 0, 0, -1563.413, 1319.129, 35.61959, 0.3532892, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Merchant Square - Difficulty: 0)
(@CGUID+123, 35374, 654, 4755, 4756, 1, 169, 0, 0, 0, -1587.821, 1356.023, 36.61205, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Generic Trigger LAB - Multiphase (Area: Merchant Square - Difficulty: 0)
(@CGUID+124, 35830, 654, 4755, 4756, 1, 169, 0, 0, 0, -1583.439, 1363.099, 35.73989, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas Evacuation Facing Marker (First) (Area: Merchant Square - Difficulty: 0)
(@CGUID+125, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1566.021, 1390.835, 36.08628, 3.410385, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+126, 35830, 654, 4755, 4756, 1, 169, 0, 0, 0, -1551.714, 1308.932, 35.9628, 3.385939, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas Evacuation Facing Marker (First) (Area: Merchant Square - Difficulty: 0)
(@CGUID+127, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1545.533, 1436.92, 35.8738, 5.710992, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+128, 35374, 654, 4755, 4756, 1, 169, 0, 0, 0, -1545.368, 1306.566, 36.50438, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Generic Trigger LAB - Multiphase (Area: Merchant Square - Difficulty: 0)
(@CGUID+129, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1557.66, 1333.977, 35.63924, 1.756745, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+130, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1501.219, 1424.144, 35.55591, 3.531477, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+131, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1432.875, 1431.646, 35.63927, 3.390748, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+132, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1398.113, 1431.059, 35.63926, 3.176499, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+133, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1475.917, 1355.622, 35.63927, 5.878766, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower)
(@CGUID+134, 34851, 654, 4755, 4756, 1, 169, 0, 0, 0, -1464.249, 1509.075, 21.07458, 5.491656, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Panicked Citizen (Area: Merchant Square - Difficulty: 0) (Auras: 52385 - Cosmetic - Periodic Cower) (possible waypoints or random movement)
(@CGUID+135, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1411.623, 1379.29, 35.99875, 0.08382688, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+136, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1544.979, 1428.746, 35.67107, 2.410889, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+137, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1459.328, 1427.792, 35.68091, 2.618594, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+138, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1562.182, 1340.674, 35.68091, 1.011261, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+139, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1511.999, 1339.039, 35.68091, 4.364907, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+140, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1490.471, 1403.829, 35.6809, 0.108385, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+141, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1462.993, 1427.874, 35.68091, 6.261045, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+142, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1520.884, 1382.729, 36.08524, 4.468043, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+143, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1527.523, 1354.498, 36.05591, 5.903816, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+144, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1470.778, 1441.059, 36.3436, 2.600541, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+145, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1462.504, 1429.624, 35.68091, 3.402726, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+146, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1509.267, 1396.259, 35.68091, 2.253919, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+147, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1437.901, 1395.618, 35.68091, 3.874631, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+148, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1571.26, 1362.925, 35.90884, 1.977821, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+149, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1438.052, 1355.324, 35.65739, 5.395221, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+150, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1454.704, 1397.945, 35.68091, 2.627764, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+151, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1488.574, 1407.449, 35.6809, 5.209097, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+152, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1470.932, 1383.085, 36.0872, 4.118977, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+153, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1538.002, 1336.111, 35.68091, 6.273883, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+154, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1483.571, 1402.54, 35.6809, 2.663725, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+155, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1437.842, 1397.483, 35.68091, 1.601698, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (Auras: 8599 - Enrage)
(@CGUID+156, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1478.35, 1344.564, 35.68091, 1.843216, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+157, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1503.202, 1347.594, 35.68091, 1.716386, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+158, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1569.121, 1364.976, 35.83338, 5.934, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+159, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1518.033, 1397.408, 35.68091, 3.924403, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+160, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1404.842, 1379.777, 35.68092, 3.198992, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+161, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1437.861, 1391.952, 35.68091, 1.581783, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+162, 34936, 654, 4755, 4756, 1, 170, 0, 0, 0, -1465.224, 1403.517, 35.63924, 4.590216, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gwen Armstead (Area: Merchant Square - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1)
(@CGUID+163, 4075, 654, 4755, 4756, 1, 170, 0, 0, 0, -1487.394, 1435.067, 35.74765, 6.266773, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Merchant Square - Difficulty: 0)
(@CGUID+164, 34913, 654, 4755, 4756, 1, 170, 0, 0, 0, -1437.955, 1401.148, 35.63927, 3.559063, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Prince Liam Greymane (Area: Merchant Square - Difficulty: 0)
(@CGUID+165, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1528.881, 1396.515, 35.68091, 2.905208, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+166, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1569.989, 1363.836, 35.91072, 2.407679, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+167, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1407.969, 1379.597, 35.99876, 0.05827284, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+168, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1502.964, 1379.617, 35.68091, 0.3837707, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+169, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1441.501, 1391.511, 35.68091, 0.1203412, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+170, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1500.891, 1377.572, 35.68091, 1.200417, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+171, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1496.102, 1450.55, 71.45199, 4.813382, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+172, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1569.1, 1366.922, 35.98795, 3.314257, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+173, 50260, 654, 4755, 4756, 1, 170, 0, 0, 0, -1405.453, 1442.995, 35.63926, 0.05235988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+174, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1436.949, 1401.039, 35.68091, 4.466555, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+175, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1437.937, 1355.966, 35.65739, 3.086175, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+176, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1569.545, 1364.445, 35.84069, 2.613681, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+177, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1459.488, 1386.6, 36.006, 1.416546, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+178, 4075, 654, 4755, 4756, 1, 170, 0, 0, 0, -1409.747, 1431.328, 35.80848, 1.434918, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Merchant Square - Difficulty: 0)
(@CGUID+179, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1555.162, 1352.488, 35.68091, 2.187409, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+180, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1532.05, 1344.733, 35.68091, 0.1200156, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+181, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1540.104, 1426.833, 35.67107, 4.147413, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+182, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1525.883, 1396.422, 35.68091, 5.695255, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+183, 44426, 654, 4755, 4756, 1, 170, 0, 0, 0, -1512.604, 1381.182, 35.94044, 3.632241, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frightened Chicken (Area: Merchant Square - Difficulty: 0)
(@CGUID+184, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1523.613, 1399.309, 35.68091, 5.176178, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+185, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1524.862, 1400.903, 35.67238, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+186, 4075, 654, 4755, 4756, 1, 170, 0, 0, 0, -1481.881, 1348.072, 35.68091, 0.2636206, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Merchant Square - Difficulty: 0)
(@CGUID+187, 44426, 654, 4755, 4756, 1, 170, 0, 0, 0, -1514.827, 1383.181, 35.99901, 0.1841887, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frightened Chicken (Area: Merchant Square - Difficulty: 0)
(@CGUID+188, 44426, 654, 4755, 4756, 1, 170, 0, 0, 0, -1519.631, 1385.293, 36.00101, 0.4849597, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frightened Chicken (Area: Merchant Square - Difficulty: 0)
(@CGUID+189, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1503.177, 1380.439, 35.68091, 5.385518, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+190, 44426, 654, 4755, 4756, 1, 170, 0, 0, 0, -1528.125, 1382.695, 36.00388, 2.699286, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frightened Chicken (Area: Merchant Square - Difficulty: 0)
(@CGUID+191, 44426, 654, 4755, 4756, 1, 170, 0, 0, 0, -1517.668, 1384.143, 36.00019, 0.566143, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frightened Chicken (Area: Merchant Square - Difficulty: 0)
(@CGUID+192, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1503.541, 1383.238, 35.68091, 4.870417, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+193, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1505.046, 1382.635, 35.68091, 5.316182, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+194, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1503.827, 1383.18, 35.68091, 4.950028, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+195, 44426, 654, 4755, 4756, 1, 170, 0, 0, 0, -1513.84, 1384.72, 35.97263, 6.141618, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frightened Chicken (Area: Merchant Square - Difficulty: 0)
(@CGUID+196, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1502.522, 1380.856, 35.68091, 5.173283, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+197, 44426, 654, 4755, 4756, 1, 170, 0, 0, 0, -1524.035, 1380.907, 37.04765, 3.426318, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frightened Chicken (Area: Merchant Square - Difficulty: 0)
(@CGUID+198, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1499.564, 1380.99, 35.63924, 1.466077, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+199, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1571.531, 1409.302, 71.54961, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+200, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1565.527, 1367.742, 36.05777, 3.367269, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+201, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1555.116, 1406.403, 35.63925, 0.4363323, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+202, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1569.828, 1359.559, 35.66602, 1.973129, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+203, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1568.777, 1360.378, 35.7738, 1.907929, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+204, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1572.712, 1366.292, 35.93214, 6.002982, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+205, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1568.423, 1360.955, 35.7741, 1.881922, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+206, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1568.137, 1363.385, 35.86844, 1.836628, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+207, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1568.777, 1360.378, 35.7738, 1.907929, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+208, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1569.952, 1359.508, 35.66602, 1.936406, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+209, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1568.777, 1360.378, 35.7738, 1.907929, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+210, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1569.952, 1359.508, 35.66602, 1.936406, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+211, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1568.423, 1360.955, 35.7741, 1.881922, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+212, 34916, 654, 4755, 4756, 1, 170, 0, 0, 0, -1568.423, 1360.955, 35.7741, 1.881922, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+213, 35456, 654, 4755, 4756, 1, 170, 0, 0, 0, -1611.757, 1493.896, 67.43678, 3.636799, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Merchant Square - Difficulty: 0)
(@CGUID+214, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1497.306, 1439.811, 36.05542, 0.8203048, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+215, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1572.33, 1441.46, 71.89567, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+216, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1492.047, 1434.349, 35.78022, 6.108652, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+217, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1522.747, 1458.594, 63.98261, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+218, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1441.899, 1450.797, 71.41571, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+219, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1490.005, 1370.417, 71.98634, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+220, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1576.019, 1377.854, 71.78739, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+221, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1387.137, 1385.486, 64.50874, 3.647738, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+222, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1539.394, 1370.75, 63.33633, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+223, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1371.455, 1346.75, 36.23652, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+224, 35456, 654, 4755, 4756, 1, 170, 0, 0, 0, -1671.273, 1396.834, 52.28713, 2.120071, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Worgen Runt (Area: Merchant Square - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+225, 35456, 654, 4755, 4756, 1, 170, 0, 0, 0, -1677.784, 1446.555, 52.28713, 4.632704, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+226, 35457, 654, 4755, 4756, 1, 170, 0, 0, 0, -1680.415, 1445.724, 52.28713, 4.899159, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Bloodletter (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+227, 50260, 654, 4755, 4756, 1, 170, 0, 0, 0, -1614.557, 1313.599, 18.88782, 2.617994, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+228, 50260, 654, 4755, 4756, 1, 170, 0, 0, 0, -1612.536, 1315.115, 18.51861, 4.782202, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+229, 50260, 654, 4755, 4756, 1, 170, 0, 0, 0, -1616.495, 1311.769, 19.28115, 4.834562, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+230, 50260, 654, 4755, 4756, 1, 170, 0, 0, 0, -1614.41, 1311.236, 18.92509, 2.600541, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+231, 50260, 654, 4755, 4756, 1, 170, 0, 0, 0, -1620.339, 1311.874, 21.43651, 3.183164, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+232, 50260, 654, 4755, 4756, 1, 170, 0, 0, 0, -1620.076, 1313.175, 21.32948, 3.262381, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+233, 50260, 654, 4755, 4756, 1, 170, 0, 0, 0, -1618.142, 1311.979, 21.86692, 0.7504916, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+234, 50260, 654, 4755, 4756, 1, 170, 0, 0, 0, -1620.374, 1308.914, 21.5301, 2.997874, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+235, 50260, 654, 4755, 4756, 1, 170, 0, 0, 0, -1614.464, 1310.024, 21.34093, 0.05236621, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+236, 35233, 654, 4755, 4756, 1, 170, 0, 0, 0, -1634.908, 1311.217, 19.7658, 4.921828, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Survivor (Area: Merchant Square - Difficulty: 0)
(@CGUID+237, 4075, 654, 4755, 4756, 1, 170, 0, 0, 0, -1635.938, 1328.867, 19.88487, 4.712389, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Merchant Square - Difficulty: 0)
(@CGUID+238, 35233, 654, 4755, 4756, 1, 170, 0, 0, 0, -1634.498, 1306.882, 19.7463, 5.462881, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Survivor (Area: Merchant Square - Difficulty: 0)
(@CGUID+239, 38853, 654, 4755, 4756, 1, 170, 0, 0, 0, -1634.16, 1301.483, 19.7463, 2.286381, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Marie Allen (Area: Merchant Square - Difficulty: 0)
(@CGUID+240, 35840, 654, 4755, 4756, 1, 170, 0, 0, 0, -1633.137, 1303.786, 19.7463, 3.333579, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gwen Armstead (Area: Merchant Square - Difficulty: 0)
(@CGUID+241, 35233, 654, 4755, 4756, 1, 170, 0, 0, 0, -1637.024, 1305.241, 19.7463, 5.759586, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Survivor (Area: Merchant Square - Difficulty: 0)
(@CGUID+242, 35233, 654, 4755, 4756, 1, 170, 0, 0, 0, -1634.955, 1300.274, 20.36875, 1.204277, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Survivor (Area: Merchant Square - Difficulty: 0)
(@CGUID+243, 4075, 654, 4755, 4756, 1, 170, 0, 0, 0, -1650.648, 1305.062, 19.86187, 6.276712, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Merchant Square - Difficulty: 0)
(@CGUID+244, 35118, 654, 4755, 4756, 1, 170, 0, 0, 0, -1663.002, 1345.666, 15.25987, 2.003033, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Merchant Square - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer) (possible waypoints or random movement)
(@CGUID+245, 35118, 654, 4755, 4756, 1, 170, 0, 0, 0, -1654.24, 1382.9, 15.69825, 1.398736, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Merchant Square - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer) (possible waypoints or random movement)
(@CGUID+246, 35118, 654, 4755, 4756, 1, 170, 0, 0, 0, -1681.47, 1348.348, 15.25987, 4.675255, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Merchant Square - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer) (possible waypoints or random movement)
(@CGUID+247, 4075, 654, 4755, 4756, 1, 170, 0, 0, 0, -1687.852, 1344.949, 15.25987, 0.2024606, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Merchant Square - Difficulty: 0)
(@CGUID+248, 35872, 654, 4755, 4756, 1, 170, 0, 0, 0, -1690.356, 1328.24, 16.33291, 1.448623, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Myriam Spellwaker (Area: Merchant Square - Difficulty: 0)
(@CGUID+249, 51947, 654, 4755, 4756, 1, 170, 0, 0, 0, -1673.247, 1313.538, 20.37605, 3.75902, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383); -- Gilnean Steed (Area: Merchant Square - Difficulty: 0)

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+250, 35874, 654, 4755, 4756, 1, 170, 0, 0, 0, -1670.313, 1297.233, 21.33171, 5.88176, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Huntsman Blake (Area: Merchant Square - Difficulty: 0)
(@CGUID+251, 47091, 654, 4755, 4756, 1, 170, 0, 0, 0, -1682.102, 1312.526, 20.36353, 4.031711, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Wounded Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+252, 35869, 654, 4755, 4756, 1, 170, 0, 0, 0, -1688.852, 1297.922, 20.3675, 1.605703, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Vitus Darkwalker (Area: Merchant Square - Difficulty: 0) (Auras: 45104 - Shadow Channelling)
(@CGUID+253, 35870, 654, 4755, 4756, 1, 170, 0, 0, 0, -1695.432, 1306.851, 19.86565, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Sister Almyra (Area: Merchant Square - Difficulty: 0)
(@CGUID+254, 35118, 654, 4755, 4756, 1, 170, 0, 0, 0, -1684.968, 1334.247, 15.50245, 3.763325, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Merchant Square - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
-- (@CGUID+255, 68993, 654, 4755, 4756, 1, 170, 0, 0, 0, -1675.292, 1312.405, 20.37601, 0.6372635, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Fenegan Cobbler (Area: Merchant Square - Difficulty: 0)
(@CGUID+256, 35912, 654, 4755, 4756, 1, 170, 0, 0, 0, -1695.146, 1308.727, 19.86565, 4.014257, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Injured Citizen (Area: Merchant Square - Difficulty: 0)
(@CGUID+257, 35118, 654, 4755, 4756, 1, 170, 0, 0, 0, -1671.831, 1371.134, 15.34935, 3.195228, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Merchant Square - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer) (possible waypoints or random movement)
(@CGUID+258, 35118, 654, 4755, 4756, 1, 170, 0, 0, 0, -1686.677, 1335.55, 15.25987, 4.358563, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Merchant Square - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+259, 35839, 654, 4755, 4756, 1, 170, 0, 0, 0, -1687.948, 1332.111, 15.2182, 1.343904, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Sergeant Cleese (Area: Merchant Square - Difficulty: 0)
(@CGUID+260, 35118, 654, 4755, 4756, 1, 170, 0, 0, 0, -1688.573, 1335.724, 15.25987, 3.102018, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Merchant Square - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+261, 38832, 654, 4755, 4756, 1, 170, 0, 0, 0, -1669.259, 1299.177, 20.36763, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Baron (Area: Merchant Square - Difficulty: 0)
(@CGUID+262, 35118, 654, 4755, 4756, 1, 170, 0, 0, 0, -1685.416, 1334.896, 15.25987, 3.974637, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Merchant Square - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+263, 35873, 654, 4755, 4756, 1, 170, 0, 0, 0, -1697.469, 1308.936, 19.86565, 6.143559, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Celestine of the Harvest (Area: Merchant Square - Difficulty: 0) (Auras: 13236 - Nature Channeling)
(@CGUID+264, 35871, 654, 4755, 4756, 1, 170, 0, 0, 0, -1696.627, 1298.148, 20.36746, 2.234021, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Loren the Fence (Area: Merchant Square - Difficulty: 0) (Auras: 34189 - Stealth)
(@CGUID+265, 47091, 654, 4755, 4756, 1, 170, 0, 0, 0, -1701.379, 1301.646, 20.36758, 0.6457718, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Wounded Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+266, 47091, 654, 4755, 4756, 1, 170, 0, 0, 0, -1701.472, 1315.807, 20.37346, 5.602507, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Wounded Guard (Area: Merchant Square - Difficulty: 0)
(@CGUID+267, 39095, 654, 4755, 0, 1, 170, 0, 0, 0, -1686.365, 1381.307, 52.37962, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Slain Guard (Area: 0 - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+268, 35118, 654, 4755, 0, 1, 170, 0, 0, 0, -1683.859, 1377.537, 52.30361, 4.699296, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: 0 - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer) (possible waypoints or random movement)
(@CGUID+269, 47091, 654, 4755, 0, 1, 170, 0, 0, 0, -1705.064, 1305.964, 19.86565, 0.2268928, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Wounded Guard (Area: 0 - Difficulty: 0)
(@CGUID+270, 35232, 654, 4755, 4757, 1, 170, 0, 0, 0, -1715.443, 1359.477, 19.92279, 5.218534, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Royal Guard (Area: Military District - Difficulty: 0)
(@CGUID+271, 39095, 654, 4755, 4757, 1, 170, 0, 0, 0, -1701.415, 1378.955, 23.04241, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Slain Guard (Area: Military District - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+272, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1700.557, 1383.612, 22.57896, 0.4822469, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+273, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1702.098, 1382.846, 22.70604, 1.771977, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+274, 35232, 654, 4755, 4757, 1, 170, 0, 0, 0, -1702.806, 1386.316, 21.75196, 4.91357, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Royal Guard (Area: Military District - Difficulty: 0)
(@CGUID+275, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1698.959, 1386.979, 21.72435, 3.312145, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+276, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1685.607, 1405.381, 21.75987, 1.636262, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+277, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1736.975, 1358.908, 19.91482, 3.054724, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0)
(@CGUID+278, 35232, 654, 4755, 4757, 1, 170, 0, 0, 0, -1685.846, 1409.039, 21.75987, 4.642576, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Royal Guard (Area: Military District - Difficulty: 0)
(@CGUID+279, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1726.121, 1391.939, 21.52553, 4.081202, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0)
(@CGUID+280, 35232, 654, 4755, 4757, 1, 170, 0, 0, 0, -1701.22, 1405.007, 21.75196, 6.021386, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Royal Guard (Area: Military District - Difficulty: 0)
(@CGUID+281, 35233, 654, 4755, 4757, 1, 170, 0, 0, 0, -1758.411, 1338.688, 19.94407, 2.286381, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Survivor (Area: Military District - Difficulty: 0)
(@CGUID+282, 35232, 654, 4755, 4757, 1, 170, 0, 0, 0, -1729.486, 1384.931, 20.06848, 0.5469471, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Royal Guard (Area: Military District - Difficulty: 0)
(@CGUID+283, 35233, 654, 4755, 4757, 1, 170, 0, 0, 0, -1761.031, 1336.861, 20.02162, 1.797689, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Survivor (Area: Military District - Difficulty: 0)
(@CGUID+284, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1738.293, 1377.038, 19.86756, 3.933294, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0)
(@CGUID+285, 35233, 654, 4755, 4757, 1, 170, 0, 0, 0, -1760.655, 1338.832, 19.98563, 2.199115, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Survivor (Area: Military District - Difficulty: 0)
(@CGUID+286, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1726.737, 1392.283, 21.53432, 4.275197, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0)
(@CGUID+287, 35232, 654, 4755, 4757, 1, 170, 0, 0, 0, -1737.245, 1392.142, 19.97222, 0.8856892, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Royal Guard (Area: Military District - Difficulty: 0)
(@CGUID+288, 35232, 654, 4755, 4757, 1, 170, 0, 0, 0, -1769.642, 1340.62, 20.04936, 0.8203048, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Royal Guard (Area: Military District - Difficulty: 0)
(@CGUID+289, 35232, 654, 4755, 4757, 1, 170, 0, 0, 0, -1768.514, 1342.24, 19.96984, 0.8203048, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Royal Guard (Area: Military District - Difficulty: 0)
(@CGUID+290, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1726.369, 1392.094, 21.53286, 4.161312, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+291, 35232, 654, 4755, 4757, 1, 170, 0, 0, 0, -1768.682, 1345.535, 19.92146, 0.8203048, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Royal Guard (Area: Military District - Difficulty: 0)
(@CGUID+292, 4075, 654, 4755, 4757, 1, 170, 0, 0, 0, -1747.624, 1377.837, 20.04159, 0.238745, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Military District - Difficulty: 0)
(@CGUID+293, 35112, 654, 4755, 4757, 1, 170, 0, 0, 0, -1767.661, 1347.892, 19.97346, 0.9773844, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- King Genn Greymane (Area: Military District - Difficulty: 0)
(@CGUID+294, 35115, 654, 4755, 4757, 1, 170, 0, 0, 0, -1767.094, 1352.62, 20.00146, 5.148721, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Lord Godfrey (Area: Military District - Difficulty: 0)
(@CGUID+295, 4075, 654, 4755, 4757, 1, 170, 0, 0, 0, -1697.96, 1409.813, 21.75987, 1.351309, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Military District - Difficulty: 0)
(@CGUID+296, 35232, 654, 4755, 4757, 1, 170, 0, 0, 0, -1767.078, 1343.66, 19.92292, 0.8203048, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Royal Guard (Area: Military District - Difficulty: 0)
(@CGUID+297, 35232, 654, 4755, 4757, 1, 170, 0, 0, 0, -1725.832, 1392.89, 21.78212, 4.15907, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Royal Guard (Area: Military District - Difficulty: 0)
(@CGUID+298, 35233, 654, 4755, 4757, 1, 170, 0, 0, 0, -1764.774, 1340.016, 19.96545, 1.692969, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Survivor (Area: Military District - Difficulty: 0)
(@CGUID+299, 35232, 654, 4755, 4757, 1, 170, 0, 0, 0, -1770.201, 1343.783, 19.97769, 0.8203048, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Royal Guard (Area: Military District - Difficulty: 0)
(@CGUID+300, 35233, 654, 4755, 4757, 1, 170, 0, 0, 0, -1775.906, 1351.906, 19.9379, 5.654867, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Survivor (Area: Military District - Difficulty: 0)
(@CGUID+301, 35233, 654, 4755, 4757, 1, 170, 0, 0, 0, -1771.661, 1351.129, 19.86565, 5.654867, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Survivor (Area: Military District - Difficulty: 0)
(@CGUID+302, 35233, 654, 4755, 4757, 1, 170, 0, 0, 0, -1774.109, 1353.189, 19.84836, 4.817109, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Survivor (Area: Military District - Difficulty: 0)
(@CGUID+303, 35233, 654, 4755, 4757, 1, 170, 0, 0, 0, -1766.576, 1362.365, 19.79161, 5.654867, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Survivor (Area: Military District - Difficulty: 0)
(@CGUID+304, 35232, 654, 4755, 4757, 1, 170, 0, 0, 0, -1770.465, 1346.887, 19.89095, 0.8203048, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Royal Guard (Area: Military District - Difficulty: 0)
(@CGUID+305, 35233, 654, 4755, 4757, 1, 170, 0, 0, 0, -1777.217, 1343.545, 19.88775, 0.6806784, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Survivor (Area: Military District - Difficulty: 0)
(@CGUID+306, 35232, 654, 4755, 4757, 1, 170, 0, 0, 0, -1771.806, 1345.877, 19.87305, 0.8203048, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Royal Guard (Area: Military District - Difficulty: 0)
(@CGUID+307, 35232, 654, 4755, 4757, 1, 170, 0, 0, 0, -1773.55, 1344.495, 19.86592, 0.8203048, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Royal Guard (Area: Military District - Difficulty: 0)
(@CGUID+308, 35233, 654, 4755, 4757, 1, 170, 0, 0, 0, -1778.993, 1342.891, 19.90075, 0.541052, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Survivor (Area: Military District - Difficulty: 0)
(@CGUID+309, 35233, 654, 4755, 4757, 1, 170, 0, 0, 0, -1778.109, 1340.135, 19.90196, 0.8203048, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Survivor (Area: Military District - Difficulty: 0)
(@CGUID+310, 35233, 654, 4755, 4757, 1, 170, 0, 0, 0, -1773.804, 1350.967, 19.88576, 5.899213, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Survivor (Area: Military District - Difficulty: 0)
(@CGUID+311, 35232, 654, 4755, 4757, 1, 170, 0, 0, 0, -1771.601, 1342.394, 20.01954, 0.8203048, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Royal Guard (Area: Military District - Difficulty: 0)
(@CGUID+312, 35233, 654, 4755, 4757, 1, 170, 0, 0, 0, -1778.181, 1344.861, 19.97241, 0.1570796, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Survivor (Area: Military District - Difficulty: 0)
(@CGUID+313, 35374, 654, 4755, 4757, 1, 170, 0, 0, 0, -1756.212, 1389.637, 19.91755, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Generic Trigger LAB - Multiphase (Area: Military District - Difficulty: 0)
(@CGUID+314, 4075, 654, 4755, 4757, 1, 170, 0, 0, 0, -1776.416, 1360.228, 19.70127, 5.374861, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Military District - Difficulty: 0)
(@CGUID+315, 35374, 654, 4755, 4757, 1, 170, 0, 0, 0, -1763.314, 1389.778, 19.95122, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Generic Trigger LAB - Multiphase (Area: Military District - Difficulty: 0)
(@CGUID+316, 35232, 654, 4755, 4757, 1, 170, 0, 0, 0, -1757.899, 1394.538, 19.87307, 5.113815, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Royal Guard (Area: Military District - Difficulty: 0)
(@CGUID+317, 39095, 654, 4755, 4757, 1, 170, 0, 0, 0, -1738.149, 1408.92, 21.75196, 0.1745329, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Slain Guard (Area: Military District - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+318, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1721.658, 1415.642, 21.79362, 3.036873, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0)
(@CGUID+319, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1740.236, 1419.12, 22.93485, 6.024833, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+320, 35374, 654, 4755, 4757, 1, 170, 0, 0, 0, -1785.16, 1367.691, 19.90518, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Generic Trigger LAB - Multiphase (Area: Military District - Difficulty: 0)
(@CGUID+321, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1733.176, 1418.101, 21.79362, 4.769615, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+322, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1728.906, 1416.694, 21.79362, 6.099685, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0)
(@CGUID+323, 35374, 654, 4755, 4757, 1, 170, 0, 0, 0, -1783.217, 1372.266, 19.93655, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Generic Trigger LAB - Multiphase (Area: Military District - Difficulty: 0)
(@CGUID+324, 35232, 654, 4755, 4757, 1, 170, 0, 0, 0, -1736.779, 1418.206, 22.1215, 2.497379, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Royal Guard (Area: Military District - Difficulty: 0)
(@CGUID+325, 35232, 654, 4755, 4757, 1, 170, 0, 0, 0, -1699.236, 1425.878, 21.76275, 3.21073, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Gilnean Royal Guard (Area: Military District - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+326, 39095, 654, 4755, 4757, 1, 170, 0, 0, 0, -1715.153, 1435.698, 21.75196, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Slain Guard (Area: Military District - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+327, 39095, 654, 4755, 4757, 1, 170, 0, 0, 0, -1669.826, 1435.016, 52.37046, 0.4537856, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Slain Guard (Area: Military District - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+328, 50371, 654, 4755, 4757, 1, 170, 0, 0, 0, -1755.069, 1418.04, 24.11409, 0.3490658, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Captain Broderick (Area: Military District - Difficulty: 0)
(@CGUID+329, 35232, 654, 4755, 4757, 1, 170, 0, 0, 0, -1713.533, 1434.259, 21.75196, 1.658063, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Royal Guard (Area: Military District - Difficulty: 0)
-- (@CGUID+330, 89715, UNKNOWN, 4755, 4757, 1, 170, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Franklin Martin (Area: Military District - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+331, 50260, 654, 4755, 4757, 1, 170, 0, 0, 0, -1618.179, 1311.964, 19.59211, 4.118977, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+332, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1765.586, 1434.784, 20.2734, 0.5630513, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer) (possible waypoints or random movement)
(@CGUID+333, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1748.606, 1428.061, 52.74531, 6.197523, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer) (possible waypoints or random movement)
(@CGUID+334, 50260, 654, 4755, 4757, 1, 170, 0, 0, 0, -1617.917, 1313.438, 19.50114, 0.6981317, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+335, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1763.908, 1398.491, 20.0508, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer) (possible waypoints or random movement)
(@CGUID+336, 35123, 654, 4755, 4757, 1, 170, 0, 0, 0, -1682.8, 1441.262, 52.37046, 5.480334, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Vincent Hersham (Area: Military District - Difficulty: 0)
(@CGUID+337, 35124, 654, 4755, 4757, 1, 170, 0, 0, 0, -1678.51, 1438.786, 52.37044, 6.253154, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Tobias Mistmantle (Area: Military District - Difficulty: 0) (Auras: )
(@CGUID+338, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1768.085, 1449.607, 20.25494, 1.860381, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer) (possible waypoints or random movement)
(@CGUID+339, 39095, 654, 4755, 4757, 1, 170, 0, 0, 0, -1735.67, 1437.476, 52.37084, 1.937315, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Slain Guard (Area: Military District - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+340, 35077, 654, 4755, 4757, 1, 170, 0, 0, 0, -1679.734, 1442.122, 52.37046, 0.7504916, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Lord Darius Crowley (Area: Military District - Difficulty: 0) (Auras: 67503 - Rebel Valor)
(@CGUID+341, 35081, 654, 4755, 4757, 1, 170, 0, 0, 0, -1682.167, 1439.67, 52.37046, 0.8377581, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Sean Dempsey (Area: Military District - Difficulty: 0) (Auras: 52165 - Cosmetic - Stun Permanent (no anim))
(@CGUID+342, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1712.974, 1437.882, 21.69875, 4.559332, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+343, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1723.535, 1395.212, 21.75196, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer) (possible waypoints or random movement)
(@CGUID+344, 35374, 654, 4755, 4757, 1, 170, 0, 0, 0, -1787.943, 1427.24, 13.00155, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Generic Trigger LAB - Multiphase (Area: Military District - Difficulty: 0)
(@CGUID+345, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1715.033, 1413.74, 21.75196, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer) (possible waypoints or random movement)
(@CGUID+346, 35369, 654, 4755, 4757, 1, 170, 0, 0, 0, -1813.616, 1428.318, 12.54652, 3.857178, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Josiah Avery (Area: Military District - Difficulty: 0) (Auras: )
(@CGUID+347, 35374, 654, 4755, 4757, 1, 170, 0, 0, 0, -1813.611, 1428.142, 12.54652, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Generic Trigger LAB - Multiphase (Area: Military District - Difficulty: 0)
(@CGUID+348, 4075, 654, 4755, 4757, 1, 170, 0, 0, 0, -1805.197, 1457.219, 18.96187, 4.875721, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Military District - Difficulty: 0)
(@CGUID+349, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1704.799, 1425.266, 21.75196, 2.360414, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer) (possible waypoints or random movement)
(@CGUID+350, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1682.042, 1414.962, 21.75196, 1.661328, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer) (possible waypoints or random movement)
(@CGUID+351, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1721.273, 1391.679, 21.75196, 1.857025, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer) (possible waypoints or random movement)
(@CGUID+352, 4075, 654, 4755, 4757, 1, 170, 0, 0, 0, -1731.122, 1480.054, 24.40585, 4.728887, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Military District - Difficulty: 0)
(@CGUID+353, 41561, 654, 4755, 0, 1, 170, 0, 0, 0, -1731.951, 1631.554, 20.88563, 1.867502, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Wary Mastiff (Area: 0 - Difficulty: 0)
(@CGUID+354, 34884, 654, 4755, 4757, 1, 170, 0, 0, 0, -1569.112, 1364.23, 35.79102, 5.814743, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Military District - Difficulty: 0)
(@CGUID+355, 34884, 654, 4755, 4757, 1, 170, 0, 0, 0, -1563.572, 1360.435, 35.68091, 5.275905, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+356, 34884, 654, 4755, 4757, 1, 170, 0, 0, 0, -1561.194, 1339.962, 35.68091, 2.10333, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Military District - Difficulty: 0)
(@CGUID+357, 34884, 654, 4755, 4757, 1, 170, 0, 0, 0, -1518.483, 1426.316, 35.67107, 2.149821, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+358, 34884, 654, 4755, 4757, 1, 170, 0, 0, 0, -1542.932, 1428.961, 35.67107, 4.87862, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+359, 50260, 654, 4755, 4757, 1, 170, 0, 0, 0, -1616.495, 1311.769, 19.28115, 4.834562, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+360, 34884, 654, 4755, 4757, 1, 170, 0, 0, 0, -1520.884, 1382.729, 36.08524, 4.468043, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Military District - Difficulty: 0)
(@CGUID+361, 50260, 654, 4755, 4757, 1, 170, 0, 0, 0, -1616.47, 1309.918, 19.33193, 0.05235988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+362, 50260, 654, 4755, 4757, 1, 170, 0, 0, 0, -1614.41, 1311.236, 18.92509, 2.600541, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+363, 50260, 654, 4755, 4757, 1, 170, 0, 0, 0, -1619.611, 1310.609, 19.85793, 0.7504916, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+364, 50260, 654, 4755, 4757, 1, 170, 0, 0, 0, -1614.557, 1313.599, 18.88782, 2.617994, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+365, 50260, 654, 4755, 4757, 1, 170, 0, 0, 0, -1612.536, 1315.115, 18.51861, 4.782202, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+366, 34884, 654, 4755, 4757, 1, 170, 0, 0, 0, -1510.103, 1395.395, 35.68091, 4.484837, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+367, 34884, 654, 4755, 4757, 1, 170, 0, 0, 0, -1470.778, 1441.059, 36.3436, 2.600541, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Military District - Difficulty: 0)
(@CGUID+368, 34884, 654, 4755, 4757, 1, 170, 0, 0, 0, -1442.207, 1390.193, 35.68091, 2.743438, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Military District - Difficulty: 0)
(@CGUID+369, 34884, 654, 4755, 4757, 1, 170, 0, 0, 0, -1420.164, 1370.47, 35.68092, 5.409766, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Military District - Difficulty: 0)
(@CGUID+370, 34884, 654, 4755, 4757, 1, 170, 0, 0, 0, -1444.965, 1421.747, 35.68091, 0.1491247, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Military District - Difficulty: 0)
(@CGUID+371, 34884, 654, 4755, 4756, 1, 170, 0, 0, 0, -1406.99, 1377.31, 35.99875, 0.7507603, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Merchant Square - Difficulty: 0)
(@CGUID+372, 35456, 654, 4755, 4756, 1, 170, 0, 0, 0, -1611.757, 1493.896, 67.43678, 3.636799, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+373, 35457, 654, 4755, 4756, 1, 170, 0, 0, 0, -1701.495, 1477.289, 59.41336, 5.3915, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Bloodletter (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+374, 35456, 654, 4755, 4756, 1, 170, 0, 0, 0, -1720.653, 1526.708, 55.9107, 5.844984, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+375, 35456, 654, 4755, 4756, 1, 170, 0, 0, 0, -1625.62, 1487.033, 71.27762, 3.531424, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+376, 35456, 654, 4755, 4756, 1, 170, 0, 0, 0, -1627.273, 1499.689, 68.89395, 4.251452, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+377, 35456, 654, 4755, 4756, 1, 170, 0, 0, 0, -1618.054, 1489.644, 68.45153, 3.593639, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+378, 35456, 654, 4755, 4756, 1, 170, 0, 0, 0, -1631.979, 1491.585, 71.11481, 4.032866, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Merchant Square - Difficulty: 0) (Auras: 8599 - Enrage)
(@CGUID+379, 35456, 654, 4755, 4756, 1, 170, 0, 0, 0, -1634.344, 1491.3, 70.10101, 4.6248, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+380, 35456, 654, 4755, 4756, 1, 170, 0, 0, 0, -1622.424, 1483.882, 67.67381, 3.404875, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+381, 35456, 654, 4755, 4756, 1, 170, 0, 0, 0, -1630.399, 1481.66, 71.41516, 3.484555, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+382, 35456, 654, 4755, 4756, 1, 170, 0, 0, 0, -1622.665, 1489.818, 71.03797, 3.776179, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+383, 35456, 654, 4755, 4756, 1, 170, 0, 0, 0, -1638.569, 1489.736, 68.55273, 4.548815, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Merchant Square - Difficulty: 0) (Auras: )
-- (@CGUID+384, 89715, UNKNOWN, 4755, 4756, 1, 170, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Franklin Martin (Area: Merchant Square - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+385, 35456, 654, 4755, 4756, 1, 170, 0, 0, 0, -1677.284, 1444.848, 52.28713, 2.803765, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Merchant Square - Difficulty: 0)
(@CGUID+386, 35456, 654, 4755, 4756, 1, 170, 0, 0, 0, -1678.199, 1447.438, 52.28713, 4.676456, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Merchant Square - Difficulty: 0)
(@CGUID+387, 50260, 654, 4755, 4756, 1, 170, 0, 0, 0, -1614.557, 1313.599, 18.88782, 2.617994, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+388, 50260, 654, 4755, 4756, 1, 170, 0, 0, 0, -1612.536, 1315.115, 18.51861, 4.782202, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+389, 50260, 654, 4755, 4756, 1, 170, 0, 0, 0, -1614.41, 1311.236, 18.92509, 2.600541, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+390, 50260, 654, 4755, 4756, 1, 170, 0, 0, 0, -1618.222, 1308.602, 19.70086, 2.199115, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+391, 50260, 654, 4755, 4756, 1, 170, 0, 0, 0, -1616.495, 1311.769, 19.28115, 4.834562, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+392, 50260, 654, 4755, 4756, 1, 170, 0, 0, 0, -1616.47, 1309.918, 19.33193, 0.05235988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+393, 50260, 654, 4755, 4756, 1, 170, 0, 0, 0, -1617.917, 1313.438, 19.50114, 0.6981317, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+394, 50260, 654, 4755, 4756, 1, 170, 0, 0, 0, -1619.611, 1310.609, 19.85793, 0.7504916, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+395, 50260, 654, 4755, 4756, 1, 170, 0, 0, 0, -1618.179, 1311.964, 19.59211, 4.118977, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Merchant Square - Difficulty: 0)
(@CGUID+396, 35456, 654, 4755, 4756, 1, 170, 0, 0, 0, -1700.017, 1469.25, 52.60233, 5.309082, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+397, 35456, 654, 4755, 4756, 1, 170, 0, 0, 0, -1699.088, 1467.081, 53.23332, 5.346412, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Merchant Square - Difficulty: 0)
(@CGUID+398, 35456, 654, 4755, 4756, 1, 170, 0, 0, 0, -1697.831, 1473.165, 54.11327, 5.407074, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+399, 35456, 654, 4755, 4756, 1, 170, 0, 0, 0, -1701.65, 1470.94, 52.2871, 5.363472, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+400, 35456, 654, 4755, 4756, 1, 170, 0, 0, 0, -1697.73, 1469.52, 52.2871, 5.285114, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+401, 35456, 654, 4755, 4756, 1, 170, 0, 0, 0, -1699.376, 1470.318, 56.496, 5.33299, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+402, 35456, 654, 4755, 4756, 1, 170, 0, 0, 0, -1694.03, 1466.33, 52.2872, 5.227995, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Merchant Square - Difficulty: 0) (Auras: )
(@CGUID+403, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1734.11, 1393.921, 20.71096, 3.657613, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+404, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1720.82, 1400.421, 21.79362, 1.206352, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+405, 34884, 654, 4755, 4757, 1, 170, 0, 0, 0, -1564.684, 1341.403, 35.81101, 1.605703, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Rampaging Worgen (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+406, 50260, 654, 4755, 4757, 1, 170, 0, 0, 0, -1617.917, 1313.438, 19.50114, 0.6981317, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+407, 50260, 654, 4755, 4757, 1, 170, 0, 0, 0, -1618.222, 1308.602, 19.70086, 2.199115, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+408, 50260, 654, 4755, 4757, 1, 170, 0, 0, 0, -1618.179, 1311.964, 19.59211, 4.118977, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+409, 50260, 654, 4755, 4757, 1, 170, 0, 0, 0, -1612.536, 1315.115, 18.51861, 4.782202, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+410, 50260, 654, 4755, 4757, 1, 170, 0, 0, 0, -1619.611, 1310.609, 19.85793, 0.7504916, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+411, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1740.278, 1418.944, 22.93476, 6.075404, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+412, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1741.318, 1435.574, 55.42303, 5.01926, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+413, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1717.031, 1459.035, 52.74283, 0.1724717, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0)
(@CGUID+414, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1696.247, 1370.394, 23.10253, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+415, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1723.076, 1354.24, 19.91219, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+416, 35118, 654, 4755, 4757, 1, 170, 0, 0, 0, -1739.832, 1378.422, 20.04544, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+417, 35118, 654, 4755, 4762, 1, 170, 0, 0, 0, -1693.439, 1387.392, 21.75196, 2.600541, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Stoneward Prison - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer) (possible waypoints or random movement)
(@CGUID+418, 35118, 654, 4755, 4762, 1, 170, 0, 0, 0, -1733.302, 1417.552, 21.75196, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Stoneward Prison - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+419, 35118, 654, 4755, 4762, 1, 170, 0, 0, 0, -1682.281, 1349.592, 15.2182, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Worgen (Area: Stoneward Prison - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer) (possible waypoints or random movement)
(@CGUID+420, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1627.273, 1499.689, 68.89395, 4.251452, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0) (Auras: 8599 - Enrage)
(@CGUID+421, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1618.054, 1489.644, 68.45153, 3.593639, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0) (Auras: 8599 - Enrage)
(@CGUID+422, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1631.979, 1491.585, 71.11481, 4.032866, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0)
(@CGUID+423, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1634.344, 1491.3, 70.10101, 4.6248, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0) (Auras: )
(@CGUID+424, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1622.424, 1483.882, 67.67381, 3.404875, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0) (Auras: )
(@CGUID+425, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1630.399, 1481.66, 71.41516, 3.484555, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0)
(@CGUID+426, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1622.665, 1489.818, 71.03797, 3.776179, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0) (Auras: )
(@CGUID+427, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1638.569, 1489.736, 68.55273, 4.548815, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0) (Auras: )
(@CGUID+428, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1720.653, 1526.708, 55.9107, 5.844984, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0) (Auras: )
(@CGUID+429, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1625.62, 1487.033, 71.27762, 3.531424, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0) (Auras: )
(@CGUID+430, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1724.719, 1526.731, 55.66177, 6.138319, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0) (Auras: 8599 - Enrage)
(@CGUID+431, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1717.75, 1513.727, 55.47941, 4.704845, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0)
(@CGUID+432, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1709.63, 1527.464, 56.86086, 3.258752, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0)
(@CGUID+433, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1729.345, 1526.495, 55.47962, 6.188943, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0)
(@CGUID+434, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1718.262, 1518.557, 55.55954, 4.726997, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0)
(@CGUID+435, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1718.104, 1524.071, 55.81641, 4.709816, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0) (Auras: 8599 - Enrage)
(@CGUID+436, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1713.974, 1526.625, 56.21981, 3.306195, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0)
(@CGUID+437, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1627.273, 1499.689, 68.89395, 4.251452, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0) (Auras: 8599 - Enrage)
(@CGUID+438, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1618.054, 1489.644, 68.45153, 3.593639, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0) (Auras: )
(@CGUID+439, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1631.979, 1491.585, 71.11481, 4.032866, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0) (Auras: )
(@CGUID+440, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1634.344, 1491.3, 70.10101, 4.6248, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0) (Auras: )
(@CGUID+441, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1622.424, 1483.882, 67.67381, 3.404875, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0) (Auras: 8599 - Enrage)
(@CGUID+442, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1630.399, 1481.66, 71.41516, 3.484555, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0)
(@CGUID+443, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1622.665, 1489.818, 71.03797, 3.776179, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0) (Auras: )
(@CGUID+444, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1638.569, 1489.736, 68.55273, 4.548815, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0)
(@CGUID+445, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1720.653, 1526.708, 55.9107, 5.844984, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0) (Auras: )
(@CGUID+446, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1625.62, 1487.033, 71.27762, 3.531424, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0) (Auras: )
(@CGUID+447, 35457, 654, 4755, 4762, 1, 170, 0, 0, 0, -1718.165, 1521.936, 55.71669, 4.732433, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Bloodletter (Area: Stoneward Prison - Difficulty: 0)
(@CGUID+448, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1611.757, 1493.896, 67.43678, 4.677482, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0) (Auras: )
(@CGUID+449, 35456, 654, 4755, 4762, 1, 170, 0, 0, 0, -1630.399, 1481.66, 71.41516, 3.484555, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Worgen Runt (Area: Stoneward Prison - Difficulty: 0) (Auras: 8599 - Enrage)
(@CGUID+450, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1760.277, 1337.226, 19.87675, 5.541513, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+451, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1677.406, 1340.441, 15.25987, 3.773301, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+452, 35504, 654, 4755, 4757, 1, 171, 0, 0, 0, -1759.486, 1410.245, 20.94987, 5.097866, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+453, 35509, 654, 4755, 4757, 1, 171, 0, 0, 0, -1767.688, 1400.507, 20.00809, 5.627713, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+454, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1710.879, 1360.24, 19.88487, 0.09382436, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+455, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1712.042, 1348.053, 19.82813, 3.809261, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+456, 35504, 654, 4755, 4757, 1, 171, 0, 0, 0, -1790.345, 1399.434, 20.37605, 5.033753, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+457, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1730.684, 1347.464, 19.75987, 2.108419, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+458, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1746.15, 1369.673, 19.97488, 0.01157437, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+459, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1689.073, 1337.146, 15.25987, 2.105538, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+460, 35504, 654, 4755, 4757, 1, 171, 0, 0, 0, -1755.899, 1409.438, 19.86546, 5.117027, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+461, 35509, 654, 4755, 4757, 1, 171, 0, 0, 0, -1794.821, 1397.097, 19.93506, 4.884682, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+462, 35504, 654, 4755, 4757, 1, 171, 0, 0, 0, -1799.769, 1402.174, 19.97234, 4.956735, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+463, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1721.444, 1359.1, 19.75987, 2.412025, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+464, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1707.693, 1352.161, 19.88487, 1.015765, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+465, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1739.178, 1373.495, 19.95046, 2.967142, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+466, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1753.76, 1377.172, 19.81179, 3.45587, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+467, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1743.115, 1372.345, 20.07546, 3.405706, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+468, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1740.253, 1359.001, 19.82436, 4.055814, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+469, 35509, 654, 4755, 4757, 1, 171, 0, 0, 0, -1802.125, 1389.582, 20.36794, 4.764749, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+470, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1773.132, 1360.342, 19.71486, 2.103249, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+471, 35504, 654, 4755, 4757, 1, 171, 0, 0, 0, -1798.167, 1404.51, 19.92372, 5.087076, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+472, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1768.301, 1347.354, 19.95631, 6.026972, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+473, 35463, 654, 4755, 4757, 1, 171, 0, 0, 0, -1789.317, 1483.763, 20.27034, 2.8409, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Lurker (Area: Military District - Difficulty: 0)
(@CGUID+474, 35509, 654, 4755, 4757, 1, 171, 0, 0, 0, -1758.484, 1399.424, 19.86806, 4.764749, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+475, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1737.666, 1359.027, 19.9573, 3.512149, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+476, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1688.13, 1338.939, 15.25987, 3.111466, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+477, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1746.853, 1329.636, 19.96486, 0.9896676, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+478, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1739.871, 1323.233, 20.06179, 1.587202, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+479, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1726.362, 1362.047, 19.90904, 5.841092, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+480, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1726.881, 1378.309, 19.90771, 0.8136587, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+481, 35463, 654, 4755, 4757, 1, 171, 0, 0, 0, -1740.702, 1513.067, 26.32375, 4.123241, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Lurker (Area: Military District - Difficulty: 0)
(@CGUID+482, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1702.911, 1352.507, 19.39717, 0.2724707, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+483, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1734.636, 1325.94, 20.29512, 3.450653, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+484, 35504, 654, 4755, 4757, 1, 171, 0, 0, 0, -1800.219, 1398.863, 19.98782, 5.156498, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+485, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1772.382, 1354.381, 19.83986, 2.479361, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+486, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1750.834, 1328.362, 19.83986, 1.104868, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+487, 38844, 654, 4755, 4757, 1, 171, 0, 0, 0, -1788.74, 1428.526, 12.99595, 3.351032, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Mastiff (Area: Military District - Difficulty: 0)
(@CGUID+488, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1771.878, 1353.877, 19.83986, 6.203314, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+489, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1740.915, 1371.662, 19.98525, 3.39781, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+490, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1728.636, 1359.391, 19.86341, 4.553943, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+491, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1730.936, 1389.145, 20.49269, 2.609706, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+492, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1748.148, 1320.7, 20.28475, 2.777936, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+493, 35906, 654, 4755, 4757, 1, 171, 0, 0, 0, -1785.66, 1437.613, 20.20581, 0.6457718, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Lord Godfrey (Area: Military District - Difficulty: 0)
(@CGUID+494, 35509, 654, 4755, 4757, 1, 171, 0, 0, 0, -1765.899, 1396.703, 19.96007, 4.764749, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+495, 35504, 654, 4755, 4757, 1, 171, 0, 0, 0, -1803.911, 1395.08, 20.36791, 5.113815, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+496, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1780.334, 1364.271, 19.83986, 6.01896, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+497, 35550, 654, 4755, 4757, 1, 171, 0, 0, 0, -1803.646, 1406.674, 19.92054, 5.098837, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- King Genn Greymane (Area: Military District - Difficulty: 0)
(@CGUID+498, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1721.004, 1355.47, 19.81864, 3.648055, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+499, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1743.861, 1320.997, 19.83986, 0.08877843, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+500, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1739.439, 1356.086, 19.83498, 5.993, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+501, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1690.881, 1336.603, 15.25987, 4.33409, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+502, 35378, 654, 4755, 4757, 1, 171, 0, 0, 0, -1789.75, 1427.413, 13.0063, 3.176499, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Lorna Crowley (Area: Military District - Difficulty: 0)
(@CGUID+503, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1739.797, 1318.662, 19.83986, 1.072088, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+504, 35504, 654, 4755, 4757, 1, 171, 0, 0, 0, -1774.825, 1400.552, 20.37605, 5.190791, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+505, 35509, 654, 4755, 4757, 1, 171, 0, 0, 0, -1794.439, 1393.835, 19.97655, 4.764749, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+506, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1740.907, 1361.023, 19.78982, 0.8035973, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+507, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1730.992, 1345.687, 19.75987, 1.685814, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+508, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1718.126, 1360.131, 19.90062, 1.38012, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+509, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1727.067, 1368.267, 19.90712, 3.006678, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+510, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1748.36, 1379.322, 19.99429, 2.947789, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+511, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1740.624, 1360.486, 19.78982, 1.148354, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+512, 35509, 654, 4755, 4757, 1, 171, 0, 0, 0, -1757.507, 1402.976, 19.86546, 4.747153, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+513, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1714.998, 1357.138, 19.88487, 1.413195, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+514, 35504, 654, 4755, 4757, 1, 171, 0, 0, 0, -1766.274, 1409.792, 19.86569, 5.172817, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+515, 35509, 654, 4755, 4757, 1, 171, 0, 0, 0, -1798.78, 1395.314, 19.98374, 5.078908, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+516, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1771.304, 1338.672, 19.97005, 3.095394, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+517, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1731.696, 1345.131, 19.75987, 5.707503, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+518, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1736.614, 1321.062, 19.83986, 1.33716, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+519, 4075, 654, 4755, 4757, 1, 171, 0, 0, 0, -1798.532, 1453.433, 19.10015, 3.143548, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Military District - Difficulty: 0)
(@CGUID+520, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1738.005, 1362.708, 19.87734, 3.122375, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+521, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1761.358, 1347.306, 19.91482, 3.220107, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+522, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1686.123, 1349.393, 15.25987, 4.813005, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+523, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1727.632, 1319.135, 19.88487, 2.449417, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+524, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1760.862, 1350.681, 19.78982, 2.37871, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+525, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1725.447, 1316.842, 19.88487, 2.740652, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+526, 35509, 654, 4755, 4757, 1, 171, 0, 0, 0, -1763.819, 1401.568, 19.95603, 5.375283, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+527, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1764.308, 1363.319, 19.9756, 5.491621, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+528, 4075, 654, 4755, 4757, 1, 171, 0, 0, 0, -1745.352, 1373.216, 20.05667, 5.368284, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Military District - Difficulty: 0)
(@CGUID+529, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1737.42, 1386.949, 19.82546, 1.71414, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+530, 35463, 654, 4755, 4757, 1, 171, 0, 0, 0, -1763.12, 1504.561, 26.32375, 2.349224, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Lurker (Area: Military District - Difficulty: 0)
(@CGUID+531, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1769.294, 1353.224, 19.96486, 2.281791, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+532, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1720.328, 1354.83, 19.75987, 3.335369, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+533, 38844, 654, 4755, 4757, 1, 171, 0, 0, 0, -1788.554, 1426.823, 13.00639, 3.351032, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Mastiff (Area: Military District - Difficulty: 0)
(@CGUID+534, 35463, 654, 4755, 4757, 1, 171, 0, 0, 0, -1737.821, 1509.776, 26.32375, 3.199308, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Lurker (Area: Military District - Difficulty: 0)
(@CGUID+535, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1731.475, 1358.273, 19.94004, 2.034523, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+536, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1739.751, 1327.354, 19.88321, 5.991296, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+537, 35504, 654, 4755, 4757, 1, 171, 0, 0, 0, -1769.109, 1410.066, 19.86565, 5.113815, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+538, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1728.863, 1381.428, 19.90712, 1.161817, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+539, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1731.088, 1390.118, 20.63345, 0.2933281, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+540, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1707.652, 1352.755, 19.88487, 0.4173355, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+541, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1722.094, 1360.276, 19.75987, 0.8951911, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+542, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1754.711, 1330.614, 19.829, 3.635673, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+543, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1770.152, 1344.958, 19.93179, 4.350411, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+544, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1712.321, 1355.149, 19.88487, 2.601887, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+545, 35463, 654, 4755, 4757, 1, 171, 0, 0, 0, -1803.564, 1468.672, 19.39296, 4.8502, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Lurker (Area: Military District - Difficulty: 0)
(@CGUID+546, 35504, 654, 4755, 4757, 1, 171, 0, 0, 0, -1772.229, 1402.641, 19.86592, 5.160146, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+547, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1730.595, 1360.739, 19.78367, 4.533161, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+548, 35509, 654, 4755, 4757, 1, 171, 0, 0, 0, -1805.082, 1393.403, 20.36976, 5.358161, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+549, 4075, 654, 4755, 4757, 1, 171, 0, 0, 0, -1805.791, 1447.843, 19.08687, 1.559442, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Military District - Difficulty: 0)
(@CGUID+550, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1720.627, 1369.185, 19.90712, 3.976244, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+551, 4075, 654, 4755, 4757, 1, 171, 0, 0, 0, -1740.488, 1512.509, 26.32375, 5.931868, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Military District - Difficulty: 0)
(@CGUID+552, 35463, 654, 4755, 4757, 1, 171, 0, 0, 0, -1790.889, 1454.852, 19.47076, 3.224734, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Lurker (Area: Military District - Difficulty: 0) (Auras: 5916 - Shadowstalker Stealth) (possible waypoints or random movement)
(@CGUID+553, 35463, 654, 4755, 4757, 1, 171, 0, 0, 0, -1753.438, 1439.001, 21.98342, 6.272454, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Lurker (Area: Military District - Difficulty: 0) (Auras: 5916 - Shadowstalker Stealth)
(@CGUID+554, 50260, 654, 4755, 4757, 1, 171, 0, 0, 0, -1800.299, 1549.613, 22.82806, 4.869469, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+555, 50260, 654, 4755, 4757, 1, 171, 0, 0, 0, -1797.958, 1547.196, 22.81093, 2.949606, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+556, 50260, 654, 4755, 4757, 1, 171, 0, 0, 0, -1797.644, 1549.366, 22.82015, 0.8028514, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+557, 50260, 654, 4755, 4757, 1, 171, 0, 0, 0, -1800.358, 1547.642, 22.83263, 1.500983, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+558, 50260, 654, 4755, 4757, 1, 171, 0, 0, 0, -1801.149, 1550.842, 22.82806, 1.448623, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+559, 50260, 654, 4755, 4757, 1, 171, 0, 0, 0, -1798.879, 1553.325, 22.81422, 3.368485, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+560, 50260, 654, 4755, 4757, 1, 171, 0, 0, 0, -1798.965, 1550.661, 22.82149, 5.585053, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+561, 50260, 654, 4755, 4757, 1, 171, 0, 0, 0, -1798.512, 1555.826, 22.806, 5.532694, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+562, 50260, 654, 4755, 4757, 1, 171, 0, 0, 0, -1797.109, 1551.752, 22.81293, 3.351032, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+563, 35463, 654, 4755, 4757, 1, 171, 0, 0, 0, -1789.022, 1523.904, 20.35213, 3.681444, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Lurker (Area: Military District - Difficulty: 0) (Auras: 5916 - Shadowstalker Stealth)
(@CGUID+564, 35463, 654, 4755, 4757, 1, 171, 0, 0, 0, -1808.373, 1528.279, 20.48392, 3.870828, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Lurker (Area: Military District - Difficulty: 0) (Auras: 5916 - Shadowstalker Stealth)
(@CGUID+565, 35463, 654, 4755, 4757, 1, 171, 0, 0, 0, -1762.845, 1460.222, 20.56118, 4.45059, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Lurker (Area: Military District - Difficulty: 0) (Auras: 5916 - Shadowstalker Stealth) (possible waypoints or random movement)
(@CGUID+566, 35463, 654, 4755, 0, 1, 171, 0, 0, 0, -1800.377, 1474.845, 20.36627, 4.45059, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Lurker (Area: 0 - Difficulty: 0) (Auras: 5916 - Shadowstalker Stealth) (possible waypoints or random movement)
(@CGUID+567, 41561, 654, 4755, 0, 1, 171, 0, 0, 0, -1731.951, 1631.554, 20.88563, 1.867502, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Wary Mastiff (Area: 0 - Difficulty: 0)
(@CGUID+568, 35505, 654, 4755, 4758, 1, 171, 0, 0, 0, -1749.575, 1377.16, 19.98192, 1.77969, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Greymane Court - Difficulty: 0)
(@CGUID+569, 35505, 654, 4755, 4758, 1, 171, 0, 0, 0, -1737.934, 1380.582, 19.92874, 3.504158, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Greymane Court - Difficulty: 0)
(@CGUID+570, 35505, 654, 4755, 4758, 1, 171, 0, 0, 0, -1771.161, 1365.819, 19.83986, 0.7857106, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Greymane Court - Difficulty: 0)
(@CGUID+571, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1720.712, 1368.991, 19.86546, 2.13413, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+572, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1748.594, 1377.879, 19.91718, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+573, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1732.46, 1333.002, 19.86573, 1.963331, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+574, 50260, 654, 4755, 4757, 1, 171, 0, 0, 0, -1798.879, 1553.325, 22.81422, 3.368485, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+575, 50260, 654, 4755, 4757, 1, 171, 0, 0, 0, -1797.109, 1551.752, 22.81293, 3.351032, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+576, 50260, 654, 4755, 4757, 1, 171, 0, 0, 0, -1798.965, 1550.661, 22.82149, 5.585053, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+577, 50260, 654, 4755, 4757, 1, 171, 0, 0, 0, -1800.299, 1549.613, 22.82806, 4.869469, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+578, 50260, 654, 4755, 4757, 1, 171, 0, 0, 0, -1800.358, 1547.642, 22.83263, 1.500983, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+579, 50260, 654, 4755, 4757, 1, 171, 0, 0, 0, -1797.644, 1549.366, 22.82015, 0.8028514, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+580, 50260, 654, 4755, 4757, 1, 171, 0, 0, 0, -1801.149, 1550.842, 22.82806, 1.448623, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+581, 50260, 654, 4755, 4757, 1, 171, 0, 0, 0, -1798.512, 1555.826, 22.806, 5.532694, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+582, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1760.705, 1372.467, 19.97486, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+583, 50260, 654, 4755, 4757, 1, 171, 0, 0, 0, -1797.958, 1547.196, 22.81093, 2.949606, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+584, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1751.63, 1377.689, 19.94535, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+585, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1737.934, 1380.582, 19.92874, 1.414315, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+586, 35463, 654, 4755, 4757, 1, 171, 0, 0, 0, -1756.665, 1482.342, 25.21637, 4.45059, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Lurker (Area: Military District - Difficulty: 0) (Auras: 5916 - Shadowstalker Stealth)
(@CGUID+587, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1749.575, 1377.16, 19.98192, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+588, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1736.514, 1382.905, 19.91917, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+589, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1750.677, 1368.717, 19.93879, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+590, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1720.712, 1368.991, 19.86546, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+591, 35463, 654, 4755, 4757, 1, 171, 0, 0, 0, -1807.28, 1445.72, 19.21187, 1.88084, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Lurker (Area: Military District - Difficulty: 0) (Auras: 5916 - Shadowstalker Stealth) (possible waypoints or random movement)
(@CGUID+592, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1748.594, 1377.879, 19.91718, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+593, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1751.63, 1377.689, 19.94535, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+594, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1750.677, 1368.717, 19.93879, 2.111256, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+595, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1744.25, 1369.384, 20.05559, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+596, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1737.934, 1380.582, 19.92874, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+597, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1748.594, 1377.879, 19.91718, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+598, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1709.747, 1307.653, 19.86565, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+599, 35463, 654, 4755, 4757, 1, 171, 0, 0, 0, -1801.762, 1485.844, 19.79056, 4.45059, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Lurker (Area: Military District - Difficulty: 0) (Auras: 8599 - Enrage)
(@CGUID+600, 35463, 654, 4755, 4757, 1, 171, 0, 0, 0, -1762.63, 1513.986, 26.30628, 4.45059, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Lurker (Area: Military District - Difficulty: 0) (Auras: 5916 - Shadowstalker Stealth)
(@CGUID+601, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1748.594, 1377.879, 19.91718, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+602, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1720.712, 1368.991, 19.86546, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+603, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1749.575, 1377.16, 19.98192, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+604, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1748.594, 1377.879, 19.91718, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+605, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1750.677, 1368.717, 19.93879, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+606, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1749.575, 1377.16, 19.98192, 2.182679, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+607, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1709.747, 1307.653, 19.86565, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+608, 35753, 654, 4755, 4757, 1, 171, 0, 0, 0, -1673.238, 1344.802, 18.98268, 0.4014257, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Krennan Aranas (Area: Military District - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1)
(@CGUID+609, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1750.677, 1368.717, 19.93879, 1.658219, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+610, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1736.514, 1382.905, 19.91917, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+611, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1751.63, 1377.689, 19.94535, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+612, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1749.575, 1377.16, 19.98192, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+613, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1720.712, 1368.991, 19.86546, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+614, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1744.25, 1369.384, 20.05559, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+615, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1748.594, 1377.879, 19.91718, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+616, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1709.747, 1307.653, 19.86565, 3.083668, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+617, 35505, 654, 4755, 4757, 1, 171, 0, 0, 0, -1745.727, 1379.918, 19.93644, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+618, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1756.089, 1466.741, 22.0611, 4.223697, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+619, 35915, 654, 4755, 4757, 1, 172, 0, 0, 0, -1771.266, 1411.809, 19.86565, 4.991642, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+620, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1678.745, 1596.986, 20.56892, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0)
(@CGUID+621, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1765.013, 1510.141, 26.32375, 1.126698, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+622, 50474, 654, 4755, 4757, 1, 172, 0, 0, 0, -1790.66, 1515.188, 19.86566, 2.21243, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+623, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1786.54, 1512.07, 19.7823, 2.968343, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+624, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1787.424, 1515.899, 20.35626, 3.35798, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+625, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1728.389, 1621.436, 20.60363, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0)
(@CGUID+626, 4075, 654, 4755, 4757, 1, 172, 0, 0, 0, -1751.582, 1511.741, 26.32375, 3.250127, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Military District - Difficulty: 0)
(@CGUID+627, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1680.278, 1579.983, 20.56892, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0)
(@CGUID+628, 4075, 654, 4755, 4757, 1, 172, 0, 0, 0, -1806.048, 1437.62, 19.40325, 1.582553, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Military District - Difficulty: 0)
(@CGUID+629, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1761.462, 1464.099, 20.88732, 3.316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+630, 50474, 654, 4755, 4757, 1, 172, 0, 0, 0, -1794.33, 1485.91, 20.01979, 6.073746, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+631, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1804.166, 1489.727, 19.66969, 4.620064, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+632, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1730.139, 1505.712, 26.30264, 3.316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+633, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1788.412, 1504.92, 20.29344, 4.512715, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+634, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1743.424, 1578.219, 20.56873, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0)
(@CGUID+635, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1787.948, 1506.699, 20.29572, 1.355791, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+636, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1788.428, 1504.887, 20.29342, 4.507551, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+637, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1690.505, 1593.313, 20.56891, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0) (Auras: )
(@CGUID+638, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1764.135, 1468.696, 21.78699, 3.316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+639, 50474, 654, 4755, 4757, 1, 172, 0, 0, 0, -1757.969, 1454.63, 21.29383, 1.416782, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+640, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1787.977, 1511.413, 19.90623, 3.236958, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+641, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1739.054, 1513.156, 26.30628, 3.316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+642, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1794.003, 1516.613, 20.34048, 4.053951, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+643, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1758.806, 1466.868, 21.36701, 3.316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+644, 50474, 654, 4755, 4757, 1, 172, 0, 0, 0, -1766.108, 1457.472, 20.46494, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+645, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1684.262, 1609.717, 20.5728, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0) (Auras: )
(@CGUID+646, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1769.906, 1514.127, 25.89461, 2.844887, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+647, 35915, 654, 4755, 4757, 1, 172, 0, 0, 0, -1802.76, 1407.512, 19.93638, 4.991642, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+648, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1788.333, 1504.867, 20.29341, 4.501601, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+649, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1788.464, 1510.366, 19.86566, 3.316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+650, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1765.781, 1476.898, 23.82987, 5.183628, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+651, 50474, 654, 4755, 4757, 1, 172, 0, 0, 0, -1763.832, 1455.307, 20.4565, 1.160691, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+652, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1787.51, 1514.08, 19.7823, 2.901756, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+653, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1791.508, 1483.572, 20.13498, 2.449669, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+654, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1766.413, 1513.141, 26.30628, 3.316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+655, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1800.197, 1509.2, 19.93174, 3.22336, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+656, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1695.958, 1594.573, 20.56892, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0) (Auras: )
(@CGUID+657, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1760.646, 1507.042, 26.30628, 3.316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+658, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1788.293, 1504.948, 20.29348, 4.508884, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+659, 50474, 654, 4755, 4757, 1, 172, 0, 0, 0, -1791.073, 1519.34, 20.32849, 3.767407, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+660, 35914, 654, 4755, 4757, 1, 172, 0, 0, 0, -1768.823, 1410.156, 19.86565, 5.235988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Commandeered Cannon (Area: Military District - Difficulty: 0)
(@CGUID+661, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1732.649, 1596.457, 20.56892, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0)
(@CGUID+662, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1701.806, 1611.01, 20.56892, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0)
(@CGUID+663, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1755.747, 1513.792, 26.30628, 3.316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+664, 50474, 654, 4755, 4757, 1, 172, 0, 0, 0, -1791.609, 1506.51, 20.37783, 1.675015, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+665, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1766.504, 1513.019, 26.09093, 4.171191, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+666, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1745.245, 1590.203, 20.56698, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0)
(@CGUID+667, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1713.762, 1612.561, 20.6894, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+668, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1687.965, 1588.323, 20.56892, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0)
(@CGUID+669, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1686.375, 1599.16, 20.56892, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0) (Auras: )
(@CGUID+670, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1791.477, 1486.665, 20.05961, 3.316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+671, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1721.549, 1617.684, 20.56892, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+672, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1787.579, 1513.97, 19.90623, 5.084849, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+673, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1791.044, 1518.802, 20.29265, 2.998155, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+674, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1721.297, 1616.066, 20.56892, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+675, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1715.661, 1590.962, 20.56892, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+676, 4075, 654, 4755, 4757, 1, 172, 0, 0, 0, -1803.003, 1484.257, 19.6223, 3.301854, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Military District - Difficulty: 0)
(@CGUID+677, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1788.045, 1506.732, 20.29605, 3.203807, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+678, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1685.16, 1584.892, 20.56892, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0)
(@CGUID+679, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1747.872, 1569.88, 20.56892, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0)
(@CGUID+680, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1725.616, 1612.509, 20.56892, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+681, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1789.812, 1518.39, 20.30914, 2.62785, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+682, 35915, 654, 4755, 4757, 1, 172, 0, 0, 0, -1768.245, 1413.576, 19.86565, 4.991642, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+683, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1697.222, 1598.13, 20.56892, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0) (Auras: )
(@CGUID+684, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1787.718, 1517.279, 20.34851, 5.584971, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+685, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1725.399, 1619.444, 20.56892, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+686, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1786.7, 1516.66, 20.3522, 2.541651, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+687, 50474, 654, 4755, 4757, 1, 172, 0, 0, 0, -1791.627, 1511.064, 19.86566, 1.739223, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilneas City Guard (Area: Military District - Difficulty: 0)
(@CGUID+688, 35914, 654, 4755, 4757, 1, 172, 0, 0, 0, -1800.604, 1406.835, 19.95013, 4.956735, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Commandeered Cannon (Area: Military District - Difficulty: 0)
(@CGUID+689, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1789.169, 1518.462, 20.30987, 2.452118, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+690, 35916, 654, 4755, 4757, 1, 172, 0, 0, 0, -1744.358, 1363.382, 19.89969, 2.022662, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+691, 35916, 654, 4755, 4757, 1, 172, 0, 0, 0, -1730.286, 1390.384, 20.77077, 3.675044, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+692, 35916, 654, 4755, 4757, 1, 172, 0, 0, 0, -1732.773, 1367.837, 19.90107, 1.411434, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+693, 35916, 654, 4755, 4757, 1, 172, 0, 0, 0, -1734.391, 1359.887, 19.9064, 2.408094, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+694, 35916, 654, 4755, 4757, 1, 172, 0, 0, 0, -1734.542, 1344.554, 19.87691, 1.992707, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+695, 35916, 654, 4755, 4757, 1, 172, 0, 0, 0, -1737.693, 1352.986, 19.8711, 2.024995, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+696, 35916, 654, 4755, 4757, 1, 172, 0, 0, 0, -1724.385, 1348.462, 19.67817, 2.246326, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+697, 35916, 654, 4755, 4757, 1, 172, 0, 0, 0, -1726.747, 1364.599, 19.92638, 2.158717, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+698, 35916, 654, 4755, 4757, 1, 172, 0, 0, 0, -1746.523, 1361.108, 19.86813, 2.050741, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+699, 35916, 654, 4755, 4757, 1, 172, 0, 0, 0, -1728.276, 1353.201, 19.68232, 2.953147, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+700, 35916, 654, 4755, 4757, 1, 172, 0, 0, 0, -1721.182, 1350.429, 19.86563, 2.447646, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+701, 35916, 654, 4755, 4757, 1, 172, 0, 0, 0, -1719.358, 1357.512, 19.77914, 2.914889, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+702, 35916, 654, 4755, 4757, 1, 172, 0, 0, 0, -1715.219, 1352.839, 19.86458, 2.551367, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Ripper (Area: Military District - Difficulty: 0)
(@CGUID+703, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1686.823, 1606.386, 20.61058, 4.340439, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0) (Auras: )
(@CGUID+704, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1682.004, 1603.635, 20.61058, 3.877607, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0) (Auras: )
(@CGUID+705, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1683.088, 1603.866, 20.61058, 3.960172, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0) (Auras: )
(@CGUID+706, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1778.186, 1513.896, 22.93163, 2.844887, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+707, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1682.323, 1607.065, 20.61058, 3.820121, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0) (Auras: )
(@CGUID+708, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1687.421, 1605.343, 20.61055, 3.671268, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0)
(@CGUID+709, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1689.715, 1606.641, 20.61058, 3.92746, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0) (Auras: )
(@CGUID+710, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1698.909, 1614.584, 20.61032, 3.524276, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0) (Auras: )
(@CGUID+711, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1789.438, 1518.111, 20.38599, 3.316126, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+712, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1752.774, 1512.857, 32.47686, 3.131317, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+713, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1761.462, 1464.099, 20.88732, 3.316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+714, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1758.806, 1466.868, 21.36701, 3.316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+715, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1764.135, 1468.696, 21.78699, 3.316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+716, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1756.089, 1466.741, 22.0611, 4.223697, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+717, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1702.953, 1625.394, 20.5728, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0)
(@CGUID+718, 50260, 654, 4755, 4757, 1, 172, 0, 0, 0, -1800.014, 1546.861, 22.73474, 5.585053, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+719, 50260, 654, 4755, 4757, 1, 172, 0, 0, 0, -1799.007, 1543.396, 22.37639, 2.949606, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+720, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1684.451, 1626.823, 20.5728, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0)
(@CGUID+721, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1681.733, 1619.833, 20.5728, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0)
(@CGUID+722, 50260, 654, 4755, 4757, 1, 172, 0, 0, 0, -1804.587, 1551.469, 14.95241, 1.500983, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+723, 50260, 654, 4755, 4757, 1, 172, 0, 0, 0, -1799.561, 1552.024, 22.82473, 5.532694, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+724, 50260, 654, 4755, 4757, 1, 172, 0, 0, 0, -1802.198, 1547.042, 22.74299, 1.448623, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+725, 50260, 654, 4755, 4757, 1, 172, 0, 0, 0, -1798.158, 1547.951, 22.81662, 3.351032, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+726, 50260, 654, 4755, 4757, 1, 172, 0, 0, 0, -1798.693, 1545.566, 22.60542, 0.8028514, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+727, 50260, 654, 4755, 4757, 1, 172, 0, 0, 0, -1795.063, 1548.858, 22.80489, 3.368485, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+728, 50260, 654, 4755, 4757, 1, 172, 0, 0, 0, -1801.347, 1545.813, 22.61855, 4.869469, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Crow (Area: Military District - Difficulty: 0)
(@CGUID+729, 4075, 654, 4755, 4757, 1, 172, 0, 0, 0, -1746.048, 1569.968, 20.60736, 4.362316, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Military District - Difficulty: 0)
(@CGUID+730, 4075, 654, 4755, 4757, 1, 172, 0, 0, 0, -1778.579, 1585.499, 20.72848, 4.254898, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Military District - Difficulty: 0)
(@CGUID+731, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1659.352, 1620.34, 20.5728, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0)
(@CGUID+732, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1714.93, 1687.323, 20.27616, 5.303787, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+733, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1666.214, 1649.962, 20.57315, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0)
(@CGUID+734, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1644.929, 1619.708, 20.53298, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0)
(@CGUID+735, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1674.469, 1672.149, 20.57525, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0)
(@CGUID+736, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1662.318, 1662.663, 20.57315, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0)
(@CGUID+737, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1664.951, 1671.149, 20.57251, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0)
(@CGUID+738, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1675.429, 1679.66, 20.58432, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0)
(@CGUID+739, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1745.719, 1509.401, 26.29873, 3.067861, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+740, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1656.7, 1671.398, 20.57315, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0)
(@CGUID+741, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1761.462, 1464.099, 20.88732, 3.316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+742, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1696.576, 1692.135, 20.35366, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0)
(@CGUID+743, 35229, 654, 4755, 4757, 1, 172, 0, 0, 0, -1656.7, 1671.398, 20.57315, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Military District - Difficulty: 0)
(@CGUID+744, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1758.806, 1466.868, 21.36701, 3.316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+745, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1764.135, 1468.696, 21.78699, 3.316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+746, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1790.45, 1482.694, 20.15673, 3.316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+747, 50471, 654, 4755, 4757, 1, 172, 0, 0, 0, -1756.089, 1466.741, 22.0611, 4.223697, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Military District - Difficulty: 0)
(@CGUID+748, 51947, 654, 4755, 0, 1, 172, 0, 0, 0, -1741.495, 1633.519, 20.56441, 1.222871, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gilnean Steed (Area: 0 - Difficulty: 0)
(@CGUID+749, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1677.302, 1703.078, 20.57291, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+750, 44469, 654, 4755, 0, 1, 172, 0, 0, 0, -1745.82, 1633.39, 20.56253, 1.605703, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Vitus Darkwalker (Area: 0 - Difficulty: 0) (Auras: 45104 - Shadow Channelling)
-- (@CGUID+751, 68993, 654, 4755, 0, 1, 172, 0, 0, 0, -1740.254, 1635.766, 20.56551, 1.416518, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Fenegan Cobbler (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+752, 44463, 654, 4755, 0, 1, 172, 0, 0, 0, -1735.75, 1640.2, 20.64153, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Baron (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+753, 44470, 654, 4755, 0, 1, 172, 0, 0, 0, -1764.78, 1654.13, 20.99363, 4.014257, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Injured Citizen (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+754, 44470, 654, 4755, 0, 1, 172, 0, 0, 0, -1760.32, 1652.16, 20.99393, 1.884956, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Injured Citizen (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+755, 44468, 654, 4755, 0, 1, 172, 0, 0, 0, -1759.36, 1652.85, 20.99393, 2.75762, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Sister Almyra (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+756, 44470, 654, 4755, 0, 1, 172, 0, 0, 0, -1761.89, 1650.96, 20.99393, 5.742133, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Injured Citizen (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+757, 44461, 654, 4755, 0, 1, 172, 0, 0, 0, -1734.89, 1637.4, 20.70203, 5.934119, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Huntsman Blake (Area: 0 - Difficulty: 0)
(@CGUID+758, 44470, 654, 4755, 0, 1, 172, 0, 0, 0, -1762.8, 1654.74, 20.99373, 2.007129, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Injured Citizen (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+759, 4075, 654, 4755, 0, 1, 172, 0, 0, 0, -1720.707, 1629.158, 20.6074, 2.620029, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: 0 - Difficulty: 0)
(@CGUID+760, 44460, 654, 4755, 0, 1, 172, 0, 0, 0, -1767.57, 1657.62, 20.99343, 5.72468, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Gwen Armstead (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+761, 35554, 654, 4755, 0, 1, 172, 0, 0, 0, -1746.719, 1652.63, 20.52352, 1.151917, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Shaken Survivor (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+762, 44470, 654, 4755, 0, 1, 172, 0, 0, 0, -1758.17, 1654.24, 20.99403, 5.77704, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Injured Citizen (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+763, 44459, 654, 4755, 0, 1, 172, 0, 0, 0, -1764.99, 1658.86, 20.99353, 5.445427, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Celestine of the Harvest (Area: 0 - Difficulty: 0) (Auras: 13236 - Nature Channeling)
(@CGUID+764, 35554, 654, 4755, 0, 1, 172, 0, 0, 0, -1750.405, 1653.955, 20.49492, 0.9075712, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Shaken Survivor (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+765, 44470, 654, 4755, 0, 1, 172, 0, 0, 0, -1760.73, 1656.72, 20.99373, 4.014257, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Injured Citizen (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+766, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1652.622, 1709.967, 20.58432, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+767, 35554, 654, 4755, 0, 1, 172, 0, 0, 0, -1755.108, 1665.076, 21.81791, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Shaken Survivor (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+768, 44464, 654, 4755, 0, 1, 172, 0, 0, 0, -1765.03, 1667.14, 22.37123, 5.689773, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Loren the Fence (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+769, 35552, 654, 4755, 0, 1, 172, 0, 0, 0, -1735.88, 1656.62, 20.56363, 2.129302, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Lord Darius Crowley (Area: 0 - Difficulty: 0) (Auras: 67503 - Rebel Valor)
(@CGUID+770, 35911, 654, 4755, 0, 1, 172, 0, 0, 0, -1740.59, 1663.13, 20.56363, 4.886922, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- King Genn Greymane (Area: 0 - Difficulty: 0)
(@CGUID+771, 44465, 654, 4755, 0, 1, 172, 0, 0, 0, -1732.12, 1648.08, 20.58433, 3.054326, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Myriam Spellwaker (Area: 0 - Difficulty: 0)
(@CGUID+772, 4075, 654, 4755, 0, 1, 172, 0, 0, 0, -1745.051, 1654.349, 20.42433, 5.382618, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: 0 - Difficulty: 0)
(@CGUID+773, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1631.29, 1692.815, 20.55083, 1.967758, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+774, 35554, 654, 4755, 0, 1, 172, 0, 0, 0, -1730.168, 1653.691, 20.58432, 2.6529, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Shaken Survivor (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+775, 44427, 654, 4755, 0, 1, 172, 0, 0, 0, -1737.68, 1655.11, 20.56283, 1.64061, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Crowley's Horse (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+776, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1640.988, 1704.443, 20.56139, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+777, 35554, 654, 4755, 0, 1, 172, 0, 0, 0, -1748.46, 1656.115, 20.50162, 0.9250245, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Shaken Survivor (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+778, 35554, 654, 4755, 0, 1, 172, 0, 0, 0, -1730.604, 1651.448, 20.58432, 2.565634, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Shaken Survivor (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+779, 35554, 654, 4755, 0, 1, 172, 0, 0, 0, -1752.019, 1662.146, 21.81791, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Shaken Survivor (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+780, 35554, 654, 4755, 0, 1, 172, 0, 0, 0, -1750.434, 1668.642, 21.81791, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Shaken Survivor (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+781, 35554, 654, 4755, 0, 1, 172, 0, 0, 0, -1755.608, 1674.998, 21.81791, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Shaken Survivor (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+782, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1635.057, 1710.239, 20.58983, 2.874167, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+783, 44455, 654, 4755, 0, 1, 172, 0, 0, 0, -1731.34, 1657.62, 20.57063, 3.665191, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Sergeant Cleese (Area: 0 - Difficulty: 0)
(@CGUID+784, 35551, 654, 4755, 0, 1, 172, 0, 0, 0, -1734, 1662.89, 20.56363, 3.490659, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Prince Liam Greymane (Area: 0 - Difficulty: 0)
(@CGUID+785, 35554, 654, 4755, 0, 1, 172, 0, 0, 0, -1749.047, 1679.066, 21.81791, 5.305801, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Shaken Survivor (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+786, 35554, 654, 4755, 0, 1, 172, 0, 0, 0, -1741.802, 1673.792, 21.81791, 3.874631, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Shaken Survivor (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+787, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1591.649, 1639.243, 20.80508, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+788, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1635.914, 1726.119, 21.29574, 0.3775561, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+789, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1641.954, 1725.178, 21.29583, 2.072681, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+790, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1619.158, 1711.749, 22.50085, 3.035452, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+791, 50471, 654, 4755, 4758, 1, 172, 0, 0, 0, -1748.098, 1509.577, 26.27493, 3.067861, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Greymane Court - Difficulty: 0)
(@CGUID+792, 4075, 654, 4755, 4758, 1, 172, 0, 0, 0, -1721.054, 1671.668, 20.52616, 4.7315, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Greymane Court - Difficulty: 0)
(@CGUID+793, 50471, 654, 4755, 4758, 1, 172, 0, 0, 0, -1766.413, 1513.141, 26.30628, 3.316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Greymane Court - Difficulty: 0)
(@CGUID+794, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1581.292, 1622.759, 20.83248, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+795, 4075, 654, 4755, 4758, 1, 172, 0, 0, 0, -1688.832, 1649.287, 20.61058, 4.701189, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Greymane Court - Difficulty: 0)
(@CGUID+796, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1577.932, 1626.953, 20.76298, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+797, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1582.194, 1640.776, 20.77001, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+798, 50471, 654, 4755, 4758, 1, 172, 0, 0, 0, -1769.906, 1514.127, 25.89461, 2.844887, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Greymane Court - Difficulty: 0)
(@CGUID+799, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1595.026, 1708.665, 20.58986, 2.766437, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+800, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1588.604, 1685.367, 20.60992, 1.412326, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+801, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1579.151, 1674.623, 20.60992, 0.05444579, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+802, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1565.693, 1661.338, 20.60992, 0.4486424, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+803, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1571.713, 1686.37, 20.60992, 1.021555, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+804, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1567.799, 1629.111, 21.09017, 5.548601, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+805, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1570.419, 1631.411, 20.67582, 2.501606, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+806, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1562.623, 1631.934, 20.85992, 5.316223, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+807, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1571.09, 1660.012, 20.60992, 2.262483, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+808, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1569.017, 1675.512, 20.64554, 3.804818, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+809, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1553.049, 1645.807, 20.60992, 6.241207, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+810, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1568.481, 1675.498, 20.63037, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+811, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1569.379, 1706.066, 20.58986, 5.066102, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+812, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1575.252, 1633.707, 20.63508, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+813, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1573.2, 1710.519, 20.58986, 1.319262, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+814, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1576.632, 1650.339, 20.57547, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+815, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1569.012, 1686.951, 20.75, 3.595378, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+816, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1575.387, 1632.431, 20.61754, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+817, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1572.181, 1671.609, 20.59549, 4.014257, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+818, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1571.017, 1644.951, 20.58359, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+819, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1579.229, 1672.809, 20.57273, 4.031711, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+820, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1566.306, 1680.399, 20.57465, 3.682645, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+821, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1553.966, 1657.794, 20.60992, 2.316462, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+822, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1575.623, 1676.594, 20.77257, 3.909538, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+823, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1570.83, 1627.345, 20.61968, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+824, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1565.45, 1647.733, 20.56825, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+825, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1572.792, 1618.106, 20.67422, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+826, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1572.63, 1682.483, 20.647, 3.735005, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+827, 4075, 654, 4755, 4758, 1, 172, 0, 0, 0, -1671.579, 1620.622, 20.61058, 0.5060208, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Greymane Court - Difficulty: 0)
(@CGUID+828, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1556.044, 1674.495, 20.60992, 2.685451, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+829, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1567.25, 1636.655, 20.73294, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+830, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1573.307, 1641.491, 20.62816, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+831, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1567.498, 1621.637, 20.58333, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+832, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1576.531, 1679.274, 20.84377, 4.452699, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+833, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1547.585, 1643.332, 20.56825, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+834, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1547.395, 1610.938, 20.48554, 4.391389, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+835, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1549.071, 1607.944, 21.61214, 0.7513461, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+836, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1547.127, 1613.251, 20.60992, 3.076198, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+837, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1546.386, 1611.262, 20.60992, 0.0822799, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+838, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1545.319, 1657.25, 20.56825, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+839, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1546.757, 1610.106, 20.56887, 5.094086, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+840, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1548.611, 1612.673, 20.60992, 6.183802, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+841, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1545.313, 1613.021, 20.60992, 4.248742, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+842, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1556.25, 1710.416, 20.59575, 2.184042, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+843, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1544.271, 1611.979, 20.60992, 3.681043, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+844, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1550.875, 1711.374, 20.59575, 1.011473, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+845, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1545.391, 1677.013, 20.70542, 4.907635, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+846, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1540.839, 1650.399, 20.58919, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+847, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1542.438, 1671.901, 20.61111, 4.747295, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+848, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1542.809, 1679.042, 20.79861, 4.747295, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+849, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1541.326, 1659.11, 20.60992, 4.097472, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+850, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1542.74, 1674.582, 20.68429, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+851, 4075, 654, 4755, 4758, 1, 172, 0, 0, 0, -1645.88, 1673.467, 20.53271, 3.284411, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Greymane Court - Difficulty: 0)
(@CGUID+852, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1544.546, 1696.755, 20.60992, 3.834562, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+853, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1555.436, 1625.783, 20.79516, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+854, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1542.36, 1687.596, 20.60992, 2.608137, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+855, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1541.149, 1694.974, 20.57747, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+856, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1538.401, 1657.207, 20.58791, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+857, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1543.696, 1610.916, 20.64965, 5.14318, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+858, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1539.335, 1672.689, 20.60992, 1.848512, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+859, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1537.134, 1668.095, 20.56825, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+860, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1537.938, 1669.667, 20.56825, 4.625123, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+861, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1539.072, 1613.437, 20.60992, 4.91555, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+862, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1538.326, 1676.351, 20.62554, 4.642576, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+863, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1533.387, 1662.943, 20.61247, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+864, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1536.406, 1613.8, 20.60992, 4.407624, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+865, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1539.483, 1608.435, 22.02348, 0.8326259, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+866, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1528.556, 1662.396, 20.56991, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+867, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1530.06, 1661.538, 20.60992, 1.375643, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+868, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1526.774, 1672.163, 21.14063, 4.380776, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+869, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1532.576, 1668.089, 20.70447, 4.485496, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+870, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1527.891, 1679.512, 21.09798, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+871, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1538.828, 1607.976, 22.27796, 1.086011, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+872, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1524.524, 1671.315, 21.23431, 0.5283892, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+873, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1536.979, 1611.979, 20.48554, 4.578099, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+874, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1525.713, 1655.847, 20.60992, 0.04958549, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+875, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1516.266, 1663.562, 20.73492, 1.670897, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+876, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1521.263, 1672.271, 21.10992, 0.6001306, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+877, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1531.925, 1674.715, 20.77431, 4.502949, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+878, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1532.49, 1654.474, 20.82552, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+879, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1533.868, 1685.939, 20.72612, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+880, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1513.874, 1594.72, 21.11072, 1.262488, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+881, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1525.478, 1602.952, 21.89165, 1.145671, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+882, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1512.824, 1622.502, 20.61054, 3.044244, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+883, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1522.132, 1608.777, 20.61054, 4.105892, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+884, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1524.492, 1606.784, 20.61054, 3.074504, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+885, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1515.107, 1600.288, 20.61054, 5.380086, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+886, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1512.278, 1598.298, 20.61053, 3.660435, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+887, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1515.712, 1599.657, 20.65541, 5.584325, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+888, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1513.021, 1598.438, 20.61053, 0.03600139, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+889, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1513.352, 1598.78, 20.61053, 0.600765, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+890, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1523.69, 1606.712, 20.61054, 4.209234, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+891, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1512.312, 1600.857, 20.61054, 4.445843, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+892, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1513.182, 1648.819, 20.60992, 6.256214, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+893, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1524.827, 1602.739, 21.81232, 1.362401, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+894, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1511.093, 1591.52, 20.85522, 5.309209, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+895, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1523.178, 1605.939, 20.61054, 5.207413, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+896, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1520.878, 1607.447, 20.61054, 5.389186, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+897, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1513.963, 1598.377, 20.61053, 3.705605, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+898, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1506.74, 1689.609, 20.60992, 4.335462, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+899, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1503.937, 1645.838, 20.60992, 1.401211, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+900, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1510.675, 1636.139, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+901, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1511.049, 1623.622, 20.61054, 1.718672, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+902, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1510.051, 1638.197, 20.60992, 0.5674251, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+903, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1514.46, 1601.225, 20.61054, 5.078954, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+904, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1494.11, 1682.133, 20.6096, 0.6011815, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+905, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1497.734, 1628.078, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+906, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1520.064, 1566.929, 26.53265, 2.918723, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+907, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1492.655, 1636.46, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+908, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1509.32, 1592.152, 20.61053, 4.789409, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+909, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1491.854, 1662.354, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+910, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1509.489, 1592.135, 20.61053, 4.835588, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+911, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1509.849, 1592.072, 20.61053, 4.93537, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+912, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1510.221, 1591.967, 20.61053, 5.040815, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+913, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1494.356, 1644.056, 20.61054, 2.731191, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+914, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1497.382, 1628.24, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+915, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1495.419, 1637.227, 20.61054, 0.5379505, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+916, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1488.039, 1653.688, 20.61054, 2.215276, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+917, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1505.648, 1577.324, 20.88468, 1.848905, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+918, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1505.729, 1565.104, 20.55082, 2.540735, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+919, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1486.101, 1670.07, 20.6096, 0.9287285, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+920, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1488.785, 1669.26, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+921, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1503.214, 1564.542, 20.96792, 2.730097, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+922, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1485.363, 1654.872, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+923, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1481.413, 1614.206, 20.61054, 5.375309, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+924, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1479.786, 1670.735, 20.6096, 5.510816, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+925, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1505.196, 1564.52, 20.83101, 3.851781, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+926, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1486.297, 1608.044, 20.61054, 2.037755, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+927, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1487.099, 1646.846, 20.61054, 0.5673299, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+928, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1483.325, 1605.934, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+929, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1489.071, 1645.182, 20.61054, 1.301282, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+930, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1505.729, 1566.146, 20.55082, 1.570796, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+931, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1504.649, 1567.387, 20.61053, 4.323196, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+932, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1502.407, 1563.616, 20.98853, 3.037641, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+933, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1471.912, 1626.082, 20.61054, 3.742743, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+934, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1469.755, 1656.703, 20.61054, 2.470408, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+935, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1477.302, 1656.328, 20.61054, 5.190209, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+936, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1478.102, 1646.113, 20.61054, 1.473317, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+937, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1470.555, 1626.791, 20.61054, 1.342795, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+938, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1482.4, 1592.636, 20.61054, 6.263905, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+939, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1474.981, 1618.252, 20.61054, 0.3649602, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+940, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1493.464, 1541.554, 20.73554, 1.21336, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+941, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1491.091, 1554.72, 20.61054, 1.162939, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+942, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1481.764, 1603.568, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+943, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1486.317, 1586.549, 20.61054, 2.478844, 120, 10, 0, 0, 0, 1, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+944, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1485.137, 1545.34, 20.63842, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+945, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1478.49, 1570.66, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+946, 50471, 654, 4755, 4758, 1, 172, 0, 0, 0, -1755.747, 1513.792, 26.30628, 3.316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Afflicted Gilnean (Area: Greymane Court - Difficulty: 0)
(@CGUID+947, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1569.4, 1680.01, 20.62353, 5.211932, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0) (Auras: )
(@CGUID+948, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1463.674, 1663.509, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+949, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1467.083, 1619.84, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+950, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1460.509, 1625.913, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+951, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1468.375, 1610.901, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+952, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1459.144, 1657.638, 20.61054, 0.7170594, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+953, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1457.369, 1645.081, 20.61054, 1.946729, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+954, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1450.749, 1665.401, 20.61054, 0.775319, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+955, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1445.148, 1682.257, 20.56888, 4.031711, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+956, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1462.198, 1631.562, 20.61054, 1.571582, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+957, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1461.109, 1635.227, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+958, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1447.191, 1675.406, 20.56887, 4.014257, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+959, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1458.177, 1622.27, 20.61054, 3.735652, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+960, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1441.826, 1678.22, 20.56888, 3.909538, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+961, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1455.873, 1621.101, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+962, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1449.453, 1630.363, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+963, 4075, 654, 4755, 4758, 1, 172, 0, 0, 0, -1538.197, 1673.28, 20.63907, 2.355481, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Greymane Court - Difficulty: 0)
(@CGUID+964, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1460.04, 1625.441, 20.61054, 3.512687, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+965, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1439.177, 1668.51, 20.56887, 3.682645, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+966, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1432.345, 1670.405, 20.56887, 3.595378, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+967, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1443.7, 1671.793, 20.56887, 3.804818, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+968, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1453.991, 1630.91, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+969, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1452.576, 1631.301, 20.61054, 2.373015, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+970, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1436.344, 1674.536, 20.56888, 3.735005, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+971, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1445.217, 1625.257, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+972, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1464.163, 1584.979, 20.83926, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+973, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1452.376, 1596.786, 20.68366, 3.709406, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+974, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1462.028, 1586.967, 20.80812, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+975, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1470.457, 1577.96, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+976, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1470.396, 1581.286, 20.60655, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+977, 4075, 654, 4755, 4758, 1, 172, 0, 0, 0, -1565.231, 1627.656, 20.86602, 3.998843, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Greymane Court - Difficulty: 0)
(@CGUID+978, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1473.31, 1571.881, 20.61054, 2.127095, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+979, 35229, 654, 4755, 4758, 1, 172, 0, 0, 0, -1438.868, 1636.081, 20.61054, 0.8629105, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Greymane Court - Difficulty: 0)
(@CGUID+980, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1434.07, 1618.807, 20.61054, 3.450052, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+981, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1461.351, 1570.427, 20.57662, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+982, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1443.552, 1588.415, 20.73554, 1.742603, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+983, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1425.063, 1610.361, 20.58984, 3.09043, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+984, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1454.431, 1575.026, 20.62816, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+985, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1455.545, 1581.023, 20.86054, 0.5041659, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+986, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1474.738, 1564.786, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+987, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1455.352, 1579.851, 20.77096, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+988, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1476.491, 1554.091, 20.727, 4.770686, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+989, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1481.665, 1549.939, 20.86006, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+990, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1445.532, 1595.7, 20.41266, 4.257154, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+991, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1461.993, 1573.932, 20.70747, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+992, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1448.279, 1563.828, 20.61054, 0.2684954, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+993, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1477.05, 1540.513, 20.61054, 3.859549, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+994, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1465.304, 1548.628, 20.61054, 2.397149, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+995, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1438.533, 1572.833, 20.8981, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+996, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1482.887, 1535.017, 20.87049, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+997, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1463.561, 1559.607, 20.61054, 1.556043, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+998, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1442.974, 1577.82, 20.88654, 4.294116, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+999, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1484.109, 1533.401, 20.87567, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+1000, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1437.926, 1573.495, 20.99701, 5.417018, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+1001, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1446.887, 1568.714, 20.6602, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+1002, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1459.153, 1523.677, 20.60095, 2.052628, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+1003, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1458.127, 1527.064, 20.59778, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+1004, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1411.426, 1555.027, 20.55698, 1.735069, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+1005, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1478.952, 1513.816, 20.60095, 2.750952, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+1006, 36057, 654, 4755, 0, 1, 172, 0, 0, 0, -1524.172, 1605.837, 20.56887, 5.835415, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Northgate Rebel (Area: 0 - Difficulty: 0)
(@CGUID+1007, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1412.576, 1572.133, 20.58984, 2.435014, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+1008, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1454.479, 1527.574, 20.68424, 4.426008, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+1009, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1461.245, 1527.719, 20.60095, 5.84154, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+1010, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1465.122, 1515.106, 20.57019, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+1011, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1452.513, 1522.339, 20.70914, 0.2405661, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+1012, 36057, 654, 4755, 0, 1, 172, 0, 0, 0, -1537.352, 1610.778, 20.56887, 3.11985, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Northgate Rebel (Area: 0 - Difficulty: 0)
(@CGUID+1013, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1424.017, 1554.649, 20.55698, 0.1794786, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+1014, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1478.214, 1520.303, 20.77184, 4.195181, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+1015, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1443.006, 1539.675, 20.61054, 3.820926, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+1016, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1439.074, 1553.287, 20.61054, 6.122747, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+1017, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1464.799, 1530.75, 20.58896, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+1018, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1425.84, 1572.026, 20.65065, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+1019, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1467.931, 1536.267, 21.58475, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+1020, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1437.057, 1559.253, 20.61054, 1.207458, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+1021, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1473.257, 1530.587, 20.68695, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+1022, 36057, 654, 4755, 0, 1, 172, 0, 0, 0, -1543.222, 1593.944, 26.62166, 5.113521, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Northgate Rebel (Area: 0 - Difficulty: 0)
(@CGUID+1023, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1427.688, 1540.552, 20.68059, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+1024, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1420.124, 1585.935, 20.58984, 3.139843, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+1025, 35229, 654, 4755, 0, 1, 172, 0, 0, 0, -1489.856, 1525.296, 21.00293, 3.972361, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: 0 - Difficulty: 0)
(@CGUID+1026, 36057, 654, 4755, 0, 1, 172, 0, 0, 0, -1546.757, 1610.106, 20.56887, 1.570796, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Northgate Rebel (Area: 0 - Difficulty: 0)
(@CGUID+1027, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1436.822, 1529.454, 20.61975, 2.376629, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1028, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1440.58, 1519.75, 20.8914, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1029, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1439.085, 1515.434, 20.58447, 1.832596, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1030, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1462.451, 1514.757, 20.60095, 4.630144, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1031, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1435.479, 1519.219, 20.65972, 2.042035, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1032, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1445.286, 1518.646, 20.65088, 4.644417, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1033, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1440.629, 1527.302, 20.73973, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1034, 36057, 654, 4755, 4759, 1, 172, 0, 0, 0, -1526.024, 1585.354, 26.62065, 1.502035, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Northgate Rebel (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1035, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1422.409, 1527.202, 20.5646, 4.139052, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1036, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1486.848, 1503.883, 20.87939, 2.600354, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1037, 36057, 654, 4755, 4759, 1, 172, 0, 0, 0, -1536.83, 1591.826, 26.62194, 2.325644, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Northgate Rebel (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1038, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1426.161, 1523.024, 20.56955, 2.478368, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1039, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1430.295, 1535.651, 20.69854, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1040, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1406.417, 1543.52, 20.55698, 1.007639, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1041, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1428.868, 1529.576, 20.77604, 2.670354, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1042, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1432.486, 1525.108, 20.96528, 2.356194, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1043, 36057, 654, 4755, 4759, 1, 172, 0, 0, 0, -1513.146, 1597.802, 20.56887, 1.570796, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Northgate Rebel (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1044, 35317, 654, 4755, 4759, 1, 172, 0, 0, 0, -1509.727, 1593.285, 20.56887, 0.418879, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rebel Cannon (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1045, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1404.216, 1559.235, 20.55698, 5.677884, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1046, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1415.391, 1547.333, 20.55698, 0.6247604, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1047, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1427.757, 1537.93, 20.68198, 0.9851462, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1048, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1441.249, 1523.606, 20.97595, 2.964524, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1049, 35317, 654, 4755, 4759, 1, 172, 0, 0, 0, -1522.68, 1576.44, 26.53769, 0.4886922, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rebel Cannon (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1050, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1432.036, 1514.234, 20.74479, 2.076942, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1051, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1418.31, 1518.308, 20.56606, 3.322854, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1052, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1438.902, 1511.807, 20.60095, 0.8217489, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1053, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1403.715, 1537.347, 20.55698, 2.577238, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1054, 35618, 654, 4755, 4759, 1, 172, 0, 0, 0, -1540.45, 1572.61, 29.28853, 0.715585, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Tobias Mistmantle (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1055, 35317, 654, 4755, 4759, 1, 172, 0, 0, 0, -1504.372, 1583.052, 20.48572, 0.3316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rebel Cannon (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1056, 36057, 654, 4755, 4759, 1, 172, 0, 0, 0, -1505.911, 1578.247, 20.60233, 4.59393, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Northgate Rebel (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1057, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1400.337, 1529.663, 20.64216, 5.426582, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1058, 36057, 654, 4755, 4759, 1, 172, 0, 0, 0, -1509.038, 1588.497, 20.56887, 1.966453, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Northgate Rebel (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1059, 44429, 654, 4755, 4759, 1, 172, 0, 0, 0, -1539.03, 1570.91, 29.28873, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Crowley's Horse (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1060, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1409.375, 1528.125, 20.56606, 3.444999, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1061, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1424.818, 1522.13, 20.56606, 0.4480821, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1062, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1444.94, 1508.779, 20.60095, 3.928619, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1063, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1428.873, 1518.137, 20.56944, 2.268928, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1064, 36057, 654, 4755, 4759, 1, 172, 0, 0, 0, -1521.899, 1579.773, 26.61992, 5.609224, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Northgate Rebel (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1065, 36057, 654, 4755, 4759, 1, 172, 0, 0, 0, -1523.639, 1567.74, 26.62185, 6.274876, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Northgate Rebel (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1066, 35317, 654, 4755, 4759, 1, 172, 0, 0, 0, -1504.215, 1568.773, 20.48546, 5.602507, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rebel Cannon (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1067, 35317, 654, 4755, 4759, 1, 172, 0, 0, 0, -1521.599, 1558.726, 28.19049, 0.1047198, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rebel Cannon (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1068, 36057, 654, 4755, 4759, 1, 172, 0, 0, 0, -1506.04, 1563.995, 20.56887, 3.282701, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Northgate Rebel (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1069, 35317, 654, 4755, 4759, 1, 172, 0, 0, 0, -1522.51, 1569.66, 26.53678, 6.126106, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rebel Cannon (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1070, 35317, 654, 4755, 4759, 1, 172, 0, 0, 0, -1515.845, 1552.627, 28.10939, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rebel Cannon (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1071, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1481.766, 1619.983, 24.49369, 3.756897, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1072, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1463.59, 1656.58, 20.56883, 4.011911, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1073, 4075, 654, 4755, 4759, 1, 172, 0, 0, 0, -1486.889, 1541.185, 20.7381, 3.309861, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1074, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1492.47, 1652.83, 20.56883, 4.118817, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1075, 4075, 654, 4755, 4759, 1, 172, 0, 0, 0, -1442.282, 1579.115, 20.86054, 5.094589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1076, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1485.75, 1664.37, 20.56883, 4.131517, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1077, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1492.51, 1663.36, 20.56883, 4.209224, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1078, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1501.34, 1651.94, 20.56883, 4.252816, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1079, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1484.08, 1655.13, 20.56883, 4.029567, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1080, 4075, 654, 4755, 4759, 1, 172, 0, 0, 0, -1423.973, 1529.619, 20.65734, 3.426554, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Rat (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1081, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1442.58, 1527.46, 20.69613, 3.461719, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1082, 36057, 654, 4755, 4759, 1, 172, 0, 0, 0, -1578.75, 1528.743, 29.34149, 0.8901179, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Northgate Rebel (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1083, 36057, 654, 4755, 4759, 1, 172, 0, 0, 0, -1588.887, 1539.076, 29.33588, 0.6632251, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Northgate Rebel (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1084, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1472.02, 1664.82, 20.56883, 4.161993, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1085, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1543.414, 1652.647, 24.25841, 4.856165, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1086, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1449.4, 1656.5, 20.56883, 3.885785, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1087, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1485.66, 1622.61, 20.56883, 3.875825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1088, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1465.26, 1665.83, 20.56883, 4.099041, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1089, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1422.142, 1545.318, 20.66782, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1090, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1569.4, 1680.01, 20.62353, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1091, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1534.81, 1678.38, 20.69953, 5.124135, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1092, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1442.46, 1576.4, 20.77533, 3.325181, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1093, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1415.98, 1558.04, 20.56253, 2.27141, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1094, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1476.88, 1665.26, 20.56883, 4.040174, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1095, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1417.32, 1526.83, 20.81423, 2.438991, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1096, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1458.83, 1532.5, 20.56883, 2.657984, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1097, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1432.34, 1514.14, 20.77083, 4.167494, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1098, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1476.305, 1549.377, 25.04453, 2.68468, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1099, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1465.17, 1624.06, 20.56883, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1100, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1485.75, 1664.37, 20.56883, 4.131517, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1101, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1483.65, 1664.25, 20.56883, 4.105886, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1102, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1492.47, 1652.83, 20.56883, 4.118817, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1103, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1475.22, 1656.02, 20.56883, 4.134988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1104, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1484.08, 1655.13, 20.56883, 4.029567, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1105, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1460.22, 1634.1, 20.56883, 3.742735, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1106, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1469.09, 1633.21, 20.56883, 3.818596, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1107, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1501.34, 1651.94, 20.56883, 4.252816, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1108, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1476.88, 1665.26, 20.56883, 4.040174, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1109, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1491.895, 1616.983, 24.59634, 3.875825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1110, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1492.51, 1663.36, 20.56883, 4.209224, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1111, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1544.16, 1657.8, 20.56823, 4.500988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1112, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1472.02, 1664.82, 20.56883, 4.161993, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1113, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1463.59, 1656.58, 20.56883, 4.011911, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1114, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1480.85, 1653.4, 20.56883, 4.18615, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1115, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1465.26, 1665.83, 20.56883, 4.099041, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1116, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1461.03, 1655.93, 20.56883, 5.139096, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1117, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1448.6, 1634.66, 20.56883, 3.660445, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1118, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1469.9, 1655.04, 20.56883, 4.065339, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1119, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1443.81, 1545.19, 20.56883, 2.594656, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1120, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1465.17, 1624.06, 20.56883, 3.64231, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1121, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1534.81, 1678.38, 20.69953, 5.124135, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1122, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1555.3, 1697.47, 20.56823, 4.905379, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1123, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1501.34, 1651.94, 20.56883, 4.252816, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1124, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1476.79, 1623.5, 20.56883, 3.756897, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1125, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1449.4, 1656.5, 20.56883, 3.885785, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1126, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1485.66, 1622.61, 20.56883, 3.875825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1127, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1529.97, 1658.738, 21.08091, 4.559667, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1128, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1484.08, 1655.13, 20.56883, 4.029567, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1129, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1469.09, 1633.21, 20.56883, 3.818596, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1130, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1465.26, 1665.83, 20.56883, 4.099041, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1131, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1475.22, 1656.02, 20.56883, 4.134988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1132, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1469.9, 1655.04, 20.56883, 4.065339, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1133, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1483.65, 1664.25, 20.56883, 4.105886, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1134, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1448.6, 1634.66, 20.56883, 3.660445, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1135, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1480.85, 1653.4, 20.56883, 4.18615, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1136, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1460.22, 1634.1, 20.56883, 3.742735, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1137, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1485.66, 1622.61, 20.56883, 3.875825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1138, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1485.75, 1664.37, 20.56883, 4.131517, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1139, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1472.02, 1664.82, 20.56883, 4.161993, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1140, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1465.17, 1624.06, 20.56883, 3.64231, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1141, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1492.51, 1663.36, 20.56883, 4.209224, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1142, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1566.873, 1628.275, 21.8902, 5.548601, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1143, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1492.47, 1652.83, 20.56883, 4.118817, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1144, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1531.03, 1678.73, 21.01523, 4.8657, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1145, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1540.93, 1665.62, 20.56823, 4.928545, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1146, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1442.58, 1527.46, 20.69613, 3.461719, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1147, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1552.91, 1682, 20.56823, 4.766211, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1148, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1479.748, 1621.409, 23.05213, 3.756897, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1149, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1530.445, 1655.655, 23.4204, 4.559667, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1150, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1463.59, 1656.58, 20.56883, 4.011911, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1151, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1461.03, 1655.93, 20.56883, 5.139096, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1152, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1476.88, 1665.26, 20.56883, 4.040174, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1153, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1501.34, 1651.94, 20.56883, 4.252816, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1154, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1544.16, 1657.8, 20.56823, 4.500988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1155, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1476.79, 1623.5, 20.56883, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1156, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1483.65, 1664.25, 20.56883, 4.105886, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1157, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1460.22, 1634.1, 20.56883, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1158, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1480.85, 1653.4, 20.56883, 4.18615, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1159, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1485.75, 1664.37, 20.56883, 4.131517, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1160, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1469.09, 1633.21, 20.56883, 3.818596, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1161, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1449.4, 1656.5, 20.56883, 3.885785, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1162, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1484.08, 1655.13, 20.56883, 4.029567, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1163, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1469.9, 1655.04, 20.56883, 4.065339, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1164, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1465.17, 1624.06, 20.56883, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1165, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1492.47, 1652.83, 20.56883, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1166, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1485.66, 1622.61, 20.56883, 3.875825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1167, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1492.51, 1663.36, 20.56883, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1168, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1569.4, 1680.01, 20.62353, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1169, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1475.22, 1656.02, 20.56883, 4.134988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1170, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1587.21, 1679.06, 20.57713, 4.641073, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0) (Auras: )
(@CGUID+1171, 35229, 654, 4755, 4759, 1, 172, 0, 0, 0, -1514.918, 1620.793, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1172, 35566, 654, 4755, 4761, 1, 172, 0, 0, 0, -1619.7, 1498.03, 32.88292, 0.7853982, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Lord Darius Crowley (Area: Light's Dawn Cathedral - Difficulty: 0) (Auras: 67503 - Rebel Valor)
(@CGUID+1173, 35229, 654, 4755, 4761, 1, 172, 0, 0, 0, -1485.03, 1593.115, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1174, 35229, 654, 4755, 4761, 1, 172, 0, 0, 0, -1488.33, 1605.313, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1175, 35229, 654, 4755, 4761, 1, 172, 0, 0, 0, -1481.764, 1603.568, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1176, 35229, 654, 4755, 4761, 1, 172, 0, 0, 0, -1432.34, 1514.14, 20.77083, 4.167494, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1177, 35229, 654, 4755, 4761, 1, 172, 0, 0, 0, -1473.859, 1618.677, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1178, 35229, 654, 4755, 4761, 1, 172, 0, 0, 0, -1483.325, 1605.934, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1179, 35229, 654, 4755, 4761, 1, 172, 0, 0, 0, -1468.375, 1610.901, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1180, 35229, 654, 4755, 4761, 1, 172, 0, 0, 0, -1497.734, 1628.078, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1181, 35229, 654, 4755, 4761, 1, 172, 0, 0, 0, -1510.675, 1636.139, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1182, 35229, 654, 4755, 4761, 1, 172, 0, 0, 0, -1497.382, 1628.24, 20.56887, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Bloodfang Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1183, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1558.277, 1568.383, 29.19984, 3.71316, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1184, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1552.227, 1566.482, 29.2256, 0.7035502, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1185, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1554.786, 1570.727, 29.19917, 2.703048, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0) (Auras: 8599 - Enrage)
(@CGUID+1186, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1553.623, 1570.04, 29.18957, 2.404701, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1187, 41015, 654, 4755, 4761, 1, 179, 0, 0, 0, -1579.273, 1546.21, 29.33743, 3.658013, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Northgate Rebel (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1188, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1545.201, 1561.826, 29.1982, 1.097429, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1189, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1603.005, 1530.483, 29.23638, 2.289958, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0) (Auras: )
(@CGUID+1190, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1559.211, 1567.555, 29.20271, 6.095902, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1191, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1553.72, 1570.917, 29.1904, 5.072607, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0) (Auras: 8599 - Enrage)
(@CGUID+1192, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1570.023, 1558.912, 29.19252, 1.158583, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1193, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1550.121, 1563.688, 29.22885, 1.532578, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1194, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1558.788, 1569.206, 29.19624, 6.045046, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1195, 41015, 654, 4755, 4761, 1, 179, 0, 0, 0, -1587.554, 1537.847, 29.33993, 0.8901179, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Northgate Rebel (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1196, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1558.526, 1547.833, 29.19279, 1.359904, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1197, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1597.547, 1535.834, 29.22873, 0.4459984, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0) (Auras: )
(@CGUID+1198, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1568.411, 1560.587, 29.19242, 3.381811, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1199, 41015, 654, 4755, 4761, 1, 179, 0, 0, 0, -1605.42, 1533.241, 29.31243, 0.3427013, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Northgate Rebel (Area: Light's Dawn Cathedral - Difficulty: 0) (Auras: )
(@CGUID+1200, 41015, 654, 4755, 4761, 1, 179, 0, 0, 0, -1594.24, 1537.415, 29.31602, 0.3316673, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Northgate Rebel (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1201, 41015, 654, 4755, 4761, 1, 179, 0, 0, 0, -1593.609, 1524.2, 29.32428, 0.7679449, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Northgate Rebel (Area: Light's Dawn Cathedral - Difficulty: 0) (Auras: )
(@CGUID+1202, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1554.579, 1550.99, 29.20203, 1.77492, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1203, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1579.341, 1542.546, 29.22209, 1.552176, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0) (Auras: )
(@CGUID+1204, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1580.632, 1524.778, 29.33551, 4.782202, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0) (Auras: )
(@CGUID+1205, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1595.38, 1512.05, 29.32603, 1.570796, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0) (Auras: )
(@CGUID+1206, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1586.365, 1507.825, 29.31241, 1.832596, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1207, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1586.752, 1540.686, 29.33968, 3.874631, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0) (Auras: )
(@CGUID+1208, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1571.536, 1537.554, 29.33545, 4.974188, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0) (Auras: )
(@CGUID+1209, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1592.363, 1537.835, 29.31415, 3.438299, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0) (Auras: )
(@CGUID+1210, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1601.52, 1520.15, 29.32303, 0.8203048, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0) (Auras: )
(@CGUID+1211, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1564.031, 1555.111, 29.29027, 3.874631, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0) (Auras: 8599 - Enrage)
(@CGUID+1212, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1575.057, 1544.705, 29.32289, 2.80998, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0) (Auras: )
(@CGUID+1213, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1609.705, 1527.16, 29.31234, 5.969026, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0) (Auras: )
(@CGUID+1214, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1561.54, 1553.106, 29.2925, 3.298672, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1215, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1578.359, 1530.28, 29.33911, 4.171337, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0) (Auras: )
(@CGUID+1216, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1553.806, 1551.823, 29.28475, 2.841066, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1217, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1595.38, 1512.05, 29.32603, 1.01116, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0) (Auras: )
(@CGUID+1218, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1602.799, 1534.434, 29.31235, 1.390373, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0) (Auras: )
(@CGUID+1219, 35627, 654, 4755, 4759, 1, 179, 0, 0, 0, -1586.365, 1507.825, 29.31241, 1.832596, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1220, 35627, 654, 4755, 4759, 1, 179, 0, 0, 0, -1558.177, 1548.964, 29.28476, 2.844887, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1221, 35627, 654, 4755, 4759, 1, 179, 0, 0, 0, -1546.13, 1560.172, 29.28475, 4.974188, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Cathedral Quarter - Difficulty: 0)
(@CGUID+1222, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1555.502, 1569.983, 29.28476, 4.071931, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0) (Auras: )
(@CGUID+1223, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1553.807, 1566.149, 29.28474, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0) (Auras: )
(@CGUID+1224, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1552.158, 1569.375, 29.28475, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)
(@CGUID+1225, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1554.533, 1567.629, 29.28475, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0) (Auras: )
(@CGUID+1226, 35627, 654, 4755, 4761, 1, 179, 0, 0, 0, -1553.122, 1569.988, 29.28476, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25383); -- Frenzied Stalker (Area: Light's Dawn Cathedral - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1226;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, ''), -- Generic Trigger LAB - Multiphase
(@CGUID+1, 0, 0, 0, 1, 0, ''), -- Generic Trigger LAB - Multiphase
(@CGUID+2, 0, 0, 0, 1, 0, ''), -- Rebel Cannon
(@CGUID+3, 0, 0, 0, 1, 0, ''), -- Generic Trigger LAB - Multiphase
(@CGUID+4, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+5, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+6, 0, 0, 0, 1, 0, ''), -- Gilneas Evacuation Facing Marker (First)
(@CGUID+7, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+8, 0, 0, 0, 1, 0, ''), -- Generic Trigger LAB - Multiphase
(@CGUID+9, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+10, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+11, 0, 0, 0, 1, 0, ''), -- Generic Trigger LAB - Multiphase
(@CGUID+12, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+13, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+14, 0, 0, 0, 1, 0, ''), -- Generic Trigger LAB - Multiphase
(@CGUID+15, 0, 0, 0, 1, 0, ''), -- Gilneas Evacuation Facing Marker (Near)
(@CGUID+16, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+17, 0, 0, 0, 1, 0, ''), -- Rebel Cannon
(@CGUID+18, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+19, 0, 0, 0, 1, 0, ''), -- Gilneas Evacuation Facing Marker (Near)
(@CGUID+20, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+21, 0, 0, 0, 1, 0, ''), -- Generic Trigger LAB - Multiphase
(@CGUID+22, 0, 0, 0, 1, 0, ''), -- Rebel Cannon
(@CGUID+23, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+24, 0, 2410, 0, 1, 0, ''), -- Prince Liam Greymane
(@CGUID+25, 0, 0, 3, 1, 0, ''), -- Cat
(@CGUID+26, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+27, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+28, 0, 0, 0, 1, 0, ''), -- Rebel Cannon
(@CGUID+29, 0, 0, 0, 1, 0, ''), -- Gilneas Evacuation Facing Marker (First)
(@CGUID+30, 0, 0, 0, 1, 0, ''), -- Rebel Cannon
(@CGUID+31, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+32, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+33, 0, 0, 0, 1, 0, ''), -- Gilneas Evacuation Facing Marker (First)
(@CGUID+34, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+35, 0, 0, 0, 1, 0, ''), -- Rebel Cannon
(@CGUID+36, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+37, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+38, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+39, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+40, 0, 0, 0, 1, 0, ''), -- Rebel Cannon
(@CGUID+41, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+42, 0, 0, 0, 1, 0, '39662'), -- Shadowy Figure - 39662 - Vertex Color Black
(@CGUID+43, 0, 0, 0, 1, 0, ''), -- Panicked Citizen
(@CGUID+44, 0, 0, 0, 1, 0, ''), -- Frightened Chicken
(@CGUID+45, 0, 0, 0, 1, 0, ''), -- Generic Trigger LAB - Multiphase
(@CGUID+46, 0, 0, 0, 1, 0, ''), -- Panicked Citizen
(@CGUID+47, 0, 0, 0, 1, 0, ''), -- Frightened Chicken
(@CGUID+48, 0, 0, 0, 1, 0, ''), -- Gilneas Evacuation Facing Marker (First)
(@CGUID+49, 0, 0, 0, 1, 0, ''), -- Gilneas Evacuation Facing Marker (Near)
(@CGUID+50, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+51, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+52, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+53, 0, 0, 0, 1, 0, ''), -- Generic Trigger LAB - Multiphase
(@CGUID+54, 0, 0, 0, 1, 0, ''), -- Panicked Citizen
(@CGUID+55, 0, 0, 0, 1, 0, ''), -- Generic Trigger LAB - Multiphase
(@CGUID+56, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+57, 0, 0, 0, 1, 0, ''), -- Panicked Citizen
(@CGUID+58, 0, 0, 0, 1, 0, ''), -- Panicked Citizen
(@CGUID+59, 0, 0, 0, 1, 0, '39662'), -- Shadowy Figure - 39662 - Vertex Color Black
(@CGUID+60, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+61, 0, 0, 0, 1, 0, ''), -- Generic Trigger LAB - Multiphase
(@CGUID+62, 0, 0, 0, 1, 0, ''), -- Gilneas Evacuation Facing Marker (First)
(@CGUID+63, 0, 0, 0, 1, 0, ''), -- Panicked Citizen
(@CGUID+64, 0, 0, 0, 1, 0, '39662'), -- Shadowy Figure - 39662 - Vertex Color Black
(@CGUID+65, 0, 0, 0, 1, 0, '29266'), -- Lieutenant Walden - 29266 - Permanent Feign Death
(@CGUID+66, 0, 0, 0, 1, 0, ''), -- Gilneas Evacuation Facing Marker (First)
(@CGUID+67, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+68, 0, 14582, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+69, 0, 0, 8, 1, 0, '39662'), -- Shadowy Figure - 39662 - Vertex Color Black
(@CGUID+70, 0, 0, 0, 1, 0, '29266'), -- Slain Guard - 29266 - Permanent Feign Death
(@CGUID+71, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+72, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+73, 0, 0, 0, 1, 0, ''), -- Gilneas Evacuation Facing Marker (First)
(@CGUID+74, 0, 0, 0, 1, 0, ''), -- Frightened Chicken
(@CGUID+75, 0, 0, 0, 1, 0, ''), -- Generic Trigger LAB - Multiphase
(@CGUID+76, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+77, 0, 0, 0, 1, 0, '39662'), -- Shadowy Figure - 39662 - Vertex Color Black
(@CGUID+78, 0, 0, 0, 1, 0, '39662'), -- Shadowy Figure - 39662 - Vertex Color Black
(@CGUID+79, 0, 0, 0, 1, 0, ''), -- Gilneas Evacuation Facing Marker (Near)
(@CGUID+80, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+81, 0, 0, 0, 1, 0, '39662'), -- Shadowy Figure - 39662 - Vertex Color Black
(@CGUID+82, 0, 0, 0, 1, 0, ''), -- Panicked Citizen
(@CGUID+83, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+84, 0, 0, 0, 1, 0, ''), -- Generic Trigger LAB - Multiphase
(@CGUID+85, 0, 0, 0, 1, 0, '39662'), -- Shadowy Figure - 39662 - Vertex Color Black
(@CGUID+86, 0, 0, 0, 1, 0, ''), -- Panicked Citizen
(@CGUID+87, 0, 0, 0, 1, 0, ''), -- Frightened Chicken
(@CGUID+88, 0, 0, 3, 1, 0, ''), -- Cat
(@CGUID+89, 0, 0, 0, 1, 0, ''), -- Gilneas Evacuation Facing Marker (Near)
(@CGUID+90, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+91, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+92, 0, 0, 0, 1, 0, '39662'), -- Shadowy Figure - 39662 - Vertex Color Black
(@CGUID+93, 0, 0, 0, 1, 0, ''), -- Panicked Citizen
(@CGUID+94, 0, 0, 0, 1, 0, '29266'), -- Slain Guard - 29266 - Permanent Feign Death
(@CGUID+95, 0, 0, 8, 1, 0, '39662'), -- Shadowy Figure - 39662 - Vertex Color Black
(@CGUID+96, 0, 0, 0, 1, 0, ''), -- Panicked Citizen
(@CGUID+97, 0, 0, 0, 1, 0, ''), -- Gilneas Market Evacuation Credit
(@CGUID+98, 0, 0, 0, 1, 0, ''), -- Frightened Chicken
(@CGUID+99, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+100, 0, 0, 0, 1, 0, ''), -- Gilneas Evacuation Facing Marker (First)
(@CGUID+101, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+102, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+103, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+104, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+105, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+106, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+107, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+108, 0, 0, 0, 1, 0, ''), -- Generic Trigger LAB - Multiphase
(@CGUID+109, 0, 0, 0, 1, 0, ''), -- Gilneas Evacuation Facing Marker (First)
(@CGUID+110, 0, 0, 0, 1, 0, ''), -- Gilneas Evacuation Facing Marker (Near)
(@CGUID+111, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+112, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+113, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+114, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+115, 0, 0, 0, 1, 0, ''), -- Generic Trigger LAB - Multiphase
(@CGUID+116, 0, 0, 0, 1, 0, ''), -- Gilneas Evacuation Facing Marker (Far)
(@CGUID+117, 0, 0, 0, 1, 0, ''), -- Generic Trigger LAB - Multiphase
(@CGUID+118, 0, 0, 0, 1, 0, ''), -- Gilneas Evacuation Facing Marker (First)
(@CGUID+119, 0, 0, 0, 1, 0, ''), -- Gilneas Evacuation Facing Marker (First)
(@CGUID+120, 0, 0, 0, 1, 0, ''), -- Gilneas Evacuation Facing Marker (First)
(@CGUID+121, 0, 0, 0, 1, 0, ''), -- Generic Trigger LAB - Multiphase
(@CGUID+122, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+123, 0, 0, 0, 1, 0, ''), -- Generic Trigger LAB - Multiphase
(@CGUID+124, 0, 0, 0, 1, 0, ''), -- Gilneas Evacuation Facing Marker (First)
(@CGUID+125, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+126, 0, 0, 0, 1, 0, ''), -- Gilneas Evacuation Facing Marker (First)
(@CGUID+127, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+128, 0, 0, 0, 1, 0, ''), -- Generic Trigger LAB - Multiphase
(@CGUID+129, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+130, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+131, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+132, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+133, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+134, 0, 0, 0, 1, 0, '52385'), -- Panicked Citizen - 52385 - Cosmetic - Periodic Cower
(@CGUID+135, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+136, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+137, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+138, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+139, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+140, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+141, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+142, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+143, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+144, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+145, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+146, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+147, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+148, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+149, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+150, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+151, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+152, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+153, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+154, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+155, 0, 0, 0, 1, 0, '8599'), -- Rampaging Worgen - 8599 - Enrage
(@CGUID+156, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+157, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+158, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+159, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+160, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+161, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+162, 0, 0, 65536, 1, 0, '49414'), -- Gwen Armstead - 49414 - Generic Quest Invisibility 1
(@CGUID+163, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+164, 0, 2410, 0, 1, 0, ''), -- Prince Liam Greymane
(@CGUID+165, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+166, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+167, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+168, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+169, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+170, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+171, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+172, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+173, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+174, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+175, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+176, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+177, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+178, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+179, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+180, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+181, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+182, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+183, 0, 0, 0, 1, 0, ''), -- Frightened Chicken
(@CGUID+184, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+185, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+186, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+187, 0, 0, 0, 1, 0, ''), -- Frightened Chicken
(@CGUID+188, 0, 0, 0, 1, 0, ''), -- Frightened Chicken
(@CGUID+189, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+190, 0, 0, 0, 1, 0, ''), -- Frightened Chicken
(@CGUID+191, 0, 0, 0, 1, 0, ''), -- Frightened Chicken
(@CGUID+192, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+193, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+194, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+195, 0, 0, 0, 1, 0, ''), -- Frightened Chicken
(@CGUID+196, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+197, 0, 0, 0, 1, 0, ''), -- Frightened Chicken
(@CGUID+198, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+199, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+200, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+201, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+202, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+203, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+204, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+205, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+206, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+207, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+208, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+209, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+210, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+211, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+212, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+213, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+214, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+215, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+216, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+217, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+218, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+219, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+220, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+221, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+222, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+223, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+224, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+225, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+226, 0, 0, 0, 1, 0, ''), -- Bloodfang Bloodletter
(@CGUID+227, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+228, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+229, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+230, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+231, 0, 0, 50331648, 1, 0, ''), -- Gilnean Crow
(@CGUID+232, 0, 0, 50331648, 1, 0, ''), -- Gilnean Crow
(@CGUID+233, 0, 0, 50331648, 1, 0, ''), -- Gilnean Crow
(@CGUID+234, 0, 0, 50331648, 1, 0, ''), -- Gilnean Crow
(@CGUID+235, 0, 0, 50331648, 1, 0, ''), -- Gilnean Crow
(@CGUID+236, 0, 0, 0, 1, 0, ''), -- Gilnean Survivor
(@CGUID+237, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+238, 0, 0, 0, 1, 0, ''), -- Gilnean Survivor
(@CGUID+239, 0, 0, 0, 1, 0, ''), -- Marie Allen
(@CGUID+240, 0, 0, 0, 1, 0, ''), -- Gwen Armstead
(@CGUID+241, 0, 0, 0, 1, 0, ''), -- Gilnean Survivor
(@CGUID+242, 0, 0, 0, 1, 0, ''), -- Gilnean Survivor
(@CGUID+243, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+244, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+245, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+246, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+247, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+248, 0, 0, 0, 1, 0, ''), -- Myriam Spellwaker
(@CGUID+249, 0, 0, 0, 1, 0, ''), -- Gilnean Steed
(@CGUID+250, 0, 0, 0, 2, 0, ''), -- Huntsman Blake
(@CGUID+251, 0, 0, 8, 1, 0, ''), -- Wounded Guard
(@CGUID+252, 0, 0, 0, 1, 0, '45104'), -- Vitus Darkwalker - 45104 - Shadow Channelling
(@CGUID+253, 0, 0, 8, 1, 0, ''), -- Sister Almyra
(@CGUID+254, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+255, 0, 0, 0, 1, 0, ''), -- Fenegan Cobbler
(@CGUID+256, 0, 0, 7, 1, 0, ''), -- Injured Citizen
(@CGUID+257, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+258, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+259, 0, 0, 0, 1, 0, ''), -- Sergeant Cleese
(@CGUID+260, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+261, 0, 0, 0, 1, 0, ''), -- Baron
(@CGUID+262, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+263, 0, 0, 0, 1, 0, '13236'), -- Celestine of the Harvest - 13236 - Nature Channeling
(@CGUID+264, 0, 0, 0, 1, 0, '34189'), -- Loren the Fence - 34189 - Stealth
(@CGUID+265, 0, 0, 8, 1, 0, ''), -- Wounded Guard
(@CGUID+266, 0, 0, 8, 1, 0, ''), -- Wounded Guard
(@CGUID+267, 0, 0, 0, 1, 0, '29266'), -- Slain Guard - 29266 - Permanent Feign Death
(@CGUID+268, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+269, 0, 0, 8, 1, 0, ''), -- Wounded Guard
(@CGUID+270, 0, 0, 0, 1, 0, ''), -- Gilnean Royal Guard
(@CGUID+271, 0, 0, 0, 1, 0, '29266'), -- Slain Guard - 29266 - Permanent Feign Death
(@CGUID+272, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+273, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+274, 0, 0, 0, 1, 0, ''), -- Gilnean Royal Guard
(@CGUID+275, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+276, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+277, 0, 0, 0, 1, 0, ''), -- Bloodfang Worgen
(@CGUID+278, 0, 0, 0, 1, 0, ''), -- Gilnean Royal Guard
(@CGUID+279, 0, 0, 0, 1, 0, ''), -- Bloodfang Worgen
(@CGUID+280, 0, 0, 0, 1, 0, ''), -- Gilnean Royal Guard
(@CGUID+281, 0, 0, 0, 1, 0, ''), -- Gilnean Survivor
(@CGUID+282, 0, 0, 0, 1, 0, ''), -- Gilnean Royal Guard
(@CGUID+283, 0, 0, 0, 1, 0, ''), -- Gilnean Survivor
(@CGUID+284, 0, 0, 0, 1, 0, ''), -- Bloodfang Worgen
(@CGUID+285, 0, 0, 0, 1, 0, ''), -- Gilnean Survivor
(@CGUID+286, 0, 0, 0, 1, 0, ''), -- Bloodfang Worgen
(@CGUID+287, 0, 0, 0, 1, 0, ''), -- Gilnean Royal Guard
(@CGUID+288, 0, 0, 0, 1, 0, ''), -- Gilnean Royal Guard
(@CGUID+289, 0, 0, 0, 1, 0, ''), -- Gilnean Royal Guard
(@CGUID+290, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+291, 0, 0, 0, 1, 0, ''), -- Gilnean Royal Guard
(@CGUID+292, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+293, 0, 2410, 0, 1, 0, ''), -- King Genn Greymane
(@CGUID+294, 0, 2410, 0, 1, 0, ''), -- Lord Godfrey
(@CGUID+295, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+296, 0, 0, 0, 1, 0, ''), -- Gilnean Royal Guard
(@CGUID+297, 0, 0, 0, 1, 0, ''), -- Gilnean Royal Guard
(@CGUID+298, 0, 0, 0, 1, 0, ''), -- Gilnean Survivor
(@CGUID+299, 0, 0, 0, 1, 0, ''), -- Gilnean Royal Guard
(@CGUID+300, 0, 0, 0, 1, 0, ''), -- Gilnean Survivor
(@CGUID+301, 0, 0, 0, 1, 0, ''), -- Gilnean Survivor
(@CGUID+302, 0, 0, 0, 1, 0, ''), -- Gilnean Survivor
(@CGUID+303, 0, 0, 0, 1, 0, ''), -- Gilnean Survivor
(@CGUID+304, 0, 0, 0, 1, 0, ''), -- Gilnean Royal Guard
(@CGUID+305, 0, 0, 0, 1, 0, ''), -- Gilnean Survivor
(@CGUID+306, 0, 0, 0, 1, 0, ''), -- Gilnean Royal Guard
(@CGUID+307, 0, 0, 0, 1, 0, ''), -- Gilnean Royal Guard
(@CGUID+308, 0, 0, 0, 1, 0, ''), -- Gilnean Survivor
(@CGUID+309, 0, 0, 0, 1, 0, ''), -- Gilnean Survivor
(@CGUID+310, 0, 0, 0, 1, 0, ''), -- Gilnean Survivor
(@CGUID+311, 0, 0, 0, 1, 0, ''), -- Gilnean Royal Guard
(@CGUID+312, 0, 0, 0, 1, 0, ''), -- Gilnean Survivor
(@CGUID+313, 0, 0, 0, 1, 0, ''), -- Generic Trigger LAB - Multiphase
(@CGUID+314, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+315, 0, 0, 0, 1, 0, ''), -- Generic Trigger LAB - Multiphase
(@CGUID+316, 0, 0, 0, 1, 0, ''), -- Gilnean Royal Guard
(@CGUID+317, 0, 0, 0, 1, 0, '29266'), -- Slain Guard - 29266 - Permanent Feign Death
(@CGUID+318, 0, 0, 0, 1, 0, ''), -- Bloodfang Worgen
(@CGUID+319, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+320, 0, 0, 0, 1, 0, ''), -- Generic Trigger LAB - Multiphase
(@CGUID+321, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+322, 0, 0, 0, 1, 0, ''), -- Bloodfang Worgen
(@CGUID+323, 0, 0, 0, 1, 0, ''), -- Generic Trigger LAB - Multiphase
(@CGUID+324, 0, 0, 0, 1, 0, ''), -- Gilnean Royal Guard
(@CGUID+325, 0, 0, 0, 1, 0, ''), -- Gilnean Royal Guard
(@CGUID+326, 0, 0, 0, 1, 0, '29266'), -- Slain Guard - 29266 - Permanent Feign Death
(@CGUID+327, 0, 0, 0, 1, 0, '29266'), -- Slain Guard - 29266 - Permanent Feign Death
(@CGUID+328, 0, 0, 0, 1, 0, ''), -- Captain Broderick
(@CGUID+329, 0, 0, 0, 1, 0, ''), -- Gilnean Royal Guard
(@CGUID+330, 0, 0, 0, 1, 0, '46598'), -- Franklin Martin - 46598 - Ride Vehicle Hardcoded
(@CGUID+331, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+332, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+333, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+334, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+335, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+336, 0, 0, 8, 1, 0, ''), -- Vincent Hersham
(@CGUID+337, 0, 0, 0, 1, 0, ''), -- Tobias Mistmantle
(@CGUID+338, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+339, 0, 0, 0, 1, 0, '29266'), -- Slain Guard - 29266 - Permanent Feign Death
(@CGUID+340, 0, 0, 0, 1, 0, '67503'), -- Lord Darius Crowley - 67503 - Rebel Valor
(@CGUID+341, 0, 0, 7, 1, 0, '52165'), -- Sean Dempsey - 52165 - Cosmetic - Stun Permanent (no anim)
(@CGUID+342, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+343, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+344, 0, 0, 0, 1, 0, ''), -- Generic Trigger LAB - Multiphase
(@CGUID+345, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+346, 0, 0, 0, 1, 0, ''), -- Josiah Avery
(@CGUID+347, 0, 0, 0, 1, 0, ''), -- Generic Trigger LAB - Multiphase
(@CGUID+348, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+349, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+350, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+351, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+352, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+353, 0, 0, 0, 1, 0, ''), -- Wary Mastiff
(@CGUID+354, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+355, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+356, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+357, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+358, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+359, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+360, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+361, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+362, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+363, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+364, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+365, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+366, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+367, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+368, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+369, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+370, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+371, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+372, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+373, 0, 0, 0, 1, 0, ''), -- Bloodfang Bloodletter
(@CGUID+374, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+375, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+376, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+377, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+378, 0, 0, 0, 1, 0, '8599'), -- Worgen Runt - 8599 - Enrage
(@CGUID+379, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+380, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+381, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+382, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+383, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+384, 0, 0, 0, 1, 0, '46598'), -- Franklin Martin - 46598 - Ride Vehicle Hardcoded
(@CGUID+385, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+386, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+387, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+388, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+389, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+390, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+391, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+392, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+393, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+394, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+395, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+396, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+397, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+398, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+399, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+400, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+401, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+402, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+403, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+404, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+405, 0, 0, 0, 1, 0, ''), -- Rampaging Worgen
(@CGUID+406, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+407, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+408, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+409, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+410, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+411, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+412, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+413, 0, 0, 0, 1, 0, ''), -- Bloodfang Worgen
(@CGUID+414, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+415, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+416, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+417, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+418, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+419, 0, 0, 0, 1, 0, '83470'), -- Bloodfang Worgen - 83470 - Arcane Missiles Trainer
(@CGUID+420, 0, 0, 0, 1, 0, '8599'), -- Worgen Runt - 8599 - Enrage
(@CGUID+421, 0, 0, 0, 1, 0, '8599'), -- Worgen Runt - 8599 - Enrage
(@CGUID+422, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+423, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+424, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+425, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+426, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+427, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+428, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+429, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+430, 0, 0, 0, 1, 0, '8599'), -- Worgen Runt - 8599 - Enrage
(@CGUID+431, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+432, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+433, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+434, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+435, 0, 0, 0, 1, 0, '8599'), -- Worgen Runt - 8599 - Enrage
(@CGUID+436, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+437, 0, 0, 0, 1, 0, '8599'), -- Worgen Runt - 8599 - Enrage
(@CGUID+438, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+439, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+440, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+441, 0, 0, 0, 1, 0, '8599'), -- Worgen Runt - 8599 - Enrage
(@CGUID+442, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+443, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+444, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+445, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+446, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+447, 0, 0, 0, 1, 0, ''), -- Bloodfang Bloodletter
(@CGUID+448, 0, 0, 0, 1, 0, ''), -- Worgen Runt
(@CGUID+449, 0, 0, 0, 1, 0, '8599'), -- Worgen Runt - 8599 - Enrage
(@CGUID+450, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+451, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+452, 0, 0, 0, 2, 0, ''), -- Gilneas City Guard
(@CGUID+453, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+454, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+455, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+456, 0, 0, 0, 2, 0, ''), -- Gilneas City Guard
(@CGUID+457, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+458, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+459, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+460, 0, 0, 0, 2, 0, ''), -- Gilneas City Guard
(@CGUID+461, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+462, 0, 0, 0, 2, 0, ''), -- Gilneas City Guard
(@CGUID+463, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+464, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+465, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+466, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+467, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+468, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+469, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+470, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+471, 0, 0, 0, 2, 0, ''), -- Gilneas City Guard
(@CGUID+472, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+473, 0, 0, 0, 1, 0, ''), -- Bloodfang Lurker
(@CGUID+474, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+475, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+476, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+477, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+478, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+479, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+480, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+481, 0, 0, 0, 1, 0, ''), -- Bloodfang Lurker
(@CGUID+482, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+483, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+484, 0, 0, 0, 2, 0, ''), -- Gilneas City Guard
(@CGUID+485, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+486, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+487, 0, 0, 0, 1, 0, ''), -- Gilnean Mastiff
(@CGUID+488, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+489, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+490, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+491, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+492, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+493, 0, 2410, 0, 1, 0, ''), -- Lord Godfrey
(@CGUID+494, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+495, 0, 0, 0, 2, 0, ''), -- Gilneas City Guard
(@CGUID+496, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+497, 0, 2410, 0, 1, 0, ''), -- King Genn Greymane
(@CGUID+498, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+499, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+500, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+501, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+502, 0, 0, 0, 2, 0, ''), -- Lorna Crowley
(@CGUID+503, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+504, 0, 0, 0, 2, 0, ''), -- Gilneas City Guard
(@CGUID+505, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+506, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+507, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+508, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+509, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+510, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+511, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+512, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+513, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+514, 0, 0, 0, 2, 0, ''), -- Gilneas City Guard
(@CGUID+515, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+516, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+517, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+518, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+519, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+520, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+521, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+522, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+523, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+524, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+525, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+526, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+527, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+528, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+529, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+530, 0, 0, 0, 1, 0, ''), -- Bloodfang Lurker
(@CGUID+531, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+532, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+533, 0, 0, 0, 1, 0, ''), -- Gilnean Mastiff
(@CGUID+534, 0, 0, 0, 1, 0, ''), -- Bloodfang Lurker
(@CGUID+535, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+536, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+537, 0, 0, 0, 2, 0, ''), -- Gilneas City Guard
(@CGUID+538, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+539, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+540, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+541, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+542, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+543, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+544, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+545, 0, 0, 0, 1, 0, ''), -- Bloodfang Lurker
(@CGUID+546, 0, 0, 0, 2, 0, ''), -- Gilneas City Guard
(@CGUID+547, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+548, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+549, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+550, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+551, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+552, 0, 0, 131072, 1, 0, '5916'), -- Bloodfang Lurker - 5916 - Shadowstalker Stealth
(@CGUID+553, 0, 0, 131072, 1, 0, '5916'), -- Bloodfang Lurker - 5916 - Shadowstalker Stealth
(@CGUID+554, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+555, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+556, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+557, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+558, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+559, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+560, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+561, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+562, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+563, 0, 0, 131072, 1, 0, '5916'), -- Bloodfang Lurker - 5916 - Shadowstalker Stealth
(@CGUID+564, 0, 0, 131072, 1, 0, '5916'), -- Bloodfang Lurker - 5916 - Shadowstalker Stealth
(@CGUID+565, 0, 0, 0, 1, 0, '5916'), -- Bloodfang Lurker - 5916 - Shadowstalker Stealth
(@CGUID+566, 0, 0, 0, 1, 0, '5916'), -- Bloodfang Lurker - 5916 - Shadowstalker Stealth
(@CGUID+567, 0, 0, 0, 1, 0, ''), -- Wary Mastiff
(@CGUID+568, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+569, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+570, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+571, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+572, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+573, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+574, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+575, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+576, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+577, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+578, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+579, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+580, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+581, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+582, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+583, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+584, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+585, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+586, 0, 0, 0, 1, 0, '5916'), -- Bloodfang Lurker - 5916 - Shadowstalker Stealth
(@CGUID+587, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+588, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+589, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+590, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+591, 0, 0, 131072, 1, 0, '5916'), -- Bloodfang Lurker - 5916 - Shadowstalker Stealth
(@CGUID+592, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+593, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+594, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+595, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+596, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+597, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+598, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+599, 0, 0, 0, 1, 0, '8599'), -- Bloodfang Lurker - 8599 - Enrage
(@CGUID+600, 0, 0, 0, 1, 0, '5916'), -- Bloodfang Lurker - 5916 - Shadowstalker Stealth
(@CGUID+601, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+602, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+603, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+604, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+605, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+606, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+607, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+608, 0, 0, 50397184, 1, 0, '49414'), -- Krennan Aranas - 49414 - Generic Quest Invisibility 1
(@CGUID+609, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+610, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+611, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+612, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+613, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+614, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+615, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+616, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+617, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+618, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+619, 0, 0, 8, 1, 0, ''), -- Gilneas City Guard
(@CGUID+620, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+621, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+622, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+623, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+624, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+625, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+626, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+627, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+628, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+629, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+630, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+631, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+632, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+633, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+634, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+635, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+636, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+637, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+638, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+639, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+640, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+641, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+642, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+643, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+644, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+645, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+646, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+647, 0, 0, 8, 1, 0, ''), -- Gilneas City Guard
(@CGUID+648, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+649, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+650, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+651, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+652, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+653, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+654, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+655, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+656, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+657, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+658, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+659, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+660, 0, 0, 0, 1, 0, ''), -- Commandeered Cannon
(@CGUID+661, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+662, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+663, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+664, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+665, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+666, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+667, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+668, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+669, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+670, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+671, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+672, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+673, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+674, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+675, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+676, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+677, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+678, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+679, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+680, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+681, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+682, 0, 0, 8, 1, 0, ''), -- Gilneas City Guard
(@CGUID+683, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+684, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+685, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+686, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+687, 0, 0, 0, 1, 0, ''), -- Gilneas City Guard
(@CGUID+688, 0, 0, 0, 1, 0, ''), -- Commandeered Cannon
(@CGUID+689, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+690, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+691, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+692, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+693, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+694, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+695, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+696, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+697, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+698, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+699, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+700, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+701, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+702, 0, 0, 0, 1, 0, ''), -- Bloodfang Ripper
(@CGUID+703, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+704, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+705, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+706, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+707, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+708, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+709, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+710, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+711, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+712, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+713, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+714, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+715, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+716, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+717, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+718, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+719, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+720, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+721, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+722, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+723, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+724, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+725, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+726, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+727, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+728, 0, 0, 50331649, 1, 0, ''), -- Gilnean Crow
(@CGUID+729, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+730, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+731, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+732, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+733, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+734, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+735, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+736, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+737, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+738, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+739, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+740, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+741, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+742, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+743, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+744, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+745, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+746, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+747, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+748, 0, 0, 0, 1, 0, ''), -- Gilnean Steed
(@CGUID+749, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+750, 0, 0, 0, 1, 0, '45104'), -- Vitus Darkwalker - 45104 - Shadow Channelling
(@CGUID+751, 0, 0, 0, 1, 0, ''), -- Fenegan Cobbler
(@CGUID+752, 0, 0, 0, 1, 0, ''), -- Baron
(@CGUID+753, 0, 0, 7, 1, 0, ''), -- Injured Citizen
(@CGUID+754, 0, 0, 7, 1, 0, ''), -- Injured Citizen
(@CGUID+755, 0, 0, 8, 1, 0, ''), -- Sister Almyra
(@CGUID+756, 0, 0, 7, 1, 0, ''), -- Injured Citizen
(@CGUID+757, 0, 0, 0, 2, 0, ''), -- Huntsman Blake
(@CGUID+758, 0, 0, 7, 1, 0, ''), -- Injured Citizen
(@CGUID+759, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+760, 0, 0, 0, 1, 0, ''), -- Gwen Armstead
(@CGUID+761, 0, 0, 0, 1, 0, ''), -- Shaken Survivor
(@CGUID+762, 0, 0, 7, 1, 0, ''), -- Injured Citizen
(@CGUID+763, 0, 0, 0, 1, 0, '13236'), -- Celestine of the Harvest - 13236 - Nature Channeling
(@CGUID+764, 0, 0, 0, 1, 0, ''), -- Shaken Survivor
(@CGUID+765, 0, 0, 7, 1, 0, ''), -- Injured Citizen
(@CGUID+766, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+767, 0, 0, 0, 1, 0, ''), -- Shaken Survivor
(@CGUID+768, 0, 0, 0, 1, 0, ''), -- Loren the Fence
(@CGUID+769, 0, 0, 0, 1, 0, '67503'), -- Lord Darius Crowley - 67503 - Rebel Valor
(@CGUID+770, 0, 2410, 0, 1, 0, ''), -- King Genn Greymane
(@CGUID+771, 0, 0, 0, 1, 0, ''), -- Myriam Spellwaker
(@CGUID+772, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+773, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+774, 0, 0, 0, 1, 0, ''), -- Shaken Survivor
(@CGUID+775, 0, 0, 0, 1, 0, ''), -- Crowley's Horse
(@CGUID+776, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+777, 0, 0, 0, 1, 0, ''), -- Shaken Survivor
(@CGUID+778, 0, 0, 0, 1, 0, ''), -- Shaken Survivor
(@CGUID+779, 0, 0, 0, 1, 0, ''), -- Shaken Survivor
(@CGUID+780, 0, 0, 0, 1, 0, ''), -- Shaken Survivor
(@CGUID+781, 0, 0, 0, 1, 0, ''), -- Shaken Survivor
(@CGUID+782, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+783, 0, 0, 0, 1, 0, ''), -- Sergeant Cleese
(@CGUID+784, 0, 2410, 0, 1, 0, ''), -- Prince Liam Greymane
(@CGUID+785, 0, 0, 0, 1, 0, ''), -- Shaken Survivor
(@CGUID+786, 0, 0, 0, 1, 0, ''), -- Shaken Survivor
(@CGUID+787, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+788, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+789, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+790, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+791, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+792, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+793, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+794, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+795, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+796, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+797, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+798, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+799, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+800, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+801, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+802, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+803, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+804, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+805, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+806, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+807, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+808, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+809, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+810, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+811, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+812, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+813, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+814, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+815, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+816, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+817, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+818, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+819, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+820, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+821, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+822, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+823, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+824, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+825, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+826, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+827, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+828, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+829, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+830, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+831, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+832, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+833, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+834, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+835, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+836, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+837, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+838, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+839, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+840, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+841, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+842, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+843, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+844, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+845, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+846, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+847, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+848, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+849, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+850, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+851, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+852, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+853, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+854, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+855, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+856, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+857, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+858, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+859, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+860, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+861, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+862, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+863, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+864, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+865, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+866, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+867, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+868, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+869, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+870, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+871, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+872, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+873, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+874, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+875, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+876, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+877, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+878, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+879, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+880, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+881, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+882, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+883, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+884, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+885, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+886, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+887, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+888, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+889, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+890, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+891, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+892, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+893, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+894, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+895, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+896, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+897, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+898, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+899, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+900, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+901, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+902, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+903, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+904, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+905, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+906, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+907, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+908, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+909, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+910, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+911, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+912, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+913, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+914, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+915, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+916, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+917, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+918, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+919, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+920, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+921, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+922, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+923, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+924, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+925, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+926, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+927, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+928, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+929, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+930, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+931, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+932, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+933, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+934, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+935, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+936, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+937, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+938, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+939, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+940, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+941, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+942, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+943, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+944, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+945, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+946, 0, 0, 0, 1, 0, ''), -- Afflicted Gilnean
(@CGUID+947, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+948, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+949, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+950, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+951, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+952, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+953, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+954, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+955, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+956, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+957, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+958, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+959, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+960, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+961, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+962, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+963, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+964, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+965, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+966, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+967, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+968, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+969, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+970, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+971, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+972, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+973, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+974, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+975, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+976, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+977, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+978, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+979, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+980, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+981, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+982, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+983, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+984, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+985, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+986, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+987, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+988, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+989, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+990, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+991, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+992, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+993, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+994, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+995, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+996, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+997, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+998, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+999, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1000, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1001, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1002, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1003, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1004, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1005, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1006, 0, 0, 0, 1, 0, ''), -- Northgate Rebel
(@CGUID+1007, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1008, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1009, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1010, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1011, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1012, 0, 0, 0, 1, 0, ''), -- Northgate Rebel
(@CGUID+1013, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1014, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1015, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1016, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1017, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1018, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1019, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1020, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1021, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1022, 0, 0, 0, 1, 0, ''), -- Northgate Rebel
(@CGUID+1023, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1024, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1025, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1026, 0, 0, 0, 1, 0, ''), -- Northgate Rebel
(@CGUID+1027, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1028, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1029, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1030, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1031, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1032, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1033, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1034, 0, 0, 0, 1, 0, ''), -- Northgate Rebel
(@CGUID+1035, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1036, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1037, 0, 0, 0, 1, 0, ''), -- Northgate Rebel
(@CGUID+1038, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1039, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1040, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1041, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1042, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1043, 0, 0, 0, 1, 0, ''), -- Northgate Rebel
(@CGUID+1044, 0, 0, 0, 1, 0, ''), -- Rebel Cannon
(@CGUID+1045, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1046, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1047, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1048, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1049, 0, 0, 0, 1, 0, ''), -- Rebel Cannon
(@CGUID+1050, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1051, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1052, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1053, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1054, 0, 0, 0, 2, 0, ''), -- Tobias Mistmantle
(@CGUID+1055, 0, 0, 0, 1, 0, ''), -- Rebel Cannon
(@CGUID+1056, 0, 0, 0, 1, 0, ''), -- Northgate Rebel
(@CGUID+1057, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1058, 0, 0, 0, 1, 0, ''), -- Northgate Rebel
(@CGUID+1059, 0, 0, 0, 1, 0, ''), -- Crowley's Horse
(@CGUID+1060, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1061, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1062, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1063, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1064, 0, 0, 0, 1, 0, ''), -- Northgate Rebel
(@CGUID+1065, 0, 0, 0, 1, 0, ''), -- Northgate Rebel
(@CGUID+1066, 0, 0, 0, 1, 0, ''), -- Rebel Cannon
(@CGUID+1067, 0, 0, 0, 1, 0, ''), -- Rebel Cannon
(@CGUID+1068, 0, 0, 0, 1, 0, ''), -- Northgate Rebel
(@CGUID+1069, 0, 0, 0, 1, 0, ''), -- Rebel Cannon
(@CGUID+1070, 0, 0, 0, 1, 0, ''), -- Rebel Cannon
(@CGUID+1071, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1072, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1073, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+1074, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1075, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+1076, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1077, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1078, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1079, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1080, 0, 0, 0, 1, 0, ''), -- Rat
(@CGUID+1081, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1082, 0, 0, 0, 1, 0, ''), -- Northgate Rebel
(@CGUID+1083, 0, 0, 0, 1, 0, ''), -- Northgate Rebel
(@CGUID+1084, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1085, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1086, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1087, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1088, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1089, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1090, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1091, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1092, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1093, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1094, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1095, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1096, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1097, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1098, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1099, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1100, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1101, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1102, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1103, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1104, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1105, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1106, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1107, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1108, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1109, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1110, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1111, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1112, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1113, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1114, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1115, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1116, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1117, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1118, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1119, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1120, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1121, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1122, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1123, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1124, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1125, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1126, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1127, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1128, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1129, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1130, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1131, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1132, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1133, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1134, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1135, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1136, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1137, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1138, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1139, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1140, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1141, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1142, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1143, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1144, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1145, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1146, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1147, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1148, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1149, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1150, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1151, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1152, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1153, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1154, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1155, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1156, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1157, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1158, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1159, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1160, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1161, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1162, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1163, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1164, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1165, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1166, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1167, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1168, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1169, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1170, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1171, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1172, 0, 0, 0, 2, 0, '67503'), -- Lord Darius Crowley - 67503 - Rebel Valor
(@CGUID+1173, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1174, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1175, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1176, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1177, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1178, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1179, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1180, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1181, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1182, 0, 0, 0, 1, 0, ''), -- Bloodfang Stalker
(@CGUID+1183, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1184, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1185, 0, 0, 0, 1, 0, '8599'), -- Frenzied Stalker - 8599 - Enrage
(@CGUID+1186, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1187, 0, 0, 0, 1, 0, ''), -- Northgate Rebel
(@CGUID+1188, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1189, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1190, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1191, 0, 0, 0, 1, 0, '8599'), -- Frenzied Stalker - 8599 - Enrage
(@CGUID+1192, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1193, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1194, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1195, 0, 0, 0, 1, 0, ''), -- Northgate Rebel
(@CGUID+1196, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1197, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1198, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1199, 0, 0, 0, 1, 0, ''), -- Northgate Rebel
(@CGUID+1200, 0, 0, 0, 1, 0, ''), -- Northgate Rebel
(@CGUID+1201, 0, 0, 0, 2, 0, ''), -- Northgate Rebel
(@CGUID+1202, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1203, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1204, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1205, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1206, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1207, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1208, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1209, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1210, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1211, 0, 0, 0, 1, 0, '8599'), -- Frenzied Stalker - 8599 - Enrage
(@CGUID+1212, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1213, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1214, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1215, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1216, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1217, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1218, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1219, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1220, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1221, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1222, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1223, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1224, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1225, 0, 0, 0, 1, 0, ''), -- Frenzied Stalker
(@CGUID+1226, 0, 0, 0, 1, 0, ''); -- Frenzied Stalker


SET @OGUID := 235505;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+60;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 195327, 654, 4755, 4756, 1, 0, 379,-1513.217, 1371.139, 36.53497, 6.213374, 0, 0, -0.03489876, 0.9993908, 120, 255, 1, 25383), -- Merchant Square Door (Area: Merchant Square - Difficulty: 0)
(@OGUID+1, 196404, 654, 4755, 4756, 1, 0, 379,-1880.474, 2545.83, 3.087044, 3.822272, 0.01975298, 0.006994247, -0.9424343, 0.3337342, 120, 255, 0, 25383), -- Basement Door (Area: Merchant Square - Difficulty: 0)
(@OGUID+2, 195327, 654, 4755, 4756, 1, 0, 379,-1463.903, 1444.259, 36.59575, 4.71239, 0, 0, -0.7071066, 0.7071069, 120, 255, 1, 25383), -- Merchant Square Door (Area: Merchant Square - Difficulty: 0)
(@OGUID+3, 202591, 654, 4755, 4756, 1, 0, 379,-1496.141, 1409.729, 35.5236, 6.274461, 0, 0, -0.004362106, 0.9999905, 120, 255, 1, 25383), -- Mailbox (Area: Merchant Square - Difficulty: 0)
(@OGUID+4, 195430, 654, 4755, 4756, 1, 0, 379,-1790.04, 1435.53, 21.7363, 1.668168, -0.01063776, 0.01383495, 0.7405329, 0.6717935, 120, 255, 0, 25383), -- Cellar Door (Area: Merchant Square - Difficulty: 0)
(@OGUID+5, 195327, 654, 4755, 4756, 1, 0, 379,-1493.828, 1371.16, 36.55773, 3.089183, 0, 0, 0.9996567, 0.02620165, 120, 255, 1, 25383), -- Merchant Square Door (Area: Merchant Square - Difficulty: 0)
(@OGUID+6, 195327, 654, 4755, 4756, 1, 0, 379,-1394.589, 1403.332, 36.42323, 3.124123, 0, 0, 0.9999619, 0.008734641, 120, 255, 1, 25383), -- Merchant Square Door (Area: Merchant Square - Difficulty: 0)
(@OGUID+7, 195327, 654, 4755, 4756, 1, 0, 379,-1426.658, 1436.557, 36.39017, 3.071766, 0, 0, 0.9993906, 0.03490613, 120, 255, 1, 25383), -- Merchant Square Door (Area: Merchant Square - Difficulty: 0)
(@OGUID+8, 195327, 654, 4755, 4756, 1, 0, 379,-1486.285, 1334.576, 36.48906, 1.832595, 0, 0, 0.7933531, 0.6087617, 120, 255, 1, 25383), -- Merchant Square Door (Area: Merchant Square - Difficulty: 0)
(@OGUID+9, 196401, 654, 4755, 4756, 1, 0, 379,-1681.84, 2507.57, 97.7786, 3.938617, 0, 0, -0.9216394, 0.3880474, 120, 255, 1, 25383), -- 196401 (Area: Merchant Square - Difficulty: 0)
(@OGUID+10, 196400, 654, 4755, 4756, 1, 0, 379,-1542.021, 1978.71, 5.616106, 3.708827, 0, 0, -0.9600496, 0.2798298, 120, 255, 1, 25383), -- 196400 (Area: Merchant Square - Difficulty: 0)
(@OGUID+11, 204986, 654, 4755, 4756, 1, 0, 379,-1586.271, 1613.42, 20.3519, 1.416609, 0, 0, 0.650547, 0.7594659, 120, 255, 1, 25383), -- Cathedral Gate (Area: Merchant Square - Difficulty: 0)
(@OGUID+12, 206693, 654, 4755, 4756, 1, 0, 379,-1880.474, 2545.83, 3.087044, 3.822272, 0.01975298, 0.006994247, -0.9424343, 0.3337342, 120, 255, 1, 25383), -- Doodad_Worgen_Cellar_Door_02 (Area: Merchant Square - Difficulty: 0)
(@OGUID+13, 196412, 654, 4755, 4756, 1, 0, 379,-1872.92, 2073.58, 89.1548, 1.547509, 0, 0, 0.6988258, 0.7152919, 120, 255, 1, 25383), -- King's Gate (Area: Merchant Square - Difficulty: 0)
(@OGUID+14, 195327, 654, 4755, 4756, 1, 0, 379,-1537.47, 1443.967, 36.70511, 4.71239, 0, 0, -0.7071066, 0.7071069, 120, 255, 1, 25383), -- Merchant Square Door (Area: Merchant Square - Difficulty: 0)
(@OGUID+15, 196399, 654, 4755, 4756, 1, 0, 379,-1817.84, 2333.37, 36.3445, 3.798994, 0, 0, -0.9464626, 0.3228134, 120, 255, 1, 25383), -- 196399 (Area: Merchant Square - Difficulty: 0)
(@OGUID+16, 207417, 654, 4755, 4756, 1, 0, 379,-1405.87, 1442.179, 35.55592, 0, 0, 0, 0, 1, 120, 255, 1, 25383), -- Crow Scatter Trap (Area: Merchant Square - Difficulty: 0)
(@OGUID+17, 195327, 654, 4755, 4756, 1, 0, 379,-1421.076, 1412.984, 36.79442, 1.53589, 0, 0, 0.6946583, 0.7193398, 120, 255, 1, 25383), -- Merchant Square Door (Area: Merchant Square - Difficulty: 0)
(@OGUID+18, 207093, 654, 4755, 4756, 1, 0, 379,-1651.25, 1607.085, 23.26756, 2.404515, 0, 0, 0.9328547, 0.360253, 120, 255, 1, 25383), -- Cozy Fire (Area: Merchant Square - Difficulty: 0)
(@OGUID+19, 207330, 654, 4755, 4756, 1, 0, 379,-1672.759, 1579.179, 20.2763, 4.022988, 0, 0, -0.9044542, 0.4265707, 120, 255, 1, 25383), -- Cauldron (Area: Merchant Square - Difficulty: 0)
(@OGUID+20, 202695, 654, 4755, 4756, 1, 0, 379,-1587.657, 1543.983, 29.20138, 2.347464, 0, 0, 0.9222002, 0.3867128, 120, 255, 1, 25383), -- Bench (Area: Merchant Square - Difficulty: 0)
(@OGUID+21, 202694, 654, 4755, 4756, 1, 0, 379,-1583.412, 1546.471, 29.20138, 1.911136, 0, 0, 0.8166418, 0.5771448, 120, 255, 1, 25383), -- Bench (Area: Merchant Square - Difficulty: 0)
(@OGUID+22, 202696, 654, 4755, 4756, 1, 0, 379,-1588.717, 1539.919, 29.20138, 3.045582, 0, 0, 0.998848, 0.04798714, 120, 255, 1, 25383), -- Bench (Area: Merchant Square - Difficulty: 0)
(@OGUID+23, 195327, 654, 4755, 4756, 1, 0, 379,-1562.477, 1409.71, 36.53197, 6.265733, 0, 0, -0.00872612, 0.9999619, 120, 255, 1, 25383), -- Merchant Square Door (Area: Merchant Square - Difficulty: 0)
(@OGUID+24, 195327, 654, 4755, 4756, 1, 0, 379,-1583.431, 1359.09, 36.53497, 1.53589, 0, 0, 0.6946583, 0.7193398, 120, 255, 1, 25383), -- Merchant Square Door (Area: Merchant Square - Difficulty: 0)
(@OGUID+25, 195327, 654, 4755, 4756, 1, 0, 379,-1576.568, 1335.938, 36.53497, 6.265733, 0, 0, -0.00872612, 0.9999619, 120, 255, 1, 25383), -- Merchant Square Door (Area: Merchant Square - Difficulty: 0)
(@OGUID+26, 195327, 654, 4755, 4756, 1, 0, 379,-1529.502, 1322.795, 36.5849, 1.832595, 0, 0, 0.7933531, 0.6087617, 120, 255, 1, 25383), -- Merchant Square Door (Area: Merchant Square - Difficulty: 0)
(@OGUID+27, 195327, 654, 4755, 4756, 1, 0, 379,-1569.804, 1384.913, 36.99949, 1.466076, 0, 0, 0.6691303, 0.743145, 120, 255, 1, 25383), -- Merchant Square Door (Area: Merchant Square - Difficulty: 0)
(@OGUID+28, 195327, 654, 4755, 4756, 1, 0, 379,-1549.554, 1309.613, 36.4266, 3.38594, 0, 0, -0.9925461, 0.12187, 120, 255, 1, 25383), -- Merchant Square Door (Area: Merchant Square - Difficulty: 0)
(@OGUID+29, 195306, 654, 4755, 4756, 1, 170, 0, -1478.734, 1380.339, 36.00387, 3.176533, 0, 0, -0.9998474, 0.01746928, 120, 255, 1, 25383), -- Supply Crate (Area: Merchant Square - Difficulty: 0)
(@OGUID+30, 195306, 654, 4755, 4756, 1, 170, 0, -1440.887, 1440.72, 35.97989, 0, 0, 0, 0, 1, 120, 255, 1, 25383), -- Supply Crate (Area: Merchant Square - Difficulty: 0)
(@OGUID+31, 195306, 654, 4755, 4756, 1, 170, 0, -1482.493, 1440.37, 35.97626, 3.176533, 0, 0, -0.9998474, 0.01746928, 120, 255, 1, 25383), -- Supply Crate (Area: Merchant Square - Difficulty: 0)
(@OGUID+32, 195306, 654, 4755, 4756, 1, 170, 0, -1419.036, 1428.557, 35.7935, 4.590216, 0, 0, -0.7489557, 0.6626201, 120, 255, 1, 25383), -- Supply Crate (Area: Merchant Square - Difficulty: 0)
(@OGUID+33, 195621, 654, 4755, 4756, 1, 170, 0, -1790.03, 1435.53, 21.7358, 1.668168, -0.01063776, 0.01383495, 0.7405329, 0.6717935, 120, 255, 1, 25383), -- Cellar Door (Area: Merchant Square - Difficulty: 0)
(@OGUID+34, 195306, 654, 4755, 4756, 1, 170, 0, -1429.873, 1399.259, 36.00387, 4.590216, 0, 0, -0.7489557, 0.6626201, 120, 255, 1, 25383), -- Supply Crate (Area: Merchant Square - Difficulty: 0)
(@OGUID+35, 195306, 654, 4755, 4756, 1, 170, 0, -1477.672, 1412.656, 35.55591, 0, 0, 0, 0, 1, 120, 255, 1, 25383), -- Supply Crate (Area: Merchant Square - Difficulty: 0)
(@OGUID+36, 202191, 654, 4755, 4756, 1, 170, 0, -1586.271, 1613.42, 20.3519, 1.416612, 0, 0, 0.650548, 0.7594652, 120, 255, 1, 25383), -- 202191 (Area: Merchant Square - Difficulty: 0)
(@OGUID+37, 195306, 654, 4755, 4756, 1, 170, 0, -1523.359, 1413.342, 35.55592, 4.590216, 0, 0, -0.7489557, 0.6626201, 120, 255, 1, 25383), -- Supply Crate (Area: Merchant Square - Difficulty: 0)
(@OGUID+38, 195306, 654, 4755, 4756, 1, 170, 0, -1466.045, 1362.194, 36.00388, 3.176533, 0, 0, -0.9998474, 0.01746928, 120, 255, 1, 25383), -- Supply Crate (Area: Merchant Square - Difficulty: 0)
(@OGUID+39, 195306, 654, 4755, 4756, 1, 170, 0, -1493.899, 1362.938, 35.99874, 0, 0, 0, 0, 1, 120, 255, 1, 25383), -- Supply Crate (Area: Merchant Square - Difficulty: 0)
(@OGUID+40, 195306, 654, 4755, 4756, 1, 170, 0, -1525.323, 1382.156, 36.00392, 0, 0, 0, 0, 1, 120, 255, 1, 25383), -- Supply Crate (Area: Merchant Square - Difficulty: 0)
(@OGUID+41, 195306, 654, 4755, 4756, 1, 170, 0, -1537.446, 1406.859, 35.55592, 0, 0, 0, 0, 1, 120, 255, 1, 25383), -- Supply Crate (Area: Merchant Square - Difficulty: 0)
(@OGUID+42, 195306, 654, 4755, 4756, 1, 170, 0, -1510.307, 1328.089, 35.80275, 5.009095, 0, 0, -0.5948229, 0.8038568, 120, 255, 1, 25383), -- Supply Crate (Area: Merchant Square - Difficulty: 0)
(@OGUID+43, 195306, 654, 4755, 4756, 1, 170, 0, -1561.401, 1432.832, 35.96232, 0, 0, 0, 0, 1, 120, 255, 1, 25383), -- Supply Crate (Area: Merchant Square - Difficulty: 0)
(@OGUID+44, 195306, 654, 4755, 4756, 1, 170, 0, -1574.023, 1401.144, 36.63025, 3.176533, 0, 0, -0.9998474, 0.01746928, 120, 255, 1, 25383), -- Supply Crate (Area: Merchant Square - Difficulty: 0)
(@OGUID+45, 195306, 654, 4755, 4756, 1, 170, 0, -1548.738, 1305.165, 35.8792, 3.281239, 0, 0, -0.9975634, 0.06976615, 120, 255, 1, 25383), -- Supply Crate (Area: Merchant Square - Difficulty: 0)
(@OGUID+46, 207417, 654, 4755, 4756, 1, 170, 0, -1615.212, 1310.425, 18.9967, 0, 0, 0, 0, 1, 120, 255, 1, 25383), -- Crow Scatter Trap (Area: Merchant Square - Difficulty: 0)
(@OGUID+47, 207417, 654, 4755, 4757, 1, 170, 0, -1615.212, 1310.425, 18.9967, 0, 0, 0, 0, 1, 120, 255, 1, 25383), -- Crow Scatter Trap (Area: Military District - Difficulty: 0)
(@OGUID+48, 195306, 654, 4755, 4756, 1, 170, 0, -1541.222, 1381.214, 36.00387, 3.176533, 0, 0, -0.9998474, 0.01746928, 120, 255, 1, 25383), -- Supply Crate (Area: Merchant Square - Difficulty: 0)
(@OGUID+49, 195306, 654, 4755, 4756, 1, 170, 0, -1477.672, 1412.656, 35.55591, 0, 0, 0, 0, 1, 120, 255, 1, 25383), -- Supply Crate (Area: Merchant Square - Difficulty: 0)
(@OGUID+50, 195306, 654, 4755, 4756, 1, 170, 0, -1574.023, 1401.144, 36.63025, 3.176533, 0, 0, -0.9998474, 0.01746928, 120, 255, 1, 25383), -- Supply Crate (Area: Merchant Square - Difficulty: 0)
(@OGUID+51, 195306, 654, 4755, 4756, 1, 170, 0, -1561.401, 1432.832, 35.96232, 0, 0, 0, 0, 1, 120, 255, 1, 25383), -- Supply Crate (Area: Merchant Square - Difficulty: 0)
(@OGUID+52, 207417, 654, 4755, 4756, 1, 170, 0, -1615.212, 1310.425, 18.9967, 0, 0, 0, 0, 1, 120, 255, 1, 25383), -- Crow Scatter Trap (Area: Merchant Square - Difficulty: 0)
(@OGUID+53, 207417, 654, 4755, 4757, 1, 170, 0, -1615.212, 1310.425, 18.9967, 0, 0, 0, 0, 1, 120, 255, 1, 25383), -- Crow Scatter Trap (Area: Military District - Difficulty: 0)
(@OGUID+54, 195453, 654, 4755, 4757, 1, 171, 0, -1769.5, 1405.62, 20.0667, 5.896716, -0.02017355, 0.06879044, -0.1894732, 0.9792655, 120, 255, 1, 25383), -- 195453 (Area: Military District - Difficulty: 0)
(@OGUID+55, 195454, 654, 4755, 4757, 1, 171, 0, -1764.931, 1415.87, 20.1221, 1.40499, 0, 0, 0.6461239, 0.7632326, 120, 255, 1, 25383), -- 195454 (Area: Military District - Difficulty: 0)
(@OGUID+56, 195465, 654, 4755, 4757, 1, 171, 0, -1794.13, 1402.51, 20.1318, 2.155482, -0.03809595, -0.02527809, 0.8803816, 0.4720572, 120, 255, 1, 25383), -- 195465 (Area: Military District - Difficulty: 0)
(@OGUID+57, 195466, 654, 4755, 4757, 1, 171, 0, -1805.29, 1399.5, 20.261, 1.265364, 0.06552887, 0.01846695, 0.5911665, 0.8036711, 120, 255, 1, 25383), -- 195466 (Area: Military District - Difficulty: 0)
(@OGUID+58, 207417, 654, 4755, 4757, 1, 171, 0, -1797.111, 1550.611, 22.73234, 0.7504908, 0, 0, 0.3665009, 0.9304177, 120, 255, 1, 25383), -- Crow Scatter Trap (Area: Military District - Difficulty: 0)
(@OGUID+59, 207417, 654, 4755, 4757, 1, 171, 0, -1797.111, 1550.611, 22.73234, 0.7504908, 0, 0, 0.3665009, 0.9304177, 120, 255, 1, 25383), -- Crow Scatter Trap (Area: Military District - Difficulty: 0)
(@OGUID+60, 207417, 654, 4755, 4757, 1, 172, 0, -1799.163, 1547.597, 22.73689, 0.7504908, 0, 0, 0.3665009, 0.9304177, 120, 255, 1, 25383); -- Crow Scatter Trap (Area: Military District - Difficulty: 0)

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+22;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`) VALUES
(@OGUID+1, 0, 0, 0.9426414, -0.3338069), -- Basement Door
(@OGUID+12, 0, 0, 0.9426414, -0.3338069), -- Doodad_Worgen_Cellar_Door_02
(@OGUID+18, 0, 0, 0.9999967, -0.00259022), -- Cozy Fire
(@OGUID+20, 0, 0, 0.9255404, -0.3786487), -- Bench
(@OGUID+21, 0, 0, 0.9255404, -0.3786487), -- Bench
(@OGUID+22, 0, 0, 0.9255404, -0.3786487); -- Bench

DELETE FROM `creature_addon` WHERE `guid` NOT IN (SELECT `guid` FROM `creature`);

