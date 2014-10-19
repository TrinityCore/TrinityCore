-- Missing Stormforged Taskmaster spawns
SET @GUID := 225;
DELETE FROM `creature` WHERE `guid` IN (@GUID,@GUID+1,@GUID+2);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,29369,571,1,1,0,1,7842.542,-110.6463,882.8068,5.88176,300,0,0,1,0,0),
(@GUID+1,29369,571,1,1,0,1,7827.683,-77.09928,882.7308,5.88176,300,0,0,1,0,0),
(@GUID+2,29369,571,1,1,0,1,7834.078,-130.5392,882.3082,5.88176,300,0,0,1,0,0);

-- Pathing for Stormforged Taskmaster Entry: 29369
SET @NPC := @GUID;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7842.542,`position_y`=-110.6463,`position_z`=882.8068 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7842.542,-110.6463,882.8068,0,0,0,0,100,0),
(@PATH,2,7839.237,-106.3565,882.6854,0,0,0,0,100,0),
(@PATH,3,7833.708,-100.7408,881.3173,0,0,0,0,100,0),
(@PATH,4,7827.768,-96.58257,881.0281,0,0,0,0,100,0),
(@PATH,5,7822.916,-90.53754,880.5125,0,0,0,0,100,0),
(@PATH,6,7822.845,-83.79515,881.5299,0,0,0,0,100,0),
(@PATH,7,7822.916,-90.48802,880.5093,0,0,0,0,100,0),
(@PATH,8,7827.694,-96.49003,881.0132,0,0,0,0,100,0),
(@PATH,9,7833.708,-100.7408,881.3173,0,0,0,0,100,0),
(@PATH,10,7839.095,-106.2119,882.6039,0,0,0,0,100,0);

-- Pathing for Stormforged Taskmaster Entry: 29369
SET @NPC := @GUID+1;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7827.683,`position_y`=-77.09928,`position_z`=882.7308 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7827.683,-77.09928,882.7308,0,0,0,0,100,0),
(@PATH,2,7824.653,-79.73319,882.5463,0,0,0,0,100,0),
(@PATH,3,7827.683,-77.09928,882.7308,0,0,0,0,100,0),
(@PATH,4,7832.377,-77.63552,881.9279,0,0,0,0,100,0),
(@PATH,5,7837.402,-75.31012,880.0537,0,0,0,0,100,0),
(@PATH,6,7832.377,-77.63552,881.9279,0,0,0,0,100,0);

-- Pathing for Stormforged Taskmaster Entry: 29369
SET @NPC := @GUID+2;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7842.921,`position_y`=-124.6453,`position_z`=880.9332 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7834.078,-130.5392,882.3082,0,0,0,0,100,0),
(@PATH,2,7842.921,-124.6453,880.9332,0,0,0,0,100,0),
(@PATH,3,7851.019,-120.6835,880.8082,0,0,0,0,100,0),
(@PATH,4,7856.965,-115.7509,881.3082,0,0,0,0,100,0),
(@PATH,5,7850.458,-124.2621,880.1832,0,0,0,0,100,0),
(@PATH,6,7856.965,-115.7509,881.3082,0,0,0,0,100,0),
(@PATH,7,7851.019,-120.6835,880.8082,0,0,0,0,100,0),
(@PATH,8,7842.921,-124.6453,880.9332,0,0,0,0,100,0);

-- Pathing for Stormforged Taskmaster Entry: 29369
SET @NPC := 113453;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7831.406,`position_y`=-36.4311,`position_z`=881.7036 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7831.406,-36.4311,881.7036,0,0,0,0,100,0),
(@PATH,2,7825.858,-41.52279,882.6611,0,0,0,0,100,0),
(@PATH,3,7825.452,-46.9974,881.7455,0,0,0,0,100,0),
(@PATH,4,7825.429,-52.69217,881.6854,0,0,0,0,100,0),
(@PATH,5,7829.174,-59.9388,881.8911,0,0,0,0,100,0),
(@PATH,6,7830.546,-64.68768,881.6604,0,0,0,0,100,0),
(@PATH,7,7829.176,-59.94751,881.8936,0,0,0,0,100,0),
(@PATH,8,7825.429,-52.69217,881.6854,0,0,0,0,100,0),
(@PATH,9,7825.452,-46.9974,881.7455,0,0,0,0,100,0),
(@PATH,10,7825.858,-41.52279,882.6611,0,0,0,0,100,0),
(@PATH,11,7831.406,-36.4311,881.7036,0,0,0,0,100,0),
(@PATH,12,7834.929,-35.81573,881.0314,0,0,0,0,100,0);

