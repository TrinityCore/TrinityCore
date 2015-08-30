-- DB/Quest: Orgrimmar - Blown Away (H)
-- Ballonspawns
SET @OGUID := 224782;
SET @OLDOGUID := 44;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+25;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OLDOGUID+0 AND @OLDOGUID+25;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 209058, 1, 1,1503.991, -4375.202, 23.263, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: 0)
(@OGUID+1, 209058, 1, 1,1528.073, -4441.75, 24.02341, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: 0)
(@OGUID+2, 209058, 1, 1,1530.462, -4374.63, 18.83806, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: 0)
(@OGUID+3, 209058, 1, 1,1515.497, -4439.116, 23.48083, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: 0)
(@OGUID+4, 209058, 1, 1,1590.663, -4366.837, 20.93084, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: 0)
(@OGUID+5, 209058, 1, 1,1602.719, -4435.96, 13.90795, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: 0)
(@OGUID+6, 209058, 1, 1,1629.444, -4417.929, 15.5577, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: 0)
(@OGUID+7, 209058, 1, 1,1539.163, -4334.366, 22.73981, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: Valley of Strength)
(@OGUID+8, 209058, 1, 1,1726.033, -4441.309, 40.65453, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: Valley of Strength)
(@OGUID+9, 209058, 1, 1,1726.655, -4498.354, 30.89155, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: The Drag)
(@OGUID+10, 209058, 1, 1,1751.536, -4534.128, 30.44205, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: The Drag)
(@OGUID+11, 209058, 1, 1,1816.24, -4496.58, 46.47007, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: The Drag)
(@OGUID+12, 209058, 1, 1,1872.5, -4464.323, 48.70532, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: The Drag)
(@OGUID+13, 209058, 1, 1,1904.172, -4694.141, 36.44628, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: Valley of Honor)
(@OGUID+14, 209058, 1, 1,1928.13, -4739.939, 36.58462, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: Valley of Honor)
(@OGUID+15, 209058, 1, 1,2215.036, -4610.439, 85.89728, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: 0)
(@OGUID+16, 209058, 1, 1,1916.698, -4418.78, 46.36224, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: The Drag)
(@OGUID+17, 209058, 1, 1,2032.356, -4414.33, 97.91099, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: The Drag)
(@OGUID+18, 209058, 1, 1,1910.321, -4378.42, 105.6533, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: The Drag)
(@OGUID+19, 209058, 1, 1,1880.024, -4237.168, 35.96712, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: Valley of Wisdom)
(@OGUID+20, 209058, 1, 1,1989.224, -4206.981, 36.1769, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: Valley of Wisdom)
(@OGUID+21, 209058, 1, 1,2027.594, -4203.146, 105.683, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: Valley of Wisdom)
(@OGUID+22, 209058, 1, 1,1911.71, -4128.022, 109.7363, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: Valley of Wisdom)
(@OGUID+23, 209058, 1, 1,1552.372, -4206.984, 53.92707, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: Valley of Strength)
(@OGUID+24, 209058, 1, 1,1481.854, -4173.207, 52.93541, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: Goblin Slums)
(@OGUID+25, 209058, 1, 1,1770.215, -3952.91, 55.46432, 0, 0, 0, 0, 1, 120, 255, 1); -- Windswept Balloon (Area: Valley of Spirits)
