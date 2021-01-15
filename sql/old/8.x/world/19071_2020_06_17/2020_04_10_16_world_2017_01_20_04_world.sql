-- Gothik the Harvester Entry 2 event
-- Scarlet Deserter
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `guid` IN (130402,130403,130404,130405);
UPDATE `creature` SET `position_x` = 2817.77, `position_y` = -5453.906, `position_z` = 159.4021, `orientation` = 1.937315 WHERE `guid` = 130405;

-- Scarlet Deserter SAI
SET @GUID := -130405;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=29193;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,0,0,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Deserter - On Reset - Set Fly On");

-- Gothik the Harvester SAI
SET @ENTRY := 29112;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2000,2000,640000,640000,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Gothik the Harvester - Out of Combat - Run Script");

-- Actionlist SAI
SET @ENTRY := 2911200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gothik the Harvester - On Script - Set Active On"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,1,0,4000,0,0,0,0,10,130405,29193,0,0,0,0,0,"Gothik the Harvester - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,4000,4000,0,0,1,0,30000,0,0,0,0,1,0,0,0,0,0,0,0,"Gothik the Harvester - On Script - Say Line 0"),
(@ENTRY,9,3,0,0,0,100,0,63000,63000,0,0,1,1,4000,0,0,0,0,10,130405,29193,0,0,0,0,0,"Gothik the Harvester - On Script - Say Line 1"),
(@ENTRY,9,4,0,0,0,100,0,4000,4000,0,0,1,1,30000,0,0,0,0,1,0,0,0,0,0,0,0,"Gothik the Harvester - On Script - Say Line 1"),
(@ENTRY,9,5,0,0,0,100,0,73000,73000,0,0,1,2,4000,0,0,0,0,10,130405,29193,0,0,0,0,0,"Gothik the Harvester - On Script - Say Line 2"),
(@ENTRY,9,6,0,0,0,100,0,4000,4000,0,0,1,2,30000,0,0,0,0,1,0,0,0,0,0,0,0,"Gothik the Harvester - On Script - Say Line 2"),
(@ENTRY,9,7,0,0,0,100,0,68000,68000,0,0,1,3,4000,0,0,0,0,10,130405,29193,0,0,0,0,0,"Gothik the Harvester - On Script - Say Line 3"),
(@ENTRY,9,8,0,0,0,100,0,4000,4000,0,0,1,3,30000,0,0,0,0,1,0,0,0,0,0,0,0,"Gothik the Harvester - On Script - Say Line 3"),
(@ENTRY,9,9,0,0,0,100,0,78000,78000,0,0,1,4,4000,0,0,0,0,10,130405,29193,0,0,0,0,0,"Gothik the Harvester - On Script - Say Line 4"),
(@ENTRY,9,10,0,0,0,100,0,4000,4000,0,0,1,4,30000,0,0,0,0,1,0,0,0,0,0,0,0,"Gothik the Harvester - On Script - Say Line 4"),
(@ENTRY,9,11,0,0,0,100,0,73000,73000,0,0,1,5,4000,0,0,0,0,10,130405,29193,0,0,0,0,0,"Gothik the Harvester - On Script - Say Line 5"),
(@ENTRY,9,12,0,0,0,100,0,4000,4000,0,0,1,5,30000,0,0,0,0,1,0,0,0,0,0,0,0,"Gothik the Harvester - On Script - Say Line 5"),
(@ENTRY,9,13,0,0,0,100,0,53000,53000,0,0,1,6,30000,0,0,0,0,10,130405,29193,0,0,0,0,0,"Gothik the Harvester - On Script - Say Line 6"),
(@ENTRY,9,14,0,0,0,100,0,0,0,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gothik the Harvester - On Script - Set Active Off");

DELETE FROM `creature_text` WHERE `CreatureID` IN (29193, 29112);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES 
-- Scarlet Deserter
(29193, 0, 0, 'You\'re a monster!', 12, 0, 100, 0, 0, 0, 29644, 'Scarlet Deserter'),
(29193, 1, 0, 'Please! Spare me! I...', 12, 0, 100, 0, 0, 0, 29645, 'Scarlet Deserter'),
(29193, 2, 0, 'Wi... Will it hurt?', 12, 0, 100, 0, 0, 0, 29641, 'Scarlet Deserter'),
(29193, 3, 0, 'It tingles...', 12, 0, 100, 0, 0, 0, 29642, 'Scarlet Deserter'),
(29193, 4, 0, 'Why don\'t you Just Kill me Already', 12, 0, 100, 0, 0, 0, 0, 'Scarlet Deserter'),
(29193, 5, 0, 'Is it too late to change my mind? How about you just kill me instead?', 12, 0, 100, 0, 0, 0, 29643, 'Scarlet Deserter'),
(29193, 6, 0, 'The horror! THE HORROR!', 12, 0, 100, 0, 0, 0, 29646, 'Scarlet Deserter'),
-- Gothik the Harvester
(29112, 0, 0, 'Flattery will get you nowhere.', 12, 0, 100, 1, 0, 0, 29650, 'Gothik the Harvester'),
(29112, 1, 0, 'Don\'t be ridiculous. Where would you even go if I did spare you? We just finished eradicating your civilization, remember?', 12, 0, 100, 1, 0, 0, 29651, 'Gothik the Harvester'),
(29112, 2, 0, 'Oh yes. Immensely. The pain will propably render you unconcious - hence the vat of slime you\'re floating in!', 12, 0, 100, 1, 0, 0, 0, 'Gothik the Harvester'), 
(29112, 3, 0, 'That\'s how you know it\'s working.', 12, 0, 100, 1, 0, 0, 29648, 'Gothik the Harvester'),
(29112, 4, 0, 'You idiot! That\'s What I\'m Doing Right Now!', 12, 0, 100, 5, 0, 0, 0, 'Gothik the Harvester'),
(29112, 5, 0, 'I AM going to kill you. What\'s the rush?', 12, 0, 100, 6, 0, 0, 29649, 'Gothik the Harvester');

-- The Noxious Glade
-- Noth the Plaguebringer SAI
SET @ENTRY := 29113;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,60000,60000,60000,60000,1,0,20000,0,0,0,0,1,0,0,0,0,0,0,0,"Noth the Plaguebringer - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=29113;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES 
(29113, 0, 0, 'We need more flesh!', 14, 0, 100, 5, 0, 0, 29634, 'Noth the Plaguebringer'),
(29113, 0, 1, 'Double your efforts! The final assault draws near!', 14, 0, 100, 5, 0, 0, 29639, 'Noth the Plaguebringer');

-- Howling Geist 
UPDATE `creature` SET `position_x` = 2597.903076, `position_y` = -5549.420410, `position_z` = 159.772934, `spawndist` = 20, `MovementType` = 1 WHERE `guid` = 130387;
UPDATE `creature` SET `position_x` = 2622.867432, `position_y` = -5481.481934, `position_z` = 156.948212, `spawndist` = 20, `MovementType` = 1 WHERE `guid` = 130386;
UPDATE `creature` SET `position_x` = 2659.806885, `position_y` = -5537.375000, `position_z` = 163.303589, `spawndist` = 20, `MovementType` = 1 WHERE `guid` = 130385;
UPDATE `creature` SET `position_x` = 2697.650391, `position_y` = -5469.664063, `position_z` = 156.943970, `spawndist` = 20, `MovementType` = 1 WHERE `guid` = 130383;
UPDATE `creature` SET `position_x` = 2735.920410, `position_y` = -5363.948730, `position_z` = 157.715302, `spawndist` = 20, `MovementType` = 1 WHERE `guid` = 130381;

-- Rampaging Abomination
UPDATE `creature` SET `position_x` = 2770.925049, `position_y` = -5536.027344, `position_z` = 161.735718, `orientation` = 2.301208, `spawndist` = 10, `MovementType` = 1 WHERE guid = 130378;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 2, `spawntimesecs` = 10 WHERE `guid` IN (130376,130379);

SET @NPC := 130376;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '53624');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 2723.56, -5356.07, 159.613,0),
(@PATH, 2, 2704.62, -5360.77, 159.398,0),
(@PATH, 3, 2691.18, -5349.93, 158.621,0),
(@PATH, 4, 2683.39, -5323.99, 155.334,0),
(@PATH, 5, 2675.71, -5304.56, 153.114,0),
(@PATH, 6, 2663.78, -5284.98, 148.258,0),
(@PATH, 7, 2658.59, -5275.23, 142.105,0),
(@PATH, 8, 2644.61, -5255.16, 121.631,0),
(@PATH, 9, 2631.96, -5238.4, 107.608,0),
(@PATH, 10, 2613.31, -5216.83, 93.161,0),
(@PATH, 11, 2598.7, -5201.75, 82.8146,0),
(@PATH, 12, 2582.36, -5187.09, 75.8517,0),
(@PATH, 13, 2569.27, -5176.85, 73.7495,0),
(@PATH, 14, 2558.21, -5168.27, 74.6465,0),
(@PATH, 15, 2538.28, -5155.75, 74.2881,0),
(@PATH, 16, 2521.03, -5147.47, 73.6583,0),
(@PATH, 17, 2502.8, -5138.25, 75.7383,0),
(@PATH, 18, 2483.53, -5131.73, 75.9083, 2000);

UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`=@PATH;
UPDATE `waypoint_data` SET `action`=1188, `action_chance`=100 WHERE `id`=@PATH AND `point`=18;

SET @NPC := 130379;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '53624');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 2726.07, -5498.8, 162.02,0),
(@PATH, 2, 2727.57, -5481.48, 161.561,0),
(@PATH, 3, 2732.97, -5468.64, 157.569,0),
(@PATH, 4, 2750.98, -5458.35, 156.968,0),
(@PATH, 5, 2772.88, -5441.7, 159.903,0),
(@PATH, 6, 2774.75, -5416.45, 160.25,0),
(@PATH, 7, 2771.21, -5396.04, 158.102,0),
(@PATH, 8, 2750.66, -5381.1, 156.956,0),
(@PATH, 9, 2727.84, -5372.87, 157.819,0),
(@PATH, 10, 2707.88, -5366.33, 158.707,0),
(@PATH, 11, 2693.81, -5354.31, 158.877,0),
(@PATH, 12, 2687.94, -5338.24, 156.999,0),
(@PATH, 13, 2681.92, -5317.73, 154.846,0),
(@PATH, 14, 2675.34, -5305.38, 153.191,0),
(@PATH, 15, 2659.58, -5278.96, 144.64,0),
(@PATH, 16, 2651.18, -5266.35, 132.35,0),
(@PATH, 17, 2636.53, -5246.73, 112.628,0),
(@PATH, 18, 2619.36, -5225.24, 97.7497,0),
(@PATH, 19, 2605.23, -5209.7, 86.9899,0),
(@PATH, 20, 2591.1, -5194.16, 79.6859,0),
(@PATH, 21, 2573.87, -5176.1, 73.9424,0),
(@PATH, 22, 2558.81, -5161.48, 74.598,0),
(@PATH, 23, 2540.44, -5148.6, 74.2861,0),
(@PATH, 24, 2525.34, -5139.75, 73.6435,0),
(@PATH, 25, 2505.64, -5127.77, 74.8511,0),
(@PATH, 26, 2480.14, -5116.4, 79.0267, 2000);

UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`=@PATH;
UPDATE `waypoint_data` SET `action`=1188, `action_chance`=100 WHERE `id`=@PATH AND `point`=26;

