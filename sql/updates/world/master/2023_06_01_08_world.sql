-- Creature templates
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=54895; -- Lower City Healer
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=54890; -- Field Commander Mahfuun
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=21159; -- Containment Beam
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=19427; -- Voidwalker Summoner
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=19226; -- Void Traveler
UPDATE `creature_template` SET `unit_flags`=570426112, `unit_flags2`=2097152, `unit_flags3`=524288 WHERE `entry`=19224; -- Void Portal
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=18891; -- Spy To'gun
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=18848; -- Malicious Instructor
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=18796; -- Fel Overseer
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=18794; -- Cabal Ritualist
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=18793; -- Invisible Target
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=18732; -- Grandmaster Vorpil
UPDATE `creature_template` SET `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=18731; -- Ambassador Hellmaw
UPDATE `creature_template` SET `unit_flags2`=2097152 WHERE `entry`=18708; -- Murmur
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=18667; -- Blackheart the Inciter
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=18642; -- Fel Guardhound
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=18639; -- Cabal Spellbinder
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=18637; -- Cabal Shadow Priest
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=18635; -- Cabal Deathsworn
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=18633; -- Cabal Acolyte

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry` IN (53488));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(53488, 2, 0, 0, 2672, 3, 1, 1, 32538, 0, 0, 49801);

UPDATE `creature_template_difficulty` SET `VerifiedBuild`=49801 WHERE (`DifficultyID`=1 AND `Entry` IN (54895,54893,54891,54890,21159,19427,19226,19224,18891,18830,18797,18796,18794,18793,18732,18731,18708,18667,18663,18642,18641,18640,18639,18638,18637,18636,18635,18634,18633,18632,18631));
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `VerifiedBuild`=49801 WHERE (`Entry`=18848 AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1069, `CreatureDifficultyID`=15254, `VerifiedBuild`=49801 WHERE (`Entry`=19427 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1069, `CreatureDifficultyID`=15048, `VerifiedBuild`=49801 WHERE (`Entry`=19226 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1069, `CreatureDifficultyID`=15044, `VerifiedBuild`=49801 WHERE (`Entry`=19224 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1069, `CreatureDifficultyID`=14671, `VerifiedBuild`=49801 WHERE (`Entry`=18891 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `ContentTuningID`=1069, `CreatureDifficultyID`=14626, `VerifiedBuild`=49801 WHERE (`Entry`=18848 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1069, `CreatureDifficultyID`=14608, `VerifiedBuild`=49801 WHERE (`Entry`=18830 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1069, `CreatureDifficultyID`=14571, `VerifiedBuild`=49801 WHERE (`Entry`=18797 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1069, `CreatureDifficultyID`=14568, `VerifiedBuild`=49801 WHERE (`Entry`=18796 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=1, `ContentTuningID`=1069, `CreatureDifficultyID`=14564, `VerifiedBuild`=49801 WHERE (`Entry`=18794 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1069, `HealthScalingExpansion`=1, `CreatureDifficultyID`=14561, `VerifiedBuild`=49801 WHERE (`Entry`=18793 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1069, `HealthModifier`=36, `CreatureDifficultyID`=14493, `TypeFlags2`=128, `VerifiedBuild`=49801 WHERE (`Entry`=18732 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1069, `HealthModifier`=37.5, `CreatureDifficultyID`=14490, `TypeFlags2`=128, `VerifiedBuild`=49801 WHERE (`Entry`=18731 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1069, `HealthModifier`=115, `CreatureDifficultyID`=14466, `TypeFlags2`=128, `VerifiedBuild`=49801 WHERE (`Entry`=18708 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1069, `HealthModifier`=37.5, `CreatureDifficultyID`=14413, `TypeFlags2`=128, `VerifiedBuild`=49801 WHERE (`Entry`=18667 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1069, `CreatureDifficultyID`=14384, `VerifiedBuild`=49801 WHERE (`Entry`=18642 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1069, `CreatureDifficultyID`=14381, `VerifiedBuild`=49801 WHERE (`Entry`=18641 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1069, `CreatureDifficultyID`=14378, `VerifiedBuild`=49801 WHERE (`Entry`=18640 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1069, `CreatureDifficultyID`=14375, `VerifiedBuild`=49801 WHERE (`Entry`=18639 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1069, `CreatureDifficultyID`=14372, `VerifiedBuild`=49801 WHERE (`Entry`=18638 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=1, `ContentTuningID`=1069, `CreatureDifficultyID`=14369, `VerifiedBuild`=49801 WHERE (`Entry`=18637 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1069, `CreatureDifficultyID`=14366, `VerifiedBuild`=49801 WHERE (`Entry`=18636 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=1, `ContentTuningID`=1069, `CreatureDifficultyID`=14363, `VerifiedBuild`=49801 WHERE (`Entry`=18635 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1069, `CreatureDifficultyID`=14360, `VerifiedBuild`=49801 WHERE (`Entry`=18634 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1069, `CreatureDifficultyID`=14357, `VerifiedBuild`=49801 WHERE (`Entry`=18633 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1069, `CreatureDifficultyID`=14354, `VerifiedBuild`=49801 WHERE (`Entry`=18632 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=1, `ContentTuningID`=1069, `CreatureDifficultyID`=14351, `VerifiedBuild`=49801 WHERE (`Entry`=18631 AND `DifficultyID`=2);

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=18708 AND `DifficultyID`=2 AND `Idx`=1) OR (`CreatureEntry`=18708 AND `DifficultyID`=2 AND `Idx`=0) OR (`CreatureEntry`=18732 AND `DifficultyID`=2 AND `Idx`=0) OR (`CreatureEntry`=18667 AND `DifficultyID`=2 AND `Idx`=0) OR (`CreatureEntry`=18642 AND `DifficultyID`=2 AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `DifficultyID`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(18708, 2, 1, 31722, 49801), -- Murmur
(18708, 2, 0, 33840, 49801); -- Murmur

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=49801 WHERE `DisplayID` IN (17544, 20665, 20666, 20668, 18932, 20661, 17081, 16946, 18280, 17543, 18596, 18597, 18598, 9786, 18193, 18191, 18192, 15880, 18535, 18821, 18839, 18058, 159, 7949, 18038, 18609, 18603, 18604, 18602, 18612, 18613, 18614, 18600, 18599, 18585, 18592, 18591, 18590, 18589, 18605, 18608, 18606, 18582, 18581, 18579, 18580, 18594, 18595, 18593, 18586, 18588, 18587);
UPDATE `creature_template_model` SET `VerifiedBuild`=49801 WHERE (`Idx`=0 AND `CreatureID` IN (19427,18638,18830,18633,18891,18667,18635,18641,19224,18793,18634,18797,18663,54895,54890,54891,34337,18639,18642,54893,18796,18848,18637,18640,18632,18732,18636,18794,18731,19226,18708,21159,18631)) OR (`Idx`=2 AND `CreatureID` IN (18638,18830,18633,18635,18634,54895,18639,54893,18637,18640,18632,18636,18631)) OR (`Idx`=1 AND `CreatureID` IN (18638,18830,18633,18635,18793,18634,54895,18639,54893,18637,18640,18632,18636,18794,21159,18631)) OR (`Idx`=3 AND `CreatureID` IN (18633,18635,54895));
UPDATE `creature_model_info` SET `VerifiedBuild`=49801 WHERE `DisplayID` IN (20664, 18601);

-- Gameobject templates
UPDATE `gameobject_questitem` SET `VerifiedBuild`=49801 WHERE (`GameObjectEntry`=182940 AND `Idx`=0);
