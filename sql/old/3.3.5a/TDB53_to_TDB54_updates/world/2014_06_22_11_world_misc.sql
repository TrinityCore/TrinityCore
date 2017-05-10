--
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`=190695;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=19069500;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(190695, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Heb\'Jin\'s Drum - On state changed - Store targetlist'),
(190695, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 19069500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Heb\'Jin\'s Drum - Linked with Previous Event - Run Script'),
(19069500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 98562, 23837, 0, 0, 0,0,0, 'Heb\'Jin\'s Drum - Script - Set Data ELM General Purpose Bunny'),
(19069500, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 28636, 100, 0, 0, 0, 0, 0, 'Heb\'Jin\'s Drum - Script - Send Target list to heb jin');

UPDATE `smart_scripts` SET `action_param2`=2, `action_param3`=300000 WHERE  `entryorguid`=2863600 AND `source_type`=9 AND `id`=3 AND `link`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=28636 AND `id`=9;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=28639 AND `id`=10;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28636, 0, 9, 0, 7, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Heb Jin - On Evade - Despawn'),
(28639, 0, 10, 0, 7, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Heb Jins Bat - On Evade - Despawn');

DELETE FROM  `event_scripts` WHERE `id`=18773;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=-98562;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-98562, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 45, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny - On Data Set - Set Data'),
(-98562, 0, 1, 0, 61, 0, 100, 0, 1, 1, 0, 0, 12, 28636, 2, 300000, 0, 0, 0, 8, 0, 0, 0, 5988.71, -3878.04, 417.15, 2.35619, 'ELM General Purpose Bunny - Linked with Previous Event - Spawn Heb Jin');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 and `SourceId`=0 and `SourceEntry`=-98562;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, -98562, 0, 0, 29, 1, 28636, 200, 0, 1, 0, 0, '', 'Only run SAI if no heb jin nearby'),
(22, 1, -98562, 0, 0, 29, 1, 28639, 200, 0, 1, 0, 0, '', 'Only run SAI if no heb jins bat nearby');
