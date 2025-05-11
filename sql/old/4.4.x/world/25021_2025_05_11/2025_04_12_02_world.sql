SET @CGUID := 3990093;

DELETE FROM `creature` WHERE `guid`= @CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID, 58154, 0, 1519, 5149, '0', 169, 0, 0, 0, -8808.22265625, 350.854156494140625, 107.132568359375, 4.590215682983398437, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 60142); -- Toren Landow (Area: Old Town - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''); -- Toren Landow
