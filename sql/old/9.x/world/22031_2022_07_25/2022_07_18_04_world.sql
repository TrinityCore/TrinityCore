-- Creature 3183 smart ai
SET @ENTRY := 3183;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On aggro - Attacked unit: Talk 0 to invoker'),
(@ENTRY, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On death - Killer: Talk 1 to invoker'),
(@ENTRY, 0, 2, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 75965, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell 75965 on Self'),
(@ENTRY, 0, 3, 0, 0, 0, 100, 0, 0, 0, 50000, 60000, 11, 37628, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 50 - 60 seconds (0 - 0s initially) (IC) - Self: Cast spell 37628 on Victim'),
(@ENTRY, 0, 4, 0, 0, 0, 100, 0, 3000, 4000, 10000, 15000, 11, 35913, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 10 - 15 seconds (3 - 4s initially) (IC) - Self: Cast spell 35913 on Victim');
