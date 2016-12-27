UPDATE `creature` SET `MovementType`=0 WHERE  `guid` IN (13578, 13166);
DELETE FROM `creature_addon` WHERE  `guid` IN (13578, 13166);
DELETE FROM `waypoint_data` WHERE  `id` IN (135780, 131660);
DELETE FROM `creature_formations` WHERE `leaderGUID`=13166;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(13166, 13166, 0, 0, 2, 0, 0),
(13166, 13578, 3, 0, 2, 0, 0);

UPDATE `creature` SET `position_x` = -29.864489, `position_y` = -2615.393311, `position_z` = 97.141731, `orientation` = 2.855997 WHERE `guid`  IN (13166, 13578);

-- Erk SAI
SET @ENTRY := 14857;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,14857,1,0,0,0,1,0,0,0,0,0,0,0,"Erk - On Reset - Start Waypoint"),
(@ENTRY,0,1,2,40,0,100,0,1,14857,0,0,54,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Erk - On Waypoint 1 Reached - Pause Waypoint"),
(@ENTRY,0,2,0,61,0,100,0,1,14857,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Erk - On Waypoint 1 Reached - Set Run On"),
(@ENTRY,0,3,4,40,0,100,0,2,14857,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Erk - On Waypoint 2 Reached - Pause Waypoint"),
(@ENTRY,0,4,5,61,0,100,0,2,14857,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Erk - On Waypoint 2 Reached - Set Run Off"),
(@ENTRY,0,5,0,61,0,100,0,2,14857,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Erk - On Waypoint 2 Reached - Say Line 0"),
(@ENTRY,0,6,0,40,0,100,0,7,14857,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Erk - On Waypoint 7 Reached - Run Script"),
(@ENTRY,0,7,0,40,0,100,0,17,14857,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Erk - On Waypoint 17 Reached - Pause Waypoint"),
(@ENTRY,0,8,9,40,0,100,0,18,1000,0,0,54,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Erk - On Waypoint 18 Reached - Pause Waypoint"),
(@ENTRY,0,9,0,61,0,100,0,18,1000,0,0,1,3,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Erk - On Waypoint 18 Reached - Say Line 3"),
(@ENTRY,0,10,0,40,0,100,0,27,14857,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Erk - On Waypoint 27 Reached - Run Script"),
(@ENTRY,0,11,0,40,0,100,0,35,14857,0,0,80,@ENTRY*100+02,2,0,0,0,0,1,0,0,0,0,0,0,0,"Erk - On Waypoint 35 Reached - Run Script"),
(@ENTRY,0,12,0,40,0,100,0,46,14857,0,0,54,120000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Erk - On Waypoint 46 Reached - Pause Waypoint");

-- Actionlist SAI
SET @ENTRY := 1485700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,35000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Erk - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,1,1,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Erk - On Script - Say Line 1"),
(@ENTRY,9,2,0,0,0,100,0,28000,28000,0,0,1,2,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Erk - On Script - Say Line 2");

-- Actionlist SAI
SET @ENTRY := 1485701;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,20000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Erk - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,15000,15000,0,0,1,4,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Erk - On Script - Say Line 4"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Erk - On Script - Set Run On");

-- Actionlist SAI
SET @ENTRY := 1485702;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,20000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Erk - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Erk - On Script - Set Run Off"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,19,14893,30,0,0,0,0,0,"Erk - On Script - Set Orientation Closest Creature 'Guard Kurall'"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,1,5,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Erk - On Script - Say Line 5"),
(@ENTRY,9,4,0,0,0,100,0,5000,5000,0,0,1,0,5000,0,0,0,0,19,14893,30,0,0,0,0,0,"Erk - On Script - Say Line 0"),
(@ENTRY,9,5,0,0,0,100,0,1000,1000,0,0,5,21,0,0,0,0,0,19,14893,30,0,0,0,0,0,"Erk - On Script - Play Emote 21"),
(@ENTRY,9,6,0,0,0,100,0,5000,5000,0,0,5,7,0,0,0,0,0,19,14893,30,0,0,0,0,0,"Erk - On Script - Play Emote 7"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,5,7,0,0,0,0,0,19,3501,30,0,0,0,0,0,"Erk - On Script - Play Emote 7"),
(@ENTRY,9,8,0,0,0,100,0,7000,7000,0,0,1,6,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Erk - On Script - Say Line 6");

DELETE FROM `waypoints` WHERE `entry`=14857;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(14857,1,-29.461918,-2615.942383,97.156921,    'Erk'),
(14857,2,-25.871311,-2613.071777,97.237740,    'Erk'),
(14857,3,-19.149178,-2619.644287,97.206207,    'Erk'),
(14857,4,-11.761329,-2621.954346,95.720047,    'Erk'),
(14857,5,-9.085948,-2621.673340,94.958389,     'Erk'),
(14857,6,-3.633063,-2621.637939,92.131180,     'Erk'),
(14857,7,3.790725,-2621.660400,89.812195,      'Erk'),
(14857,8,-0.125211,-2621.110107,91.288040,     'Erk'),
(14857,9,-4.097071,-2636.676514,91.979828,     'Erk'),
(14857,10,-9.720197,-2640.140869,95.660744,    'Erk'),
(14857,11,-21.905458,-2647.225098,95.833397,   'Erk'),
(14857,12,-29.928484,-2641.602295,96.080391,   'Erk'),
(14857,13,-33.601181,-2638.687256,96.445763,   'Erk'),
(14857,14,-33.754395,-2634.782715,96.275017,   'Erk'),
(14857,15,-31.780426,-2631.539307,95.990501,   'Erk'),
(14857,16,-30.316862,-2631.180908,95.940948,   'Erk'),
(14857,17,-29.142475,-2632.012695,95.948257,   'Erk'),
(14857,18,-29.142475,-2632.012695,95.948257,   'Erk'),
(14857,19,-32.082474,-2632.893555,96.072723,   'Erk'),
(14857,20,-32.984558,-2638.700439,96.384636,   'Erk'),
(14857,21,-31.521265,-2644.058350,96.142921,   'Erk'),
(14857,22,-24.469679,-2646.372070,95.832581,   'Erk'),
(14857,23,-18.641375,-2646.821289,95.832581,   'Erk'),
(14857,24,-9.770051,-2641.352539,95.589363,    'Erk'),
(14857,25,-8.478262,-2640.574463,95.227699,    'Erk'),
(14857,26,-3.890227,-2637.855713,92.000694,    'Erk'),
(14857,27,4.778752,-2632.607178,89.837997,     'Erk'),
(14857,28,4.568168,-2635.551270,90.447380,     'Erk'),
(14857,29,10.748284,-2640.516846,90.386475,    'Erk'),
(14857,30,34.780556,-2655.085938,91.912651,    'Erk'),
(14857,31,53.316978,-2671.718994,91.666901,    'Erk'),
(14857,32,63.588814,-2689.054932,92.944565,    'Erk'),
(14857,33,60.226498,-2698.291016,92.096138,    'Erk'),
(14857,34,55.970112,-2699.551270,91.900703,    'Erk'),
(14857,35,55.045853,-2698.405762,91.944672,    'Erk'),
(14857,36,45.898525,-2702.470947,91.700233,    'Erk'),
(14857,37,31.040888,-2703.291992,91.667572,    'Erk'),
(14857,38,23.505503,-2699.469482,91.734627,    'Erk'),
(14857,39,10.482596,-2681.701416,91.750694,    'Erk'),
(14857,40,-0.678281,-2668.660645,91.921181,    'Erk'),
(14857,41,-8.814530,-2659.541016,95.559288,    'Erk'),
(14857,42,-14.487419,-2643.521729,95.831528,   'Erk'),
(14857,43,-17.088795,-2620.453125,96.330254,   'Erk'),
(14857,44,-19.107914,-2619.602539,97.197205,   'Erk'),
(14857,45,-29.461918,-2615.942383,97.156921,   'Erk'),
(14857,46,-29.461918,-2615.942383,97.156921,   'Erk');

DELETE FROM `creature_text` WHERE `entry` IN (14857, 14893);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
-- Erk
(14857, 0, 0, 'Hmmm... Where is my fishing hook? Oh, there it is.', 12, 0, 100, 0, 0, 0, 10249, 'Erk'),
(14857, 1, 0, 'Let\'s see if the fish are biting.', 12, 0, 100, 0, 0, 0, 10250, 'Erk'),
(14857, 2, 0, 'Hmmm... I think I need better bait. I\'ll check my father\'s wagon.', 12, 0, 100, 0, 0, 0, 10195, 'Erk'),
(14857, 3, 0, 'Quillboar scraps! These should do the trick. Fish love Quillboar.', 12, 0, 100, 0, 0, 0, 10196, 'Erk'),
(14857, 4, 0, 'Caught one! I\'ll see if any of the guards are hungry. Come on Fang!', 12, 0, 100, 0, 0, 0, 10205, 'Erk'),
(14857, 5, 0, 'I caught a fish if you are hungry...', 12, 0, 100, 0, 0, 0, 10198, 'Erk'),
(14857, 6, 0, 'Zug zug! Happy to help!', 12, 0, 100, 0, 0, 0, 10206, 'Erk'),
-- Guard Kurall
(14893, 0, 0, 'A nice catch it is at that! You bring honor to the Horde boy, We thank you!', 12, 0, 100, 0, 0, 0, 10223, 'Guard Kurall');

-- Horde Guard SAI
SET @GUID := -19361;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3501;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,3000,5000,3000,5000,10,11,7,1,0,0,0,0,0,0,0,0,0,0,0,"Horde Guard - Out of Combat - Play Random Emote (11, 7, 1)");

-- Horde Guard SAI
SET @GUID := -19402;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3501;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,3000,5000,3000,5000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Guard - Out of Combat - Play Emote 1");

-- Horde Guard SAI
SET @GUID := -19412;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3501;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,3000,8000,3000,8000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Guard - Out of Combat - Play Emote 1");

-- Guard Kurall SAI
SET @GUID := -13579;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14893;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,3000,8000,3000,8000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Kurall - Out of Combat - Play Emote 1");
