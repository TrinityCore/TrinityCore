--
-- Table structure for table `character_facial_hair_styles`
--
DROP TABLE IF EXISTS `character_facial_hair_styles`;
CREATE TABLE `character_facial_hair_styles` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Geoset1` int(10) unsigned NOT NULL DEFAULT '0',
  `Geoset2` int(10) unsigned NOT NULL DEFAULT '0',
  `Geoset3` int(10) unsigned NOT NULL DEFAULT '0',
  `Geoset4` int(10) unsigned NOT NULL DEFAULT '0',
  `Geoset5` int(10) unsigned NOT NULL DEFAULT '0',
  `RaceID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SexID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VariationID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `char_base_section`
--
DROP TABLE IF EXISTS `char_base_section`;
CREATE TABLE `char_base_section` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Variation` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ResolutionVariation` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Resolution` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

ALTER TABLE `char_sections`
  CHANGE `Race` `RaceID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  CHANGE `Gender` `SexID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  CHANGE `GenType` `BaseSection` tinyint(3) unsigned NOT NULL DEFAULT '0',
  CHANGE `Type` `VariationIndex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  CHANGE `Color` `ColorIndex` tinyint(3) unsigned NOT NULL DEFAULT '0';
