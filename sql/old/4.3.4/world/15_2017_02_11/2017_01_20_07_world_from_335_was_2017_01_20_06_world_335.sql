/*
-- SCRIPT 1
SET @MAXGUID := 919;
SET @SCRIPTID := 8014900;
DELETE FROM `waypoint_scripts` WHERE `id` IN (@SCRIPTID+0);
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES
(@SCRIPTID+0, 1, 35, 1, 5, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1)),
(@SCRIPTID+0, 20, 35, 2, 0, 801490, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1));

SET @NPC := 80149;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `orientation`, `delay`, `move_type`, `action`) VALUES
(@PATH, 1, -9008.89, -320.603, 75.8279, 2.8812, 1000, 1, 0),
(@PATH, 2, -8981.22, -335.138, 73.3474, 5.82645, 0, 1, 0),
(@PATH, 3, -8946.51, -338.891, 71.1134, 5.82409, 0, 1, 0),
(@PATH, 4, -8912.77, -352.085, 72.5823, 5.88143, 0, 1, 0),
(@PATH, 5, -8881.49, -355.84, 73.1462, 6.17595, 0, 1, 0),
(@PATH, 6, -8910.65, -346.602, 71.1023, 2.81837, 0, 0, 0),
(@PATH, 7, -8883.13, -352.739, 72.9499, 2.75397, 0, 0, 0),
(@PATH, 8, -8911.38, -347.166, 71.3269, 2.95582, 0, 0, 0),
(@PATH, 9, -8947.63, -337.566, 70.9275, 2.87728, 0, 0, 0),
(@PATH, 10, -9008.89, -320.603, 75.8279, 2.8812, 25000, 0, @SCRIPTID);

UPDATE `waypoint_data` SET `action_chance`=100 WHERE `action` IN (@SCRIPTID);

-- SCRIPT 2
-- Defias Thug SAI
SET @GUID := -80152;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=38;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,0,0,10000,10000,80,8015200,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Thug - Out of Combat - Run Script"),
(@GUID,0,1,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Thug - On Aggro - Say Line 0 (No Repeat)");

-- Actionlist SAI
SET @ENTRY := 8015200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,5,1,0,0,0,0,0,10,80151,38,0,0,0,0,0,"Defias Thug - On Script - Play Emote 1"),
(@ENTRY,9,1,0,0,0,100,0,4000,4000,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Thug - On Script - Play Emote 1");

-- SCRIPT 3
SET @NPC := 80171;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 1, -9120.29, -275.579, 72.9006, 1.03043, 2000, 1),
(@PATH, 2, -9112.23, -263.542, 74.4268, 1.06342, 3000, 0),
(@PATH, 3, -9110.18, -259.698, 74.7637, 3.91441, 0, 1),
(@PATH, 4, -9120.29, -269.848, 73.5204, 3.94322, 4000, 0);

-- SCRIPT 4
SET @NPC := 80181;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 1, -9131.36, -306.832, 73.5301, 4.49767, 0, 1),
(@PATH, 2, -9132.83, -313.89, 73.306, 4.49767, 4000, 1),
(@PATH, 3, -9124.91, -379.208, 73.2856, 4.81183, 3000, 0),
(@PATH, 4, -9125.01, -372.703, 73.5785, 1.77234, 0, 1),
(@PATH, 5, -9138.42, -339.389, 72.5674, 1.2202, 0, 1),
(@PATH, 6, -9123.32, -311.799, 72.985, 1.2202, 4000, 0);

-- SCRIPT 5
-- Defias Thug SAI
SET @GUID := -80184;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=38;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,0,0,8000,8000,80,8018400,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Thug - Out of Combat - Run Script"),
(@GUID,0,1,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Thug - On Aggro - Say Line 0 (No Repeat)");

-- Actionlist SAI
SET @ENTRY := 8018400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,5,1,0,0,0,0,0,10,80185,38,0,0,0,0,0,"Defias Thug - On Script - Play Emote 1"),
(@ENTRY,9,1,0,0,0,100,0,4000,4000,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Thug - On Script - Play Emote 1");

-- SCRIPT 6
-- Defias Thug SAI
SET @GUID := -80188;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=38;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,0,0,8000,8000,80,8018800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Thug - Out of Combat - Run Script"),
(@GUID,0,1,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Thug - On Aggro - Say Line 0 (No Repeat)");

-- Actionlist SAI
SET @ENTRY := 8018800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,5,1,0,0,0,0,0,10,80189,38,0,0,0,0,0,"Defias Thug - On Script - Play Emote 1"),
(@ENTRY,9,1,0,0,0,100,0,4000,4000,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Thug - On Script - Play Emote 1");

-- SCRIPT 7
-- Defias Thug SAI
SET @GUID := -80201;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=38;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,0,0,8000,8000,80,8020100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Thug - Out of Combat - Run Script"),
(@GUID,0,1,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Thug - On Aggro - Say Line 0 (No Repeat)");

-- Actionlist SAI
SET @ENTRY := 8020100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,5,1,0,0,0,0,0,10,80200,38,0,0,0,0,0,"Defias Thug - On Script - Play Emote 1"),
(@ENTRY,9,1,0,0,0,100,0,4000,4000,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Thug - On Script - Play Emote 1");

-- SCRIPT 8
SET @MAXGUID := 921; 
SET @SCRIPTID := 8025100; 
DELETE FROM `waypoint_scripts` WHERE `id` IN (@SCRIPTID+0);
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES 
(@SCRIPTID+0, 1, 35, 1, 5, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1)),
(@SCRIPTID+0, 20, 35, 2, 0, 802510, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1));

SET @NPC := 80251;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `orientation`, `delay`, `move_type`, `action`) VALUES
(@PATH, 1, -8878.29, -410.994, 65.6802, 4.63836, 1000, 1, 0),
(@PATH, 2, -8880.02, -399.363, 66.0983, 2.83464, 0, 1, 0),
(@PATH, 3, -8898.18, -391.582, 68.6285, 3.16417, 0, 1, 0),
(@PATH, 4, -8914.49, -391.059, 69.3006, 2.22326, 0, 1, 0),
(@PATH, 5, -8928.27, -375.636, 71.218, 3.22857, 0, 1, 0),
(@PATH, 6, -8958.87, -373.826, 72.3354, 3.34245, 5000, 1, 0),
(@PATH, 7, -8921.43, -376.858, 71.1848, 0.534655, 0, 1, 0),
(@PATH, 8, -8909.08, -366.763, 72.135, 6.05679, 0, 1, 0),
(@PATH, 9, -8870.04, -371.407, 71.997, 4.63836, 0, 1, 0),
(@PATH, 10, -8878.29, -410.994, 65.6802, 4.63836, 0, 1, 0),
(@PATH, 11, -8878.29, -410.994, 65.6802, 4.63836, 25000, 1, @SCRIPTID);

UPDATE `waypoint_data` SET `action_chance`=100 WHERE `action` IN (@SCRIPTID);
*/
