-- 
DELETE FROM `creature` WHERE `guid`=111426 AND `id`=24762;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`,  `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(111426, 24762,585,1,1,1,231.641968, -183.911377, -9.484764, 1.539382,86400,0,2);

DELETE FROM `creature_addon` WHERE `guid` IN (111426);
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes1`, `bytes2`, `auras`) VALUES
(111426,1114260,0,1,"");

DELETE FROM `waypoint_data` WHERE `id` IN (1114260);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action_chance`) VALUES
(1114260,1,231.641968, -183.911377, -9.484764, 1.539382,0,0,100),
(1114260,2,231.618057, -168.050690, -9.459627, 1.600643,0,0,100),
(1114260,3,231.730774, -137.755692, -9.459627, 1.577081,0,0,100),
(1114260,4,231.524628, -115.706757, -9.438408, 1.569227,0,0,100),
(1114260,5,231.730774, -137.755692, -9.459627, 4.717081,0,0,100),
(1114260,6,231.618057, -168.050690, -9.459627, 4.700643,0,0,100),
(1114260,7,231.641968, -183.911377, -9.484764, 4.739382,0,0,100);
