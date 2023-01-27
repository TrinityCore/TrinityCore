DELETE FROM `item_scrapping_loot` WHERE `id` = 63;
INSERT INTO `item_scrapping_loot` (`id`, `class`, `subclass`, `inventoryType`, `minLevel`, `maxLevel`, `quality`, `isCrafted`) VALUES
(63, 4, 64, -1, 0, 350, -1, -1);

DELETE FROM `scrapping_loot_template` WHERE entry = 63;
INSERT INTO `scrapping_loot_template` VALUES
(63, 	152512, 	0, 	100, 	0, 	1, 	0, 	1, 	3, 	""),
(63, 	152513, 	0, 	10, 	0, 	1, 	0, 	1, 	5, 	""),
(63, 	152579, 	0, 	10, 	0, 	1, 	0, 	2, 	5, 	""),
(63, 	152668, 	0, 	16, 	0, 	1, 	0, 	1, 	1, 	""),
(63, 	160298, 	0, 	100, 	0, 	1, 	0, 	1, 	1, 	"");

UPDATE `item_scrapping_loot` SET `inventoryType` = 12582912 WHERE `id` = 49; 
UPDATE `item_scrapping_loot` SET `inventoryType` = 12582912 WHERE `id` = 48; 
UPDATE `item_scrapping_loot` SET `inventoryType` = 12582912 WHERE `id` = 50; 
