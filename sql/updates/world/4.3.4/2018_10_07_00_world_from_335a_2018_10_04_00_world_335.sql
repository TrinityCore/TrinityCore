/*
-- 
DELETE FROM `creature` WHERE `guid`=86808;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(86808, 7319, 1, 1, 1, 0, 0, 10980, 1731.3, 1303.1, 5.14113, 120, 5, 0, 0, 0, 1);

DELETE FROM `pool_template` WHERE `entry`=492;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(492,1,"Lady Sathrah");
DELETE FROM `pool_creature` WHERE `pool_entry`=492;
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(12596,492,0,"Lady Sathrah - Spawn 1"),
(86808,492,0,"Lady Sathrah - Spawn 2");
*/
