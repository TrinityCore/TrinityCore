-- 
DELETE FROM `gameobject` WHERE `guid` IN (99956,9381,9385,9386);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(99956, 184643, 530, 0, 0, 1, 1, 3964.10376, 2008.44445, 383.94104, 0.176697, 0, 0, 0, 1, 180, 0, 1, 0),
(9381, 184643, 530, 0, 0, 1, 1, 3930.18457, 2038.26062, 383.50134, 1.720004, 0, 0, 0, 1, 180, 0, 1, 0),
(9385, 184643, 530, 0, 0, 1, 1, 3902.93530, 1996.42260, 383.64352, 3.275094, 0, 0, 0, 1, 180, 0, 1, 0),
(9386, 184643, 530, 0, 0, 1, 1, 3942.99975, 1970.09973, 383.32125, 5.105074, 0, 0, 0, 1, 180, 0, 1, 0);
