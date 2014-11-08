
UPDATE `gameobject_template` SET `AIName`= 'SmartGameObjectAI' WHERE  `entry` =178325;
DELETE FROM `smart_scripts` WHERE `entryorguid` =178325 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(178325,1,0,0,70,0,100,0,2,0,0,0,85,21078,0,0,0,0,0,7,0,0,0,0,0,0,0,'Open To Pass Your Rite. - On State Changed - Invoker Cast Conjure Milton (DND)');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=178325;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 178325, 1, 0, 29, 1, 13082, 200, 0, 1, 0, 0, '', 'Only run SAI if Milton Beats is not already spawned');
