-- Pathing for Sister of Pain Entry: 22956
SET @NPC := 52847;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=927.6238,`position_y`=341.3523,`position_z`=192.8381 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,927.6238,341.3523,192.8381,0,0,0,0,100,0),
(@PATH,2,933.1646,349.9787,192.8489,0,0,0,0,100,0),
(@PATH,3,946.3496,351.5887,191.208,0,0,0,0,100,0),
(@PATH,4,957.402,349.1798,192.8489,0,0,0,0,100,0),
(@PATH,5,959.1028,340.2523,192.8339,0,0,0,0,100,0),
(@PATH,6,958.7474,315.7549,192.85,0,0,0,0,100,0),
(@PATH,7,958.1597,284.2602,192.8316,0,0,0,0,100,0),
(@PATH,8,957.9045,261.2944,192.8105,0,0,0,0,100,0),
(@PATH,9,934.2908,249.2501,192.8218,0,0,0,0,100,0),
(@PATH,10,924.9614,242.9601,192.8321,0,0,0,0,100,0),
(@PATH,11,923.0469,232.589,192.8392,0,0,0,0,100,0),
(@PATH,12,936.2947,223.5277,192.8423,0,0,0,0,100,0),
(@PATH,13,956.1213,223.5726,192.8414,0,0,0,0,100,0),
(@PATH,14,957.9364,265.2702,192.8146,0,0,0,0,100,0),
(@PATH,15,958.333,291.847,192.8519,0,0,0,0,100,0),
(@PATH,16,958.7474,315.7549,192.85,0,0,0,0,100,0),
(@PATH,17,926.8249,319.8605,192.8298,0,0,0,0,100,0);
-- 0xF13059AC00000970 .go 927.6238 341.3523 192.8381

-- Pathing for Sister of Pleasure Entry: 22964
SET @NPC := 53055;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=925.0996,`position_y`=342.9736,`position_z`=192.8381 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,925.0996,342.9736,192.8381,0,0,0,0,100,0),
(@PATH,2,932.8010,352.9566,192.8489,0,0,0,0,100,0),
(@PATH,3,946.9885,354.5199,191.2080,0,0,0,0,100,0),
(@PATH,4,960.3490,349.7412,192.8489,0,0,0,0,100,0),
(@PATH,5,962.1025,340.2088,192.8339,0,0,0,0,100,0),
(@PATH,6,961.7469,315.6989,192.8500,0,0,0,0,100,0),
(@PATH,7,961.1595,284.2269,192.8316,0,0,0,0,100,0),
(@PATH,8,959.2676,258.6220,192.8105,0,0,0,0,100,0),
(@PATH,9,935.9679,246.7626,192.8218,0,0,0,0,100,0),
(@PATH,10,927.9116,242.4155,192.8321,0,0,0,0,100,0),
(@PATH,11,924.7406,235.0652,192.8392,0,0,0,0,100,0),
(@PATH,12,936.2879,226.5277,192.8423,0,0,0,0,100,0),
(@PATH,13,953.1241,223.7031,192.8414,0,0,0,0,100,0),
(@PATH,14,954.9367,265.3150,192.8146,0,0,0,0,100,0),
(@PATH,15,955.3335,291.8990,192.8519,0,0,0,0,100,0),
(@PATH,16,958.3647,312.7794,192.8500,0,0,0,0,100,0),
(@PATH,17,923.8270,319.9719,192.8298,0,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=52847;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(52847,52847,0,0,2),
(52847,53055,3,270,2);

-- Pathing for Sister of Pain Entry: 22956
SET @NPC := 52848;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=939.6501,`position_y`=392.5455,`position_z`=192.2012 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,939.6501,392.5455,192.2012,0,0,0,0,100,0),
(@PATH,2,955.7531,392.462,192.8371,0,0,0,0,100,0),
(@PATH,3,962.5223,393.8847,192.8374,0,0,0,0,100,0),
(@PATH,4,969.5388,399.207,192.8365,0,0,0,0,100,0),
(@PATH,5,970.2259,412.7339,192.8371,0,0,0,0,100,0),
(@PATH,6,971.1399,429.8507,192.8395,0,0,0,0,100,0),
(@PATH,7,971.1545,441.883,192.8399,0,0,0,0,100,0),
(@PATH,8,963.2639,447.4974,192.8385,0,0,0,0,100,0),
(@PATH,9,950.0648,453.577,192.8389,0,0,0,0,100,0),
(@PATH,10,938.3679,452.2439,192.8379,0,0,0,0,100,0),
(@PATH,11,927.6536,446.5119,192.8374,0,0,0,0,100,0),
(@PATH,12,920.3358,436.4881,192.841,0,0,0,0,100,0),
(@PATH,13,920.5208,411.5176,192.8447,0,0,0,0,100,0),
(@PATH,14,922.6708,402.1874,192.8461,0,0,0,0,100,0),
(@PATH,15,931.1328,395.2974,192.8446,0,0,0,0,100,0);
-- 0xF13059AC00000972 .go 939.6501 392.5455 192.2012

