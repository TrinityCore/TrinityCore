--
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry` IN (4131, 4133);
DELETE FROM `smart_scripts` WHERE `entryorguid`=4131 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4131, 0, 0, 0, 0, 0, 100, 1, 4000, 7000, 22000, 25000, 11, 6016, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Silithid Invader - IC - Cast Pierce Armor'),
(4131, 0, 1, 0, 0, 0, 100, 1, 10000, 16000, 0, 0, 11, 8137, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Silithid Invader - IC - Cast Pierce Armor'),
(4131, 0, 2, 0, 2, 0, 100, 1, 0, 15, 0, 0, 39, 20, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Silithid Invader - on hp below 15 % - call for help');

DELETE FROM `smart_scripts` WHERE `entryorguid`=4133 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4133, 0, 2, 0, 2, 0, 100, 1, 0, 15, 0, 0, 39, 20, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Silithid Hive Drone - on hp below 15 % - call for help');
