-- 
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=201253;
DELETE FROM `creature_addon` WHERE `guid` IN (201253);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(201253, 2012530, 0, 0, 0, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=2012530;
INSERT INTO `waypoint_data`(`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(2012530, 1, 4356.641, 3033.731, 360.52, 0, 0, 0, 0, 100, 0), 
(2012530, 2, 4356.061, 2986.438, 360.51, 4.75, 7000, 0, 0, 100, 0), 
(2012530, 3, 4357.132, 3055.515, 360.52, 4.75, 7000, 0, 0, 100, 0);
