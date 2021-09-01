-- Sniff
UPDATE `gameobject_template` SET `AIName` = 'SmartGameObjectAI', `ScriptName` = '' WHERE `entry` = 193963;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 193963 AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(193963,1,0,0,60,0,100,0,2000,2000,8000,8000,0,11,61551,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Toy Train Set - On Update - Cast 'Toy Train Set'");

-- 76092 already has condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 62943;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,62943,0,0,31,0,5,193963,0,0,0,0,"","Group 0: Spell 'Wind-Up Train Wrecker' (Effect 1) targets object 'Toy Train Set'");
