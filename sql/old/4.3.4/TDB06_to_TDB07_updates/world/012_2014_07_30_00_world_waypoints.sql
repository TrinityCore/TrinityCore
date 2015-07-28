-- Fix speed for Marsh Walker
UPDATE `creature_template` SET `speed_walk`=0.714285 WHERE `entry`=18135;

-- Pathing for Marsh Walker Entry: 18135
SET @NPC := 64827;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-301.1938,`position_y`=8503.301,`position_z`=18.08551 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-301.1938,8503.301,18.08551,0,0,0,0,100,0),
(@PATH,2,-329.7956,8532.172,18.0473,0,0,0,0,100,0),
(@PATH,3,-346.0217,8570.542,17.29573,0,0,0,0,100,0),
(@PATH,4,-381.4028,8604.693,17.4228,0,0,0,0,100,0),
(@PATH,5,-346.0217,8570.542,17.29573,0,0,0,0,100,0),
(@PATH,6,-329.7956,8532.172,18.0473,0,0,0,0,100,0),
(@PATH,7,-301.1938,8503.301,18.08551,0,0,0,0,100,0),
(@PATH,8,-274.4911,8481.536,17.49909,0,0,0,0,100,0),
(@PATH,9,-232.2047,8467.544,17.49908,0,0,0,0,100,0),
(@PATH,10,-248.1649,8454.211,17.49908,0,0,0,0,100,0),
(@PATH,11,-250.5263,8417.836,17.49909,0,0,0,0,100,0),
(@PATH,12,-254.9303,8379.229,17.49908,0,0,0,0,100,0),
(@PATH,13,-250.5263,8417.836,17.49909,0,0,0,0,100,0),
(@PATH,14,-248.1649,8454.211,17.49908,0,0,0,0,100,0),
(@PATH,15,-232.2047,8467.544,17.49908,0,0,0,0,100,0),
(@PATH,16,-274.4911,8481.536,17.49909,0,0,0,0,100,0);

-- Pathing for Marsh Walker Entry: 18135
SET @NPC := 64825;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=874.0325,`position_y`=8117.328,`position_z`=17.64004 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,874.0325,8117.328,17.64004,0,0,0,0,100,0),
(@PATH,2,872.1207,8150.702,17.51563,0,0,0,0,100,0),
(@PATH,3,856.12,8173.937,17.83715,0,0,0,0,100,0),
(@PATH,4,872.1207,8150.702,17.51563,0,0,0,0,100,0),
(@PATH,5,874.0325,8117.328,17.64004,0,0,0,0,100,0),
(@PATH,6,869.3058,8088.53,17.37932,0,0,0,0,100,0),
(@PATH,7,849.413,8053.933,17.49905,0,0,0,0,100,0),
(@PATH,8,823.0306,8058.05,17.49907,0,0,0,0,100,0),
(@PATH,9,786.84,8065.035,17.72405,0,0,0,0,100,0),
(@PATH,10,823.0306,8058.05,17.49907,0,0,0,0,100,0),
(@PATH,11,849.413,8053.933,17.49905,0,0,0,0,100,0),
(@PATH,12,869.3058,8088.53,17.37932,0,0,0,0,100,0);

-- Pathing for Marsh Walker Entry: 18135
SET @NPC := 64836;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-170.0164,`position_y`=8324.316,`position_z`=17.49908 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-170.0164,8324.316,17.49908,0,0,0,0,100,0),
(@PATH,2,-151.9314,8340.622,17.4991,0,0,0,0,100,0),
(@PATH,3,-125.7491,8351.658,17.59933,0,0,0,0,100,0),
(@PATH,4,-105.4347,8331.116,17.55655,0,0,0,0,100,0),
(@PATH,5,-85.87706,8321.008,17.69277,0,0,0,0,100,0),
(@PATH,6,-49.14638,8337.898,17.94507,0,0,0,0,100,0),
(@PATH,7,-42.37836,8378.92,17.43042,0,0,0,0,100,0),
(@PATH,8,-48.26867,8414.372,17.47196,0,0,0,0,100,0),
(@PATH,9,-55.37891,8463.818,17.39169,0,0,0,0,100,0),
(@PATH,10,-53.64724,8494.014,17.42002,0,0,0,0,100,0),
(@PATH,11,-55.37891,8463.818,17.39169,0,0,0,0,100,0),
(@PATH,12,-48.26867,8414.372,17.47196,0,0,0,0,100,0),
(@PATH,13,-42.37836,8378.92,17.43042,0,0,0,0,100,0),
(@PATH,14,-49.14638,8337.898,17.94507,0,0,0,0,100,0),
(@PATH,15,-85.87706,8321.008,17.69277,0,0,0,0,100,0),
(@PATH,16,-105.4347,8331.116,17.55655,0,0,0,0,100,0),
(@PATH,17,-125.7491,8351.658,17.59933,0,0,0,0,100,0),
(@PATH,18,-151.9314,8340.622,17.4991,0,0,0,0,100,0);

-- Pathing for Marsh Walker Entry: 18135
SET @NPC := 64830;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=447.8367,`position_y`=8068.624,`position_z`=17.57124 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,447.8367,8068.624,17.57124,0,0,0,0,100,0),
(@PATH,2,466.6456,8034.254,17.49908,0,0,0,0,100,0),
(@PATH,3,480.148,8005.124,17.40107,0,0,0,0,100,0),
(@PATH,4,458.6443,7973.283,17.4404,0,0,0,0,100,0),
(@PATH,5,420.8627,7951.928,18.2707,0,0,0,0,100,0),
(@PATH,6,395.485,7930.003,17.47219,0,0,0,0,100,0),
(@PATH,7,415.0804,7917.56,17.55268,0,0,0,0,100,0),
(@PATH,8,425.3092,7890.014,17.49909,0,0,0,0,100,0),
(@PATH,9,415.0804,7917.56,17.55268,0,0,0,0,100,0),
(@PATH,10,395.485,7930.003,17.47219,0,0,0,0,100,0),
(@PATH,11,420.8627,7951.928,18.2707,0,0,0,0,100,0),
(@PATH,12,458.6443,7973.283,17.4404,0,0,0,0,100,0),
(@PATH,13,480.148,8005.124,17.40107,0,0,0,0,100,0),
(@PATH,14,466.6456,8034.254,17.49908,0,0,0,0,100,0);

