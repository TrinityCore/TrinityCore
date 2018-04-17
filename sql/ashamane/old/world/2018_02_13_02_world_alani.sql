-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 64403);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(64403, 0, 0, 0, 11, 0, 100, 512, 0, 0, 0, 0, '', 75, 126188, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aura Nimbus Shroud'),
(64403, 0, 1, 0, 8, 0, 100, 512, 126182, 0, 0, 0, '', 28, 126188, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Remove Aura Nimbus Shroud'),
(64403, 0, 2, 0, 8, 0, 100, 512, 126182, 0, 0, 0, '', 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Remove Unit_flag'),
(64403, 0, 3, 0, 0, 0, 100, 0, 2000, 2000, 13000, 15000, '', 11, 125787, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Lightning Breath');
