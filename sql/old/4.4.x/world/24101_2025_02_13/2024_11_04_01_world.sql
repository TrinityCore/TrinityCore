SET @CGUID := 3990029;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 43277, 0, 1519, 5149, '0', 169, 0, 0, 1, -8819.9326171875, 342.8507080078125, 107.1308822631835937, 1.535889744758605957, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57294), -- Don Omar (Area: Old Town - Difficulty: 0) CreateObject1
(@CGUID+1, 44256, 0, 1519, 5149, '0', 169, 0, 0, 0, -8813.2099609375, 335.118011474609375, 107.1323394775390625, 1.169370532035827636, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57294), -- Greypaw (Area: Old Town - Difficulty: 0) CreateObject1
(@CGUID+2, 43294, 0, 1519, 5149, '0', 169, 0, 0, 0, -8821.3701171875, 343.013885498046875, 107.131072998046875, 0.890117883682250976, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57294), -- Gonzalez (Area: Old Town - Difficulty: 0) CreateObject1
(@CGUID+3, 44251, 0, 1519, 5149, '0', 169, 0, 0, 0, -8813.7900390625, 336.29901123046875, 107.1323394775390625, 0.733038306236267089, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57294), -- Alma Deering (Area: Old Town - Difficulty: 0) CreateObject1
(@CGUID+4, 5479, 0, 1519, 5149, '0', 169, 0, 0, 1, -8803.7900390625, 330.78472900390625, 115.548583984375, 1.29154360294342041, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57294), -- Wu Shen (Area: Old Town - Difficulty: 0) CreateObject1
(@CGUID+5, 914, 0, 1519, 5149, '0', 169, 0, 0, 1, -8793.6845703125, 342.63714599609375, 117.71441650390625, 3.839724302291870117, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57294), -- Ander Germaine (Area: Old Town - Difficulty: 0) CreateObject1
(@CGUID+6, 5480, 0, 1519, 5149, '0', 169, 0, 0, 1, -8803.0263671875, 333.3125, 115.548583984375, 4.433136463165283203, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57294); -- Ilsa Corbin (Area: Old Town - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, ''), -- Don Omar
(@CGUID+1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Greypaw
(@CGUID+2, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Gonzalez
(@CGUID+3, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Alma Deering
(@CGUID+4, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Wu Shen
(@CGUID+5, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Ander Germaine
(@CGUID+6, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''); -- Ilsa Corbin
