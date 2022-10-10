CREATE TABLE `character_share` (
  `guid` int(11) unsigned NOT NULL,
  `bonus1` tinyint(1) NOT NULL DEFAULT '0',
  `bonus2` tinyint(1) NOT NULL DEFAULT '0',
  `bonus3` tinyint(1) NOT NULL DEFAULT '0',
  `bonus4` tinyint(1) NOT NULL DEFAULT '0',
  `bonus5` tinyint(1) NOT NULL DEFAULT '0',
  `bonus6` tinyint(1) NOT NULL DEFAULT '0',
  `bonus7` tinyint(1) NOT NULL DEFAULT '0',
  `bonus8` tinyint(1) NOT NULL DEFAULT '0',
  `bonus9` tinyint(1) NOT NULL DEFAULT '0',
  `bonus10` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;