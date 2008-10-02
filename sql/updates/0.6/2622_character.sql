ALTER TABLE `character` ADD COLUMN `trans_x` float NOT NULL default '0';
ALTER TABLE `character` ADD COLUMN `trans_y` float NOT NULL default '0';
ALTER TABLE `character` ADD COLUMN `trans_z` float NOT NULL default '0';
ALTER TABLE `character` ADD COLUMN `trans_o` float NOT NULL default '0';
ALTER TABLE `character` ADD COLUMN `transguid` bigint(20) unsigned NOT NULL default '0';
