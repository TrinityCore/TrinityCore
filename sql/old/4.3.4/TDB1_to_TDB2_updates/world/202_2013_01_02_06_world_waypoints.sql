-- Pathing for Commander Sarannis Entry: 17976
SET @NPC := 82986;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=125.7293,`position_y`=321.185,`position_z`=-3.635947 WHERE `guid`=@NPC;
DELETE FROM `creature_template_addon` WHERE `entry`=17976;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (17976,@PATH,1,0, '19818');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,125.7293,321.185,-3.635947,1000,0,0,100,0),
(@PATH,2,135.6253,311.316,-1.57836,0,0,0,100,0),
(@PATH,3,150.9637,296.034,-4.566956,1000,0,0,100,0),
(@PATH,4,135.6253,311.316,-1.57836,0,0,0,100,0);

-- Pathing for High Botanist Freywinn Entry: 17975
SET @NPC := 82987;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=116.3259,`position_y`=455.5696,`position_z`=-4.941401 WHERE `guid`=@NPC;
DELETE FROM `creature_template_addon` WHERE `entry`=17975;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (17975,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,116.3259,455.5696,-4.941401,3.385939,20000,0,0,100,0),
(@PATH,2,120.164,450.6817,-4.894922,0,500,0,0,100,0),
(@PATH,3,120.164,450.6817,-4.894922,4.555309,20000,0,0,100,0),
(@PATH,4,116.3259,455.5696,-4.941401,0,500,0,0,100,0);

-- Pathing for Bloodwarder Greenkeeper Entry: 18419
SET @NPC := 82994;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4.453328,`position_y`=252.8713,`position_z`=-5.396591 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4.453328,252.8713,-5.396591,0.06981317,10000,0,49,100,0),
(@PATH,2,-4.453328,252.8713,-5.396591,2.146755,19000,0,476,100,0);

-- Pathing for Bloodwarder Greenkeeper Entry: 18419
SET @NPC := 82993;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3.139327,`position_y`=253.476,`position_z`=-5.392399 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3.139327,253.476,-5.392399,3.141593,10000,0,49,100,0),
(@PATH,2,3.139327,253.476,-5.392399,0.9773844,19000,0,476,100,0);

DELETE FROM `waypoint_scripts` WHERE `id`=49;
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`guid`) VALUES
(49,1,1,378,1,68);

-- Pathing for Bloodwarder Greenkeeper Entry: 18419
SET @NPC := 82983;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2.213146,`position_y`=163.0322,`position_z`=-5.54038 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2.213146,163.0322,-5.54038,2.251475,26000,0,0,100,0),
(@PATH,2,-0.7086419,160.2672,-5.540373,0,0,0,0,100,0),
(@PATH,3,-4.294355,161.2607,-5.540364,0,0,0,0,100,0),
(@PATH,4,-6.205455,163.514,-5.54036,0,0,0,0,100,0),
(@PATH,5,-6.24241,166.6921,-5.540361,0,0,0,0,100,0),
(@PATH,6,-6.24241,166.6921,-5.540361,1.780236,18000,0,0,100,0),
(@PATH,7,-3.464332,161.0224,-5.540366,0,0,0,0,100,0),
(@PATH,8,0.992403,160.6039,-5.540379,0,0,0,0,100,0),
(@PATH,9,2.213146,163.0322,-5.54038,0,0,0,0,100,0);

-- Pathing for Bloodwarder Greenkeeper Entry: 18419
SET @NPC := 82977;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=13.11812,`position_y`=198.4727,`position_z`=-5.54039 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,13.11812,198.4727,-5.54039,0,0,0,0,100,0),
(@PATH,2,13.11812,198.4727,-5.54039,0.8552113,7000,0,0,100,0),
(@PATH,3,13.77349,194.1652,-5.540394,0,0,0,0,100,0),
(@PATH,4,17.34217,193.0448,-5.540406,0,0,0,0,100,0),
(@PATH,5,17.34217,193.0448,-5.540406,0.9424778,18000,0,0,100,0),
(@PATH,6,13.03814,196.0347,-5.540391,0,0,0,0,100,0);

