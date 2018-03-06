--
-- Table structure for table `artifact_power_picker`
--
DROP TABLE IF EXISTS `artifact_power_picker`;
CREATE TABLE `artifact_power_picker` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
