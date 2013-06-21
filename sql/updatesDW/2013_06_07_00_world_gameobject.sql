DELETE FROM `gameobject` WHERE `guid` IN (100163,100164);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(100163, 195140, 1, 1, 1, 5505.87, -3622.85, 1567.37, 5.2441, 0, 0, 0.496482, -0.868047, 300, 0, 1),
(100164, 195139, 1, 1, 1, 5542.29, -3595.34, 1567.83, 2.57124, 0, 0, 0.959612, 0.281328, 300, 0, 1);
