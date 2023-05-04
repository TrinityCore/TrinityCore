
ALTER TABLE `characters` ADD `power8` int unsigned NOT NULL DEFAULT 0 AFTER `power7`;
ALTER TABLE `characters` ADD `power9` int unsigned NOT NULL DEFAULT 0 AFTER `power8`;
ALTER TABLE `characters` ADD `power10` int unsigned NOT NULL DEFAULT 0 AFTER `power9`;

ALTER TABLE `character_stats` ADD `maxpower8` int unsigned NOT NULL DEFAULT 0 AFTER `maxpower7`;
ALTER TABLE `character_stats` ADD `maxpower9` int unsigned NOT NULL DEFAULT 0 AFTER `maxpower8`;
ALTER TABLE `character_stats` ADD `maxpower10` int unsigned NOT NULL DEFAULT 0 AFTER `maxpower9`;
