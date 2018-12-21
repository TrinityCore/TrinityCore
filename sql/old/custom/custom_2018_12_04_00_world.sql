DELETE FROM `creature_addon` WHERE `guid` IN (263870, 263868, 263933, 263932, 263921, 263920, 263862, 263860);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(263870, 0, 0, 0, 257, 375, ''),
(263868, 0, 0, 0, 257, 375, ''),
(263933, 0, 0, 0, 257, 375, ''),
(263932, 0, 0, 0, 257, 375, ''),
(263921, 0, 0, 0, 257, 375, ''),
(263920, 0, 0, 0, 257, 375, ''),
(263862, 0, 0, 0, 257, 375, ''),
(263860, 0, 0, 0, 257, 375, '');

-- Creature Ramkahen Citizen 46402 SAI
SET @ENTRY := 46402;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;

SET @ENTRY := -264447;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 2000, 10000, 2000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 2000 and 10000 ms (and later repeats every 2000 and 10000 ms) - Self: Play emote 1 // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 20000, 30000, 20000, 30000, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 20000 and 30000 ms (and later repeats every 20000 and 30000 ms) - Self: Play emote 25 // ");

SET @ENTRY := -264446;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 2000, 10000, 2000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 2000 and 10000 ms (and later repeats every 2000 and 10000 ms) - Self: Play emote 1 // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 20000, 30000, 20000, 30000, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 20000 and 30000 ms (and later repeats every 20000 and 30000 ms) - Self: Play emote 25 // ");

SET @ENTRY := -264933;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 2000, 10000, 2000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 2000 and 10000 ms (and later repeats every 2000 and 10000 ms) - Self: Play emote 1 // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 20000, 30000, 20000, 30000, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 20000 and 30000 ms (and later repeats every 20000 and 30000 ms) - Self: Play emote 25 // ");

SET @ENTRY := -264934;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 2000, 10000, 2000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 2000 and 10000 ms (and later repeats every 2000 and 10000 ms) - Self: Play emote 1 // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 20000, 30000, 20000, 30000, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 20000 and 30000 ms (and later repeats every 20000 and 30000 ms) - Self: Play emote 25 // ");

SET @ENTRY := -264930;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 2000, 10000, 2000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 2000 and 10000 ms (and later repeats every 2000 and 10000 ms) - Self: Play emote 1 // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 20000, 30000, 20000, 30000, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 20000 and 30000 ms (and later repeats every 20000 and 30000 ms) - Self: Play emote 25 // ");

SET @ENTRY := -264932;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 2000, 10000, 2000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 2000 and 10000 ms (and later repeats every 2000 and 10000 ms) - Self: Play emote 1 // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 20000, 30000, 20000, 30000, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 20000 and 30000 ms (and later repeats every 20000 and 30000 ms) - Self: Play emote 25 // ");

SET @ENTRY := -264931;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 2000, 10000, 2000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 2000 and 10000 ms (and later repeats every 2000 and 10000 ms) - Self: Play emote 1 // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 20000, 30000, 20000, 30000, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 20000 and 30000 ms (and later repeats every 20000 and 30000 ms) - Self: Play emote 25 // ");

SET @ENTRY := -264938;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 2000, 10000, 2000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 2000 and 10000 ms (and later repeats every 2000 and 10000 ms) - Self: Play emote 1 // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 20000, 30000, 20000, 30000, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 20000 and 30000 ms (and later repeats every 20000 and 30000 ms) - Self: Play emote 25 // ");

SET @ENTRY := -264939;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 2000, 10000, 2000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 2000 and 10000 ms (and later repeats every 2000 and 10000 ms) - Self: Play emote 1 // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 20000, 30000, 20000, 30000, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 20000 and 30000 ms (and later repeats every 20000 and 30000 ms) - Self: Play emote 25 // ");

SET @ENTRY := -264936;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 2000, 10000, 2000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 2000 and 10000 ms (and later repeats every 2000 and 10000 ms) - Self: Play emote 1 // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 20000, 30000, 20000, 30000, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 20000 and 30000 ms (and later repeats every 20000 and 30000 ms) - Self: Play emote 25 // ");

SET @ENTRY := -264937;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 2000, 10000, 2000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 2000 and 10000 ms (and later repeats every 2000 and 10000 ms) - Self: Play emote 1 // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 20000, 30000, 20000, 30000, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 20000 and 30000 ms (and later repeats every 20000 and 30000 ms) - Self: Play emote 25 // ");
