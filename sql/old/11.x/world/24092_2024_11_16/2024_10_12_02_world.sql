-- Path for Wisp
SET @MOVERGUID := 312829;
SET @ENTRY := 48624;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.1553, 'Wisp - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 9826.675, 828.87476, 1319.4333, NULL, 0),
(@PATH, 1, 9829.285, 827.27515, 1319.4333, NULL, 0),
(@PATH, 2, 9832.262, 827.98987, 1319.4333, NULL, 0),
(@PATH, 3, 9833.861, 830.60016, 1319.4333, NULL, 0),
(@PATH, 4, 9833.146, 833.577, 1319.4333, NULL, 0),
(@PATH, 5, 9830.536, 835.17664, 1319.4333, NULL, 0),
(@PATH, 6, 9827.56, 834.462, 1319.4333, NULL, 0),
(@PATH, 7, 9825.96, 831.8516, 1319.4333, NULL, 0);

UPDATE `creature` SET `position_x`=9826.675, `position_y`=828.87476, `position_z`=1319.4333, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Wisp
SET @MOVERGUID := 312830;
SET @ENTRY := 48624;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.1558, 'Wisp - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 9831.117, 834.0277, 1323.0834, NULL, 0),
(@PATH, 1, 9833.374, 831.9594, 1323.0834, NULL, 0),
(@PATH, 2, 9833.508, 828.9009, 1323.0834, NULL, 0),
(@PATH, 3, 9831.439, 826.64374, 1323.0834, NULL, 0),
(@PATH, 4, 9828.381, 826.5102, 1323.0834, NULL, 0),
(@PATH, 5, 9826.124, 828.5785, 1323.0834, NULL, 0),
(@PATH, 6, 9825.99, 831.637, 1323.0834, NULL, 0),
(@PATH, 7, 9828.059, 833.89417, 1323.0834, NULL, 0);

UPDATE `creature` SET `position_x`=9831.117, `position_y`=834.0277, `position_z`=1323.0834, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Wisp
SET @MOVERGUID := 312794;
SET @ENTRY := 48624;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.1432, 'Wisp - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 9794.689, 856.3815, 1309.3734, NULL, 0),
(@PATH, 1, 9792.5, 855.69104, 1309.3734, NULL, 0),
(@PATH, 2, 9790.463, 856.7512, 1309.3734, NULL, 0),
(@PATH, 3, 9789.772, 858.9411, 1309.3734, NULL, 0),
(@PATH, 4, 9790.833, 860.9777, 1309.3734, NULL, 0),
(@PATH, 5, 9793.022, 861.6682, 1309.3734, NULL, 0),
(@PATH, 6, 9795.06, 860.608, 1309.3734, NULL, 0),
(@PATH, 7, 9795.75, 858.41815, 1309.3734, NULL, 0);

UPDATE `creature` SET `position_x`=9794.689, `position_y`=856.3815, `position_z`=1309.3734, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Wisp
SET @MOVERGUID := 312803;
SET @ENTRY := 48624;
SET @PATHOFFSET := 8;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.1575, 'Wisp - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 9831.297, 835.0853, 1313.9033, NULL, 0),
(@PATH, 1, 9833.48, 832.9395, 1313.9033, NULL, 0),
(@PATH, 2, 9833.507, 829.8782, 1313.9033, NULL, 0),
(@PATH, 3, 9831.361, 827.6946, 1313.9033, NULL, 0),
(@PATH, 4, 9828.3, 827.66785, 1313.9033, NULL, 0),
(@PATH, 5, 9826.116, 829.81366, 1313.9033, NULL, 0),
(@PATH, 6, 9826.09, 832.875, 1313.9033, NULL, 0),
(@PATH, 7, 9828.235, 835.0586, 1313.9033, NULL, 0);

UPDATE `creature` SET `position_x`=9831.297, `position_y`=835.0853, `position_z`=1313.9033, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Wisp
SET @MOVERGUID := 312801;
SET @ENTRY := 48624;
SET @PATHOFFSET := 9;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.1655, 'Wisp - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 9847.25, 882.35675, 1318.5533, NULL, 0),
(@PATH, 1, 9846.251, 874.76855, 1318.5533, NULL, 0),
(@PATH, 2, 9850.91, 868.69653, 1318.5533, NULL, 0),
(@PATH, 3, 9858.498, 867.6975, 1318.5533, NULL, 0),
(@PATH, 4, 9864.57, 872.3568, 1318.5533, NULL, 0),
(@PATH, 5, 9865.569, 879.94495, 1318.5533, NULL, 0),
(@PATH, 6, 9860.91, 886.017, 1318.5533, NULL, 0),
(@PATH, 7, 9853.322, 887.01605, 1318.5533, NULL, 0);

