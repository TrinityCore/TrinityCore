-- Creature templates
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=22299; -- Spore Strider
UPDATE `creature_template` SET `unit_flags`=33536, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=18240; -- Sunspring Villager
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=19224; -- Void Portal
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=17990; -- Underbog Mushroom
UPDATE `creature_template` SET `BaseAttackTime`=4000 WHERE `entry`=17827; -- Claw
UPDATE `creature_template` SET `unit_flags`=64 WHERE `entry`=17734; -- Underbog Lord
UPDATE `creature_template` SET `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=17731; -- Fen Ray
UPDATE `creature_template` SET `unit_flags`=64 WHERE `entry`=17724; -- Underbat

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`!=0 AND `Entry` IN (54638,16030));
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry` IN (54678));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(54678, 2, 0, 0, 1078, 1, 1, 1, 30894, 128, 0, 49801);

UPDATE `creature_template_difficulty` SET `VerifiedBuild`=49801 WHERE (`DifficultyID`=1 AND `Entry` IN (54678,54675,54674,54638,20465,19632,18409,18105,17992,17990,17827,17885,17882,17871,17826,17771,17770,17735,17734,17732,17731,17730,17728,17727,17726,17725,17724,17723,16030));
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2 WHERE (`Entry`=17827 AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `DifficultyID`=1, `ContentTuningID`=234, `VerifiedBuild`=49801 WHERE (`Entry`=17894 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=1, `VerifiedBuild`=49801 WHERE (`Entry`=17729 AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `ContentTuningID`=1078, `CreatureDifficultyID`=13300, `VerifiedBuild`=49801 WHERE (`Entry`=17771 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1078, `CreatureDifficultyID`=18033, `TypeFlags`=65537, `VerifiedBuild`=49801 WHERE (`Entry`=22299 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1078, `HealthScalingExpansion`=1, `CreatureDifficultyID`=16251, `VerifiedBuild`=49801 WHERE (`Entry`=20465 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1078, `CreatureDifficultyID`=15491, `VerifiedBuild`=49801 WHERE (`Entry`=19632 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-1, `ContentTuningID`=1078, `CreatureDifficultyID`=14129, `VerifiedBuild`=49801 WHERE (`Entry`=18409 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1078, `HealthModifier`=20, `CreatureDifficultyID`=13759, `TypeFlags`=73, `TypeFlags2`=128, `VerifiedBuild`=49801 WHERE (`Entry`=18105 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1078, `CreatureDifficultyID`=13640, `VerifiedBuild`=49801 WHERE (`Entry`=17990 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1078, `HealthModifier`=18, `CreatureDifficultyID`=13388, `VerifiedBuild`=49801 WHERE (`Entry`=17827 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1078, `HealthModifier`=33, `CreatureDifficultyID`=13483, `TypeFlags`=65609, `TypeFlags2`=128, `VerifiedBuild`=49801 WHERE (`Entry`=17882 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1078, `CreatureDifficultyID`=13458, `VerifiedBuild`=49801 WHERE (`Entry`=17871 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1078, `HealthModifier`=23, `CreatureDifficultyID`=13385, `TypeFlags2`=128, `VerifiedBuild`=49801 WHERE (`Entry`=17826 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1078, `HealthModifier`=22, `CreatureDifficultyID`=13297, `TypeFlags2`=128, `VerifiedBuild`=49801 WHERE (`Entry`=17770 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1078, `CreatureDifficultyID`=13258, `VerifiedBuild`=49801 WHERE (`Entry`=17735 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1078, `CreatureDifficultyID`=13255, `VerifiedBuild`=49801 WHERE (`Entry`=17734 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1078, `CreatureDifficultyID`=13252, `VerifiedBuild`=49801 WHERE (`Entry`=17732 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1078, `CreatureDifficultyID`=13249, `VerifiedBuild`=49801 WHERE (`Entry`=17731 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1078, `CreatureDifficultyID`=13246, `VerifiedBuild`=49801 WHERE (`Entry`=17730 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=1, `ContentTuningID`=1078, `CreatureDifficultyID`=13243, `VerifiedBuild`=49801 WHERE (`Entry`=17729 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1078, `CreatureDifficultyID`=13240, `VerifiedBuild`=49801 WHERE (`Entry`=17728 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1078, `CreatureDifficultyID`=13237, `VerifiedBuild`=49801 WHERE (`Entry`=17727 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1078, `CreatureDifficultyID`=13234, `VerifiedBuild`=49801 WHERE (`Entry`=17726 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-1, `ContentTuningID`=1078, `CreatureDifficultyID`=13231, `VerifiedBuild`=49801 WHERE (`Entry`=17725 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1078, `CreatureDifficultyID`=13228, `VerifiedBuild`=49801 WHERE (`Entry`=17724 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1078, `CreatureDifficultyID`=13225, `VerifiedBuild`=49801 WHERE (`Entry`=17723 AND `DifficultyID`=2);

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=17882 AND `DifficultyID`=2 AND `Idx`=2) OR (`CreatureEntry`=17882 AND `DifficultyID`=2 AND `Idx`=1) OR (`CreatureEntry`=17882 AND `DifficultyID`=2 AND `Idx`=0) OR (`CreatureEntry`=17882 AND `DifficultyID`=0 AND `Idx`=2) OR (`CreatureEntry`=17882 AND `DifficultyID`=0 AND `Idx`=1) OR (`CreatureEntry`=17882 AND `DifficultyID`=0 AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `DifficultyID`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(17882, 0, 1, 24427, 49801), -- The Black Stalker
(17882, 0, 0, 24248, 49801), -- The Black Stalker
(17882, 2, 2, 24427, 49801), -- The Black Stalker
(17882, 2, 1, 24248, 49801), -- The Black Stalker
(17882, 2, 0, 33826, 49801); -- The Black Stalker

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=49801 WHERE `DisplayID` IN (17301, 17294, 14528, 19367, 17528, 39552, 17309, 17295, 18194, 16273, 18570, 17648, 17228, 18401, 17758, 17755, 17757, 17756, 18400, 18399, 17754, 17450, 9904, 9906);
UPDATE `creature_model_info` SET `BoundingRadius`=0.349999994039535522, `CombatReach`=3, `VerifiedBuild`=49801 WHERE `DisplayID`=45046;
UPDATE `creature_template_model` SET `VerifiedBuild`=49801 WHERE (`Idx`=0 AND `CreatureID` IN (18409,54678,17734,54674,20465,54675,17735,17871,16030,17725,17992,17731,17894,17724,17771,17726,54638,17885,17728,17723,17732,17729,17826,18105,17730,17882,19632,17827,17770,17990,17727)) OR (`Idx`=1 AND `CreatureID` IN (17734,16030,17992,17731,54638));
UPDATE `creature_template_model` SET `VerifiedBuild`=49801 WHERE (`Idx`=0 AND `CreatureID` IN (22299,56921));

-- Gameobject templates
UPDATE `gameobject_template` SET `VerifiedBuild`=49801 WHERE `entry` IN (182054, 183385, 183386, 181278, 181275);

UPDATE `gameobject_questitem` SET `VerifiedBuild`=49801 WHERE (`GameObjectEntry`=182054 AND `Idx`=0);
