--
SET @CGUID := 452375;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
DELETE FROM `creature` WHERE `guid` BETWEEN 365716 AND 365721;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 62182, 1, 0, 0, 1, 0, 0, 0, 0, -1261.97, 3037.92, 89.2445, 1.75624, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(@CGUID+1, 62182, 1, 0, 0, 1, 0, 0, 0, 0, -1151.14, 3044.89, 89.4774, 3.29531, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(@CGUID+2, 62182, 1, 0, 0, 1, 0, 0, 0, 0, -1246.53, 3043.24, 89.2717, 1.63021, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(@CGUID+3, 62182, 1, 0, 0, 1, 0, 0, 0, 0, -1161.55, 3048.79, 89.4227, 5.26283, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(@CGUID+4, 62182, 1, 0, 0, 1, 0, 0, 0, 0, -1143.39, 3033.97, 89.2261, 5.75896, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(@CGUID+5, 62182, 1, 0, 0, 1, 0, 0, 0, 0, -1196.16, 3020.19, 85.3665, 1.23148, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0);