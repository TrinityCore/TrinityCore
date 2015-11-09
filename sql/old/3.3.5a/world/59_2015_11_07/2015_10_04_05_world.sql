-- 
-- Hrothgar Landing Fixups
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=34879;
 
DELETE FROM `creature` WHERE `guid` IN (52041,52042,52043,53107,53767,12483);
DELETE FROM `creature_addon` WHERE `guid` IN (52041,52042,52043,53107,53767,12483);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(52041, 34852, 571, 1, 1, 9990.989, 1252.2, 72.15693, 0, 120, 0, 0),
(52042, 34852, 571, 1, 1, 9977.433, 1207.604, 56.32283, 0, 120, 0, 0),
(52043, 34852, 571, 1, 1, 10013.58, 1270.264, 70.93209, 0, 120, 0, 0),
(53107, 34852, 571, 1, 1, 10051.8, 1186.913, 69.17319, 0, 120, 0, 0),
(53767, 34852, 571, 1, 1, 10063.12, 1209.752, 73.48428, 0, 120, 0, 0),
(12483, 34852, 571, 1, 1, 10115.9, 1189.974, 81.12413, 0, 120, 0, 0);
 
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=10051.27,`position_y`=1216.898,`position_z`=69.68569,`orientation`=2.460914 WHERE `guid`=53109;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=10110.92,`position_y`=1218.408,`position_z`=78.9978,`orientation`=0.6283185 WHERE `guid`=53113;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=10096.75,`position_y`=1190.5,`position_z`=79.6442,`orientation`=6.195919 WHERE `guid`=53041;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=9951.683,`position_y`=1201.502,`position_z`=52.69936,`orientation`=5.585053 WHERE `guid`=53114;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=9928.953,`position_y`=1172.898,`position_z`=51.50733,`orientation`=3.054326 WHERE `guid`=53224;
 
DELETE FROM `creature_addon` WHERE `guid` IN (53041,53114,53109,53113);
INSERT INTO `creature_addon` (`guid`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (53041,0,256,0, ''),(53114,1,1,0, ''),(53109,0,1,234, ''),(53113,0,256,0, '');
 
-- Pathing for Kvaldir Reaver Entry: 34838 'TDB FORMAT'
SET @NPC := 52038;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=10347.37,`position_y`=803.1042,`position_z`=77.75536 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,10347.37,803.1042,77.75536,0,0,0,0,100,0),
(@PATH,2,10367.6,818.8438,84.29758,0,0,0,0,100,0),
(@PATH,3,10383.35,834.6024,92.76371,0,0,0,0,100,0),
(@PATH,4,10395.81,846.125,99.77592,0,0,0,0,100,0),
(@PATH,5,10405.93,863.6893,107.7268,0,0,0,0,100,0),
(@PATH,6,10405.98,875.375,111.8353,0,0,0,0,100,0),
(@PATH,7,10408.97,888.6285,116.7162,0,0,0,0,100,0),
(@PATH,8,10414.13,900.0261,121.0533,0,0,0,0,100,0),
(@PATH,9,10415.96,910.5504,123.9247,0,0,0,0,100,0),
(@PATH,10,10414.13,900.0261,121.0533,0,0,0,0,100,0),
(@PATH,11,10408.97,888.6285,116.7162,0,0,0,0,100,0),
(@PATH,12,10405.98,875.375,111.8353,0,0,0,0,100,0),
(@PATH,13,10405.93,863.6893,107.7268,0,0,0,0,100,0),
(@PATH,14,10395.81,846.125,99.77592,0,0,0,0,100,0),
(@PATH,15,10383.35,834.6024,92.76371,0,0,0,0,100,0),
(@PATH,16,10367.6,818.8438,84.29758,0,0,0,0,100,0);
 
