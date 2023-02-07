--
-- Table structure for table `spell_keybound_override`
--

DROP TABLE IF EXISTS `spell_keybound_override`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_keybound_override` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Binding` text,
  `Type` tinyint(4) NOT NULL DEFAULT '0',
  `SpellID` int(11) NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spell_keybound_override`
--

LOCK TABLES `spell_keybound_override` WRITE;
/*!40000 ALTER TABLE `spell_keybound_override` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_keybound_override` ENABLE KEYS */;
UNLOCK TABLES;
