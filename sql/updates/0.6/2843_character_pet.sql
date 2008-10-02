ALTER TABLE `character_pet`
  ADD COLUMN `renamed` tinyint(1) unsigned NOT NULL default '0' after `name`;
