SET @REFERENCEID := 700012;

-- Difficulty (Bonegnasher Skullcrusher)
UPDATE `creature_template_difficulty` SET `GoldMin` = 7500, `GoldMax` = 22000, `LootID`=127092 WHERE `Entry` IN (127092, 127127);

DELETE FROM `creature_loot_template` WHERE `Entry` = 127092;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(127092, 1, 700001, 23, 0, 1, 1, 1, 1, 'Reference Junk loot'),
(127092, 0, 152576, 60, 0, 1, 0, 1, 3, 'Tidespray Linen'),
(127092, 1, 700000, 4, 0, 1, 1, 1, 1, 'Reference Uncommon loot');

-- Difficulty (Tamed Boar)
UPDATE `creature_template_difficulty` SET `LootID`=127699 WHERE `Entry`=127699;

DELETE FROM `creature_loot_template` WHERE `Entry` = 127699;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(127699, 1, 700011, 100, 0, 1, 1, 1, 1, 'Reference Junk loot'),
(127699, 0, 154898, 31, 0, 1, 0, 1, 4, 'Meaty Haunch'),
(127699, 1, 700000, 2, 0, 1, 1, 1, 1, 'Reference Uncommon loot');

-- Difficulty (Alpine Goat)
UPDATE `creature_template_difficulty` SET `LootID`=127822 WHERE `Entry`=127822;

DELETE FROM `creature_loot_template` WHERE `Entry` = 127822;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(127822, 1, @REFERENCEID+0, 100, 0, 1, 1, 1, 1, 'Reference Junk loot'),
(127822, 0, 154898, 32, 0, 1, 0, 1, 4, 'Meaty Haunch'),
(127822, 1, 700000, 2, 0, 1, 1, 1, 1, 'Reference Uncommon loot');

-- Junk Items
DELETE FROM `reference_loot_template` WHERE `Entry` = @REFERENCEID+0;
INSERT INTO `reference_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFERENCEID+0, 0, 158779, 0, 0, 1, 1, 1, 1, 'Robust Horn'),
(@REFERENCEID+0, 0, 158860, 0, 0, 1, 1, 1, 1, 'Grindstone Molar'),
(@REFERENCEID+0, 0, 158870, 0, 0, 1, 1, 1, 1, 'Wooly Hair');

-- Difficulty (Vale Falcon)
UPDATE `creature_template_difficulty` SET `LootID`=128389 WHERE `Entry`=128389;

DELETE FROM `creature_loot_template` WHERE `Entry` = 128389;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(128389, 1, 700007, 100, 0, 1, 1, 1, 1, 'Reference Junk loot'),
(128389, 0, 154897, 28, 0, 1, 0, 1, 4, 'Stringy Loins'),
(128389, 1, 700000, 3, 0, 1, 1, 1, 1, 'Reference Uncommon loot');

-- Difficulty (Hexed Craghopper)
UPDATE `creature_template_difficulty` SET `LootID`=143929 WHERE `Entry`=143929;

DELETE FROM `creature_loot_template` WHERE `Entry` = 143929;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(143929, 1, @REFERENCEID+0, 100, 0, 1, 1, 1, 1, 'Reference Junk loot'),
(143929, 0, 154898, 29, 0, 1, 0, 1, 4, 'Meaty Haunch'),
(143929, 1, 700000, 1, 0, 1, 1, 1, 1, 'Reference Uncommon loot');
