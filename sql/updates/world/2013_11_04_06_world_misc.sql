--
DELETE FROM `smart_scripts` WHERE `entryorguid`=28518 AND `source_type`=0 AND `id` BETWEEN 5 AND 8;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(28518, 0, 5, 0, 19, 0, 100, 0, 12676, 0, 0, 0, 85, 55413, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Stefan Vadu - On quest accept (Sabotage) - Cast Clearquest'),
(28518, 0, 6, 0, 19, 0, 100, 0, 12669, 0, 0, 0, 85, 55411, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Stefan Vadu - On quest accept (So Far, So Bad) - Cast Clearquest'),
(28518, 0, 7, 0, 19, 0, 100, 0, 12677, 0, 0, 0, 85, 55412, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Stefan Vadu - On quest accept (Hazardous Materials) - Cast Clearquest'),
(28518, 0, 8, 0, 19, 0, 100, 0, 12661, 0, 0, 0, 85, 55410, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Stefan Vadu - On quest accept (Infiltrating Voltarus) - Cast Clearquests');
