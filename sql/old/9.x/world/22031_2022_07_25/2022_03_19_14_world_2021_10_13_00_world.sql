--
DELETE FROM `smart_scripts` WHERE `entryorguid`=26261 AND `source_type`=0 AND `id` IN(0,4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26261, 0, 0, 4, 8, 0, 100, 1, 47394, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - On Spellhit \'Kurun\'s Blessing\' - Store Target'),
(26261, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2626100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - On Spellhit \'Kurun\'s Blessing\' - Run Script');

UPDATE `smart_scripts` SET `target_type`=12, `target_param1`=1 WHERE `entryorguid`=2626100 AND `source_type`=9 AND `id`=0 AND `link`=0;
