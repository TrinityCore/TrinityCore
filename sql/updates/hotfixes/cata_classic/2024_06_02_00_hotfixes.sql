--
-- Table structure for table `talent_tab`
--

DROP TABLE IF EXISTS `talent_tab`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `talent_tab` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `BackgroundFile` text,
  `Description` text,
  `OrderIndex` int(11) NOT NULL DEFAULT '0',
  `RaceMask` int(11) NOT NULL DEFAULT '0',
  `ClassMask` int(11) NOT NULL DEFAULT '0',
  `CategoryEnumID` int(11) NOT NULL DEFAULT '0',
  `SpellIconID` int(11) NOT NULL DEFAULT '0',
  `RoleMask` int(11) NOT NULL DEFAULT '0',
  `MasterySpellID1` int(11) NOT NULL DEFAULT '0',
  `MasterySpellID2` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `talent_tab`
--

LOCK TABLES `talent_tab` WRITE;
/*!40000 ALTER TABLE `talent_tab` DISABLE KEYS */;
/*!40000 ALTER TABLE `talent_tab` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `talent_tab_locale`
--

DROP TABLE IF EXISTS `talent_tab_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `talent_tab_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Description_lang` text,
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
-- Dumping data for table `talent_tab_locale`
--

LOCK TABLES `talent_tab_locale` WRITE;
/*!40000 ALTER TABLE `talent_tab_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `talent_tab_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `talent_tree_primary_spells`
--

DROP TABLE IF EXISTS `talent_tree_primary_spells`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `talent_tree_primary_spells` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TalentTabID` int(11) NOT NULL DEFAULT '0',
  `SpellID` int(11) NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `talent_tree_primary_spells`
--

LOCK TABLES `talent_tree_primary_spells` WRITE;
/*!40000 ALTER TABLE `talent_tree_primary_spells` DISABLE KEYS */;
/*!40000 ALTER TABLE `talent_tree_primary_spells` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `glyph_slot`
--

DROP TABLE IF EXISTS `glyph_slot`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `glyph_slot` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Tooltip` int(11) NOT NULL DEFAULT '0',
  `Type` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `glyph_slot`
--

LOCK TABLES `glyph_slot` WRITE;
/*!40000 ALTER TABLE `glyph_slot` DISABLE KEYS */;
/*!40000 ALTER TABLE `glyph_slot` ENABLE KEYS */;
UNLOCK TABLES;
