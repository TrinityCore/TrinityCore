--
-- Table structure for table `garr_ability`
--

DROP TABLE IF EXISTS `garr_ability`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `garr_ability` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Description` text,
  `IconFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `OtherFactionGarrAbilityID` int(10) unsigned NOT NULL DEFAULT '0',
  `GarrAbilityCategoryID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `garr_ability`
--

LOCK TABLES `garr_ability` WRITE;
/*!40000 ALTER TABLE `garr_ability` DISABLE KEYS */;
/*!40000 ALTER TABLE `garr_ability` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `garr_ability_locale`
--

DROP TABLE IF EXISTS `garr_ability_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `garr_ability_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Description_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `garr_ability_locale`
--

LOCK TABLES `garr_ability_locale` WRITE;
/*!40000 ALTER TABLE `garr_ability_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `garr_ability_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `garr_class_spec`
--

DROP TABLE IF EXISTS `garr_class_spec`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `garr_class_spec` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `NameMale` text,
  `NameFemale` text,
  `NameGenderless` text,
  `ClassAtlasID` int(10) unsigned NOT NULL DEFAULT '0',
  `GarrFollItemSetID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `garr_class_spec`
--

LOCK TABLES `garr_class_spec` WRITE;
/*!40000 ALTER TABLE `garr_class_spec` DISABLE KEYS */;
/*!40000 ALTER TABLE `garr_class_spec` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `garr_class_spec_locale`
--

DROP TABLE IF EXISTS `garr_class_spec_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `garr_class_spec_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `NameMale_lang` text,
  `NameFemale_lang` text,
  `NameGenderless_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `garr_class_spec_locale`
--

LOCK TABLES `garr_class_spec_locale` WRITE;
/*!40000 ALTER TABLE `garr_class_spec_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `garr_class_spec_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `garr_follower`
--

DROP TABLE IF EXISTS `garr_follower`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `garr_follower` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `HordeCreatureID` int(10) unsigned NOT NULL DEFAULT '0',
  `AllianceCreatureID` int(10) unsigned NOT NULL DEFAULT '0',
  `HordeUiAnimRaceInfoID` int(10) unsigned NOT NULL DEFAULT '0',
  `AllianceUiAnimRaceInfoID` int(10) unsigned NOT NULL DEFAULT '0',
  `Quality` int(10) unsigned NOT NULL DEFAULT '0',
  `HordeGarrClassSpecID` int(10) unsigned NOT NULL DEFAULT '0',
  `AllianceGarrClassSpecID` int(10) unsigned NOT NULL DEFAULT '0',
  `HordeGarrFollItemSetID` int(10) unsigned NOT NULL DEFAULT '0',
  `AllianceGarrFollItemSetID` int(10) unsigned NOT NULL DEFAULT '0',
  `Level` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemLevelWeapon` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemLevelArmor` int(10) unsigned NOT NULL DEFAULT '0',
  `Unknown1` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `HordeSourceText` text,
  `AllianceSourceText` text,
  `Unknown2` int(11) NOT NULL DEFAULT '0',
  `Unknown3` int(11) NOT NULL DEFAULT '0',
  `HordePortraitIconID` int(10) unsigned NOT NULL DEFAULT '0',
  `AlliancePortraitIconID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `garr_follower`
--

LOCK TABLES `garr_follower` WRITE;
/*!40000 ALTER TABLE `garr_follower` DISABLE KEYS */;
/*!40000 ALTER TABLE `garr_follower` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `garr_follower_locale`
--

DROP TABLE IF EXISTS `garr_follower_locale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `garr_follower_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `HordeSourceText_lang` text,
  `AllianceSourceText_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `garr_follower_locale`
--

LOCK TABLES `garr_follower_locale` WRITE;
/*!40000 ALTER TABLE `garr_follower_locale` DISABLE KEYS */;
/*!40000 ALTER TABLE `garr_follower_locale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `garr_follower_x_ability`
--

DROP TABLE IF EXISTS `garr_follower_x_ability`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `garr_follower_x_ability` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `GarrFollowerID` int(10) unsigned NOT NULL DEFAULT '0',
  `GarrAbilityID` int(10) unsigned NOT NULL DEFAULT '0',
  `FactionIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `garr_follower_x_ability`
--

LOCK TABLES `garr_follower_x_ability` WRITE;
/*!40000 ALTER TABLE `garr_follower_x_ability` DISABLE KEYS */;
/*!40000 ALTER TABLE `garr_follower_x_ability` ENABLE KEYS */;
UNLOCK TABLES;

