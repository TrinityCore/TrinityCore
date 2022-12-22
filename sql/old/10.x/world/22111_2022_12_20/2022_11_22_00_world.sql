-- SW City update - part 2 =>> Area : Stormwind Harbor ( 3 / 4 )

DELETE FROM `creature_addon` WHERE `guid` IN (313610, 313615, 250989, 251030, 313459, 313609, 313605);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(313459, 3134590, 0, 0, 1, 0, 0, 0, 0, 0, '282130'), -- Dockhand - 282130 - Carry Sack (Peasant)
(313610, 3136100, 2410, 0, 1, 0, 0, 0, 0, 0, ''), -- Stormwind Harbor Guard
(313615, 3136150, 2410, 0, 1, 0, 0, 0, 0, 0, ''), -- Stormwind Harbor Guard
(313605, 3136050, 0, 0, 1, 0, 0, 0, 0, 0, '282130'), -- Dockhand - 282130 - Carry Sack (Peasant)
(313609, 3136090, 0, 0, 1, 0, 0, 0, 0, 0, ''); -- Dockhand

UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=29712; -- Stormwind Harbor Guard
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=51348; -- Stormwind Gryphon Rider
UPDATE `creature_template` SET `subname`='The Assurance' WHERE `entry` IN (29296, 29299);

DELETE FROM `creature` WHERE `guid` IN (250989, 251030);

-- Stormwind Harbor Guard WP
SET @CGUID := 313610;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8509.6015, 1214.2220, 5.157134, 0, 0),
(@PATH, 1, -8469.934, 1208.4878, 5.086937, 0, 0),
(@PATH, 2, -8444.612, 1208.3251, 5.18425, 0, 0),
(@PATH, 3, -8421.286, 1208.1751, 5.27389, 0, 0),
(@PATH, 4, -8419.291, 1208.1624, 5.281563, 0, 0);

UPDATE `creature` SET `wander_distance` = 0, `MovementType`= 2 WHERE `guid`= @CGUID;

-- Stormwind Harbor Guard WP
SET @CGUID := 313615;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8337.396, 1215.517, 5.28471, 0, 0),
(@PATH, 1, -8361.695, 1214.241, 5.15971, 0, 0),
(@PATH, 2, -8337.396, 1215.517, 5.28471, 0, 0),
(@PATH, 3, -8298.195, 1215.461, 5.268316, 0, 0),
(@PATH, 4, -8251.519, 1215.401, 5.174629, 0, 0),
(@PATH, 5, -8208.684, 1208.903, 6.532701, 0, 0),
(@PATH, 6, -8251.519, 1215.401, 5.174629, 0, 0),
(@PATH, 7, -8298.195, 1215.461, 5.268316, 0, 0),
(@PATH, 8, -8337.396, 1215.517, 5.28471, 0, 0),
(@PATH, 9, -8361.695, 1214.241, 5.15971, 0, 0),
(@PATH, 10, -8337.396, 1215.517, 5.28471, 0, 0),
(@PATH, 11, -8298.195, 1215.461, 5.268316, 0, 0),
(@PATH, 12, -8251.519, 1215.401, 5.174629, 0, 0),
(@PATH, 13, -8208.684, 1208.903, 6.532701, 0, 0),
(@PATH, 14, -8251.519, 1215.401, 5.174629, 0, 0),
(@PATH, 15, -8298.195, 1215.461, 5.268316, 0, 0),
(@PATH, 16, -8337.396, 1215.517, 5.28471, 0, 0),
(@PATH, 17, -8361.695, 1214.241, 5.15971, 0, 0),
(@PATH, 18, -8337.396, 1215.517, 5.28471, 0, 0);

UPDATE `creature` SET `wander_distance` = 0, `MovementType`= 2 WHERE `guid`= @CGUID;

