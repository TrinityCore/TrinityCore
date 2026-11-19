-- Blackrock Worg Drops with correct rates from wiki
UPDATE `creature_template` SET lootid=49871 WHERE entry=49871;
DELETE FROM `creature_loot_template` WHERE entry=49871;
INSERT INTO `creature_loot_template` (entry,item,Reference,Chance,QuestRequired,LootMode,GroupId,MinCount,MaxCount,Comment) VALUES
(49871, 62328, 0, 76, 0, 1, 0, 1, 1, 'Shed Fur'),
(49871, 3300, 0, 24, 0, 1, 0, 1, 1, 'Rabbit Foot'),
(49871, 5572, 0, 0.5, 0, 1, 0, 1, 1, 'Small Green Pouch'),
(49871, 5571, 0, 0.12, 0, 1, 0, 1, 1, 'Small Black Pouch'),
(49871, 828, 0, 0.09, 0, 1, 0, 1, 1, 'Small Blue Pouch'),
(49871, 805, 0, 0.1, 0, 1, 0, 1, 1, 'Small Red Pouch'),
(49871, 4496, 0, 0.12, 0, 1, 0, 1, 1, 'Small Brown Pouch'),
(49871, 2589, 0, 0.02, 0, 1, 0, 1, 1, 'Linen Cloth'),
(49871, 117, 0, 0.01, 0, 1, 0, 1, 1, 'Tough Jerky');
