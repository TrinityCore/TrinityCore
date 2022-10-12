--
-- Table structure for table `ui_chromie_time_expansion_info`
--

DROP TABLE IF EXISTS `ui_chromie_time_expansion_info`;
CREATE TABLE `ui_chromie_time_expansion_info` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Description` text,
  `DescriptionAlliance` text,
  `DescriptionHorde` text,
  `SpellID` int(11) NOT NULL DEFAULT '0',
  `UiTextureAtlasElementLarge` int(11) NOT NULL DEFAULT '0',
  `UiTextureAtlasElementSmall` int(11) NOT NULL DEFAULT '0',
  `AlreadyOn` int(11) NOT NULL DEFAULT '0',
  `ExpansionLevelMask` int(11) NOT NULL DEFAULT '0',
  `ContentTuningID` int(11) NOT NULL DEFAULT '0',
  `Completed` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `ui_chromie_time_expansion_info_locale`
--

DROP TABLE IF EXISTS `ui_chromie_time_expansion_info_locale`;
CREATE TABLE `ui_chromie_time_expansion_info_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Description_lang` text,
  `DescriptionAlliance_lang` text,
  `DescriptionHorde_lang` text,
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci
PARTITION BY LIST  COLUMNS(locale)
(PARTITION deDE VALUES IN ('deDE') ENGINE = InnoDB,
 PARTITION esES VALUES IN ('esES') ENGINE = InnoDB,
 PARTITION esMX VALUES IN ('esMX') ENGINE = InnoDB,
 PARTITION frFR VALUES IN ('frFR') ENGINE = InnoDB,
 PARTITION itIT VALUES IN ('itIT') ENGINE = InnoDB,
 PARTITION koKR VALUES IN ('koKR') ENGINE = InnoDB,
 PARTITION ptBR VALUES IN ('ptBR') ENGINE = InnoDB,
 PARTITION ruRU VALUES IN ('ruRU') ENGINE = InnoDB,
 PARTITION zhCN VALUES IN ('zhCN') ENGINE = InnoDB,
 PARTITION zhTW VALUES IN ('zhTW') ENGINE = InnoDB);
