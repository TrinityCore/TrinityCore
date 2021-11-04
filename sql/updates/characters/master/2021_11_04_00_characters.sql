ALTER TABLE `characters` ADD `power7` int(10) unsigned NOT NULL DEFAULT '0' AFTER `power6`;
ALTER TABLE `character_stats` ADD `maxpower7` int(10) unsigned NOT NULL DEFAULT '0' AFTER `maxpower6`;
