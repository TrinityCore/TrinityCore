DELETE FROM `creature_template_difficulty` WHERE `Entry` = 95226 AND `DifficultyID` = 1;

UPDATE `creature_template_difficulty` SET `LootID` = 95226 WHERE `Entry` = 95226 AND `DifficultyID` = 0;

DELETE FROM `creature_loot_template` WHERE `Entry` = 95226 AND `Item` = 128227;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(95226, 128227, 0, 100, 1, 1, 0, 1, 1, 'Anguish Jailer - Soulwrought Key');
