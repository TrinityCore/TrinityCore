DELETE FROM `creature` WHERE `guid` IN (396340, 396324, 396315, 396311, 396341, 396319);

-- Creature Rampaging Worgen 34884 SAI
SET @GUID := -396310;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell Enrage (8599) on Self // Rampaging Worgen - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Rampaging Worgen - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@GUID, 0, 2, 3, 63, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set react state to REACT_PASSIVE // "),
(@GUID, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1461, 1370.68, 64.398, 0, " Linked - Self: Jump to pos (-1461, 1370.68, 64.398, 0) with speed XY 14 and speed Z 10 // "),
(@GUID, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 6000, 6000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 6000 - 6000 ms // "),
(@GUID, 0, 5, 6, 59, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Set event phase to 1 // "),
(@GUID, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1459.82, 1386.06, 36.0044, 0, " Linked - Self: Jump to pos (-1459.82, 1386.06, 36.0044, 0) with speed XY 14 and speed Z 10 // "),
(@GUID, 0, 7, 8, 34, 1, 100, 0, 16, 1004, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type EFFECT_MOTION_TYPE inform, point 1004 - Self: Set react state to REACT_AGGRESSIVE // "),
(@GUID, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set home position to current position // "),
(@GUID, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, " Linked - Self: Attack Creature Gilneas City Guard (34916) in 40 yd // ");

SET @GUID := -396309;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell Enrage (8599) on Self // Rampaging Worgen - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Rampaging Worgen - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@GUID, 0, 2, 3, 63, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set react state to REACT_PASSIVE // "),
(@GUID, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1421.379, 1378.561, 73.31348, 0, " Linked - Self: Jump to pos (-1421.379, 1378.561, 73.31348, 0) with speed XY 14 and speed Z 10 // "),
(@GUID, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 5600, 5600, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 5600 - 5600 ms // "),
(@GUID, 0, 5, 6, 59, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Set event phase to 1 // "),
(@GUID, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1437.56, 1364.63, 35.5559, 0, " Linked - Self: Jump to pos (-1437.56, 1364.63, 35.5559, 0) with speed XY 14 and speed Z 10 // "),
(@GUID, 0, 7, 8, 34, 1, 100, 0, 16, 1004, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type EFFECT_MOTION_TYPE inform, point 1004 - Self: Set react state to REACT_AGGRESSIVE // "),
(@GUID, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set home position to current position // "),
(@GUID, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, " Linked - Self: Attack Creature Gilneas City Guard (34916) in 40 yd // ");

SET @GUID := -396306;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell Enrage (8599) on Self // Rampaging Worgen - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Rampaging Worgen - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@GUID, 0, 2, 3, 63, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set react state to REACT_PASSIVE // "),
(@GUID, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1425.561, 1358.085, 65.88074, 0, " Linked - Self: Jump to pos (-1425.561, 1358.085, 65.88074, 0) with speed XY 14 and speed Z 10 // "),
(@GUID, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 6000, 6000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 6000 - 6000 ms // "),
(@GUID, 0, 5, 6, 59, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Set event phase to 1 // "),
(@GUID, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1447.21, 1394.15, 35.5559, 0, " Linked - Self: Jump to pos (-1447.21, 1394.15, 35.5559, 0) with speed XY 14 and speed Z 10 // "),
(@GUID, 0, 7, 8, 34, 1, 100, 0, 16, 1004, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type EFFECT_MOTION_TYPE inform, point 1004 - Self: Set react state to REACT_AGGRESSIVE // "),
(@GUID, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set home position to current position // "),
(@GUID, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, " Linked - Self: Attack Creature Gilneas City Guard (34916) in 40 yd // ");

SET @GUID := -396318;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell Enrage (8599) on Self // Rampaging Worgen - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Rampaging Worgen - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@GUID, 0, 2, 3, 63, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set react state to REACT_PASSIVE // "),
(@GUID, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1421.267, 1380.352, 72.88285, 0, " Linked - Self: Jump to pos (-1421.267, 1380.352, 72.88285, 0) with speed XY 14 and speed Z 10 // "),
(@GUID, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 7300, 7300, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 7300 - 7300 ms // "),
(@GUID, 0, 5, 6, 59, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Set event phase to 1 // "),
(@GUID, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1444.52, 1388.68, 35.5559, 0, " Linked - Self: Jump to pos (-1444.52, 1388.68, 35.5559, 0) with speed XY 14 and speed Z 10 // "),
(@GUID, 0, 7, 8, 34, 1, 100, 0, 16, 1004, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type EFFECT_MOTION_TYPE inform, point 1004 - Self: Set react state to REACT_AGGRESSIVE // "),
(@GUID, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set home position to current position // "),
(@GUID, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, " Linked - Self: Attack Creature Gilneas City Guard (34916) in 40 yd // ");

SET @GUID := -396343;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell Enrage (8599) on Self // Rampaging Worgen - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Rampaging Worgen - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@GUID, 0, 2, 3, 63, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set react state to REACT_PASSIVE // "),
(@GUID, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1421.38, 1413.828, 64.13194, 0, " Linked - Self: Jump to pos (-1421.38, 1413.828, 64.13194, 0) with speed XY 14 and speed Z 10 // "),
(@GUID, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 5000, 5000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 5000 - 5000 ms // "),
(@GUID, 0, 5, 6, 59, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Set event phase to 1 // "),
(@GUID, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1437.75, 1394.52, 35.5559, 0, " Linked - Self: Jump to pos (-1437.75, 1394.52, 35.5559, 0) with speed XY 14 and speed Z 10 // "),
(@GUID, 0, 7, 8, 34, 1, 100, 0, 16, 1004, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type EFFECT_MOTION_TYPE inform, point 1004 - Self: Set react state to REACT_AGGRESSIVE // "),
(@GUID, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set home position to current position // "),
(@GUID, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, " Linked - Self: Attack Creature Gilneas City Guard (34916) in 40 yd // ");

SET @GUID := -396332;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell Enrage (8599) on Self // Rampaging Worgen - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Rampaging Worgen - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@GUID, 0, 2, 3, 63, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set react state to REACT_PASSIVE // "),
(@GUID, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1476.776, 1440.854, 60.71806, 0, " Linked - Self: Jump to pos (-1476.776, 1440.854, 60.71806, 0) with speed XY 14 and speed Z 10 // "),
(@GUID, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 5000, 5000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 5000 - 5000 ms // "),
(@GUID, 0, 5, 6, 59, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Set event phase to 1 // "),
(@GUID, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1491.3, 1412.48, 35.5559, 0, " Linked - Self: Jump to pos (-1491.3, 1412.48, 35.5559, 0) with speed XY 14 and speed Z 10 // "),
(@GUID, 0, 7, 8, 34, 1, 100, 0, 16, 1004, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type EFFECT_MOTION_TYPE inform, point 1004 - Self: Set react state to REACT_AGGRESSIVE // "),
(@GUID, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set home position to current position // "),
(@GUID, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, " Linked - Self: Attack Creature Gilneas City Guard (34916) in 40 yd // ");

SET @GUID := -396342;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell Enrage (8599) on Self // Rampaging Worgen - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Rampaging Worgen - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@GUID, 0, 2, 3, 63, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set react state to REACT_PASSIVE // "),
(@GUID, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 3488400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Start timed action list id #3488400 // "),
(@GUID, 0, 4, 5, 34, 1, 100, 0, 16, 1004, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type EFFECT_MOTION_TYPE inform, point 1004 - Self: Set react state to REACT_AGGRESSIVE // "),
(@GUID, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set home position to current position // "),
(@GUID, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, " Linked - Self: Attack Creature Gilneas City Guard (34916) in 40 yd // ");

-- TimedActionList  3488400 SAI
SET @ENTRY := 3488400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1387.14, 1426.55, 71.6557, 0, "Update (In Combat) 0 min and 0 max ms (repeat 0 min 0 max ms) - Self: Jump to pos (-1387.14, 1426.55, 71.6557, 0) with speed XY 14 and speed Z 10 // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 3200, 3200, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1417.49, 1417.12, 42.5891, 0, "Update (In Combat) 3200 min and 3200 max ms (repeat 0 min 0 max ms) - Self: Jump to pos (-1417.49, 1417.12, 42.5891, 0) with speed XY 14 and speed Z 10 // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 8500, 8500, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 8500 min and 8500 max ms (repeat 0 min 0 max ms) - Self: Set event phase to 1 // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1446.68, 1420.5, 35.5559, 0, "Update (In Combat) 0 min and 0 max ms (repeat 0 min 0 max ms) - Self: Jump to pos (-1446.68, 1420.5, 35.5559, 0) with speed XY 14 and speed Z 10 // ");

SET @GUID := -396333;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell Enrage (8599) on Self // Rampaging Worgen - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Rampaging Worgen - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@GUID, 0, 2, 3, 63, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set react state to REACT_PASSIVE // "),
(@GUID, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 3488401, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Start timed action list id #3488401 // "),
(@GUID, 0, 4, 5, 34, 1, 100, 0, 16, 1004, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type EFFECT_MOTION_TYPE inform, point 1004 - Self: Set react state to REACT_AGGRESSIVE // "),
(@GUID, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set home position to current position // "),
(@GUID, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, " Linked - Self: Attack Creature Gilneas City Guard (34916) in 40 yd // ");

-- TimedActionList  3488401 SAI
SET @ENTRY := 3488401;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1521.51, 1450.69, 71.2358, 0, "Update (In Combat) 0 min and 0 max ms (repeat 0 min 0 max ms) - Self: Jump to pos (-1521.51, 1450.69, 71.2358, 0) with speed XY 14 and speed Z 10 // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 3600, 3600, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1521.33, 1408.15, 40.1185, 0, "Update (In Combat) 3600 min and 3600 max ms (repeat 0 min 0 max ms) - Self: Jump to pos (-1521.33, 1408.15, 40.1185, 0) with speed XY 14 and speed Z 10 // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 6000 min and 6000 max ms (repeat 0 min 0 max ms) - Self: Set event phase to 1 // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1522.18, 1395.39, 35.5559, 0, "Update (In Combat) 0 min and 0 max ms (repeat 0 min 0 max ms) - Self: Jump to pos (-1522.18, 1395.39, 35.5559, 0) with speed XY 14 and speed Z 10 // ");

SET @GUID := -396316;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell Enrage (8599) on Self // Rampaging Worgen - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Rampaging Worgen - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@GUID, 0, 2, 3, 63, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set react state to REACT_PASSIVE // "),
(@GUID, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1523.646, 1411.806, 39.71187, 0, " Linked - Self: Jump to pos (-1523.646, 1411.806, 39.71187, 0) with speed XY 14 and speed Z 10 // "),
(@GUID, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 6000, 6000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 6000 - 6000 ms // "),
(@GUID, 0, 5, 6, 59, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Set event phase to 1 // "),
(@GUID, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1517.4, 1425.16, 35.5559, 0, " Linked - Self: Jump to pos (-1517.4, 1425.16, 35.5559, 0) with speed XY 14 and speed Z 10 // "),
(@GUID, 0, 7, 8, 34, 1, 100, 0, 16, 1004, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type EFFECT_MOTION_TYPE inform, point 1004 - Self: Set react state to REACT_AGGRESSIVE // "),
(@GUID, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set home position to current position // "),
(@GUID, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, " Linked - Self: Attack Creature Gilneas City Guard (34916) in 40 yd // ");

SET @GUID := -396326;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell Enrage (8599) on Self // Rampaging Worgen - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Rampaging Worgen - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@GUID, 0, 2, 3, 63, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set react state to REACT_PASSIVE // "),
(@GUID, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1528.896, 1381.031, 58.56568, 0, " Linked - Self: Jump to pos (-1528.896, 1381.031, 58.56568, 0) with speed XY 14 and speed Z 10 // "),
(@GUID, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 6000, 6000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 6000 - 6000 ms // "),
(@GUID, 0, 5, 6, 59, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Set event phase to 1 // "),
(@GUID, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 10, 0, 0, 0, 0, 1, 0, 0, 0, -1508.87, 1395.77, 35.5559, 0, " Linked - Self: Jump to pos (-1508.87, 1395.77, 35.5559, 0) with speed XY 14 and speed Z 10 // "),
(@GUID, 0, 7, 8, 34, 1, 100, 0, 16, 1004, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type EFFECT_MOTION_TYPE inform, point 1004 - Self: Set react state to REACT_AGGRESSIVE // "),
(@GUID, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set home position to current position // "),
(@GUID, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, " Linked - Self: Attack Creature Gilneas City Guard (34916) in 40 yd // ");

SET @GUID := -396344;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell Enrage (8599) on Self // Rampaging Worgen - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Rampaging Worgen - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@GUID, 0, 2, 3, 63, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set react state to REACT_PASSIVE // "),
(@GUID, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1518.545, 1381.559, 40.91092, 0, " Linked - Self: Jump to pos (-1518.545, 1381.559, 40.91092, 0) with speed XY 14 and speed Z 15 // "),
(@GUID, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 6000, 6000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 6000 - 6000 ms // "),
(@GUID, 0, 5, 6, 59, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Set event phase to 1 // "),
(@GUID, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1527.77, 1397.33, 35.5559, 0, " Linked - Self: Jump to pos (-1527.77, 1397.33, 35.5559, 0) with speed XY 14 and speed Z 15 // "),
(@GUID, 0, 7, 8, 34, 1, 100, 0, 16, 1004, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type EFFECT_MOTION_TYPE inform, point 1004 - Self: Set react state to REACT_AGGRESSIVE // "),
(@GUID, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set home position to current position // "),
(@GUID, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, " Linked - Self: Attack Creature Gilneas City Guard (34916) in 40 yd // ");

SET @GUID := -396312;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell Enrage (8599) on Self // Rampaging Worgen - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Rampaging Worgen - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@GUID, 0, 2, 3, 63, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set react state to REACT_PASSIVE // "),
(@GUID, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1476.056, 1342.712, 64.17184, 0, " Linked - Self: Jump to pos (-1476.056, 1342.712, 64.17184, 0) with speed XY 14 and speed Z 15 // "),
(@GUID, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 6000, 6000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 6000 - 6000 ms // "),
(@GUID, 0, 5, 6, 59, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Set event phase to 1 // "),
(@GUID, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1501.05, 1347.99, 35.5559, 0, " Linked - Self: Jump to pos (-1501.05, 1347.99, 35.5559, 0) with speed XY 14 and speed Z 15 // "),
(@GUID, 0, 7, 8, 34, 1, 100, 0, 16, 1004, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type EFFECT_MOTION_TYPE inform, point 1004 - Self: Set react state to REACT_AGGRESSIVE // "),
(@GUID, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set home position to current position // "),
(@GUID, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, " Linked - Self: Attack Creature Gilneas City Guard (34916) in 40 yd // ");

SET @GUID := -396334;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell Enrage (8599) on Self // Rampaging Worgen - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Rampaging Worgen - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@GUID, 0, 2, 3, 63, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set react state to REACT_PASSIVE // "),
(@GUID, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 3488402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Start timed action list id #3488402 // "),
(@GUID, 0, 4, 5, 34, 1, 100, 0, 16, 1004, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type EFFECT_MOTION_TYPE inform, point 1004 - Self: Set react state to REACT_AGGRESSIVE // "),
(@GUID, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set home position to current position // "),
(@GUID, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, " Linked - Self: Attack Creature Gilneas City Guard (34916) in 40 yd // ");


-- TimedActionList  3488402 SAI
SET @ENTRY := 3488402;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1477.748, 1329.99, 70.82324, 0, "Update (In Combat) 0 min and 0 max ms (repeat 0 min 0 max ms) - Self: Jump to pos (-1477.748, 1329.99, 70.82324, 0) with speed XY 14 and speed Z 15 // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 3700, 3700, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1485.25, 1358.22, 61.2311, 0, "Update (In Combat) 3700 min and 3700 max ms (repeat 0 min 0 max ms) - Self: Jump to pos (-1485.25, 1358.22, 61.2311, 0) with speed XY 14 and speed Z 15 // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 5000 min and 5000 max ms (repeat 0 min 0 max ms) - Self: Set event phase to 1 // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1511.61, 1340.52, 35.5559, 0, "Update (In Combat) 0 min and 0 max ms (repeat 0 min 0 max ms) - Self: Jump to pos (-1511.61, 1340.52, 35.5559, 0) with speed XY 14 and speed Z 15 // ");

SET @GUID := -396335;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell Enrage (8599) on Self // Rampaging Worgen - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Rampaging Worgen - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@GUID, 0, 2, 3, 63, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set react state to REACT_PASSIVE // "),
(@GUID, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1535.139, 1328.153, 66.55825, 0, " Linked - Self: Jump to pos (-1535.139, 1328.153, 66.55825, 0) with speed XY 14 and speed Z 15 // "),
(@GUID, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 5000, 5000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 5000 - 5000 ms // "),
(@GUID, 0, 5, 6, 59, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Set event phase to 1 // "),
(@GUID, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1532.06, 1346.52, 35.6684, 0, " Linked - Self: Jump to pos (-1532.06, 1346.52, 35.6684, 0) with speed XY 14 and speed Z 15 // "),
(@GUID, 0, 7, 8, 34, 1, 100, 0, 16, 1004, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type EFFECT_MOTION_TYPE inform, point 1004 - Self: Set react state to REACT_AGGRESSIVE // "),
(@GUID, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set home position to current position // "),
(@GUID, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, " Linked - Self: Attack Creature Gilneas City Guard (34916) in 40 yd // ");

SET @GUID := -396330;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell Enrage (8599) on Self // Rampaging Worgen - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Rampaging Worgen - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@GUID, 0, 2, 3, 63, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set react state to REACT_PASSIVE // "),
(@GUID, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1571.002, 1351.12, 61.17989, 0, " Linked - Self: Jump to pos (-1571.002, 1351.12, 61.17989, 0) with speed XY 14 and speed Z 15 // "),
(@GUID, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 4500, 4500, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 4500 - 4500 ms // "),
(@GUID, 0, 5, 6, 59, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Set event phase to 1 // "),
(@GUID, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1564.1, 1361.27, 35.5669, 0, " Linked - Self: Jump to pos (-1564.1, 1361.27, 35.5669, 0) with speed XY 14 and speed Z 15 // "),
(@GUID, 0, 7, 8, 34, 1, 100, 0, 16, 1004, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type EFFECT_MOTION_TYPE inform, point 1004 - Self: Set react state to REACT_AGGRESSIVE // "),
(@GUID, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set home position to current position // "),
(@GUID, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, " Linked - Self: Attack Creature Gilneas City Guard (34916) in 40 yd // ");

SET @GUID := -396337;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell Enrage (8599) on Self // Rampaging Worgen - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Rampaging Worgen - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@GUID, 0, 2, 3, 63, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set react state to REACT_PASSIVE // "),
(@GUID, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1573.484, 1333.042, 58.79423, 0, " Linked - Self: Jump to pos (-1573.484, 1333.042, 58.79423, 0) with speed XY 14 and speed Z 15 // "),
(@GUID, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 4000, 4000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 4000 - 4000 ms // "),
(@GUID, 0, 5, 6, 59, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Set event phase to 1 // "),
(@GUID, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1535.17, 1332.43, 35.5669, 0, " Linked - Self: Jump to pos (-1535.17, 1332.43, 35.5669, 0) with speed XY 14 and speed Z 15 // "),
(@GUID, 0, 7, 8, 34, 1, 100, 0, 16, 1004, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type EFFECT_MOTION_TYPE inform, point 1004 - Self: Set react state to REACT_AGGRESSIVE // "),
(@GUID, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set home position to current position // "),
(@GUID, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, " Linked - Self: Attack Creature Gilneas City Guard (34916) in 40 yd // ");

SET @GUID := -396338;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell Enrage (8599) on Self // Rampaging Worgen - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Rampaging Worgen - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@GUID, 0, 2, 3, 63, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set react state to REACT_PASSIVE // "),
(@GUID, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1573.226, 1333.057, 58.87081, 0, " Linked - Self: Jump to pos (-1573.226, 1333.057, 58.87081, 0) with speed XY 14 and speed Z 15 // "),
(@GUID, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 4000, 4000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 4000 - 4000 ms // "),
(@GUID, 0, 5, 6, 59, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Set event phase to 1 // "),
(@GUID, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1539.02, 1335.85, 35.5669, 0, " Linked - Self: Jump to pos (-1539.02, 1335.85, 35.5669, 0) with speed XY 14 and speed Z 15 // "),
(@GUID, 0, 7, 8, 34, 1, 100, 0, 16, 1004, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type EFFECT_MOTION_TYPE inform, point 1004 - Self: Set react state to REACT_AGGRESSIVE // "),
(@GUID, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set home position to current position // "),
(@GUID, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, " Linked - Self: Attack Creature Gilneas City Guard (34916) in 40 yd // ");

SET @GUID := -396307;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell Enrage (8599) on Self // Rampaging Worgen - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Rampaging Worgen - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@GUID, 0, 2, 3, 63, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set react state to REACT_PASSIVE // "),
(@GUID, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1388.774, 1370.519, 35.80763, 0, " Linked - Self: Jump to pos (-1388.774, 1370.519, 35.80763, 0) with speed XY 14 and speed Z 15 // "),
(@GUID, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 5000, 5000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 5000 - 5000 ms // "),
(@GUID, 0, 5, 6, 59, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Set event phase to 1 // "),
(@GUID, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1442.83, 1381.44, 35.5669, 0, " Linked - Self: Jump to pos (-1442.83, 1381.44, 35.5669, 0) with speed XY 14 and speed Z 15 // "),
(@GUID, 0, 7, 8, 34, 1, 100, 0, 16, 1004, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type EFFECT_MOTION_TYPE inform, point 1004 - Self: Set react state to REACT_AGGRESSIVE // "),
(@GUID, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set home position to current position // "),
(@GUID, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, " Linked - Self: Attack Creature Gilneas City Guard (34916) in 40 yd // ");

SET @GUID := -396314;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell Enrage (8599) on Self // Rampaging Worgen - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Rampaging Worgen - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@GUID, 0, 2, 3, 63, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set react state to REACT_PASSIVE // "),
(@GUID, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1398.736, 1363.804, 35.55593, 0, " Linked - Self: Jump to pos (-1398.736, 1363.804, 35.55593, 0) with speed XY 14 and speed Z 15 // "),
(@GUID, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 5000, 5000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 5000 - 5000 ms // "),
(@GUID, 0, 5, 6, 59, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Set event phase to 1 // "),
(@GUID, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1435.17, 1356.01, 35.5559, 0, " Linked - Self: Jump to pos (-1435.17, 1356.01, 35.5559, 0) with speed XY 14 and speed Z 15 // "),
(@GUID, 0, 7, 8, 34, 1, 100, 0, 16, 1004, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type EFFECT_MOTION_TYPE inform, point 1004 - Self: Set react state to REACT_AGGRESSIVE // "),
(@GUID, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set home position to current position // "),
(@GUID, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, " Linked - Self: Attack Creature Gilneas City Guard (34916) in 40 yd // ");

SET @GUID := -396345;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell Enrage (8599) on Self // Rampaging Worgen - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Rampaging Worgen - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@GUID, 0, 2, 3, 63, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set react state to REACT_PASSIVE // "),
(@GUID, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1560.042, 1433.979, 69.05463, 0, " Linked - Self: Jump to pos (-1560.042, 1433.979, 69.05463, 0) with speed XY 14 and speed Z 15 // "),
(@GUID, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 3600, 3600, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 3600 - 3600 ms // "),
(@GUID, 0, 5, 6, 59, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Set event phase to 1 // "),
(@GUID, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1538.95, 1427.15, 35.5559, 0, " Linked - Self: Jump to pos (-1538.95, 1427.15, 35.5559, 0) with speed XY 14 and speed Z 15 // "),
(@GUID, 0, 7, 8, 34, 1, 100, 0, 16, 1004, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type EFFECT_MOTION_TYPE inform, point 1004 - Self: Set react state to REACT_AGGRESSIVE // "),
(@GUID, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set home position to current position // "),
(@GUID, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, " Linked - Self: Attack Creature Gilneas City Guard (34916) in 40 yd // ");

SET @GUID := -396321;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell Enrage (8599) on Self // Rampaging Worgen - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Rampaging Worgen - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@GUID, 0, 2, 3, 63, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set react state to REACT_PASSIVE // "),
(@GUID, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1561.24, 1380.073, 55.51204, 0, " Linked - Self: Jump to pos (-1561.24, 1380.073, 55.51204, 0) with speed XY 14 and speed Z 15 // "),
(@GUID, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 4800, 4800, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 4800 - 4800 ms // "),
(@GUID, 0, 5, 6, 59, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Set event phase to 1 // "),
(@GUID, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 97, 14, 15, 0, 0, 0, 0, 1, 0, 0, 0, -1553.06, 1397.02, 35.5646, 0, " Linked - Self: Jump to pos (-1553.06, 1397.02, 35.5646, 0) with speed XY 14 and speed Z 15 // "),
(@GUID, 0, 7, 8, 34, 1, 100, 0, 16, 1004, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type EFFECT_MOTION_TYPE inform, point 1004 - Self: Set react state to REACT_AGGRESSIVE // "),
(@GUID, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set home position to current position // "),
(@GUID, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 34916, 40, 0, 0, 0, 0, 0, " Linked - Self: Attack Creature Gilneas City Guard (34916) in 40 yd // ");

-- Pathing for  Entry: 4075 'TDB FORMAT' 
SET @NPC := 376479;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1633.1216, `position_y`= 1352.3368, `position_z`= 20.1016 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1633.1216, 1352.3368, 20.1016, 0, 324, 0, 0, 100, 0),
(@PATH, 2, -1632.9514, 1370.4479, 20.159224, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1633.2466, 1389.9688, 20.248823, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1636.0243, 1398.0365, 20.24961, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -1647.8577, 1395.3021, 19.759865, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -1662.3733, 1381.9202, 15.259866, 0, 334, 0, 0, 100, 0),
(@PATH, 7, -1664.0677, 1363.9392, 15.259866, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -1660.6615, 1347.5052, 15.259866, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -1653.3385, 1337.4653, 15.259866, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -1636.8663, 1337.7709, 19.773293, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -1635.0173, 1317.0035, 19.759869, 0, 297, 0, 0, 100, 0),
(@PATH, 12, -1636.8663, 1337.7709, 19.773293, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -1653.3385, 1337.4653, 15.259866, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -1660.6615, 1347.5052, 15.259866, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -1664.0677, 1363.9392, 15.259866, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -1662.3733, 1381.9202, 15.259866, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -1647.8577, 1395.3021, 19.759865, 0, 106, 0, 0, 100, 0),
(@PATH, 18, -1636.1621, 1398.0088, 20.259865, 0, 43, 0, 0, 100, 0),
(@PATH, 19, -1633.2466, 1389.9688, 20.248823, 0, 0, 0, 0, 100, 0),
(@PATH, 20, -1632.9514, 1370.4479, 20.159224, 0, 0, 0, 0, 100, 0);
-- 0x203AF051C003FAC000003B000004BDAF .go xyz -1633.1216 1352.3368 20.1016

UPDATE `waypoint_data` SET `move_type`= 1 WHERE `id`= @PATH;

-- Pathing for  Entry: 4075 'TDB FORMAT' 
SET @NPC := 376405;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1553.007, `position_y`= 1435.7726, `position_z`= 35.78295 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1553.007, 1435.7726, 35.78295, 0, 336, 0, 0, 100, 0),
(@PATH, 2, -1535.1962, 1434.9757, 35.68094, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1516.375, 1435.5764, 35.724697, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1488.2639, 1435.0817, 35.74745, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -1460.5469, 1434.6267, 35.753765, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -1434.856, 1435.6094, 35.774353, 0, 22, 0, 0, 100, 0),
(@PATH, 7, -1460.5469, 1434.6267, 35.753765, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -1488.2639, 1435.0817, 35.74745, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -1516.375, 1435.5764, 35.724697, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -1535.1962, 1434.9757, 35.68094, 0, 0, 0, 0, 100, 0);
-- 0x203AF051C003FAC000003B000005F36E .go xyz -1553.007 1435.7726 35.78295

UPDATE `waypoint_data` SET `move_type`= 1 WHERE `id`= @PATH;

-- Pathing for  Entry: 4075 'TDB FORMAT' 
SET @NPC := 376428;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1568.0608, `position_y`= 1311.1198, `position_z`= 35.88061 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1568.0608, 1311.1198, 35.88061, 0, 380, 0, 0, 100, 0),
(@PATH, 2, -1545.1754, 1330.6875, 35.61812, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1510.8021, 1340.2656, 35.68091, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1473.8298, 1350.2448, 35.68091, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -1452.7291, 1357.2483, 35.65739, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -1435.4584, 1357.1719, 35.65739, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -1431.6041, 1348.0973, 35.57195, 0, 100, 0, 0, 100, 0),
(@PATH, 8, -1452.7291, 1357.2483, 35.65739, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -1473.8298, 1350.2448, 35.68091, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -1510.8021, 1340.2656, 35.68091, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -1545.1754, 1330.6875, 35.61812, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -1567.9341, 1318.1666, 35.626587, 0, 0, 0, 0, 100, 0);
-- 0x203AF051C003FAC000003B0000062BF5 .go xyz -1568.0608 1311.1198 35.88061

UPDATE `waypoint_data` SET `move_type`= 1 WHERE `id`= @PATH;

-- Pathing for  Entry: 4075 'TDB FORMAT' 
SET @NPC := 376590;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1782.1198, `position_y`= 1482.1598, `position_z`= 20.768042 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1782.1198, 1482.1598, 20.768042, 0, 396, 0, 0, 100, 0),
(@PATH, 2, -1796.9271, 1485.2448, 19.919983, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1801.0642, 1485.382, 19.77467, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1807.3334, 1480.75, 19.464855, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -1806.3611, 1464.2848, 18.961866, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -1804.6129, 1453.6771, 18.961866, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -1780.5504, 1453.4323, 19.470762, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -1772.316, 1451.8004, 19.605284, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -1770.599, 1443.0209, 19.811338, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -1771.0817, 1427.1493, 19.844234, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -1769.3611, 1412.6493, 19.844234, 0, 236, 0, 0, 100, 0),
(@PATH, 12, -1771.0817, 1427.1493, 19.844234, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -1770.599, 1443.0209, 19.811338, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -1772.316, 1451.8004, 19.605284, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -1780.5504, 1453.4323, 19.470762, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -1804.6129, 1453.6771, 18.961866, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -1806.3611, 1464.2848, 18.961866, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -1807.3334, 1480.75, 19.464855, 0, 0, 0, 0, 100, 0),
(@PATH, 19, -1801.0642, 1485.382, 19.77467, 0, 0, 0, 0, 100, 0),
(@PATH, 20, -1796.9271, 1485.2448, 19.919983, 0, 0, 0, 0, 100, 0);
-- 0x203AF051C003FAC000003B0000063DC6 .go xyz -1782.1198 1482.1598 20.768042

UPDATE `waypoint_data` SET `move_type`= 1 WHERE `id`= @PATH;

-- Pathing for  Entry: 4075 'TDB FORMAT' 
SET @NPC := 376420;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1575.6007, `position_y`= 1393.6685, `position_z`= 36.64277 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1575.6007, 1393.6685, 36.64277, 0, 278, 0, 0, 100, 0),
(@PATH, 2, -1563.7832, 1394.5762, 35.930916, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1525.5903, 1391.9445, 35.68091, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1494, 1393.2935, 35.680904, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -1466.6267, 1393.2865, 35.68091, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -1451.7014, 1393.8264, 35.68091, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -1444.4497, 1404.1562, 35.68091, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -1438.8125, 1420.6823, 35.68091, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -1427.9948, 1419.7935, 35.680923, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -1418.1024, 1419.9548, 35.680923, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -1410.5017, 1425.099, 35.680923, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -1409.6962, 1431.6979, 35.816124, 0, 249, 0, 0, 100, 0),
(@PATH, 13, -1410.5017, 1425.099, 35.680923, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -1418.1024, 1419.9548, 35.680923, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -1427.9948, 1419.7935, 35.680923, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -1438.8125, 1420.6823, 35.68091, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -1444.4497, 1404.1562, 35.68091, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -1451.7014, 1393.8264, 35.68091, 0, 0, 0, 0, 100, 0),
(@PATH, 19, -1466.6267, 1393.2865, 35.68091, 0, 0, 0, 0, 100, 0),
(@PATH, 20, -1494, 1393.2935, 35.680904, 0, 0, 0, 0, 100, 0),
(@PATH, 21, -1525.5903, 1391.9445, 35.68091, 0, 0, 0, 0, 100, 0),
(@PATH, 22, -1563.5764, 1394.6354, 35.930916, 0, 0, 0, 0, 100, 0);
-- 0x203AF051C003FAC000003B00000642D4 .go xyz -1575.6007 1393.6685 36.64277

UPDATE `waypoint_data` SET `move_type`= 1 WHERE `id`= @PATH;

-- Pathing for  Entry: 4075 'TDB FORMAT' 
SET @NPC := 376485;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1641.6771, `position_y`= 1305.0035, `position_z`= 19.759869 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1641.6771, 1305.0035, 19.759869, 0, 247, 0, 0, 100, 0),
(@PATH, 2, -1652.6702, 1305.0747, 19.884869, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1666.6442, 1304.9288, 19.884869, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1680.3009, 1301.1322, 20.285326, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -1688.9618, 1302.083, 19.884869, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -1697.5405, 1303.2797, 20.285326, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -1715.3473, 1310.007, 19.884869, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -1730.007, 1319.6198, 19.884869, 0, 251, 0, 0, 100, 0),
(@PATH, 9, -1728.9791, 1333.6805, 20.293655, 0, 418, 0, 0, 100, 0),
(@PATH, 10, -1730.007, 1319.6198, 19.884869, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -1715.3473, 1310.007, 19.884869, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -1697.5405, 1303.2797, 20.285326, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -1688.9618, 1302.083, 19.884869, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -1680.3009, 1301.1322, 20.285326, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -1666.6442, 1304.9288, 19.884869, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -1652.6702, 1305.0747, 19.884869, 0, 0, 0, 0, 100, 0);
-- 0x203AF051C003FAC000003B0000065D01 .go xyz -1641.6771 1305.0035 19.759869

UPDATE `waypoint_data` SET `move_type`= 1 WHERE `id`= @PATH;

-- Pathing for  Entry: 4075 'TDB FORMAT' 
SET @NPC := 376556;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1776.5938, `position_y`= 1336.3594, `position_z`= 19.964855 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1776.5938, 1336.3594, 19.964855, 0, 52, 0, 0, 100, 0),
(@PATH, 2, -1774.8716, 1358.2483, 19.66261, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1785.6719, 1372.0938, 19.93298, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1796.901, 1389.9323, 19.969234, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -1802.4028, 1406.1771, 19.943184, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -1805.7604, 1429.4045, 19.693184, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -1806.3455, 1446.8108, 19.086866, 0, 385, 0, 0, 100, 0),
(@PATH, 8, -1805.7604, 1429.4045, 19.693184, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -1802.4028, 1406.1771, 19.943184, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -1796.901, 1389.9323, 19.969234, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -1785.6719, 1372.0938, 19.93298, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -1774.8716, 1358.2483, 19.66261, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -1770.0209, 1344.467, 19.964855, 0, 0, 0, 0, 100, 0);
-- 0x203AF051C003FAC000003B0000066140 .go xyz -1776.5938 1336.3594 19.964855

UPDATE `waypoint_data` SET `move_type`= 1 WHERE `id`= @PATH;
UPDATE `creature` SET `MovementType`= 1, `spawndist`= 4, `terrainSwapMap`= 638  WHERE `guid` IN (376425, 376437, 376429, 376433, 376430, 376439, 376432);
