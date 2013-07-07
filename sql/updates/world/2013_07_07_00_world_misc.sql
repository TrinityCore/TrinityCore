-- Fix some runtime errors
UPDATE `creature` SET `MovementType`=0 WHERE `guid`=142347,142368,142371,142376,142378,142379;
UPDATE `creature` SET `modelid`=0 WHERE `id` = 30169;
-- Add missing doors on old Hyjal
DELETE FROM `gameobject` WHERE `guid` IN (4658,4695);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(4658, 182060, 534, 1, 1, 4270.964, -4143.027, 870.7232, 6.020715, 0, 0, 0.8829476, -0.4694716, 7200, 255, 1),
(4695, 182061, 534, 1, 1, 4204.479, -4112.277, 877.9128, 4.985382, 0, 0, 0.8829476, -0.4694716, 7200, 255, 1);
