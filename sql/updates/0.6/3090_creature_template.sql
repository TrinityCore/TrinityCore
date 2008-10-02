ALTER TABLE `creature_template` 
  ADD COLUMN `pickpocketloot` int(10) unsigned NOT NULL default '0' AFTER `lootid`;

UPDATE `creature_template`,`pickpocketing_loot_template`
  SET `creature_template`.`pickpocketloot` = `creature_template`.`lootid`
  WHERE `creature_template`.`lootid` = `pickpocketing_loot_template`.`entry`;
