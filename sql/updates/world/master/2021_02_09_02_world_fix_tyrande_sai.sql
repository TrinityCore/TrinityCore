-- Re added SAI for Tyrande
-- Exported from TDB 3.3.5a
DELETE FROM `smart_scripts` WHERE `source_type` = '0' AND `entryorguid` = '7999';
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(7999, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 4, 5885, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tyrande Whisperwind - On Aggro - Play Sound 5885'),
(7999, 0, 1, 0, 0, 0, 100, 0, 9000, 12000, 17000, 22000, 0, 11, 20690, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Tyrande Whisperwind - In Combat - Cast Moonfire'),
(7999, 0, 2, 0, 0, 0, 100, 0, 5000, 7000, 6000, 8000, 0, 11, 20691, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Tyrande Whisperwind - In Combat - Cast Cleave'),
(7999, 0, 3, 0, 0, 0, 100, 0, 11000, 14000, 9000, 12000, 0, 11, 20688, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Tyrande Whisperwind - In Combat - Cast Searing Arrow'),
(7999, 0, 4, 0, 0, 0, 100, 0, 6000, 8000, 20000, 25000, 0, 11, 20687, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Tyrande Whisperwind - In Combat - Cast Starfall');
