-- SW City update - part 2 =>> Area : Stormwind Harbor ( 2 / 4 )

SET @PGUID := 222698;

-- WP Stormwind Dock Worker - GUID : 251591 - ID : 29152
SET @CGUID := 251591;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 24, -8440, 1213.63, 5.245773, 1.480477, 5691),
(@PATH, 0, -8438.29, 1208.49, 5.507004, 0, 0),
(@PATH, 1, -8438.85, 1203.87, 5.495773, 0, 0),
(@PATH, 2, -8440.33, 1201.16, 5.495773, 0, 0),
(@PATH, 3, -8443.44, 1196.41, 5.555136, 0, 0),
(@PATH, 4, -8446.56, 1193.58, 5.613119, 3.235843, 6567),
(@PATH, 5, -8443.73, 1197.8, 5.555136, 0, 0),
(@PATH, 6, -8447.62, 1202.64, 5.370773, 0, 0),
(@PATH, 7, -8455.32, 1207.85, 5.245773, 0, 0),
(@PATH, 8, -8462.26, 1209.92, 5.245773, 0, 0),
(@PATH, 9, -8470.93, 1208.28, 5.320824, 0, 0),
(@PATH, 10, -8481.65, 1203.38, 5.445824, 0, 0),
(@PATH, 11, -8490.66, 1198.83, 5.572631, 0, 0),
(@PATH, 12, -8495.6, 1196.68, 5.572631, 3.703154, 5971),
(@PATH, 13, -8484.4, 1200.02, 5.631004, 0, 0),
(@PATH, 14, -8478.52, 1200.97, 5.532127, 0, 0),
(@PATH, 15, -8471.08, 1203.52, 5.33596, 0, 0),
(@PATH, 16, -8462.38, 1208.81, 5.245773, 0, 0),
(@PATH, 17, -8459.53, 1211.66, 5.245773, 0, 0),
(@PATH, 18, -8456.22, 1214.8, 5.120773, 0, 0),
(@PATH, 19, -8454.09, 1216, 5.120773, 6.275331, 6796),
(@PATH, 20, -8453.24, 1209.54, 5.245773, 0, 0),
(@PATH, 21, -8445.94, 1206.96, 5.223068, 0, 0),
(@PATH, 22, -8443.44, 1207.89, 5.236496, 0, 0),
(@PATH, 23, -8440.85, 1210.46, 5.245773, 0, 0);

