-- Creature Defias Pirate 48522 SAI
SET @ENTRY := 48522;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;

SET @ENTRY := -376082;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 1, 0, 100, 0, 0, 8500, 8500, 8500, 67, 0, 1500, 1500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 0 and 8500 ms (and later repeats every 8500 and 8500 ms) - Trigger timed event #0 in 1500 - 1500 ms // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Play emote ONESHOT_USESTANDING (432) // "),
(@ENTRY, 0, 2, 0, 59, 0, 100, 0, 0, 0, 0, 0, 86, 89757, 0, 10, 376041, 0, 0, 10, 375883, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - SMART_TARGET_CREATURE_GUID: Cast spell Cannonball (89757) at Creature General Purpose Bunny JMF 45979 // ");

SET @ENTRY := -375948;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 1, 0, 100, 0, 0, 8500, 8500, 8500, 67, 0, 1500, 1500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 0 and 8500 ms (and later repeats every 8500 and 8500 ms) - Trigger timed event #0 in 1500 - 1500 ms // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Play emote ONESHOT_USESTANDING (432) // "),
(@ENTRY, 0, 2, 0, 59, 0, 100, 0, 0, 0, 0, 0, 86, 89757, 0, 10, 376044, 0, 0, 10, 375882, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - SMART_TARGET_CREATURE_GUID: Cast spell Cannonball (89757) at Creature General Purpose Bunny JMF 45979 // ");

SET @ENTRY := -375951;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 1, 0, 100, 0, 0, 8500, 8500, 8500, 67, 0, 1500, 1500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 0 and 8500 ms (and later repeats every 8500 and 8500 ms) - Trigger timed event #0 in 1500 - 1500 ms // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Play emote ONESHOT_USESTANDING (432) // "),
(@ENTRY, 0, 2, 0, 59, 0, 100, 0, 0, 0, 0, 0, 86, 89757, 0, 10, 376090, 0, 0, 10, 375887, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - SMART_TARGET_CREATURE_GUID: Cast spell Cannonball (89757) at Creature General Purpose Bunny JMF 45979 // ");


SET @ENTRY := -376007;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 1, 0, 100, 0, 0, 8500, 8500, 8500, 67, 0, 1500, 1500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 0 and 8500 ms (and later repeats every 8500 and 8500 ms) - Trigger timed event #0 in 1500 - 1500 ms // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Play emote ONESHOT_USESTANDING (432) // "),
(@ENTRY, 0, 2, 0, 59, 0, 100, 0, 0, 0, 0, 0, 86, 89757, 0, 10, 376067, 0, 0, 10, 375886, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - SMART_TARGET_CREATURE_GUID: Cast spell Cannonball (89757) at Creature General Purpose Bunny JMF 45979 // ");

SET @ENTRY := -376005;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 1, 0, 100, 0, 0, 8500, 8500, 8500, 67, 0, 1500, 1500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 0 and 8500 ms (and later repeats every 8500 and 8500 ms) - Trigger timed event #0 in 1500 - 1500 ms // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Play emote ONESHOT_USESTANDING (432) // "),
(@ENTRY, 0, 2, 0, 59, 0, 100, 0, 0, 0, 0, 0, 86, 89757, 0, 10, 376087, 0, 0, 10, 375953, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - SMART_TARGET_CREATURE_GUID: Cast spell Cannonball (89757) at Creature General Purpose Bunny JMF 45979 // ");

SET @ENTRY := -376042;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 1, 0, 100, 0, 0, 8500, 8500, 8500, 67, 0, 1500, 1500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 0 and 8500 ms (and later repeats every 8500 and 8500 ms) - Trigger timed event #0 in 1500 - 1500 ms // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Play emote ONESHOT_USESTANDING (432) // "),
(@ENTRY, 0, 2, 0, 59, 0, 100, 0, 0, 0, 0, 0, 86, 89757, 0, 10, 376088, 0, 0, 10, 376039, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - SMART_TARGET_CREATURE_GUID: Cast spell Cannonball (89757) at Creature General Purpose Bunny JMF 45979 // ");

SET @ENTRY := -376036;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 1, 0, 100, 0, 0, 8500, 8500, 8500, 67, 0, 1500, 1500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 0 and 8500 ms (and later repeats every 8500 and 8500 ms) - Trigger timed event #0 in 1500 - 1500 ms // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Play emote ONESHOT_USESTANDING (432) // "),
(@ENTRY, 0, 2, 0, 59, 0, 100, 0, 0, 0, 0, 0, 86, 89757, 0, 10, 376001, 0, 0, 10, 375946, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - SMART_TARGET_CREATURE_GUID: Cast spell Cannonball (89757) at Creature General Purpose Bunny JMF 45979 // ");

