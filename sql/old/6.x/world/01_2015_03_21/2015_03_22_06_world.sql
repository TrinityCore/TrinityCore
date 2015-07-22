-- Pathing for Guardian of Life Entry: 33528
SET @NPC := 137528;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2267.131,`position_y`=25.01511,`position_z`=428.6021 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2267.131,25.01511,428.6021,0,0,0,0,100,0),
(@PATH,2,2267.036,24.98481,428.7653,0,0,0,0,100,0),
(@PATH,3,2266.606,38.24471,428.8724,0,0,0,0,100,0),
(@PATH,4,2266.924,24.55858,428.5795,0,0,0,0,100,0),
(@PATH,5,2267.036,24.98481,428.7653,0,0,0,0,100,0),
(@PATH,6,2266.606,38.24471,428.8724,0,0,0,0,100,0),
(@PATH,7,2267.153,24.9108,428.5908,0,0,0,0,100,0),
(@PATH,8,2267.036,24.98481,428.7653,0,0,0,0,100,0),
(@PATH,9,2266.606,38.24471,428.8724,0,0,0,0,100,0);

-- Pathing for Guardian of Life Entry: 33528
SET @NPC := 137529;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2366.774,`position_y`=4.869098,`position_z`=427.116 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2366.774,4.869098,427.116,0,0,0,0,100,0),
(@PATH,2,2362.121,4.529948,427.9323,0,0,0,0,100,0),
(@PATH,3,2348.469,20.28589,429.8685,0,0,0,0,100,0),
(@PATH,4,2364.304,30.57164,430.7769,0,0,0,0,100,0),
(@PATH,5,2361.717,29.00374,430.3431,0,0,0,0,100,0),
(@PATH,6,2353.135,9.205807,428.5914,0,0,0,0,100,0);

-- Pathing for Guardian of Life Entry: 33528
SET @NPC := 137530;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2258.508,`position_y`=-45.42564,`position_z`=427.925 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2258.508,-45.42564,427.925,0,0,0,0,100,0),
(@PATH,2,2251.779,-49.15427,426.946,0,0,0,0,100,0),
(@PATH,3,2250.673,-49.80873,426.6561,0,0,0,0,100,0),
(@PATH,4,2252.392,-71.85374,427.5378,0,0,0,0,100,0),
(@PATH,5,2247.761,-65.52759,426.7502,0,0,0,0,100,0),
(@PATH,6,2245.5,-62.23093,426.3374,0,0,0,0,100,0);

-- Pathing for Guardian of Life Entry: 33528
SET @NPC := 137531;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2337.467,`position_y`=-207.8645,`position_z`=442.2937 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2337.467,-207.8645,442.2937,0,0,0,0,100,0),
(@PATH,2,2344.242,-198.5094,441.5296,0,0,0,0,100,0),
(@PATH,3,2348.561,-192.5445,440.9542,0,0,0,0,100,0),
(@PATH,4,2324.5,-181.2047,442.9576,0,0,0,0,100,0),
(@PATH,5,2333.28,-177.3987,441.4766,0,0,0,0,100,0),
(@PATH,6,2337.545,-175.9973,441.1203,0,0,0,0,100,0);
