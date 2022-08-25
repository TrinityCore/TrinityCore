DROP TABLE IF EXISTS `garr_talent_tree`;
CREATE TABLE `garr_talent_tree` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `GarrTypeID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ClassID` int(11) NOT NULL DEFAULT '0',
  `MaxTiers` tinyint(4) NOT NULL DEFAULT '0',
  `UiOrder` tinyint(4) NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `UiTextureKitID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `GarrTalentTreeType` int(11) NOT NULL DEFAULT '0',
  `PlayerConditionID` int(11) NOT NULL DEFAULT '0',
  `FeatureTypeIndex` tinyint(3) signed NOT NULL DEFAULT '0',
  `FeatureSubtypeIndex` tinyint(3) signed NOT NULL DEFAULT '0',
  `CurrencyID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

DROP TABLE IF EXISTS `garr_talent_tree_locale`;
CREATE TABLE `garr_talent_tree_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
