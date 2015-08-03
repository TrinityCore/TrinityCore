DROP TABLE IF EXISTS `character_queststatus`;
CREATE TABLE `character_queststatus` (
  `guid` BIGINT(20) UNSIGNED NOT NULL DEFAULT '0',
  `quest` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  `status` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
  `timer` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`, `quest`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

DROP TABLE IF EXISTS `character_queststatus_objectives`;
CREATE TABLE `character_queststatus_objectives` (
  `guid` BIGINT(20) UNSIGNED NOT NULL DEFAULT '0',
  `quest` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  `objective` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
  `data` INT(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`, `quest`, `objective`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';
