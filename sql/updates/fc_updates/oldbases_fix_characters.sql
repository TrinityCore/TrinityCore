-- fix 1 for old created bases 
ALTER TABLE `characters` DROP COLUMN `latency`;
ALTER TABLE `characters` ADD COLUMN `latency` mediumint(8) unsigned NOT NULL DEFAULT '0' AFTER `power7`;

-- fix 2 for old created bases 
ALTER TABLE `character_pet` DROP COLUMN `talentpoints`;
