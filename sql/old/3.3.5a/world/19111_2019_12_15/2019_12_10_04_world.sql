-- 
DELETE FROM `creature` WHERE `guid` IN (120604,120605,120606);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(120604, 33600, 571, 1, 1, 0, 1, 8548.21, 954.800, 547.377, 4.88665, 300, 0, 0, 0, 0, 0),
(120605, 33601, 571, 1, 1, 0, 0, 8559.26, 939.371, 547.777, 6.25005, 300, 0, 0, 0, 0, 0),
(120606, 33603, 571, 1, 1, 0, 0, 8549.54, 944.761, 547.368, 1.03501, 300, 0, 0, 0, 0, 0);
