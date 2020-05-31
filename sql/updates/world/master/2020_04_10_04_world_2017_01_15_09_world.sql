-- Mordenai -- http://wotlk.openwow.com/npc=22113
-- Mordenai SAI
SET @ENTRY := 22113;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,22113,1,0,0,2,1,0,0,0,0,0,0,0,"Mordenai - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,54,180000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mordenai - On Gossip Hello - Pause Waypoint"),
(@ENTRY,0,2,3,40,0,100,0,1,22113,0,0,54,12000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mordenai - On Waypoint 1 Reached - Pause Waypoint"),
(@ENTRY,0,3,0,61,0,100,0,1,22113,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.59702,"Mordenai - On Waypoint 1 Reached - Set Orientation 4.59702"),
(@ENTRY,0,4,0,40,0,100,0,2,22113,0,0,49,0,0,0,0,0,0,19,21478,80,0,0,0,0,0,"Mordenai - On Waypoint 2 Reached - Start Attacking"),
(@ENTRY,0,5,0,40,0,100,0,12,22113,0,0,49,0,0,0,0,0,0,19,21478,80,0,0,0,0,0,"Mordenai - On Waypoint 12 Reached - Start Attacking"),
(@ENTRY,0,6,0,0,0,100,0,0,0,2300,3900,11,41440,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mordenai - In Combat - Cast 'Shoot'"),
(@ENTRY,0,7,0,0,0,100,0,6000,9000,27000,28000,11,41448,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mordenai - In Combat - Cast 'Multi-Shot'"),
(@ENTRY,0,8,0,0,0,100,0,5000,5000,18000,18000,11,38370,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mordenai - In Combat - Cast 'Aimed Shot'");

DELETE FROM `waypoints` WHERE `entry`=22113;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(22113, 1, -4100.05, 969.276,  24.9571, 'Mordenai'),
(22113, 2, -4104.06, 931.187,  18.8469, 'Mordenai'),
(22113, 3, -4105.65, 911.224,  16.1353, 'Mordenai'),
(22113, 4, -4106.05, 889.833,  14.4649, 'Mordenai'),
(22113, 5, -4118.47, 857.928,  8.29486, 'Mordenai'),
(22113, 6, -4122.4, 839.518,   10.4151, 'Mordenai'),
(22113, 7, -4143.45, 803.2,    9.22043, 'Mordenai'),
(22113, 8, -4150.96, 769.769,  6.31908, 'Mordenai'),
(22113, 9, -4153.1, 760.191,   3.47747, 'Mordenai'),
(22113, 10, -4155.08, 747.368, 1.8985,  'Mordenai'),
(22113, 11, -4151.37, 769.929, 6.42453, 'Mordenai'),
(22113, 12, -4132.84, 797.355, 8.16607, 'Mordenai'),
(22113, 13, -4137.32, 823.672, 9.68296, 'Mordenai'),
(22113, 14, -4119.16, 842.164, 9.89524, 'Mordenai'),
(22113, 15, -4115.26, 851.276, 7.68533, 'Mordenai'),
(22113, 16, -4109.66, 883.088, 13.8876, 'Mordenai'),
(22113, 17, -4110.74, 914.769, 17.723,  'Mordenai'),
(22113, 18, -4106.89, 948.026, 23.0078, 'Mordenai');
