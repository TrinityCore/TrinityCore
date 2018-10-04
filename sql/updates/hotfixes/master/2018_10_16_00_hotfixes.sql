--
-- Table structure for table `num_talents_at_level`
--
DROP TABLE IF EXISTS `num_talents_at_level`;
CREATE TABLE `num_talents_at_level` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `NumTalents` int(11) NOT NULL DEFAULT '0',
  `NumTalentsDeathKnight` int(11) NOT NULL DEFAULT '0',
  `NumTalentsDemonHunter` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
