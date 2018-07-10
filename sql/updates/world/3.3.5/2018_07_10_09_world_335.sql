-- 
-- Undo giant clam meat
DELETE FROM `creature_loot_template` WHERE `item` = 4655;
DELETE FROM `spell_loot_template` WHERE `item` = 4655;
DELETE FROM `gameobject_loot_template` WHERE `item` = 4655;

-- Undo Blue Pearl
DELETE FROM `gameobject_loot_template` WHERE `item` = 4611;

-- Redo Giant Clam (Vile Reef, STV)
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`,`MinCount`,`MaxCount`) VALUES
(2264, 4655, 35, 1, 0, 1, 1),
(2264, 4611,100, 1, 0, 1, 1);

-- Undo Black Pearl
DELETE FROM `item_loot_template` WHERE `item` = 7971;
DELETE FROM `creature_loot_template` WHERE `item` = 7971;
DELETE FROM `gameobject_loot_template` WHERE `item` = 7971;

-- Black Pearls still drop from gem bags
INSERT INTO `item_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`,`MinCount`,`MaxCount`) VALUES
(12033, 7971, 30, 1, 0, 1, 1),
(11938, 7971,  5, 1, 0, 1, 1),
(17962, 7971, 30, 1, 0, 1, 1),
(17963, 7971, 30, 1, 0, 1, 1),
(17964, 7971, 30, 1, 0, 1, 1),
(17965, 7971, 30, 1, 0, 1, 1),
(17969, 7971, 30, 1, 0, 1, 1);

-- Undo Golden Pearl
DELETE FROM `creature_loot_template` WHERE `item` = 13926;
DELETE FROM `spell_loot_template` WHERE `item` = 13926;

-- Undo Zesty Clam Meat
DELETE FROM `creature_loot_template` WHERE `item` = 7974;
DELETE FROM `skinning_loot_template` WHERE `item` = 7974;
DELETE FROM `item_loot_template` WHERE `item` = 7974;

-- Redo Big-Mouth Clam
DELETE FROM `spell_loot_template` WHERE `entry` = 58165;
INSERT INTO `spell_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`,`MinCount`,`MaxCount`) VALUES
(58165,  7974,  100, 1, 0, 1, 1),
(58165,  7971,  1.0, 1, 1, 1, 1),
(58165, 13926,  1.7, 1, 1, 1, 1),
(58165,  5500,  2.3, 1, 1, 1, 1),
(58165,  5498,  1.0, 1, 1, 1, 1);
