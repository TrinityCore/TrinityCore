--
-- Table structure for table `power_type`
--
DROP TABLE IF EXISTS `power_type`;
CREATE TABLE `power_type` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `PowerTypeToken` text,
  `PowerCostToken` text,
  `RegenerationPeace` float NOT NULL DEFAULT '0',
  `RegenerationCombat` float NOT NULL DEFAULT '0',
  `MaxPower` smallint(6) NOT NULL DEFAULT '0',
  `RegenerationDelay` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Flags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PowerTypeEnum` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RegenerationMin` tinyint(4) NOT NULL DEFAULT '0',
  `RegenerationCenter` tinyint(4) NOT NULL DEFAULT '0',
  `RegenerationMax` tinyint(4) NOT NULL DEFAULT '0',
  `UIModifier` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
