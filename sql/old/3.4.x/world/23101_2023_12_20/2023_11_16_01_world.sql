ALTER TABLE `player_classlevelstats`   
	ADD COLUMN `spi` SMALLINT NOT NULL COMMENT 'spirit' AFTER `inte`;

ALTER TABLE `player_racestats`   
	ADD COLUMN `spi` SMALLINT NOT NULL COMMENT 'spirit' AFTER `inte`;
