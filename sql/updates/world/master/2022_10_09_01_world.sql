ALTER TABLE `player_racestats` ADD COLUMN `spi` SMALLINT(5) NOT NULL COMMENT 'spirit' AFTER `inte`;

ALTER TABLE `player_classlevelstats` ADD COLUMN `spi` SMALLINT(5) UNSIGNED NOT NULL COMMENT 'spirit' AFTER `inte`;
