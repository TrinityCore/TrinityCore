CREATE TABLE IF NOT EXISTS `class_stat_values` (
	class mediumint(8) unsigned NOT NULL,
	stat_type mediumint(8) unsigned NOT NULL,
    value float NOT NULL,
	PRIMARY KEY (`class`,`stat_type`)
) ENGINE = MYISAM;