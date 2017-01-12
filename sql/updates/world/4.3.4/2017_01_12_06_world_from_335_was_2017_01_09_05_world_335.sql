/*
-- John Turner
SET @MAXGUID := 907; 
SET @SCRIPTID := 10800;
DELETE FROM `waypoint_scripts` WHERE `id` IN (@SCRIPTID+0, @SCRIPTID+1, @SCRIPTID+2, @SCRIPTID+3);
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES 
-- TEXT
(@SCRIPTID+0, 0, 0, 0, 0, 2403, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1)),
(@SCRIPTID+1, 0, 0, 0, 0, 2401, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1)),
(@SCRIPTID+2, 0, 0, 0, 0, 2404, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1)),
(@SCRIPTID+3, 0, 0, 0, 0, 2402, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1));

UPDATE `creature` SET `position_x`=-4895.609, `position_y`=-898.0984, `position_z`=501.7426, `orientation`=2.286381, `MovementType`=2 WHERE `guid`=108;

SET @NPC := 108;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`, `action`, `orientation`) VALUES
(@PATH, (@POINT := @POINT + 1), -4895.609, -898.0984, 501.6593, 4000, @SCRIPTID+0, 2.286381),
(@PATH, (@POINT := @POINT + 1), -4859.858, -887.9218, 501.6594, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4842.476, -885.5647, 501.6594, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4842.476, -885.5647, 501.6594, 0000, @SCRIPTID+1, 1.884956),
(@PATH, (@POINT := @POINT + 1), -4875.518, -889.0638, 501.6594, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4895.693, -897.8222, 501.6593, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4895.693, -897.8222, 501.6593, 4000, @SCRIPTID+2, 2.251475),
(@PATH, (@POINT := @POINT + 1), -4927.132, -915.4280, 501.6594, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4951.839, -934.9794, 501.6593, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4981.382, -966.5792, 501.6595, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4983.741, -969.7697, 501.6595, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4983.741, -969.7697, 501.6595, 4000, @SCRIPTID+3, 2.443461),
(@PATH, (@POINT := @POINT + 1), -5002.574, -1008.675, 501.6595, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -5007.885, -1022.321, 501.6549, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -5012.979, -1052.933, 501.7099, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -5012.979, -1052.933, 501.7099, 4000, @SCRIPTID+0, 2.967060),
(@PATH, (@POINT := @POINT + 1), -5006.932, -1021.700, 501.6555, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4992.735, -985.8944, 501.6595, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4981.066, -962.5291, 501.6595, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4944.819, -930.4164, 501.6594, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4906.594, -901.6618, 501.6594, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4895.609, -898.0984, 501.6593, 0, 0, 0);

UPDATE `waypoint_data` SET `action_chance`=100 WHERE `action` IN (@SCRIPTID+0, @SCRIPTID+1, @SCRIPTID+2, @SCRIPTID+3);
*/
