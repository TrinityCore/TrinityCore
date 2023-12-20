--
-- Table structure for table `item_random_properties`
--

DROP TABLE IF EXISTS `item_random_properties`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_random_properties` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Enchantment1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Enchantment2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Enchantment3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Enchantment4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Enchantment5` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_random_properties`
--

LOCK TABLES `item_random_properties` WRITE;
/*!40000 ALTER TABLE `item_random_properties` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_random_properties` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_random_properties_locale`
--

DROP TABLE IF EXISTS `item_random_properties_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_random_properties_locale` (
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
-- Dumping data for table `item_random_properties_locale`
--

LOCK TABLES `item_random_properties_locale` WRITE;
/*!40000 ALTER TABLE `item_random_properties_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_random_properties_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_random_suffix`
--

DROP TABLE IF EXISTS `item_random_suffix`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_random_suffix` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Enchantment1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Enchantment2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Enchantment3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Enchantment4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Enchantment5` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AllocationPct1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AllocationPct2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AllocationPct3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AllocationPct4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AllocationPct5` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_random_suffix`
--

LOCK TABLES `item_random_suffix` WRITE;
/*!40000 ALTER TABLE `item_random_suffix` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_random_suffix` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_random_suffix_locale`
--

DROP TABLE IF EXISTS `item_random_suffix_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_random_suffix_locale` (
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
-- Dumping data for table `item_random_suffix_locale`
--

LOCK TABLES `item_random_suffix_locale` WRITE;
/*!40000 ALTER TABLE `item_random_suffix_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_random_suffix_locale` ENABLE KEYS */;
UNLOCK TABLES;