-- Pathing for Marsh Walker Entry: 18135
SET @NPC := 64823;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1118.289,`position_y`=8010.705,`position_z`=17.82893 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1118.289,8010.705,17.82893,0,0,0,0,100,0),
(@PATH,2,1087.97,8006.682,17.62409,0,0,0,0,100,0),
(@PATH,3,1084.727,7979.982,17.49906,0,0,0,0,100,0),
(@PATH,4,1095.844,7952.913,17.70093,0,0,0,0,100,0),
(@PATH,5,1098.577,7920.478,17.51494,0,0,0,0,100,0),
(@PATH,6,1078.124,7900.944,18.06584,0,0,0,0,100,0),
(@PATH,7,1042.975,7908.009,17.94593,0,0,0,0,100,0),
(@PATH,8,1016.453,7917.573,17.33556,0,0,0,0,100,0),
(@PATH,9,1042.975,7908.009,17.94593,0,0,0,0,100,0),
(@PATH,10,1078.124,7900.944,18.06584,0,0,0,0,100,0),
(@PATH,11,1098.577,7920.478,17.51494,0,0,0,0,100,0),
(@PATH,12,1095.844,7952.913,17.70093,0,0,0,0,100,0),
(@PATH,13,1084.727,7979.982,17.49906,0,0,0,0,100,0),
(@PATH,14,1087.97,8006.682,17.62409,0,0,0,0,100,0);

-- Pathing for Marsh Walker Entry: 18135
SET @NPC := 64839;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-114.5583,`position_y`=8460.023,`position_z`=18.7491 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-114.5583,8460.023,18.7491,0,0,0,0,100,0),
(@PATH,2,-93.83334,8491.481,17.4991,0,0,0,0,100,0),
(@PATH,3,-111.76,8506.979,17.4991,0,0,0,0,100,0),
(@PATH,4,-93.83334,8491.481,17.4991,0,0,0,0,100,0),
(@PATH,5,-114.5583,8460.023,18.7491,0,0,0,0,100,0),
(@PATH,6,-122.5003,8425.968,17.49909,0,0,0,0,100,0),
(@PATH,7,-129.3711,8389.323,18.05834,0,0,0,0,100,0),
(@PATH,8,-116.9223,8349.573,17.63839,0,0,0,0,100,0),
(@PATH,9,-117.383,8311.256,17.51004,0,0,0,0,100,0),
(@PATH,10,-114.472,8279.946,17.5043,0,0,0,0,100,0),
(@PATH,11,-77.70963,8284.504,17.49908,0,0,0,0,100,0),
(@PATH,12,-114.472,8279.946,17.5043,0,0,0,0,100,0),
(@PATH,13,-117.383,8311.256,17.51004,0,0,0,0,100,0),
(@PATH,14,-116.9223,8349.573,17.63839,0,0,0,0,100,0),
(@PATH,15,-129.3711,8389.323,18.05834,0,0,0,0,100,0),
(@PATH,16,-122.5003,8425.968,17.49909,0,0,0,0,100,0);

-- Pathing for Marsh Walker Entry: 18135
SET @NPC := 64829;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=578.0402,`position_y`=7958.319,`position_z`=17.49801 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,578.0402,7958.319,17.49801,0,0,0,0,100,0),
(@PATH,2,584.077,7995.75,17.45513,0,0,0,0,100,0),
(@PATH,3,609.2556,8015.048,17.37646,0,0,0,0,100,0),
(@PATH,4,584.077,7995.75,17.45513,0,0,0,0,100,0),
(@PATH,5,578.0402,7958.319,17.49801,0,0,0,0,100,0),
(@PATH,6,555.1559,7936.427,17.49322,0,0,0,0,100,0),
(@PATH,7,514.7059,7943.127,17.47691,0,0,0,0,100,0),
(@PATH,8,488.2624,7948.173,17.4991,0,0,0,0,100,0),
(@PATH,9,460.5211,7917.301,17.49908,0,0,0,0,100,0),
(@PATH,10,488.2624,7948.173,17.4991,0,0,0,0,100,0),
(@PATH,11,514.7059,7943.127,17.47691,0,0,0,0,100,0),
(@PATH,12,555.1559,7936.427,17.49322,0,0,0,0,100,0);

-- Pathing for Marsh Walker Entry: 18135
SET @NPC := 64820;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=781.5635,`position_y`=7542.347,`position_z`=17.736 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,781.5635,7542.347,17.736,0,0,0,0,100,0),
(@PATH,2,815.6573,7517.502,17.78351,0,0,0,0,100,0),
(@PATH,3,781.5635,7542.347,17.736,0,0,0,0,100,0),
(@PATH,4,762.9514,7551.243,17.6321,0,0,0,0,100,0),
(@PATH,5,726.7571,7550.808,17.64579,0,0,0,0,100,0),
(@PATH,6,677.6494,7553.893,17.60796,0,0,0,0,100,0),
(@PATH,7,636.2073,7560.307,17.38115,0,0,0,0,100,0),
(@PATH,8,601.652,7580.129,17.57902,0,0,0,0,100,0),
(@PATH,9,636.2073,7560.307,17.38115,0,0,0,0,100,0),
(@PATH,10,677.6494,7553.893,17.60796,0,0,0,0,100,0),
(@PATH,11,726.7571,7550.808,17.64579,0,0,0,0,100,0),
(@PATH,12,762.9514,7551.243,17.6321,0,0,0,0,100,0);

-- Pathing for Marsh Walker Entry: 18135
SET @NPC := 64821;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=644.4886,`position_y`=7622.633,`position_z`=17.49904 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,644.4886,7622.633,17.49904,0,0,0,0,100,0),
(@PATH,2,623.101,7642.905,17.48726,0,0,0,0,100,0),
(@PATH,3,587.3256,7666.358,17.46451,0,0,0,0,100,0),
(@PATH,4,551.9452,7682.568,17.49909,0,0,0,0,100,0),
(@PATH,5,524.8663,7686.722,17.49909,0,0,0,0,100,0),
(@PATH,6,484.5952,7692.899,17.49909,0,0,0,0,100,0),
(@PATH,7,461.4081,7714.175,17.49909,0,0,0,0,100,0),
(@PATH,8,445.0038,7746.1,18.03618,0,0,0,0,100,0),
(@PATH,9,461.4081,7714.175,17.49909,0,0,0,0,100,0),
(@PATH,10,484.5952,7692.899,17.49909,0,0,0,0,100,0),
(@PATH,11,524.8663,7686.722,17.49909,0,0,0,0,100,0),
(@PATH,12,551.9452,7682.568,17.49909,0,0,0,0,100,0),
(@PATH,13,587.3256,7666.358,17.46451,0,0,0,0,100,0),
(@PATH,14,623.101,7642.905,17.48726,0,0,0,0,100,0);

