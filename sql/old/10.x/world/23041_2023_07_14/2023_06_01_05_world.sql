-- Creature templates
UPDATE `creature_template` SET `unit_flags3`=16777217 WHERE `entry`=83996; -- Shaffar's Stasis Chamber
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=18343; -- Tavarok
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=18430; -- Ethereal Apprentice

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`!=0 AND `Entry` IN (3300,4075,4076,14881,53488));
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=1 AND `Entry` IN (18429,18430,18394));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(18429, 1, 0, 0, 222, 1, 0.349999994039535522, 15.87440013885498046, 14158, 64, 0, 49801),
(18430, 1, 1, 1, 222, 1, 1.5, 16.373199462890625, 14161, 64, 0, 49801),
(18394, 1, -1, -1, 222, 1, 1.5, 3.075099945068359375, 14107, 0, 0, 49801);

UPDATE `creature_template_difficulty` SET `VerifiedBuild`=49801 WHERE (`DifficultyID`=1 AND `Entry` IN (83996,54694,54692,19307,19306,18431,18344,18343,18341,18331,18317,18315,18314,18313,18312,18311,18309,14881,4076,4075,3300));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2671, `VerifiedBuild`=49801 WHERE (`Entry`=53488 AND `DifficultyID`=0);
UPDATE `creature_template_difficulty` SET `DamageModifier`=4.6 WHERE (`DifficultyID`=1 AND `Entry`=18429);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=222, `VerifiedBuild`=49801 WHERE (`Entry`=22927 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1066, `HealthModifier`=15.94694995880126953, `CreatureDifficultyID`=15135, `VerifiedBuild`=49801 WHERE (`Entry`=19307 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1066, `HealthModifier`=3.037499904632568359, `CreatureDifficultyID`=15132, `TypeFlags`=1, `VerifiedBuild`=49801 WHERE (`Entry`=19306 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1066, `HealthModifier`=2.34375, `CreatureDifficultyID`=14165, `VerifiedBuild`=49801 WHERE (`Entry`=18431 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1066, `HealthModifier`=2.8125, `CreatureDifficultyID`=14162, `VerifiedBuild`=49801 WHERE (`Entry`=18430 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1066, `HealthModifier`=45, `ManaModifier`=38.83800125122070312, `CreatureDifficultyID`=14049, `TypeFlags2`=128, `VerifiedBuild`=49801 WHERE (`Entry`=18344 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1066, `HealthModifier`=37.5, `CreatureDifficultyID`=14046, `TypeFlags2`=128, `VerifiedBuild`=49801 WHERE (`Entry`=18343 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1066, `HealthModifier`=30, `CreatureDifficultyID`=14042, `TypeFlags2`=128, `VerifiedBuild`=49801 WHERE (`Entry`=18341 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1066, `HealthModifier`=7.199999809265136718, `CreatureDifficultyID`=14031, `VerifiedBuild`=49801 WHERE (`Entry`=18331 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1066, `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=13997, `VerifiedBuild`=49801 WHERE (`Entry`=18317 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1066, `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=13994, `VerifiedBuild`=49801 WHERE (`Entry`=18315 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1066, `HealthModifier`=8.797499656677246093, `CreatureDifficultyID`=13991, `VerifiedBuild`=49801 WHERE (`Entry`=18314 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1066, `HealthModifier`=7.875, `CreatureDifficultyID`=13988, `VerifiedBuild`=49801 WHERE (`Entry`=18313 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1066, `HealthModifier`=6.75, `CreatureDifficultyID`=13985, `VerifiedBuild`=49801 WHERE (`Entry`=18312 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1066, `HealthModifier`=8.808750152587890625, `CreatureDifficultyID`=13982, `VerifiedBuild`=49801 WHERE (`Entry`=18311 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1066, `HealthModifier`=7.199999809265136718, `CreatureDifficultyID`=13979, `VerifiedBuild`=49801 WHERE (`Entry`=18309 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1066, `HealthModifier`=1.063125014305114746, `CreatureDifficultyID`=14159, `VerifiedBuild`=49801 WHERE (`Entry`=18429 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-1, `LevelScalingDeltaMax`=-1, `ContentTuningID`=1066, `HealthScalingExpansion`=1, `HealthModifier`=4.55625009536743164, `CreatureDifficultyID`=14108, `VerifiedBuild`=49801 WHERE (`Entry`=18394 AND `DifficultyID`=2);

DELETE FROM `creature_questitem` WHERE (`CreatureEntry` IN (18341,18343,18344) AND `DifficultyID`=0);
DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=18344 AND `DifficultyID`=2 AND `Idx`=1) OR (`CreatureEntry`=18344 AND `DifficultyID`=2 AND `Idx`=0) OR (`CreatureEntry`=18343 AND `DifficultyID`=1 AND `Idx`=0) OR (`CreatureEntry`=18344 AND `DifficultyID`=1 AND `Idx`=0) OR (`CreatureEntry`=18341 AND `DifficultyID`=1 AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `DifficultyID`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(18343, 0, 0, 72127, 49801), -- Tavarok
(18344, 0, 0, 28490, 49801), -- Nexus-Prince Shaffar
(18344, 2, 1, 33835, 49801), -- Nexus-Prince Shaffar
(18344, 2, 0, 28490, 49801), -- Nexus-Prince Shaffar
(18341, 0, 0, 72126, 49801); -- Pandemonius

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=49801 WHERE `DisplayID` IN (11686, 19655, 19656, 16925, 13069, 18050, 16217, 25866, 19702, 19780, 19332, 71757, 20987, 21005, 20468, 21004, 20986, 20466, 19778, 20923, 44816, 2177, 1418, 2176, 1141, 1987, 1206, 1986);
UPDATE `creature_template_model` SET `VerifiedBuild`=49801 WHERE (`Idx`=0 AND `CreatureID` IN (18429,18314,18311,18343,18315,19307,18309,18344,14881,305,19677,64993,83996,18331,19306,54692,18313,54741,53488,18341,40625,25064,18317,4076,14505,59072,28363,71486,54694,18431,68288,47654,304,65011,40165,4075,3300,18312,35362,18379,356)) OR (`Idx`=1 AND `CreatureID` IN (14881,19677,83996,53488,40165,4075,3300)) OR (`Idx`=2 AND `CreatureID` IN (4075,3300));
UPDATE `creature_template_model` SET `VerifiedBuild`=49801 WHERE (`Idx`=0 AND `CreatureID` IN (18430,22927,34337)) OR (`Idx`=1 AND `CreatureID`=22927);
UPDATE `creature_model_info` SET `VerifiedBuild`=49801 WHERE `DisplayID` IN (15880, 19646);
