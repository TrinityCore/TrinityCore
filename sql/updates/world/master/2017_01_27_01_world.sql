-- Remove Twilight Rider (Humanoid)
DELETE FROM `creature` WHERE `guid` BETWEEN 315967 AND 315973;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN 315967 AND 315973;
-- Fix inhabittype for Twilight Rider
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (34282,34316);
-- Fix vehicle template for Twilight Rider
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (34282);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(34282,34293,0,1,'Twilight Rider - Twilight Rider (Humanoid)', 8, 0);
-- Fix spell click for Twilight Rider
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (34282);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(34282, 46598, 0, 0);

-- Dead
UPDATE `creature` SET `unit_flags`=537166592 WHERE `guid` IN (260121,260181,260182,260188,260189,260190,315003,315004,315005);
DELETE FROM `creature_addon` WHERE `guid` IN (260121,260181,260182,260188,260189,260190,315003,315004,315005);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(260121,0,0,0,1,0, '29266'),(260181,0,0,0,1,0, '29266'),(260182,0,0,0,1,0, '29266'),
(260188,0,0,0,1,0, '29266'),(260189,0,0,0,1,0, '29266'),(260190,0,0,0,1,0, '29266'),
(315003,0,0,0,1,0, '29266'),(315004,0,0,0,1,0, '29266'),(315005,0,0,0,1,0, '29266');

-- Sit
DELETE FROM `creature_addon` WHERE `guid` IN (315952,260232,315950,315949,260225,315956);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(315952,0,0,1,1,0, ''),(260232,0,0,1,1,0, ''),(315950,0,0,1,1,0, ''),
(315949,0,0,1,1,0, ''),(260225,0,0,1,1,0, ''),(315956,0,0,1,1,0, '');

-- Emotestate
DELETE FROM `creature_template_addon` WHERE `entry`=32861;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(32861,0,0,0,1,233, '');

-- Mount
DELETE FROM `creature_template_addon` WHERE `entry`=33359;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(33359,0,9991,0,257,0, '');

-- Sentinels
UPDATE `creature` SET `unit_flags`=537166592 WHERE `guid` IN (314948,314952,314962,314965,314945);
DELETE FROM `creature_addon` WHERE `guid` IN (260121,260181,260182,260188,260189,260190,315003,315004,315005);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(314948,0,0,0,258,376, ''),(314952,0,0,0,258,376, ''),(314962,0,0,0,258,376, ''),
(314965,0,0,0,257,333, ''),(314945,0,0,0,257,333, '');

-- Pathing for Shatterspear Mystic Entry: 34248 'TDB FORMAT' 
SET @NPC := 315948;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7728.353,`position_y`=-1024.868,`position_z`=35.55265 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7728.353,-1024.868,35.55265,0,0,0,0,100,0),
(@PATH,2,7739.828,-1011.357,33.6236,0,0,0,0,100,0),
(@PATH,3,7749.118,-996.1793,28.97294,0,0,0,0,100,0),
(@PATH,4,7749.872,-986.7863,27.41411,0,0,0,0,100,0),
(@PATH,5,7764.473,-974.2542,27.26494,0,0,0,0,100,0),
(@PATH,6,7775.485,-963.2115,30.14509,0,0,0,0,100,0),
(@PATH,7,7785.51,-959.6288,31.35176,0,0,0,0,100,0),
(@PATH,8,7798.54,-961.1868,32.13471,0,0,0,0,100,0),
(@PATH,9,7787.491,-950.3774,33.85444,0,0,0,0,100,0),
(@PATH,10,7776.849,-946.367,33.22785,0,0,0,0,100,0),
(@PATH,11,7767.75,-952.8447,31.29072,0,0,0,0,100,0),
(@PATH,12,7776.709,-946.4648,33.19477,0,0,0,0,100,0),
(@PATH,13,7787.491,-950.3774,33.85444,0,0,0,0,100,0),
(@PATH,14,7798.54,-961.1868,32.13471,0,0,0,0,100,0),
(@PATH,15,7785.51,-959.6288,31.35176,0,0,0,0,100,0),
(@PATH,16,7775.485,-963.2115,30.14509,0,0,0,0,100,0),
(@PATH,17,7764.473,-974.2542,27.26494,0,0,0,0,100,0),
(@PATH,18,7749.872,-986.7863,27.41411,0,0,0,0,100,0),
(@PATH,19,7749.118,-996.1793,28.97294,0,0,0,0,100,0),
(@PATH,20,7739.828,-1011.357,33.6236,0,0,0,0,100,0);

