-- Creature templates
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=19969; -- Green Seedling
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=19964; -- Red Seedling
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=19962; -- Blue Seedling
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=19958; -- White Seedling
UPDATE `creature_template` SET `speed_walk`=0.25, `speed_run`=0.285714298486709594, `unit_flags3`=524288 WHERE `entry`=19953; -- Frayer Protector
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=19920; -- Thorn Flayer
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=19919; -- Thorn Lasher

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=1 AND `Entry` IN (19969,19964,19962,19958,19953,19949,19920,19919));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(19969, 1, -2, -1, 229, 1, 0.150000005960464477, 1, 15838, 0, 0, 50000),
(19964, 1, -2, -2, 229, 1, 0.150000005960464477, 1, 15831, 0, 0, 50000),
(19962, 1, -1, -1, 229, 1, 0.150000005960464477, 1, 15827, 0, 0, 50000),
(19958, 1, -2, -2, 229, 1, 0.150000005960464477, 1, 15819, 0, 0, 50000),
(19953, 1, 0, 0, 229, 1, 0.60000002384185791, 1, 15811, 0, 0, 50000),
(19949, 1, 0, 0, 229, 1, 0.449999988079071044, 1, 15805, 0, 0, 50000),
(19920, 1, 0, 0, 229, 1, 0.699999988079071044, 1, 15774, 0, 0, 50000),
(19919, 1, 0, 0, 229, 1, 0.699999988079071044, 1, 15771, 0, 0, 50000);

