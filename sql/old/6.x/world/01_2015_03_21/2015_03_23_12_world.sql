-- 
UPDATE `smart_scripts` SET `action_param2`=6, `action_param3`=60000 WHERE  `entryorguid`=23310 AND `source_type`=0 AND `id`=2 AND `link`=3;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=23310;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 3, 23310, 0, 0, 29, 1, 25003, 200, 0, 1, 0, 0, '', 'Only run SAI if no Emissary of Hate nearby');

-- Irespeaker SAI
SET @ENTRY := 24999;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1500,3000,10000,15000,11,35913,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irespeaker - In Combat - Cast 'Fel Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,13000,16000,20000,35000,11,18267,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irespeaker - In Combat - Cast 'Curse of Weakness'"),
(@ENTRY,0,2,0,6,0,100,0,5000,5000,10000,10000,45,1,1,0,0,0,0,10,79450,23310,0,0,0,0,0,"Irespeaker - On Just Died - Set Data 1 1"),
(@ENTRY,0,3,0,25,0,100,0,0,0,0,0,11,45023,0,0,0,0,0,19,25953,13,0,0,0,0,0,"Irespeaker - On Reset - Cast 'Fel Consumption'");

DELETE FROM `smart_scripts` WHERE  `entryorguid`=25002 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `id`=0 WHERE  `entryorguid`=25002 AND `source_type`=0 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `id`=1 WHERE  `entryorguid`=25002 AND `source_type`=0 AND `id`=2 AND `link`=0;
UPDATE `smart_scripts` SET `id`=2 WHERE  `entryorguid`=25002 AND `source_type`=0 AND `id`=3 AND `link`=0;
