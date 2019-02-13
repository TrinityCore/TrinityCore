-- Creature Tiki Torch 52419 SAI
SET @ENTRY := 52419;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 0, 0, 7000, 7000, 7000, 11, 97000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 7000 and 7000 ms (for the first time, timer between 0 and 7000 ms) - Self: Cast spell 97000 on Self // ");

UPDATE `creature_template` SET `mechanic_immune_mask`= 617299839, `flags_extra`= `flags_extra` | 1073741824 WHERE `entry` IN (52957, 52607, 52614, 52959, 52963, 52601, 52613, 52362);
