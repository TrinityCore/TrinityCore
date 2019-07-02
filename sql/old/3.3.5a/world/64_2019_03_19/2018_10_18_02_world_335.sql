-- 
DELETE FROM `creature` WHERE `guid` IN (91800,91801,91885,92273,92276);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`,`spawndist`, `MovementType`) VALUES
(91800, 10603, 1, 1, 1, 0, 0, -840.999, -4906.85, 20.3147, 4.64331, 300, 0, 0),
(91801, 10603, 1, 1, 1, 0, 0, -851.004, -4917.86, 20.4611, 0.623161, 300, 0, 0),
(91885, 10603, 1, 1, 1, 0, 0, -839.728, -4912.160, 20.024, 2.658834, 300, 0, 0),
(92273, 10603, 1, 1, 1, 0, 0, -842.111, -4916.096, 20.381, 2.154336, 300, 0, 0),
(92276, 10603, 1, 1, 1, 0, 0, -845.914, -4918.507, 20.639, 1.644181, 300, 0, 0);

DELETE FROM `creature_template_addon` WHERE `entry`=10603;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(10603, 0, 0, 0, 0, 10, "26604");
UPDATE `creature` SET `MovementType`=0, `spawndist`=0, `orientation`= 5.6965 WHERE `id` IN (10578);
