-- Pathing for  Entry: 40177 'TDB FORMAT' 
SET @NPC := 339785;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-512.6458,`position_y`=-468.7257,`position_z`=276.5972 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-512.6458,-468.7257,276.5972,0,0,0,0,100,0),
(@PATH,2,-492.2951,-479.1701,271.9152,0,0,0,0,100,0),
(@PATH,3,-472.2431,-499.691,271.9083,0,0,0,0,100,0),
(@PATH,4,-467.6163,-519.4114,271.9075,0,0,0,0,100,0),
(@PATH,5,-465.2691,-554.9739,271.9072,0,0,0,0,100,0),
(@PATH,6,-482.7118,-574.3004,271.9124,0,0,0,0,100,0),
(@PATH,7,-503.2309,-593.0121,276.5972,0,0,0,0,100,0),
(@PATH,8,-528.2952,-595.9375,276.6013,0,0,0,0,100,0),
(@PATH,9,-546.2274,-592.8055,276.5972,0,0,0,0,100,0),
(@PATH,10,-561.1875,-591.6719,276.5972,0,0,0,0,100,0),
(@PATH,11,-546.2274,-592.8055,276.5972,0,0,0,0,100,0),
(@PATH,12,-528.2952,-595.9375,276.6013,0,0,0,0,100,0),
(@PATH,13,-503.2309,-593.0121,276.5972,0,0,0,0,100,0),
(@PATH,14,-482.7118,-574.3004,271.9124,0,0,0,0,100,0),
(@PATH,15,-465.2691,-554.9739,271.9072,0,0,0,0,100,0),
(@PATH,16,-467.6163,-519.4114,271.9075,0,0,0,0,100,0),
(@PATH,17,-472.2431,-499.691,271.9083,0,0,0,0,100,0),
(@PATH,18,-492.2951,-479.1701,271.9152,0,0,0,0,100,0),
(@PATH,19,-512.6458,-468.7257,276.5972,0,0,0,0,100,0),
(@PATH,20,-532.632,-467.6181,276.5972,0,0,0,0,100,0),
(@PATH,21,-549.9549,-466.4288,276.5973,0,0,0,0,100,0),
(@PATH,22,-532.632,-467.6181,276.5972,0,0,0,0,100,0);
-- 0x243CC853C0273C40002ACA00002EBBC4 .go xyz -512.6458 -468.7257 276.5972

-- Pathing for  Entry: 39450 'TDB FORMAT' 
SET @NPC := 339864;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-550.238,`position_y`=-469.752,`position_z`=276.5973 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-550.238,-469.752,276.5973,0,0,0,0,100,0),
(@PATH,2,-531.828,-459.755,276.5972,0,0,0,0,100,0),
(@PATH,3,-511.859,-472.01,276.5972,0,0,0,0,100,0),
(@PATH,4,-492.087,-486.094,271.914,0,0,0,0,100,0),
(@PATH,5,-511.859,-472.01,276.5972,0,0,0,0,100,0),
(@PATH,6,-531.828,-459.755,276.5972,0,0,0,0,100,0),
(@PATH,7,-550.238,-469.752,276.5973,0,0,0,0,100,0),
(@PATH,8,-571.799,-479.387,276.5972,0,0,0,0,100,0),
(@PATH,9,-588.609,-475.16,276.8722,0,0,0,0,100,0);
-- 0x203CC853C0268680002ACA00072EBBC4 .go xyz -550.238 -469.752 276.5973

DELETE FROM `creature_formations` WHERE `leaderGUID`= 339864;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(339864, 339864, 0, 0, 515, 0, 0),
(339864, 339867, 3, 0, 515, 0, 0),
(339864, 339863, 3, 45, 515, 0, 0),
(339864, 339869, 3, 315, 515, 0, 0),
(339864, 339861, 3, 90, 515, 0, 0),
(339864, 339865, 3, 270, 515, 0, 0),
(339864, 339862, 3, 210, 515, 0, 0),
(339864, 339860, 3, 150, 515, 0, 0);

