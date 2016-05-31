--
-- Table structure for table `names_profanity`
--

DROP TABLE IF EXISTS `names_profanity`;
CREATE TABLE `names_profanity` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Language` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `names_reserved`
--

DROP TABLE IF EXISTS `names_reserved`;
CREATE TABLE `names_reserved` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `names_reserved_locale`
--

DROP TABLE IF EXISTS `names_reserved_locale`;
CREATE TABLE `names_reserved_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `LocaleMask` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
