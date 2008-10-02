--
-- Table changes for `creature_loot_template`
--
ALTER TABLE `creature_loot_template` CHANGE COLUMN `quest_freeforall` `QuestFFAorLootCondition` TINYINT(3) NOT NULL DEFAULT 1,
ADD COLUMN `condition_value1` int(11) UNSIGNED NOT NULL DEFAULT '0' AFTER `QuestFFAorLootCondition`,
ADD COLUMN `condition_value2` int(11) UNSIGNED NOT NULL DEFAULT '0' AFTER `condition_value1`;

ALTER TABLE `creature_loot_template` DROP PRIMARY KEY,
ADD PRIMARY KEY(`entry`, `item`, `condition_value1`);


--
-- Table changes for `disenchant_loot_template`
--
ALTER TABLE `disenchant_loot_template` CHANGE COLUMN `quest_freeforall` `QuestFFAorLootCondition` TINYINT(3) NOT NULL DEFAULT 1,
ADD COLUMN `condition_value1` int(11) UNSIGNED NOT NULL DEFAULT '0' AFTER `QuestFFAorLootCondition`,
ADD COLUMN `condition_value2` int(11) UNSIGNED NOT NULL DEFAULT '0' AFTER `condition_value1`;

ALTER TABLE `disenchant_loot_template` DROP PRIMARY KEY,
ADD PRIMARY KEY(`entry`, `item`, `condition_value1`);


--
-- Table changes for `fishing_loot_template`
--
ALTER TABLE `fishing_loot_template` CHANGE COLUMN `quest_freeforall` `QuestFFAorLootCondition` TINYINT(3) NOT NULL DEFAULT 1,
ADD COLUMN `condition_value1` int(11) UNSIGNED NOT NULL DEFAULT '0' AFTER `QuestFFAorLootCondition`,
ADD COLUMN `condition_value2` int(11) UNSIGNED NOT NULL DEFAULT '0' AFTER `condition_value1`;

ALTER TABLE `fishing_loot_template` DROP PRIMARY KEY,
ADD PRIMARY KEY(`entry`, `item`, `condition_value1`);


--
-- Table changes for `gameobject_loot_template`
--
ALTER TABLE `gameobject_loot_template` CHANGE COLUMN `quest_freeforall` `QuestFFAorLootCondition` TINYINT(3) NOT NULL DEFAULT 1,
ADD COLUMN `condition_value1` int(11) UNSIGNED NOT NULL DEFAULT '0' AFTER `QuestFFAorLootCondition`,
ADD COLUMN `condition_value2` int(11) UNSIGNED NOT NULL DEFAULT '0' AFTER `condition_value1`;

ALTER TABLE `gameobject_loot_template` DROP PRIMARY KEY,
ADD PRIMARY KEY(`entry`, `item`, `condition_value1`);


--
-- Table changes for `item_loot_template`
--
ALTER TABLE `item_loot_template` CHANGE COLUMN `quest_freeforall` `QuestFFAorLootCondition` TINYINT(3) NOT NULL DEFAULT 1,
ADD COLUMN `condition_value1` int(11) UNSIGNED NOT NULL DEFAULT '0' AFTER `QuestFFAorLootCondition`,
ADD COLUMN `condition_value2` int(11) UNSIGNED NOT NULL DEFAULT '0' AFTER `condition_value1`;

ALTER TABLE `item_loot_template` DROP PRIMARY KEY,
ADD PRIMARY KEY(`entry`, `item`, `condition_value1`);


--
-- Table changes for `pickpocketing_loot_template`
--
ALTER TABLE `pickpocketing_loot_template` CHANGE COLUMN `quest_freeforall` `QuestFFAorLootCondition` TINYINT(3) NOT NULL DEFAULT 1,
ADD COLUMN `condition_value1` int(11) UNSIGNED NOT NULL DEFAULT '0' AFTER `QuestFFAorLootCondition`,
ADD COLUMN `condition_value2` int(11) UNSIGNED NOT NULL DEFAULT '0' AFTER `condition_value1`;

ALTER TABLE `pickpocketing_loot_template` DROP PRIMARY KEY,
ADD PRIMARY KEY(`entry`, `item`, `condition_value1`);


--
-- Table changes for `skinning_loot_template`
--
ALTER TABLE `skinning_loot_template` CHANGE COLUMN `quest_freeforall` `QuestFFAorLootCondition` TINYINT(3) NOT NULL DEFAULT 1,
ADD COLUMN `condition_value1` int(11) UNSIGNED NOT NULL DEFAULT '0' AFTER `QuestFFAorLootCondition`,
ADD COLUMN `condition_value2` int(11) UNSIGNED NOT NULL DEFAULT '0' AFTER `condition_value1`;

ALTER TABLE `skinning_loot_template` DROP PRIMARY KEY,
ADD PRIMARY KEY(`entry`, `item`, `condition_value1`);


--
-- Table changes for `prospecting_loot_template`
--
ALTER TABLE `prospecting_loot_template` CHANGE COLUMN `quest_freeforall` `QuestFFAorLootCondition` TINYINT(3) NOT NULL DEFAULT 1,
ADD COLUMN `condition_value1` int(11) UNSIGNED NOT NULL DEFAULT '0' AFTER `QuestFFAorLootCondition`,
ADD COLUMN `condition_value2` int(11) UNSIGNED NOT NULL DEFAULT '0' AFTER `condition_value1`;

ALTER TABLE `prospecting_loot_template` DROP PRIMARY KEY,
ADD PRIMARY KEY(`entry`, `item`, `condition_value1`);