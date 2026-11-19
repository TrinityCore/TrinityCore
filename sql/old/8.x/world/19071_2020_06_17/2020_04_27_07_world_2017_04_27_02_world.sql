-- 
SET @CGUID:= 100865;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+13;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 25719, 571, 0, 0, '0', 0, 0, 0,  3746.502, 6604.442, 169.675, 3.787364, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420),
(@CGUID+1, 25718, 571, 0, 0, '0', 0, 0, 0,  3746.502, 6604.442, 169.675, 3.787364, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420),
(@CGUID+2, 25719, 571, 0, 0, '0', 0, 0, 0,  3853.462, 6582.238, 167.075, 3.787364, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420),
(@CGUID+3, 25718, 571, 0, 0, '0', 0, 0, 0,  3853.462, 6582.238, 167.075, 3.787364, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420),
(@CGUID+4, 25719, 571, 0, 0, '0', 0, 0, 0,  3776.172, 6673.002, 151.503, 3.787364, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420),
(@CGUID+5, 25718, 571, 0, 0, '0', 0, 0, 0,  3776.172, 6673.002, 151.503, 3.787364, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420),
(@CGUID+6, 25713, 571, 0, 0, '0', 0, 0, 0,  3776.486, 7118.085, 165.538, 3.787364, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420),
(@CGUID+7, 25713, 571, 0, 0, '0', 0, 0, 0,  3800.425, 7227.171, 163.598, 3.787364, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420),
(@CGUID+8, 25707, 571, 0, 0, '0', 0, 0, 0,  3710.079, 7142.518, 160.422, 3.787364, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420),
(@CGUID+9, 25721, 571, 0, 0, '0', 0, 0, 0,  3899.659, 6885.204, 128.814, 3.787364, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420),
(@CGUID+10, 25721, 571, 0, 0, '0', 0, 0, 0, 3899.659, 6885.204, 139.779, 3.787364, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420),
(@CGUID+11, 25721, 571, 0, 0, '0', 0, 0, 0, 3947.159, 6927.227, 139.775, 3.787364, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420),
(@CGUID+12, 25721, 571, 0, 0, '0', 0, 0, 0, 3973.956, 6999.285, 139.779, 3.787364, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420),
(@CGUID+13, 25721, 571, 0, 0, '0', 0, 0, 0, 3844.386, 6884.535, 139.779, 3.787364, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420);

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+13; 
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, ''), 
(@CGUID+1, 0, 0, 0, 1, 0, '50637'), 
(@CGUID+2, 0, 0, 0, 1, 0, ''), 
(@CGUID+3, 0, 0, 0, 1, 0, '50637'), 
(@CGUID+4, 0, 0, 0, 1, 0, ''),
(@CGUID+5, 0, 0, 0, 1, 0, '50637'),
(@CGUID+6, 0, 0, 0, 1, 0, ''), 
(@CGUID+7, 0, 0, 0, 1, 0, ''), 
(@CGUID+8, 0, 0, 0, 1, 0, ''), 
(@CGUID+9, 0, 0, 0, 1, 0, ''), 
(@CGUID+10, 0, 0, 0, 1, 0, ''),
(@CGUID+11, 0, 0, 0, 1, 0, ''),
(@CGUID+12, 0, 0, 0, 1, 0, ''),
(@CGUID+13, 0, 0, 0, 1, 0, '');

UPDATE `creature` SET `position_x` = 3791.703 , `position_y` = 6564.170 , `position_z` = 170.505 WHERE `guid` = 122548; 
UPDATE `creature` SET `position_x` = 3958.501 , `position_y` = 6647.100 , `position_z` = 169.00 WHERE `guid` = 122549; 
UPDATE `creature` SET `position_x` = 4056.562 , `position_y` = 6855.353 , `position_z` = 165.638 WHERE `guid` = 122827; 
UPDATE `creature` SET `position_x` = 4128.494 , `position_y` = 6852.705 , `position_z` = 174.583 WHERE `guid` = 122737; 
UPDATE `creature` SET `position_x` = 4165.607 , `position_y` = 7021.470 , `position_z` = 166.323 WHERE `guid` = 122654; 
UPDATE `creature` SET `position_x` = 4009.485 , `position_y` = 7183.581 , `position_z` = 173.116 WHERE `guid` = 122824; 
UPDATE `creature` SET `position_x` = 3690.599 , `position_y` = 6963.458 , `position_z` = 156.776 WHERE `guid` = 122551; 
UPDATE `creature` SET `position_x` = 3545.916 , `position_y` = 7085.938 , `position_z` = 210.932 , `spawndist` = 20 WHERE `guid` = 122544; 
UPDATE `creature` SET `position_x` = 3737.879 , `position_y` = 6847.578 , `position_z` = 155.801 , `spawndist` = 15 WHERE `guid` = 122546; 
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 25718; 
UPDATE `creature` SET `spawndist` = 35 WHERE `guid` =121092; 
UPDATE `creature` SET `spawndist` = 35 WHERE `guid` BETWEEN 121099 AND 121111; 
UPDATE `creature_template` SET `speed_run` = 5.57143 WHERE `entry` = 24770; 
UPDATE `creature_template` SET `InhabitType` = 4 WHERE `entry` = 32534; 

