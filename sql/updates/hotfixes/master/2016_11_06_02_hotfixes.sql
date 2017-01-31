--
-- Table structure for table `scenario`
--
DROP TABLE IF EXISTS `scenario`;
CREATE TABLE `scenario` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Data` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `scenario_locale`
--
DROP TABLE IF EXISTS `scenario_locale`;
CREATE TABLE `scenario_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `scenario_step`
--
DROP TABLE IF EXISTS `scenario_step`;
CREATE TABLE `scenario_step` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Description` text,
  `Name` text,
  `CriteriaTreeID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ScenarioID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PreviousStepID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `QuestRewardID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Step` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `BonusRequiredStepID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `scenario_step_locale`
--
DROP TABLE IF EXISTS `scenario_step_locale`;
CREATE TABLE `scenario_step_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Description_lang` text,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
