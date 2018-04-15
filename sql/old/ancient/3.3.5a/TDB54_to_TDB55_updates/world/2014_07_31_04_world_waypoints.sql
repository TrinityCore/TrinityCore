-- Misc fixes Shadowmoon Vally
UPDATE `waypoint_data` SET `move_type`=1 WHERE `id` BETWEEN 755410 AND 755580;
UPDATE `waypoint_data` SET `move_type`=1 WHERE `id` IN (861030,756540);
UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `id`=20431;
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=20431;

-- Pathing for Eclipsion Bloodwarder Entry: 19806
SET @NPC := 70924;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4360.784,`position_y`=1629.075,`position_z`=155.2385 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,20937, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4360.784,1629.075,155.2385,0,0,0,0,100,0),
(@PATH,2,-4353.151,1625.602,154.0825,0,0,0,0,100,0),
(@PATH,3,-4340.475,1615.389,150.8357,0,0,0,0,100,0),
(@PATH,4,-4325.918,1602.077,146.8105,0,0,0,0,100,0),
(@PATH,5,-4320.001,1595.513,145.2775,0,0,0,0,100,0),
(@PATH,6,-4294.648,1561.691,139.0124,0,0,0,0,100,0),
(@PATH,7,-4284.038,1547.906,136.9253,0,0,0,0,100,0),
(@PATH,8,-4279.678,1538.484,135.8952,0,0,0,0,100,0),
(@PATH,9,-4270.082,1526.787,133.6908,0,0,0,0,100,0),
(@PATH,10,-4279.678,1538.484,135.8952,0,0,0,0,100,0),
(@PATH,11,-4284.038,1547.906,136.9253,0,0,0,0,100,0),
(@PATH,12,-4294.648,1561.691,139.0124,0,0,0,0,100,0),
(@PATH,13,-4320.001,1595.513,145.2775,0,0,0,0,100,0),
(@PATH,14,-4325.918,1602.077,146.8105,0,0,0,0,100,0),
(@PATH,15,-4340.475,1615.389,150.8357,0,0,0,0,100,0),
(@PATH,16,-4353.151,1625.602,154.0825,0,0,0,0,100,0);

-- Pathing for Eclipsion Bloodwarder Entry: 19806
SET @NPC := 70923;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4217.18,`position_y`=1521.898,`position_z`=121.213 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,20937, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4217.18,1521.898,121.213,0,0,0,0,100,0),
(@PATH,2,-4229.042,1525.221,124.0835,0,0,0,0,100,0),
(@PATH,3,-4240.368,1525.119,126.9637,0,0,0,0,100,0),
(@PATH,4,-4251.378,1522.142,129.3019,0,0,0,0,100,0),
(@PATH,5,-4259.183,1521.705,131.0701,0,0,0,0,100,0),
(@PATH,6,-4265.086,1523.241,132.4467,0,0,0,0,100,0),
(@PATH,7,-4259.285,1521.729,130.9489,0,0,0,0,100,0),
(@PATH,8,-4251.378,1522.142,129.3019,0,0,0,0,100,0),
(@PATH,9,-4240.368,1525.119,126.9637,0,0,0,0,100,0),
(@PATH,10,-4229.367,1525.216,124.1498,0,0,0,0,100,0),
(@PATH,11,-4217.18,1521.898,121.213,0,0,0,0,100,0),
(@PATH,12,-4208.12,1518.035,119.0382,0,0,0,0,100,0),
(@PATH,13,-4186.46,1515.448,114.3116,0,0,0,0,100,0),
(@PATH,14,-4179.203,1518.327,112.6954,0,0,0,0,100,0),
(@PATH,15,-4173.099,1522.57,111.3765,0,0,0,0,100,0),
(@PATH,16,-4163.668,1521.306,109.0289,0,0,0,0,100,0),
(@PATH,17,-4145.619,1515.821,104.8259,0,0,0,0,100,0),
(@PATH,18,-4133.985,1513.434,101.7857,0,0,0,0,100,0),
(@PATH,19,-4121.424,1515.415,99.44949,0,0,0,0,100,0),
(@PATH,20,-4113.421,1518.041,98.23904,0,0,0,0,100,0),
(@PATH,21,-4121.424,1515.415,99.44949,0,0,0,0,100,0),
(@PATH,22,-4133.985,1513.434,101.7857,0,0,0,0,100,0),
(@PATH,23,-4145.619,1515.821,104.8259,0,0,0,0,100,0),
(@PATH,24,-4163.668,1521.306,109.0289,0,0,0,0,100,0),
(@PATH,25,-4173.099,1522.57,111.3765,0,0,0,0,100,0),
(@PATH,26,-4179.203,1518.327,112.6954,0,0,0,0,100,0),
(@PATH,27,-4186.46,1515.448,114.3116,0,0,0,0,100,0),
(@PATH,28,-4208.12,1518.035,119.0382,0,0,0,0,100,0);