-- Pathing for Sister of Pleasure Entry: 22964
SET @NPC := 53056;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=939.6657,`position_y`=395.5455,`position_z`=192.2012 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,939.6657,395.5455,192.2012,0,0,0,0,100,0),
(@PATH,2,955.1361,395.3979,192.8371,0,0,0,0,100,0),
(@PATH,3,960.7093,396.2749,192.8374,0,0,0,0,100,0),
(@PATH,4,966.5427,399.3592,192.8365,0,0,0,0,100,0),
(@PATH,5,967.2302,412.8939,192.8371,0,0,0,0,100,0),
(@PATH,6,968.1399,429.8543,192.8395,0,0,0,0,100,0),
(@PATH,7,969.4152,439.4386,192.8399,0,0,0,0,100,0),
(@PATH,8,962.0088,444.7726,192.8385,0,0,0,0,100,0),
(@PATH,9,950.4045,450.5963,192.8389,0,0,0,0,100,0),
(@PATH,10,939.7831,449.5987,192.8379,0,0,0,0,100,0),
(@PATH,11,930.0766,444.7430,192.8374,0,0,0,0,100,0),
(@PATH,12,923.3357,436.5103,192.8410,0,0,0,0,100,0),
(@PATH,13,923.4442,412.1912,192.8447,0,0,0,0,100,0),
(@PATH,14,924.5650,404.5138,192.8461,0,0,0,0,100,0),
(@PATH,15,932.0551,398.1521,192.8446,0,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=52848;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(52848,52848,0,0,2),
(52848,53056,3,270,2);

-- Pathing for Sister of Pain Entry: 22956
SET @NPC := 52855;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=946.1318,`position_y`=109.8686,`position_z`=192.8489 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,946.1318,109.8686,192.8489,0,0,0,0,100,0),
(@PATH,2,927.7674,117.2716,192.8514,0,0,0,0,100,0),
(@PATH,3,918.4934,131.3158,192.8362,0,0,0,0,100,0),
(@PATH,4,919.8276,156.7103,192.8208,0,0,0,0,100,0),
(@PATH,5,924.041,177.5718,192.8279,0,0,0,0,100,0),
(@PATH,6,935.0341,190.2466,192.8337,0,0,0,0,100,0),
(@PATH,7,946.1438,190.5046,192.0657,0,0,0,0,100,0),
(@PATH,8,957.5206,190.2688,192.8344,0,0,0,0,100,0),
(@PATH,9,967.0856,176.6067,192.8276,0,0,0,0,100,0),
(@PATH,10,970.228,156.7281,192.829,0,0,0,0,100,0),
(@PATH,11,971.1368,131.5664,192.8254,0,0,0,0,100,0),
(@PATH,12,963.462,116.8087,192.829,0,0,0,0,100,0);
-- 0xF13059AC00000975 .go 946.1318 109.8686 192.8489

