-- Pathing for Huntress Kima Entry: 18416
SET @NPC := 65808;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2541.65,`position_y`=7323.38,`position_z`=6.99469 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2552.386,7337.846,7.422175,0,0,0,100,0),
(@PATH,2,-2547.391,7352.353,7.047175,0,0,0,100,0),
(@PATH,3,-2544.842,7358.259,7.047175,0,0,0,100,0),
(@PATH,4,-2562.099,7370.443,10.00821,0,0,0,100,0),
(@PATH,5,-2567.579,7369.372,10.27306,0,0,0,100,0),
(@PATH,6,-2566.174,7349.837,9.922175,0,0,0,100,0),
(@PATH,7,-2567.789,7341.593,9.872525,0,0,0,100,0),
(@PATH,8,-2577.995,7329.614,12.45477,0,0,0,100,0),
(@PATH,9,-2585.894,7320.886,13.95477,0,0,0,100,0),
(@PATH,10,-2605.105,7337.934,22.81847,0,0,0,100,0),
(@PATH,11,-2617.94,7333.2,24.0994,0,0,0,100,0),
(@PATH,12,-2619.5,7314.92,24.7855,0,0,0,100,0),
(@PATH,13,-2620.33,7306.87,22.2298,0,0,0,100,0),
(@PATH,14,-2622.22,7295.57,20.8845,0,0,0,100,0),
(@PATH,15,-2634.28,7283.98,22.6251,0,0,0,100,0),
(@PATH,16,-2645.37,7281.6,26.8452,0,0,0,100,0),
(@PATH,17,-2658.313,7277.178,31.34583,0,0,0,100,0),
(@PATH,18,-2656.347,7260.406,27.72301,0,0,0,100,0),
(@PATH,19,-2654.6,7223.491,21.68772,0,0,0,100,0),
(@PATH,20,-2649.212,7219.171,21.31272,0,0,0,100,0),
(@PATH,21,-2639.123,7217.482,21.18772,0,0,0,100,0),
(@PATH,22,-2604.8,7231.363,14.29138,0,0,0,100,0),
(@PATH,23,-2598.992,7233.284,13.06854,0,0,0,100,0),
(@PATH,24,-2589.095,7238.978,13.30505,0,0,0,100,0),
(@PATH,25,-2572.705,7258.197,14.18005,0,0,0,100,0),
(@PATH,26,-2553.04,7268.31,14.8673,0,0,0,100,0),
(@PATH,27,-2549.93,7292.21,13.5737,0,0,0,100,0),
(@PATH,28,-2543.94,7296.78,12.03,0,0,0,100,0),
(@PATH,29,-2528.52,7302.51,7.70912,0,0,0,100,0),
(@PATH,30,-2525.95,7310.64,6.42796,0,0,0,100,0),
(@PATH,31,-2541.65,7323.38,6.99469,0,0,0,100,0);

-- Pathing for Sifreldar Storm Maiden Entry: 29323
SET @NPC := 108767;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6968.795,`position_y`=-1039.291,`position_z`=804.8483 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6939.001,-1039.968,810.5756,0,0,0,100,0),
(@PATH,2,6929.729,-1038.428,811.8507,0,0,0,100,0),
(@PATH,3,6921.97,-1037.384,813.6382,0,0,0,100,0),
(@PATH,4,6899.672,-1034.548,804.9947,0,0,0,100,0),
(@PATH,5,6887.367,-1040.131,803.7447,0,0,0,100,0),
(@PATH,6,6879.581,-1055.645,802.1197,0,0,0,100,0),
(@PATH,7,6881.092,-1067.551,802.7026,0,0,0,100,0),
(@PATH,8,6891.585,-1073.036,804.8276,0,0,0,100,0),
(@PATH,9,6904.774,-1076.266,808.0779,0,0,0,100,0),
(@PATH,10,6914.952,-1077.399,813.4417,0,0,0,100,0),
(@PATH,11,6931.681,-1078.594,810.6033,0,0,0,100,0),
(@PATH,12,6953.237,-1080.285,804.8708,0,0,0,100,0),
(@PATH,13,6963.347,-1080.42,804.8613,0,0,0,100,0),
(@PATH,14,6967.195,-1070.248,804.8578,0,0,0,100,0),
(@PATH,15,6967.463,-1053.253,804.8583,0,0,0,100,0),
(@PATH,16,6968.795,-1039.291,804.8483,0,0,0,100,0);

