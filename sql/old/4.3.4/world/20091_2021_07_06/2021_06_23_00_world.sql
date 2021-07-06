DELETE FROM `waypoint_data` WHERE `id`= 2757880;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_Y`, `position_z`) VALUES
(2757880, 0, -9951.122, 1125.5764, 46.93732),
(2757880, 1, -9938.942, 1124.4445, 44.798428),
(2757880, 2, -9929.833, 1109.0608, 44.798428),
(2757880, 3, -9956.099, 1092.8767, 50.10399),
(2757880, 4, -9964.316, 1106.856, 50.103992);

UPDATE `creature` SET `MovementType`= 3 WHERE `guid`= 275788;
DELETE FROM `creature_addon` WHERE `guid`= 275788;
INSERT INTO `creature_addon` (`guid`, `cyclicSplinePathId`, `bytes1`, `bytes2`) VALUES
(275788, 2757880, 33554432, 2);

DELETE FROM `waypoint_data` WHERE `id`= 2757050;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_Y`, `position_z`) VALUES
(2757050, 0, -10000.056, 1112.3473, 48.51642),
(2757050, 1, -9996.3955, 1096.7622, 48.51642),
(2757050, 2, -9984.078, 1098.6598, 48.51642),
(2757050, 3, -9988.6045, 1108.8646, 48.51642);

UPDATE `creature` SET `MovementType`= 3 WHERE `guid`= 275705;
DELETE FROM `creature_addon` WHERE `guid`= 275705;
INSERT INTO `creature_addon` (`guid`, `cyclicSplinePathId`, `bytes1`, `bytes2`) VALUES
(275705, 2757050, 33554432, 2);


DELETE FROM `waypoint_data` WHERE `id`= 2757070;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_Y`, `position_z`) VALUES
(2757070, 0, -9980.337, 1148.9358, 47.96638),
(2757070, 1, -9970.556, 1160.8438, 47.96638),
(2757070, 2, -9983.066, 1165.9688, 47.96638),
(2757070, 3, -9995.444, 1156.0955, 47.96638);

UPDATE `creature` SET `MovementType`= 3 WHERE `guid`= 275707;
DELETE FROM `creature_addon` WHERE `guid`= 275707;
INSERT INTO `creature_addon` (`guid`, `cyclicSplinePathId`, `bytes1`, `bytes2`) VALUES
(275707, 2757070, 33554432, 2);

DELETE FROM `waypoint_data` WHERE `id`= 2754820;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_Y`, `position_z`) VALUES
(2754820, 0, -10257.851, 1148.1024, 43.714344),
(2754820, 1, -10265.736, 1136.6389, 43.714344),
(2754820, 2, -10242.538, 1121.0677, 43.714344),
(2754820, 3, -10228.021, 1128.9323, 43.714344),
(2754820, 4, -10235.926, 1149.1216, 43.714344);

UPDATE `creature` SET `MovementType`= 3 WHERE `guid`= 275482;
DELETE FROM `creature_addon` WHERE `guid`= 275482;
INSERT INTO `creature_addon` (`guid`, `cyclicSplinePathId`, `bytes1`, `bytes2`) VALUES
(275482, 2754820, 33554432, 2);

DELETE FROM `waypoint_data` WHERE `id`= 2756070;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_Y`, `position_z`) VALUES
(2756070, 0, -10120.114, 1262.7188, 46.429115),
(2756070, 1, -10146.712, 1265.8923, 46.429115),
(2756070, 2, -10145.04,  1241.6545, 46.429115),
(2756070, 3, -10120.13,  1236.7916, 46.429115),
(2756070, 4, -10114.304, 1249.4635, 46.429115);

UPDATE `creature` SET `MovementType`= 3 WHERE `guid`= 275607;
DELETE FROM `creature_addon` WHERE `guid`= 275607;
INSERT INTO `creature_addon` (`guid`, `cyclicSplinePathId`, `bytes1`, `bytes2`) VALUES
(275607, 2756070, 33554432, 2);

DELETE FROM `waypoint_data` WHERE `id`= 2754890;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_Y`, `position_z`) VALUES
(2754890, 0, -10230.134, 1011.0955, 42.384518),
(2754890, 1, -10213.471, 1007.3854, 42.384518),
(2754890, 2, -10205.263, 1004.6702, 42.384518),
(2754890, 3, -10185.926, 1017.6268, 42.384518),
(2754890, 4, -10178.424, 1033.5781, 42.384518),
(2754890, 5, -10199.185, 1039.9774, 42.384518),
(2754890, 6, -10221.098, 1038.9132, 42.384518),
(2754890, 7, -10242.408, 1036.5608, 42.384518),
(2754890, 8, -10245.149, 1026.8889, 42.384518);

UPDATE `creature` SET `MovementType`= 3 WHERE `guid`= 275489;
DELETE FROM `creature_addon` WHERE `guid`= 275489;
INSERT INTO `creature_addon` (`guid`, `cyclicSplinePathId`, `bytes1`, `bytes2`) VALUES
(275489, 2754890, 33554432, 2);

DELETE FROM `creature_template_addon` WHERE `entry`= 1109;
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`) VALUES
(1109, 33554432, 2);

UPDATE `creature_template` SET `flags_extra`= 0 WHERE `entry`= 1109;
UPDATE `creature_template_movement` SET `Ground`= 1 WHERE `CreatureId`= 1109;
