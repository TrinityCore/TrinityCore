-- 
DELETE FROM `creature` WHERE `id`  IN (21455, 23148) AND `guid` IN (106218,106222);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`,  `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(106218, 21455, 530, 1, 1, 1, -3422.27, 1122.06, 46.7247, 0.86922, 180, 0, 0),
(106222, 23148, 530, 1, 1, 0, -5137.82, 561.520, 84.3600, 4.74700, 180, 0, 0); 

