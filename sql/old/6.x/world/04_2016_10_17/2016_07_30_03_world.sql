-- Add items to gameobject_loot_template
DELETE FROM `gameobject_loot_template` WHERE `Entry`=28371;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(28371, 52281, 0, 100, 0, 1, 0, 1, 1, 'Gameobject Meatface''s Chest contains Loot item Meatface''s Locked Chest');
-- Add items to gameobject_loot_template
DELETE FROM `gameobject_loot_template` WHERE `Entry`=29638;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(29638, 56167, 0, 100, 0, 1, 0, 1, 1, 'Gameobject Wiggleweed contains Loot item Wiggleweed Sprout');
-- Add items to gameobject_loot_template
DELETE FROM `gameobject_loot_template` WHERE `Entry`=27284;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(27284, 46819, 0, 100, 0, 1, 0, 1, 1, 'Gameobject Black Mandrake contains Loot item Black Mandrake');
-- Add items to gameobject_loot_template
DELETE FROM `gameobject_loot_template` WHERE `Entry`=27845;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(27845, 50448, 0, 100, 0, 1, 0, 1, 1, 'Gameobject Kaldorei Artifact contains Loot item Kaldorei Artifact');
-- Add items to gameobject_loot_template
DELETE FROM `gameobject_loot_template` WHERE `Entry`=31795;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(31795, 3084, 0, 100, 0, 1, 0, 1, 1, 'Gameobject Gyromechanic Gear contains Loot item Gyromechanic Gear');
-- Add items to gameobject_loot_template
DELETE FROM `gameobject_loot_template` WHERE `Entry`=2882;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(2882, 5397, 0, 100, 0, 1, 0, 1, 1, 'Gameobject Defias Gunpowder contains Loot item Defias Gunpowder');
-- Add items to gameobject_loot_template
DELETE FROM `gameobject_loot_template` WHERE `Entry`=23323;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(23323, 35480, 0, 100, 1, 1, 0, 1, 1, 'Gameobject Harvest Collector Maintenance Guide contains Loot item Harvest Collector Maintenance Guide');
-- Add items to gameobject_loot_template

DELETE FROM `gameobject_loot_template` WHERE `Entry`=41213;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(41213, 73269, 0, 40, 0, 1, 0, 1, 1, 'Gameobject Shipwreck Debris contains Loot item Great Sea Herring'),
(41213, 46109, 0, 0.01, 0, 1, 1, 1, 1, 'Gameobject Shipwreck Debris contains Loot item Sea Turtle'),
(41213, 73953, 0, 0.01, 0, 1, 1, 1, 1, 'Gameobject Shipwreck Debris contains Loot item Sea Pony'),
(41213, 78930, 0, 98.98, 0, 1, 1, 1, 1, 'Gameobject Shipwreck Debris contains Loot item Sealed Crate');
