SET @REFERENCEID := 700008;

-- Difficulty (Enraged Spirit)
UPDATE `creature_template_difficulty` SET `LootID` = 126264 WHERE `Entry` = 126264;

DELETE FROM `creature_loot_template` WHERE `Entry` = 126264;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(126264, 1, 700000, 3, 0, 1, 0, 1, 1, 'Reference World drop greens loot'),
(126264, 1, (@REFERENCEID+0), 100, 0, 1, 0, 1, 1, 'Reference World drop junk loot');

-- Reference Loot table junk
DELETE FROM `reference_loot_template` WHERE `Entry` = @REFERENCEID+0;
INSERT INTO `reference_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
((@REFERENCEID+0), 0, 158771, 0, 0, 1, 1, 1, 1, 'Spirit Ichor'),
((@REFERENCEID+0), 0, 158865, 0, 0, 1, 1, 1, 1, 'Ghastly Ooze'),
((@REFERENCEID+0), 0, 158744, 0, 0, 1, 1, 1, 1, 'Spectral Veil');

-- Difficulty (Soulgorged Gravestalker)
UPDATE `creature_template_difficulty` SET `LootID` = 126263 WHERE `Entry` = 126263;

DELETE FROM `creature_loot_template` WHERE `Entry` = 126263;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(126263, 1, 700000, 3, 0, 1, 0, 1, 1, 'Reference World drop greens loot'),
(126263, 1, 700002, 100, 0, 1, 0, 1, 1, 'Reference World drop junk loot');

-- Difficulty (Wicker-Bound Hunter)
UPDATE `creature_template_difficulty` SET `LootID` = 126262 WHERE `Entry` = 126262;

DELETE FROM `creature_loot_template` WHERE `Entry` = 126262;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(126262, 1, (@REFERENCEID+1), 5, 0, 1, 0, 1, 1, 'Reference World drop greens loot'),
(126262, 1, 700002, 100, 0, 1, 0, 1, 1, 'Reference World drop junk loot');

DELETE FROM `reference_loot_template` WHERE `Entry` = @REFERENCEID+1;
INSERT INTO `reference_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFERENCEID+1, 0, 159283, 0, 0, 1, 1, 1, 1, 'Barrowknoll Cloak'),
(@REFERENCEID+1, 0, 159818, 0, 0, 1, 1, 1, 1, 'Deepwarden Torch'),
(@REFERENCEID+1, 0, 154844, 0, 0, 1, 1, 1, 1, 'Corlain Greaves'),
(@REFERENCEID+1, 0, 154847, 0, 0, 1, 1, 1, 1, 'Corlain Vambraces'),
(@REFERENCEID+1, 0, 159585, 0, 0, 1, 1, 1, 1, 'Ironcrest Sword'),
(@REFERENCEID+1, 0, 154863, 0, 0, 1, 1, 1, 1, 'Barrowknoll Legguards'),
(@REFERENCEID+1, 0, 159511, 0, 0, 1, 1, 1, 1, 'Wavecaller Fists'),
(@REFERENCEID+1, 0, 159475, 0, 0, 1, 1, 1, 1, 'Shipwreck Axe'),
(@REFERENCEID+1, 0, 154859, 0, 0, 1, 1, 1, 1, 'Barrowknoll Bracers'),
(@REFERENCEID+1, 0, 159535, 0, 0, 1, 1, 1, 1, 'Wavecaller Mave'),
(@REFERENCEID+1, 0, 159537, 0, 0, 1, 1, 1, 1, 'Deepwarden Gravel'),
(@REFERENCEID+1, 0, 159280, 0, 0, 1, 1, 1, 1, 'Crimsonwood Drape'),
(@REFERENCEID+1, 0, 154862, 0, 0, 1, 1, 1, 1, 'Barrowknoll Coif'),
(@REFERENCEID+1, 0, 159604, 0, 0, 1, 1, 1, 1, 'Coldscale Rod'),
(@REFERENCEID+1, 0, 159501, 0, 0, 1, 1, 1, 1, 'Coralshel Glaives'),
(@REFERENCEID+1, 0, 154850, 0, 0, 1, 1, 1, 1, 'Crimsonwood Boots'),
(@REFERENCEID+1, 0, 159587, 0, 0, 1, 1, 1, 1, 'Dockyard Cutlass'),
(@REFERENCEID+1, 0, 159284, 0, 0, 1, 1, 1, 1, 'Corlain Cape'),
(@REFERENCEID+1, 0, 154858, 0, 0, 1, 1, 1, 1, 'Barrowknoll Cinch'),
(@REFERENCEID+1, 0, 154843, 0, 0, 1, 1, 1, 1, 'Corlain Greathelm'),
(@REFERENCEID+1, 0, 159560, 0, 0, 1, 1, 1, 1, 'Dockyard Pike'),
(@REFERENCEID+1, 0, 159493, 0, 0, 1, 1, 1, 1, 'Gnarlwood Crossbow'),
(@REFERENCEID+1, 0, 159540, 0, 0, 1, 1, 1, 1, 'Coralshell Hammer'),
(@REFERENCEID+1, 0, 154842, 0, 0, 1, 1, 1, 1, 'Corlain Girdle'),
(@REFERENCEID+1, 0, 154845, 0, 0, 1, 1, 1, 1, 'Corlaine Spaulders'),
(@REFERENCEID+1, 0, 154853, 0, 0, 1, 1, 1, 1, 'Crimsonwood Cowl'),
(@REFERENCEID+1, 0, 159605, 0, 0, 1, 1, 1, 1, 'Ironcrest Baton'),
(@REFERENCEID+1, 0, 159522, 0, 0, 1, 1, 1, 1, 'Stagheart Knife'),
(@REFERENCEID+1, 0, 159593, 0, 0, 1, 1, 1, 1, 'Wavecaller Cutlass'),
(@REFERENCEID+1, 0, 154864, 0, 0, 1, 1, 1, 1, 'Barrowknoll Pauldrons'),
(@REFERENCEID+1, 0, 159564, 0, 0, 1, 1, 1, 1, 'Stagheart Staff');

-- Difficulty (Lowlands Doe - Lowlands Greatstag)
UPDATE `creature_template_difficulty` SET `LootID` = 128385 WHERE `Entry` IN (128385,128384);

DELETE FROM `creature_loot_template` WHERE `Entry` = 128385;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(128385, 0, 154897, 25, 0, 1, 0, 1, 4, 'Stringy Loins'),
(128385, 1, 700000, 3, 0, 1, 0, 1, 1, 'Reference World drop greens loot'),
(128385, 1, (@REFERENCEID+2), 100, 0, 1, 0, 1, 1, 'Reference World drop junks loot');

DELETE FROM `reference_loot_template` WHERE `Entry` = @REFERENCEID+2;
INSERT INTO `reference_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFERENCEID+2, 0, 158751, 0, 0, 1, 1, 1, 1, 'Matted Pelt'),
(@REFERENCEID+2, 0, 158808, 0, 0, 1, 1, 1, 1, 'Thick Tendon'),
(@REFERENCEID+2, 0, 158832, 0, 0, 1, 1, 1, 1, 'Bushy Tail');
