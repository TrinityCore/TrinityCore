SET @REFERENCEID := 700018;

-- Difficulty (Flowing Honey)
UPDATE `creature_template_difficulty` SET `LootID`=131663 WHERE `Entry`=131663;

DELETE FROM `creature_loot_template` WHERE `Entry` = 131663;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(131663, 1, @REFERENCEID+0, 100, 0, 1, 1, 1, 1, 'Reference Junk loot'),
(131663, 0, 156825, 13, 1, 1, 0, 1, 1, 'Vial of Honey Slime'), -- Chance = 13.260566%
(131663, 0, 163699, 0.4, 1, 1, 0, 1, 1, 'Annealed Honey Amulet'), -- Chance = 0.364520%
(131663, 0, 230053, 1, 1, 1, 0, 1, 1, 'Honey Globule'), -- Chance = 0.997397%
(131663, 1, 700000, 2, 1, 1, 1, 1, 1, 'Reference Uncommon loot');

-- Junk Items: Using best match Entry @REFERENCEID+0
DELETE FROM `reference_loot_template` WHERE `Entry` = @REFERENCEID+0;
INSERT INTO `reference_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFERENCEID+0, 0, 157844, 0, 0, 1, 1, 1, 1, 'Iridescent Speck'), -- Chance = 86.383810%
(@REFERENCEID+0, 0, 158831, 0, 0, 1, 1, 1, 1, 'Parched Honeycomb'), -- Chance = 3.881134%
(@REFERENCEID+0, 0, 158872, 0, 0, 1, 1, 1, 1, 'Unstable Essence'), -- Chance = 0.002458%
(@REFERENCEID+0, 0, 158873, 0, 0, 1, 1, 1, 1, 'Crystalline Honeymead'); -- Chance = 9.469099%

-- Difficulty (Bubbling Mead)
UPDATE `creature_template_difficulty` SET `LootID`=133429 WHERE `Entry`=133429;

DELETE FROM `creature_loot_template` WHERE `Entry` = 133429;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(133429, 1, @REFERENCEID+0, 100, 0, 1, 1, 1, 1, 'Reference Junk loot'),
(133429, 0, 156825, 14, 1, 1, 0, 1, 1, 'Vial of Honey Slime'), -- Chance = 14.266883%
(133429, 0, 163699, 0.4, 1, 1, 0, 1, 1, 'Annealed Honey Amulet'), -- Chance = 0.313944%
(133429, 1, 700000, 2, 0, 1, 1, 1, 1, 'Reference Uncommon loot');