DELETE FROM `creature` WHERE `guid` IN (122567, 122666, 122681);
DELETE FROM `creature_addon` WHERE `guid` IN (122567, 122666, 122681);
DELETE FROM `creature_formations` WHERE `leaderGUID`= 122681;
DELETE FROM `waypoint_data` WHERE `id`=1226810;

-- Pathing for Coldarra Spellbinder Entry: 25719 'TDB FORMAT' 
SET @NPC := @CGUID+0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3746.502,`position_y`=6604.442,`position_z`=169.6752 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3746.502,6604.442,169.6752,0,0,0,0,100,0), -- 10:09:06
(@PATH,2,3728.466,6628.31,167.4991,0,0,0,0,100,0), -- 10:09:15
(@PATH,3,3740.985,6611.622,168.9539,0,0,0,0,100,0), -- 10:09:28
(@PATH,4,3757.911,6590.785,171.0088,0,0,0,0,100,0), -- 10:09:38
(@PATH,5,3768.777,6586.423,170.0623,0,0,0,0,100,0), -- 10:09:47
(@PATH,6,3778.069,6575.995,170.2128,0,0,0,0,100,0), -- 10:09:53
(@PATH,7,3775.362,6580.682,169.8052,0,0,0,0,100,0), -- 10:10:00
(@PATH,8,3763.144,6588.104,170.9489,0,0,0,0,100,0), -- 10:10:05
(@PATH,9,3746.518,6604.487,169.7612,0,0,0,0,100,0); -- 10:10:11

DELETE FROM `creature_formations` WHERE `leaderGUID`= @CGUID+0;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+0,@CGUID+0,0,0,2,0,0),
(@CGUID+0,@CGUID+1,5,0,2,0,0);
UPDATE `creature` SET `position_x`=3746.502,`position_y`=6604.442,`position_z`=169.6752 WHERE `guid`=@CGUID+1;

-- Pathing for Coldarra Spellbinder Entry: 25719 'TDB FORMAT' 
SET @NPC := @CGUID+2;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3853.462,`position_y`=6582.238,`position_z`=167.0757 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3853.462,6582.238,167.0757,0,0,0,0,100,0), -- 10:11:07
(@PATH,2,3865.841,6600.766,165.5853,0,0,0,0,100,0), -- 10:11:18
(@PATH,3,3876.406,6620.453,165.4134,0,0,0,0,100,0), -- 10:11:27
(@PATH,4,3891.789,6642.364,166.4661,0,0,0,0,100,0), -- 10:11:39
(@PATH,5,3882.477,6631.198,166.0065,0,0,0,0,100,0), -- 10:11:50
(@PATH,6,3874.904,6617.864,165.4072,0,0,0,0,100,0), -- 10:11:59
(@PATH,7,3853.442,6582.185,167.0698,0,0,0,0,100,0); -- 10:12:11

DELETE FROM `creature_formations` WHERE `leaderGUID`= @CGUID+2;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+2,@CGUID+2,0,0,2,0,0),
(@CGUID+2,@CGUID+3,5,0,2,0,0);
UPDATE `creature` SET `position_x`=3853.462,`position_y`=6582.238,`position_z`=167.0757 WHERE `guid`=@CGUID+3;

-- Pathing for Coldarra Spellbinder Entry: 25719 'TDB FORMAT' 
SET @NPC := 122682;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3795.907,`position_y`=6607.033,`position_z`=161.6475 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3795.907,6607.033,161.6475,0,0,0,0,100,0), -- 10:09:55
(@PATH,2,3801.907,6572.36,168.6988,0,0,0,0,100,0), -- 10:10:12
(@PATH,3,3786.648,6536.464,175.4959,0,0,0,0,100,0), -- 10:10:27
(@PATH,4,3786.225,6515.275,178.2393,0,0,0,0,100,0), -- 10:10:42
(@PATH,5,3786.004,6533.51,176.1741,0,0,0,0,100,0), -- 10:10:52
(@PATH,6,3802.146,6569.362,169.4081,0,0,0,0,100,0), -- 10:10:59
(@PATH,7,3795.78,6607.015,161.4402,0,0,0,0,100,0); -- 10:11:15

DELETE FROM `creature_formations` WHERE `leaderGUID`= 122682;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(122682,122682,0,0,2,0,0),
(122682,122667,5,0,2,0,0);
UPDATE `creature` SET `position_x`=3853.462,`position_y`=6582.238,`position_z`=167.0757 WHERE `guid`=122667;

