-- 
DELETE FROM `creature` WHERE `id`  IN (23265) AND `guid` IN (109724);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`,  `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(109724, 23265, 530, 1, 1, 1, -1333.53, 7221.96, 33.583, 2.26893, 300, 0, 0);
