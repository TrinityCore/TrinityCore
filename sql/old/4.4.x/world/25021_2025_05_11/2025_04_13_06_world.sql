SET @CGUID := 3990098;
DELETE FROM `creature`WHERE `guid` BETWEEN  @CGUID+0 AND @CGUID+1;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN  @CGUID+0 AND @CGUID+1;

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 239974, 1, 1637, 5170, '0', '0', 0, 0, 0, 1596.21533203125, -4365.34375, 21.28902244567871093, 5.952373981475830078, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 60192), -- Denaa Hollowbark (Area: Valley of Strength - Difficulty: 0) CreateObject1
(@CGUID+1, 239945, 0, 1519, 5148, '0', '0', 0, 0, 0, -8823.1162109375, 635.57989501953125, 94.98770904541015625, 2.706097602844238281, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 60192); -- Alania Hollowbark (Area: Trade District - Difficulty: 0) CreateObject1

INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 426, 0, 0, 0, 0, ''); -- Alania Hollowbark
