-- 
DELETE FROM `areatrigger_teleport` WHERE  `ID`=4354;
DELETE FROM `areatrigger_scripts` WHERE  `entry`=4354;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES 
(4354, 'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid`=4354 AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4354, 2, 0, 0, 46, 0, 100, 0, 4354, 0, 0, 0, 0, 62, 530, 0, 0, 0, 0, 0, 8, 0, 0, 0, -248.149, 921.875, 84.3885, 1.58415, 'Areatrigger - On Trigger - Teleport Player');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=4354 AND `SourceId`=2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 4354, 2, 0, 27, 0, 57, 1, 0, 0, 0, 0, '', 'SAI areatrigger 4354 triggers only if player level is higher than 57');