-- Pathing for Shatterspear Mystic Entry: 34248 'TDB FORMAT' 
SET @NPC := 315953;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7859.925,`position_y`=-1049.922,`position_z`=29.49779 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7859.925,-1049.922,29.49779,0,0,0,0,100,0),
(@PATH,2,7865.632,-1031.951,31.29234,0,0,0,0,100,0),
(@PATH,3,7857.645,-1022.504,31.79392,0,0,0,0,100,0),
(@PATH,4,7841.286,-1019.47,31.31407,0,0,0,0,100,0),
(@PATH,5,7825.655,-1009.775,31.57815,0,0,0,0,100,0),
(@PATH,6,7824.332,-995.2059,32.75198,0,0,0,0,100,0),
(@PATH,7,7827.567,-982.9218,34.98917,0,0,0,0,100,0),
(@PATH,8,7824.332,-995.2059,32.75198,0,0,0,0,100,0),
(@PATH,9,7825.655,-1009.775,31.57815,0,0,0,0,100,0),
(@PATH,10,7841.286,-1019.47,31.31407,0,0,0,0,100,0),
(@PATH,11,7857.645,-1022.504,31.79392,0,0,0,0,100,0),
(@PATH,12,7865.632,-1031.951,31.29234,0,0,0,0,100,0);

-- Pathing for Shatterspear Mystic Entry: 34248 'TDB FORMAT' 
SET @NPC := 315954;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7822.587,`position_y`=-1078.475,`position_z`=34.28187 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7822.587,-1078.475,34.28187,0,0,0,0,100,0),
(@PATH,2,7829.702,-1088.829,35.08729,0,0,0,0,100,0),
(@PATH,3,7837.28,-1107.346,37.25541,0,0,0,0,100,0),
(@PATH,4,7848.562,-1118.456,40.2388,0,0,0,0,100,0),
(@PATH,5,7862.053,-1122.544,40.76432,0,0,0,0,100,0),
(@PATH,6,7848.562,-1118.456,40.2388,0,0,0,0,100,0),
(@PATH,7,7837.299,-1107.39,36.95243,0,0,0,0,100,0),
(@PATH,8,7829.702,-1088.829,35.08729,0,0,0,0,100,0);

-- Pathing for Shatterspear Mystic Entry: 34248 'TDB FORMAT' 
SET @NPC := 315955;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7894.247,`position_y`=-953.2868,`position_z`=6.170178 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7894.247,-953.2868,6.170178,0,0,0,0,100,0),
(@PATH,2,7894.247,-953.2868,6.170178,1.22173,0,0,0,100,0),
(@PATH,3,7883.209,-953.5597,7.139173,0,0,0,0,100,0),
(@PATH,4,7878.192,-953.1683,7.896985,0,0,0,0,100,0),
(@PATH,5,7874.496,-950.1553,7.988172,0,20000,0,0,100,0),
(@PATH,6,7887.877,-955.1155,7.077039,0,0,0,0,100,0);

-- Pathing for Shatterspear Mystic Entry: 34248 'TDB FORMAT' 
SET @NPC := 315958;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7917.67,`position_y`=-1007.097,`position_z`=35.55279 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7917.67,-1007.097,35.55279,0,0,0,0,100,0),
(@PATH,2,7926.677,-1001.619,35.69171,0,0,0,0,100,0),
(@PATH,3,7932.444,-995.2227,36.04287,0,0,0,0,100,0),
(@PATH,4,7942.746,-999.0692,37.38876,0,0,0,0,100,0),
(@PATH,5,7943.737,-1010.235,37.65462,0,0,0,0,100,0),
(@PATH,6,7948.241,-1019.707,36.01266,0,0,0,0,100,0),
(@PATH,7,7943.737,-1010.235,37.65462,0,0,0,0,100,0),
(@PATH,8,7942.746,-999.0692,37.38876,0,0,0,0,100,0),
(@PATH,9,7932.444,-995.2227,36.04287,0,0,0,0,100,0),
(@PATH,10,7926.677,-1001.619,35.69171,0,0,0,0,100,0);

-- Pathing for Shatterspear Mystic Entry: 34248 'TDB FORMAT' 
SET @NPC := 315959;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7959.181,`position_y`=-1050.556,`position_z`=39.31163 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7959.181,-1050.556,39.31163,0,0,0,0,100,0),
(@PATH,2,7967.601,-1047.391,40.44551,0,0,0,0,100,0),
(@PATH,3,7977.37,-1043.924,42.40401,0,0,0,0,100,0),
(@PATH,4,7991.621,-1047.562,43.19551,0,0,0,0,100,0),
(@PATH,5,7996.505,-1059.354,42.5107,0,0,0,0,100,0),
(@PATH,6,7995.118,-1069.316,40.90172,0,0,0,0,100,0),
(@PATH,7,7999.283,-1079.609,39.13915,0,0,0,0,100,0),
(@PATH,8,7995.118,-1069.316,40.90172,0,0,0,0,100,0),
(@PATH,9,7996.505,-1059.354,42.5107,0,0,0,0,100,0),
(@PATH,10,7991.621,-1047.562,43.19551,0,0,0,0,100,0),
(@PATH,11,7977.37,-1043.924,42.40401,0,0,0,0,100,0),
(@PATH,12,7967.714,-1047.345,40.57222,0,0,0,0,100,0);

