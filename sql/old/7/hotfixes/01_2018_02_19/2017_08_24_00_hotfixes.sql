--
-- Table structure for table `transmog_holiday`
--
DROP TABLE IF EXISTS `transmog_holiday`;
CREATE TABLE `transmog_holiday` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `HolidayID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `transmog_set`
--
DROP TABLE IF EXISTS `transmog_set`;
CREATE TABLE `transmog_set` (
  `Name` text,
  `BaseSetID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `UIOrder` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ExpansionID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `QuestID` int(11) NOT NULL DEFAULT '0',
  `ClassMask` int(11) NOT NULL DEFAULT '0',
  `ItemNameDescriptionID` int(11) NOT NULL DEFAULT '0',
  `TransmogSetGroupID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `transmog_set_locale`
--
DROP TABLE IF EXISTS `transmog_set_locale`;
CREATE TABLE `transmog_set_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `transmog_set_group`
--
DROP TABLE IF EXISTS `transmog_set_group`;
CREATE TABLE `transmog_set_group` (
  `Label` text,
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `transmog_set_group_locale`
--
DROP TABLE IF EXISTS `transmog_set_group_locale`;
CREATE TABLE `transmog_set_group_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Label_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `transmog_set_item`
--
DROP TABLE IF EXISTS `transmog_set_item`;
CREATE TABLE `transmog_set_item` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TransmogSetID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemModifiedAppearanceID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
