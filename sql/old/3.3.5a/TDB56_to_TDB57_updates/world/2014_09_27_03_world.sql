-- Alter creature_loot_template
ALTER TABLE `creature_loot_template` DROP PRIMARY KEY;
ALTER TABLE `creature_loot_template` CHANGE `entry` `Entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `creature_loot_template` CHANGE `item` `Item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `creature_loot_template` ADD COLUMN `Reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `Item`;
UPDATE `creature_loot_template` SET `Reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `creature_loot_template` SET  `mincountOrRef` = 1 WHERE `Reference` > 0;
ALTER TABLE `creature_loot_template` ADD COLUMN `QuestRequired` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `creature_loot_template` SET `QuestRequired` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = `ChanceOrQuestChance` * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `creature_loot_template` CHANGE `ChanceOrQuestChance` `Chance` FLOAT NOT NULL DEFAULT 100;
ALTER TABLE `creature_loot_template` CHANGE `lootmode` `LootMode` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `creature_loot_template` CHANGE `groupid` `GroupId` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `creature_loot_template` CHANGE `mincountOrRef` `MinCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `creature_loot_template` CHANGE `maxcount` `MaxCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `creature_loot_template` ADD COLUMN `Comment` VARCHAR(255) AFTER `MaxCount`;
ALTER TABLE `creature_loot_template` ADD PRIMARY KEY (`Entry`,`Item`);

-- Alter disenchant_loot_template
ALTER TABLE `disenchant_loot_template` DROP PRIMARY KEY;
ALTER TABLE `disenchant_loot_template` CHANGE `entry` `Entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `disenchant_loot_template` CHANGE `item` `Item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `disenchant_loot_template` ADD COLUMN `Reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `Item`;
UPDATE `disenchant_loot_template` SET `Reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `disenchant_loot_template` SET  `mincountOrRef` = 1 WHERE `Reference` > 0;
ALTER TABLE `disenchant_loot_template` ADD COLUMN `QuestRequired` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `disenchant_loot_template` SET `QuestRequired` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `disenchant_loot_template` SET `ChanceOrQuestChance` = `ChanceOrQuestChance` * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `disenchant_loot_template` CHANGE `ChanceOrQuestChance` `Chance` FLOAT NOT NULL DEFAULT 100;
ALTER TABLE `disenchant_loot_template` CHANGE `lootmode` `LootMode` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `disenchant_loot_template` CHANGE `groupid` `GroupId` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `disenchant_loot_template` CHANGE `mincountOrRef` `MinCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `disenchant_loot_template` CHANGE `maxcount` `MaxCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `disenchant_loot_template` ADD COLUMN `Comment` VARCHAR(255) AFTER `MaxCount`;
ALTER TABLE `disenchant_loot_template` ADD PRIMARY KEY (`Entry`,`Item`);

-- Alter fishing_loot_template
ALTER TABLE `fishing_loot_template` DROP PRIMARY KEY;
ALTER TABLE `fishing_loot_template` CHANGE `entry` `Entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `fishing_loot_template` CHANGE `item` `Item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `fishing_loot_template` ADD COLUMN `Reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `Item`;
UPDATE `fishing_loot_template` SET `Reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `fishing_loot_template` SET  `mincountOrRef` = 1 WHERE `Reference` > 0;
ALTER TABLE `fishing_loot_template` ADD COLUMN `QuestRequired` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `fishing_loot_template` SET `QuestRequired` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `fishing_loot_template` SET `ChanceOrQuestChance` = `ChanceOrQuestChance` * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `fishing_loot_template` CHANGE `ChanceOrQuestChance` `Chance` FLOAT NOT NULL DEFAULT 100;
ALTER TABLE `fishing_loot_template` CHANGE `lootmode` `LootMode` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `fishing_loot_template` CHANGE `groupid` `GroupId` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `fishing_loot_template` CHANGE `mincountOrRef` `MinCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `fishing_loot_template` CHANGE `maxcount` `MaxCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `fishing_loot_template` ADD COLUMN `Comment` VARCHAR(255) AFTER `MaxCount`;
ALTER TABLE `fishing_loot_template` ADD PRIMARY KEY (`Entry`,`Item`);