-- Pathing for Shatterspear Shaman Entry: 32860 'TDB FORMAT' 
SET @NPC := 260210;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7335.531,`position_y`=-917.5428,`position_z`=32.52893 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7335.531,-917.5428,32.52893,0,0,0,0,100,0),
(@PATH,2,7343.486,-917.3605,32.4915,0,0,0,0,100,0),
(@PATH,3,7353.216,-918.0386,32.55395,0,0,0,0,100,0),
(@PATH,4,7359.465,-924.6296,32.63941,0,0,0,0,100,0),
(@PATH,5,7364.059,-931.4347,32.64275,0,0,0,0,100,0),
(@PATH,6,7364.768,-941.908,32.52287,0,0,0,0,100,0),
(@PATH,7,7365.47,-951.0586,32.5445,0,0,0,0,100,0),
(@PATH,8,7364.768,-941.908,32.52287,0,0,0,0,100,0),
(@PATH,9,7364.059,-931.4347,32.64275,0,0,0,0,100,0),
(@PATH,10,7359.465,-924.6296,32.63941,0,0,0,0,100,0),
(@PATH,11,7353.216,-918.0386,32.55395,0,0,0,0,100,0),
(@PATH,12,7343.486,-917.3605,32.4915,0,0,0,0,100,0);

-- Pathing for Shatterspear Shaman Entry: 32860 'TDB FORMAT' 
SET @NPC := 260211;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7320.181,`position_y`=-935.1487,`position_z`=32.61071 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7320.181,-935.1487,32.61071,0,0,0,0,100,0),
(@PATH,2,7319.833,-943.6137,32.59713,0,0,0,0,100,0),
(@PATH,3,7323.545,-950.0673,32.53239,0,0,0,0,100,0),
(@PATH,4,7328.143,-955.1786,32.63148,0,0,0,0,100,0),
(@PATH,5,7335.614,-960.2813,32.62185,0,0,0,0,100,0),
(@PATH,6,7342.052,-960.9525,32.52134,0,0,0,0,100,0),
(@PATH,7,7353.032,-960.6999,32.53663,0,0,0,0,100,0),
(@PATH,8,7342.052,-960.9525,32.52134,0,0,0,0,100,0),
(@PATH,9,7335.614,-960.2813,32.62185,0,0,0,0,100,0),
(@PATH,10,7328.143,-955.1786,32.63148,0,0,0,0,100,0),
(@PATH,11,7323.545,-950.0673,32.53239,0,0,0,0,100,0),
(@PATH,12,7319.833,-943.6137,32.59713,0,0,0,0,100,0);

-- Pathing for Shatterspear Overseer Entry: 32863 'TDB FORMAT' 
SET @NPC := 260112;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7599.38,`position_y`=-1013.117,`position_z`=37.81955 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7599.38,-1013.117,37.81955,0,0,0,0,100,0),
(@PATH,2,7606.116,-996.798,35.95076,0,0,0,0,100,0),
(@PATH,3,7628.067,-989.9417,34.73323,0,0,0,0,100,0),
(@PATH,4,7643.506,-981.4705,33.30636,0,0,0,0,100,0),
(@PATH,5,7677.551,-966.1126,27.03073,0,0,0,0,100,0),
(@PATH,6,7690.428,-962.005,27.06711,0,0,0,0,100,0),
(@PATH,7,7677.551,-966.1126,27.03073,0,0,0,0,100,0),
(@PATH,8,7643.506,-981.4705,33.30636,0,0,0,0,100,0),
(@PATH,9,7628.067,-989.9417,34.73323,0,0,0,0,100,0),
(@PATH,10,7606.116,-996.798,35.95076,0,0,0,0,100,0);

