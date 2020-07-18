-- Sunstrider Isle - Updates
-- Feral Dragonhawk Hatchling
UPDATE `creature` SET `position_x` = 9313.291992, `position_y` = -7065.535156, `position_z` = 13.551550, `spawndist` = 10, `MovementType` = 1 WHERE `guid` = 55751;
UPDATE `creature` SET `position_x` = 9335.414063, `position_y` = -7095.564941, `position_z` = 15.955358, `spawndist` = 10, `MovementType` = 1 WHERE `guid` = 55750;
UPDATE `creature` SET `position_x` = 9241.479492, `position_y` = -7053.126465, `position_z` = 11.785850, `spawndist` = 10, `MovementType` = 1 WHERE `guid` = 55781;
UPDATE `creature` SET `position_x` = 9251.087891, `position_y` = -7116.528320, `position_z` = 20.209023, `spawndist` = 10, `MovementType` = 1 WHERE `guid` = 55782;
UPDATE `creature` SET `position_x` = 9280.127930, `position_y` = -7136.915039, `position_z` = 18.425961, `spawndist` = 10, `MovementType` = 1 WHERE `guid` = 55806;
UPDATE `creature` SET `position_x` = 9286.713867, `position_y` = -7275.848633, `position_z` = 17.298273, `spawndist` = 10, `MovementType` = 1 WHERE `guid` = 55747;
UPDATE `creature` SET `position_x` = 9193.906250, `position_y` = -7090.962891, `position_z` = 19.812313, `spawndist` = 10, `MovementType` = 1 WHERE `guid` = 55804;
UPDATE `creature` SET `position_x` = 9143.990234, `position_y` = -7090.308594, `position_z` = 24.407694, `spawndist` = 10, `MovementType` = 1 WHERE `guid` = 55818;
UPDATE `creature` SET `position_x` = 9144.131836, `position_y` = -6652.943359, `position_z` = 31.736256, `spawndist` = 10, `MovementType` = 1 WHERE `guid` = 55763;
UPDATE `creature` SET `position_x` = 9195.083008, `position_y` = -6625.637695, `position_z` = 34.585335, `spawndist` = 10, `MovementType` = 1 WHERE `guid` = 55799;
UPDATE `creature` SET `position_x` = 9273.759766, `position_y` = -6798.623535, `position_z` = 22.505522, `spawndist` = 10, `MovementType` = 1 WHERE `guid` = 55778;
UPDATE `creature` SET `spawndist` = 10, `MovementType` = 1 WHERE `guid` = 55771;

