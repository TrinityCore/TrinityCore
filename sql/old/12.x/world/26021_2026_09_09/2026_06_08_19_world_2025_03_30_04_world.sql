UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4088;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4088;
DELETE FROM `smart_scripts` WHERE `entryorguid`=408800 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4088,0,0,1,20,0,100,0,1683,0,0,0,0,80,408800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Elanaria - On Quest 'Vorlus Vilehoof' Rewarded - Run Script"),
(4088,0,1,0,61,0,100,0,0,0,0,0,0,5,66,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Elanaria - On Link - Play Emote (Player)"),
(408800,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Elanaria - On Script - Set Orientation Invoker"),
(408800,9,1,0,0,0,100,0,0,0,0,0,0,5,469,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Elanaria - On Script - Play Emote"),
(408800,9,2,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Elanaria - On Script - Set Orientation Home Position");
