-- 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(-74465,-74466,-74467,-74468) AND `source_type`=0 AND `id` IN(5,6,7);
DELETE FROM `smart_scripts` WHERE `entryorguid`=-76742 AND `source_type`=0 AND `id`>0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-74465, 0, 5, 0, 1, 0, 100, 0, 0, 0, 1000, 1000, 0, 45, 1, 1, 0, 0, 0, 0, 10, 76742, 21967, 0, 0, 0, 0, 0, 0, 'Auchenai Death-Speaker - OOC - Set Data'),
(-74465, 0, 6, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, 76742, 21967, 0, 0, 0, 0, 0, 0, 'Auchenai Death-Speaker - On Agro Set Data'),
(-74466, 0, 5, 0, 1, 0, 100, 0, 0, 0, 1000, 1000, 0, 45, 1, 1, 0, 0, 0, 0, 10, 76742, 21967, 0, 0, 0, 0, 0, 0, 'Auchenai Death-Speaker - OOC - Set Data'),
(-74466, 0, 6, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, 76742, 21967, 0, 0, 0, 0, 0, 0, 'Auchenai Death-Speaker - On Death Set Data'),
(-74467, 0, 5, 0, 1, 0, 100, 0, 0, 0, 1000, 1000, 0, 45, 1, 1, 0, 0, 0, 0, 10, 76742, 21967, 0, 0, 0, 0, 0, 0, 'Auchenai Death-Speaker - OOC - Set Data'),
(-74467, 0, 6, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, 76742, 21967, 0, 0, 0, 0, 0, 0, 'Auchenai Death-Speaker - On Death Set Data'),
(-74468, 0, 5, 0, 1, 0, 100, 0, 0, 0, 1000, 1000, 0, 45, 1, 1, 0, 0, 0, 0, 10, 76742, 21967, 0, 0, 0, 0, 0, 0, 'Auchenai Death-Speaker - OOC - Set Data'),
(-74468, 0, 6, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, 76742, 21967, 0, 0, 0, 0, 0, 0, 'Auchenai Death-Speaker - On Death Set Data'),
(-76742, 0, 1, 0, 38, 0, 100, 0, 1, 1, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Auchenai Death-Spirit - On Data Set - Phase 1'),
(-76742, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Auchenai Death-Spirit - On Data Set - Phase 2');

UPDATE `smart_scripts` SET `event_phase_mask`=1, `comment`='Auchenai Death-Spirit - Out of Combat (Phase 1) - Run Script' WHERE  `entryorguid`=-76742 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `event_phase_mask`=1 WHERE  `entryorguid`=2196700 AND `source_type`=9;