-- Pathing for Stormforged Taskmaster Entry: 29369
SET @NPC := 113454;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7806.823,`position_y`=-50.18902,`position_z`=883.4045 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7806.823,-50.18902,883.4045,0,0,0,0,100,0),
(@PATH,2,7810.619,-51.10297,883.5612,0,0,0,0,100,0),
(@PATH,3,7814.73,-51.17838,883.1161,0,0,0,0,100,0),
(@PATH,4,7818.904,-50.98427,882.5912,0,0,0,0,100,0),
(@PATH,5,7814.926,-51.18197,883.0936,0,0,0,0,100,0),
(@PATH,6,7810.619,-51.10297,883.5612,0,0,0,0,100,0),
(@PATH,7,7806.823,-50.18902,883.4045,0,0,0,0,100,0),
(@PATH,8,7802.53,-48.54416,883.1284,0,0,0,0,100,0),
(@PATH,9,7796.819,-50.17252,882.2547,0,0,0,0,100,0),
(@PATH,10,7802.53,-48.54416,883.1284,0,0,0,0,100,0);

-- Pathing for Stormforged Taskmaster Entry: 29369
SET @NPC := 113456;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7741.837,`position_y`=-35.62127,`position_z`=868.321 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7741.837,-35.62127,868.321,0,0,0,0,100,0),
(@PATH,2,7742.504,-41.76921,868.1025,0,0,0,0,100,0),
(@PATH,3,7745.919,-49.20704,869.4573,0,0,0,0,100,0),
(@PATH,4,7748.479,-53.62652,870.8617,0,0,0,0,100,0),
(@PATH,5,7745.919,-49.20704,869.4573,0,0,0,0,100,0),
(@PATH,6,7742.512,-41.78676,868.1014,0,0,0,0,100,0),
(@PATH,7,7741.922,-36.00348,868.2827,0,0,0,0,100,0),
(@PATH,8,7736.815,-27.02236,867.0229,0,0,0,0,100,0),
(@PATH,9,7730.213,-23.21951,867.5583,0,0,0,0,100,0),
(@PATH,10,7736.815,-27.02236,867.0229,0,0,0,0,100,0);

-- Pathing for Stormforged Taskmaster Entry: 29369
SET @NPC := 113455;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7755.479,`position_y`=-0.06315613,`position_z`=865.8619 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7755.479,-0.06315613,865.8619,0,0,0,0,100,0),
(@PATH,2,7761.083,1.82399,865.3038,0,0,0,0,100,0),
(@PATH,3,7766.307,-2.848633,864.6754,0,0,0,0,100,0),
(@PATH,4,7771.372,-8.783966,863.8624,0,0,0,0,100,0),
(@PATH,5,7776.645,-11.9133,863.2283,0,0,0,0,100,0),
(@PATH,6,7771.372,-8.783966,863.8624,0,0,0,0,100,0),
(@PATH,7,7766.307,-2.848633,864.6754,0,0,0,0,100,0),
(@PATH,8,7761.083,1.82399,865.3038,0,0,0,0,100,0),
(@PATH,9,7755.479,-0.06315613,865.8619,0,0,0,0,100,0),
(@PATH,10,7747.007,-1.096794,865.6259,0,0,0,0,100,0),
(@PATH,11,7738.89,-1.104057,866.1718,0,0,0,0,100,0),
(@PATH,12,7732.288,0.6400833,866.1253,0,0,0,0,100,0),
(@PATH,13,7726.064,0.6717682,867.4063,0,0,0,0,100,0),
(@PATH,14,7732.288,0.6400833,866.1253,0,0,0,0,100,0),
(@PATH,15,7738.89,-1.104057,866.1718,0,0,0,0,100,0),
(@PATH,16,7747.007,-1.096794,865.6259,0,0,0,0,100,0);
