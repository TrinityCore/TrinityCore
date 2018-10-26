-- 
UPDATE `gameobject_template` SET `AIName`="", ScriptName="" WHERE `entry` IN (175944);
/*
DELETE FROM `smart_scripts` WHERE `entryorguid`=175944 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(175944,1,0,1,8,0,100,0,16996,0,0,0,12,10882,4,30000,0,0,0,8,0,0,0,-5008.338, -2118.894, 83.657, 0.874,"Sacred Fire of Life - On spell Hit - Summon Arikara"),
(175944,1,1,0,61,0,100,0,0,0,0,0,99,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sacred Fire of Life - On spell Hit - activate object");

DELETE FROM `conditions` WHERE `SourceEntry`= 16996 AND `SourceTypeOrReferenceId`=17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 16996, 0, 0, 29, 0, 10882, 100, 0, 1, 0, 0, '', '');
*/
