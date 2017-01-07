-- Fleshfiend
SET @CGUID := 77792; -- 12 FREE GUIDS NEEDED SET BY TC TEAM
DELETE FROM `creature` WHERE `guid` NOT IN (72253, 72254, 72255) AND `id`=20340;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+11;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `curhealth`, `curmana`, `MovementType`) VALUES 
(@CGUID+0, 20340, 530, 1, 1, 0, 3700.07, 2104.38, 154.187, 1.05376, 300, 0, 6761, 0, 2),
(@CGUID+1, 20340, 530, 1, 1, 0, 3802, 2077.1, 149.618, 2.7682, 300, 5, 6986, 0, 1),
(@CGUID+2, 20340, 530, 1, 1, 0, 3757.67, 2080.25, 151.914, 3.0616, 300, 2, 6986, 0, 1),
(@CGUID+3, 20340, 530, 1, 1, 0, 3830.72, 2152.55, 145.842, 4.57919, 300, 5, 6986, 0, 1),
(@CGUID+4, 20340, 530, 1, 1, 0, 3845.32, 2111.13, 148.712, 3.38892, 300, 0, 6761, 0, 2),
(@CGUID+5, 20340, 530, 1, 1, 0, 3864.73, 2158.55, 139.53, 5.98851, 300, 5, 6761, 0, 1),
(@CGUID+6, 20340, 530, 1, 1, 0, 3883.87, 2131.02, 133.884, 5.14029, 300, 5, 6761, 0, 1),
(@CGUID+7, 20340, 530, 1, 1, 0, 3873.85, 2104.63, 133.388, 4.74834, 300, 0, 6986, 0, 2),
(@CGUID+8, 20340, 530, 1, 1, 0, 3919.83, 2087.85, 133.488, 2.46537, 300, 5, 6761, 0, 1),
(@CGUID+9, 20340, 530, 1, 1, 0, 3895.68, 2034.48, 148.256, 3.45105, 300, 5, 6761, 0, 1),
(@CGUID+10, 20340, 530, 1, 1, 0, 3909.46, 2090.17, 155.839, 2.58317, 300, 5, 6986, 0, 1),
(@CGUID+11, 20340, 530, 1, 1, 0, 3927.87, 2118.67, 159.924, 4.58354, 300, 0, 6761, 0, 2);

-- Updates
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE guid = 72253;
UPDATE `creature` SET `position_x` = 3845.784424, `position_y` = 2111.566895, `position_z` = 148.651016, `spawndist` = 5, `MovementType` = 1 WHERE `guid` = 72254;

SET @NPC := 72253;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES
(@PATH, 1, 3828.6, 2052.43, 146.299),
(@PATH, 2, 3814.57, 2068.55, 148.037),
(@PATH, 3, 3803.64, 2075.73, 148.999),
(@PATH, 4, 3793.57, 2076.63, 152.807),
(@PATH, 5, 3772.9, 2078.11, 154.741),
(@PATH, 6, 3793.79, 2077.36, 152.872),
(@PATH, 7, 3806.68, 2075.38, 148.988),
(@PATH, 8, 3817.08, 2066.81, 147.837),
(@PATH, 9, 3829.58, 2051.22, 145.945),
(@PATH, 10, 3837.99, 2045.38, 144.981),
(@PATH, 11, 3844.06, 2036.32, 143.92),
(@PATH, 12, 3853.07, 2030.52, 142.777),
(@PATH, 13, 3865.79, 2024.48, 144.208),
(@PATH, 14, 3851.93, 2030.9, 142.805),
(@PATH, 15, 3844.37, 2036.31, 143.849),
(@PATH, 16, 3838.85, 2044.04, 144.628);

SET @NPC := @CGUID+0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES
(@PATH, 1, 3708.42, 2110.91, 152.714),
(@PATH, 2, 3718.47, 2112.17, 150.762),
(@PATH, 3, 3738.52, 2109.59, 148.183),
(@PATH, 4, 3711.96, 2112.24, 152.367),
(@PATH, 5, 3702.12, 2107.95, 153.659),
(@PATH, 6, 3692.42, 2098.89, 155.214),
(@PATH, 7, 3686.26, 2093.03, 149.364),
(@PATH, 8, 3683.91, 2089.67, 152.259),
(@PATH, 9, 3688.53, 2083.23, 152.775),
(@PATH, 10, 3698.57, 2069.71, 150.483),
(@PATH, 11, 3715.1, 2062.27, 147.368),
(@PATH, 12, 3728.18, 2056.63, 144.842),
(@PATH, 13, 3740.76, 2052.12, 146.617),
(@PATH, 14, 3756.8, 2056.43, 150.487),
(@PATH, 15, 3741.21, 2052.22, 146.648),
(@PATH, 16, 3727.44, 2056.94, 144.813),
(@PATH, 17, 3698.21, 2070.22, 150.638),
(@PATH, 18, 3689.34, 2085.61, 152.047),
(@PATH, 19, 3687.46, 2092.86, 149.402),
(@PATH, 20, 3690.78, 2097.36, 154.156),
(@PATH, 21, 3700.04, 2104.35, 154.194);

