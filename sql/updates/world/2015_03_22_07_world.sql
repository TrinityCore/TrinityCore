-- Pathing for Guardian Lasher Entry: 33430 'TDB FORMAT' 
SET @NPC := 136608;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2409.214,`position_y`=39.68574,`position_z`=430.8202 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2409.214,39.68574,430.8202,0,0,0,0,100,0),
(@PATH,2,2419.765,55.44238,432.5078,0,0,0,0,100,0),
(@PATH,3,2412.965,68.34785,436.2759,0,0,0,0,100,0),
(@PATH,4,2392.464,56.26165,433.3107,0,0,0,0,100,0);

-- Pathing for Guardian Lasher Entry: 33430 'TDB FORMAT' 
SET @NPC := 136606;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2279.508,`position_y`=-143.8644,`position_z`=435.7896 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2279.508,-143.8644,435.7896,0,0,0,0,100,0),
(@PATH,2,2294.608,-141.4411,434.8279,0,0,0,0,100,0),
(@PATH,3,2297.896,-140.7821,434.6606,0,0,0,0,100,0),
(@PATH,4,2300.045,-107.6998,432.8321,0,0,0,0,100,0),
(@PATH,5,2282.262,-122.0434,432.8238,0,0,0,0,100,0),
(@PATH,6,2262.708,-113.97,431.0626,0,0,0,0,100,0),
(@PATH,7,2246.123,-120.2917,433.473,0,0,0,0,100,0),
(@PATH,8,2252.349,-127.7779,432.1354,0,0,0,0,100,0);

-- Pathing for Guardian Lasher Entry: 33430 'TDB FORMAT' 
SET @NPC := 136604;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2348.184,`position_y`=-33.40479,`position_z`=425.1163 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2348.184,-33.40479,425.1163,0,0,0,0,100,0),
(@PATH,2,2321.229,-1.325779,426.4646,0,0,0,0,100,0),
(@PATH,3,2314.177,14.98683,429.6667,0,0,0,0,100,0),
(@PATH,4,2318.373,3.474962,427.6927,0,0,0,0,100,0),
(@PATH,5,2346.51,-30.4225,424.8373,0,0,0,0,100,0),
(@PATH,6,2325.816,-64.16115,426.2005,0,0,0,0,100,0);

-- Pathing for Hired Engineer Entry: 33626 'TDB FORMAT' 
SET @NPC := 136355;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-714.6555,`position_y`=-17.16721,`position_z`=429.8806 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-714.6555,-17.16721,429.8806,3.124139,2000,0,0,100,0), -- 10:58:06
(@PATH,2,-718.4268,-23.51997,429.8806,0,0,0,0,100,0), -- 10:58:08
(@PATH,3,-718.511,-23.33659,430.1306,0,0,0,0,100,0), -- 10:58:10
(@PATH,4,-722.3708,-23.03671,430.1306,0,0,0,0,100,0), -- 10:58:12
(@PATH,5,-724.927,-20.31805,430.1306,0,0,0,0,100,0), -- 10:58:13
(@PATH,6,-725.4897,-15.76975,429.8806,6.178465,3000,0,0,100,0), -- 10:58:16
(@PATH,7,-724.358,-22.59787,429.8806,0,0,0,0,100,0), -- 10:58:19
(@PATH,8,-724.1555,-22.44646,430.1306,0,0,0,0,100,0), -- 10:58:20
(@PATH,9,-719.5723,-23.93241,430.1306,0,0,0,0,100,0), -- 10:58:23
(@PATH,10,-715.4219,-21.92954,430.1306,0,0,0,0,100,0); -- 10:58:25

-- Pathing for Hired Engineer Entry: 33626 'TDB FORMAT' 
SET @NPC := 136359;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-821.8198,`position_y`=-33.27892,`position_z`=430.2184 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-821.8198,-33.27892,430.2184,0,0,0,0,100,0),
(@PATH,2,-822.3601,-31.65381,430.2184,0,0,0,0,100,0),
(@PATH,3,-824.5154,-34.64041,429.9684,0,0,0,0,100,0),
(@PATH,4,-824.2672,-34.39585,430.2184,0,0,0,0,100,0),
(@PATH,5,-821.0198,-37.88292,429.9684,0.4537856,2000,0,0,100,0);

-- Pathing for Hired Engineer Entry: 33626 'TDB FORMAT' 
SET @NPC := 136357;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-754.7864,`position_y`=-36.70388,`position_z`=429.9034 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-754.7864,-36.70388,429.9034,0,0,0,0,100,0),
(@PATH,2,-751.721,-35.1428,429.9657,0,0,0,0,100,0),
(@PATH,3,-751.8016,-34.96943,430.1835,0,0,0,0,100,0),
(@PATH,4,-751.6813,-31.36849,429.9659,2.617994,2000,0,0,100,0);

