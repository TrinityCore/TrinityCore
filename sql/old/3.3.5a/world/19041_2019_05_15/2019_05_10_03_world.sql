-- 
DELETE FROM `creature` WHERE `guid` IN (104173, 104174, 104175);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES 
(104173, 18378, 571, 1, 1, 0, 0, 2750.36, 6127.08, 208.856, 5.44543, 180, 0, 0, 4050, 0, 0),
(104174, 18379, 571, 1, 1, 0, 0, 2761.16, 6137.27, 208.872, 5.35816, 180, 0, 0, 4050, 0, 0),
(104175, 18380, 571, 1, 1, 0, 0, 2779.98, 6154.28, 208.92, 5.35816, 180, 0, 0, 4050, 0, 0);
