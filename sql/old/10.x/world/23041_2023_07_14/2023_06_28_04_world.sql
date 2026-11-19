-- Creature templates
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=54668; -- Nahuud
UPDATE `creature_template` SET `speed_run`=1.142857193946838378, `unit_flags3`=1 WHERE `entry`=18206; -- Wastewalker Captive
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=17964; -- Wastewalker Worker
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=17963; -- Wastewalker Slave
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=17960; -- Coilfang Soothsayer
UPDATE `creature_template` SET `faction`=1660, `unit_flags`=33536 WHERE `entry`=17893; -- Naturalist Bite
UPDATE `creature_template` SET `faction`=74, `speed_walk`=1, `speed_run`=1, `unit_flags2`=0 WHERE `entry`=20208; -- Mennu's Healing Ward
UPDATE `creature_template` SET `faction`=74, `unit_flags2`=0 WHERE `entry`=18179; -- Corrupted Nova Totem
UPDATE `creature_template` SET `faction`=74, `unit_flags2`=0 WHERE `entry`=18176; -- Tainted Earthgrab Totem

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`!=0 AND `Entry` IN (2110));
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=19 AND `Entry` IN (21128,21127,17961,17958,17938,17957,17890,17817,17816));
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=1 AND `Entry` IN (54667,54668));
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (17991,17962,17941,17940));

UPDATE `creature_template_difficulty` SET `VerifiedBuild`=49801 WHERE (`DifficultyID`=1 AND `Entry` IN (54668,54667,21128,21127,18206,17991,17964,17963,17962,17961,17960,17959,17958,17957,17942,17941,17940,17938,17893,17890,17817,17816,2110));
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `VerifiedBuild`=49801 WHERE (`Entry`=21126 AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=233, `VerifiedBuild`=49801 WHERE (`Entry`=22421 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1076, `HealthModifier`=7.340624809265136718, `CreatureDifficultyID`=16847, `VerifiedBuild`=49801 WHERE (`Entry`=21128 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1076, `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=16844, `VerifiedBuild`=49801 WHERE (`Entry`=21127 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1076, `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=16841, `VerifiedBuild`=49801 WHERE (`Entry`=21126 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1076, `HealthScalingExpansion`=1, `HealthModifier`=0.75, `CreatureDifficultyID`=16034, `VerifiedBuild`=49801 WHERE (`Entry`=20208 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1076, `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=13878, `VerifiedBuild`=49801 WHERE (`Entry`=18206 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1076, `HealthModifier`=1.125, `CreatureDifficultyID`=13851, `VerifiedBuild`=49801 WHERE (`Entry`=18179 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1076, `HealthScalingExpansion`=1, `HealthModifier`=0.5625, `CreatureDifficultyID`=13842, `VerifiedBuild`=49801 WHERE (`Entry`=18176 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1076, `HealthModifier`=49.5, `CreatureDifficultyID`=13643, `TypeFlags2`=128, `VerifiedBuild`=49801 WHERE (`Entry`=17991 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1076, `HealthModifier`=3.037499904632568359, `CreatureDifficultyID`=13602, `VerifiedBuild`=49801 WHERE (`Entry`=17964 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1076, `HealthModifier`=3.037499904632568359, `CreatureDifficultyID`=13599, `VerifiedBuild`=49801 WHERE (`Entry`=17963 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1076, `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=13596, `VerifiedBuild`=49801 WHERE (`Entry`=17962 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1076, `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=13593, `VerifiedBuild`=49801 WHERE (`Entry`=17961 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1076, `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=13590, `VerifiedBuild`=49801 WHERE (`Entry`=17960 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1076, `HealthModifier`=9.112500190734863281, `CreatureDifficultyID`=13587, `VerifiedBuild`=49801 WHERE (`Entry`=17959 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1076, `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=13584, `VerifiedBuild`=49801 WHERE (`Entry`=17958 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1076, `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=13581, `VerifiedBuild`=49801 WHERE (`Entry`=17957 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1076, `HealthModifier`=55.5, `CreatureDifficultyID`=13558, `TypeFlags2`=128, `VerifiedBuild`=49801 WHERE (`Entry`=17942 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1076, `HealthModifier`=51, `CreatureDifficultyID`=13555, `TypeFlags2`=128, `VerifiedBuild`=49801 WHERE (`Entry`=17941 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `ContentTuningID`=1076, `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=13552, `VerifiedBuild`=49801 WHERE (`Entry`=17940 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1076, `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=13548, `VerifiedBuild`=49801 WHERE (`Entry`=17938 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1076, `CreatureDifficultyID`=13497, `VerifiedBuild`=49801 WHERE (`Entry`=17893 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1076, `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=13371, `VerifiedBuild`=49801 WHERE (`Entry`=17817 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1076, `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=13368, `VerifiedBuild`=49801 WHERE (`Entry`=17816 AND `DifficultyID`=2);

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=17942 AND `DifficultyID`=2 AND `Idx`=1) OR (`CreatureEntry`=17942 AND `DifficultyID`=2 AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `DifficultyID`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(17942, 2, 1, 33821, 49801), -- Quagmirran
(17942, 2, 0, 72119, 49801); -- Quagmirran

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=49801 WHERE `DisplayID` IN (17606, 20098, 20100, 20099, 18300, 17729, 18301, 18302, 18386, 18395, 18393, 18387, 18384, 18224, 17728, 18397, 18390, 17300);
UPDATE `creature_model_info` SET `VerifiedBuild`=49801 WHERE `DisplayID` IN (20990, 15292, 20231, 20230);
UPDATE `creature_template_model` SET `VerifiedBuild`=49801 WHERE (`Idx`=0 AND `CreatureID` IN (17961,17962,17942,17940,17963,17960,17938,17958,17957,21128,17816,21126,17941,17893,17890,17959,2110,17991,54667,54668,18206,21127,17964,17817));
UPDATE `creature_template_model` SET `VerifiedBuild`=49801 WHERE (`Idx`=0 AND `CreatureID` IN (18176,22421,18179,20208));

-- Gameobject templates
UPDATE `gameobject_template` SET `VerifiedBuild`=49801 WHERE `entry` IN (182094, 185292);
