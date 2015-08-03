-- Fix InhabitType for Unending Voidwraith Entry: 19568
UPDATE creature_template SET `InhabitType`=4 WHERE entry=19568;

-- Remove overspawns
DELETE FROM `creature` WHERE `guid` IN (70004,69971,69972,69974,69975,69979,69983,69983,69984,69985);

-- Pathing for Unending Voidwraith Entry: 19568
SET @NPC := 69987;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3915.081,`position_y`=2111.545,`position_z`=274.4216 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3910.933,2130.042,268.1047,0,0,0,0,100,0),
(@PATH,2,3906.025,2154.37,268.1672,0,0,0,0,100,0),
(@PATH,3,3902.745,2174.67,268.7223,0,0,0,0,100,0),
(@PATH,4,3897.602,2202.157,270.2776,0,1000,0,80,100,0);

-- Pathing for Unending Voidwraith Entry: 19568
SET @NPC := 69988;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3887.315,`position_y`=2258.425,`position_z`=214.2984 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3886.422,2258.591,207.7289,0,0,1,0,100,0),
(@PATH,2,3880.079,2289.422,171.0624,0,1000,0,81,100,0);

-- Pathing for Unending Voidwraith Entry: 19568
SET @NPC := 69989;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3726.479,`position_y`=1961.26,`position_z`=249.9123 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3726.549,1962.258,241.1067,0,0,1,0,100,0),
(@PATH,2,3726.522,1962.159,210.7784,0,0,0,0,100,0),
(@PATH,3,3726.594,1962.199,171.9171,0,1000,0,82,100,0);

-- Pathing for Unending Voidwraith Entry: 19568
SET @NPC := 69991;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4044.87,`position_y`=2025.382,`position_z`=267.5442 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4065.068,2028.757,270.5326,0,0,0,0,100,0),
(@PATH,2,4080.474,2031.845,270.3937,0,0,0,0,100,0),
(@PATH,3,4114.268,2037.787,271.1436,0,1000,0,83,100,0);

-- Pathing for Unending Voidwraith Entry: 19568
SET @NPC := 69993;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4148.985,`position_y`=2042.905,`position_z`=164.7122 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4148.518,2041.715,179.4717,0,0,0,0,100,0),
(@PATH,2,4148.935,2042.122,214.9162,0,0,0,0,100,0),
(@PATH,3,4149.163,2042.004,249.0274,0,1000,0,84,100,0);

-- Pathing for Unending Voidwraith Entry: 19568
SET @NPC := 69994;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3827.957,`position_y`=1979.826,`position_z`=275.0208 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3827.956,1980.894,268.086,0,0,0,0,100,0),
(@PATH,2,3808.116,1977.663,268.8724,0,0,0,0,100,0),
(@PATH,3,3781.85,1972.763,269.8727,0,0,0,0,100,0),
(@PATH,4,3759.935,1969.464,271.9074,0,1000,0,85,100,0);

-- Pathing for Unending Voidwraith Entry: 19568
SET @NPC := 69998;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4151.247,`position_y`=2042.391,`position_z`=245.5923 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4150.083,2041.977,243.7888,0,0,0,0,100,0),
(@PATH,2,4150.307,2041.957,214.594,0,0,0,0,100,0),
(@PATH,3,4150.337,2041.994,173.4543,0,1000,0,86,100,0);

-- Pathing for Unending Voidwraith Entry: 19568
SET @NPC := 69999;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3957.735,`position_y`=1894.359,`position_z`=269.9256 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3959.09,1891.894,271.8099,0,0,0,0,100,0),
(@PATH,2,3963.445,1862.928,271.171,0,0,0,0,100,0),
(@PATH,3,3969.4,1841.54,271.3934,0,0,0,0,100,0),
(@PATH,4,3976.177,1801.907,271.8932,0,0,0,0,100,0),
(@PATH,5,3978.509,1789.356,271.8932,0,0,0,0,100,0),
(@PATH,6,3985.332,1757.852,271.9979,0,0,0,0,100,0),
(@PATH,7,3988.208,1743.379,272.2765,0,1000,0,87,100,0);

-- Pathing for Unending Voidwraith Entry: 19568
SET @NPC := 69978;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3990.148,`position_y`=1735.373,`position_z`=270.1769 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3990.676,1736.489,274.6074,0,0,0,0,100,0),
(@PATH,2,3984.71,1764.321,270.99,0,0,0,0,100,0),
(@PATH,3,3978.079,1796.415,270.7212,0,0,0,0,100,0),
(@PATH,4,3976.071,1818.841,270.7491,0,0,0,0,100,0),
(@PATH,5,3967.914,1856.6,273.707,0,0,0,0,100,0),
(@PATH,6,3965.208,1873.519,274.3181,0,1000,0,88,100,0);

-- Pathing for Unending Voidwraith Entry: 19568
SET @NPC := 69980;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4001.008,`position_y`=1683.551,`position_z`=137.2256 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4000.599,1682.332,144.5384,0,0,0,0,100,0),
(@PATH,2,4001.468,1682.875,184.6771,0,0,0,0,100,0),
(@PATH,3,4000.325,1683.686,228.1769,0,1000,0,89,100,0);

-- Pathing for Unending Voidwraith Entry: 19568
SET @NPC := 69982;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3696.551,`position_y`=1954.486,`position_z`=134.3766 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3660.113,1949.127,128.0894,0,0,0,0,100,0),
(@PATH,2,3632.976,1946.206,126.9835,0,0,0,0,100,0),
(@PATH,3,3591.018,1935.34,128.265,0,0,0,0,100,0),
(@PATH,4,3570.341,1931.432,128.7372,0,0,0,0,100,0),
(@PATH,5,3552.659,1931.052,126.8722,0,1000,0,90,100,0);

DELETE FROM `waypoint_scripts` WHERE `id` IN (80,81,82,83,84,85,86,87,88,89,90);
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`,`guid`) VALUES 
(80,0,6,530,1,0,3915.081,2111.545,274.4216,0,880),
(81,0,6,530,1,0,3887.315,2258.425,214.2984,0,881),
(82,0,6,530,1,0,3726.479,1961.26,249.9123,0,882),
(83,0,6,530,1,0,4044.87,2025.382,267.5442,0,883),
(84,0,6,530,1,0,4148.985,2042.905,164.7122,0,884),
(85,0,6,530,1,0,3827.957,1979.826,275.0208,0,885),
(86,0,6,530,1,0,4151.247,2042.391,245.5923,0,886),
(87,0,6,530,1,0,3957.735,1894.359,269.9256,0,887),
(88,0,6,530,1,0,3990.148,1735.373,270.1769,0,888),
(89,0,6,530,1,0,4001.008,1683.551,137.2256,0,889),
(90,0,6,530,1,0,3696.551,1954.486,134.3766,0,890);
