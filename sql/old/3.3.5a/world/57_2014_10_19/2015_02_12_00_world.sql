--
DELETE FROM `creature_loot_template` WHERE `Entry` =39049 AND `Item`=52270;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(39049, 52270, 0, 75, 1, 1, 0, 1, 1, NULL); --  Plagued Bruin Hide

DELETE FROM `creature_loot_template` WHERE `Entry` IN (1536, 1537, 1662) AND `Item`=52077;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(1536, 52077, 0, 75, 1, 1, 0, 1, 1, NULL), -- Scarlet Missionary, High
(1537, 52077, 0, 75, 1, 1, 0, 1, 1, NULL), -- Scarlet Zealot, High
(1662, 52077, 0, 100, 1, 1, 0, 1, 1, NULL); -- Captain Perrine, Guaranteed

-- Update Duskbat Pelt drop chance for existing entry
UPDATE `creature_loot_template` SET `Chance`=100 WHERE `Entry` =1553 AND `Item`=2876;
-- Insert missing Embalming Ichor drops
DELETE FROM `creature_loot_template` WHERE `Entry`=1554 AND `Item`=2876;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(1554, 2876, 0, 100, 1, 1, 2, 1, 1, NULL);

-- Update Embalming Ichor drop chances for existing entries
UPDATE `creature_loot_template` SET `Chance`=75 WHERE `Entry` IN (1674, 1941) AND `Item`=2834;
-- Insert missing Embalming Ichor drop
DELETE FROM `creature_loot_template` WHERE `Entry`=1675 AND `Item`=2834;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(1675, 2834, 0, 75, 1, 1, 0, 1, 1, NULL);

UPDATE `creature_template` SET `lootid`=39049 WHERE  `entry`=39049;
DELETE FROM `creature_loot_template` WHERE `Entry`=39049 AND `Item`=52270;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(39049, 52270, 0, 75, 1, 1, 0, 1, 1, NULL);
