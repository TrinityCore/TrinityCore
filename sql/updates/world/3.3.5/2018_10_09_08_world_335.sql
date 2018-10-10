-- 
DELETE FROM `creature` WHERE `guid` IN (86823,86824);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(86823, 450, 0, 1, 1, 0, 0, -11155.437, 1709.242, 42.898, 2.968015, 300, 0, 0, 0, 0, 0),
(86824, 450, 0, 1, 1, 0, 0, -11328.241, 1724.133, 37.056, 5.891060, 300, 0, 0, 0, 0, 0);
