DELETE FROM `creature_formations` WHERE `leaderGUID`=33658;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(33658, 33658, 0, 0, 1),
(33658, 33657, 10, 0, 2);

-- Pathing for Hazzas Entry: 5722 'TDB FORMAT' 
SET @NPC := 33658;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-649.7056,`position_y`=131.495,`position_z`=-90.5838 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-649.7056,131.495,-90.5838,0,0,1,0,100,0), -- 14:04:57
(@PATH,2,-665.5804,131.4927,-90.58052,0,0,1,0,100,0), -- 14:05:00
(@PATH,3,-673.0132,94.911,-90.58176,0,0,1,0,100,0), -- 14:05:02
(@PATH,4,-673.0271,83.92074,-90.58344,0,0,1,0,100,0), -- 14:05:04
(@PATH,5,-665.4554,60.56186,-90.5854,0,0,1,0,100,0), -- 14:05:07
(@PATH,6,-649.9196,60.34818,-90.58607,0,0,1,0,100,0), -- 14:05:08
(@PATH,7,-641.7787,99.33066,-90.58942,0,0,1,0,100,0), -- 14:05:10
(@PATH,8,-644.1965,115.6559,-90.58284,0,0,1,0,100,0); -- 14:05:13
-- 0x1C30A00DA00596800034A9000018FBD3 .go -649.7056 131.495 -90.5838
