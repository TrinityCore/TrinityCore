ALTER TABLE `reference_loot_template` DROP PRIMARY KEY, ADD PRIMARY KEY (`Entry`, `Item`, `Reference`); 
DELETE FROM `reference_loot_template` WHERE Entry = 104;
INSERT INTO `reference_loot_template` VALUES
(104, 0, 109, 100, 0, 1, 0, 0, 1, ""),
(104, 0, 110, 100, 0, 1, 0, 0, 1, "");