-- Stormwind Dock Worker - Area: Stormwind Harbor
SET @CGUID := 313616;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8464.406, 1206.201, 5.314133, 0, 0),
(@PATH, 1, -8452.145, 1199.9552, 5.434634, 0, 0),
(@PATH, 2, -8440.33 , 1201.16, 5.4957733, 0, 0),
(@PATH, 3, -8437.671875 , 1192.377441, 5.477279, 4.872821, 7586),
(@PATH, 4, -8440.33 , 1201.16, 5.4957733, 0, 0),
(@PATH, 5, -8501.293, 1204.994, 5.440891, 0, 0),
(@PATH, 6, -8505.168945, 1204.496582, 5.426817, 3.604930, 8215);

UPDATE `creature` SET `position_x`= -8464.406, `position_y`= 1206.201, `position_z`= 5.314133, `wander_distance` = 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID, @PATH, 1);

-- Stormwind Dock Worker with guid 313616 smart ai
SET @ENTRY := -313616;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (31361600, 31361601);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 29152;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 34, 0, 100, 0, 2, 3, 0, 0, 80, 31361600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 3 - Self: Start timed action list id #31361600 (update out of combat) // -inline'),
(31361600, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Set emote state to 69'),
(31361600, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Set emote state to 0'),
(@ENTRY, 0, 1, 0, 34, 0, 100, 0, 2, 6, 0, 0, 80, 31361601, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 6 - Self: Start timed action list id #31361601 (update out of combat) // -inline'),
(31361601, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Set emote state to 69'),
(31361601, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Set emote state to 0');

-- Stormwind Dock Worker with guid 313620 smart ai
SET @ENTRY := -313620;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (31362000);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 29152;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 25000, 30000, 80, 31362000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 25 - 30 seconds (1 - 1s initially) (OOC) - Self: Start timed action list id #31362000 (update out of combat) // -inline'),
(31362000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 83610, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove aura due to spell 83610'),
(31362000, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set stand state to KNEEL'),
(31362000, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 17, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Set emote state to 234'),
(31362000, 9, 3, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 12 seconds - Self: Set emote state to 0'),
(31362000, 9, 4, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 90, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Set stand state to STAND');

-- Stormwind Dockhand - Area: Stormwind Harbor - long road
SET @CGUID := 313459;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8480.91, 1319.51, 5.23798, 0, 0),
(@PATH, 1, -8485.2500, 1322.261719, 5.233716, 1.010540, 9356),
(@PATH, 2, -8480.91, 1319.51, 5.23798, 0, 0),
(@PATH, 3, -8480.87, 1251.77, 5.76071, 0, 0),
(@PATH, 4, -8485.05, 1239.29, 5.23076, 0, 0),
(@PATH, 5, -8496.43, 1235.27, 5.23066, 0, 0),
(@PATH, 6, -8508.56, 1235.4, 5.23066, 0, 0),
(@PATH, 7, -8530.38, 1245.13, 5.23066, 0, 0),
(@PATH, 8, -8547.4,  1245.52, 5.23066, 0, 0),
(@PATH, 9, -8561.02, 1239.26, 5.23066, 0, 0),
(@PATH, 10, -8575.33, 1220.83, 5.643151, 0, 0),
(@PATH, 11, -8576.64, 1194.8, 5.51819, 0, 0),
(@PATH, 12, -8575.24, 1177.15, 18.4897, 0, 0),
(@PATH, 13, -8574.37, 1145.1, 17.9648, 0, 0),
(@PATH, 14, -8587.49, 1122.38, 17.9632, 0, 0),
(@PATH, 15, -8597.44, 1104.74, 27.5189, 0, 0),
(@PATH, 16, -8597.27, 1090.91, 32.7682, 0, 0),
(@PATH, 17, -8590.9, 1077.28, 36.0082, 0, 0),
(@PATH, 18, -8584.64, 1068, 37.4867, 0, 0),
(@PATH, 19, -8572.71, 1052.6, 46.9202, 0, 0),
(@PATH, 20, -8554.42, 1035.65, 59.3236, 0, 0),
(@PATH, 21, -8540.2, 1031.57, 59.512, 0, 0),
(@PATH, 22, -8529.66, 1020.3, 59.6992, 0, 0),
(@PATH, 23, -8521.36, 992.336, 59.4774, 0, 0),
(@PATH, 24, -8510.81, 974.859, 59.479, 0, 0),
(@PATH, 25, -8510.33, 971.9, 59.4633, 3.89761, 7345),
(@PATH, 26, -8510.71, 974.774, 59.4761, 0, 0),
(@PATH, 27, -8521.28, 992.285, 59.479, 0, 0),
(@PATH, 28, -8529.62, 1020.33, 59.7022, 0, 0),
(@PATH, 29, -8540.21, 1031.59, 59.5113, 0, 0),
(@PATH, 30, -8550.78, 1039.03, 59.4272, 0, 0),
(@PATH, 31, -8568.54, 1056.66, 46.6462, 0, 0),
(@PATH, 32, -8580.69, 1071.71, 37.1212, 0, 0),
(@PATH, 33, -8585.94, 1080.75, 34.9448, 0, 0),
(@PATH, 34, -8588.24, 1091.2, 31.8073, 0, 0),
(@PATH, 35, -8580.31, 1115.79, 17.9452, 0, 0),
(@PATH, 36, -8574.34, 1145.09, 17.9637, 0, 0),
(@PATH, 37, -8573.24, 1177.06, 18.4901, 0, 0),
(@PATH, 38, -8573.37, 1194.56, 5.53562, 0, 0),
(@PATH, 39, -8575.33, 1220.83, 5.643151, 0, 0),
(@PATH, 40, -8561.02, 1239.17, 5.23091, 0, 0),
(@PATH, 41, -8547.41, 1245.53, 5.23091, 0, 0),
(@PATH, 42, -8530.34, 1245.1, 5.23091, 0, 0),
(@PATH, 43, -8508.68, 1235.4, 5.23091, 0, 0),
(@PATH, 44, -8496.47, 1235.28, 5.23091, 0, 0),
(@PATH, 45, -8485.08, 1239.24, 5.23095, 0, 0),
(@PATH, 46, -8480.87, 1251.74, 5.75954, 0, 0);

UPDATE `creature` SET `position_x`= -8480.91, `position_y`= 1319.51, `position_z`= 5.23798, `wander_distance` = 0, `MovementType`= 2 WHERE `guid`= @CGUID;

-- Dockhand with guid 313459 smart ai
SET @ENTRY := -313459;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (31345900, 31345901);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 29019;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 31345900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Start timed action list id #31345900 (update out of combat) // -inline'),
(31345900, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 85, 282130, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Cast spell 282130 on self'),
(@ENTRY, 0, 1, 0, 34, 0, 100, 0, 2, 24, 0, 0, 80, 31345901, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 24 - Self: Start timed action list id #31345901 (update out of combat) // -inline'),
(31345901, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 28, 282130, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Remove aura due to spell 282130');

-- Stormwind Dock Worker - Area: Stormwind Harbor
SET @CGUID := 313609;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8405.32, 1216.5, 5.15656, 0.00528744, 0), -- Spawn position
(@PATH, 1, -8402.17, 1216.34, 5.14171, 6.20286, 38000),
(@PATH, 2, -8436.69, 1216.82, 5.1549, 3.13981, 33000);

-- Stormwind Dock Worker with guid 313609 smart ai
SET @ENTRY := -313609;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (31360900, 31360901);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 29152;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 31360900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Start timed action list id #31360900 (update out of combat) // -inline'),
(31360900, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set emote state to 69'),
(31360900, 9, 1, 0, 0, 0, 100, 0, 34000, 34000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 34 seconds - Self: Set emote state to 0'),
(@ENTRY, 0, 1, 0, 34, 0, 100, 0, 2, 2, 0, 0, 80, 31360901, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 2 - Self: Start timed action list id #31360901 (update out of combat) // -inline'),
(31360901, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set emote state to 69'),
(31360901, 9, 1, 0, 0, 0, 100, 0, 29000, 29000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 29 seconds - Self: Set emote state to 0');

-- Stormwind Dockhand - Area: Stormwind Harbor
SET @CGUID := 313605;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8469.76, 1319.7, 5.23688, 0, 0),
(@PATH, 1, -8467.45, 1317.99, 5.22969, 5.817664, 9750),
(@PATH, 2, -8470.93, 1313.08, 5.23897, 0, 0),
(@PATH, 3, -8470.29, 1248.65, 5.23849, 4.761327, 2045),
(@PATH, 4, -8441.68, 1230.75, 5.23027, 0, 0),
(@PATH, 5, -8438.9, 1229.5, 5.23027, 0, 0),
(@PATH, 6, -8428.19, 1225.89, 5.23027, 0, 0),
(@PATH, 7, -8400.8, 1232.4, 5.23027, 0, 0),
(@PATH, 8, -8396.62, 1248.42, 5.23027, 0, 0),
(@PATH, 9, -8390.77, 1249.4, 5.23027, 0, 0),
(@PATH, 10, -8387.84, 1307.83, 5.25174, 1.580432, 10870),
(@PATH, 11, -8387.71, 1277.12, 5.28005, 0, 0),
(@PATH, 12, -8390.62, 1247.05, 5.23119, 0, 0),
(@PATH, 13, -8401.47, 1229.15, 5.2308, 0, 0),
(@PATH, 14, -8428.47, 1224.69, 5.2308, 0, 0),
(@PATH, 15, -8465, 1243.39, 5.23095, 0, 0);

UPDATE `creature` SET `position_x`= -8469.76, `position_y`= 1319.7, `position_z`= 5.23688, `wander_distance` = 0, `MovementType`= 2 WHERE `guid`= @CGUID;

-- Dockhand with guid 313605 smart ai
SET @ENTRY := -313605;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (31360500, 31360501);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 29019;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 31360500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Start timed action list id #31360500 (update out of combat) // -inline'),
(31360500, 9, 0, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 28, 282130, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Remove aura due to spell 282130'),
(@ENTRY, 0, 1, 0, 34, 0, 100, 0, 2, 10, 0, 0, 80, 31360501, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 10 - Self: Start timed action list id #31360501 (update out of combat) // -inline'),
(31360501, 9, 0, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 85, 282130, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6 seconds - Self: Cast spell 282130 on self');

-- Stormwind Dock Worker with guid 313607
SET @CGUID := 313607;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8372.27, 1291.81, 5.37693, NULL, 0),
(@PATH, 1, -8372.36, 1295.16, 5.397205, NULL, 0),
(@PATH, 2, -8373.93, 1297.86, 5.320071, NULL, 7903),
(@PATH, 3, -8375.09, 1279.99, 5.313354, NULL, 0),
(@PATH, 4, -8375.37, 1270.02, 5.313354, NULL, 0),
(@PATH, 5, -8375.11, 1260.83, 5.313354, NULL, 0),
(@PATH, 6, -8374.94, 1254.91, 5.313354, NULL, 0),
(@PATH, 7, -8380.23, 1242.94, 5.352513, NULL, 0),
(@PATH, 8, -8385.63, 1233.02, 5.388877, NULL, 0),
(@PATH, 9, -8388.66, 1227.19, 5.41057, NULL, 0),
(@PATH, 10, -8392.78, 1219.84, 5.410055, NULL, 11748),
(@PATH, 11, -8383.01, 1242.67, 5.347569, NULL, 0),
(@PATH, 12, -8378.04, 1265.83, 5.313354, NULL, 0),
(@PATH, 13, -8378.46, 1273.91, 5.313354, NULL, 0),
(@PATH, 14, -8377.56, 1279.99, 5.313354, NULL, 0),
(@PATH, 15, -8375.82, 1286.26, 5.313354, NULL, 0);

UPDATE `creature` SET `position_x`= -8372.27, `position_y`= 1291.81, `position_z`= 5.37693, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID, @PATH, 1);

-- Stormwind Dock Worker with guid 313607 smart ai
SET @ENTRY := -313607;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (31360700, 31360701);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 29152;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 71, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Take off all equipped items'),
(@ENTRY, 0, 1, 0, 34, 0, 100, 0, 2, 2, 0, 0, 80, 31360700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 2 - Self: Start timed action list id #31360700 (update out of combat) // -inline'),
(31360700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(31360700, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Set emote state to 0'),
(31360700, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Set emote state to 69'),
(31360700, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Set emote state to 0'),
(@ENTRY, 0, 2, 0, 34, 0, 100, 0, 2, 10, 0, 0, 80, 31360701, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 10 - Self: Start timed action list id #31360701 (update out of combat) // -inline'),
(31360701, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(31360701, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Set emote state to 0'),
(31360701, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Set emote state to 69'),
(31360701, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Set emote state to 0');

-- Dockhand with guid 313580 WP
SET @CGUID := 313580;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8379.228, 1312.783, 5.313354, NULL, 0), 
(@PATH, 1, -8378.091, 1324.128, 5.313354, NULL, 0),
(@PATH, 2, -8373.257, 1324.163, 5.313354, 4.669930, 9826),
(@PATH, 3, -8376.374, 1322.796, 5.220047, NULL, 0),
(@PATH, 4, -8379.228, 1312.783, 5.313354, NULL, 0),
(@PATH, 5, -8380.141, 1299.856, 5.378013, NULL, 0),
(@PATH, 6, -8376.221, 1265.028, 5.313354, NULL, 0),
(@PATH, 7, -8370.788, 1227.637, 5.231624, NULL, 0),
(@PATH, 8, -8361.933, 1195.065, 5.616159, NULL, 0),
(@PATH, 9, -8362.246, 1178.997, 17.645021, NULL, 0),
(@PATH, 10, -8361.521, 1158.612, 18.144882, NULL, 0),
(@PATH, 11, -8372.714, 1127.194, 19.01928, NULL, 0),
(@PATH, 12, -8375.056, 1118.154, 19.09496, NULL, 0),
(@PATH, 13, -8373.721, 1113.185, 19.09496, NULL, 8433),
(@PATH, 14, -8374.737, 1123.714, 19.09496, NULL, 0),
(@PATH, 15, -8371.545, 1129.919, 18.81713, NULL, 0),
(@PATH, 16, -8365.591, 1146.693, 18.27713, NULL, 0),
(@PATH, 17, -8358.072, 1178.757, 17.814270, NULL, 0),
(@PATH, 18, -8359.267, 1194.937, 5.617903, NULL, 0), 
(@PATH, 19, -8370.725, 1227.454, 5.231219, NULL, 0),
(@PATH, 20, -8376.200, 1265.093, 5.267419, NULL, 0),
(@PATH, 21, -8380.141, 1299.856, 5.378013, NULL, 0);

UPDATE `creature` SET `position_x`= -8380.175, `position_y`= 1299.527, `position_z`= 5.331614, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID, @PATH, 1);

-- Dockhand with guid 313580 smart ai
SET @ENTRY := -313580;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (31358000, 31358001);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 29019;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 34, 0, 100, 0, 2, 2, 0, 0, 80, 31358000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 2 - Self: Start timed action list id #31358000 (update out of combat) // -inline'),
(31358000, 9, 0, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 85, 282130, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Cast spell 282130 on self'),
(@ENTRY, 0, 1, 0, 34, 0, 100, 0, 2, 13, 0, 0, 80, 31358001, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 13 - Self: Start timed action list id #31358001 (update out of combat) // -inline'),
(31358001, 9, 0, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 28, 282130, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Remove aura due to spell 282130');
