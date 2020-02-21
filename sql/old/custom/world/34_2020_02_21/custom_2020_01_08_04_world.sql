SET @GUID := -395348;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 80, 4729301, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Start timed action list id #4729301 // ");

SET @ENTRY := 4729301;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 97, 14, 9, 0, 0, 0, 0, 1, 0, 0, 0, -256.849, 2117.16, 81.1796, 0, "When in combat and timer at the begining between 1000 and 1000 ms (and later repeats every 0 and 0 ms) - Self: Jump to pos (-256.849, 2117.16, 81.1796, 0) with speed XY 14 and speed Z 9 // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 2400, 2400, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1.308997, "When in combat and timer at the begining between 2400 and 2400 ms (and later repeats every 0 and 0 ms) - Self: Look at (0, 0, 0, 1.308997) // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 2600, 2600, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 2600 and 2600 ms (and later repeats every 0 and 0 ms) - Self: Talk 0 // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 12000 and 12000 ms (and later repeats every 0 and 0 ms) - Self: Talk 1 // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 2200, 2200, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -241.741, 2157.09, 90.624, 0, "When in combat and timer at the begining between 2200 and 2200 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-241.741, 2157.09, 90.624, 0) (point id 0) // "),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 10000 and 10000 ms (and later repeats every 0 and 0 ms) - Self: Talk 2 // "),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 5000 ms (and later repeats every 0 and 0 ms) - Self: Talk 3 // "),
(@ENTRY, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 14, 224824, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Gameobject Courtyard Door 18895 (224824): Activate (only gameobject) // "),
(@ENTRY, 9, 8, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 5000 ms (and later repeats every 0 and 0 ms) - Self: Set walk // "),
(@ENTRY, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -219.403, 2143.39, 90.624, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-219.403, 2143.39, 90.624, 0) (point id 0) // "),
(@ENTRY, 9, 10, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.79439, "When in combat and timer at the begining between 11000 and 11000 ms (and later repeats every 0 and 0 ms) - Self: Look at (0, 0, 0, 2.79439) // ");

DELETE FROM `creature_template_addon` WHERE `entry`= 47031;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(47031, 0, 0, 0, 2, 0, ''); -- 47031 (Forsaken Blightspreader)
