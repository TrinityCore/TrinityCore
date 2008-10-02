ALTER TABLE `creature_loot_template` 
  CHANGE `QuestFFAorLootCondition` `freeforall` tinyint(1) unsigned NOT NULL default 0 COMMENT '1 if everybody should get a copy';
ALTER TABLE `creature_loot_template` 
  ADD COLUMN `lootcondition` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `freeforall`;

ALTER TABLE `disenchant_loot_template` 
  CHANGE `QuestFFAorLootCondition` `freeforall` tinyint(1) unsigned NOT NULL default 0 COMMENT '1 if everybody should get a copy';
ALTER TABLE `disenchant_loot_template` 
  ADD COLUMN `lootcondition` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `freeforall`;

ALTER TABLE `fishing_loot_template` 
  CHANGE `QuestFFAorLootCondition` `freeforall` tinyint(1) unsigned NOT NULL default 0 COMMENT '1 if everybody should get a copy';
ALTER TABLE `fishing_loot_template` 
  ADD COLUMN `lootcondition` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `freeforall`;

ALTER TABLE `gameobject_loot_template` 
  CHANGE `QuestFFAorLootCondition` `freeforall` tinyint(1) unsigned NOT NULL default 0 COMMENT '1 if everybody should get a copy';
ALTER TABLE `gameobject_loot_template` 
  ADD COLUMN `lootcondition` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `freeforall`;

ALTER TABLE `item_loot_template` 
  CHANGE `QuestFFAorLootCondition` `freeforall` tinyint(1) unsigned NOT NULL default 0 COMMENT '1 if everybody should get a copy';
ALTER TABLE `item_loot_template` 
  ADD COLUMN `lootcondition` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `freeforall`;

ALTER TABLE `pickpocketing_loot_template` 
  CHANGE `QuestFFAorLootCondition` `freeforall` tinyint(1) unsigned NOT NULL default 0 COMMENT '1 if everybody should get a copy';
ALTER TABLE `pickpocketing_loot_template` 
  ADD COLUMN `lootcondition` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `freeforall`;

ALTER TABLE `skinning_loot_template` 
  CHANGE `QuestFFAorLootCondition` `freeforall` tinyint(1) unsigned NOT NULL default 0 COMMENT '1 if everybody should get a copy';
ALTER TABLE `skinning_loot_template` 
  ADD COLUMN `lootcondition` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `freeforall`;

ALTER TABLE `prospecting_loot_template` 
  CHANGE `QuestFFAorLootCondition` `freeforall` tinyint(1) unsigned NOT NULL default 0 COMMENT '1 if everybody should get a copy';
ALTER TABLE `prospecting_loot_template` 
  ADD COLUMN `lootcondition` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `freeforall`;
