-- 
DELETE FROM `gameobject` WHERE `guid` IN (71,73,76,80);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `state`) VALUES
(71, 177044, 0, 1, 1, 1559.05, 191.55, -62.1819, 1.13266, 0, 0, 0.536539, 0.843876, 300, 1),
(73, 177044, 0, 1, 1, 1631.2, 191.274, -62.1815, 2.06727, 0, 0, 0.859165, 0.511699, 300, 1),
(76, 177044, 0, 1, 1, 1631.97, 288.06, -62.1824, 4.14857, 0, 0, 0.875905, -0.48248, 300, 1),
(80, 177044, 0, 1, 1, 1560.58, 289.393, -62.1814, 5.07141, 0, 0, 0.569492, -0.8219, 300, 1);
