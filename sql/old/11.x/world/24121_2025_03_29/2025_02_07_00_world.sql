-- Update Difficulty
UPDATE `creature_template_difficulty` SET `LootID` = 54130 WHERE `entry` = 54130;

-- Add loot
DELETE FROM `creature_loot_template` WHERE `Entry` = 54130;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(54130, 0, 72071, 85, 1, 1, 0, 1, 1, 'Stolen Training Supplies');
