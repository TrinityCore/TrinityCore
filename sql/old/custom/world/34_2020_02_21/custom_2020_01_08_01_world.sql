-- Horde Forsaken Troups
SET @ENTRY := 47030;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;

SET @GUID := -395358;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -276.958, 2287.4, 81.1108, 0, "When just created - Self: Move to position");

SET @GUID := -395359;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -259.259, 2301.61, 75.4333, 0, "When just created - Self: Move to position");

SET @GUID := -395360;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -269.799, 2305.93, 81.1757, 0, "When just created - Self: Move to position");

SET @GUID := -395361;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -266.472, 2283.32, 75.437, 0, "When just created - Self: Move to position");

-- Commander Springvale Alliance
SET @GUID := -395365;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 63, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set walk // "),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 69, 1, 0, 0, 0, 0, 0, 8, 0, 0, 0, -247.068, 2253.4, 100.893, 0, " Linked - Self: Move to position (-276.958, 2287.4, 81.1108, 0) (point id 1) // "),
(@GUID, 0, 2, 0, 34, 0, 100, 0, 8, 1, 0, 0, 89, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type POINT_MOTION_TYPE inform, point 1 - Self: Move in radius 5 yards // ");

SET @GUID := -395364;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 63, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set walk // "),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 69, 1, 0, 0, 0, 0, 0, 8, 0, 0, 0, -257.411, 2244.82, 100.891, 0, " Linked - Self: Move to position (-276.958, 2287.4, 81.1108, 0) (point id 1) // "),
(@GUID, 0, 2, 0, 34, 0, 100, 0, 8, 1, 0, 0, 89, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type POINT_MOTION_TYPE inform, point 1 - Self: Move in radius 5 yards // ");

SET @GUID := -395363;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 63, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set walk // "),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 69, 1, 0, 0, 0, 0, 0, 8, 0, 0, 0, -250.318, 2249.56, 100.892, 0, " Linked - Self: Move to position (-276.958, 2287.4, 81.1108, 0) (point id 1) // "),
(@GUID, 0, 2, 0, 34, 0, 100, 0, 8, 1, 0, 0, 89, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type POINT_MOTION_TYPE inform, point 1 - Self: Move in radius 5 yards // ");

-- Alliance outside
SET @GUID := -395368;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 97, 21, 15, 0, 0, 0, 0, 1, 0, 0, 0, -246.66, 2163.02, 96.6991, 0, "When just created - Self: Jump to pos with speed XY 21 and speed Z 15 // "),
(@GUID, 0, 1, 0, 60, 0, 100, 1, 5000, 5000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 8.723662, "Every 0 and 0 ms (for the first time, timer between 5000 and 5000 ms) - Self: Look at (0, 0, 0, 8.723662) // ");

SET @GUID := -395367;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 97, 21, 11, 0, 0, 0, 0, 1, 0, 0, 0, -242.762, 2152.2, 107.928, 0, "When just created - Self: Jump to pos"),
(@GUID, 0, 1, 0, 60, 0, 100, 1, 4600, 4600, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -245.069, 2146.47, 112.709, 0, "Self: Move to position");

SET @GUID := -395369;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 97, 21, 11, 0, 0, 0, 0, 1, 0, 0, 0, -265.196, 2143.25, 103.483, 0, "When just created - Self: Jump to pos"),
(@GUID, 0, 1, 0, 60, 0, 100, 1, 5000, 5000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -248.983, 2142.2, 114.038, 0, "Self: Move to position");

SET @GUID := -395366;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 97, 21, 11, 0, 0, 0, 0, 1, 0, 0, 0, -237.191, 2135.7, 109.054, 0, "When just created - Self: Jump to pos"),
(@GUID, 0, 1, 0, 60, 0, 100, 1, 5400, 5400, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -245.823, 2129.88, 113.341, 0, "Self: Move to position");

DELETE FROM `areatrigger_scripts` WHERE `ScriptName`= 'at_sfk_outside_ivar_bloodfang';
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(6424, 'at_sfk_outside_ivar_bloodfang');
