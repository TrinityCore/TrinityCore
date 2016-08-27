--
-- Table structure for table `artifact`
--
DROP TABLE IF EXISTS `artifact`;
CREATE TABLE `artifact` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `BarConnectedColor` int(10) unsigned NOT NULL DEFAULT '0',
  `BarDisconnectedColor` int(10) unsigned NOT NULL DEFAULT '0',
  `TitleColor` int(10) unsigned NOT NULL DEFAULT '0',
  `ClassUiTextureKitID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SpecID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ArtifactCategoryID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `artifact_locale`
--
DROP TABLE IF EXISTS `artifact_locale`;
CREATE TABLE `artifact_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `artifact_appearance`
--
DROP TABLE IF EXISTS `artifact_appearance`;
CREATE TABLE `artifact_appearance` (
  `Name` text,
  `SwatchColor` int(10) unsigned NOT NULL DEFAULT '0',
  `ModelDesaturation` float NOT NULL DEFAULT '0',
  `ModelAlpha` float NOT NULL DEFAULT '0',
  `ShapeshiftDisplayID` int(10) unsigned NOT NULL DEFAULT '0',
  `ArtifactAppearanceSetID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PlayerConditionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Unknown` smallint(5) unsigned NOT NULL DEFAULT '0',
  `DisplayIndex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AppearanceModID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ModifiesShapeshiftFormDisplay` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemAppearanceID` int(10) unsigned NOT NULL DEFAULT '0',
  `AltItemAppearanceID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `artifact_appearance_locale`
--
DROP TABLE IF EXISTS `artifact_appearance_locale`;
CREATE TABLE `artifact_appearance_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `artifact_appearance_set`
--
DROP TABLE IF EXISTS `artifact_appearance_set`;
CREATE TABLE `artifact_appearance_set` (
  `Name` text,
  `Name2` text,
  `UiCameraID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AltHandUICameraID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ArtifactID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DisplayIndex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AttachmentPoint` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `artifact_appearance_set_locale`
--
DROP TABLE IF EXISTS `artifact_appearance_set_locale`;
CREATE TABLE `artifact_appearance_set_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Name2_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `artifact_category`
--
DROP TABLE IF EXISTS `artifact_category`;
CREATE TABLE `artifact_category` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ArtifactKnowledgeCurrencyID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ArtifactKnowledgeMultiplierCurveID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `artifact_power`
--
DROP TABLE IF EXISTS `artifact_power`;
CREATE TABLE `artifact_power` (
  `PosX` float NOT NULL DEFAULT '0',
  `PosY` float NOT NULL DEFAULT '0',
  `ArtifactID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxRank` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `RelicType` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `artifact_power_link`
--
DROP TABLE IF EXISTS `artifact_power_link`;
CREATE TABLE `artifact_power_link` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `FromArtifactPowerID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ToArtifactPowerID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `artifact_power_rank`
--
DROP TABLE IF EXISTS `artifact_power_rank`;
CREATE TABLE `artifact_power_rank` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `Value` float NOT NULL DEFAULT '0',
  `ArtifactPowerID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Unknown` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Rank` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `artifact_quest_xp`
--
DROP TABLE IF EXISTS `artifact_quest_xp`;
CREATE TABLE `artifact_quest_xp` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp1` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp2` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp3` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp4` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp5` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp6` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp7` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp8` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp9` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp10` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `item_bonus_list_level_delta`
--
DROP TABLE IF EXISTS `item_bonus_list_level_delta`;
CREATE TABLE `item_bonus_list_level_delta` (
  `Delta` smallint(6) NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
