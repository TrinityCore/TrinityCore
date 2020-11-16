--
UPDATE `creature_template` SET `speed_walk` = 0.6, `speed_run` = 0.21428, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 33555200 WHERE `entry` = 17408;
DELETE FROM `creature_template_addon` WHERE `entry` = 17408;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(17408,0,0,0,1,0,0,"30627");

DELETE FROM `creature` WHERE `guid` IN (131087,131088) AND `id` = 17408;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`, `VerifiedBuild`) VALUES
(131087, 17408, 530, 1, 1, 0, 2887.78, 3226.63, 174.500, 2.43434, 3600, 15, 1, 14007),
(131088, 17408, 530, 1, 1, 0, 2796.53, 4342.95, 143.658, 5.30526, 3600, 15, 1, 14007);