UPDATE `creature_template_difficulty` SET `VerifiedBuild`=50000 WHERE (`DifficultyID`=1 AND `Entry` IN (19865,19843,19608,19598,19557,19555,19513,19512,19511,19509,19508,19507,19505,19486,18587,18422,18421,18420,18419,18405,18404,18155,17994,17993,17980,17978,17977,17976,17975));
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `VerifiedBuild`=50000 WHERE (`Entry`=19633 AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=50000 WHERE (`Entry`=53488 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1073, `CreatureDifficultyID`=15839, `VerifiedBuild`=50000 WHERE (`Entry`=19969 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1073, `CreatureDifficultyID`=15832, `VerifiedBuild`=50000 WHERE (`Entry`=19964 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1073, `CreatureDifficultyID`=15828, `VerifiedBuild`=50000 WHERE (`Entry`=19962 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1073, `CreatureDifficultyID`=15820, `VerifiedBuild`=50000 WHERE (`Entry`=19958 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1073, `CreatureDifficultyID`=15812, `VerifiedBuild`=50000 WHERE (`Entry`=19953 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1073, `CreatureDifficultyID`=15806, `VerifiedBuild`=50000 WHERE (`Entry`=19949 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1074, `CreatureDifficultyID`=15775, `VerifiedBuild`=50000 WHERE (`Entry`=19920 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1073, `CreatureDifficultyID`=15772, `VerifiedBuild`=50000 WHERE (`Entry`=19919 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=1, `ContentTuningID`=1073, `CreatureDifficultyID`=15735, `VerifiedBuild`=50000 WHERE (`Entry`=19865 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1073, `CreatureDifficultyID`=15711, `VerifiedBuild`=50000 WHERE (`Entry`=19843 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `ContentTuningID`=1073, `CreatureDifficultyID`=15494, `VerifiedBuild`=50000 WHERE (`Entry`=19633 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1073, `CreatureDifficultyID`=15465, `VerifiedBuild`=50000 WHERE (`Entry`=19608 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=1, `ContentTuningID`=1073, `CreatureDifficultyID`=15453, `VerifiedBuild`=50000 WHERE (`Entry`=19598 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=1, `ContentTuningID`=1073, `CreatureDifficultyID`=15410, `VerifiedBuild`=50000 WHERE (`Entry`=19557 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=1, `ContentTuningID`=1073, `CreatureDifficultyID`=15361, `VerifiedBuild`=50000 WHERE (`Entry`=19513 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=1, `ContentTuningID`=1073, `CreatureDifficultyID`=15358, `VerifiedBuild`=50000 WHERE (`Entry`=19512 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=1, `ContentTuningID`=1073, `CreatureDifficultyID`=15355, `VerifiedBuild`=50000 WHERE (`Entry`=19511 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=1, `ContentTuningID`=1073, `CreatureDifficultyID`=15349, `VerifiedBuild`=50000 WHERE (`Entry`=19509 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=1, `ContentTuningID`=1073, `CreatureDifficultyID`=15346, `VerifiedBuild`=50000 WHERE (`Entry`=19508 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=1, `ContentTuningID`=1073, `CreatureDifficultyID`=15343, `VerifiedBuild`=50000 WHERE (`Entry`=19507 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=1, `ContentTuningID`=1073, `CreatureDifficultyID`=15339, `VerifiedBuild`=50000 WHERE (`Entry`=19505 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=1, `ContentTuningID`=1073, `CreatureDifficultyID`=15318, `VerifiedBuild`=50000 WHERE (`Entry`=19486 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1073, `CreatureDifficultyID`=14327, `VerifiedBuild`=50000 WHERE (`Entry`=18587 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=1, `ContentTuningID`=1073, `CreatureDifficultyID`=14150, `VerifiedBuild`=50000 WHERE (`Entry`=18422 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=1, `ContentTuningID`=1073, `CreatureDifficultyID`=14147, `VerifiedBuild`=50000 WHERE (`Entry`=18421 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1073, `CreatureDifficultyID`=14144, `VerifiedBuild`=50000 WHERE (`Entry`=18420 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `ContentTuningID`=1073, `CreatureDifficultyID`=14141, `VerifiedBuild`=50000 WHERE (`Entry`=18419 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1073, `CreatureDifficultyID`=14123, `VerifiedBuild`=50000 WHERE (`Entry`=18405 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `ContentTuningID`=1073, `CreatureDifficultyID`=14120, `VerifiedBuild`=50000 WHERE (`Entry`=18404 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1073, `CreatureDifficultyID`=13813, `VerifiedBuild`=50000 WHERE (`Entry`=18155 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1073, `CreatureDifficultyID`=13650, `VerifiedBuild`=50000 WHERE (`Entry`=17994 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `ContentTuningID`=1073, `CreatureDifficultyID`=13647, `VerifiedBuild`=50000 WHERE (`Entry`=17993 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1073, `HealthModifier`=33, `CreatureDifficultyID`=13628, `TypeFlags2`=128, `VerifiedBuild`=50000 WHERE (`Entry`=17980 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1073, `HealthModifier`=23, `CreatureDifficultyID`=13624, `TypeFlags2`=128, `VerifiedBuild`=50000 WHERE (`Entry`=17978 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1073, `HealthModifier`=36, `CreatureDifficultyID`=13621, `TypeFlags2`=128, `VerifiedBuild`=50000 WHERE (`Entry`=17977 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1073, `HealthModifier`=30, `CreatureDifficultyID`=13618, `TypeFlags2`=128, `VerifiedBuild`=50000 WHERE (`Entry`=17976 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1073, `HealthModifier`=32, `CreatureDifficultyID`=13615, `TypeFlags2`=128, `VerifiedBuild`=50000 WHERE (`Entry`=17975 AND `DifficultyID`=2);

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=17977 AND `DifficultyID`=2 AND `Idx`=1) OR (`CreatureEntry`=17977 AND `DifficultyID`=2 AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `DifficultyID`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(17977, 2, 1, 31085, 50000), -- Warp Splinter
(17977, 2, 0, 33859, 50000); -- Warp Splinter

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=50000 WHERE `DisplayID` IN (16925, 19292, 20139, 19290, 19289, 17009, 9590, 17713, 18083, 2019, 21331, 21332, 17714, 19021, 19029, 18082, 2878, 11331, 21333, 21334, 21338, 21339, 21336, 21337, 21335, 21341, 21340, 18925, 18926, 19030, 17820, 17819, 17844, 17845, 17843, 17916, 17918, 17884, 17883, 18930, 17813, 17817, 17816, 19685, 17780, 17779, 17775, 17774, 13109, 14416, 19438, 18929, 19045);
UPDATE `creature_template_model` SET `VerifiedBuild`=50000 WHERE (`Idx`=0 AND `CreatureID` IN (19511,19919,19962,19509,17980,19598,19843,19953,19964,19958,17978,19508,18404,19969,19555,19865,19507,18155,18422,19949,19557,19608,18587,17994,19513,34337,18420,19505,19633,19920,18421,17993,19486,17977,53488,19512,17975,17976,18405,18419)) OR (`Idx`=1 AND `CreatureID` IN (19509,19508,18404,19555,19507,18422,17994,18420,19505,19633,18421,17993,19486,53488,18419)) OR (`Idx`=3 AND `CreatureID` IN (18404,17994,18421,17993)) OR (`Idx`=2 AND `CreatureID` IN (18404,19507,17994,18420,18421,17993));

-- Gameobject templates
UPDATE `gameobject_template` SET `VerifiedBuild`=50000 WHERE `entry`=181277;