-- Pathing for Coldarra Spellbinder Entry: 25719 'TDB FORMAT' 
SET @NPC := @CGUID+4;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3776.172,`position_y`=6673.002,`position_z`=151.5036 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3776.172,6673.002,151.5036,0,0,0,0,100,0), -- 10:09:07
(@PATH,2,3784.46,6665.239,151.547,0,0,0,0,100,0), -- 10:09:12
(@PATH,3,3792.497,6660.205,151.600,0,0,0,0,100,0), -- 10:09:12
(@PATH,4,3784.46,6665.239,151.547,0,0,0,0,100,0), -- 10:09:12
(@PATH,5,3776.189,6673.356,151.5305,0,0,0,0,100,0), -- 10:09:24
(@PATH,6,3776.414,6686.501,150.9531,0,0,0,0,100,0), -- 10:09:29
(@PATH,7,3784.757,6700.908,150.913,0,0,0,0,100,0), -- 10:09:36
(@PATH,8,3776.298,6686.267,151.0565,0,0,0,0,100,0), -- 10:09:41
(@PATH,9,3776.17,6673.051,151.5327,0,0,0,0,100,0); -- 10:09:47

DELETE FROM `creature_formations` WHERE `leaderGUID`= @CGUID+4;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+4,@CGUID+4,0,0,2,0,0),
(@CGUID+4,@CGUID+5,5,0,2,0,0);
UPDATE `creature` SET `position_x`=3776.172,`position_y`=6673.002,`position_z`=151.5036 WHERE `guid`=@CGUID+5;

-- Pathing for Glacial Ancient Entry: 25709 'TDB FORMAT' 
SET @NPC := 122564;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3835.835,`position_y`=6564.987,`position_z`=169.2873 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3835.835,6564.987,169.2873,0,0,0,0,100,0), -- 10:10:49
(@PATH,2,3865.19,6586.372,167.1716,0,0,0,0,100,0), -- 10:10:59
(@PATH,3,3880.876,6574.423,169.4702,0,0,0,0,100,0), -- 10:11:14
(@PATH,4,3870.494,6547.783,173.7017,0,0,0,0,100,0), -- 10:11:23
(@PATH,5,3858.838,6527.854,176.9228,0,0,0,0,100,0), -- 10:11:35
(@PATH,6,3835.596,6539.546,173.554,0,0,0,0,100,0), -- 10:11:46
(@PATH,7,3835.835,6564.987,169.2873,0,0,0,0,100,0); -- 10:10:49

-- Pathing for Glacial Ancient Entry: 25709 'TDB FORMAT' 
SET @NPC := 122566;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4011.055,`position_y`=6732.877,`position_z`=160.3647 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4011.055,6732.877,160.3647,0,0,0,0,100,0), -- 11:00:47
(@PATH,2,3988.562,6729.594,157.1546,0,0,0,0,100,0), -- 11:00:58
(@PATH,3,3947.162,6749.381,152.4034,0,0,0,0,100,0), -- 11:01:07
(@PATH,4,3952.662,6772.721,153.4604,0,0,0,0,100,0), -- 11:01:24
(@PATH,5,3973.193,6814.381,158.2204,0,0,0,0,100,0), -- 11:01:35
(@PATH,6,3993.947,6794.005,160.8671,0,0,0,0,100,0), -- 11:01:53
(@PATH,7,4015.606,6759.979,163.3595,0,0,0,0,100,0), -- 11:02:06
(@PATH,8,4011.093,6732.818,160.366,0,0,0,0,100,0); -- 11:02:28

-- Pathing for Glacial Ancient Entry: 25709 'TDB FORMAT' 
SET @NPC := 122563;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4170.233,`position_y`=7033.129,`position_z`=168.403 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4170.233,7033.129,168.403,0,0,0,0,100,0), -- 11:03:03
(@PATH,2,4150.032,7039.117,166.215,0,0,0,0,100,0), -- 11:03:09
(@PATH,3,4143.993,7041.999,165.5633,0,0,0,0,100,0), -- 11:03:20
(@PATH,4,4143.929,7041.769,165.4963,0,0,0,0,100,0), -- 11:03:28
(@PATH,5,4166.755,7032.029,167.6483,0,0,0,0,100,0), -- 11:03:35
(@PATH,6,4179.019,7036.918,169.7405,0,0,0,0,100,0), -- 11:03:45
(@PATH,7,4203.13,7044.137,175.2166,0,0,0,0,100,0), -- 11:03:51
(@PATH,8,4183.847,7038.913,170.8574,0,0,0,0,100,0), -- 11:04:03
(@PATH,9,4170.236,7033.129,168.4034,0,0,0,0,100,0); -- 11:04:11

