--
-- Table structure for table `campaign`
--
DROP TABLE IF EXISTS `campaign`;
CREATE TABLE `campaign` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Title` text,
  `Description` text,
  `UiTextureKitID` int NOT NULL DEFAULT '0',
  `RewardQuestID` int NOT NULL DEFAULT '0',
  `Prerequisite` int NOT NULL DEFAULT '0',
  `Stalled` int NOT NULL DEFAULT '0',
  `Completed` int NOT NULL DEFAULT '0',
  `OnlyStallIf` int NOT NULL DEFAULT '0',
  `UiQuestDetailsThemeID` int NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `DisplayPriority` int NOT NULL DEFAULT '0',
  `SortAsNormalQuest` int NOT NULL DEFAULT '0',
  `UseMinimalHeader` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `campaign_locale`
--
DROP TABLE IF EXISTS `campaign_locale`;
CREATE TABLE `campaign_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Title_lang` text,
  `Description_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
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

--
-- Table structure for table `campaign_x_quest_line`
--
DROP TABLE IF EXISTS `campaign_x_quest_line`;
CREATE TABLE `campaign_x_quest_line` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `CampaignID` int unsigned NOT NULL DEFAULT '0',
  `QuestLineID` int unsigned NOT NULL DEFAULT '0',
  `OrderIndex` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
