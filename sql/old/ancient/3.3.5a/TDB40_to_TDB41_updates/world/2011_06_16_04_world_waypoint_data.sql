-- Pathing for Anub'ar Underlord Entry: 26605
SET @NPC := 118237;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3704.838,`position_y`=2095.148,`position_z`=29.32822 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3704.878,2078.017,22.76327,0,0,0,100,0),
(@PATH,2,3704.838,2095.148,29.32822,0,0,0,100,0),
(@PATH,3,3716.224,2107.784,34.74489,0,0,0,100,0),
(@PATH,4,3704.838,2095.148,29.32822,0,0,0,100,0);
-- Pathing for Anub'ar Underlord Entry: 26605
SET @NPC := 118244;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3720.111,`position_y`=2070.069,`position_z`=20.87124 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3719.379,2060.642,18.13046,0,0,0,100,0),
(@PATH,2,3717.377,2046.599,19.50792,0,0,0,100,0),
(@PATH,3,3712.452,2034.414,20.03152,0,0,0,100,0),
(@PATH,4,3717.377,2046.599,19.50792,0,0,0,100,0),
(@PATH,5,3719.186,2059.884,18.13046,0,0,0,100,0),
(@PATH,6,3720.111,2070.069,20.87124,0,0,0,100,0);
-- Pathing for Anub'ar Underlord Entry: 26605
SET @NPC := 118288;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3697.697,`position_y`=2009.523,`position_z`=26.85555 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3694.476,2020.034,23.35549,0,0,0,100,0),
(@PATH,2,3696.517,2032.483,19.2324,0,0,0,100,0),
(@PATH,3,3694.476,2020.034,23.35549,0,0,0,100,0),
(@PATH,4,3697.697,2009.523,26.85555,0,0,0,100,0);
-- Pathing for Anub'ar Underlord Entry: 26605
SET @NPC := 118245;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3732.257,`position_y`=2176.174,`position_z`=37.1051 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3718.512,2172.458,37.42885,0,0,0,100,0),
(@PATH,2,3732.257,2176.174,37.1051,0,0,0,100,0),
(@PATH,3,3743.498,2155.942,37.23704,0,0,0,100,0),
(@PATH,4,3732.257,2176.174,37.1051,0,0,0,100,0);
-- Pathing for Anub'ar Underlord Entry: 26605
SET @NPC := 118238;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3743.132,`position_y`=2124.906,`position_z`=44.5452 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3736.5,2122.697,41.26656,0,0,0,100,0),
(@PATH,2,3728.368,2133.333,39.51953,0,0,0,100,0),
(@PATH,3,3736.5,2122.697,41.26656,0,0,0,100,0),
(@PATH,4,3742.983,2124.628,44.42427,0,0,0,100,0),
(@PATH,5,3748.981,2135.839,47.54227,0,0,0,100,0),
(@PATH,6,3746.108,2146.75,50.10811,0,0,0,100,0),
(@PATH,7,3748.981,2135.839,47.54227,0,0,0,100,0),
(@PATH,8,3743.132,2124.906,44.5452,0,0,0,100,0);
-- Pathing for Anub'ar Cultist Entry: 26319
SET @NPC := 115443;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4022.739,`position_y`=2258.957,`position_z`=152.3082 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4032.673,2267.958,152.1369,0,0,0,100,0),
(@PATH,2,4023.99,2280.177,153.2619,0,0,0,100,0),
(@PATH,3,4012.677,2274.532,153.6369,0,0,0,100,0),
(@PATH,4,3999.963,2258.323,154.234,0,0,0,100,0),
(@PATH,5,4000.036,2251.767,154.5582,0,0,0,100,0),
(@PATH,6,3995.088,2248.992,154.234,0,0,0,100,0),
(@PATH,7,3993.707,2243.226,154.109,0,0,0,100,0),
(@PATH,8,3998.962,2241.267,154.734,0,0,0,100,0),
(@PATH,9,4006.684,2243.027,154.1832,0,0,0,100,0),
(@PATH,10,4022.739,2258.957,152.3082,0,0,0,100,0);