-- Pathing for Coldarra Scalesworn Entry: 25717 'TDB FORMAT' 
SET @NPC := 122650;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4110.18,`position_y`=6946.943,`position_z`=163.6098 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4110.18,6946.943,163.6098,0,0,0,0,100,0), -- 11:02:36
(@PATH,2,4103.704,6947.318,163.2632,0,0,0,0,100,0), -- 11:02:43
(@PATH,3,4103.726,6946.983,163.1357,0,0,0,0,100,0), -- 11:02:52
(@PATH,4,4115.845,6946.851,163.8068,0,0,0,0,100,0), -- 11:02:59
(@PATH,5,4119.202,6946.812,164.0883,0,0,0,0,100,0), -- 11:03:05
(@PATH,6,4135.35,6952.008,165.1999,0,0,0,0,100,0), -- 11:03:11
(@PATH,7,4133.528,6951.487,164.7321,0,0,0,0,100,0), -- 11:03:18
(@PATH,8,4129.267,6950.042,164.7286,0,0,0,0,100,0), -- 11:03:23
(@PATH,9,4110.18,6946.943,163.6098,0,0,0,0,100,0); -- 11:02:36

-- Pathing for Coldarra Scalesworn Entry: 25717 'TDB FORMAT' 
SET @NPC := 122653;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4177.346,`position_y`=6999.94,`position_z`=167.1795 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4177.346,6999.94,167.1795,0,0,0,0,100,0), -- 11:02:53
(@PATH,2,4178.359,7003.933,167.159,0,0,0,0,100,0), -- 11:03:05
(@PATH,3,4179.334,6983.605,167.3742,0,0,0,0,100,0), -- 11:03:12
(@PATH,4,4180.535,6960.606,169.7544,0,0,0,0,100,0), -- 11:03:23
(@PATH,5,4171.201,6939.539,171.0945,0,0,0,0,100,0), -- 11:03:34
(@PATH,6,4173.018,6943.02,170.7052,0,0,0,0,100,0), -- 11:03:46
(@PATH,7,4182.021,6975.294,168.3171,0,0,0,0,100,0), -- 11:03:56
(@PATH,8,4177.346,6999.94,167.1795,0,0,0,0,100,0); -- 11:02:53

-- Pathing for Blue Drakonid Supplicant Entry: 25713 'TDB FORMAT' 
SET @NPC := @CGUID+6;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3776.486,`position_y`=7118.085,`position_z`=165.5381 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3776.486,7118.085,165.5381,0,0,0,0,100,0), -- 11:31:16
(@PATH,2,3777.939,7118.563,165.6976,0,0,0,0,100,0), -- 11:31:18
(@PATH,3,3777.769,7118.291,165.5747,0,0,0,0,100,0), -- 11:31:24
(@PATH,4,3772.185,7117.834,164.6136,0,0,0,0,100,0), -- 11:31:26
(@PATH,5,3756.582,7117.771,167.8193,0,0,0,0,100,0), -- 11:31:29
(@PATH,6,3748.333,7119.222,162.9769,0,0,0,0,100,0), -- 11:31:35
(@PATH,7,3737.513,7121.027,162.1733,0,0,0,0,100,0), -- 11:31:40
(@PATH,8,3725.984,7124.862,161.4078,0,0,0,0,100,0), -- 11:31:45
(@PATH,9,3732.13,7121.827,161.6777,0,0,0,0,100,0), -- 11:31:51
(@PATH,10,3739.073,7120.887,162.5571,0,0,0,0,100,0), -- 11:31:54
(@PATH,11,3754.043,7118.356,166.37,0,0,0,0,100,0), -- 11:31:59
(@PATH,12,3766.063,7117.793,165.3616,0,0,0,0,100,0), -- 11:32:03
(@PATH,13,3776.254,7118.123,165.5038,0,0,0,0,100,0); -- 11:32:10

-- Pathing for Blue Drakonid Supplicant Entry: 25713 'TDB FORMAT' 
SET @NPC := @CGUID+7;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3800.425,`position_y`=7227.171,`position_z`=163.5981 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3800.425,7227.171,163.5981,0,0,0,0,100,0), -- 11:30:54
(@PATH,2,3810.142,7206.111,161.8623,0,0,0,0,100,0), -- 11:30:59
(@PATH,3,3804.592,7221.301,163.6667,0,0,0,0,100,0), -- 11:31:09
(@PATH,4,3796.86,7231.097,163.0284,0,0,0,0,100,0), -- 11:31:15
(@PATH,5,3777.21,7239.271,160.0223,0,0,0,0,100,0), -- 11:31:20
(@PATH,6,3770.141,7240.695,159.4914,0,0,0,0,100,0), -- 11:31:28
(@PATH,7,3776.136,7239.694,159.5423,0,0,0,0,100,0), -- 11:31:36
(@PATH,8,3793.909,7233.141,162.8602,0,0,0,0,100,0), -- 11:31:42
(@PATH,9,3800.39,7227.242,163.4349,0,0,0,0,100,0); -- 11:31:50

