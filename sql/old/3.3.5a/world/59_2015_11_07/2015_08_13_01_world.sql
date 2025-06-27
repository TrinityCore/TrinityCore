-- Patchwork Horror 
-- Pathing for Entry: 53943 'TDB FORMAT'
SET @NPC := 53953;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x` = 3560.001, `position_y` = -3333.560, `position_z` = 129.3446 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES
(@PATH, 1, 3560, -3333.56, 129.345),
(@PATH, 2, 3586.66, -3333.67, 127.532),
(@PATH, 3, 3547.96, -3350.48, 129.671),
(@PATH, 4, 3535.26, -3386.41, 132.376),
(@PATH, 5, 3547.32, -3425.53, 135.592),
(@PATH, 6, 3535.26, -3386.41, 132.376),
(@PATH, 7, 3547.96, -3350.48, 129.671),
(@PATH, 8, 3586.66, -3333.67, 127.532),
(@PATH, 9, 3560, -3333.56, 129.345),
(@PATH, 10, 3534.01, -3324.43, 129.798),
(@PATH, 11, 3514.71, -3316.2, 131.367),
(@PATH, 12, 3534.01, -3324.43, 129.798);

-- Pathing for Entry: 53943 'TDB FORMAT'
SET @NPC := 53943;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2, `position_x` = 3658.833, `position_y` = -3494.780, `position_z` = 136.6372 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES
(@PATH, 1, 3658.83, -3494.78, 136.637),
(@PATH, 2, 3643.47, -3488.16, 137.328),
(@PATH, 3, 3627.43, -3493.95, 136.949),
(@PATH, 4, 3613.32, -3494.96, 136.837),
(@PATH, 5, 3595.51, -3479.3, 134.85),
(@PATH, 6, 3611.96, -3502.99, 137.218),
(@PATH, 7, 3628.52, -3521.97, 136.803),
(@PATH, 8, 3646.97, -3519.17, 136.667),
(@PATH, 9, 3657.54, -3512.66, 136.748);

-- Pathing for Entry: 53954 'TDB FORMAT'
SET @NPC := 53954;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2, `position_x` = 3659.589, `position_y` = -3336.161, `position_z` = 123.8126 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES
(@PATH, 1, 3659.59, -3336.16, 123.813),
(@PATH, 2, 3676.39, -3362, 126.91),
(@PATH, 3, 3684.48, -3376.63, 129.534),
(@PATH, 4, 3692.16, -3390.77, 131.803),
(@PATH, 5, 3704.82, -3409.99, 132.136),
(@PATH, 6, 3707.44, -3415.75, 131.862),
(@PATH, 7, 3713.12, -3429.09, 131.052),
(@PATH, 8, 3707.44, -3415.75, 131.862),
(@PATH, 9, 3704.82, -3409.99, 132.136),
(@PATH, 10, 3692.16, -3390.77, 131.803),
(@PATH, 11, 3684.48, -3376.63, 129.534),
(@PATH, 12, 3676.56, -3362.26, 126.988),
(@PATH, 13, 3659.59, -3336.16, 123.813),
(@PATH, 14, 3676.38, -3308.39, 126.575),
(@PATH, 15, 3684.71, -3277.38, 127.788),
(@PATH, 16, 3710.36, -3258.23, 127.414),
(@PATH, 17, 3684.71, -3277.38, 127.788),
(@PATH, 18, 3676.38, -3308.39, 126.575);

UPDATE `creature_template` SET `speed_walk` = 1 WHERE `Entry` = 10414;
