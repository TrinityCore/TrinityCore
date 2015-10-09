-- deprecated on 4.x
DELETE FROM `creature_text` WHERE `entry`=14875;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(14875, 0, 0, 'Begin the ritual, my servants. We must banish the heart of Hakkar back into the void!', 14, 0, 100, 0, 0, 0, 'Molthor'),
(14875, 1, 0, 'All Hail $n, slayer of Hakkar, and hero of Azeroth!', 14, 0, 100, 0, 0, 0, 'Molthor');

DELETE FROM `locales_creature_text` WHERE `entry`=14875;
INSERT INTO `locales_creature_text` (`entry`, `groupid`, `id`, `text_loc3`) VALUES
(14875, 0, 0, 'Beginnt mit dem Ritual. Wir müssen das Herz von Hakkar zurück in die Leere verbannen!'),
(14875, 1, 0, 'All Hail $n, Bezwinger von Hakkar und Held von Azeroth!');

-- Molthor SAI
SET @ENTRY := 14875;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Molthor - On Gossip Hello - Play Emote 4"),
(@ENTRY,0,1,0,20,0,100,0,8183,0,0,0,53,0,14875,0,0,0,0,1,0,0,0,0,0,0,0,"Molthor - On Quest 'The Heart of Hakkar' Finished - Start Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,11,14875,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Molthor - On Waypoint 12 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,11,14875,0,0,54,39000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Molthor - On Waypoint 12 Reached - Pause Waypoint");

-- Actionlist SAI
SET @ENTRY := 1487500;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,24203,2,0,0,0,0,1,0,0,0,0,0,0,0,"Molthor - On Script - Cast 'Heart of Hakkar Banning'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,12,15080,6,0,0,0,0,8,0,0,0,-11817,1324,1,1,"Molthor - On Script - Summon Creature 'Servant of the Hand'"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,12,15080,6,0,0,0,0,8,0,0,0,-11831.5,1331.15,1.839,0.615,"Molthor - On Script - Summon Creature 'Servant of the Hand'"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,12,15080,6,0,0,0,0,8,0,0,0,-11834.8,1349.83,2.009,5.864,"Molthor - On Script - Summon Creature 'Servant of the Hand'"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,12,15080,6,0,0,0,0,8,0,0,0,-11801,1335.25,1.261,2.808,"Molthor - On Script - Summon Creature 'Servant of the Hand'"),
(@ENTRY,9,5,0,0,0,100,0,2000,2000,0,0,12,15069,2,38000,0,0,0,8,0,0,0,-11818.9,1343.2,7.905,4.3411,"Molthor - On Script - Summon Creature 'Heart of Hakkar'"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Molthor - On Script - Say Line 1"),
(@ENTRY,9,7,0,0,0,100,0,36000,36000,0,0,85,24425,0,0,0,0,0,17,0,2000,0,0,0,0,0,"Molthor - On Script - Invoker Cast 'Spirit of Zandalar'"),
(@ENTRY,9,8,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Molthor - On Script - Set Run On"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Molthor - On Script - Say Line 1"),
(@ENTRY,9,10,0,0,0,100,0,0,0,0,0,11,24425,2,0,0,0,0,17,0,2000,0,0,0,0,0,"Molthor - On Script - Cast 'Spirit of Zandalar'");

-- Servant of the Hand SAI
SET @ENTRY := 15080;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Servant of the Hand - On Just Summoned - Run Script");

-- Actionlist SAI
SET @ENTRY := 1508000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,24602,2,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Create Heart of Hakkar Summon Circle'"),
(@ENTRY,9,1,0,0,0,100,0,4000,4000,0,0,11,24217,64,0,0,0,0,19,15069,200,0,0,0,0,0,"On Script - Cast 'Quest - Heart of Hakkar, Ritual Cast Visual'"),
(@ENTRY,9,2,0,0,0,100,0,34000,34000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Despawn Instant");

-- Heart of Hakkar SAI
SET @ENTRY := 15069;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,100,100,5000,5000,11,24202,2,0,0,0,0,1,0,0,0,0,0,0,0,"Heart of Hakkar - Out of Combat - Cast 'Create Heart of Hakkar Rift'"),
(@ENTRY,0,1,0,1,0,100,0,38000,38000,0,0,41,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Heart of Hakkar - Out of Combat - Despawn In 10 ms");

DELETE FROM `waypoints` WHERE `entry`=14875;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(14875, 1, -11813.9, 1257.9, 6.00591, 'Molthor'),
(14875, 2, -11816, 1253.34, 4.10438, 'Molthor'),
(14875, 3, -11817.8, 1250.34, 2.64272, 'Molthor'),
(14875, 4, -11822.2, 1248.5, 2.45973, 'Molthor'),
(14875, 5, -11823, 1248.43, 2.43644, 'Molthor'),
(14875, 6, -11830.2, 1262.37, 1.60647, 'Molthor'),
(14875, 7, -11833.6, 1272.28, 1.51623, 'Molthor'),
(14875, 8, -11836.3, 1282.42, 1.74283, 'Molthor'),
(14875, 9, -11836.9, 1294, 0.464341, 'Molthor'),
(14875, 10, -11835.6, 1297.62, 0.654105, 'Molthor'),
(14875, 11, -11826.2, 1322.37, 0.217855, 'Molthor'),
(14875, 21, -11813.9, 1257.9, 6.00591, 'Molthor'),
(14875, 20, -11816, 1253.34, 4.10438, 'Molthor'),
(14875, 19, -11817.8, 1250.34, 2.64272, 'Molthor'),
(14875, 18, -11822.2, 1248.5, 2.45973, 'Molthor'),
(14875, 17, -11823, 1248.43, 2.43644, 'Molthor'),
(14875, 16, -11830.2, 1262.37, 1.60647, 'Molthor'),
(14875, 15, -11833.6, 1272.28, 1.51623, 'Molthor'),
(14875, 14, -11836.3, 1282.42, 1.74283, 'Molthor'),
(14875, 13, -11836.9, 1294, 0.464341, 'Molthor'),
(14875, 12, -11835.6, 1297.62, 0.654105, 'Molthor'),
(14875, 22, -11811.491, 1262.42, 6.004, 'Molthor'),
(14875, 23, -11812.52, 1260.45, 6.004, 'Molthor');
