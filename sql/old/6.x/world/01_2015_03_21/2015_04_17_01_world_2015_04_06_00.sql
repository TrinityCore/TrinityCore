-- Pathing for Barash the Den Mother Entry: 23269 'TDB FORMAT' 
SET @NPC := 40645;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5028.414,`position_y`=385.6584,`position_z`=171.0149 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5028.414,385.6584,171.0149,0,0,1,0,100,0), -- 20:05:15
(@PATH,2,-5037.621,373.1704,171.0173,0,0,1,0,100,0), -- 20:05:18
(@PATH,3,-5051.44,373.3133,171.0181,0,0,1,0,100,0), -- 20:05:20
(@PATH,4,-5055.748,366.6401,171.0181,0,0,1,0,100,0), -- 20:05:21
(@PATH,5,-5058.255,357.087,171.0151,0,0,1,0,100,0), -- 20:05:23
(@PATH,6,-5055.19,345.9996,170.9724,0,0,1,0,100,0), -- 20:05:25
(@PATH,7,-5034.827,346.2221,171.0174,0,0,1,0,100,0), -- 20:05:27
(@PATH,8,-5025.357,353.0934,170.6913,0,0,1,0,100,0), -- 20:05:31
(@PATH,9,-5019.042,361.9999,170.704,0,0,1,0,100,0), -- 20:05:33
(@PATH,10,-5018.177,373.4781,170.964,0,0,1,0,100,0); -- 20:05:34

-- Update position Ja'y Nosliw <Skybreaker General> 22433
UPDATE `creature` SET `position_x`=-5144.404, `position_y`=600.9089, `position_z`=82.75489, `orientation`=6.021386 WHERE  `guid`=78787;

-- Update position Taskmaster Varkule Dragonbreath 23140
UPDATE `creature` SET `position_x`=-5114.439, `position_y`=588.4843, `position_z`=85.87241, `orientation`=3.036873 WHERE  `guid`=51876;

-- Pathing for Arvoar the Rapacious Entry: 23267 'TDB FORMAT' 
SET @NPC := 40619;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5115.436,`position_y`=144.5614,`position_z`=130.1606 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5115.436,144.5614,130.1606,0,0,0,0,100,0), -- 07:19:51
(@PATH,2,-5127.696,139.5475,130.1854,0,0,0,0,100,0), -- 07:19:53
(@PATH,3,-5122.23,120.3736,129.9845,0,0,0,0,100,0), -- 07:19:56
(@PATH,4,-5117.039,117.6734,129.9086,0,0,0,0,100,0), -- 07:19:58
(@PATH,5,-5107.681,117.8557,129.8407,0,0,0,0,100,0), -- 07:19:59
(@PATH,6,-5100.675,122.349,130.0891,0,0,0,0,100,0), -- 07:20:01
(@PATH,7,-5105.304,139.7458,130.1348,0,0,0,0,100,0); -- 07:20:04

-- Update fly speed of Dragonmaw Skybreakers
UPDATE `waypoint_data` SET `move_type`=1 WHERE  `id` IN (782940, 782970, 782910, 782920, 782930, 782940, 782950, 782960, 782970, 782980, 782990, 783000);

-- Pathing for Dragonmaw Transporter Entry: 23188 'TDB FORMAT' 
SET @NPC := 132814;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4584.821,`position_y`=56.05914,`position_z`=260.3116 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,16314,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4584.821,56.05914,260.3116,0,0,1,0,100,0), -- 07:28:22
(@PATH,2,-4554.921,74.39236,250.4782,0,0,1,0,100,0), -- 07:28:22
(@PATH,3,-4532.374,72.2015,243.3948,0,0,1,0,100,0), -- 07:28:22
(@PATH,4,-4508.559,67.28505,241.6727,0,0,1,0,100,0), -- 07:28:22
(@PATH,5,-4487.302,56.6492,242.2004,0,0,1,0,100,0), -- 07:28:22
(@PATH,6,-4470.297,28.84614,244.756,0,0,1,0,100,0), -- 07:28:22
(@PATH,7,-4461.818,-8.348633,247.9227,0,0,1,0,100,0), -- 07:28:22
(@PATH,8,-4477.97,-44.38118,242.3393,0,0,1,0,100,0), -- 07:28:22
(@PATH,9,-4516.678,-59.03483,240.2283,0,0,1,0,100,0), -- 07:28:22
(@PATH,10,-4543.176,-60.92849,240.2838,0,0,1,0,100,0), -- 07:28:22
(@PATH,11,-4566.225,-51.06413,247.3116,0,0,1,0,100,0), -- 07:28:22
(@PATH,12,-4581.653,-29.58301,254.2004,0,0,1,0,100,0), -- 07:28:22
(@PATH,13,-4591.782,0.532661,260.3116,0,0,1,0,100,0), -- 07:28:22
(@PATH,14,-4594.208,28.59668,260.3116,0,0,1,0,100,0); -- 07:28:22

-- Pathing for Dragonmaw Transporter Entry: 23188 'TDB FORMAT' 
SET @NPC := 132818;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4735.987,`position_y`=122.2487,`position_z`=106.433 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,16314,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4735.987,122.2487,106.433,0,0,1,0,100,0), -- 07:15:27
(@PATH,2,-4744.92,149.3799,106.433,0,0,1,0,100,0), -- 07:15:27
(@PATH,3,-4751.057,182.3161,106.433,0,0,1,0,100,0), -- 07:15:27
(@PATH,4,-4767.275,216.0688,106.433,0,0,1,0,100,0), -- 07:15:27
(@PATH,5,-4776.866,248.6194,106.433,0,0,1,0,100,0), -- 07:15:27
(@PATH,6,-4781.172,280.7835,106.433,0,0,1,0,100,0), -- 07:15:27
(@PATH,7,-4783.174,319.2545,106.433,0,0,1,0,100,0), -- 07:15:27
(@PATH,8,-4752.483,324.3357,106.433,0,0,1,0,100,0), -- 07:15:27
(@PATH,9,-4729.643,316.453,106.433,0,0,1,0,100,0), -- 07:15:27
(@PATH,10,-4715.97,309.7697,106.433,0,0,1,0,100,0), -- 07:15:27
(@PATH,11,-4709.104,290.6015,106.433,0,0,1,0,100,0), -- 07:15:27
(@PATH,12,-4710.651,264.7013,106.433,0,0,1,0,100,0), -- 07:15:27
(@PATH,13,-4709.572,256.6543,106.433,0,0,1,0,100,0), -- 07:15:27
(@PATH,14,-4706.147,218.4914,106.433,0,0,1,0,100,0), -- 07:15:27
(@PATH,15,-4709.459,193.1469,106.433,0,0,1,0,100,0), -- 07:15:27
(@PATH,16,-4704.721,157.6649,106.433,0,0,1,0,100,0), -- 07:15:27
(@PATH,17,-4695.498,116.758,106.433,0,0,1,0,100,0), -- 07:15:27
(@PATH,18,-4713.938,87.04405,101.2085,0,0,1,0,100,0), -- 07:15:27
(@PATH,19,-4726.667,100.212,106.433,0,0,1,0,100,0); -- 07:15:27
