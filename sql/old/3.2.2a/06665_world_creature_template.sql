ALTER TABLE `creature_template` ADD `exp` smallint(2) NOT NULL DEFAULT 0 AFTER `IconName`;
ALTER TABLE `creature_template` DROP `minhealth`;
ALTER TABLE `creature_template` DROP `maxhealth`;
ALTER TABLE `creature_template` DROP `minmana`;
ALTER TABLE `creature_template` DROP `maxmana`;
ALTER TABLE `creature_template` CHANGE `unk16` `Health_mod` FLOAT;
ALTER TABLE `creature_template` CHANGE `unk17` `Mana_mod` FLOAT;
