UPDATE `smart_scripts` SET `id`=5 WHERE `source_type` = 9 AND `entryorguid` = 2229300 AND `id`=4 AND `action_type`=51;

DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryorguid` = 2229300 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(2229300, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 85, 38758, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Inactive Fel Reaver - Action list - Invoker Cast [PH] Quest reward: Nether Gas In a Fel Fire Engine');
