-- Creature Spike 44765 SAI
SET @ENTRY := 44765;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 200, 200, 0, 0, 11, 83487, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 200 and 200 ms) - Self: Cast spell 83487 on Self // ");
