DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-314811) AND `source_type`= 0;

SET @CGUID := 314811;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, -10957.5, -1485.63, 6.767189, 0, 2122, 1),
(@PATH, 1, -10968.2, -1477.91, 6.766029, 0, 2352, 1),
(@PATH, 2, -10963, -1500.02, 7.105066, 0, 2526, 1);

UPDATE `creature` SET `position_x`= -10957.5, `position_y`= -1485.63, `position_z`= 6.767189, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `bytes2`) VALUES
(@CGUID, @PATH, 1);

SET @CGUID := 339598;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -11023.1, -1380.58, 10.8854, 0, 260),
(@PATH, 1, -11034.4, -1383.64, 10.81598, 0, -988),
(@PATH, 2, -11045.8, -1386.95, 10.81598, 0, -875),
(@PATH, 3, -11053.6, -1389.37, 10.81598, 0, -973),
(@PATH, 4, -11064.9, -1392.5, 10.81598, 0, -758),
(@PATH, 5, -11075.9, -1395.61, 10.89567, 0, -1581),
(@PATH, 6, -11085.9, -1397.88, 10.89567, 0, 696),
(@PATH, 7, -11075.9, -1395.61, 10.89567, 0, -1333),
(@PATH, 8, -11064.9, -1392.5, 10.81598, 0, -956),
(@PATH, 9, -11053.6, -1389.37, 10.81598, 0, -753),
(@PATH, 10, -11045.8, -1386.95, 10.81598, 0, -838),
(@PATH, 11, -11034.4, -1383.64, 10.81598, 0, -800);

UPDATE `creature` SET `position_x`= -11023.1, `position_y`= -1380.58, `position_z`= 10.8854, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
UPDATE `creature` SET `position_x`= -11023.1, `position_y`= -1380.58, `position_z`= 10.8854, `orientation`= 0, `spawndist`= 0, `MovementType`= 0 WHERE `guid`= 339597;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `bytes2`) VALUES
(@CGUID, @PATH, 1);

DELETE FROM `creature_formations` WHERE `LeaderGUID`= @CGUID;
INSERT INTO `creature_formations` (`LeaderGUID`, `MemberGUID`, `FollowDistance`, `FollowAngle`, `GroupAI`, `InversionPoint1`, `InversionPoint2`) VALUES
(@CGUID, @CGUID, 0, 0, 515, 0, 0),
(@CGUID, 339597, 4, 270, 515, 6, 0);

SET @CGUID := 339647;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -11091, -1326.5, 10.88428, 0, 100),
(@PATH, 1, -11082.5, -1325.75, 10.88428, 0, -1517),
(@PATH, 2, -11069.6, -1321.7, 10.80078, 0, -1160),
(@PATH, 3, -11057, -1317, 10.81959, 0, -1200),
(@PATH, 4, -11043.3, -1312.46, 10.81959, 0, -1370),
(@PATH, 5, -11029.4, -1309.01, 10.92488, 0, 27),
(@PATH, 6, -11043.3, -1312.46, 10.81959, 0, -1370),
(@PATH, 7, -11057, -1317, 10.81959, 0, -1584),
(@PATH, 8, -11069.6, -1321.7, 10.80078, 0, -1236),
(@PATH, 9, -11082.5, -1325.75, 10.88428, 0, -901);

UPDATE `creature` SET `position_x`= -11091, `position_y`= -1326.5, `position_z`= 10.88428, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
UPDATE `creature` SET `position_x`= -11091, `position_y`= -1326.5, `position_z`= 10.88428, `orientation`= 0, `spawndist`= 0, `MovementType`= 0 WHERE `guid`= 339648;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `bytes2`) VALUES
(@CGUID, @PATH, 1);

DELETE FROM `creature_formations` WHERE `LeaderGUID`= @CGUID;
INSERT INTO `creature_formations` (`LeaderGUID`, `MemberGUID`, `FollowDistance`, `FollowAngle`, `GroupAI`, `InversionPoint1`, `InversionPoint2`) VALUES
(@CGUID, @CGUID, 0, 0, 515, 0, 0),
(@CGUID, 339648, 4, 270, 515, 6, 0);
