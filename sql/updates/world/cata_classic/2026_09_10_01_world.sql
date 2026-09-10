DELETE FROM `disables` WHERE `sourceType` = 1 AND `entry` = 2158;

DELETE FROM `creature` WHERE `guid`= 3990100;
DELETE FROM `creature_addon` WHERE `guid`= 3990100;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`) VALUES
(3990100, 6774, 0, 12, 9, '0', '0', -9044.56, -45.9817, 88.4193, 3.08923, 300);

DELETE FROM `creature_queststarter` WHERE `id`= 6774;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(6774, 2158);
