DROP TABLE IF EXISTS `item_scrapping_loot`;
CREATE TABLE `item_scrapping_loot` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `class` int(10) unsigned NOT NULL,
  `subclass` int(10) unsigned NOT NULL,
  `inventoryType` int(10) NOT NULL,
  `minLevel` int(10) unsigned NOT NULL,
  `maxLevel` int(10) unsigned NOT NULL,
  `quality` int(10) NOT NULL,
  `isCrafted` int(10) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

DROP TABLE IF EXISTS `scrapping_loot_template`;
CREATE TABLE `scrapping_loot_template` (
  `Entry` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `Item` mediumint(8) NOT NULL DEFAULT '0',
  `Reference` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `Chance` float NOT NULL DEFAULT '100',
  `QuestRequired` tinyint(1) NOT NULL DEFAULT '0',
  `LootMode` smallint(5) unsigned NOT NULL DEFAULT '1',
  `GroupId` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinCount` int(10) unsigned NOT NULL DEFAULT '1',
  `MaxCount` int(10) unsigned NOT NULL DEFAULT '1',
  `Comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`Entry`,`Item`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Loot System';
/* Quest items */
-- id 1 Quest
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (12, 		1, 			-1 , 			 0, 		 350, 		 -1, 		-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (1, 		160266, 0, 			 100,	   0, 				1, 			0, 		   1, 		   1);
/* Bow & Crossbows */
-- id 2 Bow & Crossbows uncommon
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (2, 		262148, 	-1 , 			 0, 		 280, 		 2,			-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (2, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (2, 		154165, 0, 			 100,	   0, 				1, 			0, 		   1, 		   8),
									  (2, 		11291,  0, 			 100,	   0, 				1, 			0, 		   1, 		   3);
-- id 3 Bow & Crossbows rare
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (2, 		262148, 	-1 , 			 0, 		 280, 		 3, 		-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (3, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (3, 		154165, 0, 			 100,	   0, 				1, 			0, 		   2, 		   8),
									  (3, 		11291,  0, 			 100,	   0, 				1, 			0, 		   1, 		   4);
-- id 4 Bow & Crossbows epic
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (2, 		262148, 	-1 , 			 0, 		 280, 		 4, 		-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (4, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (4, 		154165, 0, 			 100,	   0, 				1, 			0, 		   4, 		   8),
									  (4, 		11291,  0, 			 100,	   0, 				1, 			0, 		   3, 		   6);
/* Cloth Armor */
-- id 5 cloth armor uncommon
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		2,			-1 , 			 0, 		 350, 		 2, 		-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (5, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (5, 		152576, 0, 			 100,	   0, 				1, 			0, 		   1, 		   3),
									  (5, 		159959, 0, 			 100,	   0, 				1, 			0, 		   1, 		   5);
-- id 6 cloth armor azerith rare
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`) VALUES
								  (4, 		2,			42 , 			 0, 		 350, 		 3);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (6, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (6, 		152576, 0, 			 100,	   0, 				1, 			0, 		   1, 		   3),
									  (6, 		152577, 0, 			 20, 	   0, 				1, 			0, 		   5, 		   8),
									  (6, 		158378, 0, 			 5, 	   0, 				1, 			0, 		   2, 		   6),
									  (6, 		159959, 0, 			 100,	   0, 				1, 			0, 		   1, 		   8);
-- id 7 cloth armor non azerith rare
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`) VALUES
								  (4, 		2,			536870869 ,		 0, 		 350, 		 3);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (7, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (7, 		152576, 0, 			 100,	   0, 				1, 			0, 		   1, 		   3),
									  (7, 		152577, 0, 			 5, 	   0, 				1, 			0, 		   4, 		   6),
									  (7, 		158378, 0, 			 5, 	   0, 				1, 			0, 		   2, 		   4),
									  (7, 		159959, 0, 			 100,	   0, 				1, 			0, 		   1, 		   8);
-- id 8 cloth armor azerith epic
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`) VALUES
								  (4, 		2,			42 , 			 0, 		 350, 		 4);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (8, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (8, 		152577, 0, 			 100, 	   0, 				1, 			0, 		   8, 		   21),
									  (8, 		158378, 0, 			 100, 	   0, 				1, 			0, 		   3, 		   8),
									  (8, 		159959, 0, 			 100,	   0, 				1, 			0, 		   5, 		   10);
-- id 9 cloth armor non azerith epic
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`) VALUES
								  (4, 		2,			536870869 ,		 0, 		 350, 		 4);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (9, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (9, 		152577, 0, 			 100, 	   0, 				1, 			0, 		   4, 		   10),
									  (9, 		158378, 0, 			 100, 	   0, 				1, 			0, 		   2, 		   6),
									  (9, 		159959, 0, 			 100,	   0, 				1, 			0, 		   3, 		   9);
-- id 10 cloth armor crafted 355
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		2,			-1 ,			 355, 		 355, 		 -1,		1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (10, 		162460, 0, 			 100,	   0, 				1, 			0, 		   15, 		   15);
-- id 11 cloth armor crafted 370
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		2,			-1 ,			 370, 		 370, 		 -1,		1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (11, 		162461, 0, 			 100,	   0, 				1, 			0, 		   25, 		   25);
-- id 12 cloth armor crafted 385
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		2,			-1 ,			 385, 		 385, 		 -1,		1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (12, 		162461, 0, 			 100,	   0, 				1, 			0, 		   250, 		   250);
/* Leather Armor */
-- id 13 leather armor uncommon
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		4,			-1 , 			 0, 		 350, 		 2, 		-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (13, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (13, 		152541, 0, 			 100,	   0, 				1, 			0, 		   1, 		   3),
									  (13, 		154164, 0, 			 100,	   0, 				1, 			0, 		   1, 		   2);
-- id 14 leather armor azerith rare
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`) VALUES
								  (4, 		4,			42 , 			 0, 		 350, 		 3);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (14, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (14, 		152541, 0, 			 100,	   0, 				1, 			0, 		   2, 		   5),
									  (14, 		152542, 0, 			 5, 	   0, 				1, 			0, 		   2, 		   5),
									  (14, 		154164, 0, 			 100,	   0, 				1, 			0, 		   1, 		   3),
									  (14, 		154165, 0, 			 20, 	   0, 				1, 			0, 		   3, 		   9);
-- id 15 leather armor non azerith rare
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`) VALUES
								  (4, 		4,			536870869 ,		 0, 		 350, 		 3);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (15, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (15, 		152541, 0, 			 100,	   0, 				1, 			0, 		   2, 		   5),
									  (15, 		152542, 0, 			 5, 	   0, 				1, 			0, 		   1, 		   4),
									  (15, 		154164, 0, 			 100,	   0, 				1, 			0, 		   1, 		   3),
									  (15, 		154165, 0, 			 5, 	   0, 				1, 			0, 		   2, 		   7);
-- id 16 leather armor azerith epic
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`) VALUES
								  (4, 		4,			42 , 			 0, 		 350, 		 4);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (16, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (16, 		152542, 0, 			 100, 	   0, 				1, 			0, 		   4, 		   9),
									  (16, 		154165, 0, 			 100, 	   0, 				1, 			0, 		   7, 		   12),
									  (16, 		154722, 0, 			 100, 	   0, 				1, 			0, 		   3, 		   21);
-- id 17 leather armor non azerith epic
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`) VALUES
								  (4, 		4,			536870869 ,		 0, 		 350, 		 4);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (17, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (17, 		152542, 0, 			 100, 	   0, 				1, 			0, 		   1, 		   4),
									  (17, 		154165, 0, 			 100, 	   0, 				1, 			0, 		   5, 		   8),
									  (17, 		154722, 0, 			 100, 	   0, 				1, 			0, 		   5, 		   12);
-- id 18 leather armor crafted 355
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		4,			-1 ,			 355, 		 355, 		 -1,		1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (18, 		162460, 0, 			 100,	   0, 				1, 			0, 		   15, 		   15);
-- id 19 leather armor crafted 370
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		4,			-1 ,			 370, 		 370, 		 -1,		1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (19, 		162461, 0, 			 100,	   0, 				1, 			0, 		   25, 		   25);
-- id 20 leather armor crafted 385
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		4,			-1 ,			 385, 		 385, 		 -1,		1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (20, 		162461, 0, 			 100,	   0, 				1, 			0, 		   250, 		   250);
/* Mail Armor */
-- id 21 mail armor uncommon
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		8,			-1 , 			 0, 		 350, 		 2, 		-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (21, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (21, 		153050, 0, 			 100,	   0, 				1, 			0, 		   1, 		   3),
									  (21, 		154164, 0, 			 100,	   0, 				1, 			0, 		   1, 		   2);
-- id 22 mail armor azerith rare
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`) VALUES
								  (4, 		8,			42 , 			 0, 		 350, 		 3);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (22, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (22, 		153051, 0, 			 10,	   0, 				1, 			0, 		   8, 		   17),
									  (22, 		154165, 0, 			 10, 	   0, 				1, 			0, 		   5, 		   8),
									  (22, 		153050, 0, 			 100,	   0, 				1, 			0, 		   2, 		   5),
									  (22, 		154164, 0, 			 100,	   0, 				1, 			0, 		   2, 		   3);
-- id 23 mail armor non azerith rare
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`) VALUES
								  (4, 		8,			536870869 ,		 0, 		 350, 		 3);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (23, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (23, 		153051, 0, 			 10,	   0, 				1, 			0, 		   4, 		   9),
									  (23, 		154165, 0, 			 10, 	   0, 				1, 			0, 		   2, 		   8),
									  (23, 		153050, 0, 			 100,	   0, 				1, 			0, 		   2, 		   5),
									  (23, 		154164, 0, 			 100,	   0, 				1, 			0, 		   2, 		   3);
-- id 24 mail armor azerith epic
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`) VALUES
								  (4, 		8,			42 , 			 0, 		 350, 		 4);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (24, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (24, 		152542, 0, 			 100,	   0, 				1, 			0, 		   4, 		   8),
									  (24, 		154165, 0, 			 100, 	   0, 				1, 			0, 		   6, 		   16),
									  (24, 		153051, 0, 			 100,	   0, 				1, 			0, 		   8, 		   18),
									  (24, 		160059, 0, 			 100,	   0, 				1, 			0, 		   6, 		   10);
-- id 25 mail armor non azerith epic
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`) VALUES
								  (4, 		8,			536870869 ,		 0, 		 350, 		 4);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (25, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (25, 		152542, 0, 			 100,	   0, 				1, 			0, 		   1, 		   2),
									  (25, 		154165, 0, 			 100, 	   0, 				1, 			0, 		   6, 		   8),
									  (25, 		153051, 0, 			 100,	   0, 				1, 			0, 		   10, 		   14),
									  (25, 		160059, 0, 			 100,	   0, 				1, 			0, 		   3, 		   7);
-- id 26 mail armor crafted 355
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		8,			-1 ,			 355, 		 355, 		 -1,		1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (26, 		162460, 0, 			 100,	   0, 				1, 			0, 		   15, 		   15);
-- id 27 mail armor crafted 370
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		8,			-1 ,			 370, 		 370, 		 -1,		1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (27, 		162461, 0, 			 100,	   0, 				1, 			0, 		   25, 		   25);
-- id 28 mail armor crafted 385
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		8,			-1 ,			 385, 		 385, 		 -1,		1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (28, 		162461, 0, 			 100,	   0, 				1, 			0, 		   250, 		   250);
/* Plate Armor */
-- id 29 plate armor uncommon
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		16,			-1 , 			 0, 		 350, 		 2,			-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (29, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (29, 		152512, 0, 			 100,	   0, 				1, 			0, 		   1, 		   2),
									  (29, 		160298, 0, 			 100,	   0, 				1, 			0, 		   1, 		   1);
-- id 30 plate armor azerith rare
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`) VALUES
								  (4, 		16,			42 , 			 0, 		 350, 		 3);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (30, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (30, 		152513, 0, 			 10,	   0, 				1, 			0, 		   2, 		   7),
									  (30, 		152579, 0, 			 10, 	   0, 				1, 			0, 		   2, 		   9),
									  (30, 		152512, 0, 			 100,	   0, 				1, 			0, 		   1, 		   4),
									  (30, 		160298, 0, 			 100,	   0, 				1, 			0, 		   1, 		   1);
-- id 31 plate armor non azerith rare
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`) VALUES
								  (4, 		16,			536870869 ,		 0, 		 350, 		 3);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (31, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (31, 		152513, 0, 			 10,	   0, 				1, 			0, 		   1, 		   5),
									  (31, 		152579, 0, 			 10, 	   0, 				1, 			0, 		   2, 		   5),
									  (31, 		152512, 0, 			 100,	   0, 				1, 			0, 		   1, 		   3),
									  (31, 		160298, 0, 			 100,	   0, 				1, 			0, 		   1, 		   1);
-- id 32 plate armor azerith epic
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`) VALUES
								  (4, 		16,			42 , 			 0, 		 350, 		 4);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (32, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (32, 		152542, 0, 			 100,	   0, 				1, 			0, 		   4, 		   8),
									  (32, 		154165, 0, 			 100, 	   0, 				1, 			0, 		   6, 		   16),
									  (32, 		153051, 0, 			 100,	   0, 				1, 			0, 		   8, 		   18),
									  (32, 		160059, 0, 			 100,	   0, 				1, 			0, 		   6, 		   10);
-- id 33 plate armor non azerith epic
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`) VALUES
								  (4, 		16,			536870869 ,		 0, 		 350, 		 4);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (33, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (33, 		152542, 0, 			 100,	   0, 				1, 			0, 		   1, 		   2),
									  (33, 		154165, 0, 			 100, 	   0, 				1, 			0, 		   6, 		   8),
									  (33, 		153051, 0, 			 100,	   0, 				1, 			0, 		   10, 		   14),
									  (33, 		160059, 0, 			 100,	   0, 				1, 			0, 		   3, 		   7);
-- id 34 plate armor crafted 355
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		16,			-1 ,			 355, 		 355, 		 -1,		1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (34, 		162460, 0, 			 100,	   0, 				1, 			0, 		   15, 		   15);
-- id 35 plate armor crafted 370
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		16,			-1 ,			 370, 		 370, 		 -1,		1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (35, 		162461, 0, 			 100,	   0, 				1, 			0, 		   25, 		   25);
-- id 36 plate armor crafted 385
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		16,			-1 ,			 385, 		 385, 		 -1,		1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (36, 		162461, 0, 			 100,	   0, 				1, 			0, 		   250, 		   250);
/* Cloaks */
-- id 37 cloaks uncommon
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		1,			65536 , 		 0, 		 350, 		 2, 		-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (37, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (37, 		152576, 0, 			 100,	   0, 				1, 			0, 		   1, 		   3),
									  (37, 		159959, 0, 			 100,	   0, 				1, 			0, 		   1, 		   5);
-- id 38 cloaks rare
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		1,			65536 ,			 0, 		 350, 		 3, 		-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (38, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (38, 		152576, 0, 			 100,	   0, 				1, 			0, 		   1, 		   3),
									  (38, 		152577, 0, 			 5, 	   0, 				1, 			0, 		   4, 		   6),
									  (38, 		158378, 0, 			 5, 	   0, 				1, 			0, 		   2, 		   4),
									  (38, 		159959, 0, 			 100,	   0, 				1, 			0, 		   1, 		   8);
-- id 39 cloaks epic
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		1,			65536,			 0, 		 350, 		 4, 		-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (39, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (39, 		152577, 0, 			 100, 	   0, 				1, 			0, 		   4, 		   10),
									  (39, 		158378, 0, 			 100, 	   0, 				1, 			0, 		   2, 		   6),
									  (39, 		159959, 0, 			 100,	   0, 				1, 			0, 		   3, 		   9);
/* Rings */
-- id 40 ring uncommon
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		1,			2048 , 			 0, 		 350, 		 2, 		-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (40, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (40, 		153700, 0, 			 5, 	   0, 				1, 			0, 		   1, 		   2),
									  (40, 		153701, 0, 			 5, 	   0, 				1, 			0, 		   1, 		   2),
									  (40, 		153702, 0, 			 5, 	   0, 				1, 			0, 		   1, 		   2),
									  (40, 		153703, 0, 			 5, 	   0, 				1, 			0, 		   1, 		   2),
									  (40, 		153704, 0, 			 5, 	   0, 				1, 			0, 		   1, 		   2),
									  (40, 		153705, 0, 			 5, 	   0, 				1, 			0, 		   1, 		   2),
									  (40, 		152512, 0, 			 100,	   0, 				1, 			0, 		   1, 		   3);
-- id 41 ring rare
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		1,			2048,			 0, 		 350, 		 3, 		-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (41, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (41, 		154120, 0, 			 5, 	   0, 				1, 			0, 		   1, 		   2),
									  (41, 		154121, 0, 			 5, 	   0, 				1, 			0, 		   1, 		   2),
									  (41, 		154122, 0, 			 5, 	   0, 				1, 			0, 		   1, 		   2),
									  (41, 		154123, 0, 			 5, 	   0, 				1, 			0, 		   1, 		   2),
									  (41, 		154124, 0, 			 5, 	   0, 				1, 			0, 		   1, 		   2),
									  (41, 		154125, 0, 			 5, 	   0, 				1, 			0, 		   1, 		   2),
									  (41, 		152579, 0, 			 100,	   0, 				1, 			0, 		   1, 		   5);
-- id 42 ring epic
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		1,			2048,			 0, 		 350, 		 4, 		-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (42, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (42, 		154120, 0, 			 10, 	   0, 				1, 			0, 		   1, 		   2),
									  (42, 		154121, 0, 			 10, 	   0, 				1, 			0, 		   1, 		   2),
									  (42, 		154122, 0, 			 10, 	   0, 				1, 			0, 		   1, 		   2),
									  (42, 		154123, 0, 			 10, 	   0, 				1, 			0, 		   1, 		   2),
									  (42, 		154124, 0, 			 10, 	   0, 				1, 			0, 		   1, 		   2),
									  (42, 		154125, 0, 			 10, 	   0, 				1, 			0, 		   1, 		   2),
									  (42, 		152513, 0, 			 100,	   0, 				1, 			0, 		   1, 		   5);
-- id 43 plate armor crafted 355
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		1,			2048 ,			 355, 		 355, 		 -1,		1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (43, 		162460, 0, 			 100,	   0, 				1, 			0, 		   15, 		   15);
-- id 44 plate armor crafted 370
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		1,			2048 ,			 370, 		 370, 		 -1,		1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (44, 		162461, 0, 			 100,	   0, 				1, 			0, 		   25, 		   25);
-- id 45 plate armor crafted 385
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		1,			2048 ,			 385, 		 385, 		 -1,		1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (45, 		162461, 0, 			 100,	   0, 				1, 			0, 		   250, 		   250);
/* Trinkets */
-- id 46 trinket not crafted
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		1,			4096 , 			 0, 		 999, 		 -1, 		0);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (46, 		152668, 0, 			 100,	   0, 				1, 			0, 		   1, 		   1);
-- id 47 trinket crafted
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		1,			4096 ,			 0, 		 999, 		 -1,		1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (47, 		152510, 0, 			 100,	   0, 				1, 			0, 		   1, 		   3),
									  (47, 		152507, 0, 			 100,	   0, 				1, 			0, 		   1, 		   12),
									  (47, 		152505, 0, 			 100,	   0, 				1, 			0, 		   1, 		   12),
									  (47, 		152511, 0, 			 100,	   0, 				1, 			0, 		   1, 		   12),
									  (47, 		152509, 0, 			 100,	   0, 				1, 			0, 		   1, 		   8),
									  (47, 		152506, 0, 			 100,	   0, 				1, 			0, 		   1, 		   8),
									  (47, 		152508, 0, 			 100,	   0, 				1, 			0, 		   1, 		   12);
/* Off-hands */
-- id 48 Off-hands uncommon
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		1,			4194304 , 		 0, 		 350, 		 2, 		-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (48, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (48, 		158188, 0, 			 50, 	   0, 				1, 			0, 		   2, 		   8),
									  (48, 		158187, 0, 			 100, 	   0, 				1, 			0, 		   5, 		   10);
-- id 49 Off-hands rare
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		1,			4194304 , 		 0, 		 350, 		 3, 		-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (49, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (49, 		158188, 0, 			 50, 	   0, 				1, 			0, 		   5, 		   11),
									  (49, 		158187, 0, 			 100, 	   0, 				1, 			0, 		   5, 		   10);
-- id 50 Off-hands epic
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (4, 		1,			4194304 , 		 0, 		 350, 		 4, 		-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (50, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (50, 		158189, 0, 			 25, 	   0, 				1, 			0, 		   1, 		   4),
									  (50, 		158188, 0, 			 50, 	   0, 				1, 			0, 		   5, 		   13),
									  (50, 		158187, 0, 			 100, 	   0, 				1, 			0, 		   5, 		   10);
/* Wands */
-- id 51 wands uncommon
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (2, 		524288, 	-1 , 			 0, 		 350, 		 2,			-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (51, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (51, 		11291,  0, 			 50,	   0, 				1, 			0, 		   1, 		   1),
									  (51, 		152875, 0, 			 100,	   0, 				1, 			0, 		   1, 		   3);
-- id 52 wands rare
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (2, 		524288, 	-1 , 			 0, 		 350, 		 3, 		-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (52, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (52, 		11291,  0, 			 50,	   0, 				1, 			0, 		   1, 		   1),
									  (52, 		152875, 0, 			 100,	   0, 				1, 			0, 		   1, 		   3);
-- id 53 wands epic
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (2, 		524288, 	-1 , 			 0, 		 350, 		 4, 		-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (53, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (53, 		11291,  0, 			 50,	   0, 				1, 			0, 		   1, 		   1),
									  (53, 		152876, 0, 			 100,	   0, 				1, 			0, 		   1, 		   1);
/* Fist weapons */
-- id 54 fist weapons uncommon
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (2, 		8192,	 	-1 , 			 0, 		 350, 		 2, 		-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (54, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (54, 		153050, 0, 			 80,	   0, 				1, 			0, 		   1, 		   4),
									  (54, 		154164, 0, 			 80,	   0, 				1, 			0, 		   1, 		   2),
									  (54, 		152512, 0, 			 100,	   0, 				1, 			0, 		   1, 		   3);
-- id 55 fist weapons rare
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (2, 		8192, 		-1 , 			 0, 		 350, 		 3, 		-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (55, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (55, 		154165, 0, 			 80,	   0, 				1, 			0, 		   5, 		   10),
									  (55, 		153051, 0, 			 80,	   0, 				1, 			0, 		   5, 		   10),
									  (55, 		160059, 0, 			 100,	   0, 				1, 			0, 		   4, 		   10);
-- id 56 fist weapons epic
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (2, 		8192,	 	-1 , 			 0, 		 350, 		 4, 		-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (56, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (56, 		154165, 0, 			 80,	   0, 				1, 			0, 		   9, 		   12),
									  (56, 		153051, 0, 			 80,	   0, 				1, 			0, 		   7, 		   17),
									  (56, 		160059, 0, 			 100,	   0, 				1, 			0, 		   4, 		   15);
/* Staves */
-- id 57 staves uncommon
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (2, 		1024,	 	-1,	 			 0, 		 350, 		 2, 		-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (57, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (57, 		153700, 0, 			 5, 	   0, 				1, 			0, 		   1, 		   2),
									  (57, 		153701, 0, 			 5, 	   0, 				1, 			0, 		   1, 		   2),
									  (57, 		153702, 0, 			 5, 	   0, 				1, 			0, 		   1, 		   2),
									  (57, 		153703, 0, 			 5, 	   0, 				1, 			0, 		   1, 		   2),
									  (57, 		153704, 0, 			 5, 	   0, 				1, 			0, 		   1, 		   2),
									  (57, 		153705, 0, 			 5, 	   0, 				1, 			0, 		   1, 		   2),
									  (57, 		152512, 0, 			 100,	   0, 				1, 			0, 		   1, 		   3);
-- id 58 staves rare
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (2, 		1024,	 	-1 , 			 0, 		 350, 		 3, 		-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (58, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (58, 		154120, 0, 			 5, 	   0, 				1, 			0, 		   1, 		   2),
									  (58, 		154121, 0, 			 5, 	   0, 				1, 			0, 		   1, 		   2),
									  (58, 		154122, 0, 			 5, 	   0, 				1, 			0, 		   1, 		   2),
									  (58, 		154123, 0, 			 5, 	   0, 				1, 			0, 		   1, 		   2),
									  (58, 		154124, 0, 			 5, 	   0, 				1, 			0, 		   1, 		   2),
									  (58, 		154125, 0, 			 5, 	   0, 				1, 			0, 		   1, 		   2),
									  (58, 		152579, 0, 			 100,	   0, 				1, 			0, 		   1, 		   5);
-- id 59 staves epic
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (2, 		1024,	 	-1 , 			 0, 		 350, 		 4, 		-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (59, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (59, 		154120, 0, 			 10, 	   0, 				1, 			0, 		   1, 		   2),
									  (59, 		154121, 0, 			 10, 	   0, 				1, 			0, 		   1, 		   2),
									  (59, 		154122, 0, 			 10, 	   0, 				1, 			0, 		   1, 		   2),
									  (59, 		154123, 0, 			 10, 	   0, 				1, 			0, 		   1, 		   2),
									  (59, 		154124, 0, 			 10, 	   0, 				1, 			0, 		   1, 		   2),
									  (59, 		154125, 0, 			 10, 	   0, 				1, 			0, 		   1, 		   2),
									  (59, 		152579, 0, 			 100,	   0, 				1, 			0, 		   1, 		   5);
/* All other weapons */
-- id 60 all other weapons uncommon
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (2, 		1285115,	-1, 			 0, 		 350, 		 2,			-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (60, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (60, 		152512, 0, 			 100,	   0, 				1, 			0, 		   1, 		   2),
									  (60, 		160298, 0, 			 100,	   0, 				1, 			0, 		   1, 		   1);
-- id 61 all other weapons rare
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (2, 		1285115,	-1,				 0, 		 350, 		 3,			-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (61, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (61, 		152513, 0, 			 10,	   0, 				1, 			0, 		   1, 		   5),
									  (61, 		152579, 0, 			 10, 	   0, 				1, 			0, 		   2, 		   5),
									  (61, 		152512, 0, 			 100,	   0, 				1, 			0, 		   1, 		   3),
									  (61, 		160298, 0, 			 100,	   0, 				1, 			0, 		   1, 		   1);
-- id 62 all other weapons epic
INSERT INTO `item_scrapping_loot` (`class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
								  (2, 		1285115,	-1,				 0, 		 350, 		 4,			-1);
INSERT INTO `scrapping_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
									  (62, 		152668, 0, 			 16,	   0, 				1, 			0, 		   1, 		   1),
									  (62, 		152542, 0, 			 100,	   0, 				1, 			0, 		   1, 		   2),
									  (62, 		154165, 0, 			 100, 	   0, 				1, 			0, 		   6, 		   8),
									  (62, 		153051, 0, 			 100,	   0, 				1, 			0, 		   10, 		   14),
									  (62, 		160059, 0, 			 100,	   0, 				1, 			0, 		   3, 		   7);
