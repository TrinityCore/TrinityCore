-- Some Hinterlands fixups.

-- Waypoint Script guids
SET @SCRIPTGUID := 55; -- 12 required

-- Fixup Revantusk Watcher add Invisibility and Stealth Detection aura
UPDATE creature SET `modelid`=0,`curhealth`=1 WHERE id=14730;
UPDATE `creature_addon` SET `bytes2`=257,`auras`=18950 WHERE guid IN (SELECT guid FROM creature WHERE id=14730);

-- Revantusk Drummer add emote
DELETE FROM `creature_addon` WHERE `guid` IN (92886,92887,92888);
DELETE FROM `creature_template_addon` WHERE `entry`=14734;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`emote`) VALUES (14734,1,36);

-- Pathing for Smith Slagtree Entry: 14737
SET @NPC := 92909;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-589.9536,`position_y`=-4548.458,`position_z`=9.161489 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-591.6767,-4554.789,9.161489,0,0,0,0,100,0),
(@PATH,2,-595.7503,-4559.671,9.161489,0,6000,0,929090,100,0),
(@PATH,3,-589.9536,-4548.458,9.161489,0,29000,0,929091,100,0);
DELETE FROM `waypoint_scripts` WHERE `id` IN (929090,929091);
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`o`,`guid`) VALUES
(929090,1,30,0,0,3.228859,@SCRIPTGUID),
(929090,2,2,74,8,0,@SCRIPTGUID+1),
(929090,5,2,74,0,0,@SCRIPTGUID+2),
(929091,1,30,0,0,0.6108652,@SCRIPTGUID+3),
(929091,2,15,23488,1,0,@SCRIPTGUID+4),
(929091,5,2,83,233,0,@SCRIPTGUID+5),
(929091,24,2,83,69,0,@SCRIPTGUID+6);

-- Pathing for Mystic Yayo'jin Entry: 14739
SET @NPC := 92911;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-541.7078,`position_y`=-4608.892,`position_z`=13.12271 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-538.0938,-4609.549,13.11275,0,500,0,0,100,0),
(@PATH,2,-538.0938,-4609.549,13.11275,5.986479,8000,0,0,100,0),
(@PATH,3,-539.3364,-4606.846,13.11516,0,500,0,0,100,0),
(@PATH,4,-539.3364,-4606.846,13.11516,0.9773844,10000,0,0,100,0),
(@PATH,5,-542.105,-4606.523,13.12286,0,500,0,0,100,0),
(@PATH,6,-542.105,-4606.523,13.12286,1.815142,9000,0,0,100,0),
(@PATH,7,-543.7079,-4611.147,13.15176,0,0,0,0,100,0),
(@PATH,8,-540.0343,-4611.84,13.11918,0,0,0,0,100,0),
(@PATH,9,-539.916,-4609.014,13.11769,0,0,0,0,100,0),
(@PATH,10,-541.7078,-4608.892,13.12271,0,500,0,0,100,0),
(@PATH,11,-541.7078,-4608.892,13.12271,2.86234,48000,0,929110,100,0);
DELETE FROM `waypoint_scripts` WHERE `id`=929110;
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`guid`) VALUES
(929110,2,2,74,1,@SCRIPTGUID+7),
(929110,39,2,74,0,@SCRIPTGUID+8),
(929110,41,2,83,133,@SCRIPTGUID+9);

-- Pathing for Revantusk Watcher Entry: 14730
SET @NPC := 92898;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-621.9691,`position_y`=-4670.079,`position_z`=5.061154 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,257,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-614.1932,-4653.834,5.040805,0,0,0,0,100,0),
(@PATH,2,-620.4515,-4667.109,5.066647,0,0,0,0,100,0),
(@PATH,3,-630.2896,-4686.361,5.086016,0,0,0,0,100,0),
(@PATH,4,-644.1071,-4714.346,5.219747,0,9000,0,928980,100,0);
DELETE FROM `waypoint_scripts` WHERE `id` IN (928980);
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`x`,`y`,`z`,`o`,`guid`) VALUES
(928980,8,6,0,1,-621.9691,-4670.079,5.061154,1.098353,@SCRIPTGUID+10);

