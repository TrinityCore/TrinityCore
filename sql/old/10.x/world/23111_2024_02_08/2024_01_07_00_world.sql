-- Creature
UPDATE `creature` SET `wander_distance`=20,`MovementType`=1 WHERE `id`=39004; -- Pygmy Surf Crawler
UPDATE `creature` SET `wander_distance`=10,`MovementType`=1 WHERE `id`=6145; -- School of Fish
UPDATE `creature` SET `wander_distance`=6,`MovementType`=1 WHERE `id`=37961; -- Corrupted Bloodtalon
UPDATE `creature` SET `wander_distance`=6,`MovementType`=1 WHERE `guid` IN (309242, 309226, 309233, 309218, 309215, 309243, 309237, 309231); -- Bloodtalon Raptor
UPDATE `creature` SET `wander_distance`=8,`MovementType`=1 WHERE `guid` IN (309287, 309303, 309308, 309310, 309258, 309309, 309288, 309282, 309286, 309271, 309264, 309261, 309280, 309260); -- Bloodtalon Raptor
UPDATE `creature` SET `wander_distance`=4,`MovementType`=1 WHERE `guid` IN (309289, 309285, 309283, 309277, 309284, 309281, 309272, 309269, 309268, 309274, 309275, 309278, 309273, 309294, 309297, 309293, 309295, 309292, 309302, 309304, 309306, 309301); -- Bloodtalon Hatchling
UPDATE `creature` SET `wander_distance`=4,`MovementType`=1 WHERE `id`=39157; -- Lost Bloodtalon Hatchling

-- Creature Addon
DELETE FROM `creature_addon` WHERE `guid` IN (308753,308768);
INSERT INTO `creature_addon` (`guid`,`PathId`,`mount`,`StandState`,`SheathState`,`emote`,`visibilityDistanceType`,`auras`) VALUES
(308753,0,0,0,1,425,0, '18950'),
(308768,0,0,0,1,425,0, '18950');

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 38005;
INSERT INTO `creature_template_addon` (`entry`,`PathId`,`StandState`,`SheathState`,`auras`) VALUES
(38005,0,1,1,''); -- Moraya

-- Pathing for Ardsami Entry: 90113
SET @ENTRY := 90113;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Ardsami');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1301.47, -5562.309, 21.36381, NULL, 0),
(@PATH, 1, -1308.043, -5559.795, 21.04879, NULL, 0),
(@PATH, 2, -1311.884, -5556.941, 21.04385, NULL, 19936),
(@PATH, 3, -1306.991, -5559.122, 21.03464, NULL, 0),
(@PATH, 4, -1300.597, -5560.802, 21.3103, NULL, 0),
(@PATH, 5, -1295.148, -5563.182, 21.31884, NULL, 0),
(@PATH, 6, -1290.83, -5565.188, 21.03766, NULL, 20030);

UPDATE `creature` SET `position_x`= -1301.47, `position_y`= -5562.309, `position_z`= 21.36381, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= 3000465;
DELETE FROM `creature_addon` WHERE `guid`= 3000465;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(3000465, @PATH, 1);

-- Pathing for Kijara Entry: 37969
SET @ENTRY := 37969;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Kijara');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1549.887, -5314.896, 8.022441, NULL, 27210),
(@PATH, 1, -1559.969, -5304.731, 8.862761, NULL, 2760),
(@PATH, 2, -1555.208, -5296.349, 9.122182, NULL, 3182),
(@PATH, 3, -1553.476, -5311.234, 8.29786, NULL, 0);

UPDATE `creature` SET `position_x`= -1549.887, `position_y`= -5314.896, `position_z`= 8.022441, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= 309291;
DELETE FROM `creature_addon` WHERE `guid`= 309291;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(309291, @PATH, 1);

-- Pathing for Bloodtalon Hatchling Entry: 37960
SET @ENTRY := 37960;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Bloodtalon Hatchling');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1295.399, -5525.825, 20.62567, NULL, 0),
(@PATH, 1, -1287.394, -5535.88, 20.95694, NULL, 0),
(@PATH, 2, -1285.075, -5533.776, 20.94916, NULL, 0),
(@PATH, 3, -1286.203, -5529.047, 20.81564, NULL, 0),
(@PATH, 4, -1292.056, -5524.962, 20.75318, NULL, 0),
(@PATH, 5, -1291.153, -5523.003, 20.76695, 5.689, 34586),
(@PATH, 6, -1292.04, -5519.14, 20.76695, 1.570, 32397);

UPDATE `creature` SET `position_x`= -1295.399, `position_y`= -5525.825, `position_z`= 20.62567, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= 309056;
DELETE FROM `creature_addon` WHERE `guid`= 309056;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(309056, @PATH, 1);

