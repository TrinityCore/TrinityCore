--
-- Rework Scourge Deathspeaker SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=27615 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(27615, 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 0, 0, 11, 49119, 2, 0, 0, 0, 0, 10, 101497, 27452, 0, 0, 0, 0, 0, 'Scourge Deathspeaker - Out of Combat - Cast \'Fire Beam\' (Triggered)'),
(27615, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 52281, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scourge Deathspeaker - On Aggro - Cast \'Flame of the Seer\' (No Repeat)'),
(27615, 0, 2, 0, 0, 0, 100, 0, 1000, 2000, 5000, 6000, 11, 52282, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scourge Deathspeaker - In Combat - Cast \'Fireball\'');
