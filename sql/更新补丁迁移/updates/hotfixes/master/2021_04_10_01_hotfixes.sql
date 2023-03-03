--
-- Table structure for table `vignette`
--

DROP TABLE IF EXISTS `vignette`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `vignette` (
  `ID` int(11) NOT NULL DEFAULT '0',
  `Name` text,
  `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `VisibleTrackingQuestID` int(10) unsigned NOT NULL DEFAULT '0',
  `QuestFeedbackEffectID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxHeight` float NOT NULL DEFAULT '0',
  `MinHeight` float NOT NULL DEFAULT '0',
  `VignetteType` tinyint(4) NOT NULL DEFAULT '0',
  `RewardQuestID` int(11) NOT NULL DEFAULT '0',
  `UiWidgetSetID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `vignette`
--

LOCK TABLES `vignette` WRITE;
/*!40000 ALTER TABLE `vignette` DISABLE KEYS */;
/*!40000 ALTER TABLE `vignette` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `vignette_locale`
--

DROP TABLE IF EXISTS `vignette_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `vignette_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
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

--
-- Dumping data for table `vignette_locale`
--

LOCK TABLES `vignette_locale` WRITE;
/*!40000 ALTER TABLE `vignette_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `vignette_locale` ENABLE KEYS */;
UNLOCK TABLES;

