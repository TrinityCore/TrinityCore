-- 
DELETE FROM `creature` WHERE `id` IN (44244,43012,50484, 47421);
DELETE FROM `creature` WHERE `guid` BETWEEN  289964 AND 289967;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseid`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(289964, 44244, 530,  1,  169,  0, 0, 9505.31, -6765.01, 16.5957, 4.7822, 120, 0, 0, 0, 0, 0),
(289965, 43012, 530,  1,  169,  0, 0, 9521.21, -6865.33, 18.8333, 5.16617, 120, 0, 0, 0, 0, 0),
(289966, 50484, 530,  1,  169,  0, 0, 9372.66, -7160.7, 9.26152, 3.90954, 120, 0, 0, 0, 0, 0),
(289967, 47421, 530,  1,  169,  0, 0, 9503.18, -6897.75, 28.4305, 2.70526, 120, 0, 0, 0, 0, 0);
