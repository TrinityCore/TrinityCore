-- Creature Bad Intentions Target 44586 SAI
SET @ENTRY := 44586;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 27, 0, 100, 0, 0, 0, 0, 0, 67, 0, 1000, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On passenger boarded (vehicle) - Trigger timed event #0 in 1000 - 1000 ms // "),
(@ENTRY, 0, 1, 2, 59, 0, 100, 0, 0, 0, 0, 0, 11, 83339, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Cast spell 83339 on Target unit in Seat 0 // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 50630, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 50630 on Self // ");
