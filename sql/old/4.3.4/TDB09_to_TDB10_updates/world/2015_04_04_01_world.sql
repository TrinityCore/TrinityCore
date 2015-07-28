-- Northshire Goblin Assassin Loot

UPDATE `creature_template` SET `lootid`=50039 WHERE `entry`=50039;
DELETE FROM `creature_loot_template` WHERE `entry`=50039;
INSERT INTO `creature_loot_template` (`entry`,`item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(50039, 62328, 0, 0.01, 0, 1, 0, 1, 1, 'Shed Fur'),
(50039, 5572, 0, 0.9, 0, 1, 0, 1, 1, 'Small Green Pouch'),
(50039, 5571, 0, 0.9, 0, 1, 0, 1, 1, 'Small Black Pouch'),
(50039, 828, 0, 0.8, 0, 1, 0, 1, 1, 'Small Blue Pouch'),
(50039, 805, 0, 0.8, 0, 1, 0, 1, 1, 'Small Red Pouch'),
(50039, 4496, 0, 1, 0, 1, 0, 1, 1, 'Small Brown Pouch'),
(50039, 2589, 0, 0.3, 0, 1, 0, 1, 1, 'Linen Cloth'),
(50039, 117, 0, 10, 0, 1, 0, 1, 1, 'Tough Jerky'),
(50039, 159, 0, 4, 0, 1, 0, 1, 1, 'Refreshing Spring Water');
