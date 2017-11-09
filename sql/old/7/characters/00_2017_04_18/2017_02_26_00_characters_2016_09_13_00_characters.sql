DROP TABLE IF EXISTS `character_fishingsteps`;
CREATE TABLE `character_fishingsteps` (
  `guid` BIGINT(20) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `fishingSteps` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=INNODB DEFAULT CHARSET=utf8;
