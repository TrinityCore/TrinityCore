SET @OGUID:=6354;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 185454, 571, 1, 1, 5491.154, -2652.184, 303.9539, 2.460913, 0, 0, 0, 1, 120, 255, 1), -- 185454 (Area: 4275)
(@OGUID+1, 185456, 571, 1, 1, 3393.345, -2801.472, 211.3246, 5.410522, 0, 0, 0, 1, 120, 255, 1), -- 185456 (Area: 0)
(@OGUID+2, 185434, 571, 1, 1, 5527.56, -2646.927, 303.9539, 2.600535, 0, 0, 0, 1, 120, 255, 1); -- 185434 (Area: 4275)