-- Pathing for Shatterspear Overseer Entry: 32863 'TDB FORMAT' 
SET @NPC := 260113;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7568.692,`position_y`=-908.0872,`position_z`=17.90287 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7568.692,-908.0872,17.90287,0,0,0,0,100,0),
(@PATH,2,7585.981,-901.0091,16.61991,0,0,0,0,100,0),
(@PATH,3,7605.405,-908.0601,17.52477,0,0,0,0,100,0),
(@PATH,4,7620.811,-914.934,18.15929,0,0,0,0,100,0),
(@PATH,5,7645.816,-926.577,20.18037,0,0,0,0,100,0),
(@PATH,6,7660.266,-936.6155,22.45372,0,0,0,0,100,0),
(@PATH,7,7645.816,-926.577,20.18037,0,0,0,0,100,0),
(@PATH,8,7620.811,-914.934,18.15929,0,0,0,0,100,0),
(@PATH,9,7605.405,-908.0601,17.52477,0,0,0,0,100,0),
(@PATH,10,7585.981,-901.0091,16.61991,0,0,0,0,100,0);

-- Pathing for Shatterspear Overseer Entry: 32863 'TDB FORMAT' 
SET @NPC := 260114;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7606.419,`position_y`=-1065.72,`position_z`=38.66918 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7606.419,-1065.72,38.66918,0,0,0,0,100,0),
(@PATH,2,7592.838,-1081.104,40.36279,0,0,0,0,100,0),
(@PATH,3,7570.682,-1084.795,41.51733,0,0,0,0,100,0),
(@PATH,4,7553.966,-1086.787,41.34108,0,0,0,0,100,0),
(@PATH,5,7541.666,-1088.682,41.08522,0,0,0,0,100,0),
(@PATH,6,7529.438,-1090.964,40.20127,0,0,0,0,100,0),
(@PATH,7,7514.799,-1080.535,36.90684,0,0,0,0,100,0),
(@PATH,8,7529.438,-1090.964,40.20127,0,0,0,0,100,0),
(@PATH,9,7541.666,-1088.682,41.08522,0,0,0,0,100,0),
(@PATH,10,7553.966,-1086.787,41.34108,0,0,0,0,100,0),
(@PATH,11,7570.682,-1084.795,41.51733,0,0,0,0,100,0),
(@PATH,12,7592.838,-1081.104,40.36279,0,0,0,0,100,0);

-- Pathing for Shatterspear Overseer Entry: 32863 'TDB FORMAT' 
SET @NPC := 260115;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7502.747,`position_y`=-826.8952,`position_z`=18.97173 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7502.747,-826.8952,18.97173,0,0,0,0,100,0),
(@PATH,2,7510.808,-839.6569,21.11386,0,0,0,0,100,0),
(@PATH,3,7513.217,-857.0547,22.89401,0,0,0,0,100,0),
(@PATH,4,7517.783,-877.2765,23.02552,0,0,0,0,100,0),
(@PATH,5,7531.417,-890.7168,22.06057,0,0,0,0,100,0),
(@PATH,6,7548.83,-892.5985,18.39466,0,0,0,0,100,0),
(@PATH,7,7531.417,-890.7169,22.03571,0,0,0,0,100,0),
(@PATH,8,7517.992,-877.3906,23.01136,0,0,0,0,100,0),
(@PATH,9,7513.217,-857.0547,22.89401,0,0,0,0,100,0),
(@PATH,10,7510.808,-839.6569,21.11386,0,0,0,0,100,0);

-- Pathing for Shatterspear Overseer Entry: 32863 'TDB FORMAT' 
SET @NPC := 260116;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7448.36,`position_y`=-908.9323,`position_z`=12.40135 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7448.36,-908.9323,12.40135,0,0,0,0,100,0),
(@PATH,2,7460.012,-905.4692,12.90135,0,0,0,0,100,0),
(@PATH,3,7466.651,-890.3277,12.87762,0,0,0,0,100,0),
(@PATH,4,7476.055,-880.0972,12.97028,0,0,0,0,100,0),
(@PATH,5,7488.799,-866.6018,13.09356,0,0,0,0,100,0),
(@PATH,6,7490.512,-854.1754,12.99444,0,0,0,0,100,0),
(@PATH,7,7488.799,-866.6018,13.09356,0,0,0,0,100,0),
(@PATH,8,7476.055,-880.0972,12.97028,0,0,0,0,100,0),
(@PATH,9,7466.651,-890.3277,12.87762,0,0,0,0,100,0),
(@PATH,10,7460.012,-905.4692,12.90135,0,0,0,0,100,0);

-- Pathing for Shatterspear Overseer Entry: 32863 'TDB FORMAT' 
SET @NPC := 260117;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7454.95,`position_y`=-975.898,`position_z`=-4.259661 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7454.95,-975.898,-4.259661,0,0,0,0,100,0),
(@PATH,2,7467.293,-996.7088,-9.756348,0,0,0,0,100,0),
(@PATH,3,7484.445,-1001.503,-9.756347,0,0,0,0,100,0),
(@PATH,4,7508.458,-1000.874,-9.756348,0,0,0,0,100,0),
(@PATH,5,7528.374,-993.3583,-9.756348,0,0,0,0,100,0),
(@PATH,6,7508.458,-1000.874,-9.756348,0,0,0,0,100,0),
(@PATH,7,7484.445,-1001.503,-9.756347,0,0,0,0,100,0),
(@PATH,8,7467.293,-996.7088,-9.756348,0,0,0,0,100,0);

