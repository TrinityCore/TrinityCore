-- Pathing for Forsaken Courier Entry: 2714 'TDB FORMAT' 
SET @NPC := 285848;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1644.767,`position_y`=-2970.928,`position_z`=26.889 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1644.767,-2970.928,26.889,0,0,0,0,100,0), -- 07:35:57
(@PATH,2,-1643.685,-2961.697,27.81409,0,0,0,0,100,0), -- 07:36:03
(@PATH,3,-1640.91,-2951.572,28.43296,0,0,0,0,100,0), -- 07:36:05
(@PATH,4,-1639.894,-2948.18,28.76205,0,0,0,0,100,0), -- 07:36:11
(@PATH,5,-1640.859,-2917.589,27.26082,0,0,0,0,100,0), -- 07:36:17
(@PATH,6,-1641.814,-2914.426,26.85855,0,0,0,0,100,0), -- 07:36:25
(@PATH,7,-1641.825,-2914.764,26.78742,0,0,0,0,100,0), -- 07:36:32
(@PATH,8,-1639.265,-2923.267,27.66898,0,0,0,0,100,0), -- 07:36:36
(@PATH,9,-1637.15,-2931.193,28.27434,0,0,0,0,100,0), -- 07:36:43
(@PATH,10,-1642.04,-2955.996,28.04179,0,0,0,0,100,0); -- 07:36:49
-- .go -1644.767 -2970.928 26.889

-- Pathing for Lieutenant Valorcall Entry: 2612 'TDB FORMAT' 
SET @NPC := 285677;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1446.705,`position_y`=-2441.104,`position_z`=58.81701 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1446.705,-2441.104,58.81701,0,0,0,0,100,0), -- 07:31:34
(@PATH,2,-1463.374,-2435.582,58.04238,0,0,0,0,100,0), -- 07:31:48
(@PATH,3,-1461.709,-2424.357,58.29197,0,0,0,0,100,0), -- 07:31:51
(@PATH,4,-1454.812,-2409.983,60.27683,0,0,0,0,100,0), -- 07:31:57
(@PATH,5,-1452.604,-2397.783,61.1295,0,0,0,0,100,0), -- 07:32:03
(@PATH,6,-1451.443,-2379.965,61.44468,0,0,0,0,100,0), -- 07:32:27
(@PATH,7,-1452.552,-2400.638,60.94978,0,0,0,0,100,0), -- 07:32:38
(@PATH,8,-1457.302,-2415.967,59.68084,0,0,0,0,100,0), -- 07:32:49
(@PATH,9,-1462.218,-2424.716,58.24706,0,0,0,0,100,0), -- 07:32:55
(@PATH,10,-1465.748,-2430.155,57.81998,0,0,0,0,100,0), -- 07:33:00
(@PATH,11,-1449.211,-2440.016,58.65489,0,0,0,0,100,0), -- 07:33:02
(@PATH,12,-1425.944,-2451.505,59.25491,0,0,0,0,100,0); -- 07:33:08
--  .go -1446.705 -2441.104 58.81701
