-- add fake death emote for K3 Snow Runner
UPDATE `creature` SET `spawndist`=0, `MovementType`=0, `dynamicflags`=32 WHERE  `guid` IN (105491);
UPDATE `creature_addon` SET `bytes1`=7, `auras`='29266' WHERE  `guid`=105491;

-- Cast Emote Snowblind Devotee
-- Snowblind Devotee SAI
SET @GUID := -152070;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=29407;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,2000,3000,2000,3000,5,51,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Devotee - Out of Combat - Play Emote 51"),
(@GUID,0,1,0,2,0,100,0,0,30,120000,130000,11,56410,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Devotee - Between 0-30% Health - Cast 'Blind Faith'");

-- Snowblind Devotee SAI
SET @GUID := -117307;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=29407;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,2000,3000,2000,3000,5,51,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Devotee - Out of Combat - Play Emote 51"),
(@GUID,0,1,0,2,0,100,0,0,30,120000,130000,11,56410,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Devotee - Between 0-30% Health - Cast 'Blind Faith'");

-- Snowblind Devotee SAI
SET @GUID := -117305;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=29407;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,2000,3000,2000,3000,5,51,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Devotee - Out of Combat - Play Emote 51"),
(@GUID,0,1,0,2,0,100,0,0,30,120000,130000,11,56410,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Devotee - Between 0-30% Health - Cast 'Blind Faith'");

-- Snowblind Devotee SAI
SET @GUID := -117306;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=29407;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,2000,3000,2000,3000,5,51,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Devotee - Out of Combat - Play Emote 51"),
(@GUID,0,1,0,2,0,100,0,0,30,120000,130000,11,56410,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Devotee - Between 0-30% Health - Cast 'Blind Faith'");

-- Snowblind Devotee SAI
SET @GUID := -117309;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=29407;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,2000,3000,2000,3000,5,51,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Devotee - Out of Combat - Play Emote 51"),
(@GUID,0,1,0,2,0,100,0,0,30,120000,130000,11,56410,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Devotee - Between 0-30% Health - Cast 'Blind Faith'");

-- Snowblind Devotee SAI
SET @GUID := -152076;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=29407;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,2000,3000,2000,3000,5,51,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Devotee - Out of Combat - Play Emote 51"),
(@GUID,0,1,0,2,0,100,0,0,30,120000,130000,11,56410,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Devotee - Between 0-30% Health - Cast 'Blind Faith'");

-- Snowblind Devotee SAI
SET @GUID := -152071;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=29407;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,2000,3000,2000,3000,5,51,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Devotee - Out of Combat - Play Emote 51"),
(@GUID,0,1,0,2,0,100,0,0,30,120000,130000,11,56410,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Devotee - Between 0-30% Health - Cast 'Blind Faith'");

SET @MAXGUID := 935; 
SET @SCRIPTID := 11730800; 
DELETE FROM `waypoint_scripts` WHERE `id` IN (@SCRIPTID+0);
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES 
(@SCRIPTID+0, 16, 1, 51, 0, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1));

SET @NPC := 117308;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`, `action`, `orientation`) VALUES
(@PATH, 1, 6293.67, -1372.49, 425.351, 0, 0, 0),
(@PATH, 2, 6292.79, -1379.43, 425.474, 0, 0, 0),
(@PATH, 3, 6292.56, -1389.92, 425.328, 0, 0, 0),
(@PATH, 4, 6291.29, -1402.94, 425.217, 0, 0, 0),
(@PATH, 5, 6280.42, -1410.52, 425.174, 0, 0, 0),
(@PATH, 6, 6276.46, -1426.88, 425.625, 0, 0, 0),
(@PATH, 7, 6287.83, -1430.52, 426.185, 0, 0, 0),
(@PATH, 8, 6299.13, -1428.12, 426.536, 0, 0, 0),
(@PATH, 9, 6300.72, -1411.98, 425.887, 0, 0, 0),
(@PATH, 10, 6298.78, -1404.25, 425.477, 0, 0, 0),
(@PATH, 11, 6294.47, -1397.44, 425.235, 0, 0, 0),
(@PATH, 12, 6293.67, -1372.49, 425.351, 19000, @SCRIPTID, 0);

UPDATE `waypoint_data` SET `action_chance`=100 WHERE `action` IN (@SCRIPTID);

-- path event for one nowblind Devotee
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE  `guid` IN (117310);

SET @MAXGUID := 936; 
SET @SCRIPTID := 11730800; 
DELETE FROM `waypoint_scripts` WHERE `id` IN (@SCRIPTID+0);
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES 
(@SCRIPTID+0, 1, 1, 36, 0, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1));

SET @NPC := 117310;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`, `action`, `orientation`, `move_type`) VALUES
(@PATH, 1, 6310.51, -1764.65, 457.506, 3000, @SCRIPTID, 0.106101, 1),
(@PATH, 2, 6312.33, -1761.09, 457.204, 3000, @SCRIPTID, 5.38790, 1),
(@PATH, 3, 6316.17, -1760.95, 457.158, 3000, @SCRIPTID, 4.253009, 1),
(@PATH, 4, 6314.01, -1761.02, 457.186, 0, 0, 0, 1),
(@PATH, 5, 6310.96, -1762.02, 457.424, 0, 0, 0, 1);

UPDATE `waypoint_data` SET `action_chance`=100 WHERE `action` IN (@SCRIPTID);
