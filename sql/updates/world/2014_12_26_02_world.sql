SET @OGUID := 6166;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 181575, 533, 3, 1, 3465.175, -3940.402, 308.79, 2.443457, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- 181575 (Area: 3456)
(@OGUID+1, 181578, 533, 3, 1, 2493.018, -2921.778, 241.1933, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- 181578 (Area: -1)
(@OGUID+2, 181576, 533, 3, 1, 3539.016, -2936.821, 302.4756, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1); -- 181576 (Area: 3456)
