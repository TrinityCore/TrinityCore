-- Seal of Ascension 4743

-- Emberstrife Template
UPDATE creature_template SET spell8=16054, AIName="SmartAI" WHERE entry=10321;

-- Emberstrife Text
DELETE FROM creature_text WHERE entry=10321;
INSERT INTO creature_text (entry, groupid, id, TEXT, TYPE, LANGUAGE, probability, emote, duration, textrange, COMMENT) VALUES
(10321, 0, 0, "Emberstrife will falters!", 41, 0, 100, 0, 2000, 50, "Emberstrife Emote when below 10%");

-- Emberstrife AI 
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 10321);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10321, 0, 0, 0, 2, 0, 100, 0, 0, 10, 60000, 60000, 1, 0, 2000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Emberstrife - Emote Below 10%'),
(10321, 0, 1, 0, 0, 0, 100, 0, 2000, 5000, 5000, 12000, 11, 9573, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Emberstrife - Flame Breath'),
(10321, 0, 2, 0, 0, 0, 100, 0, 2000, 5000, 4000, 10000, 11, 40504, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Emberstrife - Cleave'),
(10321, 0, 3, 0, 2, 0, 100, 0, 0, 10, 60000, 60000, 11, 8269, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Emberstrife - Frenzy below 10%');
