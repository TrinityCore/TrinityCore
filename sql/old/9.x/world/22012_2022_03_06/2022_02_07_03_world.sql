-- 
SET @CGUID := 1050589;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 156280, 2261, 10424, 10639, '0', 14350, 0, 0, 0, 37.83321762084960937, -1.40558588504791259, 12.40759944915771484, 3.31911778450012207, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079); -- Captain Garrick (Area: -Unknown- - Difficulty: 0)
