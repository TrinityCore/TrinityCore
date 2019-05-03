-- The Stagnant Oasis
DELETE FROM `event_scripts` WHERE `id` = 525;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(525, 2, 9, 825, 60, 0, 0, 0, 0, 0),
(525, 2, 9, 8194, 60, 0, 0, 0, 0, 0),
(525, 2, 9, 8195, 60, 0, 0, 0, 0, 0),
(525, 2, 9, 8196, 60, 0, 0, 0, 0, 0),
(525, 2, 9, 8197, 60, 0, 0, 0, 0, 0);

DELETE FROM `gameobject` WHERE `id` = 3743;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(825, 3743, 1, 1, 1, -1278.97, -3008.1, 72.0716, 0.86185, 0, 0, 0.417711, 0.90858, -1, 100, 1),
(8194, 3743, 1, 1, 1, -1275.4, -3006.46, 72.5618, 1.29382, 0, 0, 0.602723, 0.79795, -1, 100, 1),
(8195, 3743, 1, 1, 1, -1279.63, -3014.32, 71.7535, 0.539832, 0, 0, 0.26665, 0.963793, -1, 100, 1),
(8196, 3743, 1, 1, 1, -1277.91, -3016.5, 72.699, 0.889334, 0, 0, 0.430157, 0.902754, -1, 100, 1),
(8197, 3743, 1, 1, 1, -1274.86, -3016.2, 72.6146, 1.63939, 0, 0, 0.730938, 0.682444, -1, 100, 1);

DELETE FROM `gameobject_loot_template` WHERE `entry` = 2603;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `MinCount`, `Maxcount`) VALUES
(2603, 5066, 100, 1, 0, 1, 1);
