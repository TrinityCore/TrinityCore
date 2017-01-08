--
-- Levers for heroic
SET @GUID := 200968;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) values
(@GUID  ,207218,644,0,0,2,1,0,0,-603.212,339.951,54.5611,3.14159,0,0,0,1,7200,255,1,0),
(@GUID+1,207219,644,0,0,2,1,0,0,-677.708,339.788,54.2874,6.21337,0,0,0,1,7200,255,1,0);
--
