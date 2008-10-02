ALTER TABLE `character` ADD COLUMN `pending_honor` float NOT NULL default '0';
ALTER TABLE `character` ADD COLUMN `last_honor_date` int(11) unsigned NOT NULL default '0';
ALTER TABLE `character` ADD COLUMN `last_kill_date` int(11) unsigned NOT NULL default '0';