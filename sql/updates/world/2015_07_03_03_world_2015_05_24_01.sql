-- Ammo for Rumbleshot
UPDATE `creature` SET position_x = -6070.349121, position_y = -285.940399, position_z = 428.220367, orientation = 1.496177 WHERE guid = 263;
UPDATE `creature` SET position_x = -6104.470703, position_y = -163.987122, position_z = 433.257080, orientation = 1.833880 WHERE guid = 1716;
UPDATE `creature` SET position_x = -5988.834473, position_y = -135.639069, position_z = 400.818604, orientation = 4.441411 WHERE guid = 290;
-- Mortar Combat - event
-- correct spawn possition for all involved in event
UPDATE `creature` SET position_x = -6009.25, position_y = -202.649994, position_z = 406.982605, orientation = 1.58825 WHERE guid = 269; -- angus
UPDATE `creature` SET orientation = 0.03490658 WHERE guid = 265 ; -- hegnar
UPDATE `creature` SET position_x = -6007.301758, position_y = -200.348206, position_z = 406.777496, orientation = 3.282219 WHERE guid = 272; -- klemmy
UPDATE `creature` SET position_x = -6007.458984, position_y = -202.157593, position_z = 407.447937, orientation = 2.478368 WHERE guid = 267; -- shorty
UPDATE `creature` SET position_x = -6010.668151495, position_y = -199.434006, position_z = 406.792480, orientation = 5.532694 WHERE guid = 268; -- middlecamp
UPDATE `creature` SET position_x = -6008.527832, position_y = -199.145203, position_z = 406.687225, orientation = 4.372177 WHERE guid = 266; -- wheeler

DELETE FROM `waypoints` WHERE `entry`=10610;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(10610, 1, -6009.25,-202.649994,406.982605, 'Angus'),
(10610, 2, -6009.25,-202.649994,406.982605, 'Angus'),
(10610, 3, -6009.25,-202.649994,406.982605, 'Angus'),
(10610, 4, -6031.16,-230.264,414.361, 'Angus');

DELETE FROM `spell_target_position` WHERE id IN (18634,16572,16767,16768,16772,16775,16776,16777,16778,16779,16780,16786,18634);
INSERT INTO `spell_target_position` (id, target_map, target_position_x, target_position_y, target_position_z, target_orientation) VALUES 
(16572,0,-6046.85,-207.329,418.304,0),
(16767,0,-6046.73,-207.159,417.267,0),
(16768,0,-6051.39,-206.749,418.159,0),
(16772,0,-6046.84,-204.535,416.897,0),
(16775,0,-6044.47,-205.783,417.267,0),
(16776,0,-6044.54,-205.562,417.663,0),
(16777,0,-6044.53,-202.912,416.756,0),
(16778,0,-6042.18,-204.949,416.336,0),
(16779,0,-6042.02,-204.134,416.894,0),
(16780,0,-6044.79,-196.959,419.19,0),
(16786,0,-6078.3,-211.89,424.197,0),
(18634,0,-6076,-215,424,0);

-- Hegnar Rumbleshot SAI
SET @ENTRY := 1243;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,20,0,100,0,5541,0,0,0,45,1,0,0,0,0,0,19,10610,20,0,0,0,0,0,"Hegnar Rumbleshot - On Quest 'Ammo for Rumbleshot' Finished - Set Data 1 0"),
(@ENTRY,0,1,2,61,0,100,0,5541,0,0,0,45,1,0,0,0,0,0,19,10611,20,0,0,0,0,0,"Hegnar Rumbleshot - On Quest 'Ammo for Rumbleshot' Finished - Set Data 1 0"),
(@ENTRY,0,2,3,61,0,100,0,5541,0,0,0,45,1,0,0,0,0,0,19,10804,20,0,0,0,0,0,"Hegnar Rumbleshot - On Quest 'Ammo for Rumbleshot' Finished - Set Data 1 0"),
(@ENTRY,0,3,4,61,0,100,0,5541,0,0,0,45,1,0,0,0,0,0,19,10805,20,0,0,0,0,0,"Hegnar Rumbleshot - On Quest 'Ammo for Rumbleshot' Finished - Set Data 1 0"),
(@ENTRY,0,4,0,61,0,100,0,5541,0,0,0,45,1,0,0,0,0,0,19,10803,20,0,0,0,0,0,"Hegnar Rumbleshot - On Quest 'Ammo for Rumbleshot' Finished - Set Data 1 0"),
(@ENTRY,0,5,0,38,0,100,0,2,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.68522,"Hegnar Rumbleshot - On Data Set 2 0 - Set Orientation 3,68522"),
(@ENTRY,0,6,0,38,0,100,0,3,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.03490658,"Hegnar Rumbleshot - On Data Set 3 0 - Set Orientation 0.03490658");

