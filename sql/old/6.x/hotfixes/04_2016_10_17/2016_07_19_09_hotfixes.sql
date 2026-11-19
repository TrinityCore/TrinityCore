--
-- Table structure for table `item_search_name`
--
DROP TABLE IF EXISTS `item_search_name`;
CREATE TABLE `item_search_name` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Flags1` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags2` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags3` int(10) unsigned NOT NULL DEFAULT '0',
  `AllowableRace` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredSpell` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredReputationFaction` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredSkill` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredSkillRank` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Quality` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RequiredExpansion` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RequiredReputationRank` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RequiredLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AllowableClass` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `item_search_name_locale`
--
DROP TABLE IF EXISTS `item_search_name_locale`;
CREATE TABLE `item_search_name_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

