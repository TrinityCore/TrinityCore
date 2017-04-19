-- Silvermoon City - Trainer Update 3
-- Welethelon <Blunt Weapon Merchant>
UPDATE `creature` SET position_x = 9665.084, position_y = -7073.852, position_z = 14.32864, orientation = 4.869938, Spawndist = 0, MovementType = 2 WHERE guid = 57631;
SET @NPC := 57631;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 9665.08, -7073.85, 14.3286,0),
(@PATH, 2, 9663.17, -7075.62, 14.3327,0),
(@PATH, 3, 9662.24, -7078.38, 14.3211,5000),
(@PATH, 4, 9668.51, -7079.23, 14.3343,0),
(@PATH, 5, 9668.51, -7079.23, 14.3343,5000),
(@PATH, 6, 9666.14, -7076.94, 14.3352,0),
(@PATH, 7, 9665.08, -7073.85, 14.3286,0),
(@PATH, 8, 9665.08, -7073.85, 14.3286,10000);

-- Noraelath <Leather Armor Merchant>
UPDATE `creature` SET position_x = 9651.68, position_y = -7070.56, position_z = 14.3104, orientation = 4.01189, Spawndist = 0, MovementType = 2 WHERE guid = 57680;
SET @NPC := 57680;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 9651.68, -7070.56, 14.3104,10000),
(@PATH, 2, 9650.83, -7073.55, 14.3112,0),
(@PATH, 3, 9649.54, -7070.92, 14.3095,0),
(@PATH, 4, 9648.21, -7071.54, 14.3092,10000),
(@PATH, 5, 9651.68, -7070.56, 14.3104,0),
(@PATH, 6, 9651.68, -7070.56, 14.3104,5000);

-- Rahein <Blade Vendor>
DELETE FROM `waypoints` WHERE `entry`=16678;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES 
(16678, 1, 9630.69, -7032.97, 15.2687),
(16678, 2, 9636.05, -7031.66, 15.2674),
(16678, 3, 9630.66, -7032.19, 15.2674),
(16678, 4, 9627.83, -7031.5, 15.2674),
(16678, 5, 9630.69, -7032.97, 15.2687),
(16678, 6, 9630.69, -7032.97, 15.2687);

-- Rahein SAI
SET @ENTRY := 16678;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,16678,1,0,0,0,1,0,0,0,0,0,0,0,"Rahein - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,4,16678,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rahein - On Waypoint 4 Reached - Run Script"),
(@ENTRY,0,2,0,64,0,100,0,0,0,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rahein - On Gossip Hello - Pause Waypoint");

-- Actionlist SAI
SET @ENTRY := 1667800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,40000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 69"),
(@ENTRY,9,2,0,0,0,100,0,35000,35000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 0");

-- Feledis <Axe Vendor>
DELETE FROM `waypoints` WHERE `entry`=16666;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES 
(16666, 1, 9644.87, -7037.51, 15.2466),
(16666, 2, 9649.12, -7037.71, 15.247),
(16666, 3, 9649.12, -7037.71, 15.247),
(16666, 4, 9649.84, -7036.01, 15.2545),
(16666, 5, 9650.34, -7034.34, 15.2614),
(16666, 6, 9647.34, -7032.51, 15.2673),
(16666, 7, 9647.34, -7032.51, 15.2673),
(16666, 8, 9644.26, -7032.12, 15.2673),
(16666, 9, 9643.18, -7034.19, 15.2648),
(16666, 10, 9643.12, -7036.25, 15.254),
(16666, 11, 9644.87, -7037.51, 15.2466),
(16666, 12, 9644.87, -7037.51, 15.2466);

-- Feledis SAI
SET @ENTRY := 16666;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,16666,1,0,0,0,1,0,0,0,0,0,0,0,"Feledis - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,4,16666,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feledis - On Waypoint 4 Reached - Run Script"),
(@ENTRY,0,2,0,64,0,100,0,0,0,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feledis - On Gossip Hello - Pause Waypoint");

-- Actionlist SAI
SET @ENTRY := 1666600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,45000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 69"),
(@ENTRY,9,2,0,0,0,100,0,41000,41000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 0");
