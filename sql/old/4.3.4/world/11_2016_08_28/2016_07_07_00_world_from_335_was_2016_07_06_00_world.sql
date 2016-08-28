-- 
SET @GUID := 12459;
DELETE FROM `creature` WHERE `guid` IN (@GUID);
INSERT INTO `creature` (`guid`, `id`, `map`, `SpawnMask`, `modelid`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@GUID, 6491, 571, 1, 0, 4105.362, -4818.6, 76.074, 0.149361, 7200, 0, 0);
