ALTER TABLE `creature_loot_template` ADD COLUMN `BonusList`  text NULL AFTER `MaxCount`, DROP PRIMARY KEY;
ALTER TABLE `disenchant_loot_template` ADD COLUMN `BonusList`  text NULL AFTER `MaxCount`, DROP PRIMARY KEY;
ALTER TABLE `fishing_loot_template` ADD COLUMN `BonusList`  text NULL AFTER `MaxCount`, DROP PRIMARY KEY;
ALTER TABLE `gameobject_loot_template` ADD COLUMN `BonusList`  text NULL AFTER `MaxCount`, DROP PRIMARY KEY;
ALTER TABLE `item_loot_template` ADD COLUMN `BonusList`  text NULL AFTER `MaxCount`, DROP PRIMARY KEY;
ALTER TABLE `mail_loot_template` ADD COLUMN `BonusList`  text NULL AFTER `MaxCount`, DROP PRIMARY KEY;
ALTER TABLE `milling_loot_template` ADD COLUMN `BonusList`  text NULL AFTER `MaxCount`, DROP PRIMARY KEY;
ALTER TABLE `pickpocketing_loot_template` ADD COLUMN `BonusList`  text NULL AFTER `MaxCount`, DROP PRIMARY KEY;
ALTER TABLE `prospecting_loot_template` ADD COLUMN `BonusList`  text NULL AFTER `MaxCount`, DROP PRIMARY KEY;
ALTER TABLE `reference_loot_template` ADD COLUMN `BonusList`  text NULL AFTER `MaxCount`, DROP PRIMARY KEY;
ALTER TABLE `skinning_loot_template` ADD COLUMN `BonusList`  text NULL AFTER `MaxCount`, DROP PRIMARY KEY;
ALTER TABLE `spell_loot_template` ADD COLUMN `BonusList`  text NULL AFTER `MaxCount`, DROP PRIMARY KEY;

ALTER TABLE `npc_vendor` DROP PRIMARY KEY;