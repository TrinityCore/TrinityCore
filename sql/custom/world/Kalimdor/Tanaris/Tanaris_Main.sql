-- Tanaris Fixes

-- NPC: 8207 Emberwind
-- NPC: 47386 Ainamiss the Hive Queen
-- NPC: 44759 Andre Firebeard
-- NPC: 44761 Aquementas the Unchained
-- NPC: 44750 Caliph Scorpidsting
-- NPC: 44714 Fronkle the Disturbed
-- NPC: 47387 Harakiss the Infestor
-- NPC: 44767 Occulus the Corrupted
-- NPC: 39183 Scorpitar
-- NPC: 39185 Slaverjaw

-- Difficulty fixes
-- Missing Content Tuning
UPDATE creature_template_difficulty SET `ContentTuningID` = 28 WHERE `Entry` = 47386 AND `DifficultyID` = 0;
UPDATE creature_template_difficulty SET `ContentTuningID` = 28 WHERE `Entry` = 47387 AND `DifficultyID` = 0;
UPDATE creature_template_difficulty SET `ContentTuningID` = 28, `LootID` = 44759, `GoldMin` = 1000, `GoldMax` = 2000 WHERE `Entry` = 44759 AND `DifficultyID` = 0;

UPDATE `creature_template_difficulty` SET `LootID` = 44761, StaticFlags1 = StaticFlags1 | 0x10000000 WHERE `Entry` = 44761 AND `DifficultyID` = 0;
UPDATE `creature_template_difficulty` SET `ContentTuningID` = 28, `LootID` = 44750, StaticFlags1 = StaticFlags1 | 0x10000000 WHERE `Entry` = 44750 AND `DifficultyID` = 0;
UPDATE `creature_template_difficulty` SET `ContentTuningID` = 28, `LootID` = 8207 WHERE `Entry` = 8207 AND `DifficultyID` = 0;
UPDATE `creature_template_difficulty` SET `LootID` = 44714, StaticFlags1 = StaticFlags1 | 0x10000000, `GoldMin` = 1000, `GoldMax` = 2000 WHERE `Entry` = 44714 AND `DifficultyID` = 0;
UPDATE `creature_template_difficulty` SET `ContentTuningID` = 28, `LootID` = 44767 WHERE `Entry` = 44767 AND `DifficultyID` = 0;
UPDATE `creature_template_difficulty` SET `ContentTuningID` = 28, `LootID` = 39183 WHERE `Entry` = 39183 AND `DifficultyID` = 0;
UPDATE `creature_template_difficulty` SET `ContentTuningID` = 28, `LootID` = 39185 WHERE `Entry` = 39185 AND `DifficultyID` = 0;
