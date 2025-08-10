-- Creature templates
UPDATE `creature_template` SET `speed_walk`=1, `unit_flags`=33554432 WHERE `entry`=18766; -- Pool of Souls
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=18503; -- Phantasmal Possessor
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=18501; -- Unliving Stalker
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=18500; -- Unliving Cleric
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=18499; -- Unliving Sorcerer
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=18498; -- Unliving Soldier

-- Difficulty
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=49801 WHERE (`DifficultyID`=1 AND `Entry` IN (54725,54698,18766,18726,18700,18559,18558,18557,18556,18524,18521,18506,18499,18498,18497,18495,18493,18373,18371));
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `VerifiedBuild`=49801 WHERE (`DifficultyID`=1 AND `Entry` IN (18778,18503));
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=2, `VerifiedBuild`=49801 WHERE (`Entry`=18702 AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `VerifiedBuild`=49801 WHERE (`DifficultyID`=1 AND `Entry` IN (18501,18500));
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `ContentTuningID`=1064, `CreatureDifficultyID`=14547, `VerifiedBuild`=49801 WHERE (`Entry`=18778 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=5, `LevelScalingDeltaMax`=5, `ContentTuningID`=1064, `CreatureDifficultyID`=14532, `VerifiedBuild`=49801 WHERE (`Entry`=18766 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1064, `CreatureDifficultyID`=14483, `VerifiedBuild`=49801 WHERE (`Entry`=18726 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=2, `ContentTuningID`=1064, `CreatureDifficultyID`=14456, `VerifiedBuild`=49801 WHERE (`Entry`=18702 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1064, `CreatureDifficultyID`=14450, `VerifiedBuild`=49801 WHERE (`Entry`=18700 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1064, `CreatureDifficultyID`=14310, `VerifiedBuild`=49801 WHERE (`Entry`=18559 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=1064, `CreatureDifficultyID`=14307, `VerifiedBuild`=49801 WHERE (`Entry`=18558 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1064, `CreatureDifficultyID`=14304, `VerifiedBuild`=49801 WHERE (`Entry`=18557 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1064, `CreatureDifficultyID`=14301, `VerifiedBuild`=49801 WHERE (`Entry`=18556 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1064, `CreatureDifficultyID`=14267, `VerifiedBuild`=49801 WHERE (`Entry`=18524 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=1, `ContentTuningID`=1064, `CreatureDifficultyID`=14264, `VerifiedBuild`=49801 WHERE (`Entry`=18521 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1064, `CreatureDifficultyID`=14260, `VerifiedBuild`=49801 WHERE (`Entry`=18506 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1064, `CreatureDifficultyID`=14256, `VerifiedBuild`=49801 WHERE (`Entry`=18503 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `ContentTuningID`=1064, `CreatureDifficultyID`=14252, `VerifiedBuild`=49801 WHERE (`Entry`=18501 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `ContentTuningID`=1064, `CreatureDifficultyID`=14249, `VerifiedBuild`=49801 WHERE (`Entry`=18500 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1064, `CreatureDifficultyID`=14246, `VerifiedBuild`=49801 WHERE (`Entry`=18499 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1064, `CreatureDifficultyID`=14243, `VerifiedBuild`=49801 WHERE (`Entry`=18498 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1064, `CreatureDifficultyID`=14240, `VerifiedBuild`=49801 WHERE (`Entry`=18497 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1064, `CreatureDifficultyID`=14236, `VerifiedBuild`=49801 WHERE (`Entry`=18495 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1064, `CreatureDifficultyID`=14232, `VerifiedBuild`=49801 WHERE (`Entry`=18493 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1064, `HealthModifier`=33, `CreatureDifficultyID`=14083, `TypeFlags2`=128, `VerifiedBuild`=49801 WHERE (`Entry`=18373 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1064, `HealthModifier`=32, `CreatureDifficultyID`=14079, `TypeFlags2`=128, `VerifiedBuild`=49801 WHERE (`Entry`=18371 AND `DifficultyID`=2);

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=18373 AND `DifficultyID`=2 AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `DifficultyID`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(18373, 2, 0, 33836, 49801); -- Exarch Maladaar

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=49801 WHERE `DisplayID` IN (18077, 18078, 18138, 17930, 17990, 17991, 25873, 17937, 17936, 17938, 17941, 17940, 17939, 17929, 17931, 17928, 17933, 17935, 17932, 17934, 17920, 17923, 17922, 17921, 17919, 17911, 17910, 17942, 17943, 17926, 17927, 17715, 18916);
UPDATE `creature_template_model` SET `VerifiedBuild`=49801 WHERE (`Idx`=0 AND `CreatureID` IN (18700,18559,18702,18501,18499,18557,18766,18498,18371,18506,54698,18558,18373,18503,18493,18524,18726,18500,18521,18497,18556,54725,18495,18778)) OR (`Idx`=3 AND `CreatureID` IN (18559,18702,18501,18499,18557,18498,18558,18493,18500,18497,18556,18495)) OR (`Idx`=2 AND `CreatureID` IN (18559,18702,18501,18499,18557,18498,18558,18493,18500,18497,18556,18495)) OR (`Idx`=1 AND `CreatureID` IN (18559,18702,18501,18499,18557,18498,18558,18503,18493,18524,18500,18521,18497,18556,18495));
UPDATE `creature_model_info` SET `VerifiedBuild`=49801 WHERE `DisplayID`=17912;
UPDATE `creature_template_model` SET `VerifiedBuild`=49801 WHERE (`CreatureID`=34337 AND `Idx`=0);

-- Gameobject templates
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=20014, `ContentTuningId`=219, `VerifiedBuild`=49801 WHERE `entry`=183441; -- Soul Mirror

UPDATE `gameobject_questitem` SET `VerifiedBuild`=49801 WHERE (`GameObjectEntry`=183441 AND `Idx`=0);
