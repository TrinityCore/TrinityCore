-- Pathing for Silverback Patriarch Entry: 1558
SET @NPC := 749;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-13838.81,`position_y`=-41.79492,`position_z`=57.10373 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-13838.81,-41.79492,57.10373,0,0,0,0,100,0),
(@PATH,2,-13838.5,-38.40104,57.65744,0,0,0,0,100,0),
(@PATH,3,-13836.35,-38.66819,59.79758,0,0,0,0,100,0),
(@PATH,4,-13832.86,-39.19607,63.04682,0,0,0,0,100,0),
(@PATH,5,-13831.31,-36.38173,64.45819,0,0,0,0,100,0),
(@PATH,6,-13830.13,-33.02333,65.43832,0,0,0,0,100,0),
(@PATH,7,-13828.11,-29.58236,66.1478,0,0,0,0,100,0),
(@PATH,8,-13824.51,-25.85015,65.75058,0,0,0,0,100,0),
(@PATH,9,-13830.01,-34.07888,65.5036,0,0,0,0,100,0),
(@PATH,10,-13831.8,-38.61513,63.99628,0,0,0,0,100,0),
(@PATH,11,-13833.62,-39.39497,62.43454,0,0,0,0,100,0),
(@PATH,12,-13836.13,-38.83323,60.02853,0,0,0,0,100,0),
(@PATH,13,-13838.13,-38.85352,58.11642,0,0,0,0,100,0),
(@PATH,14,-13839.39,-40.52235,56.70822,0,0,0,0,100,0),
(@PATH,15,-13838.61,-42.74751,57.09225,0,0,0,0,100,0),
(@PATH,16,-13836.2,-45.23134,57.99826,0,0,0,0,100,0),
(@PATH,17,-13835.5,-48.41515,57.52194,0,0,0,0,100,0),
(@PATH,18,-13836.58,-51.4235,56.96213,0,0,0,0,100,0),
(@PATH,19,-13836.19,-54.46452,56.9155,0,0,0,0,100,0),
(@PATH,20,-13833.54,-58.13335,56.65427,0,0,0,0,100,0),
(@PATH,21,-13829.67,-61.67665,56.68818,0,0,0,0,100,0),
(@PATH,22,-13826.99,-63.81337,56.73749,0,0,0,0,100,0),
(@PATH,23,-13832.18,-58.75868,56.71039,0,0,0,0,100,0),
(@PATH,24,-13835.33,-53.75391,57.13693,0,0,0,0,100,0),
(@PATH,25,-13835.29,-48.64996,57.6257,0,0,0,0,100,0),
(@PATH,26,-13836.21,-45.25011,57.99411,0,0,0,0,100,0);
-- .go -13838.81 -41.79492 57.10373

-- Pathing for Bloodsail Deckhand Entry: 4505
SET @NPC := 2597;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-14943.2,`position_y`=356.997,`position_z`=12.59546 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-14943.2,356.997,12.59546,0,0,0,0,100,0),
(@PATH,2,-14940.8,348.512,7.541732,0,0,0,0,100,0),
(@PATH,3,-14940.6,346.788,7.541214,0,0,0,0,100,0),
(@PATH,4,-14944.1,346.391,7.542305,0,0,0,0,100,0),
(@PATH,5,-14949.2,345.878,7.542548,0,0,0,0,100,0),
(@PATH,6,-14955.6,344.557,7.542547,0,0,0,0,100,0),
(@PATH,7,-14954.4,340.313,7.542553,0,0,0,0,100,0),
(@PATH,8,-14955.6,344.557,7.542547,0,0,0,0,100,0),
(@PATH,9,-14949.2,345.878,7.542548,0,0,0,0,100,0),
(@PATH,10,-14944.1,346.391,7.542305,0,0,0,0,100,0),
(@PATH,11,-14940.6,346.788,7.541214,0,0,0,0,100,0),
(@PATH,12,-14940.8,348.512,7.541732,0,0,0,0,100,0),
(@PATH,13,-14942.7,355.733,12.4607,0,0,0,0,100,0),
(@PATH,14,-14944.9,357.038,12.59546,0,0,0,0,100,0);
-- .go -14943.2 356.997 12.59546

-- Pathing for Bloodsail Deckhand Entry: 4505
SET @NPC := 2629;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-14979.3,`position_y`=265.158,`position_z`=7.921213 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-14979.3,265.158,7.921213,0,0,0,0,100,0),
(@PATH,2,-14974.15,264.915,7.921058,0,0,0,0,100,0),
(@PATH,3,-14968.1,264.92,4.665063,0,0,0,0,100,0),
(@PATH,4,-14965.3,267.002,4.658327,0,0,0,0,100,0),
(@PATH,5,-14975.79,269.4849,0.9351397,0,0,0,0,100,0),
(@PATH,6,-14965.2,268.908,4.658086,0,0,0,0,100,0),
(@PATH,7,-14965,264.917,4.657606,0,0,0,0,100,0),
(@PATH,8,-14968.2,264.917,4.665308,0,0,0,0,100,0),
(@PATH,9,-14974.2,264.797,7.881999,0,0,0,0,100,0);
-- .go -14979.3 265.158 7.921213