-- Pathing for Sifreldar Storm Maiden Entry: 29323
SET @NPC := 108780;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6849.583,`position_y`=-1122.161,`position_z`=799.7357 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6825.424,-1137.925,795.3445,0,0,0,100,0),
(@PATH,2,6823.116,-1152.258,802.8445,0,0,0,100,0),
(@PATH,3,6804.956,-1162.505,810.9695,0,0,0,100,0),
(@PATH,4,6823.116,-1152.258,802.8445,0,0,0,100,0),
(@PATH,5,6825.424,-1137.925,795.3445,0,0,0,100,0),
(@PATH,6,6849.583,-1122.161,799.7357,0,0,0,100,0),
(@PATH,7,6859.529,-1108.683,802.3607,0,0,0,100,0),
(@PATH,8,6869.339,-1099.14,802.9526,0,0,0,100,0),
(@PATH,9,6888.484,-1113.396,802.4324,0,0,0,100,0),
(@PATH,10,6899.414,-1132.413,801.4324,0,0,0,100,0),
(@PATH,11,6888.484,-1113.396,802.4324,0,0,0,100,0),
(@PATH,12,6869.339,-1099.14,802.9526,0,0,0,100,0),
(@PATH,13,6859.529,-1108.683,802.3607,0,0,0,100,0),
(@PATH,14,6849.583,-1122.161,799.7357,0,0,0,100,0);

-- Pathing for Sifreldar Runekeeper Entry: 29331
SET @NPC := 108779;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `id`=29331,`modelid`=0,`spawndist`=0,`MovementType`=2,`position_x`=6824.564,`position_y`=-1140.901,`position_z`=796.8445 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6819.699,-1158.881,805.9695,0,0,0,100,0),
(@PATH,2,6802.754,-1164.963,811.4695,0,0,0,100,0),
(@PATH,3,6819.699,-1158.881,805.9695,0,0,0,100,0),
(@PATH,4,6824.564,-1140.901,796.8445,0,0,0,100,0),
(@PATH,5,6793.759,-1107.705,773.118,0,0,0,100,0),
(@PATH,6,6824.564,-1140.901,796.8445,0,0,0,100,0);

-- Pathing for Dragonblight Mage Hunter Entry: 26280
SET @NPC := 101640;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3089.834,`position_y`=339.6018,`position_z`=71.35417 WHERE `guid`=@NPC;
DELETE FROM `creature` WHERE `guid`=111762;
DELETE FROM `creature_addon` WHERE `guid`=111762;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3101.223,333.8671,68.35417,0,0,0,100,0),
(@PATH,2,3089.834,339.6018,71.35417,0,0,0,100,0),
(@PATH,3,3074.878,340.6855,74.60417,0,0,0,100,0),
(@PATH,4,3059.406,343.7871,76.1516,0,0,0,100,0),
(@PATH,5,3048.349,347.3151,75.9016,0,0,0,100,0),
(@PATH,6,3059.406,343.7871,76.1516,0,0,0,100,0),
(@PATH,7,3074.878,340.6855,74.60417,0,0,0,100,0),
(@PATH,8,3089.834,339.6018,71.35417,0,0,0,100,0);

-- Pathing for Magnataur Patriarch Entry: 26295
SET @NPC := 113264;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3455.645,`position_y`=450.5741,`position_z`=55.77813 WHERE `guid`=@NPC;
DELETE FROM `creature` WHERE `guid`=131082;
DELETE FROM `creature_addon` WHERE `guid`=131082;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3461.032,458.0605,55.52813,0,0,0,100,0),
(@PATH,2,3459.928,468.002,57.48453,0,0,0,100,0),
(@PATH,3,3461.031,458.0605,55.52813,0,0,0,100,0),
(@PATH,4,3455.645,450.5741,55.77813,0,0,0,100,0),
(@PATH,5,3449.821,447.5877,56.65313,0,0,0,100,0),
(@PATH,6,3444.278,447.4793,57.77813,0,0,0,100,0),
(@PATH,7,3449.821,447.5877,56.65313,0,0,0,100,0),
(@PATH,8,3455.645,450.5741,55.77813,0,0,0,100,0);

-- Pathing for Magnataur Patriarch Entry: 26295
SET @NPC := 113259;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4335.951,`position_y`=-180.1597,`position_z`=80.65488 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4314.526,-194.2564,76.19753,0,0,0,100,0),
(@PATH,2,4310.347,-212.7189,75.1636,0,0,0,100,0),
(@PATH,3,4319.451,-236.1514,78.55873,0,0,0,100,0),
(@PATH,4,4310.347,-212.7189,75.1636,0,0,0,100,0),
(@PATH,5,4314.526,-194.2564,76.19753,0,0,0,100,0),
(@PATH,6,4335.951,-180.1597,80.65488,0,0,0,100,0);

-- Pathing for Anub'ar Cultist Entry: 26319
SET @NPC := 115435;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4063.753,`position_y`=2196.374,`position_z`=151.8217 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4054.478,2188.652,151.9467,0,0,0,100,0),
(@PATH,2,4039.943,2185.158,151.6967,0,0,0,100,0),
(@PATH,3,4054.478,2188.652,151.9467,0,0,0,100,0),
(@PATH,4,4063.753,2196.374,151.8217,0,0,0,100,0),
(@PATH,5,4066.901,2217.657,152.0965,0,0,0,100,0),
(@PATH,6,4060.092,2234.396,151.5342,0,0,0,100,0),
(@PATH,7,4066.901,2217.657,152.0965,0,0,0,100,0),
(@PATH,8,4063.753,2196.374,151.8217,0,0,0,100,0);

