-- Pathing for Hath'ar Necromagus Entry: 28257
SET @NPC := 104622;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5019.215,`position_y`=-3688.894,`position_z`=320.5594 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5019.215,-3688.894,320.5594,0,0,0,100,0),
(@PATH,2,5002.956,-3658.76,323.2104,0,0,0,100,0),
(@PATH,3,4992.721,-3643.726,324.9065,0,0,0,100,0),
(@PATH,4,5002.956,-3658.76,323.2104,0,0,0,100,0),
(@PATH,5,5019.215,-3688.894,320.5594,0,0,0,100,0),
(@PATH,6,5019.668,-3703.462,320.5379,0,0,0,100,0);

-- Pathing for Hath'ar Necromagus Entry: 28257
SET @NPC := 104614;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5025.362,`position_y`=-3604.257,`position_z`=349.464 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5025.362,-3604.257,349.464,0,0,0,100,0),
(@PATH,2,5041.33,-3605.005,352.8885,0,0,0,100,0),
(@PATH,3,5052.726,-3607.239,355.7938,0,0,0,100,0),
(@PATH,4,5066.022,-3605.421,360.1152,0,0,0,100,0),
(@PATH,5,5080.014,-3609.861,362.831,0,0,0,100,0),
(@PATH,6,5095.403,-3626.727,359.9017,0,0,0,100,0),
(@PATH,7,5109.978,-3643.893,366.1679,0,0,0,100,0),
(@PATH,8,5115.737,-3659.64,372.9412,0,0,0,100,0),
(@PATH,9,5119.728,-3671.96,375.7362,0,0,0,100,0),
(@PATH,10,5115.737,-3659.64,372.9412,0,0,0,100,0),
(@PATH,11,5110.043,-3644.025,366.2568,0,0,0,100,0),
(@PATH,12,5095.57,-3627.037,360.0706,0,0,0,100,0),
(@PATH,13,5080.014,-3609.861,362.831,0,0,0,100,0),
(@PATH,14,5066.022,-3605.421,360.1152,0,0,0,100,0),
(@PATH,15,5052.726,-3607.239,355.7938,0,0,0,100,0),
(@PATH,16,5041.33,-3605.005,352.8885,0,0,0,100,0);

-- Pathing for Hath'ar Necromagus Entry: 28257
SET @NPC := 104619;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5071.903,`position_y`=-3665.457,`position_z`=295.4549 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5071.903,-3665.457,295.4549,0,0,0,100,0),
(@PATH,2,5059.392,-3682.827,295.5384,0,0,0,100,0),
(@PATH,3,5037.78,-3681.667,299.7601,0,0,0,100,0),
(@PATH,4,5028.569,-3670.129,300.9308,0,0,0,100,0),
(@PATH,5,5026.874,-3657.909,301.366,0,0,0,100,0),
(@PATH,6,5035.031,-3642.29,299.8145,0,0,0,100,0),
(@PATH,7,5053.08,-3636.957,297.5071,0,0,0,100,0),
(@PATH,8,5067.131,-3644.62,295.7921,0,0,0,100,0);

-- Pathing for Drakuru's Guard Entry: 28803
SET @NPC := 107821;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6114.339,`position_y`=-2034.41,`position_z`=417.6801 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6114.339,-2034.41,417.6801,0,0,0,100,0),
(@PATH,2,6129.907,-2060.738,417.5455,0,0,0,100,0),
(@PATH,3,6144.443,-2073.784,417.6692,0,0,0,100,0),
(@PATH,4,6171.715,-2080.903,417.5605,0,0,0,100,0),
(@PATH,5,6185.524,-2080.392,417.5476,0,0,0,100,0),
(@PATH,6,6171.715,-2080.903,417.5605,0,0,0,100,0),
(@PATH,7,6144.443,-2073.784,417.6692,0,0,0,100,0),
(@PATH,8,6129.907,-2060.738,417.5455,0,0,0,100,0);