-- Pathing for Marsh Walker Entry: 18135
SET @NPC := 64834;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=86.54546,`position_y`=8255.574,`position_z`=18.9558 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,86.54546,8255.574,18.9558,0,0,0,0,100,0),
(@PATH,2,87.19987,8292.317,18.10031,0,0,0,0,100,0),
(@PATH,3,94.62978,8320.794,17.46457,0,0,0,0,100,0),
(@PATH,4,87.61372,8359.54,17.70627,0,0,0,0,100,0),
(@PATH,5,94.62978,8320.794,17.46457,0,0,0,0,100,0),
(@PATH,6,87.19987,8292.317,18.10031,0,0,0,0,100,0),
(@PATH,7,86.54546,8255.574,18.9558,0,0,0,0,100,0),
(@PATH,8,94.9808,8216.692,18.18986,0,0,0,0,100,0),
(@PATH,9,86.12218,8174.826,17.72863,0,0,0,0,100,0),
(@PATH,10,108.6104,8145.648,18.16449,0,0,0,0,100,0),
(@PATH,11,117.8114,8117.763,17.48594,0,0,0,0,100,0),
(@PATH,12,112.2395,8086.566,17.46772,0,0,0,0,100,0),
(@PATH,13,109.7972,8043.445,17.49909,0,0,0,0,100,0),
(@PATH,14,93.5204,8017.323,17.62408,0,0,0,0,100,0),
(@PATH,15,116.5076,8021.615,17.62409,0,0,0,0,100,0),
(@PATH,16,148.3784,8017.857,18.15998,0,0,0,0,100,0),
(@PATH,17,116.5076,8021.615,17.62409,0,0,0,0,100,0),
(@PATH,18,93.5204,8017.323,17.62408,0,0,0,0,100,0),
(@PATH,19,109.7972,8043.445,17.49909,0,0,0,0,100,0),
(@PATH,20,112.2395,8086.566,17.46772,0,0,0,0,100,0),
(@PATH,21,117.8114,8117.763,17.48594,0,0,0,0,100,0),
(@PATH,22,108.6104,8145.648,18.16449,0,0,0,0,100,0),
(@PATH,23,86.12218,8174.826,17.72863,0,0,0,0,100,0),
(@PATH,24,94.9808,8216.692,18.18986,0,0,0,0,100,0);

-- Pathing for Marsh Walker Entry: 18135
SET @NPC := 64824;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=961.119,`position_y`=8084.976,`position_z`=17.46151 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,961.119,8084.976,17.46151,0,0,0,0,100,0),
(@PATH,2,944.0886,8122.21,17.58651,0,0,0,0,100,0),
(@PATH,3,961.119,8084.976,17.46151,0,0,0,0,100,0),
(@PATH,4,965.8881,8057.272,17.07878,0,0,0,0,100,0),
(@PATH,5,966.6901,8014.281,17.40984,0,0,0,0,100,0),
(@PATH,6,932.3383,8016.327,17.51394,0,0,0,0,100,0),
(@PATH,7,886.6631,8012.957,17.5023,0,0,0,0,100,0),
(@PATH,8,884.9916,7986.938,17.5023,0,0,0,0,100,0),
(@PATH,9,886.6631,8012.957,17.5023,0,0,0,0,100,0),
(@PATH,10,932.3383,8016.327,17.51394,0,0,0,0,100,0),
(@PATH,11,966.6901,8014.281,17.40984,0,0,0,0,100,0),
(@PATH,12,965.8881,8057.272,17.07878,0,0,0,0,100,0);

-- Pathing for Marsh Walker Entry: 18135
SET @NPC := 64835;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-50.38683,`position_y`=8411.523,`position_z`=17.47196 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-50.38683,8411.523,17.47196,0,0,0,0,100,0),
(@PATH,2,-7.419705,8405.802,17.59548,0,0,0,0,100,0),
(@PATH,3,33.12446,8413.819,17.56993,0,0,0,0,100,0),
(@PATH,4,-7.419705,8405.802,17.59548,0,0,0,0,100,0),
(@PATH,5,-50.38683,8411.523,17.47196,0,0,0,0,100,0),
(@PATH,6,-96.01302,8420.427,17.54388,0,0,0,0,100,0),
(@PATH,7,-141.6372,8435.925,17.49909,0,0,0,0,100,0),
(@PATH,8,-155.1646,8460.817,17.49909,0,0,0,0,100,0),
(@PATH,9,-128.9806,8498.716,17.4991,0,0,0,0,100,0),
(@PATH,10,-148.222,8536.911,17.4991,0,0,0,0,100,0),
(@PATH,11,-128.9806,8498.716,17.4991,0,0,0,0,100,0),
(@PATH,12,-155.1646,8460.817,17.49909,0,0,0,0,100,0),
(@PATH,13,-141.6372,8435.925,17.49909,0,0,0,0,100,0),
(@PATH,14,-96.01302,8420.427,17.54388,0,0,0,0,100,0);

-- Pathing for Marsh Walker Entry: 18135
SET @NPC := 64833;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=87.91873,`position_y`=8158.213,`position_z`=17.85594 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,87.91873,8158.213,17.85594,0,0,0,0,100,0),
(@PATH,2,119.1228,8142.663,17.80609,0,0,0,0,100,0),
(@PATH,3,149.2628,8139.451,17.49908,0,0,0,0,100,0),
(@PATH,4,183.1385,8135.855,17.49909,0,0,0,0,100,0),
(@PATH,5,215.0218,8123.902,17.49909,0,0,0,0,100,0),
(@PATH,6,227.7337,8086.152,17.52486,0,0,0,0,100,0),
(@PATH,7,253.659,8054.662,17.49908,0,0,0,0,100,0),
(@PATH,8,282.684,8039.052,17.49798,0,0,0,0,100,0),
(@PATH,9,313.2512,8034.264,17.49908,0,0,0,0,100,0),
(@PATH,10,340.0236,8034.506,17.49909,0,0,0,0,100,0),
(@PATH,11,313.2512,8034.264,17.49908,0,0,0,0,100,0),
(@PATH,12,282.684,8039.052,17.49798,0,0,0,0,100,0),
(@PATH,13,253.659,8054.662,17.49908,0,0,0,0,100,0),
(@PATH,14,227.7337,8086.152,17.52486,0,0,0,0,100,0),
(@PATH,15,215.0218,8123.902,17.49909,0,0,0,0,100,0),
(@PATH,16,183.1385,8135.855,17.49909,0,0,0,0,100,0),
(@PATH,17,149.2628,8139.451,17.49908,0,0,0,0,100,0),
(@PATH,18,119.1228,8142.663,17.80609,0,0,0,0,100,0);

