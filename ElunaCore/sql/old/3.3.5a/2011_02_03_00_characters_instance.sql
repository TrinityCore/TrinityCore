ALTER TABLE `instance` ADD COLUMN `completedEncounters` int(10) unsigned NOT NULL DEFAULT '0' AFTER `difficulty`;
