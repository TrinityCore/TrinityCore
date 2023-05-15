SET @CGUID := 9003851;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+19;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 200173, 2454, 14022, 14654, '0', 0, 0, 0, 1, 846.21875, 2094.189208984375, -4.28133821487426757, 4.436814308166503906, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 49474), -- Drakonid Poacher (Area: Slitherdrake Roost - Difficulty: 0) CreateObject1
(@CGUID+1, 200173, 2454, 14022, 14654, '0', 0, 0, 0, 1, 820.7716064453125, 2067.146728515625, -6.76614761352539062, 2.69597482681274414, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 49474), -- Drakonid Poacher (Area: Slitherdrake Roost - Difficulty: 0) CreateObject1
(@CGUID+2, 204204, 2454, 14022, 14654, '0', 0, 0, 0, 0, 937.203125, 2077.670166015625, -11.6984338760375976, 0.868576109409332275, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 49474), -- Zaqali Berserker (Area: Slitherdrake Roost - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+3, 202549, 2454, 14022, 14654, '0', 0, 0, 0, 0, 883.47222900390625, 2186.270751953125, -27.0328845977783203, 1.186231613159179687, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 49474), -- Drakonid Poacher (Area: Slitherdrake Roost - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+4, 204204, 2454, 14022, 14654, '0', 0, 0, 0, 0, 857.20489501953125, 2153.708251953125, -20.8694133758544921, 5.978754043579101562, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 49474), -- Zaqali Berserker (Area: Slitherdrake Roost - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+5, 204208, 2454, 14022, 14654, '0', 0, 0, 0, 0, 845.6788330078125, 2145.223876953125, -19.5291976928710937, 0, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 49474), -- Drakonid Poacher (Area: Slitherdrake Roost - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+6, 204204, 2454, 14022, 14654, '0', 0, 0, 0, 0, 944.779541015625, 2109.28466796875, -18.5180397033691406, 2.219065189361572265, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 49474), -- Zaqali Berserker (Area: Slitherdrake Roost - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+7, 200173, 2454, 14022, 14654, '0', 0, 0, 0, 1, 877.124755859375, 2016.476318359375, 0.495396137237548828, 1.118859291076660156, 120, 10, 0, 225838, 0, 1, 0, 0, 0, 49474), -- Drakonid Poacher (Area: Slitherdrake Roost - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+8, 200173, 2454, 14022, 14654, '0', 0, 0, 0, 1, 923.1788330078125, 2046.4722900390625, -1.84981703758239746, 6.135968685150146484, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 49474), -- Drakonid Poacher (Area: Slitherdrake Roost - Difficulty: 0) CreateObject1
(@CGUID+9, 200173, 2454, 14022, 14654, '0', 0, 0, 0, 1, 861.607666015625, 2027.9427490234375, -4.7063140869140625, 4.298270225524902343, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 49474), -- Drakonid Poacher (Area: Slitherdrake Roost - Difficulty: 0) CreateObject1
(@CGUID+10, 204204, 2454, 14022, 14654, '0', 0, 0, 0, 0, 861.9461669921875, 2124.439208984375, -12.07977294921875, 3.521567821502685546, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 49474), -- Zaqali Berserker (Area: Slitherdrake Roost - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+11, 204204, 2454, 14022, 14654, '0', 0, 0, 0, 0, 883.6007080078125, 2133.951416015625, -16.0343360900878906, 1.860213756561279296, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 49474), -- Zaqali Berserker (Area: Slitherdrake Roost - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+12, 202529, 2454, 14022, 14654, '0', 0, 0, 0, 0, 869.75, 2176.84716796875, -23.9877681732177734, 4.602481842041015625, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 49474), -- Zaqali Berserker (Area: Slitherdrake Roost - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+13, 204208, 2454, 14022, 14654, '0', 0, 0, 0, 0, 870.1961669921875, 2158.1494140625, -22.7052135467529296, 0, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 49474), -- Drakonid Poacher (Area: Slitherdrake Roost - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+14, 204204, 2454, 14022, 14654, '0', 0, 0, 0, 0, 911.04864501953125, 2119.26220703125, -13.7636928558349609, 3.52156829833984375, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 49474), -- Zaqali Berserker (Area: Slitherdrake Roost - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+15, 204208, 2454, 14022, 14654, '0', 0, 0, 0, 0, 910.06427001953125, 2079.63720703125, -3.23447227478027343, 0, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 49474), -- Drakonid Poacher (Area: Slitherdrake Roost - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+16, 200173, 2454, 14022, 14654, '0', 0, 0, 0, 1, 795.97393798828125, 2053.9619140625, -1.08932304382324218, 3.85231637954711914, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 49474), -- Drakonid Poacher (Area: Slitherdrake Roost - Difficulty: 0) CreateObject1
(@CGUID+17, 200173, 2454, 14022, 14654, '0', 0, 0, 0, 1, 786.07464599609375, 2027.2413330078125, -5.81964588165283203, 4.120373725891113281, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 49474), -- Drakonid Poacher (Area: Slitherdrake Roost - Difficulty: 0) CreateObject1
(@CGUID+18, 200186, 2454, 14022, 14654, '0', 0, 0, 0, 1, 861.28302001953125, 1926.423583984375, 14.59328556060791015, 1.778510093688964843, 120, 0, 0, 395217, 0, 0, 0, 0, 0, 49474), -- Overseer Xymra (Area: Slitherdrake Roost - Difficulty: 0) CreateObject1
(@CGUID+19, 200173, 2454, 14022, 14654, '0', 0, 0, 0, 1, 794.9876708984375, 2002.025634765625, -3.19710850715637207, 1.1249237060546875, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 49474); -- Drakonid Poacher (Area: Slitherdrake Roost - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+19;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+8, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Drakonid Poacher
(@CGUID+9, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Drakonid Poacher
(@CGUID+17, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Drakonid Poacher

UPDATE `creature_template` SET `faction`=168, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=200186; -- Overseer Xymra
UPDATE `creature_template` SET `faction`=168, `BaseAttackTime`=2000, `unit_flags`=570426176, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=204208; -- Drakonid Poacher
UPDATE `creature_template` SET `faction`=168, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=536904512, `unit_flags2`=18433, `unit_flags3`=8192, `dynamicflags`=128 WHERE `entry`=202549; -- Drakonid Poacher
UPDATE `creature_template` SET `faction`=168, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=200173; -- Drakonid Poacher
UPDATE `creature_template` SET `faction`=3318, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=536871744, `unit_flags2`=18433, `unit_flags3`=8192, `dynamicflags`=128 WHERE `entry`=202529; -- Zaqali Berserker

DELETE FROM `creature_template_addon` WHERE `entry` IN (202529, 204208, 202549, 204204);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(202529, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- 202529 (Zaqali Berserker) - Permanent Feign Death (NO Stun, Untrackable, Immune)
(204208, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- 204208 (Drakonid Poacher) - Permanent Feign Death (NO Stun, Untrackable, Immune)
(202549, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- 202549 (Drakonid Poacher) - Permanent Feign Death (NO Stun, Untrackable, Immune)
(204204, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'); -- 204204 (Zaqali Berserker) - Permanent Feign Death (NO Stun, Untrackable; Immune)

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (200186,200173));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(200186, 1, 59100, 0, 0, 0, 0, 0, 0, 0, 0, 49474), -- Overseer Xymra
(200173, 1, 161808, 0, 0, 0, 0, 0, 0, 0, 0, 49474); -- Drakonid Poacher

-- Scaling & Model
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (200186,202529,204208,202549,204204,200173));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(200186, 0, 0, 0, 2650, 49474),
(202529, 0, 0, 0, 2650, 49474),
(204208, 0, 0, 0, 2650, 49474),
(202549, 0, 0, 0, 2650, 49474),
(204204, 0, 0, 0, 2650, 49474),
(200173, 0, 0, 0, 2650, 49474);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=49474 WHERE (`DifficultyID`=0 AND `Entry` IN (203101,203132,204291,203095,203118));

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (102185, 111137, 111133, 111132, 111135, 111134, 111136);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(102185, 1.746612310409545898, 5.232499599456787109, 0, 49474),
(111137, 2.405673980712890625, 5, 0, 49474),
(111133, 2.496351242065429687, 5, 0, 49474),
(111132, 2.496351242065429687, 5, 0, 49474),
(111135, 2.405673980712890625, 5, 0, 49474),
(111134, 2.405673980712890625, 5, 0, 49474),
(111136, 2.405673980712890625, 5, 0, 49474);

UPDATE `creature_model_info` SET `VerifiedBuild`=49474 WHERE `DisplayID`=108428;
UPDATE `creature_model_info` SET `BoundingRadius`=1.132115364074707031, `CombatReach`=1.5, `VerifiedBuild`=49474 WHERE `DisplayID`=109293;

-- Waypoints for CGUID+7
SET @PATH := ((@CGUID+7) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 876.1771, 2014.524, 0.6420719, NULL, 0),
(@PATH, 1, 877.7309, 1990.799, 8.08582, NULL, 0),
(@PATH, 2, 876.6649, 1972.668, 11.50927, NULL, 0),
(@PATH, 3, 877.7309, 1990.799, 8.08582, NULL, 0),
(@PATH, 4, 876.1771, 2014.524, 0.6420719, NULL, 0),
(@PATH, 5, 881.8837, 2026.28, -0.06537215, NULL, 0);

UPDATE `creature` SET `position_x`= 876.1771, `position_y`= 2014.524, `position_z`= 0.6420719, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+7;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+7;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+7, @PATH, 1);

-- Waypoints for CGUID+1
SET @PATH := ((@CGUID+1) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 839.3906, 2058.253, -6.572495, NULL, 0),
(@PATH, 1, 880.3229, 2040.033, 1.654491, NULL, 0),
(@PATH, 2, 839.3906, 2058.253, -6.572495, NULL, 0),
(@PATH, 3, 810.4323, 2072.085, -5.616134, NULL, 0);

UPDATE `creature` SET `position_x`= 839.3906, `position_y`= 2058.253, `position_z`= -6.572495, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+1;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+1, @PATH, 1);

-- Waypoints for CGUID+19
SET @PATH := ((@CGUID+19) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 792.3524, 1996.512, -3.178757, NULL, 0),
(@PATH, 1, 788.9983, 1979.63, -0.1791203, NULL, 0),
(@PATH, 2, 805.2761, 1958.837, 7.20268, NULL, 0),
(@PATH, 3, 818.0677, 1942.986, 12.81573, NULL, 0),
(@PATH, 4, 805.2761, 1958.837, 7.20268, NULL, 0),
(@PATH, 5, 788.9983, 1979.63, -0.1791203, NULL, 0),
(@PATH, 6, 792.3524, 1996.512, -3.178757, NULL, 0),
(@PATH, 7, 800.3021, 2013.144, -4.898316, NULL, 0);

UPDATE `creature` SET `position_x`= 792.3524, `position_y`= 1996.512, `position_z`= -3.178757, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+19;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+19;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+19, @PATH, 1);