-- Pathing for Shatterspear Overseer Entry: 32863 'TDB FORMAT' 
SET @NPC := 260118;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7401.012,`position_y`=-1124.809,`position_z`=40.59638 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7401.012,-1124.809,40.59638,0,0,0,0,100,0),
(@PATH,2,7404.583,-1112.102,41.05244,0,0,0,0,100,0),
(@PATH,3,7411.577,-1100.636,41.7353,0,0,0,0,100,0),
(@PATH,4,7416.818,-1087.871,41.01855,0,0,0,0,100,0),
(@PATH,5,7426.627,-1073.011,38.48559,0,0,0,0,100,0),
(@PATH,6,7443.395,-1071.23,36.74761,0,0,0,0,100,0),
(@PATH,7,7458.042,-1082.665,35.61504,0,0,0,0,100,0),
(@PATH,8,7470.624,-1099.98,35.74009,0,0,0,0,100,0),
(@PATH,9,7458.042,-1082.665,35.61504,0,0,0,0,100,0),
(@PATH,10,7443.395,-1071.23,36.74761,0,0,0,0,100,0),
(@PATH,11,7426.627,-1073.011,38.48559,0,0,0,0,100,0),
(@PATH,12,7416.818,-1087.871,41.01855,0,0,0,0,100,0),
(@PATH,13,7411.577,-1100.636,41.7353,0,0,0,0,100,0),
(@PATH,14,7404.583,-1112.102,41.05244,0,0,0,0,100,0);

-- Pathing for Shatterspear Overseer Entry: 32863 'TDB FORMAT' 
SET @NPC := 260119;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7405.374,`position_y`=-884.6844,`position_z`=14.03211 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7405.374,-884.6844,14.03211,0,0,0,0,100,0),
(@PATH,2,7411.338,-895.1248,13.38172,0,0,0,0,100,0),
(@PATH,3,7415.38,-907.8409,12.98542,0,0,0,0,100,0),
(@PATH,4,7435.712,-916.7114,12.83348,0,0,0,0,100,0),
(@PATH,5,7442.533,-935.9618,9.444044,0,0,0,0,100,0),
(@PATH,6,7435.712,-916.7114,12.83348,0,0,0,0,100,0),
(@PATH,7,7415.38,-907.8409,12.98542,0,0,0,0,100,0),
(@PATH,8,7411.338,-895.1248,13.38172,0,0,0,0,100,0);

-- Pathing for Shatterspear Overseer Entry: 32863 'TDB FORMAT' 
SET @NPC := 260120;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7351.075,`position_y`=-1026.211,`position_z`=32.76779 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7351.075,-1026.211,32.76779,0,0,0,0,100,0),
(@PATH,2,7365.121,-1029.707,34.06247,0,0,0,0,100,0),
(@PATH,3,7383.807,-1036.224,34.97688,0,0,0,0,100,0),
(@PATH,4,7390.823,-1050.069,38.60383,0,0,0,0,100,0),
(@PATH,5,7398.736,-1072.353,38.44911,0,0,0,0,100,0),
(@PATH,6,7413.12,-1053.016,37.97487,0,0,0,0,100,0),
(@PATH,7,7422.581,-1056.303,37.97487,0,0,0,0,100,0),
(@PATH,8,7413.12,-1053.016,37.97487,0,0,0,0,100,0),
(@PATH,9,7398.736,-1072.353,38.44911,0,0,0,0,100,0),
(@PATH,10,7390.823,-1050.069,38.60383,0,0,0,0,100,0),
(@PATH,11,7383.807,-1036.224,34.97688,0,0,0,0,100,0),
(@PATH,12,7365.121,-1029.707,34.06247,0,0,0,0,100,0);

