-- Wrong npc spawned, should be a Stormwind Infantry npc
UPDATE `creature` SET `id`=16864 WHERE `guid`=57934;

-- Pathing for Stormwind Infantry Entry: 16864 'TDB FORMAT' 
SET @NPC := 57934;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-702.9703,`position_y`=1826.119,`position_z`=75.24933 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-702.9703,1826.119,75.24933,0,0,0,0,100,0),
(@PATH,2,-707.4134,1826.754,75.24933,0,0,0,0,100,0);
-- 0x1C09E4424010780000002B00009A4063 .go -702.9703 1826.119 75.24933

DELETE FROM `creature_formations` WHERE `leaderGUID`=57965;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(57965, 57965, 0, 0, 2),
(57965, 57966, 5, 0, 2),
(57965, 57967, 10, 0, 2),
(57965, 57968, 15, 0, 2);

-- SAI Set Run On is bugged, if fixed this will work.
-- Honor Hold Cavalryman SAI
SET @ENTRY := 16843;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Honor Hold Cavalryman - On Respawn - Set Run On");

-- Pathing for Honor Hold Cavalryman Entry: 16843 'TDB FORMAT' 
SET @NPC := 57965;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-693.6425,`position_y`=2675.357,`position_z`=93.08069 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,2410,0,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-693.6425,2675.357,93.08069,0,0,0,0,100,0),
(@PATH,2,-678.617,2653.904,90.11584,0,0,0,0,100,0),
(@PATH,3,-670.0779,2623.337,87.22372,0,0,0,0,100,0),
(@PATH,4,-647.809,2588.676,83.14737,0,0,0,0,100,0),
(@PATH,5,-620.405,2546.836,73.68471,0,0,0,0,100,0),
(@PATH,6,-604.7114,2503.37,64.40894,0,0,0,0,100,0),
(@PATH,7,-603.8063,2468.986,57.10122,0,0,0,0,100,0),
(@PATH,8,-604.4416,2435.113,50.43313,0,0,0,0,100,0),
(@PATH,9,-599.5267,2409.476,44.74646,0,0,0,0,100,0),
(@PATH,10,-584.7905,2406.665,43.70581,0,0,0,0,100,0),
(@PATH,11,-582.3721,2430.458,47.94434,0,0,0,0,100,0),
(@PATH,12,-582.2322,2463.321,53.99577,0,0,0,0,100,0),
(@PATH,13,-583.6086,2498.498,61.39573,0,0,0,0,100,0),
(@PATH,14,-558.1572,2532.4,67.07269,0,0,0,0,100,0),
(@PATH,15,-524.5069,2553.839,65.79486,0,0,0,0,100,0),
(@PATH,16,-505.5841,2594.287,68.31036,0,0,0,0,100,0),
(@PATH,17,-504.4444,2604.637,70.43836,0,0,0,0,100,0),
(@PATH,18,-510.0499,2664.531,70.29152,0,0,0,0,100,0),
(@PATH,19,-511.0184,2694.743,68.82625,0,0,0,0,100,0),
(@PATH,20,-517.2742,2716.729,67.8214,0,0,0,0,100,0),
(@PATH,21,-534.5939,2747.733,69.1256,0,0,0,0,100,0),
(@PATH,22,-565.1152,2807.142,63.14902,0,0,0,0,100,0),
(@PATH,23,-596.1111,2836.904,59.59448,0,0,0,0,100,0),
(@PATH,24,-630.4422,2866.988,51.1272,0,0,0,0,100,0),
(@PATH,25,-678.3279,2883.457,47.06744,0,0,0,0,100,0),
(@PATH,26,-723.3876,2887.968,33.10106,0,0,0,0,100,0),
(@PATH,27,-762.0458,2886.646,24.27474,0,0,0,0,100,0),
(@PATH,28,-792.7939,2863.772,21.49371,0,0,0,0,100,0),
(@PATH,29,-819.7803,2843.219,19.12334,0,0,0,0,100,0),
(@PATH,30,-873.9691,2815.151,15.98937,0,0,0,0,100,0),
(@PATH,31,-893.9761,2802.479,14.45792,0,0,0,0,100,0),
(@PATH,32,-897.1367,2771.076,20.99353,0,0,0,0,100,0),
(@PATH,33,-867.2095,2775.483,38.31301,0,0,0,0,100,0),
(@PATH,34,-860.2045,2761.954,45.71127,0,0,0,0,100,0),
(@PATH,35,-868.9539,2736.927,57.97308,0,0,0,0,100,0),
(@PATH,36,-871.5066,2701.324,78.20714,0,0,0,0,100,0),
(@PATH,37,-856.217,2675.711,92.33214,0,0,0,0,100,0),
(@PATH,38,-833.6348,2676.617,98.47594,0,0,0,0,100,0),
(@PATH,39,-808.0863,2687.279,104.1725,0,0,0,0,100,0),
(@PATH,40,-790.8087,2689.64,104.0867,0,0,0,0,100,0),
(@PATH,41,-724.9875,2676.18,96.8718,0,0,0,0,100,0);
-- 0x1C09E442401072C000002000004EA00B .go -693.6425 2675.357 93.08069

DELETE FROM `creature_formations` WHERE `leaderGUID`=57937;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(57937, 57937, 0, 0, 2),
(57937, 57923, 3, 90, 2);

