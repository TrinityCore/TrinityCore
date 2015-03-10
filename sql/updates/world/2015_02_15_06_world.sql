--
DELETE FROM `areatrigger_scripts` WHERE `entry` = 4479;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(4479, 'SmartTrigger');
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4479 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4479, 2, 0, 0, 46, 0, 100, 0, 4479, 0, 0, 0, 85, 33728, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Areatrigger - On Trigger - Cast Teleport Shattrath');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 4479 AND `SourceId` = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 4479, 2, 0, 28, 0, 10280, 0, 0, 0, 0, '', 'Teleport only on Quest "Special Delivery to Shattrath City"');
