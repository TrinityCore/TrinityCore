-- Pathing for Stonespine Gargoyle Entry: 36896
SET @NPC := 201822;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=674.3073,`position_y`=-26.43229,`position_z`=512.5833 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,871.2952,252.9757,561.8807,0,0,0,100,0),
(@PATH,2,908.3472,250.5347,561.8807,0,0,0,100,0),
(@PATH,3,914.9774,291.7049,561.8807,0,0,0,100,0),
(@PATH,4,862.7778,292.8316,561.8807,0,0,0,100,0),
(@PATH,5,840.6111,278.9184,561.8807,0,0,0,100,0),
(@PATH,6,826.5712,228.2292,561.8807,0,0,0,100,0),
(@PATH,7,833.5452,174.3576,561.8807,0,0,0,100,0),
(@PATH,8,840.9531,116.6059,561.8807,0,0,0,100,0),
(@PATH,9,816.033,96.46702,561.8807,0,0,0,100,0),
(@PATH,10,773.6111,120.1024,561.8807,0,0,0,100,0),
(@PATH,11,700.3021,175.5278,561.8807,0,0,0,100,0),
(@PATH,12,672.0243,223.6806,561.8807,0,0,0,100,0),
(@PATH,13,710.2379,266.3021,561.8807,0,0,0,100,0),
(@PATH,14,806.8594,287.4445,561.8807,0,0,0,100,0);

-- Pathing for Stonespine Gargoyle Entry: 36896
SET @NPC := 201834;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=674.3073,`position_y`=-26.43229,`position_z`=512.5833 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,410.967,187.1424,581.4994,0,0,0,100,0),
(@PATH,2,413.2448,207.5677,581.4994,0,0,0,100,0),
(@PATH,3,410.6823,230.7569,581.4994,0,0,0,100,0),
(@PATH,4,365.309,278.4445,581.4994,0,0,0,100,0),
(@PATH,5,378.1736,302.0868,581.4994,0,0,0,100,0),
(@PATH,6,410.0504,294.9097,581.4994,0,0,0,100,0),
(@PATH,7,439.2795,289.7951,581.4994,0,0,0,100,0),
(@PATH,8,477.2188,240.033,581.4994,0,0,0,100,0),
(@PATH,9,473.9323,183.2101,581.4994,0,0,0,100,0),
(@PATH,10,469.3889,140.6754,581.4994,0,0,0,100,0),
(@PATH,11,429.6354,121.7135,581.4994,0,0,0,100,0),
(@PATH,12,407.4063,143.0243,581.4994,0,0,0,100,0);

-- Pathing for Stonespine Gargoyle Entry: 36896
SET @NPC := 201838;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=674.3073,`position_y`=-26.43229,`position_z`=512.5833 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,873.783,136.9774,623.6115,0,0,0,100,0),
(@PATH,2,872.9045,139.2743,622.4446,0,0,0,100,0),
(@PATH,3,888.7917,171.3403,591.3615,0,0,0,100,0),
(@PATH,4,861.3073,209.8455,591.3615,0,0,0,100,0),
(@PATH,5,830.4913,254.5556,591.3615,0,0,0,100,0),
(@PATH,6,780.4844,277.6406,591.3615,0,0,0,100,0),
(@PATH,7,732.6771,272.4635,591.3615,0,0,0,100,0),
(@PATH,8,683.9028,265.276,591.3615,0,0,0,100,0),
(@PATH,9,612.3368,284.7934,553.4998,0,0,0,100,0),
(@PATH,10,554.816,303.1858,553.4998,0,0,0,100,0),
(@PATH,11,498.1024,309.0625,553.4998,0,0,0,100,0),
(@PATH,12,470.4167,230.0174,553.4998,0,0,0,100,0),
(@PATH,13,454.0087,175.2135,553.4998,0,0,0,100,0),
(@PATH,14,492.4288,127.1806,583.1108,0,0,0,100,0),
(@PATH,15,551.2604,121.6354,583.1108,0,0,0,100,0),
(@PATH,16,647.5573,126.3542,583.1108,0,0,0,100,0),
(@PATH,17,766.2222,130.9254,583.1108,0,0,0,100,0),
(@PATH,18,829.408,42.33854,583.1108,0,0,0,100,0),
(@PATH,19,746.7101,-53.03299,583.1108,0,0,0,100,0),
(@PATH,20,663.2379,-77.32291,583.1108,0,0,0,100,0),
(@PATH,21,618.6389,3.369792,583.1108,0,0,0,100,0),
(@PATH,22,641.8559,89.27604,583.1108,0,0,0,100,0),
(@PATH,23,794.1667,115.6858,583.1108,0,0,0,100,0);

