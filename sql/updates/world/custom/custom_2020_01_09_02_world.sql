-- Belmont
SET @GUID := -395384;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 63, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -142.101, 2171.24, 128.201, 0, "When just created - Self: Move to position (-142.101, 2171.24, 128.201, 0) (point id 0) // "),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 4729302, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Start timed action list id #4729302 // ");

SET @ENTRY := 4729302;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 7000 and 7000 ms (and later repeats every 0 and 0 ms) - Self: Talk 8 // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 80, 4729401, 0, 0, 0, 0, 0, 10, 395385, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Start timed action list id #4729401 // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 80, 4703000, 0, 0, 0, 0, 0, 10, 395383, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Start timed action list id #4703000 // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 80, 4703001, 0, 0, 0, 0, 0, 10, 395382, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Start timed action list id #4703001 // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 80, 4703002, 0, 0, 0, 0, 0, 10, 395379, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Start timed action list id #4703002 // "),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 80, 4703003, 0, 0, 0, 0, 0, 10, 395378, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Start timed action list id #4703003 // "),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 80, 4703004, 0, 0, 0, 0, 0, 10, 395380, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Start timed action list id #4703004 // "),
(@ENTRY, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 80, 4703005, 0, 0, 0, 0, 0, 10, 395381, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Start timed action list id #4703005 // "),
(@ENTRY, 9, 8, 0, 0, 0, 100, 0, 17000, 17000, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 17000 and 17000 ms (and later repeats every 0 and 0 ms) - Self: Set walk // "),
(@ENTRY, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -133.266, 2164.33, 128.944, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-133.266, 2164.33, 128.944, 0) (point id 0) // "),
(@ENTRY, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Talk 9 // "),
(@ENTRY, 9, 11, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 9, 0, 0, 0, 0, 0, 0, 14, 224839, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 6000 ms (and later repeats every 0 and 0 ms) - Gameobject Sorcerer's Gate 18972 (224839): Activate (only gameobject) // "),
(@ENTRY, 9, 12, 0, 0, 0, 100, 0, 900, 900, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.77182, "When in combat and timer at the begining between 900 and 900 ms (and later repeats every 0 and 0 ms) - Self: Look at (0, 0, 0, 2.77182) // ");

SET @ENTRY := 4703000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 5, 71, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 5000 ms (and later repeats every 0 and 0 ms) - Self: Play emote ONESHOT_CHEER_NOSHEATHE (71) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -119.922, 2168.9, 139.415, 0, "When in combat and timer at the begining between 3000 and 3000 ms (and later repeats every 0 and 0 ms) - Self: Move to position // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 2400, 2400, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 2400 and 2400 ms (and later repeats every 0 and 0 ms) - Self: Despawn instantly // ");

SET @ENTRY := 4703001;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 5, 71, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 5000 ms (and later repeats every 0 and 0 ms) - Self: Play emote ONESHOT_CHEER_NOSHEATHE (71) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -118.918, 2172.09, 139.866, 0, "When in combat and timer at the begining between 3000 and 3000 ms (and later repeats every 0 and 0 ms) - Self: Move to position // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 2400, 2400, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 2400 and 2400 ms (and later repeats every 0 and 0 ms) - Self: Despawn instantly // ");

SET @ENTRY := 4703002;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 5, 71, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 5000 ms (and later repeats every 0 and 0 ms) - Self: Play emote ONESHOT_CHEER_NOSHEATHE (71) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -120.403, 2168.63, 139.371, 0, "When in combat and timer at the begining between 3000 and 3000 ms (and later repeats every 0 and 0 ms) - Self: Move to position // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 2400, 2400, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 2400 and 2400 ms (and later repeats every 0 and 0 ms) - Self: Despawn instantly // ");

SET @ENTRY := 4703003;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 5, 71, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 5000 ms (and later repeats every 0 and 0 ms) - Self: Play emote ONESHOT_CHEER_NOSHEATHE (71) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -119.325, 2173.39, 140.044, 0, "When in combat and timer at the begining between 3000 and 3000 ms (and later repeats every 0 and 0 ms) - Self: Move to position // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 2400, 2400, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 2400 and 2400 ms (and later repeats every 0 and 0 ms) - Self: Despawn instantly // ");

SET @ENTRY := 4703004;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 5, 71, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 5000 ms (and later repeats every 0 and 0 ms) - Self: Play emote ONESHOT_CHEER_NOSHEATHE (71) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -118.906, 2171.71, 139.811, 0, "When in combat and timer at the begining between 3000 and 3000 ms (and later repeats every 0 and 0 ms) - Self: Move to position // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 2400, 2400, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 2400 and 2400 ms (and later repeats every 0 and 0 ms) - Self: Despawn instantly // ");

SET @ENTRY := 4703005;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 5, 71, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 5000 ms (and later repeats every 0 and 0 ms) - Self: Play emote ONESHOT_CHEER_NOSHEATHE (71) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -119.661, 2168.92, 139.427, 0, "When in combat and timer at the begining between 3000 and 3000 ms (and later repeats every 0 and 0 ms) - Self: Move to position // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 2400, 2400, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 2400 and 2400 ms (and later repeats every 0 and 0 ms) - Self: Despawn instantly // ");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= 47031;

-- Cromush
UPDATE `creature_template_movement` SET `Flight`= 1 WHERE `CreatureId`= 47294;

SET @GUID := -395385;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 11, 12980, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Cast spell Simple Teleport (12980) on Self // ");

SET @ENTRY := 4729401;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 5000 ms (and later repeats every 0 and 0 ms) - Self: Talk 2 // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 5200, 5200, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.916666, "When in combat and timer at the begining between 5200 and 5200 ms (and later repeats every 0 and 0 ms) - Self: Look at (0, 0, 0, 5.916666) // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 1200, 1200, 0, 0, 97, 14, 10, 0, 0, 0, 0, 1, 0, 0, 0, -130.894, 2166.81, 138.697, 0, "When in combat and timer at the begining between 1200 and 1200 ms (and later repeats every 0 and 0 ms) - Self: Jump to pos (-130.894, 2166.81, 138.697, 0) with speed XY 14 and speed Z 10 // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 1300, 1300, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -119.031, 2172.02, 139.853, 0, "When in combat and timer at the begining between 1300 and 1300 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-119.031, 2172.02, 139.853, 0) (point id 0) // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 2400, 2400, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 2400 and 2400 ms (and later repeats every 0 and 0 ms) - Self: Despawn instantly // ");