-- Pathing for Tempus Wyrm Entry: 32180
SET @NPC := 112957;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4165.901,`position_y`=-407.722,`position_z`=155.0924 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4161.29,-415.327,155.0924,0,0,0,100,0),
(@PATH,2,4157.975,-426.0655,155.0924,0,0,0,100,0),
(@PATH,3,4149.574,-441.3904,155.0924,0,0,0,100,0),
(@PATH,4,4138.248,-453.2982,155.0924,0,0,0,100,0),
(@PATH,5,4125.589,-462.9384,155.0924,0,0,0,100,0),
(@PATH,6,4108.414,-468.0847,155.0925,0,0,0,100,0),
(@PATH,7,4093.35,-469.384,155.0924,0,0,0,100,0),
(@PATH,8,4076.784,-468.8313,155.0924,0,0,0,100,0),
(@PATH,9,4060.223,-464.068,155.0924,0,0,0,100,0),
(@PATH,10,4047.407,-453.0881,155.0924,0,0,0,100,0),
(@PATH,11,4034.705,-434.9922,155.0924,0,0,0,100,0),
(@PATH,12,4028.23,-418.9452,155.0924,0,0,0,100,0),
(@PATH,13,4027.506,-402.0115,155.0925,0,0,0,100,0),
(@PATH,14,4032.801,-387.0902,155.0924,0,0,0,100,0),
(@PATH,15,4040.891,-372.8224,155.0924,0,0,0,100,0),
(@PATH,16,4051.813,-359.7613,155.0924,0,0,0,100,0),
(@PATH,17,4065.439,-349.6774,155.0924,0,0,0,100,0),
(@PATH,18,4080.03,-344.1142,155.0924,0,0,0,100,0),
(@PATH,19,4095.92,-340.0204,155.0924,0,0,0,100,0),
(@PATH,20,4118.203,-337.1474,155.0924,0,0,0,100,0),
(@PATH,21,4146.275,-349.1546,155.0924,0,0,0,100,0),
(@PATH,22,4157.594,-358.4243,155.0924,0,0,0,100,0),
(@PATH,23,4168.311,-372.3049,155.0925,0,0,0,100,0),
(@PATH,24,4170.974,-391.4471,155.0924,0,0,0,100,0),
(@PATH,25,4165.901,-407.722,155.0924,0,0,0,100,0);

-- Pathing for Infinite Eradicator Entry: 32185
SET @NPC := 113438;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4190.591,`position_y`=-350.934,`position_z`=146.6842 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4207.472,-375.1424,146.6842,0,0,0,100,0),
(@PATH,2,4214.245,-404.9322,146.6842,0,0,0,100,0),
(@PATH,3,4209.104,-434.3985,146.6843,0,0,0,100,0),
(@PATH,4,4196.61,-460.4471,146.6842,0,0,0,100,0),
(@PATH,5,4170.492,-477.5867,146.6842,0,0,0,100,0),
(@PATH,6,4139.513,-481.6089,146.6842,0,0,0,100,0),
(@PATH,7,4111.95,-465.5229,146.6842,0,0,0,100,0),
(@PATH,8,4091.976,-440.942,146.6842,0,0,0,100,0),
(@PATH,9,4095.912,-407.7865,146.6842,0,0,0,100,0),
(@PATH,10,4098.527,-380.9193,146.6842,0,0,0,100,0),
(@PATH,11,4091.802,-357.8462,146.6842,0,0,0,100,0),
(@PATH,12,4075.851,-333.6917,146.6842,0,0,0,100,0),
(@PATH,13,4055.005,-351.5806,146.6842,0,0,0,100,0),
(@PATH,14,4051.888,-372.2745,146.6842,0,0,0,100,0),
(@PATH,15,4056.19,-395.6217,146.6842,0,0,0,100,0),
(@PATH,16,4061.398,-417.6198,146.6842,0,0,0,100,0),
(@PATH,17,4062.656,-443.156,146.6842,0,0,0,100,0),
(@PATH,18,4085.277,-457.1473,146.6842,0,0,0,100,0),
(@PATH,19,4107.788,-455.9095,146.6842,0,0,0,100,0),
(@PATH,20,4117.597,-435.8233,146.6842,0,0,0,100,0),
(@PATH,21,4113.671,-413.1419,146.6842,0,0,0,100,0),
(@PATH,22,4105.402,-392.1701,146.6842,0,0,0,100,0),
(@PATH,23,4106.15,-363.3776,146.6842,0,0,0,100,0),
(@PATH,24,4131.285,-341.2223,146.6842,0,0,0,100,0),
(@PATH,25,4162.843,-332.6555,146.6842,0,0,0,100,0),
(@PATH,26,4190.591,-350.934,146.6842,0,0,0,100,0);

