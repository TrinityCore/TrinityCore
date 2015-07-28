-- Northshire Blackrock Spy Loot
UPDATE `creature_template` SET `lootid`=49874 WHERE `entry`=49874;
DELETE FROM `creature_loot_template` WHERE `entry`=49874;
INSERT INTO `creature_loot_template` (`entry`,`item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(49874, 62328, 0, 0.06, 0, 1, 0, 1, 1, 'Shed Fur'),
(49874, 5572, 0, 0.9, 0, 1, 0, 1, 1, 'Small Green Pouch'),
(49874, 5571, 0, 1.1, 0, 1, 0, 1, 1, 'Small Black Pouch'),
(49874, 828, 0, 1.4, 0, 1, 0, 1, 1, 'Small Blue Pouch'),
(49874, 805, 0, 1.2, 0, 1, 0, 1, 1, 'Small Red Pouch'),
(49874, 4496, 0, 1.1, 0, 1, 0, 1, 1, 'Small Brown Pouch'),
(49874, 2589, 0, 0.3, 0, 1, 0, 1, 1, 'Linen Cloth');
