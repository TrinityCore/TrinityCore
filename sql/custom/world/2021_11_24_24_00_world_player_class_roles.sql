CREATE TABLE `player_class_roles` (
	`class` MEDIUMINT(8) UNSIGNED NOT NULL,
	`tank` TINYINT(1) UNSIGNED NOT NULL,
	`healer` TINYINT(1) UNSIGNED NOT NULL,
	`damage` TINYINT(1) UNSIGNED NOT NULL,
	`leader` TINYINT(1) UNSIGNED NOT NULL,
	PRIMARY KEY (`class`)
);

INSERT INTO `player_class_roles` (`class`,`tank`,`healer`,`damage`,`leader`) VALUES
	(1,1,0,1,1),
	(2,1,1,1,1),
	(3,0,0,1,1),
	(4,0,0,1,1),
	(5,0,1,1,1),
	(6,1,0,1,1),
	(7,0,1,1,1),
	(8,0,0,1,1),
	(9,0,0,1,1),
	(11,1,1,1,1);