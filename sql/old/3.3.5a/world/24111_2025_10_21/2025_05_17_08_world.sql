-- More Blizzlike fixes for quest "Therylune's Escape" (945)

-- Therylune's script
DELETE FROM `smart_scripts` WHERE `entryorguid`=3584 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (358400,358401) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3584,0,0,0,11,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Therylune - On Spawn - Say Line 2"),
(3584,0,1,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Therylune - Between 0-15% Health - Flee For Assist"),
(3584,0,2,0,19,0,100,0,945,0,0,0,0,80,358400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Therylune - On Quest Accept - Run Script"),
(3584,0,3,0,40,0,100,0,12,3584,0,0,0,80,358401,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Therylune - On WP 12 Reached - Run Script"),
(3584,0,4,0,40,0,100,0,16,3584,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Therylune - On WP 16 - Say Line 3"),
(3584,0,5,0,40,0,100,0,16,3584,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Therylune - On WP 16 - Forced Despawn"),
(3584,0,6,0,6,0,100,0,0,0,0,0,0,6,945,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Therylune - On Death - Fail quest"),

-- Timed List 1
(358400,9,1,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Therylune - On Script - Remove Npc Flag Questgiver"),
(358400,9,2,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Therylune - On Script - Store Target"),
(358400,9,3,0,0,0,100,0,0,0,0,0,0,145,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Therylune - On Script - Remove Flag Immune to NPC"),
(358400,9,4,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Therylune - On Scrip - Say Line 0"),
(358400,9,5,0,0,0,100,0,0,0,0,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Therylune - On Scrip - Set Faction 250"),
(358400,9,6,0,0,0,100,0,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Therylune - On Scrip - Set React State 1"),
(358400,9,7,0,0,0,100,0,0,0,0,0,0,53,0,3584,0,0,0,0,1,0,0,0,0,0,0,0,0,"Therylune - On Scrip - Start WP"),

-- Timed List 2
(358401,9,0,0,0,0,100,0,0,0,0,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Therylune - On Script - Pause Waypoint"),
(358401,9,1,0,0,0,100,0,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Therylune - On Script - Set Run On"),
(358401,9,2,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Therylune - On Script - Set Orientation Invoker"),
(358401,9,3,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Therylune - On Script - Say Line 1"),
(358401,9,4,0,0,0,100,0,0,0,0,0,0,15,945,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Therylune - On Script - Quest Credit");

-- Therylune's creature text
DELETE FROM `creature_text` WHERE `CreatureID`=3584 AND `GroupID` IN (2,3);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3584,2,0,"%s hides among the bushes.",16,7,100,0,0,0,1186,0,"Therylune"),
(3584,3,0,"%s disappears into the woods.",16,7,100,0,0,0,1190,0,"Therylune");

-- Therylune's waypoints
DELETE FROM `waypoints` WHERE `entry`=3584;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(3584,1,4504.28,389.60,31.9814,"Therylune"),
(3584,2,4512.16,374.68,33.2877,"Therylune"),
(3584,3,4532.26,369.353,31.5946,"Therylune"),
(3584,4,4575.78,372.10,31.4839,"Therylune"),
(3584,5,4599.76,365.036,31.5225,"Therylune"),
(3584,6,4598.63,350.758,33.6244,"Therylune"),
(3584,7,4573.25,343.515,42.1702,"Therylune"),
(3584,8,4557.85,341.514,47.2117,"Therylune"),
(3584,9,4555.56,335.148,48.7235,"Therylune"),
(3584,10,4563.15,312.387,53.6122,"Therylune"),
(3584,11,4557.81,305.154,57.5486,"Therylune"),
(3584,12,4528.66,287.463,56.2182,"Therylune"),
(3584,13,4479.74,265.108,59.2870,"Therylune"),
(3584,14,4397.44,249.499,58.3769,"Therylune"),
(3584,15,4347.50,260.826,54.2498,"Therylune"),
(3584,16,4328.62,250.360,58.0594,"Therylune");
