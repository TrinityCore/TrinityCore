-- Expedition Armory Fixup
-- Add Missing spawns
SET @CGUID := 78634;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 16904, 530, 1, 1, -1157.934, 2530.102, 50.09461, 4.869469, 120, 0, 0),
(@CGUID+1, 16904, 530, 1, 1, -1169.858, 2523.522, 51.36825, 4.904375, 120, 0, 0),
(@CGUID+2, 16904, 530, 1, 1, -1181.167, 2518.094, 52.19978, 4.939282, 120, 0, 0),
(@CGUID+3, 16904, 530, 1, 1, -1204.251, 2513.907, 50.62469, 4.991642, 120, 0, 0),
(@CGUID+4, 16904, 530, 1, 1, -1214.583, 2514.443, 48.68005, 5.026548, 120, 0, 0),
(@CGUID+5, 16904, 530, 1, 1, -1226.806, 2517.432, 45.69573, 5.061455, 120, 0, 0),
(@CGUID+6, 16904, 530, 1, 1, -1240.974, 2518.019, 42.89053, 5.096361, 120, 0, 0),
(@CGUID+7, 16904, 530, 1, 1, -1242.193, 2666.122, 5.166966, 0.8517824, 120, 5, 1);
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`emote`,`auras`) VALUES
(@CGUID+0,0,1,0, 333, ''),(@CGUID+1,0,1,0, 333, ''),(@CGUID+2,0,1,0, 333, ''),(@CGUID+3,0,1,0, 333, ''),
(@CGUID+4,0,1,0, 333, ''),(@CGUID+5,0,1,0, 333, ''),(@CGUID+6,0,1,0, 333, '');

-- Replace with proper spawn location and emote
DELETE FROM `creature` WHERE `guid`=58573;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(58573, 16904, 530, 1, 1, -1193.391, 2514.129, 52.23314, 4.974188, 120, 0, 0);
DELETE FROM `creature_addon` WHERE `guid`=58573;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`emote`,`auras`) VALUES (58573,0,1,0, 333, '');

-- Add Missing spawns
SET @CGUID := 45136;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 16906, 530, 1, 1, -1245.85, 2530.152, 39.89544, 0.3257069, 120, 0, 0);