-- Volatile Ghoul
UPDATE `creature` SET `spawntimesecs` = 10 WHERE `guid` IN (130363,130373,130362);

SET @MAXGUID := 917; 
SET @SCRIPTID := 13036300; 
DELETE FROM `waypoint_scripts` WHERE `id` IN (@SCRIPTID+0);
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES 
(@SCRIPTID+0, 1, 15, 26047, 1, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1)),
(@SCRIPTID+0, 4, 1, 0, 1, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1));

SET @NPC := 130363;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,67108864,1,0, '53624');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`, `action`, `action_chance`) VALUES
(@PATH, 1, 2676.73, -5314.65, 154.792, 5000, @SCRIPTID, 100),
(@PATH, 2, 2684.4, -5306.35, 154.941, 0, 0, 0),
(@PATH, 3, 2670.25, -5284.02, 150.153, 0, 0, 0),
(@PATH, 4, 2662.09, -5274.22, 142.412, 0, 0, 0),
(@PATH, 5, 2644.94, -5255.23, 121.88, 0, 0, 0),
(@PATH, 6, 2620.75, -5225.3, 98.1054, 0, 0, 0),
(@PATH, 7, 2592.76, -5198.52, 80.7613, 0, 0, 0),
(@PATH, 8, 2574.95, -5181.7, 74.3096, 0, 0, 0),
(@PATH, 9, 2522.32, -5148.41, 73.6604, 0, 0, 0),
(@PATH, 10, 2475.21, -5122.23, 77.9418, 2000, 1188, 100);

UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`=@PATH;

