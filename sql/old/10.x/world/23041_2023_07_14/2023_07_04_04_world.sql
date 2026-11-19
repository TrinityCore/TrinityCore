-- Creature templates
UPDATE `creature_template` SET `speed_run`=1.142857193946838378, `unit_flags3`=16777216 WHERE `entry`=55108; -- Fel Anomaly
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=17662; -- Broggok Poison Cloud
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=17401; -- Felhound Manastalker
UPDATE `creature_template` SET `speed_walk`=1, `unit_flags`=32768, `unit_flags3`=524288 WHERE `entry`=17399; -- Seductress
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=17381; -- The Maker
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=17377; -- Keli'dan the Breaker
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=16006; -- InCombat Trigger

-- Difficulty
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=50000 WHERE (`DifficultyID`=1 AND `Entry` IN (55108,54637,54636,21174,19016,18894,17662,17653,17626,17624,17491,17477,17429,17416,17414,17401,17400,17399,17398,17397,17395,17381,17380,17377,17371,17370,17256,16006));
UPDATE `creature_template_difficulty` SET `DifficultyID`=0 WHERE `DifficultyID`=1 AND `Entry` IN (16006,17256);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1072, `CreatureDifficultyID`=14809, `VerifiedBuild`=50000 WHERE (`Entry`=19016 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1072, `CreatureDifficultyID`=14676, `VerifiedBuild`=50000 WHERE (`Entry`=18894 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1072, `HealthScalingExpansion`=1, `CreatureDifficultyID`=13136, `VerifiedBuild`=50000 WHERE (`Entry`=17653 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1072, `CreatureDifficultyID`=13107, `VerifiedBuild`=50000 WHERE (`Entry`=17626 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1072, `CreatureDifficultyID`=13103, `VerifiedBuild`=50000 WHERE (`Entry`=17624 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1072, `CreatureDifficultyID`=12957, `VerifiedBuild`=50000 WHERE (`Entry`=17491 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1072, `CreatureDifficultyID`=12939, `VerifiedBuild`=50000 WHERE (`Entry`=17477 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1072, `CreatureDifficultyID`=12874, `VerifiedBuild`=50000 WHERE (`Entry`=17429 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1072, `CreatureDifficultyID`=12855, `VerifiedBuild`=50000 WHERE (`Entry`=17416 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1072, `CreatureDifficultyID`=12851, `VerifiedBuild`=50000 WHERE (`Entry`=17414 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1072, `CreatureDifficultyID`=12836, `VerifiedBuild`=50000 WHERE (`Entry`=17401 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1072, `CreatureDifficultyID`=12833, `VerifiedBuild`=50000 WHERE (`Entry`=17400 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1072, `CreatureDifficultyID`=12830, `VerifiedBuild`=50000 WHERE (`Entry`=17399 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1072, `CreatureDifficultyID`=12827, `VerifiedBuild`=50000 WHERE (`Entry`=17398 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1072, `CreatureDifficultyID`=12824, `VerifiedBuild`=50000 WHERE (`Entry`=17397 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1072, `CreatureDifficultyID`=12818, `VerifiedBuild`=50000 WHERE (`Entry`=17395 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1072, `HealthModifier`=21, `CreatureDifficultyID`=12802, `TypeFlags2`=128, `VerifiedBuild`=50000 WHERE (`Entry`=17381 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1072, `HealthModifier`=24, `CreatureDifficultyID`=12799, `TypeFlags2`=128, `VerifiedBuild`=50000 WHERE (`Entry`=17380 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1072, `HealthModifier`=30, `CreatureDifficultyID`=12794, `TypeFlags2`=128, `VerifiedBuild`=50000 WHERE (`Entry`=17377 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1072, `CreatureDifficultyID`=12786, `VerifiedBuild`=50000 WHERE (`Entry`=17371 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1072, `CreatureDifficultyID`=12783, `VerifiedBuild`=50000 WHERE (`Entry`=17370 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=1072, `HealthScalingExpansion`=1, `CreatureDifficultyID`=13147, `VerifiedBuild`=50000 WHERE (`Entry`=17662 AND `DifficultyID`=2);

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=17377 AND `DifficultyID`=2 AND `Idx`=1) OR (`CreatureEntry`=17377 AND `DifficultyID`=2 AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `DifficultyID`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(17377, 2, 1, 23894, 50000), -- Keli'dan the Breaker
(17377, 2, 0, 33814, 50000); -- Keli'dan the Breaker

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=50000 WHERE `DisplayID` IN (17088, 20127, 17150, 17152, 17151, 16891, 16888, 17167, 17147, 18342, 10923, 16332, 17148, 17145, 18369, 19372, 17153, 17137, 17149, 9865);
UPDATE `creature_template_model` SET `VerifiedBuild`=50000 WHERE (`Idx`=1 AND `CreatureID` IN (19016,17256,17477,54637,54638,55108)) OR (`Idx`=0 AND `CreatureID` IN (19016,17377,17395,17371,17401,54636,17429,17256,17400,17653,17399,18894,17397,17380,17477,16006,17491,17626,54637,17398,17370,54638,17662,17414,55108,17624,21174,17416,17381)) OR (`Idx`=3 AND `CreatureID`=54637) OR (`Idx`=2 AND `CreatureID`=54637);

-- Gameobject templates
UPDATE `gameobject_template` SET `VerifiedBuild`=50000 WHERE `entry` IN (181823, 181927, 181923, 181817, 181925, 181821, 181713, 181924, 181813, 181822, 181982, 181922, 181926, 181811, 181820, 181814, 181818, 181877, 181816, 181819, 181812, 181766, 181921, 181815);
UPDATE `gameobject_template` SET `ContentTuningId`=228, `VerifiedBuild`=50000 WHERE `entry`=182607; -- Proximity Bomb