-- Unyielding Footman SAI
SET @ENTRY := 16904;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unyielding Footman - On Respawn - Cast 'Shroud of Death' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,10000,10000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unyielding Footman - In Combat - Cast 'Shield Bash'"),
(@ENTRY,0,2,0,0,0,100,0,8000,8000,10000,10000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unyielding Footman - In Combat - Cast 'Strike'");

-- Unyielding Sorcerer SAI
SET @ENTRY := 16905;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unyielding Sorcerer - On Respawn - Cast 'Shroud of Death' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2400,3800,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Unyielding Sorcerer - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,2,0,0,0,100,0,5000,9000,12000,15000,11,11829,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unyielding Sorcerer - In Combat - Cast 'Flamestrike'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Unyielding Sorcerer - Between 0-15% Health - Cast 'Frost Nova' (No Repeat)");

-- Unyielding Knight SAI
SET @ENTRY := 16906;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unyielding Knight - On Respawn - Cast 'Shroud of Death' (No Repeat)"),
(@ENTRY,0,1,0,4,0,75,1,0,0,0,0,11,22911,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unyielding Knight - On Aggro - Cast 'Charge'"),
(@ENTRY,0,2,0,2,0,100,0,0,49,22000,22000,11,33910,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unyielding Knight - Between 0-50% Health - Cast 'Heal Other'");

-- Pathing for Unyielding Knight Entry: 16906
SET @NPC := 58608;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1078.709,`position_y`=2658.081,`position_z`=9.177089 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1078.709,2658.081,9.177089,0,0,0,0,100,0),
(@PATH,2,-1096.243,2642.266,14.738,0,0,0,0,100,0),
(@PATH,3,-1105.353,2613.758,25.22659,0,0,0,0,100,0),
(@PATH,4,-1122.484,2589.949,32.58151,0,0,0,0,100,0),
(@PATH,5,-1141.678,2565.609,39.58993,0,0,0,0,100,0),
(@PATH,6,-1169.054,2546.374,42.65359,0,0,0,0,100,0),
(@PATH,7,-1201.852,2535.243,43.5426,0,0,0,0,100,0),
(@PATH,8,-1236.385,2534.726,39.98657,0,0,0,0,100,0),
(@PATH,9,-1270.036,2541.282,33.16335,0,0,0,0,100,0),
(@PATH,10,-1301.669,2538.872,24.4906,0,0,0,0,100,0),
(@PATH,11,-1270.036,2541.282,33.16335,0,0,0,0,100,0),
(@PATH,12,-1236.385,2534.726,39.98657,0,0,0,0,100,0),
(@PATH,13,-1201.852,2535.243,43.5426,0,0,0,0,100,0),
(@PATH,14,-1169.054,2546.374,42.65359,0,0,0,0,100,0),
(@PATH,15,-1141.854,2565.387,39.52779,0,0,0,0,100,0),
(@PATH,16,-1122.484,2589.949,32.58151,0,0,0,0,100,0),
(@PATH,17,-1105.353,2613.758,25.22659,0,0,0,0,100,0),
(@PATH,18,-1096.243,2642.266,14.738,0,0,0,0,100,0);

-- Pathing for Unyielding Knight Entry: 16906
SET @NPC := 58613;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1162.367,`position_y`=2607.771,`position_z`=29.40837 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1162.367,2607.771,29.40837,0,0,0,0,100,0),
(@PATH,2,-1164.079,2598.115,32.16755,0,0,0,0,100,0),
(@PATH,3,-1169.018,2589.196,34.63213,0,0,0,0,100,0),
(@PATH,4,-1179.051,2584.435,35.66524,0,0,0,0,100,0),
(@PATH,5,-1188.898,2584.126,34.93496,0,0,0,0,100,0),
(@PATH,6,-1197.719,2589.689,32.88239,0,0,0,0,100,0),
(@PATH,7,-1203.93,2597.356,30.07175,0,0,0,0,100,0),
(@PATH,8,-1203.094,2608.61,26.71258,0,0,0,0,100,0),
(@PATH,9,-1197.07,2618.492,23.25711,0,0,0,0,100,0),
(@PATH,10,-1204.688,2630.729,14.91746,0,0,0,0,100,0),
(@PATH,11,-1192.009,2621.045,23.11704,0,0,0,0,100,0),
(@PATH,12,-1180,2623.365,23.50857,0,0,0,0,100,0),
(@PATH,13,-1169.128,2618.959,25.65092,0,0,0,0,100,0);

-- Pathing for Unyielding Knight Entry: 16906
SET @NPC := 58609;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1157.924,`position_y`=2633.312,`position_z`=16.72635 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1157.924,2633.312,16.72635,0,0,0,0,100,0),
(@PATH,2,-1181.425,2651.707,10.95528,0,0,0,0,100,0),
(@PATH,3,-1199.719,2651.361,11.49239,0,0,0,0,100,0),
(@PATH,4,-1224.046,2633.264,15.18406,0,0,0,0,100,0),
(@PATH,5,-1222.288,2613.92,19.34373,0,0,0,0,100,0),
(@PATH,6,-1217.993,2590.402,25.86894,0,0,0,0,100,0),
(@PATH,7,-1200.087,2563.635,34.07263,0,0,0,0,100,0),
(@PATH,8,-1167.751,2566.861,36.42008,0,0,0,0,100,0),
(@PATH,9,-1147.493,2597.137,28.52765,0,0,0,0,100,0);

