-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22  AND `SourceEntry`=24314 AND `SourceId`=0;

DELETE FROM `areatrigger_scripts` WHERE `entry`=4778;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES 
(4778, 'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid`=4778 AND `source_type`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2431501 AND `source_type`=9 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4778, 2, 0, 0, 46, 0, 100, 0, 4778, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 48229, 24314, 0, 0, 0, 0, 0, 0, 'Areatrigger - On Trigger - Set Data 1 1'),
(2431501, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 3.036870, 'Ancient Female Vrykul - Action list - set orientation');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=4778 AND `SourceId`=2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 4778, 2, 0, 9, 0, 11343, 0, 0, 0, 0, 0, '', 'SAI areatrigger 4778 triggers only if player has taken Quest 11343'),
(22, 1, 4778, 2, 0, 1, 0, 42786, 0, 0, 0, 0, 0, '', 'SAI areatrigger 4778 triggers only if player has aura 42786');

UPDATE `smart_scripts` SET `event_type`=38, `event_param1`=1, `event_param2`=1, `event_param5`=0, `comment`='Ancient Male Vrykul - On Data Set  - Start Script' WHERE  `entryorguid`=24314 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `target_type`=1 WHERE  `entryorguid`=2431400 AND `source_type`=9 AND `id`=10 AND `link`=0;

DELETE FROM `areatrigger_scripts` WHERE `entry`=4779;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES 
(4779, 'SmartTrigger');

UPDATE `smart_scripts` SET `event_type`=38, `event_param1`=1, `event_param2`=1,`event_param3`=60000, `event_param4`=60000, `comment`='King Ymiron - On Data Set  - Run Script' WHERE  `entryorguid`=24321 AND `source_type`=0 AND `id`=0 AND `link`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=4779 AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4779, 2, 0, 0, 46, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 151840, 24321, 0, 0, 0, 0, 0, 0, 'Areatrigger - On Trigger - Set Data 1 1');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=4779 AND `SourceId`=2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 4779, 2, 0, 9, 0, 11344, 0, 0, 0, 0, 0, '', 'SAI areatrigger 4779 triggers only if player has taken Quest 11344'),
(22, 1, 4779, 2, 0, 1, 0, 43466, 0, 0, 0, 0, 0, '', 'SAI areatrigger 4779 triggers only if player has aura 43466');
