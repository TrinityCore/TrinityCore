-- Alter creature_loot_template "Cannot set item to 0 for reference entries. Will get primary key error"
ALTER TABLE `creature_loot_template` ADD COLUMN `reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `item`;
ALTER TABLE `creature_loot_template` DROP PRIMARY KEY;
ALTER TABLE `creature_loot_template` ADD PRIMARY KEY (`entry`,`item`,`reference`);
UPDATE `creature_loot_template` SET `reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `creature_loot_template` SET  `mincountOrRef` = 1 WHERE `reference` > 0;
ALTER TABLE `creature_loot_template` ADD COLUMN `needsquest` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `creature_loot_template` SET `needsquest` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = ChanceOrQuestChance * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `creature_loot_template` CHANGE `ChanceOrQuestChance` `chance` FLOAT;
ALTER TABLE `creature_loot_template` ADD COLUMN `mincount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1 AFTER `mincountOrRef`;
UPDATE `creature_loot_template` SET `mincount` = `mincountOrRef`;
ALTER TABLE `creature_loot_template` DROP `mincountOrRef`;
ALTER TABLE `creature_loot_template` ADD COLUMN `comment` VARCHAR(255) AFTER `maxcount`;

-- Alter disenchant_loot_template
ALTER TABLE `disenchant_loot_template` ADD COLUMN `reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `item`;
ALTER TABLE `disenchant_loot_template` DROP PRIMARY KEY;
ALTER TABLE `disenchant_loot_template` ADD PRIMARY KEY (`entry`,`item`,`reference`);
UPDATE `disenchant_loot_template` SET `reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `disenchant_loot_template` SET `mincountOrRef` = 1 WHERE `reference` > 0;
ALTER TABLE `disenchant_loot_template` ADD COLUMN `needsquest` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `disenchant_loot_template` SET `needsquest` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `disenchant_loot_template` SET `ChanceOrQuestChance` = ChanceOrQuestChance * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `disenchant_loot_template` CHANGE `ChanceOrQuestChance` `chance` FLOAT;
ALTER TABLE `disenchant_loot_template` ADD COLUMN `mincount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1 AFTER `mincountOrRef`;
UPDATE `disenchant_loot_template` SET `mincount` = `mincountOrRef`;
ALTER TABLE `disenchant_loot_template` DROP `mincountOrRef`;
ALTER TABLE `disenchant_loot_template` ADD COLUMN `comment` VARCHAR(255) AFTER `maxcount`;

-- Alter fishing_loot_template
ALTER TABLE `fishing_loot_template` ADD COLUMN `reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `item`;
ALTER TABLE `fishing_loot_template` DROP PRIMARY KEY;
ALTER TABLE `fishing_loot_template` ADD PRIMARY KEY (`entry`,`item`,`reference`);
UPDATE `fishing_loot_template` SET `reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `fishing_loot_template` SET `mincountOrRef` = 1 WHERE `reference` > 0;
ALTER TABLE `fishing_loot_template` ADD COLUMN `needsquest` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `fishing_loot_template` SET `needsquest` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `fishing_loot_template` SET `ChanceOrQuestChance` = ChanceOrQuestChance * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `fishing_loot_template` CHANGE `ChanceOrQuestChance` `chance` FLOAT;
ALTER TABLE `fishing_loot_template` ADD COLUMN `mincount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1 AFTER `mincountOrRef`;
UPDATE `fishing_loot_template` SET `mincount` = `mincountOrRef`;
ALTER TABLE `fishing_loot_template` DROP `mincountOrRef`;
ALTER TABLE `fishing_loot_template` ADD COLUMN `comment` VARCHAR(255) AFTER `maxcount`;

-- Alter gameobject_loot_template "Cannot set item to 0 for reference entries. Will get primary key error"
ALTER TABLE `gameobject_loot_template` ADD COLUMN `reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `item`;
ALTER TABLE `gameobject_loot_template` DROP PRIMARY KEY;
ALTER TABLE `gameobject_loot_template` ADD PRIMARY KEY (`entry`,`item`,`reference`);
UPDATE `gameobject_loot_template` SET `reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `gameobject_loot_template` SET `mincountOrRef` = 1 WHERE `reference` > 0;
ALTER TABLE `gameobject_loot_template` ADD COLUMN `needsquest` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `gameobject_loot_template` SET `needsquest` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance` = ChanceOrQuestChance * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `gameobject_loot_template` CHANGE `ChanceOrQuestChance` `chance` FLOAT;
ALTER TABLE `gameobject_loot_template` ADD COLUMN `mincount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1 AFTER `mincountOrRef`;
UPDATE `gameobject_loot_template` SET `mincount` = `mincountOrRef`;
ALTER TABLE `gameobject_loot_template` DROP `mincountOrRef`;
ALTER TABLE `gameobject_loot_template` ADD COLUMN `comment` VARCHAR(255) AFTER `maxcount`;

-- Alter item_loot_template "Cannot set item to 0 for reference entries. Will get primary key error"
ALTER TABLE `item_loot_template` ADD COLUMN `reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `item`;
ALTER TABLE `item_loot_template` DROP PRIMARY KEY;
ALTER TABLE `item_loot_template` ADD PRIMARY KEY (`entry`,`item`,`reference`);
UPDATE `item_loot_template` SET `reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `item_loot_template` SET `mincountOrRef` = 1 WHERE `reference` > 0;
ALTER TABLE `item_loot_template` ADD COLUMN `needsquest` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `item_loot_template` SET `needsquest` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `item_loot_template` SET `ChanceOrQuestChance` = ChanceOrQuestChance * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `item_loot_template` CHANGE `ChanceOrQuestChance` `chance` FLOAT;
ALTER TABLE `item_loot_template` ADD COLUMN `mincount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1 AFTER `mincountOrRef`;
UPDATE `item_loot_template` SET `mincount` = `mincountOrRef`;
ALTER TABLE `item_loot_template` DROP `mincountOrRef`;
ALTER TABLE `item_loot_template` ADD COLUMN `comment` VARCHAR(255) AFTER `maxcount`;

