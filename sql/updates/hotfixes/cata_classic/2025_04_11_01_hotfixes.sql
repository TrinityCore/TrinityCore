--
-- Table structure for table `scaling_stat_distribution`
--

DROP TABLE IF EXISTS `scaling_stat_distribution`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `scaling_stat_distribution` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `PlayerLevelToItemLevelCurveID` smallint unsigned NOT NULL DEFAULT '0',
  `Minlevel` int NOT NULL DEFAULT '0',
  `Maxlevel` int NOT NULL DEFAULT '0',
  `Bonus1` int NOT NULL DEFAULT '0',
  `Bonus2` int NOT NULL DEFAULT '0',
  `Bonus3` int NOT NULL DEFAULT '0',
  `Bonus4` int NOT NULL DEFAULT '0',
  `Bonus5` int NOT NULL DEFAULT '0',
  `Bonus6` int NOT NULL DEFAULT '0',
  `Bonus7` int NOT NULL DEFAULT '0',
  `Bonus8` int NOT NULL DEFAULT '0',
  `Bonus9` int NOT NULL DEFAULT '0',
  `Bonus10` int NOT NULL DEFAULT '0',
  `StatID1` int NOT NULL DEFAULT '0',
  `StatID2` int NOT NULL DEFAULT '0',
  `StatID3` int NOT NULL DEFAULT '0',
  `StatID4` int NOT NULL DEFAULT '0',
  `StatID5` int NOT NULL DEFAULT '0',
  `StatID6` int NOT NULL DEFAULT '0',
  `StatID7` int NOT NULL DEFAULT '0',
  `StatID8` int NOT NULL DEFAULT '0',
  `StatID9` int NOT NULL DEFAULT '0',
  `StatID10` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `scaling_stat_distribution`
--

LOCK TABLES `scaling_stat_distribution` WRITE;
/*!40000 ALTER TABLE `scaling_stat_distribution` DISABLE KEYS */;
/*!40000 ALTER TABLE `scaling_stat_distribution` ENABLE KEYS */;
UNLOCK TABLES;
