-- Mebok Mizzyrix, NPC entry 3446
SET @ENTRY := 3446;

DELETE FROM `creature_text` WHERE `entry`= @ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ENTRY,0,0,"Now let's try it...",   12,0,100, 7,0,0,2078,0,'Mebok Mizzyrix on Quest 865 rewarded'),
(@ENTRY,1,0,"Ugh!  That's terrible!",12,0,100,33,0,0,2079,0,'Mebok Mizzyrix on Quest 865 rewarded');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry`= @ENTRY;

DELETE FROM `smart_scripts` WHERE `source_type`= 0 AND `entryorguid`= @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,20,0,100,0,865,0,0,0,1,0,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Mebok Mizzyrix - on Quest 865 Rewarded - Say Line 0'),
(@ENTRY,0,1,0,61,0,100,0,  0,0,0,0,1,1,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Mebok Mizzyrix - on Quest 865 Rewarded - Say Line 1');