-- Pathing for Marsh Walker Entry: 18135
SET @NPC := 64840;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-347.4796,`position_y`=8533.388,`position_z`=17.49909 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-347.4796,8533.388,17.49909,0,0,0,0,100,0),
(@PATH,2,-329.523,8553.835,17.49909,0,0,0,0,100,0),
(@PATH,3,-296.6537,8564.734,17.43943,0,0,0,0,100,0),
(@PATH,4,-261.5942,8595.95,17.49909,0,0,0,0,100,0),
(@PATH,5,-296.6537,8564.734,17.43943,0,0,0,0,100,0),
(@PATH,6,-329.523,8553.835,17.49909,0,0,0,0,100,0),
(@PATH,7,-347.4796,8533.388,17.49909,0,0,0,0,100,0),
(@PATH,8,-368.0536,8508.598,17.49909,0,0,0,0,100,0),
(@PATH,9,-388.4557,8480.802,17.499,0,0,0,0,100,0),
(@PATH,10,-368.0536,8508.598,17.49909,0,0,0,0,100,0);

-- Pathing for Marsh Walker Entry: 18135
SET @NPC := 64838;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=184.0078,`position_y`=8977,`position_z`=17.39463 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,184.0078,8977,17.39463,0,0,0,0,100,0),
(@PATH,2,211.13,8973.212,17.81977,0,0,0,0,100,0),
(@PATH,3,216.3611,8937.859,18.64739,0,0,0,0,100,0),
(@PATH,4,200.0475,8911.421,17.49908,0,0,0,0,100,0),
(@PATH,5,210.271,8891.9,17.46042,0,0,0,0,100,0),
(@PATH,6,200.0475,8911.421,17.49908,0,0,0,0,100,0),
(@PATH,7,216.3611,8937.859,18.64739,0,0,0,0,100,0),
(@PATH,8,211.13,8973.212,17.81977,0,0,0,0,100,0),
(@PATH,9,184.0078,8977,17.39463,0,0,0,0,100,0),
(@PATH,10,148.9398,8971.519,19.89098,0,0,0,0,100,0),
(@PATH,11,121.7532,8954.647,17.59854,0,0,0,0,100,0),
(@PATH,12,98.23904,8918.107,18.67969,0,0,0,0,100,0),
(@PATH,13,121.7532,8954.647,17.59854,0,0,0,0,100,0),
(@PATH,14,148.9398,8971.519,19.89098,0,0,0,0,100,0);

-- Pathing for Marsh Walker Entry: 18135
SET @NPC := 64832;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=785.5858,`position_y`=8579.806,`position_z`=17.56527 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,785.5858,8579.806,17.56527,0,0,0,0,100,0),
(@PATH,2,755.4162,8584.002,17.4991,0,0,0,0,100,0),
(@PATH,3,735.4412,8602.093,17.4991,0,0,0,0,100,0),
(@PATH,4,715.2771,8583.415,17.4991,0,0,0,0,100,0),
(@PATH,5,710.8354,8545.135,17.8741,0,0,0,0,100,0),
(@PATH,6,716.3047,8522.668,20.39779,0,0,0,0,100,0),
(@PATH,7,710.8354,8545.135,17.8741,0,0,0,0,100,0),
(@PATH,8,715.2771,8583.415,17.4991,0,0,0,0,100,0),
(@PATH,9,735.4412,8602.093,17.4991,0,0,0,0,100,0),
(@PATH,10,755.4162,8584.002,17.4991,0,0,0,0,100,0),
(@PATH,11,785.5858,8579.806,17.56527,0,0,0,0,100,0),
(@PATH,12,825.7322,8589.715,17.49902,0,0,0,0,100,0),
(@PATH,13,849.3665,8614.612,17.69501,0,0,0,0,100,0),
(@PATH,14,867.0609,8633.648,18.25114,0,0,0,0,100,0),
(@PATH,15,849.3665,8614.612,17.69501,0,0,0,0,100,0),
(@PATH,16,825.7322,8589.715,17.49902,0,0,0,0,100,0);

-- Pathing for Marsh Walker Entry: 18135
SET @NPC := 64822;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=291.873,`position_y`=7703.415,`position_z`=17.88411 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,291.873,7703.415,17.88411,0,0,0,0,100,0),
(@PATH,2,314.779,7703.312,17.58478,0,0,0,0,100,0),
(@PATH,3,342.3629,7700.679,17.4991,0,0,0,0,100,0),
(@PATH,4,368.9921,7677.205,18.26697,0,0,0,0,100,0),
(@PATH,5,404.9698,7692.616,17.5832,0,0,0,0,100,0),
(@PATH,6,438.4161,7710.469,17.49909,0,0,0,0,100,0),
(@PATH,7,473.649,7704.022,17.41897,0,0,0,0,100,0),
(@PATH,8,505.8389,7679.953,17.49909,0,0,0,0,100,0),
(@PATH,9,514.8956,7650.235,17.49901,0,0,0,0,100,0),
(@PATH,10,497.9654,7624.322,17.80044,0,0,0,0,100,0),
(@PATH,11,514.8956,7650.235,17.49901,0,0,0,0,100,0),
(@PATH,12,505.8389,7679.953,17.49909,0,0,0,0,100,0),
(@PATH,13,473.649,7704.022,17.41897,0,0,0,0,100,0),
(@PATH,14,438.4161,7710.469,17.49909,0,0,0,0,100,0),
(@PATH,15,404.9698,7692.616,17.5832,0,0,0,0,100,0),
(@PATH,16,368.9921,7677.205,18.26697,0,0,0,0,100,0),
(@PATH,17,342.3629,7700.679,17.4991,0,0,0,0,100,0),
(@PATH,18,314.779,7703.312,17.58478,0,0,0,0,100,0);