-- Pathing for Bloodwarder Greenkeeper Entry: 18419
SET @NPC := 82981;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8.21974,`position_y`=204.3309,`position_z`=-5.540359 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8.21974,204.3309,-5.540359,3.560472,26000,0,0,100,0),
(@PATH,2,-7.085683,202.0462,-5.540362,0,0,0,0,100,0),
(@PATH,3,-10.7415,199.8233,-5.540348,0,0,0,0,100,0),
(@PATH,4,-12.49067,195.6114,-5.540347,0,0,0,0,100,0),
(@PATH,5,-16.42434,194.2959,-5.540349,0,0,0,0,100,0),
(@PATH,6,-19.61755,196.9462,-5.540346,0,0,0,0,100,0),
(@PATH,7,-19.61755,196.9462,-5.540346,1.361357,22000,0,0,100,0),
(@PATH,8,-16.42434,194.2959,-5.540349,0,0,0,0,100,0),
(@PATH,9,-10.83238,198.4772,-5.540348,0,0,0,0,100,0),
(@PATH,10,-7.085683,202.0462,-5.540362,0,0,0,0,100,0),
(@PATH,11,-8.21974,204.3309,-5.540359,0,0,0,0,100,0);

-- Pathing for Tempest-Forge Peacekeeper Entry: 18405
SET @NPC := 82992;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=14.39464,`position_y`=191.6226,`position_z`=-5.540398 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,14.39464,191.6226,-5.540398,0,0,0,100,0),
(@PATH,2,14.18493,177.3456,-5.540413,0,0,0,100,0),
(@PATH,3,14.39464,191.6226,-5.540398,0,0,0,100,0),
(@PATH,4,9.744885,197.8509,-5.540387,0,0,0,100,0),
(@PATH,5,-0.7083383,202.6878,-5.540373,0,0,0,100,0),
(@PATH,6,-0.863688,242.4021,-5.575537,0,0,0,100,0),
(@PATH,7,-0.771556,202.717,-5.540379,0,0,0,100,0),
(@PATH,8,9.744885,197.8509,-5.540387,0,0,0,100,0);

-- Pathing for Bloodfalcon Entry: 18155
SET @NPC := 83010;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=100.8468,`position_y`=280.3725,`position_z`=-6.887547 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,100.8468,280.3725,-6.887547,0,0,0,100,0),
(@PATH,2,77.20944,279.0805,-5.444278,0,0,0,100,0),
(@PATH,3,84.07146,264.8167,-5.424605,0,0,0,100,0),
(@PATH,4,92.04115,267.708,-5.393034,0,0,0,100,0),
(@PATH,5,99.9794,272.1951,-6.974396,0,0,0,100,0);

-- Pathing for Bloodfalcon Entry: 18155
SET @NPC := 83009;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=109.3741,`position_y`=279.2442,`position_z`=-6.94078 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,109.3741,279.2442,-6.94078,0,0,0,100,0),
(@PATH,2,106.6039,296.3932,-6.736755,0,0,0,100,0),
(@PATH,3,114.8603,296.713,-5.403351,0,0,0,100,0),
(@PATH,4,120.5567,289.947,-5.410193,0,0,0,100,0),
(@PATH,5,119.7589,278.0228,-5.423053,0,0,0,100,0),
(@PATH,6,114.742,276.3138,-6.998993,0,0,0,100,0);

