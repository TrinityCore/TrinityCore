--
DELETE FROM `smart_scripts` WHERE `entryorguid`=11032 AND `source_type`=0 AND `id`=5;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11032, 0, 5, 0, 6, 0, 100, 0, 0, 0, 0, 0, 104, 0, 0, 0, 0, 0, 0, 14, 47278, 176112, 0, 0, 0, 0, 0, 'Malor the Zealous - On Death - Set Malors Strongbox Selectable');