-- Pathing for Honor Hold Defender Entry: 16842 'TDB FORMAT' 
SET @NPC := 57937;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-872.1663,`position_y`=2769.454,`position_z`=37.44319 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-872.1663,2769.454,37.44319,0,0,0,0,100,0),
(@PATH,2,-869.7395,2768.148,39.13062,0,0,0,0,100,0),
(@PATH,3,-865.2796,2739.821,56.70609,0,0,0,0,100,0),
(@PATH,4,-867.5071,2718.566,68.9836,0,0,0,0,100,0),
(@PATH,5,-867.6776,2699.037,79.59444,0,0,0,0,100,0),
(@PATH,6,-857.8785,2686.67,88.437,0,0,0,0,100,0),
(@PATH,7,-842.5071,2678.96,95.25343,0,0,0,0,100,0),
(@PATH,8,-822.5238,2681.506,102.4034,0,0,0,0,100,0),
(@PATH,9,-817.7297,2683.09,103.48,0,0,0,0,100,0),
(@PATH,10,-817.5452,2683.404,103.4257,0,0,0,0,100,0),
(@PATH,11,-838.7125,2678.288,96.64885,0,0,0,0,100,0),
(@PATH,12,-856.334,2685.094,89.30038,0,0,0,0,100,0),
(@PATH,13,-866.9412,2697.539,80.50797,0,0,0,0,100,0),
(@PATH,14,-867.8522,2713.977,71.4567,0,0,0,0,100,0),
(@PATH,15,-865.3911,2736.797,58.61076,0,0,0,0,100,0),
(@PATH,16,-866.6399,2765.021,41.61932,0,0,0,0,100,0);
-- 0x1C09E4424010728000002D00001E733B .go -872.1663 2769.454 37.44319

-- Pathing for Honor Hold Archer Entry: 16896 'TDB FORMAT' 
SET @NPC := 58441;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-794.1317,`position_y`=2601.671,`position_z`=133.2523 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-794.1317,2601.671,133.2523,0,0,0,0,100,0),
(@PATH,2,-778.0168,2611.436,133.2532,0,0,0,0,100,0);
-- 0x1C09E4424010800000001F00004BCB3D .go -794.1317 2601.671 133.2523

-- Pathing for Honor Hold Archer Entry: 16896 'TDB FORMAT' 
SET @NPC := 58440;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-800.5278,`position_y`=2648.273,`position_z`=133.2537 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-800.5278,2648.273,133.2537,0,0,0,0,100,0),
(@PATH,2,-816.2895,2638.862,133.2529,0,0,0,0,100,0);
-- 0x1C09E4424010800000001F00004BCB47 .go -800.5278 2648.273 133.2537

-- Pathing for Honor Hold Archer Entry: 16896 'TDB FORMAT' 
SET @NPC := 58448;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-697.1456,`position_y`=2567.732,`position_z`=101.4374 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-697.1456,2567.732,101.4374,0,0,0,0,100,0),
(@PATH,2,-683.9911,2574.386,100.8064,0,0,0,0,100,0),
(@PATH,3,-683.9779,2574.394,100.8655,0,0,0,0,100,0),
(@PATH,4,-697.2676,2567.764,101.4445,0,0,0,0,100,0),
(@PATH,5,-682.3236,2567.782,100.8602,0,0,0,0,100,0);
-- 0x1C09E4424010800000001F00014B15DB .go -697.1456 2567.732 101.4374


-- Pathing for Honor Hold Archer Entry: 16896 'TDB FORMAT' 
SET @NPC := 58442;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-750.128,`position_y`=2567.929,`position_z`=104.1502 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-750.128,2567.929,104.1502,0,0,0,0,100,0),
(@PATH,2,-746.1736,2566.977,104.3655,0,0,0,0,100,0),
(@PATH,3,-732.6676,2565.869,104.5501,0,0,0,0,100,0),
(@PATH,4,-754.0043,2574.421,104.1675,0,0,0,0,100,0),
(@PATH,5,-754.0061,2574.378,104.2026,0,0,0,0,100,0),
(@PATH,6,-732.6328,2565.721,104.5407,0,0,0,0,100,0),
(@PATH,7,-746.1768,2566.991,104.2605,0,0,0,0,100,0);
-- 0x1C09E4424010800000001F00024B15DA .go -750.128 2567.929 104.1502

-- Pathing for Honor Hold Archer Entry: 16896 'TDB FORMAT' 
SET @NPC := 58452;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-674.274,`position_y`=2787.06,`position_z`=109.5986 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-674.274,2787.06,109.5986,0,0,0,0,100,0),
(@PATH,2,-661.9408,2782.68,107.5661,0,0,0,0,100,0),
(@PATH,3,-645.2046,2773.514,104.8345,0,0,0,0,100,0),
(@PATH,4,-664.4965,2777.165,107.6214,0,0,0,0,100,0),
(@PATH,5,-664.445,2776.807,107.7074,0,0,0,0,100,0),
(@PATH,6,-645.4469,2773.186,104.7909,0,0,0,0,100,0);
-- 0x1C09E4424010800000001F0003CB15DA .go -674.274 2787.06 109.5986

-- Pathing for Honor Hold Archer Entry: 16896 'TDB FORMAT' 
SET @NPC := 58453;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-607.841,`position_y`=2612.785,`position_z`=99.32381 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-607.841,2612.785,99.32381,0,0,0,0,100,0),
(@PATH,2,-604.588,2617.701,99.53741,0,0,0,0,100,0),
(@PATH,3,-605.6599,2620.353,99.11266,0,0,0,0,100,0),
(@PATH,4,-605.5408,2620.273,98.99216,0,0,0,0,100,0),
(@PATH,5,-604.4185,2617.526,99.5359,0,0,0,0,100,0);
-- 0x1C09E4424010800000002000004E9D75 .go -607.841 2612.785 99.32381