-- Pathing for Revantusk Watcher Entry: 14730
SET @NPC := 92899;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-619.3934,`position_y`=-4664.687,`position_z`=5.057855 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,257,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-615.9739,-4657.611,5.048162,0,0,0,0,100,0),
(@PATH,2,-617.2744,-4660.37,5.053535,0,0,0,0,100,0),
(@PATH,3,-618.5742,-4663.127,5.058907,0,0,0,0,100,0),
(@PATH,4,-619.8167,-4665.867,5.066616,0,0,0,0,100,0),
(@PATH,5,-621.2051,-4668.584,5.066684,0,0,0,0,100,0),
(@PATH,6,-622.5936,-4671.301,5.066746,0,0,0,0,100,0),
(@PATH,7,-623.9827,-4674.019,5.066799,0,0,0,0,100,0),
(@PATH,8,-625.2844,-4676.566,5.066853,0,0,0,0,100,0),
(@PATH,9,-626.7726,-4679.479,5.060135,0,0,0,0,100,0),
(@PATH,10,-628.1486,-4682.171,5.07026,0,0,0,0,100,0),
(@PATH,11,-629.5447,-4684.852,5.078729,0,0,0,0,100,0),
(@PATH,12,-630.8968,-4687.591,5.091967,0,0,0,0,100,0),
(@PATH,13,-632.2471,-4690.326,5.105191,0,10000,0,928990,100,0);
DELETE FROM `waypoint_scripts` WHERE `id` IN (928990);
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`x`,`y`,`z`,`o`,`guid`) VALUES
(928990,9,6,0,1,-619.3934,-4664.687,5.057855,1.120319,@SCRIPTGUID+11);

