ALTER TABLE `creature_loot_template`
ADD `shared` TINYINT(3) DEFAULT '0' NOT NULL AFTER `maxcount`;
ALTER TABLE `disenchant_loot_template`
ADD `shared` TINYINT(3) DEFAULT '0' NOT NULL AFTER `maxcount`;
ALTER TABLE `fishing_loot_template`
ADD `shared` TINYINT(3) DEFAULT '0' NOT NULL AFTER `maxcount`;
ALTER TABLE `gameobject_loot_template`
ADD `shared` TINYINT(3) DEFAULT '0' NOT NULL AFTER `maxcount`;
ALTER TABLE `item_loot_template`
ADD `shared` TINYINT(3) DEFAULT '0' NOT NULL AFTER `maxcount`;
ALTER TABLE `mail_loot_template`
ADD `shared` TINYINT(3) DEFAULT '0' NOT NULL AFTER `maxcount`;
ALTER TABLE `milling_loot_template`
ADD `shared` TINYINT(3) DEFAULT '0' NOT NULL AFTER `maxcount`;
ALTER TABLE `pickpocketing_loot_template`
ADD `shared` TINYINT(3) DEFAULT '0' NOT NULL AFTER `maxcount`;
ALTER TABLE `prospecting_loot_template`
ADD `shared` TINYINT(3) DEFAULT '0' NOT NULL AFTER `maxcount`;
ALTER TABLE `reference_loot_template`
ADD `shared` TINYINT(3) DEFAULT '0' NOT NULL AFTER `maxcount`;
ALTER TABLE `skinning_loot_template`
ADD `shared` TINYINT(3) DEFAULT '0' NOT NULL AFTER `maxcount`;
ALTER TABLE `spell_loot_template`
ADD `shared` TINYINT(3) DEFAULT '0' NOT NULL AFTER `maxcount`;
ALTER TABLE `spell_trigger`
ADD `check_spell_id` INT(11) DEFAULT '0' NOT NULL;