-- Silvermoon Guardian #1
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `guid` = 56871;
-- Silvermoon Guardian #2
UPDATE `creature` SET `position_x` = 9310.937500, `position_y` = -7261.342285, `position_z` = 13.262838, `orientation` = 5.123657 WHERE `guid` = 56870;
SET @NPC := 56870;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`) VALUES
(@PATH, 1, 9313.76, -7233.52, 14.3607, 0),
(@PATH, 2, 9321.56, -7210.41, 14.9568, 0),
(@PATH, 3, 9324.87, -7190.41, 15.5912, 0),
(@PATH, 4, 9322.9, -7169.13, 15.6939, 0),
(@PATH, 5, 9315.66, -7141.71, 16.3783, 0),
(@PATH, 6, 9308.27, -7128.08, 16.3927, 0),
(@PATH, 7, 9288.27, -7098.95, 15.0777, 0),
(@PATH, 8, 9282.51, -7083.99, 12.7755, 0),
(@PATH, 9, 9283.83, -7072.6, 11.6658, 0),
(@PATH, 10, 9279.03, -7084.2, 12.8351, 0),
(@PATH, 11, 9285.3, -7100.68, 15.1796, 0),
(@PATH, 12, 9305.98, -7130.13, 16.3521, 0),
(@PATH, 13, 9313.23, -7142.95, 16.3343, 0),
(@PATH, 14, 9320.03, -7170.39, 15.744, 0),
(@PATH, 15, 9321.99, -7191.2, 15.5395, 0),
(@PATH, 16, 9318.65, -7209.67, 15.0213, 0),
(@PATH, 17, 9311.12, -7233.62, 14.4968, 0),
(@PATH, 18, 9310.98, -7261.15, 13.2516, 180000);

DELETE FROM `creature_formations` WHERE `leaderGUID`=56870;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(56870, 56870, 0, 0, 2, 0, 0),
(56870, 56871, 2, 90, 2, 0, 0);

-- Rotlimb Cannibal
UPDATE `creature_template` SET `inhabittype` = 1 WHERE `entry` = 15655;
UPDATE `creature` SET `position_x` = 9134.863281, `position_y` = -6999.031250, `position_z` = 9.883224, `spawndist` = 10, `MovementType` = 1 WHERE `guid` = 56080;

-- Springpaw panther
UPDATE `creature` SET `position_x` = 9337.779297, `position_y` = -6581.497070, `position_z` = 40.059837, `spawndist` = 10, `MovementType` = 1 WHERE `guid` = 55923;

-- Solanin <Bag Vandor>
UPDATE `creature` SET `position_x` = 9308.556641, `position_y` = -6554.437500, `position_z` = 34.680603, `orientation` = 2.170510, `Spawndist` = 0, `MovementType` = 0 WHERE `guid` = 68009;

DELETE FROM `waypoints` WHERE `entry`=18947;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(18947, 1, 9308.56, -6554.44, 34.6806, 'Solanin'),
(18947, 2, 9308.9, -6549.6, 34.6871, 'Solanin'),
(18947, 3, 9310.42, -6547.2, 34.6966, 'Solanin'),
(18947, 4, 9312.12, -6546.47, 35.6365, 'Solanin'),
(18947, 5, 9309.84, -6546.45, 34.6963, 'Solanin'),
(18947, 6, 9306.75, -6544.39, 34.6448, 'Solanin'),
(18947, 7, 9304.57, -6542.03, 34.7358, 'Solanin'),
(18947, 8, 9300.32, -6553.67, 34.604, 'Solanin'),
(18947, 9, 9302.13, -6550.81, 34.623, 'Solanin'),
(18947, 10, 9305.58, -6548.93, 34.6424, 'Solanin'),
(18947, 11, 9311.03, -6549.56, 34.7268, 'Solanin'),
(18947, 12, 9308.56, -6554.44, 34.6806, 'Solanin'),
(18947, 13, 9308.56, -6554.44, 34.6806, 'Solanin');

-- Solanin SAI
SET @ENTRY := 18947;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,18947,1,0,0,0,1,0,0,0,0,0,0,0,"Solanin - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,1,18947,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solanin - On Waypoint 1 Reached - Pause Waypoint"),
(@ENTRY,0,2,3,40,0,100,0,4,18947,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solanin - On Waypoint 4 Reached - Pause Waypoint"),
(@ENTRY,0,3,0,61,0,100,0,4,18947,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solanin - On Waypoint 4 Reached - Run Script"),
(@ENTRY,0,4,5,40,0,100,0,7,18947,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solanin - On Waypoint 7 Reached - Pause Waypoint"),
(@ENTRY,0,5,0,61,0,100,0,7,18947,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solanin - On Waypoint 7 Reached - Run Script"),
(@ENTRY,0,6,0,40,0,100,0,8,18947,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solanin - On Waypoint 8 Reached - Pause Waypoint"),
(@ENTRY,0,7,8,40,0,100,0,11,18947,0,0,54,14000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solanin - On Waypoint 11 Reached - Pause Waypoint"),
(@ENTRY,0,8,0,61,0,100,0,11,18947,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solanin - On Waypoint 11 Reached - Run Script"),
(@ENTRY,0,9,0,40,0,100,0,13,18947,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solanin - On Waypoint 13 Reached - Pause Waypoint");

-- Actionlist SAI
SET @ENTRY := 1894700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,3000,3000,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 16");

-- Actionlist SAI
SET @ENTRY := 1894701;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.19456,"On Script - Set Orientation 3,19456"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 1");

DELETE FROM `creature_text` WHERE `entry`=18947;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(18947, 0, 0, 'Gah! Every time I load something into the wagon, it reappears here within moments!', 12, 0, 100, 6, 0, 0, 16099, 'Solanin'), 
(18947, 1, 0, 'I should have better than to have given Silanna that tome of cantrips.', 12, 0, 100, 1, 0, 0, 16100, 'Solanin');
