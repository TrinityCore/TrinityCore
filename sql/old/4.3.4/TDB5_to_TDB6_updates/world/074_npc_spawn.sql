-- Fix : Add Captain Beld
SET @CGUID := 25; -- set by TDB, need one

DELETE FROM `creature` WHERE `guid`=@CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID, 6124, 1, 1, 0, -5920.449, -2034.187, 400.8329, 3.298672, 300, 0, 0);

DELETE FROM `creature_equip_template` WHERE `entry`=6124;
INSERT INTO `creature_equip_template` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(6124, 1, 1909, 2052, 0);
