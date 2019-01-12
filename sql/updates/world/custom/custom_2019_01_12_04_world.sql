-- Pathing for  Entry: 49813 'TDB FORMAT' 
SET @NPC := 254061;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-842.4097,`position_y`=-659.1024,`position_z`=831.9011 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-842.4097,-659.1024,831.9011,0,0,0,0,100,0),
(@PATH,2,-842.6354,-643.3143,831.9011,0,0,0,0,100,0),
(@PATH,3,-845.6443,-630.6788,831.901,0,0,0,0,100,0),
(@PATH,4,-851.9236,-615.9549,831.9009,0,0,0,0,100,0),
(@PATH,5,-858.941,-605.8246,831.9009,0,0,0,0,100,0),
(@PATH,6,-868.1458,-594.6719,831.9011,0,0,0,0,100,0),
(@PATH,7,-878.0174,-585.4393,831.9011,0,0,0,0,100,0),
(@PATH,8,-890.8246,-583.9236,831.9009,0,0,0,0,100,0),
(@PATH,9,-878.0174,-585.4393,831.9011,0,0,0,0,100,0),
(@PATH,10,-868.1458,-594.6719,831.9011,0,0,0,0,100,0),
(@PATH,11,-858.941,-605.8246,831.9009,0,0,0,0,100,0),
(@PATH,12,-851.9236,-615.9549,831.9009,0,0,0,0,100,0),
(@PATH,13,-845.6736,-630.5555,831.901,0,0,0,0,100,0),
(@PATH,14,-842.6354,-643.3143,831.9011,0,0,0,0,100,0);
-- 0x20307C53E030A5400003490000CE82FC .go xyz -842.4097 -659.1024 831.9011

-- Pathing for  Entry: 49825 'TDB FORMAT' 
SET @NPC := 254072;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-971.8889,`position_y`=-608.3871,`position_z`=831.9053 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '93335');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-971.8889,-608.3871,831.9053,0,0,0,0,100,0),
(@PATH,2,-981.1563,-603.0712,831.9033,0,0,0,0,100,0),
(@PATH,3,-995.4566,-602.6893,831.9021,0,0,0,0,100,0),
(@PATH,4,-971.8889,-608.3871,831.9053,0,0,0,0,100,0),
(@PATH,5,-981.1563,-603.0712,831.9033,0,0,0,0,100,0),
(@PATH,6,-995.4566,-602.6893,831.9021,0,0,0,0,100,0),
(@PATH,7,-971.8889,-608.3871,831.9053,0,0,0,0,100,0),
(@PATH,8,-964.0184,-600.7383,831.9053,0,0,0,0,100,0),
(@PATH,9,-971.8889,-608.3871,831.9053,0,0,0,0,100,0),
(@PATH,10,-981.1563,-603.0712,831.9033,0,0,0,0,100,0),
(@PATH,11,-995.4566,-602.6893,831.9021,0,0,0,0,100,0),
(@PATH,12,-1010.358,-604.8177,831.901,0,0,0,0,100,0),
(@PATH,13,-981.1563,-603.0712,831.9033,0,0,0,0,100,0),
(@PATH,14,-995.4566,-602.6893,831.9021,0,0,0,0,100,0),
(@PATH,15,-995.4566,-602.6893,831.9021,0,0,0,0,100,0),
(@PATH,16,-981.1563,-603.0712,831.9033,0,0,0,0,100,0);
-- 0x20307C53E030A84000034900004E82FC .go xyz -971.8889 -608.3871 831.9053

-- Pathing for  Entry: 49825 'TDB FORMAT' 
SET @NPC := 254074;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-978.3004,`position_y`=-582.6614,`position_z`=831.9009 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '93335');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-978.3004,-582.6614,831.9009,0,0,0,0,100,0),
(@PATH,2,-1007.611,-582.6649,831.9002,0,0,0,0,100,0),
(@PATH,3,-978.3004,-582.6614,831.9009,0,0,0,0,100,0),
(@PATH,4,-968.9236,-582.8229,831.9008,0,0,0,0,100,0),
(@PATH,5,-978.3004,-582.6614,831.9009,0,0,0,0,100,0),
(@PATH,6,-1007.611,-582.6649,831.9002,0,0,0,0,100,0),
(@PATH,7,-1037.835,-582.7778,831.9017,0,0,0,0,100,0);
-- 0x20307C53E030A8400003490000CE82FC .go xyz -978.3004 -582.6614 831.9009

-- Pathing for  Entry: 49821 'TDB FORMAT' 
SET @NPC := 254097;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1029.908,`position_y`=-561.9636,`position_z`=831.9038 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '87906');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1029.908,-561.9636,831.9038,0,0,0,0,100,0),
(@PATH,2,-1037.516,-574.8715,831.9014,0,0,0,0,100,0),
(@PATH,3,-1037.649,-590.7049,831.902,0,0,0,0,100,0),
(@PATH,4,-1029.872,-603.75,831.9018,0,0,0,0,100,0),
(@PATH,5,-1016.889,-612.4601,831.9055,0,0,0,0,100,0),
(@PATH,6,-1000.611,-613.2969,831.9027,0,0,0,0,100,0),
(@PATH,7,-991.8733,-608.691,831.903,0,0,0,0,100,0),
(@PATH,8,-983.8542,-602.4496,831.903,0,0,0,0,100,0),
(@PATH,9,-978.8386,-593.9358,831.9017,0,0,0,0,100,0),
(@PATH,10,-976.7535,-583.441,831.9005,0,0,0,0,100,0),
(@PATH,11,-978.0104,-571.8264,831.902,0,0,0,0,100,0),
(@PATH,12,-986.1094,-560.6632,831.9047,0,0,0,0,100,0),
(@PATH,13,-999.7465,-552.618,831.9041,0,0,0,0,100,0),
(@PATH,14,-1015.778,-551.7413,831.9076,0,0,0,0,100,0);
-- 0x20307C53E030A74000034900004E82FC .go xyz -1029.908 -561.9636 831.9038