-- Pathing for Hired Engineer Entry: 33626 'TDB FORMAT' 
SET @NPC := 136347;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-806.7797,`position_y`=-61.91017,`position_z`=430.2184 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-806.7797,-61.91017,430.2184,0,0,0,0,100,0), -- 10:58:05
(@PATH,2,-805.1627,-65.66473,430.1716,0,0,0,0,100,0), -- 10:58:06
(@PATH,3,-807.4543,-68.63271,429.8748,2.460914,2000,0,0,100,0), -- 10:58:09
(@PATH,4,-810.992,-72.29839,429.8748,0,0,0,0,100,0), -- 10:58:11
(@PATH,5,-811.0092,-71.93497,430.1248,0,0,0,0,100,0), -- 10:58:12
(@PATH,6,-819.4515,-69.41702,429.9216,0,0,0,0,100,0), -- 10:58:16
(@PATH,7,-821.9469,-64.33131,430.2059,0,0,0,0,100,0), -- 10:58:18
(@PATH,8,-819.5031,-58.79203,430.2184,0,0,0,0,100,0), -- 10:58:20
(@PATH,9,-817.4072,-59.57487,429.9684,4.729842,2000,0,0,100,0), -- 10:58:23
(@PATH,10,-807.0515,-61.87196,429.9684,0,0,0,0,100,0); -- 10:58:25

-- Pathing for Hired Engineer Entry: 33626 'TDB FORMAT' 
SET @NPC := 136356;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-785.7463,`position_y`=-41.38455,`position_z`=429.9659 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-785.7463,-41.38455,429.9659,0,0,0,0,100,0), -- 10:58:08
(@PATH,2,-785.3948,-41.14034,430.2159,0,0,0,0,100,0), -- 10:58:09
(@PATH,3,-782.2135,-41.35977,430.2159,0,0,0,0,100,0), -- 10:58:10
(@PATH,4,-779.5613,-40.3548,430.2159,0,0,0,0,100,0), -- 10:58:11
(@PATH,5,-777.8319,-36.41965,430.183,0,0,0,0,100,0), -- 10:58:14
(@PATH,6,-778.6835,-33.0957,429.9001,3.420845,2000,0,0,100,0), -- 10:58:16
(@PATH,7,-779.9354,-28.00385,429.9001,0,0,0,0,100,0), -- 10:58:18
(@PATH,8,-779.8657,-28.03287,430.1501,0,0,0,0,100,0), -- 10:58:20
(@PATH,9,-784.348,-25.80318,430.1501,0,0,0,0,100,0), -- 10:58:21
(@PATH,10,-788.9271,-27.93935,430.183,0,0,0,0,100,0), -- 10:58:23
(@PATH,11,-791.5985,-34.02659,430.1966,0,0,0,0,100,0), -- 10:58:26
(@PATH,12,-790.8046,-36.75038,430.2113,0,0,0,0,100,0); -- 10:58:27

-- Pathing for Hired Engineer Entry: 33626 'TDB FORMAT' 
SET @NPC := 136349;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-808.118,`position_y`=-40.2321,`position_z`=429.9684 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-808.118,-40.2321,429.9684,0,0,0,0,100,0),
(@PATH,2,-807.7555,-40.07573,430.2184,0,0,0,0,100,0),
(@PATH,3,-804.9432,-39.92784,430.2184,0,0,0,0,100,0),
(@PATH,4,-807.1721,-39.73579,430.2184,0,0,0,0,100,0),
(@PATH,5,-808.9033,-36.34509,430.2184,0,0,0,0,100,0);

-- Pathing for Hired Engineer Entry: 33626 'TDB FORMAT' 
SET @NPC := 136350;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-712.0216,`position_y`=-106.3855,`position_z`=430.3862 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-712.0216,-106.3855,430.3862,0,0,0,0,100,0), -- 10:58:08
(@PATH,2,-712.1302,-106.2594,430.5872,0,0,0,0,100,0), -- 10:58:09
(@PATH,3,-712.4497,-100.7512,430.033,0,0,0,0,100,0), -- 10:58:11
(@PATH,4,-714.1099,-98.13288,430.1651,0,0,0,0,100,0), -- 10:58:12
(@PATH,5,-717.9264,-97.92854,430.2126,0,0,0,0,100,0), -- 10:58:14
(@PATH,6,-720.3586,-98.40739,430.1744,0,0,0,0,100,0), -- 10:58:18
(@PATH,7,-722.0936,-101.579,430.1653,0,0,0,0,100,0), -- 10:58:20
(@PATH,8,-722.2216,-104.0047,430.1362,0,0,0,0,100,0), -- 10:58:21
(@PATH,9,-721.8704,-107.3522,429.9794,0,0,0,0,100,0), -- 10:58:22
(@PATH,10,-719.009,-109.2184,430.31,0,0,0,0,100,0), -- 10:58:23
(@PATH,11,-717.5231,-108.9742,430.4017,0,0,0,0,100,0); -- 10:58:25

