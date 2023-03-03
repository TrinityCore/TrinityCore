CREATE TABLE `character_visuals` (
  `guid` int(11) NOT NULL DEFAULT '0',
  `head` int(11) NOT NULL DEFAULT '0',
  `shoulders` int(11) NOT NULL DEFAULT '0',
  `chest` int(11) NOT NULL DEFAULT '0',
  `waist` int(11) NOT NULL DEFAULT '0',
  `legs` int(11) NOT NULL DEFAULT '0',
  `feet` int(11) NOT NULL DEFAULT '0',
  `wrists` int(11) NOT NULL DEFAULT '0',
  `hands` int(11) NOT NULL DEFAULT '0',
  `back` int(11) NOT NULL DEFAULT '0',
  `main` int(11) NOT NULL DEFAULT '0',
  `off` int(11) NOT NULL DEFAULT '0',
  `ranged` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