-- Pathing for Infinite Eradicator Entry: 32185
SET @NPC := 113436;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4181.173,`position_y`=-369.9417,`position_z`=146.6842 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4191.631,-389.251,146.6842,0,0,0,100,0),
(@PATH,2,4193.926,-411.0253,146.6842,0,0,0,100,0),
(@PATH,3,4187.936,-433.0087,146.6843,0,0,0,100,0),
(@PATH,4,4176.908,-452.5828,146.6842,0,0,0,100,0),
(@PATH,5,4156.808,-461.3777,146.6842,0,0,0,100,0),
(@PATH,6,4135.129,-460.8535,146.6842,0,0,0,100,0),
(@PATH,7,4119.67,-445.7643,146.6842,0,0,0,100,0),
(@PATH,8,4107.466,-426.4492,146.6842,0,0,0,100,0),
(@PATH,9,4117.114,-407.0864,146.6842,0,0,0,100,0),
(@PATH,10,4119.729,-381.6279,146.6842,0,0,0,100,0),
(@PATH,11,4112.734,-354.4067,146.6842,0,0,0,100,0),
(@PATH,12,4093.601,-322.0753,146.6842,0,0,0,100,0),
(@PATH,13,4052.978,-330.4644,146.6842,0,0,0,100,0),
(@PATH,14,4034.263,-360.4702,146.6842,0,0,0,100,0),
(@PATH,15,4035.172,-392.7458,146.6842,0,0,0,100,0),
(@PATH,16,4040.271,-419.5353,146.6842,0,0,0,100,0),
(@PATH,17,4041.469,-444.2213,146.6842,0,0,0,100,0),
(@PATH,18,4071.126,-472.951,146.6842,0,0,0,100,0),
(@PATH,19,4103.979,-476.7779,146.6842,0,0,0,100,0),
(@PATH,20,4129.341,-453.4892,146.6842,0,0,0,100,0),
(@PATH,21,4134.468,-417.3209,146.6842,0,0,0,100,0),
(@PATH,22,4126.431,-389.3766,146.6842,0,0,0,100,0),
(@PATH,23,4127.358,-363.8509,146.6842,0,0,0,100,0),
(@PATH,24,4147.167,-355.2841,146.6842,0,0,0,100,0),
(@PATH,25,4170.109,-352.5856,146.6842,0,0,0,100,0),
(@PATH,26,4181.173,-369.9417,146.6842,0,0,0,100,0);

-- Pathing for Laire Brewgold Entry: 32424
SET @NPC := 111730;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5661.111,`position_y`=726.7043,`position_z`=641.6643 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5656.774,721.9439,641.6959,0,0,0,100,0),
(@PATH,2,5653.122,721.5146,641.6296,0,0,0,100,0),
(@PATH,3,5649.408,722.6322,641.5455,0,0,0,100,0),
(@PATH,4,5645.466,725.3781,641.6395,0,0,0,100,0),
(@PATH,5,5639.154,728.4048,641.61,0,0,0,100,0),
(@PATH,6,5635.932,732.4274,641.7092,5000,0,0,100,0),
(@PATH,7,5639.154,728.4048,641.61,0,0,0,100,0),
(@PATH,8,5645.889,733.0624,641.682,0,0,0,100,0),
(@PATH,9,5655.076,730.4822,641.6819,0,0,0,100,0),
(@PATH,10,5661.111,726.7043,641.6643,0,0,0,100,0);

-- Fixup Injured Soldier Waypoint 01 Set as trigger
UPDATE `creature` SET `modelid`=0 WHERE `id` IN (27792);
UPDATE `creature_template` SET `InhabitType`=3,`flags_extra`=`flags_extra`|128 WHERE `entry` IN (27792);

-- Pathing for Injured Soldier Waypoint 01 Entry: 27792
SET @NPC := 133440;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3687.688,`position_y`=-1131.765,`position_z`=98.09109 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3694.245,-1132.365,97.6494,0,0,0,100,0),
(@PATH,2,3697.133,-1137.371,97.6494,0,0,0,100,0),
(@PATH,3,3707.083,-1140.569,98.09109,0,0,0,100,0),
(@PATH,4,3697.133,-1137.371,97.6494,0,0,0,100,0),
(@PATH,5,3694.245,-1132.365,97.6494,0,0,0,100,0),
(@PATH,6,3687.688,-1131.765,98.09109,0,0,0,100,0);

-- Pathing for Injured Soldier Waypoint 01 Entry: 27792
SET @NPC := 133441;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3639.129,`position_y`=-1245.702,`position_z`=98.09111 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3646.784,-1246.543,98.26001,0,0,0,100,0),
(@PATH,2,3647.515,-1248.791,98.26001,0,0,0,100,0),
(@PATH,3,3655.563,-1252.757,98.09111,0,0,0,100,0),
(@PATH,4,3647.515,-1248.791,98.26001,0,0,0,100,0),
(@PATH,5,3646.784,-1246.543,98.26001,0,0,0,100,0),
(@PATH,6,3639.129,-1245.702,98.09111,0,0,0,100,0),
(@PATH,7,3634.578,-1242.256,98.09111,0,0,0,100,0),
(@PATH,8,3639.129,-1245.702,98.09111,0,0,0,100,0);