-- Pathing for Revantusk Watcher Entry: 14730
SET @NPC := 92946;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-583.7281,`position_y`=-4567.89,`position_z`=9.120717 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,257,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-576.5599,-4568.717,9.161489,0,0,0,0,100,0),
(@PATH,2,-570.6282,-4570.051,9.286489,0,0,0,0,100,0),
(@PATH,3,-564.2906,-4571.396,9.480314,0,0,0,0,100,0),
(@PATH,4,-559.9419,-4573.958,9.605314,0,0,0,0,100,0),
(@PATH,5,-554.7994,-4581.686,9.740568,0,0,0,0,100,0),
(@PATH,6,-552.841,-4589.281,9.605314,0,0,0,0,100,0),
(@PATH,7,-555.0905,-4596.873,9.605314,0,0,0,0,100,0),
(@PATH,8,-555.7503,-4601.974,9.614173,0,0,0,0,100,0),
(@PATH,9,-559.4357,-4608.517,9.739173,0,0,0,0,100,0),
(@PATH,10,-563.2764,-4613.221,9.739173,0,0,0,0,100,0),
(@PATH,11,-566.1555,-4615.88,9.739173,0,0,0,0,100,0),
(@PATH,12,-566.157,-4619.973,9.739173,0,0,0,0,100,0),
(@PATH,13,-565.7682,-4621.338,10.5361,0,0,0,0,100,0),
(@PATH,14,-564.9091,-4624.298,12.33652,0,0,0,0,100,0),
(@PATH,15,-564.4247,-4626.619,13.21042,0,0,0,0,100,0),
(@PATH,16,-565.8718,-4628.861,13.21023,0,0,0,0,100,0),
(@PATH,17,-568.9028,-4629.674,13.21105,0,0,0,0,100,0),
(@PATH,18,-571.7204,-4630.63,14.69388,0,0,0,0,100,0),
(@PATH,19,-576.4782,-4631.931,17.15172,0,0,0,0,100,0),
(@PATH,20,-581.1254,-4634.227,19.03236,0,0,0,0,100,0),
(@PATH,21,-585.7308,-4639.775,21.21893,0,0,0,0,100,0),
(@PATH,22,-585.2182,-4645.189,22.94262,0,0,0,0,100,0),
(@PATH,23,-582.2473,-4647.843,24.75424,0,0,0,0,100,0),
(@PATH,24,-576.8602,-4648.417,26.25482,0,0,0,0,100,0),
(@PATH,25,-572.6866,-4646.474,28.46729,0,0,0,0,100,0),
(@PATH,26,-569.6187,-4644.834,30.25781,0,0,0,0,100,0),
(@PATH,27,-565.1738,-4641.978,30.34623,0,0,0,0,100,0),
(@PATH,28,-561.8621,-4639.479,30.34518,0,0,0,0,100,0),
(@PATH,29,-559.1216,-4640.588,30.34381,0,0,0,0,100,0),
(@PATH,30,-561.8621,-4639.479,30.34518,0,0,0,0,100,0),
(@PATH,31,-568.164,-4644.291,30.34578,0,0,0,0,100,0),
(@PATH,32,-572.6866,-4646.474,28.46729,0,0,0,0,100,0),
(@PATH,33,-576.8602,-4648.417,26.25482,0,0,0,0,100,0),
(@PATH,34,-582.2473,-4647.843,24.75424,0,0,0,0,100,0),
(@PATH,35,-585.2182,-4645.189,22.94262,0,0,0,0,100,0),
(@PATH,36,-585.7538,-4639.803,21.22803,0,0,0,0,100,0),
(@PATH,37,-581.134,-4634.237,19.03649,0,0,0,0,100,0),
(@PATH,38,-576.6482,-4631.978,17.23644,0,0,0,0,100,0),
(@PATH,39,-572.6212,-4631.001,15.44738,0,0,0,0,100,0),
(@PATH,40,-568.9028,-4629.674,13.21105,0,0,0,0,100,0),
(@PATH,41,-565.8718,-4628.861,13.21023,0,0,0,0,100,0),
(@PATH,42,-564.4247,-4626.619,13.21042,0,0,0,0,100,0),
(@PATH,43,-564.7512,-4625.108,12.77208,0,0,0,0,100,0),
(@PATH,44,-565.6238,-4622.17,11.06051,0,0,0,0,100,0),
(@PATH,45,-566.157,-4619.973,9.739173,0,0,0,0,100,0),
(@PATH,46,-566.1555,-4615.88,9.739173,0,0,0,0,100,0),
(@PATH,47,-563.2764,-4613.221,9.739173,0,0,0,0,100,0),
(@PATH,48,-559.4357,-4608.517,9.739173,0,0,0,0,100,0),
(@PATH,49,-555.7503,-4601.974,9.614173,0,0,0,0,100,0),
(@PATH,50,-555.0905,-4596.873,9.605314,0,0,0,0,100,0),
(@PATH,51,-552.841,-4589.281,9.605314,0,0,0,0,100,0),
(@PATH,52,-554.7994,-4581.686,9.740568,0,0,0,0,100,0),
(@PATH,53,-559.9419,-4573.958,9.605314,0,0,0,0,100,0),
(@PATH,54,-564.2906,-4571.396,9.480314,0,0,0,0,100,0),
(@PATH,55,-570.6282,-4570.051,9.286489,0,0,0,0,100,0),
(@PATH,56,-576.5599,-4568.717,9.161489,0,0,0,0,100,0),
(@PATH,57,-583.7281,-4567.89,9.120717,0,0,0,0,100,0),
(@PATH,58,-589.5422,-4571.942,9.482045,0,0,0,0,100,0),
(@PATH,59,-595.0231,-4573.951,9.786489,0,0,0,0,100,0),
(@PATH,60,-589.5422,-4571.942,9.482045,0,0,0,0,100,0),
(@PATH,61,-583.7281,-4567.89,9.120717,0,0,0,0,100,0);

