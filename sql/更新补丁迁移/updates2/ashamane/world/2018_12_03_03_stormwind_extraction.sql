DELETE FROM `areatrigger` WHERE `guid` = 49;
INSERT INTO `areatrigger` (`guid`, `id`, `map_id`, `spawn_mask`, `position_x`, `position_y`, `position_z`, `ScriptName`) VALUES
(49, 100007, 1904, 4096, -8322.06, 1389.50, 6.22794, 'at_se_boat_final');

DELETE FROM `creature_summon_groups` WHERE summonerId = 1904 AND groupId = 80;
INSERT INTO `creature_summon_groups` VALUES
(1904, 2, 80, 134201, -8290.900391, 1404.900024, 4.812300, 4.714060, 6, 0),
(1904, 2, 80, 138161, -8298.809570, 1406.089966, 4.502620, 4.836300, 6, 0),
(1904, 2, 80, 138161, -8294.490234, 1405.680054, 4.519910, 4.836300, 6, 0),
(1904, 2, 80, 138161, -8287.250000, 1405.770020, 4.472690, 4.836300, 6, 0),
(1904, 2, 80, 138161, -8283.469727, 1406.270020, 4.466890, 4.836300, 6, 0);

DELETE FROM creature WHERE guid IN (280000970, 280000968, 280000971, 280000969, 280000967);
