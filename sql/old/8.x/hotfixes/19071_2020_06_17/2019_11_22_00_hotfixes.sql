--
-- Table structure for table `azerite_essence`
--
DROP TABLE IF EXISTS `azerite_essence`;
CREATE TABLE `azerite_essence` (
  `Name` text,
  `Description` text,
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpecSetID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `azerite_essence_locale`
--
DROP TABLE IF EXISTS `azerite_essence_locale`;
CREATE TABLE `azerite_essence_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Description_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `azerite_essence_power`
--
DROP TABLE IF EXISTS `azerite_essence_power`;
CREATE TABLE `azerite_essence_power` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SourceAlliance` text,
  `SourceHorde` text,
  `AzeriteEssenceID` int(11) NOT NULL DEFAULT '0',
  `Tier` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MajorPowerDescription` int(11) NOT NULL DEFAULT '0',
  `MinorPowerDescription` int(11) NOT NULL DEFAULT '0',
  `MajorPowerActual` int(11) NOT NULL DEFAULT '0',
  `MinorPowerActual` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `azerite_essence_power_locale`
--
DROP TABLE IF EXISTS `azerite_essence_power_locale`;
CREATE TABLE `azerite_essence_power_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `SourceAlliance_lang` text,
  `SourceHorde_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `azerite_item_milestone_power`
--
DROP TABLE IF EXISTS `azerite_item_milestone_power`;
CREATE TABLE `azerite_item_milestone_power` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredLevel` int(11) NOT NULL DEFAULT '0',
  `AzeritePowerID` int(11) NOT NULL DEFAULT '0',
  `Type` int(11) NOT NULL DEFAULT '0',
  `AutoUnlock` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `azerite_power`
--
DROP TABLE IF EXISTS `azerite_power`;
CREATE TABLE `azerite_power` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(11) NOT NULL DEFAULT '0',
  `ItemBonusListID` int(11) NOT NULL DEFAULT '0',
  `SpecSetID` int(11) NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `spec_set_member`
--
DROP TABLE IF EXISTS `spec_set_member`;
CREATE TABLE `spec_set_member` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ChrSpecializationID` int(11) NOT NULL DEFAULT '0',
  `SpecSetID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
