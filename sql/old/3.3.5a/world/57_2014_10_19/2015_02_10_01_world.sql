--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND  `SourceGroup`=1 AND `SourceEntry`=45465;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 45465, 0, 0, 31, 0, 3, 24862, 0, 0, 0, 0, '', 'Mage Hunter Channel - targets Bunny');

-- Beryl Treasure Hunter SAI
SET @ENTRY := 25353;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,1000,12500,15500,11,50658,0,0,0,0,0,2,0,0,0,0,0,0,0,"Beryl Treasure Hunter - In Combat - Cast 'Focus Beam'"),
(@ENTRY,0,1,0,1,0,100,0,5000,5000,15000,15000,11,45465,0,0,0,0,0,19,24862,60,0,0,0,0,0,"Beryl Treasure Hunter - Out of Combat - Cast 'Mage Hunter Channel'");