-- Pathing for Unyielding Knight Entry: 16906
SET @NPC := 58619;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1493.109,`position_y`=2718.145,`position_z`=-57.93349 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1493.109,2718.145,-57.93349,0,0,0,0,100,0),
(@PATH,2,-1468.903,2730.062,-50.4717,0,0,0,0,100,0),
(@PATH,3,-1433.335,2745.595,-43.2352,0,0,0,0,100,0),
(@PATH,4,-1405.03,2752.498,-40.70433,0,0,0,0,100,0),
(@PATH,5,-1390.104,2756.25,-43.58144,0,0,0,0,100,0),
(@PATH,6,-1376.017,2740.627,-32.08193,0,0,0,0,100,0),
(@PATH,7,-1352.832,2718.672,-21.35978,0,0,0,0,100,0),
(@PATH,8,-1376.017,2740.627,-32.08193,0,0,0,0,100,0),
(@PATH,9,-1390.104,2756.25,-43.58144,0,0,0,0,100,0),
(@PATH,10,-1405.03,2752.498,-40.70433,0,0,0,0,100,0),
(@PATH,11,-1433.335,2745.595,-43.2352,0,0,0,0,100,0),
(@PATH,12,-1468.903,2730.062,-50.4717,0,0,0,0,100,0);

-- Pathing for Unyielding Knight Entry: 16906
SET @NPC := 58620;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1386.777,`position_y`=2826.613,`position_z`=-40.38738 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1386.777,2826.613,-40.38738,0,0,0,0,100,0),
(@PATH,2,-1408.631,2819.229,-50.63119,0,0,0,0,100,0),
(@PATH,3,-1435.901,2797.797,-55.37954,0,0,0,0,100,0),
(@PATH,4,-1443.677,2772.503,-52.40151,0,0,0,0,100,0),
(@PATH,5,-1446.915,2736.08,-44.52816,0,0,0,0,100,0),
(@PATH,6,-1446.109,2711.511,-39.9799,0,0,0,0,100,0),
(@PATH,7,-1442.769,2677.443,-35.50436,0,0,0,0,100,0),
(@PATH,8,-1442.006,2654.465,-31.99123,0,0,0,0,100,0),
(@PATH,9,-1442.769,2677.443,-35.50436,0,0,0,0,100,0),
(@PATH,10,-1446.109,2711.511,-39.9799,0,0,0,0,100,0),
(@PATH,11,-1446.915,2736.08,-44.52816,0,0,0,0,100,0),
(@PATH,12,-1443.677,2772.503,-52.40151,0,0,0,0,100,0),
(@PATH,13,-1435.901,2797.797,-55.37954,0,0,0,0,100,0),
(@PATH,14,-1408.631,2819.229,-50.63119,0,0,0,0,100,0);

-- Pathing for Unyielding Knight Entry: 16906
SET @NPC := 58614;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1231.44,`position_y`=2673.48,`position_z`=3.212412 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1231.44,2673.48,3.212412,0,0,0,0,100,0),
(@PATH,2,-1254.712,2666.087,4.77948,0,0,0,0,100,0),
(@PATH,3,-1279.99,2669.128,2.280368,0,0,0,0,100,0),
(@PATH,4,-1292.908,2659.416,5.344853,0,0,0,0,100,0),
(@PATH,5,-1321.698,2645.006,3.804264,0,0,0,0,100,0),
(@PATH,6,-1347.104,2642.002,-3.149265,0,0,0,0,100,0),
(@PATH,7,-1364.082,2701.073,-19.61125,0,0,0,0,100,0),
(@PATH,8,-1368.983,2729.167,-27.60984,0,0,0,0,100,0),
(@PATH,9,-1353.149,2746.193,-30.35087,0,0,0,0,100,0),
(@PATH,10,-1309.631,2746.361,-26.77184,0,0,0,0,100,0),
(@PATH,11,-1291.355,2741.067,-22.2482,0,0,0,0,100,0),
(@PATH,12,-1283.964,2721.001,-15.59282,0,0,0,0,100,0),
(@PATH,13,-1245.741,2718.254,-10.36791,0,0,0,0,100,0),
(@PATH,14,-1228.433,2697.869,-3.761098,0,0,0,0,100,0);

