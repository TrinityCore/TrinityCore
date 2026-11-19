-- 
-- Spawn Firelands portal
SET @OGUID:= 300914;
DELETE FROM `gameobject` WHERE `guid`=@OGUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`,  `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 214611, 720, 0, 0, 120, 169, -560.341, 322.966, 115.636, 5.95157, 0, 0, -0.165047, 0.986286, 7200, 255, 1, 15595);

-- correct spawn location for creature ID 6124, Captain Beld:
UPDATE `creature` SET `map`= 0 WHERE `guid`= 349908 AND `id`= 6124;
