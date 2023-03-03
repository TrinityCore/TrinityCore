--
-- Table structure for table `pvp_item`
--
DROP TABLE IF EXISTS `pvp_item`;
CREATE TABLE `pvp_item` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemLevelBonus` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
