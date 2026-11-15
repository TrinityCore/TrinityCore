SET @SL_CGUID := 8000064;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @SL_CGUID+0 AND @SL_CGUID+8;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@SL_CGUID+0, 176222, 0, 1519, 5346, '0', 0, 0, 0, 0, -8304.2158203125, 880.2100830078125, 99.15404510498046875, 4.20131683349609375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Trey Wells (Area: Stormwind City Cemetery - Difficulty: 0) CreateObject1
(@SL_CGUID+1, 176238, 0, 1519, 5346, '0', 0, 0, 0, 0, -8383.0263671875, 915.5086669921875, 98.6052398681640625, 2.593044757843017578, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Abbe Tami (Area: Stormwind City Cemetery - Difficulty: 0) CreateObject1
(@SL_CGUID+2, 176241, 0, 1519, 5346, '0', 0, 0, 0, 1, -8367.654296875, 988.33331298828125, 96.33782958984375, 6.124119758605957031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Tasha Tallen (Area: Stormwind City Cemetery - Difficulty: 0) CreateObject1
(@SL_CGUID+3, 176242, 0, 1519, 5346, '0', 0, 0, 0, 0, -8285.486328125, 847.6319580078125, 101.1020431518554687, 1.465356945991516113, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Ryth the Melodious (Area: Stormwind City Cemetery - Difficulty: 0) CreateObject1 (Auras: 303032 - Placeholder [DNT])
(@SL_CGUID+4, 176224, 0, 1519, 5346, '0', 0, 0, 0, 0, -8415.0849609375, 909.30206298828125, 98.42950439453125, 4.546591758728027343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Elisa Perry (Area: Stormwind City Cemetery - Difficulty: 0) CreateObject1
(@SL_CGUID+5, 176240, 0, 1519, 5346, '0', 0, 0, 0, 0, -8412.3212890625, 920.78643798828125, 98.70714569091796875, 5.428269863128662109, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hiumi Togo (Area: Stormwind City Cemetery - Difficulty: 0) CreateObject1
(@SL_CGUID+6, 176234, 0, 1519, 5346, '0', 0, 0, 0, 0, -8434.2236328125, 934.47222900390625, 98.81858062744140625, 1.619816064834594726, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Harriet Mura (Area: Stormwind City Cemetery - Difficulty: 0) CreateObject1
(@SL_CGUID+7, 176231, 0, 1519, 5346, '0', 0, 0, 0, 0, -8435.28125, 936.2899169921875, 98.777862548828125, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Anna Taki (Area: Stormwind City Cemetery - Difficulty: 0) CreateObject1
(@SL_CGUID+8, 176236, 0, 1519, 5346, '0', 0, 0, 0, 0, -8456.8642578125, 936.342041015625, 97.40241241455078125, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609); -- Yoska Merce (Area: Stormwind City Cemetery - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @SL_CGUID+0 AND @SL_CGUID+8;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@SL_CGUID+0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Trey Wells
(@SL_CGUID+1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Abbe Tami
(@SL_CGUID+2, 0, 0, 8, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Tasha Tallen
(@SL_CGUID+3, 0, 0, 0, 0, 0, 1, 1, 0, 22046, 0, 0, 0, '303032'), -- Ryth the Melodious - 303032 - Placeholder [DNT]
(@SL_CGUID+4, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Elisa Perry
(@SL_CGUID+5, 0, 0, 8, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Hiumi Togo
(@SL_CGUID+6, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Harriet Mura
(@SL_CGUID+7, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Anna Taki
(@SL_CGUID+8, 0, 0, 0, 0, 0, 1, 1, 720, 0, 0, 0, 0, ''); -- Yoska Merce