-- Pathing for Marsh Walker Entry: 18135
SET @NPC := 64832;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=716.7272,`position_y`=8601.276,`position_z`=17.4991 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,716.7272,8601.276,17.4991,0,0,0,0,100,0),
(@PATH,2,752.174,8584.586,17.4991,0,0,0,0,100,0),
(@PATH,3,795.9551,8585.222,17.49673,0,0,0,0,100,0),
(@PATH,4,827.15,8586.998,17.49902,0,0,0,0,100,0),
(@PATH,5,856.6465,8574.583,17.49829,0,0,0,0,100,0),
(@PATH,6,886.3231,8559.085,17.39889,0,0,0,0,100,0),
(@PATH,7,912.6191,8540.341,17.49909,0,0,0,0,100,0),
(@PATH,8,939.4836,8513.34,17.45282,0,0,0,0,100,0),
(@PATH,9,954.2996,8474.65,17.49907,0,0,0,0,100,0),
(@PATH,10,984.855,8453.599,17.39467,0,0,0,0,100,0),
(@PATH,11,954.2996,8474.65,17.49907,0,0,0,0,100,0),
(@PATH,12,939.4836,8513.34,17.45282,0,0,0,0,100,0),
(@PATH,13,912.6191,8540.341,17.49909,0,0,0,0,100,0),
(@PATH,14,886.3231,8559.085,17.39889,0,0,0,0,100,0),
(@PATH,15,856.6465,8574.583,17.49829,0,0,0,0,100,0),
(@PATH,16,827.15,8586.998,17.49902,0,0,0,0,100,0),
(@PATH,17,795.9551,8585.222,17.49673,0,0,0,0,100,0),
(@PATH,18,752.174,8584.586,17.4991,0,0,0,0,100,0);

-- Pathing for Marsh Walker Entry: 18135
SET @NPC := 64828;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=924.0667,`position_y`=8305.966,`position_z`=17.67109 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,924.0667,8305.966,17.67109,0,0,0,0,100,0),
(@PATH,2,902.5826,8273.492,18.56687,0,0,0,0,100,0),
(@PATH,3,924.0667,8305.966,17.67109,0,0,0,0,100,0),
(@PATH,4,947.1714,8327.824,17.4991,0,0,0,0,100,0),
(@PATH,5,986.4986,8340.583,17.49908,0,0,0,0,100,0),
(@PATH,6,948.4996,8346.964,17.4991,0,0,0,0,100,0),
(@PATH,7,947.7733,8389.242,17.68296,0,0,0,0,100,0),
(@PATH,8,952.5717,8412.851,17.49909,0,0,0,0,100,0),
(@PATH,9,957.0486,8448.102,17.46062,0,0,0,0,100,0),
(@PATH,10,952.5717,8412.851,17.49909,0,0,0,0,100,0),
(@PATH,11,947.7733,8389.242,17.68296,0,0,0,0,100,0),
(@PATH,12,948.4996,8346.964,17.4991,0,0,0,0,100,0),
(@PATH,13,986.4986,8340.583,17.49908,0,0,0,0,100,0),
(@PATH,14,947.1714,8327.824,17.4991,0,0,0,0,100,0);

-- Pathing for Marsh Walker Entry: 18135
SET @NPC := 64819;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-390.1439,`position_y`=8253.518,`position_z`=16.09562 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-390.1439,8253.518,16.09562,0,0,0,0,100,0),
(@PATH,2,-357.2793,8281.346,17.36786,0,0,0,0,100,0),
(@PATH,3,-350.4625,8312.578,17.4991,0,0,0,0,100,0),
(@PATH,4,-349.5631,8344.943,17.49913,0,0,0,0,100,0),
(@PATH,5,-379.0918,8372.424,17.49909,0,0,0,0,100,0),
(@PATH,6,-414.88,8355.182,17.44271,0,0,0,0,100,0),
(@PATH,7,-446.0282,8319.295,15.24428,0,0,0,0,100,0),
(@PATH,8,-445.7359,8287.406,17.17921,0,0,0,0,100,0),
(@PATH,9,-461.3513,8246.95,17.877,0,0,0,0,100,0),
(@PATH,10,-445.7359,8287.406,17.17921,0,0,0,0,100,0),
(@PATH,11,-446.0282,8319.295,15.24428,0,0,0,0,100,0),
(@PATH,12,-414.88,8355.182,17.44271,0,0,0,0,100,0),
(@PATH,13,-379.0918,8372.424,17.49909,0,0,0,0,100,0),
(@PATH,14,-349.5631,8344.943,17.49913,0,0,0,0,100,0),
(@PATH,15,-350.4625,8312.578,17.4991,0,0,0,0,100,0),
(@PATH,16,-357.2793,8281.346,17.36786,0,0,0,0,100,0),
(@PATH,17,-390.1172,8253.547,16.111,0,0,0,0,100,0),
(@PATH,18,-424.5453,8234.055,17.90831,0,0,0,0,100,0),
(@PATH,19,-442.472,8206.46,16.09482,0,0,0,0,100,0),
(@PATH,20,-424.5453,8234.055,17.90831,0,0,0,0,100,0);

-- Pathing for Marsh Walker Entry: 18135
SET @NPC := 64831;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=883.9965,`position_y`=8521.639,`position_z`=17.83781 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,883.9965,8521.639,17.83781,0,0,0,0,100,0),
(@PATH,2,914.638,8546.687,17.49909,0,0,0,0,100,0),
(@PATH,3,947.3973,8548.576,17.42227,0,0,0,0,100,0),
(@PATH,4,973.8578,8584.088,16.96828,0,0,0,0,100,0),
(@PATH,5,947.3973,8548.576,17.42227,0,0,0,0,100,0),
(@PATH,6,914.638,8546.687,17.49909,0,0,0,0,100,0),
(@PATH,7,883.9965,8521.639,17.83781,0,0,0,0,100,0),
(@PATH,8,858.9237,8483.394,17.51669,0,0,0,0,100,0),
(@PATH,9,839.9093,8454.622,17.62974,0,0,0,0,100,0),
(@PATH,10,818.9688,8447.583,17.50474,0,0,0,0,100,0),
(@PATH,11,788.2785,8449.614,18.37276,0,0,0,0,100,0),
(@PATH,12,818.9688,8447.583,17.50474,0,0,0,0,100,0),
(@PATH,13,839.9093,8454.622,17.62974,0,0,0,0,100,0),
(@PATH,14,858.9237,8483.394,17.51669,0,0,0,0,100,0);

