--
-- Table structure for table `adventure_journal`
--
DROP TABLE IF EXISTS `adventure_journal`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `adventure_journal` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text DEFAULT NULL,
  `Description` text DEFAULT NULL,
  `ButtonText` text DEFAULT NULL,
  `RewardDescription` text DEFAULT NULL,
  `ContinueDescription` text DEFAULT NULL,
  `Type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PlayerConditionId` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ButtonActionType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `TextureFileDataId` int(11) NOT NULL DEFAULT '0',
  `LfgDungeonId` smallint(5) unsigned NOT NULL DEFAULT '0',
  `QuestId` smallint(5) unsigned NOT NULL DEFAULT '0',
  `BattleMasterListId` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PriorityMin` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PriorityMax` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ItemId` int(11) NOT NULL DEFAULT '0',
  `ItemQuantity` int(10) unsigned NOT NULL DEFAULT '0',
  `CurrencyType` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CurrencyQuantity` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `UiMapId` smallint(5) unsigned NOT NULL DEFAULT '0',
  `BonusPlayerConditionId1` int(11) NOT NULL DEFAULT '0',
  `BonusPlayerConditionId2` int(11) NOT NULL DEFAULT '0',
  `BonusValue1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `BonusValue2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `adventure_journal_locale`
--
DROP TABLE IF EXISTS `adventure_journal_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `adventure_journal_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text DEFAULT NULL,
  `Description_lang` text DEFAULT NULL,
  `ButtonText_lang` text DEFAULT NULL,
  `RewardDescription_lang` text DEFAULT NULL,
  `ContinueDescription_lang` text DEFAULT NULL,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci
/*!50500 PARTITION BY LIST  COLUMNS(locale)
(PARTITION deDE VALUES IN ('deDE') ENGINE = InnoDB,
 PARTITION esES VALUES IN ('esES') ENGINE = InnoDB,
 PARTITION esMX VALUES IN ('esMX') ENGINE = InnoDB,
 PARTITION frFR VALUES IN ('frFR') ENGINE = InnoDB,
 PARTITION itIT VALUES IN ('itIT') ENGINE = InnoDB,
 PARTITION koKR VALUES IN ('koKR') ENGINE = InnoDB,
 PARTITION ptBR VALUES IN ('ptBR') ENGINE = InnoDB,
 PARTITION ruRU VALUES IN ('ruRU') ENGINE = InnoDB,
 PARTITION zhCN VALUES IN ('zhCN') ENGINE = InnoDB,
 PARTITION zhTW VALUES IN ('zhTW') ENGINE = InnoDB) */;
/*!40101 SET character_set_client = @saved_cs_client */;