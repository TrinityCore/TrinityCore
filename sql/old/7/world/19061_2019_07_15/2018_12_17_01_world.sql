-- Pathing for  Entry: 475 'TDB FORMAT' 
SET @NPC := 280185;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9857.371,`position_y`=179.0012,`position_z`=20.34673 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9857.371,179.0012,20.34673,0,0,0,0,100,0),
(@PATH,2,-9865.824,179.7147,18.95403,0,0,0,0,100,0),
(@PATH,3,-9875.407,186.6826,17.52646,0,0,0,0,100,0),
(@PATH,4,-9883.963,195.0957,15.47739,0,0,0,0,100,0),
(@PATH,5,-9893.877,206.7493,14.13369,0,0,0,0,100,0),
(@PATH,6,-9900.333,215.4647,14.84706,0,0,0,0,100,0),
(@PATH,7,-9912.066,220.6375,17.55446,0,0,0,0,100,0),
(@PATH,8,-9936.305,225.5934,22.25602,0,0,0,0,100,0),
(@PATH,9,-9912.066,220.6375,17.55446,0,0,0,0,100,0),
(@PATH,10,-9900.333,215.4647,14.84706,0,0,0,0,100,0),
(@PATH,11,-9893.877,206.7493,14.13369,0,0,0,0,100,0),
(@PATH,12,-9884.15,195.3242,15.47739,0,0,0,0,100,0),
(@PATH,13,-9875.619,186.8867,17.47739,0,0,0,0,100,0),
(@PATH,14,-9865.939,179.8086,18.91875,0,0,0,0,100,0),
(@PATH,15,-9857.371,179.0012,20.34673,0,0,0,0,100,0),
(@PATH,16,-9845.659,183.0172,20.97102,0,0,0,0,100,0),
(@PATH,17,-9838.6,191.2428,23.04388,0,0,0,0,100,0),
(@PATH,18,-9845.029,183.2025,21.20053,0,0,0,0,100,0),
(@PATH,19,-9857.371,179.0012,20.34673,0,0,0,0,100,0);
-- 0x203CC400000076C00013930003F8925A .go xyz -9857.371 179.0012 20.34673

-- Pathing for  Entry: 475 'TDB FORMAT' 
SET @NPC := 280142;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9761.747,`position_y`=106.7565,`position_z`=26.45013 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9761.747,106.7565,26.45013,0,0,0,0,100,0),
(@PATH,2,-9770.365,103.1574,27.18955,0,0,0,0,100,0),
(@PATH,3,-9781.66,98.24756,28.74007,0,0,0,0,100,0),
(@PATH,4,-9789.447,94.47607,28.77352,0,0,0,0,100,0),
(@PATH,5,-9797.38,89.08634,28.51797,0,0,0,0,100,0),
(@PATH,6,-9789.447,94.47607,28.77352,0,0,0,0,100,0),
(@PATH,7,-9781.66,98.24756,28.74007,0,0,0,0,100,0),
(@PATH,8,-9770.365,103.1574,27.18955,0,0,0,0,100,0),
(@PATH,9,-9761.747,106.7565,26.45013,0,0,0,0,100,0),
(@PATH,10,-9748.221,110.5554,25.59357,0,0,0,0,100,0),
(@PATH,11,-9740.368,112.9743,24.81501,0,0,0,0,100,0),
(@PATH,12,-9748.221,110.5554,25.59357,0,0,0,0,100,0);
-- 0x203CC400000076C00013930001F8925B .go xyz -9761.747 106.7565 26.45013

-- Pathing for  Entry: 475 'TDB FORMAT' 
SET @NPC := 280145;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9788.127,`position_y`=149.6609,`position_z`=25.07858 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9788.127,149.6609,25.07858,0,0,0,0,100,0),
(@PATH,2,-9794.722,152.9546,24.72138,0,0,0,0,100,0),
(@PATH,3,-9797.021,159.9689,25.46847,0,0,0,0,100,0),
(@PATH,4,-9800.761,172.8822,23.31731,0,0,0,0,100,0),
(@PATH,5,-9803.823,180.0129,22.35514,0,0,0,0,100,0),
(@PATH,6,-9809.692,182.0895,22.5449,0,0,0,0,100,0),
(@PATH,7,-9821.691,180.9642,22.81018,0,0,0,0,100,0),
(@PATH,8,-9809.692,182.0895,22.5449,0,0,0,0,100,0),
(@PATH,9,-9803.823,180.0129,22.35514,0,0,0,0,100,0),
(@PATH,10,-9800.761,172.8822,23.31731,0,0,0,0,100,0),
(@PATH,11,-9797.021,159.9689,25.46847,0,0,0,0,100,0);
-- 0x203CC400000076C0001393000178925B .go xyz -9788.127 149.6609 25.07858

-- Pathing for  Entry: 475 'TDB FORMAT' 
SET @NPC := 280248;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9772.54,`position_y`=97.54986,`position_z`=6.61907 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9772.54,97.54986,6.61907,0,0,0,0,100,0),
(@PATH,2,-9762.998,91.01275,11.75701,0,0,0,0,100,0),
(@PATH,3,-9751.17,89.2978,13.26458,0,0,0,0,100,0),
(@PATH,4,-9746.868,89.78358,12.87456,0,0,0,0,100,0),
(@PATH,5,-9744.331,97.00578,12.62533,0,0,0,0,100,0),
(@PATH,6,-9749.636,106.8764,13.79356,0,0,0,0,100,0),
(@PATH,7,-9753.591,118.0865,15.39913,0,0,0,0,100,0),
(@PATH,8,-9751.409,126.1938,17.07101,0,0,0,0,100,0),
(@PATH,9,-9749.368,136.0419,19.43791,0,0,0,0,100,0),
(@PATH,10,-9751.409,126.1938,17.07101,0,0,0,0,100,0),
(@PATH,11,-9753.591,118.0865,15.39913,0,0,0,0,100,0),
(@PATH,12,-9749.636,106.8764,13.79356,0,0,0,0,100,0),
(@PATH,13,-9744.331,97.00578,12.62533,0,0,0,0,100,0),
(@PATH,14,-9746.868,89.78358,12.87456,0,0,0,0,100,0),
(@PATH,15,-9751.17,89.2978,13.26458,0,0,0,0,100,0),
(@PATH,16,-9762.998,91.01275,11.75701,0,0,0,0,100,0),
(@PATH,17,-9772.54,97.54986,6.61907,0,0,0,0,100,0);
-- 0x203CC400000076C00013930000F8925B .go xyz -9744.331 97.00578 12.62533

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
