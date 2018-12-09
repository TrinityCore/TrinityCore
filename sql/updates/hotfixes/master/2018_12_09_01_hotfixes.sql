--
-- Table structure for table `animation_data`
--
DROP TABLE IF EXISTS `animation_data`;
CREATE TABLE `animation_data` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Fallback` smallint(5) unsigned NOT NULL DEFAULT '0',
  `BehaviorTier` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `BehaviorID` int(11) NOT NULL DEFAULT '0',
  `Flags1` int(11) NOT NULL DEFAULT '0',
  `Flags2` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

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
