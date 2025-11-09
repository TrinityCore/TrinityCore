SET @CGUID := 10006842;

SET @GGUID := 100098;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 6491, 2444, 13862, 0, '0', 0, 0, 0, 0, -104.864593505859375, -1202.48095703125, 847.81988525390625, 1.305020809173583984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163); -- Spirit Healer (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 10848 - Shroud of Death)

-- Graveyard
DELETE FROM `graveyard_zone` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+0;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(@GGUID+0, 13862, 'Valdrakken - The Emerald Enclave');

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+0;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(@GGUID+0, 2444, -103.73, -1198.4, 847.713, 4.4217214, 'Valdrakken - The Emerald Enclave - GY');