-- Pathing for Hired Engineer Entry: 33626 'TDB FORMAT' 
SET @NPC := 136360;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-805.7245,`position_y`=-92.51467,`position_z`=429.9373 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-805.7245,-92.51467,429.9373,0,0,0,0,100,0),
(@PATH,2,-809.9697,-93.78546,430.1968,0,0,0,0,100,0),
(@PATH,3,-813.4847,-92.64854,429.9998,1.518436,3000,0,0,100,0),
(@PATH,4,-821.6218,-88.66959,429.8748,0,0,0,0,100,0),
(@PATH,5,-821.3884,-88.30928,430.1454,0,0,0,0,100,0),
(@PATH,6,-820.6511,-83.99181,430.1248,0,0,0,0,100,0),
(@PATH,7,-819.0802,-80.95631,430.1201,0,0,0,0,100,0),
(@PATH,8,-815.6989,-79.63522,429.9362,0,0,0,0,100,0),
(@PATH,9,-812.4637,-81.22309,429.9998,4.45059,2000,0,0,100,0),
(@PATH,10,-805.8566,-83.38759,429.9998,0,0,0,0,100,0),
(@PATH,11,-805.8384,-83.39809,430.1873,0,0,0,0,100,0),
(@PATH,12,-804.1865,-87.55893,430.1577,0,0,0,0,100,0);

-- Pathing for Hired Demolitionist Entry: 33627 'TDB FORMAT' 
SET @NPC := 136369;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-741.3947,`position_y`=-207.9769,`position_z`=431.7578 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-741.3947,-207.9769,431.7578,0,0,0,0,100,0),
(@PATH,2,-742.5634,-205.1704,431.0431,0,0,0,0,100,0),
(@PATH,3,-746.6194,-203.6891,430.4383,0,0,0,0,100,0),
(@PATH,4,-751.6924,-207.3801,430.4216,0,0,0,0,100,0),
(@PATH,5,-752.3352,-214.3417,431.4221,0,0,0,0,100,0),
(@PATH,6,-751.818,-216.1215,431.7806,0,0,0,0,100,0),
(@PATH,7,-752.1444,-209.4591,430.6995,0,0,0,0,100,0),
(@PATH,8,-752.5813,-208.6543,430.434,0,0,0,0,100,0),
(@PATH,9,-749.45,-205.2882,430.5325,0,0,0,0,100,0),
(@PATH,10,-742.3865,-205.8632,431.1866,0,0,0,0,100,0),
(@PATH,11,-740.8467,-209.625,432.1345,0,0,0,0,100,0),
(@PATH,12,-740.2542,-212.8133,432.6738,3.438299,3000,0,0,100,0);

-- Pathing for Hired Demolitionist Entry: 33627 'TDB FORMAT' 
SET @NPC := 136366;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-712.1467,`position_y`=-168.2411,`position_z`=432.9551 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-712.1467,-168.2411,432.9551,0,0,0,0,100,0),
(@PATH,2,-711.2845,-169.7373,433.5219,0,0,0,0,100,0),
(@PATH,3,-718.3967,-173.3105,431.6536,0,0,0,0,100,0),
(@PATH,4,-722.842,-172.8361,430.3402,0,0,0,0,100,0),
(@PATH,5,-723.5557,-172.3758,430.0638,0,0,0,0,100,0),
(@PATH,6,-724.2864,-166.9745,429.9667,0.7853982,3000,0,0,100,0),
(@PATH,7,-727.4843,-162.5646,429.9667,0,0,0,0,100,0),
(@PATH,8,-727.1448,-162.4384,430.2167,0,0,0,0,100,0),
(@PATH,9,-725.0723,-159.2923,430.2167,0,0,0,0,100,0),
(@PATH,10,-719.7878,-157.1184,430.2519,0,0,0,0,100,0),
(@PATH,11,-715.3311,-160.4503,430.7693,0,0,0,0,100,0),
(@PATH,12,-713.6705,-163.3997,431.3184,0,0,0,0,100,0);