-- Pathing for Revantusk Watcher Entry: 14730
SET @NPC := 92903;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-587.9592,`position_y`=-4565.161,`position_z`=9.161489 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,257,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-589.1211,-4560.011,9.161489,0,0,0,0,100,0),
(@PATH,2,-586.8055,-4558.024,9.161489,0,0,0,0,100,0),
(@PATH,3,-582.1091,-4557.421,9.418232,0,0,0,0,100,0),
(@PATH,4,-563.0848,-4567.083,9.617765,0,0,0,0,100,0),
(@PATH,5,-564.0873,-4565.243,9.636915,0,0,0,0,100,0),
(@PATH,6,-554.4955,-4549.669,10.38081,0,0,0,0,100,0),
(@PATH,7,-551.9146,-4546.659,10.20161,0,0,0,0,100,0),
(@PATH,8,-530.5864,-4534.892,10.88507,0,0,0,0,100,0),
(@PATH,9,-528.0935,-4540.74,10.68414,0,0,0,0,100,0),
(@PATH,10,-548.4247,-4552.033,10.33687,0,0,0,0,100,0),
(@PATH,11,-559.3554,-4571.553,9.605396,0,0,0,0,100,0),
(@PATH,12,-558.353,-4572.357,9.734953,0,0,0,0,100,0),
(@PATH,13,-552.0048,-4585.105,9.830168,0,0,0,0,100,0),
(@PATH,14,-551.9355,-4589.406,9.685699,0,0,0,0,100,0),
(@PATH,15,-559.1077,-4612.717,9.864173,0,0,0,0,100,0),
(@PATH,16,-563.384,-4614.937,9.739216,0,0,0,0,100,0),
(@PATH,17,-587.5415,-4618.487,9.456761,0,0,0,0,100,0),
(@PATH,18,-596.1833,-4629.224,9.796849,0,0,0,0,100,0),
(@PATH,19,-601.0118,-4628.754,9.411202,0,0,0,0,100,0),
(@PATH,20,-592.4224,-4616.147,9.359911,0,0,0,0,100,0),
(@PATH,21,-588.6967,-4613.219,9.55808,0,0,0,0,100,0),
(@PATH,22,-567.4048,-4614.91,9.729955,0,0,0,0,100,0),
(@PATH,23,-566.9582,-4615.76,9.628169,0,0,0,0,100,0),
(@PATH,24,-557.4971,-4586.748,9.730397,0,0,0,0,100,0),
(@PATH,25,-565.1426,-4573.827,9.526945,0,0,0,0,100,0),
(@PATH,26,-587.9592,-4565.161,9.161489,0,0,0,0,100,0);

-- Pathing for Revantusk Watcher Entry: 14730
SET @NPC := 92904;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-563.7853,`position_y`=-4572.203,`position_z`=9.480314 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,257,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-589.0695,-4562.6,9.161489,0,0,0,0,100,0),
(@PATH,2,-584.3304,-4558.535,9.161489,0,0,0,0,100,0),
(@PATH,3,-563.9773,-4568.874,9.527922,0,0,0,0,100,0),
(@PATH,4,-551.5903,-4548.764,10.15376,0,0,0,0,100,0),
(@PATH,5,-529.4497,-4536.548,11.02155,0,0,0,0,100,0),
(@PATH,6,-549.9079,-4550.587,9.985304,0,0,0,0,100,0),
(@PATH,7,-561.3011,-4570.924,9.605314,0,0,0,0,100,0),
(@PATH,8,-553.2903,-4587.01,9.647795,0,0,0,0,100,0),
(@PATH,9,-561.1612,-4612.59,9.864173,0,0,0,0,100,0),
(@PATH,10,-588.2601,-4616.572,9.456761,0,0,0,0,100,0),
(@PATH,11,-599.4961,-4630.079,9.579808,0,0,0,0,100,0),
(@PATH,12,-589.3387,-4615.174,9.456761,0,0,0,0,100,0),
(@PATH,13,-565.2857,-4617.084,9.739173,0,0,0,0,100,0),
(@PATH,14,-555.2867,-4586.42,9.730314,0,0,0,0,100,0),
(@PATH,15,-563.7853,-4572.203,9.480314,0,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=92903;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(92903,92903,0,0,2),
(92903,92904,2,300,2);

-- Pathing for Vilebranch Headhunter Entry: 2641
SET @NPC := 93747;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-334.7697,`position_y`=-4118.176,`position_z`=152.1513 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-333.2237,-4134.225,152.0622,0,0,0,0,100,0),
(@PATH,2,-339.8373,-4147.746,152.1256,0,0,0,0,100,0),
(@PATH,3,-346.6712,-4160.327,152.1256,0,0,0,0,100,0),
(@PATH,4,-345.9421,-4177.107,152.2871,0,0,0,0,100,0),
(@PATH,5,-346.2449,-4195.276,152.2244,0,0,0,0,100,0),
(@PATH,6,-345.7937,-4206.436,152.1899,0,0,0,0,100,0),
(@PATH,7,-341.1774,-4208.535,152.0649,0,0,0,0,100,0),
(@PATH,8,-337.7476,-4206.129,152.1899,0,1000,0,0,100,0),
(@PATH,9,-341.1774,-4208.535,152.0649,0,0,0,0,100,0),
(@PATH,10,-345.7937,-4206.436,152.1899,0,0,0,0,100,0),
(@PATH,11,-346.2449,-4195.276,152.2244,0,0,0,0,100,0),
(@PATH,12,-345.9421,-4177.107,152.2871,0,0,0,0,100,0),
(@PATH,13,-346.6712,-4160.327,152.1256,0,0,0,0,100,0),
(@PATH,14,-339.8373,-4147.746,152.1256,0,0,0,0,100,0),
(@PATH,15,-333.2237,-4134.225,152.0622,0,0,0,0,100,0),
(@PATH,16,-334.7697,-4118.176,152.1513,0,0,0,0,100,0),
(@PATH,17,-345.4443,-4114.745,151.9538,0,0,0,0,100,0),
(@PATH,18,-358.0292,-4116.998,154.2687,0,0,0,0,100,0),
(@PATH,19,-345.4443,-4114.745,151.9538,0,0,0,0,100,0),
(@PATH,20,-334.7697,-4118.176,152.1513,0,0,0,0,100,0);

