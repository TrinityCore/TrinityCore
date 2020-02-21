-- Alliance troups
SET @GUID := -395341;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 63, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set walk // "),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 4700600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Start timed action list id #4700600 // ");

SET @ENTRY := 4700600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -248.271, 2119.36, 87.0129, 0, "When in combat and timer at the begining between 1000 and 1000 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-248.271, 2119.36, 87.0129, 0) (point id 0) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 3700, 3700, 0, 0, 97, 14, 12, 0, 0, 0, 0, 1, 0, 0, 0, -254.559, 2121.7, 81.1795, 0, "When in combat and timer at the begining between 3700 and 3700 ms (and later repeats every 0 and 0 ms) - Self: Jump to pos (-254.559, 2121.7, 81.1795, 0) with speed XY 14 and speed Z 12 // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 2400, 2400, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 7.49774, "When in combat and timer at the begining between 2400 and 2400 ms (and later repeats every 0 and 0 ms) - Self: Look at (0, 0, 0, 7.49774) // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Set run // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 2600, 2600, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 2600 and 2600 ms (and later repeats every 0 and 0 ms) - Self: Talk 0 // "),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 4800, 4800, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 4800 and 4800 ms (and later repeats every 0 and 0 ms) - Self: Talk 1 // "),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 4900, 4900, 0, 0, 84, 0, 0, 0, 0, 0, 0, 10, 395337, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 4900 and 4900 ms (and later repeats every 0 and 0 ms) - Creature Bloodfang Berserker 47027 (395337): Talk 0 // "),
(@ENTRY, 9, 7, 0, 0, 0, 100, 0, 1200, 1200, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 1200 and 1200 ms (and later repeats every 0 and 0 ms) - Self: Talk 5 // "),
(@ENTRY, 9, 8, 0, 0, 0, 100, 0, 4700, 4700, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.35615, "When in combat and timer at the begining between 4700 and 4700 ms (and later repeats every 0 and 0 ms) - Self: Look at (0, 0, 0, 4.35615) // "),
(@ENTRY, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Talk 2 // "),
(@ENTRY, 9, 10, 0, 0, 0, 100, 0, 7500, 7500, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 7500 and 7500 ms (and later repeats every 0 and 0 ms) - Self: Talk 3 // "),
(@ENTRY, 9, 11, 0, 0, 0, 100, 0, 5900, 5900, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -241.84, 2156.7, 90.624, 0, "When in combat and timer at the begining between 5900 and 5900 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-241.84, 2156.7, 90.624, 0) (point id 0) // "),
(@ENTRY, 9, 12, 0, 0, 0, 100, 0, 9900, 9900, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 9900 and 9900 ms (and later repeats every 0 and 0 ms) - Self: Talk 4 // "),
(@ENTRY, 9, 13, 0, 0, 0, 100, 0, 4700, 4700, 0, 0, 11, 87719, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 4700 and 4700 ms (and later repeats every 0 and 0 ms) - Self: Cast spell Cleave (87719) on Self // "),
(@ENTRY, 9, 14, 0, 0, 0, 100, 0, 1200, 1200, 0, 0, 9, 0, 0, 0, 0, 0, 0, 14, 224824, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 1200 and 1200 ms (and later repeats every 0 and 0 ms) - Gameobject Courtyard Door 18895 (224824): Activate (only gameobject) // "),
(@ENTRY, 9, 15, 0, 0, 0, 100, 0, 2400, 2400, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 2400 and 2400 ms (and later repeats every 0 and 0 ms) - Self: Set walk // "),
(@ENTRY, 9, 16, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -228.681, 2146.92, 90.624, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-228.681, 2146.92, 90.624, 0) (point id 0) // "),
(@ENTRY, 9, 17, 0, 0, 0, 100, 0, 7400, 7400, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 9.01014, "When in combat and timer at the begining between 7400 and 7400 ms (and later repeats every 0 and 0 ms) - Self: Look at (0, 0, 0, 9.01014) // ");

SET @GUID := -395339;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 60, 0, 100, 1, 1100, 1100, 0, 0, 97, 14, 12, 0, 0, 0, 0, 1, 0, 0, 0, -253.896, 2116.94, 81.1795, 0, ""),
(@GUID, 0, 1, 0, 60, 0, 100, 1, 2300, 2300, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 7.212862, "");

SET @GUID := -395337;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 60, 0, 100, 1, 1100, 1100, 0, 0, 97, 14, 12, 0, 0, 0, 0, 1, 0, 0, 0, -258.332, 2119.02, 81.1795, 0, ""),
(@GUID, 0, 1, 0, 60, 0, 100, 1, 3200, 3200, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 7.323833, "");

SET @GUID := -395336;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 60, 0, 100, 1, 1100, 1100, 0, 0, 97, 14, 12, 0, 0, 0, 0, 1, 0, 0, 0, -256.205, 2118.07, 81.1795, 0, ""),
(@GUID, 0, 1, 0, 60, 0, 100, 1, 2800, 2800, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 7.287638, "");

-- Pathing for  Entry: 47027 'TDB FORMAT' 
SET @NPC := 395335;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -235.078, 2136.51, 87.0147, 0, 220, 0, 0, 100, 0),
(@PATH, 2, -253.585, 2133.03, 81.981, 0, 2222, 0, 0, 100, 0);
-- 0x20309404202DECC00071740001CB9D57 .go xyz -235.078 2136.51 87.0147
