 -- Fix plates on boss_spine_of_deathwing
DELETE FROM `gameobject` WHERE `id` in (209632,209623,209631);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`) VALUES
(null, 209632, 967, 5892, 5960, 120, 1, 0, -13855.4, -13597.8, 272.356, 1.58825, 0, 0, 0.71325, 0.70091, 300, 255, 1, 0, NULL),
(null, 209623, 967, 5892, 5960, 120, 1, 0, -13855, -13639.7, 267.866, 1.58825, 0, 0, 0.71325, 0.70091, 300, 255, 1, 0, NULL),
(null, 209631, 967, 5892, 5960, 120, 1, 0, -13855, -13619.1, 269.869, 1.58825, 0, 0, 0.71325, 0.70091, 300, 255, 1, 0, NULL);

 -- Update HP on boss_madness_of_deathwing
UPDATE `creature_template` SET `exp` = '3' WHERE `entry` in
(56173,56168,56846,56167,56471,56581,56188,56263,56359,56262,56545,57479,56332,56311,56724,56710,57798,57962,57693,56844,56699,56307);
