-- Pathing for  Entry: 45265 'TDB FORMAT' 
SET @NPC := 253837;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '84849');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-424.701,-538.622,894.0889,0,0,0,0,100,0),
(@PATH,2,-449.543,-538.153,894.0859,0,0,0,0,100,0),
(@PATH,3,-424.701,-538.622,894.0889,0,0,0,0,100,0),
(@PATH,4,-403.469,-539.156,894.0871,0,0,0,0,100,0);
-- 0x20307C53E02C344000034900004E80CA .go xyz -424.701 -538.622 894.0889

DELETE FROM `creature_formations` WHERE `leaderGUID`= 253837;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
-- Front Line
(253837, 253837, 0, 0, 515, 0, 0),
(253837, 253838, 6, 90, 515, 2, 4),
(253837, 253840, 12, 90, 515, 2, 4),
(253837, 253849, 6, 270, 515, 2, 4),
(253837, 253834, 12, 270, 515, 2, 4),
-- Back Line
(253837, 253836, 5, 0, 515, 2, 4),
(253837, 253843, 8, 45, 515, 2, 4),
(253837, 253835, 8, 315, 515, 2, 4),
(253837, 253844, 12, 65, 515, 2, 4),
(253837, 253847, 12, 295, 515, 2, 4);

-- Pathing for  Entry: 45265 'TDB FORMAT' 
SET @NPC := 253794;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '84849');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-423.875,-523.818,894.0902,0,0,0,0,100,0),
(@PATH,2,-401.708,-524.644,894.087,0,0,0,0,100,0),
(@PATH,3,-423.875,-523.818,894.0902,0,0,0,0,100,0),
(@PATH,4,-448.594,-523.03,894.0881,0,0,0,0,100,0);
-- 0x20307C53E02C344000034900044E80CA .go xyz -423.875 -523.818 894.0902

DELETE FROM `creature_formations` WHERE `leaderGUID`= 253794;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
-- Front Line
(253794, 253794, 0, 0, 515, 0, 0),
(253794, 253791, 6, 90, 515, 2, 4),
(253794, 253784, 12, 90, 515, 2, 4),
(253794, 253782, 6, 270, 515, 2, 4),
(253794, 253797, 12, 270, 515, 2, 4),
-- Back Line
(253794, 253795, 5, 0, 515, 2, 4),
(253794, 253798, 8, 45, 515, 2, 4),
(253794, 253790, 8, 315, 515, 2, 4),
(253794, 253788, 12, 65, 515, 2, 4),
(253794, 253792, 12, 295, 515, 2, 4);

-- Pathing for  Entry: 45265 'TDB FORMAT' 
SET @NPC := 253842;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '84849');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-323.597,-534.234,894.5809,0,0,0,0,100,0),
(@PATH,2,-321.976,-565.561,894.5803,0,0,0,0,100,0),
(@PATH,3,-323.597,-534.234,894.5809,0,0,0,0,100,0),
(@PATH,4,-361.729,-533.083,894.58,0,0,0,0,100,0);
-- 0x20307C53E02C344000034900014E80CA .go xyz -323.597 -534.234 894.5809

DELETE FROM `creature_formations` WHERE `leaderGUID`= 253842;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(253842, 253842, 0, 0, 515, 0, 0),
(253842, 253830, 6, 0, 515, 2, 4),
(253842, 253846, 6, 270, 515, 2, 4),
(253842, 253827, 9, 315, 515, 2, 4);
