--
SET @CGUID := 81110;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID + 0 AND @CGUID + 5;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@CGUID+0, 1412, 530, 3518, 3518, '0', 0, 0, 0, -2023.83, 8911.35, 34.2775, 2.98928, 300, 10, 0, 8, 0, 1, 0, 0, 0, '', 0),
(@CGUID+1, 1412, 530, 3518, 3633, '0', 0, 0, 0, -2103.56, 8854.62, 24.6233, 0.58631, 300, 10, 0, 8, 0, 1, 0, 0, 0, '', 0),
(@CGUID+2, 1412, 530, 3518, 3633, '0', 0, 0, 0, -2105.73, 8904.69, 27.0793, 0.366985, 300, 10, 0, 8, 0, 1, 0, 0, 0, '', 0),
(@CGUID+3, 1412, 530, 3524, 3524, '0', 0, 0, 0, -4466.41, -11567.3, 13.3558, 5.58932, 300, 10, 0, 8, 0, 1, 0, 0, 0, '', 0),
(@CGUID+4, 1412, 530, 3524, 3524, '0', 0, 0, 0, -4786.42, -11723, 20.8626, 3.09852, 300, 10, 0, 8, 0, 1, 0, 0, 0, '', 0),
(@CGUID+5, 1412, 530, 3524, 3524, '0', 0, 0, 0, -4745.74, -12185.6, 18.5034, 5.9609, 300, 10, 0, 8, 0, 1, 0, 0, 0, '', 0);
