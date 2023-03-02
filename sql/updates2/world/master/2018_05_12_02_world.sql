-- 
SET @GUID := 68274;

-- Pathing for Mechagnome Laborer Entry: 29389
SET @NPC := @GUID;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7910.65,`position_y`=-1418.727,`position_z`=1534.705 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7910.65,-1418.727,1534.705,0,0,0,0,100,0),
(@PATH,2,7913.654,-1426.635,1534.705,0,0,0,0,100,0),
(@PATH,3,7920.053,-1414.188,1534.705,0,0,0,0,100,0),
(@PATH,4,7922.347,-1395.791,1534.705,0,0,0,0,100,0),
(@PATH,5,7920.222,-1386.216,1534.705,0,0,0,0,100,0),
(@PATH,6,7923.166,-1385.087,1534.705,0,0,0,0,100,0),
(@PATH,7,7916.864,-1385.485,1534.705,0,0,0,0,100,0),
(@PATH,8,7916.226,-1392.192,1534.705,0,0,0,0,100,0),
(@PATH,9,7911.995,-1404.557,1534.705,0,0,0,0,100,0);

-- Pathing for Mechagnome Laborer Entry: 29389
SET @NPC := @GUID+1;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7868.562,`position_y`=-1363.65,`position_z`=1534.059 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7868.562,-1363.65,1534.059,0,0,0,0,100,0),
(@PATH,2,7879.646,-1351.339,1534.705,0,0,0,0,100,0),
(@PATH,3,7868.222,-1355.34,1534.705,0,0,0,0,100,0),
(@PATH,4,7851.979,-1359.603,1534.705,0,0,0,0,100,0),
(@PATH,5,7840.327,-1375.057,1534.059,0,0,0,0,100,0),
(@PATH,6,7843.573,-1379.135,1534.059,0,0,0,0,100,0),
(@PATH,7,7830.217,-1389.011,1534.366,0,0,0,0,100,0),
(@PATH,8,7825.899,-1405.483,1534.705,0,0,0,0,100,0),
(@PATH,9,7846.697,-1416.326,1534.059,0,0,0,0,100,0),
(@PATH,10,7849.118,-1427.04,1534.059,0,0,0,0,100,0),
(@PATH,11,7848.421,-1411.426,1534.059,0,0,0,0,100,0),
(@PATH,12,7845.131,-1389.869,1534.059,0,0,0,0,100,0),
(@PATH,13,7859.611,-1375.139,1534.059,0,0,0,0,100,0);

-- Pathing for Mechagnome Laborer Entry: 29389
SET @NPC := @GUID+2;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7900.394,`position_y`=-1481.597,`position_z`=1532.27 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7900.394,-1481.597,1532.27,0,0,0,0,100,0),
(@PATH,2,7921.518,-1469.935,1532.267,0,0,0,0,100,0),
(@PATH,3,7939.954,-1444.368,1532.134,0,0,0,0,100,0),
(@PATH,4,7915.613,-1432.221,1535.256,0,0,0,0,100,0),
(@PATH,5,7939.954,-1444.368,1532.134,0,0,0,0,100,0),
(@PATH,6,7921.518,-1469.935,1532.267,0,0,0,0,100,0),
(@PATH,7,7900.394,-1481.597,1532.27,0,0,0,0,100,0),
(@PATH,8,7875.807,-1482.918,1532.255,0,0,0,0,100,0),
(@PATH,9,7872.38,-1464.144,1534.557,0,0,0,0,100,0),
(@PATH,10,7875.807,-1482.918,1532.255,0,0,0,0,100,0);

-- Pathing for Mechagnome Laborer Entry: 29389
SET @NPC := @GUID+3;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7857.495,`position_y`=-1330.407,`position_z`=1534.557 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7857.495,-1330.407,1534.557,0,0,0,0,100,0),
(@PATH,2,7853.63,-1310.692,1532.1,0,0,0,0,100,0),
(@PATH,3,7832.517,-1312.412,1532.386,0,0,0,0,100,0),
(@PATH,4,7814.14,-1322.234,1532.386,0,0,0,0,100,0),
(@PATH,5,7795.604,-1339.547,1532.251,0,0,0,0,100,0),
(@PATH,6,7817.405,-1356.497,1535.256,0,0,0,0,100,0),
(@PATH,7,7804.852,-1402.777,1535.256,0,0,0,0,100,0),
(@PATH,8,7782.151,-1408.093,1532.063,0,0,0,0,100,0),
(@PATH,9,7804.852,-1402.777,1535.256,0,0,0,0,100,0),
(@PATH,10,7817.405,-1356.497,1535.256,0,0,0,0,100,0),
(@PATH,11,7795.604,-1339.547,1532.251,0,0,0,0,100,0),
(@PATH,12,7814.14,-1322.234,1532.386,0,0,0,0,100,0),
(@PATH,13,7832.517,-1312.412,1532.386,0,0,0,0,100,0),
(@PATH,14,7853.63,-1310.692,1532.1,0,0,0,0,100,0);

-- Pathing for Mechagnome Laborer Entry: 29389
SET @NPC := @GUID+4;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7309.224,`position_y`=-666.5821,`position_z`=784.8982 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7309.224,-666.5821,784.8982,0,0,0,0,100,0),
(@PATH,2,7309.142,-656.5869,784.8982,0,0,0,0,100,0),
(@PATH,3,7309.335,-647.4516,784.8982,0,0,0,0,100,0),
(@PATH,4,7309.67,-640.1229,784.8982,0,0,0,0,100,0),
(@PATH,5,7309.579,-631.7067,785.1652,0,0,0,0,100,0),
(@PATH,6,7309.624,-623.5741,785.4073,0,0,0,0,100,0),
(@PATH,7,7309.579,-631.7067,785.1652,0,0,0,0,100,0),
(@PATH,8,7309.67,-640.1229,784.8982,0,0,0,0,100,0),
(@PATH,9,7309.335,-647.4516,784.8982,0,0,0,0,100,0),
(@PATH,10,7309.142,-656.5869,784.8982,0,0,0,0,100,0),
(@PATH,11,7309.224,-666.5821,784.8982,0,0,0,0,100,0),
(@PATH,12,7309.377,-678.6055,785.1129,0,0,0,0,100,0),
(@PATH,13,7309.483,-688.7038,785.1492,0,0,0,0,100,0),
(@PATH,14,7309.378,-678.7083,785.1492,0,0,0,0,100,0);