UPDATE `creature` SET `position_x`=9847.25, `position_y`=882.35675, `position_z`=1318.5533, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Wisp
SET @MOVERGUID := 312738;
SET @ENTRY := 48624;
SET @PATHOFFSET := 10;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.1370, 'Wisp - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 9762.154, 949.3478, 1323.0333, NULL, 0),
(@PATH, 1, 9763.6455, 947.6018, 1323.0333, NULL, 0),
(@PATH, 2, 9765.935, 947.42163, 1323.0333, NULL, 0),
(@PATH, 3, 9767.68, 948.91284, 1323.0333, NULL, 0),
(@PATH, 4, 9767.86, 951.20184, 1323.0333, NULL, 0),
(@PATH, 5, 9766.369, 952.9478, 1323.0333, NULL, 0),
(@PATH, 6, 9764.08, 953.128, 1323.0333, NULL, 0),
(@PATH, 7, 9762.334, 951.6368, 1323.0333, NULL, 0);

UPDATE `creature` SET `position_x`=9762.154, `position_y`=949.3478, `position_z`=1323.0333, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Wisp
SET @MOVERGUID := 312737;
SET @ENTRY := 48624;
SET @PATHOFFSET := 11;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.1661, 'Wisp - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 9833.372, 1004.2603, 1318.0333, NULL, 0),
(@PATH, 1, 9825.872, 1005.7862, 1318.0333, NULL, 0),
(@PATH, 2, 9819.489, 1001.5618, 1318.0333, NULL, 0),
(@PATH, 3, 9817.964, 994.0618, 1318.0333, NULL, 0),
(@PATH, 4, 9822.188, 987.67957, 1318.0333, NULL, 0),
(@PATH, 5, 9829.688, 986.1536, 1318.0333, NULL, 0),
(@PATH, 6, 9836.07, 990.378, 1318.0333, NULL, 0),
(@PATH, 7, 9837.597, 997.878, 1318.0333, NULL, 0);

UPDATE `creature` SET `position_x`=9833.372, `position_y`=1004.2603, `position_z`=1318.0333, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Wisp
SET @MOVERGUID := 312690;
SET @ENTRY := 48624;
SET @PATHOFFSET := 12;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.1478, 'Wisp - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 9678.129, 971.60004, 1307.3838, NULL, 0),
(@PATH, 1, 9675.993, 970.75854, 1307.3838, NULL, 0),
(@PATH, 2, 9673.887, 971.6741, 1307.3838, NULL, 0),
(@PATH, 3, 9673.046, 973.8104, 1307.3838, NULL, 0),
(@PATH, 4, 9673.961, 975.9161, 1307.3838, NULL, 0),
(@PATH, 5, 9676.098, 976.7576, 1307.3838, NULL, 0),
(@PATH, 6, 9678.203, 975.84204, 1307.3838, NULL, 0),
(@PATH, 7, 9679.045, 973.7057, 1307.3838, NULL, 0);

UPDATE `creature` SET `position_x`=9678.129, `position_y`=971.60004, `position_z`=1307.3838, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Wisp
SET @MOVERGUID := 312691;
SET @ENTRY := 48624;
SET @PATHOFFSET := 13;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.1394, 'Wisp - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 9675.499, 969.8569, 1312.7693, NULL, 0),
(@PATH, 1, 9673.753, 971.3481, 1312.7693, NULL, 0),
(@PATH, 2, 9673.573, 973.63715, 1312.7693, NULL, 0),
(@PATH, 3, 9675.064, 975.3831, 1312.7693, NULL, 0),
(@PATH, 4, 9677.354, 975.56323, 1312.7693, NULL, 0),
(@PATH, 5, 9679.1, 974.072, 1312.7693, NULL, 0),
(@PATH, 6, 9679.279, 971.783, 1312.7693, NULL, 0),
(@PATH, 7, 9677.788, 970.03705, 1312.7693, NULL, 0);

UPDATE `creature` SET `position_x`=9675.499, `position_y`=969.8569, `position_z`=1312.7693, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Wisp
SET @MOVERGUID := 312693;
SET @ENTRY := 48624;
SET @PATHOFFSET := 14;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.0797, 'Wisp - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 9648.28, 933.104, 1301.9, NULL, 0),
(@PATH, 1, 9646.39, 927.262, 1307.64, NULL, 0),
(@PATH, 2, 9648.88, 921.696, 1309.55, NULL, 0),
(@PATH, 3, 9654.07, 918.689, 1310.48, NULL, 0),
(@PATH, 4, 9660.33, 920.774, 1310.48, NULL, 0),
(@PATH, 5, 9662.52, 929.736, 1310.48, NULL, 0),
(@PATH, 6, 9654.28, 936.446, 1310.48, NULL, 0),
(@PATH, 7, 9647.23, 932.66, 1310.48, NULL, 0),
(@PATH, 8, 9645.86, 926.271, 1308.94, NULL, 0),
(@PATH, 9, 9651.54, 919.078, 1306.24, NULL, 0),
(@PATH, 10, 9659.92, 921.219, 1304.77, NULL, 0),
(@PATH, 11, 9662.24, 930.839, 1301.96, NULL, 0),
(@PATH, 12, 9659.31, 933.941, 1299.47, NULL, 0),
(@PATH, 13, 9656.33, 935.035, 1299.37, NULL, 0);

UPDATE `creature` SET `position_x`=9648.28, `position_y`=933.104, `position_z`=1301.9, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
