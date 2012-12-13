-- Fix quest The Ring of Blood: The Final Challenge (Nagrand Arena).
DELETE FROM smart_scripts WHERE entryorguid IN (1806900,1806901,18069);

INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(18069, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 3500, 3500, 11, 16033, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Mogor - In Combat - Cast Chain Lightning'),
(18069, 0, 1, 0, 0, 0, 100, 0, 4000, 4000, 11000, 13000, 11, 39529, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Mogor - In Combat - Cast Flame Shock'),
(18069, 0, 2, 0, 2, 0, 100, 1, 0, 60, 0, 0, 11, 15982, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mogor - At 60% HP - Cast Healing Wave'),
(18069, 0, 3, 0, 2, 0, 100, 1, 0, 30, 0, 0, 11, 28747, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mogor - At 30% HP - Cast Frenzy'),
(18069, 0, 4, 0, 2, 0, 100, 1, 0, 30, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - At 30% HP - Say Line 0'),
(18069, 0, 5, 0, 6, 0, 100, 1, 0, 0, 0, 0, 80, 1806901, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Death - Run Script'),
(18069, 0, 6, 0, 38, 0, 100, 0, 12, 12, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Data Set - Say Line 1'),
(18069, 0, 7, 0, 38, 0, 100, 0, 13, 13, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Data Set - Say Line 2'),
(18069, 0, 8, 0, 38, 0, 100, 0, 14, 14, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Data Set - Say Line 6'),
(18069, 0, 9, 10, 38, 0, 100, 0, 1, 1, 0, 0, 53, 0, 18069, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Data Set - Start WP'),
(18069, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Data Set - Say Line 3'),
(18069, 0, 11, 12, 40, 0, 100, 0, 4, 18069, 0, 0, 54, 100000, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mogor - At WP 4 - Pause Path'),
(18069, 0, 12, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 1806900, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mogor - At WP 4 - Run Script'),
(18069, 0, 13, 0, 21, 0, 100, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mogor - Reached Home - Set Faction Friendly'),
(18069, 0, 14, 0, 6, 0, 100, 0, 0, 0, 0, 0, 15, 9977, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Death - Give Quest Credit');

INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(1806900, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Script - Say Line 4'),
(1806900, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Script - Set Faction Aggressive'),
(1806900, 9, 2, 0, 0, 0, 100, 0, 9, 9, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Script - Set React State Aggressive');

INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(1806901, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 32343, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Script - Cast Revive Self'),
(1806901, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 70, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Script - Revive Self'),
(1806901, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Script - Say Line 5'),
(1806901, 9, 3, 0, 0, 0, 100, 0, 500, 500, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 35, 0, 0, 0, 0, 0, 0, 'Mogor - On Script - Attack Closest Player');

UPDATE quest_template SET RequiredNpcOrGo1 = '18069',RequiredNpcOrGoCount1 = '1' WHERE Id =9977;
UPDATE quest_template SET SpecialFlags = '0' WHERE Id =9977;