-- Pathing for Unyielding Knight Entry: 16906
SET @NPC := 45136;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1245.85,`position_y`=2530.152,`position_z`=39.89544 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1245.85,2530.152,39.89544,0,0,0,0,100,0),
(@PATH,2,-1215.004,2524.66,46.13549,0,0,0,0,100,0),
(@PATH,3,-1199.705,2529.827,46.08618,0,0,0,0,100,0),
(@PATH,4,-1174.797,2530.012,49.23584,0,0,0,0,100,0),
(@PATH,5,-1148.801,2544.552,46.86727,0,0,0,0,100,0),
(@PATH,6,-1124.96,2558.433,43.62494,0,0,0,0,100,0),
(@PATH,7,-1109.299,2576.635,38.45712,0,0,0,0,100,0),
(@PATH,8,-1096.697,2593.505,33.96788,0,0,0,0,100,0),
(@PATH,9,-1087.887,2610.023,27.83411,0,0,0,0,100,0),
(@PATH,10,-1076.242,2628.693,21.12952,0,0,0,0,100,0),
(@PATH,11,-1087.887,2610.023,27.87952,0,0,0,0,100,0),
(@PATH,12,-1096.697,2593.505,33.96788,0,0,0,0,100,0),
(@PATH,13,-1109.299,2576.635,38.45712,0,0,0,0,100,0),
(@PATH,14,-1124.96,2558.433,43.62494,0,0,0,0,100,0),
(@PATH,15,-1148.801,2544.552,46.86727,0,0,0,0,100,0),
(@PATH,16,-1174.797,2530.012,49.23584,0,0,0,0,100,0),
(@PATH,17,-1199.705,2529.827,46.08618,0,0,0,0,100,0),
(@PATH,18,-1215.004,2524.66,46.13549,0,0,0,0,100,0);

-- Pathing for Unyielding Sorcerer Entry: 16905
SET @NPC := 58606;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1248.946,`position_y`=2795.938,`position_z`=-22.21242 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1248.946,2795.938,-22.21242,0,0,0,0,100,0),
(@PATH,2,-1279.016,2799.39,-25.40128,0,0,0,0,100,0),
(@PATH,3,-1291.09,2807.696,-25.71146,0,0,0,0,100,0),
(@PATH,4,-1304.905,2801.276,-26.05369,0,0,0,0,100,0),
(@PATH,5,-1318.396,2792.647,-27.12447,0,0,0,0,100,0),
(@PATH,6,-1332.008,2791.637,-29.05025,0,0,0,0,100,0),
(@PATH,7,-1349.991,2782.115,-31.00883,0,0,0,0,100,0),
(@PATH,8,-1332.008,2791.637,-29.05025,0,0,0,0,100,0),
(@PATH,9,-1318.396,2792.647,-27.12447,0,0,0,0,100,0),
(@PATH,10,-1304.905,2801.276,-26.05369,0,0,0,0,100,0),
(@PATH,11,-1291.09,2807.696,-25.71146,0,0,0,0,100,0),
(@PATH,12,-1279.016,2799.39,-25.40128,0,0,0,0,100,0);

-- Pathing for Unyielding Sorcerer Entry: 16905
SET @NPC := 58601;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1227.628,`position_y`=2677.318,`position_z`=2.078013 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1227.628,2677.318,2.078013,0,0,0,0,100,0),
(@PATH,2,-1226.847,2697.971,-3.660757,0,0,0,0,100,0),
(@PATH,3,-1232.792,2711.546,-7.570609,0,0,0,0,100,0),
(@PATH,4,-1249.994,2720.591,-11.24999,0,0,0,0,100,0),
(@PATH,5,-1271.9,2723.106,-14.73588,0,0,0,0,100,0),
(@PATH,6,-1293.75,2719.271,-15.91459,0,0,0,0,100,0),
(@PATH,7,-1312.421,2708.201,-14.32982,0,0,0,0,100,0),
(@PATH,8,-1314.915,2697.092,-10.55418,0,0,0,0,100,0),
(@PATH,9,-1299.07,2679.115,-3.104276,0,0,0,0,100,0),
(@PATH,10,-1272.621,2669.487,2.713473,0,0,0,0,100,0),
(@PATH,11,-1251.434,2666.855,4.773651,0,0,0,0,100,0),
(@PATH,12,-1237.163,2669.433,4.330657,0,0,0,0,100,0);
