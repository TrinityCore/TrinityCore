-- 
-- Zlagk SAI
SET @ENTRY := 3882;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,21000,21000,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Zlagk - Out of Combat - Run Script");

-- Actionlist SAI
SET @ENTRY := 388200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.577578,"On Script - Set Orientation 0.577578"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,17,234,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 234"),
(@ENTRY,9,2,0,0,0,100,0,9000,9000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.302916,"On Script - Set Orientation 3,302916"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 69");