-- Pathing for Shatterspear Overseer Entry: 32863 'TDB FORMAT' 
SET @NPC := 260122;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7338.461,`position_y`=-897.3798,`position_z`=32.35087 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7338.461,-897.3798,32.35087,0,0,0,0,100,0),
(@PATH,2,7357.258,-900.9969,32.3793,0,0,0,0,100,0),
(@PATH,3,7373.655,-911.5593,32.33734,0,0,0,0,100,0),
(@PATH,4,7380.987,-921.4531,32.33734,0,0,0,0,100,0),
(@PATH,5,7383.574,-936.3718,32.3609,0,0,0,0,100,0),
(@PATH,6,7383.104,-954.163,32.3609,0,0,0,0,100,0),
(@PATH,7,7384.088,-968.9316,32.2615,0,0,0,0,100,0),
(@PATH,8,7372.396,-982.0106,32.1365,0,0,0,0,100,0),
(@PATH,9,7384.088,-968.9316,32.2615,0,0,0,0,100,0),
(@PATH,10,7383.104,-954.163,32.3609,0,0,0,0,100,0),
(@PATH,11,7383.574,-936.3718,32.3609,0,0,0,0,100,0),
(@PATH,12,7380.987,-921.4531,32.33734,0,0,0,0,100,0),
(@PATH,13,7373.655,-911.5593,32.33734,0,0,0,0,100,0),
(@PATH,14,7357.258,-900.9969,32.3793,0,0,0,0,100,0);

-- Pathing for Shatterspear Overseer Entry: 32863 'TDB FORMAT' 
SET @NPC := 260123;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7223.094,`position_y`=-880.5992,`position_z`=37.79979 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7223.094,-880.5992,37.79979,0,0,0,0,100,0),
(@PATH,2,7234.228,-894.6946,37.06801,0,0,0,0,100,0),
(@PATH,3,7239.879,-905.9241,37.9833,0,0,0,0,100,0),
(@PATH,4,7251.563,-921.3535,37.58487,0,0,0,0,100,0),
(@PATH,5,7261.594,-943.1263,35.16981,0,0,0,0,100,0),
(@PATH,6,7251.563,-921.3535,37.58487,0,0,0,0,100,0),
(@PATH,7,7239.879,-905.9241,37.9833,0,0,0,0,100,0),
(@PATH,8,7234.228,-894.6946,37.06801,0,0,0,0,100,0);

-- Pathing for Shatterspear Laborer Entry: 32861 'TDB FORMAT' 
SET @NPC := 260126;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7755.712,`position_y`=-1066.941,`position_z`=19.89425 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7755.712,-1066.941,19.89425,0,3000,0,0,100,0),
(@PATH,2,7766.917,-1064.461,19.69485,0,0,0,0,100,0),
(@PATH,3,7775.641,-1066.84,19.21276,0,4000,0,0,100,0),
(@PATH,4,7767.621,-1073.029,18.60546,0,0,0,0,100,0),
(@PATH,5,7756.965,-1077.687,18.86471,5000,0,0,0,100,0);

-- Pathing for Shatterspear Laborer Entry: 32861 'TDB FORMAT' 
SET @NPC := 260127;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7732.149,`position_y`=-914.355,`position_z`=21.68252 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7732.149,-914.355,21.68252,0,3000,0,0,100,0),
(@PATH,2,7730.493,-928.5589,21.75088,0,0,0,0,100,0),
(@PATH,3,7723.89,-927.4189,21.20474,0,3000,0,0,100,0),
(@PATH,4,7716.666,-931.25,21.68252,0,0,0,0,100,0),
(@PATH,5,7712.218,-925.2083,21.15384,0,0,0,0,100,0),
(@PATH,6,7711.432,-916.2186,21.55752,0,3000,0,0,100,0),
(@PATH,7,7718.129,-914.1452,21.06949,0,0,0,0,100,0),
(@PATH,8,7725.17,-915.9028,21.26541,0,0,0,0,100,0),
(@PATH,9,7725.17,-915.9028,21.26541,1.727876,3000,0,0,100,0);

-- Pathing for Twilight Fanatic Entry: 32888 'TDB FORMAT' 
SET @NPC := 260090;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6919.327,`position_y`=112.5985,`position_z`=8.312071 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6919.327,112.5985,8.312071,0,0,0,0,100,0),
(@PATH,2,6911.659,110.723,7.987853,0,0,0,0,100,0),
(@PATH,3,6896.64,107.7805,7.924678,0,0,0,0,100,0),
(@PATH,4,6885.765,110.6686,7.407832,0,0,0,0,100,0),
(@PATH,5,6877.127,115.8606,7.178462,0,0,0,0,100,0),
(@PATH,6,6872.436,128.7393,7.683223,0,0,0,0,100,0),
(@PATH,7,6870.944,145.7486,7.576735,0,0,0,0,100,0),
(@PATH,8,6871.082,168.4998,10.64218,0,0,0,0,100,0),
(@PATH,9,6867.46,178.8064,9.249354,0,0,0,0,100,0),
(@PATH,10,6871.082,168.4998,10.64218,0,0,0,0,100,0),
(@PATH,11,6870.944,145.7486,7.576735,0,0,0,0,100,0),
(@PATH,12,6872.436,128.7393,7.683223,0,0,0,0,100,0),
(@PATH,13,6877.127,115.8606,7.178462,0,0,0,0,100,0),
(@PATH,14,6885.765,110.6686,7.407832,0,0,0,0,100,0),
(@PATH,15,6896.64,107.7805,7.924678,0,0,0,0,100,0),
(@PATH,16,6911.659,110.723,7.987853,0,0,0,0,100,0);

