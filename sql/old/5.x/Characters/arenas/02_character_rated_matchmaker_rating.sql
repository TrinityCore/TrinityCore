DROP TABLE IF EXISTS `character_rated_matchmaker_rating`;
CREATE TABLE `character_rated_matchmaker_rating` (
	`guid` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`matchmakerRating` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
	PRIMARY KEY (`guid`)
)
COLLATE='utf8_general_ci'
ENGINE=InnoDB;