-- Pathing for Darkfallen Deathblade Entry: 26103
SET @NPC := 119232;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3657.896,`position_y`=3592.591,`position_z`=371.479 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3665.972,3599.461,371.4846,0,0,0,100,0),
(@PATH,2,3682.637,3610.097,371.4544,0,0,0,100,0),
(@PATH,3,3696.372,3619.76,371.3447,0,0,0,100,0),
(@PATH,4,3682.637,3610.097,371.4544,0,0,0,100,0),
(@PATH,5,3665.972,3599.461,371.4846,0,0,0,100,0),
(@PATH,6,3657.896,3592.591,371.479,0,0,0,100,0),
(@PATH,7,3651.491,3585.525,371.674,0,0,0,100,0),
(@PATH,8,3651.062,3578.088,371.551,0,0,0,100,0),
(@PATH,9,3656.478,3568.307,371.4457,0,0,0,100,0),
(@PATH,10,3665.993,3555.432,371.3665,0,0,0,100,0),
(@PATH,11,3656.478,3568.307,371.4457,0,0,0,100,0),
(@PATH,12,3651.062,3578.088,371.551,0,0,0,100,0),
(@PATH,13,3651.473,3585.204,371.6653,0,0,0,100,0),
(@PATH,14,3657.896,3592.591,371.479,0,0,0,100,0);

-- Pathing for Darkfallen Deathblade Entry: 26103
SET @NPC := 119253;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3742.794,`position_y`=3604.008,`position_z`=346.2505 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3728.665,3600.99,345.8076,0,0,0,100,0),
(@PATH,2,3716.573,3595.571,346.0472,0,0,0,100,0),
(@PATH,3,3709.646,3587.291,345.7931,0,0,0,100,0),
(@PATH,4,3705.439,3578.289,345.9121,0,0,0,100,0),
(@PATH,5,3703.899,3570.889,345.8815,0,0,0,100,0),
(@PATH,6,3704.667,3561.633,345.6407,0,0,0,100,0),
(@PATH,7,3706.808,3553.582,345.8144,0,0,0,100,0),
(@PATH,8,3712.931,3543.78,345.7907,0,0,0,100,0),
(@PATH,9,3718.246,3537.947,345.8893,0,0,0,100,0),
(@PATH,10,3729.692,3532.638,345.8766,0,0,0,100,0),
(@PATH,11,3741.682,3531.879,345.7675,0,0,0,100,0),
(@PATH,12,3752.107,3533.592,345.952,0,0,0,100,0),
(@PATH,13,3762.405,3538.37,346.1658,0,0,0,100,0),
(@PATH,14,3772.811,3550.474,346.3304,0,0,0,100,0),
(@PATH,15,3776.353,3563.746,346.2406,0,0,0,100,0),
(@PATH,16,3774.419,3578.473,346.1627,0,0,0,100,0),
(@PATH,17,3768.748,3590.277,346.2671,0,0,0,100,0),
(@PATH,18,3755.322,3600.473,346.2415,0,0,0,100,0),
(@PATH,19,3742.794,3604.008,346.2505,0,0,0,100,0);

-- Pathing for Darkfallen Deathblade Entry: 26103
SET @NPC := 119306;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3825.312,`position_y`=3561.968,`position_z`=371.449 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3828.243,3550.227,371.6633,0,0,0,100,0),
(@PATH,2,3821.141,3538.786,371.4709,0,0,0,100,0),
(@PATH,3,3810.434,3533.297,371.4811,0,0,0,100,0),
(@PATH,4,3797.684,3527.717,371.4747,0,0,0,100,0),
(@PATH,5,3788.295,3523.66,371.5133,0,0,0,100,0),
(@PATH,6,3797.684,3527.717,371.4747,0,0,0,100,0),
(@PATH,7,3810.434,3533.297,371.4811,0,0,0,100,0),
(@PATH,8,3821.141,3538.786,371.4709,0,0,0,100,0),
(@PATH,9,3828.243,3550.227,371.6633,0,0,0,100,0),
(@PATH,10,3825.312,3561.968,371.449,0,0,0,100,0),
(@PATH,11,3818.058,3572.063,371.4479,0,0,0,100,0),
(@PATH,12,3825.312,3561.968,371.449,0,0,0,100,0);

-- Pathing for Darkfallen Deathblade Entry: 26103
SET @NPC := 119344;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3719.171,`position_y`=3634.032,`position_z`=371.4312 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3728.891,3640.265,371.399,0,0,0,100,0),
(@PATH,2,3744.495,3650.741,371.4715,0,0,0,100,0),
(@PATH,3,3754.314,3654.938,371.6409,0,0,0,100,0),
(@PATH,4,3762.468,3653.046,371.6256,0,0,0,100,0),
(@PATH,5,3769.032,3645.54,371.4821,0,0,0,100,0),
(@PATH,6,3779.281,3629.354,371.3682,0,0,0,100,0),
(@PATH,7,3769.032,3645.54,371.4821,0,0,0,100,0),
(@PATH,8,3762.468,3653.046,371.6256,0,0,0,100,0),
(@PATH,9,3754.314,3654.938,371.6409,0,0,0,100,0),
(@PATH,10,3744.495,3650.741,371.4715,0,0,0,100,0),
(@PATH,11,3728.891,3640.265,371.399,0,0,0,100,0),
(@PATH,12,3719.171,3634.032,371.4312,0,0,0,100,0),
(@PATH,13,3706.394,3625.895,371.3447,0,0,0,100,0),
(@PATH,14,3719.171,3634.032,371.4312,0,0,0,100,0);

-- Pathing for Darkfallen Deathblade Entry: 26103
SET @NPC := 119346;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3757.834,`position_y`=3500.429,`position_z`=371.4323 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3744.604,3489.214,371.4503,0,0,0,100,0),
(@PATH,2,3731.337,3479.792,371.4355,0,0,0,100,0),
(@PATH,3,3724.038,3478.357,371.6531,0,0,0,100,0),
(@PATH,4,3716.938,3479.223,371.649,0,0,0,100,0),
(@PATH,5,3709.829,3487.23,371.4689,0,0,0,100,0),
(@PATH,6,3699.577,3504.449,371.358,0,0,0,100,0),
(@PATH,7,3709.829,3487.23,371.4689,0,0,0,100,0),
(@PATH,8,3716.938,3479.223,371.649,0,0,0,100,0),
(@PATH,9,3724.038,3478.357,371.6531,0,0,0,100,0),
(@PATH,10,3731.337,3479.792,371.4355,0,0,0,100,0),
(@PATH,11,3744.604,3489.214,371.4503,0,0,0,100,0),
(@PATH,12,3757.834,3500.429,371.4323,0,0,0,100,0),
(@PATH,13,3769.854,3508.61,371.3447,0,0,0,100,0),
(@PATH,14,3757.834,3500.429,371.4323,0,0,0,100,0);

