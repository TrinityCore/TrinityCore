--
-- Table structure for table `pvp_talent`
--
DROP TABLE IF EXISTS `pvp_talent`;
CREATE TABLE `pvp_talent` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Description` text,
  `SpellID` int(10) NOT NULL DEFAULT '0',
  `OverridesSpellID` int(10) NOT NULL DEFAULT '0',
  `ExtraSpellID` int(10) NOT NULL DEFAULT '0',
  `TierID` int(10) NOT NULL DEFAULT '0',
  `ColumnIndex` int(10) NOT NULL DEFAULT '0',
  `Flags` int(10) NOT NULL DEFAULT '0',
  `ClassID` int(10) NOT NULL DEFAULT '0',
  `SpecID` int(10) NOT NULL DEFAULT '0',
  `Role` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `pvp_talent_locale`
--
DROP TABLE IF EXISTS `pvp_talent_locale`;
CREATE TABLE `pvp_talent_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Description_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `pvp_talent_unlock`
--
DROP TABLE IF EXISTS `pvp_talent_unlock`;
CREATE TABLE `pvp_talent_unlock` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TierID` int(10) NOT NULL DEFAULT '0',
  `ColumnIndex` int(10) NOT NULL DEFAULT '0',
  `HonorLevel` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
