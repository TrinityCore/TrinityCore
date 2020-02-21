-- Alliance
SET @GUID := -395355;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 97, 21, 11, 0, 0, 0, 0, 1, 0, 0, 0, -268.177, 2294.44, 77.4874, 0, "When just created - Self: Jump to pos (-268.177, 2294.44, 77.4874, 0) with speed XY 21 and speed Z 11 // "),
(@GUID, 0, 1, 0, 60, 0, 100, 1, 6500, 6500, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 6500 and 6500 ms) - Self: Talk 6 // ");

SET @ENTRY := 47027;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;

SET @GUID := -395352;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 97, 21, 11, 0, 0, 0, 0, 1, 0, 0, 0, -234.196, 2281.85, 76.2979, 0, "Just Created - Jump to Postition"),
(@GUID, 0, 1, 2, 60, 0, 100, 1, 6500, 6500, 0, 0, 17, 418, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 6500 and 6500 ms) - Self: Set emote state (UNIT_NPC_EMOTESTATE) to STATE_EAT (418) // "),
(@GUID, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set UNIT_FIELD_BYTES_1 to 8 // ");

SET @GUID := -395353;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 97, 21, 11, 0, 0, 0, 0, 1, 0, 0, 0, -240.969, 2283.85, 76.3204, 0, "Just Created - Jump to Postition"),
(@GUID, 0, 1, 2, 60, 0, 100, 1, 6500, 6500, 0, 0, 17, 418, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 6500 and 6500 ms) - Self: Set emote state (UNIT_NPC_EMOTESTATE) to STATE_EAT (418) // "),
(@GUID, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set UNIT_FIELD_BYTES_1 to 8 // ");

SET @GUID := -395354;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 97, 21, 11, 0, 0, 0, 0, 1, 0, 0, 0, -255.816, 2289.09, 76.3441, 0, "Just Created - Jump to Postition"),
(@GUID, 0, 1, 2, 60, 0, 100, 1, 6500, 6500, 0, 0, 17, 418, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 6500 and 6500 ms) - Self: Set emote state (UNIT_NPC_EMOTESTATE) to STATE_EAT (418) // "),
(@GUID, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set UNIT_FIELD_BYTES_1 to 8 // ");

-- Horde
-- Belmont
SET @ENTRY := 47293;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;

SET @GUID := -395362;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 80, 4729300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Start timed action list id #4729300 // "),
(@GUID, 0, 1, 0, 17, 0, 100, 0, 47294, 0, 0, 0, 80, 4729400, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On summoned unit High Warlord Cromush (47294)  - Start timed action list id #4729400 // ");

SET @ENTRY := 4729300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 1, 0, 0, 100, 0, 3600, 3600, 0, 0, 28, 58506, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 3600 and 3600 ms (and later repeats every 0 and 0 ms) - Self: Remove aura due to spell Stealth (58506) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set emote state (UNIT_NPC_EMOTESTATE) to 0 // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 200, 200, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 200 and 200 ms (and later repeats every 0 and 0 ms) - Self: Talk 4 // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 3800, 3800, 0, 0, 12, 47294, 8, 0, 0, 0, 0, 8, 0, 0, 0, -269.828, 2293.46, 77.56844, 5.951573, "When in combat and timer at the begining between 3800 and 3800 ms (and later repeats every 0 and 0 ms) - Self: Summon creature High Warlord Cromush (47294) at (-269.828, 2293.46, 77.56844, 5.951573) // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 3500 and 3500 ms (and later repeats every 0 and 0 ms) - Self: Talk 5 // "),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 8400, 8400, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 8400 and 8400 ms (and later repeats every 0 and 0 ms) - Self: Talk 6 // "),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 6000 ms (and later repeats every 0 and 0 ms) - None: Talk 7 // "),
(@ENTRY, 9, 7, 0, 0, 0, 100, 0, 22800, 22800, 0, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 22800 and 22800 ms (and later repeats every 0 and 0 ms) - Self: Play emote ONESHOT_BOW (2) // ");

-- Cromush
SET @ENTRY := 47294;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;

SET @ENTRY := 4729400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 12980, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Cast spell Simple Teleport (12980) on Self // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 6200, 6200, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6200 and 6200 ms (and later repeats every 0 and 0 ms) - Self: Talk 0 // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 16900, 16900, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 16900 and 16900 ms (and later repeats every 0 and 0 ms) - Self: Talk 1 // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 5800, 5800, 0, 0, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5800 and 5800 ms (and later repeats every 0 and 0 ms) - Self: Play emote ONESHOT_TALK_NOSHEATHE (396) // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 4900, 4900, 0, 0, 5, 397, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 4900 and 4900 ms (and later repeats every 0 and 0 ms) - Self: Play emote ONESHOT_POINT_NOSHEATHE (397) // ");
