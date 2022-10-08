DROP TABLE IF EXISTS `character_archaeology`;
CREATE TABLE `character_archaeology` (
  `guid` int(11) NOT NULL,
  `sites` text NOT NULL,
  `counts` text NOT NULL,
  `projects` text NOT NULL,
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Archaeology System';
