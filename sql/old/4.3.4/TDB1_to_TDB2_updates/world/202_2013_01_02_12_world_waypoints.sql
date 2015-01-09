-- Pathing for Dark Ritualist Entry: 34734
SET @NPC := 63124;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8508.912,`position_y`=1423.379,`position_z`=642.1677 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8508.912,1423.379,642.1677,0,0,0,100,0),
(@PATH,2,8515.332,1430.247,642.2927,0,0,0,100,0),
(@PATH,3,8523.013,1437.788,642.3946,0,0,0,100,0),
(@PATH,4,8526.778,1446.524,642.3687,0,0,0,100,0),
(@PATH,5,8530.59,1452.149,642.3568,0,0,0,100,0),
(@PATH,6,8534.38,1456.161,642.9715,0,0,0,100,0),
(@PATH,7,8530.59,1452.149,642.3568,0,0,0,100,0),
(@PATH,8,8526.778,1446.524,642.3687,0,0,0,100,0),
(@PATH,9,8523.013,1437.788,642.3946,0,0,0,100,0),
(@PATH,10,8515.332,1430.247,642.2927,0,0,0,100,0);

-- Pathing for Dark Ritualist Entry: 34734
SET @NPC := 62889;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8514.877,`position_y`=1673.441,`position_z`=646.5894 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8514.877,1673.441,646.5894,0,0,0,100,0),
(@PATH,2,8518.864,1693.484,645.4977,0,0,0,100,0),
(@PATH,3,8515.326,1712.451,643.958,0,0,0,100,0),
(@PATH,4,8518.864,1693.484,645.4977,0,0,0,100,0),
(@PATH,5,8514.877,1673.441,646.5894,0,0,0,100,0),
(@PATH,6,8510.175,1661.057,647.1356,0,0,0,100,0),
(@PATH,7,8504.302,1654.377,647.6522,0,0,0,100,0),
(@PATH,8,8499.16,1651.429,649.0247,0,0,0,100,0),
(@PATH,9,8504.302,1654.377,647.6522,0,0,0,100,0),
(@PATH,10,8510.175,1661.057,647.1356,0,0,0,100,0);

-- Pathing for Dark Ritualist Entry: 34734
SET @NPC := 62178;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8561.401,`position_y`=1416.401,`position_z`=643.1947 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8561.401,1416.401,643.1947,0,0,0,100,0),
(@PATH,2,8559.43,1405.359,643.6021,0,0,0,100,0),
(@PATH,3,8561.401,1416.401,643.1947,0,0,0,100,0),
(@PATH,4,8559.165,1427.087,642.582,0,0,0,100,0),
(@PATH,5,8558.565,1438.543,642.76,0,0,0,100,0),
(@PATH,6,8563.757,1448.488,643.133,0,0,0,100,0),
(@PATH,7,8558.565,1438.543,642.76,0,0,0,100,0),
(@PATH,8,8559.165,1427.087,642.582,0,0,0,100,0);

-- Pathing for Dark Ritualist Entry: 34734
SET @NPC := 62886;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8558.849,`position_y`=1638.248,`position_z`=642.7181 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8558.849,1638.248,642.7181,0,0,0,100,0),
(@PATH,2,8569.741,1643.606,643.0836,0,0,0,100,0),
(@PATH,3,8580.118,1650.653,643.5215,0,0,0,100,0),
(@PATH,4,8569.741,1643.606,643.0836,0,0,0,100,0),
(@PATH,5,8558.849,1638.248,642.7181,0,0,0,100,0),
(@PATH,6,8543.526,1634.698,642.6174,0,0,0,100,0),
(@PATH,7,8527.557,1636.082,642.7275,0,0,0,100,0),
(@PATH,8,8543.526,1634.698,642.6174,0,0,0,100,0);

-- Pathing for Swift Alliance Steed Entry: 35808
SET @NPC := 85115;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8541.001,`position_y`=980.2708,`position_z`=547.4177 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8541.001,980.2708,547.4177,0,1000,0,0,100,0),
(@PATH,2,8541.001,980.2708,547.4177,1.064651,21000,0,0,100,0),
(@PATH,3,8538.89,981.222,547.4177,0,13000,0,51,100,0);

DELETE FROM `waypoint_scripts` WHERE `id`=51;
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`guid`) VALUES
(51,1,1,402,0,70);

-- Missing spawns Swift Horde Wolf
SET @GUID := 148; -- 4.x
DELETE FROM `creature` WHERE `guid` IN (@GUID,@GUID+1);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,36223,571,1,1,0,0,8540.497,986.4167,547.4177,0.01343229,120,0,0,1,0,0),
(@GUID+1,36223,571,1,1,0,0,8533.108,985.1597,547.3926,0.6806784,120,0,0,1,0,0);

-- Pathing for Swift Horde Wolf Entry: 36223
SET @NPC := 148;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8537.03,`position_y`=986.37,`position_z`=547.4177 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8537.03,986.37,547.4177,0,13000,0,52,100,0),
(@PATH,2,8540.497,986.4167,547.4177,0,0,0,0,100,0),
(@PATH,3,8540.497,986.4167,547.4177,5.462881,37000,0,0,100,0);

DELETE FROM `waypoint_scripts` WHERE `id`=52;
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`guid`) VALUES
(52,2,1,418,1,71),
(52,10,1,0,1,72);

-- Pathing for Argent Custodian Entry: 36069
SET @NPC := 85131;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8515.2,`position_y`=746.3889,`position_z`=575.785 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8515.2,746.3889,575.785,0,0,0,100,0),
(@PATH,2,8497.708,749.8507,575.7857,0,0,0,100,0);

