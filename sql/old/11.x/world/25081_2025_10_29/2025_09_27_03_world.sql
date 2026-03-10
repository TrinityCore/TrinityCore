-- Update Fleshripper to createobject2 spawn positions
UPDATE `creature` SET `position_x` = -9955.375, `position_y` = 1121.52783203125, `position_z` = 46.43650054931640625, `orientation` = 0.760787665843963623 WHERE `guid` = 275788;
UPDATE `creature` SET `position_x` = -9999.607421875, `position_y` = 1116.107666015625, `position_z` = 47.42549514770507812, `orientation` = 4.593747615814208984 WHERE `guid` = 275705;
UPDATE `creature` SET `position_x` = -9981.0107421875, `position_y` = 1149.3941650390625, `position_z` = 48.96377182006835937, `orientation` = 5.68583536148071289 WHERE `guid` = 275707;
UPDATE `creature` SET `position_x` = -10115.5576171875, `position_y` = 1257.845458984375, `position_z` = 47.50981903076171875, `orientation` = 2.322627782821655273 WHERE `guid` = 275607;
UPDATE `creature` SET `position_x` = -10254.0517578125, `position_y` = 1150.4375, `position_z` = 42.80022811889648437, `orientation` = 3.692740201950073242 WHERE `guid` = 275482;
UPDATE `creature` SET `position_x` = -10235.61328125, `position_y` = 1011.4132080078125, `position_z` = 42.37844467163085937, `orientation` = 6.225272655487060546 WHERE `guid` = 275489;

-- Delete duplicate spawn
DELETE FROM `creature` WHERE `guid` = 275668;
DELETE FROM `creature_addon` WHERE `guid` = 275668;

-- Difficulty - set disableGravity for guids
DELETE FROM `creature_static_flags_override` WHERE `SpawnId` IN (275788,275705,275707,275607,275482,275489);
INSERT INTO `creature_static_flags_override` (`SpawnId`, `DifficultyId`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`) VALUES
(275788, 0, 0x20000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(275705, 0, 0x20000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(275707, 0, 0x20000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(275607, 0, 0x20000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(275482, 0, 0x20000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(275489, 0, 0x20000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

-- Path for Fleshripper
SET @MOVERGUID := 275788;
SET @ENTRY := 1109;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 3.3271, 'Fleshripper - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -9951.122, 1125.5764, 46.93732, NULL, 0),
(@PATH, 1, -9938.942, 1124.4445, 44.798428, NULL, 0),
(@PATH, 2, -9929.833, 1109.0608, 44.798428, NULL, 0),
(@PATH, 3, -9956.099, 1092.8767, 50.10399, NULL, 0),
(@PATH, 4, -9964.316, 1106.856, 50.103992, NULL, 0),
(@PATH, 5, -9951.122, 1125.5764, 46.93732, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @Path, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '');

-- Path for Fleshripper
SET @MOVERGUID := 275705;
SET @ENTRY := 1109;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 3.3151, 'Fleshripper - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -10000.056, 1112.3473, 48.51642, NULL, 0),
(@PATH, 1, -9996.3955, 1096.7622, 48.51642, NULL, 0),
(@PATH, 2, -9984.078, 1098.6598, 48.51642, NULL, 0),
(@PATH, 3, -9988.6045, 1108.8646, 48.51642, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @Path, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '');

-- Path for Fleshripper
SET @MOVERGUID := 275707;
SET @ENTRY := 1109;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 3.6266, 'Fleshripper - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -9980.337, 1148.9358, 47.96638, NULL, 0),
(@PATH, 1, -9970.556, 1160.8438, 47.96638, NULL, 0),
(@PATH, 2, -9983.066, 1165.9688, 47.96638, NULL, 0),
(@PATH, 3, -9995.444, 1156.0955, 47.96638, NULL, 0),
(@PATH, 4, -9980.337, 1148.9358, 47.96638, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @Path, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '');

-- Path for Fleshripper
SET @MOVERGUID := 275607;
SET @ENTRY := 1109;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.9999, 'Fleshripper - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -10120.114, 1262.7188, 46.429115, NULL, 0),
(@PATH, 1, -10146.712, 1265.8923, 46.429115, NULL, 0),
(@PATH, 2, -10145.04, 1241.6545, 46.429115, NULL, 0),
(@PATH, 3, -10120.13, 1236.7916, 46.429115, NULL, 0),
(@PATH, 4, -10114.304, 1249.4635, 46.429115, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @Path, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '');

-- Path for Fleshripper
SET @MOVERGUID := 275482;
SET @ENTRY := 1109;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 3.2735, 'Fleshripper - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -10257.851, 1148.1024, 43.714344, NULL, 0),
(@PATH, 1, -10265.736, 1136.6389, 43.714344, NULL, 0),
(@PATH, 2, -10242.538, 1121.0677, 43.714344, NULL, 0),
(@PATH, 3, -10228.021, 1128.9323, 43.714344, NULL, 0),
(@PATH, 4, -10235.926, 1149.1216, 43.714344, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @Path, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '');

-- Path for Fleshripper
SET @MOVERGUID := 275489;
SET @ENTRY := 1109;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.9314, 'Fleshripper - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -10230.134, 1011.0955, 42.384518, NULL, 0),
(@PATH, 1, -10213.471, 1007.3854, 42.384518, NULL, 0),
(@PATH, 2, -10205.263, 1004.6702, 42.384518, NULL, 0),
(@PATH, 3, -10185.926, 1017.6268, 42.384518, NULL, 0),
(@PATH, 4, -10178.424, 1033.5781, 42.384518, NULL, 0),
(@PATH, 5, -10199.185, 1039.9774, 42.384518, NULL, 0),
(@PATH, 6, -10221.098, 1038.9132, 42.384518, NULL, 0),
(@PATH, 7, -10242.408, 1036.5608, 42.384518, NULL, 0),
(@PATH, 8, -10245.149, 1026.8889, 42.384518, NULL, 0),
(@PATH, 9, -10230.134, 1011.0955, 42.384518, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @Path, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '');
