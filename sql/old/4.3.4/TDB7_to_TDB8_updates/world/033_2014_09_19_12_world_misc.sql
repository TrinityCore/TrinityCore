-- Pathing for Son of Corok Entry: 19824
SET @NPC := 70934;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4400.59,`position_y`=1298.177,`position_z`=84.52772 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4400.59,1298.177,84.52772,0,0,0,0,100,0),
(@PATH,2,-4420.625,1286.901,77.03065,0,0,0,0,100,0),
(@PATH,3,-4433.011,1273.885,71.53358,0,0,0,0,100,0),
(@PATH,4,-4443.392,1262.241,66.49532,0,0,0,0,100,0),
(@PATH,5,-4461.213,1245.472,58.49483,0,0,0,0,100,0),
(@PATH,6,-4443.392,1262.241,66.49532,0,0,0,0,100,0),
(@PATH,7,-4433.011,1273.885,71.53358,0,0,0,0,100,0),
(@PATH,8,-4420.625,1286.901,77.03065,0,0,0,0,100,0);

-- Pathing for Son of Corok Entry: 19824
SET @NPC := 70936;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4462.013,`position_y`=1364.896,`position_z`=131.461 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4462.013,1364.896,131.461,0,0,0,0,100,0),
(@PATH,2,-4423.92,1374.436,132.7069,0,0,0,0,100,0),
(@PATH,3,-4406.461,1375.059,136.9795,0,0,0,0,100,0),
(@PATH,4,-4380.588,1383.079,140.5566,0,0,0,0,100,0),
(@PATH,5,-4354.617,1389.822,141.8532,0,0,0,0,100,0),
(@PATH,6,-4380.588,1383.079,140.5566,0,0,0,0,100,0),
(@PATH,7,-4406.461,1375.059,136.9795,0,0,0,0,100,0),
(@PATH,8,-4423.92,1374.436,132.7069,0,0,0,0,100,0);

-- Pathing for Son of Corok Entry: 19824
SET @NPC := 70939;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4329.11,`position_y`=1386.571,`position_z`=143.7565 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4329.11,1386.571,143.7565,0,0,0,0,100,0),
(@PATH,2,-4303.821,1385.086,143.7775,0,0,0,0,100,0),
(@PATH,3,-4281.203,1392.313,139.9943,0,0,0,0,100,0),
(@PATH,4,-4257.452,1400.368,135.1779,0,0,0,0,100,0),
(@PATH,5,-4241.35,1408.419,131.0781,0,0,0,0,100,0),
(@PATH,6,-4257.452,1400.368,135.1779,0,0,0,0,100,0),
(@PATH,7,-4281.203,1392.313,139.9943,0,0,0,0,100,0),
(@PATH,8,-4303.821,1385.086,143.7775,0,0,0,0,100,0);