-- Pathing for Argent Custodian Entry: 36069
SET @NPC := 85130;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8481.823,`position_y`=791.7691,`position_z`=558.5565 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8481.823,791.7691,558.5565,0,0,0,100,0),
(@PATH,2,8485.347,778.4419,558.5739,0,0,0,100,0),
(@PATH,3,8490.990,769.2891,558.5689,0,0,0,100,0),
(@PATH,4,8502.299,762.0498,558.5673,0,0,0,100,0),
(@PATH,5,8515.458,759.0677,558.5405,0,0,0,100,0),
(@PATH,6,8528.095,762.0035,558.5671,0,0,0,100,0),
(@PATH,7,8539.435,769.0851,558.5685,0,0,0,100,0),
(@PATH,8,8545.628,779.4549,558.5715,0,0,0,100,0),
(@PATH,9,8548.36,792.8768,558.5598,0,0,0,100,0),
(@PATH,10,8545.584,805.2761,558.5731,0,0,0,100,0),
(@PATH,11,8537.013,818.8125,558.5636,0,0,0,100,0),
(@PATH,12,8515.279,820.3889,558.1152,0,0,0,100,0),
(@PATH,13,8493.552,818.8524,558.5643,0,0,0,100,0),
(@PATH,14,8484.993,804.7049,558.5677,0,0,0,100,0);

-- Pathing for Kvaldir Reaver Entry: 34838
SET @NPC := 52604;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=10213.43,`position_y`=785.3785,`position_z`=65.56143 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,10213.43,785.3785,65.56143,0,0,0,100,0),
(@PATH,2,10203.03,791.2552,62.39041,0,0,0,100,0),
(@PATH,3,10192.28,799.4097,57.93019,0,0,0,100,0),
(@PATH,4,10181.2,816.316,52.61528,0,0,0,100,0),
(@PATH,5,10170.49,831.2708,47.18571,0,0,0,100,0),
(@PATH,6,10181.2,816.316,52.61528,0,0,0,100,0),
(@PATH,7,10192.28,799.4097,57.93019,0,0,0,100,0),
(@PATH,8,10203.03,791.2552,62.39041,0,0,0,100,0),
(@PATH,9,10213.43,785.3785,65.56143,0,0,0,100,0),
(@PATH,10,10224.06,785.1649,68.88577,0,0,0,100,0);

-- Missing spawns Mam'toth Disciple & Claw of Har'koa
SET @GUID := 83026;
DELETE FROM `creature` WHERE `guid` IN (@GUID,@GUID+1);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,28861,571,1,1,0,0,6320.923,-4130.368,458.9318,0.01343229,120,0,0,1,0,0),
(@GUID+1,28402,571,1,1,0,0,5493.606,-3712.333,362.6227,0.6806784,120,0,0,1,0,0);

-- Pathing for Mam'toth Disciple Entry: 28861
SET @NPC := 83026;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6320.923,`position_y`=-4130.368,`position_z`=458.9318 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '52574');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6320.923,-4130.368,458.9318,0,0,0,100,0),
(@PATH,2,6303.191,-4100.656,458.9318,0,0,0,100,0),
(@PATH,3,6275.148,-4083.311,458.9212,0,0,0,100,0),
(@PATH,4,6237.833,-4079.906,459.0136,0,0,0,100,0),
(@PATH,5,6215.262,-4070.717,459.0136,0,0,0,100,0),
(@PATH,6,6190.383,-4078.323,459.0136,0,0,0,100,0),
(@PATH,7,6174.816,-4074.354,459.0981,0,0,0,100,0),
(@PATH,8,6190.383,-4078.323,459.0136,0,0,0,100,0),
(@PATH,9,6215.262,-4070.717,459.0136,0,0,0,100,0),
(@PATH,10,6237.833,-4079.906,459.0136,0,0,0,100,0),
(@PATH,11,6275.148,-4083.311,458.9212,0,0,0,100,0),
(@PATH,12,6303.191,-4100.656,458.9318,0,0,0,100,0);

-- Pathing for Claw of Har'koa Entry: 28402
SET @NPC := 83027;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5493.606,`position_y`=-3712.333,`position_z`=362.6227 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5493.606,-3712.333,362.6227,0,0,0,100,0),
(@PATH,2,5488.515,-3736.998,361.9892,0,0,0,100,0),
(@PATH,3,5476.753,-3750.571,361.9892,0,0,0,100,0),
(@PATH,4,5461.006,-3767.059,362.002,0,0,0,100,0),
(@PATH,5,5443.998,-3774.203,361.9609,0,0,0,100,0),
(@PATH,6,5421.117,-3781.667,361.9677,0,0,0,100,0),
(@PATH,7,5398.986,-3767.582,361.9875,0,0,0,100,0),
(@PATH,8,5370.875,-3741.746,360.2243,0,0,0,100,0),
(@PATH,9,5354.693,-3725.205,360.0981,0,0,0,100,0),
(@PATH,10,5326.64,-3697.498,362.1892,0,0,0,100,0),
(@PATH,11,5322.16,-3670.425,362.0858,0,0,0,100,0),
(@PATH,12,5332.216,-3656.184,361.9609,0,0,0,100,0),
(@PATH,13,5356.117,-3639.557,361.9609,0,0,0,100,0),
(@PATH,14,5390.954,-3622.599,361.9609,0,0,0,100,0),
(@PATH,15,5416.427,-3639.384,361.9608,0,0,0,100,0),
(@PATH,16,5440.461,-3661.758,361.9644,0,0,0,100,0),
(@PATH,17,5468.425,-3688.130,361.9646,0,0,0,100,0);