-- Pathing for Twilight Fanatic Entry: 32888 'TDB FORMAT' 
SET @NPC := 260093;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6867.437,`position_y`=258.3246,`position_z`=11.47223 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6867.437,258.3246,11.47223,0,0,0,0,100,0),
(@PATH,2,6873.317,275.9132,11.87106,0,0,0,0,100,0),
(@PATH,3,6875.585,281.2715,11.57345,0,0,0,0,100,0),
(@PATH,4,6888.444,285.6841,11.71943,0,0,0,0,100,0),
(@PATH,5,6875.264,280.9003,11.76047,0,0,0,0,100,0),
(@PATH,6,6866.85,254.1372,11.75119,0,0,0,0,100,0),
(@PATH,7,6861.601,235.207,14.01228,0,0,0,0,100,0),
(@PATH,8,6861.519,218.7237,13.06638,0,0,0,0,100,0),
(@PATH,9,6866.079,207.4168,10.72429,0,0,0,0,100,0),
(@PATH,10,6862.422,215.7157,12.33571,0,0,0,0,100,0),
(@PATH,11,6861.315,223.1795,13.94405,0,0,0,0,100,0),
(@PATH,12,6864.38,244.7205,12.52484,0,0,0,0,100,0);

-- Pathing for Twilight Fanatic Entry: 32888 'TDB FORMAT' 
SET @NPC := 260104;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6803.426,`position_y`=170.3012,`position_z`=16.82818 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6803.426,170.3012,16.82818,0,0,0,0,100,0),
(@PATH,2,6806.263,186.2723,17.3586,0,0,0,0,100,0),
(@PATH,3,6819.214,200.4716,16.58287,0,0,0,0,100,0),
(@PATH,4,6830.084,214.1072,16.49259,0,0,0,0,100,0),
(@PATH,5,6839.63,230.7369,16.40366,0,0,0,0,100,0),
(@PATH,6,6829.777,213.9445,16.31444,0,0,0,0,100,0),
(@PATH,7,6819.214,200.4716,16.58287,0,0,0,0,100,0),
(@PATH,8,6806.263,186.2723,17.3586,0,0,0,0,100,0);

-- Pathing for Enthralled Earth Elemental Entry: 33058 'TDB FORMAT' 
SET @NPC := 315285;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5820.561,`position_y`=-121.0071,`position_z`=16.12423 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5820.561,-121.0071,16.12423,0,0,0,0,100,0),
(@PATH,2,5807.826,-101.6979,19.9954,0,0,0,0,100,0),
(@PATH,3,5806.935,-98.3638,21.16542,0,0,0,0,100,0),
(@PATH,4,5812.666,-77.26229,24.26128,0,0,0,0,100,0),
(@PATH,5,5815.359,-53.61518,22.21927,0,0,0,0,100,0),
(@PATH,6,5815.366,-69.13989,24.8548,0,0,0,0,100,0),
(@PATH,7,5809.308,-86.17673,22.99191,0,0,0,0,100,0),
(@PATH,8,5807.006,-97.99152,21.24799,0,0,0,0,100,0),
(@PATH,9,5813.304,-112.7094,17.30792,0,0,0,0,100,0),
(@PATH,10,5820.438,-121.129,16.13358,0,0,0,0,100,0),
(@PATH,11,5827.214,-130.8516,16.87419,0,0,0,0,100,0),
(@PATH,12,5835.785,-140.8633,15.99019,0,0,0,0,100,0),
(@PATH,13,5832.729,-137.7882,16.1165,0,0,0,0,100,0),
(@PATH,14,5823.876,-125.5016,15.91865,0,0,0,0,100,0);

