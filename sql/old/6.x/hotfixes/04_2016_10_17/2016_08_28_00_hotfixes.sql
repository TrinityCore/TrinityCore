--
-- Table structure for table `tact_key`
--

DROP TABLE IF EXISTS `tact_key`;
CREATE TABLE `tact_key` (
  `Id` int(10) unsigned NOT NULL DEFAULT '0',
  `Key1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key4` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key5` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key6` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key7` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key8` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key9` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key10` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key11` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key12` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key13` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key14` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key15` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Key16` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`Id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
