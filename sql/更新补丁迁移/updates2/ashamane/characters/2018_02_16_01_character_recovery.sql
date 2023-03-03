DROP TABLE IF EXISTS `character_recovery`;
CREATE TABLE `character_recovery` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `delivered` tinyint(1) DEFAULT '0',
  `account` int(11) unsigned NOT NULL,
  `race` int(11) unsigned NOT NULL,
  `class` int(11) unsigned NOT NULL,
  `level` int(11) unsigned NOT NULL,
  `skill1` int(11) NOT NULL DEFAULT '0',
  `skill1_value` int(11) NOT NULL DEFAULT '0',
  `skill2` int(11) NOT NULL DEFAULT '0',
  `skill2_value` int(11) NOT NULL DEFAULT '0',
  `items` text NOT NULL,
  `spells` text NOT NULL,
  `at_login` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=50917 DEFAULT CHARSET=latin1;