UPDATE `creature` SET `position_x`= -8440, `position_y`= 1213.63, `position_z`= 5.245773, `orientation`= 1.480477, `spawnDifficulties`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`, `auras`) VALUES
(@CGUID, @PATH, 1, '83610');

-- Stormwind Dock Worker with guid 251591 smart ai
SET @ENTRY := -251591;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (25159100, 25159101, 25159102, 25159103);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 29152;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 71, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Take off all equipped items'),
(@ENTRY, 0, 1, 0, 34, 0, 100, 0, 2, 4, 0, 0, 80, 25159100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 4 - Self: Start timed action list id #25159100 (update out of combat) // -inline'),
(25159100, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set stand state to KNEEL'),
(25159100, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 28, 83610, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove aura due to spell 83610'),
(25159100, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove stand state KNEEL'),
(@ENTRY, 0, 2, 0, 34, 0, 100, 0, 2, 12, 0, 0, 80, 25159101, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 12 - Self: Start timed action list id #25159101 (update out of combat) // -inline'),
(25159101, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set stand state to KNEEL'),
(25159101, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 85, 83610, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Cast spell 83610 on self'),
(25159101, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove stand state KNEEL'),
(@ENTRY, 0, 3, 0, 34, 0, 100, 0, 2, 19, 0, 0, 80, 25159102, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 19 - Self: Start timed action list id #25159102 (update out of combat) // -inline'),
(25159102, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set stand state to KNEEL'),
(25159102, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 28, 83610, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove aura due to spell 83610'),
(25159102, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove stand state KNEEL'),
(@ENTRY, 0, 4, 0, 34, 0, 100, 0, 2, 24, 0, 0, 80, 25159103, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 24 - Self: Start timed action list id #25159103 (update out of combat) // -inline'),
(25159103, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set stand state to KNEEL'),
(25159103, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 85, 83610, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Cast spell 83610 on self'),
(25159103, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove stand state KNEEL');

-- Stormwind Dock Worker with guid 313465 smart ai
SET @ENTRY := -313465;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (31346500);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 29152;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 25000, 30000, 80, 31346500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 25 - 30 seconds (1 - 1s initially) (OOC) - Self: Start timed action list id #31346500 (update out of combat) // -inline'),
(31346500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 83610, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove aura due to spell 83610'),
(31346500, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set stand state to KNEEL'),
(31346500, 9, 2, 0, 0, 0, 100, 0, 2000, 3000, 0, 0, 17, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 - 3 seconds - Self: Set emote state to 234'),
(31346500, 9, 3, 0, 0, 0, 100, 0, 8000, 12000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 8 - 12 seconds - Self: Set emote state to 0'),
(31346500, 9, 4, 0, 0, 0, 100, 0, 2000, 3000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 - 3 seconds - Self: Remove stand state KNEEL');

-- Stormwind Dock Worker with guid 313464 smart ai
SET @CGUID := 313464;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8537.81, 1258.28, 4.596226, 0, 0), -- Spawn position
(@PATH, 1, -8536.72, 1266.31, 4.596226, 1.959575, 5824),
(@PATH, 2, -8540.46, 1258.84, 4.596226, 0, 0),
(@PATH, 3, -8540.46, 1254.42, 5.633698, 0, 0),
(@PATH, 4, -8542.78, 1248.98, 5.393101, 0, 0),
(@PATH, 5, -8547.35, 1245.88, 5.393101, 0, 0),
(@PATH, 6, -8553.15, 1241.2, 5.393101, 0, 0),
(@PATH, 7, -8555.68, 1234.78, 5.393101, 0, 0),
(@PATH, 8, -8554.55, 1225.95, 5.393101, 0, 0),
(@PATH, 9, -8553.97, 1217.03, 5.205818, 0, 0),
(@PATH, 10, -8555.26, 1210.32, 5.205818, 0, 0),
(@PATH, 11, -8555.79, 1205.208, 5.330818, 4.457134, 6013),
(@PATH, 12, -8557.02, 1211.58, 5.205818, 0, 0),
(@PATH, 13, -8558.23, 1217.91, 5.205818, 0, 0),
(@PATH, 14, -8559.91, 1228.23, 5.393101, 0, 0),
(@PATH, 15, -8556.53, 1237.19, 5.393101, 0, 0),
(@PATH, 16, -8548.47, 1244.95, 5.393101, 0, 0),
(@PATH, 17, -8541.38, 1251.13, 5.393101, 0, 0);

DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`, `auras`) VALUES
(@CGUID, @PATH, 1, 83610);

UPDATE `creature` SET `zoneId`= 1519, `areaId` = 4411, `curhealth`= 11791, `spawntimesecs` = 120, `position_x`= -8537.81, `position_y`= 1258.28, `position_z`= 4.596226, `MovementType`= 2, `VerifiedBuild` = 45745 WHERE `guid` = 313464;

