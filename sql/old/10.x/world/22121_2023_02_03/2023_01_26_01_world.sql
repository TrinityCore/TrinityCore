-- Steam Tank Engineer with guid 313641 smart ai
SET @ENTRY := -313641;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (31364100);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 29016;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 1000, 3000, 50000, 50000, 80, 31364100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 50 seconds (1 - 3s initially) (OOC) - Self: Start timed action list id #31364100 (update out of combat) // -inline'),
(31364100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 233'),
(31364100, 9, 1, 0, 0, 0, 100, 0, 20000, 20000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 20 seconds - Self: Set emote state to 0'),
(31364100, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Set emote state to 69'),
(31364100, 9, 3, 0, 0, 0, 100, 0, 20000, 20000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 20 seconds - Self: Set emote state to 0');

-- Steam Tank Engineer with guid 313640 smart ai
SET @ENTRY := -313640;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (31364000);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 29016;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 1000, 3000, 65000, 65000, 80, 31364000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 65 seconds (1 - 3s initially) (OOC) - Self: Start timed action list id #31364000 (update out of combat) // -inline'),
(31364000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(31364000, 9, 1, 0, 0, 0, 100, 0, 20000, 20000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 20 seconds - Self: Set emote state to 0'),
(31364000, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Set emote state to 69'),
(31364000, 9, 3, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 15 seconds - Self: Set emote state to 0'),
(31364000, 9, 4, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6 seconds - Self: Set emote state to 233'),
(31364000, 9, 5, 0, 0, 0, 100, 0, 17000, 17000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 17 seconds - Self: Set emote state to 0');

-- Steam Tank Engineer with guid 313637 smart ai
SET @ENTRY := -313637;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (31363700, 31363701, 31363702);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 29016;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 34, 0, 100, 0, 2, 2, 0, 0, 80, 31363700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 2 - Self: Start timed action list id #31363700 (update out of combat) // -inline'),
(31363700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(31363700, 9, 1, 0, 0, 0, 100, 0, 20000, 20000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 20 seconds - Self: Set emote state to 0'),
(@ENTRY, 0, 1, 0, 34, 0, 100, 0, 2, 5, 0, 0, 80, 31363701, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 5 - Self: Start timed action list id #31363701 (update out of combat) // -inline'),
(31363701, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(31363701, 9, 1, 0, 0, 0, 100, 0, 20000, 20000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 20 seconds - Self: Set emote state to 0'),
(@ENTRY, 0, 2, 0, 34, 0, 100, 0, 2, 6, 0, 0, 80, 31363702, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 6 - Self: Start timed action list id #31363702 (update out of combat) // -inline'),
(31363702, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 233'),
(31363702, 9, 1, 0, 0, 0, 100, 0, 21000, 21000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 21 seconds - Self: Set emote state to 0');

SET @CGUID := 313637;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 6, -8333.33, 1143.18, 19.0271, 0.955337, 31896),
(@PATH, 5, -8341.82, 1144.29, 19.1521, 2.38083, 31893),
(@PATH, 4, -8338.68, 1141.81, 19.0271, NULL, 0),
(@PATH, 3, -8330.28, 1139.63, 18.9021, NULL, 0),
(@PATH, 2, -8317.43, 1145.05, 19.0271, 1.1831, 22248),
(@PATH, 1, -8320.71, 1140.15, 18.9021, NULL, 0),
(@PATH, 0, -8329.26, 1139.97, 18.9021, NULL, 0);

UPDATE `creature` SET `position_x`= -8329.26, `position_y`= 1139.97, `position_z`= 18.9021, `orientation`= 0, `spawnDifficulties`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;

DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID, @PATH, 1);

-- Steam Tank Engineer with guid 313639 smart ai
SET @ENTRY := -313639;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (31363900);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 29016;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 1000, 3000, 65000, 65000, 80, 31363900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 65 seconds (1 - 3s initially) (OOC) - Self: Start timed action list id #31363900 (update out of combat) // -inline'),
(31363900, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(31363900, 9, 1, 0, 0, 0, 100, 0, 20000, 20000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 20 seconds - Self: Set emote state to 0'),
(31363900, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Set emote state to 69'),
(31363900, 9, 3, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 15 seconds - Self: Set emote state to 0'),
(31363900, 9, 4, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6 seconds - Self: Set emote state to 233'),
(31363900, 9, 5, 0, 0, 0, 100, 0, 17000, 17000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 17 seconds - Self: Set emote state to 0');

SET @ENTRY := -313643;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (31364300);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 29152;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 1000, 2000, 25000, 25000, 80, 31364300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 25 seconds (1 - 2s initially) (OOC) - Self: Start timed action list id #31364300 (update out of combat) // -inline'),
(31364300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 83610, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove aura due to spell 83610'),
(31364300, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set emote state to 234'),
(31364300, 9, 2, 0, 0, 0, 100, 0, 20000, 20000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 20 seconds - Self: Set emote state to 0');

-- Steam Tank Engineer with guid 313638 smart ai
SET @ENTRY := -313638;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (31363800);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 29016;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 1000, 3000, 90000, 90000, 80, 31363800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 90 seconds (1 - 3s initially) (OOC) - Self: Start timed action list id #31363800 (update out of combat) // -inline'),
(31363800, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Set emote state to 69'),
(31363800, 9, 1, 0, 0, 0, 100, 0, 24000, 24000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 24 seconds - Self: Set emote state to 0'),
(31363800, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Set emote state to 69'),
(31363800, 9, 3, 0, 0, 0, 100, 0, 25000, 25000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 25 seconds - Self: Set emote state to 0'),
(31363800, 9, 4, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6 seconds - Self: Set emote state to 233'),
(31363800, 9, 5, 0, 0, 0, 100, 0, 20000, 20000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 20 seconds - Self: Set emote state to 0');

-- Steam Tank Engineer with guid 313657 smart ai
SET @ENTRY := -313657;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (31365700);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 29016;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 1000, 3000, 40000, 40000, 80, 31365700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 40 seconds (1 - 3s initially) (OOC) - Self: Start timed action list id #31365700 (update out of combat) // -inline'),
(31365700, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Set emote state to 69'),
(31365700, 9, 1, 0, 0, 0, 100, 0, 22000, 22000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 22 seconds - Self: Set emote state to 0'),
(31365700, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6 seconds - Self: Set emote state to 233'),
(31365700, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6 seconds - Self: Set emote state to 0');

-- Steam Tank Engineer GUID : 313655 - Entry : 29016
SET @CGUID := 313655;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8425.388, 1126.362, 19.06917, NULL, 0),
(@PATH, 1, -8420.282, 1127.108, 19.00362, NULL, 0),
(@PATH, 2, -8414.95, 1123.927, 19.06917, NULL, 236),
(@PATH, 3, -8416.248, 1122.003, 19.06917, 3.247623, 30710),
(@PATH, 4, -8419.116, 1126.676, 19.06917, NULL, 0),
(@PATH, 5, -8420.849, 1129.353, 18.85921, NULL, 0),
(@PATH, 6, -8423.114, 1128.677, 18.94417, NULL, 0),
(@PATH, 7, -8422.651, 1126.724, 19.06917, 4.841979, 6799),
(@PATH, 8, -8427.568, 1123.782, 19.06917, NULL, 0),
(@PATH, 9, -8427.253, 1120.467, 19.06917, 0.192424, 24270),
(@PATH, 10, -8425.388, 1126.362, 19.06917, NULL, 0),
(@PATH, 11, -8420.282, 1127.108, 19.00362, NULL, 0),
(@PATH, 12, -8414.95, 1123.927, 19.06917, NULL, 246),
(@PATH, 13, -8416.248, 1122.003, 19.06917, 3.247623, 30653),
(@PATH, 14, -8419.116, 1126.676, 19.06917, NULL, 0),
(@PATH, 15, -8420.849, 1129.353, 18.85921, NULL, 0),
(@PATH, 16, -8423.114, 1128.677, 18.94417, NULL, 0),
(@PATH, 17, -8422.651, 1126.724, 19.06917, 4.841979, 11730),
(@PATH, 18, -8427.568, 1123.782, 19.06917, NULL, 0),
(@PATH, 19, -8427.253, 1120.467, 19.06917, 0.192424, 21887);

UPDATE `creature` SET `position_x`= -8425.388, `position_y`= 1126.362, `position_z`= 19.06917, `orientation`= 0, `spawnDifficulties`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID, @PATH, 1);

 -- Steam Tank Engineer with guid 313655 smart ai
SET @ENTRY := -313655;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (31365500, 31365501, 31365502, 31365503);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 29016;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 34, 0, 100, 0, 2, 3, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 3 - Self: Set emote state to 233'),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 31365500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 3 - Self: Start timed action list id #31365500 (update out of combat) // -inline'),
(31365500, 9, 0, 0, 0, 0, 100, 0, 25000, 25000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 25 seconds - Self: Set emote state to 0'),
(@ENTRY, 0, 2, 3, 34, 0, 100, 0, 2, 9, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 9 - Self: Set emote state to 69'),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 31365501, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 9 - Self: Start timed action list id #31365501 (update out of combat) // -inline'),
(31365501, 9, 0, 0, 0, 0, 100, 0, 21000, 21000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 21 seconds - Self: Set emote state to 0'),
(@ENTRY, 0, 4, 5, 34, 0, 100, 0, 2, 13, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 13 - Self: Set emote state to 69'),
(@ENTRY, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 31365502, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 13 - Self: Start timed action list id #31365502 (update out of combat) // -inline'),
(31365502, 9, 0, 0, 0, 0, 100, 0, 25000, 25000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 25 seconds - Self: Set emote state to 0'),
(@ENTRY, 0, 6, 7, 34, 0, 100, 0, 2, 19, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 19 - Self: Set emote state to 233'),
(@ENTRY, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 31365503, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 19 - Self: Start timed action list id #31365503 (update out of combat) // -inline'),
(31365503, 9, 0, 0, 0, 0, 100, 0, 18000, 18000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 18 seconds - Self: Set emote state to 0');
