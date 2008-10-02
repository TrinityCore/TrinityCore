ALTER TABLE `creature_loot_template`
  ADD COLUMN `mincount` tinyint(3) unsigned NOT NULL default '1' AFTER `QuestChanceOrGroup`;

ALTER TABLE `fishing_loot_template`
  ADD COLUMN `mincount` tinyint(3) unsigned NOT NULL default '1' AFTER `QuestChanceOrGroup`;

ALTER TABLE `gameobject_loot_template`
  ADD COLUMN `mincount` tinyint(3) unsigned NOT NULL default '1' AFTER `QuestChanceOrGroup`;

ALTER TABLE `item_loot_template`
  ADD COLUMN `mincount` tinyint(3) unsigned NOT NULL default '1' AFTER `QuestChanceOrGroup`;

ALTER TABLE `pickpocketing_loot_template`
  ADD COLUMN `mincount` tinyint(3) unsigned NOT NULL default '1' AFTER `QuestChanceOrGroup`;

ALTER TABLE `skinning_loot_template`
  ADD COLUMN `mincount` tinyint(3) unsigned NOT NULL default '1' AFTER `QuestChanceOrGroup`;