-- Pathing for Vilebranch Headhunter Entry: 2641
SET @NPC := 93634;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-304.2423,`position_y`=-4087.691,`position_z`=152.2971 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-295.6881,-4087.868,152.4837,0,0,0,0,100,0),
(@PATH,2,-284.571,-4085.302,152.14,0,0,0,0,100,0),
(@PATH,3,-272.7595,-4092.214,152.5167,0,0,0,0,100,0),
(@PATH,4,-284.571,-4085.302,152.14,0,0,0,0,100,0),
(@PATH,5,-295.6881,-4087.868,152.4837,0,0,0,0,100,0),
(@PATH,6,-304.2423,-4087.691,152.2971,0,0,0,0,100,0),
(@PATH,7,-314.2382,-4088.344,152.2971,0,0,0,0,100,0),
(@PATH,8,-322.7508,-4087.331,152.5894,0,0,0,0,100,0),
(@PATH,9,-331.1907,-4082.108,152.5066,0,0,0,0,100,0),
(@PATH,10,-338.1729,-4086.666,153.3141,0,0,0,0,100,0),
(@PATH,11,-342.3202,-4093.814,152.2581,0,0,0,0,100,0),
(@PATH,12,-338.1729,-4086.666,153.3141,0,0,0,0,100,0),
(@PATH,13,-331.1907,-4082.108,152.5066,0,0,0,0,100,0),
(@PATH,14,-322.7508,-4087.331,152.5894,0,0,0,0,100,0),
(@PATH,15,-314.2382,-4088.344,152.2971,0,0,0,0,100,0),
(@PATH,16,-304.2423,-4087.691,152.2971,0,0,0,0,100,0);

