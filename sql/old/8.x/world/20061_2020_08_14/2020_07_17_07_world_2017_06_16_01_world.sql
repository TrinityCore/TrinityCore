UPDATE `smart_scripts` SET `action_type`=11, `action_param2`=0, `comment`='Wrangled Aether Ray - On Just Summoned - Cast \'Wrangle Aether Rays: Wrangling Rope Channel\' (No Repeat)' WHERE `entryorguid`=23343 AND `source_type`=0 AND `id`=0 AND `link`=1;

UPDATE `smart_scripts` SET `link`=2 WHERE `entryorguid`=23343 AND `source_type`=0 AND `id`=1 AND `link`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=23343 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23343, 0, 2, 0, 61, 0, 100, 512, 0, 0, 0, 0, 33, 23343, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Wrangled Aether Ray - On Just Summoned - Give Kill Credit (No Repeat)');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=23335;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 23335, 0, 2, 9, 0, 11065, 0, 0, 0, 0, 0, '', ''),
(22, 1, 23335, 0, 1, 9, 0, 11066, 0, 0, 0, 0, 0, '', ''),
(22, 1, 23335, 0, 0, 28, 0, 11065, 0, 0, 0, 0, 0, '', ''),
(22, 1, 23335, 0, 3, 28, 0, 11066, 0, 0, 0, 0, 0, '', ''),
(22, 1, 23335, 0, 2, 1, 0, 40926, 0, 0, 0, 0, 0, '', ''),
(22, 1, 23335, 0, 1, 1, 0, 40926, 0, 0, 0, 0, 0, '', ''),
(22, 1, 23335, 0, 0, 1, 0, 40926, 0, 0, 0, 0, 0, '', ''),
(22, 1, 23335, 0, 3, 1, 0, 40926, 0, 0, 0, 0, 0, '', '');