-- Angus SAI
SET @ENTRY := 10610;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,38,0,100,0,1,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angus - On Data Set 1 0 - Set Active On"),
(@ENTRY,0,1,2,61,0,100,0,1,0,0,0,53,0,10610,0,0,0,0,1,0,0,0,0,0,0,0,"Angus - On Data Set 1 0 - Start Waypoint"),
(@ENTRY,0,2,0,61,0,100,0,1,0,0,0,4,6598,0,0,0,0,0,21,50,0,0,0,0,0,0,"Angus - On Data Set 1 0 - Play Sound 6598"),
(@ENTRY,0,3,4,40,0,100,0,4,10610,0,0,54,250000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angus - On Waypoint 4 Reached - Pause Waypoint"),
(@ENTRY,0,4,0,61,0,100,0,4,10610,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angus - On Waypoint 4 Reached - Run Script"),
(@ENTRY,0,5,0,38,0,100,0,2,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6009.25,-202.649994,406.982605,2,"Shorty - On Data Set 2 0 - Move To Position"),
(@ENTRY,0,6,0,38,0,100,0,3,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.58825,"Shorty - On Data Set 3 0 - Set Orientation 1.58825");

-- Mortar Team Target Dummy SAI
SET @ENTRY := 11875;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,100,100,0,0,75,42716,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mortar Team Target Dummy - Out of Combat - Add Aura 'Self Root Forever (No Visual)' (No Repeat)");

-- move to eventplace
-- Shorty SAI
SET @ENTRY := 10611;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,38,0,100,0,1,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6031.589,-228.182,414.4035,2,"Shorty - On Data Set 1 0 - Move To Position"),
(@ENTRY,0,1,0,61,0,100,0,1,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shorty - On Data Set 1 0 - Set Active On"),
(@ENTRY,0,2,0,38,0,100,0,2,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.18492,"Shorty - On Data Set 2 0 - Set Orientation 2,18492"),
(@ENTRY,0,3,0,38,0,100,0,3,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.844887,"Shorty - On Data Set 3 0 - Set Orientation 2.844887"),
(@ENTRY,0,4,0,38,0,100,0,4,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.54215,"Shorty - On Data Set 4 0 - Set Orientation 4.54215"),
(@ENTRY,0,5,0,38,0,100,0,5,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.844887,"Shorty - On Data Set 4 0 - Set Orientation 2.844887"),
(@ENTRY,0,6,0,38,0,100,0,6,0,0,0,11,18655,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shorty - On Data Set 6 0 - Cast 'Mortar Animate'"),
(@ENTRY,0,7,0,38,0,100,0,7,0,0,0,11,16786,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shorty - On Data Set 7 0 - Cast 'Mortar Shot'"),
(@ENTRY,0,8,0,38,0,100,0,8,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.54215,"Shorty - On Data Set 8 0 - Set Orientation 4.54215"),
(@ENTRY,0,9,0,38,0,100,0,9,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.54215,"Shorty - On Data Set 9 0 - Set Orientation 4.54215"),
(@ENTRY,0,10,0,38,0,100,0,10,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.844887,"Shorty - On Data Set 10 0 - Set Orientation 2.844887"),
(@ENTRY,0,11,0,38,0,100,0,11,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6007.458984,-202.157593,407.447937,2,"Shorty - On Data Set 11 0 - Move To Position"),
(@ENTRY,0,12,0,38,0,100,0,12,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.478368,"Shorty - On Data Set 12 0 - Set Orientation 2.478368");

-- Klemmy SAI
SET @ENTRY := 10805;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,38,0,100,0,1,0,0,0,53,0,10805,0,0,0,0,1,0,0,0,0,0,0,0,"Klemmy - On Data Set 1 0 - Start Waypoint"),
(@ENTRY,0,1,0,61,0,100,0,1,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Klemmy - On Data Set 1 0 - Set Active On"),
(@ENTRY,0,2,0,38,0,100,0,2,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.59936,"Spotter Klemmy - On Data Set 2 0 - Set Orientation 5,59936"),
(@ENTRY,0,3,0,38,0,100,0,3,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6077.43,-213.2565,424.0502,5.59936,"Spotter Klemmy - On Data Set 3 0 - Move To Position"),
(@ENTRY,0,4,0,38,0,100,0,4,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6065.903,-202.2976,424.3693,5,"Spotter Klemmy - On Data Set 4 0 - Move To Position"),
(@ENTRY,0,5,0,38,0,100,0,5,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.59936,"Spotter Klemmy - On Data Set 5 0 - Set Orientation 5.59936"),
(@ENTRY,0,6,0,38,0,100,0,6,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.0985,"Spotter Klemmy - On Data Set 6 0 - Set Orientation 4.0985"),
(@ENTRY,0,7,0,38,0,100,0,7,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.0985,"Spotter Klemmy - On Data Set 7 0 - Set Orientation 4.0985"),
(@ENTRY,0,8,0,38,0,100,0,8,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6077.43,-213.2565,424.0502,5.59936,"Spotter Klemmy - On Data Set 8 0 - Move To Position"),
(@ENTRY,0,9,0,38,0,100,0,9,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.844887,"Spotter Klemmy - On Data Set 9 0 - Set Orientation 2.844887"),
(@ENTRY,0,10,0,38,0,100,0,10,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6071.88,-212.831,422.929,5,"Spotter Klemmy - On Data Set 10 0 - Move To Position"),
(@ENTRY,0,11,0,38,0,100,0,11,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,6.04228,"Spotter Klemmy - On Data Set 11 0 - Set Orientation 6.04228"),
(@ENTRY,0,12,0,38,0,100,0,12,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6065.903,-202.2976,424.3693,5,"Spotter Klemmy - On Data Set 12 0 - Move To Position"),
(@ENTRY,0,13,0,38,0,100,0,13,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.0985,"Spotter Klemmy - On Data Set 13 0 - Set Orientation 4.0985"),
(@ENTRY,0,14,0,38,0,100,0,14,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6064.07,-209.851,421.98,6.10275,"Spotter Klemmy - On Data Set 14 0 - Move To Position"),
(@ENTRY,0,15,0,38,0,100,0,15,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6061.97,-218.956,421.085,5.92054,"Spotter Klemmy - On Data Set 15 0 - Move To Position"),
(@ENTRY,0,16,0,38,0,100,0,16,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6040.96,-221.929,414.921,5.92054,"Spotter Klemmy - On Data Set 16 0 - Move To Position"),
(@ENTRY,0,17,0,38,0,100,0,17,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6007.301758,-200.348206,406.777496,3.282219,"Spotter Klemmy - On Data Set 17 0 - Move To Position"),
(@ENTRY,0,18,0,38,0,100,0,18,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.282219,"Spotter Klemmy - On Data Set 18 0 - Set Orientation 3.282219");

-- Wheeler SAI
SET @ENTRY := 10803;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,38,0,100,0,1,0,0,0,53,0,10803,0,0,0,0,1,0,0,0,0,0,0,0,"Wheeler - On Data Set 1 0 - Start Waypoint"),
(@ENTRY,0,1,0,61,0,100,0,1,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wheeler - On Data Set 1 0 - Set Active On"),
(@ENTRY,0,2,0,38,0,100,0,2,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.443461,"Wheeler - On Data Set 2 0 - Set Orientation 2,443461"),
(@ENTRY,0,3,0,38,0,100,0,3,0,0,0,11,16767,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wheeler - On Data Set 3 0 - Cast 'Shoot'"),
(@ENTRY,0,4,0,38,0,100,0,4,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.00565,"Wheeler - On Data Set 4 0 - Set Orientation 4.00565"),
(@ENTRY,0,5,0,38,0,100,0,5,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.443461,"Wheeler - On Data Set 5 0 - Set Orientation 2.443461"),
(@ENTRY,0,6,0,38,0,100,0,6,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.00565,"Wheeler - On Data Set 6 0 - Set Orientation 4.00565"),
(@ENTRY,0,7,0,38,0,100,0,7,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.443461,"Wheeler - On Data Set 7 0 - Set Orientation 2.443461"),
(@ENTRY,0,8,0,38,0,100,0,8,0,0,0,11,16775,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wheeler - On Data Set 8 0 - Cast 'Shoot'"),
(@ENTRY,0,9,0,38,0,100,0,9,0,0,0,11,16778,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wheeler - On Data Set 9 0 - Cast 'Shoot'"),
(@ENTRY,0,10,0,38,0,100,0,10,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.00565,"Wheeler - On Data Set 10 0 - Set Orientation 4.00565"),
(@ENTRY,0,11,0,38,0,100,0,11,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.443461,"Wheeler - On Data Set 11 0 - Set Orientation 4.00565"),
(@ENTRY,0,12,0,38,0,100,0,12,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.00565,"Wheeler - On Data Set 12 0 - Set Orientation 4.00565"),
(@ENTRY,0,13,0,38,0,100,0,13,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.77803,"Wheeler - On Data Set 13 0 - Set Orientation 4.77803"),
(@ENTRY,0,14,0,38,0,100,0,14,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.01942,"Wheeler - On Data Set 14 0 - Set Orientation 3.01942"),
(@ENTRY,0,15,0,38,0,100,0,15,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6008.527832,-199.145203,406.687225,4.372177,"Wheeler - On Data Set 15 0 - Move To Position"),
(@ENTRY,0,16,0,38,0,100,0,16,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.372177,"Wheeler - On Data Set 16 0 - Set Orientation 4.372177");

-- Rifleman Middlecamp SAI
SET @ENTRY := 10804;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,38,0,100,0,1,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6034.14,-223.333,413.4,1,"Rifleman Middlecamp - On Data Set 1 0 - Move To Position"),
(@ENTRY,0,1,0,61,0,100,0,1,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rifleman Middlecamp - On Data Set 1 0 - Set Active On"),
(@ENTRY,0,2,0,38,0,100,0,2,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.884956,"Rifleman Middlecamp - On Data Set 2 0 - Set Orientation 1,884956"),
(@ENTRY,0,3,0,38,0,100,0,3,0,0,0,11,16768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rifleman Middlecamp - On Data Set 3 0 - Cast 'Shoot'"),
(@ENTRY,0,4,0,38,0,100,0,4,0,0,0,11,16772,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rifleman Middlecamp - On Data Set 4 0 - Cast 'Shoot'"),
(@ENTRY,0,5,0,38,0,100,0,5,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.810652,"Rifleman Middlecamp - On Data Set 5 0 - Set Orientation 0.810652"),
(@ENTRY,0,6,0,38,0,100,0,6,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.884956,"Rifleman Middlecamp - On Data Set 6 0 - Set Orientation 1.884956"),
(@ENTRY,0,7,0,38,0,100,0,7,0,0,0,11,16777,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rifleman Middlecamp - On Data Set 7 0 - Cast 'Shoot'"),
(@ENTRY,0,8,0,38,0,100,0,8,0,0,0,11,16780,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rifleman Middlecamp - On Data Set 8 0 - Cast 'Shoot'"),
(@ENTRY,0,9,0,38,0,100,0,9,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.810652,"Rifleman Middlecamp - On Data Set 9 0 - Set Orientation 0.810652"),
(@ENTRY,0,10,0,38,0,100,0,10,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.884956,"Rifleman Middlecamp - On Data Set 10 0 - Set Orientation 1.884956"),
(@ENTRY,0,11,0,38,0,100,0,11,0,0,0,11,16572,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rifleman Middlecamp - On Data Set 11 0 - Cast 'Shoot'"),
(@ENTRY,0,12,0,38,0,100,0,12,0,0,0,11,16776,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rifleman Middlecamp - On Data Set 12 0 - Cast 'Shoot'"),
(@ENTRY,0,13,0,38,0,100,0,13,0,0,0,11,16779,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rifleman Middlecamp - On Data Set 13 0 - Cast 'Shoot'"),
(@ENTRY,0,14,0,38,0,100,0,14,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.810652,"Rifleman Middlecamp - On Data Set 14 0 - Set Orientation 0.810652"),
(@ENTRY,0,15,0,38,0,100,0,15,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.13852,"Rifleman Middlecamp - On Data Set 15 0 - Set Orientation 5.13852"),
(@ENTRY,0,16,0,38,0,100,0,16,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.9147,"Rifleman Middlecamp - On Data Set 16 0 - Set Orientation 2.9147"),
(@ENTRY,0,17,1,38,0,100,0,17,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6010.668151495,-199.434006,406.792480,5.532694,"Rifleman Middlecamp - On Data Set 17 0 - Move To Position"),
(@ENTRY,0,18,0,38,0,100,0,18,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.532694,"Rifleman Middlecamp - On Data Set 18 0 - Set Orientation 5.532694");

DELETE FROM `waypoints` WHERE `entry`=10805;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(10805, 1, -6011.17,-197.021,406.765, 'Klemmy'),
(10805, 2, -6015.51,-184.362,407.712, 'Klemmy'),
(10805, 3, -6042.365723,-191.418701,421.045868, 'Klemmy'),
(10805, 4, -6065.18,-201.938,424.419, 'Klemmy');

DELETE FROM `waypoints` WHERE `entry`=10803;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(10803, 1, -6011.87,-199.241,406.834, 'Wheeler'),
(10803, 2, -6031.929,-221.0882,413.1531, 'Wheeler');

DELETE FROM `creature_text` WHERE `entry` IN (10804, 10803);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES 
(10804, 0, 0, '%s picks the orc target...', 16, 0, 100, 25, 0, 0, 'Middlecamp', 6107),
(10804, 1, 0, '%s misses...', 16, 0, 100, 6, 0, 0, 'Middlecamp', 6140),
(10804, 2, 0, '%s takes a more careful aim...', 16, 0, 100, 6, 0, 6247, 'Middlecamp', 6106),
(10804, 3, 0, '%s misses again...', 16, 0, 100, 6, 0, 0, 'Middlecamp', 6141),
(10804, 4, 0, '%s takes aim at the bottles...', 16, 0, 100, 0, 0, 0, 'Middlecamp', 6120),
(10804, 5, 0, '%s misses...', 16, 0, 100, 15, 0, 0, 'Middlecamp', 6140),
(10804, 6, 0, '%s takes aim at the bottles again...', 16, 0, 100, 0, 0, 0, 'Middlecamp', 6121),
(10804, 7, 0, '%s misses again...', 16, 0, 100, 18, 0, 0, 'Middlecamp', 6141),
(10804, 8, 0, '%s quickly shoots the orc dummy...', 16, 0, 100, 0, 0, 0, 'Middlecamp', 6137),
(10804, 9, 0, '%s turns to the paper target...', 16, 0, 100, 0, 0, 0, 'Middlecamp', 6136),
(10804, 10, 0, '%s shoots from the hip at the bottles...', 16, 0, 100, 0, 0, 0, 'Middlecamp', 6138),
-- 
(10803, 0, 0, '%s casually points at the orc target...', 16, 0, 100, 25, 0, 0, 'Wheeler', 6118),
(10803, 1, 0, '%s hits!', 16, 0, 100, 0, 0, 0, 'Wheeler', 6142),
(10803, 2, 0, '%s quickly shoots the middle target dead center...', 16, 0, 100, 0, 0, 0, 'Wheeler', 6124),
(10803, 3, 0, '%s then takes aim at the bottles...', 16, 0, 100, 0, 0, 0, 'Wheeler', 6122),
(10803, 4, 0, '%s only hits the side of the box!', 16, 0, 100, 0, 0, 0, 'Wheeler', 6123);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=18655;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 18655, 0, 0, 31, 0, 5, 176557, 0, 0, 0, 0, '', 'Mörser - Mörser');

-- Actionlist SAI
SET @ENTRY := 1061000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,45,2,0,0,0,0,0,19,10805,100,0,0,0,0,0,"On Script - Set Data 2 0"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,45,2,0,0,0,0,0,19,10611,100,0,0,0,0,0,"On Script - Set Data 2 0"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,45,2,0,0,0,0,0,19,10803,100,0,0,0,0,0,"On Script - Set Data 2 0"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,45,2,0,0,0,0,0,19,10804,100,0,0,0,0,0,"On Script - Set Data 2 0"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,45,2,0,0,0,0,0,19,1243,100,0,0,0,0,0,"On Script - Set Data 2 0"),
(@ENTRY,9,5,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,19,10804,100,0,0,0,0,0,"Angus - On Script - Say Line 0"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,45,3,0,0,0,0,0,19,10804,50,0,0,0,0,0,"Angus - On Script - Set Data 3 0"),
(@ENTRY,9,7,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,19,10804,100,0,0,0,0,0,"Angus - On Script - Say Line 1"),
(@ENTRY,9,8,0,0,0,100,0,4000,4000,0,0,1,2,0,0,0,0,0,19,10804,100,0,0,0,0,0,"Angus - On Script - Say Line 2"),
(@ENTRY,9,9,0,0,0,100,0,2000,2000,0,0,45,4,0,0,0,0,0,19,10804,50,0,0,0,0,0,"Angus - On Script - Set Data 4 0"),
(@ENTRY,9,10,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,19,10804,100,0,0,0,0,0,"Angus - On Script - Say Line 3"),
(@ENTRY,9,11,0,0,0,100,0,2000,2000,0,0,45,5,0,0,0,0,0,19,10804,50,0,0,0,0,0,"Angus - On Script - Set Data 5 0"),
(@ENTRY,9,12,0,0,0,100,0,1000,1000,0,0,5,5,0,0,0,0,0,19,10804,100,0,0,0,0,0,"Angus - On Script - Play Emote 5"),
(@ENTRY,9,13,0,0,0,100,0,1000,1000,0,0,5,11,0,0,0,0,0,19,10803,100,0,0,0,0,0,"Angus - On Script - Play Emote 11"),
(@ENTRY,9,14,0,0,0,100,0,1000,1000,0,0,5,274,0,0,0,0,0,19,10611,100,0,0,0,0,0,"Angus - On Script - Play Emote 11"),
(@ENTRY,9,15,0,0,0,100,0,0,0,0,0,5,274,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angus - On Script - Play Emote 11"),
(@ENTRY,9,16,0,0,0,100,0,1000,1000,0,0,45,6,0,0,0,0,0,19,10804,50,0,0,0,0,0,"Angus - On Script - Set Data 6 0"),
(@ENTRY,9,17,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,19,10803,100,0,0,0,0,0,"Angus - On Script - Say Line 0"),
(@ENTRY,9,18,0,0,0,100,0,4000,4000,0,0,45,3,0,0,0,0,0,19,10803,50,0,0,0,0,0,"Angus - On Script - Set Data 3 0"),
(@ENTRY,9,19,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,19,10803,100,0,0,0,0,0,"Angus - On Script - Say Line 1"),
(@ENTRY,9,20,0,0,0,100,0,2000,2000,0,0,45,4,0,0,0,0,0,19,10803,50,0,0,0,0,0,"Angus - On Script - Set Data 4 0"),
(@ENTRY,9,21,0,0,0,100,0,1000,1000,0,0,5,25,0,0,0,0,0,19,10803,50,0,0,0,0,0,"Angus - On Script - Play Emote 25"),
(@ENTRY,9,22,0,0,0,100,0,0,0,0,0,4,6249,0,0,0,0,0,21,100,0,0,0,0,0,0,"Angus - On Script - Play Sound 6249"),
(@ENTRY,9,23,0,0,0,100,0,2000,2000,0,0,5,21,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angus - On Script - Play Emote 21"),
(@ENTRY,9,24,0,0,0,100,0,1000,1000,0,0,5,21,0,0,0,0,0,19,10611,100,0,0,0,0,0,"Angus - On Script - Play Emote 21"),
(@ENTRY,9,25,0,0,0,100,0,0,0,0,0,5,23,0,0,0,0,0,19,10803,100,0,0,0,0,0,"Angus - On Script - Play Emote 23"),
(@ENTRY,9,26,0,0,0,100,0,2000,2000,0,0,45,5,0,0,0,0,0,19,10803,50,0,0,0,0,0,"Angus - On Script - Set Data 5 0 Wheeler"),
(@ENTRY,9,27,0,0,0,100,0,3000,3000,0,0,1,4,0,0,0,0,0,19,10804,100,0,0,0,0,0,"Angus - On Script - Say Line 4"),
(@ENTRY,9,28,0,0,0,100,0,2000,2000,0,0,45,7,0,0,0,0,0,19,10804,50,0,0,0,0,0,"Angus - On Script - Set Data 5 0 Middlecamp"),
(@ENTRY,9,29,0,0,0,100,0,2000,2000,0,0,1,5,0,0,0,0,0,19,10804,100,0,0,0,0,0,"Angus - On Script - Say Line 5 Middlecamp"),
(@ENTRY,9,30,0,0,0,100,0,2000,2000,0,0,5,20,0,0,0,0,0,19,10804,100,0,0,0,0,0,"Angus - On Script - Play Emote 20 Middlecamp"),
(@ENTRY,9,31,0,0,0,100,0,0,0,0,0,45,6,0,0,0,0,0,19,10803,50,0,0,0,0,0,"Angus - On Script - Set Data 6 0 Wheeler"),
(@ENTRY,9,32,0,0,0,100,0,1000,1000,0,0,5,6,0,0,0,0,0,19,10803,100,0,0,0,0,0,"Angus - On Script - Play Emote 6 Wheeler"),
(@ENTRY,9,33,0,0,0,100,0,0,0,0,0,4,6248,0,0,0,0,0,21,100,0,0,0,0,0,0,"Angus - On Script - Play Sound 6248"),
(@ENTRY,9,34,0,0,0,100,0,3000,3000,0,0,45,7,0,0,0,0,0,19,10803,50,0,0,0,0,0,"Angus - On Script - Set Data 6 0 Wheeler"),
(@ENTRY,9,35,0,0,0,100,0,0,0,0,0,1,6,0,0,0,0,0,19,10804,100,0,0,0,0,0,"Angus - On Script - Say Line 6 Middlecamp"),
(@ENTRY,9,36,0,0,0,100,0,1000,1000,0,0,45,8,0,0,0,0,0,19,10804,50,0,0,0,0,0,"Angus - On Script - Set Data 8 0 Middlecamp"),
(@ENTRY,9,38,0,0,0,100,0,0,0,0,0,1,7,0,0,0,0,0,19,10804,100,0,0,0,0,0,"Angus - On Script - Say Line 7 Middlecamp"),
(@ENTRY,9,40,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,19,10803,100,0,0,0,0,0,"Angus - On Script - Say Line 2 Wheeler"),
(@ENTRY,9,41,0,0,0,100,0,2000,2000,0,0,45,8,0,0,0,0,0,19,10803,50,0,0,0,0,0,"Angus - On Script - Set Data 8 0 Wheeler"),
(@ENTRY,9,42,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,19,10803,100,0,0,0,0,0,"Angus - On Script - Say Line 3 Wheeler"),
(@ENTRY,9,43,0,0,0,100,0,2000,2000,0,0,45,9,0,0,0,0,0,19,10803,50,0,0,0,0,0,"Angus - On Script - Set Data 9 0 Wheeler"),
(@ENTRY,9,44,0,0,0,100,0,2000,2000,0,0,1,4,0,0,0,0,0,19,10803,100,0,0,0,0,0,"Angus - On Script - Say Line 4 Wheeler"),
(@ENTRY,9,45,0,0,0,100,0,1000,1000,0,0,45,10,0,0,0,0,0,19,10803,50,0,0,0,0,0,"Angus - On Script - Set Data 10 0 Wheeler"),
(@ENTRY,9,46,0,0,0,100,0,1000,1000,0,0,5,5,0,0,0,0,0,19,10803,100,0,0,0,0,0,"Angus - On Script - Play Emote 5 Wheeler"),
(@ENTRY,9,47,0,0,0,100,0,0,0,0,0,45,9,0,0,0,0,0,19,10804,50,0,0,0,0,0,"Angus - On Script - Set Data 9 0 Middlecamp"),
(@ENTRY,9,48,0,0,0,100,0,2000,2000,0,0,5,25,0,0,0,0,0,19,10804,100,0,0,0,0,0,"Angus - On Script - Play Emote 25 Middlecamp"),
(@ENTRY,9,59,0,0,0,100,0,2000,2000,0,0,5,11,0,0,0,0,0,19,10804,100,0,0,0,0,0,"Angus - On Script - Play Emote 11 Middlecamp"),
(@ENTRY,9,60,0,0,0,100,0,3000,3000,0,0,45,10,0,0,0,0,0,19,10803,50,0,0,0,0,0,"Angus - On Script - Set Data 10 0 Middlecamp"),
(@ENTRY,9,61,0,0,0,100,0,0,0,0,0,45,11,0,0,0,0,0,19,10803,50,0,0,0,0,0,"Angus - On Script - Set Data 11 0 Wheeler"),
(@ENTRY,9,62,0,0,0,100,0,2000,2000,0,0,1,8,0,0,0,0,0,19,10804,100,0,0,0,0,0,"Angus - On Script - Say Line 8 Middlecamp"),
(@ENTRY,9,63,0,0,0,100,0,0,0,0,0,4,6250,0,0,0,0,0,21,100,0,0,0,0,0,0,"Angus - On Script - Play Sound 6250"),
(@ENTRY,9,64,0,0,0,100,0,0,0,0,0,45,11,0,0,0,0,0,19,10804,50,0,0,0,0,0,"Angus - On Script - Set Data 11 0 Middlecamp"),
(@ENTRY,9,65,0,0,0,100,0,3000,3000,0,0,1,9,0,0,0,0,0,19,10804,100,0,0,0,0,0,"Angus - On Script - Say Line 9 Middlecamp"),
(@ENTRY,9,66,0,0,0,100,0,0,0,0,0,4,6250,0,0,0,0,0,21,100,0,0,0,0,0,0,"Angus - On Script - Play Sound 6250"),
(@ENTRY,9,67,0,0,0,100,0,0,0,0,0,45,12,0,0,0,0,0,19,10804,50,0,0,0,0,0,"Angus - On Script - Set Data 12 0 Middlecamp"),
(@ENTRY,9,68,0,0,0,100,0,3000,3000,0,0,1,10,0,0,0,0,0,19,10804,100,0,0,0,0,0,"Angus - On Script - Say Line 10 Middlecamp"),
(@ENTRY,9,69,0,0,0,100,0,0,0,0,0,4,6250,0,0,0,0,0,21,100,0,0,0,0,0,0,"Angus - On Script - Play Sound 6250"),
(@ENTRY,9,70,0,0,0,100,0,0,0,0,0,45,13,0,0,0,0,0,19,10804,50,0,0,0,0,0,"Angus - On Script - Set Data 13 0 Middlecamp"),
(@ENTRY,9,71,0,0,0,100,0,0,0,0,0,5,71,0,0,0,0,0,19,10804,100,0,0,0,0,0,"Angus - On Script - Play Emote 71 Middlecamp"),
(@ENTRY,9,72,0,0,0,100,0,0,0,0,0,4,6246,0,0,0,0,0,21,100,0,0,0,0,0,0,"Angus - On Script - Play Sound 6246"),
(@ENTRY,9,73,0,0,0,100,0,3000,3000,0,0,45,14,0,0,0,0,0,19,10804,50,0,0,0,0,0,"Angus - On Script - Set Data 14 0 Middlecamp"),
(@ENTRY,9,74,0,0,0,100,0,1000,1000,0,0,45,12,0,0,0,0,0,19,10803,50,0,0,0,0,0,"Angus - On Script - Set Data 12 0 Wheeler"),
(@ENTRY,9,75,0,0,0,100,0,1000,1000,0,0,5,2,0,0,0,0,0,19,10804,100,0,0,0,0,0,"Angus - On Script - Play Emote 2 Middlecamp"),
(@ENTRY,9,76,0,0,0,100,0,0,0,0,0,5,21,0,0,0,0,0,19,10803,100,0,0,0,0,0,"Angus - On Script - Play Emote 21 Wheeler"),
(@ENTRY,9,77,0,0,0,100,0,4000,4000,0,0,45,15,0,0,0,0,0,19,10804,50,0,0,0,0,0,"Angus - On Script - Set Data 15 0 Middlecamp"),
(@ENTRY,9,78,0,0,0,100,0,0,0,0,0,45,13,0,0,0,0,0,19,10803,50,0,0,0,0,0,"Angus - On Script - Set Data 13 0 Wheeler"),
(@ENTRY,9,79,0,0,0,100,0,0,0,0,0,45,3,0,0,0,0,0,19,10611,50,0,0,0,0,0,"Angus - On Script - Set Data 3 0 Shorty"),
(@ENTRY,9,80,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.844887,"Angus - On Script - Set Orientation 2,844887"),
(@ENTRY,9,81,0,0,0,100,0,2000,2000,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angus - On Script - Play Emote 4 Wheeler"),
(@ENTRY,9,82,0,0,0,100,0,0,0,0,0,5,4,0,0,0,0,0,19,10611,100,0,0,0,0,0,"Angus - On Script - Play Emote 4 Shorty"),
(@ENTRY,9,83,0,0,0,100,0,0,0,0,0,4,6256,0,0,0,0,0,21,100,0,0,0,0,0,0,"Angus - On Script - Play Sound 6256"),
(@ENTRY,9,84,0,0,0,100,0,0,0,0,0,45,3,0,0,0,0,0,19,10805,100,0,0,0,0,0,"Angus - On Script - Set Data 3 0 Klemmy"),
(@ENTRY,9,85,0,0,0,100,0,10000,10000,0,0,11,18634,2,0,0,0,0,8,0,0,0,0,0,0,0,"Angus - On Script - Summon Creature 'Mortar Team Target Dummy'"),
(@ENTRY,9,86,0,0,0,100,0,3000,3000,0,0,45,4,0,0,0,0,0,19,10805,100,0,0,0,0,0,"Angus - On Script - Set Data 4 0 Klemmy"),
(@ENTRY,9,87,0,0,0,100,0,3000,3000,0,0,45,5,0,0,0,0,0,19,10805,100,0,0,0,0,0,"Angus - On Script - Set Data 5 0 Klemmy"),
(@ENTRY,9,88,0,0,0,100,0,2000,2000,0,0,5,3,0,0,0,0,0,19,10805,100,0,0,0,0,0,"Angus - On Script - Play Emote 3 Klemmy"),
(@ENTRY,9,89,0,0,0,100,0,0,0,0,0,45,4,0,0,0,0,0,19,10611,50,0,0,0,0,0,"Angus - On Script - Set Data 4 0 Shorty"),
(@ENTRY,9,90,0,0,0,100,0,1000,1000,0,0,45,6,0,0,0,0,0,19,10805,100,0,0,0,0,0,"Angus - On Script - Set Data 6 0 Klemmy"),
(@ENTRY,9,91,0,0,0,100,0,1000,1000,0,0,5,16,0,0,0,0,0,19,10611,100,0,0,0,0,0,"Angus - On Script - Play Emote 16 Shorty"),
(@ENTRY,9,92,0,0,0,100,0,1000,1000,0,0,5,69,0,0,0,0,0,19,10611,100,0,0,0,0,0,"Angus - On Script - Play Emote 69 Shorty"),
(@ENTRY,9,93,0,0,0,100,0,1000,1000,0,0,5,0,0,0,0,0,0,19,10611,100,0,0,0,0,0,"Angus - On Script - Play Emote 0 Shorty"),
(@ENTRY,9,94,0,0,0,100,0,2000,2000,0,0,45,5,0,0,0,0,0,19,10611,50,0,0,0,0,0,"Angus - On Script - Set Data 5 0 Shorty"),
(@ENTRY,9,95,0,0,0,100,0,1000,1000,0,0,45,16,0,0,0,0,0,19,10804,50,0,0,0,0,0,"Angus - On Script - Set Data 16 0 Middlecamp"),
(@ENTRY,9,96,0,0,0,100,0,0,0,0,0,45,14,0,0,0,0,0,19,10803,50,0,0,0,0,0,"Angus - On Script - Set Data 14 0 Wheeler"),
(@ENTRY,9,97,0,0,0,100,0,0,0,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angus - On Script - Play Emote 25"),
(@ENTRY,9,98,0,0,0,100,0,1000,1000,0,0,45,6,0,0,0,0,0,19,10611,50,0,0,0,0,0,"Angus - On Script - Set Data 6 0 Shorty"),
(@ENTRY,9,99,0,0,0,100,0,2000,2000,0,0,4,7316,0,0,0,0,0,21,100,0,0,0,0,0,0,"Angus - On Script - Play Sound 7316"),
(@ENTRY,9,100,0,0,0,100,0,2000,2000,0,0,45,7,0,0,0,0,0,19,10611,50,0,0,0,0,0,"Angus - On Script - Set Data 7 0 Shorty"),
(@ENTRY,9,101,0,0,0,100,0,0,0,0,0,51,0,0,0,0,0,0,19,11875,200,0,0,0,0,0,"On Script - Kill Target"),
(@ENTRY,9,102,0,0,0,100,0,3000,3000,0,0,5,17,0,0,0,0,0,19,10611,100,0,0,0,0,0,"Angus - On Script - Play Emote 17 Shorty"),
(@ENTRY,9,103,0,0,0,100,0,3000,3000,0,0,45,8,0,0,0,0,0,19,10611,50,0,0,0,0,0,"Angus - On Script - Set Data 8 0 Shorty"),
(@ENTRY,9,104,0,0,0,100,0,0,0,0,0,45,8,0,0,0,0,0,19,10805,100,0,0,0,0,0,"Angus - On Script - Set Data 8 0 Klemmy"),
(@ENTRY,9,105,0,0,0,100,0,0,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angus - On Script - Play Emote 1"),
(@ENTRY,9,106,0,0,0,100,0,0,0,0,0,4,6252,0,0,0,0,0,21,100,0,0,0,0,0,0,"Angus - On Script - Play Sound 6252"),
(@ENTRY,9,107,0,0,0,100,0,1000,1000,0,0,5,4,0,0,0,0,0,19,10611,100,0,0,0,0,0,"Angus - On Script - Play Emote 4 Shorty"),
(@ENTRY,9,108,0,0,0,100,0,3000,3000,0,0,45,9,0,0,0,0,0,19,10611,100,0,0,0,0,0,"Angus - On Script - Set Data 8 0 Shorty"),
(@ENTRY,9,109,0,0,0,100,0,5000,5000,0,0,11,18634,2,0,0,0,0,1,0,0,0,0,0,0,0,"Angus - On Script - Summon Creature 'Mortar Team Target Dummy'"),
(@ENTRY,9,110,0,0,0,100,0,2000,2000,0,0,45,10,0,0,0,0,0,19,10805,100,0,0,0,0,0,"Angus - On Script - Set Data 10 0 Klemmy"),
(@ENTRY,9,111,0,0,0,100,0,2000,2000,0,0,45,11,0,0,0,0,0,19,10805,100,0,0,0,0,0,"Angus - On Script - Set Data 11 0 Klemmy"),
(@ENTRY,9,112,0,0,0,100,0,2000,2000,0,0,5,66,0,0,0,0,0,19,10805,100,0,0,0,0,0,"Angus - On Script - Play Emote 66 Klemmy"),
(@ENTRY,9,113,0,0,0,100,0,3000,3000,0,0,45,9,0,0,0,0,0,19,10611,100,0,0,0,0,0,"Angus - On Script - Set Data 9 0 Shorty"),
(@ENTRY,9,114,0,0,0,100,0,2000,2000,0,0,45,12,0,0,0,0,0,19,10805,100,0,0,0,0,0,"Angus - On Script - Set Data 12 0 Klemmy"),
(@ENTRY,9,115,0,0,0,100,0,0,0,0,0,5,25,0,0,0,0,0,19,10611,100,0,0,0,0,0,"Angus - On Script - Play Emote 8 Shorty"),
(@ENTRY,9,116,0,0,0,100,0,2000,2000,0,0,4,6254,0,0,0,0,0,21,100,0,0,0,0,0,0,"Angus - On Script - Play Sound 6254"),
(@ENTRY,9,117,0,0,0,100,0,1000,1000,0,0,45,13,0,0,0,0,0,19,10805,100,0,0,0,0,0,"Angus - On Script - Set Data 13 0 Klemmy"),
(@ENTRY,9,118,0,0,0,100,0,3000,3000,0,0,17,0,0,0,0,0,0,19,10611,100,0,0,0,0,0,"Angus - On Script - Play Emote 0 Shorty"),
(@ENTRY,9,119,0,0,0,100,0,1000,1000,0,0,45,10,0,0,0,0,0,19,10611,100,0,0,0,0,0,"Angus - On Script - Set Data 10 0 Shorty"),
(@ENTRY,9,120,0,0,0,100,0,1000,1000,0,0,5,25,0,0,0,0,0,19,10611,100,0,0,0,0,0,"Angus - On Script - Play Emote 25 Shorty"),
(@ENTRY,9,121,0,0,0,100,0,0,0,0,0,4,6255,0,0,0,0,0,21,100,0,0,0,0,0,0,"Angus - On Script - Play Sound 6255"),
(@ENTRY,9,122,0,0,0,100,0,1000,1000,0,0,45,6,0,0,0,0,0,19,10611,50,0,0,0,0,0,"Angus - On Script - Set Data 6 0 Shorty"),
(@ENTRY,9,123,0,0,0,100,0,1000,1000,0,0,4,7316,0,0,0,0,0,21,100,0,0,0,0,0,0,"Angus - On Script - Play Sound 7316"),
(@ENTRY,9,124,0,0,0,100,0,1000,1000,0,0,45,7,0,0,0,0,0,19,10611,50,0,0,0,0,0,"Angus - On Script - Set Data 7 0 Shorty"),
(@ENTRY,9,125,0,0,0,100,0,0,0,0,0,51,0,0,0,0,0,0,19,11875,200,0,0,0,0,0,"On Script - Kill Target"),
(@ENTRY,9,126,0,0,0,100,0,1000,1000,0,0,45,9,0,0,0,0,0,19,10611,50,0,0,0,0,0,"Angus - On Script - Set Data 9 0 Shorty"),
(@ENTRY,9,127,0,0,0,100,0,2000,2000,0,0,5,25,0,0,0,0,0,19,10611,100,0,0,0,0,0,"Angus - On Script - Play Emote 25 Shorty"),
(@ENTRY,9,128,0,0,0,100,0,0,0,0,0,4,6251,0,0,0,0,0,21,100,0,0,0,0,0,0,"Angus - On Script - Play Sound 6251"),
(@ENTRY,9,129,0,0,0,100,0,1000,1000,0,0,45,15,0,0,0,0,0,19,10804,50,0,0,0,0,0,"Angus - On Script - Set Data 15 0 Middlecamp"),
(@ENTRY,9,130,0,0,0,100,0,0,0,0,0,45,8,0,0,0,0,0,19,10805,100,0,0,0,0,0,"Angus - On Script - Set Data 8 0 Klemmy"),
(@ENTRY,9,131,0,0,0,100,0,1000,1000,0,0,45,13,0,0,0,0,0,19,10803,100,0,0,0,0,0,"Angus - On Script - Set Data 13 0 Wheeler"),
(@ENTRY,9,132,0,0,0,100,0,1000,1000,0,0,45,10,0,0,0,0,0,19,10611,100,0,0,0,0,0,"Angus - On Script - Set Data 10 0 Shorty"),
(@ENTRY,9,133,0,0,0,100,0,0,0,0,0,5,4,0,0,0,0,0,19,10803,100,0,0,0,0,0,"Angus - On Script - Play Emote 4 Wheeler"),
(@ENTRY,9,134,0,0,0,100,0,7000,7000,0,0,11,18634,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angus - On Script - Summon Creature 'Mortar Team Target Dummy'"),
(@ENTRY,9,135,0,0,0,100,0,1000,1000,0,0,45,10,0,0,0,0,0,19,10805,100,0,0,0,0,0,"Angus - On Script - Set Data 10 0 Klemmy"),
(@ENTRY,9,136,0,0,0,100,0,1000,1000,0,0,45,11,0,0,0,0,0,19,10805,100,0,0,0,0,0,"Angus - On Script - Set Data 11 0 Klemmy"),
(@ENTRY,9,137,0,0,0,100,0,2000,2000,0,0,45,6,0,0,0,0,0,19,10611,50,0,0,0,0,0,"Angus - On Script - Set Data 6 0 Shorty"),
(@ENTRY,9,138,0,0,0,100,0,0,0,0,0,5,25,0,0,0,0,0,19,10805,100,0,0,0,0,0,"Angus - On Script - Play Emote 25 Klemmy"),
(@ENTRY,9,139,0,0,0,100,0,1000,1000,0,0,5,11,0,0,0,0,0,19,10805,100,0,0,0,0,0,"Angus - On Script - Play Emote 11 Klemmy"),
(@ENTRY,9,140,0,0,0,100,0,0,0,0,0,5,15,0,0,0,0,0,19,10611,100,0,0,0,0,0,"Angus - On Script - Play Emote 15 Shorty"),
(@ENTRY,9,141,0,0,0,100,0,0,0,0,0,5,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angus - On Script - Play Emote 5"),
(@ENTRY,9,142,0,0,0,100,0,0,0,0,0,4,6258,0,0,0,0,0,21,100,0,0,0,0,0,0,"Angus - On Script - Play Sound 6258"),
(@ENTRY,9,143,0,0,0,100,0,2000,2000,0,0,4,7316,0,0,0,0,0,21,100,0,0,0,0,0,0,"Angus - On Script - Play Sound 7316"),
(@ENTRY,9,144,0,0,0,100,0,1000,1000,0,0,45,16,0,0,0,0,0,19,10804,50,0,0,0,0,0,"Angus - On Script - Set Data 16 0 Middlecamp"),
(@ENTRY,9,145,0,0,0,100,0,1000,1000,0,0,45,14,0,0,0,0,0,19,10803,100,0,0,0,0,0,"Angus - On Script - Set Data 14 0 Wheeler"),
(@ENTRY,9,146,0,0,0,100,0,0,0,0,0,45,14,0,0,0,0,0,19,10805,100,0,0,0,0,0,"Angus - On Script - Set Data 14 0 Klemmy"),
(@ENTRY,9,147,0,0,0,100,0,1000,1000,0,0,45,7,0,0,0,0,0,19,10611,50,0,0,0,0,0,"Angus - On Script - Set Data 6 0 Shorty"),
(@ENTRY,9,148,0,0,0,100,0,0,0,0,0,51,0,0,0,0,0,0,19,11875,200,0,0,0,0,0,"On Script - Kill Target"),
(@ENTRY,9,149,0,0,0,100,0,1000,1000,0,0,5,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angus - On Script - Play Emote 10"),
(@ENTRY,9,150,0,0,0,100,0,0,0,0,0,5,10,0,0,0,0,0,19,10611,100,0,0,0,0,0,"Angus - On Script - Play Emote 10 Shorty"),
(@ENTRY,9,151,0,0,0,100,0,2000,2000,0,0,45,15,0,0,0,0,0,19,10805,100,0,0,0,0,0,"Angus - On Script - Set Data 15 0 Klemmy"),
(@ENTRY,9,152,0,0,0,100,0,3000,3000,0,0,45,16,0,0,0,0,0,19,10805,100,0,0,0,0,0,"Angus - On Script - Set Data 16 0 Klemmy"),
(@ENTRY,9,153,0,0,0,100,0,6000,6000,0,0,5,14,0,0,0,0,0,19,10805,100,0,0,0,0,0,"Angus - On Script - Play Emote 14 Klemmy"),
(@ENTRY,9,154,0,0,0,100,0,0,0,0,0,5,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angus - On Script - Play Emote 0"),
(@ENTRY,9,155,0,0,0,100,0,0,0,0,0,5,0,0,0,0,0,0,19,10611,100,0,0,0,0,0,"Angus - On Script - Play Emote 0 Shorty"),
(@ENTRY,9,156,0,0,0,100,0,0,0,0,0,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angus - On Script - Play Emote 11"),
(@ENTRY,9,157,0,0,0,100,0,0,0,0,0,5,11,0,0,0,0,0,19,10611,100,0,0,0,0,0,"Angus - On Script - Play Emote 11 Shorty"),
(@ENTRY,9,158,0,0,0,100,0,1000,1000,0,0,5,11,0,0,0,0,0,19,10804,100,0,0,0,0,0,"Angus - On Script - Play Emote 11 Middlecamp"),
(@ENTRY,9,159,0,0,0,100,0,0,0,0,0,5,11,0,0,0,0,0,19,10803,100,0,0,0,0,0,"Angus - On Script - Play Emote 11 Wheeler"),
(@ENTRY,9,160,0,0,0,100,0,0,0,0,0,5,11,0,0,0,0,0,19,10805,100,0,0,0,0,0,"Angus - On Script - Play Emote 11 Klemmy"),
(@ENTRY,9,161,0,0,0,100,0,1000,1000,0,0,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angus - On Script - Play Emote 11"),
(@ENTRY,9,162,0,0,0,100,0,0,0,0,0,5,11,0,0,0,0,0,19,10611,100,0,0,0,0,0,"Angus - On Script - Play Emote 11 Shorty"),
(@ENTRY,9,163,0,0,0,100,0,1000,1000,0,0,5,11,0,0,0,0,0,19,10804,100,0,0,0,0,0,"Angus - On Script - Play Emote 11 Middlecamp"),
(@ENTRY,9,164,0,0,0,100,0,0,0,0,0,5,11,0,0,0,0,0,19,10803,100,0,0,0,0,0,"Angus - On Script - Play Emote 11 Wheeler"),
(@ENTRY,9,165,0,0,0,100,0,1000,1000,0,0,45,17,0,0,0,0,0,19,10805,100,0,0,0,0,0,"Angus - On Script - Set Data 17 0 Klemmy"),
(@ENTRY,9,166,0,0,0,100,0,0,0,0,0,45,11,0,0,0,0,0,19,10611,50,0,0,0,0,0,"Angus - On Script - Set Data 11 0 Shorty"),
(@ENTRY,9,167,0,0,0,100,0,0,0,0,0,45,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angus - On Script - Set Data 2 0 Angus"),
(@ENTRY,9,168,0,0,0,100,0,0,0,0,0,45,17,0,0,0,0,0,19,10804,50,0,0,0,0,0,"Angus - On Script - Set Data 17 0 Middlecamp"),
(@ENTRY,9,169,0,0,0,100,0,0,0,0,0,45,15,0,0,0,0,0,19,10803,50,0,0,0,0,0,"Angus - On Script - Set Data 15 0 Wheeler"),
(@ENTRY,9,170,0,0,0,100,0,12000,12000,0,0,45,18,0,0,0,0,0,19,10805,100,0,0,0,0,0,"Angus - On Script - Set Data 18 0 Klemmy"),
(@ENTRY,9,171,0,0,0,100,0,4000,4000,0,0,45,16,0,0,0,0,0,19,10803,100,0,0,0,0,0,"Angus - On Script - Set Data 16 0 Wheeler"),
(@ENTRY,9,172,0,0,0,100,0,2000,2000,0,0,45,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angus - On Script - Set Data 3 0 Angus"),
(@ENTRY,9,173,0,0,0,100,0,1000,1000,0,0,45,18,0,0,0,0,0,19,10804,100,0,0,0,0,0,"Angus - On Script - Set Data 18 0 Middlecamp"),
(@ENTRY,9,174,0,0,0,100,0,1000,1000,0,0,45,3,0,0,0,0,0,19,1243,100,0,0,0,0,0,"Angus - On Script - Set Data 3 0 Hegnar"),
(@ENTRY,9,175,0,0,0,100,0,0,0,0,0,45,12,0,0,0,0,0,19,10611,100,0,0,0,0,0,"Angus - On Script - Set Data 12 0 Shorty");