-- Pathing for Magic-bound Ancient Entry: 25707 'TDB FORMAT' 
SET @NPC := @CGUID+8;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3710.079,`position_y`=7142.518,`position_z`=160.4226 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3710.079,7142.518,160.4226,0,0,0,0,100,0), -- 11:31:41
(@PATH,2,3686.689,7155.103,160.3858,0,0,0,0,100,0), -- 11:32:01
(@PATH,3,3710.107,7142.603,160.6128,0,0,0,0,100,0), -- 11:32:13
(@PATH,4,3684.977,7134.014,160.5279,0,0,0,0,100,0), -- 11:32:20
(@PATH,5,3670.651,7109.532,160.3714,0,0,0,0,100,0), -- 11:33:46
(@PATH,6,3675.45,7074.923,159.6847,0,0,0,0,100,0), -- 11:33:50
(@PATH,7,3671.232,7082.916,160.2348,0,0,0,0,100,0), -- 11:34:00
(@PATH,8,3664.486,7095.002,160.777,0,0,0,0,100,0), -- 11:34:07
(@PATH,9,3671.143,7109.756,160.2934,0,0,0,0,100,0), -- 11:34:12
(@PATH,10,3685.304,7134.208,160.3568,0,0,0,0,100,0), -- 11:34:18
(@PATH,11,3710.079,7142.518,160.4226,0,0,0,0,100,0); -- 11:31:41

-- Pathing for Glacial Ancient Entry: 25709 'TDB FORMAT' 
SET @NPC := 122557;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3613.729,`position_y`=7243.817,`position_z`=220.5891 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3613.729,7243.817,220.5891,0,0,0,0,100,0), -- 11:39:14
(@PATH,2,3606.35,7267.252,225.9267,0,0,0,0,100,0), -- 11:39:28
(@PATH,3,3597.403,7303.142,237.27,0,0,0,0,100,0), -- 11:39:38
(@PATH,4,3623.762,7318.709,229.6163,0,0,0,0,100,0), -- 11:39:53
(@PATH,5,3624.336,7287.603,221.3449,0,0,0,0,100,0), -- 11:40:07
(@PATH,6,3624.804,7317.062,228.2999,0,0,0,0,100,0), -- 11:40:24
(@PATH,7,3597.886,7306.813,237.9965,0,0,0,0,100,0), -- 11:40:38
(@PATH,8,3604.609,7272.363,227.2627,0,0,0,0,100,0), -- 11:40:52
(@PATH,9,3612.816,7250.049,221.6292,0,0,0,0,100,0), -- 11:41:06
(@PATH,10,3613.881,7218.981,220.517,0,0,0,0,100,0), -- 11:41:17
(@PATH,11,3613.729,7243.817,220.5891,0,0,0,0,100,0); -- 11:41:33

-- Pathing for Glacial Ancient Entry: 25709 'TDB FORMAT' 
SET @NPC := 122558;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3517.92,`position_y`=7212.637,`position_z`=236.2428 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3517.92,7212.637,236.2428,0,0,0,0,100,0), -- 11:35:05
(@PATH,2,3550.075,7207.158,227.5906,0,0,0,0,100,0), -- 11:35:23
(@PATH,3,3592.844,7188.292,223.4674,0,0,0,0,100,0), -- 11:35:39
(@PATH,4,3587.187,7147.094,220.9413,0,0,0,0,100,0), -- 11:35:57
(@PATH,5,3586.441,7120.506,214.5045,0,0,0,0,100,0), -- 11:36:14
(@PATH,6,3581.853,7110.294,213.1641,0,0,0,0,100,0), -- 11:36:24
(@PATH,7,3577.837,7101.881,212.4084,0,0,0,0,100,0), -- 11:36:32
(@PATH,8,3564.537,7091.157,212.0578,0,0,0,0,100,0), -- 11:36:39
(@PATH,9,3517.627,7113.079,213.7343,0,0,0,0,100,0), -- 11:36:56
(@PATH,10,3508.483,7146.259,217.3716,0,0,0,0,100,0), -- 11:37:07
(@PATH,11,3513.477,7184.227,226.257,0,0,0,0,100,0), -- 11:37:21
(@PATH,12,3507.745,7149.502,218.1569,0,0,0,0,100,0), -- 11:37:36
(@PATH,13,3514.594,7125.146,214.8003,0,0,0,0,100,0), -- 11:37:50
(@PATH,14,3520.546,7095.021,212.3433,0,0,0,0,100,0), -- 11:38:03
(@PATH,15,3520.975,7092.51,211.883,0,0,0,0,100,0), -- 11:38:14
(@PATH,16,3564.593,7091.29,212.0666,0,0,0,0,100,0), -- 11:38:31
(@PATH,17,3585.45,7118.269,213.5838,0,0,0,0,100,0), -- 11:38:38
(@PATH,18,3586.194,7142.931,219.9543,0,0,0,0,100,0), -- 11:38:47
(@PATH,19,3590.48,7164.959,223.1869,0,0,0,0,100,0), -- 11:38:57
(@PATH,20,3558.002,7205.05,226.8047,0,0,0,0,100,0), -- 11:39:14
(@PATH,21,3517.836,7212.686,236.2242,0,0,0,0,100,0); -- 11:39:31

