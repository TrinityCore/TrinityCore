-- 
DELETE FROM `creature` WHERE `guid` IN (62786,62787);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`,`spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(62786, 16070, 0, 1, 1, 0, 0, -4641.59, -1106.97, 501.389, 1.11701, 300, 0, 0, 1220, 0, 0),
(62787, 16069, 0, 1, 1, 0, 0, -4639.4409, -1108.212, 501.323, 1.050256, 300, 0, 0, 0, 0, 0);
UPDATE `creature` SET `orientation`=1.050256 WHERE `guid`=1792;
