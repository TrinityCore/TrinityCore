-- 
DELETE FROM `creature` WHERE `guid`=110942;
DELETE FROM `creature_addon` WHERE `guid` IN (152125,110942);
INSERT INTO `creature_addon` (`guid`, `bytes1`, `bytes2`) VALUES
(152125, 1, 1);
DELETE FROM `gameobject` WHERE `guid`=6659;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(6659, 191726, 571, 0, 0, 1, 1, 7312.41, -1610.48, 944.294, 4.99164, 0, 0, -0.6018143, 0.7986361, 120, 255, 1, 23420); 