-- Pathing for Bloodfalcon Entry: 18155
SET @NPC := 83008;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=101.2185,`position_y`=295.671,`position_z`=-6.719101 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,101.2185,295.671,-6.719101,0,0,0,100,0),
(@PATH,2,101.0785,294.0834,-6.736097,0,0,0,100,0),
(@PATH,3,99.73528,294.2418,-6.727928,0,0,0,100,0),
(@PATH,4,99.9539,294.9124,-6.721509,0,0,0,100,0),
(@PATH,5,101.4649,294.7929,-6.730046,0,0,0,100,0),
(@PATH,6,97.40523,292.5155,-6.736019,0,0,0,100,0),
(@PATH,7,99.61896,292.5375,-6.746336,0,0,0,100,0),
(@PATH,8,99.74017,296.1521,-6.706696,0,0,0,100,0),
(@PATH,9,98.21532,295.972,-6.701425,0,0,0,100,0),
(@PATH,10,100.0779,295.0646,-6.720407,0,0,0,100,0),
(@PATH,11,101.4872,291.8169,-6.763266,0,0,0,100,0),
(@PATH,12,99.03914,291.6151,-6.753832,0,0,0,100,0),
(@PATH,13,100.0113,293.701,-6.735262,0,0,0,100,0),
(@PATH,14,99.75899,294.4994,-6.725174,0,0,0,100,0),
(@PATH,15,99.56416,293.6588,-6.733598,0,0,0,100,0),
(@PATH,16,99.97965,293.2847,-6.739742,0,0,0,100,0);

-- Pathing for Bloodwarder Falconer Entry: 17994
SET @NPC := 83007;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=102.2101,`position_y`=287.5207,`position_z`=-6.814517 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,102.2101,287.5207,-6.814517,0,0,0,0,100,0),
(@PATH,2,102.5804,286.6708,-6.825739,0,0,0,0,100,0),
(@PATH,3,102.1126,287.9805,-6.808935,0,0,0,0,100,0),
(@PATH,4,103.0655,288.2263,-6.810746,0,0,0,0,100,0),
(@PATH,5,102.2138,287.1823,-6.818299,0,0,0,0,100,0),
(@PATH,6,100.6942,286.5314,-6.818292,0,0,0,0,100,0),
(@PATH,7,101.7873,287.9028,-6.808247,0,0,0,0,100,0),
(@PATH,8,101.8391,289.0352,-6.795895,0,0,0,0,100,0),
(@PATH,9,102.7853,288.8042,-6.802979,0,0,0,0,100,0),
(@PATH,10,102.7853,288.8042,-6.802979,0.8377581,3000,0,50,100,0),
(@PATH,11,102.208,288.0875,-6.808199,0,0,0,0,100,0),
(@PATH,12,103.2457,288.6324,-6.807087,0,0,0,0,100,0),
(@PATH,13,101.3874,289.0022,-6.794107,0,0,0,0,100,0),
(@PATH,14,102.0153,287.4591,-6.814272,0,0,0,0,100,0),
(@PATH,15,101.6863,285.8949,-6.830106,0,0,0,0,100,0),
(@PATH,16,103.6638,286.2337,-6.83577,0,0,0,0,100,0),
(@PATH,17,103.6638,286.2337,-6.83577,0.8377581,3000,0,50,100,0),
(@PATH,18,101.7167,286.4881,-6.823652,0,0,0,0,100,0),
(@PATH,19,102.2377,286.9568,-6.820922,0,0,0,0,100,0),
(@PATH,20,102.3838,285.2078,-6.841079,0,0,0,0,100,0),
(@PATH,21,102.3838,285.2078,-6.841079,0.8377581,3000,0,50,100,0);

DELETE FROM `waypoint_scripts` WHERE `id`=50;
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`guid`) VALUES
(50,0,1,25,0,69);

-- Pathing for Sunseeker Researcher Entry: 18421
SET @NPC := 83052;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=158.1747,`position_y`=496.2738,`position_z`=-3.868253 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,158.1747,496.2738,-3.868253,0,0,0,100,0),
(@PATH,2,156.1526,489.3673,-4.857466,0,0,0,100,0),
(@PATH,3,150.5289,483.8496,-4.521907,0,0,0,100,0),
(@PATH,4,138.1562,471.4412,-1.710583,0,0,0,100,0),
(@PATH,5,125.0919,458.282,-4.002612,25000,0,0,100,0),
(@PATH,6,136.7875,469.6367,-1.535325,0,0,0,100,0),
(@PATH,7,143.6099,477.3061,-2.875249,0,0,0,100,0),
(@PATH,8,151.2965,484.3168,-4.559049,0,0,0,100,0),
(@PATH,9,157.2852,490.9466,-4.815495,0,0,0,100,0),
(@PATH,10,159.9993,499.248,-2.327699,0,0,0,100,0),
(@PATH,11,164.1381,501.6526,-2.169621,25000,0,0,100,0);

