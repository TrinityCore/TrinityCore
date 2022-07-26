--
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 20227;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 20227 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = -84989 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 16514 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1651400 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16514,0,0,0,20,0,100,0,9294,0,0,0,0,80,1651400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Botanist Taerix - On Quest 'Healing the Lake' Finished - Run Script"), -- 05:47:42.076

(1651400,9,0,0,0,0,100,0,1000,1000,0,0,0,83,1,0,0,0,0,0,19,20227,0,0,0,0,0,0,0,"Botanist Taerix - On Script - Remove NPC Flag Gossip (Apprentice Tedon)"), -- 05:47:43.277
(1651400,9,1,0,0,0,100,0,2500,2500,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Botanist Taerix - On Script - Say Line 0"), -- 05:47:45.773
(1651400,9,2,0,0,0,100,0,1500,1500,0,0,0,1,0,0,0,0,0,0,19,20227,0,0,0,0,0,0,0,"Botanist Taerix - On Script - Say Line 0 (Apprentice Tedon)"), -- 05:47:47.006
(1651400,9,3,0,0,0,100,0,2000,2000,0,0,0,17,133,0,0,0,0,0,19,20227,0,0,0,0,0,0,0,"Botanist Taerix - On Script - Set Emote State 133 (Apprentice Tedon)"), -- 05:47:49.237
(1651400,9,4,0,0,0,100,0,2000,2000,0,0,0,17,0,0,0,0,0,0,19,20227,0,0,0,0,0,0,0,"Botanist Taerix - On Script - Set Emote State 0 (Apprentice Tedon)"), -- 05:47:51.608
(1651400,9,5,0,0,0,100,0,0,0,0,0,0,9,0,0,0,0,0,0,20,181370,0,0,0,0,0,0,0,"Botanist Taerix - On Script - Activate Closest Gameobject 'Volatile Mutation Cage'"), -- 05:47:51.920
(1651400,9,6,0,0,0,100,0,1000,1000,0,0,0,45,0,1,0,0,0,0,10,84989,16516,0,0,0,0,0,0,"Botanist Taerix - On Script - Set Data 0 1 (Volatile Mutation)"), -- 05:47:52.747
(1651400,9,7,0,0,0,100,0,6000,6000,0,0,0,1,1,0,0,0,0,0,19,20227,0,0,0,0,0,0,0,"Botanist Taerix - On Script - Say Line 1 (Apprentice Tedon)"), -- 05:47:58.581
(1651400,9,8,0,0,0,100,0,500,500,0,0,0,45,0,1,0,0,0,0,19,20227,0,0,0,0,0,0,0,"Botanist Taerix - On Script - Set Data 0 1 (Apprentice Tedon)"), -- 05:47:59.111
(1651400,9,9,0,0,0,100,0,500,500,0,0,0,17,133,0,0,0,0,0,19,20227,0,0,0,0,0,0,0,"Botanist Taerix - On Script - Set Emote State 133 (Apprentice Tedon)"), -- 05:47:59.595
(1651400,9,10,0,0,0,100,0,2000,2000,0,0,0,17,0,0,0,0,0,0,19,20227,0,0,0,0,0,0,0,"Botanist Taerix - On Script - Set Emote State 0 (Apprentice Tedon)"), -- 05:48:01.701
(1651400,9,11,0,0,0,100,0,0,0,0,0,0,86,35068,0,10,84989,16516,0,1,0,0,0,0,0,0,0,0,"Botanist Taerix - On Script - Cross Cast 'Quest - Volatile Mutation Transformation' (Volatile Mutation)"), -- 05:48:01.701
(1651400,9,12,0,0,0,100,0,3000,3000,0,0,0,1,2,0,0,0,0,0,19,20227,0,0,0,0,0,0,0,"Botanist Taerix - On Script - Say Line 2 (Apprentice Tedon)"), -- 05:48:04.431
(1651400,9,13,0,0,0,100,0,0,0,0,0,0,45,0,2,0,0,0,0,10,84989,16516,0,0,0,0,0,0,"Botanist Taerix - On Script - Set Data 0 2 (Volatile Mutation)"), -- 05:48:04.525
(1651400,9,14,0,0,0,100,0,4000,4000,0,0,0,45,0,2,0,0,0,0,19,20227,0,0,0,0,0,0,0,"Botanist Taerix - On Script - Set Data 0 2 (Apprentice Tedon)"), -- 05:48:08.237
(1651400,9,15,0,0,0,100,0,0,0,0,0,0,82,1,0,0,0,0,0,19,20227,0,0,0,0,0,0,0,"Botanist Taerix - On Script - Add NPC Flag Gossip (Apprentice Tedon)"), -- 05:48:08.237

(20227,0,0,0,38,0,100,0,0,1,0,0,0,66,0,0,0,0,0,0,10,84989,16516,0,0,0,0,0,0,"Apprentice Tedon - On Data Set 0 1 - Set Orientation"),
(20227,0,1,0,38,0,100,0,0,2,0,0,0,66,0,0,0,0,0,0,20,181370,0,0,0,0,0,0,0,"Apprentice Tedon - On Data Set 0 2 - Set Orientation Closest Gameobject 'Volatile Mutation Cage'"),

(-84989,0,0,0,38,0,100,0,0,1,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Volatile Mutation - On Data Set 0 1 - Set Run Off"),
(-84989,0,1,0,38,0,100,0,0,1,0,0,0,69,1,0,0,0,0,0,8,0,0,0,0,-4055.89,-13714.2,73.064926,0,"Volatile Mutation - On Data Set 0 1 - Move To Position"),
(-84989,0,2,0,38,0,100,0,0,2,0,0,0,53,0,16516,0,0,0,3,1,0,0,0,0,0,0,0,0,"Volatile Mutation - On Data Set 0 2 - Start Waypoint"),
(-84989,0,3,0,40,0,100,0,3,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Volatile Mutation - On Waypoint 3 Reached - Despawn Instant");

UPDATE `creature` SET `spawntimesecs` = 2, `unit_flags` = 256 WHERE `id` = 16516 AND `guid` = 84989; -- Sniff

DELETE FROM `waypoints` WHERE `entry` = 16516;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(16516,1,-4050.9736,-13711.841,73.793686,0,0,"Volatile Mutation"),
(16516,2,-4049.6997,-13705.48,73.34471,0,0,"Volatile Mutation"),
(16516,3,-4049.355,-13698.271,72.793106,0,0,"Volatile Mutation");