-- Pathing for Sister of Pleasure Entry: 22964
SET @NPC := 53059;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=945.0102,`position_y`=107.0862,`position_z`=192.8489 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,945.0102,107.0862,192.8489,0,0,0,0,100,0),
(@PATH,2,925.2640,115.6185,192.8514,0,0,0,0,100,0),
(@PATH,3,915.4975,131.4732,192.8362,0,0,0,0,100,0),
(@PATH,4,916.8870,157.3042,192.8208,0,0,0,0,100,0),
(@PATH,5,921.7747,179.5374,192.8279,0,0,0,0,100,0),
(@PATH,6,934.9644,193.2458,192.8337,0,0,0,0,100,0),
(@PATH,7,946.2060,193.5040,192.0657,0,0,0,0,100,0),
(@PATH,8,959.9782,191.9894,192.8344,0,0,0,0,100,0),
(@PATH,9,970.0488,177.0751,192.8276,0,0,0,0,100,0),
(@PATH,10,973.2260,156.8364,192.8290,0,0,0,0,100,0),
(@PATH,11,973.7984,130.1822,192.8254,0,0,0,0,100,0),
(@PATH,12,964.5773,114.0237,192.8290,0,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=52855;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(52855,52855,0,0,2),
(52855,53059,3,270,2);

-- Pathing for Sister of Pain Entry: 22956
SET @NPC := 52846;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=832.2903,`position_y`=526.5916,`position_z`=165.7311 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,832.2903,526.5916,165.7311,0,0,0,0,100,0),
(@PATH,2,818.8309,520.7764,165.9885,0,0,0,0,100,0),
(@PATH,3,812.696,514.7813,166.1044,0,0,0,0,100,0),
(@PATH,4,812.6564,506.3056,170.2904,0,0,0,0,100,0),
(@PATH,5,812.5226,493.5983,180.3996,0,0,0,0,100,0),
(@PATH,6,812.2745,477.484,192.7058,0,0,0,0,100,0),
(@PATH,7,812.5706,466.9394,192.7913,0,0,0,0,100,0),
(@PATH,8,812.2745,477.484,192.7058,0,0,0,0,100,0),
(@PATH,9,812.5226,493.5983,180.3996,0,0,0,0,100,0),
(@PATH,10,812.6564,506.3056,170.2904,0,0,0,0,100,0),
(@PATH,11,812.696,514.7813,166.1044,0,0,0,0,100,0),
(@PATH,12,818.8309,520.7764,165.9885,0,0,0,0,100,0),
(@PATH,13,832.2903,526.5916,165.7311,0,0,0,0,100,0),
(@PATH,14,837.6116,532.7322,165.7527,0,0,0,0,100,0),
(@PATH,15,840.6443,543.301,165.6792,0,0,0,0,100,0),
(@PATH,16,849.1154,543.5079,165.8225,0,0,0,0,100,0),
(@PATH,17,862.1961,543.5349,156.2316,0,0,0,0,100,0),
(@PATH,18,874.82,543.4052,146.1888,0,0,0,0,100,0),
(@PATH,19,890.8995,543.0212,139.3036,0,0,0,0,100,0),
(@PATH,20,874.82,543.4052,146.1888,0,0,0,0,100,0),
(@PATH,21,862.1961,543.5349,156.2316,0,0,0,0,100,0),
(@PATH,22,849.1154,543.5079,165.8225,0,0,0,0,100,0),
(@PATH,23,840.6443,543.301,165.6792,0,0,0,0,100,0),
(@PATH,24,837.6116,532.7322,165.7527,0,0,0,0,100,0);
-- 0xF13059AC000009CB .go 832.2903 526.5916 165.7311

