-- extend=0 is normal, extend=1 is extended, extend=2 is expired
ALTER TABLE `character_instance` ADD COLUMN `extendState` TINYINT(2) UNSIGNED NOT NULL DEFAULT '1';
