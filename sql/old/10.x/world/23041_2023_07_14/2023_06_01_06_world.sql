-- Creature templates
UPDATE `creature_template` SET `faction`=16, `speed_run`=1.142857193946838378, `unit_flags2`=0 WHERE `entry`=20343; -- Charming Totem
UPDATE `creature_template` SET `speed_walk`=1, `unit_flags3`=524288 WHERE `entry`=18703; -- Sethekk Spirit
UPDATE `creature_template` SET `faction`=16 WHERE `entry`=18701; -- Dark Vortex
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=18473; -- Talon King Ikiss
UPDATE `creature_template` SET `unit_flags2`=2099200, `movementId`=144, `VerifiedBuild`=49801 WHERE `entry`=23035; -- Anzu
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=23136; -- Eagle Spirit
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=23135; -- Falcon Spirit
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=23134; -- Hawk Spirit
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=22515; -- World Trigger

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`!=0 AND `Entry` IN (22515));

UPDATE `creature_template_difficulty` SET `ContentTuningID`=224, `VerifiedBuild`=49801 WHERE (`DifficultyID`=2 AND `Entry` IN (23136,23135,23134));
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1068, `CreatureDifficultyID`=18966, `TypeFlags`=73, `VerifiedBuild`=49801 WHERE (`Entry`=23035 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-3, `LevelScalingDeltaMax`=-3, `ContentTuningID`=1068, `CreatureDifficultyID`=17568, `VerifiedBuild`=49801 WHERE (`Entry`=21931 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1068, `CreatureDifficultyID`=17546, `VerifiedBuild`=49801 WHERE (`Entry`=21904 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-1, `ContentTuningID`=1068, `CreatureDifficultyID`=17531, `VerifiedBuild`=49801 WHERE (`Entry`=21891 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-1, `LevelScalingDeltaMax`=-1, `ContentTuningID`=1068, `HealthScalingExpansion`=1, `CreatureDifficultyID`=16126, `VerifiedBuild`=49801 WHERE (`Entry`=20343 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1068, `CreatureDifficultyID`=15260, `VerifiedBuild`=49801 WHERE (`Entry`=19429 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `ContentTuningID`=1068, `CreatureDifficultyID`=15257, `VerifiedBuild`=49801 WHERE (`Entry`=19428 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1068, `CreatureDifficultyID`=14459, `VerifiedBuild`=49801 WHERE (`Entry`=18703 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1068, `CreatureDifficultyID`=14453, `VerifiedBuild`=49801 WHERE (`Entry`=18701 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1068, `HealthModifier`=32, `CreatureDifficultyID`=14208, `TypeFlags2`=128, `VerifiedBuild`=49801 WHERE (`Entry`=18473 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1068, `HealthModifier`=33, `CreatureDifficultyID`=14205, `TypeFlags2`=128, `VerifiedBuild`=49801 WHERE (`Entry`=18472 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1068, `CreatureDifficultyID`=14027, `VerifiedBuild`=49801 WHERE (`Entry`=18328 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1068, `CreatureDifficultyID`=14024, `VerifiedBuild`=49801 WHERE (`Entry`=18327 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1068, `CreatureDifficultyID`=14021, `VerifiedBuild`=49801 WHERE (`Entry`=18326 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1068, `CreatureDifficultyID`=14018, `VerifiedBuild`=49801 WHERE (`Entry`=18325 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1068, `CreatureDifficultyID`=14015, `VerifiedBuild`=49801 WHERE (`Entry`=18323 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1068, `CreatureDifficultyID`=14012, `VerifiedBuild`=49801 WHERE (`Entry`=18322 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `ContentTuningID`=1068, `CreatureDifficultyID`=14009, `VerifiedBuild`=49801 WHERE (`Entry`=18321 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1068, `CreatureDifficultyID`=14003, `VerifiedBuild`=49801 WHERE (`Entry`=18319 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1068, `CreatureDifficultyID`=14000, `VerifiedBuild`=49801 WHERE (`Entry`=18318 AND `DifficultyID`=2);

UPDATE `creature_template_difficulty` SET `VerifiedBuild`=49801 WHERE (`DifficultyID`=1 AND `Entry` IN (54847,54840,21931,21904,21891,20343,19429,19428,18956,18703,18701,18473,18472,18328,18327,18326,18325,18323,18322,18321,18320,18319,18318,2914));

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=18472 AND `DifficultyID`=2 AND `Idx`=1) OR (`CreatureEntry`=18472 AND `DifficultyID`=2 AND `Idx`=0) OR (`CreatureEntry`=18473 AND `DifficultyID`=2 AND `Idx`=1) OR (`CreatureEntry`=18473 AND `DifficultyID`=2 AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `DifficultyID`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(18472, 2, 1, 25461, 49801), -- Darkweaver Syth
(18472, 2, 0, 27633, 49801), -- Darkweaver Syth
(18473, 2, 1, 27632, 49801), -- Talon King Ikiss
(18473, 2, 0, 33834, 49801); -- Talon King Ikiss

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=49801 WHERE `DisplayID` IN (20588, 4566, 20729, 20730, 15291, 20725, 19788, 18347, 14368, 1132, 18636, 20599, 17865, 18628, 20573, 20598, 20683, 20682, 20572, 2958, 2957, 6303);
UPDATE `creature_model_info` SET `BoundingRadius`=0.210000008344650268, `CombatReach`=0.900000035762786865, `VerifiedBuild`=49801 WHERE `DisplayID`=18933;
UPDATE `creature_template_model` SET `VerifiedBuild`=49801 WHERE (`Idx`=0 AND `CreatureID` IN (18319,18320,18328,18701,21891,18326,18321,21904,18473,18318,18703,18327,2914,54847,19428,20343,18323,54840,18322,18956,18472,21931,19429,18325)) OR (`Idx`=3 AND `CreatureID`=2914) OR (`Idx`=2 AND `CreatureID` IN (2914,21931)) OR (`Idx`=1 AND `CreatureID` IN (2914,21931));
UPDATE `creature_model_info` SET `VerifiedBuild`=49801 WHERE `DisplayID` IN (10829, 21492);
UPDATE `creature_template_model` SET `VerifiedBuild`=49801 WHERE (`Idx`=0 AND `CreatureID` IN (23136,22515,23035,23134,23135)) OR (`Idx`=1 AND `CreatureID`=22515);
