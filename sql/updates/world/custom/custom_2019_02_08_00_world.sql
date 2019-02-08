-- Creature Zandalari Juggernaut 52956 SAI
SET @ENTRY := 52956;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 97987, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Self: Cast spell 97987 on Self // "),
(@ENTRY, 0, 1, 2, 2, 0, 100, 1, 0, 50, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 50% (check every 0 - 0 ms) - Self: Talk 0 // "),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 11, 97977, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 97977 on Self // "),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 97970, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 97970 on Self // "),
(@ENTRY, 0, 4, 0, 0, 2, 100, 0, 500, 500, 6000, 6000, 11, 98000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 500 and 500 ms (and later repeats every 6000 and 6000 ms) - Self: Cast spell 98000 on Self // "),
(@ENTRY, 0, 5, 0, 8, 0, 100, 0, 97970, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell 97970 hit  - Self: Set event phase to 2 // ");

-- Creature Zandalari Hierophant 52958 SAI
SET @ENTRY := 52958;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 3000, 4000, 5000, 6000, 11, 97962, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 3000 and 4000 ms (and later repeats every 5000 and 6000 ms) - Self: Cast spell 97962 on Random hostile // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 12000, 13000, 22000, 23000, 11, 97973, 0, 0, 0, 0, 0, 26, 20, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 12000 and 13000 ms (and later repeats every 22000 and 23000 ms) - Self: Cast spell 97973 on Closest friendly creature in 20 yards // "),
(@ENTRY, 0, 2, 3, 2, 0, 100, 1, 0, 50, 0, 0, 11, 97977, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 50% (check every 0 - 0 ms) - Self: Cast spell 97977 on Self // "),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 11, 97969, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 97969 on Self // "),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // "),
(@ENTRY, 0, 5, 0, 8, 0, 100, 0, 97969, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell 97969 hit  - Self: Set event phase to 2 // "),
(@ENTRY, 0, 6, 0, 0, 2, 100, 0, 500, 500, 30000, 31000, 11, 97978, 0, 0, 0, 0, 0, 26, 20, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 500 and 500 ms (and later repeats every 30000 and 31000 ms) - Self: Cast spell 97978 on Closest friendly creature in 20 yards // ");

-- Creature Zandalari Archon 52962 SAI
SET @ENTRY := 52962;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 2, 0, 100, 1, 0, 50, 0, 0, 11, 97977, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 50% (check every 0 - 0 ms) - Self: Cast spell 97977 on Self // "),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 97972, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 97972 on Self // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // "),
(@ENTRY, 0, 3, 0, 0, 0, 100, 0, 3000, 3000, 5000, 5000, 11, 98016, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 3000 and 3000 ms (and later repeats every 5000 and 5000 ms) - Self: Cast spell 98016 on Random hostile // "),
(@ENTRY, 0, 4, 0, 0, 0, 100, 0, 4000, 5000, 5000, 5000, 11, 98014, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 4000 and 5000 ms (and later repeats every 5000 and 5000 ms) - Self: Cast spell 98014 on Random hostile // "),
(@ENTRY, 0, 5, 0, 0, 0, 100, 0, 15000, 15000, 16000, 16000, 11, 98024, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 15000 and 15000 ms (and later repeats every 16000 and 16000 ms) - Self: Cast spell 98024 on Self // "),
(@ENTRY, 0, 6, 0, 8, 0, 100, 0, 97972, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell 97972 hit  - Self: Set event phase to 2 // "),
(@ENTRY, 0, 7, 0, 0, 2, 100, 0, 600, 600, 30000, 30000, 11, 98019, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 600 and 600 ms (and later repeats every 30000 and 30000 ms) - Self: Cast spell 98019 on Self // ");

DELETE FROM `creature_text` WHERE `CreatureID` IN (52958, 52962);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(52958, 0, 0, 'Ancestors be beside me, let \'dem hear yo\' voice!', 14, 14, 100, 0, 0, 0, 51611, 'Zandalari Hierophant - Glory of the Zandalari'),
(52962, 0, 0, 'Ancients of Zandalar, mark ''dem for de black road.', 14, 14, 100, 0, 0, 0, 51630, 'Zandalari Archon - - Glory of the Zandalari');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_zulgurub_sigil_shatter',
'spell_zulgurub_ancient_guardian');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(98024, 'spell_zulgurub_sigil_shatter'),
(97978, 'spell_zulgurub_ancient_guardian');
