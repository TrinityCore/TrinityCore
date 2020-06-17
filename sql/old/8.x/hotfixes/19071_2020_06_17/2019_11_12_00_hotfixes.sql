--
-- Table structure for table `azerite_item`
--
DROP TABLE IF EXISTS `azerite_item`;
CREATE TABLE `azerite_item` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `azerite_knowledge_multiplier`
--
DROP TABLE IF EXISTS `azerite_knowledge_multiplier`;
CREATE TABLE `azerite_knowledge_multiplier` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Multiplier` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `azerite_level_info`
--
DROP TABLE IF EXISTS `azerite_level_info`;
CREATE TABLE `azerite_level_info` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `BaseExperienceToNextLevel` bigint(20) unsigned NOT NULL DEFAULT '0',
  `MinimumExperienceToNextLevel` bigint(20) unsigned NOT NULL DEFAULT '0',
  `ItemLevel` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
