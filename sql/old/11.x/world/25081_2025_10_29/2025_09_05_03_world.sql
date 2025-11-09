SET @CGUID := 10006839;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 245349, 2738, 15336, 15805, '0', '0', 0, 0, 0, 1998.6666259765625, 1762.5260009765625, -277.16796875, 4.3103790283203125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876); -- Zo'ropo (Area: Shadow Point - Difficulty: 0) CreateObject1

UPDATE `creature_template` SET `faction`=3558, `npcflag`=130, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=245349; -- Zo'ropo

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry`= 245349);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `TypeFlags3`) VALUES
(245349, 0, 10, 1, 1, 324745, 0x0, 0, 0); -- Zo'ropo

UPDATE `creature_template_difficulty` SET `ContentTuningID`=3008, `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=245349 AND `DifficultyID`=0); -- 245349 (Zo'ropo) - CanSwim

-- Vendor
DELETE FROM `npc_vendor` WHERE `entry`=245349;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(245349, 73, 249217, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Devouring Starcrusher
(245349, 72, 249216, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Umbral Starcrusher
(245349, 71, 249215, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Cosmic Starcrusher
(245349, 70, 249163, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Gamma Starcrusher
(245349, 69, 249162, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Tyrant Maul
(245349, 68, 249214, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Devouring Blade
(245349, 67, 249213, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Umbral Blade
(245349, 66, 249212, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Cosmic Blade
(245349, 65, 249161, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Gamma Blade
(245349, 64, 249211, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Devouring Hatchet
(245349, 63, 249210, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Umbral Hatchet
(245349, 62, 249209, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Cosmic Hatchet
(245349, 61, 249160, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Gamma Hatchet
(245349, 60, 249208, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Devouring Baton
(245349, 59, 249207, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Umbral Baton
(245349, 58, 249206, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Cosmic Baton
(245349, 57, 249159, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Gamma Baton
(245349, 56, 249205, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Devouring Caster
(245349, 55, 249204, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Umbral Caster
(245349, 54, 249203, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Cosmic Caster
(245349, 53, 249158, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Gamma Caster
(245349, 52, 249202, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Devouring Shard
(245349, 51, 249201, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Umbral Shard
(245349, 50, 249200, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Cosmic Shard
(245349, 49, 249157, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Gamma Shard
(245349, 48, 249199, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Devouring Phaseblade
(245349, 47, 249198, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Umbral Phaseblade
(245349, 46, 249197, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Cosmic Phaseblade
(245349, 45, 249156, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Gamma Phaseblade
(245349, 44, 249196, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Devouring Reactor
(245349, 43, 249195, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Umbral Reactor
(245349, 42, 249194, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Cosmic Reactor
(245349, 41, 249155, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Gamma Reactor
(245349, 40, 249193, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Devouring Greatsword
(245349, 39, 249192, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Umbral Greatsword
(245349, 38, 249191, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Cosmic Greatsword
(245349, 37, 249154, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Gamma Greatsword
(245349, 36, 249190, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Devouring Staff
(245349, 35, 249189, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Umbral Staff
(245349, 34, 249188, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Cosmic Staff
(245349, 33, 249153, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Gamma Staff
(245349, 32, 249187, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Devouring Ward
(245349, 31, 249186, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Umbral Ward
(245349, 30, 249185, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Cosmic Ward
(245349, 29, 249152, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Gamma Ward
(245349, 28, 249184, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Devouring Spire
(245349, 27, 249183, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Umbral Spire
(245349, 26, 249182, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Cosmic Spire
(245349, 25, 249151, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Gamma Spire
(245349, 24, 249181, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Devouring Warpblade
(245349, 23, 249180, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Umbral Warpblade
(245349, 22, 249179, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Cosmic Warpblade
(245349, 21, 249150, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Gamma Warpblade
(245349, 20, 249178, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Devouring Recurve
(245349, 19, 249177, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Umbral Recurve
(245349, 18, 249176, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Cosmic Recurve
(245349, 17, 249149, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Gamma Recurve
(245349, 16, 249175, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Devouring Lightshiv
(245349, 15, 249174, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Umbral Lightshiv
(245349, 14, 249173, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Cosmic Lightshiv
(245349, 13, 249148, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Gamma Lightshiv
(245349, 12, 249172, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Devouring Beamglaive
(245349, 11, 249171, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Umbral Beamglaive
(245349, 10, 249170, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Cosmic Beamglaive
(245349, 9, 249147, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Gamma Beamglaive
(245349, 8, 249169, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Devouring Plexhammer
(245349, 7, 249168, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Umbral Plexhammer
(245349, 6, 249167, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Cosmic Plexhammer
(245349, 5, 249146, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Gamma Plexhammer
(245349, 4, 249166, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Devouring Shockmace
(245349, 3, 249165, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Umbral Shockmace
(245349, 2, 249164, 0, 10586, 1, 0, 0, 62876), -- Manaforge Raider's Cosmic Shockmace
(245349, 1, 249145, 0, 10586, 1, 0, 0, 62876); -- Manaforge Raider's Gamma Shockmace
