--
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 29753;
DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 29753);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29753, 0, 0, 0, 0, 0, 100, 0, 3000, 6000, 9000, 12000, 0, 11, 57833, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Stormpeak Wyrm - In Combat - Cast 'Frost Spit'");
