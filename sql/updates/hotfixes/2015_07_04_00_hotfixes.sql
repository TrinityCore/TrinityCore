/*Table structure for table `game_tables` */

DROP TABLE IF EXISTS `game_tables`;

CREATE TABLE `game_tables` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text NOT NULL,
  `NumRows` int(10) unsigned NOT NULL DEFAULT '0',
  `NumColumns` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(5) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Table structure for table `game_tables_locale` */

DROP TABLE IF EXISTS `game_tables_locale`;

CREATE TABLE `game_tables_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text NOT NULL,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
