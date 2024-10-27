-- Path for Wisp
SET @MOVERGUID := 313296;
SET @ENTRY := 48624;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.0653, 'Wisp - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 10329.271, 744.684, 1334.5488, NULL, 0),
(@PATH, 1, 10329.003, 741.5347, 1333.2526, NULL, 0),
(@PATH, 2, 10332.361, 740.2344, 1333.3473, NULL, 0),
(@PATH, 3, 10335.872, 746.8993, 1336.5226, NULL, 0),
(@PATH, 4, 10341.161, 747.09375, 1339.1598, NULL, 0),
(@PATH, 5, 10342.8, 742.07117, 1340.9467, NULL, 0),
(@PATH, 6, 10337.369, 738.1233, 1340.9686, NULL, 0),
(@PATH, 7, 10328.47, 740.8264, 1339.3236, NULL, 0),
(@PATH, 8, 10327.908, 745.5573, 1337.8783, NULL, 0),
(@PATH, 9, 10332.898, 746.5208, 1335.6619, NULL, 0),
(@PATH, 10, 10338.035, 740.7257, 1334.0903, NULL, 0),
(@PATH, 11, 10340.536, 742.92883, 1332.3331, NULL, 0),
(@PATH, 12, 10339.659, 746.5035, 1334.2145, NULL, 0),
(@PATH, 13, 10336.292, 746.8316, 1334.5488, NULL, 0);

UPDATE `creature` SET `position_x`=10339.659, `position_y`=746.5035, `position_z`=1334.2145, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Wisp
SET @MOVERGUID := 313297;
SET @ENTRY := 48624;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 7.8203, 'Wisp - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 10354.955, 707.30206, 1340.2677, NULL, 0),
(@PATH, 1, 10351.08, 710.23615, 1341.536, NULL, 0),
(@PATH, 2, 10344.742, 705.88544, 1341.4491, NULL, 0),
(@PATH, 3, 10340.81, 700.61633, 1339.1139, NULL, 0),
(@PATH, 4, 10342.533, 696.4566, 1337.1692, NULL, 0),
(@PATH, 5, 10347.712, 696.6476, 1334.0653, NULL, 0),
(@PATH, 6, 10356.123, 701.783, 1333.291, NULL, 0),
(@PATH, 7, 10357.533, 711.51044, 1332.6805, NULL, 0),
(@PATH, 8, 10353.271, 713.19617, 1332.4512, NULL, 0),
(@PATH, 9, 10348.353, 708.941, 1333.1494, NULL, 0),
(@PATH, 10, 10347.653, 704.11115, 1335.0155, NULL, 0),
(@PATH, 11, 10351.339, 701.0469, 1336.1609, NULL, 0),
(@PATH, 12, 10353.536, 700.4375, 1337.4088, NULL, 0);

UPDATE `creature` SET `position_x`=10351.339, `position_y`=701.0469, `position_z`=1336.1609, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Wisp
SET @MOVERGUID := 313293;
SET @ENTRY := 48624;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.1845, 'Wisp - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 10344.305, 808.2639, 1331.617, NULL, 0),
(@PATH, 1, 10352.113, 809.58856, 1331.9805, NULL, 0),
(@PATH, 2, 10351.073, 818.63367, 1327.3499, NULL, 0),
(@PATH, 3, 10345.139, 820.0781, 1327.3499, NULL, 0),
(@PATH, 4, 10342.41, 814.58856, 1327.3499, NULL, 0),
(@PATH, 5, 10347.016, 810.86456, 1330.6635, NULL, 0),
(@PATH, 6, 10352.333, 813.91144, 1331.3212, NULL, 0),
(@PATH, 7, 10349.232, 819.77606, 1332.3054, NULL, 0),
(@PATH, 8, 10343.367, 818.8264, 1333.3867, NULL, 0),
(@PATH, 9, 10342.868, 814.7153, 1332.4296, NULL, 0);

UPDATE `creature` SET `position_x`=10343.367, `position_y`=818.8264, `position_z`=1333.3867, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Wisp
SET @MOVERGUID := 313285;
SET @ENTRY := 48624;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.1874, 'Wisp - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 10419.873, 803.2917, 1330.4156, NULL, 0),
(@PATH, 1, 10417.881, 793.29517, 1330.4156, NULL, 0),
(@PATH, 2, 10408.223, 788.94965, 1329.2657, NULL, 0),
(@PATH, 3, 10396.814, 788.4583, 1327.8483, NULL, 0),
(@PATH, 4, 10394.913, 782.283, 1326.8333, NULL, 0),
(@PATH, 5, 10402.804, 781.1233, 1328.0524, NULL, 0),
(@PATH, 6, 10407.384, 792.8281, 1329.453, NULL, 0),
(@PATH, 7, 10409.64, 800.4601, 1329.453, NULL, 0),
(@PATH, 8, 10429.028, 798.54865, 1330.8037, NULL, 0),
(@PATH, 9, 10432.188, 803.28644, 1331.0669, NULL, 0),
(@PATH, 10, 10428.435, 809.91144, 1331.0669, NULL, 0),
(@PATH, 11, 10424.993, 810.0868, 1330.8717, NULL, 0);

UPDATE `creature` SET `position_x`=10428.435, `position_y`=809.91144, `position_z`=1331.0669, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Wisp
SET @MOVERGUID := 313426;
SET @ENTRY := 48624;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.2444, 'Wisp - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 10208.347, 689.31946, 1372.0664, NULL, 0),
(@PATH, 1, 10207.995, 693.9809, 1372.9098, NULL, 0),
(@PATH, 2, 10197.723, 698.7743, 1374.9606, NULL, 0),
(@PATH, 3, 10198.319, 705.34375, 1378.3469, NULL, 0),
(@PATH, 4, 10203.481, 705.01044, 1378.3469, NULL, 0),
(@PATH, 5, 10203.747, 697.80206, 1375.403, NULL, 0),
(@PATH, 6, 10199.27, 692.0573, 1374.0133, NULL, 0),
(@PATH, 7, 10198.944, 686.2205, 1374.0133, NULL, 0),
(@PATH, 8, 10203.842, 685.57465, 1372.0664, NULL, 0);

UPDATE `creature` SET `position_x`=10198.944, `position_y`=686.2205, `position_z`=1374.0133, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
