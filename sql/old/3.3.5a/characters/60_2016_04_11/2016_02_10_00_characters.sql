-- extend=0 is expired, extend=1 is normal, extend=2 is extended
ALTER TABLE `character_instance` ADD COLUMN `extendState` TINYINT(2) UNSIGNED NOT NULL DEFAULT '1';
