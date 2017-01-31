ALTER TABLE `characters` ADD `power6` int(10) unsigned NOT NULL DEFAULT '0' AFTER `power5`;
ALTER TABLE `character_stats` ADD `maxpower6` int(10) unsigned NOT NULL DEFAULT '0' AFTER `maxpower5`;
