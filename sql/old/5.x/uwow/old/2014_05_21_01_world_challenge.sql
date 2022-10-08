-- ------------------------------------
-- Challenge Mogu'shan Palace
-- ------------------------------------

-- Phase mask only for heroic
update gameobject SET `spawnMask` = `spawnMask` |256 WHERE map = 994;
update creature SET `spawnMask` = `spawnMask` | 256 WHERE map = 994;

-- Check
DELETE FROM `gameobject` WHERE map = 994 AND id in (211674, 211991, 211992, 211989, 211988, 212972);
INSERT INTO `gameobject` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`) VALUES
-- 994
(212972, 994, 6182, 6470, 256, 1, -3968.47, -2564.27, 24.0608, 4.75821, 0, 0, 0.690723, -0.723119, 300, 0, 1, 0),
(211674, 994, 6182, 6470, 256, 1, -3969.384, -2556.505, 26.93957, 3.118482, 0, 0, 0, 1, 7200, 0, 1, 0);