-- Pathing for Kvaldir Reaver Entry: 34838 'TDB FORMAT'
SET @NPC := 52039;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=10238.24,`position_y`=782.2483,`position_z`=71.30614 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,10238.24,782.2483,71.30614,0,0,0,0,100,0),
(@PATH,2,10263.58,779.5504,72.51409,0,0,0,0,100,0),
(@PATH,3,10288.04,780.6441,74.41165,0,0,0,0,100,0),
(@PATH,4,10303.06,778.2899,74.40554,0,0,0,0,100,0),
(@PATH,5,10317.63,777.9688,74.40554,0,0,0,0,100,0),
(@PATH,6,10330.9,782.1233,74.53054,0,0,0,0,100,0),
(@PATH,7,10340.32,781.7136,74.69975,0,0,0,0,100,0),
(@PATH,8,10330.9,782.1233,74.53054,0,0,0,0,100,0),
(@PATH,9,10317.63,777.9688,74.40554,0,0,0,0,100,0),
(@PATH,10,10303.06,778.2899,74.40554,0,0,0,0,100,0),
(@PATH,11,10288.04,780.6441,74.41165,0,0,0,0,100,0),
(@PATH,12,10263.58,779.5504,72.51409,0,0,0,0,100,0);
 
-- Pathing for Kvaldir Reaver Entry: 34838 'TDB FORMAT'
SET @NPC := 52604;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=10163.75,`position_y`=843.0364,`position_z`=42.24613 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,10163.75,843.0364,42.24613,0,0,0,0,100,0),
(@PATH,2,10170.49,831.2708,47.18571,0,0,0,0,100,0),
(@PATH,3,10181.2,816.316,52.61528,0,0,0,0,100,0),
(@PATH,4,10192.17,799.5977,57.89101,0,0,0,0,100,0),
(@PATH,5,10203.03,791.2552,62.39041,0,0,0,0,100,0),
(@PATH,6,10213.43,785.3785,65.56143,0,0,0,0,100,0),
(@PATH,7,10224.06,785.1649,68.88577,0,0,0,0,100,0),
(@PATH,8,10213.43,785.3785,65.56143,0,0,0,0,100,0),
(@PATH,9,10203.03,791.2552,62.39041,0,0,0,0,100,0),
(@PATH,10,10192.28,799.4097,57.93019,0,0,0,0,100,0),
(@PATH,11,10181.2,816.316,52.61528,0,0,0,0,100,0),
(@PATH,12,10170.49,831.2708,47.18571,0,0,0,0,100,0);
 
-- Pathing for Kvaldir Reaver Entry: 34838 'TDB FORMAT'
SET @NPC := 52045;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=10151.62,`position_y`=744.2795,`position_z`=66.60175 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,10151.62,744.2795,66.60175,0,0,0,0,100,0),
(@PATH,2,10160.01,748.9653,66.73127,0,0,0,0,100,0),
(@PATH,3,10170,758.5295,66.86421,0,0,0,0,100,0),
(@PATH,4,10177.37,775.2413,63.86098,0,0,0,0,100,0),
(@PATH,5,10186.68,792.9365,58.51601,0,0,0,0,100,0),
(@PATH,6,10177.37,775.2413,63.86098,0,0,0,0,100,0),
(@PATH,7,10170,758.5295,66.86421,0,0,0,0,100,0),
(@PATH,8,10160.01,748.9653,66.73127,0,0,0,0,100,0);
 
-- Pathing for Kvaldir Reaver Entry: 34838 'TDB FORMAT'
SET @NPC := 53134;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=10135.21,`position_y`=1210.611,`position_z`=79.11204 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,10135.21,1210.611,79.11204,0,0,0,0,100,0),
(@PATH,2,10143.43,1207.156,79.93629,0,0,0,0,100,0),
(@PATH,3,10151.32,1200.924,83.26014,0,0,0,0,100,0),
(@PATH,4,10160.9,1196.632,81.05866,0,0,0,0,100,0),
(@PATH,5,10167.02,1193.387,78.56778,0,0,0,0,100,0),
(@PATH,6,10172.88,1190.09,76.37518,0,0,0,0,100,0),
(@PATH,7,10167.02,1193.387,78.56778,0,0,0,0,100,0),
(@PATH,8,10160.9,1196.631,81.06026,0,0,0,0,100,0),
(@PATH,9,10151.32,1200.924,83.26014,0,0,0,0,100,0),
(@PATH,10,10143.43,1207.156,79.93629,0,0,0,0,100,0);
 
