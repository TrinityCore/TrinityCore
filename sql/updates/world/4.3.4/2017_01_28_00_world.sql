-- Whirlpool camera bunny is a trigger
UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry` IN (48648);

-- Remove bad spawns
DELETE FROM `creature` WHERE `guid` IN (315932,315920,315923,315403,315408,315409,315787,315788,315789,315790,315791,315792);
DELETE FROM `creature_addon` WHERE `guid` IN (315932,315920,315923,315403,315408,315409,315787,315788,315789,315790,315791,315792);

-- Fix location for Lor'danel Sentinel Entry: 32969
UPDATE `creature` SET `position_x`=7405.967,`position_y`=-123.9869,`position_z`=3.509157,`orientation`=0.3839724 WHERE `guid`=314984;
UPDATE `creature` SET `position_x`=7407.41,`position_y`=-128.1112,`position_z`=3.39502,`orientation`=0.2704744 WHERE `guid`=314987;
UPDATE `creature` SET `position_x`=7411.946,`position_y`=-129.9177,`position_z`=3.100831,`orientation`=0.1596799 WHERE `guid`=314978;
UPDATE `creature` SET `position_x`=7458.145,`position_y`=-223.173,`position_z`=5.286477,`orientation`=2.428539 WHERE `guid`=314990;

-- Greaymist Tidehunter, Greaymist Warrior, Shimmershell Snail, Corrupted Tide Crawler, Cursed Highbourne, Writhing Highbourne, Darkscale Scout
-- Wildkin Spirit
UPDATE `creature` SET `spawndist`=5,`MovementType`=1 WHERE `id` IN (33262,33277,48182,32935,33179,33180,33206,34304);

-- Flagglemurk the Cruel, Corrupted Thistle Bear, Darkshore Stage, Mottled Doe, Thistle Bear cub
UPDATE `creature` SET `spawndist`=10,`MovementType`=1 WHERE `id` IN (7015,33009,33311,33313,33903);

-- Corrupted Duskrat Should not have this aura
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=33884;

-- Forsaken Looter
UPDATE `creature` SET `spawndist`=5,`MovementType`=1 WHERE `guid` IN (315933,315936);

-- Pathing for Apothecary Furrows Entry: 33980 'TDB FORMAT' 
SET @NPC := 315901;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6766.749,`position_y`=-685.3788,`position_z`=69.84402 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6766.749,-685.3788,69.84402,0,0,0,0,100,0),
(@PATH,2,6766.749,-685.3788,69.84402,0.3839724,5000,0,0,100,0),
(@PATH,3,6766.982,-695.4534,69.87701,0,0,0,0,100,0),
(@PATH,4,6766.982,-695.4534,69.87701,6.126106,14000,0,0,100,0),
(@PATH,5,6764.227,-687.1804,69.85509,0,0,0,0,100,0);

-- Pathing for Vile Grell Entry: 33021 'TDB FORMAT' 
SET @NPC := 315135;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6736.511,`position_y`=-640.4534,`position_z`=68.91206 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6736.511,-640.4534,68.91206,0,0,1,0,100,0),
(@PATH,2,6739.302,-640.1891,68.8529,0,0,1,0,100,0),
(@PATH,3,6739.302,-640.1891,68.8529,2.129302,7000,0,0,100,0),
(@PATH,4,6734.394,-637.7097,69.15035,0,0,1,0,100,0),
(@PATH,5,6735.736,-633.965,69.35959,0,0,1,0,100,0),
(@PATH,6,6735.736,-633.965,69.35959,5.235988,5000,0,0,100,0);

-- Pathing for Vile Grell Entry: 33021 'TDB FORMAT' 
SET @NPC := 315153;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6872.594,`position_y`=-770.5278,`position_z`=60.65966 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6872.594,-770.5278,60.65966,0,0,1,0,100,0),
(@PATH,2,6872.594,-770.5278,60.65966,6.108652,10000,0,0,100,0),
(@PATH,3,6876.051,-767.4254,60.84224,0,0,1,0,100,0),
(@PATH,4,6876.051,-767.4254,60.84224,4.433136,10000,0,0,100,0);

-- Pathing for Vile Grell Entry: 33021 'TDB FORMAT' 
SET @NPC := 315142;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6800.378,`position_y`=-772.7652,`position_z`=69.56477 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6800.378,-772.7652,69.56477,0,0,1,0,100,0),
(@PATH,2,6800.378,-772.7652,69.56477,4.886922,11000,0,0,100,0),
(@PATH,3,6805.586,-775.4944,69.23468,0,0,1,0,100,0),
(@PATH,4,6805.586,-775.4944,69.23468,3.246312,11000,0,0,100,0);

-- Pathing for Vile Grell Entry: 33021 'TDB FORMAT' 
SET @NPC := 315143;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6809.584,`position_y`=-670.4387,`position_z`=64.80177 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6809.584,-670.4387,64.80177,0,0,1,0,100,0),
(@PATH,2,6806.946,-680.9832,64.8784,0,0,1,0,100,0),
(@PATH,3,6807.187,-690.1902,64.75293,0,0,1,0,100,0),
(@PATH,4,6812.018,-697.9299,64.3994,0,0,1,0,100,0),
(@PATH,5,6819.667,-698.6309,64.44962,0,0,1,0,100,0),
(@PATH,6,6828.85,-699.6611,64.27182,0,0,1,0,100,0),
(@PATH,7,6832.445,-687.606,64.21928,0,0,1,0,100,0),
(@PATH,8,6830.785,-677.3671,64.30475,0,0,1,0,100,0),
(@PATH,9,6822.043,-672.3708,64.50322,0,0,1,0,100,0),
(@PATH,10,6812.884,-670.9805,64.78618,0,0,1,0,100,0);

-- Pathing for Forsaken Looter Entry: 34046 'TDB FORMAT' 
SET @NPC := 315919;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7177.68,`position_y`=-760.519,`position_z`=59.03672 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7177.68,-760.519,59.03672,0,12000,0,0,100,0),
(@PATH,2,7185.777,-751.2477,59.03279,0,12000,0,0,100,0);

-- Pathing for Forsaken Looter Entry: 34046 'TDB FORMAT' 
SET @NPC := 315921;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7191.956,`position_y`=-716.5089,`position_z`=57.92269 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7191.956,-716.5089,57.92269,0,0,0,0,100,0),
(@PATH,2,7186.702,-717.8577,58.09237,0,0,0,0,100,0),
(@PATH,3,7181.096,-721.0053,58.12862,0,0,0,0,100,0),
(@PATH,4,7176.741,-724.6785,60.43246,0,0,0,0,100,0),
(@PATH,5,7181.096,-721.0053,58.12862,0,0,0,0,100,0),
(@PATH,6,7186.702,-717.8577,58.09237,0,0,0,0,100,0);

-- Pathing for Forsaken Looter Entry: 34046 'TDB FORMAT' 
SET @NPC := 315922;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7188.168,`position_y`=-747.6301,`position_z`=69.34828 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7188.168,-747.6301,69.34828,0,0,0,0,100,0),
(@PATH,2,7188.168,-747.6301,69.34828,0.6806784,18000,0,0,100,0),
(@PATH,3,7194.488,-739.9717,69.62007,0,0,0,0,100,0),
(@PATH,4,7197.025,-737.614,69.18649,0,18000,0,0,100,0),
(@PATH,5,7192.496,-740.9324,69.819,0,0,0,0,100,0),
(@PATH,6,7194.117,-745.0861,68.74011,0,0,0,0,100,0),
(@PATH,7,7196.959,-746.5308,67.12482,0,0,0,0,100,0),
(@PATH,8,7199.903,-745.9681,65.55296,0,0,0,0,100,0),
(@PATH,9,7201.908,-744.9346,64.16375,0,0,0,0,100,0),
(@PATH,10,7196.695,-746.5519,67.23624,0,0,0,0,100,0),
(@PATH,11,7194.534,-745.6495,68.41464,0,0,0,0,100,0),
(@PATH,12,7191.561,-743.5471,69.5268,0,0,0,0,100,0),
(@PATH,13,7187.519,-746.7962,69.34827,0,0,0,0,100,0),
(@PATH,14,7189.936,-749.5984,69.34828,0,0,0,0,100,0);

-- Pathing for Forsaken Looter Entry: 34046 'TDB FORMAT' 
SET @NPC := 315924;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7199.776,`position_y`=-742.1746,`position_z`=59.02187 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7199.776,-742.1746,59.02187,0,0,0,0,100,0),
(@PATH,2,7200.67,-738.9,59.02459,0,0,0,0,100,0),
(@PATH,3,7199.905,-736.1902,59.01844,0,0,0,0,100,0),
(@PATH,4,7197.378,-733.6581,59.02427,0,0,0,0,100,0),
(@PATH,5,7194.933,-733.4409,59.02668,0,0,0,0,100,0),
(@PATH,6,7194.933,-733.4409,59.02668,5.223136,26000,0,0,100,0),
(@PATH,7,7198.02,-739.1995,59.02069,0,0,0,0,100,0),
(@PATH,8,7193.837,-735.8347,59.01772,0,0,0,0,100,0),
(@PATH,9,7191.529,-737.7593,59.00806,0,0,0,0,100,0),
(@PATH,10,7194.459,-740.4893,59.00609,0,0,0,0,100,0),
(@PATH,11,7194.438,-743.5845,59.01817,0,0,0,0,100,0),
(@PATH,12,7196.067,-744.8092,59.0169,0,0,0,0,100,0);

-- Pathing for Forsaken Looter Entry: 34046 'TDB FORMAT' 
SET @NPC := 315927;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7201.604,`position_y`=-691.113,`position_z`=47.84871 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7201.604,-691.113,47.84871,0,0,0,0,100,0),
(@PATH,2,7201.604,-691.113,47.84871,0.296706,11000,0,0,100,0),
(@PATH,3,7189.275,-680.8945,44.13353,0,0,0,0,100,0),
(@PATH,4,7189.275,-680.8945,44.13353,2.740167,16000,0,0,100,0),
(@PATH,5,7192.775,-685.4963,44.32762,0,0,0,0,100,0),
(@PATH,6,7192.775,-685.4963,44.32762,4.904375,8000,0,0,100,0);

-- Pathing for Forsaken Looter Entry: 34046 'TDB FORMAT' 
SET @NPC := 315928;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7183.147,`position_y`=-706.2485,`position_z`=55.79305 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7183.147,-706.2485,55.79305,0,0,0,0,100,0),
(@PATH,2,7184.96,-711.3265,57.56307,0,0,0,0,100,0),
(@PATH,3,7190.958,-710.4654,58.10433,0,0,0,0,100,0),
(@PATH,4,7194.183,-709.8981,58.17269,0,0,0,0,100,0),
(@PATH,5,7197.338,-715.2917,57.78219,0,0,0,0,100,0),
(@PATH,6,7199.394,-716.0557,57.44357,0,0,0,0,100,0),
(@PATH,7,7199.705,-712.5112,57.79769,0,0,0,0,100,0),
(@PATH,8,7199.705,-712.5112,57.79769,1.343904,9000,0,0,100,0),
(@PATH,9,7192.151,-716.8735,57.92269,0,0,0,0,100,0),
(@PATH,10,7185.889,-712.4818,57.78597,0,12000,0,0,100,0),
(@PATH,11,7180.011,-711.0066,55.59505,0,0,0,0,100,0),
(@PATH,12,7176.788,-707.2032,53.13509,0,0,0,0,100,0),
(@PATH,13,7171.672,-704.7053,50.20272,0,0,0,0,100,0);

-- Pathing for Forsaken Looter Entry: 34046 'TDB FORMAT' 
SET @NPC := 315929;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7195.11,`position_y`=-726.1858,`position_z`=73.69622 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7195.11,-726.1858,73.69622,0,0,0,0,100,0),
(@PATH,2,7191.889,-726.8865,72.8548,0,0,0,0,100,0),
(@PATH,3,7189.361,-728.8406,72.42436,0,0,0,0,100,0),
(@PATH,4,7193.434,-726.7476,73.18609,0,0,0,0,100,0),
(@PATH,5,7197.421,-726.2888,74.51892,0,0,0,0,100,0),
(@PATH,6,7203.458,-727.8279,75.56367,0,0,0,0,100,0),
(@PATH,7,7203.458,-727.8279,75.56367,0.9599311,38000,0,0,100,0),
(@PATH,8,7203.458,-727.8279,75.56367,5.532694,60000,0,0,100,0);

-- Pathing for Forsaken Looter Entry: 34046 'TDB FORMAT' 
SET @NPC := 315931;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7217.735,`position_y`=-732.2157,`position_z`=57.02836 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7217.735,-732.2157,57.02836,0,0,0,0,100,0),
(@PATH,2,7216.357,-728.5892,58.05021,0,0,0,0,100,0),
(@PATH,3,7218.499,-734.0751,56.49741,0,0,0,0,100,0),
(@PATH,4,7218.499,-734.0751,56.49741,0.3316126,25000,0,0,100,0),
(@PATH,5,7221.922,-741.0486,56.03854,0,0,0,0,100,0);

-- Pathing for Forsaken Looter Entry: 34046 'TDB FORMAT' 
SET @NPC := 315935;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7248.61,`position_y`=-691.8707,`position_z`=32.22581 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7248.61,-691.8707,32.22581,0,0,0,0,100,0),
(@PATH,2,7239.967,-686.8516,34.62144,0,0,0,0,100,0),
(@PATH,3,7230.429,-685.4198,38.16957,0,0,0,0,100,0),
(@PATH,4,7230.429,-685.4198,38.16957,0.06981317,16000,0,0,100,0),
(@PATH,5,7234.086,-691.3945,36.49644,0,0,0,0,100,0),
(@PATH,6,7232.788,-693.8477,36.7024,0,0,0,0,100,0),
(@PATH,7,7243.922,-699.578,33.17528,0,0,0,0,100,0),
(@PATH,8,7243.922,-699.578,33.17528,5.759586,11000,0,0,100,0);

-- Pathing for Vile Corruptor Entry: 33022 'TDB FORMAT' 
SET @NPC := 315155;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6765.608,`position_y`=-647.3037,`position_z`=68.00615 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6765.608,-647.3037,68.00615,0,0,0,0,100,0),
(@PATH,2,6755.777,-645.4041,68.29015,0,0,0,0,100,0),
(@PATH,3,6745.452,-645.7691,68.4114,0,0,0,0,100,0),
(@PATH,4,6732.773,-648.8165,69.2528,0,0,0,0,100,0),
(@PATH,5,6720.875,-656.2098,69.42473,0,0,0,0,100,0),
(@PATH,6,6714.049,-668.3818,69.36121,0,0,0,0,100,0),
(@PATH,7,6720.875,-656.2098,69.42473,0,0,0,0,100,0),
(@PATH,8,6732.773,-648.8165,69.2528,0,0,0,0,100,0),
(@PATH,9,6745.452,-645.7691,68.4114,0,0,0,0,100,0),
(@PATH,10,6755.777,-645.4041,68.29015,0,0,0,0,100,0);

-- Pathing for Vile Corruptor Entry: 33022 'TDB FORMAT' 
SET @NPC := 315156;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6767.488,`position_y`=-700.1125,`position_z`=89.33279 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6767.488,-700.1125,89.33279,0,0,0,0,100,0),
(@PATH,2,6772.733,-681.5526,89.34745,0,0,0,0,100,0),
(@PATH,3,6782.262,-669.0615,89.34534,0,0,0,0,100,0),
(@PATH,4,6799.226,-663.6876,89.33282,0,0,0,0,100,0),
(@PATH,5,6817.322,-663.3174,86.953,0,0,0,0,100,0),
(@PATH,6,6836.274,-669.0125,84.46097,0,0,0,0,100,0),
(@PATH,7,6850.069,-672.0616,83.63032,0,0,0,0,100,0),
(@PATH,8,6836.274,-669.0125,84.46097,0,0,0,0,100,0),
(@PATH,9,6817.322,-663.3174,86.953,0,0,0,0,100,0),
(@PATH,10,6799.226,-663.6876,89.33282,0,0,0,0,100,0),
(@PATH,11,6782.262,-669.0615,89.34534,0,0,0,0,100,0),
(@PATH,12,6772.733,-681.5526,89.34745,0,0,0,0,100,0);

-- Pathing for Vile Corruptor Entry: 33022 'TDB FORMAT' 
SET @NPC := 315157;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6819.007,`position_y`=-685.1706,`position_z`=64.81625 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6819.007,-685.1706,64.81625,0,0,0,0,100,0),
(@PATH,2,6808.852,-675.7698,64.8784,0,0,0,0,100,0),
(@PATH,3,6792.804,-677.1729,67.17678,0,0,0,0,100,0),
(@PATH,4,6787.298,-694.2832,72.42098,0,0,0,0,100,0),
(@PATH,5,6790.598,-705.7642,74.22253,0,0,0,0,100,0),
(@PATH,6,6807.454,-713.2137,76.7362,0,0,0,0,100,0),
(@PATH,7,6818.073,-720.8569,78.39761,0,0,0,0,100,0),
(@PATH,8,6832.278,-715.6337,81.32961,0,0,0,0,100,0),
(@PATH,9,6842.809,-707.5815,82.92715,0,0,0,0,100,0),
(@PATH,10,6848.04,-692.9834,83.04761,0,0,0,0,100,0),
(@PATH,11,6842.809,-707.5815,82.92715,0,0,0,0,100,0),
(@PATH,12,6832.36,-715.6033,81.3393,0,0,0,0,100,0),
(@PATH,13,6818.073,-720.8569,78.39761,0,0,0,0,100,0),
(@PATH,14,6807.454,-713.2137,76.7362,0,0,0,0,100,0),
(@PATH,15,6790.598,-705.7642,74.22253,0,0,0,0,100,0),
(@PATH,16,6787.298,-694.2832,72.42098,0,0,0,0,100,0),
(@PATH,17,6792.804,-677.1729,67.17678,0,0,0,0,100,0),
(@PATH,18,6808.852,-675.7698,64.8784,0,0,0,0,100,0);

-- Pathing for Vile Corruptor Entry: 33022 'TDB FORMAT' 
SET @NPC := 315158;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6817.674,`position_y`=-706.4523,`position_z`=64.10796 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6817.674,-706.4523,64.10796,0,0,0,0,100,0),
(@PATH,2,6818.622,-716.7908,61.78214,0,0,0,0,100,0),
(@PATH,3,6820.366,-738.5843,59.88383,0,0,0,0,100,0),
(@PATH,4,6830.563,-752.2618,58.66794,0,0,0,0,100,0),
(@PATH,5,6846.628,-761.9297,59.38832,0,0,0,0,100,0),
(@PATH,6,6854.671,-773.7188,60.2253,0,0,0,0,100,0),
(@PATH,7,6852.72,-786.2754,61.47425,0,0,0,0,100,0),
(@PATH,8,6836.268,-795.285,64.62118,0,0,0,0,100,0),
(@PATH,9,6824.04,-784.2211,68.22215,0,0,0,0,100,0),
(@PATH,10,6836.268,-795.285,64.62118,0,0,0,0,100,0),
(@PATH,11,6852.72,-786.2754,61.47425,0,0,0,0,100,0),
(@PATH,12,6854.671,-773.7188,60.2253,0,0,0,0,100,0),
(@PATH,13,6846.628,-761.9297,59.38832,0,0,0,0,100,0),
(@PATH,14,6830.563,-752.2618,58.66794,0,0,0,0,100,0),
(@PATH,15,6820.366,-738.5843,59.88383,0,0,0,0,100,0);

-- Pathing for Lor'danel Sentinel Entry: 33115 'TDB FORMAT' 
SET @NPC := 315412;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7499.509,`position_y`=-294.8363,`position_z`=35.15154 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,22474,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 7499.509, -294.8363, 35.15154,0,0,1,0,100,0),
(@PATH, 2, 7499.285, -281.9187, 35.15154,0,0,1,0,100,0),
(@PATH, 3, 7507.077, -223.311, 35.15154,0,0,1,0,100,0),
(@PATH, 4, 7496.524, -177.0706, 35.15154,0,0,1,0,100,0),
(@PATH, 5, 7471.306, -158.0385, 35.15154,0,0,1,0,100,0),
(@PATH, 6, 7430.237, -174.9673, 35.15154,0,0,1,0,100,0),
(@PATH, 7, 7431.958, -214.4149, 35.15154,0,0,1,0,100,0),
(@PATH, 8, 7452.094, -242.7555, 35.15154,0,0,1,0,100,0),
(@PATH, 9, 7489.091, -262.7455, 35.15154,0,0,1,0,100,0),
(@PATH, 10, 7541.014, -266.2898, 35.15154,0,0,1,0,100,0),
(@PATH, 11, 7573.369, -305.1656, 35.15154,0,0,1,0,100,0),
(@PATH, 12, 7555.393, -334.4871, 35.15154,0,0,1,0,100,0),
(@PATH, 13, 7509.281, -330.2931, 35.15154,0,0,1,0,100,0);

-- Pathing for Lor'danel Sentinel Entry: 33115 'TDB FORMAT' 
SET @NPC := 315415;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7344.508,`position_y`=-196.5441,`position_z`=21.65709 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,22474,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 7344.508, -196.5441, 21.65709,0,0,1,0,100,0),
(@PATH, 2, 7332.405, -194.5552, 21.65709,0,0,1,0,100,0),
(@PATH, 3, 7298.426, -194.4225, 21.65709,0,0,1,0,100,0),
(@PATH, 4, 7280.807, -224.0089, 26.82377,0,0,1,0,100,0),
(@PATH, 5, 7283.773, -284.3799, 29.29599,0,0,1,0,100,0),
(@PATH, 6, 7320.993, -351.2531, 26.01821,0,0,1,0,100,0),
(@PATH, 7, 7352.619, -354.2096, 27.57376,0,0,1,0,100,0),
(@PATH, 8, 7386.786, -333.7047, 29.4071,0,0,1,0,100,0),
(@PATH, 9, 7394.262, -293.7051, 23.74043,0,0,1,0,100,0),
(@PATH, 10, 7391.187, -258.1592, 21.65709,0,0,1,0,100,0),
(@PATH, 11, 7373.832, -223.4427, 21.65709,0,0,1,0,100,0);

-- Pathing for Lor'danel Sentinel Entry: 33115 'TDB FORMAT' 
SET @NPC := 315416;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7437.086,`position_y`=-172.2867,`position_z`=16.97672 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,22474,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 7437.086, -172.2867, 16.97672,0,0,1,0,100,0),
(@PATH, 2, 7433.918, -142.7918, 16.97672,0,0,1,0,100,0),
(@PATH, 3, 7433.939, -126.3797, 16.97672,0,0,1,0,100,0),
(@PATH, 4, 7436.127, -90.80317, 15.69894,0,0,1,0,100,0),
(@PATH, 5, 7434.67, -57.73904, 10.17116,0,0,1,0,100,0),
(@PATH, 6, 7413.789, -26.47049, 9.476728,0,0,1,0,100,0),
(@PATH, 7, 7413.504, 4.67296, 13.58783,0,0,1,0,100,0),
(@PATH, 8, 7426.699, 41.96832, 19.86561,0,0,1,0,100,0),
(@PATH, 9, 7433.827, 80.95823, 19.28228,0,0,1,0,100,0),
(@PATH, 10, 7426.461, 132.9439, 16.97672,0,0,1,0,100,0),
(@PATH, 11, 7410.144, 175.1382, 21.69894,0,0,1,0,100,0),
(@PATH, 12, 7414.363, 222.886, 31.19895,0,0,1,0,100,0),
(@PATH, 13, 7450.488, 233.3828, 26.5045,0,0,1,0,100,0),
(@PATH, 14, 7488.843, 197.5329, 16.97672,0,0,1,0,100,0),
(@PATH, 15, 7502.77, 133.5547, 16.97672,0,0,1,0,100,0),
(@PATH, 16, 7509.401, 57.51899, 16.97672,0,0,1,0,100,0),
(@PATH, 17, 7507.268, -12.94553, 16.97672,0,0,1,0,100,0),
(@PATH, 18, 7502.201, -65.74273, 16.97672,0,0,1,0,100,0),
(@PATH, 19, 7496.602, -140.7608, 16.97672,0,0,1,0,100,0),
(@PATH, 20, 7468.624, -171.9021, 16.97672,0,0,1,0,100,0);
--