-- Pathing for Hired Demolitionist Entry: 33627 'TDB FORMAT' 
SET @NPC := 136361;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-715.4345,`position_y`=-120.4184,`position_z`=430.8215 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-715.4345,-120.4184,430.8215,0,0,0,0,100,0),
(@PATH,2,-715.2732,-119.9876,430.8068,0,0,0,0,100,0),
(@PATH,3,-713.6184,-118.4633,430.9174,0,0,0,0,100,0),
(@PATH,4,-714.1099,-115.8266,430.8853,0,0,0,0,100,0),
(@PATH,5,-718.0544,-115.391,430.4921,0,0,0,0,100,0),
(@PATH,6,-720.8175,-116.2792,430.0629,0,0,0,0,100,0),
(@PATH,7,-721.2681,-119.6442,430.1362,0,0,0,0,100,0),
(@PATH,8,-721.4601,-123.3716,430.1362,0,0,0,0,100,0),
(@PATH,9,-721.3339,-127.6245,429.9487,0,0,0,0,100,0),
(@PATH,10,-718.5485,-128.1067,430.2194,0,0,0,0,100,0);

-- Pathing for Hired Demolitionist Entry: 33627 'TDB FORMAT' 
SET @NPC := 136365;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-798.1786,`position_y`=-248.1221,`position_z`=432.4507 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-798.1786,-248.1221,432.4507,0,0,0,0,100,0),
(@PATH,2,-798.7401,-245.9213,431.4652,0,0,0,0,100,0),
(@PATH,3,-799.3177,-242.9683,430.5485,0,0,0,0,100,0),
(@PATH,4,-797.5398,-247.3222,432.0694,0,0,0,0,100,0),
(@PATH,5,-796.4919,-249.3278,432.7336,0,0,0,0,100,0),
(@PATH,6,-789.5071,-248.2485,433.1029,0,0,0,0,100,0),
(@PATH,7,-786.5637,-240.1779,432.2992,0,0,0,0,100,0),
(@PATH,8,-789.908,-234.2144,431.4653,0,0,0,0,100,0),
(@PATH,9,-791.3019,-233.3431,430.7617,4.206244,2000,0,0,100,0),
(@PATH,10,-787.354,-241.1295,432.3823,0,0,0,0,100,0),
(@PATH,11,-786.8214,-247.0664,433.4664,0,0,0,0,100,0),
(@PATH,12,-787.0446,-247.7635,433.499,0,0,0,0,100,0);

-- Pathing for Hired Demolitionist Entry: 33627 'TDB FORMAT' 
SET @NPC := 136367;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-767.8429,`position_y`=-217.267,`position_z`=429.9667 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-767.8429,-217.267,429.9667,0,0,0,0,100,0),
(@PATH,2,-767.6378,-217.1616,430.0292,0,0,0,0,100,0),
(@PATH,3,-761.6285,-219.4796,430.4327,0,0,0,0,100,0),
(@PATH,4,-760.9791,-222.4792,430.8569,3.281219,2000,0,0,100,0),
(@PATH,5,-761.7565,-231.0529,432.8887,0,0,0,0,100,0),
(@PATH,6,-761.9493,-231.9112,433.0276,0,0,0,0,100,0),
(@PATH,7,-770.1174,-232.0044,432.3535,0,0,0,0,100,0),
(@PATH,8,-772.8343,-227.3204,431.1874,0,0,0,0,100,0),
(@PATH,9,-772.8062,-223.4772,430.3036,0,0,0,0,100,0),
(@PATH,10,-772.7734,-222.031,429.9667,0,0,0,0,100,0);

-- Pathing for Hired Demolitionist Entry: 33627 'TDB FORMAT' 
SET @NPC := 136368;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-731.2537,`position_y`=-177.8654,`position_z`=430.2253 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-731.2537,-177.8654,430.2253,0,0,0,0,100,0),
(@PATH,2,-727.3505,-179.0715,430.0485,4.39823,3000,0,0,100,0),
(@PATH,3,-734.2864,-179.9329,429.8522,0,0,0,0,100,0),
(@PATH,4,-734.1282,-180.0425,429.9078,0,0,0,0,100,0),
(@PATH,5,-735.3954,-183.6396,429.8522,5.8294,2000,0,0,100,0),
(@PATH,6,-731.4017,-177.9422,429.9667,0,0,0,0,100,0);

-- Pathing for Weslex Quickwrench Entry: 33629 'TDB FORMAT' 
SET @NPC := 136370;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-744.1992,`position_y`=-41.8189,`position_z`=429.9657 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,14374,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-744.1992,-41.8189,429.9657,1.919862,3000,0,0,100,0),
(@PATH,2,-722.2444,-31.58008,429.8806,0,0,0,0,100,0),
(@PATH,3,-722.0319,-31.24901,430.1359,0,0,0,0,100,0),
(@PATH,4,-715.6211,-29.15961,429.8806,1.884956,2000,0,0,100,0),
(@PATH,5,-743.2397,-42.08398,429.9657,0,0,0,0,100,0);

-- Earthen Stoneshaper ,Goran Steelbreaker, Ulduar Shield Bunny should not have movement
UPDATE `creature` SET `modelid`=0,`spawndist`=0,`MovementType`=0, `curhealth`=1 WHERE `id` IN (33620,33622,33779);
