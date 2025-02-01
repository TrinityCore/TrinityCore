-- Creature templates
UPDATE `creature_template` SET `speed_walk`=1, `unit_flags2`=2048 WHERE `entry`=28276; -- Greater Ley-Whelp
UPDATE `creature_template` SET `speed_walk`=1.799999952316284179, `speed_run`=0.642857134342193603, `unit_flags3`=524288 WHERE `entry`=28239; -- Arcane Beam
UPDATE `creature_template` SET `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=28236; -- Azure Ring Captain
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=28183; -- Centrifuge Core
UPDATE `creature_template` SET `unit_flags3`=524289 WHERE `entry`=28166; -- Unstable Sphere
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=28153; -- Snowflake
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=28012; -- Image of Belgaristrasz
UPDATE `creature_template` SET `speed_walk`=1, `unit_flags3`=524288 WHERE `entry`=27756; -- Ruby Drake
UPDATE `creature_template` SET `speed_walk`=1, `unit_flags3`=524288 WHERE `entry`=27755; -- Amber Drake
UPDATE `creature_template` SET `speed_walk`=1, `unit_flags3`=524288 WHERE `entry`=27692; -- Emerald Drake
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=27656; -- Ley-Guardian Eregos
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=27655; -- Mage-Lord Urom
UPDATE `creature_template` SET `speed_walk`=1, `unit_flags2`=2048 WHERE `entry`=27654; -- Drakos the Interrogator
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=27653; -- Phantasmal Water
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857193946838378, `unit_flags3`=0 WHERE `entry`=27642; -- Phantasmal Mammoth
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=27641; -- Centrifuge Construct
UPDATE `creature_template` SET `speed_walk`=1, `unit_flags2`=2048 WHERE `entry`=27638; -- Azure Ring Guardian
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=27636; -- Azure Ley-Whelp
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=27635; -- Azure Spellbinder
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857193946838378 WHERE `entry`=27633; -- Azure Inquisitor
UPDATE `creature_template` SET `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=27447; -- Varos Cloudstrider
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=30879; -- Planar Anomaly

UPDATE `creature_template_addon` SET `AnimTier`=0, `auras`='' WHERE `entry`=27756; -- 27756 (Ruby Drake)
UPDATE `creature_template_addon` SET `AnimTier`=0, `auras`='' WHERE `entry`=27755; -- 27755 (Amber Drake)
UPDATE `creature_template_addon` SET `AnimTier`=0, `auras`='' WHERE `entry`=27692; -- 27692 (Emerald Drake)
UPDATE `creature_template_addon` SET `AnimTier`=3 WHERE `entry`=27656; -- 27656 (Ley-Guardian Eregos)
UPDATE `creature_template_addon` SET `AnimTier`=3, `SheathState`=1 WHERE `entry`=30879; -- 30879 (Planar Anomaly)

-- Difficulties
UPDATE `creature_template_difficulty` ctd
LEFT JOIN `creature_template_difficulty` ctd2 ON ctd.`Entry`=ctd2.`Entry`
SET
    ctd.`DamageModifier`=ctd2.`DamageModifier`,
    ctd.`LootID`=ctd2.`LootID`,
    ctd.`PickPocketLootID`=ctd2.`PickPocketLootID`,
    ctd.`SkinLootID`=ctd2.`SkinLootID`,
    ctd.`GoldMin`=ctd2.`GoldMin`,
    ctd.`GoldMax`=ctd2.`GoldMax`
