ALTER TABLE `player_levelstats` CHANGE `str` `str` SMALLINT(6) UNSIGNED NOT NULL COMMENT 'strength';
ALTER TABLE `player_levelstats` CHANGE `agi` `agi` SMALLINT(6) UNSIGNED NOT NULL COMMENT 'agility';
ALTER TABLE `player_levelstats` CHANGE `sta` `sta` SMALLINT(6) UNSIGNED NOT NULL COMMENT 'stamina';
ALTER TABLE `player_levelstats` CHANGE `inte` `inte` SMALLINT(6) UNSIGNED NOT NULL COMMENT 'intellect';
ALTER TABLE `player_levelstats` CHANGE `spi` `spi` SMALLINT(6) UNSIGNED NOT NULL COMMENT 'spirit';
