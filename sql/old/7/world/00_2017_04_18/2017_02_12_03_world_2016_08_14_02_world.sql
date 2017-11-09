UPDATE `conditions` SET `ConditionValue1`=12, `ConditionValue3`=0 WHERE  `SourceTypeOrReferenceId`=22 AND `Comment`='Execute SAI only if Arthas Started';
UPDATE`conditions` SET `ConditionValue1`=1 WHERE  `SourceTypeOrReferenceId`=22 AND `Comment`='Execute SAI only if Salramm not done';

UPDATE`creature_template` SET `unit_flags`=256 WHERE  `entry`=32292;

DELETE FROM `smart_scripts` WHERE `entryorguid`=32236 AND `source_type`=0 AND `id`=10;
DELETE FROM `smart_scripts` WHERE `entryorguid`=32236 AND `source_type`=0 AND `id`>14;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32236, 0, 10, 15, 61, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - Link - Set Active'),
(32236, 0, 15, 16, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - Link - Set Passive'),
(32236, 0, 16, 17, 61, 0, 100, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - Link - Disable Auto Attack'),
(32236, 0, 17, 0, 61, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - Link - Disable Combat Movement');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=25758;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 25758, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Defendo-tank 66D - Only run SAI if invoker is player');
