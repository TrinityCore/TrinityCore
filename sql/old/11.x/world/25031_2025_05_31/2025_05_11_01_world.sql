SET @REFERENCEID := 700015;

-- Difficulty (Vengeful Bones)
UPDATE `creature_template_difficulty` SET `LootID`=128703 WHERE `Entry`=128703;

DELETE FROM `creature_loot_template` WHERE `Entry` = 128703;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(128703, 1, @REFERENCEID+0, 100, 0, 1, 1, 1, 1, 'Reference Junk loot'),
(128703, 1, 700000, 2, 0, 1, 1, 1, 1, 'Reference Uncommon loot');

-- Junk Items: Using best match Entry @REFERENCEID+0
DELETE FROM `reference_loot_template` WHERE `Entry` = @REFERENCEID+0;
INSERT INTO `reference_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFERENCEID+0, 0, 155608, 71, 0, 1, 1, 1, 1, 'Defiled Bone'), -- Chance = 71.159882%
(@REFERENCEID+0, 0, 158790, 5, 0, 1, 1, 1, 1, 'Charnel Ash'), -- Chance = 4.569387%
(@REFERENCEID+0, 0, 158862, 24, 0, 1, 1, 1, 1, 'Ancient Grave Dust'); -- Chance = 24.248181%

-- Difficulty (Awoken Guardian)
UPDATE `creature_template_difficulty` SET `LootID`=126355 WHERE `Entry`=126355;

DELETE FROM `creature_loot_template` WHERE `Entry` = 126355;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(126355, 1, @REFERENCEID+1, 100, 0, 1, 1, 1, 1, 'Reference Junk loot'),
(126355, 0, 152394, 31, 1, 1, 0, 1, 1, 'Runic Power Core'), -- Chance = 30.549203%
(126355, 1, 700000, 2, 0, 1, 1, 1, 1, 'Reference Uncommon loot');

-- Junk Items: Using best match Entry @REFERENCEID+1
DELETE FROM `reference_loot_template` WHERE `Entry` = @REFERENCEID+1;
INSERT INTO `reference_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFERENCEID+1, 0, 155631, 72, 0, 1, 1, 1, 1, 'Inert Stone'), -- Chance = 71.542273%
(@REFERENCEID+1, 0, 158790, 4, 0, 1, 1, 1, 1, 'Charnel Ash'), -- Chance = 3.833045%
(@REFERENCEID+1, 0, 158862, 24, 0, 1, 1, 1, 1, 'Ancient Grave Dust'); -- Chance = 23.832500%

-- Difficulty (Ancient Sentinel)
UPDATE `creature_template_difficulty` SET `LootID`=126542 WHERE `Entry`=126542;

DELETE FROM `creature_loot_template` WHERE `Entry` = 126542;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(126542, 1, @REFERENCEID+1, 100, 0, 1, 1, 1, 1, 'Reference Junk loot'),
(126542, 0, 152394, 81, 1, 1, 0, 1, 1, 'Runic Power Core'), -- Chance = 81.067496%
(126542, 1, 700000, 3, 0, 1, 1, 1, 1, 'Reference Uncommon loot');
