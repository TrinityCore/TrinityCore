CREATE TABLE `pvpstats_faction` (
	`id` BIGINT(20) NOT NULL AUTO_INCREMENT,
	`faction` INT(11) NOT NULL,
	`level` INT(11) NOT NULL,
	`date` DATETIME NOT NULL,
	PRIMARY KEY (`id`)
)
COLLATE='latin1_swedish_ci'
ENGINE=InnoDB
AUTO_INCREMENT=12;

CREATE TABLE `pvpstats_players` (
	`id` BIGINT(20) NOT NULL AUTO_INCREMENT,
	`character_guid` INT(11) NOT NULL,
	`level` INT(11) NOT NULL,
	`date` DATETIME NOT NULL,
	PRIMARY KEY (`id`)
)
COLLATE='latin1_swedish_ci'
ENGINE=InnoDB
AUTO_INCREMENT=14;

