/*
-- ==================================================================
-- Hammerfall - Arathi Highland
-- Hammerfall Guardian SAI
SET @GUID := -11212;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2621;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,0,0,10000,10000,80,1121200,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hammerfall Guardian - Out of Combat - Run Script");

-- Actionlist SAI
SET @ENTRY := 1121200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,5,1,0,0,0,0,0,10,11235,2621,0,0,0,0,0,"Hammerfall Guardian - On Script - Play Emote 1"),
(@ENTRY,9,1,0,0,0,100,0,4000,4000,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hammerfall Guardian - On Script - Play Emote 1");

-- ==================================================================
-- Horde Guard - Barrens
-- Horde Guard SAI
SET @GUID := -19403;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3501;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,0,0,10000,10000,80,1940300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Guard - Out of Combat - Run Script");

-- Actionlist SAI
SET @ENTRY := 1940300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,5,1,0,0,0,0,0,10,19428,3501,0,0,0,0,0,"Horde Guard - On Script - Play Emote 1"),
(@ENTRY,9,1,0,0,0,100,0,4000,4000,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Guard - On Script - Play Emote 1");

-- ==================================================================
-- Peon - Barrens
-- Peon SAI
SET @GUID := -13751;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14901;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,0,0,10000,10000,80,1375100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Peon - Out of Combat - Run Script");

-- Actionlist SAI
SET @ENTRY := 1375100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,5,1,0,0,0,0,0,10,13772,14901,0,0,0,0,0,"Peon - On Script - Play Emote 1"),
(@ENTRY,9,1,0,0,0,100,0,4000,4000,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Peon - On Script - Play Emote 1");

-- Peon Emotestate script
SET @MAXGUID := 933; 
SET @SCRIPTID := 1377500; 
DELETE FROM `waypoint_scripts` WHERE `id` IN (@SCRIPTID+0);
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES
(@SCRIPTID+0, 3, 1, 69, 1, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1)),
(@SCRIPTID+0, 235, 1, 0, 1, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1));

SET @NPC := 13775;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `orientation`, `delay`, `move_type`, `action`) VALUES
(@PATH, 1, -629.313, -3161, 92.3242, 3.79019, 0, 0, 0),     
(@PATH, 2, -624.911, -3156.44, 91.7832, 0.483361, 0, 0, 0),     
(@PATH, 3, -617.56, -3155.6, 91.7512, 0.161653, 0, 0, 0),     
(@PATH, 4, -617.56, -3155.6, 91.7512, 0.161653, 240000, 0, @SCRIPTID),     
(@PATH, 5, -625.854, -3158.22, 91.9782, 3.5153, 0, 0, 0),     
(@PATH, 6, -629.313, -3161, 92.3242, 3.79019, 20000, 0, 0);

UPDATE `waypoint_data` SET `action_chance`=100 WHERE `action` IN (@SCRIPTID);

-- ==================================================================
-- Westfall Woodworker - Sentinell Hill - Westfall
DELETE FROM `creature_addon` WHERE guid IN (44303,45472,45521,89860);
SET @SCTIPT_ID = 4430300;
SET @MAXGUID := 930; 
DELETE FROM `waypoint_scripts` WHERE id BETWEEN @SCTIPT_ID+0 AND @SCTIPT_ID+1;
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES
(@SCTIPT_ID+0, 3, 1, 69, 1, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1)),
(@SCTIPT_ID+0, 87, 1, 0, 1, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1)),
(@SCTIPT_ID+1, 3, 1, 16, 0, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1));

SET @NPC := 44303;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`, `action`) VALUES
(@PATH, 1, -10662.1, 1130.83, 34.1967, 15000, 0) ,
(@PATH, 2, -10662.1, 1130.83, 34.1967, 90000, @SCTIPT_ID+0),
(@PATH, 3, -10661.3, 1113.16, 34.1967, 90000, @SCTIPT_ID+0);

SET @NPC := 45472;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`, `action`) VALUES
(@PATH, 1, -10650.8, 1128.61, 34.1978, 90000, @SCTIPT_ID+0),
(@PATH, 2, -10650.8, 1128.61, 34.1978, 10000, 0),
(@PATH, 3, -10658.8, 1134.62, 34.1967, 90000, @SCTIPT_ID+0);

SET @NPC := 45521;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`, `action`) VALUES
(@PATH, 1, -10650.1, 1115.028, 35.611, 6000, @SCTIPT_ID+1),
(@PATH, 2, -10646.4, 1113.332, 35.6268, 90000, @SCTIPT_ID+0);

SET @NPC := 89860;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`, `action`) VALUES
(@PATH, 1, -10656.2, 1126.87, 34.1967, 90000, @SCTIPT_ID+0),
(@PATH, 2, -10667.4, 1121.39, 34.1967, 90000, @SCTIPT_ID+0);

UPDATE `waypoint_data` SET `action_chance`=100 WHERE `action` BETWEEN @SCTIPT_ID+0 AND @SCTIPT_ID+1;
*/
