-- 
DELETE FROM `gameobject` WHERE `guid` IN (6680,6683,6686);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`,`position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES 
(6680, 180634, 531, 0, 0, 1, 1, -8929.61, 1344.38, -104.211, -2.43473, 0, 0, -0.938191, 0.346119, 604800, 100, 1, 0),
(6683, 180635, 531, 0, 0, 1, 1, -9016.36, 1330.68, -104.211, 2.80125, 0, 0, 0.985556, 0.169351, 604800, 100, 1, 0),
(6686, 180636, 531, 0, 0, 1, 1, -8429.59, 2048.81, 153.309, -2.76634, 0, 0, -0.98245, 0.186527, 604800, 100, 1, 0);
