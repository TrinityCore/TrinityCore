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
