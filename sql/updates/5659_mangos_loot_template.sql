ALTER TABLE `creature_loot_template` 
  CHANGE `group` groupid tinyint unsigned NOT NULL default '0';

ALTER TABLE `disenchant_loot_template` 
  CHANGE `group` groupid tinyint unsigned NOT NULL default '0';

ALTER TABLE `fishing_loot_template`
  CHANGE `group` groupid tinyint unsigned NOT NULL default '0';

ALTER TABLE `gameobject_loot_template`
  CHANGE `group` groupid tinyint unsigned NOT NULL default '0';

ALTER TABLE `item_loot_template`
  CHANGE `group` groupid tinyint unsigned NOT NULL default '0';

ALTER TABLE `pickpocketing_loot_template`
  CHANGE `group` groupid tinyint unsigned NOT NULL default '0';

ALTER TABLE `prospecting_loot_template`
  CHANGE `group` groupid tinyint unsigned NOT NULL default '0';

ALTER TABLE `skinning_loot_template` 
  CHANGE `group` groupid tinyint unsigned NOT NULL default '0';
