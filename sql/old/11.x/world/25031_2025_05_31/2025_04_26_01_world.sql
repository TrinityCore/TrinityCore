SET @REFERENCEID := 700003;

-- Difficulty
UPDATE `creature_template_difficulty` SET `LootID` = 125452 WHERE `Entry` = 125452;

-- Loot
DELETE FROM `creature_loot_template` WHERE `Entry` = 125452;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(125452, 0, 151935, 32, 1, 1, 0, 1, 1, 'Intact Venom Gland'),
(125452, 0, 154899, 27, 0, 1, 0, 1, 4, 'Thick Paleo Steak'),
(125452, 1, 700000, 6, 0, 1, 0, 1, 1, 'Reference World drop greens loot'),
(125452, 1, (@REFERENCEID+0), 100, 0, 1, 0, 1, 1, 'Reference World drop junk loot');

-- Reference Loot table junk
DELETE FROM `reference_loot_template` WHERE `Entry` = @REFERENCEID+0;
INSERT INTO `reference_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFERENCEID+0, 0, 155609, 0, 0, 1, 1, 1, 1, 'Springy Eyeball'),
(@REFERENCEID+0, 0, 158859, 0, 0, 1, 1, 1, 1, 'Jagged Fang'),
(@REFERENCEID+0, 0, 158849, 0, 0, 1, 1, 1, 1, 'Sawtooth Jawbone'),
(@REFERENCEID+0, 0, 155618, 0, 0, 1, 1, 1, 1, 'Discarded Molting');
