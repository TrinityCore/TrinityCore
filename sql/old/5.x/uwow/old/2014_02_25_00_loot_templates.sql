ALTER TABLE `creature_loot_template` MODIFY COLUMN `item` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `creature_loot_template` MODIFY COLUMN `maxcount` smallint(5) unsigned NOT NULL DEFAULT '1';

ALTER TABLE `disenchant_loot_template` MODIFY COLUMN `item` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `disenchant_loot_template` MODIFY COLUMN `maxcount` smallint(5) unsigned NOT NULL DEFAULT '1';

ALTER TABLE `fishing_loot_template` MODIFY COLUMN `item` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `fishing_loot_template` MODIFY COLUMN `maxcount` smallint(5) unsigned NOT NULL DEFAULT '1';

ALTER TABLE `gameobject_loot_template` MODIFY COLUMN `item` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `gameobject_loot_template` MODIFY COLUMN `maxcount` smallint(5) unsigned NOT NULL DEFAULT '1';

ALTER TABLE `item_loot_template` MODIFY COLUMN `item` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `item_loot_template` MODIFY COLUMN `maxcount` smallint(5) unsigned NOT NULL DEFAULT '1';

ALTER TABLE `mail_loot_template` MODIFY COLUMN `item` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `mail_loot_template` MODIFY COLUMN `maxcount` smallint(5) unsigned NOT NULL DEFAULT '1';

ALTER TABLE `milling_loot_template` MODIFY COLUMN `item` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `milling_loot_template` MODIFY COLUMN `maxcount` smallint(5) unsigned NOT NULL DEFAULT '1';

ALTER TABLE `pickpocketing_loot_template` MODIFY COLUMN `item` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `pickpocketing_loot_template` MODIFY COLUMN `maxcount` smallint(5) unsigned NOT NULL DEFAULT '1';

ALTER TABLE `prospecting_loot_template` MODIFY COLUMN `item` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `prospecting_loot_template` MODIFY COLUMN `maxcount` smallint(5) unsigned NOT NULL DEFAULT '1';

ALTER TABLE `reference_loot_template` MODIFY COLUMN `item` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `reference_loot_template` MODIFY COLUMN `maxcount` smallint(5) unsigned NOT NULL DEFAULT '1';

ALTER TABLE `skinning_loot_template` MODIFY COLUMN `item` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `skinning_loot_template` MODIFY COLUMN `maxcount` smallint(5) unsigned NOT NULL DEFAULT '1';

ALTER TABLE `spell_loot_template` MODIFY COLUMN `item` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `spell_loot_template` MODIFY COLUMN `maxcount` smallint(5) unsigned NOT NULL DEFAULT '1';
