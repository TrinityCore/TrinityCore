DROP TABLE IF EXISTS `creature_sparring_template`;
CREATE TABLE `creature_sparring_template`(  
  `AttackerEntry` MEDIUMINT(8) UNSIGNED NOT NULL,
  `VictimEntry` MEDIUMINT(8) UNSIGNED NOT NULL,
  `HealthLimitPct` FLOAT(5) DEFAULT 0,
  PRIMARY KEY (`AttackerEntry`, `VictimEntry`)
);
