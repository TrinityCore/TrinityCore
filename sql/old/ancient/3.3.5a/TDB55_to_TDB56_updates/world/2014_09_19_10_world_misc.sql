-- Pathing for Son of Hodir Entry: 29809
SET @NPC := 106332;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7333.749,`position_y`=-2849.251,`position_z`=800.5008 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7333.749,-2849.251,800.5008,0,0,0,0,100,0),
(@PATH,2,7297.994,-2845.033,792.8625,0,0,0,0,100,0),
(@PATH,3,7333.748,-2849.252,800.5008,0,0,0,0,100,0),
(@PATH,4,7368.463,-2842.755,800.5325,0,0,0,0,100,0),
(@PATH,5,7400.792,-2857.594,800.4119,0,0,0,0,100,0),
(@PATH,6,7445.252,-2857.651,799.9712,0,0,0,0,100,0),
(@PATH,7,7400.792,-2857.594,800.4119,0,0,0,0,100,0),
(@PATH,8,7368.463,-2842.755,800.5325,0,0,0,0,100,0);

-- Pathing for Son of Hodir Entry: 29809
SET @NPC := 106501;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7360.89,`position_y`=-2783.458,`position_z`=770.2411 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7360.89,-2783.458,770.2411,0,0,0,0,100,0),
(@PATH,2,7347.097,-2770.412,767.152,0,0,0,0,100,0),
(@PATH,3,7347.097,-2770.412,767.152,1.553343,15000,0,0,100,0),
(@PATH,4,7395.059,-2778.334,770.9921,0,0,0,0,100,0),
(@PATH,5,7397.093,-2777.097,770.9921,0,0,0,0,100,0),
(@PATH,6,7397.093,-2777.097,770.9921,3.176499,20000,0,0,100,0);

UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=7206.456,`position_y`=-2834.342,`position_z`=822.8013,`orientation`=1.553343 WHERE `guid`=106336;
DELETE FROM `creature_addon` WHERE `guid`=106336;
DELETE FROM `waypoint_data` WHERE `id`=1063360;
UPDATE `creature` SET `modelid`=0,`spawndist`=0,`MovementType`=0,`curhealth`=1 WHERE `id`=29558;
DELETE FROM `creature` WHERE `guid`=97993;
DELETE FROM `creature_addon` WHERE `guid`=97993;