-- Pathing for Marsh Walker Entry: 18135
SET @NPC := 64826;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=974.1456,`position_y`=8151.406,`position_z`=17.49909 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,974.1456,8151.406,17.49909,0,0,0,0,100,0),
(@PATH,2,936.1339,8152.216,17.41899,0,0,0,0,100,0),
(@PATH,3,918.0892,8178.414,17.52471,0,0,0,0,100,0),
(@PATH,4,913.4008,8213.664,17.40324,0,0,0,0,100,0),
(@PATH,5,918.0892,8178.414,17.52471,0,0,0,0,100,0),
(@PATH,6,936.1339,8152.216,17.41899,0,0,0,0,100,0),
(@PATH,7,974.1456,8151.406,17.49909,0,0,0,0,100,0),
(@PATH,8,1005.321,8156.346,17.49909,0,0,0,0,100,0),
(@PATH,9,1032.515,8133.889,17.49909,0,0,0,0,100,0),
(@PATH,10,1060.987,8106.548,17.49909,0,0,0,0,100,0),
(@PATH,11,1047.958,8075.616,17.77516,0,0,0,0,100,0),
(@PATH,12,1011.745,8049.339,18.16889,0,0,0,0,100,0),
(@PATH,13,1047.958,8075.616,17.77516,0,0,0,0,100,0),
(@PATH,14,1060.987,8106.548,17.49909,0,0,0,0,100,0),
(@PATH,15,1032.515,8133.889,17.49909,0,0,0,0,100,0),
(@PATH,16,1005.321,8156.346,17.49909,0,0,0,0,100,0);

-- Pathing for Marsh Walker Entry: 18135
SET @NPC := 64837;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=82.27843,`position_y`=8509.213,`position_z`=17.49909 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,82.27843,8509.213,17.49909,0,0,0,0,100,0),
(@PATH,2,94.213,8544.274,17.99909,0,0,0,0,100,0),
(@PATH,3,69.33735,8574.196,17.68814,0,0,0,0,100,0),
(@PATH,4,83.5051,8551.99,17.49909,0,0,0,0,100,0),
(@PATH,5,117.2316,8551.036,17.96043,0,0,0,0,100,0),
(@PATH,6,150.0363,8554.89,17.68345,0,0,0,0,100,0),
(@PATH,7,163.1173,8588.505,18.63587,0,0,0,0,100,0),
(@PATH,8,156.6575,8612.926,17.53897,0,0,0,0,100,0),
(@PATH,9,163.1173,8588.505,18.63587,0,0,0,0,100,0),
(@PATH,10,150.0363,8554.89,17.68345,0,0,0,0,100,0),
(@PATH,11,117.2316,8551.036,17.96043,0,0,0,0,100,0),
(@PATH,12,83.5051,8551.99,17.49909,0,0,0,0,100,0),
(@PATH,13,69.33735,8574.196,17.68814,0,0,0,0,100,0),
(@PATH,14,94.213,8544.274,17.99909,0,0,0,0,100,0),
(@PATH,15,82.27843,8509.213,17.49909,0,0,0,0,100,0),
(@PATH,16,92.01487,8483.376,17.49909,0,0,0,0,100,0),
(@PATH,17,77.338,8501.032,17.49909,0,0,0,0,100,0),
(@PATH,18,47.22873,8506.513,17.49909,0,0,0,0,100,0),
(@PATH,19,25.15582,8520.438,17.49283,0,0,0,0,100,0),
(@PATH,20,47.22873,8506.513,17.49909,0,0,0,0,100,0);

-- Pathing for Ango'rosh Shaman Entry: 18118
SET @NPC := 64200;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=644.8542,`position_y`=7864.837,`position_z`=22.3112 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,644.8542,7864.837,22.3112,0,0,0,0,100,0),
(@PATH,2,658.7136,7850.472,21.90904,0,0,0,0,100,0),
(@PATH,3,673.5045,7838.813,22.60974,0,0,0,0,100,0),
(@PATH,4,679.8118,7823.88,22.23306,0,0,0,0,100,0),
(@PATH,5,684.8212,7799.125,21.99128,0,0,0,0,100,0),
(@PATH,6,693.1428,7791.885,22.23091,0,0,0,0,100,0),
(@PATH,7,693.1428,7791.885,22.23091,0,0,0,0,100,0),
(@PATH,8,684.8212,7799.125,21.99128,0,0,0,0,100,0),
(@PATH,9,679.8118,7823.88,22.23306,0,0,0,0,100,0),
(@PATH,10,673.5045,7838.813,22.60974,0,0,0,0,100,0),
(@PATH,11,658.7136,7850.472,21.90904,0,0,0,0,100,0),
(@PATH,12,644.7537,7864.248,22.31084,0,0,0,0,100,0),
(@PATH,13,637.0594,7876.642,21.9847,0,0,0,0,100,0),
(@PATH,14,622.5043,7883.878,22.07429,0,0,0,0,100,0),
(@PATH,15,597.0054,7883.503,21.96379,0,0,0,0,100,0),
(@PATH,16,584.8994,7878.884,22.13079,0,0,0,0,100,0),
(@PATH,17,578.9732,7863.721,22.09724,0,0,0,0,100,0),
(@PATH,18,572.3759,7854.287,21.59724,0,0,0,0,100,0),
(@PATH,19,557.7398,7852.659,21.62408,0,0,0,0,100,0),
(@PATH,20,572.3759,7854.287,21.59724,0,0,0,0,100,0),
(@PATH,21,578.9732,7863.721,22.09724,0,0,0,0,100,0),
(@PATH,22,584.8994,7878.884,22.13079,0,0,0,0,100,0),
(@PATH,23,597.0054,7883.503,21.96379,0,0,0,0,100,0),
(@PATH,24,622.5043,7883.878,22.07429,0,0,0,0,100,0),
(@PATH,25,637.0594,7876.642,21.9847,0,0,0,0,100,0);

