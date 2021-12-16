--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3230 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 323000 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3230,0,0,0,20,0,100,0,11003,0,0,0,0,80,323000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nazgrel - On Quest 'The Fall of Magtheridon' Finished - Run Script"),

(323000,9,0,0,0,0,100,0,0,0,0,0,0,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nazgrel - On Script - Play Emote 15"),
(323000,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Nazgrel - On Script - Say Line 0"),
(323000,9,2,0,0,0,100,0,7000,7000,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Nazgrel - On Script - Say Line 1");
