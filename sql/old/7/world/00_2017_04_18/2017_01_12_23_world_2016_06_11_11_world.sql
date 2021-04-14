-- 
-- Mebok Mizzyrix SAI

SET @ENTRY := 3446;
DELETE FROM `creature_text` WHERE `entry`= @ENTRY AND `GroupId`=2;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ENTRY,2,0,"Hey $n!  Don't forget to grab a crate, a manual and a command stick!", 12,0,100,0,0,0,1788,0,'Mebok Mizzyrix on Quest 1221 taken');

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,865,0,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mebok Mizzyrix - On Quest 'Raptor Horns' Finished - Run Script"),
(@ENTRY,0,1,0,19,0,100,0,1221,0,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mebok Mizzyrix - On Quest 'Blueleaf Tubers' Taken - Run Script");

-- Actionlist SAI
SET @ENTRY := 344600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mebok Mizzyrix - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,11,17550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mebok Mizzyrix - On Script - Cast 'Purification'"),
(@ENTRY,9,2,0,0,0,100,0,4000,4000,0,0,5,34,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mebok Mizzyrix - On Script - Play Emote 34"),
(@ENTRY,9,3,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mebok Mizzyrix - On Script - Say Line 1");

-- Actionlist SAI
SET @ENTRY := 344601;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mebok Mizzyrix - On Script - Say Line 2"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,-929.023,-3696.98,7.97395,1.7352,"Mebok Mizzyrix - On Script - Move To Position"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mebok Mizzyrix - On Script - Play Emote 25"),
(@ENTRY,9,3,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,-928.778,-3697.25,7.99705,6.17741,"Mebok Mizzyrix - On Script - Move To Position"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,-928.982,-3697.23,8.06642,3.08923,"Mebok Mizzyrix - On Script - Move To Position");
