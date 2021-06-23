-- https://youtu.be/VheadnRwbLw?t=770
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3287 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 328700 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3287,0,0,0,19,0,100,0,804,0,0,0,0,80,328700,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hana'zua - On Quest 'Sarkoth' Taken - Run Script"),

(328700,9,0,0,0,0,100,0,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hana'zua - On Script - Remove Flag Standstate Dead"),
(328700,9,1,0,0,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hana'zua - On Script - Set Flag Standstate Kneel"),
(328700,9,2,0,0,0,100,0,5000,5000,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Hana'zua - On Script - Say Line 0"),
(328700,9,3,0,0,0,100,0,5000,5000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hana'zua - On Script - Remove Flag Standstate Kneel"),
(328700,9,4,0,0,0,100,0,0,0,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hana'zua - On Script - Set Flag Standstate Dead");
