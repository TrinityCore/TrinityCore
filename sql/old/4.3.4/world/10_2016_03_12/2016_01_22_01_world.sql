--
UPDATE `gameobject` SET `id`=209061 WHERE `id`=214611; 
SET @OGUID:= 235184;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 209063, 1, 0, 0, 1, 1, 0, 3981.355, -2927.725, 1003.854, 5.135562, 0, 0, 0.8398378, 0.5428374, 120, 255, 1, 15595), -- 209063 (Area: 5040)
(@OGUID+1, 209060, 1, 0, 0, 1, 1, 0, 3981.355, -2927.725, 1003.854, 5.135562, 0, 0, 0.8398378, 0.5428374, 120, 255, 1, 15595), -- 209060 (Area: 5040)
(@OGUID+2, 209062, 1, 0, 0, 1, 1, 0, 3981.355, -2927.725, 1003.854, 5.135562, 0, 0, 0.8398378, 0.5428374, 120, 255, 1, 15595), -- 209062 (Area: 5040)
(@OGUID+3, 209063, 967, 0, 0, 1, 1, 0, -2313.86, -2387.19, 83.788, 6.11301, 0, 0, 0, 1, 120, 255, 1, 15595), -- 209063
(@OGUID+4, 209060, 967, 0, 0, 4, 1, 0, -2313.86, -2387.19, 83.788, 6.11301, 0, 0, 0, 1, 120, 255, 1, 15595), -- 209060
(@OGUID+5, 209062, 967, 0, 0, 8, 1, 0, -2313.86, -2387.19, 83.788, 6.11301, 0, 0, 0, 1, 120, 255, 1, 15595); -- 209062
UPDATE gameobject SET `position_z`=83.788 WHERE @guid=224760;
