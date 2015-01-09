-- Pathing for Beryl Treasure Hunter Entry: 25353
SET @NPC := 97322;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3561.386,`position_y`=5473.793,`position_z`=30.31353 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3557.931,5461.132,32.72385,0,0,0,100,0),
(@PATH,2,3561.386,5473.793,30.31353,0,0,0,100,0),
(@PATH,3,3564.122,5486.128,28.18853,0,0,0,100,0),
(@PATH,4,3570.361,5499.623,27.06404,0,0,0,100,0),
(@PATH,5,3575.282,5511.941,27.06258,0,0,0,100,0),
(@PATH,6,3582.943,5519.652,27.06258,0,0,0,100,0),
(@PATH,7,3597.379,5520.971,27.06258,0,0,0,100,0),
(@PATH,8,3582.943,5519.652,27.06258,0,0,0,100,0),
(@PATH,9,3575.282,5511.941,27.06258,0,0,0,100,0),
(@PATH,10,3570.361,5499.623,27.06404,0,0,0,100,0),
(@PATH,11,3564.122,5486.128,28.18853,0,0,0,100,0),
(@PATH,12,3561.386,5473.793,30.31353,0,0,0,100,0);

-- Pathing for Beryl Treasure Hunter Entry: 25353
SET @NPC := 97331;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3664.771,`position_y`=5602.22,`position_z`=32.81259 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3652.738,5615.229,33.31259,0,0,0,100,0),
(@PATH,2,3664.771,5602.22,32.81259,0,0,0,100,0),
(@PATH,3,3674.368,5584.944,32.89562,0,0,0,100,0),
(@PATH,4,3674.716,5568.044,34.64562,0,0,0,100,0),
(@PATH,5,3678.86,5555.542,36.44348,0,0,0,100,0),
(@PATH,6,3685.907,5546.087,38.06848,0,0,0,100,0),
(@PATH,7,3690.099,5526.772,39.84897,0,0,0,100,0),
(@PATH,8,3685.907,5546.087,38.06848,0,0,0,100,0),
(@PATH,9,3678.86,5555.542,36.44348,0,0,0,100,0),
(@PATH,10,3674.716,5568.044,34.64562,0,0,0,100,0),
(@PATH,11,3674.368,5584.944,32.89562,0,0,0,100,0),
(@PATH,12,3664.771,5602.22,32.81259,0,0,0,100,0);

-- Pathing for Beryl Treasure Hunter Entry: 25353
SET @NPC := 97301;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3585.395,`position_y`=5444.673,`position_z`=39.95293 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3585.856,5453.249,37.95293,0,0,0,100,0),
(@PATH,2,3586.374,5461.863,35.32793,0,0,0,100,0),
(@PATH,3,3585.856,5453.249,37.95293,0,0,0,100,0),
(@PATH,4,3585.395,5444.673,39.95293,0,0,0,100,0),
(@PATH,5,3585.615,5433.987,40.45293,0,0,0,100,0),
(@PATH,6,3585.395,5444.673,39.95293,0,0,0,100,0);

-- Pathing for Beryl Treasure Hunter Entry: 25353
SET @NPC := 97276;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3697.089,`position_y`=5631.371,`position_z`=32.76652 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3698.534,5644.674,32.66938,0,0,0,100,0),
(@PATH,2,3706.474,5658.97,32.38537,0,0,0,100,0),
(@PATH,3,3698.534,5644.674,32.66938,0,0,0,100,0),
(@PATH,4,3697.089,5631.371,32.76652,0,0,0,100,0),
(@PATH,5,3702.564,5621.85,32.72995,0,0,0,100,0),
(@PATH,6,3708.017,5615.569,32.85495,0,0,0,100,0),
(@PATH,7,3716.102,5613.98,33.35495,0,0,0,100,0),
(@PATH,8,3727.071,5621.008,35.35495,0,0,0,100,0),
(@PATH,9,3716.102,5613.98,33.35495,0,0,0,100,0),
(@PATH,10,3708.017,5615.569,32.85495,0,0,0,100,0),
(@PATH,11,3702.564,5621.85,32.72995,0,0,0,100,0),
(@PATH,12,3697.089,5631.371,32.76652,0,0,0,100,0);

-- Pathing for Beryl Treasure Hunter Entry: 25353
SET @NPC := 97318;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3548.629,`position_y`=5599.825,`position_z`=50.65398 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3555.003,5601.37,46.20094,0,0,0,100,0),
(@PATH,2,3564.607,5602.538,37.57594,0,0,0,100,0),
(@PATH,3,3578.939,5601.566,31.57699,0,0,0,100,0),
(@PATH,4,3586.806,5593.127,31.12983,0,0,0,100,0),
(@PATH,5,3592.613,5587.148,30.37983,0,0,0,100,0),
(@PATH,6,3586.806,5593.127,31.12983,0,0,0,100,0),
(@PATH,7,3578.939,5601.566,31.57699,0,0,0,100,0),
(@PATH,8,3564.607,5602.538,37.57594,0,0,0,100,0),
(@PATH,9,3555.003,5601.37,46.20094,0,0,0,100,0),
(@PATH,10,3548.629,5599.825,50.65398,0,0,0,100,0),
(@PATH,11,3543.457,5613.289,52.70094,0,0,0,100,0),
(@PATH,12,3535.345,5628.1,53.57594,0,0,0,100,0),
(@PATH,13,3526.802,5644.103,55.89756,0,0,0,100,0),
(@PATH,14,3535.345,5628.1,53.57594,0,0,0,100,0),
(@PATH,15,3543.457,5613.289,52.70094,0,0,0,100,0),
(@PATH,16,3548.629,5599.825,50.65398,0,0,0,100,0);