-- Pathing for Glacial Ancient Entry: 25709 'TDB FORMAT' 
SET @NPC := 122559;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3687.762,`position_y`=7297.271,`position_z`=216.3398 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3687.762,7297.271,216.3398,0,0,0,0,100,0), -- 11:59:27
(@PATH,2,3707.212,7307.455,212.5712,0,0,0,0,100,0), -- 11:59:42
(@PATH,3,3722.934,7317.455,210.9211,0,0,0,0,100,0), -- 11:59:54
(@PATH,4,3745.952,7321.007,208.1814,0,0,0,0,100,0), -- 12:00:01
(@PATH,5,3773.425,7337.966,202.0872,0,0,0,0,100,0), -- 12:00:09
(@PATH,6,3803.516,7357.45,195.994,0,0,0,0,100,0), -- 12:00:23
(@PATH,7,3832.716,7372.932,194.2845,0,0,0,0,100,0), -- 12:00:38
(@PATH,8,3869.961,7381.905,190.084,0,0,0,0,100,0), -- 12:00:51
(@PATH,9,3872.366,7356.501,185.054,0,0,0,0,100,0), -- 12:01:07
(@PATH,10,3857.737,7331.208,182.6498,0,0,0,0,100,0), -- 12:01:20
(@PATH,11,3844.623,7305.171,179.0436,0,0,0,0,100,0), -- 12:01:33
(@PATH,12,3844.439,7290.313,176.6929,0,0,0,0,100,0), -- 12:01:42
(@PATH,13,3855.4,7274.202,177.718,0,0,0,0,100,0), -- 12:01:48
(@PATH,14,3886.856,7257.011,177.3157,0,0,0,0,100,0), -- 12:02:12
(@PATH,15,3868.667,7259.01,177.2133,0,0,0,0,100,0), -- 12:03:01
(@PATH,16,3853.885,7253.435,175.0069,0,0,0,0,100,0), -- 12:03:01
(@PATH,17,3844.439,7290.313,176.6929,0,0,0,0,100,0), -- 12:01:42
(@PATH,18,3872.366,7356.501,185.054,0,0,0,0,100,0), -- 12:01:07
(@PATH,19,3869.961,7381.905,190.084,0,0,0,0,100,0), -- 12:00:51
(@PATH,20,3803.516,7357.45,195.994,0,0,0,0,100,0), -- 12:00:23
(@PATH,21,3745.952,7321.007,208.1814,0,0,0,0,100,0), -- 12:00:01
(@PATH,22,3722.934,7317.455,210.9211,0,0,0,0,100,0), -- 11:59:54
(@PATH,23,3687.762,7297.271,216.3398,0,0,0,0,100,0); -- 11:59:27

-- Pathing for Glacial Ancient Entry: 25709 'TDB FORMAT' 
SET @NPC := 122565;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3708.99,`position_y`=6800.135,`position_z`=161.5988 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3708.99,6800.135,161.5988,0,0,0,0,100,0), -- 12:12:58
(@PATH,2,3692.747,6804.992,164.3114,0,0,0,0,100,0), -- 12:13:11
(@PATH,3,3639.456,6825.105,165.9832,0,0,0,0,100,0), -- 12:13:24
(@PATH,4,3665.913,6795.765,168.4959,0,0,0,0,100,0), -- 12:13:41
(@PATH,5,3640.409,6822.443,166.3176,0,0,0,0,100,0), -- 12:14:00
(@PATH,6,3671.205,6812.824,163.8588,0,0,0,0,100,0), -- 12:14:17
(@PATH,7,3706.647,6800.021,162.3539,0,0,0,0,100,0), -- 12:14:34
(@PATH,8,3735.945,6812.461,155.727,0,0,0,0,100,0), -- 12:14:47
(@PATH,9,3770.794,6815.737,150.5865,0,0,0,0,100,0), -- 12:15:00
(@PATH,10,3782.188,6807.51,151.3537,0,0,0,0,100,0), -- 12:15:17
(@PATH,11,3781.339,6813.935,150.541,0,0,0,0,100,0), -- 12:15:31
(@PATH,12,3738.144,6812.984,155.2458,0,0,0,0,100,0), -- 12:15:41
(@PATH,13,3709.039,6800.329,161.4585,0,0,0,0,100,0); -- 12:15:59

SET @NPC := 122690;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3844.386,`position_y`=6884.535,`position_z`=116.977 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3844.386,6884.535,116.977,0,0,0,0,100,0), -- 12:13:11
(@PATH,2,3899.659,6885.204,116.977,0,0,0,0,100,0);

SET @NPC := 122691;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3899.659,`position_y`=6885.204,`position_z`=116.977 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3899.659,6885.204,116.977,0,0,0,0,100,0), -- 12:13:24
(@PATH,2,3947.159,6927.227,116.977,0,0,0,0,100,0);

