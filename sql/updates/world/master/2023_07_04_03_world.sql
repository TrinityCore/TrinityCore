-- Creature templates
UPDATE `creature_template` SET `speed_walk`=1, `unit_flags3`=524288 WHERE `entry`=17540; -- Fiendish Hound
UPDATE `creature_template` SET `unit_flags`=32832, `unit_flags2`=2099200, `unit_flags3`=8912896 WHERE `entry`=17537; -- Vazruden
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=17306; -- Watchkeeper Gargolmar
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=17280; -- Shattered Hand Warhound

-- Difficulty
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=50000 WHERE (`DifficultyID`=1 AND `Entry` IN (54607,54606,17540,17537,17307,17517,17478,17455,17309,17308,17306,17281,17280,17271,17270,17269,17264,17259));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1065, `CreatureDifficultyID`=13011, `VerifiedBuild`=50000 WHERE (`Entry`=17540 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1065, `CreatureDifficultyID`=13006, `TypeFlags2`=128, `VerifiedBuild`=50000 WHERE (`Entry`=17537 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1065, `CreatureDifficultyID`=12710, `VerifiedBuild`=50000 WHERE (`Entry`=17307 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-1, `LevelScalingDeltaMax`=0, `ContentTuningID`=1065, `CreatureDifficultyID`=12982, `VerifiedBuild`=50000 WHERE (`Entry`=17517 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1065, `CreatureDifficultyID`=12942, `VerifiedBuild`=50000 WHERE (`Entry`=17478 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1065, `CreatureDifficultyID`=12904, `VerifiedBuild`=50000 WHERE (`Entry`=17455 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1065, `CreatureDifficultyID`=12716, `VerifiedBuild`=50000 WHERE (`Entry`=17309 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1065, `CreatureDifficultyID`=12713, `TypeFlags2`=128, `VerifiedBuild`=50000 WHERE (`Entry`=17308 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1065, `CreatureDifficultyID`=12707, `TypeFlags2`=128, `VerifiedBuild`=50000 WHERE (`Entry`=17306 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1065, `CreatureDifficultyID`=12678, `VerifiedBuild`=50000 WHERE (`Entry`=17281 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1065, `CreatureDifficultyID`=12675, `VerifiedBuild`=50000 WHERE (`Entry`=17280 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1065, `CreatureDifficultyID`=12665, `VerifiedBuild`=50000 WHERE (`Entry`=17271 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1065, `CreatureDifficultyID`=12662, `VerifiedBuild`=50000 WHERE (`Entry`=17270 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1065, `CreatureDifficultyID`=12659, `VerifiedBuild`=50000 WHERE (`Entry`=17269 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1065, `CreatureDifficultyID`=12652, `VerifiedBuild`=50000 WHERE (`Entry`=17264 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1065, `CreatureDifficultyID`=12645, `VerifiedBuild`=50000 WHERE (`Entry`=17259 AND `DifficultyID`=2);

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=17536 AND `DifficultyID`=0 AND `Idx`=1);
DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=17307 AND `DifficultyID`=2 AND `Idx`=2) OR (`CreatureEntry`=17307 AND `DifficultyID`=2 AND `Idx`=1) OR (`CreatureEntry`=17307 AND `DifficultyID`=2 AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `DifficultyID`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(17307, 2, 2, 35229, 50000), -- Vazruden the Herald
(17307, 2, 1, 33833, 50000), -- Vazruden the Herald
(17307, 2, 0, 23901, 50000); -- Vazruden the Herald

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=50000 WHERE `DisplayID` IN (17039, 10950, 18407, 18812, 16577, 17048, 16583, 17051, 18237, 18236, 17732, 14334, 17043, 17050, 17044, 17049, 17052);
UPDATE `creature_template_model` SET `VerifiedBuild`=50000 WHERE (`Idx`=0 AND `CreatureID` IN (17537,17478,17517,17308,17259,17455,17306,17271,17307,17280,17536,17281,17270,17264,17309,54606,17540,54607,17269)) OR (`Idx`=3 AND `CreatureID`=54607) OR (`Idx`=2 AND `CreatureID`=54607) OR (`Idx`=1 AND `CreatureID`=54607);

-- Gameobject templates
UPDATE `gameobject_template` SET `VerifiedBuild`=50000 WHERE `entry` IN (209347, 185168, 181734, 181735, 181738, 181736, 181737);

UPDATE `gameobject_questitem` SET `VerifiedBuild`=50000 WHERE (`GameObjectEntry`=209347 AND `Idx`=0);