-- Pathing for Eclipsion Centurion Entry: 19792
SET @NPC := 70813;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4172.616,`position_y`=1491.763,`position_z`=115.0119 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4172.616,1491.763,115.0119,0,0,0,0,100,0),
(@PATH,2,-4137.529,1488.114,107.3583,0,0,0,0,100,0),
(@PATH,3,-4101.359,1478.424,98.54732,0,0,0,0,100,0),
(@PATH,4,-4137.529,1488.114,107.3583,0,0,0,0,100,0),
(@PATH,5,-4172.616,1491.763,115.0119,0,0,0,0,100,0),
(@PATH,6,-4203.639,1494.258,121.3947,0,0,0,0,100,0);

-- Pathing for Eclipsion Centurion Entry: 19792
SET @NPC := 70819;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4215.104,`position_y`=1564.346,`position_z`=118.4787 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4215.104,1564.346,118.4787,0,0,0,0,100,0),
(@PATH,2,-4180.447,1555.489,110.1809,0,0,0,0,100,0),
(@PATH,3,-4156.682,1546.285,106.5436,0,0,0,0,100,0),
(@PATH,4,-4126.055,1537.171,99.63662,0,0,0,0,100,0),
(@PATH,5,-4089.762,1532.374,93.84246,0,0,0,0,100,0),
(@PATH,6,-4126.055,1537.171,99.63662,0,0,0,0,100,0),
(@PATH,7,-4156.682,1546.285,106.5436,0,0,0,0,100,0),
(@PATH,8,-4180.447,1555.489,110.1809,0,0,0,0,100,0);

-- Pathing for Eclipsion Centurion Entry: 19792
SET @NPC := 70818;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4234.924,`position_y`=1547.492,`position_z`=126.5343 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4234.924,1547.492,126.5343,0,0,0,0,100,0),
(@PATH,2,-4265.908,1569.376,133.2798,0,0,0,0,100,0),
(@PATH,3,-4281.013,1599.981,133.654,0,0,0,0,100,0),
(@PATH,4,-4302.111,1633.574,134.6775,0,0,0,0,100,0),
(@PATH,5,-4315.956,1670.131,135.9053,0,0,0,0,100,0),
(@PATH,6,-4302.111,1633.574,134.6775,0,0,0,0,100,0),
(@PATH,7,-4281.013,1599.981,133.654,0,0,0,0,100,0),
(@PATH,8,-4265.908,1569.376,133.2798,0,0,0,0,100,0);

-- Pathing for Eclipsion Centurion Entry: 19792
SET @NPC := 45146;
SET @PATH := @NPC * 10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@NPC,19792,530,1,1,-4300.741,1528.299,145.3227,6.021386,300,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4300.741,1528.299,145.3227,0,0,0,0,100,0),
(@PATH,2,-4267.303,1506.346,137.3165,0,0,0,0,100,0),
(@PATH,3,-4234.437,1486.09,127.7667,0,0,0,0,100,0),
(@PATH,4,-4266.797,1506.019,137.5665,0,0,0,0,100,0),
(@PATH,5,-4300.741,1528.299,145.3227,0,0,0,0,100,0),
(@PATH,6,-4333.723,1549.17,154.284,0,0,0,0,100,0),
(@PATH,7,-4365.854,1562.435,160.9441,0,0,0,0,100,0),
(@PATH,8,-4333.708,1549.164,154.1973,0,0,0,0,100,0);