-- Pathing for Enthralled Earth Elemental Entry: 33058 'TDB FORMAT' 
SET @NPC := 315287;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5808.927,`position_y`=-148.8282,`position_z`=-3.053004 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5808.927,-148.8282,-3.053004,0,0,0,0,100,0),
(@PATH,2,5802.896,-139.4884,-3.059315,0,0,0,0,100,0),
(@PATH,3,5795.539,-137.5016,-2.704766,0,0,0,0,100,0),
(@PATH,4,5791.682,-150.8412,0.7786703,0,0,0,0,100,0),
(@PATH,5,5793.471,-161.8667,5.361899,0,0,0,0,100,0),
(@PATH,6,5797.309,-175.5537,8.425787,0,0,0,0,100,0),
(@PATH,7,5788.411,-181.258,8.425739,0,0,0,0,100,0),
(@PATH,8,5779.882,-178.3024,11.06845,0,0,0,0,100,0),
(@PATH,9,5775.74,-170.114,13.07427,0,0,0,0,100,0),
(@PATH,10,5778.27,-177.003,11.65279,0,0,0,0,100,0),
(@PATH,11,5778.854,-177.7961,11.48596,0,0,0,0,100,0),
(@PATH,12,5795.152,-179.703,8.769825,0,0,0,0,100,0),
(@PATH,13,5795.101,-167.1949,7.347314,0,0,0,0,100,0),
(@PATH,14,5791.535,-156.1721,2.673098,0,0,0,0,100,0),
(@PATH,15,5792.682,-142.1777,-1.508863,0,0,0,0,100,0),
(@PATH,16,5796.202,-137.3857,-2.817325,0,0,0,0,100,0),
(@PATH,17,5802.579,-139.496,-2.964786,0,0,0,0,100,0),
(@PATH,18,5811.665,-154.574,-3.272311,0,0,0,0,100,0),
(@PATH,19,5814.487,-162.1497,-3.082276,0,0,0,0,100,0),
(@PATH,20,5813.974,-160.4351,-3.067814,0,0,0,0,100,0);

-- Pathing for Enthralled Earth Elemental Entry: 33058 'TDB FORMAT' 
SET @NPC := 315288;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5814.069,`position_y`=-199.0372,`position_z`=6.673443 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5814.069,-199.0372,6.673443,0,0,0,0,100,0),
(@PATH,2,5823.619,-185.1271,9.721956,0,0,0,0,100,0),
(@PATH,3,5838.491,-168.198,15.88406,0,0,0,0,100,0),
(@PATH,4,5845.921,-161.5283,16.20603,0,0,0,0,100,0),
(@PATH,5,5851.29,-151.6499,17.84514,0,0,0,0,100,0),
(@PATH,6,5850.197,-138.4522,23.03709,0,0,0,0,100,0),
(@PATH,7,5844.923,-120.2591,24.69491,0,0,0,0,100,0),
(@PATH,8,5846.337,-124.7687,24.4348,0,0,0,0,100,0),
(@PATH,9,5850.37,-138.3095,23.02853,0,0,0,0,100,0),
(@PATH,10,5851.357,-151.5398,17.80348,0,0,0,0,100,0),
(@PATH,11,5843.22,-163.9431,16.34752,0,0,0,0,100,0),
(@PATH,12,5831.983,-175.4485,13.40946,0,0,0,0,100,0),
(@PATH,13,5816.444,-193.2543,7.989729,0,0,0,0,100,0),
(@PATH,14,5814.352,-200.3254,6.493942,0,0,0,0,100,0),
(@PATH,15,5820.726,-216.2295,4.247161,0,0,0,0,100,0),
(@PATH,16,5836.152,-222.0003,2.050763,0,0,0,0,100,0),
(@PATH,17,5829.718,-220.1595,2.429072,0,0,0,0,100,0),
(@PATH,18,5815.342,-206.8544,5.401509,0,0,0,0,100,0);

-- Pathing for Horoo the Flamekeeper Entry: 34385 'TDB FORMAT' 
SET @NPC := 315271;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5944.877,`position_y`=62.78913,`position_z`=25.5901 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5944.877,62.78913,25.5901,0,0,0,0,100,0),
(@PATH,2,5960.68,64.46701,23.42866,0,0,0,0,100,0),
(@PATH,3,5987.251,51.73784,18.50991,0,0,0,0,100,0),
(@PATH,4,5995.24,40.76894,15.23792,0,0,0,0,100,0),
(@PATH,5,6001.361,31.2449,15.27518,0,0,0,0,100,0),
(@PATH,6,6018.31,16.46953,15.55856,0,0,0,0,100,0),
(@PATH,7,6034.508,0.9987111,15.93836,0,0,0,0,100,0),
(@PATH,8,6047.429,-11.54982,16.45337,0,0,0,0,100,0),
(@PATH,9,6034.36,1.309183,15.85757,0,0,0,0,100,0),
(@PATH,10,6018.097,16.82041,15.5601,0,0,0,0,100,0),
(@PATH,11,5990.006,48.90125,17.83001,0,0,0,0,100,0),
(@PATH,12,5964.421,63.73357,22.72399,0,0,0,0,100,0);
--
