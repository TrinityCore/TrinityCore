-- Nekthar -- http://wotlk.openwow.com/npc=18248
-- Nekthar SAI
SET @ENTRY := 18248;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,18248,1,0,0,0,1,0,0,0,0,0,0,0,"Nekthar - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,1,18248,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Nekthar - On Waypoint 1 Reached - Say Line 0"),
(@ENTRY,0,2,0,40,0,100,0,4,18248,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Nekthar - On Waypoint 4 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,8,18248,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Nekthar - On Waypoint 8 Reached - Run Script"),
(@ENTRY,0,4,0,64,0,100,0,0,0,0,0,54,180000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nekthar - On Gossip Hello - Pause Waypoint");

-- Actionlist SAI
SET @ENTRY := 1824800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,240000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nekthar - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.63,"Nekthar - On Script - Set Orientation 5.63"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,90,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nekthar - On Script - Set Flag Standstate Sit Down"),
(@ENTRY,9,3,0,0,0,100,0,235000,235000,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nekthar - On Script - Remove Flag Standstate Sit Down");

-- Actionlist SAI
SET @ENTRY := 1824801;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,240000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nekthar - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.88,"Nekthar - On Script - Set Orientation 3,88"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Nekthar - On Script - Say Line 1");

DELETE FROM `creature_text` WHERE `entry`=18248;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(18248, 0, 0, 'Grunting, %s turns away from the wanted poster, returning to his warm spot by the fire.', 16, 0, 100, 0, 0, 0, 18782, 'Nekthar'),
(18248, 1, 0, '%s begins to read the wanted poster.', 16, 0, 100, 0, 0, 0, 18781, 'Nekthar');

SET @PATH := 18248;
DELETE FROM `waypoints` WHERE `entry`=@PATH;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(@PATH, 1, 2317.72, 6030.27, 142.57, 'Nekthar'),
(@PATH, 2, 2307.82, 6024.44, 142.56, 'Nekthar'),
(@PATH, 3, 2304.89, 6025.77, 142.96, 'Nekthar'),
(@PATH, 4, 2304.89, 6025.77, 142.96, 'Nekthar'), 
(@PATH, 5, 2306.93, 6023.86, 142.56, 'Nekthar'), 
(@PATH, 6, 2317.38, 6030, 142.57, 'Nekthar'),
(@PATH, 7, 2319.51, 6029.16, 142.62, 'Nekthar'),
(@PATH, 8, 2319.51, 6029.16, 142.62, 'Nekthar');
