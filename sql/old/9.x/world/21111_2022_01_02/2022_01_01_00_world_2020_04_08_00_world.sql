-- 
DELETE FROM  `spell_linked_spell` WHERE `spell_trigger` IN (47309, 47925, 47311, 47306);
DELETE FROM `smart_scripts` WHERE `entryorguid`=26293 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN (2629300,2629301) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(26293, 0, 0, 0, 0, 0, 100, 0, 1500, 2000, 7000, 10000, 0, 11, 50293, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Hulking Jormungar - In Combat - Cast \'Corrosive Poison\''),
(26293, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Hulking Jormungar - On Agro -Set Phase 1'),
(26293, 0, 2, 3, 2, 0, 100, 0, 0, 80, 10000, 10000, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Hulking Jormungar - On Health at or below 80% HP (Phase 1) - Say'),
(26293, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Hulking Jormungar - IC (Phase 1) - Set Phase 2'),
(26293, 0, 4, 0, 0, 2, 100, 0, 5000, 5000, 5000, 5000, 0, 22, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Hulking Jormungar - IC (Phase 2) - Set Phase 1'),
(26293, 0, 5, 0, 8, 2, 100, 1, 47305, 0, 0, 0, 0, 80, 2629300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Hulking Jormungar - On Spellhit \'Potent Explosive Charge\' (Phase 2) - Run Script (No Repeat)'),
(2629300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 22, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Hulking Jormungar - On Script - Set Phase 4'),
(2629300, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 11, 47311, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Hulking Jormungar - On Script - Cast Quest - Jormungar Explosion Summon Object'),
(2629300, 9, 2, 0, 0, 0, 100, 0, 300, 300, 0, 0, 0, 11, 47309, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Hulking Jormungar - On Script - Cast \'Quest - Jormungar Explosion Summon Object'),
(2629300, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 47309, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Hulking Jormungar - On Script - Cast \'Quest - Jormungar Explosion Summon Object'),
(2629300, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 47309, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Hulking Jormungar - On Script - Cast \'Quest - Jormungar Explosion Summon Object'),
(2629300, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 47924, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Hulking Jormungar - On Script - Cast Quest - Jormungar Explosion Summon Object'),
(2629300, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 47924, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Hulking Jormungar - On Script - Cast Quest - Jormungar Explosion Summon Object'),
(2629300, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 47924, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Hulking Jormungar - On Script - Cast Quest - Jormungar Explosion Summon Object'),
(2629300, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 47925, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Hulking Jormungar - On Script - Cast Quest - Jormungar Explosion Summon Object'),
(2629300, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 47925, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Hulking Jormungar - On Script - Cast Quest - Jormungar Explosion Summon Object'),
(2629300, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 47306, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Hulking Jormungar - On Script - Cast Potent Explosive Charge');