SET @NPC := 122692;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3947.159,`position_y`=6927.227,`position_z`=116.977 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3947.159,6927.227,116.977,0,0,0,0,100,0), -- 12:13:41
(@PATH,2,3973.956,6999.285,116.977,0,0,0,0,100,0);

SET @NPC := 122693;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3973.956,`position_y`=6999.285,`position_z`=116.977 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3973.956,6999.285,116.977,0,0,0,0,100,0), -- 12:14:00
(@PATH,2,3954.742,7044.256,116.977,0,0,0,0,100,0);

SET @NPC := 122694;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3954.742,`position_y`=7044.256,`position_z`=116.977 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3954.742,7044.256,116.977,0,0,0,0,100,0), -- 12:14:17
(@PATH,2,3849.460,7077.785,116.977,0,0,0,0,100,0);

SET @NPC := 122696;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3849.460,`position_y`=7077.785,`position_z`=116.977 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3849.460,7077.785,116.977,0,0,0,0,100,0), -- 12:14:34
(@PATH,2,3777.356,7034.979,116.977,0,0,0,0,100,0);

SET @NPC := 122699;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3771.472,`position_y`=6971.930,`position_z`=128.814 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,2,3777.356,7034.979,128.814,0,0,0,0,100,0), -- 12:14:47
(@PATH,1,3771.472,6971.930,128.814,0,0,0,0,100,0); -- 12:15:00

SET @NPC := 122701;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3777.356,`position_y`=7034.979,`position_z`=128.814 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,2,3849.460,7077.785,128.814,0,0,0,0,100,0), -- 12:14:34
(@PATH,1,3777.356,7034.979,128.814,0,0,0,0,100,0); -- 12:14:47

SET @NPC := 122702;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3849.460,`position_y`=7077.785,`position_z`=128.814 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,2,3954.742,7044.256,128.814,0,0,0,0,100,0), -- 12:14:17
(@PATH,1,3849.460,7077.785,128.814,0,0,0,0,100,0);

SET @NPC := 122703;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3954.742,`position_y`=7044.256,`position_z`=128.814 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,2,3973.956,6999.285,128.814,0,0,0,0,100,0), -- 12:14:00
(@PATH,1,3954.742,7044.256,128.814,0,0,0,0,100,0);

SET @NPC := 122704;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3973.956,`position_y`=6999.285,`position_z`=128.814 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,2,3947.159,6927.227,128.814,0,0,0,0,100,0), -- 12:13:41
(@PATH,1,3973.956,6999.285,128.814,0,0,0,0,100,0);

SET @NPC := 122705;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3947.159,`position_y`=6927.227,`position_z`=128.814 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,2,3899.659,6885.204,128.814,0,0,0,0,100,0), -- 12:13:24
(@PATH,1,3947.159,6927.227,128.814,0,0,0,0,100,0);

SET @NPC := @CGUID+9;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3899.659,`position_y`=6885.204,`position_z`=128.814 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,2,3844.386,6884.535,128.814,0,0,0,0,100,0), -- 12:13:11
(@PATH,1,3899.659,6885.204,128.814,0,0,0,0,100,0); -- 12:13:24

SET @NPC := @CGUID+10;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3899.659,`position_y`=6885.204,`position_z`=139.779 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3899.659,6885.204,139.779,0,0,0,0,100,0), -- 12:13:24
(@PATH,2,3947.159,6927.227,139.779,0,0,0,0,100,0);

SET @NPC := @CGUID+11;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3947.159,`position_y`=6927.227,`position_z`=139.779 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3947.159,6927.227,139.779,0,0,0,0,100,0), -- 12:13:41
(@PATH,2,3973.956,6999.285,139.779,0,0,0,0,100,0);

SET @NPC := @CGUID+12;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3973.956,`position_y`=6999.285,`position_z`=139.779 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3973.956,6999.285,139.779,0,0,0,0,100,0), -- 12:14:00
(@PATH,2,3954.742,7044.256,139.779,0,0,0,0,100,0);

SET @NPC := 122699;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3954.742,`position_y`=7044.256,`position_z`=139.779 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3954.742,7044.256,139.779,0,0,0,0,100,0), -- 12:14:17
(@PATH,2,3849.460,7077.785,139.779,0,0,0,0,100,0);


SET @NPC := @CGUID+13;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3844.386,`position_y`=6884.535,`position_z`=139.779 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3844.386,6884.535,139.779,0,0,0,0,100,0), -- 12:13:11
(@PATH,2,3899.659,6885.204,139.779,0,0,0,0,100,0);

