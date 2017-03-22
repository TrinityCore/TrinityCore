DROP TABLE IF EXISTS `pvp_reward`;
CREATE TABLE `pvp_reward` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `HonorLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `Prestige` int(10) unsigned NOT NULL DEFAULT '0',
  `RewardPackID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

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

DROP TABLE IF EXISTS `prestige_level_info_locale`;
CREATE TABLE `prestige_level_info_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `PrestigeText_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `reward_pack`;
CREATE TABLE `reward_pack` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Money` int(10) unsigned NOT NULL DEFAULT '0',
  `ArtifactXPMultiplier` float NOT NULL DEFAULT '0',
  `ArtifactXPDifficulty` int(10) unsigned NOT NULL DEFAULT '0',
  `ArtifactCategoryID` int(10) unsigned NOT NULL DEFAULT '0',
  `TitleID` int(10) unsigned NOT NULL DEFAULT '0',
  `Unused` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `reward_pack_x_item`;
CREATE TABLE `reward_pack_x_item` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `RewardPackID` int(10) unsigned NOT NULL DEFAULT '0',
  `Amount` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DELETE FROM `prestige_level_info` WHERE `ID`=11;
INSERT INTO `prestige_level_info` (`ID`, `IconID`, `PrestigeText`, `PrestigeLevel`, `Flags`, `VerifiedBuild`) VALUES
(11, 1567394, 'Prestige Level 9', 9, 0, 23420);

-- is this needed ? I can't see it listed without this.
DELETE FROM `hotfix_data` WHERE `TableHash`=1362239809 AND `RecordID`=11;
INSERT INTO `hotfix_data` (`TableHash`, `RecordID`, `TimeStamp`, `Deleted`) VALUES
(1362239809, 11, 0, 0);
