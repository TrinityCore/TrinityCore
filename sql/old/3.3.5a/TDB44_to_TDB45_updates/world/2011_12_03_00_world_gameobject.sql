DELETE FROM `gameobject` WHERE `guid` IN (207,215) AND `id`=300245; -- TEMP Forgemaster''s Anvil
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(207, 300245, 658, 3, 1, 637.954, -209.544, 533.269, 3.53903, 0, 0, 0.980321, -0.197413, 300, 0, 1),
(215, 300245, 658, 3, 1, 726.268, -237.654, 534.13, 5.5732, 0, 0, 0.347582, -0.93765, 300, 0, 1);
