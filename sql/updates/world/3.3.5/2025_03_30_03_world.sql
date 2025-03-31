-- Jocaste outro emote when "Training the Beast" (6103) is rewarded.
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4146;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4146;
DELETE FROM `smart_scripts` WHERE `entryorguid`=414600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4146,0,0,0,20,0,100,0,6103,0,0,0,0,80,414600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Jocaste - On Quest 'Training the Beast' Rewarded - Run Script"),
(414600,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Jocaste - On Script - Set Orientation Invoker"),
(414600,9,1,0,0,0,100,0,10,10,0,0,0,5,469,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Jocaste - On Script - Play Emote"),
(414600,9,2,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Jocaste - On Script - Set Orientation Home Position");
