-- Thrallmar Grunt Scripts
-- Script 1
SET @MAXGUID := 937; 
SET @SCRIPTID := 5753900; 
DELETE FROM `waypoint_scripts` WHERE `id` IN (@SCRIPTID+0);
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES 
(@SCRIPTID+0, 2, 1, 7, 0, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1));

SET @NPC := 57539;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `orientation`, `delay`, `action`) VALUES
(@PATH, 1, -1326, 2377.83, 88.981, 0.488692, 20000, 0),
(@PATH, 2, -1326, 2377.83, 88.981, 0.488692, 5000, @SCRIPTID);

UPDATE `waypoint_data` SET `action_chance`=100 WHERE `action` IN (@SCRIPTID);

-- Thrallmar Grunt SAI
SET @GUID := -57541;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=16580;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,34,0,100,0,2,1,0,0,80,5754100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thrallmar Grunt - On Reached Point 1 - Run Script"),
(@GUID,0,1,0,34,0,100,0,2,3,0,0,80,5754101,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thrallmar Grunt - On Reached Point 3 - Run Script"),
(@GUID,0,2,0,25,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thrallmar Grunt - On Reset - Cast 'Invisibility and Stealth Detection' (No Repeat)");

-- Actionlist SAI
SET @ENTRY := 5754100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thrallmar Grunt - On Script - Set Active On"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.88507,"Thrallmar Grunt - On Script - Set Orientation 4.88507"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,1,0,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Thrallmar Grunt - On Script - Say Line 0"),
(@ENTRY,9,3,0,0,0,100,0,4000,4000,0,0,45,1,1,0,0,0,0,10,57538,16580,0,0,0,0,0,"Thrallmar Grunt - On Script - Set Data 1 1"),
(@ENTRY,9,4,0,0,0,100,0,2000,2000,0,0,1,1,7000,0,0,0,0,10,57538,16580,0,0,0,0,0,"Thrallmar Grunt - On Script - Say Line 1"),
(@ENTRY,9,5,0,0,0,100,0,4000,4000,0,0,45,2,2,0,0,0,0,10,57538,16580,0,0,0,0,0,"Thrallmar Grunt - On Script - Set Data 2 2"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,1,2,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Thrallmar Grunt - On Script - Say Line 2"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thrallmar Grunt - On Script - Set Active Off");

-- Actionlist SAI
SET @ENTRY := 5754101;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thrallmar Grunt - On Script - Set Active On"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.88507,"Thrallmar Grunt - On Script - Set Orientation 4.88507"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,1,3,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Thrallmar Grunt - On Script - Say Line 3"),
(@ENTRY,9,3,0,0,0,100,0,4000,4000,0,0,45,1,1,0,0,0,0,10,57538,16580,0,0,0,0,0,"Thrallmar Grunt - On Script - Set Data 1 1"),
(@ENTRY,9,4,0,0,0,100,0,2000,2000,0,0,1,4,6000,0,0,0,0,10,57538,16580,0,0,0,0,0,"Thrallmar Grunt - On Script - Say Line 4"),
(@ENTRY,9,5,0,0,0,100,0,4000,4000,0,0,45,2,2,0,0,0,0,10,57538,16580,0,0,0,0,0,"Thrallmar Grunt - On Script - Set Data 2 2"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.03687,"Thrallmar Grunt - On Script - Set Orientation 3.03687"),
(@ENTRY,9,7,0,0,0,100,0,3000,3000,0,0,1,5,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Thrallmar Grunt - On Script - Say Line 5"),
(@ENTRY,9,8,0,0,0,100,0,5000,5000,0,0,1,6,3000,0,0,0,0,10,57538,16580,0,0,0,0,0,"Thrallmar Grunt - On Script - Say Line 6"),
(@ENTRY,9,9,0,0,0,100,0,3000,3000,0,0,1,7,6000,0,0,0,0,10,0,0,0,0,0,0,0,"Thrallmar Grunt - On Script - Say Line 7"),
(@ENTRY,9,10,0,0,0,100,0,0,0,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thrallmar Grunt - On Script - Set Active Off");

-- Thrallmar Grunt SAI
SET @GUID := -57538;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=16580; 
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,38,0,100,0,1,1,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.01994,"Thrallmar Grunt - On Data Set 1 1 - Set Orientation 2,01994"),
(@GUID,0,1,0,38,0,100,0,2,2,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.977384,"Thrallmar Grunt - On Data Set 2 2 - Set Orientation 0.977384"),
(@GUID,0,2,0,25,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thrallmar Grunt - On Reset - Cast 'Invisibility and Stealth Detection' (No Repeat)");

DELETE FROM `creature_text` WHERE `entry`=16580;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(16580, 0, 0, 'I say we fire it. Cut the rope.', 12, 1, 100, 1, 0, 0, 16981, 'Thrallmar Grunt'),
(16580, 1, 0, 'You cut the rope. You have the knife.', 12, 1, 100, 1, 0, 0, 16983, 'Thrallmar Grunt'),
(16580, 2, 0, 'Harumph! Coward.', 12, 1, 100, 1, 0, 0, 16982, 'Thrallmar Grunt'),
(16580, 3, 0, 'You know, I think we can hit Honor Hold from here.', 12, 1, 100, 1, 0, 0, 16986, 'Thrallmar Grunt'),
(16580, 4, 0, 'If General Krakork found out, he''d eat us alive. Don''t.', 12, 1, 100, 1, 0, 0, 16988, 'Thrallmar Grunt'),
(16580, 5, 0, 'Ah! We can tell him Hagash stumbled into it and fired it accidentally!', 12, 1, 100, 1, 0, 0, 16987, 'Thrallmar Grunt'),
(16580, 6, 0, 'I''m blind, you stupid sow-spawn, not deaf. Don''t even think about it.', 12, 1, 100, 1, 0, 0, 16990, 'Thrallmar Grunt'),
(16580, 7, 0, '%s sighs.', 16, 0, 100, 0, 0, 0, 16989, 'Thrallmar Grunt');

SET @NPC := 57541;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 1, -1323.67, 2397.49, 88.731, 6.19592, 30000, 0),
(@PATH, 2, -1323.67, 2397.49, 88.731, 6.19592, 15000, 0),
(@PATH, 3, -1323.67, 2397.49, 88.731, 6.19592, 120000, 0),
(@PATH, 4, -1323.67, 2397.49, 88.731, 6.19592, 29000, 0),
(@PATH, 5, -1323.67, 2397.49, 88.731, 6.19592, 90000, 0);