-- Pathing for Vilebranch Headhunter Entry: 2641
SET @NPC := 93755;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-334.7697,`position_y`=-4118.176,`position_z`=152.1513 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-345.4443,-4114.745,151.9538,0,0,0,0,100,0),
(@PATH,2,-334.7697,-4118.176,152.1513,0,0,0,0,100,0),
(@PATH,3,-333.2237,-4134.225,152.0622,0,0,0,0,100,0),
(@PATH,4,-339.8373,-4147.746,152.1256,0,0,0,0,100,0),
(@PATH,5,-345.9421,-4177.107,152.2871,0,0,0,0,100,0),
(@PATH,6,-346.2449,-4195.276,152.2244,0,0,0,0,100,0),
(@PATH,7,-345.7937,-4206.436,152.1899,0,0,0,0,100,0),
(@PATH,8,-341.1774,-4208.535,152.0649,0,0,0,0,100,0),
(@PATH,9,-337.7476,-4206.129,152.1899,0,3000,0,0,100,0),
(@PATH,10,-341.1774,-4208.535,152.0649,0,0,0,0,100,0),
(@PATH,11,-345.7937,-4206.436,152.1899,0,0,0,0,100,0),
(@PATH,12,-346.2449,-4195.276,152.2244,0,7000,0,0,100,0),
(@PATH,13,-345.9421,-4177.107,152.2871,0,0,0,0,100,0),
(@PATH,14,-339.8373,-4147.746,152.1256,0,0,0,0,100,0),
(@PATH,15,-333.2237,-4134.225,152.0622,0,0,0,0,100,0),
(@PATH,16,-334.7697,-4118.176,152.1513,0,0,0,0,100,0);

-- Pathing for Green Sludge Entry: 2655
SET @NPC := 92995;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=367.4861,`position_y`=-3892.534,`position_z`=103.3926 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,362.0923,-3869.861,106.0149,0,0,0,0,100,0),
(@PATH,2,359.729,-3842.23,107.0658,0,0,0,0,100,0),
(@PATH,3,362.0923,-3869.861,106.0149,0,0,0,0,100,0),
(@PATH,4,367.4861,-3892.534,103.3926,0,0,0,0,100,0),
(@PATH,5,388.8041,-3900.64,99.87824,0,0,0,0,100,0),
(@PATH,6,399.8027,-3882.644,97.61748,0,0,0,0,100,0),
(@PATH,7,390.798,-3860.872,95.97817,0,0,0,0,100,0),
(@PATH,8,379.3473,-3843.385,96.72575,0,0,0,0,100,0),
(@PATH,9,389.2842,-3825.799,98.92686,0,0,0,0,100,0),
(@PATH,10,399.2549,-3789.222,102.3659,0,0,0,0,100,0),
(@PATH,11,389.2842,-3825.799,98.92686,0,0,0,0,100,0),
(@PATH,12,379.3473,-3843.385,96.72575,0,0,0,0,100,0),
(@PATH,13,390.7259,-3860.698,95.98909,0,0,0,0,100,0),
(@PATH,14,399.8027,-3882.644,97.61748,0,0,0,0,100,0),
(@PATH,15,388.8041,-3900.64,99.87824,0,0,0,0,100,0),
(@PATH,16,367.4861,-3892.534,103.3926,0,0,0,0,100,0);

-- Pathing for Jade Ooze Entry: 2656
SET @NPC := 93068;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=386.5382,`position_y`=-3767.701,`position_z`=103.1262 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,382.7473,-3754.237,102.4903,0,0,0,0,100,0),
(@PATH,2,376.4646,-3738.252,105.2092,0,0,0,0,100,0),
(@PATH,3,365.8063,-3725.304,105.9001,0,0,0,0,100,0),
(@PATH,4,348.4052,-3720.816,105.9374,0,0,0,0,100,0),
(@PATH,5,319.9912,-3724.497,106.8615,0,0,0,0,100,0),
(@PATH,6,312.3986,-3744.087,106.7072,0,0,0,0,100,0),
(@PATH,7,318.8742,-3761.253,106.802,0,0,0,0,100,0),
(@PATH,8,343.6207,-3757.014,106.9888,0,0,0,0,100,0),
(@PATH,9,318.8742,-3761.253,106.802,0,0,0,0,100,0),
(@PATH,10,312.3907,-3744.138,106.7072,0,0,0,0,100,0),
(@PATH,11,319.9912,-3724.497,106.8615,0,0,0,0,100,0), 
(@PATH,12,348.4052,-3720.816,105.9374,0,0,0,0,100,0),
(@PATH,13,365.8063,-3725.304,105.9001,0,0,0,0,100,0),
(@PATH,14,376.4646,-3738.252,105.2092,0,0,0,0,100,0),
(@PATH,15,382.7473,-3754.237,102.4903,0,0,0,0,100,0),
(@PATH,16,386.5382,-3767.701,103.1262,0,0,0,0,100,0),
(@PATH,17,398.7607,-3775.05,102.3659,0,0,0,0,100,0),
(@PATH,18,403.8524,-3788.918,102.2382,0,0,0,0,100,0),
(@PATH,19,398.7607,-3775.05,102.3659,0,0,0,0,100,0),
(@PATH,20,386.5382,-3767.701,103.1262,0,0,0,0,100,0);

