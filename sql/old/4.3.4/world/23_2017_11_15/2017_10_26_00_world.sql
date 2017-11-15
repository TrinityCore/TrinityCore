--
SET @CGUID := 251548;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@CGUID+0, 15500, 1, 5695, 0, 1, 169, 0, 0, 0, -8411.228, 1480.601, 25.6424, 0.9075712, 120, 0, 0, 0, 0, 0, 0, 0, 0, "", 15595), -- 15500 (Area: 0 - Difficulty: 0)
(@CGUID+1, 15499, 1, 5695, 0, 1, 169, 0, 0, 0, -8412.529, 1483.203, 26.07258, 0.2617994, 120, 0, 0, 0, 0, 0, 0, 0, 0, "", 15595), -- 15499 (Area: 0 - Difficulty: 0)
(@CGUID+2, 15498, 1, 5695, 0, 1, 169, 0, 0, 0, -8412.724, 1486.411, 26.46852, 0.122173, 120, 0, 0, 0, 0, 0, 0, 0, 0, "", 15595); -- 15498 (Area: 0 - Difficulty: 0)