-- Stormwind Dock Worker with guid 313464 smart ai
SET @ENTRY := -313464;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (31346400, 31346401);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 29152;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 1, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 31346400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Start timed action list id #31346400 (update out of combat) // -inline'),
(31346400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Take off all equipped items'),, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 71, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Take off all equipped items'),
(31346400, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set stand state to KNEEL'),
(31346400, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 83610, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Cast spell 83610 on Self'),
(31346400, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove stand state KNEEL'),
(@ENTRY, 0, 2, 0, 34, 0, 100, 0, 2, 11, 0, 0, 80, 31346401, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 11 - Self: Start timed action list id #31346401 (update out of combat) // -inline'),
(31346401, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set stand state to KNEEL'),
(31346401, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 28, 83610, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove aura due to spell 83610'),
(31346401, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove stand state KNEEL');

DELETE FROM `creature` WHERE `guid` = @PGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@PGUID+0, 29152, 0, 1519, 4411, 0, 0, 0, 0, 0, -8447.8896484375, 1228.3800048828125, 5.3133544921875, 4.874576568603515625, 120, 0, 0, 11791, 0, 2, 0, 0, 0, 45745); -- Stormwind Dock Worker (Area: Stormwind Harbor - Difficul, 0)

SET @PATH := @PGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8450.99, 1238.31, 5.313354, 0, 0),
(@PATH, 1, -8448.72, 1233.42, 5.313355, 0, 0),
(@PATH, 2, -8447.89, 1228.38, 5.313354, 4.874580, 11667), -- Spawn position
(@PATH, 3, -8450.1, 1236.06, 5.357065, 0, 0),
(@PATH, 4, -8452.1, 1240.02, 5.313354, 0, 0),
(@PATH, 5, -8452.63, 1244.02, 5.313354, 1.409807, 7869),
(@PATH, 6, -8450.99, 1238.31, 5.313354, 0, 0);

DELETE FROM `creature_addon` WHERE `guid`= @PGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@PGUID, @PATH, 1);

-- Stormwind Dock Worker with guid @PGUID smart ai    
SET @ENTRY1 := -@PGUID;
SET @ENTRY := @PGUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY1;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ENTRY * 100, @ENTRY * 100 + 1);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY1, 0, 0, 0, 34, 0, 100, 0, 2, 2, 0, 0, 80, @ENTRY * 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 2 - Self: Start timed action list id #@ENTRY * 100 (update out of combat) // -inline'),
(@ENTRY * 100, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set emote state to 69'),
(@ENTRY * 100, 9, 1, 0, 0, 0, 100, 0, 3000, 4000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 - 4 seconds - Self: Set emote state to 0'),
(@ENTRY * 100, 9, 2, 0, 0, 0, 100, 0, 1000, 2000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 - 2 seconds - Self: Set emote state to 69'),
(@ENTRY * 100, 9, 3, 0, 0, 0, 100, 0, 2000, 3000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 - 3 seconds - Self: Set emote state to 0'),
(@ENTRY1, 0, 1, 0, 34, 0, 100, 0, 2, 5, 0, 0, 80, @ENTRY * 100 + 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 5 - Self: Start timed action list id #@ENTRY * 100 + 1 (update out of combat) // -inline'),
(@ENTRY * 100 + 1, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set emote state to 69'),
(@ENTRY * 100 + 1, 9, 1, 0, 0, 0, 100, 0, 1000, 2000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 - 2 seconds - Self: Set emote state to 0'),
(@ENTRY * 100 + 1, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set emote state to 69'),
(@ENTRY * 100 + 1, 9, 3, 0, 0, 0, 100, 0, 2000, 3000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 - 3 seconds - Self: Set emote state to 0');

-- Stormwind Harbor Guard
UPDATE `creature` SET `zoneId` = 1519, `areaId` = 4411, `position_x` = -8497.4521484375, `position_y` = 1169.0305, `position_z` = 17.757504, `orientation` = 3.106281, `MovementType`= 2, `spawntimesecs` = 120, `curhealth` = 23582, `VerifiedBuild` = 45745 WHERE `guid` = 313441;

SET @CGUID := 313441;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8479.757812, 1169.146606, 17.709072, 0, 0),
(@PATH, 1, -8497.208, 1169.0305, 17.757504, 0, 0),
(@PATH, 2, -8508.547, 1169.4381, 17.704222, 0, 0),
(@PATH, 3, -8519.886, 1169.8457, 17.65094, 0, 0),
(@PATH, 4, -8526.6455, 1170.0886, 17.714525, 0, 0),
(@PATH, 5, -8530.145, 1170.2145, 17.582886, 0, 0),
(@PATH, 6, -8533.334, 1170.3291, 17.681004, 0, 0),
(@PATH, 7, -8547.19, 1170.8271, 17.730152, 0, 0),
(@PATH, 8, -8578.2471, 1169.9789, 17.707663, 0, 0);

DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID, @PATH, 1);
