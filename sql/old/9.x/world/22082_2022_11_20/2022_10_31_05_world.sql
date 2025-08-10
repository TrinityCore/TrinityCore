SET @OGUID = 400392;

DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 259008, 0, 1519, 1617, '0', 0, 0, -8736.3037109375, 1044.1336669921875, 80.14505767822265625, 4.694936752319335937, 0, 0, -0.71325016021728515, 0.700909554958343505, 120, 255, 1, 46340); -- 7.0 Stormwind - Lion's Rest - Phased WMO (Area: Valley of Heroes - Difficulty: 0)

-- Phase
DELETE FROM `phase_area` WHERE `AreaId` = 1519 AND `PhaseId` = 7434;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(1519, 7434, 'Cosmetic - See Memorial Objects at Lions Rest');

DELETE FROM `phase_name` WHERE `ID` = 7434;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(7434, 'Cosmetic - See Memorial Objects at Lions Rest');

-- Waypoints for entry: 114246 spawnID: 452698
SET @PATH := 452698 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8723.29, 910.9514, 85.40772, 3.9945, 15848),
(@PATH, 1, -8697.948, 937.3524, 85.33095, 1.5268, 14794),
(@PATH, 2, -8715.825, 935.3125, 85.45737, 2.7457, 13701),
(@PATH, 3, -8729.91, 922.3125, 85.36675, 3.2130, 15909);

UPDATE `creature` SET `position_x`= -8723.29, `position_y`= 910.9514, `position_z`= 85.40772, `orientation`= 3.9945, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= 452698;
DELETE FROM `creature_addon` WHERE `guid`= 452698;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(452698, @PATH, 1);

 -- Karl Wogksch smart ai
SET @ENTRY := 114246;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 34, 0, 100, 0, 2, 0, 0, 0, 80, 11424601, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 0 - Self: Start timed action list id #11424600 (update out of combat)'),
(@ENTRY, 0, 1, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 11424600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Start timed action list id #11424601 (update out of combat)'),
(@ENTRY, 0, 2, 0, 34, 0, 100, 0, 2, 2, 0, 0, 80, 11424601, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 2 - Self: Start timed action list id #11424600 (update out of combat)'),
(@ENTRY, 0, 3, 0, 34, 0, 100, 0, 2, 3, 0, 0, 80, 11424600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 3 - Self: Start timed action list id #11424601 (update out of combat)');

 -- Timed list 11424600 smart ai
SET @ENTRY := 11424600;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 128, 1320, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Plays Anim with ID 1320'),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 14000, 14000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 14 seconds - Self: Plays Anim with ID 0');

 -- Timed list 11424601 smart ai
SET @ENTRY := 11424601;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 567, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set emote state to 567'),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 11 seconds - Self: Set emote state to 0');
