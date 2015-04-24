CREATE TABLE `custom_reforging` (
	`GUID` INT(10) UNSIGNED NOT NULL COMMENT 'item guid low',
	`increase` INT(10) UNSIGNED NOT NULL COMMENT 'stat_type',
	`decrease` INT(10) UNSIGNED NOT NULL COMMENT 'stat_type',
	`stat_value` INT(10) NOT NULL DEFAULT '0' COMMENT 'stat change',
	`Owner` INT(10) UNSIGNED NULL DEFAULT NULL COMMENT 'player guid',
	PRIMARY KEY (`GUID`)
)
COLLATE='utf8_general_ci'
ENGINE=InnoDB;
