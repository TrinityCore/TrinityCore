DELETE FROM `smart_scripts` WHERE `entryorguid`=27409 AND `source_type`=0 AND `id`>7;
DELETE FROM `smart_scripts` WHERE `entryorguid`=27417 AND `source_type`=0 AND `id`=2;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(27409, 0, 8, 0, 27, 0, 100, 512, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ducal\'s Horse - On Passenger Boarded - Set Phase 2'),
(27409, 0, 9, 0, 28, 0, 100, 512, 0, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ducal\'s Horse - On Passenger Removed - Despawn'),
(27409, 0, 10, 0, 27, 2, 100, 512, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ducal\'s Horse - On Passenger Boarded (Phase 2) - Store Targetlist'),
(27409, 0, 11, 12, 1, 0, 100, 512, 300000, 300000, 300000, 300000, 41, 0, 0, 0, 0, 0, 0, 19, 27411, 0, 0, 0, 0, 0, 0, 'Ducal\'s Horse - OOC - Despawn'),
(27409, 0, 12, 0, 61, 0, 100, 512, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ducal\'s Horse - OOC - Despawn'),

(27417, 0, 2, 0, 1, 0, 100, 0, 5000, 5000, 5000, 5000, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Silverbrook Worgen - OOC - Despawn');

UPDATE `smart_scripts` SET `event_phase_mask`=2, `comment`='Ducal\'s Horse - On Passenger Boarded (Phase 2) - Run Script' WHERE  `entryorguid`=27409 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `action_type`=85, `action_param3`=1, `target_type`=12, `target_param1`=1 WHERE  `entryorguid`=27409 AND `source_type`=0 AND `id`=5 AND `link`=6;
UPDATE `smart_scripts` SET `event_param1`=0, `event_param2`=0, `event_param3`=0, `event_param4`=0 WHERE  `entryorguid`=2740900 AND `source_type`=9 AND `id`=0 AND `link`=0;
