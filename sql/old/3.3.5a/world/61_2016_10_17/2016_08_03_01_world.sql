DELETE FROM `areatrigger_involvedrelation` WHERE  `id`=4950;

DELETE FROM `smart_scripts` WHERE `entryorguid`=4950 AND `source_type`=2 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4950, 2, 1, 0, 46, 0, 100, 0, 4950, 0, 0, 0, 15, 12036, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On Trigger - Complete quest');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=4950 AND `SourceId`=2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 2, 4950, 2, 0, 9, 0, 12036, 0, 0, 0, 0, 0, '', 'Trigger - requires From the Depths of Azjol-Nerub');