-- Pathing for Green Sludge Entry: 2655
SET @NPC := 93068;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=353.2792,`position_y`=-3775.147,`position_z`=126.7992 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,337.8778,-3781.475,127.0284,0,0,0,0,100,0),
(@PATH,2,348.2281,-3797.657,127.2243,0,0,0,0,100,0),
(@PATH,3,337.8778,-3781.475,127.0284,0,0,0,0,100,0),
(@PATH,4,353.2792,-3775.147,126.7992,0,0,0,0,100,0),
(@PATH,5,360.8041,-3764.615,126.8099,0,0,0,0,100,0),
(@PATH,6,384.1081,-3758.339,126.8203,0,0,0,0,100,0),
(@PATH,7,398.6287,-3760.762,126.0662,0,0,0,0,100,0),
(@PATH,8,421.6737,-3776.188,122.9383,0,0,0,0,100,0),
(@PATH,9,439.5612,-3795.414,120.8122,0,0,0,0,100,0),
(@PATH,10,416.8036,-3816.887,120.3546,0,0,0,0,100,0),
(@PATH,11,400.8517,-3822.608,118.5542,0,0,0,0,100,0),
(@PATH,12,381.2686,-3822.9,114.8412,0,0,0,0,100,0),
(@PATH,13,372.0157,-3806.465,111.9946,0,0,0,0,100,0),
(@PATH,14,363.0406,-3792.427,111.5014,0,0,0,0,100,0),
(@PATH,15,374.681,-3774.967,106.5569,0,0,0,0,100,0),
(@PATH,16,363.0406,-3792.427,111.5014,0,0,0,0,100,0),
(@PATH,17,372.0157,-3806.465,111.9946,0,0,0,0,100,0),
(@PATH,18,381.2686,-3822.9,114.8412,0,0,0,0,100,0),
(@PATH,19,400.8517,-3822.608,118.5542,0,0,0,0,100,0),
(@PATH,20,416.8036,-3816.887,120.3546,0,0,0,0,100,0),
(@PATH,21,439.5612,-3795.414,120.8122,0,0,0,0,100,0),
(@PATH,22,421.6737,-3776.188,122.9383,0,0,0,0,100,0),
(@PATH,23,398.6287,-3760.762,126.0662,0,0,0,0,100,0),
(@PATH,24,384.1081,-3758.339,126.8203,0,0,0,0,100,0),
(@PATH,25,360.8041,-3764.615,126.8099,0,0,0,0,100,0),
(@PATH,26,353.2792,-3775.147,126.7992,0,0,0,0,100,0);

