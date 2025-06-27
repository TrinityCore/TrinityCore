-- 
UPDATE `creature` SET `id`=358, `position_x`=2165, `position_y`=-4656.42, `position_z`=50.5176, `orientation`=2.79916 WHERE `guid`=6615;
DELETE FROM `creature` WHERE `guid` IN (86813);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(86813, 5194, 1, 1, 1, 0, 0, 2163.92, -4651.9, 50.6112, 3.61204, 180, 0, 0, 0, 0,0);
UPDATE `creature` SET `orientation`=0.484856 WHERE `guid`=6617;