-- Pathing for Sunseeker Botanist Entry: 18422
SET @NPC := 83017;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=161.3267,`position_y`=377.6318,`position_z`=-5.38641 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,161.3267,377.6318,-5.38641,0,0,0,0,100,0),
(@PATH,2,161.3267,377.6318,-5.38641,3.892084,25000,0,0,100,0),
(@PATH,3,164.7352,383.6933,-5.386415,0,0,0,0,100,0),
(@PATH,4,164.0884,388.1612,-5.386421,0,0,0,0,100,0),
(@PATH,5,161.8422,392.5251,-5.386427,0,0,0,0,100,0),
(@PATH,6,159.0437,394.9259,-5.386432,0,0,0,0,100,0),
(@PATH,7,154.6845,398.0776,-5.386438,0,0,0,0,100,0),
(@PATH,8,153.9412,401.8906,-5.386443,0,0,0,0,100,0),
(@PATH,9,153.9412,401.8906,-5.386443,0.9424778,25000,0,0,100,0),
(@PATH,10,155.4246,397.5377,-5.386436,0,0,0,0,100,0),
(@PATH,11,157.8206,395.4006,-5.386433,0,0,0,0,100,0),
(@PATH,12,160.7398,392.5124,-5.386428,0,0,0,0,100,0),
(@PATH,13,163.7198,388.017,-5.386421,0,0,0,0,100,0),
(@PATH,14,163.845,385.0679,-5.386418,0,0,0,0,100,0),
(@PATH,15,163.1142,380.8199,-5.386413,0,0,0,0,100,0);
-- 0xF13047F60000354E .go 161.3267 377.6318 -5.38641

-- Pathing for Sunseeker Botanist Entry: 18422
SET @NPC := 83030;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=185.3934,`position_y`=384.4199,`position_z`=-5.391479 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,185.3934,384.4199,-5.391479,0,0,0,0,100,0),
(@PATH,2,191.3777,384.4846,-5.404879,0,0,0,0,100,0),
(@PATH,3,191.3777,384.4846,-5.404879,0.7679449,25000,0,0,100,0),
(@PATH,4,186.8178,385.4778,-5.394615,0,0,0,0,100,0),
(@PATH,5,183.8889,388.4998,-5.3879,0,0,0,0,100,0),
(@PATH,6,182.7735,392.4268,-5.386416,0,0,0,0,100,0),
(@PATH,7,181.8264,397.8481,-5.386423,0,0,0,0,100,0),
(@PATH,8,177.4602,402.4377,-5.386431,0,0,0,0,100,0),
(@PATH,9,169.0016,404.7528,-5.386438,0,0,0,0,100,0),
(@PATH,10,161.5859,402.9305,-5.38644,0,0,0,0,100,0),
(@PATH,11,161.5859,402.9305,-5.38644,2.268928,25000,0,0,100,0),
(@PATH,12,165.1373,399.9031,-5.386434,0,0,0,0,100,0),
(@PATH,13,168.7618,399.839,-5.386432,0,0,0,0,100,0),
(@PATH,14,172.8151,400.5747,-5.386431,0,0,0,0,100,0),
(@PATH,15,177.9102,400.0075,-5.386427,0,0,0,0,100,0),
(@PATH,16,181.755,397.4692,-5.386423,0,0,0,0,100,0),
(@PATH,17,182.4747,393.0989,-5.386417,0,0,0,0,100,0),
(@PATH,18,183.0329,388.3197,-5.386411,0,0,0,0,100,0);

DELETE FROM `creature` WHERE `guid` IN (83022,83027,83023,83026);
