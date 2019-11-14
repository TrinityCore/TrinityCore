-- 
DELETE FROM `gameobject` WHERE `guid` IN (9266,9268) AND `id` IN (184072,184092);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(9266, 184072, 530, 3523, 3741, 1, 1, 4671.726, 2512.325, 240.0145, 0.802851, 0, 0, 0.3907309, 0.920505, 120, 255, 1, 15354), -- 184072 (Area: 3741 - Difficulty: 0)
(9268, 184092, 530, 3523, 3741, 1, 1, 4671.729, 2512.325, 242.9658, 2.600535, 0, 0, 0.9636297, 0.267241, 120, 255, 1, 15354); -- 184092 (Area: 3741 - Difficulty: 0)