-- Pathing for Injured Soldier Waypoint 01 Entry: 27792
SET @NPC := 133439;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3656.245,`position_y`=-1252.887,`position_z`=98.09111 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3634.244,-1242.946,98.09111,0,0,0,100,0),
(@PATH,2,3656.245,-1252.887,98.09111,0,0,0,100,0);

-- Pathing for Injured Soldier Waypoint 01 Entry: 27792
SET @NPC := 133438;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3706.577,`position_y`=-1140.745,`position_z`=98.09109 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3688.351,-1132.398,98.09109,0,0,0,100,0),
(@PATH,2,3706.577,-1140.745,98.09109,0,0,0,100,0);

DELETE FROM `creature` WHERE `guid`=109148;
DELETE FROM `creature_addon` WHERE `guid`=109148;

-- Fixup Injured Soldier Waypoint 02 Set as trigger
UPDATE `creature` SET `modelid`=0 WHERE `id` IN (27793);
UPDATE `creature_template` SET `InhabitType`=3,`flags_extra`=`flags_extra`|128 WHERE `entry` IN (27793);

-- Pathing for Injured Soldier Waypoint 02 Entry: 27793
SET @NPC := 133449;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3662.666,`position_y`=-1239.828,`position_z`=98.09111 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3641.625,-1230.667,98.09111,0,0,0,100,0),
(@PATH,2,3662.666,-1239.828,98.09111,0,0,0,100,0);

-- Pathing for Injured Soldier Waypoint 02 Entry: 27793
SET @NPC := 133450;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3680.119,`position_y`=-1145.329,`position_z`=98.09109 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3688.248,-1146.153,97.6494,0,0,0,100,0),
(@PATH,2,3691.404,-1149.929,97.6494,0,0,0,100,0),
(@PATH,3,3694.596,-1152.75,97.6494,0,0,0,100,0),
(@PATH,4,3700.401,-1152.819,98.09109,0,0,0,100,0),
(@PATH,5,3701.976,-1154.921,98.09109,0,0,0,100,0),
(@PATH,6,3700.401,-1152.819,98.09109,0,0,0,100,0),
(@PATH,7,3694.596,-1152.75,97.6494,0,0,0,100,0),
(@PATH,8,3691.404,-1149.929,97.6494,0,0,0,100,0),
(@PATH,9,3688.248,-1146.153,97.6494,0,0,0,100,0),
(@PATH,10,3680.119,-1145.329,98.09109,0,0,0,100,0);

-- Pathing for Injured Soldier Waypoint 02 Entry: 27793
SET @NPC := 109632;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `id`=27793,`spawndist`=0,`MovementType`=2,`position_x`=3681.213,`position_y`=-1145.856,`position_z`=98.09109 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3699.753,-1153.359,98.09109,0,0,0,100,0),
(@PATH,2,3681.213,-1145.856,98.09109,0,0,0,100,0);

-- Pathing for Injured Soldier Waypoint 02 Entry: 27793
SET @NPC := 109633;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `id`=27793,`spawndist`=0,`MovementType`=2,`position_x`=3640.924,`position_y`=-1231.039,`position_z`=98.09111 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3649.915,-1232.593,98.26001,0,0,0,100,0),
(@PATH,2,3656.266,-1238.324,98.09111,0,0,0,100,0),
(@PATH,3,3660.733,-1237.718,98.09111,0,0,0,100,0),
(@PATH,4,3656.266,-1238.324,98.09111,0,0,0,100,0),
(@PATH,5,3649.915,-1232.593,98.26001,0,0,0,100,0),
(@PATH,6,3640.924,-1231.039,98.09111,0,0,0,100,0);

-- Fixup Injured Soldier Waypoint 03 Set as trigger
UPDATE `creature` SET `modelid`=0 WHERE `id` IN (27794);
UPDATE `creature_template` SET `InhabitType`=3,`flags_extra`=`flags_extra`|128 WHERE `entry` IN (27794);

-- Pathing for Injured Soldier Waypoint 03 Entry: 27794
SET @NPC := 133451;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3661.358,`position_y`=-1221.376,`position_z`=98.09111 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3665.178,-1225.378,98.09111,0,0,0,100,0),
(@PATH,2,3661.358,-1221.376,98.09111,0,0,0,100,0),
(@PATH,3,3654.384,-1216.99,98.09111,0,0,0,100,0),
(@PATH,4,3647.583,-1216.188,98.09111,0,0,0,100,0),
(@PATH,5,3654.384,-1216.99,98.09111,0,0,0,100,0),
(@PATH,6,3661.358,-1221.376,98.09111,0,0,0,100,0);

-- Pathing for Injured Soldier Waypoint 03 Entry: 27794
SET @NPC := 133452;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3668.855,`position_y`=-1225.114,`position_z`=98.09111 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3647.801,-1216.172,98.09111,0,0,0,100,0),
(@PATH,2,3668.855,-1225.114,98.09111,0,0,0,100,0);

