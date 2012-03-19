ALTER TABLE `instance_reset`
CHANGE `mapid` `mapid` SMALLINT(5) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `difficulty` `difficulty` TINYINT(3) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `resettime` `resettime` INT(10) UNSIGNED DEFAULT '0' NOT NULL;