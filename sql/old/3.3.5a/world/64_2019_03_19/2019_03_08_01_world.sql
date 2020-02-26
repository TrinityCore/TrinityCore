-- 
UPDATE `gameobject` SET `position_x`= 756.897,  `position_y`= -1180.7, `position_z`= -118.596, `orientation`= 2.91469, `rotation2`=0.993571, `rotation3`=0.113208 WHERE `id`= 179703;
DELETE FROM `gameobject` WHERE `guid` IN (7085,7091,7098);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(7085, 178194, 409, 1, 1, 765.562, -995.398, -197.221, 2.19912, 0, 0, 0.891008, 0.453988, 604800, 255, 1),
(7091, 178107, 409, 1, 1, 838.951, -830.383, -230.206, 0.837757, 0, 0, 0.406736, 0.913546, 604800, 255, 1),
(7098, 178108, 409, 1, 1, 839.279, -831.058, -230.202, -1.37881, 0, 0, -0.636078, 0.771625, 604800, 255, 1);
