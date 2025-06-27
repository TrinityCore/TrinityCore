-- 
-- Gruk SAI
SET @ENTRY := 14850;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,14850,1,0,0,0,1,0,0,0,0,0,0,0,"Gruk - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,2,8000,0,0,54,8000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gruk - On Waypoint 2 Reached - Pause Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,4,14850,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gruk - On Waypoint 4 Reached - Pause Waypoint"),
(@ENTRY,0,3,0,40,0,100,0,10,14850,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gruk - On Waypoint 10 Reached - Pause Waypoint"),
(@ENTRY,0,4,0,40,0,100,0,16,14850,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Gruk - On Waypoint 16 Reached - Run Script"),
(@ENTRY,0,5,0,40,0,100,0,21,14850,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gruk - On Waypoint 21 Reached - Pause Waypoint"),
(@ENTRY,0,6,0,40,0,100,0,27,14850,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Gruk - On Waypoint 27 Reached - Run Script"),
(@ENTRY,0,7,0,40,0,100,0,29,14850,0,0,54,120000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gruk - On Waypoint 29 Reached - Pause Waypoint");

-- Actionlist SAI
SET @ENTRY := 1485000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,11000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gruk - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,19,14859,30,0,0,0,0,0,"Gruk - On Script - Set Orientation Closest Creature 'Guard Taruc'"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Gruk - On Script - Say Line 0"),
(@ENTRY,9,3,0,0,0,100,0,5000,5000,0,0,1,0,4000,0,0,0,0,19,14859,30,0,0,0,0,0,"Gruk - On Script - Say Line 0"),
(@ENTRY,9,4,0,0,0,100,0,4000,4000,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Gruk - On Script - Say Line 1");

-- Actionlist SAI
SET @ENTRY := 1485001;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,12000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gruk - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,19,14859,30,0,0,0,0,0,"Gruk - On Script - Set Orientation Closest Creature 'Guard Taruc'"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,1,2,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Gruk - On Script - Say Line 2"),
(@ENTRY,9,3,0,0,0,100,0,4000,4000,0,0,1,1,5000,0,0,0,0,19,14859,30,0,0,0,0,0,"Gruk - On Script - Say Line 1"),
(@ENTRY,9,4,0,0,0,100,0,5000,5000,0,0,1,3,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Gruk - On Script - Say Line 3");

DELETE FROM `waypoints` WHERE `entry`=14850;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(14850,1,-533.573547,-2984.998291,92.891449,    'Gruk'),
(14850,2,-532.475403,-2982.788330,92.937279,    'Gruk'),
(14850,3,-535.363220,-2986.683350,92.872704,    'Gruk'),
(14850,4,-542.794800,-2987.175781,92.978973,    'Gruk'),
(14850,5,-539.589355,-2979.670410,93.142120,    'Gruk'),
(14850,6,-540.856995,-2972.263428,93.218491,    'Gruk'),
(14850,7,-542.508789,-2968.742188,91.666573,    'Gruk'),
(14850,8,-556.491699,-2958.448730,91.808884,    'Gruk'),
(14850,9,-560.313782,-2959.109131,91.671059,    'Gruk'),
(14850,10,-563.526733,-2961.728027,91.670532,   'Gruk'),
(14850,11,-554.859009,-2957.945313,91.988205,   'Gruk'),
(14850,12,-542.145020,-2969.399414,91.667198,   'Gruk'),
(14850,13,-541.034119,-2970.875977,92.783127,   'Gruk'),
(14850,14,-540.202698,-2974.504883,93.244942,   'Gruk'),
(14850,15,-538.437439,-2986.249268,92.934875,   'Gruk'),
(14850,16,-534.473755,-2989.052246,92.933678,   'Gruk'),
(14850,17,-537.863098,-2989.072754,92.941650,   'Gruk'),
(14850,18,-541.218079,-2972.432129,93.217178,   'Gruk'),
(14850,19,-542.573792,-2969.562012,91.666840,   'Gruk'),
(14850,20,-555.276855,-2959.603027,91.810295,   'Gruk'),
(14850,21,-557.442505,-2961.866943,91.666817,   'Gruk'),
(14850,22,-549.292786,-2960.807861,91.770721,   'Gruk'),
(14850,23,-541.476624,-2969.215576,91.667030,   'Gruk'),
(14850,24,-540.882019,-2970.607422,92.726028,   'Gruk'),
(14850,25,-540.170898,-2974.454590,93.247406,   'Gruk'),
(14850,26,-538.799744,-2988.168457,92.916451,   'Gruk'),
(14850,27,-534.022583,-2988.809082,92.925842,   'Gruk'),
(14850,28,-535.851135,-2988.203857,92.910934,   'Gruk'),
(14850,29,-537.077087,-2984.784668,92.954727,   'Gruk');

DELETE FROM `creature_text` WHERE `entry` IN (14850, 14859);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
-- Gruk
(14850, 0, 0, 'Would you like something more to eat sir?', 12, 0, 100, 1, 0, 0, 10066, 'Gruk'),
(14850, 1, 0, 'Right away sir.', 12, 0, 100, 1, 0, 0, 10267, 'Gruk'),
(14850, 2, 0, 'Here is your bread sir.', 12, 0, 100, 1, 0, 0, 10184, 'Gruk'),
(14850, 3, 0, 'As you wish sir.', 12, 0, 100, 1, 0, 0, 10266, 'Gruk'),
-- Guard Taruc
(14859, 0, 0, 'More bread boy!', 12, 0, 100, 1, 0, 0, 10183, 'Guard Taruc'),
(14859, 1, 0, 'Aaahh... Very good. Now scat!', 12, 0, 100, 1, 0, 0, 10265, 'Guard Taruc');

-- Grub SAI
SET @ENTRY := 3443;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,8000,8000,8000,8000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grub - Out of Combat - Play Emote 1");

-- Duhng SAI
SET @ENTRY := 8306;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,8000,10000,8000,10000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duhng - Out of Combat - Play Emote 1");

-- Guard Taruc SAI
SET @ENTRY := 14859;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,8000,9000,8000,9000,5,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Taruc - Out of Combat - Play Emote 7");