WHERE ctd.`Entry` IN (32261,28276,28239,28236,28183,28166,28153,28012,27756,27755,27692,27659,27658,27657,27656,27655,27654,27653,27651,27650,27649,27648,27647,27645,27644,27642,27641,27640,27639,27638,27636,27635,27633,27447)
AND ctd.`DifficultyID`=0 AND ctd2.`DifficultyID`=1 AND ctd2.`Entry` IS NOT NULL;

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=1 AND `Entry` IN (32261,28276,28239,28236,28183,28166,28153,28012,27756,27755,27692,27659,27658,27657,27656,27655,27654,27653,27651,27650,27649,27648,27647,27645,27644,27642,27641,27640,27639,27638,27636,27635,27633,27447));

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry` IN (28236,27756,27755,27692,22517));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(28236, 2, 0, 0, 1093, 805830656, 0, 0, 0, 0, 0, 0, 0, 54904), -- 28236 (Azure Ring Captain) - CanSwim, Floating
(27756, 2, 0, 0, 1093, 524288, 0, 0, 0, 0, 0, 0, 0, 54904), -- 27756 (Ruby Drake) - 
(27755, 2, 0, 0, 1093, 524288, 0, 0, 0, 0, 0, 0, 0, 54904), -- 27755 (Amber Drake) - 
(27692, 2, 0, 0, 1093, 524288, 0, 0, 0, 0, 0, 0, 0, 54904), -- 27692 (Emerald Drake) - 
(22517, 2, 0, 0, 2672, 536870912, 0, 0, 0, 0, 0, 0, 0, 54904); -- 22517 (World Trigger (Large AOI)) - Floating

DELETE FROM `creature_template_difficulty` WHERE (`Entry`=30161 AND `DifficultyID`=2);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(30161, 2, 2, 7.936510086059570312, 1, 33879, 0, 0); -- Wyrmrest Skytalon

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=22517 AND `DifficultyID`=0); -- World Trigger (Large AOI)
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2671, `VerifiedBuild`=54904 WHERE (`Entry`=22517 AND `DifficultyID`=0); -- 22517 (World Trigger (Large AOI)) - Floating
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=54904 WHERE (`Entry`=53488 AND `DifficultyID`=0);
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=32261 AND `DifficultyID`=0); -- 32261 (Crystal Spider) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-1, `ContentTuningID`=246, `StaticFlags1`=805830656, `VerifiedBuild`=54904 WHERE (`Entry`=28276 AND `DifficultyID`=0); -- 28276 (Greater Ley-Whelp) - Amphibious, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=246, `VerifiedBuild`=54904 WHERE (`Entry`=28239 AND `DifficultyID`=0); -- 28239 (Arcane Beam) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=246, `StaticFlags1`=805830656, `VerifiedBuild`=54904 WHERE (`Entry`=28236 AND `DifficultyID`=0); -- 28236 (Azure Ring Captain) - Amphibious, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=246, `StaticFlags1`=805830912, `VerifiedBuild`=54904 WHERE (`Entry`=28183 AND `DifficultyID`=0); -- 28183 (Centrifuge Core) - Sessile, Amphibious, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=246, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=28166 AND `DifficultyID`=0); -- 28166 (Unstable Sphere) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=246, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=28153 AND `DifficultyID`=0); -- 28153 (Snowflake) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=246, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=28012 AND `DifficultyID`=0); -- 28012 (Image of Belgaristrasz) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=246, `StaticFlags1`=524288, `VerifiedBuild`=54904 WHERE (`Entry`=27756 AND `DifficultyID`=0); -- 27756 (Ruby Drake) - Amphibious
UPDATE `creature_template_difficulty` SET `ContentTuningID`=246, `StaticFlags1`=524288, `VerifiedBuild`=54904 WHERE (`Entry`=27755 AND `DifficultyID`=0); -- 27755 (Amber Drake) - Amphibious
UPDATE `creature_template_difficulty` SET `ContentTuningID`=246, `StaticFlags1`=524288, `VerifiedBuild`=54904 WHERE (`Entry`=27692 AND `DifficultyID`=0); -- 27692 (Emerald Drake) - Amphibious
UPDATE `creature_template_difficulty` SET `ContentTuningID`=246, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27659 AND `DifficultyID`=0); -- 27659 (Eternos) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=246, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27658 AND `DifficultyID`=0); -- 27658 (Belgaristrasz) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=246, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27657 AND `DifficultyID`=0); -- 27657 (Verdisa) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=246, `StaticFlags1`=805830656, `StaticFlags2`=0, `VerifiedBuild`=54904 WHERE (`Entry`=27656 AND `DifficultyID`=0); -- 27656 (Ley-Guardian Eregos) - Amphibious, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=246, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27655 AND `DifficultyID`=0); -- 27655 (Mage-Lord Urom) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=246, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27654 AND `DifficultyID`=0); -- 27654 (Drakos the Interrogator) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=246, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27653 AND `DifficultyID`=0); -- 27653 (Phantasmal Water) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-1, `ContentTuningID`=246, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27651 AND `DifficultyID`=0); -- 27651 (Phantasmal Fire) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-1, `LevelScalingDeltaMax`=-1, `ContentTuningID`=246, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27650 AND `DifficultyID`=0); -- 27650 (Phantasmal Air) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-1, `LevelScalingDeltaMax`=-1, `ContentTuningID`=246, `VerifiedBuild`=54904 WHERE (`Entry`=27649 AND `DifficultyID`=0); -- 27649 (Phantasmal Murloc) - Amphibious
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-1, `ContentTuningID`=246, `VerifiedBuild`=54904 WHERE (`Entry`=27648 AND `DifficultyID`=0); -- 27648 (Phantasmal Naga) - Amphibious
UPDATE `creature_template_difficulty` SET `ContentTuningID`=246, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27647 AND `DifficultyID`=0); -- 27647 (Phantasmal Ogre) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-1, `LevelScalingDeltaMax`=-1, `ContentTuningID`=246, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27645 AND `DifficultyID`=0); -- 27645 (Phantasmal Cloudscraper) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=246, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27644 AND `DifficultyID`=0); -- 27644 (Phantasmal Wolf) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=246, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27642 AND `DifficultyID`=0); -- 27642 (Phantasmal Mammoth) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-1, `ContentTuningID`=246, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27641 AND `DifficultyID`=0); -- 27641 (Centrifuge Construct) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-1, `ContentTuningID`=246, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27640 AND `DifficultyID`=0); -- 27640 (Ring-Lord Conjurer) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-1, `LevelScalingDeltaMax`=-1, `ContentTuningID`=246, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27639 AND `DifficultyID`=0); -- 27639 (Ring-Lord Sorceress) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-1, `ContentTuningID`=246, `StaticFlags1`=805830656, `VerifiedBuild`=54904 WHERE (`Entry`=27638 AND `DifficultyID`=0); -- 27638 (Azure Ring Guardian) - Amphibious, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-1, `ContentTuningID`=246, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27636 AND `DifficultyID`=0); -- 27636 (Azure Ley-Whelp) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-1, `ContentTuningID`=246, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27635 AND `DifficultyID`=0); -- 27635 (Azure Spellbinder) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-1, `ContentTuningID`=246, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27633 AND `DifficultyID`=0); -- 27633 (Azure Inquisitor) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=246, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27447 AND `DifficultyID`=0); -- 27447 (Varos Cloudstrider) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=246, `StaticFlags1`=536870912, `VerifiedBuild`=54904 WHERE (`Entry`=30879 AND `DifficultyID`=0); -- 30879 (Planar Anomaly) - Floating
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=28472 WHERE (`Entry`=27653 AND `DifficultyID`=2); -- Phantasmal Water
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=29821 WHERE (`Entry`=28276 AND `DifficultyID`=2); -- Greater Ley-Whelp
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=28438 WHERE (`Entry`=27645 AND `DifficultyID`=2); -- Phantasmal Cloudscraper
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=28467 WHERE (`Entry`=27651 AND `DifficultyID`=2); -- Phantasmal Fire
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=28478, `TypeFlags2`=128 WHERE (`Entry`=27654 AND `DifficultyID`=2); -- Drakos the Interrogator
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=28452 WHERE (`Entry`=27648 AND `DifficultyID`=2); -- Phantasmal Naga
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=28457 WHERE (`Entry`=27649 AND `DifficultyID`=2); -- Phantasmal Murloc
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=28462 WHERE (`Entry`=27650 AND `DifficultyID`=2); -- Phantasmal Air
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=28420 WHERE (`Entry`=27641 AND `DifficultyID`=2); -- Centrifuge Construct
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=28491, `TypeFlags2`=128 WHERE (`Entry`=27656 AND `DifficultyID`=2); -- Ley-Guardian Eregos
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=28426 WHERE (`Entry`=27642 AND `DifficultyID`=2); -- Phantasmal Mammoth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=2, `CreatureDifficultyID`=29739 WHERE (`Entry`=28239 AND `DifficultyID`=2); -- Arcane Beam
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=28415 WHERE (`Entry`=27640 AND `DifficultyID`=2); -- Ring-Lord Conjurer
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=28448 WHERE (`Entry`=27647 AND `DifficultyID`=2); -- Phantasmal Ogre
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=28410 WHERE (`Entry`=27639 AND `DifficultyID`=2); -- Ring-Lord Sorceress
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=29557 WHERE (`Entry`=28153 AND `DifficultyID`=2); -- Snowflake
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=28009, `TypeFlags2`=128 WHERE (`Entry`=27447 AND `DifficultyID`=2); -- Varos Cloudstrider
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=28381 WHERE (`Entry`=27633 AND `DifficultyID`=2); -- Azure Inquisitor
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=28404 WHERE (`Entry`=27638 AND `DifficultyID`=2); -- Azure Ring Guardian
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=28433 WHERE (`Entry`=27644 AND `DifficultyID`=2); -- Phantasmal Wolf
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=28397 WHERE (`Entry`=27636 AND `DifficultyID`=2); -- Azure Ley-Whelp
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=28483, `TypeFlags2`=128 WHERE (`Entry`=27655 AND `DifficultyID`=2); -- Mage-Lord Urom
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=28392 WHERE (`Entry`=27635 AND `DifficultyID`=2); -- Azure Spellbinder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=2, `HealthModifier`=10, `ManaModifier`=5, `CreatureDifficultyID`=195364, `TypeFlags`=8 WHERE (`Entry`=28236 AND `DifficultyID`=2); -- Azure Ring Captain
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=2, `HealthModifier`=5.952380180358886718, `CreatureDifficultyID`=195366, `TypeFlags`=72 WHERE (`Entry`=27755 AND `DifficultyID`=2); -- Amber Drake
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=2, `HealthModifier`=5.952380180358886718, `CreatureDifficultyID`=195367, `TypeFlags`=72 WHERE (`Entry`=27756 AND `DifficultyID`=2); -- Ruby Drake
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3, `HealthModifier`=1.35000002384185791, `CreatureDifficultyID`=18489 WHERE (`Entry`=22517 AND `DifficultyID`=2); -- World Trigger (Large AOI)
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=2, `HealthModifier`=5.952380180358886718, `CreatureDifficultyID`=195365, `TypeFlags`=72 WHERE (`Entry`=27692 AND `DifficultyID`=2); -- Emerald Drake
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=54904 WHERE (`DifficultyID`=2 AND `Entry` IN (53488,27649));
UPDATE `creature_template_difficulty` SET `StaticFlags1`=805830656, `VerifiedBuild`=54904 WHERE (`Entry`=28276 AND `DifficultyID`=2); -- 28276 (Greater Ley-Whelp) - Amphibious, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1093, `VerifiedBuild`=54904 WHERE (`Entry`=28239 AND `DifficultyID`=2); -- 28239 (Arcane Beam) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=1, `ContentTuningID`=1093, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=28153 AND `DifficultyID`=2); -- 28153 (Snowflake) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=805830656, `StaticFlags2`=0, `VerifiedBuild`=54904 WHERE (`Entry`=27656 AND `DifficultyID`=2); -- 27656 (Ley-Guardian Eregos) - Amphibious, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27655 AND `DifficultyID`=2); -- 27655 (Mage-Lord Urom) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27654 AND `DifficultyID`=2); -- 27654 (Drakos the Interrogator) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27653 AND `DifficultyID`=2); -- 27653 (Phantasmal Water) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27651 AND `DifficultyID`=2); -- 27651 (Phantasmal Fire) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27650 AND `DifficultyID`=2); -- 27650 (Phantasmal Air) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `VerifiedBuild`=54904 WHERE (`Entry`=27648 AND `DifficultyID`=2); -- 27648 (Phantasmal Naga) - Amphibious
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27647 AND `DifficultyID`=2); -- 27647 (Phantasmal Ogre) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27645 AND `DifficultyID`=2); -- 27645 (Phantasmal Cloudscraper) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27644 AND `DifficultyID`=2); -- 27644 (Phantasmal Wolf) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=0, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27642 AND `DifficultyID`=2); -- 27642 (Phantasmal Mammoth) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27641 AND `DifficultyID`=2); -- 27641 (Centrifuge Construct) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27640 AND `DifficultyID`=2); -- 27640 (Ring-Lord Conjurer) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27639 AND `DifficultyID`=2); -- 27639 (Ring-Lord Sorceress) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=805830656, `VerifiedBuild`=54904 WHERE (`Entry`=27638 AND `DifficultyID`=2); -- 27638 (Azure Ring Guardian) - Amphibious, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27636 AND `DifficultyID`=2); -- 27636 (Azure Ley-Whelp) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27635 AND `DifficultyID`=2); -- 27635 (Azure Spellbinder) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27633 AND `DifficultyID`=2); -- 27633 (Azure Inquisitor) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=27447 AND `DifficultyID`=2); -- 27447 (Varos Cloudstrider) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1019, `VerifiedBuild`=54904 WHERE (`Entry`=30161 AND `DifficultyID`=2); -- 30161 (Wyrmrest Skytalon) - 

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=54904 WHERE `DisplayID` IN (27718, 26089, 28046, 28419, 17612, 25347, 25011, 25852, 25853, 24746, 24759, 24742, 27034, 25010, 27032, 5450, 25148, 25146, 25149, 25150, 25151, 25147, 25153, 25145, 24943, 25303, 25304, 25302, 25305, 25307, 25306, 28080, 26088, 25250, 25195, 27033);
UPDATE `creature_model_info` SET `BoundingRadius`=2.23112344741821289, `VerifiedBuild`=54904 WHERE `DisplayID`=25854;
UPDATE `creature_model_info` SET `BoundingRadius`=2, `CombatReach`=4, `VerifiedBuild`=54904 WHERE `DisplayID`=28107;
UPDATE `creature_template_model` SET `VerifiedBuild`=54904 WHERE (`Idx`=0 AND `CreatureID` IN (27655,28183,27638,27644,28236,28166,32261,27651,27657,27645,27659,27447,27658,27653,27650,27635,27692,27647,28276,28012,28239,27755,27649,27642,28153,27756,27641,27636,27656,27648,27654,27633,27639,27640)) OR (`Idx`=1 AND `CreatureID` IN (28183,28239,27639,27640)) OR (`Idx`=2 AND `CreatureID` IN (27639,27640));
UPDATE `creature_template_model` SET `VerifiedBuild`=54904 WHERE (`CreatureID`=30879 AND `Idx` IN (1,0));

-- Gameobject templates
UPDATE `gameobject_template` SET `VerifiedBuild`=54904 WHERE `entry` IN (191351, 190172, 190343, 189985, 188715);
UPDATE `gameobject_template` SET `Data1`=0, `Data15`=0, `Data25`=2013, `Data30`=24462, `ContentTuningId`=245, `VerifiedBuild`=54904 WHERE `entry`=191349; -- Cache of Eregos
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=54904 WHERE `entry`=189986; -- Dragon Cage
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=54904 WHERE `entry`=193995; -- Dragon Cage Door
UPDATE `gameobject_template` SET `ContentTuningId`=245, `VerifiedBuild`=54904 WHERE `entry`=190402; -- Blaze

UPDATE `gameobject_template_addon` SET `flags`=2113536 WHERE `entry`=191349; -- Cache of Eregos
