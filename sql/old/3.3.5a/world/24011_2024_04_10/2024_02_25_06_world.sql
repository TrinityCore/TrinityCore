-- Fix Daedal's Outro for quest "An Alternative Alternative" (9473)
-- Daedal's Waypoints
DELETE FROM `waypoints` WHERE `entry`=17215;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(17215,1,-4193.0980,-12475.6787,45.8185,"Daedal"),
(17215,2,-4195.5728,-12477.2754,45.7839,"Daedal"),
(17215,3,-4198.7573,-12476.4922,45.7583,"Daedal"),
(17215,4,-4200.5928,-12472.1885,45.6273,"Daedal"),
(17215,5,-4196.8164,-12473.2051,45.6863,"Daedal"),
(17215,6,-4193.4995,-12472.7910,45.6340,"Daedal"),
(17215,7,-4191.1499,-12470.0,45.6375,"Daedal");

-- Daedal's Script
DELETE FROM `smart_scripts` WHERE `entryorguid`=17215 AND `id` IN (4,5,6,7);
DELETE FROM `smart_scripts` WHERE `entryorguid`=17117 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1721500,1711700) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17215,0,4,5,20,0,100,0,9473,0,0,0,0,83,18,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Daedal - On Quest 'An Alternative Alternative' Rewarded - Remove Npc Flag Questgiver+Trainer"),
(17215,0,5,0,61,0,100,0,0,0,0,0,0,53,0,17215,0,0,0,0,1,0,0,0,0,0,0,0,0,"Daedal - On Link - Start WP"),
(17215,0,6,0,40,0,100,0,4,17215,0,0,0,80,1721500,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Daedal - On Waypoint 4 Reached - Run Script"),
(1721500,9,0,0,0,0,100,0,0,0,0,0,0,54,26000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Daedal - On Script - Pause Waypoint"),
(1721500,9,1,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,19,17117,0,0,0,0,0,0,0,"Daedal - On Script - Set Orientation"),
(1721500,9,2,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Daedal - On Script - Say Line 1"),
(1721500,9,3,0,0,0,100,0,0,0,0,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Daedal - On Script - Set Emote State"),
(1721500,9,4,0,0,0,100,0,4000,4000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Daedal - On Script - Set Emote State"),
(1721500,9,5,0,0,0,100,0,1000,1000,0,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Daedal - On Script - Play Emote"),
(1721500,9,6,0,0,0,100,0,3000,3000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Daedal - On Script - Say Line 2"),
(1721500,9,7,0,0,0,100,0,4000,4000,0,0,0,1,0,0,0,0,0,0,19,17117,0,0,0,0,0,0,0,"Daedal - On Script - Say Line 0 (Injured Night Elf Priestess)"),
(1721500,9,8,0,0,0,100,0,3000,3000,0,0,0,1,1,0,0,0,0,0,19,17117,0,0,0,0,0,0,0,"Daedal - On Script - Say Line 1 (Injured Night Elf Priestess)"),
(1721500,9,9,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,9,17117,0,10,0,0,0,0,0,"Daedal - On Script - Set Data 1 1 To Injured Night Elf Priestess"),
(1721500,9,10,0,0,0,100,0,2000,2000,0,0,0,1,2,0,0,0,0,0,19,17117,0,0,0,0,0,0,0,"Daedal - On Script - Say Line 2 (Injured Night Elf Priestess)"),
(1721500,9,11,0,0,0,100,0,5000,5000,0,0,0,1,3,0,0,0,0,0,19,17117,0,0,0,0,0,0,0,"Daedal - On Script - Say Line 3 (Injured Night Elf Priestess)"),
(1721500,9,12,0,0,0,100,0,6000,6000,0,0,0,1,4,0,0,0,0,0,19,17117,0,0,0,0,0,0,0,"Daedal - On Script - Say Line 4 (Injured Night Elf Priestess)"),
(1721500,9,13,0,0,0,100,0,2000,2000,0,0,0,1,2,0,0,0,0,0,19,17214,0,0,0,0,0,0,0,"Daedal - On Script - Say Line 2 (Anchorite Fateema)"),
(1721500,9,14,0,0,0,100,0,500,500,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,4.1765,"Daedal - On Script - Set Orientation"),
(1721500,9,15,0,0,0,100,0,0,0,0,0,0,82,18,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Daedal - On Script - Add Npc Flag Questgiver+Trainer"),

-- Injured Night Elf Priestess Script
(17117,0,0,1,54,0,100,0,0,0,0,0,0,91,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Night Elf Priestess - On Just Summoned - Remove Flag Standstate Sleep"),
(17117,0,1,0,61,0,100,0,0,0,0,0,0,82,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Night Elf Priestess - On Link - Add Npc Flag Gossip"),
(17117,0,2,0,64,0,100,0,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Night Elf Priestess - On Gossip Hello - Say Line 5"),
(17117,0,3,0,38,0,100,0,1,1,0,0,0,80,1711700,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Night Elf Priestess - On Data Set 1 1 - Run Script"),
(1711700,9,1,0,0,0,100,0,0,0,0,0,0,91,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Night Elf Priestess - On Script - Set Stand State"),
(1711700,9,2,0,0,0,100,0,400,400,0,0,0,90,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Night Elf Priestess - On Script - Set Stand State"),
(1711700,9,3,0,0,0,100,0,10000,10000,0,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Night Elf Priestess - On Script - Play Emote"),
(1711700,9,4,0,0,0,100,0,3000,3000,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Night Elf Priestess - On Script - Set Stand State"),
(1711700,9,5,0,0,0,100,0,400,400,0,0,0,90,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Injured Night Elf Priestess - On Script - Set Stand State");