-- Pathing for  Entry: 49821 'TDB FORMAT' 
SET @NPC := 254071;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-967.3524,`position_y`=-596.1667,`position_z`=831.9025 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '87906');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-967.3524,-596.1667,831.9025,0,0,0,0,100,0),
(@PATH,2,-966.8871,-581.9705,831.9012,0,0,0,0,100,0),
(@PATH,3,-969.0087,-567.1858,831.9041,0,0,0,0,100,0),
(@PATH,4,-979.6441,-549.8837,831.9069,0,0,0,0,100,0),
(@PATH,5,-996.4896,-539.7639,831.9059,0,0,0,0,100,0),
(@PATH,6,-1011.033,-538.25,831.9028,0,0,0,0,100,0),
(@PATH,7,-1025.214,-544.993,833.9316,0,0,0,0,100,0),
(@PATH,8,-1035.576,-557.4236,833.8071,0,0,0,0,100,0),
(@PATH,9,-1043.63,-570.4393,833.9287,0,0,0,0,100,0),
(@PATH,10,-1044.866,-584.0382,833.5701,0,0,0,0,100,0),
(@PATH,11,-1041.389,-599.8663,833.8691,0,0,0,0,100,0),
(@PATH,12,-1033.95,-610.291,833.9688,0,0,0,0,100,0),
(@PATH,13,-1016.733,-624.8594,831.9109,0,0,0,0,100,0),
(@PATH,14,-1011.547,-626.5,831.9102,0,0,0,0,100,0),
(@PATH,15,-996.184,-627.9948,831.9071,0,0,0,0,100,0),
(@PATH,16,-985.0555,-622.092,831.9051,0,0,0,0,100,0),
(@PATH,17,-979.4739,-617.3785,831.9056,0,0,0,0,100,0),
(@PATH,18,-971.6476,-606.9011,831.9044,0,0,0,0,100,0);
-- 0x20307C53E030A7400003490000CE82FC .go xyz -967.3524 -596.1667 831.9025

-- Pathing for  Entry: 49826 'TDB FORMAT' 
SET @NPC := 254089;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-995.3924,`position_y`=-557.2222,`position_z`=831.904 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-995.3924,-557.2222,831.904,0,0,0,0,100,0),
(@PATH,2,-995.3924,-557.2222,831.904,0,0,0,0,100,0),
(@PATH,3,-1016.984,-563.8299,831.9017,0,0,0,0,100,0),
(@PATH,4,-1023.422,-590.9948,831.9017,0,0,0,0,100,0),
(@PATH,5,-1025.028,-601.2952,831.9015,0,0,0,0,100,0),
(@PATH,6,-1024.795,-618.3316,833.6077,0,0,0,0,100,0),
(@PATH,7,-1024.283,-629.5746,832.8298,0,0,0,0,100,0),
(@PATH,8,-1024.795,-618.3316,833.6077,0,0,0,0,100,0),
(@PATH,9,-1025.028,-601.2952,831.9015,0,0,0,0,100,0),
(@PATH,10,-1023.422,-590.9948,831.9017,0,0,0,0,100,0),
(@PATH,11,-1016.984,-563.8299,831.9017,0,0,0,0,100,0),
(@PATH,12,-995.3924,-557.2222,831.904,0,0,0,0,100,0),
(@PATH,13,-975.6684,-552.5521,831.907,0,0,0,0,100,0);
-- 0x20307C53E030A88000034900004E82FC .go xyz -995.3924 -557.2222 831.904


-- Pathing for  Entry: 49826 'TDB FORMAT' 
SET @NPC := 254103;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1004.67,`position_y`=-608.3055,`position_z`=831.9019 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1004.67,-608.3055,831.9019,0,0,0,0,100,0),
(@PATH,2,-1003.269,-619.7986,831.9061,0,0,0,0,100,0),
(@PATH,3,-1002.045,-628.9254,831.9086,0,0,0,0,100,0),
(@PATH,4,-1003.269,-619.7986,831.9061,0,0,0,0,100,0),
(@PATH,5,-1004.67,-608.3055,831.9019,0,0,0,0,100,0),
(@PATH,6,-1005.733,-595.2969,831.9006,0,0,0,0,100,0),
(@PATH,7,-1006.453,-583.2014,831.901,0,0,0,0,100,0),
(@PATH,8,-1006.805,-573.7188,831.9004,0,0,0,0,100,0),
(@PATH,9,-1007.255,-560.9323,831.902,0,0,0,0,100,0),
(@PATH,10,-1007.726,-545.7396,831.9052,0,0,0,0,100,0),
(@PATH,11,-1008.99,-532.8611,831.8925,0,0,0,0,100,0),
(@PATH,12,-1007.726,-545.7396,831.9052,0,0,0,0,100,0),
(@PATH,13,-1007.255,-560.9323,831.902,0,0,0,0,100,0),
(@PATH,14,-1006.805,-573.7188,831.9004,0,0,0,0,100,0),
(@PATH,15,-1006.453,-583.2014,831.901,0,0,0,0,100,0),
(@PATH,16,-1005.733,-595.2969,831.9006,0,0,0,0,100,0);
-- 0x20307C53E030A8800003490000CE82FC .go xyz -1004.67 -608.3055 831.9019

UPDATE `creature` SET `spawndist`= 30, `MovementType`= 1 WHERE `guid` IN (254120, 254121);
