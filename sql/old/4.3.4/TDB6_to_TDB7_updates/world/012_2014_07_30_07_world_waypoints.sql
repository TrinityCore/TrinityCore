-- Pathing for Swamprat Guard Entry: 18910
SET @NPC := 67906;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=75.29373,`position_y`=5261.419,`position_z`=23.08392 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,257,0, '5301');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,75.29373,5261.419,23.08392,0,0,0,0,100,0),
(@PATH,2,75.29796,5274.807,23.04233,0,0,0,0,100,0),
(@PATH,3,82.62872,5302.216,22.98195,0,0,0,0,100,0),
(@PATH,4,83.02105,5314.273,22.13724,0,0,0,0,100,0),
(@PATH,5,82.34508,5302.751,22.97913,0,0,0,0,100,0),
(@PATH,6,75.29796,5274.807,23.04233,0,0,0,0,100,0),
(@PATH,7,75.29373,5261.419,23.08392,0,0,0,0,100,0),
(@PATH,8,75.86388,5247.502,23.12924,0,0,0,0,100,0),
(@PATH,9,79.21181,5240.832,23.16174,0,0,0,0,100,0),
(@PATH,10,87.85194,5229.543,22.38807,0,0,0,0,100,0),
(@PATH,11,79.21181,5240.832,23.16174,0,0,0,0,100,0),
(@PATH,12,75.86388,5247.502,23.12924,0,0,0,0,100,0);

-- Pathing for Swamprat Guard Entry: 18910
SET @NPC := 67907;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=75.29373,`position_y`=5261.419,`position_z`=23.08392 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,257,0, '5301');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,75.29373,5261.419,23.08392,0,0,0,0,100,0),
(@PATH,2,75.29796,5274.807,23.04233,0,0,0,0,100,0),
(@PATH,3,82.62872,5302.216,22.98195,0,0,0,0,100,0),
(@PATH,4,83.02105,5314.273,22.13724,0,0,0,0,100,0),
(@PATH,5,82.34508,5302.751,22.97913,0,0,0,0,100,0),
(@PATH,6,75.29796,5274.807,23.04233,0,0,0,0,100,0),
(@PATH,7,75.29373,5261.419,23.08392,0,0,0,0,100,0),
(@PATH,8,75.86388,5247.502,23.12924,0,0,0,0,100,0),
(@PATH,9,79.21181,5240.832,23.16174,0,0,0,0,100,0),
(@PATH,10,87.85194,5229.543,22.38807,0,0,0,0,100,0),
(@PATH,11,79.21181,5240.832,23.16174,0,0,0,0,100,0),
(@PATH,12,75.86388,5247.502,23.12924,0,0,0,0,100,0);

-- Add Swamprat Guard formation
DELETE FROM `creature_formations` WHERE `leaderGUID`=67907;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`)VALUES
(67907,67907,0,0,2),(67907,67906,3,0,2);

-- Pathing for Swamprat Guard Entry: 18910
SET @NPC := 67910;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=104.3016,`position_y`=5221.673,`position_z`=22.33099 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,257,0, '5301');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,104.3016,5221.673,22.33099,0,0,0,0,100,0),
(@PATH,2,98.48994,5217.889,22.21583,0,0,0,0,100,0),
(@PATH,3,97.17163,5209.297,21.69117,0,0,0,0,100,0),
(@PATH,4,82.73155,5204.081,22.44019,0,0,0,0,100,0),
(@PATH,5,80.67603,5193.767,21.65778,0,0,0,0,100,0),
(@PATH,6,90.1913,5186.492,21.33686,0,0,0,0,100,0),
(@PATH,7,92.36255,5170.327,22.81916,0,0,0,0,100,0),
(@PATH,8,104.2373,5163.936,22.91181,0,0,0,0,100,0),
(@PATH,9,108.7816,5178.44,22.09893,0,0,0,0,100,0),
(@PATH,10,121.7926,5183.15,24.04241,0,0,0,0,100,0),
(@PATH,11,117.1341,5191.477,23.33294,0,0,0,0,100,0),
(@PATH,12,118.593,5209.887,22.58294,0,0,0,0,100,0),
(@PATH,13,114.1548,5216.103,23.23504,0,0,0,0,100,0);
