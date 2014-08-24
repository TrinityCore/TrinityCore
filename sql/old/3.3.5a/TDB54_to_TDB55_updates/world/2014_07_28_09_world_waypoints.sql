-- [ph] bat target & [ph] cave bat
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (22039,22040);

-- Pathing for Mature Cavern Crawler Entry: 22132
SET @NPC := 77719;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1236.683,`position_y`=6974.834,`position_z`=86.52148 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1236.683,6974.834,86.52148,0,0,0,0,100,0),
(@PATH,2,1213.585,6994.503,96.45895,0,0,0,0,100,0),
(@PATH,3,1191.594,7009.763,104.1238,0,0,0,0,100,0),
(@PATH,4,1179.399,7021.068,106.6655,0,0,0,0,100,0),
(@PATH,5,1191.594,7009.763,104.1238,0,0,0,0,100,0),
(@PATH,6,1213.585,6994.503,96.45895,0,0,0,0,100,0),
(@PATH,7,1236.552,6974.855,86.55492,0,0,0,0,100,0),
(@PATH,8,1259.068,6971.35,87.20951,0,0,0,0,100,0),
(@PATH,9,1302.526,6966.913,92.38039,0,0,0,0,100,0),
(@PATH,10,1315.864,6961.601,92.83173,0,0,0,0,100,0),
(@PATH,11,1328.682,6944.249,93.1772,0,0,0,0,100,0),
(@PATH,12,1334.158,6919.819,94.02305,0,0,0,0,100,0),
(@PATH,13,1341.481,6899.75,94.77781,0,0,0,0,100,0),
(@PATH,14,1355.231,6884.747,95.21254,0,0,0,0,100,0),
(@PATH,15,1373.986,6866.587,97.52299,0,0,0,0,100,0),
(@PATH,16,1390.79,6861.882,102.2583,0,0,0,0,100,0),
(@PATH,17,1407.61,6858.912,108.0289,0,0,0,0,100,0),
(@PATH,18,1390.79,6861.882,102.2583,0,0,0,0,100,0),
(@PATH,19,1373.986,6866.587,97.52299,0,0,0,0,100,0),
(@PATH,20,1355.231,6884.747,95.21254,0,0,0,0,100,0),
(@PATH,21,1341.481,6899.75,94.77781,0,0,0,0,100,0),
(@PATH,22,1334.158,6919.819,94.02305,0,0,0,0,100,0),
(@PATH,23,1328.682,6944.249,93.1772,0,0,0,0,100,0),
(@PATH,24,1315.864,6961.601,92.83173,0,0,0,0,100,0),
(@PATH,25,1302.526,6966.913,92.38039,0,0,0,0,100,0),
(@PATH,26,1259.068,6971.35,87.20951,0,0,0,0,100,0);

-- Pathing for [PH] Cave Bat JZB Entry: 22040
SET @NPC := 77191;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1252.224,`position_y`=6959.56,`position_z`=109.6476 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1252.224,6959.56,109.6476,0,0,1,0,100,0),
(@PATH,2,1305.89,6960.333,103.8583,0,0,1,0,100,0),
(@PATH,3,1330.604,6925.649,102.9162,0,0,1,0,100,0),
(@PATH,4,1342.882,6882.453,111.1166,0,0,1,0,100,0),
(@PATH,5,1330.604,6925.649,102.9162,0,0,1,0,100,0),
(@PATH,6,1305.89,6960.333,103.8583,0,0,1,0,100,0),
(@PATH,7,1254.092,6959.132,109.3246,0,0,1,0,100,0),
(@PATH,8,1213.555,6978.563,119.4476,0,0,1,0,100,0),
(@PATH,9,1182.203,7005.035,122.6381,0,0,1,0,100,0),
(@PATH,10,1213.555,6978.563,119.4476,0,0,1,0,100,0);

-- Pathing for [PH] Cave Bat JZB Entry: 22040
SET @NPC := 77192;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1308.526,`position_y`=6957.836,`position_z`=103.7312 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1308.526,6957.836,103.7312,0,0,1,0,100,0),
(@PATH,2,1329.486,6927.308,102.9568,0,0,1,0,100,0),
(@PATH,3,1342.306,6884.338,110.7806,0,0,1,0,100,0),
(@PATH,4,1331.965,6921.992,103.4478,0,0,1,0,100,0);

-- Pathing for [PH] Cave Bat JZB Entry: 22040
SET @NPC := 77193;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1182.27,`position_y`=7005.14,`position_z`=122.562 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1182.27,7005.14,122.562,0,0,1,0,100,0),
(@PATH,2,1252.268,6959.663,109.5825,0,0,1,0,100,0);

-- Pathing for [PH] Cave Bat JZB Entry: 22040
SET @NPC := 77194;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1213.555,`position_y`=6978.563,`position_z`=119.4476 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1213.555,6978.563,119.4476,0,0,1,0,100,0),
(@PATH,2,1252.222,6959.555,109.6505,0,0,1,0,100,0),
(@PATH,3,1305.89,6960.333,103.8584,0,0,1,0,100,0),
(@PATH,4,1254.092,6959.148,109.3239,0,0,1,0,100,0);

-- Pathing for [PH] Cave Bat JZB Entry: 22040
SET @NPC := 77195;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1331.969,`position_y`=6921.993,`position_z`=103.4453 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1331.969,6921.993,103.4453,0,0,1,0,100,0),
(@PATH,2,1342.366,6884.349,110.745,0,0,1,0,100,0);

-- Pathing for [PH] Cave Bat JZB Entry: 22040
SET @NPC := 77196;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1308.01,`position_y`=6958.695,`position_z`=103.7117 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1308.01,6958.695,103.7117,0,0,1,0,100,0),
(@PATH,2,1255.087,6959.109,109.2217,0,0,1,0,100,0),
(@PATH,3,1304.895,6960.3,103.9611,0,0,1,0,100,0),
(@PATH,4,1329.993,6926.441,102.9424,0,0,1,0,100,0);
