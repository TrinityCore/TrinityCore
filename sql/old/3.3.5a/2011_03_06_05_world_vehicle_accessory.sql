RENAME TABLE `vehicle_accessory` TO `vehicle_template_accessory`;
 
CREATE TABLE IF NOT EXISTS `vehicle_accessory` (
  `guid` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0,
  `accessory_entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0,
  `seat_id` TINYINT(1) NOT NULL DEFAULT 0,
  `minion` TINYINT(1) UNSIGNED NOT NULL DEFAULT 0,
  `description` TEXT NOT NULL,
  `summontype` TINYINT(3) UNSIGNED NOT NULL DEFAULT 6 COMMENT 'see enum TempSummonType',
  `summontimer` INT(10) UNSIGNED NOT NULL DEFAULT 30000 COMMENT 'timer, only relevant for certain summontypes',
  PRIMARY KEY (`guid`,`seat_id`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED;