-- Pathing for Drakuru's Guard Entry: 28803
SET @NPC := 107817;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6194.729,`position_y`=-2078.011,`position_z`=417.6379 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6194.729,-2078.011,417.6379,0,0,0,100,0),
(@PATH,2,6217.196,-2064.708,417.5335,0,0,0,100,0),
(@PATH,3,6232.834,-2048.468,417.6579,0,0,0,100,0),
(@PATH,4,6240.251,-2020.826,417.5575,0,0,0,100,0),
(@PATH,5,6238.296,-2002.501,417.7368,0,0,0,100,0),
(@PATH,6,6240.251,-2020.826,417.5575,0,0,0,100,0),
(@PATH,7,6232.834,-2048.468,417.6579,0,0,0,100,0),
(@PATH,8,6217.196,-2064.708,417.5335,0,0,0,100,0);

-- Pathing for Drakuru's Guard Entry: 28803
SET @NPC := 107836;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6236.967,`position_y`=-1995.491,`position_z`=417.6333 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6236.967,-1995.491,417.6333,0,0,0,100,0),
(@PATH,2,6228.093,-1980.412,417.5516,0,0,0,100,0),
(@PATH,3,6215.869,-1967.486,417.5413,0,0,0,100,0),
(@PATH,4,6196.992,-1955.543,417.5889,0,0,0,100,0),
(@PATH,5,6174.948,-1953.596,417.5572,0,0,0,100,0),
(@PATH,6,6164.511,-1955.177,417.5472,0,0,0,100,0),
(@PATH,7,6174.948,-1953.596,417.5572,0,0,0,100,0),
(@PATH,8,6196.992,-1955.543,417.5889,0,0,0,100,0),
(@PATH,9,6215.869,-1967.486,417.5413,0,0,0,100,0),
(@PATH,10,6228.093,-1980.412,417.5516,0,0,0,100,0);

-- Pathing for Drakuru's Guard Entry: 28803
SET @NPC := 107821;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6119.209,`position_y`=-1985.834,`position_z`=417.6736 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6119.209,-1985.834,417.6736,0,0,0,100,0),
(@PATH,2,6109.752,-2008.77,417.5636,0,0,0,100,0),
(@PATH,3,6113.512,-2033.001,417.7308,0,0,0,100,0),
(@PATH,4,6109.752,-2008.77,417.5636,0,0,0,100,0);

-- Pathing for Drakuru's Guard Entry: 28803
SET @NPC := 107837;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6194.729,`position_y`=-2078.011,`position_z`=417.6379 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6194.729,-2078.011,417.6379,0,0,0,100,0),
(@PATH,2,6217.196,-2064.708,417.5335,0,0,0,100,0),
(@PATH,3,6232.834,-2048.468,417.6579,0,0,0,100,0),
(@PATH,4,6240.251,-2020.826,417.5575,0,0,0,100,0),
(@PATH,5,6238.296,-2002.501,417.7368,0,0,0,100,0),
(@PATH,6,6240.251,-2020.826,417.5575,0,0,0,100,0),
(@PATH,7,6232.834,-2048.468,417.6579,0,0,0,100,0),
(@PATH,8,6217.196,-2064.708,417.5335,0,0,0,100,0);

-- Pathing for Shalewing Guard Entry: 28879
SET @NPC := 115429;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6184.199,`position_y`=-1985.717,`position_z`=434.6442 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6184.199,-1985.717,434.6442,0,0,0,100,0),
(@PATH,2,6205.602,-1997.712,423.9775,0,0,0,100,0),
(@PATH,3,6209.002,-2021.652,426.0051,0,0,0,100,0),
(@PATH,4,6191.328,-2043.418,431.6164,0,0,0,100,0),
(@PATH,5,6172.321,-2047.748,423.9775,0,0,0,100,0),
(@PATH,6,6159.705,-2039.765,423.9775,0,0,0,100,0),
(@PATH,7,6151.034,-2030.29,423.9775,0,0,0,100,0),
(@PATH,8,6148.249,-2012.318,427.6442,0,0,0,100,0),
(@PATH,9,6160.55,-1991.355,423.9775,0,0,0,100,0);
