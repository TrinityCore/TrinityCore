SET @REFERENCEID := 700011;

-- Difficulty (Hexed Howler)
UPDATE `creature_template_difficulty` SET `LootID` = 124814 WHERE `Entry` = 124814;

DELETE FROM `creature_loot_template` WHERE `Entry` = 124814;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(124814, 0, 154897, 28, 0, 1, 0, 1, 4, 'Stringy Loins'),
(124814, 1, 700000, 3, 0, 1, 0, 1, 1, 'Reference World drop greens loot'),
(124814, 1, 700004, 100, 0, 1, 0, 1, 1, 'Reference World drop junk loot');

-- Difficulty (Harbor Raven)
UPDATE `creature_template_difficulty` SET `LootID` = 124921 WHERE `Entry` = 124921;

DELETE FROM `creature_loot_template` WHERE `Entry` = 124921;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(124921, 0, 154897, 29, 0, 1, 0, 1, 4, 'Stringy Loins'),
(124921, 1, 700000, 3, 0, 1, 0, 1, 1, 'Reference World drop greens loot'),
(124921, 1, 700005, 100, 0, 1, 0, 1, 1, 'Reference World drop junk loot');

-- Difficulty (Bonepicker Raven)
UPDATE `creature_template_difficulty` SET `LootID` = 124382 WHERE `Entry` = 124382;

DELETE FROM `creature_loot_template` WHERE `Entry` = 124382;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(124382, 0, 154897, 28, 0, 1, 0, 1, 4, 'Stringy Loins'),
(124382, 1, 700000, 3, 0, 1, 0, 1, 1, 'Reference World drop greens loot'),
(124382, 1, 700005, 100, 0, 1, 0, 1, 1, 'Reference World drop junk loot');

-- Difficulty (Fallhaven Pig)
UPDATE `creature_template_difficulty` SET `LootID` = 124170 WHERE `Entry` = 124170;

DELETE FROM `creature_loot_template` WHERE `Entry` = 124170;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(124170, 0, 154898, 27, 0, 1, 0, 1, 4, 'Meaty Haunch'),
(124170, 1, 700000, 3, 0, 1, 0, 1, 1, 'Reference World drop greens loot'),
(124170, 1, (@REFERENCEID+0), 100, 0, 1, 0, 1, 1, 'Reference World drop junk loot');

DELETE FROM `reference_loot_template` WHERE `Entry` = @REFERENCEID+0;
INSERT INTO `reference_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFERENCEID+0, 0, 158751, 0, 0, 1, 1, 1, 1, 'Matted Pelt'),
(@REFERENCEID+0, 0, 158797, 0, 0, 1, 1, 1, 1, 'Jar of Truffles'),
(@REFERENCEID+0, 0, 158813, 0, 0, 1, 1, 1, 1, 'Sausage Casing');