-- Pathing for Injured Soldier Waypoint 03 Entry: 27794
SET @NPC := 133453;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3675.706,`position_y`=-1162.181,`position_z`=98.09109 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3693.215,-1169.852,98.09109,0,0,0,100,0),
(@PATH,2,3675.706,-1162.181,98.09109,0,0,0,100,0);

-- Pathing for Injured Soldier Waypoint 03 Entry: 27794
SET @NPC := 133454;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3685.215,`position_y`=-1162.893,`position_z`=97.6494 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3685.235,-1167.974,98.09109,0,0,0,100,0),
(@PATH,2,3694.442,-1170.397,98.09109,0,0,0,100,0),
(@PATH,3,3685.235,-1167.974,98.09109,0,0,0,100,0),
(@PATH,4,3685.316,-1162.941,97.6494,0,0,0,100,0),
(@PATH,5,3675.632,-1164.499,98.09109,0,0,0,100,0),
(@PATH,6,3674.321,-1160.317,98.09109,0,0,0,100,0),
(@PATH,7,3675.632,-1164.499,98.09109,0,0,0,100,0),
(@PATH,8,3685.215,-1162.893,97.6494,0,0,0,100,0);

-- Fixup Injured Soldier Summon Point Set as trigger
UPDATE `creature` SET `modelid`=0 WHERE `id` IN (27795);
UPDATE `creature_template` SET `InhabitType`=3,`flags_extra`=`flags_extra`|128 WHERE `entry` IN (27795);

-- Pathing for Injured Soldier Summon Point Entry: 27795
SET @NPC := 109737;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3635.371,`position_y`=-1260.123,`position_z`=98.09111 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3639.637,-1256.701,98.09111,0,0,0,100,0),
(@PATH,2,3641.038,-1263.186,98.09111,0,0,0,100,0),
(@PATH,3,3645.456,-1260.151,98.09111,0,0,0,100,0),
(@PATH,4,3646.584,-1265.838,98.09111,0,0,0,100,0),
(@PATH,5,3649.356,-1262.853,98.09111,0,0,0,100,0),
(@PATH,6,3650.487,-1267.485,98.09111,0,0,0,100,0),
(@PATH,7,3649.356,-1262.853,98.09111,0,0,0,100,0),
(@PATH,8,3646.584,-1265.838,98.09111,0,0,0,100,0),
(@PATH,9,3645.456,-1260.151,98.09111,0,0,0,100,0),
(@PATH,10,3641.148,-1263.11,98.09111,0,0,0,100,0),
(@PATH,11,3639.637,-1256.701,98.09111,0,0,0,100,0),
(@PATH,12,3635.371,-1260.123,98.09111,0,0,0,100,0),
(@PATH,13,3634.036,-1255.147,98.09111,0,0,0,100,0),
(@PATH,14,3628.426,-1256.89,98.09111,0,0,0,100,0),
(@PATH,15,3634.036,-1255.147,98.09111,0,0,0,100,0),
(@PATH,16,3635.371,-1260.123,98.09111,0,0,0,100,0);

-- Pathing for Injured Soldier Summon Point Entry: 27795
SET @NPC := 133459;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3639.455,`position_y`=-1259.333,`position_z`=98.09111 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3635.177,-1258.972,98.09111,0,0,0,100,0),
(@PATH,2,3628.478,-1255.191,98.09111,0,0,0,100,0),
(@PATH,3,3635.177,-1258.972,98.09111,0,0,0,100,0),
(@PATH,4,3639.455,-1259.333,98.09111,0,0,0,100,0),
(@PATH,5,3649.663,-1265.676,98.09111,0,0,0,100,0),
(@PATH,6,3639.455,-1259.333,98.09111,0,0,0,100,0);

-- Pathing for Injured Soldier Summon Point Entry: 27795
SET @NPC := 133458;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3690.377,`position_y`=-1120.719,`position_z`=98.09109 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3714.914,-1132.499,98.09109,0,0,0,100,0),
(@PATH,2,3690.377,-1120.719,98.09109,0,0,0,100,0);

-- Pathing for Injured Soldier Summon Point Entry: 27795
SET @NPC := 133456;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3704.953,`position_y`=-1125.08,`position_z`=98.09109 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3695.954,-1125.092,98.09109,0,0,0,100,0),
(@PATH,2,3690.822,-1117.956,98.09109,0,0,0,100,0),
(@PATH,3,3695.954,-1125.092,98.09109,0,0,0,100,0),
(@PATH,4,3704.953,-1125.08,98.09109,0,0,0,100,0),
(@PATH,5,3711.798,-1131.639,98.09109,0,0,0,100,0),
(@PATH,6,3704.953,-1125.08,98.09109,0,0,0,100,0);

-- Pathing for Tattered Abomination Entry: 27797
SET @NPC := 133490;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3596.785,`position_y`=-1234.963,`position_z`=89.07387 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3611.023,-1205.49,89.12477,0,0,0,100,0),
(@PATH,2,3596.785,-1234.963,89.07387,0,0,0,100,0);
-- 0xF130006C9505F3CC .go 3611.023 -1205.49 89.12477