-- Alter mail_loot_template
ALTER TABLE `mail_loot_template` ADD COLUMN `reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `item`;
ALTER TABLE `mail_loot_template` DROP PRIMARY KEY;
ALTER TABLE `mail_loot_template` ADD PRIMARY KEY (`entry`,`item`,`reference`);
UPDATE `mail_loot_template` SET `reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `mail_loot_template` SET `mincountOrRef` = 1 WHERE `reference` > 0;
ALTER TABLE `mail_loot_template` ADD COLUMN `needsquest` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `mail_loot_template` SET `needsquest` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `mail_loot_template` SET `ChanceOrQuestChance` = ChanceOrQuestChance * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `mail_loot_template` CHANGE `ChanceOrQuestChance` `chance` FLOAT;
ALTER TABLE `mail_loot_template` ADD COLUMN `mincount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1 AFTER `mincountOrRef`;
UPDATE `mail_loot_template` SET `mincount` = `mincountOrRef`;
ALTER TABLE `mail_loot_template` DROP `mincountOrRef`;
ALTER TABLE `mail_loot_template` ADD COLUMN `comment` VARCHAR(255) AFTER `maxcount`;

-- Alter milling_loot_template
ALTER TABLE `milling_loot_template` ADD COLUMN `reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `item`;
ALTER TABLE `milling_loot_template` DROP PRIMARY KEY;
ALTER TABLE `milling_loot_template` ADD PRIMARY KEY (`entry`,`item`,`reference`);
UPDATE `milling_loot_template` SET `reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `milling_loot_template` SET `mincountOrRef` = 1 WHERE `reference` > 0;
ALTER TABLE `milling_loot_template` ADD COLUMN `needsquest` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `milling_loot_template` SET `needsquest` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `milling_loot_template` SET `ChanceOrQuestChance` = ChanceOrQuestChance * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `milling_loot_template` CHANGE `ChanceOrQuestChance` `chance` FLOAT;
ALTER TABLE `milling_loot_template` ADD COLUMN `mincount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1 AFTER `mincountOrRef`;
UPDATE `milling_loot_template` SET `mincount` = `mincountOrRef`;
ALTER TABLE `milling_loot_template` DROP `mincountOrRef`;
ALTER TABLE `milling_loot_template` ADD COLUMN `comment` VARCHAR(255) AFTER `maxcount`;

-- Alter pickpocketing_loot_template
ALTER TABLE `pickpocketing_loot_template` ADD COLUMN `reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `item`;
ALTER TABLE `pickpocketing_loot_template` DROP PRIMARY KEY;
ALTER TABLE `pickpocketing_loot_template` ADD PRIMARY KEY (`entry`,`item`,`reference`);
UPDATE `pickpocketing_loot_template` SET `reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `pickpocketing_loot_template` SET `mincountOrRef` = 1 WHERE `reference` > 0;
ALTER TABLE `pickpocketing_loot_template` ADD COLUMN `needsquest` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `pickpocketing_loot_template` SET `needsquest` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `pickpocketing_loot_template` SET `ChanceOrQuestChance` = ChanceOrQuestChance * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `pickpocketing_loot_template` CHANGE `ChanceOrQuestChance` `chance` FLOAT;
ALTER TABLE `pickpocketing_loot_template` ADD COLUMN `mincount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1 AFTER `mincountOrRef`;
UPDATE `pickpocketing_loot_template` SET `mincount` = `mincountOrRef`;
ALTER TABLE `pickpocketing_loot_template` DROP `mincountOrRef`;
ALTER TABLE `pickpocketing_loot_template` ADD COLUMN `comment` VARCHAR(255) AFTER `maxcount`;

-- Alter prospecting_loot_template
ALTER TABLE `prospecting_loot_template` ADD COLUMN `reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `item`;
ALTER TABLE `prospecting_loot_template` DROP PRIMARY KEY;
ALTER TABLE `prospecting_loot_template` ADD PRIMARY KEY (`entry`,`item`,`reference`);
UPDATE `prospecting_loot_template` SET `reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `prospecting_loot_template` SET `mincountOrRef` = 1 WHERE `reference` > 0;
ALTER TABLE `prospecting_loot_template` ADD COLUMN `needsquest` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `prospecting_loot_template` SET `needsquest` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `prospecting_loot_template` SET `ChanceOrQuestChance` = ChanceOrQuestChance * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `prospecting_loot_template` CHANGE `ChanceOrQuestChance` `chance` FLOAT;
ALTER TABLE `prospecting_loot_template` ADD COLUMN `mincount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1 AFTER `mincountOrRef`;
UPDATE `prospecting_loot_template` SET `mincount` = `mincountOrRef`;
ALTER TABLE `prospecting_loot_template` DROP `mincountOrRef`;
ALTER TABLE `prospecting_loot_template` ADD COLUMN `comment` VARCHAR(255) AFTER `maxcount`;

