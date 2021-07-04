--
-- Table structure for table `adventure_journal`
--
DROP TABLE IF EXISTS `adventure_journal`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `adventure_journal` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Description` text,
  `ButtonText` text,
  `RewardDescription` text,
  `ContinueDescription` text,
  `Type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ButtonActionType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `TextureFileDataID` int(11) NOT NULL DEFAULT '0',
  `LfgDungeonID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `QuestID` int(11) NOT NULL DEFAULT '0',
  `BattleMasterListID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PriorityMin` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PriorityMax` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ItemID` int(11) NOT NULL DEFAULT '0',
  `ItemQuantity` int(10) unsigned NOT NULL DEFAULT '0',
  `CurrencyType` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CurrencyQuantity` int(10) unsigned NOT NULL DEFAULT '0',
  `UiMapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `BonusPlayerConditionID1` int(10) unsigned NOT NULL DEFAULT '0',
  `BonusPlayerConditionID2` int(10) unsigned NOT NULL DEFAULT '0',
  `BonusValue1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `BonusValue2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
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
  `Name_lang` text,
  `Description_lang` text,
  `ButtonText_lang` text,
  `RewardDescription_lang` text,
  `ContinueDescription_lang` text,
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`)
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
