--
-- Table structure for table `garr_type`
--

DROP TABLE IF EXISTS `garr_type`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `garr_type` (
  `ID` tinyint unsigned NOT NULL DEFAULT '0',
  `PrimaryCurrencyTypeID` int unsigned NOT NULL DEFAULT '0',
  `SecondaryCurrencyTypeID` int unsigned NOT NULL DEFAULT '0',
  `ExpansionID` int unsigned NOT NULL DEFAULT '0',
  `Flags` int unsigned NOT NULL DEFAULT '0',
  `AutoFollowerHealRate` float NOT NULL DEFAULT '0',
  `MissionCostCurveID` int NOT NULL DEFAULT '0',
  `AutoFollowerHealCostMult` float NOT NULL DEFAULT '0',
  `MapIDs1` int NOT NULL DEFAULT '0',
  `MapIDs2` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `garr_type`
--

LOCK TABLES `garr_type` WRITE;
/*!40000 ALTER TABLE `garr_type` DISABLE KEYS */;
/*!40000 ALTER TABLE `garr_type` ENABLE KEYS */;
UNLOCK TABLES;
