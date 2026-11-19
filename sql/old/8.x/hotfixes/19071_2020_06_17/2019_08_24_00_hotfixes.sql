--
-- Table structure for table `world_state_expression`
--
DROP TABLE IF EXISTS `world_state_expression`;
CREATE TABLE `world_state_expression` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Expression` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
