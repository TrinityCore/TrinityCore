--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2558400) AND `source_type`=9 AND `id`>2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2558400, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 45775, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'Inquisitor Salrand - On Script - Remove Aura'),
(2558400, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 30, 0, 0, 0, 0, 0, 0,'Inquisitor Salrand - On Script - Start attack');
