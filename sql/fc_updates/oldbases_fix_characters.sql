ALTER TABLE `characters` DROP COLUMN `latency`;
ALTER TABLE `characters` ADD COLUMN `latency` mediumint(8) unsigned NOT NULL DEFAULT '0' AFTER `power7`;