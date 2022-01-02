--
DELETE FROM `gameobject_loot_template` WHERE `Entry` = 2579 AND `Item` != 1179;
DELETE FROM `gameobject_loot_template` WHERE `Entry` = 2601 AND `Item` != 1205;
UPDATE `item_loot_template` SET `Chance` = 100 WHERE `Entry` = 5335;
UPDATE `item_loot_template` SET `Chance` = 100 WHERE `Entry` = 5738;
UPDATE `item_loot_template` SET `Chance` = 100 WHERE `Entry` = 20228;
UPDATE `item_loot_template` SET `Chance` = 100 WHERE `Entry` = 11568 AND `Item` = 11570;
DELETE FROM `item_loot_template` WHERE `Entry` = 5758 AND `Item` IN (11914,11948);
DELETE FROM `item_loot_template` WHERE `Entry` = 6352 AND `Item` IN (6304,18683);
DELETE FROM `item_loot_template` WHERE `Entry` = 10569 AND `Item` IN (11569,11570);
DELETE FROM `item_loot_template` WHERE `Entry` = 11107 AND `Item` IN (11569,11570);
DELETE FROM `item_loot_template` WHERE `Entry` = 16882 AND `Item` = 16746;
DELETE FROM `item_loot_template` WHERE `Entry` = 16883 AND `Item` = 5737;
DELETE FROM `item_loot_template` WHERE `Entry` = 16884 AND `Item` IN (15868,15875);
-- Patch 1.4.0 (2005-05-05): Tormented Spirits will drop their Ghostly Bracers every time they die now.
UPDATE `creature_loot_template` SET `Chance` = 100 WHERE `Entry` = 1533 AND `Item` = 3323;
-- This item should be pickpocketed
DELETE FROM `creature_loot_template` WHERE `Item` = 29570;
-- These should drop always
UPDATE `creature_loot_template` SET `Chance` = 100 WHERE `Item` IN (24559,29443);
-- Runn Tum Tuber should drop only from Pusillin
DELETE FROM `creature_loot_template` WHERE `Item` = 18255 AND `Entry` != 14354;
-- Incorrect/weird and/or already drops from gameobjects or items
DELETE FROM `creature_loot_template` WHERE `Item` IN (4957,11914,11948,19221,19229,19245,19246,19247,19248,19249,19250,19251,19253,19252,19237,19256,19266,19254,19255,19423,19424,19443,19451,19452,19453,19454,19238,19239,19240,19241,19242,19243,19244,19774,17348,17349,17351,17352,19029,19031,19046,19083,19085,19087,19088,19089,19090,19095,19096,19099,19101,19103,19301,19307,19308,19309,19310,19311,19312,19315,19316,19317,19318,19319,19320,19321,19323,19324,19325,19483,20062,20066,21235,21308,21744,3766,3767,3769,4100,4101,4102,4957,7280,13545,15564,17202,17706,17709,17722,18240,18266,18297,18631,22123,22176,22202,22203,24479,32464,32470,4388,4405,4406,11953,18588,25,45,140,287,783,2318,2319,2928,2934,2996,2997,3384,3829,4232,4234,4304,4305,4339,4623,8364,8956,8957,9030,9036,9144,9154,9155,9179,9187,9197,9206,9224,9261,9262,9332,9333,9334,9335,9336,9355,9356,9357,9358,9361,11110,10592,13926,14048,15416,25707,5066);
