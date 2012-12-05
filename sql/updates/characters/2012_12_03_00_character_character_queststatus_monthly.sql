DROP TABLE IF EXISTS `character_queststatus_monthly`;

CREATE TABLE IF NOT EXISTS `character_queststatus_monthly` (
  `guid` INT(10) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `quest` INT(10) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'Quest Identifier',
  PRIMARY KEY (`guid`,`quest`),
  KEY `idx_guid` (`guid`)
) ENGINE=INNODB DEFAULT CHARSET=utf8 COMMENT='Player System';
