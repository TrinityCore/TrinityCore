--
-- Table structure for table `crafting_quality`
--
DROP TABLE IF EXISTS `crafting_quality`;
CREATE TABLE `crafting_quality` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `QualityTier` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `modified_crafting_item`
--
DROP TABLE IF EXISTS `modified_crafting_item`;
CREATE TABLE `modified_crafting_item` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ModifiedCraftingReagentItemID` int NOT NULL DEFAULT '0',
  `CraftingQualityID` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `perks_activity`
--
DROP TABLE IF EXISTS `perks_activity`;
CREATE TABLE `perks_activity` (
  `ActivityName` text,
  `Description` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `CriteriaTreeID` int NOT NULL DEFAULT '0',
  `ThresholdContributionAmount` int NOT NULL DEFAULT '0',
  `Supersedes` int NOT NULL DEFAULT '0',
  `Priority` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `perks_activity_locale`
--
DROP TABLE IF EXISTS `perks_activity_locale`;
CREATE TABLE `perks_activity_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `ActivityName_lang` text,
  `Description_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci PARTITION BY LIST COLUMNS(locale)
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