-- Pathing for Sister of Pleasure Entry: 22964
SET @NPC := 53054;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=833.4802,`position_y`=523.8377,`position_z`=165.7311 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,833.4802,523.8377,165.7311,0,0,0,0,100,0),
(@PATH,2,820.9276,518.6308,165.9885,0,0,0,0,100,0),
(@PATH,3,815.6960,514.7673,166.1044,0,0,0,0,100,0),
(@PATH,4,815.6562,506.2740,170.2904,0,0,0,0,100,0),
(@PATH,5,815.5222,493.5521,180.3996,0,0,0,0,100,0),
(@PATH,6,815.2733,477.5682,192.7058,0,0,0,0,100,0),
(@PATH,7,815.5694,467.0236,192.7913,0,0,0,0,100,0),
(@PATH,8,815.2741,477.4378,192.7058,0,0,0,0,100,0),
(@PATH,9,815.5224,493.5667,180.3996,0,0,0,0,100,0),
(@PATH,10,815.6564,506.2916,170.2904,0,0,0,0,100,0),
(@PATH,11,814.7927,512.6357,166.1044,0,0,0,0,100,0),
(@PATH,12,820.0208,518.0225,165.9885,0,0,0,0,100,0),
(@PATH,13,834.5575,524.6269,165.7311,0,0,0,0,100,0),
(@PATH,14,840.4952,531.9047,165.7527,0,0,0,0,100,0),
(@PATH,15,840.7176,540.3019,165.6792,0,0,0,0,100,0),
(@PATH,16,849.1216,540.5079,165.8225,0,0,0,0,100,0),
(@PATH,17,862.1653,540.5351,156.2316,0,0,0,0,100,0),
(@PATH,18,874.7484,540.4061,146.1888,0,0,0,0,100,0),
(@PATH,19,890.8279,540.0221,139.3036,0,0,0,0,100,0),
(@PATH,20,874.7892,540.4054,146.1888,0,0,0,0,100,0),
(@PATH,21,862.2023,540.5349,156.2316,0,0,0,0,100,0),
(@PATH,22,849.1887,540.5088,165.8225,0,0,0,0,100,0),
(@PATH,23,843.5279,542.4735,165.6792,0,0,0,0,100,0),
(@PATH,24,839.8788,530.7675,165.7527,0,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=52846;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(52846,52846,0,0,2),
(52846,53054,3,270,2);

-- Pathing for Sister of Pain Entry: 22956
SET @NPC := 52854;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=897.643,`position_y`=368.6811,`position_z`=112.7681 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,897.643,368.6811,112.7682,0,0,0,0,100,0),
(@PATH,2,891.4086,375.0052,112.7682,0,0,0,0,100,0),
(@PATH,3,886.6258,392.1916,112.7681,0,0,0,0,100,0),
(@PATH,4,889.0926,406.6414,112.7681,0,0,0,0,100,0),
(@PATH,5,895.0201,414.2144,112.7681,0,0,0,0,100,0),
(@PATH,6,907.2474,422.6099,112.7681,0,0,0,0,100,0),
(@PATH,7,917.291,427.4965,112.7681,0,0,0,0,100,0),
(@PATH,8,917.538,443.7802,112.7681,0,0,0,0,100,0),
(@PATH,9,918.18,480.8549,121.0903,0,0,0,0,100,0),
(@PATH,10,918.1483,469.0587,112.768,0,0,0,0,100,0),
(@PATH,11,917.9372,449.7168,112.7681,0,0,0,0,100,0),
(@PATH,12,917.7559,427.5167,112.7681,0,0,0,0,100,0),
(@PATH,13,928.2393,423.6823,112.768,0,0,0,0,100,0),
(@PATH,14,942.3116,412.3955,112.768,0,0,0,0,100,0),
(@PATH,15,947.6193,400.7702,112.768,0,0,0,0,100,0),
(@PATH,16,947.3901,388.0476,112.768,0,0,0,0,100,0),
(@PATH,17,944.3997,375.4843,112.768,0,0,0,0,100,0),
(@PATH,18,934.3572,366.3027,112.7681,0,0,0,0,100,0),
(@PATH,19,922.269,361.623,112.7681,0,0,0,0,100,0),
(@PATH,20,907.52,362.9464,112.7682,0,0,0,0,100,0);
-- 0xF13059AC000009CE .go 917.291 427.4965 112.7681

