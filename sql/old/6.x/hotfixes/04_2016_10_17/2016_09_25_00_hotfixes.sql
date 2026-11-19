--
-- Table structure for table `scene_script`
--
DROP TABLE IF EXISTS `scene_script`;
CREATE TABLE `scene_script` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Script` text,
  `PrevScriptId` smallint(5) unsigned NOT NULL DEFAULT '0',
  `NextScriptId` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `scene_script_package`
--
DROP TABLE IF EXISTS `scene_script_package`;
CREATE TABLE `scene_script_package` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