-- Update Pathing for Swiftclaw Entry: 37989
SET @ENTRY := 37989;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Swiftclaw');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1588.484, -5282.405, 7.772076, NULL, 0),
(@PATH, 1, -1631.594, -5272.896, 3.207359, NULL, 0),
(@PATH, 2, -1633.125, -5292.288, 3.067279, NULL, 0),
(@PATH, 3, -1606.47, -5307.899, 6.589447, NULL, 0),
(@PATH, 4, -1603.608, -5325.474, 6.286586, NULL, 0),
(@PATH, 5, -1647.531, -5337.802, 0.8759594, NULL, 0),
(@PATH, 6, -1646.438, -5353.684, 1.191002, NULL, 0),
(@PATH, 7, -1613.677, -5353.108, 4.591012, NULL, 0),
(@PATH, 8, -1589.583, -5354.05, 6.334129, NULL, 0),
(@PATH, 9, -1583.773, -5371.53, 2.030993, NULL, 0),
(@PATH, 10, -1612.688, -5366.184, 3.200978, NULL, 0),
(@PATH, 11, -1599.408, -5349.478, 6.031469, NULL, 0),
(@PATH, 12, -1573.696, -5351.231, 5.943117, NULL, 0),
(@PATH, 13, -1562.012, -5336.09, 7.81131, NULL, 0),
(@PATH, 14, -1549.799, -5324.856, 7.458646, NULL, 0),
(@PATH, 15, -1532.8, -5335.096, 6.897034, NULL, 0),
(@PATH, 16, -1542.205, -5354.551, 5.568115, NULL, 0),
(@PATH, 17, -1531.813, -5367.337, 4.337, NULL, 0),
(@PATH, 18, -1516.96, -5356.293, 6.358775, NULL, 0),
(@PATH, 19, -1509.054, -5333.045, 5.412372, NULL, 0),
(@PATH, 20, -1531.285, -5315.335, 7.199174, NULL, 0),
(@PATH, 21, -1552.431, -5298.374, 9.10468, NULL, 0),
(@PATH, 22, -1576.738, -5285.853, 8.204369, NULL, 0),
(@PATH, 23, -1585.991, -5272.233, 7.801679, NULL, 0),
(@PATH, 24, -1561.387, -5265.125, 7.242541, NULL, 0),
(@PATH, 25, -1526.946, -5293.338, 6.964685, NULL, 0),
(@PATH, 26, -1513.422, -5261.768, 5.990261, NULL, 0),
(@PATH, 27, -1529.59, -5251.986, 5.449595, NULL, 0),
(@PATH, 28, -1546.019, -5244.101, 5.882013, NULL, 0),
(@PATH, 29, -1571.21, -5227.306, 2.905599, NULL, 0),
(@PATH, 30, -1588.757, -5226.844, 2.659902, NULL, 0),
(@PATH, 31, -1592.734, -5240.252, 4.774369, NULL, 0),
(@PATH, 32, -1587.373, -5256.415, 6.227251, NULL, 0),
(@PATH, 33, -1558.642, -5270.479, 7.651531, NULL, 0),
(@PATH, 34, -1550.734, -5285.778, 8.643347, NULL, 0),
(@PATH, 35, -1563.161, -5320.452, 8.062709, NULL, 0),
(@PATH, 36, -1584.167, -5326.924, 7.451439, NULL, 0),
(@PATH, 37, -1589.431, -5312.096, 7.500421, NULL, 0);

UPDATE `creature` SET `position_x`= -1588.484, `position_y`= -5282.405, `position_z`= 7.772076, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= 309298;
DELETE FROM `creature_addon` WHERE `guid`= 309298;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(309298, @PATH, 1);

-- Creature 90113 smart ai
SET @ENTRY := 90113;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 34, 0, 100, 0, 2, 2, 0, 0, 80, 9011300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 2 - Self: Start timed action list id #9011300 (update out of combat)'),
(@ENTRY, 0, 1, 0, '', 34, 0, 100, 0, 2, 6, 0, 0, 80, 9011301, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 6 - Self: Start timed action list id #9011301 (update out of combat)');

SET @ENTRY := 9011301;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.8498, 'After 0 seconds - Self: Set orientation to 5.8498'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 11, 133464, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell  133464 on Self'),
(@ENTRY, 9, 2, 0, '', 0, 0, 100, 0, 19000, 19000, 0, 0, 92, 0, 133464, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 19 seconds - Self: Interrupt casted spell  133464');

SET @ENTRY := 9011300;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 18000, 18000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 18 seconds - Self: Set emote state to 0');

-- Creature 37969 smart ai
SET @ENTRY := 37969;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 34, 0, 100, 0, 2, 1, 0, 0, 5, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Play emote 16'),
(@ENTRY, 0, 1, 0, '', 34, 0, 100, 0, 2, 2, 0, 0, 5, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 2 - Self: Play emote 16');
