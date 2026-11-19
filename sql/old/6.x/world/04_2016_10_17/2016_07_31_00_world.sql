-- Add items to gameobject_loot_template
DELETE FROM `gameobject_loot_template` WHERE `Entry` IN (31796,35947,4364,2501,19324,23322,23917,23918,24094,25344,24743,26006,27257,27259,28401,31472,34717);
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(31796, 3083, 0, 100, 1, 1, 0, 1, 1, 'Gameobject Restabilization Cog contains Loot Restabilization Cog'),
(35947, 64307, 0, 100, 1, 1, 0, 1, 1, 'Gameobject Alliance Battle Plans contains Loot item Alliance Battle Plans'),
(4364, 6992, 0, 100, 1, 1, 0, 1, 1, 'Gameobject Jordan''s Shipment contains Loot item Jordan''s Ore Shipment'),
(2501, 5057, 0, 100, 0, 1, 0, 1, 1, 'Gameobject Ripe Watermelon contains Loot Ripe Watermelon'),
(19324, 25468, 0, 100, 0, 1, 0, 1, 1, 'Gameobject Boulderfist Plans contains Loot Boulderfist Plans'),
(23322, 35482, 0, 100, 0, 1, 0, 1, 1, 'Gameobject Agricultural Engineering for Dummies contains Loot Agricultural Engineering for Dummies'),
(23917, 37089, 0, 100, 1, 1, 0, 1, 1, 'Gameobject Honeycone contains Loot Honeycone'),
(23918, 37090, 0, 100, 1, 1, 0, 1, 1, 'Gameobject Quickpoppy contains Loot Quickpoppy'),
(24094, 36902, 0, 100, 0, 1, 0, 1, 1, 'Gameobject Constrictor Grass contains Loot Constrictor Grass'),
(25344, 40843, 0, 100, 1, 1, 0, 1, 1, 'Gameobject Iceberries contains Loot Iceberries'),
(24743, 38687, 0, 100, 1, 1, 0, 1, 1, 'Gameobject Gooey Ghoul Drool contains Loot Gooey Ghoul Drool'),
(26006, 71141, 0, 100, 0, 1, 0, 1, 1, 'Gameobject Eternal Embers contains Loot Eternal Embers'),
(27257, 46694, 0, 100, 1, 1, 0, 1, 1, 'Gameobject Dellylah''s Stolen Beans contains Loot Dellylah''s Stolen Beans'),
(27259, 46699, 0, 100, 1, 1, 0, 1, 1, 'Gameobject Dellylah''s Stolen Water contains Loot Dellylah''s Stolen Water'),
(28401, 52498, 0, 100, 1, 1, 0, 1, 1, 'Gameobject Oxygenated Seaweed contains Loot Oxygenated Seaweed'),
(31472, 60575, 0, 100, 1, 1, 0, 1, 1, 'Gameobject The Middle Fragment of the World Pillar contains Loot The Middle Fragment of the World Pillar'),
(34717, 61356, 0, 100, 1, 1, 0, 1, 1, 'Gameobject Stolen Silversnap Ice contains Loot Stolen Silversnap Ice');
 
-- Add items to gameobject_loot_template
DELETE FROM `gameobject_loot_template` WHERE `Entry`=39449;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(39449, 22739, 0, 0.01, 0, 1, 1, 1, 1, 'Gameobject Deepsea Sagefish School contains Loot item Tome of Polymorph: Turtle'),
(39449, 46109, 0, 0.01, 0, 1, 1, 1, 1, 'Gameobject Deepsea Sagefish School contains Loot item Sea Turtle'),
(39449, 52326, 0, 9.98, 0, 1, 1, 1, 1, 'Gameobject Deepsea Sagefish School contains Loot item Volatile Water'),
(39449, 53072, 0, 90, 0, 1, 1, 1, 1, 'Gameobject Deepsea Sagefish School contains Loot item Deepsea Sagefish');
 
-- Add items to gameobject_loot_template
DELETE FROM `gameobject_loot_template` WHERE `Entry`=28559;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(28559, 22739, 0, 0.01, 0, 1, 1, 1, 1, 'Gameobject Albino Cavefish School contains Loot item Tome of Polymorph: Turtle'),
(28559, 46109, 0, 0.01, 0, 1, 1, 1, 1, 'Gameobject Albino Cavefish School contains Loot item Sea Turtle'),
(28559, 52326, 0, 9.98, 0, 1, 1, 1, 1, 'Gameobject Albino Cavefish School contains Loot item Volatile Water'),
(28559, 53065, 0, 90, 0, 1, 1, 1, 1, 'Gameobject Albino Cavefish School contains Loot item Albino Cavefish');
 
-- Add items to gameobject_loot_template
DELETE FROM `gameobject_loot_template` WHERE `Entry`=28556;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(28556, 22739, 0, 0.01, 0, 1, 1, 1, 1, 'Gameobject Highland Guppy School contains Loot item Tome of Polymorph: Turtle'),
(28556, 46109, 0, 0.01, 0, 1, 1, 1, 1, 'Gameobject Highland Guppy School contains Loot item Sea Turtle'),
(28556, 52326, 0, 9.98, 0, 1, 1, 1, 1, 'Gameobject Highland Guppy School contains Loot item Volatile Water'),
(28556, 53064, 0, 90, 0, 1, 1, 1, 1, 'Gameobject Highland Guppy School contains Loot item Highland Guppy');