-- Pathing for  Entry: 39450 'TDB FORMAT' 
SET @NPC := 340044;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-534.641,`position_y`=-597.892,`position_z`=276.5972 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-534.641,-597.892,276.5972,0,0,0,0,100,0),
(@PATH,2,-513.95,-590.392,276.5965,0,0,0,0,100,0),
(@PATH,3,-488.979,-573.819,271.9133,0,0,0,0,100,0),
(@PATH,4,-513.95,-590.392,276.5965,0,0,0,0,100,0),
(@PATH,5,-534.641,-597.892,276.5972,0,0,0,0,100,0),
(@PATH,6,-552.561,-591.356,276.5972,0,0,0,0,100,0),
(@PATH,7,-576.5,-581.304,276.5972,0,0,0,0,100,0),
(@PATH,8,-592.226,-591.113,276.7903,0,0,0,0,100,0),
(@PATH,9,-611.21,-606.175,276.5812,0,0,0,0,100,0),
(@PATH,10,-622.96,-600.955,276.5808,0,0,0,0,100,0),
(@PATH,11,-631.622,-596.46,276.5824,0,0,0,0,100,0),
(@PATH,12,-640.967,-594.156,276.5701,0,0,0,0,100,0),
(@PATH,13,-622.96,-600.955,276.5808,0,0,0,0,100,0),
(@PATH,14,-611.21,-606.175,276.5812,0,0,0,0,100,0),
(@PATH,15,-592.226,-591.113,276.7903,0,0,0,0,100,0),
(@PATH,16,-576.5,-581.304,276.5972,0,0,0,0,100,0),
(@PATH,17,-552.561,-591.356,276.5972,0,0,0,0,100,0);
-- 0x203CC853C0268680002ACA00032EBBC4 .go xyz -534.641 -597.892 276.5972


DELETE FROM `creature_formations` WHERE `leaderGUID`= 340044;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(340044, 340044, 0, 0, 515, 0, 0),
(340044, 340046, 3, 180, 515, 0, 0),
(340044, 340048, 3, 135, 515, 0, 0),
(340044, 340041, 3, 225, 515, 0, 0),
(340044, 340047, 3, 90, 515, 0, 0),
(340044, 340038, 3, 270, 515, 0, 0),
(340044, 340045, 3, 30, 515, 0, 0),
(340044, 340040, 3, 330, 515, 0, 0);

-- Pathing for  Entry: 39873 'TDB FORMAT' 
SET @NPC := 340127;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-525.8577,`position_y`=-748.0295,`position_z`=268.7671 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-525.8577,-748.0295,268.7671,0,0,0,0,100,0),
(@PATH,2,-501.1424,-744.3351,268.7674,0,0,0,0,100,0),
(@PATH,3,-486.0469,-745.0121,268.7679,0,0,0,0,100,0),
(@PATH,4,-486.0469,-745.0121,268.7679,6.038839,0,0,0,100,0),
(@PATH,5,-502.8229,-745.2813,268.7674,0,0,0,0,100,0),
(@PATH,6,-524.0903,-746.5886,268.767,0,0,0,0,100,0),
(@PATH,7,-553.2274,-746.5382,268.7675,0,0,0,0,100,0);
-- 0x203CC853C026F040002ACA00002EBBC4 .go xyz -525.8577 -748.0295 268.7671


-- Pathing for  Entry: 39873 'TDB FORMAT' 
SET @NPC := 340088;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-612.868,`position_y`=-677.5382,`position_z`=268.7674 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-612.868,-677.5382,268.7674,0,0,0,0,100,0),
(@PATH,2,-617.8438,-672.3368,268.7674,0,0,0,0,100,0),
(@PATH,3,-623.9132,-669.3889,268.7674,0,0,0,0,100,0),
(@PATH,4,-633.5469,-669.5139,268.7674,0,0,0,0,100,0),
(@PATH,5,-633.5469,-669.5139,268.7674,2.286381,0,0,0,100,0),
(@PATH,6,-623.8281,-669.4653,268.7674,0,0,0,0,100,0),
(@PATH,7,-609.243,-679.1597,268.7675,0,0,0,0,100,0),
(@PATH,8,-595.9445,-689.0035,268.7668,0,0,0,0,100,0),
(@PATH,9,-571.4358,-694.1736,268.7674,0,0,0,0,100,0),
(@PATH,10,-595.4028,-687.6077,268.7667,0,0,0,0,100,0);
-- 0x203CC853C026F040002ACA00002EBBC5 .go xyz -612.868 -677.5382 268.7674

