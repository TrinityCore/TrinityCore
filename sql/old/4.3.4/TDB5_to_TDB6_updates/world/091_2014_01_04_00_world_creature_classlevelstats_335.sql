/*
ALTER TABLE `creature_classlevelstats`   
  CHANGE `level` `level` TINYINT(3) UNSIGNED NOT NULL,
  CHANGE `class` `class` TINYINT(3) UNSIGNED NOT NULL,
  CHANGE `basehp0` `basehp0` SMALLINT(5) UNSIGNED DEFAULT 1  NOT NULL,
  CHANGE `basehp1` `basehp1` SMALLINT(5) UNSIGNED DEFAULT 1  NOT NULL,
  CHANGE `basehp2` `basehp2` SMALLINT(5) UNSIGNED DEFAULT 1  NOT NULL,
  CHANGE `basemana` `basemana` SMALLINT(5) UNSIGNED DEFAULT 0  NOT NULL,
  CHANGE `basearmor` `basearmor` SMALLINT(5) UNSIGNED DEFAULT 1  NOT NULL,
  CHANGE `attackpower` `attackpower` SMALLINT(5) UNSIGNED DEFAULT 0  NOT NULL,
  CHANGE `rangedattackpower` `rangedattackpower` SMALLINT(5) UNSIGNED DEFAULT 0  NOT NULL;
*/