-- Pathing for Bloodsail Elder Magus Entry: 1653
SET @NPC := 2592;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-14956.4,`position_y`=353.116,`position_z`=7.54255 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-14956.4,353.116,7.54255,0,0,0,0,100,0),
(@PATH,2,-14949.4,356.132,7.54255,0,0,0,0,100,0),
(@PATH,3,-14944.9,357.394,7.544742,0,0,0,0,100,0),
(@PATH,4,-14936.1,355.807,7.542393,0,0,0,0,100,0),
(@PATH,5,-14934.4,350.286,7.54255,0,0,0,0,100,0),
(@PATH,6,-14936.1,355.807,7.542393,0,0,0,0,100,0),
(@PATH,7,-14944.9,357.394,7.544742,0,0,0,0,100,0),
(@PATH,8,-14949.4,356.132,7.54255,0,0,0,0,100,0),
(@PATH,9,-14956.4,353.116,7.54255,0,0,0,0,100,0),
(@PATH,10,-14962.9,351.408,7.544349,0,0,0,0,100,0),
(@PATH,11,-14971.6,347.196,7.542575,0,0,0,0,100,0),
(@PATH,12,-14962.9,351.408,7.544349,0,0,0,0,100,0);
-- .go -14956.4 353.116 7.54255

-- Pathing for Bloodsail Sea Dog Entry: 1565
SET @NPC := 2633;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-14998.4,`position_y`=261.767,`position_z`=7.921235 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-14998.4,261.767,7.921235,0,0,0,0,100,0),
(@PATH,2,-14995,261.635,7.921237,0,0,0,0,100,0),
(@PATH,3,-14993.8,266.361,6.306773,0,0,0,0,100,0),
(@PATH,4,-14992.8,266.477,6.306773,0,0,0,0,100,0),
(@PATH,5,-14993.18,266.3545,6.306773,0,0,0,0,100,0),
(@PATH,6,-14993.3,261.415,7.922341,0,0,0,0,100,0),
(@PATH,7,-14994.1,256.648,7.922004,0,0,0,0,100,0),
(@PATH,8,-14995,261.635,7.921237,0,0,0,0,100,0),
(@PATH,9,-14998.4,261.767,7.921235,0,0,0,0,100,0),
(@PATH,10,-14999.5,257.26,7.921242,0,0,0,0,100,0),
(@PATH,11,-14999.7,269.5383,7.921235,0,0,0,0,100,0),
(@PATH,12,-14999.24,270.291,7.921232,0,0,0,0,100,0),
(@PATH,13,-14994.7,270.899,7.921236,0,0,0,0,100,0),
(@PATH,14,-14993.9,275.938,7.921239,0,0,0,0,100,0),
(@PATH,15,-14992.9,271.8,7.921234,0,0,0,0,100,0),
(@PATH,16,-14987.2,270.889,7.923097,0,0,0,0,100,0),
(@PATH,17,-14982.9,272.309,7.921443,0,0,0,0,100,0),
(@PATH,18,-14982.7,275.998,7.921844,0,0,0,0,100,0),
(@PATH,19,-14982.8,272.679,7.921484,0,0,0,0,100,0),
(@PATH,20,-14977,272.87,7.921478,0,0,0,0,100,0),
(@PATH,21,-14976.6,275.734,7.921723,0,0,0,0,100,0),
(@PATH,22,-14977,257.986,7.921237,0,0,0,0,100,0),
(@PATH,23,-14977.7,261.219,7.921233,0,0,0,0,100,0),
(@PATH,24,-14982.1,261.434,7.921239,0,0,0,0,100,0),
(@PATH,25,-14982.8,258.325,7.92124,0,0,0,0,100,0),
(@PATH,26,-14982.1,261.434,7.921239,0,0,0,0,100,0),
(@PATH,27,-14979.8,261.929,7.921233,0,0,0,0,100,0),
(@PATH,28,-14977,257.986,7.921237,0,0,0,0,100,0),
(@PATH,29,-14977,272.87,7.921478,0,0,0,0,100,0),
(@PATH,30,-14982.8,272.679,7.921484,0,0,0,0,100,0),
(@PATH,31,-14982.7,275.998,7.921844,0,0,0,0,100,0),
(@PATH,32,-14982.9,272.309,7.921443,0,0,0,0,100,0),
(@PATH,33,-14987.2,270.889,7.923097,0,0,0,0,100,0),
(@PATH,34,-14992.73,271.7733,7.921853,0,0,0,0,100,0),
(@PATH,35,-14993.9,275.938,7.921239,0,0,0,0,100,0),
(@PATH,36,-14994.7,270.899,7.921236,0,0,0,0,100,0),
(@PATH,37,-14999.24,270.291,7.921235,0,0,0,0,100,0),
(@PATH,38,-14999.4,275.372,7.92124,0,0,0,0,100,0),
(@PATH,39,-14999.7,269.592,7.921232,0,0,0,0,100,0),
(@PATH,40,-14999.5,257.26,7.921242,0,0,0,0,100,0);
-- .go -14998.4 261.767 7.921235

