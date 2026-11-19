--
-- Table structure for table `pvp_reward`
--
DROP TABLE IF EXISTS `pvp_reward`;
CREATE TABLE `pvp_reward` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `HonorLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `Prestige` int(10) unsigned NOT NULL DEFAULT '0',
  `RewardPackID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `prestige_level_info`
--
DROP TABLE IF EXISTS `prestige_level_info`;
CREATE TABLE `prestige_level_info` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `IconID` int(10) unsigned NOT NULL DEFAULT '0',
  `PrestigeText` text,
  `PrestigeLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `prestige_level_info_locale`
--
DROP TABLE IF EXISTS `prestige_level_info_locale`;
CREATE TABLE `prestige_level_info_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `PrestigeText_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `reward_pack`
--
DROP TABLE IF EXISTS `reward_pack`;
CREATE TABLE `reward_pack` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Money` int(10) unsigned NOT NULL DEFAULT '0',
  `ArtifactXPMultiplier` float NOT NULL DEFAULT '0',
  `ArtifactXPDifficulty` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ArtifactCategoryID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `TitleID` int(10) unsigned NOT NULL DEFAULT '0',
  `Unused` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `reward_pack_x_item`
--
DROP TABLE IF EXISTS `reward_pack_x_item`;
CREATE TABLE `reward_pack_x_item` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `RewardPackID` int(10) unsigned NOT NULL DEFAULT '0',
  `Amount` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
