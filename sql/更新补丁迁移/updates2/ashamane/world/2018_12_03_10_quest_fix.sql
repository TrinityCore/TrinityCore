-- Darkspear Cage SAI
SET @ENTRY := 201968;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,70,0,100,0,2,0,0,0,45,1,1,0,0,0,0,11,38142,20,0,0,0,0,0,"Darkspear Cage - On Gameobject State Changed - Set Data 1 1");


-- Captive Spitescale Scout SAI
SET @ENTRY := 38142;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,0,0,100,1,1000,1000,2000,2000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captive Spitescale Scout - In Combat - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,38,0,100,0,1,1,0,0,114,0,0,0,0,0,0,1,0,0,0,0,4,0,0,"Captive Spitescale Scout - On Data Set 1 1"),
(@ENTRY,0,3,0,11,0,100,0,0,0,0,0,99,1,0,0,0,0,0,13,201968,0,30,0,0,0,0,"Captive Spitescale Scout - On Respawn - Set Lootstate Ready");