-- Pathing for Ango'rosh Shaman Entry: 18118
SET @NPC := 64199;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=770.1323,`position_y`=7774.846,`position_z`=22.67318 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,770.1323,7774.846,22.67318,0,0,0,0,100,0),
(@PATH,2,777.4385,7767.182,21.9991,0,0,0,0,100,0),
(@PATH,3,785.0085,7758.705,21.86028,0,0,0,0,100,0),
(@PATH,4,794.3231,7747.627,21.98528,0,0,0,0,100,0),
(@PATH,5,804.1041,7737.199,21.84237,0,0,0,0,100,0),
(@PATH,6,810.9216,7725.344,21.92386,0,0,0,0,100,0),
(@PATH,7,814.6373,7706.108,21.62845,0,0,0,0,100,0),
(@PATH,8,810.9216,7725.344,21.92386,0,0,0,0,100,0),
(@PATH,9,804.1041,7737.199,21.84237,0,0,0,0,100,0),
(@PATH,10,794.3231,7747.627,21.98528,0,0,0,0,100,0),
(@PATH,11,785.0085,7758.705,21.86028,0,0,0,0,100,0),
(@PATH,12,777.4385,7767.182,21.9991,0,0,0,0,100,0),
(@PATH,13,770.3223,7774.25,22.63703,0,0,0,0,100,0),
(@PATH,14,765.7609,7779.539,22.77408,0,0,0,0,100,0),
(@PATH,15,761.437,7784.407,22.66974,0,0,0,0,100,0),
(@PATH,16,755.484,7787.25,22.49196,0,0,0,0,100,0),
(@PATH,17,748.4116,7788.092,22.13786,0,0,0,0,100,0),
(@PATH,18,742.2909,7786.957,22.00575,0,0,0,0,100,0),
(@PATH,19,734.4057,7787.279,22.0069,0,0,0,0,100,0),
(@PATH,20,727.2755,7788.375,21.81407,0,0,0,0,100,0),
(@PATH,21,717.0435,7789.009,22.1188,0,0,0,0,100,0),
(@PATH,22,710.8192,7789.798,22.10098,0,0,0,0,100,0),
(@PATH,23,702.6148,7790.601,22.37459,0,0,0,0,100,0),
(@PATH,24,690.6102,7791.114,22.24128,0,0,0,0,100,0),
(@PATH,25,679.7465,7787.897,22.47639,0,0,0,0,100,0),
(@PATH,26,675.0551,7778.473,21.07356,0,0,0,0,100,0),
(@PATH,27,678.0349,7766.003,21.06932,0,0,0,0,100,0),
(@PATH,28,684.7713,7752.402,22.23509,0,0,0,0,100,0),
(@PATH,29,678.0349,7766.003,21.06932,0,0,0,0,100,0),
(@PATH,30,675.0551,7778.473,21.07356,0,0,0,0,100,0),
(@PATH,31,679.7465,7787.897,22.47639,0,0,0,0,100,0),
(@PATH,32,690.6102,7791.114,22.24128,0,0,0,0,100,0),
(@PATH,33,702.6148,7790.601,22.37459,0,0,0,0,100,0),
(@PATH,34,710.5023,7789.834,22.10141,0,0,0,0,100,0),
(@PATH,35,717.0435,7789.009,22.1188,0,0,0,0,100,0),
(@PATH,36,727.2755,7788.375,21.81407,0,0,0,0,100,0),
(@PATH,37,734.4057,7787.279,22.0069,0,0,0,0,100,0),
(@PATH,38,742.2909,7786.957,22.00575,0,0,0,0,100,0),
(@PATH,39,748.4116,7788.092,22.13786,0,0,0,0,100,0),
(@PATH,40,755.484,7787.25,22.49196,0,0,0,0,100,0),
(@PATH,41,761.437,7784.407,22.66974,0,0,0,0,100,0),
(@PATH,42,765.7609,7779.539,22.77408,0,0,0,0,100,0);

UPDATE `creature` SET `id`=18118 WHERE `guid`=64195;
UPDATE `creature` SET `spawndist`=5,`MovementType`=1 WHERE `guid` IN (64191,64195,64159,64196,64186,64170,64163,64158);
DELETE FROM `creature_addon` WHERE `guid` IN (64191,64195,64159,64196,64186,64170,64163,64158);
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`emote`,`auras`) VALUES 
(64159,0,1,0, ''),(64196,0,1,0, ''),(64191,0,1,0, ''),(64186,0,1,0, ''),(64170,0,1,0, ''),(64163,0,1,0, ''),(64158,0,1,0, '');

-- Pathing for Ango'rosh Sentry Entry: 20443
SET @NPC := 72411;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1280.438,`position_y`=8627.676,`position_z`=20.92095 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1280.438,8627.676,20.92095,0,0,0,0,100,0),
(@PATH,2,1260.006,8639.502,22.83721,0,0,0,0,100,0),
(@PATH,3,1245.05,8641.163,24.4113,0,0,0,0,100,0),
(@PATH,4,1216.487,8650.236,20.57172,0,0,0,0,100,0),
(@PATH,5,1245.05,8641.163,24.4113,0,0,0,0,100,0),
(@PATH,6,1260.006,8639.502,22.83721,0,0,0,0,100,0),
(@PATH,7,1280.438,8627.676,20.92095,0,0,0,0,100,0),
(@PATH,8,1281.377,8600.357,18.18194,0,0,0,0,100,0);

-- Pathing for Ango'rosh Sentry Entry: 20443
SET @NPC := 72420;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=970.3631,`position_y`=8553.178,`position_z`=21.38559 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,970.3631,8553.178,21.38559,0,0,0,0,100,0),
(@PATH,2,985.7488,8583.917,19.42825,0,0,0,0,100,0),
(@PATH,3,999.244,8606.11,24.68743,0,0,0,0,100,0),
(@PATH,4,1025.91,8617.661,19.0017,0,0,0,0,100,0),
(@PATH,5,999.2891,8606.135,24.75078,0,0,0,0,100,0),
(@PATH,6,985.7488,8583.917,19.42825,0,0,0,0,100,0),
(@PATH,7,970.3631,8553.178,21.38559,0,0,0,0,100,0),
(@PATH,8,969.0519,8528.513,20.06933,0,0,0,0,100,0),
(@PATH,9,988.2411,8512.356,18.72606,0,0,0,0,100,0),
(@PATH,10,969.0519,8528.513,20.06933,0,0,0,0,100,0);