-- Pathing for Kvaldir Reaver Entry: 34838 'TDB FORMAT'
SET @NPC := 53108;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=9980.583,`position_y`=1195.92,`position_z`=54.3329 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,9980.583,1195.92,54.3329,0,0,0,0,100,0),
(@PATH,2,9986.409,1177.829,50.95467,0,0,0,0,100,0),
(@PATH,3,9977.379,1170.333,47.40315,0,0,0,0,100,0),
(@PATH,4,9968.799,1153.069,42.6813,0,0,0,0,100,0),
(@PATH,5,9968.064,1136.25,37.7756,0,0,0,0,100,0),
(@PATH,6,9967.274,1118.092,32.56385,0,0,0,0,100,0),
(@PATH,7,9969.733,1107.026,29.42457,0,0,0,0,100,0),
(@PATH,8,9969.542,1093.946,25.73834,0,0,0,0,100,0),
(@PATH,9,9969.849,1082.082,23.47699,0,0,0,0,100,0),
(@PATH,10,9970.052,1073.906,21.76483,0,0,0,0,100,0),
(@PATH,11,9969.849,1082.082,23.47699,0,0,0,0,100,0),
(@PATH,12,9969.542,1093.946,25.73834,0,0,0,0,100,0),
(@PATH,13,9969.732,1106.946,29.36329,0,0,0,0,100,0),
(@PATH,14,9967.274,1118.092,32.56385,0,0,0,0,100,0),
(@PATH,15,9968.064,1136.25,37.7756,0,0,0,0,100,0),
(@PATH,16,9968.799,1153.069,42.6813,0,0,0,0,100,0),
(@PATH,17,9977.379,1170.333,47.40315,0,0,0,0,100,0),
(@PATH,18,9986.482,1177.609,51.15157,0,0,0,0,100,0);
 
-- Pathing for Kvaldir Reaver Entry: 34838 'TDB FORMAT'
SET @NPC := 53099;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=9975.161,`position_y`=1041.323,`position_z`=16.6497 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,9975.161,1041.323,16.6497,0,0,0,0,100,0),
(@PATH,2,9988.208,1029.54,13.30617,0,0,0,0,100,0),
(@PATH,3,10005.18,1011.085,9.467186,0,0,0,0,100,0),
(@PATH,4,10021.29,994.6493,6.951415,0,0,0,0,100,0),
(@PATH,5,10047,976.625,6.902773,0,0,0,0,100,0),
(@PATH,6,10066.32,965.4705,10.23769,0,0,0,0,100,0),
(@PATH,7,10047,976.625,6.902773,0,0,0,0,100,0),
(@PATH,8,10021.29,994.6493,6.951415,0,0,0,0,100,0),
(@PATH,9,10005.19,1011.068,9.509178,0,0,0,0,100,0),
(@PATH,10,9988.272,1029.477,13.34639,0,0,0,0,100,0);
 
-- Pathing for Kvaldir Reaver Entry: 34838 'TDB FORMAT'
SET @NPC := 53112;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=10003.86,`position_y`=1191.727,`position_z`=58.1468 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,10003.86,1191.727,58.1468,0,0,0,0,100,0),
(@PATH,2,10019.43,1197.052,61.09853,0,0,0,0,100,0),
(@PATH,3,10034.4,1198.321,64.06003,0,0,0,0,100,0),
(@PATH,4,10053.43,1195.531,69.2673,0,0,0,0,100,0),
(@PATH,5,10066.09,1187.489,73.69296,0,0,0,0,100,0),
(@PATH,6,10071.19,1179.259,75.82832,0,0,0,0,100,0),
(@PATH,7,10066.11,1187.476,73.49924,0,0,0,0,100,0),
(@PATH,8,10053.45,1195.518,69.44296,0,0,0,0,100,0),
(@PATH,9,10034.4,1198.321,64.06003,0,0,0,0,100,0),
(@PATH,10,10019.43,1197.052,61.09853,0,0,0,0,100,0);
 
-- Kvaldir Reaver SAI
SET @ENTRY := 34838;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,9000,11000,11,49922,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kvaldir Reaver - In Combat - Cast 'Wave Crash'");
 
-- Kvaldir Mist Binder SAI
SET @ENTRY := 34839;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,12000,15000,11,49816,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kvaldir Mist Binder - In Combat - Cast 'Mist of Strangulation'");
