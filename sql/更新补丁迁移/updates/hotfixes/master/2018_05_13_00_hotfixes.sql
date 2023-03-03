--
-- Table structure for table `cfg_regions`
--
DROP TABLE IF EXISTS `cfg_regions`;
CREATE TABLE `cfg_regions` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Tag` text,
  `Raidorigin` int(10) unsigned NOT NULL DEFAULT '0',
  `ChallengeOrigin` int(10) unsigned NOT NULL DEFAULT '0',
  `RegionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RegionGroupMask` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
