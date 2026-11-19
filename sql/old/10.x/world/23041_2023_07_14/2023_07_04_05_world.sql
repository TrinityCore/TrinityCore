-- Creature templates
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=20709; -- Blade Dance Target
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=19524; -- O'mrogg's Right Head
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=19523; -- O'mrogg's Left Head
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=0.857142865657806396, `unit_flags`=33554432, `unit_flags2`=0, `unit_flags3`=524289 WHERE `entry`=18370; -- Wild Shadow Fissure
UPDATE `creature_template` SET `BaseAttackTime`=1600 WHERE `entry`=17695; -- Shattered Hand Assassin
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=17693; -- Shattered Hand Scout
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=17687; -- Flame Arrow
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=17669; -- Rabid Warhound
UPDATE `creature_template` SET `speed_walk`=1, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=17623; -- Reaver Guard
UPDATE `creature_template` SET `speed_walk`=1, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=17622; -- Sharpshooter Guard
UPDATE `creature_template` SET `speed_walk`=1, `BaseAttackTime`=1800, `unit_flags`=64, `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=17621; -- Heathen Guard
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=17611; -- Warchief's Portal
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=17552; -- Hellfire Death Brazier
UPDATE `creature_template` SET `unit_flags3`=524289 WHERE `entry`=17471; -- Lesser Shadow Fissure
UPDATE `creature_template` SET `faction`=1692 WHERE `entry`=17464; -- Shattered Hand Gladiator
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=17462; -- Shattered Hand Zealot
UPDATE `creature_template` SET `speed_walk`=1, `unit_flags`=64, `unit_flags2`=2099200 WHERE `entry`=17461; -- Shattered Hand Blood Guard
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=17427; -- Shattered Hand Archer
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=17083; -- Fel Orc Convert
UPDATE `creature_template` SET `BaseAttackTime`=2200, `unit_flags2`=2099200 WHERE `entry`=16809; -- Warbringer O'mrogg
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=16808; -- Warchief Kargath Bladefist
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=16807; -- Grand Warlock Nethekurse
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=20923; -- Blood Guard Porung

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=1 AND `Entry`=9699);
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry`IN (17461,18370));
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=50000 WHERE (`DifficultyID`=1 AND `Entry` IN (17295,17296,17297,17302,57909,57908,55136,54932,54931,20709,19524,19523,18370,17695,17694,17693,17687,17671,17670,17669,17623,17622,17621,17611,17578,17552,17471,17465,17464,17462,17461,17427,17420,17357,17356,17083,16809,16808,16807,16704,16700,16699,16594,16593,16523,16507));
UPDATE `creature_template_difficulty` SET `HealthModifier`=42.52500152587890625, `CreatureDifficultyID`=16629, `TypeFlags2`=128, `VerifiedBuild`=50000 WHERE (`Entry`=20923 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1075, `CreatureDifficultyID`=15375, `VerifiedBuild`=50000 WHERE (`Entry`=19524 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1075, `CreatureDifficultyID`=15372, `VerifiedBuild`=50000 WHERE (`Entry`=19523 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1075, `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=13191, `VerifiedBuild`=50000 WHERE (`Entry`=17695 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1075, `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=13188, `VerifiedBuild`=50000 WHERE (`Entry`=17694 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1075, `HealthModifier`=4.55625009536743164, `CreatureDifficultyID`=13185, `VerifiedBuild`=50000 WHERE (`Entry`=17693 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1075, `HealthModifier`=11.84624958038330078, `CreatureDifficultyID`=13162, `VerifiedBuild`=50000 WHERE (`Entry`=17671 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1075, `HealthModifier`=8.797499656677246093, `CreatureDifficultyID`=13159, `VerifiedBuild`=50000 WHERE (`Entry`=17670 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1075, `HealthModifier`=3.9375, `CreatureDifficultyID`=13156, `VerifiedBuild`=50000 WHERE (`Entry`=17669 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1075, `HealthModifier`=3.796875, `CreatureDifficultyID`=13100, `VerifiedBuild`=50000 WHERE (`Entry`=17623 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1075, `HealthModifier`=3.796875, `CreatureDifficultyID`=13097, `VerifiedBuild`=50000 WHERE (`Entry`=17622 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1075, `HealthModifier`=3.796875, `CreatureDifficultyID`=13094, `VerifiedBuild`=50000 WHERE (`Entry`=17621 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1075, `HealthModifier`=1.01250004768371582, `CreatureDifficultyID`=12930, `VerifiedBuild`=50000 WHERE (`Entry`=17471 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1075, `HealthModifier`=11.84624958038330078, `CreatureDifficultyID`=12922, `VerifiedBuild`=50000 WHERE (`Entry`=17465 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1075, `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=12919, `VerifiedBuild`=50000 WHERE (`Entry`=17464 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1075, `HealthModifier`=3.037499904632568359, `CreatureDifficultyID`=12915, `VerifiedBuild`=50000 WHERE (`Entry`=17462 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1075, `HealthModifier`=3.037499904632568359, `CreatureDifficultyID`=12870, `VerifiedBuild`=50000 WHERE (`Entry`=17427 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1075, `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=12861, `VerifiedBuild`=50000 WHERE (`Entry`=17420 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1075, `HealthModifier`=1.518749952316284179, `CreatureDifficultyID`=12768, `VerifiedBuild`=50000 WHERE (`Entry`=17357 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1075, `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=12765, `VerifiedBuild`=50000 WHERE (`Entry`=17356 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=12700, `VerifiedBuild`=50000 WHERE (`Entry`=17301 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1075, `HealthModifier`=4.5, `CreatureDifficultyID`=12471, `VerifiedBuild`=50000 WHERE (`Entry`=17083 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1075, `HealthModifier`=63, `CreatureDifficultyID`=12194, `TypeFlags2`=128, `VerifiedBuild`=50000 WHERE (`Entry`=16809 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1075, `HealthModifier`=63, `CreatureDifficultyID`=12191, `TypeFlags2`=128, `VerifiedBuild`=50000 WHERE (`Entry`=16808 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1075, `HealthModifier`=54, `CreatureDifficultyID`=12188, `TypeFlags2`=128, `VerifiedBuild`=50000 WHERE (`Entry`=16807 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `ContentTuningID`=1075, `HealthModifier`=9.84375, `CreatureDifficultyID`=12081, `VerifiedBuild`=50000 WHERE (`Entry`=16704 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1075, `HealthModifier`=16.875, `CreatureDifficultyID`=12075, `VerifiedBuild`=50000 WHERE (`Entry`=16700 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `ContentTuningID`=1075, `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=12072, `VerifiedBuild`=50000 WHERE (`Entry`=16699 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1075, `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=11964, `VerifiedBuild`=50000 WHERE (`Entry`=16594 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1075, `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=11961, `VerifiedBuild`=50000 WHERE (`Entry`=16593 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1075, `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=11891, `VerifiedBuild`=50000 WHERE (`Entry`=16523 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1075, `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=11874, `VerifiedBuild`=50000 WHERE (`Entry`=16507 AND `DifficultyID`=2);

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=50000 WHERE `DisplayID` IN (16969, 16968, 16967, 16966, 17190, 17189, 17727, 17186, 17184, 15435, 17185, 17183, 17726, 17725, 17013, 16839, 18031, 19799, 16628, 16578, 19275, 16580, 16581, 16584, 19277, 8971, 1418, 2176, 6303, 2958, 2957, 1141);
UPDATE `creature_model_info` SET `BoundingRadius`=0.598999977111816406, `CombatReach`=1.25, `VerifiedBuild`=50000 WHERE `DisplayID`=358;
UPDATE `creature_template_model` SET `VerifiedBuild`=50000 WHERE (`Idx`=0 AND `CreatureID` IN (17621,17471,19524,17695,16704,17461,17693,16809,17671,57908,16699,54932,17622,19523,16807,17420,16808,17687,16507,17465,17427,17083,17694,4075,2914,17357,17462,54931,17578,17464,16523,17669,2110,16593,57909,9699,16700,17623,17552,17670,20709,55136,18370,17356,17611,16594)) OR (`Idx`=3 AND `CreatureID` IN (57908,2914,57909)) OR (`Idx`=2 AND `CreatureID` IN (57908,4075,2914,57909)) OR (`Idx`=1 AND `CreatureID` IN (57908,17687,4075,2914,57909,17552,20709,17611));
UPDATE `creature_template_model` SET `VerifiedBuild`=50000 WHERE (`Idx`=0 AND `CreatureID` IN (17301,17296,17302,17295,17297,20923));

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=37, `VerifiedBuild`=50000 WHERE `entry`=181679; -- Fel Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=50000 WHERE `entry` IN (181438, 181671, 181435, 182539, 181440, 181442, 181439, 181436, 181437, 182540, 181441);

UPDATE `gameobject_questitem` SET `VerifiedBuild`=50000 WHERE (`GameObjectEntry`=181671 AND `Idx`=0);
