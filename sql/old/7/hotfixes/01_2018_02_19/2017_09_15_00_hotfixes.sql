--
-- Table structure for table `item_level_selector`
--
DROP TABLE IF EXISTS `item_level_selector`;
CREATE TABLE `item_level_selector` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