-- Pathing for Stonespine Gargoyle Entry: 36896
SET @NPC := 201846;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=674.3073,`position_y`=-26.43229,`position_z`=512.5833 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,750.842,23.30903,568.327,0,0,0,100,0),
(@PATH,2,755.467,-50.2257,568.327,0,0,0,100,0),
(@PATH,3,734.6927,-93.41319,568.327,0,0,0,100,0),
(@PATH,4,662.4028,-41.9757,568.327,0,0,0,100,0),
(@PATH,5,634.9601,19.78472,568.327,0,0,0,100,0),
(@PATH,6,619.0972,58.13368,568.327,0,0,0,100,0),
(@PATH,7,569.6493,80.08681,568.327,0,0,0,100,0),
(@PATH,8,474.8889,136.7135,568.327,0,0,0,100,0),
(@PATH,9,427.566,173.5174,568.327,0,0,0,100,0),
(@PATH,10,399.5938,237.6424,568.327,0,0,0,100,0),
(@PATH,11,416.8108,271.5695,568.327,0,0,0,100,0),
(@PATH,12,442.8767,281.1493,568.327,0,0,0,100,0),
(@PATH,13,472.9375,286.9531,568.327,0,0,0,100,0),
(@PATH,14,515.0677,321.1632,568.327,0,0,0,100,0),
(@PATH,15,547.0538,332.9358,568.327,0,0,0,100,0),
(@PATH,16,605.0295,286.3281,568.327,0,0,0,100,0),
(@PATH,17,673.9167,184.0747,568.327,0,0,0,100,0);

-- Remove dupe Stonespine Gargoyle Spawns
DELETE FROM `creature` WHERE `MovementType`=0 AND `id`=36896;

-- Pathing for Iceborn Proto-Drake Entry: 36891
SET @NPC := 202197;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=619.3055,`position_y`=18.79167,`position_z`=513.5994 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,626.5364,0.711806,513.8494,0,0,0,100,0),
(@PATH,2,619.3055,18.79167,513.5994,0,0,0,100,0),
(@PATH,3,615.1875,32.38021,512.5994,0,0,0,100,0),
(@PATH,4,615.4705,47.52778,512.4364,0,0,0,100,0),
(@PATH,5,617.6285,62.52083,512.5614,0,0,0,100,0),
(@PATH,6,621.3264,77.02604,512.4487,0,0,0,100,0),
(@PATH,7,617.6285,62.52083,512.5614,0,0,0,100,0),
(@PATH,8,615.4705,47.52778,512.4364,0,0,0,100,0),
(@PATH,9,615.1875,32.38021,512.5994,0,0,0,100,0),
(@PATH,10,619.3055,18.79167,513.5994,0,0,0,100,0);

-- Pathing for Iceborn Proto-Drake Entry: 36891
SET @NPC := 201991;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=679.2205,`position_y`=-100.6076,`position_z`=513.8377 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,661.1771,-79.90452,513.8378,0,0,0,100,0),
(@PATH,2,651.3489,-62.0191,513.7985,0,0,0,100,0),
(@PATH,3,645.1337,-45.49132,513.7985,0,0,0,100,0),
(@PATH,4,634.1077,-20.19618,513.8635,0,0,0,100,0),
(@PATH,5,645.1337,-45.49132,513.7985,0,0,0,100,0),
(@PATH,6,651.3489,-62.0191,513.7985,0,0,0,100,0),
(@PATH,7,661.1771,-79.90452,513.8378,0,0,0,100,0),
(@PATH,8,679.2205,-100.6076,513.8377,0,0,0,100,0);
