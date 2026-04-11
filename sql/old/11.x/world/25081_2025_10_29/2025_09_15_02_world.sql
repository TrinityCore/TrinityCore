-- Difficulty (Watchful Raven)
UPDATE `creature_template_difficulty` SET `LootID`=121610 WHERE `Entry`=121610;

DELETE FROM `creature_loot_template` WHERE `Entry` = 121610;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(121610, 1, 700005, 100, 0, 1, 1, 1, 1, 'Reference Junk loot'), -- Total Drop Chance = 99.696379%
(121610, 0, 154897, 26, 0, 1, 0, 1, 4, 'Stringy Loins'), -- Chance = 26.139240%
(121610, 1, 700000, 2, 0, 1, 1, 1, 1, 'Reference Uncommon loot');

-- Difficulty (Darkmaw Prowler)
UPDATE `creature_template_difficulty` SET `LootID`=121620 WHERE `Entry`=121620;

DELETE FROM `creature_loot_template` WHERE `Entry` = 121620;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(121620, 1, 700004, 100, 0, 1, 1, 1, 1, 'Reference Junk loot'), -- Total Drop Chance = 99.347084%
(121620, 0, 154897, 26, 0, 1, 0, 1, 4, 'Stringy Loins'), -- Chance = 25.745299%
(121620, 1, 700000, 2, 0, 1, 1, 1, 1, 'Reference Uncommon loot');

-- Difficulty (Cursed Game-hawk)
UPDATE `creature_template_difficulty` SET `LootID`=122961 WHERE `Entry`=122961;

DELETE FROM `creature_loot_template` WHERE `Entry` = 122961;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(122961, 1, 700007, 100, 0, 1, 1, 1, 1, 'Reference Junk loot'), -- Total Drop Chance = 99.475153%
(122961, 0, 154897, 26, 0, 1, 0, 1, 4, 'Stringy Loins'), -- Chance = 26.362604%
(122961, 1, 700000, 2, 0, 1, 1, 1, 1, 'Reference Uncommon loot');
