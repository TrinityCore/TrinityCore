ALTER TABLE `vehicle_accessory`
ADD `summontype` TINYINT(3) UNSIGNED NOT NULL DEFAULT 6 COMMENT "see enum TempSummonType",
ADD `summontimer` INT(10) UNSIGNED NOT NULL DEFAULT 30000 COMMENT "timer, only relevant for certain summontypes";