SET @NPC := 122700;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3608.967,`position_y`=6921.947,`position_z`=171.243 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3608.967,6921.947,171.243,0,0,0,0,100,0), -- 12:12:58
(@PATH,2,3645.704,6919.833,162.704,0,0,0,0,100,0), -- 12:13:11
(@PATH,3,3708.166,6916.377,141.299,0,0,0,0,100,0), -- 12:13:24
(@PATH,4,3755.512,6942.326,128.528,0,0,0,0,100,0), -- 12:13:41
(@PATH,5,3708.166,6916.377,141.299,0,0,0,0,100,0), -- 12:13:24
(@PATH,6,3645.704,6919.833,162.704,0,0,0,0,100,0), -- 12:13:11
(@PATH,7,3608.967,6921.947,171.243,0,0,0,0,100,0);

SET @NPC := 122697;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4101.004,`position_y`= 6768.417,`position_z`= 175.147 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4101.004,6768.417,175.147,0,0,0,0,100,0), -- 12:12:58
(@PATH,2,4044.740,6779.533,166.437,0,0,0,0,100,0), -- 12:13:11
(@PATH,3,4027.592,6806.338,164.339,0,0,0,0,100,0), -- 12:13:24
(@PATH,4,4035.885,6847.380,164.952,0,0,0,0,100,0), -- 12:13:41
(@PATH,5,4003.515,6883.456,159.719,0,0,0,0,100,0), -- 12:13:24
(@PATH,6,3984.422,6925.823,132.130,0,0,0,0,100,0), -- 12:13:11
(@PATH,7,4003.515,6883.456,159.719,0,0,0,0,100,0), -- 12:13:24
(@PATH,8,4035.885,6847.380,164.952,0,0,0,0,100,0), -- 12:13:41
(@PATH,9,4027.592,6806.338,164.339,0,0,0,0,100,0), -- 12:13:24
(@PATH,10,4044.740,6779.533,166.437,0,0,0,0,100,0), -- 12:13:11
(@PATH,11,4101.004,6768.417,175.147,0,0,0,0,100,0); -- 12:12:58

SET @NPC := 122698;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3971.448,`position_y`= 7253.354,`position_z`= 181.999 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3971.448,7253.354,181.999,0,0,0,0,100,0), -- 12:12:58
(@PATH,2,3947.747,7224.773,172.647,0,0,0,0,100,0), -- 12:13:11
(@PATH,3,3958.392,7169.247,166.275,0,0,0,0,100,0), -- 12:13:24
(@PATH,4,3922.217,7111.124,157.287,0,0,0,0,100,0), -- 12:13:41
(@PATH,5,3912.121,7088.232,138.103,0,0,0,0,100,0), -- 12:13:24
(@PATH,6,3922.217,7111.124,157.287,0,0,0,0,100,0), -- 12:13:41
(@PATH,7,3958.392,7169.247,166.275,0,0,0,0,100,0), -- 12:13:24
(@PATH,8,3947.747,7224.773,172.647,0,0,0,0,100,0), -- 12:13:11
(@PATH,9,3971.448,7253.354,181.999,0,0,0,0,100,0);

-- Glacial Ancient SAI
SET @ENTRY := 25709;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,16000,11,50505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Glacial Ancient - In Combat - Cast 'Frost Breath'");

-- Coldarra Scalesworn SAI
SET @ENTRY := 25717;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,15000,17000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coldarra Scalesworn - In Combat - Cast 'Rend'"),
(@ENTRY,0,1,0,0,0,100,0,1000,3000,8000,12000,11,12748,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coldarra Scalesworn - In Combat - Cast 'Frost Nova'");

-- Scalesworn Elite SAI
SET @ENTRY := 32534;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,3000,3000,8000,11,61269,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scalesworn Elite - In Combat - Cast 'Ice Shard'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,16000,22000,11,61272,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scalesworn Elite - In Combat - Cast 'Arcane Surge'");

DELETE FROM `gameobject` WHERE `guid`IN(46,48,50,55,57);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(46, 188113, 571, 0, 0, '0', 0, 4127.31, 6852.023, 174.3926, 3.717554, 0, 0, -0.9588194, 0.2840165, 120, 255, 1, 23420), -- 188113 (Area: -1)
(48, 188113, 571, 0, 0, '0', 0, 4123.374, 6881.992, 172.3801, 0.4188786, 0, 0, 0.2079115, 0.9781476, 120, 255, 1, 23420), -- 188113 (Area: -1)
(50, 188113, 571, 0, 0, '0', 0, 4095.132, 6847.428, 168.9135, 2.007128, 0, 0, 0.8433914, 0.5372996, 120, 255, 1, 23420), -- 188113 (Area: -1)
(55, 188113, 571, 0, 0, '0', 0, 3872.185, 7336.54, 181.9368, 2.495818, 0, 0, 0.9483232, 0.3173059, 120, 255, 1, 23420), -- 188113 (Area: -1)
(57, 188113, 571, 0, 0, '0', 0, 3880.16, 7309.908, 181.1171, 6.178466, 0, 0, -0.05233574, 0.9986296, 120, 255, 1, 23420); -- 188113 (Area: -1)
 