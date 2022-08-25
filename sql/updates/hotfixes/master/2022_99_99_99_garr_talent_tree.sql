--
-- Table structure for table `garr_talent_tree`
--

DROP TABLE IF EXISTS `garr_talent_tree`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
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
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `garr_talent_tree`
--

LOCK TABLES `garr_talent_tree` WRITE;
/*!40000 ALTER TABLE `garr_talent_tree` DISABLE KEYS */;
/*!40000 ALTER TABLE `garr_talent_tree` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `garr_talent_tree_locale`
--

DROP TABLE IF EXISTS `garr_talent_tree_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `garr_talent_tree_locale` (
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
-- Dumping data for table `garr_talent_tree_locale`
--

LOCK TABLES `garr_talent_tree_locale` WRITE;
/*!40000 ALTER TABLE `garr_talent_tree_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `garr_talent_tree_locale` ENABLE KEYS */;
UNLOCK TABLES;