-- Pathing for Carrion Condor Entry: 26174
SET @NPC := 101925;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3451.899,`position_y`=3774.349,`position_z`=60.27904 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3448.265,3763.589,58.0846,0,0,0,100,0),
(@PATH,2,3436.357,3758.859,60.27904,0,0,0,100,0),
(@PATH,3,3427.118,3761.404,60.27904,0,0,0,100,0),
(@PATH,4,3424.513,3775.218,58.22348,0,0,0,100,0),
(@PATH,5,3436.752,3781.46,63.00128,0,0,0,100,0),
(@PATH,6,3451.899,3774.349,60.27904,0,0,0,100,0);

-- Pathing for Carrion Condor Entry: 26174
SET @NPC := 101886;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3470.062,`position_y`=3504.777,`position_z`=60.02877 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3489.508,3468.938,55.75098,0,0,0,100,0),
(@PATH,2,3510.609,3460.939,68.02877,0,0,0,100,0),
(@PATH,3,3538.059,3469.108,64.88989,0,0,0,100,0),
(@PATH,4,3555.875,3503.135,68.02877,0,0,0,100,0),
(@PATH,5,3568.626,3532.901,68.02877,0,0,0,100,0),
(@PATH,6,3563.242,3557.899,68.02877,0,0,0,100,0),
(@PATH,7,3527.993,3578.705,68.02877,0,0,0,100,0),
(@PATH,8,3490.05,3549.902,68.02877,0,0,0,100,0),
(@PATH,9,3470.062,3504.777,60.02877,0,0,0,100,0);

-- Pathing for Carrion Condor Entry: 26174
SET @NPC := 101817;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3499.697,`position_y`=3508.944,`position_z`=62.80863 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3496.299,3531.275,62.80864,0,0,0,100,0),
(@PATH,2,3502.673,3553.807,62.08641,0,0,0,100,0),
(@PATH,3,3522.777,3562.911,64.72532,0,0,0,100,0),
(@PATH,4,3549.392,3558.91,58.39198,0,0,0,100,0),
(@PATH,5,3561,3538.082,64.39198,0,0,0,100,0),
(@PATH,6,3554.785,3496.833,60.16974,0,0,0,100,0),
(@PATH,7,3518.356,3475.909,62.80864,0,0,0,100,0),
(@PATH,8,3499.697,3508.944,62.80863,0,0,0,100,0);

-- Pathing for Carrion Condor Entry: 26174
SET @NPC := 101887;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3487.025,`position_y`=3801.495,`position_z`=64.28619 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3508.315,3787.482,64.28619,0,0,0,100,0),
(@PATH,2,3525.658,3795.386,64.28619,0,0,0,100,0),
(@PATH,3,3515.372,3818.548,64.28619,0,0,0,100,0),
(@PATH,4,3510.063,3829.02,64.28619,0,0,0,100,0),
(@PATH,5,3500.235,3840.592,64.28619,0,0,0,100,0),
(@PATH,6,3487.377,3829.144,64.28619,0,0,0,100,0),
(@PATH,7,3487.025,3801.495,64.28619,0,0,0,100,0);

-- Pathing for Carrion Condor Entry: 26174
SET @NPC := 101840;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3525.344,`position_y`=3832.733,`position_z`=69.65799 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3531.916,3820.634,72.24132,0,0,0,100,0),
(@PATH,2,3526.877,3800.81,72.24132,0,0,0,100,0),
(@PATH,3,3515.555,3788.204,72.24132,0,0,0,100,0),
(@PATH,4,3500.742,3787.609,72.24132,0,0,0,100,0),
(@PATH,5,3491.085,3798.095,70.21355,0,0,0,100,0),
(@PATH,6,3493.959,3822.765,75.10243,0,0,0,100,0),
(@PATH,7,3505.338,3836.017,72.24132,0,0,0,100,0),
(@PATH,8,3525.344,3832.733,69.65799,0,0,0,100,0);

-- Pathing for Carrion Condor Entry: 26174
SET @NPC := 101929;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3512.759,`position_y`=3582.701,`position_z`=53.18045 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3535.782,3562.454,57.09711,0,0,0,100,0),
(@PATH,2,3546.515,3533.243,53.18045,0,0,0,100,0),
(@PATH,3,3551.337,3503.115,53.18045,0,0,0,100,0),
(@PATH,4,3538.455,3471.695,53.18045,0,0,0,100,0),
(@PATH,5,3508.635,3459.773,53.18045,0,0,0,100,0),
(@PATH,6,3482.672,3471.235,53.18045,0,0,0,100,0),
(@PATH,7,3466.057,3507.579,53.18045,0,0,0,100,0),
(@PATH,8,3464.838,3544.961,53.18045,0,0,0,100,0),
(@PATH,9,3486.096,3576.008,53.18045,0,0,0,100,0),
(@PATH,10,3512.759,3582.701,53.18045,0,0,0,100,0);