-- Pathing for Beryl Treasure Hunter Entry: 25353
SET @NPC := 97307;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3534.608,`position_y`=5627.963,`position_z`=53.57594 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3539.981,5619.029,53.45094,0,0,0,100,0),
(@PATH,2,3546.2,5609.595,51.45094,0,0,0,100,0),
(@PATH,3,3550.636,5602.65,49.20094,0,0,0,100,0),
(@PATH,4,3560.588,5603.686,41.20094,0,0,0,100,0),
(@PATH,5,3567.586,5605.285,35.95199,0,0,0,100,0),
(@PATH,6,3573.637,5605.286,32.70199,0,0,0,100,0),
(@PATH,7,3581.634,5597.975,31.25483,0,0,0,100,0),
(@PATH,8,3587.999,5591.561,31.12983,0,0,0,100,0),
(@PATH,9,3596.174,5584.191,29.25483,0,0,0,100,0),
(@PATH,10,3587.999,5591.561,31.12983,0,0,0,100,0),
(@PATH,11,3581.634,5597.975,31.25483,0,0,0,100,0),
(@PATH,12,3573.637,5605.286,32.70199,0,0,0,100,0),
(@PATH,13,3567.637,5605.286,35.95199,0,0,0,100,0),
(@PATH,14,3560.814,5603.728,41.20094,0,0,0,100,0),
(@PATH,15,3550.873,5602.673,49.20094,0,0,0,100,0),
(@PATH,16,3546.2,5609.595,51.45094,0,0,0,100,0),
(@PATH,17,3539.981,5619.029,53.45094,0,0,0,100,0),
(@PATH,18,3534.608,5627.963,53.57594,0,0,0,100,0),
(@PATH,19,3530.087,5637.976,54.52256,0,0,0,100,0),
(@PATH,20,3527.31,5655.765,58.77256,0,0,0,100,0),
(@PATH,21,3530.087,5637.976,54.52256,0,0,0,100,0),
(@PATH,22,3534.608,5627.963,53.57594,0,0,0,100,0);

-- Pathing for Beryl Treasure Hunter Entry: 25353
SET @NPC := 97326;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3513.876,`position_y`=5606.854,`position_z`=63.13185 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3520.958,5599.072,62.37835,0,0,0,100,0),
(@PATH,2,3526.856,5589.065,62.00335,0,0,0,100,0),
(@PATH,3,3526.894,5567.229,62.87835,0,0,0,100,0),
(@PATH,4,3528.539,5553.205,63.56588,0,0,0,100,0),
(@PATH,5,3530.672,5540.383,65.44087,0,0,0,100,0),
(@PATH,6,3527.634,5519.506,64.80357,0,0,0,100,0),
(@PATH,7,3530.648,5540.28,65.44087,0,0,0,100,0),
(@PATH,8,3528.539,5553.205,63.56588,0,0,0,100,0),
(@PATH,9,3526.894,5567.229,62.87835,0,0,0,100,0),
(@PATH,10,3526.856,5589.065,62.00335,0,0,0,100,0),
(@PATH,11,3520.958,5599.072,62.37835,0,0,0,100,0),
(@PATH,12,3513.876,5606.854,63.13185,0,0,0,100,0),
(@PATH,13,3505.681,5611.771,63.63185,0,0,0,100,0),
(@PATH,14,3502.509,5621.209,64.63185,0,0,0,100,0),
(@PATH,15,3503.642,5628.48,64.50685,0,0,0,100,0),
(@PATH,16,3505.995,5635.619,63.89756,0,0,0,100,0),
(@PATH,17,3505.937,5645.619,62.52256,0,0,0,100,0),
(@PATH,18,3505.995,5635.619,63.89756,0,0,0,100,0),
(@PATH,19,3503.642,5628.48,64.50685,0,0,0,100,0),
(@PATH,20,3502.509,5621.209,64.63185,0,0,0,100,0),
(@PATH,21,3505.681,5611.771,63.63185,0,0,0,100,0),
(@PATH,22,3513.876,5606.854,63.13185,0,0,0,100,0);

-- Pathing for Beryl Treasure Hunter Entry: 25353
SET @NPC := 97319;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3517.062,`position_y`=5501.915,`position_z`=63.42858 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3518.122,5485.379,58.96079,0,0,0,100,0),
(@PATH,2,3522.787,5476,55.96079,0,0,0,100,0),
(@PATH,3,3518.122,5485.379,58.96079,0,0,0,100,0),
(@PATH,4,3517.062,5501.915,63.42858,0,0,0,100,0),
(@PATH,5,3517.615,5510.972,65.17857,0,0,0,100,0),
(@PATH,6,3521.31,5518.627,65.42857,0,0,0,100,0),
(@PATH,7,3517.615,5510.972,65.17857,0,0,0,100,0),
(@PATH,8,3517.062,5501.915,63.42858,0,0,0,100,0);
