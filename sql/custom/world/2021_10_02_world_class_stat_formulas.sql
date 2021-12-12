CREATE TABLE IF NOT EXISTS `class_stat_formulas` (
	class mediumint(8) unsigned NOT NULL,
	stat_type mediumint(8) unsigned NOT NULL,
    class_out mediumint(8) unsigned NOT NULL,
	PRIMARY KEY (`class`,`stat_type`)
) ENGINE = MYISAM;