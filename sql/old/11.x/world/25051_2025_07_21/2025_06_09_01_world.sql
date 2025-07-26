-- Adolescent Flame Hound
UPDATE `creature_template_difficulty` SET `GoldMin` = 2500, `GoldMax` = 10000 WHERE `Entry` = 61657;

-- Mature Flame Hound
UPDATE `creature_template_difficulty` SET `GoldMin` = 3000, `GoldMax` = 10000 WHERE `Entry` = 61658;

-- Corrupted Reaver & Dark Shaman Acolyte & Corrupted Flamecaller & Corrupted Houndmaster
UPDATE `creature_template_difficulty` SET `LootID` = 61678, `GoldMin` = 2000, `GoldMax` = 10000 WHERE `Entry` IN (61678, 61672, 61705, 61666);

DELETE FROM `creature_loot_template` WHERE `Entry` = 61678;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(61678, 0, 2589, 50, 0, 1, 0, 1, 5, 'Linen Cloth');
