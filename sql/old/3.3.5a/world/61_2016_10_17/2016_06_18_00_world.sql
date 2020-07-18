-- Fjord Hawk Matriarch
UPDATE `creature_template` SET `InhabitType`='5' WHERE  `entry`=24787;
-- Pathing for Entry: 24787 'TDB FORMAT' 
SET @NPC := 115835;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=491.5974,`position_y`=-6158.39,`position_z`=144.1042 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '43775');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,491.5974,-6158.39,144.1042,0,0,1,0,100,0),
(@PATH,2,509.5939,-6162.629,111.2709,0,0,1,0,100,0),
(@PATH,3,526.574,-6162.785,95.60418,0,0,1,0,100,0),
(@PATH,4,574.4791,-6163.997,95.60418,0,0,1,0,100,0),
(@PATH,5,603.0228,-6169.135,135.1598,0,0,1,0,100,0),
(@PATH,6,621.6965,-6158.342,152.5963,0,0,1,0,100,0),
(@PATH,7,637.6,-6155.499,154.6354,0,0,1,0,100,0),
(@PATH,8,663.0421,-6125.693,179.4132,0,0,1,0,100,0),
(@PATH,9,656.72,-6138.115,215.4652,0,0,1,0,100,0),
(@PATH,10,639.1322,-6143.215,215.4652,0,0,1,0,100,0),
(@PATH,11,618.7733,-6150.35,208.0208,0,0,1,0,100,0),
(@PATH,12,588.9388,-6145.327,208.0208,0,0,1,0,100,0),
(@PATH,13,554.6487,-6152.367,187.5208,0,0,1,0,100,0),
(@PATH,14,528.2413,-6138.124,166.6597,0,0,1,0,100,0),
(@PATH,15,497.937,-6157.058,187.5208,0,0,1,0,100,0),
(@PATH,16,482.7061,-6146.376,174.6875,0,0,1,0,100,0),
(@PATH,17,491.5974,-6158.39,144.1042,0,0,1,0,100,0);

-- Pathing for Entry: 24787 'TDB FORMAT' 
SET @NPC := 115836;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=520.6224,`position_y`=-6137.84,`position_z`=169.3022 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '43775');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,520.6224,-6137.84,169.3022,0,0,1,0,100,0),
(@PATH,2,539.8384,-6131.232,149.1912,0,0,1,0,100,0),
(@PATH,3,520.709,-6158.917,160.4134,0,0,1,0,100,0),
(@PATH,4,485.8767,-6155.685,160.4134,0,0,1,0,100,0),
(@PATH,5,438.8145,-6158.287,160.4134,0,0,1,0,100,0),
(@PATH,6,419.3206,-6156.742,160.4134,0,0,1,0,100,0),
(@PATH,7,390.6546,-6143.165,160.4134,0,0,1,0,100,0),
(@PATH,8,377.2733,-6114.98,160.4134,0,0,1,0,100,0),
(@PATH,9,383.0898,-6128.999,185.83,0,0,0,1,100,0),
(@PATH,10,417.4906,-6154.904,185.83,0,0,1,0,100,0),
(@PATH,11,452.2428,-6147.803,185.83,0,0,1,0,100,0),
(@PATH,12,497.4655,-6150.674,185.83,0,0,1,0,100,0),
(@PATH,13,520.6224,-6137.84,169.3022,0,0,1,0,100,0);

-- Pathing for Entry: 24787 'TDB FORMAT' 
SET @NPC := 115837;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=596.8774,`position_y`=-6114.975,`position_z`=271.1343 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '43775');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,596.8774,-6114.975,271.1343,0,0,1,0,100,0),
(@PATH,2,595.4591,-6109.405,278.3748,0,0,1,0,100,0),
(@PATH,3,571.2776,-6109.743,290.4025,0,0,1,0,100,0),
(@PATH,4,556.7193,-6108.814,297.3566,0,0,1,0,100,0),
(@PATH,5,517.0029,-6104.844,297.3566,0,0,1,0,100,0),
(@PATH,6,503.9214,-6117.692,297.3566,0,0,1,0,100,0),
(@PATH,7,466.3313,-6107.801,271.1343,0,0,1,0,100,0),
(@PATH,8,475.6375,-6120.523,271.1343,0,0,1,0,100,0),
(@PATH,9,500.4033,-6130.543,271.1343,0,0,1,0,100,0),
(@PATH,10,542.1522,-6114.92,271.1343,0,0,1,0,100,0),
(@PATH,11,567.1166,-6129.524,271.1343,0,0,1,0,100,0),
(@PATH,12,596.8774,-6114.975,271.1343,0,0,1,0,100,0);

