-- Creature templates
UPDATE `creature_template` SET `npcflag`=1, `unit_flags3`=1 WHERE `entry`=54852; -- Earthbinder Rayge
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=54851; -- Windcaller Claw
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=54849; -- Naturalist Bite
UPDATE `creature_template` SET `unit_flags`=64 WHERE `entry`=21695; -- Tidal Surger
UPDATE `creature_template` SET `unit_flags`=64 WHERE `entry`=21694; -- Bog Overlord
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=21338; -- Coilfang Leper
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=17951; -- Steamrigger Mechanic
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=17803; -- Coilfang Oracle
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=17801; -- Coilfang Siren
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=17799; -- Dreghood Slave
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=17798; -- Warlord Kalithresh
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=17797; -- Hydromancer Thespia
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=17796; -- Mekgineer Steamrigger
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=17722; -- Coilfang Sorceress

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry` IN (54849));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(54849, 2, 0, 0, 1077, 1, 1, 1, 30759, 128, 0, 49890);

UPDATE `creature_template_difficulty` SET `VerifiedBuild`=49801 WHERE (`DifficultyID`=1 AND `Entry` IN (54852,54851,54849,54848,21696,21695,21694,21338,20926,17954,17951,17917,17805,17803,17802,17801,17800,17799,17798,17797,17796,17722,17721,6827));
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=49890 WHERE (`Entry`=53488 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1077, `CreatureDifficultyID`=17330, `VerifiedBuild`=49890 WHERE (`Entry`=21696 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1077, `CreatureDifficultyID`=17327, `VerifiedBuild`=49890 WHERE (`Entry`=21695 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1077, `CreatureDifficultyID`=17324, `VerifiedBuild`=49890 WHERE (`Entry`=21694 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1077, `CreatureDifficultyID`=17073, `VerifiedBuild`=49890 WHERE (`Entry`=21338 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1077, `CreatureDifficultyID`=13576, `VerifiedBuild`=49890 WHERE (`Entry`=17954 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1077, `CreatureDifficultyID`=13569, `VerifiedBuild`=49890 WHERE (`Entry`=17951 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1077, `CreatureDifficultyID`=13523, `VerifiedBuild`=49890 WHERE (`Entry`=17917 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1077, `CreatureDifficultyID`=13352, `VerifiedBuild`=49890 WHERE (`Entry`=17805 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1077, `CreatureDifficultyID`=13348, `VerifiedBuild`=49890 WHERE (`Entry`=17803 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1077, `CreatureDifficultyID`=13345, `VerifiedBuild`=49890 WHERE (`Entry`=17802 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1077, `CreatureDifficultyID`=13342, `VerifiedBuild`=49890 WHERE (`Entry`=17801 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1077, `CreatureDifficultyID`=13339, `VerifiedBuild`=49890 WHERE (`Entry`=17800 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1077, `CreatureDifficultyID`=13336, `VerifiedBuild`=49890 WHERE (`Entry`=17799 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1077, `CreatureDifficultyID`=13333, `TypeFlags2`=128, `VerifiedBuild`=49890 WHERE (`Entry`=17798 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1077, `HealthModifier`=36, `CreatureDifficultyID`=13330, `TypeFlags2`=128, `VerifiedBuild`=49890 WHERE (`Entry`=17797 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1077, `HealthModifier`=24, `CreatureDifficultyID`=13327, `TypeFlags2`=128, `VerifiedBuild`=49890 WHERE (`Entry`=17796 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1077, `CreatureDifficultyID`=13222, `VerifiedBuild`=49890 WHERE (`Entry`=17722 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1077, `CreatureDifficultyID`=13219, `VerifiedBuild`=49890 WHERE (`Entry`=17721 AND `DifficultyID`=2);

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=17798 AND `DifficultyID`=2 AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `DifficultyID`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(17798, 2, 0, 33827, 49890); -- Warlord Kalithresh

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=49890 WHERE `DisplayID` IN (29407, 29418, 15374, 17294, 5561, 17450, 6932, 6937, 17423, 6936, 18394, 18391, 18398, 18392, 18389, 17691, 20235, 11268, 18638, 18396, 18388, 18075, 1924, 6297, 6295, 32790, 32791, 45880, 32789, 1206, 901);
UPDATE `creature_template_model` SET `VerifiedBuild`=49890 WHERE (`Idx`=0 AND `CreatureID` IN (21695,54849,17954,17797,17722,6827,1420,2914,17799,17802,54851,20926,17803,17721,13321,18362,17805,21694,21338,17801,17798,17917,54852,54638,17378,17796,17800,308,54848,17951,21696)) OR (`Idx`=3 AND `CreatureID` IN (6827,2914,13321)) OR (`Idx`=2 AND `CreatureID` IN (6827,2914,13321,21338)) OR (`Idx`=1 AND `CreatureID` IN (6827,2914,20926,13321,21338,54638,17951));

-- Gameobject templates
UPDATE `gameobject_template` SET `VerifiedBuild`=49890 WHERE `entry` IN (182197, 184125, 181557, 184126, 181555, 181556, 183049, 181275, 181278, 214501, 181270);