SET @NPC := @CGUID+4;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES
(@PATH, 1, 3832.22, 2107.48, 149.717),
(@PATH, 2, 3825.75, 2105.58, 151.003),
(@PATH, 3, 3820.36, 2104.75, 148.444),
(@PATH, 4, 3811.88, 2098.79, 147.848),
(@PATH, 5, 3804.56, 2091.55, 149.842),
(@PATH, 6, 3813.68, 2099.89, 147.724),
(@PATH, 7, 3820.93, 2105.03, 148.563),
(@PATH, 8, 3825.93, 2106.17, 151.103),
(@PATH, 9, 3832.41, 2107.12, 149.743),
(@PATH, 10, 3843.08, 2112.63, 148.908),
(@PATH, 11, 3843.73, 2122.31, 147.232),
(@PATH, 12, 3839.65, 2131.35, 146.628),
(@PATH, 13, 3837.69, 2138.62, 145.446),
(@PATH, 14, 3832.25, 2154.89, 145.916),
(@PATH, 15, 3838.13, 2137.13, 145.727),
(@PATH, 16, 3842.26, 2122.59, 147.082),
(@PATH, 17, 3846.68, 2115.09, 148.459),
(@PATH, 18, 3855.48, 2114.4, 147.42),
(@PATH, 19, 3870.42, 2114.12, 147.612),
(@PATH, 20, 3885.1, 2109.86, 149.593),
(@PATH, 21, 3893.09, 2104.7, 152.478),
(@PATH, 22, 3903.74, 2097.1, 154.744),
(@PATH, 23, 3895.22, 2104.42, 153.216),
(@PATH, 24, 3883.14, 2110.8, 149.206),
(@PATH, 25, 3867.52, 2114.77, 147.194),
(@PATH, 26, 3852.24, 2113.81, 147.649),
(@PATH, 27, 3846.62, 2115.55, 148.453),
(@PATH, 28, 3840.54, 2128.64, 146.783),
(@PATH, 29, 3837.58, 2140.16, 145.256),
(@PATH, 30, 3832.01, 2155.39, 145.949),
(@PATH, 31, 3837.48, 2140.4, 145.27);

SET @NPC := @CGUID+7;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES
(@PATH, 1, 3874.85, 2092.38, 131.986),
(@PATH, 2, 3881.79, 2076.72, 132.069),
(@PATH, 3, 3876.13, 2088.46, 131.757),
(@PATH, 4, 3873.89, 2102.41, 132.905),
(@PATH, 5, 3875.56, 2109.94, 135.03),
(@PATH, 6, 3879.99, 2120.42, 133.436),
(@PATH, 7, 3882.52, 2130.11, 133.948),
(@PATH, 8, 3877.94, 2139.1, 135.257),
(@PATH, 9, 3876.27, 2145.36, 139.053),
(@PATH, 10, 3874.56, 2152.62, 138.963),
(@PATH, 11, 3867.19, 2159.01, 139.152),
(@PATH, 12, 3857.43, 2157.18, 140.557),
(@PATH, 13, 3846.26, 2156.16, 141.191),
(@PATH, 14, 3842.13, 2158.58, 141.856),
(@PATH, 15, 3848.25, 2155.62, 140.979),
(@PATH, 16, 3858.78, 2157.24, 140.533),
(@PATH, 17, 3872.4, 2155.03, 138.92),
(@PATH, 18, 3875.87, 2150.28, 139.98),
(@PATH, 19, 3876.41, 2145.97, 139.209),
(@PATH, 20, 3878.13, 2140.38, 135.46),
(@PATH, 21, 3882.97, 2129.62, 133.867),
(@PATH, 22, 3880.17, 2118.79, 133.545),
(@PATH, 23, 3875.72, 2110.03, 134.98),
(@PATH, 24, 3874.23, 2103.02, 132.96);

SET @NPC := @CGUID+11;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES
(@PATH, 1, 3923.03, 2102, 158.719),
(@PATH, 2, 3918.22, 2094.92, 157.148),
(@PATH, 3, 3909.27, 2086.84, 156.194),
(@PATH, 4, 3908.21, 2079.6, 153.654),
(@PATH, 5, 3907.09, 2069.95, 152.617),
(@PATH, 6, 3906.22, 2058.27, 150.862),
(@PATH, 7, 3901.95, 2047.35, 149.152),
(@PATH, 8, 3907.01, 2060.82, 151.077),
(@PATH, 9, 3907.93, 2080.42, 153.756),
(@PATH, 10, 3909.4, 2086.92, 156.191),
(@PATH, 11, 3913.55, 2091.18, 155.927),
(@PATH, 12, 3920.32, 2096.83, 157.939),
(@PATH, 13, 3926.47, 2109.47, 159.1),
(@PATH, 14, 3927.97, 2121.86, 160.375),
(@PATH, 15, 3930.43, 2129, 160.119),
(@PATH, 16, 3940.05, 2136.96, 160.067),
(@PATH, 17, 3952.66, 2135.78, 161.632),
(@PATH, 18, 3957.72, 2133.09, 162.299),
(@PATH, 19, 3946.18, 2137.7, 160.791),
(@PATH, 20, 3936.69, 2136.25, 160.133),
(@PATH, 21, 3928.27, 2125.16, 160.584),
(@PATH, 22, 3927.47, 2118.3, 159.805);