-- Pathing for Bloodsail Deckhand Entry: 4505
SET @NPC := 2598;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-14960.1,`position_y`=342.326,`position_z`=7.543998 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-14960.1,342.326,7.543998,0,0,0,0,100,0),
(@PATH,2,-14956.5,345.042,7.542546,0,0,0,0,100,0),
(@PATH,3,-14951.4,349.271,7.542691,0,0,0,0,100,0),
(@PATH,4,-14956.5,345.042,7.542546,0,0,0,0,100,0),
(@PATH,5,-14960.1,342.326,7.543998,0,0,0,0,100,0),
(@PATH,6,-14969,340.03,7.542808,0,0,0,0,100,0),
(@PATH,7,-14974.56,345.089,7.542461,0,0,0,0,100,0),
(@PATH,8,-14977,344.637,7.117788,0,0,0,0,100,0),
(@PATH,9,-14982.7,343.339,4.284928,0,0,0,0,100,0),
(@PATH,10,-14984.6,341.158,4.279126,0,0,0,0,100,0),
(@PATH,11,-14982.7,343.339,4.284928,0,0,0,0,100,0),
(@PATH,12,-14977,344.637,7.117788,0,0,0,0,100,0),
(@PATH,13,-14974.6,345.128,7.542428,0,0,0,0,100,0),
(@PATH,14,-14969,340.03,7.542808,0,0,0,0,100,0);
-- .go -14960.1 342.326 7.543998

-- Pathing for Guard Lasiter Entry: 4973
SET @NPC := 30458;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3772.623,`position_y`=-4533.357,`position_z`=11.58731 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3772.623,-4533.357,11.58731,0,22000,0,0,100,0),
(@PATH,2,-3770.078,-4531.741,11.54261,0,24000,0,0,100,0);
-- .go -3772.623 -4533.357 11.58731

-- Pathing for Privateer Entry: 23620
SET @NPC := 31209;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4060.446,`position_y`=-4506.618,`position_z`=6.030344 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4060.446,-4506.618,6.030344,0,0,0,0,100,0),
(@PATH,2,-4059.9,-4511.36,6.031829,0,0,0,0,100,0),
(@PATH,3,-4060.427,-4506.697,6.03091,0,0,0,0,100,0),
(@PATH,4,-4066.929,-4501.822,6.031856,0,0,0,0,100,0),
(@PATH,5,-4072.242,-4506.002,6.032337,0,0,0,0,100,0),
(@PATH,6,-4066.929,-4501.822,6.031856,0,0,0,0,100,0);
-- .go -4060.446 -4506.618 6.030344

-- Pathing for Sergeant Amelyn Entry: 23835
SET @NPC := 18589;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3839.592,`position_y`=-4562.359,`position_z`=8.639986 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,4097,2402, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3839.592,-4562.359,8.639986,0,0,0,0,100,0),
(@PATH,2,-3834.418,-4560.115,8.764986,0,0,0,0,100,0),
(@PATH,3,-3831.503,-4554.752,9.017159,0,0,0,0,100,0),
(@PATH,4,-3832.31,-4547.42,9.267159,0,0,0,0,100,0),
(@PATH,5,-3837.411,-4543.646,9.264986,0,0,0,0,100,0),
(@PATH,6,-3843.691,-4542.708,9.139986,0,0,0,0,100,0),
(@PATH,7,-3848.835,-4545.314,8.889986,0,0,0,0,100,0),
(@PATH,8,-3852.152,-4551.402,8.514986,0,0,0,0,100,0),
(@PATH,9,-3849.583,-4557.867,8.514986,0,0,0,0,100,0),
(@PATH,10,-3846.69,-4558.219,8.514986,0,0,0,0,100,0),
(@PATH,11,-3846.69,-4558.219,8.514986,3.892084,50000,0,0,100,0),
(@PATH,12,-3844.929,-4561.821,8.514986,0,0,0,0,100,0);
-- .go -3839.592 -4562.359 8.639986

-- Pathing for Zanzil Zombie Entry: 1488
SET @NPC := 2244;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-13646.8,`position_y`=-274.549,`position_z`=8.300073 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-13646.8,-274.549,8.300073,0,0,0,0,100,0),
(@PATH,2,-13634.3,-280.575,8.300073,0,0,0,0,100,0),
(@PATH,3,-13624.5,-285.943,8.300567,0,0,0,0,100,0),
(@PATH,4,-13622.9,-293.137,8.425567,0,0,0,0,100,0),
(@PATH,5,-13635.7,-313.58,8.309404,0,0,0,0,100,0),
(@PATH,6,-13641.1,-314.866,8.184404,0,0,0,0,100,0),
(@PATH,7,-13649.3,-309.953,8.184404,0,0,0,0,100,0),
(@PATH,8,-13655,-302.635,8.184404,0,0,0,0,100,0),
(@PATH,9,-13656,-290.47,8.300073,0,0,0,0,100,0);
-- 0xF53005D300674CA0 .go -13646.8 -274.549 8.300073
