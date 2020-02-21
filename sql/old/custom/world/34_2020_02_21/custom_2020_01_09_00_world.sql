-- Alliance
SET @GUID := -395377;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 80, 4700601, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Start timed action list id #4700601 // ");

SET @ENTRY := 4700601;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -149.165, 2174.34, 127.953, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-149.165, 2174.34, 127.953, 0) (point id 0) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 1, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 3500 and 3500 ms (and later repeats every 0 and 0 ms) - Self: Talk 8 // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 5400, 5400, 0, 0, 1, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5400 and 5400 ms (and later repeats every 0 and 0 ms) - Self: Talk 9 // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 15800, 15800, 0, 0, 1, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 15800 and 15800 ms (and later repeats every 0 and 0 ms) - Self: Talk 10 // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Set walk // "),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -133.304, 2164.27, 128.944, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-133.304, 2164.27, 128.944, 0) (point id 0) // "),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 10200, 10200, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.77023, "When in combat and timer at the begining between 10200 and 10200 ms (and later repeats every 0 and 0 ms) - Self: Look at (0, 0, 0, 2.77023) // "),
(@ENTRY, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 14, 224839, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Gameobject Sorcerer's Gate 18972 (224839): Activate (only gameobject) // ");

SET @GUID := -395375;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 80, 4702700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Start timed action list id #4702700 // ");

SET @ENTRY := 4702700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 13100, 13100, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -141.179, 2172.86, 128.201, 0, "When in combat and timer at the begining between 13100 and 13100 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-141.179, 2172.86, 128.201, 0) (point id 0) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 1600, 1600, 0, 0, 97, 14, 20, 0, 0, 0, 0, 1, 0, 0, 0, -137.408, 2170.33, 136.578, 0, "When in combat and timer at the begining between 1600 and 1600 ms (and later repeats every 0 and 0 ms) - Self: Jump to pos (-137.408, 2170.33, 136.578, 0) with speed XY 14 and speed Z 20 // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 3200, 3200, 0, 0, 97, 14, 10, 0, 0, 0, 0, 1, 0, 0, 0, -132.797, 2166.66, 138.697, 0, "When in combat and timer at the begining between 3200 and 3200 ms (and later repeats every 0 and 0 ms) - Self: Jump to pos (-132.797, 2166.66, 138.697, 0) with speed XY 14 and speed Z 10 // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 800, 800, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -120.785, 2169.25, 139.416, 0, "When in combat and timer at the begining between 800 and 800 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-120.785, 2169.25, 139.416, 0) (point id 0) // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 2000 and 2000 ms (and later repeats every 0 and 0 ms) - Self: Despawn instantly // ");

SET @GUID := -395373;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 80, 4702701, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Start timed action list id #4702701 // ");

SET @ENTRY := 4702701;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 11100, 11100, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -146.189, 2164.87, 128.448, 0, "When in combat and timer at the begining between 11100 and 11100 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-146.189, 2164.87, 128.448, 0) (point id 0) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 900, 900, 0, 0, 97, 14, 20, 0, 0, 0, 0, 1, 0, 0, 0, -138.97, 2166.46, 136.578, 0, "When in combat and timer at the begining between 900 and 900 ms (and later repeats every 0 and 0 ms) - Self: Jump to pos (-138.97, 2166.46, 136.578, 0) with speed XY 14 and speed Z 20 // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 97, 14, 10, 0, 0, 0, 0, 1, 0, 0, 0, -133.672, 2164.91, 138.697, 0, "When in combat and timer at the begining between 4000 and 4000 ms (and later repeats every 0 and 0 ms) - Self: Jump to pos (-133.672, 2164.91, 138.697, 0) with speed XY 14 and speed Z 10 // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 800, 800, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -119.62, 2169.44, 139.479, 0, "When in combat and timer at the begining between 800 and 800 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-119.62, 2169.44, 139.479, 0) (point id 0) // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 2800, 2800, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 2800 and 2800 ms (and later repeats every 0 and 0 ms) - Self: Despawn instantly // ");

SET @GUID := -395372;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 80, 4702702, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Start timed action list id #4702702 // ");

SET @ENTRY := 4702702;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 13500, 13500, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -142.191, 2171.89, 128.201, 0, "When in combat and timer at the begining between 13500 and 13500 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-142.191, 2171.89, 128.201, 0) (point id 0) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 1200, 1200, 0, 0, 97, 14, 20, 0, 0, 0, 0, 1, 0, 0, 0, -137.516, 2169.59, 136.578, 0, "When in combat and timer at the begining between 1200 and 1200 ms (and later repeats every 0 and 0 ms) - Self: Jump to pos (-137.516, 2169.59, 136.578, 0) with speed XY 14 and speed Z 20 // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 3600, 3600, 0, 0, 97, 14, 10, 0, 0, 0, 0, 1, 0, 0, 0, -132.753, 2167.57, 138.697, 0, "When in combat and timer at the begining between 3600 and 3600 ms (and later repeats every 0 and 0 ms) - Self: Jump to pos (-132.753, 2167.57, 138.697, 0) with speed XY 14 and speed Z 10 // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 800, 800, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -119.097, 2172.41, 139.908, 0, "When in combat and timer at the begining between 800 and 800 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-119.097, 2172.41, 139.908, 0) (point id 0) // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 2900, 2900, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 2900 and 2900 ms (and later repeats every 0 and 0 ms) - Self: Despawn instantly // ");

SET @GUID := -395370;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 80, 4702703, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Start timed action list id #4702703 // ");

SET @ENTRY := 4702703;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 11100, 11100, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -147.859, 2168.45, 128.201, 0, "When in combat and timer at the begining between 11100 and 11100 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-147.859, 2168.45, 128.201, 0) (point id 0) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 2100, 2100, 0, 0, 97, 14, 20, 0, 0, 0, 0, 1, 0, 0, 0, -138.807, 2166.77, 136.578, 0, "When in combat and timer at the begining between 2100 and 2100 ms (and later repeats every 0 and 0 ms) - Self: Jump to pos (-138.807, 2166.77, 136.578, 0) with speed XY 14 and speed Z 20 // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 2800, 2800, 0, 0, 97, 14, 10, 0, 0, 0, 0, 1, 0, 0, 0, -130.965, 2166.47, 138.697, 0, "When in combat and timer at the begining between 2800 and 2800 ms (and later repeats every 0 and 0 ms) - Self: Jump to pos (-130.965, 2166.47, 138.697, 0) with speed XY 14 and speed Z 10 // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 1200, 1200, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -120.132, 2168.36, 139.355, 0, "When in combat and timer at the begining between 1200 and 1200 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-120.132, 2168.36, 139.355, 0) (point id 0) // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 2000 and 2000 ms (and later repeats every 0 and 0 ms) - Self: Despawn instantly // ");

SET @GUID := -395376;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 80, 4702704, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Start timed action list id #4702704 // ");

SET @ENTRY := 4702704;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 13500, 13500, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -148.229, 2166.35, 128.448, 0, "When in combat and timer at the begining between 13500 and 13500 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-148.229, 2166.35, 128.448, 0) (point id 0) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 800, 800, 0, 0, 97, 14, 20, 0, 0, 0, 0, 1, 0, 0, 0, -138.858, 2166.37, 136.578, 0, "When in combat and timer at the begining between 800 and 800 ms (and later repeats every 0 and 0 ms) - Self: Jump to pos (-138.858, 2166.37, 136.578, 0) with speed XY 14 and speed Z 20 // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 1800, 1800, 0, 0, 97, 14, 10, 0, 0, 0, 0, 1, 0, 0, 0, -134.12, 2167.11, 138.697, 0, "When in combat and timer at the begining between 1800 and 1800 ms (and later repeats every 0 and 0 ms) - Self: Jump to pos (-134.12, 2167.11, 138.697, 0) with speed XY 14 and speed Z 10 // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 800, 800, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -118.717, 2171.66, 139.81, 0, "When in combat and timer at the begining between 800 and 800 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-118.717, 2171.66, 139.81, 0) (point id 0) // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 2900, 2900, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 2900 and 2900 ms (and later repeats every 0 and 0 ms) - Self: Despawn instantly // ");

SET @GUID := -395374;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 80, 4702705, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Start timed action list id #4702705 // ");

SET @ENTRY := 4702705;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -140.714, 2170.52, 128.201, 0, "When in combat and timer at the begining between 11000 and 11000 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-140.714, 2170.52, 128.201, 0) (point id 0) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 1600, 1600, 0, 0, 97, 14, 20, 0, 0, 0, 0, 1, 0, 0, 0, -138.573, 2169.05, 136.578, 0, "When in combat and timer at the begining between 1600 and 1600 ms (and later repeats every 0 and 0 ms) - Self: Jump to pos (-138.573, 2169.05, 136.578, 0) with speed XY 14 and speed Z 20 // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 3200, 3200, 0, 0, 97, 14, 10, 0, 0, 0, 0, 1, 0, 0, 0, -132.535, 2167.76, 138.697, 0, "When in combat and timer at the begining between 3200 and 3200 ms (and later repeats every 0 and 0 ms) - Self: Jump to pos (-132.535, 2167.76, 138.697, 0) with speed XY 14 and speed Z 10 // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 1200, 1200, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -119.319, 2168.17, 139.368, 0, "When in combat and timer at the begining between 1200 and 1200 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-119.319, 2168.17, 139.368, 0) (point id 0) // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 2400, 2400, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 2400 and 2400 ms (and later repeats every 0 and 0 ms) - Self: Despawn instantly // ");

SET @GUID := -395371;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 80, 4702706, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Start timed action list id #4702706 // ");

SET @ENTRY := 4702706;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -141.41, 2172.98, 128.201, 0, "When in combat and timer at the begining between 11000 and 11000 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-141.41, 2172.98, 128.201, 0) (point id 0) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 1200, 1200, 0, 0, 97, 14, 20, 0, 0, 0, 0, 1, 0, 0, 0, -136.769, 2171.22, 136.578, 0, "When in combat and timer at the begining between 1200 and 1200 ms (and later repeats every 0 and 0 ms) - Self: Jump to pos (-136.769, 2171.22, 136.578, 0) with speed XY 14 and speed Z 20 // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 3600, 3600, 0, 0, 97, 14, 10, 0, 0, 0, 0, 1, 0, 0, 0, -132.109, 2168.61, 138.697, 0, "When in combat and timer at the begining between 3600 and 3600 ms (and later repeats every 0 and 0 ms) - Self: Jump to pos (-132.109, 2168.61, 138.697, 0) with speed XY 14 and speed Z 10 // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 800, 800, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -120.089, 2168.95, 139.414, 0, "When in combat and timer at the begining between 800 and 800 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-120.089, 2168.95, 139.414, 0) (point id 0) // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 2400, 2400, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 2400 and 2400 ms (and later repeats every 0 and 0 ms) - Self: Despawn instantly // ");

-- Horde
SET @CGUID := 395378;
UPDATE `creature` SET `MovementType`= 0, `spawndist`= 0 WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6;
