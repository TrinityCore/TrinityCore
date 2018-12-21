-- Pathing for  Entry: 330 'TDB FORMAT' 
SET @NPC := 280296;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9946.83,`position_y`=408.503,`position_z`=34.89249 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '87519');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9946.83,408.503,34.89249,0,0,0,0,100,0),
(@PATH,2,-9934.89,375.823,35.15996,0,0,0,0,100,0),
(@PATH,3,-9905.29,378.352,35.28614,0,0,0,0,100,0),
(@PATH,4,-9889.87,404.354,35.3951,0,0,0,0,100,0),
(@PATH,5,-9911.25,423.392,35.39784,0,0,0,0,100,0);
-- 0x203CC80000005280003C9800004BCA0D .go xyz -9946.83 408.503 34.89249