-- Pathing for Sister of Pleasure Entry: 22964
SET @NPC := 53058;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=895.5066,`position_y`=366.5750,`position_z`=112.7681 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,895.5066,366.5750,112.7682,0,0,0,0,100,0),
(@PATH,2,888.5184,374.2009,112.7682,0,0,0,0,100,0),
(@PATH,3,883.6686,392.6964,112.7681,0,0,0,0,100,0),
(@PATH,4,886.7302,408.4905,112.7681,0,0,0,0,100,0),
(@PATH,5,893.3220,416.6875,112.7681,0,0,0,0,100,0),
(@PATH,6,905.9349,425.3075,112.7681,0,0,0,0,100,0),
(@PATH,7,914.2913,427.5420,112.7681,0,0,0,0,100,0),
(@PATH,8,914.5384,443.8321,112.7681,0,0,0,0,100,0),
(@PATH,9,915.1800,480.8630,121.0903,0,0,0,0,100,0),
(@PATH,10,915.1485,469.0914,112.7680,0,0,0,0,100,0),
(@PATH,11,914.9373,449.7413,112.7681,0,0,0,0,100,0),
(@PATH,12,916.7254,424.6992,112.7681,0,0,0,0,100,0),
(@PATH,13,930.1163,426.0226,112.7680,0,0,0,0,100,0),
(@PATH,14,945.0406,413.6415,112.7680,0,0,0,0,100,0),
(@PATH,15,950.6188,400.7162,112.7680,0,0,0,0,100,0),
(@PATH,16,950.3086,387.3529,112.7680,0,0,0,0,100,0),
(@PATH,17,946.4240,373.2702,112.7680,0,0,0,0,100,0),
(@PATH,18,935.4403,363.5050,112.7681,0,0,0,0,100,0),
(@PATH,19,922.0009,358.6350,112.7681,0,0,0,0,100,0),
(@PATH,20,906.0137,360.3520,112.7682,0,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=52854;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(52854,52854,0,0,2),
(52854,53058,3,270,2);

-- Pathing for Sister of Pain Entry: 22956
SET @NPC := 52850;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=863.5932,`position_y`=404.4617,`position_z`=192.8021 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,863.5932,404.4617,192.8021,0,0,0,0,100,0),
(@PATH,2,857.1285,400.2212,192.8021,0,0,0,0,100,0),
(@PATH,3,841.5421,399.2611,192.8021,0,0,0,0,100,0),
(@PATH,4,824.6133,403.406,192.8021,0,0,0,0,100,0),
(@PATH,5,809.0944,408.0469,192.8021,0,0,0,0,100,0),
(@PATH,6,803.2555,409.021,192.8021,0,0,0,0,100,0),
(@PATH,7,798.0318,415.624,192.8021,0,0,0,0,100,0),
(@PATH,8,797.907,434.2558,192.8021,0,0,0,0,100,0),
(@PATH,9,803.9134,446.4958,192.8102,0,0,0,0,100,0),
(@PATH,10,822.2453,446.5771,192.8121,0,0,0,0,100,0),
(@PATH,11,832.8823,444.5272,192.8021,0,0,0,0,100,0),
(@PATH,12,841.865,440.6642,192.8021,0,0,0,0,100,0),
(@PATH,13,857.7858,440.4023,192.8021,0,0,0,0,100,0),
(@PATH,14,868.998,422.5621,192.8202,0,0,0,0,100,0),
(@PATH,15,892.9637,421.5781,192.8236,0,0,0,0,100,0),
(@PATH,16,869.101,417.053,192.80818,0,0,0,0,100,0);
-- 0xF13059AC00000B10 .go 863.5932 404.4617 192.8021

-- Pathing for Sister of Pleasure Entry: 22964
SET @NPC := 53057;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=865.2386,`position_y`=401.9532,`position_z`=192.8021 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,865.2386,401.9532,192.8021,0,0,0,0,100,0),
(@PATH,2,857.3129,397.2269,192.8021,0,0,0,0,100,0),
(@PATH,3,840.8286,396.3472,192.8021,0,0,0,0,100,0),
(@PATH,4,823.7538,400.5318,192.8021,0,0,0,0,100,0),
(@PATH,5,808.6007,405.0878,192.8021,0,0,0,0,100,0),
(@PATH,6,800.9027,407.1597,192.8021,0,0,0,0,100,0),
(@PATH,7,795.0319,415.6039,192.8021,0,0,0,0,100,0),
(@PATH,8,795.2138,435.5774,192.8021,0,0,0,0,100,0),
(@PATH,9,803.9001,449.4958,192.8102,0,0,0,0,100,0),
(@PATH,10,822.8130,449.5229,192.8121,0,0,0,0,100,0),
(@PATH,11,834.0675,447.2832,192.8021,0,0,0,0,100,0),
(@PATH,12,841.9143,443.6638,192.8021,0,0,0,0,100,0),
(@PATH,13,860.3258,441.9986,192.8021,0,0,0,0,100,0),
(@PATH,14,869.1211,425.5596,192.8202,0,0,0,0,100,0),
(@PATH,15,893.0868,424.5756,192.8236,0,0,0,0,100,0),
(@PATH,16,868.987,420.166,192.80742,0,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=52850;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(52850,52850,0,0,2),
(52850,53057,3,270,2);
