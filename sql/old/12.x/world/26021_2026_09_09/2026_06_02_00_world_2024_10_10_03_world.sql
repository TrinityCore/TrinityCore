-- Pathing for Rex Ashil Entry: 14475
DELETE FROM `waypoint_path_node` WHERE `PathId`=28998480;
DELETE FROM `waypoint_path` WHERE `PathId`=28998480;

SET @GUID=51836;
SET @PATH=4146880;
UPDATE `creature` SET `guid`=@GUID,`position_x`=-6630.2847,`position_y`=945.4344,`position_z`=-53.113213,`orientation`=1.90135,`spawntimesecs`=43200,`wander_distance`=0,`MovementType`=2 WHERE `guid`=362481;
UPDATE `creature_addon` SET `guid`=@GUID,`PathId`=@PATH WHERE `guid`=362481;

DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x1, NULL, 'Rex Ashil - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -6630.2847, 945.4344, -53.113213, NULL, 0),
(@PATH, 1, -6627.747, 929.4205, -53.13147, NULL, 0),
(@PATH, 2, -6609.186, 929.8785, -53.079853, NULL, 0),
(@PATH, 3, -6591.815, 909.97754, -48.13315, NULL, 0),
(@PATH, 4, -6591.293, 896.9764, -44.32776, NULL, 0),
(@PATH, 5, -6595.7266, 884.783, -44.183353, NULL, 0),
(@PATH, 6, -6581.963, 877.2528, -44.43298, NULL, 0),
(@PATH, 7, -6570.469, 885.4149, -43.190834, NULL, 0),
(@PATH, 8, -6555.0957, 885.0344, -39.407715, NULL, 0),
(@PATH, 9, -6545.19, 871.5345, -32.732586, NULL, 0),
(@PATH, 10, -6535.754, 862.1162, -29.067938, NULL, 0),
(@PATH, 11, -6518.3926, 866.1533, -30.373377, NULL, 0),
(@PATH, 12, -6512.0576, 887.03265, -39.665333, NULL, 0),
(@PATH, 13, -6497.0356, 901.76587, -41.670567, NULL, 0),
(@PATH, 14, -6473.988, 908.0661, -41.263145, NULL, 0),
(@PATH, 15, -6480.721, 921.9516, -41.815945, NULL, 0);
