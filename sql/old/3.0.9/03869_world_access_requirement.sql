ALTER TABLE `access_requirement` ADD COLUMN `heroic_level_min` tinyint(3) unsigned NOT NULL default '0' AFTER `level_min`;
