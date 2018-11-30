-- 
-- Technician Dyvuun SAI -- http://www.wowhead.com/npc=16551
SET @ENTRY := 16551;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,16551,1,0,0,0,1,0,0,0,0,0,0,0,"Technician Dyvuun - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Technician Dyvuun - On Gossip Hello - Pause Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,1,16551,0,0,54,20000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Technician Dyvuun - On Waypoint 1 Reached - Pause Waypoint"),
(@ENTRY,0,3,0,40,0,100,0,2,16551,0,0,54,46000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Technician Dyvuun - On Waypoint 2 Reached - Pause Waypoint"),
(@ENTRY,0,4,0,40,0,100,0,3,16551,0,0,54,90000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Technician Dyvuun - On Waypoint 3 Reached - Pause Waypoint"),
(@ENTRY,0,5,6,40,0,100,0,4,16551,0,0,54,65000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Technician Dyvuun - On Waypoint 4 Reached - Pause Waypoint"),
(@ENTRY,0,6,0,61,0,100,0,4,16551,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Technician Dyvuun - On Waypoint 4 Reached - Run Script"),
(@ENTRY,0,7,0,40,0,100,0,5,16551,0,0,54,100000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Technician Dyvuun - On Waypoint 5 Reached - Pause Waypoint");

DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(@ENTRY, 1, -4158.32, -12483.1, 45.4554, 'Technician Dyvuun'),
(@ENTRY, 2, -4157.08, -12480.4, 45.2039, 'Technician Dyvuun'),
(@ENTRY, 3, -4158.32, -12483.1, 45.4554, 'Technician Dyvuun'),
(@ENTRY, 4, -4157.08, -12480.4, 45.2039, 'Technician Dyvuun'),
(@ENTRY, 5, -4158.32, -12483.1, 45.4554, 'Technician Dyvuun');

-- Actionlist SAI
SET @ENTRY := 1655100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,3000,3000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 69"),
(@ENTRY,9,1,0,0,0,100,0,7000,7000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 0"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,9,0,0,0,0,0,0,20,181805,100,0,0,0,0,0,"On Script - Activate Gameobject"),
(@ENTRY,9,3,0,0,0,100,0,2000,2000,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 4"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,12,17268,3,27000,0,0,0,8,0,0,0,-4156.35,-12477.5,46.1839,3.12414,"On Script - Summon Creature 'Image of Technician Zhanaa'"),
(@ENTRY,9,5,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,19,17268,100,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,6,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,7,0,0,0,100,0,9000,9000,0,0,1,1,0,0,0,0,0,19,17268,100,0,0,0,0,0,"On Script - Say Line 1"),
(@ENTRY,9,8,0,0,0,100,0,9000,9000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 1"),
(@ENTRY,9,9,0,0,0,100,0,6000,6000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 69"),
(@ENTRY,9,10,0,0,0,100,0,15000,15000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 0");

-- must be summned by script
DELETE FROM `creature` WHERE guid = 62014;

DELETE FROM `creature_text` WHERE `entry`=16551;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(16551, 0, 0, 'Yes, Zhanna, it''s me! Your signal is weak.', 12, 0, 100, 0, 0, 0, 13687, 'Technician Dyvuun'),
(16551, 1, 0, 'Zhanna! Gah, I have to get this thing fixed!', 12, 0, 100, 0, 0, 0, 13692, 'Technician Dyvuun');

DELETE FROM `creature_text` WHERE `entry`=17268;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(17268, 0, 0, 'Dyvuun, is that you?', 12, 0, 100, 0, 0, 0, 13686, 'Image of Technician Zhanaa'),
(17268, 1, 0, 'I can barely hear you... <static> aking up!', 12, 0, 100, 0, 0, 0, 13688, 'Image of Technician Zhanaa');