-- Pathing for Vilebranch Warrior Entry: 4465
SET @NPC := 93742;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-300.8814,`position_y`=-4190.363,`position_z`=136.5622 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-299.2402,-4199.432,136.8216,0,0,0,0,100,0),
(@PATH,2,-294.703,-4206.721,136.5972,0,0,0,0,100,0),
(@PATH,3,-284.916,-4203.682,136.7266,0,0,0,0,100,0),
(@PATH,4,-281.4611,-4198.692,136.5716,0,0,0,0,100,0),
(@PATH,5,-278.4128,-4187.48,136.5716,0,0,0,0,100,0),
(@PATH,6,-279.7527,-4179.343,136.4959,0,0,0,0,100,0),
(@PATH,7,-282.9599,-4172.346,136.5655,0,0,0,0,100,0),
(@PATH,8,-291.1088,-4159.861,136.5396,0,0,0,0,100,0),
(@PATH,9,-296.5112,-4150.362,136.5396,0,0,0,0,100,0),
(@PATH,10,-297.4698,-4136.667,136.5396,0,0,0,0,100,0),
(@PATH,11,-296.116,-4127.808,136.4748,0,0,0,0,100,0),
(@PATH,12,-287.9145,-4123.469,136.6125,0,0,0,0,100,0),
(@PATH,13,-276.8211,-4123.947,137.0688,0,0,0,0,100,0),
(@PATH,14,-268.0964,-4124.016,135.5265,0,0,0,0,100,0),
(@PATH,15,-259.8373,-4124.032,128.8418,0,0,0,0,100,0),
(@PATH,16,-253.119,-4123.896,124.6126,0,0,0,0,100,0),
(@PATH,17,-245.0412,-4124.756,119.3458,0,0,0,0,100,0),
(@PATH,18,-231.2207,-4124.845,117.8142,0,0,0,0,100,0),
(@PATH,19,-213.4383,-4132.925,118.0337,0,0,0,0,100,0),
(@PATH,20,-231.2207,-4124.845,117.8142,0,0,0,0,100,0),
(@PATH,21,-245.0412,-4124.756,119.3458,0,0,0,0,100,0),
(@PATH,22,-253.119,-4123.896,124.6126,0,0,0,0,100,0),
(@PATH,23,-259.8373,-4124.032,128.8418,0,0,0,0,100,0),
(@PATH,24,-268.0964,-4124.016,135.5265,0,0,0,0,100,0),
(@PATH,25,-276.8211,-4123.947,137.0688,0,0,0,0,100,0),
(@PATH,26,-287.9145,-4123.469,136.6125,0,0,0,0,100,0),
(@PATH,27,-296.116,-4127.808,136.4748,0,0,0,0,100,0),
(@PATH,28,-297.4698,-4136.667,136.5396,0,0,0,0,100,0),
(@PATH,29,-296.5112,-4150.362,136.5396,0,0,0,0,100,0),
(@PATH,30,-291.1088,-4159.861,136.5396,0,0,0,0,100,0),
(@PATH,31,-282.9599,-4172.346,136.5655,0,0,0,0,100,0),
(@PATH,32,-279.7527,-4179.343,136.4959,0,0,0,0,100,0),
(@PATH,33,-278.4128,-4187.48,136.5716,0,0,0,0,100,0),
(@PATH,34,-281.4611,-4198.692,136.5716,0,0,0,0,100,0),
(@PATH,35,-284.916,-4203.682,136.7266,0,0,0,0,100,0),
(@PATH,36,-294.703,-4206.721,136.5972,0,0,0,0,100,0),
(@PATH,37,-299.2402,-4199.432,136.8216,0,0,0,0,100,0),
(@PATH,38,-300.8814,-4190.363,136.5622,0,0,0,0,100,0);

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=6059 AND `text_id`=7211;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (6059,7211);
DELETE FROM `gossip_menu` WHERE `entry`=6087 AND `text_id`=7241;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (6087,7241);
DELETE FROM `gossip_menu` WHERE `entry`=6088 AND `text_id`=7242;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (6088,7242);
DELETE FROM `gossip_menu` WHERE `entry`=6086 AND `text_id`=7240;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (6086,7240);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=6059 WHERE `entry`=14731;
UPDATE `creature_template` SET `gossip_menu_id`=6087 WHERE `entry`=14740;
UPDATE `creature_template` SET `gossip_menu_id`=6088 WHERE `entry`=14741;
UPDATE `creature_template` SET `gossip_menu_id`=6086 WHERE `entry`=14739;

-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (6059,6087,6086) AND `id` IN (0);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (6059,6087) AND `id` IN (1);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(6059,0,5, 'Make this inn your home.',8,65536,0,0,0,0, ''),
(6059,1,1, 'Let me browse your goods.',3,128,0,0,0,0, ''),
(6087,0,1, 'I would like to buy from you.',3,128,0,0,0,0, ''),
(6087,1,3, 'What can you teach me?',5,16,0,0,0,0, ''),
(6086,0,1, 'I would like to buy from you.',3,128,0,0,0,0, '');

