-- Protector Weaver path
SET @MOVERGUID := 275167;
SET @ENTRY := 488;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Protector Weaver - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -10503.813, 1032.656, 95.926506, NULL, 0),
(@PATH, 1, -10498.092, 1032.9823, 95.87571, NULL, 0),
(@PATH, 2, -10494.097, 1028.5104, 95.78732, NULL, 0),
(@PATH, 3, -10493.688, 1023.1009, 95.78733, NULL, 0),
(@PATH, 4, -10497.403, 1019.0657, 95.89738, NULL, 0),
(@PATH, 5, -10503.215, 1018.5884, 95.89708, NULL, 0),
(@PATH, 6, -10506.956, 1021.8047, 95.84116, NULL, 0),
(@PATH, 7, -10508.083, 1027.1096, 95.85617, NULL, 0);

UPDATE `creature` SET `position_x`=-10503.813, `position_y`=1032.656, `position_z`=95.926506, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `PvpFlags`) VALUES
(@MOVERGUID, @PATH, 1, 1);

-- Protector Dutfield path
SET @MOVERGUID := 275159;
SET @ENTRY := 489;
SET @PATH := @ENTRY * 100;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Protector Dutfield - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -10521.006, 1024.1843, 60.563126, NULL, 0),
(@PATH, 1, -10518.504, 1019.7985, 60.60384, NULL, 0),
(@PATH, 2, -10515.286, 1014.1583, 60.5842, NULL, 0),
(@PATH, 3, -10512.503, 1009.2794, 60.46545, NULL, 0),
(@PATH, 4, -10511.894, 1008.2119, 60.46465, NULL, 0),
(@PATH, 5, -10503.619, 1006.0582, 60.596302, NULL, 0),
(@PATH, 6, -10493.653, 1008.3578, 60.480694, NULL, 0),
(@PATH, 7, -10484.865, 1014.4223, 60.584194, NULL, 0),
(@PATH, 8, -10481.817, 1029.5293, 60.521385, NULL, 0),
(@PATH, 9, -10487.994, 1041.0077, 60.47728, NULL, 0),
(@PATH, 10, -10499.225, 1045.555, 60.584198, NULL, 0),
(@PATH, 11, -10516.6, 1039.7664, 60.555386, NULL, 0);

UPDATE `creature` SET `position_x`=-10521.006, `position_y`=1024.1843, `position_z`=60.563126, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `PvpFlags`) VALUES
(@MOVERGUID, @PATH, 1, 1);

-- Protector Korelor path
SET @MOVERGUID := 274917;
SET @ENTRY := 874;
SET @PATH := @ENTRY * 100;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x01, NULL, 'Protector Korelor - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -10634, 1085.8853, 33.735893, NULL, 0),
(@PATH, 1, -10634.184, 1072.2194, 33.85315, NULL, 0),
(@PATH, 2, -10640.825, 1056.6143, 33.569912, NULL, 0),
(@PATH, 3, -10655.064, 1038.7388, 33.465805, NULL, 0),
(@PATH, 4, -10663.542, 1029.0798, 32.66153, NULL, 0),
(@PATH, 5, -10699.919, 1033.6962, 34.46218, NULL, 0),
(@PATH, 6, -10719.79, 1032.3854, 34.528484, NULL, 0),
(@PATH, 7, -10732.507, 1027.0764, 34.524857, NULL, 0),
(@PATH, 8, -10746.816, 1018.5417, 34.045944, NULL, 0),
(@PATH, 9, -10768.826, 1017.2587, 32.17281, NULL, 0),
(@PATH, 10, -10794.009, 1018.6667, 32.228947, NULL, 0),
(@PATH, 11, -10833.286, 1009.7239, 32.747368, NULL, 0),
(@PATH, 12, -10864.482, 1006.4549, 31.587172, NULL, 0),
(@PATH, 13, -10898.813, 999.4549, 35.526184, NULL, 0),
(@PATH, 14, -10919.726, 993.3299, 35.412037, NULL, 0),
(@PATH, 15, -10942.452, 967.619, 32.40742, NULL, 0),
(@PATH, 16, -10949.246, 940.71497, 31.527164, NULL, 0),
(@PATH, 17, -10946.804, 934.30316, 31.52058, NULL, 0),
(@PATH, 18, -10914.473, 901.58386, 32.21682, NULL, 0),
(@PATH, 19, -10916.354, 868.85645, 32.473618, NULL, 0),
(@PATH, 20, -10926.304, 852.3051, 32.80895, NULL, 0),
(@PATH, 21, -10929.212, 832.72614, 32.32375, NULL, 0),
(@PATH, 22, -10919.833, 800.1399, 30.722464, NULL, 0),
(@PATH, 23, -10900.73, 777.5663, 30.722462, NULL, 0),
(@PATH, 24, -10880.348, 749.30206, 31.049938, NULL, 0),
(@PATH, 25, -10877.123, 732.9159, 31.131363, NULL, 0),
(@PATH, 26, -10871.73, 699.81946, 30.894178, NULL, 0),
(@PATH, 27, -10866.871, 665.3965, 30.985062, NULL, 0);

UPDATE `creature` SET `position_x`=-10634, `position_y`=1085.8853, `position_z`=33.735893, `orientation`=4.77, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `PvpFlags`) VALUES
(@MOVERGUID, @PATH, 1, 1);
