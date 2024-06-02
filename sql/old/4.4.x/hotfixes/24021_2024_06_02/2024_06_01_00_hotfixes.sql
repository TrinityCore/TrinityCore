--
-- Table structure for table `item_reforge`
--

DROP TABLE IF EXISTS `item_reforge`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_reforge` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SourceStat` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SourceMultiplier` float NOT NULL DEFAULT '0',
  `TargetStat` smallint(5) unsigned NOT NULL DEFAULT '0',
  `TargetMultiplier` float NOT NULL DEFAULT '0',
  `LegacyItemReforgeID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_reforge`
--

LOCK TABLES `item_reforge` WRITE;
/*!40000 ALTER TABLE `item_reforge` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_reforge` ENABLE KEYS */;
UNLOCK TABLES;
