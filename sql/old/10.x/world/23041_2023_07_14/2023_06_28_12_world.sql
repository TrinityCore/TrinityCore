-- Creature templates
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=20481; -- Raging Flames
UPDATE `creature_template` SET `unit_flags3`=524289 WHERE `entry`=20405; -- Nether Charge

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`!=0 AND `Entry` IN (45979));
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=1 AND `Entry` IN (21062,20405));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(21062, 1, 0, 0, 230, 1, 1.5, 1, 16771, 8, 0, 50000),
(20405, 1, 0, 0, 230, 1, 0.800000011920928955, 1, 16189, 0, 0, 50000);

UPDATE `creature_template_difficulty` SET `VerifiedBuild`=50000 WHERE (`DifficultyID`=1 AND `Entry` IN (20481,20478,19221,19220));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=230, `VerifiedBuild`=50000 WHERE (`DifficultyID`=1 AND `Entry` IN (20990,20988,19716,19168,19712,19510,19231,20059,19735,19713,19710,19219,19218,19167,19166));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1074, `CreatureDifficultyID`=16772, `VerifiedBuild`=50000 WHERE (`Entry`=21062 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=16704, `VerifiedBuild`=50000 WHERE (`Entry`=20990 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=16700, `VerifiedBuild`=50000 WHERE (`Entry`=20988 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1074, `CreatureDifficultyID`=16271, `VerifiedBuild`=50000 WHERE (`Entry`=20481 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1074, `CreatureDifficultyID`=16266, `VerifiedBuild`=50000 WHERE (`Entry`=20478 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1074, `CreatureDifficultyID`=16190, `VerifiedBuild`=50000 WHERE (`Entry`=20405 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=15914, `VerifiedBuild`=50000 WHERE (`Entry`=20059 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=15602, `VerifiedBuild`=50000 WHERE (`Entry`=19735 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=15581, `VerifiedBuild`=50000 WHERE (`Entry`=19716 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=15577, `VerifiedBuild`=50000 WHERE (`Entry`=19713 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=15574, `VerifiedBuild`=50000 WHERE (`Entry`=19712 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `HealthModifier`=34, `CreatureDifficultyID`=15571, `TypeFlags2`=128, `VerifiedBuild`=50000 WHERE (`Entry`=19710 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=15352, `VerifiedBuild`=50000 WHERE (`Entry`=19510 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=15055, `VerifiedBuild`=50000 WHERE (`Entry`=19231 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1074, `HealthModifier`=34, `CreatureDifficultyID`=15039, `TypeFlags2`=128, `VerifiedBuild`=50000 WHERE (`Entry`=19221 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1074, `HealthModifier`=34, `CreatureDifficultyID`=15036, `TypeFlags2`=128, `VerifiedBuild`=50000 WHERE (`Entry`=19220 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `HealthModifier`=42, `CreatureDifficultyID`=15033, `TypeFlags2`=128, `VerifiedBuild`=50000 WHERE (`Entry`=19219 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `HealthModifier`=25, `CreatureDifficultyID`=15030, `TypeFlags2`=128, `VerifiedBuild`=50000 WHERE (`Entry`=19218 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=14964, `VerifiedBuild`=50000 WHERE (`Entry`=19168 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=14961, `VerifiedBuild`=50000 WHERE (`Entry`=19167 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=14958, `VerifiedBuild`=50000 WHERE (`Entry`=19166 AND `DifficultyID`=2);

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=19220 AND `DifficultyID`=2 AND `Idx`=1) OR (`CreatureEntry`=19220 AND `DifficultyID`=2 AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `DifficultyID`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(19220, 2, 1, 31086, 50000), -- Pathaleon the Calculator
(19220, 2, 0, 33860, 50000); -- Pathaleon the Calculator

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=50000 WHERE `DisplayID` IN (19968, 19970, 19966, 19967, 5488, 48197, 18288, 18647, 21191, 17977, 19166, 20033, 19162, 18816, 17917, 18662);
UPDATE `creature_template_model` SET `VerifiedBuild`=50000 WHERE (`Idx`=0 AND `CreatureID` IN (19219,19218,19220,19716,19713,19168,19710,19221,21062,19712,20405,20988,19167,19166,45979,19735,20059,20990,20481,20478,19231,19510)) OR (`Idx`=2 AND `CreatureID` IN (19168,19167,20059,19510)) OR (`Idx`=1 AND `CreatureID` IN (19168,20988,19167,45979,20059,20990,19510)) OR (`Idx`=3 AND `CreatureID` IN (19167,19510));

-- Gameobject templates
UPDATE `gameobject_template` SET `VerifiedBuild`=50000 WHERE `entry` IN (184465, 184449, 183788, 184632, 184322, 185018, 185015);

UPDATE `gameobject_template_addon` SET `flags`=2 WHERE `entry`=184465; -- Cache of the Legion

UPDATE `gameobject_questitem` SET `VerifiedBuild`=50000 WHERE (`Idx`=0 AND `GameObjectEntry` IN (184465,185015));
