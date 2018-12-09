-- 
DELETE FROM `creature` WHERE `guid` IN (56954,56955,62014,77758);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnDifficulties`, `PhaseID`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(56954, 3681, 582, '0', 0, 29.50126, 0.000602, 24.44553, 0.03490658, 120, 0, 0), -- 3681 (Area: 452)
(56955, 24998, 582, '0', 0, 4.989703, -1.72901, 5.419243, 3.261605, 120, 0, 0), -- 24998 (Area: 452)
(62014, 3681, 586, '0', 0, -48.46594, 0.112139, 8.758898, 3.455752, 120, 0, 0), -- 3681 (Area: 452)
(77758, 25053, 586, '0', 0, -36.79112, -0.04812, 5.976357, 2.775074, 120, 0, 0); -- 25053 (Area: 452)
