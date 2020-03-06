DROP TABLE IF EXISTS `zone_default_light_override`;
CREATE TABLE `zone_default_light_override` (
	`zoneId` INT(10) UNSIGNED NOT NULL,
	`defaultLight` INT(10) UNSIGNED NOT NULL,
	`comment` VARCHAR(255) NULL DEFAULT NULL COLLATE 'utf8_general_ci',
	PRIMARY KEY (`zoneId`)
)COLLATE='utf8_general_ci'ENGINE=InnoDB;
