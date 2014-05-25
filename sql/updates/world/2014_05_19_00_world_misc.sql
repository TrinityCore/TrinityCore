--
UPDATE `smart_scripts` SET `event_phase_mask`=0 WHERE  `entryorguid`=24539 AND `source_type`=0 AND `id` IN(5,6) AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=2453900 AND `source_type`=9 AND `id`=5 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=2453901 AND `source_type`=9 AND `id`=4 AND `link`=0;
UPDATE `smart_scripts` SET `event_param3`=0, `event_param4`=0 WHERE  `entryorguid`=24539 AND `source_type`=0 AND `id`=4 AND `link`=0;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=24539;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 6, 24539, 0, 0, 38, 1, 50, 4, 0, 0, 0, 0, '', 'Silvermoon Harry - Only run SAI if silvermoon harry hp at 50% or lower'),
(22, 6, 24539, 0, 0, 9, 0, 11464, 0, 0, 0, 0, 0, '', 'Silvermoon Harry - Only run SAI if player has gambling debt taken');
