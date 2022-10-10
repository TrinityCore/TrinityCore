CREATE TABLE `mount_list` (
  `spell` int(11) unsigned NOT NULL DEFAULT '0',
  `side` int(11) unsigned NOT NULL DEFAULT '0',
  `spellS` int(11) unsigned NOT NULL DEFAULT '0',
  `sideS` int(11) unsigned NOT NULL DEFAULT '0',
  `name` varchar(50) CHARACTER SET latin1 NOT NULL DEFAULT '',
  PRIMARY KEY (`spell`),
  KEY `side` (`side`),
  KEY `spellS` (`spellS`),
  KEY `sideS` (`sideS`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