-- Alter reference_loot_template "Cannot set item to 0 for reference entries. Will get primary key error"
ALTER TABLE `reference_loot_template` ADD COLUMN `reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `item`;
ALTER TABLE `reference_loot_template` DROP PRIMARY KEY;
ALTER TABLE `reference_loot_template` ADD PRIMARY KEY (`entry`,`item`,`reference`);
UPDATE `reference_loot_template` SET `reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `reference_loot_template` SET `mincountOrRef` = 1 WHERE `reference` > 0;
ALTER TABLE `reference_loot_template` ADD COLUMN `needsquest` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `reference_loot_template` SET `needsquest` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `reference_loot_template` SET `ChanceOrQuestChance` = ChanceOrQuestChance * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `reference_loot_template` CHANGE `ChanceOrQuestChance` `chance` FLOAT;
ALTER TABLE `reference_loot_template` ADD COLUMN `mincount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1 AFTER `mincountOrRef`;
UPDATE `reference_loot_template` SET `mincount` = `mincountOrRef`;
ALTER TABLE `reference_loot_template` DROP `mincountOrRef`;
ALTER TABLE `reference_loot_template` ADD COLUMN `comment` VARCHAR(255) AFTER `maxcount`;

-- Alter skinning_loot_template
ALTER TABLE `skinning_loot_template` ADD COLUMN `reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `item`;
ALTER TABLE `skinning_loot_template` DROP PRIMARY KEY;
ALTER TABLE `skinning_loot_template` ADD PRIMARY KEY (`entry`,`item`,`reference`);
UPDATE `skinning_loot_template` SET `reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `skinning_loot_template` SET `mincountOrRef` = 1 WHERE `reference` > 0;
ALTER TABLE `skinning_loot_template` ADD COLUMN `needsquest` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `skinning_loot_template` SET `needsquest` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `skinning_loot_template` SET `ChanceOrQuestChance` = ChanceOrQuestChance * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `skinning_loot_template` CHANGE `ChanceOrQuestChance` `chance` FLOAT;
ALTER TABLE `skinning_loot_template` ADD COLUMN `mincount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1 AFTER `mincountOrRef`;
UPDATE `skinning_loot_template` SET `mincount` = `mincountOrRef`;
ALTER TABLE `skinning_loot_template` DROP `mincountOrRef`;
ALTER TABLE `skinning_loot_template` ADD COLUMN `comment` VARCHAR(255) AFTER `maxcount`;

-- Alter spell_loot_template
ALTER TABLE `spell_loot_template` ADD COLUMN `reference` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `item`;
ALTER TABLE `spell_loot_template` DROP PRIMARY KEY;
ALTER TABLE `spell_loot_template` ADD PRIMARY KEY (`entry`,`item`,`reference`);
UPDATE `spell_loot_template` SET `reference` = `mincountOrRef` * -1 WHERE `mincountOrRef` < 0;
UPDATE `spell_loot_template` SET `mincountOrRef` = 1 WHERE `reference` > 0;
ALTER TABLE `spell_loot_template` ADD COLUMN `needsquest` BOOL NOT NULL DEFAULT 0 AFTER `ChanceOrQuestChance`;
UPDATE `spell_loot_template` SET `needsquest` = 1 WHERE `ChanceOrQuestChance` < 0;
UPDATE `spell_loot_template` SET `ChanceOrQuestChance` = ChanceOrQuestChance * -1 WHERE `ChanceOrQuestChance` < 0;
ALTER TABLE `spell_loot_template` CHANGE `ChanceOrQuestChance` `chance` FLOAT;
ALTER TABLE `spell_loot_template` ADD COLUMN `mincount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1 AFTER `mincountOrRef`;
UPDATE `spell_loot_template` SET `mincount` = `mincountOrRef`;
ALTER TABLE `spell_loot_template` DROP `mincountOrRef`;
ALTER TABLE `spell_loot_template` ADD COLUMN `comment` VARCHAR(255) AFTER `maxcount`;
