-- 
DELETE FROM `creature` WHERE `guid` IN (86810, 86811);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(86810, 35001, 530, 1, 1, 0, 1, -1971.53, 5267.4, -38.7625, 3.52556, 300, 0, 0, 521300, 448950, 0),
(86811, 35002, 530, 1, 1, 0, 1, -1958.68, 5258.8, -38.7644, 4.7822, 300, 0, 0, 521300, 448950, 0);