-- Pathing for  Entry: 39392 'TDB FORMAT' 
SET @NPC := 340214;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-691.3108,`position_y`=-809.2292,`position_z`=233.2342 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-691.3108,-809.2292,233.2342,0,0,0,0,100,0),
(@PATH,2,-708.2292,-796.4445,233.2314,0,0,0,0,100,0),
(@PATH,3,-736.1719,-798.6788,232.4155,0,0,0,0,100,0),
(@PATH,4,-753.6233,-809.4132,232.4127,0,0,0,0,100,0),
(@PATH,5,-744.7336,-803.9452,232.4118,0,0,0,0,100,0),
(@PATH,6,-753.6233,-809.4132,232.4127,0,0,0,0,100,0),
(@PATH,7,-736.1719,-798.6788,232.4155,0,0,0,0,100,0),
(@PATH,8,-708.2292,-796.4445,233.2314,0,0,0,0,100,0),
(@PATH,9,-708.2292,-796.4445,233.2314,0,0,0,0,100,0);
-- 0x203CC853C0267800002ACA00002EBBC4 .go xyz -691.3108 -809.2292 233.2342

-- Pathing for  Entry: 39392 'TDB FORMAT' 
SET @NPC := 340238;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-729.2153,`position_y`=-860.8663,`position_z`=232.4356 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-729.2153,-860.8663,232.4356,0,0,0,0,100,0),
(@PATH,2,-743.5746,-862.5833,232.4862,0,0,0,0,100,0),
(@PATH,3,-757.3143,-859.4028,233.229,0,0,0,0,100,0),
(@PATH,4,-752.991,-860.4036,232.9894,0,0,0,0,100,0),
(@PATH,5,-757.3143,-859.4028,233.229,0,0,0,0,100,0),
(@PATH,6,-769.8958,-849.0295,233.2121,0,0,0,0,100,0),
(@PATH,7,-757.3143,-859.4028,233.229,0,0,0,0,100,0),
(@PATH,8,-743.5746,-862.5833,232.4862,0,0,0,0,100,0),
(@PATH,9,-729.2153,-860.8663,232.4356,0,0,0,0,100,0),
(@PATH,10,-743.5746,-862.5833,232.4862,0,0,0,0,100,0),
(@PATH,11,-729.2153,-860.8663,232.4356,0,0,0,0,100,0),
(@PATH,12,-729.2153,-860.8663,232.4356,0,0,0,0,100,0),
(@PATH,13,-757.3143,-859.4028,233.229,0,0,0,0,100,0),
(@PATH,14,-743.5746,-862.5833,232.4862,0,0,0,0,100,0),
(@PATH,15,-729.2153,-860.8663,232.4356,0,0,0,0,100,0),
(@PATH,16,-706.9375,-851.2274,232.4799,0,0,0,0,100,0),
(@PATH,17,-729.2153,-860.8663,232.4356,0,0,0,0,100,0),
(@PATH,18,-743.5746,-862.5833,232.4862,0,0,0,0,100,0),
(@PATH,19,-757.3143,-859.4028,233.229,0,0,0,0,100,0),
(@PATH,20,-769.8958,-849.0295,233.2121,0,0,0,0,100,0),
(@PATH,21,-757.3143,-859.4028,233.229,0,0,0,0,100,0),
(@PATH,22,-743.5746,-862.5833,232.4862,0,0,0,0,100,0);
-- 0x203CC853C0267800002ACA0000AEBBC4 .go xyz -729.2153 -860.8663 232.4356
