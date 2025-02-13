SET @CGUID := 3990046;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 52408, 0, 1519, 5154, '0', '0', 0, 0, 0, -9009.4599609375, 862.2413330078125, 29.45246505737304687, 1.2042771577835083, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57564), -- Coridormi (Area: Mage Quarter - Difficulty: 0) CreateObject1 (Auras: 94223 - Generic Quest Invisibility 25)
(@CGUID+1, 5498, 0, 1519, 5154, '0', '0', 0, 0, 1, -9006.11328125, 885.3751220703125, 29.70399093627929687, 0.802851438522338867, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55141), -- Elsharin (Area: Mage Quarter - Difficulty: 0) CreateObject1
(@CGUID+2, 331, 0, 1519, 5154, '0', '0', 0, 0, 1, -9012.5341796875, 867.14190673828125, 29.70398712158203125, 3.735004663467407226, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55141), -- Maginor Dumas (Area: Mage Quarter - Difficulty: 0) CreateObject1
(@CGUID+3, 5497, 0, 1519, 5154, '0', '0', 0, 0, 0, -8989.69921875, 861.881103515625, 29.70398712158203125, 4.729842185974121093, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55141), -- Jennea Cannon (Area: Mage Quarter - Difficulty: 0) CreateObject1
(@CGUID+4, 2485, 0, 1519, 5154, '0', '0', 0, 0, 1, -8991.9013671875, 847.484130859375, 29.70399093627929687, 0.663225114345550537, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55141); -- Larimaine Purdue (Area: Mage Quarter - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 2, 1, 1, 0, 0, 0, 0, 0, 0, '94223'), -- Coridormi - 94223 - Generic Quest Invisibility 25
(@CGUID+1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Elsharin
(@CGUID+2, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Maginor Dumas
(@CGUID+3, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Jennea Cannon
(@CGUID+4, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''); -- Larimaine Purdue

DELETE FROM `creature_template_movement` WHERE `CreatureId`= 52408;
INSERT INTO `creature_template_movement` (`CreatureId`, `HoverInitiallyEnabled`) VALUES
(52408, 1);
