SET @REFERENCEID := 700004;

-- Difficulty (Darkmaw Prowler)
UPDATE `creature_template_difficulty` SET `LootID` = 125464 WHERE `Entry` = 125464;

-- Loot
DELETE FROM `creature_loot_template` WHERE `Entry` = 125464;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(125464, 1, 700000, 3, 0, 1, 0, 1, 1, 'Reference World drop greens loot'),
(125464, 1, (@REFERENCEID+0), 100, 0, 1, 0, 1, 1, 'Reference World drop junk loot');

-- Reference Loot table junk
DELETE FROM `reference_loot_template` WHERE `Entry` = @REFERENCEID+0;
INSERT INTO `reference_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFERENCEID+0, 0, 155629, 0, 0, 1, 1, 1, 1, 'Shaggy Mane'),
(@REFERENCEID+0, 0, 158808, 0, 0, 1, 1, 1, 1, 'Thick Tendon'),
(@REFERENCEID+0, 0, 158818, 0, 0, 1, 1, 1, 1, 'Canine Tongue'),
(@REFERENCEID+0, 0, 158751, 0, 0, 1, 1, 1, 1, 'Matted Pelt');

-- Difficulty (Watchful Raven)
UPDATE `creature_template_difficulty` SET `LootID` = 125411 WHERE `Entry` = 125411;

-- Loot
DELETE FROM `creature_loot_template` WHERE `Entry` = 125411;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(125411, 0, 154897, 27, 0, 1, 0, 1, 4, 'Stringy Loins'),
(125411, 1, 700000, 3, 0, 1, 0, 1, 1, 'Reference World drop greens loot'),
(125411, 1, (@REFERENCEID+1), 100, 0, 1, 0, 1, 1, 'Reference World drop junk loot');

-- Reference Loot table junk
DELETE FROM `reference_loot_template` WHERE `Entry` = @REFERENCEID+1;
INSERT INTO `reference_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFERENCEID+1, 0, 158822, 0, 0, 1, 1, 1, 1, 'Lustrous Black Feather'),
(@REFERENCEID+1, 0, 155593, 0, 0, 1, 1, 1, 1, 'Keeled Breastbone'),
(@REFERENCEID+1, 0, 158806, 0, 0, 1, 1, 1, 1, 'Hooked Talon');

-- Difficulty (Coastal Osprey)
UPDATE `creature_template_difficulty` SET `LootID` = 130359 WHERE `Entry` = 130359;

-- Loot
DELETE FROM `creature_loot_template` WHERE `Entry` = 130359;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(130359, 0, 154897, 31, 0, 1, 0, 1, 4, 'Stringy Loins'),
(130359, 1, (@REFERENCEID+2), 1, 0, 1, 0, 1, 1, 'Reference World drop greens loot'),
(130359, 1, (@REFERENCEID+3), 100, 0, 1, 0, 1, 1, 'Reference World drop junk loot');

-- Reference Loot table greens
DELETE FROM `reference_loot_template` WHERE `Entry` = @REFERENCEID+2;
INSERT INTO `reference_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFERENCEID+2, 0, 159283, 0, 0, 1, 1, 1, 1, 'Barrowknoll Cloak'),
(@REFERENCEID+2, 0, 159805, 0, 0, 1, 1, 1, 1, 'Coralshell Barrier'),
(@REFERENCEID+2, 0, 159280, 0, 0, 1, 1, 1, 1, 'Crimsonwood Drape'),
(@REFERENCEID+2, 0, 159587, 0, 0, 1, 1, 1, 1, 'Dockyard Cutlass'),
(@REFERENCEID+2, 0, 154840, 0, 0, 1, 1, 1, 1, 'Corlain Breastplate'),
(@REFERENCEID+2, 0, 154863, 0, 0, 1, 1, 1, 1, 'Barrowknoll Legguards'),
(@REFERENCEID+2, 0, 159818, 0, 0, 1, 1, 1, 1, 'Deepwarden Touch');

-- Reference Loot table junk
DELETE FROM `reference_loot_template` WHERE `Entry` = @REFERENCEID+3;
INSERT INTO `reference_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFERENCEID+3, 0, 158754, 0, 0, 1, 1, 1, 1, 'Trueflight Fletching'),
(@REFERENCEID+3, 0, 155593, 0, 0, 1, 1, 1, 1, 'Keeled Breastbone'),
(@REFERENCEID+3, 0, 158806, 0, 0, 1, 1, 1, 1, 'Hooked Talon');
