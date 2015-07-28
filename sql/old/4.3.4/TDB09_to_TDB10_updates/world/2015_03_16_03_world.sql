-- 
-- Shade of the Spiritspeaker SAI
SET @ENTRY := 48678;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2000,2000,1500,1500,11,90700,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Spiritspeaker - Out of Combat - Cast 'Summon Arcane Sphere'"),
(@ENTRY,0,1,0,0,0,100,0,2000,5000,5000,5000,11,85424,2,0,0,0,0,2,0,0,0,0,0,0,0,"Shade of the Spiritspeaker - In Combat - Cast 'Spirit Burst'");

DELETE FROM `creature_template_addon` WHERE `entry`=48681;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(48681,0,0,33554432,1,0,'90698');

-- Arcane Roller SAI
SET @ENTRY := 48681;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,87,@ENTRY*100+00,@ENTRY*100+01,@ENTRY*100+02,0,0,0,1,0,0,0,0,0,0,0,"Arcane Roller - On Just Summoned - Run Random Script"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcane Roller - On Aggro - Despawn Instant");

-- Actionlist SAI
SET @ENTRY := 4868100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,100,100,0,0,53,1,4868100,0,0,1000,0,1,0,0,0,0,0,0,0,"On Script - Start Waypoint");

-- Actionlist SAI
SET @ENTRY := 4868101;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,100,100,0,0,53,1,4868101,0,0,1000,0,1,0,0,0,0,0,0,0,"On Script - Start Waypoint");

-- Actionlist SAI
SET @ENTRY := 4868102;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,100,100,0,0,53,1,4868102,0,0,1000,0,1,0,0,0,0,0,0,0,"On Script - Start Waypoint");

UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=48681;
UPDATE `creature_template` SET `speed_walk`=2.5, `speed_run`=2.5 WHERE  `entry`=48681;

DELETE FROM `waypoints` WHERE `entry`=4868101;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(4868101, 1, 6195.35, -4111.85, 744.147, 'Arcane Roller'),
(4868101, 2, 6203.05, -4111.92, 741.04, 'Arcane Roller'),
(4868101, 3, 6212.6, -4112.66, 735.066, 'Arcane Roller'),
(4868101, 4, 6228.86, -4114.14, 723.562, 'Arcane Roller'),
(4868101, 5, 6240.95, -4113.68, 721.984, 'Arcane Roller'),
(4868101, 6, 6247.91, -4112.89, 721.482, 'Arcane Roller'),
(4868101, 7, 6261.13, -4110.28, 718.787, 'Arcane Roller'),
(4868101, 8, 6274.36, -4103.5, 715.604, 'Arcane Roller'),
(4868101, 9, 6285.37, -4086.53, 710.668, 'Arcane Roller'),
(4868101, 10, 6293.89, -4064.3, 703.658, 'Arcane Roller'),
(4868101, 11, 6303.82, -4052.11, 701.461, 'Arcane Roller'),
(4868101, 12, 6315.01, -4049.11, 698.762, 'Arcane Roller'),
(4868101, 13, 6331.43, -4046.85, 697.436, 'Arcane Roller'),
(4868101, 14, 6354.13, -4042.56, 694.022, 'Arcane Roller'),
(4868101, 15, 6360.85, -4041.71, 686.905, 'Arcane Roller'),
(4868101, 16, 6378.82, -4041.17, 664.861, 'Arcane Roller');

DELETE FROM `waypoints` WHERE `entry`=4868100;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(4868100, 1, 6196.32, -4105.12, 744.028, 'Arcane Roller'),
(4868100, 2, 6206.79, -4105.92, 739.795, 'Arcane Roller'),
(4868100, 3, 6217.26, -4106.65, 732.59, 'Arcane Roller'),
(4868100, 4, 6229.98, -4107.5, 723.776, 'Arcane Roller'),
(4868100, 5, 6241.76, -4107.84, 722.284, 'Arcane Roller'),
(4868100, 6, 6251.8, -4107.76, 721.797, 'Arcane Roller'),
(4868100, 7, 6265.56, -4100.52, 716.464, 'Arcane Roller'),
(4868100, 8, 6272.71, -4094.95, 713.936, 'Arcane Roller'),
(4868100, 9, 6277.71, -4084.69, 711.392, 'Arcane Roller'),
(4868100, 10, 6282.68, -4072.6, 708.661, 'Arcane Roller'),
(4868100, 11, 6290.79, -4054.63, 704.589, 'Arcane Roller'),
(4868100, 12, 6298.65, -4047.94, 703.035, 'Arcane Roller'),
(4868100, 13, 6310.25, -4044.52, 699.736, 'Arcane Roller'),
(4868100, 14, 6323.37, -4041.15, 697.811, 'Arcane Roller'),
(4868100, 15, 6345.7, -4034.72, 695.33, 'Arcane Roller'),
(4868100, 16, 6355.44, -4032.31, 690.346, 'Arcane Roller'),
(4868100, 17, 6377.85, -4026.08, 664.858, 'Arcane Roller');

DELETE FROM `waypoints` WHERE `entry`=4868102;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(4868102, 1, 6195.2, -4118.27, 743.577, 'Arcane Roller'),
(4868102, 2, 6202.19, -4118.49, 740.402, 'Arcane Roller'),
(4868102, 3, 6214.4, -4120.41, 732.631, 'Arcane Roller'),
(4868102, 4, 6229.96, -4123.08, 723.281, 'Arcane Roller'),
(4868102, 5, 6241.04, -4121.34, 721.329, 'Arcane Roller'),
(4868102, 6, 6254.89, -4119.31, 720.073, 'Arcane Roller'),
(4868102, 7, 6275.18, -4112.21, 716.654, 'Arcane Roller'),
(4868102, 8, 6286.03, -4103.33, 714.633, 'Arcane Roller'),
(4868102, 9, 6296.62, -4080.74, 706.334, 'Arcane Roller'),
(4868102, 10, 6313.36, -4054.73, 698.949, 'Arcane Roller'),
(4868102, 11, 6344.67, -4053.76, 695.791, 'Arcane Roller'),
(4868102, 12, 6353.26, -4052.85, 693.859, 'Arcane Roller'),
(4868102, 13, 6389.22, -4047.54, 658.284, 'Arcane Roller');