-- Pathing for Carrion Condor Entry: 26174
SET @NPC := 101855;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3561,`position_y`=3538.082,`position_z`=64.39198 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3554.785,3496.833,60.16974,0,0,0,100,0),
(@PATH,2,3518.356,3475.909,62.80864,0,0,0,100,0),
(@PATH,3,3499.697,3508.944,62.80863,0,0,0,100,0),
(@PATH,4,3496.299,3531.275,62.80864,0,0,0,100,0),
(@PATH,5,3502.673,3553.807,62.08641,0,0,0,100,0),
(@PATH,6,3522.777,3562.911,64.72532,0,0,0,100,0),
(@PATH,7,3549.392,3558.91,58.39198,0,0,0,100,0),
(@PATH,8,3561,3538.082,64.39198,0,0,0,100,0);

-- Pathing for Grove Walker Entry: 31228
SET @NPC := 120259;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5767.086,`position_y`=554.6254,`position_z`=159.9334 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5788.306,541.5344,167.8084,0,0,0,100,0),
(@PATH,2,5811.419,543.5833,174.3569,0,0,0,100,0),
(@PATH,3,5820.507,571.3627,171.8876,0,0,0,100,0),
(@PATH,4,5808.849,592.7281,167.2626,0,0,0,100,0),
(@PATH,5,5794.39,615.308,162.3778,0,0,0,100,0),
(@PATH,6,5782.429,599.8776,160.4631,0,0,0,100,0),
(@PATH,7,5772.276,576.5581,158.2131,0,0,0,100,0),
(@PATH,8,5767.086,554.6254,159.9334,0,0,0,100,0);

-- Pathing for Ancient Watcher Entry: 31229
SET @NPC := 120410;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5790.005,`position_y`=419.9462,`position_z`=177.7312 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5825.215,357.9948,189.9353,0,0,0,100,0),
(@PATH,2,5790.005,419.9462,177.7312,0,0,0,100,0),
(@PATH,3,5799.53,427.6059,180.2312,0,0,0,100,0),
(@PATH,4,5802.141,444.2674,181.5455,0,0,0,100,0),
(@PATH,5,5806.649,507.7448,178.8326,0,0,0,100,0),
(@PATH,6,5814.846,560.8038,170.8569,0,0,0,100,0),
(@PATH,7,5781.772,575.9896,160.5881,0,0,0,100,0),
(@PATH,8,5786.224,593.0746,162.2131,0,0,0,100,0),
(@PATH,9,5816.907,596.3663,169.6376,0,0,0,100,0),
(@PATH,10,5786.224,593.0746,162.2131,0,0,0,100,0),
(@PATH,11,5781.772,575.9896,160.5881,0,0,0,100,0),
(@PATH,12,5814.846,560.8038,170.8569,0,0,0,100,0),
(@PATH,13,5806.649,507.7448,178.8326,0,0,0,100,0),
(@PATH,14,5802.141,444.2674,181.5455,0,0,0,100,0),
(@PATH,15,5799.53,427.6059,180.2312,0,0,0,100,0),
(@PATH,16,5790.005,419.9462,177.7312,0,0,0,100,0);

-- Pathing for Northrend Daily Dungeon Image Bunny Entry: 32265
SET @NPC := 97334;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5704.948,`position_y`=584.5382,`position_z`=653.6223 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5703.734,582.9427,653.631,0,0,0,100,0),
(@PATH,2,5701.61,583.4393,653.6489,0,0,0,100,0),
(@PATH,3,5700.888,585.4722,653.6498,0,0,0,100,0),
(@PATH,4,5702.143,586.9913,653.6417,0,0,0,100,0),
(@PATH,5,5704.137,586.5278,653.6327,0,0,0,100,0),
(@PATH,6,5704.948,584.5382,653.6223,0,0,0,100,0);
-- 0xF130007E090099EB .go 5703.734 582.9427 653.631
-- Fixup Northrend Daily Dungeon Image Bunny Set as trigger
UPDATE `creature` SET `modelid`=0 WHERE `id` IN (32265);
UPDATE `creature_template` SET `InhabitType`=7,`flags_extra`=`flags_extra`|128 WHERE `entry` IN (32265);

-- Pathing for Vern Entry: 32435 (RARE)
SET @NPC := 112862;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5856.26,`position_y`=589.199,`position_z`=608.38 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5849.843,581.8642,610.2223,0,0,0,100,0),
(@PATH,2,5856.26,589.199,608.38,0,0,0,100,0),
(@PATH,3,5848.6,611.398,605.308,0,0,0,100,0),
(@PATH,4,5861.108,630.3746,601.8403,0,0,0,100,0),
(@PATH,5,5848.6,611.398,605.308,0,0,0,100,0),
(@PATH,6,5856.26,589.199,608.38,0,0,0,100,0);

-- Pathing for Underbelly Croc Entry: 32441
SET @NPC := 113419;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5894.618,`position_y`=654.9387,`position_z`=615.2944 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5881.377,637.9071,615.1934,0,0,0,100,0),
(@PATH,2,5894.618,654.9387,615.2944,0,0,0,100,0);

