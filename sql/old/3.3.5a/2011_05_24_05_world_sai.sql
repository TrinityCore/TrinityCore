-- Pathing for Zorus the Judicator Entry: 21774 (Replace)
SET @NPC := 76076;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3970.86,`position_y`=2191.12,`position_z`=101.885 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3959.922,2188.494,101.799,0,0,0,100,0),
(@PATH,2,-3951.734,2200.173,101.7906,0,0,0,100,0),
(@PATH,3,-3958.357,2210.038,101.9156,0,0,0,100,0),
(@PATH,4,-3967.201,2208.166,101.76,0,0,0,100,0),
(@PATH,5,-3972.306,2201.522,101.76,0,0,0,100,0),
(@PATH,6,-3992.194,2215.025,103.635,0,0,0,100,0),
(@PATH,7,-4014.109,2218.045,108.6923,0,0,0,100,0),
(@PATH,8,-4023.189,2214.694,109.9423,0,0,0,100,0),
(@PATH,9,-4019.969,2183.267,107.4989,0,0,0,100,0),
(@PATH,10,-4000.393,2174.054,104.3739,0,0,0,100,0),
(@PATH,11,-3970.86,2191.12,101.885,0,0,0,100,0);

-- Pathing for Wildhammer Guard Entry: 19353 (Replace)
SET @NPC := 69029;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3956.661,`position_y`=2150.609,`position_z`=99.19981 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3952.747,2135.461,98.19981,0,0,0,100,0),
(@PATH,2,-3942.882,2121.993,96.84258,0,0,0,100,0),
(@PATH,3,-3936.123,2108.748,95.46758,0,0,0,100,0),
(@PATH,4,-3928.641,2095.985,94.73193,0,0,0,100,0),
(@PATH,5,-3916.894,2085.577,94.10693,0,0,0,100,0),
(@PATH,6,-3905.937,2073.934,94.48193,3000,0,0,100,0),
(@PATH,7,-3916.894,2085.577,94.10693,0,0,0,100,0),
(@PATH,8,-3928.641,2095.985,94.73193,0,0,0,100,0),
(@PATH,9,-3936.123,2108.748,95.46758,0,0,0,100,0),
(@PATH,10,-3942.882,2121.993,96.84258,0,0,0,100,0),
(@PATH,11,-3952.747,2135.461,98.19981,0,0,0,100,0),
(@PATH,12,-3956.661,2150.609,99.19981,0,0,0,100,0),
(@PATH,13,-3958.419,2169.508,100.424,0,0,0,100,0),
(@PATH,14,-3945.74,2173.963,101.174,0,0,0,100,0),
(@PATH,15,-3941.273,2175.507,101.549,3000,0,0,100,0),
(@PATH,16,-3945.74,2173.963,101.174,0,0,0,100,0),
(@PATH,17,-3958.419,2169.508,100.424,0,0,0,100,0),
(@PATH,18,-3956.661,2150.609,99.19981,0,0,0,100,0);

-- Pathing for Wildhammer Guard Entry: 19353 (Replace)
SET @NPC := 69030;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3953.156,`position_y`=2196.489,`position_z`=101.799 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3956.213,2190.557,101.799,0,0,0,100,0),
(@PATH,2,-3961.978,2187.907,101.924,0,0,0,100,0),
(@PATH,3,-3970.904,2191.666,101.885,0,0,0,100,0),
(@PATH,4,-3977.542,2187.189,102.135,0,0,0,100,0),
(@PATH,5,-3984.635,2183.306,102.885,0,0,0,100,0),
(@PATH,6,-3994.975,2177.334,103.885,0,0,0,100,0),
(@PATH,7,-4002.002,2173.979,104.4989,0,0,0,100,0),
(@PATH,8,-4020.553,2182.329,107.4989,0,0,0,100,0),
(@PATH,9,-4022.445,2199.229,109.3739,0,0,0,100,0),
(@PATH,10,-4024.303,2213.243,110.0673,0,0,0,100,0),
(@PATH,11,-4019.943,2220.104,109.9423,0,0,0,100,0),
(@PATH,12,-4010.167,2219.025,107.8173,0,0,0,100,0),
(@PATH,13,-3997.926,2217.727,105.135,0,0,0,100,0),
(@PATH,14,-3987.671,2211.935,102.76,0,0,0,100,0),
(@PATH,15,-3976.702,2204.916,101.885,0,0,0,100,0),
(@PATH,16,-3971.531,2203.007,101.76,0,0,0,100,0),
(@PATH,17,-3967.494,2207.26,101.76,0,0,0,100,0),
(@PATH,18,-3961.75,2209.582,101.7906,0,0,0,100,0),
(@PATH,19,-3955.481,2208.423,101.9156,0,0,0,100,0),
(@PATH,20,-3952.822,2204.261,101.9156,0,0,0,100,0),
(@PATH,21,-3953.156,2196.489,101.799,0,0,0,100,0);