-- Pathing for Entry: 24787 'TDB FORMAT' 
SET @NPC := 115843;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=290.8945,`position_y`=-6070.151,`position_z`=84.36917 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '43775');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,290.8945,-6070.151,84.36917,0,0,1,0,100,0),
(@PATH,2,273.076,-6034.628,84.36917,0,0,1,0,100,0),
(@PATH,3,268.3575,-6009.71,121.8221,0,0,1,0,100,0),
(@PATH,4,282.7736,-6034.701,150.6469,0,0,1,0,100,0),
(@PATH,5,297.921,-6060.3,111.1191,0,0,1,0,100,0),
(@PATH,6,324.4433,-6101.173,115.008,0,0,1,0,100,0),
(@PATH,7,351.7174,-6115.625,115.008,0,0,1,0,100,0),
(@PATH,8,380.059,-6146.51,102.4525,0,0,1,0,100,0),
(@PATH,9,381.592,-6162.233,80.36916,0,0,1,0,100,0),
(@PATH,10,363.2276,-6145.913,80.36916,0,0,1,0,100,0),
(@PATH,11,338.3981,-6105.44,80.36916,0,0,1,0,100,0),
(@PATH,12,319.2164,-6096.714,84.36917,0,0,1,0,100,0),
(@PATH,13,290.8945,-6070.151,84.36917,0,0,1,0,100,0);

-- Pathing for Entry: 24787 'TDB FORMAT' 
SET @NPC := 115845;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=360.9156,`position_y`=-6061.682,`position_z`=302.8403 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '43775');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,360.9156,-6061.682,302.8403,0,0,1,0,100,0),
(@PATH,2,389.247,-6078.495,302.8403,0,0,1,0,100,0),
(@PATH,3,392.2037,-6094.839,296.007,0,0,1,0,100,0),
(@PATH,4,374.589,-6096.534,288.5903,0,0,1,0,100,0),
(@PATH,5,358.6935,-6082.393,274.9237,0,0,1,0,100,0),
(@PATH,6,338.8949,-6049.761,274.9237,0,0,1,0,100,0),
(@PATH,7,320.3495,-6021.407,274.9237,0,0,1,0,100,0),
(@PATH,8,306.0276,-5998.132,285.257,0,0,1,0,100,0),
(@PATH,9,313.4884,-5983.751,285.2291,0,0,1,0,100,0),
(@PATH,10,320.7385,-5972.151,286.1277,0,0,1,0,100,0),
(@PATH,11,330.6828,-6007.996,302.8403,0,0,1,0,100,0),
(@PATH,12,349.4529,-6033.62,302.8403,0,0,1,0,100,0),
(@PATH,13,360.9156,-6061.682,302.8403,0,0,1,0,100,0);

-- Pathing for Entry: 24787 'TDB FORMAT' 
SET @NPC := 115844;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=389.949,`position_y`=-6113.926,`position_z`=217.1557 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '43775');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,389.949,-6113.926,217.1557,0,0,1,0,100,0),
(@PATH,2,365.9727,-6083.048,249.1279,0,0,1,0,100,0),
(@PATH,3,348.9503,-6058.797,249.1279,0,0,1,0,100,0),
(@PATH,4,334.4755,-6041.239,249.1279,0,0,1,0,100,0),
(@PATH,5,306.4679,-6010.077,240.8223,0,0,1,0,100,0),
(@PATH,6,305.4742,-6011.148,217.1557,0,0,1,0,100,0),
(@PATH,7,308.0244,-6019.713,217.1557,0,0,1,0,100,0),
(@PATH,8,331.7084,-6052.974,217.1557,0,0,1,0,100,0),
(@PATH,9,350.9348,-6071.563,217.1557,0,0,1,0,100,0),
(@PATH,10,371.7133,-6102.678,217.1557,0,0,1,0,100,0),
(@PATH,11,389.949,-6113.926,217.1557,0,0,1,0,100,0);
