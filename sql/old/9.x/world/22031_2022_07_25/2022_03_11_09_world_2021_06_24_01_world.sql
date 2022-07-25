--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 5697 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (569700,569701) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(5697,0,0,0,38,0,100,0,1,1,0,0,0,53,0,5697,0,0,0,2,1,0,0,0,0,0,0,0,0,"Theresa - On Data Set 1 1 - Start Waypoint"),
(5697,0,1,0,38,0,100,0,1,1,0,0,0,71,0,0,2717,0,0,0,1,0,0,0,0,0,0,0,0,"Theresa - On Data Set 1 1 - Change Equipment"),
(5697,0,2,0,40,0,100,0,54,5697,0,0,0,80,569700,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Theresa - On Waypoint 54 Reached - Run Script"),
(5697,0,3,0,40,0,100,0,109,5697,0,0,0,80,569701,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Theresa - On Waypoint 109 Reached - Run Script"),

(569700,9,0,0,0,0,100,0,0,0,0,0,0,54,17000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Theresa - On Script - Pause Waypoint"),
(569700,9,1,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Theresa - On Script - Say Line 1"),
(569700,9,2,0,0,0,100,0,0,0,0,0,0,71,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Theresa - On Script - Change Equipment"),
(569700,9,3,0,0,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Theresa - On Script - Set Flag Standstate Kneel"),
(569700,9,4,0,0,0,100,0,10000,10000,0,0,0,1,0,0,0,0,0,0,19,4607,0,0,0,0,0,0,0,"Theresa - On Script - Say Line 0 (Father Lankester)"),
(569700,9,5,0,0,0,100,0,0,0,0,0,0,71,0,0,2717,0,0,0,1,0,0,0,0,0,0,0,0,"Theresa - On Script - Change Equipment"),
(569700,9,6,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Theresa - On Script - Say Line 0"),
(569700,9,7,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Theresa - On Script - Remove Flag Standstate Kneel"),

(569701,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,4.27606,"Theresa - On Script - Set Orientation 4.27606"),
(569701,9,1,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Theresa - On Script - Say Line 2"),
(569701,9,2,0,0,0,100,0,0,0,0,0,0,71,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Theresa - On Script - Change Equipment"),
(569701,9,3,0,0,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Theresa - On Script - Set Flag Standstate Kneel"),
(569701,9,4,0,0,0,100,0,5000,5000,0,0,0,1,1,0,0,0,0,0,19,5696,0,0,0,0,0,0,0,"Theresa - On Script - Say Line 1 (Gerard Abernathy)"),
(569701,9,5,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Theresa - On Script - Remove Flag Standstate Kneel");