-- Pathing for Ango'rosh Sentry Entry: 20443
SET @NPC := 72413;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1173.638,`position_y`=8413.106,`position_z`=47.84419 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1173.638,8413.106,47.84419,0,0,0,0,100,0),
(@PATH,2,1163.449,8415.349,42.86897,0,0,0,0,100,0),
(@PATH,3,1152.371,8420.931,36.45106,0,0,0,0,100,0),
(@PATH,4,1149.642,8423.404,35.62211,0,0,0,0,100,0),
(@PATH,5,1161.088,8437.671,27.15933,0,0,0,0,100,0),
(@PATH,6,1167.009,8444.979,22.7928,0,0,0,0,100,0),
(@PATH,7,1161.088,8437.671,27.15933,0,0,0,0,100,0),
(@PATH,8,1149.642,8423.404,35.62211,0,0,0,0,100,0),
(@PATH,9,1152.371,8420.931,36.45106,0,0,0,0,100,0),
(@PATH,10,1163.449,8415.349,42.86897,0,0,0,0,100,0),
(@PATH,11,1173.638,8413.106,47.84419,0,0,0,0,100,0),
(@PATH,12,1178.014,8414.137,50.07702,0,0,0,0,100,0),
(@PATH,13,1184.483,8417.801,53.34129,0,0,0,0,100,0),
(@PATH,14,1190.194,8420.89,56.02716,0,0,0,0,100,0),
(@PATH,15,1187.88,8427.463,57.16458,0,0,0,0,100,0),
(@PATH,16,1183.713,8437.44,58.30647,0,0,0,0,100,0),
(@PATH,17,1187.88,8427.463,57.16458,0,0,0,0,100,0),
(@PATH,18,1190.194,8420.89,56.02716,0,0,0,0,100,0),
(@PATH,19,1184.483,8417.801,53.34129,0,0,0,0,100,0),
(@PATH,20,1178.014,8414.137,50.07702,0,0,0,0,100,0);

-- Pathing for Ango'rosh Sentry Entry: 20443
SET @NPC := 72421;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1072.604,`position_y`=8637.91,`position_z`=22.98809 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1072.604,8637.91,22.98809,0,0,0,0,100,0),
(@PATH,2,1052.562,8618.747,17.68465,0,0,0,0,100,0),
(@PATH,3,1072.604,8637.91,22.98809,0,0,0,0,100,0),
(@PATH,4,1094.035,8644.675,23.35613,0,0,0,0,100,0);

-- Pathing for Ango'rosh Sentry Entry: 20443
SET @NPC := 72410;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1257.143,`position_y`=8512.616,`position_z`=22.73383 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1257.143,8512.616,22.73383,0,0,0,0,100,0),
(@PATH,2,1267.241,8500.584,24.4882,0,0,0,0,100,0),
(@PATH,3,1275.148,8489.038,23.69006,0,0,0,0,100,0),
(@PATH,4,1267.47,8461.444,22.73318,0,0,0,0,100,0),
(@PATH,5,1251.861,8441.785,20.1918,0,0,0,0,100,0),
(@PATH,6,1237.605,8424.362,17.89481,0,0,0,0,100,0),
(@PATH,7,1229.287,8411.072,18.9991,0,0,0,0,100,0),
(@PATH,8,1210.862,8406.452,17.7491,0,0,0,0,100,0),
(@PATH,9,1229.287,8411.072,18.9991,0,0,0,0,100,0),
(@PATH,10,1237.605,8424.362,17.89481,0,0,0,0,100,0),
(@PATH,11,1251.861,8441.785,20.1918,0,0,0,0,100,0),
(@PATH,12,1267.47,8461.444,22.73318,0,0,0,0,100,0),
(@PATH,13,1275.148,8489.038,23.69006,0,0,0,0,100,0),
(@PATH,14,1267.241,8500.584,24.4882,0,0,0,0,100,0),
(@PATH,15,1257.143,8512.616,22.73383,0,0,0,0,100,0),
(@PATH,16,1264.564,8540.619,18.63026,0,0,0,0,100,0),
(@PATH,17,1281.139,8567.028,20.92814,0,0,0,0,100,0),
(@PATH,18,1285.464,8603.98,18.06524,0,0,0,0,100,0),
(@PATH,19,1281.139,8567.028,20.92814,0,0,0,0,100,0),
(@PATH,20,1264.564,8540.619,18.63026,0,0,0,0,100,0);

-- Pathing for Ango'rosh Sentry Entry: 20443
SET @NPC := 72418;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1050.08,`position_y`=8471.225,`position_z`=55.79852 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1050.08,8471.225,55.79852,0,0,0,0,100,0),
(@PATH,2,1045.566,8467.722,53.36241,0,0,0,0,100,0),
(@PATH,3,1039.81,8464.549,50.48059,0,0,0,0,100,0),
(@PATH,4,1034.04,8462.964,47.46804,0,0,0,0,100,0),
(@PATH,5,1023.59,8466.265,41.93713,0,0,0,0,100,0),
(@PATH,6,1015.494,8469.264,37.75529,0,0,0,0,100,0),
(@PATH,7,1010.956,8473.249,35.49992,0,0,0,0,100,0),
(@PATH,8,1018.681,8483.053,29.74021,0,0,0,0,100,0),
(@PATH,9,1027.361,8493.991,23.25309,0,0,0,0,100,0),
(@PATH,10,1018.681,8483.053,29.74021,0,0,0,0,100,0),
(@PATH,11,1010.956,8473.249,35.49992,0,0,0,0,100,0),
(@PATH,12,1015.494,8469.264,37.75529,0,0,0,0,100,0),
(@PATH,13,1023.397,8466.325,41.84349,0,0,0,0,100,0),
(@PATH,14,1034.04,8462.964,47.46804,0,0,0,0,100,0),
(@PATH,15,1039.81,8464.549,50.48059,0,0,0,0,100,0),
(@PATH,16,1045.566,8467.722,53.36241,0,0,0,0,100,0),
(@PATH,17,1050.08,8471.225,55.79852,0,0,0,0,100,0),
(@PATH,18,1049.307,8476.159,57.09945,0,0,0,0,100,0),
(@PATH,19,1044.823,8485.451,58.18297,0,0,0,0,100,0),
(@PATH,20,1049.307,8476.159,57.09945,0,0,0,0,100,0);