SET @NPC := 130373;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,67108864,1,0, '53624');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`, `action`, `action_chance`) VALUES
(@PATH, 1, 2632.02, -5394.72, 168.397, 5000, @SCRIPTID, 100),
(@PATH, 2, 2651.32, -5405.91, 159.224, 0, 0, 0),
(@PATH, 3, 2684.38, -5384.49, 157.184, 0, 0, 0),
(@PATH, 4, 2687.79, -5330.18, 156.083, 0, 0, 0),
(@PATH, 5, 2684.96, -5314.39, 154.96, 0, 0, 0),
(@PATH, 6, 2679.3, -5303.38, 153.638, 0, 0, 0),
(@PATH, 7, 2672.93, -5295.8, 151.813, 0, 0, 0),
(@PATH, 8, 2664.86, -5285.81, 148.772, 0, 0, 0),
(@PATH, 9, 2655.93, -5274.74, 141.215, 0, 0, 0),
(@PATH, 10, 2639.53, -5252.05, 116.733, 0, 0, 0),
(@PATH, 11, 2621.55, -5230.63, 100.908, 0, 0, 0),
(@PATH, 12, 2606.08, -5211.66, 88.0324, 0, 0, 0),
(@PATH, 13, 2582.86, -5185.51, 75.8192, 0, 0, 0),
(@PATH, 14, 2564.62, -5169.25, 74.5214, 0, 0, 0),
(@PATH, 15, 2536.72, -5149.97, 74.2893, 0, 0, 0),
(@PATH, 16, 2516.32, -5145.46, 74.148, 0, 0, 0),
(@PATH, 17, 2491.97, -5142.91, 76.1721, 0, 0, 0),
(@PATH, 18, 2467.02, -5137.46, 77.5501, 2000, 1188, 100);

UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`=@PATH;

SET @NPC := 130362;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,67108864,1,0, '53624');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`, `action`, `action_chance`) VALUES
(@PATH, 1, 2567.76, -5185.66, 74.8526, 5000, @SCRIPTID, 100),
(@PATH, 2, 2521.28, -5146.41, 73.6638, 0, 0, 0),
(@PATH, 3, 2483.25, -5139.37, 76.3581, 0, 0, 0),
(@PATH, 4, 2464.89, -5154.73, 78.0666, 2000, 1188, 100);

UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`=@PATH;

-- Volatile Ghoul
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 2, `spawntimesecs` = 10 WHERE `guid` IN (130363,130373,130362);

-- Scourge Commander Thalanor
UPDATE `creature` SET `spawndist` = 10, `MovementType` = 1 WHERE `guid` = 130467;
