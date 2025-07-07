SET @REFERENCEID := 700013;

-- Difficulty (Venomous Weaver)
UPDATE `creature_template_difficulty` SET `LootID`=125130 WHERE `Entry`=125130;

DELETE FROM `creature_loot_template` WHERE `Entry` = 125130;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(125130, 1, @REFERENCEID+0, 100, 0, 1, 1, 1, 1, 'Reference Junk loot'),
(125130, 0, 164985, 1, 1, 1, 0, 4, 6, 'Durable Spider Silk'),
(125130, 1, 700000, 2, 0, 1, 1, 1, 1, 'Reference Uncommon loot');

-- Junk Items:
DELETE FROM `reference_loot_template` WHERE `Entry` = @REFERENCEID+0;
INSERT INTO `reference_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFERENCEID+0, 0, 155601, 77, 0, 1, 1, 1, 1, 'Pointy Leg Segment'), -- Chance = 77.308624%
(@REFERENCEID+0, 0, 158759, 4, 0, 1, 1, 1, 1, 'Bloodgorged Sac'), -- Chance = 4.024708%
(@REFERENCEID+0, 0, 158864, 19, 0, 1, 1, 1, 1, 'Viscous Webbing'); -- Chance = 18.587811%

-- Difficulty (Woodland Bat)
UPDATE `creature_template_difficulty` SET `LootID`=126353 WHERE `Entry`=126353;

DELETE FROM `creature_loot_template` WHERE `Entry` = 126353;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(126353, 1, @REFERENCEID+1, 100, 0, 1, 1, 1, 1, 'Reference Junk loot'),
(126353, 0, 154897, 27, 0, 1, 0, 1, 4, 'Stringy Loins'), -- Chance = 26.610618%
(126353, 1, 700000, 2, 0, 1, 1, 1, 1, 'Reference Uncommon loot');

-- Junk Items:
DELETE FROM `reference_loot_template` WHERE `Entry` = @REFERENCEID+1;
INSERT INTO `reference_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFERENCEID+1, 0, 155635, 50, 0, 1, 1, 1, 1, 'Sinewy Wing'), -- Chance = 50.317587%
(@REFERENCEID+1, 0, 158749, 24, 0, 1, 1, 1, 1, 'Intricate Ossicles'), -- Chance = 23.366619%
(@REFERENCEID+1, 0, 158859, 26, 0, 1, 1, 1, 1, 'Jagged Fang'); -- Chance = 25.566619%
