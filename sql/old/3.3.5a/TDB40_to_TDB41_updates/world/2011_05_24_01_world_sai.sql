-- Pathing for Stormpeak Wyrm Entry: 29753
SET @NPC := 101109;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7171.794,`position_y`=-1623.425,`position_z`=1024.3910 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7232.853,-1552.436,1018.6120,0,0,0,100,0),
(@PATH,2,7307.723,-1450.282,1031.3350,0,0,0,100,0),
(@PATH,3,7331.675,-1329.285,1071.6680,0,0,0,100,0),
(@PATH,4,7358.584,-1200.453,1095.0840,0,0,0,100,0),
(@PATH,5,7466.604,-1189.773,1087.8350,0,0,0,100,0),
(@PATH,6,7551.937,-1306.039,1036.9180,0,0,0,100,0),
(@PATH,7,7448.903,-1429.033,989.2788,0,0,0,100,0),
(@PATH,8,7265.264,-1460.603,924.7513,0,0,0,100,0),
(@PATH,9,7092.603,-1462.597,1039.6130,0,0,0,100,0),
(@PATH,10,6996.566,-1627.143,1060.5580,0,0,0,100,0),
(@PATH,11,7050.830,-1759.601,1026.4740,0,0,0,100,0),
(@PATH,12,7171.794,-1623.425,1024.3910,0,0,0,100,0);

-- Pathing for Stormpeak Wyrm Entry: 29753
SET @NPC := 101111;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7587.957,`position_y`=-1291.808,`position_z`=991.6395 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7576.177,-1339.229,991.6395,0,0,0,100,0),
(@PATH,2,7507.776,-1364.563,991.6395,0,0,0,100,0),
(@PATH,3,7462.349,-1304.429,991.6395,0,0,0,100,0),
(@PATH,4,7498.511,-1237.602,991.6395,0,0,0,100,0),
(@PATH,5,7560.044,-1239.629,991.6395,0,0,0,100,0),
(@PATH,6,7587.957,-1291.808,991.6395,0,0,0,100,0);

-- Pathing for Stormpeak Wyrm Entry: 29753
SET @NPC := 101112;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7325.549,`position_y`=-1146.471,`position_z`=1046.3540 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7422.022,-1135.820,1033.4380,0,0,0,100,0),
(@PATH,2,7518.522,-1237.663,1056.8260,0,0,0,100,0),
(@PATH,3,7501.124,-1449.262,1017.7980,0,0,0,100,0),
(@PATH,4,7376.508,-1303.557,1049.8540,0,0,0,100,0),
(@PATH,5,7325.549,-1146.471,1046.3540,0,0,0,100,0);

-- Pathing for Stormpeak Wyrm Entry: 29753
SET @NPC := 101121;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7306.776,`position_y`=-1409.522,`position_z`=1035.3630 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7403.804,-1456.458,1035.3630,0,0,0,100,0),
(@PATH,2,7468.895,-1421.992,1035.3630,0,0,0,100,0),
(@PATH,3,7499.714,-1349.263,1035.3630,0,0,0,100,0),
(@PATH,4,7436.533,-1280.687,1035.3630,0,0,0,100,0),
(@PATH,5,7396.054,-1281.403,1035.3630,0,0,0,100,0),
(@PATH,6,7298.188,-1334.745,1035.3630,0,0,0,100,0),
(@PATH,7,7306.776,-1409.522,1035.3630,0,0,0,100,0);

-- Pathing for Stormpeak Wyrm Entry: 29753
SET @NPC := 101123;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7505.094,`position_y`=-1216.210,`position_z`=980.8120 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7458.424,-1438.003,1005.1730,0,0,0,100,0),
(@PATH,2,7528.125,-1725.565,1300.1730,0,0,0,100,0),
(@PATH,3,7422.311,-1569.981,1141.3120,0,0,0,100,0),
(@PATH,4,7330.956,-1412.603,980.8120,0,0,0,100,0),
(@PATH,5,7303.932,-1283.664,980.8120,0,0,0,100,0),
(@PATH,6,7361.022,-1158.353,980.8120,0,0,0,100,0),
(@PATH,7,7505.094,-1216.210,980.8120,0,0,0,100,0);

-- Pathing for Stormpeak Wyrm Entry: 29753
SET @NPC := 101124;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7462.040,`position_y`=-1145.189,`position_z`=1073.3400 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7534.368,-1192.623,1109.7570,0,0,0,100,0),
(@PATH,2,7491.979,-1297.336,1075.2560,0,0,0,100,0),
(@PATH,3,7435.823,-1388.198,963.8117,0,0,0,100,0),
(@PATH,4,7374.318,-1466.145,951.8396,0,0,0,100,0),
(@PATH,5,7270.311,-1513.188,983.5063,0,0,0,100,0),
(@PATH,6,7186.261,-1542.495,999.2841,0,0,0,100,0),
(@PATH,7,7146.302,-1430.093,1026.7840,0,0,0,100,0),
(@PATH,8,7277.046,-1312.483,941.7841,0,0,0,100,0),
(@PATH,9,7350.680,-1247.736,932.9788,0,0,0,100,0),
(@PATH,10,7462.040,-1145.189,1073.3400,0,0,0,100,0);

-- Some fixups
UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `guid` IN (101107,101113,101115,101117);
DELETE FROM `creature` WHERE `guid`=101116;
DELETE FROM `creature_addon` WHERE `guid`=101116;
UPDATE `creature_template` SET `speed_run`=1.25 WHERE `entry`=29753;