-- Pathing for Wildhammer Guard Entry: 19353
SET @NPC := 69036;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4027.414,`position_y`=2111.922,`position_z`=137.2429 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4010.903,2103.363,137.2429,0,0,0,100,0),
(@PATH,2,-4027.414,2111.922,137.2429,0,0,0,100,0),
(@PATH,3,-4040.183,2116.031,137.2471,0,0,0,100,0),
(@PATH,4,-4051.71,2120.875,137.254,0,0,0,100,0),
(@PATH,5,-4064.835,2126.483,137.2603,0,0,0,100,0),
(@PATH,6,-4061.585,2129.041,137.2603,0,0,0,100,0),
(@PATH,7,-4053.318,2126.078,137.2559,0,0,0,100,0),
(@PATH,8,-4049.116,2130.594,137.254,0,0,0,100,0),
(@PATH,9,-4030.205,2123.756,127.3917,0,0,0,100,0),
(@PATH,10,-4013.132,2115.52,115.9905,0,0,0,100,0),
(@PATH,11,-4008.05,2114.437,115.6337,0,0,0,100,0),
(@PATH,12,-4005.22,2120.062,115.6409,0,0,0,100,0),
(@PATH,13,-4000.72,2130.597,107.8586,0,0,0,100,0),
(@PATH,14,-3993.985,2139.561,104.7343,0,0,0,100,0),
(@PATH,15,-3984.795,2135.855,104.9843,0,0,0,100,0),
(@PATH,16,-3982.541,2129.627,105.0458,0,0,0,100,0),
(@PATH,17,-3963.905,2117.34,100.7176,0,0,0,100,0),
(@PATH,18,-3954.1,2115.367,97.96758,0,0,0,100,0),
(@PATH,19,-3946.531,2111.822,96.84258,0,0,0,100,0),
(@PATH,20,-3943.734,2106.022,96.21758,0,0,0,100,0),
(@PATH,21,-3946.531,2111.822,96.84258,0,0,0,100,0),
(@PATH,22,-3953.81,2115.304,97.96758,0,0,0,100,0),
(@PATH,23,-3963.905,2117.34,100.7176,0,0,0,100,0),
(@PATH,24,-3982.541,2129.627,105.0458,0,0,0,100,0),
(@PATH,25,-3984.795,2135.855,104.9843,0,0,0,100,0),
(@PATH,26,-3993.985,2139.561,104.7343,0,0,0,100,0),
(@PATH,27,-4000.72,2130.597,107.8586,0,0,0,100,0),
(@PATH,28,-4005.202,2120.103,115.6362,0,0,0,100,0),
(@PATH,29,-4008.05,2114.437,115.6337,0,0,0,100,0),
(@PATH,30,-4013.132,2115.52,115.9905,0,0,0,100,0),
(@PATH,31,-4030.205,2123.756,127.3917,0,0,0,100,0),
(@PATH,32,-4049.116,2130.594,137.254,0,0,0,100,0),
(@PATH,33,-4053.318,2126.078,137.2559,0,0,0,100,0),
(@PATH,34,-4061.585,2129.041,137.2603,0,0,0,100,0),
(@PATH,35,-4064.835,2126.483,137.2603,0,0,0,100,0),
(@PATH,36,-4051.71,2120.875,137.254,0,0,0,100,0),
(@PATH,37,-4040.183,2116.031,137.2471,0,0,0,100,0),
(@PATH,38,-4027.414,2111.922,137.2429,0,0,0,100,0);

-- Pathing for Thane Yoregar Entry: 21773
SET @NPC := 76075;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4034.194,`position_y`=2233.48,`position_z`=112.0453 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,17718, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4037.18,2229.153,112.0457,0,0,0,100,0),
(@PATH,2,-4043.923,2229.386,112.0464,0,0,0,100,0),
(@PATH,3,-4037.18,2229.153,112.0457,0,0,0,100,0),
(@PATH,4,-4034.194,2233.48,112.0453,0,0,0,100,0);

-- Pathing for Wildhammer Scout Entry: 19384
SET @NPC := 69128;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4022.309,`position_y`=2134.639,`position_z`=104.274 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4021.637,2136.38,104.274,0,0,0,100,0),
(@PATH,2,-4020.335,2138.243,104.274,0,0,0,100,0),
(@PATH,3,-4018.53,2139.381,104.274,0,0,0,100,0),
(@PATH,4,-4016.425,2138.772,104.274,10000,0,0,100,0),
(@PATH,5,-4017.231,2139.141,104.274,0,0,0,100,0),
(@PATH,6,-4018.49,2140.534,104.274,0,0,0,100,0),
(@PATH,7,-4019.722,2143.937,104.274,10000,0,0,100,0),
(@PATH,8,-4019.373,2143.061,104.274,0,0,0,100,0),
(@PATH,9,-4019.427,2140.091,104.274,0,0,0,100,0),
(@PATH,10,-4020.97,2136.993,104.274,0,0,0,100,0),
(@PATH,11,-4022.309,2134.639,104.274,15000,0,0,100,0);
