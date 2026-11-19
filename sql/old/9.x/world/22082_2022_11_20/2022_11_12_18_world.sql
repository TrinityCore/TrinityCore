UPDATE `waypoint_data` SET `action`=0 WHERE `id`=3139370 AND `point`=9;
DELETE FROM `waypoint_scripts` WHERE `id`=9;

SET @ENTRY := -313937;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2000, 4000, 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 2000 and 4000 ms) - Self: Cast spell Shoot (6660) on Victim // Stormwind City Patroller - In Combat - Cast 'Shoot'"),
(@ENTRY, 0, 1, 0, 9, 0, 100, 0, 0, 5, 11000, 14000, 11, 12169, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When victim in range 0 - 5 yards (check every 11000 - 14000 ms) - Self: Cast spell Shield Block (12169) on Self // Stormwind City Patroller - Within 0-5 Range - Cast 'Shield Block'"),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 5000, 9000, 8000, 13000, 11, 12170, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 9000 ms (and later repeats every 8000 and 13000 ms) - Self: Cast spell Revenge (12170) on Victim // Stormwind City Patroller - In Combat - Cast 'Revenge'"),
(@ENTRY, 0, 3, 0, 34, 0, 100, 0, 2, 8, 0, 0, 80, 197600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement of type WAYPOINT_MOTION_TYPE inform, point 8 - Start timed action list id #197600 // ");

-- TimedActionList  197600 SAI
SET @ENTRY := 197600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 124, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, ""),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 17, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, ""),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, ""),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 124, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "");

DELETE FROM `creature_equip_template` WHERE `CreatureID` IN (1976, 37944) AND `ID` IN (2, 3);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`) VALUES
(1976, 2, 2715, 143, 2551),
(1976, 3, 1902, 0, 2551),
(37944, 2, 2715, 143, 2551);

DELETE FROM `game_event_model_equip` WHERE `guid` IN (314421, 314481, 314630, 314635, 314625, 314069, 326106, 313764, 314048, 314119, 313928, 314087, 314253, 314174, 307151, 314331, 314065, 314015, 313836, 314219, 314333, 314338);
INSERT INTO `game_event_model_equip` (`eventEntry`, `guid`, `modelid`, `equipment_id`) VALUES
(25, 314421, 0, 2),
(25, 314481, 0, 2),
(25, 314630, 0, 2),
(25, 314635, 0, 2),
(25, 314625, 0, 2),
(25, 314069, 0, 2),
(25, 326106, 0, 2),
(25, 313764, 0, 2),
(25, 314048, 0, 2),
(25, 314119, 0, 2),
(25, 313928, 0, 2),
(25, 314087, 0, 2),
(25, 314253, 0, 2),
(25, 314174, 0, 2),
(25, 307151, 0, 2),
(25, 314331, 0, 2),
(25, 314065, 0, 2),
(25, 314015, 0, 2),
(25, 313836, 0, 2),
(25, 314219, 0, 2),
(25, 314333, 0, 2),
(25, 314338, 0, 2);
