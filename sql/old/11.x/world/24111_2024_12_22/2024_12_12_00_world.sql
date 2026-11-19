SET @CGUID := 10004751;
SET @OGUID := 10001197;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 217815, 2552, 14717, 14837, '0', 0, 0, 0, 0, 2646.009521484375, -4063.28125, 80.3326416015625, 1.475708723068237304, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Shalehoof (Area: Durgaz Cabin - Difficulty: 0) CreateObject1
(@CGUID+1, 214640, 2552, 14717, 14837, '0', 0, 0, 0, 1, 2639.991455078125, -4062.546875, 80.3326416015625, 0.319552153348922729, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Harvester Farnee (Area: Durgaz Cabin - Difficulty: 0) CreateObject1
(@CGUID+2, 213691, 2552, 14717, 14837, '0', 0, 0, 0, 1, 2644.09375, -4062.920166015625, 80.3326416015625, 6.276271343231201171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Harmot (Area: Durgaz Cabin - Difficulty: 0) CreateObject1
(@CGUID+3, 230117, 2552, 14717, 14837, '0', 0, 0, 0, 0, 2645.989501953125, -3998.053955078125, 72.770538330078125, 3.195847511291503906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Aschbie (Area: Durgaz Cabin - Difficulty: 0) CreateObject1
(@CGUID+4, 217542, 2552, 14717, 14837, '0', 0, 0, 0, 0, 2673.7109375, -4103.9619140625, 86.51788330078125, 1.601612806320190429, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689); -- Drelda (Area: Durgaz Cabin - Difficulty: 0) CreateObject1

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+14;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 446160, 2552, 14717, 14837, '0', 0, 0, 2630.926513671875, -3997.242431640625, 72.16313934326171875, 1.483530640602111816, 0, 0, 0.67559051513671875, 0.737277030944824218, 120, 255, 1, 57689), -- Chair (Area: Durgaz Cabin - Difficulty: 0) CreateObject1
(@OGUID+1, 446161, 2552, 14717, 14837, '0', 0, 0, 2629.4658203125, -3995.871337890625, 72.16313934326171875, 6.257008075714111328, 0, 0, -0.01308822631835937, 0.999914348125457763, 120, 255, 1, 57689), -- Chair (Area: Durgaz Cabin - Difficulty: 0) CreateObject1
(@OGUID+2, 433148, 2552, 14717, 14837, '0', 0, 0, 2532.682373046875, -4036.413330078125, 51.16840362548828125, 3.935721635818481445, 0, 0, -0.92220020294189453, 0.386712819337844848, 120, 255, 1, 57689), -- Chair (Area: Durgaz Cabin - Difficulty: 0) CreateObject1
(@OGUID+3, 446162, 2552, 14717, 14837, '0', 0, 0, 2631.13134765625, -3993.83740234375, 72.16313934326171875, 4.668757438659667968, 0, 0, -0.72236347198486328, 0.691513597965240478, 120, 255, 1, 57689), -- Chair (Area: Durgaz Cabin - Difficulty: 0) CreateObject1
(@OGUID+4, 446163, 2552, 14717, 14837, '0', 0, 0, 2633.296142578125, -3997.3837890625, 72.16313934326171875, 1.527163028717041015, 0, 0, 0.6915130615234375, 0.722363948822021484, 120, 255, 1, 57689), -- Chair (Area: Durgaz Cabin - Difficulty: 0) CreateObject1
(@OGUID+5, 433144, 2552, 14717, 14837, '0', 0, 0, 2648.1494140625, -4065.81591796875, 80.2679901123046875, 4.136432647705078125, 0, 0, -0.87881660461425781, 0.477159708738327026, 120, 255, 1, 57689), -- Chair (Area: Durgaz Cabin - Difficulty: 0) CreateObject1
(@OGUID+6, 433145, 2552, 14717, 14837, '0', 0, 0, 2652.257080078125, -4067.132080078125, 80.25000762939453125, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 120, 255, 1, 57689), -- Forge (Area: Durgaz Cabin - Difficulty: 0) CreateObject1
(@OGUID+7, 433146, 2552, 14717, 14837, '0', 0, 0, 2530.9072265625, -4035.479248046875, 51.171875, 4.747295856475830078, 0, 0, -0.69465827941894531, 0.719339847564697265, 120, 255, 1, 57689), -- Chair (Area: Durgaz Cabin - Difficulty: 0) CreateObject1
(@OGUID+8, 433147, 2552, 14717, 14837, '0', 0, 0, 2531.471435546875, -4039.953125, 51.17595291137695312, 2.76633763313293457, 0, 0, 0.982449531555175781, 0.186528548598289489, 120, 255, 1, 57689), -- Chair (Area: Durgaz Cabin - Difficulty: 0) CreateObject1
(@OGUID+9, 446164, 2552, 14717, 14837, '0', 0, 0, 2634.982421875, -3995.933837890625, 72.16313934326171875, 3.071766138076782226, 0, 0, 0.999390602111816406, 0.034906134009361267, 120, 255, 1, 57689), -- Chair (Area: Durgaz Cabin - Difficulty: 0) CreateObject1
(@OGUID+10, 433143, 2552, 14717, 14837, '0', 0, 0, 2646.572021484375, -4073.060791015625, 80.25, 3.045581579208374023, 0, 0, 0.99884796142578125, 0.047987140715122222, 120, 255, 1, 57689), -- Anvil (Area: Durgaz Cabin - Difficulty: 0) CreateObject1
(@OGUID+11, 446165, 2552, 14717, 14837, '0', 0, 0, 2633.385498046875, -3993.92578125, 72.16313934326171875, 4.747298717498779296, 0, 0, -0.6946573257446289, 0.719340801239013671, 120, 255, 1, 57689), -- Chair (Area: Durgaz Cabin - Difficulty: 0) CreateObject1
(@OGUID+12, 463994, 2552, 14717, 14837, '0', 0, 0, 2639.1796875, -3984.0869140625, 73.1550140380859375, 5.476319313049316406, 0, 0, -0.392578125, 0.919718682765960693, 120, 255, 1, 57689), -- Observational Notes: Cinderbees (Area: Durgaz Cabin - Difficulty: 0) CreateObject1
(@OGUID+13, 423415, 2552, 14717, 14837, '0', 0, 0, 2631.483642578125, -4047.3994140625, 81.5147552490234375, 0, 0, 0, 0, 1, 120, 255, 1, 57689), -- Pot of Fire Honey (Area: Durgaz Cabin - Difficulty: 0) CreateObject1
(@OGUID+14, 423370, 2552, 14717, 14837, '0', 0, 0, 2646.21533203125, -4072.9619140625, 81.19947052001953125, 0, 0, 0, 0, 1, 120, 255, 1, 57689); -- Earthen Mortar (Area: Durgaz Cabin - Difficulty: 0) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+14;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0.694658875465393066, 0.719339311122894287, 0, 0), -- Chair
(@OGUID+1, 0, 0, 0.694658875465393066, 0.719339311122894287, 0, 0), -- Chair
(@OGUID+3, 0, 0, 0.694658875465393066, 0.719339311122894287, 0, 0), -- Chair
(@OGUID+4, 0, 0, 0.694658875465393066, 0.719339311122894287, 0, 0), -- Chair
(@OGUID+9, 0, 0, 0.694658875465393066, 0.719339311122894287, 0, 0), -- Chair
(@OGUID+11, 0, 0, 0.694658875465393066, 0.719339311122894287, 0, 0), -- Chair
(@OGUID+12, 0, 0, 0, 1, 2100, 0); -- Observational Notes: Cinderbees

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 230117;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(230117, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 230117 (Aschbie)

-- Template
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=230117; -- Aschbie
UPDATE `creature_template` SET `faction`=3407, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=213691; -- Harmot
UPDATE `creature_template` SET `faction`=3407, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=214640; -- Harvester Farnee
UPDATE `creature_template` SET `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=217815; -- Shalehoof
UPDATE `creature_template` SET `faction`=35, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=217542; -- Drelda

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=213691 AND `DifficultyID`=0); -- 213691 (Harmot) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=214640 AND `DifficultyID`=0); -- 214640 (Harvester Farnee) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x30000000, `VerifiedBuild`=57689 WHERE (`Entry`=230117 AND `DifficultyID`=0); -- 230117 (Aschbie) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=217815 AND `DifficultyID`=0); -- 217815 (Shalehoof) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=217542 AND `DifficultyID`=0); -- 217542 (Drelda) - CanSwim

-- Quest
DELETE FROM `creature_questender` WHERE (`id`=214640 AND `quest`=78754);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(214640, 78754, 57689); -- Lost Delivery ended by Harvester Farnee