-- Alter gameobject_loot_template
ALTER TABLE `gameobject_loot_template` DROP PRIMARY KEY;
ALTER TABLE `gameobject_loot_template` CHANGE `entry` `Entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `gameobject_loot_template` CHANGE `item` `Item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `gameobject_loot_template` ADD COLUMN `Reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `Item`;
UPDATE `gameobject_loot_template` SET `Reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `gameobject_loot_template` SET  `mincountOrRef` = 1 WHERE `Reference` > 0;
ALTER TABLE `gameobject_loot_template` ADD COLUMN `QuestRequired` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `gameobject_loot_template` SET `QuestRequired` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance` = `ChanceOrQuestChance` * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `gameobject_loot_template` CHANGE `ChanceOrQuestChance` `Chance` FLOAT NOT NULL DEFAULT 100;
ALTER TABLE `gameobject_loot_template` CHANGE `lootmode` `LootMode` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `gameobject_loot_template` CHANGE `groupid` `GroupId` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `gameobject_loot_template` CHANGE `mincountOrRef` `MinCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `gameobject_loot_template` CHANGE `maxcount` `MaxCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `gameobject_loot_template` ADD COLUMN `Comment` VARCHAR(255) AFTER `MaxCount`;
ALTER TABLE `gameobject_loot_template` ADD PRIMARY KEY (`Entry`,`Item`);

-- Alter item_loot_template
ALTER TABLE `item_loot_template` DROP PRIMARY KEY;
ALTER TABLE `item_loot_template` CHANGE `entry` `Entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `item_loot_template` CHANGE `item` `Item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `item_loot_template` ADD COLUMN `Reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `Item`;
UPDATE `item_loot_template` SET `Reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `item_loot_template` SET  `mincountOrRef` = 1 WHERE `Reference` > 0;
ALTER TABLE `item_loot_template` ADD COLUMN `QuestRequired` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `item_loot_template` SET `QuestRequired` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `item_loot_template` SET `ChanceOrQuestChance` = `ChanceOrQuestChance` * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `item_loot_template` CHANGE `ChanceOrQuestChance` `Chance` FLOAT NOT NULL DEFAULT 100;
ALTER TABLE `item_loot_template` CHANGE `lootmode` `LootMode` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `item_loot_template` CHANGE `groupid` `GroupId` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `item_loot_template` CHANGE `mincountOrRef` `MinCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `item_loot_template` CHANGE `maxcount` `MaxCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `item_loot_template` ADD COLUMN `Comment` VARCHAR(255) AFTER `MaxCount`;
ALTER TABLE `item_loot_template` ADD PRIMARY KEY (`Entry`,`Item`);

-- Alter mail_loot_template
ALTER TABLE `mail_loot_template` DROP PRIMARY KEY;
ALTER TABLE `mail_loot_template` CHANGE `entry` `Entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `mail_loot_template` CHANGE `item` `Item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `mail_loot_template` ADD COLUMN `Reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `Item`;
UPDATE `mail_loot_template` SET `Reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `mail_loot_template` SET  `mincountOrRef` = 1 WHERE `Reference` > 0;
ALTER TABLE `mail_loot_template` ADD COLUMN `QuestRequired` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `mail_loot_template` SET `QuestRequired` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `mail_loot_template` SET `ChanceOrQuestChance` = `ChanceOrQuestChance` * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `mail_loot_template` CHANGE `ChanceOrQuestChance` `Chance` FLOAT NOT NULL DEFAULT 100;
ALTER TABLE `mail_loot_template` CHANGE `lootmode` `LootMode` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `mail_loot_template` CHANGE `groupid` `GroupId` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `mail_loot_template` CHANGE `mincountOrRef` `MinCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `mail_loot_template` CHANGE `maxcount` `MaxCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `mail_loot_template` ADD COLUMN `Comment` VARCHAR(255) AFTER `MaxCount`;
ALTER TABLE `mail_loot_template` ADD PRIMARY KEY (`Entry`,`Item`);

-- Alter milling_loot_template
ALTER TABLE `milling_loot_template` DROP PRIMARY KEY;
ALTER TABLE `milling_loot_template` CHANGE `entry` `Entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `milling_loot_template` CHANGE `item` `Item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `milling_loot_template` ADD COLUMN `Reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `Item`;
UPDATE `milling_loot_template` SET `Reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `milling_loot_template` SET  `mincountOrRef` = 1 WHERE `Reference` > 0;
ALTER TABLE `milling_loot_template` ADD COLUMN `QuestRequired` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `milling_loot_template` SET `QuestRequired` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `milling_loot_template` SET `ChanceOrQuestChance` = `ChanceOrQuestChance` * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `milling_loot_template` CHANGE `ChanceOrQuestChance` `Chance` FLOAT NOT NULL DEFAULT 100;
ALTER TABLE `milling_loot_template` CHANGE `lootmode` `LootMode` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `milling_loot_template` CHANGE `groupid` `GroupId` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `milling_loot_template` CHANGE `mincountOrRef` `MinCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `milling_loot_template` CHANGE `maxcount` `MaxCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `milling_loot_template` ADD COLUMN `Comment` VARCHAR(255) AFTER `MaxCount`;
ALTER TABLE `milling_loot_template` ADD PRIMARY KEY (`Entry`,`Item`);

-- Alter pickpocketing_loot_template
ALTER TABLE `pickpocketing_loot_template` DROP PRIMARY KEY;
ALTER TABLE `pickpocketing_loot_template` CHANGE `entry` `Entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `pickpocketing_loot_template` CHANGE `item` `Item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `pickpocketing_loot_template` ADD COLUMN `Reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `Item`;
UPDATE `pickpocketing_loot_template` SET `Reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `pickpocketing_loot_template` SET  `mincountOrRef` = 1 WHERE `Reference` > 0;
ALTER TABLE `pickpocketing_loot_template` ADD COLUMN `QuestRequired` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `pickpocketing_loot_template` SET `QuestRequired` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `pickpocketing_loot_template` SET `ChanceOrQuestChance` = `ChanceOrQuestChance` * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `pickpocketing_loot_template` CHANGE `ChanceOrQuestChance` `Chance` FLOAT NOT NULL DEFAULT 100;
ALTER TABLE `pickpocketing_loot_template` CHANGE `lootmode` `LootMode` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `pickpocketing_loot_template` CHANGE `groupid` `GroupId` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `pickpocketing_loot_template` CHANGE `mincountOrRef` `MinCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `pickpocketing_loot_template` CHANGE `maxcount` `MaxCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `pickpocketing_loot_template` ADD COLUMN `Comment` VARCHAR(255) AFTER `MaxCount`;
ALTER TABLE `pickpocketing_loot_template` ADD PRIMARY KEY (`Entry`,`Item`);

-- Alter prospecting_loot_template
ALTER TABLE `prospecting_loot_template` DROP PRIMARY KEY;
ALTER TABLE `prospecting_loot_template` CHANGE `entry` `Entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `prospecting_loot_template` CHANGE `item` `Item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `prospecting_loot_template` ADD COLUMN `Reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `Item`;
UPDATE `prospecting_loot_template` SET `Reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `prospecting_loot_template` SET  `mincountOrRef` = 1 WHERE `Reference` > 0;
ALTER TABLE `prospecting_loot_template` ADD COLUMN `QuestRequired` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `prospecting_loot_template` SET `QuestRequired` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `prospecting_loot_template` SET `ChanceOrQuestChance` = `ChanceOrQuestChance` * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `prospecting_loot_template` CHANGE `ChanceOrQuestChance` `Chance` FLOAT NOT NULL DEFAULT 100;
ALTER TABLE `prospecting_loot_template` CHANGE `lootmode` `LootMode` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `prospecting_loot_template` CHANGE `groupid` `GroupId` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `prospecting_loot_template` CHANGE `mincountOrRef` `MinCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `prospecting_loot_template` CHANGE `maxcount` `MaxCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `prospecting_loot_template` ADD COLUMN `Comment` VARCHAR(255) AFTER `MaxCount`;
ALTER TABLE `prospecting_loot_template` ADD PRIMARY KEY (`Entry`,`Item`);

-- Alter reference_loot_template
ALTER TABLE `reference_loot_template` DROP PRIMARY KEY;
ALTER TABLE `reference_loot_template` CHANGE `entry` `Entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `reference_loot_template` CHANGE `item` `Item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `reference_loot_template` ADD COLUMN `Reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `Item`;
UPDATE `reference_loot_template` SET `Reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `reference_loot_template` SET  `mincountOrRef` = 1 WHERE `Reference` > 0;
ALTER TABLE `reference_loot_template` ADD COLUMN `QuestRequired` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `reference_loot_template` SET `QuestRequired` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `reference_loot_template` SET `ChanceOrQuestChance` = `ChanceOrQuestChance` * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `reference_loot_template` CHANGE `ChanceOrQuestChance` `Chance` FLOAT NOT NULL DEFAULT 100;
ALTER TABLE `reference_loot_template` CHANGE `lootmode` `LootMode` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `reference_loot_template` CHANGE `groupid` `GroupId` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `reference_loot_template` CHANGE `mincountOrRef` `MinCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `reference_loot_template` CHANGE `maxcount` `MaxCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `reference_loot_template` ADD COLUMN `Comment` VARCHAR(255) AFTER `MaxCount`;
ALTER TABLE `reference_loot_template` ADD PRIMARY KEY (`Entry`,`Item`);

-- Alter skinning_loot_template
ALTER TABLE `skinning_loot_template` DROP PRIMARY KEY;
ALTER TABLE `skinning_loot_template` CHANGE `entry` `Entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `skinning_loot_template` CHANGE `item` `Item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `skinning_loot_template` ADD COLUMN `Reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `Item`;
UPDATE `skinning_loot_template` SET `Reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `skinning_loot_template` SET  `mincountOrRef` = 1 WHERE `Reference` > 0;
ALTER TABLE `skinning_loot_template` ADD COLUMN `QuestRequired` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `skinning_loot_template` SET `QuestRequired` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `skinning_loot_template` SET `ChanceOrQuestChance` = `ChanceOrQuestChance` * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `skinning_loot_template` CHANGE `ChanceOrQuestChance` `Chance` FLOAT NOT NULL DEFAULT 100;
ALTER TABLE `skinning_loot_template` CHANGE `lootmode` `LootMode` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `skinning_loot_template` CHANGE `groupid` `GroupId` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `skinning_loot_template` CHANGE `mincountOrRef` `MinCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `skinning_loot_template` CHANGE `maxcount` `MaxCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `skinning_loot_template` ADD COLUMN `Comment` VARCHAR(255) AFTER `MaxCount`;
ALTER TABLE `skinning_loot_template` ADD PRIMARY KEY (`Entry`,`Item`);

-- Alter spell_loot_template
ALTER TABLE `spell_loot_template` DROP PRIMARY KEY;
ALTER TABLE `spell_loot_template` CHANGE `entry` `Entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `spell_loot_template` CHANGE `item` `Item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `spell_loot_template` ADD COLUMN `Reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `Item`;
UPDATE `spell_loot_template` SET `Reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `spell_loot_template` SET  `mincountOrRef` = 1 WHERE `Reference` > 0;
ALTER TABLE `spell_loot_template` ADD COLUMN `QuestRequired` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `spell_loot_template` SET `QuestRequired` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `spell_loot_template` SET `ChanceOrQuestChance` = `ChanceOrQuestChance` * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `spell_loot_template` CHANGE `ChanceOrQuestChance` `Chance` FLOAT NOT NULL DEFAULT 100;
ALTER TABLE `spell_loot_template` CHANGE `lootmode` `LootMode` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `spell_loot_template` CHANGE `groupid` `GroupId` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `spell_loot_template` CHANGE `mincountOrRef` `MinCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `spell_loot_template` CHANGE `maxcount` `MaxCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1;
ALTER TABLE `spell_loot_template` ADD COLUMN `Comment` VARCHAR(255) AFTER `MaxCount`;
ALTER TABLE `spell_loot_template` ADD PRIMARY KEY (`Entry`,`Item`);
