--
UPDATE `gameobject` SET `animprogress` = 255, `VerifiedBuild` = 12340 WHERE `guid` BETWEEN 151278 AND 151283 AND `id` = 192676;
DELETE FROM `gameobject` WHERE `guid` IN (30024,30030) AND `id` = 192676;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `ScriptName`, `VerifiedBuild`) values
(30024,192676,1,0,0,1,2,7820.66,-2244.36,463.302,1.76278,0,0,0.771625,0.636078,120,255,1,'',15595),
(30030,192676,1,0,0,1,2,7812.99,-2158.31,478.524,1.0472,0,0,0.5,0.866025,120,255,1,'',15595);
