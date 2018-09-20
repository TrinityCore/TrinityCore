-- Netherologist Coppernickels -- http://wotlk.openwow.com/npc=19569
DELETE FROM `creature_template_addon` WHERE  `entry`=19569;

-- Netherologist Coppernickels SAI
SET @ENTRY := 19569;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,54,180000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Gossip Hello - Pause Waypoint"),
(@ENTRY,0,1,0,25,0,100,0,0,0,0,0,53,0,19569,1,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Reset - Start Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,1,19569,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Waypoint 1 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,7,19569,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Waypoint 7 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,0,11,19569,0,0,80,@ENTRY*100+02,2,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Waypoint 11 Reached - Run Script"),
(@ENTRY,0,5,0,40,0,100,0,14,19569,0,0,80,@ENTRY*100+03,2,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Waypoint 14 Reached - Run Script"),
(@ENTRY,0,6,0,40,0,100,0,22,19569,0,0,80,@ENTRY*100+04,2,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Waypoint 22 Reached - Run Script");

-- Actionlist SAI
SET @ENTRY := 1956900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.74424,"Netherologist Coppernickels - On Script - Set Orientation 0.74424"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,54,45000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Script - Pause Waypoint"),
(@ENTRY,9,2,0,0,0,100,0,20000,20000,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Script - Set Emote State 133"),
(@ENTRY,9,3,0,0,0,100,0,19000,19000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Script - Set Emote State 0"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,1,0,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Script - Say Line 0");

-- Actionlist SAI
SET @ENTRY := 1956901;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.159118,"Netherologist Coppernickels - On Script - Set Orientation 0.159118"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,54,45000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Script - Pause Waypoint"),
(@ENTRY,9,2,0,0,0,100,0,20000,20000,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Script - Set Emote State 133"),
(@ENTRY,9,3,0,0,0,100,0,19000,19000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Script - Set Emote State 0"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,1,1,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Script - Say Line 1");

-- Actionlist SAI
SET @ENTRY := 1956902;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.81776,"Netherologist Coppernickels - On Script - Set Orientation 3.81776"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,54,45000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Script - Pause Waypoint"),
(@ENTRY,9,2,0,0,0,100,0,20000,20000,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Script - Set Emote State 133"),
(@ENTRY,9,3,0,0,0,100,0,19000,19000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Script - Set Emote State 0"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,1,2,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Script - Say Line 2");

-- Actionlist SAI
SET @ENTRY := 1956903;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.200999,"Netherologist Coppernickels - On Script - Set Orientation 0.200999"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,54,45000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Script - Pause Waypoint"),
(@ENTRY,9,2,0,0,0,100,0,20000,20000,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Script - Set Emote State 133"),
(@ENTRY,9,3,0,0,0,100,0,19000,19000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Script - Set Emote State 0"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,1,2,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Script - Say Line 2");

-- Actionlist SAI
SET @ENTRY := 1956904;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.118525,"Netherologist Coppernickels - On Script - Set Orientation 0.118525"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,54,45000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Script - Pause Waypoint"),
(@ENTRY,9,2,0,0,0,100,0,20000,20000,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Script - Set Emote State 133"),
(@ENTRY,9,3,0,0,0,100,0,19000,19000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Script - Set Emote State 0"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,1,3,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Netherologist Coppernickels - On Script - Say Line 3");

DELETE FROM `creature_text` WHERE `entry`=19569;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(19569, 0, 0, 'I hope those blood elves across the way don''t think that I''m spying on them!', 12, 0, 100, 5, 0, 0, 16952, 'Netherologist Coppernickels'),
(19569, 1, 0, 'If I were smart, I''d be selling this research for a seat on the rocket ship.  I have a feeling we''re going to need to get out of here soon!', 12, 0, 100, 5, 0, 0, 16955, 'Netherologist Coppernickels'),
(19569, 2, 0, 'If this is right, we don''t have long! Oh well.', 12, 0, 100, 5, 0, 0, 16953, 'Netherologist Coppernickels'),
(19569, 3, 0, 'This is the last time that I buy second-hand equipment from an ethereal!', 12, 0, 100, 5, 0, 0, 16951, 'Netherologist Coppernickels');

DELETE FROM `waypoints` WHERE `entry`=19569;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(19569, 1, 3389.06, 4296.1, 120.848,   'Netherologist Coppernickels'),
(19569, 2, 3381.91, 4300.33, 120.185,  'Netherologist Coppernickels'),
(19569, 3, 3379.54, 4317.5, 121.136,   'Netherologist Coppernickels'),
(19569, 4, 3379.26, 4319.73, 122.64,   'Netherologist Coppernickels'),
(19569, 5, 3378.79, 4328.07, 122.64,   'Netherologist Coppernickels'),
(19569, 6, 3380.94, 4335.49, 122.64,   'Netherologist Coppernickels'),
(19569, 7, 3386.13, 4336.3, 122.64,    'Netherologist Coppernickels'),
(19569, 8, 3374.05, 4341.09, 122.684,  'Netherologist Coppernickels'),
(19569, 9, 3371.34, 4343.16, 122.712,  'Netherologist Coppernickels'),
(19569, 10, 3367.23, 4343.4, 122.719,  'Netherologist Coppernickels'),
(19569, 11, 3363.59, 4340.95, 122.697, 'Netherologist Coppernickels'),
(19569, 12, 3367.61, 4344.06, 122.727, 'Netherologist Coppernickels'),
(19569, 13, 3374.61, 4356.84, 123.634, 'Netherologist Coppernickels'),
(19569, 14, 3379.82, 4357.93, 123.631, 'Netherologist Coppernickels'),
(19569, 15, 3375.75, 4344.93, 122.725, 'Netherologist Coppernickels'),
(19569, 16, 3377.95, 4319.35, 122.641, 'Netherologist Coppernickels'),
(19569, 17, 3378.48, 4315.87, 121.045, 'Netherologist Coppernickels'),
(19569, 18, 3382.31, 4281.61, 121.106, 'Netherologist Coppernickels'),
(19569, 19, 3382.72, 4279, 122.64,     'Netherologist Coppernickels'),
(19569, 20, 3383.64, 4271.15, 122.64,  'Netherologist Coppernickels'),
(19569, 21, 3388.75, 4267.11, 122.64,  'Netherologist Coppernickels'),
(19569, 22, 3392.29, 4267.63, 122.64,  'Netherologist Coppernickels'),
(19569, 23, 3382.1, 4279.11, 122.64,   'Netherologist Coppernickels'),
(19569, 24, 3381.78, 4281.36, 121.115, 'Netherologist Coppernickels'),
(19569, 25, 3381.14, 4290.22, 120.607, 'Netherologist Coppernickels'),
(19569, 26, 3383.74, 4292.46, 120.963, 'Netherologist Coppernickels'),
(19569, 27, 3389.09, 4296.38, 120.831, 'Netherologist Coppernickels');
